<?php
/**
 * @file
 * user_settings..inc
 */

/**
 * Implements hook_multifield_default_multifield().
 */
function user_settings_multifield_default_multifield() {
  $export = array();

  $multifield = new stdClass();
  $multifield->disabled = FALSE; /* Edit this to true to make a default multifield disabled initially */
  $multifield->machine_name = 'field_bb_minors_details';
  $multifield->label = 'field_bb_minors_details';
  $multifield->description = '';
  $export['field_bb_minors_details'] = $multifield;

  return $export;
}
