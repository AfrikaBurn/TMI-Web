<?php
/**
 * @file
 *  Drupal Log Filter module
 */

/**
 * Defines configuration form fields.
 *
 * @param array $form
 * @param array &$form_state
 * @return array
 *   - the return value of system_settings_form()
 */
function _log_filter_admin_form($form, &$form_state) {
  module_load_include('inc', 'log_filter', 'LogFilter');
  if (variable_get('log_filter_css', TRUE)) {
    drupal_add_css(
      ($path = drupal_get_path('module', 'log_filter')) . '/admin/log_filter.admin.css',
      array('type' => 'file', 'group' => CSS_DEFAULT, 'preprocess' => FALSE, 'every_page' => FALSE)
    );
  }
  //  Clear menu cache if just submitted.
  if (!empty($_SESSION) && !empty($_SESSION['module']) && !empty($_SESSION['module']['log_filter'])
      && array_key_exists('admin_form_submitted', $_SESSION['module']['log_filter'])) {
    menu_rebuild();
    unset($_SESSION['module']['log_filter']['admin_form_submitted']);
    if (empty($_SESSION['module']['log_filter'])) {
      unset($_SESSION['module']['log_filter']);
      if (empty($_SESSION['module'])) {
        unset($_SESSION['module']);
      }
    }
  }
  $form['general'] = array(
    '#type' => 'fieldset',
    '#title' => t('General settings'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
    'log_filter_admintheme' => array(
      '#type' => 'checkbox',
      '#title' => t('Do always use the administrative theme on log view pages'),
      '#default_value' => variable_get('log_filter_admintheme', TRUE),
      '#attributes' => array('autocomplete' => 'off'),
    ),
    'log_filter_cssdefault' => array(
      '#type' => 'checkbox',
      '#title' => t('Link this module\'s default stylesheet'),
      '#description' => t('Otherwise, implement styling in the site\'s theme layer.'),
      '#default_value' => variable_get('log_filter_cssdefault', TRUE),
      '#attributes' => array('autocomplete' => 'off'),
    ),
  );
  $form['log_list'] = array(
    '#type' => 'fieldset',
    '#title' => t('Log list settings'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
    'log_filter_pgrng' => array(
      '#type' => 'textfield',
      '#title' => t('Default log list page range'),
      '#default_value' => variable_get('log_filter_pgrng', LogFilter::PAGE_RANGE_DEFAULT),
      '#attributes' => array('autocomplete' => 'off'),
      '#size' => 3,
    ),
    'log_filter_trnslt' => array(
      '#type' => 'checkbox',
      '#title' => t('Default to translate log message'),
      '#description' => t('Translating log messages is heavy performance-wise'),
      '#default_value' => variable_get('log_filter_trnslt', FALSE),
      '#attributes' => array('autocomplete' => 'off'),
    ),
    'log_filter_showdeletions' => array(
      '#type' => 'checkbox',
      '#title' => t('List log entries that record that logs have been deleted'),
      '#description' => t('Log entries of type \'log_filter delete logs\' defaults to be hidden, unless when that type is selected specifically.'),
      '#default_value' => variable_get('log_filter_showdeletions', FALSE),
      '#attributes' => array('autocomplete' => 'off'),
    ),
  );

  $form['#submit'][] = 'log_filter_admin_form_submit';
  return system_settings_form($form);
}

/**
 * @param array $form
 * @param array &$form_state
 * @return void
 */
function _log_filter_admin_form_submit($form, &$form_state) {
  //  Make form clear menu cache upon submission.
  if (!isset($_SESSION['module'])) {
    $_SESSION['module'] = array(
      'log_filter' => array('admin_form_submitted' => TRUE),
    );
  }
  elseif (!isset($_SESSION['module']['log_filter'])) {
    $_SESSION['module']['log_filter'] = array('admin_form_submitted' => TRUE);
  }
  else {
    $_SESSION['module']['log_filter']['admin_form_submitted'] = TRUE;
  }

  $values =& $form_state['values'];
  $values['log_filter_pgrng'] = !($val = (int)trim($values['log_filter_pgrng'])) || $val < 0 ? LogFilter::PAGE_RANGE_DEFAULT :
    ($val > LogFilter::PAGE_RANGE_MAX ? LogFilter::PAGE_RANGE_MAX : $val);
}