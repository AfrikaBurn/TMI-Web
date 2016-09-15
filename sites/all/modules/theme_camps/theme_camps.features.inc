<?php
/**
 * @file
 * theme_camps.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function theme_camps_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function theme_camps_node_info() {
  $items = array(
    'theme_camps' => array(
      'name' => t('Theme Camps'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Name of the Theme Camp'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
