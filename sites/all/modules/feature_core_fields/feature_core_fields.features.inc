<?php
/**
 * @file
 * feature_core_fields.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_core_fields_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}
