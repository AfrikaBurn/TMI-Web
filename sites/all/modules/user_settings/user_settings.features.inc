<?php
/**
 * @file
 * user_settings.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function user_settings_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "field_validation" && $api == "default_field_validation_rules") {
    return array("version" => "2");
  }
  if ($module == "multifield" && $api == "") {
    return array("version" => "");
  }
}
