<?php

/**
 * @file
 * Simple Mail admin forms.
 */

/**
 * Simple Mail configuration form.
 */
function simple_mail_admin_form($form, &$form_state) {
  $form['simple_mail_override'] = array(
    '#type' => 'textfield',
    '#title' => t('E-mail override address'),
    '#description' => t('Enter an e-mail address to have all system emails redirected to it. If empty, e-mail will be delivered normally, to the intended recipient.'),
    '#default_value' => variable_get('simple_mail_override', ''),
  );

  return system_settings_form($form);
}

/**
 * Simple Mail configuration form validate callback.
 */
function simple_mail_admin_form_validate($form, &$form_state) {
  $mail = $form_state['values']['simple_mail_override'];
  if (($mail !== '') && !valid_email_address($mail)) {
    form_set_error('simple_mail_override', t('Please enter a valid email address.'));
  }
}
