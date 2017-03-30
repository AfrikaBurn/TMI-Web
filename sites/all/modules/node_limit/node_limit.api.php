<?php
/**
 * @file
 * Node_limit api reference.
 */

/**
 * Check node limit context.
 * 
 * Called when trying to know which submodule is concerned by a given node limit.
 * Each of them have to answer with an integer as follow :
 *   NODE_LIMIT_LIMIT_NEUTRAL if the node limit do nos use this submodule ;
 *   NODE_LIMIT_LIMIT_DOESNT_APPLY if this submodule is not concerned ;
 *   NODE_LIMIT_LIMIT_DOES_APPLY if this submodule is concerned.
 * 
 * @param int $lid
 *   The node limit id.
 * @param object $node
 *   The node to check.
 * @param object $user
 *   The user to check.
 * @return array
 *   An array with a single key-value pair. The key must be the name of the 
 *   submodule, and the value is an integer between 0 and 2 inclusive.
 */
function hook_node_limit_applies_in_context($lid, $node, $user) {
  // Load limit data
  $limit = submodule_node_limit_load($lid);
  
  $applies = NODE_LIMIT_LIMIT_DOES_APPLY;
  if (empty($limit)) {
    $applies = NODE_LIMIT_LIMIT_NEUTRAL;
  }
  elseif ($limit['submodule']['uid'] != $user->uid) {
    $applies = NODE_LIMIT_LIMIT_DOESNT_APPLY;
  }

  return array('submodule' => $applies);
}

/**
 * Delete submodules' data.
 * 
 * Called when deleting a node_limit.
 * 
 * @param array $lids
 *   An array of node limit ids. Cannot be empty.
 */
function hook_node_limit_delete($lids) {
  db_delete('submodule')
    ->condition('lid', $lids, 'IN')
    ->execute();
}

/**
 * Return submodules' form elements.
 * 
 * You may set the value '#custom_render' => true if your element requires a 
 * custom rendering. The $lid parameter is given if the user is editing 
 * (as opposed to adding) a node limit.  The implementor should fill in a 
 * #default_value for the element.
 * 
 * @param int $lid
 *   The node limit id.
 * @return array
 *   An array with a single key-value pair. The key must be the name of the 
 *   submodule, and the value is an element in form api.
 */
function hook_node_limit_element($lid = 0) {
  $limit = submodule_node_limit_load($lid);
  $name = !empty($limit['submodule']['name']) ? $limit['submodule']['name'] : '';
  return array(
    'submodule' => array(
      '#type' => 'textfield',
      '#title' => t('User'),
      '#autocomplete_path' => 'user/autocomplete',
      '#default_value' => $name
    )
  );
}

/**
 * Validate a submodules' elements values.
 * 
 * Called when the user attempts to add or edit a Node Limit.  The implementor 
 * of the hook has the opportunity to validate the value the user entered.
 * 
 * @param object $element
 *   The element.
 * @return array
 *   TODO explain
 */
function hook_node_limit_element_validate($element) {
  /**
   * Validation:
   * User cannot be user:1
   * User must be in the {user} table
   */
  $potential_user = user_load_by_name($element);
  if ($potential_user->uid == 1) {
    //we cannot apply a limit to user:1
    return array(
      'error' => t('Node Limits cannot be applied to User #1')
    );
  }
  elseif ($potential_user === FALSE) {
    //unknown user
    return array(
      'error' => t('Unknown user "!user"', array('!user' => $element))
    );
  }
  return TRUE;
}

/**
 * Load submodules' data.
 * 
 * Called when node_limit loads a limit from the database.
 * 
 * @param int $lid
 *   The node limit id.
 * @return array
 *   An array with a single key-value pair. The key must be the name of the 
 *   submodule, and the value is an array containing submodule's data.
 */
function hook_node_limit_load($lid) {
  $select = db_select('submodule', 'sub');
  $select->join('users', 'u', 'u.uid = sub.uid');
  $select->fields('sub')
    ->fields('u', array('name'))
    ->condition('lid', $lid);

  $info = $select->execute()->fetchAssoc();
  if (empty($info['uid'])) {
    return array();
  }
  return array(
    'submodule' => array(
      'uid' => $info['uid'],
      'name' => $info['name']
    )
  );
}

/**
 * Special render for special elements.
 * 
 * Called if the element returned from hook_node_limit_element has 
 * '#custom_render' => true.
 * 
 * @param object $element
 *   The element.
 * @return string
 *   Rendered HTML.
 */
function hook_node_limit_render_element(&$element) {
  unset($element['submodule']['#title']);
  return drupal_render($element['submodule']);
}

/**
 * Save submodules' data.
 * 
 * Called when saving a node limit for each submodule individually.
 * 
 * @param int $lid
 *   The node limit id
 * @param bool $applies
 *   TRUE if this submodule have been chosen
 * @param mixed $element
 *   The form element value
 */
function hook_node_limit_save($lid, $applies, $element) {
  if ($applies) {
    // $element contains the username of the user
    // user_load based on the name to get the uid
    $user = user_load_by_name($element);

    db_insert('submodule')
      ->fields(array(
        'lid' => $lid,
        'uid' => $user->uid,
      ))
      ->execute();
  }
}

/**
 * Improve node limit count request.
 * 
 * Called when counting nodes to know if a limit has been reached.
 * 
 * @param int $lid
 *   The node limit id
 * @param SelectQuery $select
 *   The SQL select query
 */
function hook_node_limit_sql($lid, $select) {
  $limit = submodule_node_limit_load($lid);
  if (empty($limit)) return;
  
  $select->condition('uid', $limit['submodule']['uid']);
}