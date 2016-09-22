<?php

/**
 * @file
 * Possibly include 3rd party module hooks that should be in those modules and
 * might be, that's why they're includes with a nasty function_exists() around it.
 */

// blockreference.module
if (!function_exists('blockreference_entityreference_link_config')) {
  require __DIR__ . '/modules/entityreference_link.blockreference.inc';
}

// entityreference.module
if (!function_exists('entityreference_entityreference_link_config')) {
  require __DIR__ . '/modules/entityreference_link.entityreference.inc';
}

// taxonomy.module
if (!function_exists('taxonomy_entityreference_link_config')) {
  require __DIR__ . '/modules/entityreference_link.taxonomy.inc';
}
