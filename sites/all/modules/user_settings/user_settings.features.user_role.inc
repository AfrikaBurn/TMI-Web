<?php
/**
 * @file
 * user_settings.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function user_settings_user_default_roles() {
  $roles = array();

  // Exported role: Support.
  $roles['Support'] = array(
    'name' => 'Support',
    'weight' => 2,
  );

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 3,
  );

  return $roles;
}
