<?php

/**
 * @file
 * This file contains the menu callbacks for the Entity Reference Multiple
 * module.
 */

/**
 * Menu callback for the Entity Reference Multiple Autocomplete.
 *
 * @param string $field_name
 *   The field name to autocomplete is called from.
 * @param string $entity_type
 *   The entity type this field is attached to.
 * @param string $bundle_name
 *   The name of the bundle this field is attached to.
 * @param string $target_type
 *   The searchable entity type.
 * @param string $search_string
 *   The label of the entity to query by.
 */
function entity_reference_multiple_autocomplete_page_callback($field_name, $entity_type, $bundle_name, $target_type, $search_string = '') {
  // If the request has a '/' in the search text, then the menu system will have
  // split it into multiple arguments, recover the intended $tags_typed.
  $args = func_get_args();

  // Shift off the $field_name, $entity_type, $bundle_name adn $target_type.
  $args = array_slice($args, 4);
  $search_string = implode('/', $args);

  $field = field_info_field($field_name);
  $instance = field_info_instance($entity_type, $field_name, $bundle_name);

  // Build entity query.
  $entities = _entity_reference_multiple_entities_matching_search($field, $instance, $target_type, $search_string);

  // Prepare entities for output.
  $matches = _entity_reference_multiple_prepare_entities_for_autocomplete($entities, $target_type);

  drupal_json_output($matches);
}
