<?php
/**
 * @file
 * creative_grants.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function creative_grants_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function creative_grants_node_info() {
  $items = array(
    'creative_grant_application' => array(
      'name' => t('Creative Grant Application'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
