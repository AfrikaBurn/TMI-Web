<?php
/**
 * @file
 * user_settings.ds.inc
 */

/**
 * Implements hook_ds_view_modes_info().
 */
function user_settings_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'anonymous_user';
  $ds_view_mode->label = 'Anonymous User';
  $ds_view_mode->entities = array(
    'user' => 'user',
  );
  $export['anonymous_user'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'multifield_view';
  $ds_view_mode->label = 'Multifield';
  $ds_view_mode->entities = array(
    'multifield' => 'multifield',
  );
  $export['multifield_view'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'user_admin_edit';
  $ds_view_mode->label = 'User Admin Edit';
  $ds_view_mode->entities = array(
    'user' => 'user',
  );
  $export['user_admin_edit'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'user_admin_view';
  $ds_view_mode->label = 'User admin view';
  $ds_view_mode->entities = array(
    'user' => 'user',
  );
  $export['user_admin_view'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'user_edit_view';
  $ds_view_mode->label = 'User Edit View';
  $ds_view_mode->entities = array(
    'user' => 'user',
  );
  $export['user_edit_view'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'user_view';
  $ds_view_mode->label = 'User View';
  $ds_view_mode->entities = array(
    'user' => 'user',
  );
  $export['user_view'] = $ds_view_mode;

  return $export;
}
