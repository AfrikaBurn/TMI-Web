<?php
/**
 * @file
 * artwork_registration.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function artwork_registration_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create artwork_registration content'.
  $permissions['create artwork_registration content'] = array(
    'name' => 'create artwork_registration content',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any artwork_registration content'.
  $permissions['delete any artwork_registration content'] = array(
    'name' => 'delete any artwork_registration content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own artwork_registration content'.
  $permissions['delete own artwork_registration content'] = array(
    'name' => 'delete own artwork_registration content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any artwork_registration content'.
  $permissions['edit any artwork_registration content'] = array(
    'name' => 'edit any artwork_registration content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own artwork_registration content'.
  $permissions['edit own artwork_registration content'] = array(
    'name' => 'edit own artwork_registration content',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  return $permissions;
}
