<?php

/**
 * @file
 * Provides page callbacks for configuration page.
 */

/**
 * Callback function for add protected page.
 */
function protected_pages_configure($form, &$form_state) {

  $form['rules_list'] = array(
    '#title' => t("Add Protected Page Relative path and password."),
    '#type' => 'fieldset',
    '#prefix' => '<div id="rules_list">',
    '#suffix' => '</div>',
    '#description' => t('Please enter the relative path and its corresponding
    password. When user opens this url, they will asked to enter password to
    view this page. For example, "node/5", "new-events" etc.'),
  );
  $form['rules_list']['path'] = array(
    '#type' => 'textfield',
    '#title' => t('Relative Path'),
    '#description' => t('Enter relative drupal path. For example, "node/5", "new-events" etc.'),
    '#required' => TRUE,
  );
  $form['rules_list']['password'] = array(
    '#type' => 'password_confirm',
    '#size' => 25,
    '#required' => TRUE,
  );
  $form['rules_list']['submit'] = array(
    '#type' => 'submit',
    '#ajax' => array(
      'callback' => 'protected_pages_configure_submit_callback',
      'wrapper' => 'rules_list',
      'effect' => 'fade',
      'method' => 'replace',
      'progress' => array('type' => 'throbber', 'message' => t('Please wait. The data is being saved.')),
    ),
    '#value' => t('Save'),
  );

  $form['rules_list']['pages_table'] = array(
    '#markup' => protected_pages_get_pages_list(),
  );
  return $form;
}

/**
 * Callback to generate list of protected pages.
 */
function protected_pages_get_pages_list() {

  $header = array(
    array(
      'data' => t('#'),
      'width' => '10%',
    ),
    array(
      'data' => t('Relative Path'),
      'width' => '60%',
    ),
    array(
      'data' => t('Operations'),
      'colspan' => 3,
      'width' => '30%',
    ),
  );

  $rows = array();
  $query = db_select('protected_pages', 'pp')->extend('PagerDefault')->extend('TableSort');
  $query->fields('pp')
      ->limit(20)
      ->orderByHeader($header);

  $result = $query->execute();

  $rows = array();
  $count = 1;
  foreach ($result as $data) {
    $rows[] = array(
      'data' =>
      array(
        $count,
        $data->path,
        l(t('Edit'), "admin/config/system/protected_pages/" . $data->pid . "/edit"),
        l(t('Delete'), 'admin/config/system/protected_pages/' . $data->pid . "/delete"),
        l(t('Send E-mail'), 'admin/config/system/protected_pages/' . $data->pid . "/send_email"),
      ),
    );
    $count++;
  }

  $output = theme('table', array(
    'header' => $header,
    'rows' => $rows,
    "attributes" => array('width' => "500"),
    "sticky" => TRUE,
    "caption" => "",
    "colgroups" => array(),
    "empty" => t("No record found!"),
      )
  );

  $output .= theme('pager', array(
    'tags' => array(),
      )
  );

  return $output;
}

/**
 * Implements hook_validate().
 */
function protected_pages_configure_validate($form, &$form_state) {

  $form_state['normal_path'] = drupal_get_normal_path($form_state['values']['path']);
  $path_alias = drupal_strtolower(drupal_get_path_alias($form_state['values']['path']));
  if (!drupal_valid_path($form_state['normal_path'])) {
    form_set_error('path', t('Please enter a correct path!'));
  }

  $pid = db_select('protected_pages')
      ->fields('protected_pages', array('pid'))
      ->condition(db_or()->condition('path', $form_state['normal_path'])->condition('path', $path_alias))
      ->range(0, 1)
      ->execute()
      ->fetchField();
  if ($pid) {
    form_set_error('path', t('Duplicate path entry is not allowed. There is already a path or its alias exists.'));
  }
}

/**
 * Ajax submit callback for add protected page form.
 */
function protected_pages_configure_submit_callback($form, &$form_state) {

  $errors = form_get_errors();

  if (count($errors) < 1) {

    db_insert('protected_pages')->fields(array(
      'password' => sha1(trim(check_plain($form_state['values']['password']))),
      'path' => check_plain($form_state['values']['path']),
    ))->execute();

    drupal_set_message('The protected page settings has been successfully saved.');
    $form['rules_list']['pages_table']['#markup'] = protected_pages_get_pages_list();
    $form['rules_list']['path']['#value'] = '';
  }

  return $form['rules_list'];
}

/**
 * Callback function for edit protected page form.
 */
function protected_pages_edit($form, &$form_state, $pid) {
  $protected_page = db_select('protected_pages')
      ->fields('protected_pages', array('path'))
      ->condition('pid', $pid)
      ->execute()
      ->fetchObject();

  if (!isset($protected_page->path)) {
    drupal_access_denied();
    exit;
  }
  $form['rules_list'] = array(
    '#title' => t("Edit Protected Page Relative path and password."),
    '#type' => 'fieldset',
    '#prefix' => '<div id="rules_list">',
    '#suffix' => '</div>',
    '#description' => t('Please enter the relative path and its corresponding
    password. When user opens this url, they will assked to enter password to
    view this page. For example, "node/5", "new-events" etc.'),
  );
  $form['rules_list']['path'] = array(
    '#type' => 'textfield',
    '#title' => t('Relative Path'),
    '#description' => t('Enter relative drupal path. For example, "node/5", "new-events" etc.'),
    '#required' => TRUE,
    '#default_value' => $protected_page->path,
  );
  $form['rules_list']['password'] = array(
    '#type' => 'password_confirm',
    '#size' => 25,
  );
  $form['rules_list']['pid'] = array(
    '#type' => 'hidden',
    '#value' => $pid,
  );
  $form['rules_list']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );

  return $form;
}

/**
 * Implements hook_validate().
 */
function protected_pages_edit_validate($form, &$form_state) {
  $form_state['normal_path'] = drupal_get_normal_path($form_state['values']['path']);
  if (!drupal_valid_path($form_state['normal_path'])) {
    form_set_error('path', t('Please enter a correct path!'));
  }

  $pid = db_select('protected_pages')
      ->fields('protected_pages', array('pid'))
      ->condition(db_or()->condition('path', $form_state['normal_path'])->condition('path', $form_state['values']['path']))
      ->condition('pid', $form_state['values']['pid'], '<>')
      ->range(0, 1)
      ->execute()
      ->fetchField();
  if ($pid) {
    form_set_error('path', t('Duplicate path entry is not allowed. There is already a path or its alias exists.'));
  }
}

/**
 * Implements hook_submit().
 */
function protected_pages_edit_submit($form, &$form_state) {

  $values['path'] = check_plain($form_state['values']['path']);
  if (!empty($form_state['values']['password'])) {
    $values['password'] = sha1(trim(check_plain($form_state['values']['password'])));
  }
  db_update('protected_pages')
      ->fields($values)
      ->condition('pid', $form_state['values']['pid'])
      ->execute();
  drupal_set_message('The protected page settings has been successfully saved.');
  $form_state['redirect'] = 'admin/config/system/protected_pages';
}

/**
 * Callback function for delete protected page.
 */
function protected_pages_delete_confirm($form, &$form_state, $pid) {

  $path = db_select('protected_pages')
      ->fields('protected_pages', array('path'))
      ->condition('pid', $pid)
      ->range(0, 1)
      ->execute()
      ->fetchField();

  $form['pid'] = array('#type' => 'hidden', '#value' => $pid);
  return confirm_form($form, t('Are you sure you want to delete <b>"%path"</b> from protected pages list?', array('%path' => $path)), 'admin/config/system/protected_pages', t('This action cannot be undone.'), t('Delete'), t('Cancel')
  );
}

/**
 * Implements hook_submit().
 */
function protected_pages_delete_confirm_submit($form, &$form_state) {
  if ($form_state['values']['confirm']) {
    $pid = $form_state['values']['pid'];

    db_delete('protected_pages')
        ->condition('pid', $pid)
        ->execute();

    drupal_set_message(t('The path has been successfully deleted from protected pages.'));
    $form_state['redirect'] = 'admin/config/system/protected_pages';
  }
}

/**
 * Callback function for send protected pages details email form.
 */
function protected_pages_send_email($form, &$form_state, $pid) {
  $destination = drupal_get_destination();
  $form['send_email_box'] = array(
    '#type' => 'fieldset',
    '#title' => t('Send email'),
    '#description' => t('You send details of this protected page by email to multiple users. Please click !here to configure email settings.', array(
      '!here' => l(t('here'), 'admin/config/system/protected_pages/settings', array(
        'query' => $destination,
          )
      ),
        )
    ),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form_state['pid'] = $pid;

  $form['send_email_box']['recipents'] = array(
    '#type' => 'textarea',
    '#title' => t('Recipents'),
    '#rows' => 5,
    '#description' => t('Enter enter comma separated list of recipents.'),
    '#required' => TRUE,
  );
  $form['send_email_box']['subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Subject'),
    '#default_value' => variable_get('protected_pages_email_subject', protected_pages_email_subject()),
    '#description' => t('Enter subject of email.'),
    '#required' => TRUE,
  );
  $form['send_email_box']['body'] = array(
    '#type' => 'textarea',
    '#title' => t('Email Body'),
    '#rows' => 15,
    '#default_value' => variable_get('protected_pages_email_body', protected_pages_email_body()),
    '#description' => t('Enter the body of the email. Only [protected-page-url] and [site-name] tokens are available. 
      Since password is encrypted, therefore we can not provide it by token.'),
    '#required' => TRUE,
  );

  $form['send_email_box']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Send Email'),
  );

  return $form;
}

/**
 * Implements hook_validate().
 */
function protected_pages_send_email_validate($form, &$form_state) {
  $emails = explode(',', str_replace(array("\r", "\n"), ',', $form_state['values']['recipents']));
  foreach ($emails as $key => $email) {
    $email = trim($email);
    if ($email) {
      if (!valid_email_address($email)) {
        form_error($form['send_email_box']['recipents'], t('Invalid email address: @mail. Please correct this email.', array('@mail' => $email)));
        unset($emails[$key]);
      }
      else {
        $emails[$key] = $email;
      }
    }
    else {
      unset($emails[$key]);
    }
  }
  $form_state['validated_recipents'] = implode(', ', $emails);
}

/**
 * Implements hook_submit().
 */
function protected_pages_send_email_submit($form, &$form_state) {
  $path = db_select('protected_pages')
      ->fields('protected_pages', array('path'))
      ->condition('pid', $form_state['pid'])
      ->range(0, 1)
      ->execute()
      ->fetchField();

  $module = 'protected_pages';
  $key = 'protected_pages_details_mail';
  $to = $form_state['values']['recipents'];
  $from = variable_get('site_mail');
  $language = language_default();
  $send = TRUE;
  $params = array();
  $params['subject'] = $form_state['values']['subject'];
  $params['body'] = $form_state['values']['body'];
  $params['protected_page_url'] = url($path, array('absolute' => TRUE));

  drupal_mail($module, $key, $to, $language, $params, $from, $send);
  drupal_set_message(t('The email has been successfully sent.'));
  $form_state['redirect'] = 'admin/config/system/protected_pages';
}

/**
 * Callback function for protected pages settings.
 */
function protected_pages_settings() {
  $form['protected_pages_password_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Protected Pages Password Settings'),
    '#description' => t('Configure password related settings.'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $global_password_help_text = array();

  $global_password_help_text[] = t('Allow per page password = Only per page password will be accepted. Global password will not be accepted.');
  $global_password_help_text[] = t('Allow per page password or Global password = Per page  password and global password both will be accepted.');
  $global_password_help_text[] = t('Allow Only Global = Only global password will be accepted for each protected page.');

  $form['protected_pages_password_fieldset']['protected_pages_user_global_password'] = array(
    '#type' => 'select',
    '#title' => t('Global Password Setting'),
    '#default_value' => variable_get('protected_pages_user_global_password', 'per_page_or_global'),
    '#options' => array(
      'per_page_password' => t('Allow per page password'),
      'per_page_or_global' => t('Allow per page password or Global password'),
      'only_global' => t('Allow Only Global'),
    ),
    '#description' => t('Please select the appropriate option for protected pages handling.') .
    '<br />' . theme('item_list', array('items' => $global_password_help_text)),
  );

  $form['protected_pages_password_fieldset']['protected_pages_global_password_field'] = array(
    '#type' => 'password_confirm',
    '#title' => t('Global Password'),
    '#description' => t('The default password for all protected pages. This 
      password is necessary if you select the previous checkbox "Allow per page 
      password or Global password" or "Allow Only Global" options above.'),
  );
  $form['protected_pages_password_fieldset']['protected_pages_session_expire_time'] = array(
    '#type' => 'textfield',
    '#title' => t('Session Expire Time'),
    '#description' => t('When user enters password a session is created. 
      The node will be accessible until session expire. Once session expires, 
      user will need to enter password again. The default session expire time 
      is 0 (unlimited).'),
    '#default_value' => variable_get('protected_pages_session_expire_time', 0),
    '#required' => TRUE,
    '#size' => 10,
    '#element_validate' => array('protected_pages_validate_integer_positive'),
    '#field_suffix' => t('in minutes'),
  );

  $form['protected_pages_email_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Protected pages email settings'),
    '#description' => t('The following settings allows admin to send emails to multiple users about protected pages details to access protected pages.'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['protected_pages_email_fieldset']['protected_pages_email_subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Email subject'),
    '#default_value' => variable_get('protected_pages_email_subject', protected_pages_email_subject()),
    '#description' => t('Enter the subject of the email.'),
  );

  $form['protected_pages_email_fieldset']['protected_pages_email_body'] = array(
    '#type' => 'textarea',
    '#title' => t('Email content'),
    '#rows' => 15,
    '#default_value' => variable_get('protected_pages_email_body', protected_pages_email_body()),
    '#description' => t('Enter the body of the email. Only [protected-page-url] and [site-name] tokens are available. 
      Since password is encrypted, therefore we can not provide it by token.'),
  );

  $form['protected_pages_other_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Protected Pages Other Settings'),
    '#description' => t('Configure other settings.'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['protected_pages_other_fieldset']['protected_pages_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Password page title'),
    '#default_value' => variable_get('protected_pages_title', t('Protected Page -- Enter password')),
    '#description' => t('Enter the title of the protected page.'),
  );

  $form['protected_pages_other_fieldset']['protected_pages_description'] = array(
    '#type' => 'textarea',
    '#title' => t('Password page description (inside the field set)'),
    '#default_value' => variable_get('protected_pages_description', t('The page you are trying to view is password protected. Please enter the password below to proceed.')),
    '#description' => t('Enter specific description for the protected page. This description is displayed inside the fieldset. HTML is accepted.'),
  );

  $form['protected_pages_other_fieldset']['protected_pages_password_label'] = array(
    '#type' => 'textfield',
    '#title' => t('Password field label'),
    '#default_value' => variable_get('protected_pages_password_label', t('Enter Password')),
    '#description' => t('Enter the text for the password field label.'),
  );
  $form['protected_pages_other_fieldset']['protected_pages_submit_button_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Submit Button Text'),
    '#default_value' => variable_get('protected_pages_submit_button_text', t('Authenticate')),
    '#description' => t('Enter the text for the submit button of enter password form.'),
  );
  $form['protected_pages_other_fieldset']['protected_pages_incorrect_password_msg'] = array(
    '#type' => 'textarea',
    '#title' => t('Incorrect Password Error Text'),
    '#default_value' => variable_get('protected_pages_incorrect_password_msg', t('Incorrect password!')),
    '#description' => t('This error text will appear if someone enters wrong password in "Enter password screen".'),
  );
  $form['#submit'][] = '_protected_pages_settings_submit';
  return system_settings_form($form);
}

/**
 * Callback function to validate session expire time value.
 */
function protected_pages_validate_integer_positive($element, &$form_state) {
  $value = $element['#value'];
  if ($value !== '' && (!is_numeric($value) || intval($value) != $value || $value < 0)) {
    form_error($element, t('%name must be a positive integer.', array('%name' => $element['#title'])));
  }
}

/**
 * Custom submit function encrypt password and deleting non-useful variable. 
 */
function _protected_pages_settings_submit($form, &$form_state) {
  $passwd = $form_state['values']['protected_pages_global_password_field'];
  if ($passwd) {
    variable_set('protected_pages_global_password', sha1($passwd));
    unset($form_state['values']['protected_pages_global_password_field']);
    variable_del('protected_pages_global_password_field');
  }
}
