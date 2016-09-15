<?php
/**
 * @file
 * creative_grants.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function creative_grants_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_application_amount'.
  $field_bases['field_application_amount'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_application_amount',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'number',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'number_integer',
  );

  return $field_bases;
}
