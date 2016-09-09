<?php

/**
 * @file
 * API documentation for Select or other.
 */


/**
 * Provide a list of options for a select or other field. Options can be keyed,
 * unkeyed or a combination of both. Keyed values should be entered in a
 * key|value fashion. Unkeyed options will automatically be keyed with a key
 * identical to the value.
 *
 * Options provided using this hook can be overwritten by options provided in
 * the 'Available options' field on the instance settings form.
 */
function hook_select_or_other_available_options($entity_type, $bundle, $field_name){
  if ($entity_type === 'node' && $bundle === 'page' && $field_name === 'field_some_field') {
    return array(
      'keyed|A keyed value',
      'unkeyed',
    );
  }
}
