<?php
/**
 * @file
 * artwork_registration_features_download.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function artwork_registration_features_download_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function artwork_registration_features_download_node_info() {
  $items = array(
    'artwork_registration' => array(
      'name' => t('Artwork Registration'),
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
