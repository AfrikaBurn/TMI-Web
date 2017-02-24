<?php
/**
 * @file
 * An administration page which allows for configuration of transport types.
 */

/**
 * Form builder; the transport form.
 *
 * @see swiftmailer_admin_transport_form_ajax()
 * @see swiftmailer_admin_transport_form_update()
 * @see swiftmailer_admin_transport_form_submit()
 */
function swiftmailer_admin_transport_form($form, &$form_state) {

  // Include helper functions.
  require_once(dirname(dirname(__FILE__)) . '/helpers/utilities.inc');

  // The configuration options for the selected transport type should be
  // displayed using AJAX if JavaScript is enabled. However, we need to
  // disable the 'Configure' button if JavaScript is enabled as the button
  // only is needed when JavaScript is disabled.
  drupal_add_js('jQuery(document).ready(function() { jQuery("#transport_configuration_submit").hide(); })',
    array('type' => 'inline', 'scope' => 'header'));

  // Submitted form values should be nested.
  $form['#tree'] = TRUE;

  // Display a page description.
  $form['description'] = array(
    '#markup' => '<p>' . t('This page allows you to configure settings which determines how e-mail messages are sent.') . '</p>',
  );

  // Validate that the Swift Mailer library is available. Configuration options
  // should only be displayed if the library is available.
  if (swiftmailer_validate_library(variable_get('swiftmailer_path', SWIFTMAILER_VARIABLE_PATH_DEFAULT))) {

    $form['transport'] = array(
      '#id' => 'transport',
      '#type' => 'fieldset',
      '#title' => t('Transport types'),
      '#description' => t('Which transport type should Drupal use to send e-mails?'),
    );

    // Display the currently configured transport type, or alternatively the
    // currently selected transport type if the user has chosen to configure
    // another transport type.
    $transport = variable_get('swiftmailer_transport', SWIFTMAILER_TRANSPORT_NATIVE);
    $transport = (isset($form_state['values']['transport']['type'])) ? $form_state['values']['transport']['type'] : $transport;

    $form['transport']['type'] = array(
      '#type' => 'radios',
      '#options' => array(
        SWIFTMAILER_TRANSPORT_SMTP => t('SMTP'),
        SWIFTMAILER_TRANSPORT_SENDMAIL => t('Sendmail'),
        SWIFTMAILER_TRANSPORT_NATIVE => t('PHP'),
        SWIFTMAILER_TRANSPORT_SPOOL => t('Spool')
      ),
      '#default_value' => $transport,
      '#ajax' => array(
        'callback' => 'swiftmailer_admin_transport_form_ajax',
        'wrapper' => 'transport_configuration',
        'method' => 'replace',
        'effect' => 'fade',
      ),
      '#description' => t('Not sure which transport type to choose? The !documentation gives you a good overview of the various transport types.', array('!documentation' => l(t('Swift Mailer documentation'), 'http://swiftmailer.org/docs/sending.html#transport-types'))),
    );

    $form['transport']['submit'] = array(
      '#type' => 'submit',
      '#id' => 'transport_configuration_submit',
      '#value' => t('Configure'),
      '#submit' => array('swiftmailer_admin_transport_form_update'),
      '#limit_validation_errors' => array(array('transport', 'type')),
    );

    $form['transport']['configuration'] = array(
      '#type' => 'item',
      '#id' => 'transport_configuration',
    );

    $form['transport']['configuration'][SWIFTMAILER_TRANSPORT_SMTP] = array(
      '#type' => 'item',
      '#access' => $form['transport']['type']['#default_value'] == SWIFTMAILER_TRANSPORT_SMTP,
    );

    $form['transport']['configuration'][SWIFTMAILER_TRANSPORT_SMTP]['title'] = array(
      '#markup' => '<h3>' . t('SMTP transport options') . '</h3>',
    );

    $form['transport']['configuration'][SWIFTMAILER_TRANSPORT_SMTP]['description'] = array(
      '#markup' => '<p>' . t('This transport type will send all e-mails using a SMTP
        server of your choice. You need to specify which SMTP server
        to use. Please refer to the !documentation for more details
        about this transport type.',
      array('!documentation' => l(t('Swift Mailer documentation'), 'http://swiftmailer.org/docs/sending.html#the-smtp-transport'))) . '</p>',
    );

    $form['transport']['configuration'][SWIFTMAILER_TRANSPORT_SMTP]['server'] = array(
      '#type' => 'textfield',
      '#title' => t('SMTP server'),
      '#description' => t('The hostname or IP address at which the SMTP server can be reached.'),
      '#required' => TRUE,
      '#default_value' => variable_get('swiftmailer_smtp_host', SWIFTMAILER_VARIABLE_SMTP_HOST_DEFAULT),
    );

    $form['transport']['configuration'][SWIFTMAILER_TRANSPORT_SMTP]['port'] = array(
      '#type' => 'textfield',
      '#title' => t('Port'),
      '#description' => t('The port at which the SMTP server can be reached (defaults to 25)'),
      '#default_value' => variable_get('swiftmailer_smtp_port', SWIFTMAILER_VARIABLE_SMTP_PORT_DEFAULT),
      '#size' => 10,
    );

    $form['transport']['configuration'][SWIFTMAILER_TRANSPORT_SMTP]['encryption'] = array(
      '#type' => 'select',
      '#title' => t('Encryption'),
      '#options' => swiftmailer_get_encryption_options(),
      '#description' => t('The type of encryption which should be used (if any)'),
      '#default_value' => variable_get('swiftmailer_smtp_encryption', SWIFTMAILER_VARIABLE_SMTP_ENCRYPTION_DEFAULT),
    );

    $form['transport']['configuration'][SWIFTMAILER_TRANSPORT_SMTP]['username'] = array(
      '#type' => 'textfield',
      '#title' => t('Username'),
      '#description' => t('A username required by the SMTP server (leave blank if not required)'),
      '#default_value' => variable_get('swiftmailer_smtp_username', SWIFTMAILER_VARIABLE_SMTP_USERNAME_DEFAULT),
    );

    $form['transport']['configuration'][SWIFTMAILER_TRANSPORT_SMTP]['password'] = array(
      '#type' => 'password',
      '#title' => t('Password'),
      '#description' => t('A password required by the SMTP server (leave blank if not required)'),
      '#default_value' => variable_get('swiftmailer_smtp_password', SWIFTMAILER_VARIABLE_SMTP_PASSWORD_DEFAULT),
    );

    $current_password = variable_get('swiftmailer_smtp_password');
    if (!empty($current_password)) {
      $form['transport']['configuration'][SWIFTMAILER_TRANSPORT_SMTP]['password']['#description'] = t('A password
        required by the SMTP server. <em>The currently set password is hidden for security reasons</em>.');
    }

    $form['transport']['configuration'][SWIFTMAILER_TRANSPORT_SENDMAIL] = array(
      '#type' => 'item',
      '#access' => $form['transport']['type']['#default_value'] == SWIFTMAILER_TRANSPORT_SENDMAIL,
    );

    $form['transport']['configuration'][SWIFTMAILER_TRANSPORT_SENDMAIL]['title'] = array(
      '#markup' => '<h3>' . t('Sendmail transport options') . '</h3>',
    );

    $form['transport']['configuration'][SWIFTMAILER_TRANSPORT_SENDMAIL]['description'] = array(
      '#markup' => '<p>' . t('This transport type will send all e-mails using a locally
        installed MTA such as Sendmail. You need to specify which
        locally installed MTA to use by providing a path to the
        MTA. If you do not provide any path then Swift Mailer
        defaults to /usr/sbin/sendmail. You can read more about
        this transport type in the !documentation.',
        array('!documentation' => l(t('Swift Mailer documentation'), 'http://swiftmailer.org/docs/sending.html#the-sendmail-transport'))) . '</p>',
    );

    $form['transport']['configuration'][SWIFTMAILER_TRANSPORT_SENDMAIL]['path'] = array(
      '#type' => 'textfield',
      '#title' => t('MTA path'),
      '#description' => t('The absolute path to the locally installed MTA.'),
      '#default_value' => variable_get('swiftmailer_sendmail_path', SWIFTMAILER_VARIABLE_SENDMAIL_PATH_DEFAULT),
    );

    $form['transport']['configuration'][SWIFTMAILER_TRANSPORT_SENDMAIL]['mode'] = array(
      '#type' => 'radios',
      '#title' => t('Mode'),
      '#options' => array('bs' => 'bs', 't' => 't '),
      '#description' => t('Not sure which option to choose? Go with <em>bs</em>. You can read more about the above two modes in the !documentation.', array('!documentation' => l(t('Swift Mailer documentation'), 'http://swiftmailer.org/docs/sendmail-transport'))),
      '#default_value' => variable_get('swiftmailer_sendmail_mode', SWIFTMAILER_VARIABLE_SENDMAIL_MODE_DEFAULT),
    );

    $form['transport']['configuration'][SWIFTMAILER_TRANSPORT_NATIVE] = array(
      '#type' => 'item',
      '#access' => $form['transport']['type']['#default_value'] == SWIFTMAILER_TRANSPORT_NATIVE,
    );

    $form['transport']['configuration'][SWIFTMAILER_TRANSPORT_NATIVE]['title'] = array(
      '#markup' => '<h3>' . t('PHP transport options') . '</h3>',
    );

    $form['transport']['configuration'][SWIFTMAILER_TRANSPORT_NATIVE]['description'] = array(
      '#markup' => '<p>' . t('This transport type will send all e-mails using the built-in
        mail functionality of PHP. This transport type can not be
        configured here. Please refer to the !documentation if you
        would like to read more about how the built-in mail functionality
        in PHP can be configured.',
        array('!documentation' => l(t('PHP documentation'), 'http://www.php.net/manual/en/mail.configuration.php'))) . '</p>',
    );

    $form['transport']['configuration'][SWIFTMAILER_TRANSPORT_SPOOL] = array(
      '#type' => 'item',
      '#access' => $form['transport']['type']['#default_value'] == SWIFTMAILER_TRANSPORT_SPOOL,
    );

    $form['transport']['configuration'][SWIFTMAILER_TRANSPORT_SPOOL]['title'] = array(
      '#markup' => '<h3>' . t('Spool transport options') . '</h3>',
    );

    $form['transport']['configuration'][SWIFTMAILER_TRANSPORT_SPOOL]['description'] = array(
      '#markup' => '<p>' . t('This transport does not attempt to send the email
      but instead saves the message to a spool file. Another process can then
      read from the spool and take care of sending the emails.') . '</p>',
    );

    $form['transport']['configuration'][SWIFTMAILER_TRANSPORT_SPOOL]['directory'] = array(
      '#type' => 'textfield',
      '#title' => t('Spool directory'),
      '#description' => t('The absolute path to the spool directory.'),
      '#default_value' => variable_get('swiftmailer_spool_directory', SWIFTMAILER_VARIABLE_SPOOL_DIRECTORY_DEFAULT),
    );

    $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Save'),
    );

  }
  else {

    $form['message'] = array(
      '#markup' => t('<p>You need to configure the location of the Swift Mailer library. Please visit the !page
        and configure the library to enable the configuration options on this page.</p>',
        array('!page' => l(t('library configuration page'), 'admin/config/people/swiftmailer'))),
    );

  }

  return $form;
}

/**
 * Partial form submission handler for swiftmailer_admin_transport_form().
 */
function swiftmailer_admin_transport_form_ajax($form, &$form_state) {
  return $form['transport']['configuration'];
}

/**
 * Partial form submission handler for swiftmailer_admin_transport_form().
 */
function swiftmailer_admin_transport_form_update($form, &$form_state) {
  $form_state['rebuild'] = TRUE;
}

/**
 * Form submission handler for swiftmailer_admin_transport_form().
 */
function swiftmailer_admin_transport_form_submit($form, &$form_state) {

  if (isset($form_state['values']['transport']['type'])) {
    variable_set('swiftmailer_transport', $form_state['values']['transport']['type']);

    switch ($form_state['values']['transport']['type']) {
      case SWIFTMAILER_TRANSPORT_SMTP:
        variable_set('swiftmailer_smtp_host', $form_state['values']['transport']['configuration'][SWIFTMAILER_TRANSPORT_SMTP]['server']);
        variable_set('swiftmailer_smtp_port', $form_state['values']['transport']['configuration'][SWIFTMAILER_TRANSPORT_SMTP]['port']);
        variable_set('swiftmailer_smtp_encryption', $form_state['values']['transport']['configuration'][SWIFTMAILER_TRANSPORT_SMTP]['encryption']);
        variable_set('swiftmailer_smtp_username', $form_state['values']['transport']['configuration'][SWIFTMAILER_TRANSPORT_SMTP]['username']);
        variable_set('swiftmailer_smtp_password', $form_state['values']['transport']['configuration'][SWIFTMAILER_TRANSPORT_SMTP]['password']);
        drupal_set_message(t('Drupal has been configured to send all e-mails using the SMTP transport type.'), 'status');
        break;

      case SWIFTMAILER_TRANSPORT_SENDMAIL:
        variable_set('swiftmailer_sendmail_path', $form_state['values']['transport']['configuration'][SWIFTMAILER_TRANSPORT_SENDMAIL]['path']);
        variable_set('swiftmailer_sendmail_mode', $form_state['values']['transport']['configuration'][SWIFTMAILER_TRANSPORT_SENDMAIL]['mode']);
        drupal_set_message(t('Drupal has been configured to send all e-mails using the Sendmail transport type.'), 'status');
        break;

      case SWIFTMAILER_TRANSPORT_NATIVE:
        drupal_set_message(t('Drupal has been configured to send all e-mails using the PHP transport type.'), 'status');
        break;

      case SWIFTMAILER_TRANSPORT_SPOOL:
        variable_set('swiftmailer_spool_directory', $form_state['values']['transport']['configuration'][SWIFTMAILER_TRANSPORT_SPOOL]['directory']);
        drupal_set_message(t('Drupal has been configured to send all e-mails using the Spool transport type.'), 'status');
        break;
    }
  }
}
