<?php
/**
 * @file
 * feature_core_fields..inc
 */

/**
 * Implements hook_multifield_default_multifield().
 */
function feature_core_fields_multifield_default_multifield() {
  $export = array();

  $multifield = new stdClass();
  $multifield->disabled = FALSE; /* Edit this to true to make a default multifield disabled initially */
  $multifield->machine_name = 'field_dimentions_foot_print_m2';
  $multifield->label = 'field_dimentions_foot_print_m2';
  $multifield->description = '';
  $export['field_dimentions_foot_print_m2'] = $multifield;

  $multifield = new stdClass();
  $multifield->disabled = FALSE; /* Edit this to true to make a default multifield disabled initially */
  $multifield->machine_name = 'field_dimentions_m2';
  $multifield->label = 'field_dimentions_m2';
  $multifield->description = '';
  $export['field_dimentions_m2'] = $multifield;

  return $export;
}
