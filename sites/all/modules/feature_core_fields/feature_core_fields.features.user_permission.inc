<?php
/**
 * @file
 * feature_core_fields.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function feature_core_fields_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'delete terms in sound_level'.
  $permissions['delete terms in sound_level'] = array(
    'name' => 'delete terms in sound_level',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in sound_level'.
  $permissions['edit terms in sound_level'] = array(
    'name' => 'edit terms in sound_level',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  return $permissions;
}
