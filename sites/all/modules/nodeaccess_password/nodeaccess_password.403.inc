<?php

/**
 * @file
 * Node access password 403 functionality.
 */

/**
 * Menu callback.  Draws the 403 page.
 */
function nodeaccess_password_403() {
  // Standard 403 handler.
  drupal_set_title(t('Access denied'));
  $return['standard_403_message'] = array(
    '#prefix' => '<p>',
    '#markup' => t('You are not authorized to access this page.'),
    '#suffix' => '</p>',
  );
  $base_path = base_path();
  $request_uri = request_uri();
  if (strpos($request_uri, $base_path) === 0) {
    $full_path = preg_replace("#$base_path#", '', $request_uri, 1);
    $full_path_parts = explode('?', $full_path);
    $path = &$full_path_parts[0];
    if (arg(0, $path) != 'node' || !is_numeric(arg(1, $path))) {
      $path = drupal_lookup_path('source', $path);
    }
    if (arg(0, $path) == 'node' && is_numeric(arg(1, $path))) {
      $nid = arg(1, $path);
      if (nodeaccess_password_403_show_form($nid)) {
        if (
          isset($_SESSION['nodeaccess_password_last_retry'][$nid])
          && REQUEST_TIME - $_SESSION['nodeaccess_password_last_retry'][$nid] > 900
        ) {
          unset($_SESSION['nodeaccess_password_retries'][$nid]);
          unset($_SESSION['nodeaccess_password_last_retry'][$nid]);
        }
        if (
          isset($_SESSION['nodeaccess_password_retries'][$nid]) &&
          $_SESSION['nodeaccess_password_retries'][$nid] >= 5
        ) {
          drupal_set_message(
            t('You have attempted too many retries on this page for now, please try again later.'),
            'error'
          );
        }
        else {
          $form = drupal_get_form('nodeaccess_password_403_form', $nid);
          $return = array_merge($return, $form);
        }
      }
    }
  }
  // Allow modules to change this page.
  drupal_alter('nodeaccess_password_403', $return);
  return $return;
}

/**
 * Password form for the 403 page.
 */
function nodeaccess_password_403_form($form, $form_state, $nid) {
  $form['nid'] = array(
    '#type' => 'value',
    '#value' => $nid,
  );
  $form['nodeaccess_password'] = array(
    '#type' => 'fieldset',
    '#title' => t('Password'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
  );
  $form['nodeaccess_password']['nodeaccess_password_intro'] = array(
    '#prefix' => '<p>',
    '#markup' => t('Do you have a password for this page?  Enter it here.'),
    '#suffix' => '</p>',
  );
  $form['nodeaccess_password']['nodeaccess_password'] = array(
    '#type' => 'textfield',
    '#title' => t('Password'),
    '#required' => TRUE,
  );
  $form['nodeaccess_password']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Retry'),
  );
  return $form;
}

/**
 * Submit function for password form for the 403 page.
 */
function nodeaccess_password_403_form_submit($form, &$form_state) {
  global $user;
  $password = strtolower(trim($form_state['values']['nodeaccess_password']));
  $nid = $form_state['values']['nid'];
  $node = node_load($nid);
  if (
    isset($node->nodeaccess_password) &&
    in_array($password, $node->nodeaccess_password)
  ) {
    if (isset($_SESSION['nodeaccess_password_retries'][$nid])) {
      unset($_SESSION['nodeaccess_password_retries'][$nid]);
    }
    if (isset($_SESSION['nodeaccess_password_last_retry'][$nid])) {
      unset($_SESSION['nodeaccess_password_last_retry'][$nid]);
    }
    drupal_set_message(
      t('You have been granted access to %node',
        array('%node' => $node->title)
      ),
      'success'
    );
    if ($user->uid) {
      // Authenticated
      $passwords = nodeaccess_password_user_get_passwords($user->uid);
      $passwords[] = $password;
      nodeaccess_password_user_set_passwords($user->uid, $passwords);
    }
    else {
      // Anonymous.
      $_SESSION['nodeaccess_password'][] = $password;
    }
  }
  else {
    drupal_set_message(t('The password you entered is incorrect.'), 'error');
    if (isset($_SESSION['nodeaccess_password_retries'][$nid])) {
      $_SESSION['nodeaccess_password_retries'][$nid]++;
      $_SESSION['nodeaccess_password_last_retry'][$nid] = REQUEST_TIME;
    }
    else {
      $_SESSION['nodeaccess_password_retries'][$nid] = 0;
    }
  }
}

/**
 * Determine whether a node falls into a realm that shows the 403 form.
 */
function nodeaccess_password_403_show_form($nid) {
  $realms = nodeaccess_password_get_realms();
  $result = db_query(
    "SELECT realm FROM {nodeaccess_password} WHERE nid = :nid",
    array(':nid' => $nid)
  );
  foreach ($result as $row) {
    $realm = $realms[$row->realm];
    if ($realm->access_denied) {
      return TRUE;
    }
  }
  return FALSE;
}

/**
 * Determine whether to usurp the 403 page.
 */
function nodeaccess_password_403_check() {
  $realms = nodeaccess_password_get_realms();
  foreach ($realms as &$realm) {
    if ($realm->access_denied) {
      return TRUE;
    }
  }
  return FALSE;
}

/**
 * Usurp the 403 page.
 */
function nodeaccess_password_403_usurp() {
  $current_403 = variable_get('site_403', '');
  if ($current_403 != 'nodeaccess_password_403') {
    variable_set('nodeaccess_password_old_403', $current_403);
    variable_set('site_403', 'nodeaccess_password_403');
  }
}

/**
 * Restore the 403 page.
 */
function nodeaccess_password_403_restore() {
  $current_403 = variable_get('site_403', '');
  if ($current_403 == 'nodeaccess_password_403') {
    $old_403 = variable_get('nodeaccess_password_old_403', '');
    variable_set('site_403', $old_403);
    variable_del('nodeaccess_password_old_403');
  }
}