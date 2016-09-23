<?php
/**
 * @file
 */

/**
 * Callback that loads the search filters and results.
 */
function profile_field_search_page() {
  $build['form'] = drupal_get_form('profile_field_search_form');
  $build['result'] = array('#markup' => profile_field_search_results());
  return $build;
}

/**
 * Form builder; Return content profile search form.
 */
function profile_field_search_form() {
  $session = &$_SESSION['profile_field_search_filter'];
  $session = is_array($session) ? $session : array();

  // Create a list of field names and labels the current user may access, which
  // we can feed into the form as an option list.
  $fields = _profile_field_search_fields();
  $options = _profile_field_search_fields_options($fields, TRUE);

  $form['search'] = array(
    '#type' => 'fieldset',
  );

  $form['search']['string'] = array(
    '#type' => 'textfield',
    '#title' => 'Search',
    '#description' => t("Enter arbitrary text to search for in all checked Content Profile fields and the user's username and email address."),
    '#default_value' => isset($session['string']) ? $session['string'] : '',
  );

  $form['search']['filters'] = array(
    '#type' => 'fieldset',
    '#title' => 'Filters',
    '#description' => '',
    '#collapsible' => TRUE,
    '#collapsed' => (variable_get('profile_field_search_filter_collapse', 0) == 1) ? TRUE : FALSE,
  );

  $form['search']['filters']['fields'] = array(
    '#type' => 'checkboxes',
    '#title' => 'Search fields',
    '#description' => t('Check all the fields that you wish to search. The login name and email address fields are always searched.'),
    '#options' => $options,
    '#default_value' => isset($session['fields']) ? $session['fields'] : variable_get('profile_field_search_default_fields', array()),
  );

  // Do not display the roles filter if there are no roles to filter by.
  $roles = _profile_field_search_roles();
  if (!empty($roles)) {
    $form['search']['filters']['roles'] = array(
      '#type' => 'checkboxes',
      '#title' => 'User roles',
      '#description' => t('Check any roles you wish to limit results by.'),
      '#options' => $roles,
      '#default_value' => isset($session['roles']) ? $session['roles'] : variable_get('profile_field_search_default_roles', array()),
    );
  }

  $form['search']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('List Users'),
  );

  return $form;
}

/**
 * Process results of the content_profile_search filter form.
 */
function profile_field_search_form_submit($form, &$form_state) {
  $_SESSION['profile_field_search_filter'] = $form_state['values'];
  $form_state['redirect'] = 'admin/people/profile-field-search';
}

/**
 * Perform the search.
 */
function profile_field_search_results() {
  $entity_type = variable_get('profile_field_search_entity', PROFILE_FIELD_SEARCH_CORE);
  $result = profile_field_search_build_query();

  if (empty($result[$entity_type])) {
    return t('No users found.');
  }

  $entities = entity_load($entity_type, array_keys($result[$entity_type]));

  $filter = $_SESSION['profile_field_search_filter'];
  $fields = array_intersect_key(_profile_field_search_fields(), array_filter($filter['fields']));

  $header = array(
    'uid'  => t('Uid'),
    'name' => t('Name'),
    'mail' => t('Mail'),
  );
  foreach ($fields as $field) {
    $header[$field['field_name']] = $field['label'];
  }

  $rows = array();
  foreach ($entities as $entity) {
    if ($entity_type != PROFILE_FIELD_SEARCH_CORE) {
      $account = user_load($entity->uid);
    }
    else {
      $account = $entity;
    }
    $row['uid'] = (user_access('administer users')) ? l($account->uid, 'user/' . $account->uid .' /edit') : $account->uid;
    $row['name'] = theme('username', array('account' => $account));
    $row['mail'] = $account->mail;
    foreach ($fields as $field) {
      // Set a default and skip to next if this field has no items.
      $row[$field['field_name']] = '';
      $items = field_view_field($entity_type, $entity, $field['field_name'], array());
      if (empty($items['#items'])) {
        continue;
      }

      // Create an array of rendered values for this field.
      $values = array();
      $items = field_get_items($entity_type, $entity, $field['field_name']);
      foreach ($items as $item) {
        // Use a temp var to keep drupal_render() happy.
        $value = field_view_value($entity_type, $entity, $field['field_name'], $item);
        $values[] = drupal_render($value);
      }
      $row[$field['field_name']] = implode(', ', $values);
    }
    $rows[] = $row;
  }
  return theme('table', array('header' => $header, 'rows' => $rows));
}
