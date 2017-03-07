<?php

/**
 * @file
 * Custom Formatters module integration.
 */

/**
 * Implements hook_custom_formatters_token_tree_types_alter().
 */
function field_tokens_custom_formatters_token_tree_types_alter(&$token_types, $field_type) {
  $token_types[] = "formatted_field-{$field_type}";
  $token_types[] = 'field_property';
}

/**
 * Implements hook_custom_formatters_token_data_alter().
 */
function field_tokens_custom_formatters_token_data_alter(&$token_data, &$text, $field, $delta) {
  // Formatted field tokens context data.
  $token_data["formatted_field-{$field['type']}"] = array($token_data['item']);
  $token_data['entity_type']                      = $token_data['obj_type'];
  $token_data['entity']                           = $token_data[$token_data['obj_type']];
  $token_data['field_name']                       = $field['field_name'];

  // Field property tokens context data.
  $token_data['field_property'] = array($token_data['item']);
}
