<?php

/**
 * @file
 * Drush integration for the Multifield module.
 */

function multifield_drush_command() {
  $commands['convert-field-collection'] = array(
    'description' => 'Convert a field collection to a multifield',
    'callback' => 'drush_multifield_convert_field_collection',
    'arguments' => array(
      'field_name' => 'The multifield field to migrate.',
    ),
    'options' => array(
      'target-field-name' => 'The new field name to use. Defaults to the existing field name.',
    ),
    'required arguments' => TRUE,
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
  );

  return $commands;
}

function drush_multifield_convert_field_collection($source_field_name) {
  $source_field = field_read_field($source_field_name);
  $target_field_name = drush_get_option('target-field-name', $source_field_name);

  if (empty($source_field)) {
    return drush_set_error('FIELD_NOT_FOUND', "Field $source_field_name not found.");
  }
  elseif ($source_field['type'] != 'field_collection') {
    return drush_set_error('FIELD_NOT_FIELD_COLLECTION', "Field $source_field_name is not a field_collection field type.");
  }
  elseif ($source_field['storage']['type'] != 'field_sql_storage') {
    return drush_set_error('FIELD_STORAGE_NOT_SQL', "Field $source_field_name cannot be converted unless it uses field_sql_storage storage.");
  }
  elseif ($source_field_name != $target_field_name && field_read_field($target_field_name)) {
    return drush_set_error('FIELD_ALREADY_EXISTS', "The target field $target_field_name already exists.");

  }

  $data_table = _field_sql_storage_tablename($source_field);
  $revision_table = _field_sql_storage_revision_tablename($source_field);
  $data_count = db_select($data_table)->countQuery()->execute()->fetchField();
  $revision_count = db_select($revision_table)->countQuery()->execute()->fetchField();
  if (!drush_confirm(dt("You are about to convert $source_field_name field collection to a $target_field_name multifield. $data_count entity data records and $revision_count entity revision records will also be converted. Are you sure?"))) {
    return FALSE;
  }

  // Double check that the field instances
  $subfields = array();
  $subinstances = field_read_instances(array('entity_type' => 'field_collection_item', 'bundle' => $source_field_name));
  foreach ($subinstances as $subinstance) {
    $subfield = $subfields[$subinstance['field_name']] = field_read_field($subinstance['field_name']);
    if ($subfield['cardinality'] != 1) {
      return drush_set_error('FIELD_NOT_FOUND', "Field $source_field_name cannot be converted since subfield {$subinstance['field_name']} has cardinality of {$subfield['cardinality']} when it should be 1.");
    }
  }

  $instances = field_read_instances(array('field_name' => $source_field_name));
  $settings = field_bundle_settings('field_collection_item', $source_field_name);

  // Disable the field value purging until our operation is finished.
  $old_batch_size = variable_get('field_purge_batch_size', 10);
  variable_set('field_purge_batch_size', 0);

  field_delete_field($source_field_name);
  $source_field['deleted'] = 1;

  // Re-create the field as a multifield.
  $target_field = array_intersect_key($source_field, array_flip(array('settings', 'cardinality', 'locked')));
  $target_field['storage'] = array_intersect_key($source_field['storage'], array_flip(array('type', 'settings')));
  $target_field['type'] = 'multifield';
  $target_field['field_name'] = $target_field_name;
  field_create_field($target_field);

  // Re-create the subinstances.
  foreach ($subinstances as $subinstance) {
    // If the subfield happened to get deleted, recreate it.
    if (!field_read_field($subinstance['field_name'])) {
      $subfield = $subfields[$subinstance['field_name']];
      field_create_field($subfield);
      $subfields[$subinstance['field_name']]['deleted'] = 1;
    }

    $subinstance['entity_type'] = 'multifield';
    $subinstance['bundle'] = $target_field_name;
    field_create_instance($subinstance);
  }

  // Re-read the field now that the subfields were recreated.
  $target_field = field_read_field($target_field_name);

  // Re-create the instances.
  foreach ($instances as $instance) {
    if ($instance['widget']['type'] == 'field_collection_embed') {
      $instance['widget']['type'] = 'multifield_default';
      $instance['widget']['module'] = 'multifield';
    }
    foreach ($instance['display'] as $view_mode => $display) {
      if ($display['type'] == 'field_collection_view') {
        $instance['display'][$view_mode]['type'] = 'multifield_default';
        $instance['display'][$view_mode]['module'] = 'multifield';
      }
    }
    $instance['field_name'] = $target_field_name;
    field_create_instance($instance);
  }

  field_bundle_settings('multifield', $target_field_name, $settings);

  $batch = array();
  if ($data_count) {
    $batch['operations'][] = array('drush_multifield_convert_field_collection_table', array($source_field, $target_field, $subfields, 'data'));
  }
  if ($revision_count) {
    $batch['operations'][] = array('drush_multifield_convert_field_collection_table', array($source_field, $target_field, $subfields, 'revision'));
  }
  if (!empty($batch)) {
    batch_set($batch);
    drush_backend_batch_process();
  }

  variable_set('field_purge_batch_size', $old_batch_size);
}

function drush_multifield_convert_field_collection_table($source_field, $target_field, $subfields, $type, &$context) {
  $source_table = $type == 'data' ? _field_sql_storage_tablename($source_field) : _field_sql_storage_revision_tablename($source_field);
  $target_table = $type == 'data' ? _field_sql_storage_tablename($target_field) : _field_sql_storage_revision_tablename($target_field);

  if (!isset($context['sandbox']['total'])) {
    $context['sandbox']['count'] = 0;
    $context['sandbox']['total'] = db_select($source_table)->countQuery()->execute()->fetchField();
  }

  $query = db_select($source_table, 'old');
  $query->fields('old');
  $query->orderBy('entity_type');
  $query->orderBy('revision_id');
  $query->range($context['sandbox']['count'], 100);
  $records = $query->execute()->fetchAllAssoc($source_field['field_name'] . '_value', PDO::FETCH_ASSOC);
  //var_export($records);
  $context['sandbox']['count'] += count($records);

  foreach ($subfields as $subfield) {
    $columns = array();
    foreach (array_keys($target_field['columns']) as $column_name) {
      if (strpos($column_name, $subfield['field_name']) === 0) {
        $columns[] = $column_name;
      }
    }
    $subtable = $type == 'revision' ? _field_sql_storage_revision_tablename($subfield) : _field_sql_storage_tablename($subfield);
    $subquery = db_select($subtable, 'subfield');
    $subquery->fields('subfield', array_merge($columns, array('entity_id')));
    $subquery->condition('entity_type', 'field_collection_item');
    $subquery->condition('bundle', $source_field['field_name']);
    $subquery->condition('entity_id', array_keys($records), 'IN');
    $subrecords = $subquery->execute()->fetchAllAssoc('entity_id', PDO::FETCH_ASSOC);
    foreach ($subrecords as $id => $subrecord) {
      foreach ($columns as $column_name) {
        $records[$id][$target_field['field_name'] . '_' . $column_name] = $subrecord[$column_name];
      }
    }
  }

  foreach ($records as &$record) {
    $record[$target_field['field_name'] . '_id'] = multifield_get_next_id();
    $record['deleted'] = 0;
    drupal_write_record($target_table, $record);
    entity_get_controller($record['entity_type'])->resetCache(array($record['entity_id']));
  }
  multifield_update_maximum_id($records);

  $context['finished'] = empty($context['sandbox']['total']) ? 1 : ($context['sandbox']['count'] / $context['sandbox']['total']);
}
