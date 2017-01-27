<?php
/**
 * @file
 * Functionality and helper functions for Better field descriptions.
 */

/**
 * Implements hook_admin_settings_form().
 */
function better_field_descriptions_admin_settings_form($form, &$form_state) {

  // Get info on bundles.
  $bundles = field_info_bundles('node');

  // Get list of fields selected for better descriptions.
  $bfds = variable_get('better_field_descriptions_settings', array());

  $form['descriptions'] = array(
    '#type' => 'markup',
    '#markup' => t('Select fields that should have better descriptions.'),
  );

  $form['bundles'] = array(
    '#type' => 'item',
    '#prefix' => '<div id="better-descriptions-form-id-wrapper">',
    '#suffix' => '</div>',
    '#tree' => TRUE,
  );

  foreach ($bundles as $bundle_machine_name => $bundle) {

    // Array to hold fields in the node.
    $fields_instances = array();

    // Get info on pseudo fields, like title.
    $extra_fields = field_info_extra_fields('node', $bundle_machine_name, 'form');
    if (isset($extra_fields['title'])) {
      $fields_instances['title'] = $extra_fields['title']['label'];
    }

    // Get info on regular fields to the bundle.
    $fields = field_info_instances('node', $bundle_machine_name);

    foreach ($fields as $field_machine_name => $field) {
      $fields_instances[$field_machine_name] = $field['label'] . ' (' . $field_machine_name . ')';
    }

    // Compute default values.
    $default_values = array();
    if (isset($bfds[$bundle_machine_name])) {
      $default_values = array_intersect_key($bfds[$bundle_machine_name], $fields_instances);
    }

    // Generate checkboxes.
    $form['bundles'][$bundle_machine_name] = array(
      '#type' => 'checkboxes',
      '#title' => $bundle['label'],
      '#options' => $fields_instances,
      '#default_value' => $default_values,
      '#description' => t('Choose which fields should have better descriptions.'),
    );
  }

  $form['#submit'] = array('better_field_descriptions_admin_settings_submit');

  return system_settings_form($form);
}

/**
 * Implements hook_submit().
 */
function better_field_descriptions_admin_settings_submit($form, &$form_state) {

  // Instead of changing values, we just set all values anew on each submit.
  variable_del('better_field_descriptions_settings');

  // We don't want our settings to contain 0-values, only selected values.
  $bfds = array();

  foreach ($form_state['values']['bundles'] as $bundle_machine_name => $bundle) {
    foreach ($bundle as $field_machine_name => $value) {

      // $value is (int) 0 if the field was not selected in the form.
      if (is_string($value)) {
        $bfds[$bundle_machine_name][$field_machine_name] = $field_machine_name;
      }
    }
  }

  variable_set('better_field_descriptions_settings', $bfds);
}

/**
 * Implements hook_form().
 */
function better_field_descriptions_fields_form($form, &$form_state) {

  // Get better descriptions settings.
  $bfds = variable_get('better_field_descriptions_settings', array());

  // Get existing descriptions for fields.
  $bfd = variable_get('better_field_descriptions', array());

  // Use default template if not configured.
  if (isset($bfd['template']) == FALSE || empty($bfd['template'])) {
    $bfd['template'] = 'better-field-descriptions-text';
  }

  // Regex for locating all template files starting with 'better-descriptions'.
  $regex = '/^better-field-descriptions.*\.tpl\.php$/i';

  // Fetching template files from this module.
  $path = drupal_get_path('module', 'better_field_descriptions');
  $templates_module = drupal_system_listing($regex, $path, 'name', 0);

  // Fetching template files from themes.
  $templates_system = drupal_system_listing($regex, "themes", 'name', 0);

  // Merges all template files allowing theme templates to override the modules
  // templates.
  $templates = array_merge($templates_module, $templates_system);

  $form['#templates'] = $templates;

  // Collects all templates found into array for select list.
  $better_descriptions_templates = array();

  foreach ($templates as $template) {

    $path = $template->uri;
    // Removing the '.tpl' if exists.
    if (($pos = strpos($template->name, '.')) !== FALSE) {
      $template = substr($template->name, 0, $pos);
    }

    $better_descriptions_templates[$template] = $template;
  }

  // Possible positions for the better description.
  $positions = array(
    0 => t('Above title and input'),
    1 => t('Below title and input'),
    2 => t('Between title and input'),
  );

  $form['descriptions'] = array(
    '#type' => 'markup',
    '#markup' => t('Add/edit better descriptions to the fields below.'),
  );

  $form['bundles'] = array(
    '#type' => 'item',
    '#prefix' => '<div id="better-field-descriptions-form-id-wrapper">',
    '#suffix' => '</div>',
    '#tree' => TRUE,
  );

  // Template selection.
  $form['bundles']['template'] = array(
    '#type' => 'select',
    '#title' => t('Select template for the descriptions'),
    '#options' => $better_descriptions_templates,
    '#default_value' => $bfd['template'],
    '#description' => t('Changing this value will trigger a theme registry rebuild. You can also provide your own template, consult the documentation.'),
  );

  // Setting label, default if not set.
  if (isset($bfd['default_label']) == FALSE) {
    $default_label = t('Description');
  }
  else {
    $default_label = $bfd['default_label'];
  }

  $form['bundles']['default_label'] = array(
    '#type' => 'textfield',
    '#title' => 'Default label for all field descriptions.',
    '#default_value' => $default_label,
    '#description' => t('This label will be used if not set in each of the fields below.'),
  );

  // Get info on bundles.
  $bundles = field_info_bundles('node');

  foreach ($bfds as $bundle_machine_name => $fields) {

    // Array to hold fields in the node.
    $fields_instances = array();

    // Get info on pseudo fields, like title.
    $extra_fields = field_info_extra_fields('node', $bundle_machine_name, 'form');
    if (isset($extra_fields['title'])) {
      $fields_instances['title'] = $extra_fields['title'];
    }

    // Get info on regular fields to the bundle.
    $fields_instances += field_info_instances('node', $bundle_machine_name);

    // Wrapping each bundle in a collapsed fieldset.
    $form['bundles'][$bundle_machine_name] = array(
      '#type' => 'fieldset',
      '#title' => $bundles[$bundle_machine_name]['label'],
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
      '#prefix' => '<div id="better-field-descriptions-form-id-wrapper">',
      '#suffix' => '</div>',
    );

    foreach ($fields as $field_machine_name) {

      // Descriptions.
      $bfd_description = '';
      if (isset($bfd[$bundle_machine_name][$field_machine_name]['description'])) {
        $bfd_description = $bfd[$bundle_machine_name][$field_machine_name]['description'];
      }
      $form['bundles'][$bundle_machine_name][$field_machine_name]['description'] = array(
        '#type' => 'textarea',
        '#title' => $fields_instances[$field_machine_name]['label'] . ' (' . $field_machine_name . ')',
        '#default_value' => filter_xss($bfd_description),
        '#description' => t('Add description for !machine_name.', array('!machine_name' => $field_machine_name)),
      );

      // Label.
      $bfd_label = '';
      if (isset($bfd[$bundle_machine_name][$field_machine_name]['label'])) {
        $bfd_label = $bfd[$bundle_machine_name][$field_machine_name]['label'];
      }
      $form['bundles'][$bundle_machine_name][$field_machine_name]['label'] = array(
        '#type' => 'textfield',
        '#title' => 'Label for this field description',
        '#default_value' => filter_xss($bfd_label),
        '#description' => t('Label for this field description.'),
      );

      $position = 1;
      if (isset($bfd[$bundle_machine_name][$field_machine_name]['position'])) {
        $position = $bfd[$bundle_machine_name][$field_machine_name]['position'];
      }

      // Position of description.
      $form['bundles'][$bundle_machine_name][$field_machine_name]['position'] = array(
        '#type' => 'radios',
        '#title' => 'Position of description.',
        '#options' => $positions,
        '#default_value' => $position,
        '#description' => t('Position the description field above or below the input field. When choosing the between-option the #title of the field will be used as label (if label is left blank) and the original field #title will be set as invisible.'),
      );
    }
  }

  $form['#submit'] = array('better_field_descriptions_fields_submit');

  return system_settings_form($form);
}

/**
 * Implements hook_submit().
 */
function better_field_descriptions_fields_submit($form, &$form_state) {

  $bfd = variable_get('better_field_descriptions', array());

  $template = $form_state['values']['bundles']['template'];
  $template_uri = $form_state['complete form']['#templates'][$template . '.tpl']->uri;
  $form_state['values']['bundles']['template_uri'] = $template_uri;

  // If the template is changed, do a theme registry rebuild.
  if (isset($bfd['template']) && $template != $bfd['template']) {
    drupal_theme_rebuild();
  }

  // Setting variables.
  variable_del('better_field_descriptions');
  variable_set('better_field_descriptions', $form_state['values']['bundles']);
}
