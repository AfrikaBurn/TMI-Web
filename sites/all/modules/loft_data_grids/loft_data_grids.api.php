<?php
/**
 * @file
 * API documentation for loft_data_grids module.
 */

/**
 * Implements hook_loft_data_grids_info_alter(&$info).
 *
 * @param array &$info
 */
function hook_loft_data_grids_info_alter(&$info) {
  if (isset($info['MarkdownExporter'])) {
    // Alter the class used for the markdown exporter.
    $info['MarkdownExporter']['class'] = 'JSmith\LoftDataGrids\MarkdownExporter';
  }
}
