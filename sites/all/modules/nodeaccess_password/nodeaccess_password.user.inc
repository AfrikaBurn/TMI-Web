<?php

/**
 * @file
 * Node access password integration with the user module.
 */

/**
 * Implements hook_form_FORM_ID_alter().
 */
function nodeaccess_password_form_user_profile_form_alter(&$form, &$form_state, $form_id, $account, $category = 'account') {
  if ($category == variable_get('nodeaccess_password_profile_category', 'account')) {
    nodeaccess_password_user_form($form, $form_state, $form_id);
  }
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function nodeaccess_password_form_user_register_form_alter(&$form, &$form_state, $form_id) {
  nodeaccess_password_user_form($form, $form_state, $form_id);
}

/**
 * Handles alters of user forms.
 */
function nodeaccess_password_user_form(&$form, &$form_state, $form_id) {
  if ($account = &$form_state['user']) {
    $passwords = nodeaccess_password_user_get_passwords($account->uid);
    $form['nodeaccess_password'] = array(
      '#type' => 'textarea',
      '#title' => t('Node access passwords'),
      '#default_value' => !empty($passwords) ? implode("\n", $passwords) : '',
      '#description' => t('Enter one password per line.'),
      '#rows' => 1,
    );
    $form['#validate'][] = 'nodeaccess_password_user_form_validate';
  }
}

/**
 * Handles validation of user forms.
 */
function nodeaccess_password_user_form_validate(&$form, &$form_state) {
  $edit = &$form_state['values'];
  if (!empty($edit['nodeaccess_password'])) {
    $passwords = explode("\n", $edit['nodeaccess_password']);
    foreach ($passwords as $password) {
      if (trim($password)) {
        $result = db_query('SELECT nid FROM {nodeaccess_password} WHERE LOWER(:password) = LOWER(password)', array(':password' => trim($password)))->fetchField();
        if ($result === FALSE) {
          form_set_error('nodeaccess_password', t('%password is not a valid value for !field', array('%password' => $password, '!field' => t("Node access passwords"))));
        }
      }
    }
  }
}

/**
 * Implements hook_user_delete().
 */
function nodeaccess_password_user_delete($account) {
  db_delete('nodeaccess_password_users')
    ->condition('uid', $account->uid)
    ->execute();
}

/**
 * Implements hook_user_insert().
 */
function nodeaccess_password_user_insert(&$edit, $account, $category) {
  nodeaccess_password_user_account_save($edit, $account, $category);
}

/**
 * Implements hook_user_update().
 */
function nodeaccess_password_user_update(&$edit, $account, $category) {
  nodeaccess_password_user_account_save($edit, $account, $category);
}

/**
 * Handles saving of user accounts.
 */
function nodeaccess_password_user_account_save(&$edit, $account, $category) {
  if (isset($edit['nodeaccess_password'])) {
    $nodeaccess_passwords = explode("\n", $edit['nodeaccess_password']);
    foreach ($nodeaccess_passwords as $password) {
      $passwords[] = $password;
    }
    nodeaccess_password_user_set_passwords($account->uid, $passwords);
    unset($edit['nodeaccess_password']);
  }
  $nodes_by_realm = nodeaccess_password_user_get_nodes($account);
  foreach ($nodes_by_realm as $realm_name => $nodes) {
    foreach ($nodes as $nid) {
      $loaded_node = node_load($nid, NULL, TRUE);
      // To preserve database integrity, only acquire grants if the node
      // loads successfully.
      if (!empty($loaded_node)) {
        db_delete('node_access')
          ->condition('nid', $loaded_node->nid)
          ->execute();
        node_access_acquire_grants($loaded_node);
      }
    }
  }
}

/**
 * Set passwords for a user.
 */
function nodeaccess_password_user_set_passwords($uid, $passwords = array()) {
  db_delete('nodeaccess_password_users')
    ->condition('uid', $uid)
    ->execute();
  $passwords = array_unique($passwords);
  foreach ($passwords as $password) {
    db_insert('nodeaccess_password_users')
      ->fields(array(
        'uid' => $uid,
        'password' => strtolower(trim($password)),
      ))
      ->execute();
  }
}

/**
 * Get passwords for a user.
 */
function nodeaccess_password_user_get_passwords($uid) {
  $passwords = array();
  if ($uid) {
    // Authenticated user, get their data from the database.
    $result = db_query('SELECT password FROM {nodeaccess_password_users} WHERE uid = :uid', array(':uid' => $uid));
    foreach ($result as $row) {
      $passwords[] = $row->password;
    }
  }
  elseif (isset($_SESSION['nodeaccess_password'])) {
    // Anonymous user, get their data from the session.
    $passwords = $_SESSION['nodeaccess_password'];
  }
  return $passwords;
}

/**
 * Get an array of nodes that are accessible by a certain user
 *
 * @todo: This could be more efficient by using joins, instead of
 *   nodeaccess_password_user_get_passwords().
 */
function nodeaccess_password_user_get_nodes($account, $realm_prefix = NULL) {
  $passwords = nodeaccess_password_user_get_passwords($account->uid);
  $nodes = array();
  if (!empty($passwords)) {
    $args = array();
    $sql = 'SELECT nid, realm FROM {nodeaccess_password} WHERE password IN (:passwords)';
    $args[':passwords'] = $passwords;
    $result = db_query($sql, $args);
    foreach ($result as $row) {
      $index = is_null($realm_prefix) ? $row->realm : $realm_prefix . $row->realm;
      $nodes[$index][] = $row->nid;
    }
  }
  return $nodes;
}
