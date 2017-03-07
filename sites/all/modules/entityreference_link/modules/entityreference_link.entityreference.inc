<?php

/**
 * @file
 * Entity Reference's shadow implementation of hook_entityreference_link_config().
 */

/**
 * Implements hook_entityreference_link_config().
 */
function entityreference_entityreference_link_config() {
  return array(
    'entityreference' => array(
      'value_column' => 'target_id',
      'target_type_callback' => function($context, $element) {
        $field = $context['field'];
        return $field['settings']['target_type'];
      },
    ),
  );
}
