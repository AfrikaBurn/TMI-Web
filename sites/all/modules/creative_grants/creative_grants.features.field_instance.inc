<?php
/**
 * @file
 * creative_grants.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function creative_grants_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'node-creative_grant_application-field_application_amount'.
  $field_instances['node-creative_grant_application-field_application_amount'] = array(
    'bundle' => 'creative_grant_application',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_integer',
        'weight' => 16,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_application_amount',
    'label' => 'AMOUNT YOU\'RE APPLYING FOR',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'max' => '',
      'min' => 0,
      'prefix' => 'R',
      'suffix' => 'ZAR (South African Rands)',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 8,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('AMOUNT YOU\'RE APPLYING FOR');

  return $field_instances;
}
