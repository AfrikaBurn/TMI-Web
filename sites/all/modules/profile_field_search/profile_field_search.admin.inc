<?php
/**
 * @file
 */

/**
 * Settings form.
 */
function profile_field_search_admin_form($form, &$form_state) {

  $form['profile_field_search_entity'] = array(
    '#title' => t('Entity'),
    '#description' => t('Configure entity and bundle settings for the profile field search form.'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
  );

  // Create a list of entities that can store user profiles.
  $entities = array(
    PROFILE_FIELD_SEARCH_CORE => t('Core Profile'),
  );
  if (module_exists('profile2')) {
    $entities[PROFILE_FIELD_SEARCH_PROFILE2] = t('Profile2');
  }

  $form['profile_field_search_entity']['profile_field_search_entity'] = array(
    '#title' => t('Profile Entity'),
    '#description' => t('Select the entity that contains the profile.'),
    '#type' => 'select',
    '#options' => $entities,
    '#default_value' => variable_get('profile_field_search_entity', PROFILE_FIELD_SEARCH_CORE),
    '#ajax' => array(
      'callback' => '_profile_field_search_bundle_callback',
      'wrapper' => 'profile-field-search-bundle',
      'method' => 'replace',
      'effect' => 'fade',
    ),
  );

  // Create a list of bundles for the selected entity.
  $entity_type = isset($form_state['values']['profile_field_search_entity'])
    ? $form_state['values']['profile_field_search_entity']
    : variable_get('profile_field_search_entity', PROFILE_FIELD_SEARCH_CORE);

  $entity = entity_get_info($entity_type);

  $bundles = array('' => t('- None -'));
  foreach ($entity['bundles'] as $bundle => $info) {
    $bundles[$bundle] = $info['label'];
  }

  $form['profile_field_search_entity']['profile_field_search_bundle'] = array(
    '#title' => t('Profile Bundle'),
    '#description' => t('Select the bundle that contains the profile fields that should be searchable.'),
    '#type' => 'select',
    '#options' => $bundles,
    '#default_value' => variable_get('profile_field_search_bundle', PROFILE_FIELD_SEARCH_CORE),
    '#prefix' => '<div id="profile-field-search-bundle">',
    '#suffix' => '</div>',
    '#ajax' => array(
      'callback' => '_profile_field_search_field_callback',
      'wrapper' => 'profile-field-search-fields',
      'method' => 'replace',
      'effect' => 'fade',
    ),
  );

  $form['profile_field_search_defaults'] = array(
    '#title' => t('Defaults'),
    '#description' => t('Set defaults for the profile field search form.'),
    '#type' => 'fieldset',
  );

  $form['profile_field_search_defaults']['profile_field_search_filter_collapse'] = array(
    '#title' => t('Collapse Filters'),
    '#description' => t('Should the filters default to collapsed on the search page.'),
    '#type' => 'radios',
    '#options' => array(
      0 => t('Not collapsed'),
      1 => t('Collapsed'),
    ),
    '#default_value' => variable_get('profile_field_search_filter_collapse', 0),
  );

  // Create a list of fields for the selected bundle.
  $bundle = isset($form_state['values']['profile_field_search_bundle'])
    ? $form_state['values']['profile_field_search_bundle']
    : variable_get('profile_field_search_bundle', PROFILE_FIELD_SEARCH_CORE);

  $fields = _profile_field_search_fields(TRUE, $entity_type, $bundle);

  if (!empty($fields)) {
    $options = _profile_field_search_fields_options($fields);

    $form['profile_field_search_defaults']['description'] = array(
      '#markup' => t('Select any fields that you want searched by default. The login name and email address are always searched.'),
    );

    $header = array('label' => t('Label'), 'field' => t('Field'), 'widget' => t('Widget'));
    $form['profile_field_search_defaults']['profile_field_search_default_fields'] = array(
      '#type' => 'tableselect',
      '#header' => $header,
      '#options' => $options,
      '#default_value' => variable_get('profile_field_search_default_fields', array()),
      '#prefix' => '<div id="profile-field-search-fields">',
      '#suffix' => '</div>',
    );
  }
  else {
    $form['profile_field_search_defaults']['profile_field_search_default_fields'] = array(
      '#markup' => t('Select an entity and bundle first.'),
    );
  }

  $roles = _profile_field_search_roles();
  if (!empty($roles)) {
    $form['profile_field_search_defaults']['profile_field_search_default_roles'] = array(
      '#title' => t('Default Roles'),
      '#description' => t('Select any roles you want limit results to.'),
      '#type' => 'checkboxes',
      '#options' => $roles,
      '#default_value' => variable_get('profile_field_search_default_roles', array(DRUPAL_AUTHENTICATED_RID)),
    );
  }
  else {
    $form['profile_field_search_defaults']['profile_field_search_no_custom_roles'] = array(
      '#title' => t('Default Roles'),
      '#value' => t('No custom roles have been defined. Authenticated users searched by default.'),
      '#type' => 'markup',
    );
  }
  $form['profile_field_search_defaults']['profile_field_search_pager_items'] = array(
    '#title' => t('Results per page'),
    '#type' => 'textfield',
    '#size' => 4,
    '#description' => t('The number of search results that will be shown per page. Setting this too high may affect site performance.'),
    '#default_value' => variable_get('profile_field_search_pager_items', 50),
    '#element_validate' => array('element_validate_integer_positive'),
  );

  return system_settings_form($form);
}

/**
 * Validate hander for the settings form.
 */
function profile_field_search_admin_form_validate($form, &$form_state) {
  if (intval($form_state['values']['profile_field_search_pager_items']) >= 250) {
    drupal_set_message(t('Setting results per page too high may affect site performance'), 'warning');
  }
}
