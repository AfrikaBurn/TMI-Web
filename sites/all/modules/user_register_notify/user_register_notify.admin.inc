<?php

/**
 * @file
 * Administrative page callbacks for the user_register_notify module.
 */

/**
 * Implements hook_admin_settings() for module settings configuration.
 */
function user_register_notify_admin_settings_form() {

  $form['general'] = array(
    '#collapsed' => FALSE,
    '#collapsible' => TRUE,
    '#title' => t('Account notifications'),
    '#type' => 'fieldset',
  );
  $form['general']['user_register_notify_type'] = array(
    '#default_value' => variable_get('user_register_notify_type', 'custom'),
    '#type' => 'radios',
    '#title' => t('Send to role or custom e-mail address?'),
    '#options' => array(
      'custom' => t('Send e-mail to custom e-mail address'),
      'role' => t('Send e-mail to specific role(s)'),
      'both' => t('Send e-mail to both custom e-mail address and specific role(s)'),
    ),
  );
  $form['general']['user_register_notify_mail_to'] = array(
    '#default_value' => variable_get('user_register_notify_mail_to', ''),
    '#description' => t("Comma separated list of e-mail addresses to be used as the 'to' address for all account notifications listed below. Leave empty to use the default system e-mail address <em>(%site-email).</em>", array('%site-email' => variable_get('site_mail', ini_get('sendmail_from')))),
    '#title' => t('Custom e-mail addresses'),
    '#type' => 'textfield',
    '#states' => array(
      'visible' => array(
        array(':input[name="user_register_notify_type"]' => array('value' => 'custom')),
        'or',
        array(':input[name="user_register_notify_type"]' => array('value' => 'both')),
      ),
    ),
  );
  $user_roles = array_map('check_plain', user_roles());
  $form['general']['user_register_notify_roles'] = array(
    '#default_value' => variable_get('user_register_notify_roles', array()),
    '#description' => t('All users with these checked roles will receive a notification e-mail when selected.'),
    '#options' => $user_roles,
    '#title' => t('Send e-mail to specific role(s)'),
    '#type' => 'checkboxes',
    '#states' => array(
      'visible' => array(
        array(':input[name="user_register_notify_type"]' => array('value' => 'role')),
        'or',
        array(':input[name="user_register_notify_type"]' => array('value' => 'both')),
      ),
    ),
  );

  $form['user_notify_email_addresses'] = array(
    '#type' => 'fieldset',
    '#title' => t('E-mail addresses'),
    '#description' => t("You should probably not set these unless you have specific requirements. In particular, modifying the 'from' address could result in e-mail being blocked as spam, and the response could impact on your server."),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['user_notify_email_addresses']['user_register_notify_mail_from'] = array(
    '#default_value' => variable_get('user_register_notify_mail_from', ''),
    '#description' => t("The e-mail address to be used as the 'from' address for all account notifications listed below. Leave empty to use the default system e-mail address <em>(%site-email).</em>", array('%site-email' => variable_get('site_mail', ini_get('sendmail_from')))),
    '#title' => t('From e-mail address'),
    '#type' => 'textfield',
  );
  $form['user_notify_email_addresses']['user_register_notify_mail_replyto'] = array(
    '#default_value' => variable_get('user_register_notify_mail_replyto', ''),
    '#description' => t("The e-mail address to be used as the 'reply-to' address for all account notifications listed below. Leave empty for not using 'reply-to' e-mail header. Configure this field only, if your 'reply-to' address is not your 'from' address."),
    '#title' => t('Reply-to e-mail address'),
    '#type' => 'textfield',
  );

  $form['email_title'] = array(
    '#type' => 'item',
    '#title' => t('E-mails'),
  );
  $form['email'] = array(
    '#type' => 'vertical_tabs',
  );

  $form['email_pending_approval_admin'] = array(
    '#type' => 'fieldset',
    '#title' => t('Admin (user awaiting approval)'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#description' => t('Edit the email notifying the site administrator that there are new members awaiting administrative approval. The list of available tokens that can be used in e-mails is provided below.') . ' ' . t('Note that this e-mail template is hidden from core account settings for unknown reasons.'),
    '#group' => 'email',
  );
  $form['email_pending_approval_admin']['user_mail_register_pending_approval_admin_subject'] = array(
    '#default_value' => variable_get('user_mail_register_pending_approval_admin_subject', t('Account details for [user:name] at [site:name] (pending admin approval)')),
    '#description' => t('Subject of user pending admin approval messages.'),
    '#required' => TRUE,
    '#title' => t('Subject'),
    '#type' => 'textfield',
  );
  $form['email_pending_approval_admin']['user_mail_register_pending_approval_admin_body'] = array(
    '#default_value' => variable_get('user_mail_register_pending_approval_admin_body', t("[user:name] has applied for an account.\n\n[user:edit-url]")),
    '#description' => t('Customize the body of the user pending admin approval notification e-mail.'),
    '#required' => TRUE,
    '#rows' => 10,
    '#title' => t('Body'),
    '#type' => 'textarea',
  );
  if (module_exists('token')) {
    $form['email_pending_approval_admin']['user_mail_register_pending_approval_admin_subject']['#element_validate'][] = 'token_element_validate';
    $form['email_pending_approval_admin']['user_mail_register_pending_approval_admin_subject']['#token_types'][] = 'user';
    $form['email_pending_approval_admin']['user_mail_register_pending_approval_admin_body']['#element_validate'][] = 'token_element_validate';
    $form['email_pending_approval_admin']['user_mail_register_pending_approval_admin_body']['#token_types'][] = 'user';
    $form['email_pending_approval_admin']['user_mail_register_pending_approval_token_tree'] = array(
      '#theme' => 'token_tree',
      '#token_types' => array('user'),
      '#show_restricted' => TRUE,
      '#dialog' => TRUE,
      '#weight' => 90,
    );
  };

  $form['user_register_notify_created'] = array(
    '#type' => 'fieldset',
    '#title' => t('Admin (account created)'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#description' => t('Edit the notification e-mail message sent to specific users or roles if a new user account was created.'),
    '#group' => 'email',
  );
  $form['user_register_notify_created']['user_register_notify_created_subject'] = array(
    '#default_value' => variable_get('user_register_notify_created_subject', t('Account details for [user:name] at [site:name]')),
    '#description' => t('Subject of user created messages.'),
    '#required' => TRUE,
    '#title' => t('Subject'),
    '#type' => 'textfield',
  );
  $form['user_register_notify_created']['user_register_notify_created_body'] = array(
    '#default_value' => variable_get('user_register_notify_created_body', t("User [user:name] ([user:url]) has created account.\n\nEdit user: [user:edit-url]\n\nDelete user: [user:cancel-url]")),
    '#description' => t('Customize the body of the user created notification e-mail.'),
    '#required' => TRUE,
    '#rows' => 10,
    '#title' => t('Body'),
    '#type' => 'textarea',
  );
  if (module_exists('token')) {
    $form['user_register_notify_created']['user_register_notify_created_subject']['#element_validate'][] = 'token_element_validate';
    $form['user_register_notify_created']['user_register_notify_created_subject']['#token_types'][] = 'user';
    $form['user_register_notify_created']['user_register_notify_created_body']['#element_validate'][] = 'token_element_validate';
    $form['user_register_notify_created']['user_register_notify_created_body']['#token_types'][] = 'user';
    $form['user_register_notify_created']['user_register_notify_created_token_tree'] = array(
      '#theme' => 'token_tree',
      '#token_types' => array('user'),
      '#show_restricted' => TRUE,
      '#dialog' => TRUE,
      '#weight' => 90,
    );
  };

  $form['user_register_notify_updated'] = array(
    '#type' => 'fieldset',
    '#title' => t('Admin (account updated)'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#description' => t('Edit the notification e-mail message sent to specific users or roles if a user account has been updated.'),
    '#group' => 'email',
  );
  $form['user_register_notify_updated']['user_register_notify_updated_subject'] = array(
    '#default_value' => variable_get('user_register_notify_updated_subject', t('Account details for [user:name] at [site:name]')),
    '#description' => t('Subject of user updated messages.'),
    '#required' => TRUE,
    '#title' => t('Subject'),
    '#type' => 'textfield',
  );
  $form['user_register_notify_updated']['user_register_notify_updated_body'] = array(
    '#default_value' => variable_get('user_register_notify_updated_body', t("User [user:name] ([user:url]) has updated account.\n\nEdit user: [user:edit-url]\n\nDelete user: [user:cancel-url]")),
    '#description' => t('Customize the body of the user updated notification e-mail.'),
    '#required' => TRUE,
    '#rows' => 10,
    '#title' => t('Body'),
    '#type' => 'textarea',
  );
  if (module_exists('token')) {
    $form['user_register_notify_updated']['user_register_notify_updated_subject']['#element_validate'][] = 'token_element_validate';
    $form['user_register_notify_updated']['user_register_notify_updated_subject']['#token_types'][] = 'user';
    $form['user_register_notify_updated']['user_register_notify_updated_body']['#element_validate'][] = 'token_element_validate';
    $form['user_register_notify_updated']['user_register_notify_updated_body']['#token_types'][] = 'user';
    $form['user_register_notify_updated']['user_register_notify_updated_token_tree'] = array(
      '#theme' => 'token_tree',
      '#token_types' => array('user'),
      '#show_restricted' => TRUE,
      '#dialog' => TRUE,
      '#weight' => 90,
    );
  };

  $form['user_register_notify_deleted'] = array(
    '#type' => 'fieldset',
    '#title' => t('Admin (account deleted)'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#description' => t('Edit the notification e-mail message sent to specific users or roles if a user account has been deleted.'),
    '#group' => 'email',
  );
  $form['user_register_notify_deleted']['user_register_notify_deleted_subject'] = array(
    '#default_value' => variable_get('user_register_notify_deleted_subject', t('Account details for [user:name] at [site:name]')),
    '#description' => t('Subject of user deleted messages.'),
    '#required' => TRUE,
    '#title' => t('Subject'),
    '#type' => 'textfield',
  );
  $form['user_register_notify_deleted']['user_register_notify_deleted_body'] = array(
    '#default_value' => variable_get('user_register_notify_deleted_body', t("User [user:name] ([user:url]) has deleted account.")),
    '#description' => t('Customize the body of the user deleted notification e-mail.'),
    '#required' => TRUE,
    '#rows' => 10,
    '#title' => t('Body'),
    '#type' => 'textarea',
  );
  if (module_exists('token')) {
    $form['user_register_notify_deleted']['user_register_notify_deleted_subject']['#element_validate'][] = 'token_element_validate';
    $form['user_register_notify_deleted']['user_register_notify_deleted_subject']['#token_types'][] = 'user';
    $form['user_register_notify_deleted']['user_register_notify_deleted_body']['#element_validate'][] = 'token_element_validate';
    $form['user_register_notify_deleted']['user_register_notify_deleted_body']['#token_types'][] = 'user';
    $form['user_register_notify_deleted']['user_register_notify_deleted_token_tree'] = array(
      '#theme' => 'token_tree',
      '#token_types' => array('user'),
      '#show_restricted' => TRUE,
      '#dialog' => TRUE,
      '#weight' => 90,
    );
  };

  $form['advanced'] = array(
    '#collapsed' => FALSE,
    '#collapsible' => TRUE,
    '#title' => t('Advanced settings'),
    '#type' => 'fieldset',
  );
  $form['advanced']['user_register_notify_alert'] = array(
    '#default_value' => variable_get('user_register_notify_alert', array('create' => 'create')),
    '#description' => t('When to send an e-mail.'),
    '#options' => array(
      'create' => t('Send e-mail upon account created.'),
      'update' => t('Send e-mail upon account updated.'),
      'delete' => t('Send e-mail upon account deleted.'),
    ),
    '#required' => FALSE,
    '#title' => t('Actions'),
    '#type' => 'checkboxes',
  );
  $user_register_notify_mail_messageid_default = drupal_map_assoc(array(
    'user_register_notify_admin_create',
    'user_register_notify_admin_delete',
    'user_register_notify_admin_update',
  ));
  $form['advanced']['user_register_notify_mail_messageid'] = array(
    '#default_value' => variable_get('user_register_notify_mail_messageid', $user_register_notify_mail_messageid_default),
    '#description' => t("The messages where 'from' and 'reply-to' settings should be used."),
    '#options' => array(
      'user_register_notify_admin_create' => t('Admin (account created)'),
      'user_register_notify_admin_update' => t('Admin (account updated)'),
      'user_register_notify_admin_delete' => t('Admin (account deleted)'),
      // Core - User module
      'user_register_admin_created' => t('Welcome (new user created by administrator)'),
      'user_register_no_approval_required' => t('Welcome (awaiting approval)'),
      // If a user registered requiring admin approval, notify the admin, too.
      'user_register_pending_approval_admin' => t('Admin (user awaiting approval)'),
      'user_register_pending_approval' => t('Welcome (no approval required)'),
      'user_status_activated' => t('Account activation'),
      'user_status_blocked' => t('Account blocked'),
      'user_cancel_confirm' => t('Account cancellation confirmation'),
      'user_status_canceled' => t('Account canceled'),
      'user_password_reset' => t('Password recovery'),
    ),
    '#title' => t('Messages affected'),
    '#type' => 'checkboxes',
  );

  return system_settings_form($form);
}

/**
 * Implements _form_validate().
 */
function user_register_notify_admin_settings_form_validate($form, &$form_state) {
  // Cleanup the e-mail string.
  $user_register_notify_mail_to = explode(',', $form_state['values']['user_register_notify_mail_to']);
  $user_register_notify_mail_to = array_map('trim', $user_register_notify_mail_to);
  $user_register_notify_mail_to = array_filter($user_register_notify_mail_to, 'strlen');
  $form_state['values']['user_register_notify_mail_to'] = implode(',', $user_register_notify_mail_to);

  // Remove useless 0's.
  $form_state['values']['user_register_notify_roles'] = array_filter($form_state['values']['user_register_notify_roles']);
  $form_state['values']['user_register_notify_alert'] = array_filter($form_state['values']['user_register_notify_alert']);

  foreach ($user_register_notify_mail_to as $email) {
    if (!valid_email_address($email)) {
      form_set_error('user_register_notify_mail_to', t('The e-mail address %mail is not valid.', array('%mail' => $email)));
    }
  }

  // Validate and cleanup the 'from' e-mail.
  $user_register_notify_mail_from = trim($form_state['values']['user_register_notify_mail_from']);
  if (!empty($user_register_notify_mail_from) && !valid_email_address($user_register_notify_mail_from)) {
    form_set_error('user_register_notify_mail_from', t('The e-mail address %mail is not valid.', array('%mail' => $user_register_notify_mail_from)));
  }
  $form_state['values']['user_register_notify_mail_from'] = $user_register_notify_mail_from;

  // Validate and cleanup the 'reply-to' e-mail.
  $user_register_notify_mail_replyto = trim($form_state['values']['user_register_notify_mail_replyto']);
  if (!empty($user_register_notify_mail_replyto) && !valid_email_address($user_register_notify_mail_replyto)) {
    form_set_error('user_register_notify_mail_replyto', t('The e-mail address %mail is not valid.', array('%mail' => $user_register_notify_mail_replyto)));
  }
  $form_state['values']['user_register_notify_mail_replyto'] = $user_register_notify_mail_replyto;
}
