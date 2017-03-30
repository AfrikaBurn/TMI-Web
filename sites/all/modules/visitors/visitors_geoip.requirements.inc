<?php

/* vim: set filetype=php: */

/**
 * @file
 * Checks requirements.
 */

/**
 * Implements of hook_requirements().
 */
function visitors_geoip_requirements($phase) {
  $requirements = array();
  // Ensure translations don't break at install time
  $t = get_t();

  $requirements['visitors_geoip'] = array(
    'title' => $t('Visitors GeoIP module'),
  );

  if (!function_exists('geoip_record_by_name')) {
    $requirements['visitors_geoip']['value'] = $t(
      'The %extension_geoip PHP extension is not installed!',
      array('%extension_geoip' => 'geoip')
    );
    $requirements['visitors_geoip']['severity'] = REQUIREMENT_ERROR;
    return $requirements;
  }

  $geoip_db = GEOIP_CITY_EDITION_REV1;
  $geoip_db_filename = geoip_db_filename($geoip_db);
  $geoip_db_name = 'GeoIP City';

  if (!geoip_db_avail($geoip_db)) {
    $requirements['visitors_geoip']['value'] = $t(
      'The %geoip_db_name database file is not available at %geoip_db_file!',
      array(
        '%geoip_db_name' => $geoip_db_name,
        '%geoip_db_file' => $geoip_db_filename
      )
    );
    $requirements['visitors_geoip']['severity'] = REQUIREMENT_ERROR;
    return $requirements;
  }

  $geoip_database_info = geoip_database_info($geoip_db);
  $requirements['visitors_geoip']['value'] = $t(
    'The %geoip_db_name database file is available at %geoip_db_file',
    array(
      '%geoip_db_name' => $geoip_db_name,
      '%geoip_db_file' => $geoip_db_filename
    )
  );
  $requirements['visitors_geoip']['description'] = $geoip_db_name .
    $t(' database version: ') . $geoip_database_info;
  $requirements['visitors_geoip']['severity'] = REQUIREMENT_OK;
  return $requirements;
}

