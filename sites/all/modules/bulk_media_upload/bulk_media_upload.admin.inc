<?php
/**
 * @file
 * Admin configuration page for bulk media upload
 *
 */

/**
 * Admin configuration page
 */
function bulk_media_upload_admin($form, &$form_state) {
  $form = array();

  $entity_types = entity_get_info();
  $options = array();

  foreach ($entity_types as $entity_type => $entity_info) {
    if ($entity_info['fieldable'] && entity_type_supports($entity_type, 'save')) {
      $types[$entity_type] = $entity_info['label'];
    }
  }

  if (isset($form_state['values']['bulk_media_upload_entity_type'])) {
    $selected_entity_type = $form_state['values']['bulk_media_upload_entity_type'];
  }
  else {
    $selected_entity_type = variable_get('bulk_media_upload_entity_type');
  }

  $form['bulk_media_upload_entity_type'] = array(
    '#type' => 'select',
    '#title' => t('Entity type'),
    '#default_value' => $selected_entity_type,
    '#description' => t('Which entity type should be generated?'),
    '#required' => TRUE,
    '#options' => $types,
    '#ajax' => array(
      'callback' => 'bulk_media_upload_admin_ajax',
      'wrapper' => 'bundle-div',
      'method' => 'replace',
      'effect' => 'fade',
    ),
  );

  $form['bundle-wrapper'] = array(
    '#prefix' => '<div id="bundle-div">',
    '#suffix' => '</div>',
  );

  if ($selected_entity_type) {
    $bundles = array();
    foreach ($entity_types[$selected_entity_type]['bundles'] as $bundle_name => $bundle_info) {
      $bundles[$bundle_name] = check_plain($bundle_info['label']);
    }

    if (isset($form_state['values']['bulk_media_upload_bundle'])) {
      $selected_bundle = $form_state['values']['bulk_media_upload_bundle'];
    }
    else {
      $selected_bundle = variable_get('bulk_media_upload_bundle');
    }

    // If we have stale data from a previous save, use the first available
    // value.
    if (!isset($bundles[$selected_bundle])) {
      $selected_bundle = key(reset($bundles));
    }

    $form['bundle-wrapper']['bulk_media_upload_bundle'] = array(
      '#type' => 'select',
      '#title' => t('Bundle'),
      '#default_value' => $selected_bundle,
      '#description' => t('Which bundle should be generated?'),
      '#required' => $selected_entity_type ? TRUE : FALSE,
      '#options' => $bundles,
      '#ajax' => array(
        'callback' => 'bulk_media_upload_admin_ajax',
        'wrapper' => 'mediaelement-div',
        'method' => 'replace',
        'effect' => 'fade',
      ),
    );
  }

  $form['bundle-wrapper']['mediafield-wrapper'] = array(
    '#prefix' => '<div id="mediaelement-div">',
    '#suffix' => '</div>',
  );

  if ($selected_entity_type && $selected_bundle) {
    // Search for supported fields and add them to the dropdown.
    $fields = field_info_instances($selected_entity_type, $selected_bundle);
    $supported_modules = array('media', 'image', 'file');
    $mediafields = array();
    
    foreach ($fields as $field) {
      $field_infos = field_info_field($field['field_name']);
      if (in_array($field_infos['module'], $supported_modules)) {
        $mediafields[$field['field_name']] = $field['label'] . ' (' . $field['field_name'] . ')';
      }
    }

    if (count($mediafields) > 0) {
      $form['bundle-wrapper']['mediafield-wrapper']['bulk_media_upload_mediafield'] = array(
        '#type' => 'select',
        '#title' => t('Mediafield'),
        '#default_value' => variable_get('bulk_media_upload_mediafield'),
        '#description' => t('Select the field which should be filled with the uploaded files'),
        '#required' => TRUE,
        '#options' => $mediafields,
      );
    }
    else {
      $form['bundle-wrapper']['mediafield-wrapper']['bulk_media_upload_mediafield_info'] = array(
        '#markup' => '<p>' . t('There are no supported fields (@fields) assigned to bundle <strong>@bundle.</strong>', array('@fields' => implode(', ', $supported_modules), '@bundle' => $selected_bundle)) . '</p>',
      );
    }
  }

  $form['bulk_media_upload_redirect_path'] = array(
    '#type' => 'textfield',
    '#title' => t('Redirect path'),
    '#default_value' => variable_get('bulk_media_upload_redirect_path', 'admin/content/file/bulk_upload/summary'),
    '#description' => t('Where to redirect after bulk media upload is finished'),
    '#required' => TRUE,
    '#size' => 50,
  );

  return system_settings_form($form);
}

/**
 * Implements hook_validate().
 */
function bulk_media_upload_admin_validate($form, &$form_state) {
  if ($form_state['submitted']) {
    foreach (array('bulk_media_upload_bundle' => t('bundle'), 'bulk_media_upload_mediafield' => t('media field')) as $setting => $label) {
      if (!isset($form_state['values'][$setting]) || $form_state['values'][$setting] == '') {
        form_set_error('', t('You must select a !label.', array('!label' => $label)));
      }
    }
  }
}

/**
 * Returns media field wrapper for ajax request
 */
function bulk_media_upload_admin_ajax($form, $form_state) {
  switch (end($form_state['triggering_element']['#parents'])) {
    case 'bulk_media_upload_entity_type':
      return $form['bundle-wrapper'];
    case 'bulk_media_upload_bundle':
      return $form['bundle-wrapper']['mediafield-wrapper'];
  }
}
