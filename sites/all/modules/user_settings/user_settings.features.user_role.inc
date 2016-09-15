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

  // Exported role: DMV Admin.
  $roles['DMV Admin'] = array(
    'name' => 'DMV Admin',
    'weight' => 3,
  );

  // Exported role: DMV Wrangle.
  $roles['DMV Wrangle'] = array(
    'name' => 'DMV Wrangle',
    'weight' => 2,
  );

  // Exported role: Support.
  $roles['Support'] = array(
    'name' => 'Support',
    'weight' => 4,
  );

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 5,
  );

  return $roles;
}
