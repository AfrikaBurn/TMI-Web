<?php
/**
 * @file
 * theme_camps..inc
 */

/**
 * Implements hook_multifield_default_multifield().
 */
function theme_camps_multifield_default_multifield() {
  $export = array();

  $multifield = new stdClass();
  $multifield->disabled = FALSE; /* Edit this to true to make a default multifield disabled initially */
  $multifield->machine_name = 'field_creative_lead';
  $multifield->label = 'field_creative_lead';
  $multifield->description = '';
  $export['field_creative_lead'] = $multifield;

  return $export;
}
