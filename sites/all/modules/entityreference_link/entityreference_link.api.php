<?php

/**
 * Implements hook_entityreference_link_config().
 *
 * Config is not cached persistent, so don't do anything crazy. The upside: use closures!
 */
function hook_entityreference_link_config() {
  return array(
    'entityreference' => array(
      // The column the entity id is in. Must always be one column. Used to extract ids AND to insert links.
      'value_column' => 'target_id',

      // If that's not good enough, you can add your custom extractor. Anything falsey will be ignored.
      'ids_callback' => function($context, $element) {
        return array_map(function($item) {
          return $item['column_a'] ? $item['column_b'] : $item['column_c']; // This would be very odd...
        }, $context['items']);
      },

      // The entity type of the targeted reference. For taxonomy references, that's static.
      'target_type' => 'taxonomy_term',
      // For entity references, that's dynamic, so it can be a callback.
      'target_type_callback' => function($context, $element) {
        $field = $context['field'];
        return $field['settings']['target_type'];
      },

      // The links processor: for real entities that can be the default, but for blocks it's a custom. This
      // could be a closure too, but you might want to reuse that awesome function.
      'links_callback' => '_entityreference_link_entity_links', // The default.
      'links_callback' => '_blockreference_entityreference_link_links', // A custom.
      'links_callback' => function($target_type, $ids, $options, $context, $element) { // A closure.
        // Do magic here. Create links using l() with $options. Entity links usually go to the edit form.
        // Block links to the block config form.
      },
    ),
  );
}
