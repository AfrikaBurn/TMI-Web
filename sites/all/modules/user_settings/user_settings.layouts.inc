<?php
/**
 * @file
 * user_settings.layouts.inc
 */

/**
 * Implements hook_default_panels_layout().
 */
function user_settings_default_panels_layout() {
  $export = array();

  $layout = new stdClass();
  $layout->disabled = FALSE; /* Edit this to true to make a default layout disabled initially */
  $layout->api_version = 1;
  $layout->name = 'home_test';
  $layout->admin_title = 'Home Test';
  $layout->admin_description = '';
  $layout->category = '';
  $layout->plugin = 'flexible';
  $layout->settings = array();
  $export['home_test'] = $layout;

  return $export;
}
