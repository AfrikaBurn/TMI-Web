<?php
/**
 * @file
 *  Drupal Log Filter module
 */

class LogFilter {

  /**
   * Numeric index of filter name request argument, if any.
   *
   * @type integer
   */
  const FILTER_NAME_ARG = 4;

  /**
   * @type integer
   */
  const TYPE_SOME_MAX = 102400;

  /**
   * @type integer
   */
  const PAGE_RANGE_DEFAULT = 20;

  /**
   * @type integer
   */
  const PAGE_RANGE_MAX = 1000;

  /**
   * @type integer
   */
  const LIST_MESSAGE_TRUNCATE = 100;

  /**
   * Does databases (MySQL) support LIMIT for sub queries?
   *
   * @type boolean
   */
  const DB_SUBQUERY_LIMIT = FALSE;

  /**
   * @type array $_errorCodes
   */
  protected static $_errorCodes = array(
    'unknown' => 1,
    //  Programmatic errors and wrong use of program.
    'algo' => 100,
    'use' => 101,
    //  Missing permission.
    'perm_general' => 200,
    'form_expired' => 201,
    'perm_filter_crud' => 202,
    'perm_filter_restricted' => 203,
    //  Database.
    'db_general' => 500,
    //  Misc.
    'filter_name_composition' => 1001,
    'filter_name_nonunique' => 1002,
    'filter_doesnt_exist' => 1003,
    'bad_filter_condition' => 1010,
  );

  /**
   * Traces and logs via Inspect tracer, or watchdog (no trace).
   *
   * @param Exception $xc
   * @param integer $severity
   *  - default: WATCHDOG_ERROR
   * @return void
   */
  protected static function _errorHandler($xc, $severity = WATCHDOG_ERROR) {
    if (module_exists('inspect')) {
      inspect_trace($xc, array('category' => 'log_filter', 'severity' => $severity));
    }
    else {
      watchdog(
        'log_filter',
        '(' . (int)$xc->getCode() . ') ' . check_plain($xc->getMessage()),
        NULL,
        $severity
      );
    }
  }

  /**
   * @type array
   */
  protected static $_fields = array(
    'settings' => array(
      'only_own',
      'delete_logs_max',
      'translate',
      'pager_range',
    ),
    'filter' => array(
      'name', // Hidden.
      'origin',
      'name_suggest',
      'description',
      'require_admin',
    ),
    'conditions' => array(
      'time_range',
      'time_from',
      'time_from_proxy', // Skip in actual conditions.
      'time_to',
      'time_to_proxy', // Skip in actual conditions.
      'severity',
      'type_wildcard', // Skip in actual conditions.
      'type',
      'role', // Default in database: -1.
      'uid', // Default in database: -1.
      'hostname',
      'location',
      'referer',
    ),
    'order_by' => array(
      'orderby_',
      'descending_',
    ),
  );

  /**
   * Defines log viewer form and GUI.
   *
   * @param array $form
   * @param array &$form_state
   * @return array
   */
  public static function viewerForm($form, &$form_state) {
    $path = drupal_get_path('module', 'log_filter');
    //  Get Judy.
    drupal_add_library('judy', 'judy');
    //  Get jQuery UI dialog.
    drupal_add_library('system', 'ui.dialog');
    //  Get jQuery UI datepicker.
    drupal_add_library('system', 'ui.datepicker');
    //  Get jQuery UI autocomplete for username.
    drupal_add_library('system', 'ui.autocomplete');
    //  Have to include own datepicker localisation, because it doesnt seem to exist in neither core nor the Date Popup module.
    drupal_add_js(
      $path . '/js/jquery_ui_datepicker_i18n/jquery.ui.datepicker-' . $GLOBALS['language']->language . '.min.js',
      array('type' => 'file', 'group' => JS_DEFAULT, 'preprocess' => FALSE, 'every_page' => FALSE)
    );

    // Use the module's default css.
    if (($use_module_css = variable_get('log_filter_cssdefault', TRUE))) {
      drupal_add_css(
        $path . '/css/log_filter' . '.min' . '.css',
        array('type' => 'file', 'group' => CSS_DEFAULT, 'preprocess' => FALSE, 'every_page' => FALSE)
      );
    }
    // Add table header script.
    drupal_add_js('misc/tableheader.js');

    drupal_add_js(
      $path . '/js/log_filter' . '.min' . '.js',
      array('type' => 'file', 'group' => JS_DEFAULT, 'preprocess' => FALSE, 'every_page' => FALSE)
    );

    try {
      $allow_filter_edit = user_access('log_filter edit filters');

      //  Get submitted vars from session, and remove them (for later form build and submission).
      $formSubmitted = $session = $settings = $submitted = $messages = NULL;
      if (module_exists('state')) {
        if (($session = State::sessionGet('module', 'log_filter')) && array_key_exists('submitted', $session)) {
          State::sessionRemove('module', 'log_filter', 'submitted');
          State::sessionRemove('module', 'log_filter', 'messages');
        }
      }
      else {
        drupal_session_start();
        if (!empty($_SESSION['module']) && !empty($_SESSION['module']['log_filter'])) {
          $session = $_SESSION['module']['log_filter'];
          unset($_SESSION['module']['log_filter']['submitted']);
          unset($_SESSION['module']['log_filter']['messages']);
        }
      }
      if ($session) {
        if (array_key_exists('settings', $session)) {
          $settings =& $session['settings'];
        }
        if (array_key_exists('submitted', $session)) {
          $formSubmitted = TRUE;
          $submitted =& $session['submitted'];
        }
        if (array_key_exists('messages', $session)) {
          $messages =& $session['messages'];
        }
      }

      //  Get current filter name from url, if any.
      $filter_name = $submitted ? $submitted['filter']['name'] :
        (($le = strlen($v = arg(self::FILTER_NAME_ARG))) // Deliberately not drupal_...().
          && $le <= 32
          && $v != 'log_filter' && $v != 'default' && $v != 'adhoc'
          && preg_match('/^[a-z_][a-z\d_]+$/', $v) ? $v : '');

      $require_admin = $submitted ? $submitted['filter']['require_admin'] : FALSE;
      $user_admin_permission = user_access('log_filter administer');

      //  Get mode: default | adhoc | stored (create|edit|delete_filter aren't allowed at form build).
      $mode = $submitted ? $submitted['mode'] : ($filter_name ? 'stored' : 'default');

      //  Stored mode may degrade to default.
      if ($mode == 'stored') {
        $success = TRUE;
        if (!$filter_name) {
          throw new Exception('Filter name[' . $filter_name . '] cannot be empty in mode[stored].');
        }
        if (!($stored_filter = self::_readFilter($filter_name))) {
          $success = FALSE;
          if (!$formSubmitted) { // Don't put these errors twice.
            if ($stored_filter === FALSE) {
              drupal_set_message(
                t('The filter \'!name\' doesn\'t exist.', array('!name' => $filter_name)),
                'warning'
              );
            }
            else {
              drupal_set_message(
                t('You\'re not allowed to use the filter named \'!name\'.', array('!name' => $filter_name)),
                'warning'
              );
            }
          }
          $mode = 'default';
        }
        if ($success) {
          $filter = array(
            'origin' => '',
            'description' => $stored_filter['description'],
            'require_admin' => $require_admin = $stored_filter['require_admin'],
          );
          $fields_conditions =& self::$_fields['conditions'];
          $conditions = array();
          foreach ($fields_conditions as $name) {
            switch ($name) {
              case 'time_range':
              case 'time_from':
              case 'time_to':
              case 'role':
                $conditions[$name] = ($v = $stored_filter[$name]) > 0 ? $v : '';
              case 'uid':
                $conditions[$name] = ($v = $stored_filter[$name]) > 0 || $v === '0' || $v === 0 ? $v : '';
                break;
              case 'severity':
                if (!strlen($v = $stored_filter['severity'])) { // Deliberately not drupal_...().
                  $v = array('-1');
                }
                else {
                  $v = str_replace(',0,', ',zero,', ',' . $v . ',');
                  $v = explode(',', substr($v, 1, strlen($v) - 1)); // Deliberately not drupal_...().
                }
                $conditions['severity'] = $v;
                break;
              case 'type_wildcard':
                $conditions['type_wildcard'] = !$stored_filter['type'] ? TRUE : FALSE;
                break;
              case 'type':
                $conditions['type'] = ($v = $stored_filter['type']) ? explode(',', $v) : array();
                break;
              case 'time_from_proxy':
              case 'time_to_proxy':
                //  Set by frontend, if non-empty time_from/time_to
                $conditions[$name] = '';
                break;
              default:
                $conditions[$name] = $stored_filter[$name];
            }
          }
          unset($fields_conditions);
          $order_by = array();
          if (($v = $stored_filter['order_by'])) {
            $le = count($arr = explode(',', $v));
            for ($i = 0; $i < $le; $i++) {
              $v = explode(':', $arr[$i]);
              $order_by[] = array(
                $v[0],
                $v[1] == 'DESC' // ~ To boolean.
              );
            }
          }
          $title = $filter_name . (($v = $filter['description']) ? ('<span> - ' . $v . '</span>') : '');
        }
        else {
          $mode = 'default';
          $filter_name = 'default';
        }
        unset($stored_filter);
      }
      //  Do other modes.
      switch ($mode) {
        case 'default':
          $filter = array(
            'origin' => '',
            'description' => '',
            'require_admin' => FALSE,
          );
          $fields_conditions =& self::$_fields['conditions'];
          $conditions = array();
          foreach ($fields_conditions as $name) {
            switch ($name) {
              case 'severity':
                $conditions[$name] = array('-1');
                break;
              case 'type_wildcard':
                $conditions[$name] = TRUE;
                break;
              case 'type':
                $conditions[$name] = array();
                break;
              default:
                $conditions[$name] = '';
            }
          }
          unset($fields_conditions);
          $order_by = array(
            array('time', TRUE),
          );
          $title = t('Default');
          break;
        case 'adhoc':
          $filter =& $submitted['filter'];
          $conditions =& $submitted['conditions'];
          if (!$conditions['severity']) {
            $conditions['severity'] = array('-1');
          }
          $order_by =& $submitted['order_by'];
          $title = t('Ad hoc') . (($v = $filter['origin']) ? ('<span> - ' . t('based on !origin', array('!origin' => $v)) . '</span>') : '');
          break;
        case 'stored':
          //  Done earlier.
          break;
        case 'create':
        case 'edit':
        case 'delete_filter':
          throw new Exception('Mode[' . $mode . '] not allowed at form build.', self::$_errorCodes['algo']);
          break;
        default:
          throw new Exception('Unsupported mode[' . $mode . '].', self::$_errorCodes['algo']);
      }

      //  Prepare some fields.
      //  Type (frontend: type_some).
      if (($options_type = db_select('watchdog')
          ->fields('watchdog', array('type'))
          ->distinct()
          ->execute()->fetchCol())) {
        sort($options_type);
        foreach ($options_type as &$v) {
          $v = str_replace(array("\r", "\n", ','), ' ', $v);
        }
        unset($v); // Clear reference.
        $options_type = array_combine($options_type, $options_type);
        //  The filter may contain types that do not exist currently.
        $prepend_types = array();
        if ($conditions['type']) {
          foreach ($conditions['type'] as $v) {
            if ($v) {
              if (isset($options_type[$v])) {
                unset($options_type[$v]);
              }
              $prepend_types[$v] = $v;
            }
          }
          if ($prepend_types) {
            $options_type = array_merge($prepend_types, $options_type);
          }
        }
      }
      elseif ($conditions['type']) {
        $options_type = $conditions['type'];
      }
      else { // Make sure that there's always at least a single option.
        $options_type = array('php' => 'php');
      }
      //  Severity.
      $options_severity = array(
        '-1' => t('Any'),
        'zero' => t('emergency'),
        '1' => t('alert'),
        '2' => t('critical'),
        '3' => t('error'),
        '4' => t('warning'),
        '5' => t('notice'),
        '6' => t('info'),
        '7' => t('debug'),
      );
      //  Role.
      $options_role = user_roles();
      foreach ($options_role as &$v) {
        $v = t($v);
      }
      unset($v); // Clear reference.
      $options_role = array('' => t('Any')) + $options_role; // Union operator (+) doesnt re-index numerical keys like array_merge() does.
      //  Order by.
      $options_order_by = array(
        '' => '',
        'time' => t('Time'),
        'severity' => t('Severity'),
        'type' => t('Type'),
        'role' => t('User role'),
        'uid' => t('User ID'),
        'hostname' => t('Visitor\'s hostname'),
        'location' => t('Location'),
        'referer' => t('Referrer'),
      );
      $length_order_by = count($order_by);


      //  Only own filters.
      $value_only_own = $settings && array_key_exists('only_own', $settings) ? $settings['only_own'] : FALSE;

      //  Filter selector.
      $uid = $GLOBALS['user']->uid;
      if ( ($options_filters = self::_listFilters(!$value_only_own ? NULL : array($uid), array('name'), array(array('name')), $uid) ) ) {
        $js_filters = '["' . join('","', $options_filters) . '"]';
        $options_filters = array_merge(
          array('' => t('Default')),
          array_combine($options_filters, $options_filters)
        );
      }
      else {
        $js_filters = '[]';
        $options_filters = array('' => t('Default'));
      }

      //  Get current theme.
      $theme = $GLOBALS['theme'];

      //  Build form.
      $form['#attributes'] = array('autocomplete' => 'off');
      $form['log_filter_filter_edit'] = array(
        '#type' => 'fieldset',
        '#title' => t('Filter') . ': <span id="log_filter_title_display">' . $title . '</span>',
        '#collapsible' => TRUE,
        '#collapsed' => FALSE,
        'frontend_init' => array(
          '#type' => 'markup',
          '#markup' => '<script type="text/javascript"> LogFilter.init(' . (int)$use_module_css . ', "' . $theme . '"); </script>',
        ),
        //  Control vars.
        'log_filter_mode' => array(
          '#type' => 'hidden',
          '#default_value' => $mode,
        ),
        'log_filter_name' => array(
          '#type' => 'hidden',
          '#default_value' => $filter_name,
        ),
        'log_filter_origin' => array(
          '#type' => 'hidden',
          '#default_value' => $filter['origin'],
        ),
        //  Conditions.
        //  Time.
        'log_filter_time_range' => array( // (3 open)
          '#type' => 'textfield',
          '#title' => t('Preceding hours'),
          '#default_value' => $conditions['time_range'] ? $conditions['time_range'] : '',
          '#size' => 2,
          '#prefix' => '<div id="log_filter_criteria"><div class="filter-conditions"><div class="form-item log-filter-time">'
            . '<label>' . t('Time') . '</label>',
        ),
        'log_filter_time_from_proxy' => array(
          '#type' => 'textfield',
          '#title' => t('From') . '<span>?</span>',
          '#default_value' => '', // Frontend sets it, if non-empty time_from.
          '#size' => 10,
          '#prefix' => '<div class="log-filter-time-or">' . t('or') . '</div>',
        ),
        'log_filter_time_from' => array(
          '#type' => 'hidden',
          '#default_value' => $conditions['time_from'],
        ),
        'log_filter_time_to_proxy' => array(
          '#type' => 'textfield',
          '#title' => t('To'),
          '#default_value' => '', // Frontend sets it, if non-empty time_to.
          '#size' => 10,
        ),
        'log_filter_time_to' => array( // End: log-filter-time (2 open).
          '#type' => 'hidden',
          '#default_value' => $conditions['time_to'],
          '#suffix' => '</div>',
        ),
        //  Severity.
        'log_filter_severity' => array(
          '#type' => 'checkboxes',
          '#title' => t('Severity'),
          '#multiple' => TRUE,
          '#options' => $options_severity,
          '#default_value' => $conditions['severity'],
        ),
        //  Type.
        'log_filter_type_wildcard' => array( // (3 open).
          '#type' => 'checkbox',
          '#title' => t('Any'),
          '#default_value' => $conditions['type_wildcard'],
          '#prefix' => '<div class="form-item log-filter-type">'
            . '<label>' . t('Type') . '</label>',
        ),
        'log_filter_type_proxy' => array(
          '#type' => 'checkboxes',
          '#options' => $options_type,
          '#default_value' => array(),
          '#prefix' => '<div class="log-filter-type-container">',
        ),
        'log_filter_type' => array( // End: log-filter-type (2 open).
          '#type' => 'textarea',
          '#default_value' => join("\n", $conditions['type']),
          '#resizable' => FALSE,
          '#suffix' => '</div></div>',
        ),
        //  Various.
        'log_filter_role' => array( // (4 open).
          '#type' => 'select',
          '#title' => t('User role'),
          '#options' => $options_role,
          '#default_value' => $conditions['role'],
          '#prefix' => '<div class="form-item log-filter-various"><div class="log-filter-user">',
        ),
        'log_filter_uid' => array(
          '#type' => 'textfield',
          '#title' => t('ID'),
          '#default_value' => $conditions['uid'],
          '#size' => 11,
        ),
        'log_filter_username' => array( // End: log-filter-user (3 open).
          '#type' => 'textfield',
          '#title' => t('Name'),
          '#default_value' => $conditions['uid'],
          '#size' => 20,
          // Can't use Drupal Form API autocomplete, because we need to pass value to the uid field upon selection.
          '#attributes' => array(
            'class' => array('form-autocomplete'),
          ),
          '#suffix' => '</div>',
        ),
        'log_filter_hostname' => array(
          '#type' => 'textfield',
          '#title' => t('Visitor\'s hostname') . '<span title="' . t('Use * to display in event list, without filtering') . '">?</span>',
          '#default_value' => $conditions['hostname'],
          '#size' => 64,
        ),
        'log_filter_location' => array(
          '#type' => 'textfield',
          '#title' => t('Location') . '<span title="' . t('Use * to display in event list, without filtering') . '">?</span>',
          '#default_value' => $conditions['location'],
          '#size' => 64,
        ),
        'log_filter_referer' => array( // End: filter-conditions, (1 open).
          '#type' => 'textfield',
          '#title' => t('Referrer') . '<span title="'
            . t('Use \'none\' for empty referrer.!nlUse * to display in event list, without filtering.', array('!nl' => "\n"))
            . '">?</span>',
          '#default_value' => $conditions['referer'],
          '#size' => 64,
          '#suffix' => '</div></div>',
        ),
        //  Order by.
        'log_filter_orderby_1' => array( // (2 open)
          '#type' => 'select',
          '#options' => $options_order_by,
          '#default_value' => $length_order_by ? array($order_by[0][0]) : array(),
          '#prefix' => '<div class="filter-orderby"><label>' . t('Order by') . '</label>',
        ),
        'log_filter_descending_1' => array(
          '#type' => 'checkbox',
          '#default_value' => $length_order_by ? $order_by[0][1] : FALSE,
          '#attributes' => array(
            'title' => t('Descending'),
          ),
        ),
        'log_filter_orderby_2' => array(
          '#type' => 'select',
          '#options' => $options_order_by,
          '#default_value' => $length_order_by > 1 ? array($order_by[1][0]) : array(),
        ),
        'log_filter_descending_2' => array(
          '#type' => 'checkbox',
          '#default_value' => $length_order_by > 1 ? $order_by[1][1] : FALSE,
          '#attributes' => array(
            'title' => t('Descending'),
          ),
        ),
        'log_filter_orderby_3' => array(
          '#type' => 'select',
          '#options' => $options_order_by,
          '#default_value' => $length_order_by > 2 ? array($order_by[2][0]) : array(),
        ),
        'log_filter_descending_3' => array(
          '#type' => 'checkbox',
          '#default_value' => $length_order_by > 2 ? $order_by[2][1] : FALSE,
          '#attributes' => array(
            'title' => t('Descending'),
          ),
        ),
        'log_filter_reset' => array( // End: log-filter-reset, filter-orderby, log_filter_criteria (0 open).
          '#type' => 'button',
          '#name' => 'log_filter_reset',
          '#value' => t('Reset'),
          '#button_type' => 'button', // Doesnt work; still type:submit.
          '#attributes' => array(
            'type' => 'button', // Doesnt work; still type:submit.
            'class' => array('form-submit', 'edit-reset'),
          ),
          '#prefix' => '<div class="log-filter-reset">',
          '#suffix' => '</div></div></div>',
        ),
        //  Filters.
        array(
          '#type' => 'markup',
          '#markup' => '<div id="log_filter_filters"><div id="log_filter_box_filter"><div id="log_filter_filters_cell_0">',
        ),
        'log_filter_filter' => array( // (2 open)
          '#type' => 'select',
          '#title' => t('Filter'),
          '#options' => $options_filters,
          '#default_value' => $filter_name,
        ),
        'log_filter_only_own' => array(
          '#access' => $allow_filter_edit,
          '#type' => 'checkbox',
          '#title' => t('List my filters only'),
          '#default_value' => $value_only_own,
        ),
        array(
          '#type' => 'markup',
          '#markup' => '</div>' // End: log_filter_filters_cell_0
            . '<div id="log_filter_filters_cell_1">',
        ),
        'log_filter_name_suggest' => array(
          '#access' => $allow_filter_edit,
          '#type' => 'textfield',
          '#title' => t('Name'),
          '#default_value' => '', // Only used frontend.
          '#size' => 32,
          '#attributes' => array(
            'maxlength' => 32,
          ),
        ),
        'log_filter_require_admin' => array(
          '#access' => $allow_filter_edit && $user_admin_permission,
          '#type' => 'checkbox',
          '#title' => t('Restrict access') . '<span title="' . ($title = t('Require the \'Administer log filtering\' permission.')) . '">?</span>',
          '#default_value' => $require_admin,
          '#attributes' => array(
            'title' => $title,
          ),
        ),
        array( // End: log_filter_filters_cell_1
          '#type' => 'markup',
          '#markup' => '</div>',
        ),
        'log_filter_description' => array(
          '#access' => $allow_filter_edit,
          '#type' => 'textarea',
          '#title' => t('Description'),
          '#default_value' => $filter['description'],
          '#rows' => 3,
          '#cols' => 32,
          '#resizable' => FALSE, // Otherwise styling too complicated, and browsers support it natively.
        ),
        array( // (3 open)
          '#type' => 'markup',
          '#markup' => '<div class="log-filter-edit-create">',
        ),
        'log_filter_edit' => array(
          '#access' => $allow_filter_edit,
          '#type' => 'button',
          '#name' => 'log_filter_edit',
          '#value' => t('Edit'),
          '#button_type' => 'button', // Doesnt work; still type:submit.
          '#attributes' => array(
            'type' => 'button', // Doesnt work; still type:submit.
            'class' => array('form-submit'),
            'style' => 'display:none;',
          ),
        ),
        'log_filter_create' => array( // (2 open)
          '#access' => $allow_filter_edit,
          '#type' => 'button',
          '#name' => 'log_filter_create',
          '#value' => t('Save as...'),
          '#button_type' => 'button', // Doesnt work; still type:submit.
          '#attributes' => array(
            'type' => 'button', // Doesnt work; still type:submit.
            'class' => array('form-submit'),
            'style' => 'display:none;',
          ),
        ),
        array(
          '#type' => 'markup',
          '#markup' => '</div>' // End. log-filter-edit-create
            . '<div class="log-filter-cancel-save'
            . (strpos(strtolower(PHP_OS), 'win') === 0 ? ' log-filter-reversed-button-sequence' : '') // Deliberately not drupal_...().
            . '">',
        ),
        'log_filter_cancel' => array( // (3 open)
          '#access' => $allow_filter_edit,
          '#type' => 'button',
          '#name' => 'log_filter_cancel',
          '#value' => t('Cancel'),
          '#button_type' => 'button', // Doesnt work; still type:submit.
          '#attributes' => array(
            'type' => 'button', // Doesnt work; still type:submit.
            'class' => array('form-submit', 'edit-cancel'),
            'style' => 'display:none;',
          ),
        ),
        'log_filter_save' => array(
          '#access' => $allow_filter_edit,
          '#type' => 'button',
          '#name' => 'log_filter_save',
          '#value' => t('Save'),
          '#button_type' => 'button', // Doesnt work; still type:submit.
          '#attributes' => array(
            'type' => 'button', // Doesnt work; still type:submit.
            'class' => array('form-submit'),
            'style' => 'display:none;',
          ),
        ),
        array(
          '#type' => 'markup',
          '#markup' => '</div>' // End: log-filter-cancel-save
            . '<div class="log-filter-delete">',
        ),
        'log_filter_delete' => array(
          '#access' => $allow_filter_edit,
          '#type' => 'button',
          '#name' => 'log_filter_delete',
          '#value' => t('Delete filter'),
          '#button_type' => 'button', // Doesnt work; still type:submit.
          '#attributes' => array(
            'type' => 'button', // Doesnt work; still type:submit.
            'class' => array('form-submit', 'edit-delete'),
            'style' => 'display:none;',
          ),
        ),
        array(
          '#type' => 'markup',
          '#markup' => '</div>' // End: log-filter-delete
            . '</div>', // End: log_filter_box_filter
        ),
        array(
          '#access' => ($allow_delete_logs = user_access('log_filter remove logs')),
          '#type' => 'markup',
          '#markup' => '<div id="log_filter_box_delete_logs">',
        ),
        array(
          '#access' => !$allow_delete_logs,
          '#type' => 'markup',
          '#markup' => '<div id="log_filter_box_delete_logs" class="log-filter-delete-logs-none">&nbsp;',
        ),
        array( // (2 open)
          '#access' => $allow_delete_logs,
          '#type' => 'button',
          '#name' => 'log_filter_delete_logs_button',
          '#value' => t('Delete logs'),
          '#button_type' => 'button', // Doesnt work; still type:submit.
          '#attributes' => array(
            'type' => 'button', // Doesnt work; still type:submit.
            'class' => array('form-submit', 'edit-delete'),
            'style' => 'display:none;',
          ),
        ),
        array(
          '#access' => $allow_delete_logs,
          '#type' => 'textfield',
          '#name' => 'log_filter_delete_logs_max',
          '#title' => t('Max.'),
          '#default_value' =>  $settings && array_key_exists('delete_logs_max', $settings) ? $settings['delete_logs_max'] : '',
          '#attributes' => array(
            'maxlength' => 11,
          ),
        ),
        array(
          '#type' => 'markup',
          '#markup' => '</div>' // End: log_filter_box_delete_logs
            . '</div>', // End: log_filter_filters
        ),
      );

      $form['log_filter_list_controls'] = array(
        'frontend_setup' => array(
          '#type' => 'markup',
          '#markup' => '<script type="text/javascript">
(function($) {
  if(!$) {
    return;
  }
  $(document).bind("ready", function() {
    var elm;
    // t() ruins this, because of some hocus pocus.
    $("div.form-item-log-filter-time-from-proxy label").get(0).setAttribute("title", "'
      . t('Date format: YYYY-MM-DD!newlineTime formats: N, NN, NNNN, NNNNNN, NN:NN, NN:NN:NN') . '".replace(/\!newline/, "\n"));
    // Go.
    LogFilter.setup(
      ' . $js_filters . ',
      ' . ($messages ? json_encode($messages) : 'null') . '
    );
  } );
})(jQuery);
</script>
',
        ),
        'log_filter_update_list' => array(
          '#type' => 'button',
          '#name' => 'log_filter_update_list',
          '#value' => t('Update list'),
          '#button_type' => 'button', // Doesnt work; still type:submit.
          '#attributes' => array(
            'class' => array('form-submit'),
            'title' => t('[CTR + U / CMD + U]'),
          ),
          '#prefix' => '<div class="log-filter-button log-filter-update-list">',
          '#suffix' => '</div>',
        ),
        'log_filter_pager_controls' => array(
          '#type' => 'markup',
          '#markup' => '<div class="log-filter-pager-controls">'
            . '<div id="log_filter_pager_first" class="log-filter-pager-button log-filter-pager-button-disabled" title="'
              . t('First') . '">&#x25c4;&#x25c4;</div>'
            . '<div id="log_filter_pager_previous" class="log-filter-pager-button log-filter-pager-button-disabled" title="'
              . t('Previous') . '">&#x25c4;</div>'
            . '<div id="log_filter_pager_current" title="' . t('Update list') . '">&nbsp;</div>'
            . '<div id="log_filter_pager_progress" class="ajax-progress"><div class="throbber"></div>' . t('Loading...') . '</div>'
            . '<div id="log_filter_pager_next" class="log-filter-pager-button log-filter-pager-button-disabled" title="'
              . t('Next') . '">&#x25ba;</div>'
            . '<div id="log_filter_pager_last" class="log-filter-pager-button log-filter-pager-button-disabled" title="'
              . t('Last') . '">&#x25ba;&#x25ba;</div>'
            . '</div>',
        ),
        'log_filter_pager_range' => array(
          '#type' => 'textfield',
          '#title' => t('Logs per page'),
          '#default_value' => $settings && array_key_exists('pager_range', $settings) && $settings['pager_range'] > 0 ?
            $settings['pager_range'] : variable_get('log_filter_pgrng', self::PAGE_RANGE_DEFAULT),
          '#size' => 4,
        ),
        'log_filter_translate' => array(
          '#type' => 'checkbox',
          '#title' => t('Translate messages') . '<span title="' . ($title = t('Translating messages is heavy performance-wise.')) . '">?</span>',
          '#default_value' => $settings && array_key_exists('translate', $settings) ? $settings['translate'] : variable_get('log_filter_trnslt', 0),
          '#attributes' => array(
            'title' => $title,
          ),
        ),
        'actions' => array(
          '#type' => 'actions',
          'submit' => array(
            '#type' => 'submit',
            '#value' => t('Update list'),
            '#attributes' => array('style' => 'display:none;'),
          ),
        ),
        '#prefix' => '<div id="log_filter_list_controls">',
        '#suffix' => '</div>',
      );

      $logList = '';
      for ($i = 97; $i < 97 + 26; $i++) {
        //$logList .= '<div class="' . str_repeat(chr($i), 3) . '">' . str_repeat(chr($i), 3) . '</div>';
      }


      $form['log_filter_log_list'] = array(
        '#type' => 'markup',
        '#markup' => '<div id="log_filter_log_list" class="scrollable">' . $logList . '</div>',
      );

      //  Add our submit form;
      $form['#submit'][] = '_log_filter_form_submit';
      return $form;
    }
    catch (Exception $xc) {
      self::_errorHandler($xc);
      drupal_set_message($xc->getMessage(), 'error');
      return array();
    }
  }

  /**
   * Called when log viewer form submits.
   *
   * @param array $form
   * @param array &$form_state
   * @return void
   */
  public static function viewerFormSubmit($form, &$form_state) {
    try {
      $values =& $form_state['values'];
      $prefix = 'log_filter_';

      $messages = array();

      $settings = array(
        'only_own' => !array_key_exists($prefix . 'only_own', $values) ? FALSE : $values[$prefix . 'only_own'],
        'delete_logs_max' => !array_key_exists($prefix . 'delete_logs_max', $values) ? '' : $values[$prefix . 'delete_logs_max'],
        'translate' => $values[$prefix . 'translate'],
        'only_own' => !array_key_exists($prefix . 'only_own', $values) ? FALSE : $values[$prefix . 'only_own'],
        'pager_range' => ($v = (int)$values[$prefix . 'pager_range']) > -1 ? ($v > self::PAGE_RANGE_MAX ? self::PAGE_RANGE_MAX : $v) :
          variable_get('log_filter_pgrng', self::PAGE_RANGE_DEFAULT),
      );

      $submitted = array(
        'mode' => $values[$prefix . 'mode'],
        'filter' => array(
          'name' => '',
          'origin' => '',
          'name_suggest' => '',
          'description' => '',
          'require_admin' => !array_key_exists($prefix . 'require_admin', $values) ? FALSE : $values[$prefix . 'require_admin'],
        ),
      );

      $use_form_values = $save = FALSE;
      switch (($mode = $submitted['mode'])) {
        case 'default':
          //  Use default values.
          break;
        case 'adhoc':
          //  Get specs from form.
          $use_form_values = TRUE;
          $submitted['filter']['origin'] = $values[$prefix . 'origin']; // ~ Hidden field.
          break;
        case 'stored': // Saved filter.
          //  Just get filter name; in stored mode we do absolutely nothing at submission but establishing the filter's name.
          //  Whether the filter require_admin and user has that permission will be checked at form build - no reason to check twice.
          if (!($submitted['filter']['name'] = $filter_name = $values[$prefix . 'name'])) {
            throw new Exception('Mode[' . $mode . '], empty name[' . $filter_name . '].', self::$_errorCodes['filter_name_composition']);
          }
          break;
        case 'create': // Always AJAX-handled.
          throw new Exception('Mode[' . $mode . '] not allowed at form submission.', self::$_errorCodes['algo']);
          break;
        case 'edit':
        case 'delete_filter':
          //  Get name.
          if (!($submitted['filter']['name'] = $filter_name = $values[$prefix . 'name'])) {
            throw new Exception('Mode[' . $mode . '], empty name[' . $filter_name . '].', self::$_errorCodes['filter_name_composition']);
          }
          $success = TRUE;
          //  Check CRUD permission.
          if (!user_access('log_filter edit filters')) {
            $success = FALSE;
            //  Horrible; have to make almost exactly same message, because of shortcomings of the localization regime.
            switch ($mode) {
              case 'edit':
                watchdog(
                  'log_filter',
                  'Won\'t edit the filter \'!name\' because user !user doesn\'t have \'log_filter edit filters\' permission.',
                  array('!name' => $filter_name, '!user' => $GLOBALS['user']->name),
                  WATCHDOG_WARNING
                );
                drupal_set_message(
                  t('Cannot edit the filter \'!name\', because you don\'t have permission to edit log filters.', array('!name' => $filter_name)),
                  'warning'
                );
                break;
              default: // delete
                watchdog(
                  'log_filter',
                  'Won\'t delete the filter \'!name\' because user !user doesn\'t have \'log_filter edit filters\' permission.',
                  array('!name' => $filter_name, '!user' => $GLOBALS['user']->name),
                  WATCHDOG_WARNING
                );
                drupal_set_message(
                  t('Cannot delete the filter \'!name\', because you don\'t have permission to edit log filters.', array('!name' => $filter_name)),
                  'warning'
                );
            }
          }
          //  Check if exists, and get require_admin field.
          elseif (!($require_admin = db_select('log_filter')
            ->fields('log_filter', array('require_admin'))
            ->condition('name', $filter_name, '=')
            ->execute()->fetchField())
          ) {
            if ($require_admin === FALSE) { // Doesn't exist.
              $success = FALSE;
              /* drupal_set_message(
                  t('The filter \'!name\' doesn\'t exist.', array('!name' => $filter_name)),
                  'warning'
              ); */
              $messages[] = array(
                  t('The filter \'!name\' doesn\'t exist.', array('!name' => $filter_name)),
                  'warning'
              );
            }
            //  else... the filter doesnt require admin permission.
          }
          elseif (!user_access('log_filter administer')) {
            $success = FALSE;
          }
          if ($success) {
            switch ($mode) {
              case 'edit':
                //  Get specs from form, and save to database.
                $use_form_values = TRUE;
                $save = TRUE;
                $submitted['filter']['description'] = $values[$prefix . 'description'];
                //  Change mode.
                $submitted['mode'] = $mode = 'stored';
                break;
              default: // delete
                global $user;
                db_delete('log_filter')->condition('name', $filter_name, '=')->execute();
                watchdog(
                  'log_filter',
                  'User (%uid) %name deleted the log filter \'!filter\'.',
                  array('%uid' => $user->uid, '%name' => $user->name, '!filter' => $filter_name),
                  WATCHDOG_INFO
                );
                $messages[] = array(
                    t('Deleted the filter \'!name\'.', array('!name' => $filter_name))
                );
                //  Change mode.
                $submitted['mode'] = $mode = 'default';
            }
          }
          else {
            $use_form_values = $save = FALSE;
            //  Change mode.
            $submitted['mode'] = $mode = 'default';
          }
          break;
        default:
          throw new Exception('Unsupported mode[' . $mode . '].', self::$_errorCodes['algo']);
      }

      //  Load values from form.
      if ($use_form_values) {
        $fields_conditions =& self::$_fields['conditions'];
        $conditions = array();
        foreach ($fields_conditions as $name) {
          switch ($name) {
            case 'time_range':
              $conditions[$name] = ($v = trim($values[$prefix . $name])) ? $v : '';
              break;
            case 'role':
              $conditions[$name] = ($v = trim($values[$prefix . $name])) > 0 ? $v : -1;
              break;
            case 'uid': // Accepts zero.
              $conditions[$name] = ($v = trim($values[$prefix . $name])) > 0 || $v === '0' || $v === 0 ? $v : -1;
              break;
            case 'time_from':
              $conditions[$name] = $conditions['time_range'] ? '' : (($v = trim($values[$prefix . $name])) ? $v : '');
              break;
            case 'time_from_proxy':
              if (!$save) { // Because save doesnt use the proxy field.
                $conditions[$name] = !$conditions['time_from'] ? '' : $values[$prefix . $name];
              }
              break;
            case 'time_to':
              $conditions[$name] = $conditions['time_range'] ? '' : (($v = trim($values[$prefix . $name])) ? $v : '');
              break;
            case 'time_to_proxy':
              if (!$save) { // Because save doesnt use the proxy field.y
                $conditions[$name] = !$conditions['time_to'] ? '' : $values[$prefix . $name];
              }
              break;
            case 'severity':
              $arr = $values[$prefix . $name];
              $vals = array();
              foreach ($arr as $k => $v) {
                if ($v) {
                  if ('' . $k == '-1') {
                    $vals = array();
                    break;
                  }
                  else {
                    $vals[] = $k;
                  }
                }
              }
              $conditions[$name] = $vals;
              break;
            case 'type_wildcard':
              $conditions[$name] = $values[$prefix . $name] ? TRUE : FALSE;
              break;
            case 'type':
              //  Dont remember type list (may be very long), if wildcard on.
              $conditions[$name] = $conditions['type_wildcard'] ? array() :
                array_combine($a = explode("\n", str_replace("\r", '', $values[$prefix . $name])), $a);
              if ($save) {
                unset($conditions['type_wildcard']);
              }
              break;
            default:
              $conditions[$name] = trim($values[$prefix . $name]);
          }
        }
        unset($fields_conditions);
        $submitted['conditions'] =& $conditions;

        $fields_order_by =& self::$_fields['order_by'];
        $order_by = array();
        for ($i = 1; $i < 10; $i++) {
          if (array_key_exists($key = $prefix . $fields_order_by[0] . $i, $values)) {
            if (($key = $values[ $key ])) {
              if (!$save) {
                $order_by[] = array($key, $values[ $prefix . $fields_order_by[1] . $i ]);
              }
              else {
                $order_by[] = array($key, $values[ $prefix . $fields_order_by[1] . $i ] ? 'DESC' : 'ASC');
              }
            }
          }
          else {
            break;
          }
        }
        $submitted['order_by'] =& $order_by;
        unset($order_by, $fields_order_by);
      }
      if ($save) { // edit mode.
        $success = TRUE;
        try {
          self::_saveFilter($filter_name, $submitted);
        }
        catch (Exception $xc) {
          self::_errorHandler($xc);
          $success = FALSE;
          $messages[] = array(
            t('Failed to update filter \'!name\'.', array('!name' => $filter_name)),
            'warning'
          );
        }
        //  Change mode.
        if ($success) {
          $submitted['mode'] = $mode = 'stored';
        }
        else {
          $submitted['mode'] = $mode = 'default';
        }
      }

      //  Clear conditions and order_by from vars to be passed to session, unless adhoc filter.
      if ($mode != 'adhoc') {
        unset( $submitted['conditions'], $submitted['order_by'] );
      }

      //  Pass to session.
      $session = array('settings' => $settings, 'submitted' => $submitted);
      if ($messages) {
        $session['messages'] = $messages;
      }
      if (module_exists('state')) {
        State::sessionSet('module', 'log_filter', $session);
      }
      else {
        drupal_session_start();
        if (!isset($_SESSION['module'])) {
          $_SESSION['module'] = array(
            'log_filter' => $session,
          );
        }
        else {
          $_SESSION['module']['log_filter'] = $session;
        }
      }
    }
    catch (Exception $xc) {
      self::_errorHandler($xc);
      drupal_set_message($xc->getMessage(), 'error');
    }
  }

  /**
   * Filters off restricted filters if current user isnt allowed to administer filters.
   *
   * @throws PDOException
   * @param integer|string|array|NULL $creatorIds
   *  - default: NULL (~ any user)
   *  - integer|string: list only filters created by that user
   *  - array: list only filters created by those users
   * @param array|NULL $fields
   *  - default: all fields
   * @param arrayNULL $orderBy
   *  - default: unordered
   *  - array: multi-dimensional; every bucket being an array listing field name and 'ASC'|'DESC'
   * @param integer|string|NULL $latestAtTop
   *  - default: not
   *  - user id: place lastest changed of that user at the very top of the list (requires that $fields is falsy or has 'name' bucket)
   * @return array
   */
  protected static function _listFilters($creatorIds = NULL, $fields = NULL, $orderBy = NULL, $latestAtTop = NULL) {
    $uid = $GLOBALS['user']->uid;

    if ( ($creatorIds && !is_array($creatorIds)) || (!$creatorIds && $creatorIds !== NULL)) {
      $creatorIds = array($creatorIds);
    }

    $list = db_select('log_filter')
      ->fields('log_filter', $fields ? $fields : array('*'));

    if ($creatorIds) {
      $list->condition('creator', $creatorIds, 'IN');
    }
    if (!user_access('log_filter administer')) {
      $list->condition('require_admin', 0);
    }
    if ($orderBy) {
      foreach ($orderBy as $subArr) {
        $list->orderBy($subArr[0], !empty($subArr[1]) ? $subArr[1] : 'ASC');
      }
    }
    $list = ($singleColumned = ($fields && count($fields) == 1)) ? $list->execute()->fetchCol() : $list->execute()->fetchAll();

    if ($list && $latestAtTop !== NULL
      && (!$creatorIds || in_array($latestAtTop, $creatorIds))
      && (!$fields || in_array('name', $fields))
    ) {
      if (($listLatest = db_select('log_filter')
        ->fields('log_filter', array('name', 'changed'))
        ->condition('editor', $latestAtTop, '=')
        ->execute()
        ->fetchAll()
      )) {
        $latestChange = $latestName = 0;
        foreach ($listLatest as $subObj) {
          if ($subObj->changed > $latestChange) {
            $latestChange = $subObj->changed;
            $latestName = $subObj->name;
          }
        }
        if ($latestName) {
          if ($singleColumned) {
            if (($index = array_search($latestName, $list))) { // No need to check !== FALSE, because if zero there's nothing to be done.
              array_splice($list, $index, 1);
              array_unshift($list, $latestName);
            }
          }
          else {
            $index = 0;
            foreach ($list as $k => $subObj) {
              if ($subObj->name == $latestName) {
                $index = $k;
                break;
              }
            }
            if ($index) {
              $latest = array_splice($list, $index, 1);
              array_unshift($list, $latest);
            }
          }
        }
      }
    }
    return $list;
  }

  /**
   * Checks if the filter requires log_filter administrative permission and whether the user has that permission.
   *
   * @throws PDOException
   * @param string $name
   * @return array|boolean|NULL
   *  - FALSE: the filter doesnt exist
   *  - NULL: user not allowed to use that filter
   */
  protected static function _readFilter($name) {
    return !(
      $filter = db_select('log_filter')
      ->fields('log_filter')
      ->condition('name', $name, '=')
      ->execute()->fetchAssoc()
    ) ? FALSE : $filter['require_admin'] && !user_access('log_filter administer') ? NULL : $filter;
  }

  /**
   * Insert/update filter in database.
   *
   * @throws Exception
   * @param string $name
   * @param array $values
   * @param boolean $create
   *  - default: FALSE
   * @return void
   *  - throws error on failure
   */
  protected static function _saveFilter($name, $values, $create = FALSE) {
    $uid = $GLOBALS['user']->uid;

    if (!user_access('log_filter edit filters')) {
      throw new Exception(
        'You\'re not allowed to edit filters.',
        self::$_errorCodes['perm_filter_crud']
      );
    }

    //  Filter metadata and last updated by.
    $fields = array(
      'editor' => $uid,
      'changed' => REQUEST_TIME,
      'require_admin' => !empty($values['filter']['require_admin']) ? 1 : 0,
      'description' => $values['filter']['description'],
    );
    if ($create) {
      $fields['creator'] = $uid;
      $fields['created'] = REQUEST_TIME;
    }

    //  Conditions.
    $names =& self::$_fields['conditions'];
    $conditions =& $values['conditions'];
    foreach ($names as $key) {
      switch ($key) {
        case 'severity':
          if (!empty($conditions[$key])) {
            if (!is_array($v = $conditions[$key])) {
              throw new Exception('Non-empty condition[' . $key . '], type[' . gettype($v) . '], must be array.',
                self::$_errorCodes['bad_filter_condition']);
            }
            //  Use array values, but convert 'zero' to zero.
            //  And make sure it's all integers.
            $fields[$key] = preg_replace('/[^\d,]/', '', str_replace('zero', '0', join(',', $v)));
          }
          else {
            $fields[$key] = '';
          }
          break;
        case 'type':
          if (!empty($conditions[$key])) {
            if (!is_array($v = $conditions[$key])) {
              throw new Exception('Non-empty condition[' . $key . '], type[' . gettype($v) . '], must be array.',
                self::$_errorCodes['bad_filter_condition']);
            }
            //  Use array values, because key is simply numeric index.
            $fields[$key] = check_plain(join(',', $v));
          }
          else {
            $fields[$key] = '';
          }
          break;
        case 'time_range':
          $fields[$key] = !empty($conditions[$key]) && ($v = (int)$conditions[$key]) > 0 && $v < 10000 ? $v : 0;
          break;
        case 'time_from':
        case 'time_to':
          $fields[$key] = !empty($conditions[$key]) && ($v = (int)$conditions[$key]) > 0 && $v <= PHP_INT_MAX ? $v : 0;
          break;
        case 'role':
        case 'uid':
          $fields[$key] = array_key_exists($key, $conditions) ? (int)$conditions[$key] : -1;
          break;
        case 'hostname':
        case 'location':
        case 'referer':
          $fields[$key] = !empty($conditions[$key]) ? check_plain($conditions[$key]) : '';
          break;
        default:
          //  Ignore.
      }
    }

    //  Order by.
    $order_by = '';
    if (!empty($values['order_by'])) {
      $order_by = array();
      foreach ($values['order_by'] as $k => $v) {
        if (preg_match('/^[a-z\d_]{2,32}$/', $k) && ($v === 'DESC' || $v === 'ASC')) {
          $order_by[] = $k . ':' . $v;
        }
      }
      $fields['order_by'] = join(',', $order_by);
    }
    else {
      $fields['order_by'] = '';
    }

    //  Use unique key on name column for testing uniqueness.
    if ($create) {
      $fields['name'] = $name;
      try {
        db_insert('log_filter')
          ->fields($fields)
          ->execute();
      }
      catch (PDOException $xc) {
        if ((int)$xc->getCode() == 23000) { // Fair chance that it's a duplicate key error, though 23000 may also (MySQL) mean null error.
          throw new Exception('Filter name[' . $name . '] already exists.', self::$_errorCodes['filter_name_nonunique']);
        }
        else {
          throw $xc;
        }
      }
    }
    elseif (!($filter = self::_readFilter($name))) {
      if ($filter === FALSE) {
        throw new Exception('Filter name[' . $name . '] doesnt exist.', self::$_errorCodes['filter_doesnt_exist']);
      }
      throw new Exception('User (' . $uid . ') ' . $GLOBALS['user']->name . ' is not allowed to use filter[' . $name . '].',
          self::$_errorCodes['perm_filter_restricted']);
    }
    elseif (
      !db_update('log_filter')
        ->fields($fields)
        ->condition('name', $name)
        ->execute()
    ) {
      throw new Exception('Failed to update filter[' . $name . '].', self::$_errorCodes['unknown']);
    }
  }

  /**
   * @param array &$conditions
   *  - empty or invalid conditions will be removed from the array
   * @param array $order_by
   * @param integer $offset
   *  - default: zero
   *  - ignored until MySQL supports LIMIT for sub queries
   * @param integer $max
   *  - default: zero
   *  - ignored until MySQL supports LIMIT for sub queries
   * @param array|NULL|boolean $log_columns
   *  - default: NULL (~ all watchdog columns)
   *  - FALSE: count only
   * @param array|boolean $user_columns
   *  - default: FALSE (~ no user columns)
   * @param boolean $deletion
   *  - default: FALSE (~ not for deleting logs)
   * @return SelectQuery|SelectQueryInterface
   * @throws Exception
   *  - PDOException
   */
  protected static function _logListQuery(&$conditions, $order_by, $offset = 0, $max = 0, $log_columns = NULL, $user_columns = FALSE, $deletion = FALSE) {
    $query = db_select('watchdog', 'w');
    if ($user_columns) {
      $query->leftJoin('users', 'u', 'w.uid = u.uid');
    }
    if (!$log_columns) {
      if ($log_columns !== FALSE) {
        $query->fields('w'); // Wildcard columns.
        //->fields('w', array('wid', 'uid', 'type', 'message', 'variables', 'severity', 'link', 'location', 'referer', 'hostname', 'timestamp'))
      }
    }
    else {
      $query->fields('w', $log_columns);
    }
    if ($user_columns) {
      $le = count($user_columns);
      for ($i = 0; $i < $le; $i++) {
        $query->addField('u', $user_columns[$i]);
      }
    }
    //  Conditions.
    if ($deletion || $conditions) {
      // The wid (log id) condition is not part of the overall used conditions, so we have to handle it differently.
      // @todo: Explain just how, the code is certainly not self-explanatory in this sense.
      $wid = 0;
      if (isset($conditions['wid'])) {
        if (($v = (int)$conditions['wid']) && $v > -1 && $v <= PHP_INT_MAX) {
          $wid = $v;
          $query->condition('w.' . 'wid', $v, '=');
          // Remove all other conditions.
          array_splice($conditions, 0);
          $conditions['wid'] = $wid;
        }
        else {
          unset($conditions['wid']);
        }
      }
      if (!$wid) {
        $names =& self::$_fields['conditions'];

        // Use user id instead of role (anonymous user role doesnt really exists - only as a lack of any roles)?
        $is_anonymous = $not_anonymous = FALSE;
        if (isset($conditions['role'])) {
          switch ($conditions['role']) {
            case DRUPAL_ANONYMOUS_RID:
              $is_anonymous = TRUE;
              $conditions['uid'] = 0;
              break;
            case DRUPAL_AUTHENTICATED_RID:
              $not_anonymous = TRUE;
              $conditions['uid'] = 0;
              break;
          }
        }

        // Deleting events that log deletion of events is illegal.
        if ($deletion) {
          if (!empty($conditions['type']) && ($index = array_search('log_filter delete logs', $conditions['type'], TRUE)) !== FALSE) {
            if (count($conditions['type']) == 1) {
              unset($conditions['type']);
            }
            else {
              array_splice($conditions['type'], $index, 1);
            }
          }
          $query->condition('w.' . 'type', 'log_filter delete logs', '!=');
        }

        foreach ($names as $key) {
          if (isset($conditions[$key])) {
            if (!($v = $conditions[$key]) && $key != 'uid') {
              unset($conditions[$key]);
            }
            else {
              switch ($key) {
                case 'severity':
                  if (!is_array($v)) {
                    throw new Exception('Non-empty condition[' . $key . '], type[' . gettype($v) . '], must be array.',
                      self::$_errorCodes['bad_filter_condition']);
                  }
                  //  Convert 'zero' to zero.
                  $query->condition('w.' . $key, explode(',', str_replace('zero', '0', join(',', $v))), 'IN');
                  break;
                case 'type':
                  if (!is_array($v)) {
                    throw new Exception('Non-empty condition[' . $key . '], type[' . gettype($v) . '], must be array.',
                      self::$_errorCodes['bad_filter_condition']);
                  }
                  $query->condition('w.' . $key, explode(',', check_plain(join(',', $v))), 'IN');
                  break;
                case 'time_range':
                  if (($v = (int)$v) > 0 && $v < 10000) {
                    $query->condition('w.' . 'timestamp', REQUEST_TIME - ($v * 60 * 60), '>=');
                  }
                  else {
                    unset($conditions[$key]);
                  }
                  break;
                case 'time_from':
                  if (($v = (int)$v) > 0 && $v <= PHP_INT_MAX) {
                    $query->condition('w.' . 'timestamp', $v, '>=');
                  }
                  else {
                    unset($conditions[$key]);
                  }
                  break;
                case 'time_to':
                  if (($v = (int)$v) > 0 && $v <= PHP_INT_MAX) {
                    $query->condition('w.' . 'timestamp', $v, '<=');
                  }
                  else {
                    unset($conditions[$key]);
                  }
                  break;
                case 'role':
                  if (($v = (int)$v) > 0 && $v <= PHP_INT_MAX) {
                    if (!$is_anonymous && !$not_anonymous) {
                      $query->join('users_roles', 'ur', 'w.uid = ur.uid AND ur.rid = :rid', array(':rid' => $v));
                    }
                  }
                  else {
                    unset($conditions[$key]);
                  }
                  break;
                case 'uid':
                  if (($v = (int)$v) > -1 && $v <= PHP_INT_MAX) {
                    $query->condition('w.' . $key, $v, !$not_anonymous ? '=' : '!=');
                  }
                  else {
                    unset($conditions[$key]);
                  }
                  break;
                case 'hostname':
                case 'location':
                  if (($v = trim(check_plain($v))) && $v !== '*') {
                    $query->condition('w.' . $key, $v, '=');
                  }
                  else {
                    unset($conditions[$key]);
                  }
                  break;
                case 'referer': // Support strictly empty value 'none'
                  if (($v = trim(check_plain($v))) && $v !== '*') {
                    if ($v != 'none') {
                      $query->condition('w.' . $key, $v, '=');
                    }
                    else {
                      $query->condition(db_or()->condition('w.' . $key, '', '=')->isNull('w.' . $key));
                    }
                  }
                  else {
                    unset($conditions[$key]);
                  }
                  break;
                default:
                  //  Ignore.
              }
            }
          }
        }
        // Remove uid again, if only used as surrogate for role.
        if ($is_anonymous || $not_anonymous) {
          unset($conditions['uid']);
        }
      }
    }

    // Simple log listing defaults to hide previous log deletions, unless user actually want to list log deletions.
    if (!$deletion
      && (empty($conditions['type']) || array_search('log_filter delete logs', $conditions['type'], TRUE) === FALSE)
      && !variable_get('log_filter_showdeletions', FALSE)
    ) {
      $query->condition('w.' . 'type', 'log_filter delete logs', '!=');
    }

    if ($log_columns === FALSE) {
      return $query->countQuery();
    }

    //  Order by.
    //  Will always be qualified extra by log id order, to secure correct (sub) order.
    if (!empty($order_by)) {
      $timeAscending = FALSE;
      foreach($order_by as &$orderBy) {
        if (preg_match('/^[a-z\d_]{2,32}$/', $k = $orderBy[0]) && (($v = $orderBy[1]) === 'DESC' || $v === 'ASC')) {
          if ($k == 'time' || $k == 'timestamp') {
            $query->orderBy('w.timestamp', $v);
            if ($v == 'ASC') {
              $timeAscending = TRUE;
            }
          }
          else {
            $query->orderBy('w.' . $k, $v);
          }
        }
      }
      unset($orderBy);
      $query->orderBy('w.wid', !$timeAscending ? 'DESC' : 'ASC');
    }
    else {
      $query->orderBy('timestamp', 'DESC')->orderBy('w.wid', 'DESC');
    }
    if (($offset || $max) && self::DB_SUBQUERY_LIMIT) {
      // A range must have a max length, otherwise it's ignored.
      if (!$max) {
        $max = PHP_INT_MAX - $offset;
      }
      $query->range($offset, $max);
    }
    return $query;
  }

  /**
   * @param array &$conditions
   * @param array $order_by
   * @param integer $offset
   * - minus one: list $max number of items from end of total matching items
   * @param integer $max
   * @param boolean $translate
   *  - default: FALSE
   * @return array
   */
  protected static function _listLogs(&$conditions, $order_by, $offset, $max, $translate = FALSE) {
    // Find total matching items.
    $total = (int)self::_logListQuery($conditions, $order_by, 0, 0, FALSE)->execute()->fetchField();

    // Max number of items from end of total matching items?
    if ($offset < 0) {
      $offset = $max ? $total - $max : 0;
    }

    $query = self::_logListQuery($conditions, $order_by, $offset, $max, NULL, array('name'));

    if (($offset || $max) && !self::DB_SUBQUERY_LIMIT) {
      // A range must have a max length, otherwise it's ignored.
      if (!$max) {
        $max = PHP_INT_MAX - $offset;
      }
      $query->range($offset, $max);
    }
    //  Work on event buckets.
    if (($rows = $query->execute()->fetchAll())) {
      foreach($rows as &$event) {
        //  Translate?
        if (($vars = $event->variables) === 'N;') {
          $event->variables = '';
        }
        elseif (!$translate) { // Do variables replacement frontend.
          $event->variables = unserialize($vars);
        }
        else { // Do translate if any variables
          $event->message = t($event->message, unserialize($vars));
          $event->variables = '';
        }
        //  Filter link.
        if ($event->link) {
          $event->link = filter_xss($event->link);
        }
      }
      unset($event); // Clear reference.
    }
    // Tell which conditions were used, but not what their values where - except for the wid (log id) condition.
    $responseConditions = array_fill_keys(array_keys($conditions), true);
    if (!empty($conditions['wid'])) {
      $responseConditions['wid'] = $conditions['wid'];
    }
    return array(
      $rows,
      $responseConditions,
      $offset,
      $total,
    );
  }

  /**
   * Using a LIMIT for delete queryies is kind of hard since db_delete doesnt support LIMIT (because PostgresSQL doesnt support that),
   * and MySQL doesnt support LIMIT for sub queries.
   *
   * And MySQL doesnt support using the same table in a sub query and in an outer CRUD query.
   *
   * So we have to do a separate select getting the relevant ids, and then do a delete using that - potentially too long - list of ids.
   * Does it in chunks of 40000 items; that should work even when db query max length is only half a megabyte.
   *
   * @param array $conditions
   * @param array $order_by
   * @param integer $offset
   * @param integer $max
   * @return integer
   */
  protected static function _deleteLogs($conditions, $order_by, $offset, $max) {
    global $user;

    // Deleting all logs unconditionally is not an option, because deleting logs of type 'log_filter delete logs' is illegal.
    //if (!$conditions && !$offset && !$max) {
    //  $deleted = db_delete('watchdog')
    //    ->execute();
    //}
    //else {
    $query = self::_logListQuery($conditions, $order_by, $offset, $max, array('wid'), FALSE, TRUE);
    if (($offset || $max) && !self::DB_SUBQUERY_LIMIT) {
      // A range must have a max length, otherwise it's ignored.
      if (!$max) {
        $max = PHP_INT_MAX - $offset;
      }
      $query->range($offset, $max);
    }
    $ids = $query->execute()->fetchCol();

    if (!($le = count($ids))) {
      return 0;
    }
    //  This may fail because the list of ids may exceed query limit (query max length).
    if ($le > 40000) {
      $le = count($ids = array_chunk($ids, 40000));
      $deleted = 0;
      for ($i = 0; $i < $le; $i++) {
        $deleted += db_delete('watchdog')
          ->condition('wid', $ids[$i], 'IN')
          ->execute();
      }
    }
    else {
      $deleted = db_delete('watchdog')
        ->condition('wid', $ids, 'IN')
        ->execute();
    }
    //}
    watchdog(
      'log_filter delete logs',
      'User (%uid) %name deleted !deleted log events.',
      array('%uid' => $user->uid, '%name' => $user->name, '!deleted' => $deleted),
      WATCHDOG_NOTICE
    );
    return $deleted;
  }

  /**
   * Access permission: 'access site reports'.
   *
   * All actions require the POST var form_token.
   *
   *  Expects (requires) POST vars on actions:
   *  - filter_create|filter_edit: name, filter, conditions, order_by
   *  - list_logs: conditions, order_by, offset, max, translate
   *  - delete_logs: conditions, order_by, offset, max
   *
   * @see LogFilter::ajaxCallback
   * @param string $action
   * @return void
   *  - sends 403 header if the expected POST vars arent set or their sanitized values evaluates to empty
   */
  public static function ajaxCallback($action) {
    if ( // Require permission.
      !user_access('access site reports')
      //  Require valid composition of the 'action' parameter (presumably a GET var).
      || !$action || !($le = strlen($action)) // Deliberately not drupal_...().
        || $le > 32
    ) {
      header('HTTP/1.1 403 Forbidden');
      exit;
    }
    $action = '' . $action;
    $oResp = new stdClass();
    $oResp->action = check_plain($action); // Redundant; vs. code review.
    $oResp->error = '';
    $oResp->success = TRUE;
    $oResp->error_code = 0;

    try {
      switch ($action) {
        case 'username_autocomplete':
          $oResp = array();
          if (isset($_GET['term']) && strlen($needle = trim($_GET['term'])) && drupal_validate_utf8($needle)) {
            $maxResult = 9;
            //$oResp = array( array('value' => '8', 'label' => 'someuser'), );
            $uids = array();
            $users = db_select('users', 'u')
              ->fields('u', array('uid', 'name'))
              ->condition('name', db_like($needle) . '%', 'LIKE')
              ->orderBy('u.name', 'ASC')
              ->range(0, $maxResult)
              ->execute()
              ->fetchAll();
            if (($le = count($users))) {
              for ($i = 0; $i < $le; ++$i) {
                $oResp[] = array('value' => $uids[] = $users[$i]->uid, 'label' => $users[$i]->name);
              }
            }
            if ($le < $maxResult) {
              $users = db_select('users', 'u')
                ->fields('u', array('uid', 'name'));
              if ($uids) {
                $users = $users->condition('uid', $uids, 'NOT IN');
              }
              $users = $users->condition('name', '%' . db_like($needle) . '%', 'LIKE')
                ->orderBy('u.name', 'ASC')
                ->range(0, $maxResult - $le)
                ->execute()
                ->fetchAll();
              if (($le = count($users))) {
                for ($i = 0; $i < $le; ++$i) {
                  $oResp[] = array('value' => $users[$i]->uid, 'label' => $users[$i]->name);
                }
              }
            }
          }
          break;
        case 'filter_create':
        case 'filter_edit':
          $conditions = $order_by = NULL;
          if (
            !array_key_exists('name', $_POST) || !($le = strlen($name = $_POST['name'])) // Deliberately not drupal_...(). And composition is checked later.
              || $le > 32
            || !array_key_exists('filter', $_POST) || !is_array($filter = $_POST['filter']) // It is an array!
            || !array_key_exists('require_admin', $filter) || !(($require_admin = (int)$filter['require_admin']) == 0 || $require_admin == 1)
            || !array_key_exists('description', $filter)
              || ( ($description = $filter['description']) !== '' && (!drupal_validate_utf8($description) || drupal_strlen($description) > 255) )
            // conditions may not exist, because jQuery.ajax() >v1.4.4 doesn't POST empty object.
            // _saveFilter() checks/filters conditions buckets vs. xss.
            || (array_key_exists('conditions', $_POST) && ($conditions = $_POST['conditions']) && !is_array($conditions))
            // order_by may not exist, because jQuery.ajax() >v1.4.4 doesn't POST empty object.
            // _saveFilter() checks/filters order_by buckets vs. xss.
            || (array_key_exists('order_by', $_POST) && ($order_by = $_POST['order_by']) && !is_array($order_by))
          ) {
            header('HTTP/1.1 403 Forbidden');
            exit;
          }
          if (!user_access('log_filter edit filters')) {
            $oResp->success = FALSE;
            $oResp->error_code = self::$_errorCodes['perm_filter_crud'];
          }
          elseif (!preg_match('/^[a-z_][a-z\d_]+$/', $name) || $name == 'default' || $name == 'adhoc') { // @IDE: var $name is declared.
            $oResp->success = FALSE;
            $oResp->error_code = self::$_errorCodes['filter_name_composition'];
            //  $oResp->error = t('Invalid machine name[' . $name . '].'); Frontend creates own message.
            $oResp->name = check_plain($name);
          }
          else {
            $oResp->name = $name = check_plain(strtolower($name)); // Deliberately not drupal_...().
            $oResp->description = !$description ? '' : check_plain(trim(str_replace(array("\r", "\n", "\t"), ' ', $description)));
            self::_saveFilter(
              $name,
              array(
                'filter' => array(
                  'require_admin' => $require_admin,
                  'description' => $description
                ),
                'conditions' => $conditions ? $conditions : array(), // _saveFilter() checks/filters conditions buckets vs. xss.
                'order_by' => $order_by ? $order_by : array(), // _saveFilter() checks/filters order_by buckets vs. xss.
              ),
              $action == 'filter_create'
            );
          }
          break;
        case 'list_logs':
          $conditions = $order_by = NULL;
          if (
            // conditions may not exist, because jQuery.ajax() >v1.4.4 doesn't POST empty object.
            // _logListQuery() checks/filters conditions buckets vs. xss.
            (array_key_exists('conditions', $_POST) && ($conditions = $_POST['conditions']) && !is_array($conditions))
            // order_by may not exist, because jQuery.ajax() >v1.4.4 doesn't POST empty object.
            // _logListQuery() checks/filters order_by buckets vs. xss.
            || (array_key_exists('order_by', $_POST) && ($order_by = $_POST['order_by']) && !is_array($order_by))
            || !array_key_exists('offset', $_POST) || ($offset = (int)$_POST['offset']) < -1 || $offset > PHP_INT_MAX
            || !array_key_exists('max', $_POST) || ($max = (int)$_POST['max']) < 0 || $max > PHP_INT_MAX
            || !array_key_exists('translate', $_POST)
          ) {
            header('HTTP/1.1 403 Forbidden');
            exit;
          }
          if ($max > self::PAGE_RANGE_MAX) {
            $max = self::PAGE_RANGE_MAX;
          }
          if (!$conditions) {
            $conditions = array();
          }
          $oResp->log_list = self::_listLogs(
            $conditions,
            $order_by ? $order_by : array(),
            $offset,
            $max,
            $translate = (bool)$_POST['translate']
          );
          //  Save pager_range and translate to session.
          $session = array(
            'settings' => array(
              'pager_range' => $max > 0 ? $max : variable_get('log_filter_pgrng', self::PAGE_RANGE_DEFAULT),
              'translate' => $translate,
            ),
          );
          if (module_exists('state')) {
            State::sessionSet('module', 'log_filter', $session);
          }
          else {
            drupal_session_start();
            if (!isset($_SESSION['module'])) {
              $_SESSION['module'] = array(
                'log_filter' => $session,
              );
            }
            else {
              $_SESSION['module']['log_filter'] = $session;
            }
          }
          break;
        case 'delete_logs':
          $conditions = $order_by = NULL;
          if (
            // conditions may not exist, because jQuery.ajax() >v1.4.4 doesn't POST empty object.
            // _logListQuery() checks/filters conditions buckets vs. xss.
            (array_key_exists('conditions', $_POST) && ($conditions = $_POST['conditions']) && !is_array($conditions))
            // order_by may not exist, because jQuery.ajax() >v1.4.4 doesn't POST empty object.
            // _logListQuery() checks/filters order_by buckets vs. xss.
            || (array_key_exists('order_by', $_POST) && ($order_by = $_POST['order_by']) && !is_array($order_by))
            || !array_key_exists('offset', $_POST) || ($offset = (int)$_POST['offset']) < -1 || $offset > PHP_INT_MAX
            || !array_key_exists('max', $_POST) || ($max = (int)$_POST['max']) < 0 || $max > PHP_INT_MAX
          ) {
            header('HTTP/1.1 403 Forbidden');
            exit;
          }
          $oResp->delete_logs = self::_deleteLogs(
            $conditions ? $conditions : array(),
            $order_by ? $order_by : array(),
            $offset,
            $max
          );
          break;
        default:
          $oResp->success = FALSE;
          $oResp->error_code = 1;
          $oResp->error = 'Unsupported action[' . $action . '].';
      }
    }
    catch (PDOException $xc) {
      self::_errorHandler($xc);
      $oResp->success = FALSE;
      $oResp->error_code = self::$_errorCodes['db_general'];
    }
    catch (Exception $xc) {
      self::_errorHandler($xc);
      $oResp->success = FALSE;
      if (($error_code = $xc->getCode()) && in_array($error_code, self::$_errorCodes)) {
        $oResp->error_code = $error_code;
      }
      else {
        $oResp->error_code = self::$_errorCodes['unknown'];
      }
    }

    header('Content-Type: application/json; charset=utf-8');
    header('Cache-Control: private, no-store, no-cache, must-revalidate');
    header('Expires: Thu, 01 Jan 1970 00:00:01 GMT');
    echo drupal_json_encode($oResp);
    flush();
    exit;
  }
}