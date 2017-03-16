<?php
/**
 * @file
 * Upload form and entity generation functions.
 *
 */

/**
 * Form for bulk media upload
 */
function bulk_media_upload_upload_form($form, &$form_state) {
  global $language;

  $entity_type = variable_get('bulk_media_upload_entity_type');
  $entity_info = entity_get_info($entity_type);
  $bundle = variable_get('bulk_media_upload_bundle');
  $mediafield = variable_get('bulk_media_upload_mediafield');

  if (empty($entity_type) || empty($bundle) || empty($mediafield)) {
    drupal_set_message(t('You have not configured the Bulk Media Upload module. Go to the <a href="@admin-url">configuration page</a> to fix this.', array('@admin-url' => url('admin/config/media/bulk_media_upload'))), 'error');
    return $form;
  }

  $mediafield_info = field_info_instance($entity_type, $mediafield, $bundle);

  $form['import_information'] = array(
    '#markup' => '<p>' . t('Bundle used for generating the entities: <strong>@bundle_label (@bundle_name)</strong>', array('@bundle_label' => $entity_info['bundles'][$bundle]['label'], '@bundle_name' => $bundle)) . '</p>'
    . '<p>' . t('Mediafield used for uploading your media: <strong>@field_label (@field_name)</strong>', array('@field_label' => $mediafield_info['label'], '@field_name' => $mediafield_info['field_name'])) . '</p>',
  );

  $form['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#default_value' => '[file:name]',
    '#size' => 60,
    '#maxlength' => 255,
    '#required' => TRUE,
  );

  $form['token_help'] = array(
    '#title' => t('Replacement patterns'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['token_help']['help'] = array(
    '#theme' => 'token_tree',
    '#token_types' => array($entity_type, 'file'),
    '#global_types' => TRUE,
    '#click_insert' => TRUE,
  );

  $form['upload'] = array(
    '#type' => 'plupload',
    '#title' => t('Bulk Media Upload'),
    '#description' => t(''),
    '#required' => TRUE,
  );

  if (isset($mediafield_info['settings']['file_extensions'])) {
    $form['upload']['#upload_validators']['file_validate_extensions'][] = $mediafield_info['settings']['file_extensions'];
  }

  // Use the entity creation form to extract all assigned fields.
  $allowed_fields = array_diff_key(field_info_instances($entity_type, $bundle), array($mediafield => NULL));

  // Create the new entity.
  $entity = entity_create($entity_type, array(
    $entity_info['entity keys']['bundle'] => $bundle,
  ));

  $entity_form = array();

  // And add these fields, if any, to a default value fieldset without the media field.
  field_attach_form($entity_type, $entity, $entity_form, $form_state);
  if ($additions = array_intersect_key($entity_form, $allowed_fields)) {
    $form['default_values'] = array(
      '#type' => 'fieldset',
      '#title' => t('Default Values'),
      '#tree' => TRUE,
    ) + $additions;
  }

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Generate @entity_type entities', array('@entity_type' => $entity_info['label'])),
  );

  return $form;
}

/**
 * Implements hook_validate().
 */
function bulk_media_upload_upload_form_validate($form, &$form_state) {
}

/**
 * Implements hook_submit().
 */
function bulk_media_upload_upload_form_submit($form, &$form_state) {
  $entity_type = variable_get('bulk_media_upload_entity_type');
  $entity_info = entity_get_info($entity_type);

  // Create new taxonomy terms
  if (isset($form['default_values'])) {
    $fields = field_info_instances(variable_get('bulk_media_upload_entity_type'), variable_get('bulk_media_upload_bundle'));
    foreach ($fields as $field) {
      $fieldinfo = field_info_field($field['field_name']);
      if($fieldinfo['module'] == 'taxonomy'){
        foreach ($form_state['values']['default_values'][$field['field_name']][LANGUAGE_NONE] as $key => $term) {
          if($term['tid'] == 'autocreate'){
            // Create term.
            $term = (object) $term;
            unset($term->tid);
            taxonomy_term_save($term);
            $form_state['values']['default_values'][$field['field_name']][LANGUAGE_NONE][$key] = (array) $term;
          }
        }
      }
    }
  }

  // Prepare the batch process.
  $placeholders = array('@entity_type' => $entity_info['label']);
  $batch = array(
    'title' => t('Generating @entity_type entities', $placeholders),
    'error_message' => t('@entity_type generation has encountered an error.', $placeholders),
    'finished' => '_bulk_media_upload_batch_finished',
    'file' => drupal_get_path('module', 'bulk_media_upload') . '/bulk_media_upload.upload.inc',
  );

  foreach ($form_state['values']['upload'] as $tmpfile) {
    $batch['operations'][] = array('_bulk_media_upload_generate_entity', array($tmpfile, $form, $form_state));
  }

  batch_set($batch);
}

/**
 * Internal function for entity generation.
 */
function _bulk_media_upload_generate_entity($tmpfile, $form, $form_state, &$context) {
  global $user;
  $entity_type = variable_get('bulk_media_upload_entity_type');
  $entity_info = entity_get_info($entity_type);
  // Default label field to 'name'.
  $label_field = isset($entity_info['entity keys']['label']) ? $entity_info['entity keys']['label'] : 'name';
  $mediafield_name = variable_get('bulk_media_upload_mediafield');
  $bundle = variable_get('bulk_media_upload_bundle');
  $mediafield_info = field_info_instance($entity_type, $mediafield_name, $bundle);

  // Save media file.
  $scheme = variable_get('file_default_scheme', 'public') . '://';
  $source = $tmpfile['tmppath'];

  $directory = '';
  if(isset($mediafield_info['settings']['file_directory'])){
    $directory .= token_replace($mediafield_info['settings']['file_directory']) . '/';

    // If the directory isn't writable, or doesn't exist and can't be created,
    // the upload will fail.
    $prepare_directory = file_stream_wrapper_uri_normalize($scheme . $directory);
    if (!file_prepare_directory($prepare_directory, FILE_CREATE_DIRECTORY)) {
      drupal_set_message(t('The file directory @dir does not exist or is not writable. Please contact an administrator.', array('@dir' => $prepare_directory)), 'error');
      return;
    }
  }

  $destination = file_stream_wrapper_uri_normalize($scheme . $directory . $tmpfile['name']);
  $destination = file_unmanaged_move($source, $destination, FILE_EXISTS_RENAME);

  // Create the file object.
  $uri = file_stream_wrapper_uri_normalize($destination);
  $wrapper = file_stream_wrapper_get_instance_by_uri($uri);
  $file = new StdClass;
  $file->uid = $user->uid;
  $file->filename = basename($uri);
  $file->uri = $uri;
  $file->filemime = file_get_mimetype($uri);
  $file->filesize = @filesize($uri);
  $file->timestamp = REQUEST_TIME;
  $file->status = FILE_STATUS_PERMANENT;
  $file->is_new = TRUE;
  $file->status = FILE_STATUS_PERMANENT;
  file_save($file);

  // Create the new entity.
  $entity = entity_create($entity_type, array(
    $entity_info['entity keys']['bundle'] => $bundle,
    $label_field => $file->filename,
  ));

  // Taxonomy terms need to have their vocabulary ID added.
  // See http://drupal.org/node/1409256.
  if ($entity_type == 'taxonomy_term') {
    if ($vocabulary = taxonomy_vocabulary_machine_name_load($entity->vocabulary_machine_name)) {
      $entity->vid = $vocabulary->vid;
    }
  }
  // If the entity has a property tied to UID, set it so that, e.g., nodes will
  // be assigned an author.
  $info = entity_get_property_info($entity_type);
  foreach ($info['properties'] as $property) {
    if (isset($property['schema field']) && $property['schema field'] == 'uid') {
      $entity->uid = $user->uid;
      break;
    }
  }
  entity_save($entity_type, $entity);

  // Create the media field.
  $fieldinfo = field_info_field($mediafield_name);
  $filefields = array('image', 'file');

  $settings = array();
  $settings['fid'] = $file->fid;

  // Additional values for filefield (and imagefield).
  if(in_array($fieldinfo['module'], $filefields)){
    $settings['display'] = 1;
    $settings['description'] = '';
  };

  $entity->$mediafield_name = array(LANGUAGE_NONE => array(0 => $settings));

  // Default values.
  if (isset($form['default_values'])) {
    field_attach_submit($entity_type, $entity, $form['default_values'], $form_state);
  }

  entity_save($entity_type, $entity);

  // Replace tokens in title - this has to be done after entity_save.
  $label = token_replace($form_state['values']['title'], array($entity_type => $entity, 'file' => $file), array('clear' => TRUE));

  $entity->$label_field = $label;

  entity_save($entity_type, $entity);

  $context['message'] = t('Importing: @filename', array('@filename' => $file->filename));
  $context['results']['ids'][] = $entity->$entity_info['entity keys']['id'];
}

/**
 * Finished function for batch
 */
function _bulk_media_upload_batch_finished($success, $results, $operations) {
  $entity_type = variable_get('bulk_media_upload_entity_type');
  $entity_info = entity_get_info($entity_type);
  drupal_set_message(t('@entity_type generation completed.', array('@entity_type' => $entity_info['label'])));
  $_SESSION['bulk_media_upload_batch_result'] = $results;
  // TODO: do landing pages for other entity types?
  if ($entity_type == 'node') {
    drupal_goto(variable_get('bulk_media_upload_redirect_path', 'admin/content/file/bulk_upload/summary'));
  }
}
