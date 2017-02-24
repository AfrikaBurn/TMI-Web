<?php

/**
 * @file
 * Block Reference's shadow implementation of hook_entityreference_link_config().
 */

/**
 * Implements hook_entityreference_link_config().
 */
function blockreference_entityreference_link_config() {
  return array(
    'blockreference' => array(
      'value_column' => 'bid',
      'links_callback' => '_entityreference_link_blocks_links',
    ),
  );
}

/**
 * Helper to make simple links from blocks.
 */
function _entityreference_link_blocks_links($entity_type, $bids, $options, $context, $element) {
  $blocks = db_query('SELECT * FROM {block} WHERE bid IN (:bids)', array(':bids' => $bids))->fetchAll();
  $links = $block_infos = array();
  foreach ($blocks as $block) {
    isset($block_infos[$block->module]) or $block_infos[$block->module] = module_invoke($block->module, 'block_info');

    if (isset($block_infos[$block->module][$block->delta])) {
      $title = $block_infos[$block->module][$block->delta]['info'];
      $links[] = l($title, 'admin/structure/block/manage/' . $block->module . '/' . $block->delta . '/configure', $options);
    }
  }

  return $links;
}
