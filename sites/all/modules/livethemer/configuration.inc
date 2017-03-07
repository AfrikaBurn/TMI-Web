<?php
/**
 * @file configuration.inc helper functions.
 */

/**
 * Configuration page.
 */
function livethemer_settings($form, &$form_state) {

  $themes = system_rebuild_theme_data();
  $themes = list_themes(TRUE);
  
  $default_theme_name = variable_get('theme_default');
  $default_theme = $themes[$default_theme_name];
  
  $form['#attached']['css'] = array(
    drupal_get_path('module', 'livethemer') . '/css/configuration_form.css',
  );

  $form['logo'] = array(
    '#markup' => '<p><img src="' . base_path() . drupal_get_path('module', 'livethemer') . '/images/lt-logo-small.png" title="Livethemer" alt="Livethemer"></p>'
                 . '<p>Livethemer configuration.</p>',
  );

 // Set/check the settings file.
  $options = get_settings_options();  
  $settings_file_stored = theme_get_setting('livethemer_settings_file', $default_theme_name);
  $settings_file = isset($form_state['input']['livethemer_settings_file']) ? $form_state['input']['livethemer_settings_file'] : $settings_file_stored;
  
  $class = 'error'; // Signify that no settings file has been selected.
  $settings_choice_ok = FALSE;
  foreach ($options as $options_group) {
    if (array_key_exists($settings_file, (array) $options_group)) {
      $class = 'status'; // Signify that a settings file HAS been selected.
      $settings_choice_ok = TRUE;
      break;
    }
  }
  
  $form['config_settings'] = array(
    '#type' => 'fieldset',
    '#title' => 'Select a settings file.',
    '#description' => '<p>Livethemer stores all its configuration settings and selected variation data in a settings file. The settings file determines how the current theme will be modified by Livethemer.</p>',
    '#collapsible' => FALSE, 
    '#collapsed' => FALSE,
    '#attributes' => array('class' => array($class)),
  );

  $form['config_settings']['livethemer_settings_file'] = array(
    '#type' => 'select',
    '#title' => 'Settings file',
    '#options' => $options,
    '#default_value' => $settings_file,
    '#description' => '<p>Select the Livethemer settings file that you want to use. If you select a read-only settings file and later use the Livethemer inspector, the file will automatically be copied to your public files directory so it can be modified.</p>', 
    // #element_validate
  );

  // Set/check the currently active theme.
  $theme_choice_ok = FALSE;
  if ($default_theme_name == 'livethemer_base') {
    $msg = array();
    $class = 'status';
    $theme_choice_ok = TRUE;
  }
  else {
    if (!empty($themes['livethemer_base'])) {
      $msg['enable_ltbase'] = array(
        '#type' => 'checkbox',
        '#title' => t('Set Livethemer Base as your default theme.'),
      );
    }
    else {
      $msg['msg'] = array(
        '#markup' => 'If you wish to use the Livethemer Base theme, ' . l( t('download it'),  'http://drupal.org/project/livethemer_base') . ', place it in your themes directory then refresh this page.',
      );
    }
    $class = 'warning';
  }
  
  $form['config_theme'] = array(
    '#type' => 'fieldset',
    '#title' => 'Your currently active theme is: <strong>' . $default_theme->info['name'] . '</strong>.',
    '#collapsible' => FALSE, 
    '#collapsed' => FALSE,
    '#attributes' => array('class' => array($class)),
    '#description' => '<p>Livethemer works best with the <strong>Livethemer Base</strong> theme.</p>',
  );
  
  $form['config_theme'] += $msg;
  
  // Check if the inspector module is active.
  if (function_exists('livethemer_inspector_init')) {
    $form['inspector_module'] = array(
      '#type' => 'fieldset',
      '#title' => 'The Livethemer Inspector module is enabled.',
      '#description' => 'You may dynamically modify the current theme. However, the Livethemer module can be used on its own (without the Livethemer Inspector module) to simply apply an existing settings file to the current theme.',
      '#collapsible' => FALSE, 
      '#collapsed' => FALSE,
      '#attributes' => array('class' => array('status')),
    );
  }
  else {
    $form['inspector_module'] = array(
      '#type' => 'fieldset',
      '#title' => 'The Livethemer Inspector module is not enabled.',
      '#description' => '<p>You will need to enable the Livethemer Inspector module if you wish to modify the current theme.</p>'
                        . '<p>The Livethemer module can be used on its own to apply an existing settings file to the current theme. However, if you wish to use the Livethemer inspector to dynamically modify the settings file and change how the current theme looks, you will need to '
                        . l('enable the Livethemer Inspector module', 'admin/modules') . '.</p>',
      '#collapsible' => FALSE, 
      '#collapsed' => FALSE,
      '#attributes' => array('class' => array('warning')),
    );
  }
  
  if ($theme_choice_ok && $settings_choice_ok) {
    $form['goto_site'] = array(
      '#markup' => '<p>Everything is ready. ' . l('Visit the front page of your site.', '') . '</p>',
    );
  }

  $form['#submit'][] = 'livethemer_settings_form_submit';
  // $form['#submit'][] = 'livethemer_system_theme_settings_submit';
  
  // Adds a simple submit button that refreshes the form and clears its contents -- this is the default behavior for forms.
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Save configuration',
  );

  return $form;
}

/**
 * Callback function for settings page.
 */
function livethemer_settings_validate($form, &$form_state) {
  if ($form_state['values']['livethemer_settings_file'] == '-') {
    form_set_error('livethemer_settings_file', t('You must select a settings file in order to use Livethemer.'));
  }
}

function livethemer_settings_form_submit($form, &$form_state) {
  if (isset($form_state['values']['enable_ltbase']) && $form_state['values']['enable_ltbase']) {
    // Get current list of themes.
    $themes = list_themes();

    $theme = 'livethemer_base';
    if (!empty($themes[$theme])) {
      theme_enable(array($theme));
      variable_set('theme_default', $theme);
      drupal_set_message(t('The %theme theme has been enabled.', array('%theme' => $themes[$theme]->info['name'])));
    }
    else {
      drupal_set_message(t('The %theme theme was not found.', array('%theme' => $theme)), 'error');
    }
  }

  // Grab the value of the dropdown and set a system variable.
  $file = $form_state['values']['livethemer_settings_file'];
  if ($file != '-') {
    $theme_name = variable_get('theme_default', NULL);
    $theme_settings =  variable_get('theme_' . $theme_name . '_settings', NULL);
    $theme_settings['livethemer_settings_file'] = $file;
    variable_set('theme_' . $theme_name . '_settings', $theme_settings);   
  }
}

function livethemer_info($form, $form_values) {
  $options = get_settings_options();  
 
  $form['livethemer_settings_file'] = array(
    '#type' => 'select',
    '#title' => 'Settings file',
    '#options' => $options,
    '#description' => '<p>Select the Livethemer settings file that you want to view.</p>', 
  );
  
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'View',
  );  
  return $form;
}

function livethemer_info_submit($form, $form_state) {
  $settings_file = isset($form_state['values']['livethemer_settings_file'])? $form_state['values']['livethemer_settings_file']:NULL;

  $data = read_write_settings_file(NULL, $settings_file);
  
  if (function_exists('dsm')) {
    dsm($data);
    // dsm($livethemer_metadata);
    $output = '<p>Printout of $livethemer_variables</p>';
  }
}   