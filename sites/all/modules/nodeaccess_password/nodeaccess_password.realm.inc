<?php

/**
 * @file
 * Node access password realm functionality.
 */

/**
 * Save a realm record.
 */
function nodeaccess_password_realm_save(&$realm) {
  $primary_key = array();
  $op = 'nodeaccess_password_realm_insert';
  if (!empty($realm->id)) {
    $op = 'nodeaccess_password_realm_update';
    $primary_key[] = 'id';
  }
  // Copy everything other than id, name, and settings into $realm->settings.
  // This ensures drupal_write_record() will save properly.
  foreach ($realm as $key => $value) {
    if (!in_array($key, array('id', 'name', 'settings'))) {
      $realm->settings[$key] = $value;
    }
  }
  drupal_write_record('nodeaccess_password_realm', $realm, $primary_key);
  // Remove $realm->settings as it is not used directly.
  unset($realm->settings);
  nodeaccess_password_realm_api($realm, $op);
}

/**
 * Delete a realm record.
 */
function nodeaccess_password_realm_delete($id) {
  $realm = nodeaccess_password_realm_load($id);
  db_delete('nodeaccess_password_realm')
    ->condition('id', array($id), 'IN')
    ->execute();
  nodeaccess_password_realm_api($realm, 'nodeaccess_password_realm_delete');
  watchdog('nodeaccess_password', 'Realm %title deleted.', array('%title' => $realm->name));
  drupal_set_message(t('Realm %title has been deleted.', array('%title' => $realm->name)));
  // Reset load cache.
  nodeaccess_password_load_objects('nodeaccess_password_realm', NULL, array(), TRUE);
}

/**
 * Load a single realm record.
 */
function nodeaccess_password_realm_load($id = NULL, $reset = FALSE) {
  $ids = $id ? array($id) : array();
  $realms = nodeaccess_password_load_objects('nodeaccess_password_realm', $ids, array(), $reset);
  return isset($realms[$id]) ? $realms[$id] : FALSE;
}

/**
 * Load objects from the database.
 *
 * This is intended as a reverse 'drupal_write_record' based on the code from
 * an early node_load_multiple() in Drupal 7.  It can be used to read records
 * from any table assuming they are keyed by a serial field named {table}_id.
 * Also supports serialized fields.
 *
 * @param $load
 *   The name of the table, and thus the type of object to load.
 * @param $ids
 *   An array of IDs, if selecting by ID.
 * @param $conditions
 *   An array of conditions on the table, each value being an array in the form
 *   array('field', $value, $operator).
 * @param $reset
 *   Whether to reset the internal cache for this type of $load object.
 * @return
 *   An array of loaded objects indexed by ID.
 */
function nodeaccess_password_load_objects($load, $ids = NULL, $conditions = array(), $reset = FALSE) {
  static $object_cache = array();
  if ($reset) {
    $object_cache[$load] = array();
  }

  if (!isset($object_cache[$load])) {
    $object_cache[$load] = array();
  }

  $objects = array();

  $id_key = 'id';

  // Create a new variable which is either a prepared version of the $ids
  // array for later comparison with the realm cache, or FALSE if no $ids were
  // passed. The $ids array is reduced as items are loaded from cache, and we
  // need to know if it's empty for this reason to avoid querying the database
  // when all requested objects are loaded from cache.

  $passed_ids = !empty($ids) ? array_flip($ids) : FALSE;

  // Load any available objects from the internal cache.
  if ($object_cache[$load]) {
    if (!empty($ids)) {
      $objects += array_intersect_key($object_cache[$load], $passed_ids);
      // If any objects were loaded, remove them from the $ids still to load.
      $ids = array_keys(array_diff_key($passed_ids, $objects));
    }
    // If loading objects only by conditions, fetch all available objects from
    // the cache. objects which don't match are removed later.
    elseif ($conditions) {
      $objects = $object_cache[$load];
    }
  }

  // Exclude any objects loaded from cache if they don't match $conditions.
  // This ensures the same behavior whether loading from memory or database.
  if (!empty($conditions)) {
    foreach ($objects as $object) {
      $object_values = (array) $object;
      if (array_diff_assoc($conditions, $object_values)) {
        unset($objects[$object->$id_key]);
      }
    }
  }

  // Load objects from the database. This is the case if there are
  // any $ids left to load, if $conditions was passed without $ids,
  // or if $ids and $conditions were intentionally left blank.
  if ((!empty($ids) || ($conditions && !$passed_ids)) || ($ids === NULL && $conditions === array())) {
    $query = array();

    // Build query.
    $query = db_select($load)->fields($load);
    if (!empty($ids)) {
      $query->condition($id_key, $ids, 'IN');
    }
    if (!empty($conditions)) {
      foreach ($conditions as $condition) {
        list($field, $value, $operator) = $condition;
        $query->condition($field, $value, $operator);
      }
    }

    $queried_objects = $query->execute()->fetchAllAssoc($id_key);

  }

  // Pass all objects loaded from the database through the hooks, then add them
  // to the internal cache.
  if (!empty($queried_objects)) {

    foreach ($queried_objects as $q_key => $q_object) {

      // Unserialize settings.
      if (isset($q_object->settings)) {
        if (!isset($queried_objects[$q_key])) {
          $queried_objects[$q_key] = array();
        }
        $queried_objects[$q_key] = (object)array_merge(
          (array)$queried_objects[$q_key],
          (array)unserialize($q_object->settings)
        );
        unset($queried_objects[$q_key]->settings);
      }

      // Invoke realm_api so modules can make changes.
      nodeaccess_password_realm_api($queried_objects[$q_key], $load . '_load');
    }

    $objects += $queried_objects;
    // Add objects to the cache.
    foreach ($queried_objects as $queried_object) {
      $object_cache[$load][$queried_object->$id_key] = $queried_object;
    }

  }

  return $objects;
}

/**
 * Get an array of all active realms.
 */
function nodeaccess_password_get_realms() {
  return nodeaccess_password_load_objects(
    'nodeaccess_password_realm',
    NULL,
    array(
      array('name', '', '<>'),
    )
  );
}

/**
 * Invoke hook_nodeaccess_password_realm_api().
 *
 * @param &$object
 *   The realm.
 * @param $op
 *   The operation, indicates where/when this is being invoked.
 * @param $a3, $a4
 *   Arguments to pass to the hook implementation.
 * @return
 *   The returned value of the invoked hooks.
 */
function nodeaccess_password_realm_api(&$object, $op, $a3 = NULL, $a4 = NULL) {
  $return = array();
  foreach (module_implements('nodeaccess_password_realm_api') as $name) {
    $function = $name . '_nodeaccess_password_realm_api';
    $result = $function($object, $op, $a3, $a4);
    if (isset($result) && is_array($result)) {
      $return = array_merge($return, $result);
    }
    elseif (isset($result)) {
      $return[] = $result;
    }
  }
  return $return;
}