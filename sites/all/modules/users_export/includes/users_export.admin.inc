<?php
/**
 * @file
 * Administration page callbacks for the users_export module.
 *
 * @ingroup users_export
 * @{
 */

/**
 * Form builder. Configure my_module.
 *
 * @ingroup forms
 * @see     system_settings_form()
 */

function users_export_form($form, &$form_state) {
  $info = loft_data_grids_export_info();

  // See if we get our visibiltiy using the new method
  $options = loft_data_grids_exporter_options(TRUE, FALSE, FALSE);
  $needs_migrate = FALSE;
  if (empty($options)) {

    // So if there are no options because no perms have been set
    // we'll go ahead and rely on the older permissions and alert user
    // in a later update we'll remove these the hook_perms altogether.
    $options = loft_data_grids_exporter_options(FALSE, FALSE, FALSE);
    $needs_migrate = TRUE;
    foreach (array_keys($options) as $key) {
      if (!user_access('users_export:export as ' . $key)) {
        unset($options[$key]);
      }
    }
  }

  if ($needs_migrate && $options) {
    drupal_set_message(t('Please <a href="!url">go here</a> and transfer your <em>Users Export: Export As...</em> permissions to <em>Loft Data Grids: Visible in UI...</em> permissions as soon as possible.', array(
      '!url' => url('admin/people/permissions', array('query' => drupal_get_destination())),
    )), 'warning', FALSE);
  }

  $form['#post_render'][] = '_users_export_export_post_render';

  $class = variable_get('users_export_type', 'CSVExporter');
  $type = $info[$class]['extension'];
  $form['users_export_type'] = array(
    '#type'          => 'select',
    '#title'         => t('Export file format'),
    '#default_value' => $class,
    '#options'       => $options,
  );

  $default = variable_get('users_export_filename', strtolower(preg_replace('/\W+/', '_', variable_get('site_name', 'users_export')) . '_users'));
  $form['users_export_filename'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Filename to save as'),
    '#default_value' => $default,
    '#required'      => TRUE,
    '#field_suffix'  => $type,
  );

  $test_mode = variable_get('users_export_test_mode', FALSE);

  $form['advanced'] = array(
    '#type'        => 'fieldset',
    '#title'       => t('Advanced Settings'),
    '#collapsible' => TRUE,
    '#collapsed'   => !$test_mode,
  );

  // Add field to add 'blocked' users to the export as well.
  $form['advanced']['users_export_user_status'] = array(
    '#type'          => 'select',
    '#title'         => t('Export users with status'),
    '#default_value' => variable_get('users_export_user_status', 1),
    '#options'       => array(
      1 => t('Active'),
      0 => t('Blocked'),
      2 => t('Both active and blocked'),
    ),
  );

  if (module_exists('date')) {
    $options = array();
    foreach (date_format_type_options() as $type => $title) {
      $type = date_format_type_format($type);
      $options[$type] = $title;
    }

    // Now add in those we think most users will want to use
    $options += array(
      DATE_FORMAT_DATETIME => 'Datetime (' . date(DATE_FORMAT_DATETIME) . ')',
      DATE_FORMAT_UNIX     => 'Unix Timestamp (' . date(DATE_FORMAT_UNIX) . ')',
      DATE_FORMAT_ISO      => 'ISO 8601 (' . date(DATE_FORMAT_ISO) . ')',
      DATE_FORMAT_ICAL     => 'iCal (' . date(DATE_FORMAT_ICAL) . ')',
    );

    $form['advanced']['users_export_date_format'] = array(
      '#type'          => 'select',
      '#title'         => t('Date format'),
      '#default_value' => variable_get('users_export_date_format', DATE_FORMAT_DATETIME),
      '#options'       => $options,
    );
  }
  else {
    $form['advanced']['users_export_date_format'] = array(
      '#type'   => 'hidden',
      '#value'  => USERS_EXPORT_DEFAULT_DATE_FORMAT,
      '#prefix' => t('Enable the <a href="!url">date module</a> to be able to control date formatting.', array(
        '!url' => url('https://drupal.org/project/date'),
      )),
    );
  }

  $options = array(-1 => t('- Default -'));
  foreach (range(128, 2048, 32) as $value) {
    $options[$value . 'M'] = format_size($value * 1024 * 1024);
  }
  $form['advanced']['users_export_memory_limit'] = array(
    '#type'          => 'select',
    '#title'         => t('Memory Limit', array(
      '@size' => format_size(variable_get('users_export_last_export_memory', 0)),
    )),
    '#description'   => t('If you have many users you may need to set this value higher so you the web server does not run out of memory processing the export. <strong>Depending upon your server configuration, this may or may not have any effect!</strong> For more information refer to <a href="http://php.net/manual/en/function.ini-set.php">http://php.net/manual/en/function.ini-set.php</a>.'),
    '#default_value' => variable_get('users_export_memory_limit', 160),
    '#options'       => $options,
  );

  $options = array(-1 => t('- Default -'));
  foreach (range(30, 1800, 30) as $value) {
    $options[$value] = format_interval($value);
  }
  $form['advanced']['users_export_max_execution'] = array(
    '#type'          => 'select',
    '#title'         => t('Maximum Execution Time', array(
      '@time' => format_interval(variable_get('users_export_last_export_time', 0)),
    )),
    '#description'   => t('If you have many users you may need to set this value higher so you the web server does not timeout. <strong>Depending upon your server configuration, this may or may not have any effect!</strong> For more information refer to <a href="http://php.net/manual/en/function.set-time-limit.php">http://php.net/manual/en/function.set-time-limit.php</a>.'),
    '#default_value' => variable_get('users_export_max_execution', 60),
    '#options'       => $options,
  );

  $form['advanced']['users_export_test_mode'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Preview mode (Enable to limit the export to only the first 10 users to check formatting.)'),
    '#default_value' => $test_mode,
  );

  $form = system_settings_form($form);
  $form['actions']['submit']['#value'] = t('Download File');
  $form['#submit'][] = 'users_export_form_submit';

  return $form;
}

/**
 * Apply post render processing and return the form array
 *
 * @param array $form
 * @param array &$form_state
 *
 * @return array
 */
function _users_export_export_post_render($form, &$form_state) {
  drupal_add_js(drupal_get_path('module', 'users_export') . '/users_export.js');
  drupal_add_js(array(
    'usersExport' => loft_data_grids_export_info(),
  ), 'setting');

  return $form;
}

/**
 * Form submission handler
 */
function users_export_form_submit($form, &$form_state) {
  $timer_id = __FUNCTION__ . $form['#build_id'];
  timer_start($timer_id);
  if ($form_state['values']['users_export_memory_limit'] != -1) {
    ini_set('memory_limit', $form_state['values']['users_export_memory_limit']);
  }

  if ($form_state['values']['users_export_max_execution'] != -1) {
    set_time_limit($form_state['values']['users_export_max_execution']);
  }

  // Load the users
  $query = db_select('users', 'u');
  $query
    ->fields('u', array('uid', 'name', 'status'))
    ->orderBy('uid');
  $query->addField('u', 'mail', 'email');
  $query->addField('u', 'created');
  $query->addField('u', 'access', 'last_access');
  $query->addField('u', 'login', 'last_login');
  $query->condition('uid', 0, '<>'); // Exclude anonymous.

  // Add status of user.
  if (!empty($form_state['values']['users_export_user_status'])) {
    switch ($form_state['values']['users_export_user_status']) {
      case 1 :
        $query->condition('status', 1);
        break;
      case 0 :
        $query->condition('status', 0);
        break;
    }
  }
  else {
    // Default behaviour.
    $query->condition('status', 1);
  }

  if ($form_state['values']['users_export_test_mode']) {
    $query->range(0, 10);
  }

  $result = $query->execute();
  $data = loft_data_grids_export_data();
  $date_format = $form_state['values']['users_export_date_format'];
  $context = array(
    'settings' => $form_state['values'],
    'data'     => $data,
  );
  foreach ($result as $row) {
    $row = $context['original_row'] = (array) $row;
    $row['last_login'] = empty($row['last_login']) ? '' : date($date_format, $row['last_login']);
    $row['last_access'] = empty($row['last_access']) ? '' : date($date_format, $row['last_access']);
    $row['created'] = empty($row['created']) ? '' : date($date_format, $row['created']);

    drupal_alter('users_export_row', $row, $row['uid'], $context);

    foreach ($row as $key => $value) {
      $data->add($key, $value);
    }
    $data->next();
  }

  $data->normalize('');
  $exporter = loft_data_grids_exporter($data, $form_state['values']['users_export_type'], $form_state['values']['users_export_filename']);

  drupal_alter('users_export_exporter', $exporter);

  $exporter->save();

  //$memory = memory_get_peak_usage(TRUE);
  //variable_set('users_export_last_export_memory', $memory);
  //
  //$timer = round(timer_read($timer_id) / 1000, 2);
  //variable_set('users_export_last_export_time', $timer);

  drupal_exit();
}

/** @} */ //end of group users_export1
