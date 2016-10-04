<?php
/**
 * @file
 * An administration page which allows for sending a test e-mail.
 */

/**
 * Form builder; the messages form.
 *
 * @see swiftmailer_admin_test_form_submit()
 */
function swiftmailer_admin_test_form($form, &$form_state) {

  // Include helper functions.
  require_once(dirname(dirname(__FILE__)) . '/helpers/utilities.inc');

  $form['#tree'] = TRUE;

  $form['description'] = array(
    '#markup' => '<p>' . t('This page allows you to send a test e-mail to a recipient of your choice.') . '</p>',
  );

  if (swiftmailer_validate_library(variable_get('swiftmailer_path', SWIFTMAILER_VARIABLE_PATH_DEFAULT))) {

    $form['test'] = array(
      '#type' => 'fieldset',
      '#title' => t('Recipient'),
      '#description' => '<p>' . t('You can send a test e-mail to a recipient of your choice. The e-mail will be sent using the default values as provided by the Swift Mailer module or as configured by you.') . '</p>',
    );

    global $user;

    $form['test']['recipient'] = array(
      '#title' => t('E-mail'),
      '#type' => 'textfield',
      '#default_value' => $user->mail,
    );

    $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Send'),
    );

  }
  else {

    $form['message'] = array(
      '#markup' => '<p>' . t('You need to configure the location of the Swift Mailer library. Please visit the !page
        and configure the library to enable the configuration options on this page.',
      array('!page' => l(t('library configuration page'), 'admin/config/people/swiftmailer'))) . '</p>',
    );

  }

  return $form;
}

/**
 * Submit handler for swiftmailer_admin_test_form.
 */
function swiftmailer_admin_test_form_submit($form, &$form_state) {

  if (isset($form_state['values']['test']['recipient'])) {
    drupal_mail('swiftmailer', 'test', $form_state['values']['test']['recipient'], language_default());
    drupal_set_message(t('An attempt has been made to send an e-mail to @email.', array('@email' => $form_state['values']['test']['recipient'])));
  }

}
