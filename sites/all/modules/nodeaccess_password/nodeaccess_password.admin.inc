<?php

/**
 * @file
 * Node access password admin pages.
 */

/**
 * Menu callback. Draws the admin page.
 */
function nodeaccess_password_admin_form($form, &$form_state) {

  $realms = nodeaccess_password_get_realms();

  $form['realms'] = array(
    '#type' => 'fieldset',
    '#title' => t('Realms'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
    '#description' => '<p>' . t(
      "Node access password realms are collections of settings.  Realms allow "
      ."you to configure multiple instances of node access password's "
      ."settings, so you can affect nodes and users in multiple ways.  Nodes "
      ."affected by multiple realms will have one password for each realm, "
      ."allowing different types of users to access the same content using "
      ."different passwords.  You must create at least one realm."
    ) . '</p>',
  );

  if (!$realms) {
    $form['realms']['no_realms']['#markup'] = '<p>' . t(
      'There are no realms configured.  Please use the <em>add realm</em> button.'
    ) . '</p>';
  }
  else {
    $realm_rows = array();
    foreach ($realms as $realm) {
      $links = array(
        l(t('Edit'), 'admin/config/people/nodeaccess_password/' . $realm->id),
        l(t('Delete'), 'admin/config/people/nodeaccess_password/' . $realm->id . '/delete'),
      );
      $realm_rows[] = array(
        check_plain($realm->name),
        implode(' | ', $links),
      );
    }
    $form['realms']['table'] = array(
      '#theme' => 'table',
      '#header' => array(t('Realm'), t('Operations')),
      '#rows' => $realm_rows,
    );
  }

  $form['realms']['add_realm'] = array(
    '#type' => 'button',
    '#value' => t('Add realm'),
    '#submit' => array('nodeaccess_password_admin_form_add_realm'),
    '#executes_submit_callback' => TRUE,
  );

  // Allow to pick which category to put password field into.
  if (module_exists('profile')) {
    $result = db_query('SELECT DISTINCT(category) FROM {profile_field}');
    $categories = array();
    foreach ($result as $category) {
      $categories[$category->category] = $category->category;
    }
    if (
      !empty($categories) ||
      variable_get('nodeaccess_password_profile_category', 'account') != 'account'
    ) {
      $categories['account'] = 'account';
      $form['nodeaccess_password_profile_category'] = array(
        '#type' => 'select',
        '#title' => t('Password field user profile category'),
        '#default_value' => variable_get('nodeaccess_password_profile_category', 'account'),
        '#options' => $categories,
      );
    }
  }
  else {
    // Profile module not installed, ensure the default is set.
    variable_set('nodeaccess_password_profile_category', 'account');
  }

  return system_settings_form($form);
}

/**
 * Submit function when the 'add realm' button is hit.
 */
function nodeaccess_password_admin_form_add_realm($form, $form_state) {
  $realm = new StdClass;
  // Can't save an empty object.
  $realm->name = '';
  nodeaccess_password_realm_save($realm);
  
  // Updating realm with default name.
  $realm->name = 'Realm ' . $realm->id;
  nodeaccess_password_realm_save($realm);
  
  // Redirecting to editing of the created realm.
  drupal_set_message(t("A realm has been added, edit it below."));
  drupal_goto('admin/config/people/nodeaccess_password/' . $realm->id);
}

/**
 * Admin realm form.
 */
function nodeaccess_password_admin_realm_form($form, $form_state, $realm) {

  $form['#tree'] = TRUE;

  $form['nodeaccess_password_realm_id'] = array(
    '#type' => 'value',
    '#value' => $realm->id,
  );
  $form['nodeaccess_password_realm_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Realm name'),
    '#default_value' => !empty($realm->name) ? $realm->name : t('Realm') . ' ' . $realm->id,
    '#required' => TRUE,
  );

  $form['nodeaccess_password_realm'] = array(
    '#type' => 'fieldset',
    '#title' => t('Realm settings'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
  );
  $form['nodeaccess_password_realm']['access_denied'] = array(
    '#type' => 'checkbox',
    '#title' => t('Allow password input on the <em>access denied</em> page.'),
    '#default_value' => isset($realm->access_denied) ? $realm->access_denied : 1,
    '#description' => t("Node access password will handle the 403 <em>access denied</em> page."),
  );
  $form['nodeaccess_password_realm']['nodes'] = array(
    '#type' => 'fieldset',
    '#title' => t('Nodes'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
    '#description' => t('Which nodes will be affected by this realm.'),
  );
  $form['nodeaccess_password_realm']['nodes']['types'] = array(
    '#type' => 'select',
    '#title' => t('Node types'),
    '#default_value' => isset($realm->nodes['types']) ? $realm->nodes['types'] : array(),
    '#options' => nodeaccess_password_admin_node_types(),
    '#multiple' => TRUE,
    '#size' => 6,
  );
  if (module_exists('views')) {
    $form['nodeaccess_password_realm']['nodes']['views'] = array(
      '#type' => 'fieldset',
      '#title' => t('Views'),
      '#collapsible' => TRUE,
      '#collapsed' => !isset($realm->nodes['views']['view']) || $realm->nodes['views']['view'] == '',
      '#description' => t('If you choose a views display, it will override the node types setting above.'),
    );
    $form['nodeaccess_password_realm']['nodes']['views']['view'] = array(
      '#type' => 'select',
      '#title' => t('View'),
      '#default_value' => isset($realm->nodes['views']['view']) ? $realm->nodes['views']['view'] : '',
      '#options' => nodeaccess_password_admin_views_displays('node'),
    );
    $form['nodeaccess_password_realm']['nodes']['views']['view_args'] = array(
      '#type' => 'textfield',
      '#title' => t('View arguments'),
      '#default_value' => isset($realm->nodes['views']['view_args']) ? $realm->nodes['views']['view_args'] : '',
      '#description' => t('Provide a comma separated list of arguments to pass to the view.'),
    );
  }
  else {
    $form['nodeaccess_password_realm']['nodes']['views']['view'] = array(
      '#type' => 'value',
      '#value' => isset($realm->nodes['views']['view']) ? $realm->nodes['views']['view'] : '',
    );
    $form['nodeaccess_password_realm']['nodes']['views']['view_args'] = array(
      '#type' => 'value',
      '#value' => isset($realm->nodes['views']['view_args']) ? $realm->nodes['views']['view_args'] : '',
    );
  }
  $form['nodeaccess_password_realm']['roles'] = array(
    '#type' => 'select',
    '#title' => t('User roles'),
    '#default_value' => isset($realm->roles) ? $realm->roles : array(),
    '#options' => nodeaccess_password_admin_user_roles(),
    '#multiple' => TRUE,
    '#size' => 6,
    '#description' => t('Which users will be able to use the password.  Remember, new registrants will still be anonymous.'),
  );
  $form['nodeaccess_password_realm']['grants'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Password grants'),
    '#default_value' => isset($realm->grants) ? $realm->grants : array('view'),
    '#options' => array(
      'view' => t('Grant <em>view</em> access'),
      'update' => t('Grant <em>update</em> access'),
      'delete' => t('Grant <em>delete</em> access'),
    ),
    '#description' => t("These content access permissions will be granted to users that have a node's node access password for this realm."),
  );
  $form['nodeaccess_password_realm']['grants_published'] = array(
    '#type' => 'select',
    '#title' => t('Unpublished nodes'),
    '#title_display' => 'none',
    '#default_value' => isset($realm->grants_published) ? $realm->grants_published : 0,
    '#options' => array(
      0 => t('Give these grants for published nodes only'),
      1 => t('Give these grants for published and unpublished nodes'),
    ),
  );
  $form['nodeaccess_password_realm']['author'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Author grants'),
    '#default_value' => isset($realm->author) ? $realm->author : array('view', 'update', 'delete'),
    '#options' => array(
      'view' => t('Grant <em>view</em> access'),
      'update' => t('Grant <em>update</em> access'),
      'delete' => t('Grant <em>delete</em> access'),
    ),
    '#description' => t("These content access permissions will be granted to authors of nodes."),
  );
  $form['nodeaccess_password_realm']['author_published'] = array(
    '#type' => 'select',
    '#title' => t('Unpublished nodes'),
    '#title_display' => 'none',
    '#default_value' => isset($realm->author_published) ? $realm->author_published : 0,
    '#options' => array(
      0 => t('Give these grants for published nodes only'),
      1 => t('Give these grants for published and unpublished nodes'),
    ),
  );
  $form['nodeaccess_password_realm']['all'] = array(
    '#type' => 'checkboxes',
    '#title' => t('All user grants'),
    '#default_value' => isset($realm->all) ? $realm->all : array(),
    '#options' => array(
      'view' => t('Grant <em>view</em> access'),
    ),
    '#description' => t("These content access permissions will be granted to all users."),
  );
  $form['nodeaccess_password_realm']['all_published'] = array(
    '#type' => 'select',
    '#title' => t('Unpublished nodes'),
    '#title_display' => 'none',
    '#default_value' => isset($realm->all_published) ? $realm->all_published : 0,
    '#options' => array(
      0 => t('Give these grants for published nodes only'),
      1 => t('Give these grants for published and unpublished nodes'),
    ),
  );
  $form['nodeaccess_password_realm']['priority'] = array(
    '#type' => 'textfield',
    '#title' => t('Priority'),
    '#size' => 3,
    '#maxlength' => 9,
    '#default_value' => isset($realm->priority) && is_numeric($realm->priority) ? $realm->priority : 0,
    '#description' => t('It is recommended to always leave this set to 0.'),
  );

  $form['actions'] = array(
    '#type' => 'actions',
  );
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save realm'),
  );

  return $form;
}

/**
 * Submit function for admin realm form.
 */
function nodeaccess_password_admin_realm_form_submit($form, $form_state) {
  $realm = new StdClass;
  $realm->id = $form_state['values']['nodeaccess_password_realm_id'];
  $realm->name = $form_state['values']['nodeaccess_password_realm_name'];
  $realm->settings = $form_state['values']['nodeaccess_password_realm'];
  nodeaccess_password_realm_save($realm);
  drupal_set_message(t("Realm %name has been saved.", array("%name" => $realm->name)));
  module_load_include('inc', 'nodeaccess_password', 'nodeaccess_password.403');
  if (nodeaccess_password_403_check()) {
    nodeaccess_password_403_usurp();
  }
  else {
    nodeaccess_password_403_restore();
  }
  node_access_needs_rebuild(TRUE);
  drupal_goto('admin/config/people/nodeaccess_password');
}

/**
 * Admin realm delete form.
 */
function nodeaccess_password_admin_realm_delete($form, &$form_state, $realm) {
  $form['realm_id'] = array(
    '#type' => 'value',
    '#value' => $realm->id,
  );
  return confirm_form($form,
    t('Are you sure you want to delete the %title realm?', array('%title' => $realm->name)),
    isset($_GET['destination']) ? $_GET['destination'] : 'admin/config/people/nodeaccess_password',
    t('This action cannot be undone.'),
    t('Delete'), t('Cancel'));
}

/**
 * Submit function for admin realm delete form.
 */
function nodeaccess_password_admin_realm_delete_submit($form, &$form_state) {
  $id = &$form_state['values']['realm_id'];
  $realm = nodeaccess_password_realm_load($id);
  nodeaccess_password_realm_delete($id);
  drupal_set_message(t("Realm %name has been deleted.", array("%name" => $realm->name)));
  menu_rebuild();
  node_access_needs_rebuild(TRUE);
  drupal_goto('admin/config/people/nodeaccess_password');
}

/**
 * Get an array of content types for use in select forms.
 */
function nodeaccess_password_admin_node_types() {
  $types = node_type_get_types();
  $type_array = array();
  foreach ((array)$types as $type) {
    $type_array[$type->type] = $type->name;
  }
  if (count($type_array) == 1) {
    return FALSE;
  }
  return $type_array;
}

/**
 * Get an array of user roles for use in select forms.
 */
function nodeaccess_password_admin_user_roles() {
  $role_array = array();
  $role_array = user_roles();
  if (count($role_array) == 1) {
    return FALSE;
  }
  return $role_array;
}

/**
 * Get an array of node views for use in select forms.
 */
function nodeaccess_password_admin_views_displays($base_table) {
  $views = array('' => '<' . t('none') . '>');
  $all_views = views_get_all_views();

  foreach ($all_views as $view_name => $view) {
    // Only $base_table views that have fields will work for our purpose.
    if ($view->base_table == $base_table) {
      foreach ((array)$view->display as $display_key => $display) {
        $id = $view_name . ':' . $display_key;
        // Get display title.
       $display_title = nodeaccess_password_admin_views_display_title($view_name, $view, $display_key);
        // Append $id to the title for disambiguation in lists.
        $display_title .= ' ['. $id . ']';

        if ($view->type == 'Default') {
          $views[t('Default views')][$id] = $display_title;
        }
        else {
          $views[t('Existing views')][$id] = $display_title;
        }
      }
    }
  }
  return $views;
}

/**
 * Set the display title for a views display.
 */
function nodeaccess_password_admin_views_display_title($view_name, $view, $display_name) {
  $view->set_display($display_name);
  $display_title = $view->get_title();
  if (!$display_title) {
    // No title, we have to construct a title.
    $display_title = ucfirst($view_name) ." ". strtolower($view->display[$display_name]->display_title);
  }
  return $display_title;
}