<?php
/**
 * @file
 * performance_registration.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function performance_registration_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function performance_registration_node_info() {
  $items = array(
    'performance_registration' => array(
      'name' => t('Performance Registration'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title of the Project'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
