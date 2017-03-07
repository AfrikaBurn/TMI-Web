<?php
/**
 * @file
 * artwork_registration..inc
 */

/**
 * Implements hook_multifield_default_multifield().
 */
function artwork_registration_multifield_default_multifield() {
  $export = array();

  $multifield = new stdClass();
  $multifield->disabled = FALSE; /* Edit this to true to make a default multifield disabled initially */
  $multifield->machine_name = 'field_artwork_site_clean';
  $multifield->label = 'field_artwork_site_clean';
  $multifield->description = '';
  $export['field_artwork_site_clean'] = $multifield;

  return $export;
}
