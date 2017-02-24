<?php
/**
 * @file
 * API documentation for users_export module.
 *
 * @ingroup users_export
 */

/**
 * Implements hook_users_export_row_alter().
 *
 * Modify the contents of an exported row
 *
 * @param array &$row
 * @param int   $uid
 * @param array $context
 *   - settings array The form_state values coming from the submission form.
 *
 * @return NULL
 */
function hook_users_export_row_alter(&$row, $uid, $context) {
  $settings = $context['settings'];
  $names = &drupal_static(__FUNCTION__, array());
  if (empty($names)) {

    // Add in the first and last name of the user
    $query = db_select('field_data_field_first_name', 'f');
    $names['first'] = $query
      ->fields('f', array('entity_id', 'field_first_name_value'))
      ->execute()->fetchAllAssoc('entity_id');

    $query = db_select('field_data_field_last_name', 'l');
    $names['last'] = $query
      ->fields('l', array('entity_id', 'field_last_name_value'))
      ->execute()->fetchAllAssoc('entity_id');
  }
  $row['first_name'] = empty($names['first'][$uid]->field_first_name_value) ? '' : $names['first'][$uid]->field_first_name_value;
  $row['last_name'] = empty($names['last'][$uid]->field_last_name_value) ? '' : $names['last'][$uid]->field_last_name_value;
}

/**
 * Implements hook_users_export_exporter_alter().
 *
 * @param ExporterInterface $exporter
 */
function hook_users_export_exporter_alter(ExporterInterface $exporter) {

  // Example shows how we can reverse the order of the columns
  $keys = $exporter->getData()->getKeys();
  $keys = array_reverse($keys);
  $exporter->getData()->setKeys($keys);
}

/**
 * Implements hook_menu_alter().
 *
 * An example how to change the url of the export page
 *
 * @link https://www.drupal.org/node/2824163
 */
function hook_menu_alter(&$items) {
  if (isset($items['admin/people/export'])) {
    $items['do/re/mi'] = $items['admin/people/export'];
    unset($items['admin/people/export']);

    // Change the title
    $items['do/re/mi']['title'] = t('Export User List');

    // Move it to the main menu
    $items['do/re/mi']['menu_name'] = 'main-menu';

    // Make it a normal item
    $items['do/re/mi']['type'] = MENU_NORMAL_ITEM;
  }
}

/**
 * Implements hook_admin_paths().
 */
function hook_admin_paths() {
  return array(

    // Indicate we want our path defined above to use the admin theme.
    'do/re/mi' => TRUE,
  );
}
