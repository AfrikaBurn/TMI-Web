<?php

/**
 * @file
 * Node access password integration with the node module.
 */

/**
 * Implements hook_node_load().
 */
function nodeaccess_password_node_load($nodes, $types) {
  foreach ($nodes as $nid => $node) {
    $nodes[$nid]->nodeaccess_password = array();
    $result = db_query("SELECT realm, password FROM {nodeaccess_password} WHERE nid = :nid", array(':nid' => $node->nid));
    foreach ($result as $row) {
      $nodes[$nid]->nodeaccess_password[$row->realm] = $row->password;
    }
  }
}

/**
 * Implements hook_node_delete().
 */
function nodeaccess_password_node_delete($node) {
  // Deleting node, delete related permissions.
  db_delete('nodeaccess_password')
    ->condition('nid', $node->nid)
    ->execute();

  if (isset($node->nodeaccess_password) && is_array($node->nodeaccess_password)) {
    // Remove node's password(s) from any users that have them.
    foreach ($node->nodeaccess_password as $password) {
      db_delete('nodeaccess_password_users')
        ->condition('password', $password)
        ->execute();
    }
  }
}

/**
 * Generate the passwords for a node.
 */
function nodeaccess_password_node_generate_passwords($node) {
  $realms = nodeaccess_password_node_get_realms($node);

  foreach ($realms as $realm) {
    $has_rows = (bool)db_query_range('SELECT 1 FROM {nodeaccess_password} WHERE nid = :nid AND realm = :realm', 0, 1, array(':nid' => $node->nid, ':realm' => $realm->id))->fetchField();
    if (!$has_rows) {
      // ensure we don't create a duplicate pasword
      $duplicate = 1;
      while ($duplicate) {
        $password = strtolower(user_password(8));
        $duplicate = (bool)db_query_range('SELECT 1 FROM {nodeaccess_password} WHERE password = :password', 0, 1, array(':password' => $password))->fetchField();
      }
      db_insert('nodeaccess_password')
        ->fields(array(
          'nid' => $node->nid,
          'realm' => $realm->id,
          'password' => $password,
        ))
        ->execute();
    }
  }
}

/**
 * Get an array of users who have access to a certain node
 *
 * @param $node
 *   A node object.
 * @return
 *   An array keyed by realm where the values are an array of usernames keyed
 *   by user id.
 */
function nodeaccess_password_node_get_users($node) {
  $passwords = &$node->nodeaccess_password;
  static $user_list = array();
  if (is_array($passwords) && empty($user_list)) {
    foreach ($passwords as $realm => $password) {
      $args = array();
      $sql = "SELECT uid FROM {nodeaccess_password_users} WHERE password = :password";
      $args[':password'] = $password;
      $result = db_query($sql, $args);
      foreach ($result as $row) {
        $account = user_load($row->uid);
        if ($account && in_array($password, nodeaccess_password_user_get_passwords($row->uid))) {
          $user_list[$realm][$row->uid] = $account->name;
        }
      }
    }
  }
  return $user_list;
}

/**
 * Get an array of realms that this node is affected by.
 */
function nodeaccess_password_node_get_realms($node, $reset = FALSE) {
  static $node_realms = array();
  if ($reset) {
    $node_realms = array();
  }
  if (!isset($node_realms[$node->nid])) {
    $realms = nodeaccess_password_get_realms();
    $node_realms[$node->nid] = array();
    foreach ($realms as $realm) {
      if (
        (
          !empty($realm->nodes['views']['view']) &&
          nodeaccess_password_node_in_realm_view($realm, $node, 'node', 'nid')
        )
        ||
        (
          empty($realm->nodes['views']['view']) &&
          !empty($realm->nodes['types']) &&
          in_array($node->type, $realm->nodes['types'])
        )
      ) {
        $node_realms[$node->nid][] = $realm;
      }
    }
  }
  return $node_realms[$node->nid];
}

/**
 * Implements hook_node_grants().
 */
function nodeaccess_password_node_grants($account, $op) {
  $grants = nodeaccess_password_user_get_nodes($account, 'nodeaccess_password_realm_');
  $grants['nodeaccess_password_author'][] = $account->uid;
  return $grants;
}

/**
 * Implements hook_node_access_records().
 */
function nodeaccess_password_node_access_records($node) {
  // Generate a password for the node, if none set.
  nodeaccess_password_node_generate_passwords($node);
  $grants = array();
  $realms = nodeaccess_password_node_get_realms($node);
  foreach ($realms as $realm) {
    if (!empty($node->status) || !empty($realm->grants_published)) {
      nodeaccess_password_add_grant(
        $grants,
        'nodeaccess_password_realm_' . $realm->id,
        $node->nid,
        $realm->priority,
        $realm->grants
      );
    }
    if (!empty($node->status) || !empty($realm->author_published)) {
      nodeaccess_password_add_grant(
        $grants,
        'nodeaccess_password_author',
        $node->nid,
        $realm->priority,
        $realm->author
      );
    }
    if (!empty($node->status) || !empty($realm->all_published)) {
      nodeaccess_password_add_grant(
        $grants,
        'nodeaccess_password_all',
        $node->nid,
        $realm->priority,
        $realm->all
      );
    }
  }
  return $grants;
}

/**
 * Add node grants in a way that prevents overriding previous iterations.
 *
 * @param &$grants
 *  The grants array where the grant will be added.
 * @param $realm
 *  The realm of this grant.
 * @param $gid
 *  The grant ID.
 * @param $priority
 *  The grant priority.
 * @param $settings
 *  An settings array of boolean equivalent values with keys 'view', 'edit',
 *  and 'delete'.
 */
function nodeaccess_password_add_grant(&$grants, $realm, $gid, $priority, $settings) {
  $key = $realm . $gid;
  if (!isset($grants[$key])) {
    // Setup the record.
    $grants[$key] = array(
      'realm' => $realm,
      'gid' => $gid,
      'priority' => $priority,
      'grant_view' => 0,
      'grant_update' => 0,
      'grant_delete' => 0,
    );
  }
  // Add the grants needed, so as not to override previous iterations.
  if (isset($settings['view']) && $settings['view']) {
    $grants[$key]['grant_view'] = 1;
  }
  if (isset($settings['update']) && $settings['update']) {
    $grants[$key]['grant_update'] = 1;
  }
  if (isset($settings['delete']) && $settings['delete']) {
    $grants[$key]['grant_delete'] = 1;
  }
  // Increase the priority if needed.
  if ($priority > $grants[$key]['priority']) {
    $grants[$key]['priority'] = $priority;
  }
}

/**
 * Implements hook_node_access_explain().
 *
 * This gives the Devel module nice information to display when
 * debugging node grants.
 */
function nodeaccess_password_node_access_explain($row) {
  if (substr($row->realm, 0, 19) == 'nodeaccess_password') {
    foreach (array('view', 'update', 'delete') as $op) {
      $gop = 'grant_' . $op;
      if (!empty($row->$gop)) {
        $ops[] = $op;
      }
    }

    if (!empty($ops)) {
      $do = implode('/', $ops);
      if ($row->realm == 'nodeaccess_password_author') {
        $node = node_load($row->nid);
        $name = format_username(user_load($node->uid));
        return t(
          'Node author %name may !do this node',
          array(
            '%name' => $name,
            '!do' => $do,
          )
        );
      }
      elseif ($row->realm == 'nodeaccess_password_all') {
        return t(
          'All users may !do this node',
          array(
            '!do' => $do,
          )
        );
      }
      elseif (substr($row->realm, 0, 26) == 'nodeaccess_password_realm_') {
        $realm = nodeaccess_password_realm_load(str_replace('nodeaccess_password_realm_', '', $row->realm));
        return t(
          "Users that have this node's %realm Node access password and may !do this node",
          array(
            '%realm' => $realm->name,
            '!do' => $do,
          )
        );
      }
    }

  }
}

/**
 * Determine if the node falls into the view.
 *
 * @param $realm
 *  The node access password realm object, with the view configured.
 * @param $entity
 *  The node or user object.
 * @param $entity_type
 *  String giving the base table to be used by views. e.g. 'node'.
 * @param $entity_id
 *  String id key field for the entity, e.g. 'nid'. Doesn't support multiple keys.
 * @return
 *  Boolean indicating if the entity is in the view defined by the realm.
 */
function nodeaccess_password_node_in_realm_view($realm, $entity, $entity_type, $entity_id) {
  $view_id = $realm->nodes['views']['view'];
  list($view_name, $view_display) = explode(':', $view_id);

  if ($view = views_get_view($view_name)) {

    // We add a display, and let it derive from the 'default' display.
    $display = $view->add_display('nodeaccess_password_views_plugin_display');
    $view->set_display($display);

    // Get the options from the user supplied display.
    if ($view_display != 'default' && isset($view->display[$view_display]->display_options)) {
      $view->display[$display]->display_options = $view->display[$view_display]->display_options;
    }

    // TODO from merlinofchaos on IRC : arguments using summary view can defeat the style setting.
    // We might also need to check if there's an argument, and set *its* style_plugin as well.
    $view->display_handler->set_option('style_plugin', 'nodeaccess_password_views_plugin_style');
    $view->display_handler->set_option('row_plugin', 'fields');

    // Additional options to let node_reference_display::query()
    // narrow the results.
    $options = array(
      'table' => $entity_type,
      'field_id' => $entity_id,
      'id' => $entity->$entity_id,
    );

    $view->display_handler->set_option('nodeaccess_password_options', $options);

    // TODO : for consistency, a fair amount of what's below
    // should be moved to node_reference_display

    // Limit to a single result.
    $view->display_handler->set_option('items_per_page', 1);

    // Get arguments for the view.
    if (!empty($realm->nodes['views']['view_args'])) {
      $view_args = array_map('trim', explode(',', $realm->nodes['views']['view']));
    }
    else {
      $view_args = array();
    }

    // Make sure the query is not cached
    $view->is_cacheable = FALSE;

    // Get the results.
    $result = $view->execute_display($display, $view_args);
  }
  else {
    $result = FALSE;
  }

  return $result;
}