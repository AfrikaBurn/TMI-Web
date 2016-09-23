<?php

/**
 * @file
 * Taxonomy's shadow implementation of hook_entityreference_link_config().
 */

/**
 * Implements hook_entityreference_link_config().
 */
function taxonomy_entityreference_link_config() {
  return array(
    'taxonomy_term_reference' => array(
      'value_column' => 'tid',
      'target_type' => 'taxonomy_term',
    ),
  );
}
