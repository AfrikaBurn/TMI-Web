<?php
/**
 * @file
 * An administration page which allows for configuration of how messages are
 * to be formatted.
 */

/**
 * Form builder; the messages form.
 *
 * @see swiftmailer_admin_messages_form_submit()
 */
function swiftmailer_admin_messages_form($form, &$form_state) {

  // Include helper functions.
  require_once(dirname(dirname(__FILE__)) . '/helpers/utilities.inc');

  $form['#tree'] = TRUE;

  $form['description'] = array(
    '#markup' => '<p>' . t('This page allows you to configure settings which determines how e-mail messages are created.') . '</p>',
  );

  if (swiftmailer_validate_library(variable_get('swiftmailer_path', SWIFTMAILER_VARIABLE_PATH_DEFAULT))) {

    $form['format'] = array(
      '#type' => 'fieldset',
      '#title' => t('Message format'),
      '#description' => t('You can set the default message format which should be applied to e-mail
        messages.'),
    );

    $form['format']['type'] = array(
      '#type' => 'radios',
      '#options' => array(SWIFTMAILER_FORMAT_PLAIN => t('Plain Text'), SWIFTMAILER_FORMAT_HTML => t('HTML')),
      '#default_value' => variable_get('swiftmailer_format', SWIFTMAILER_VARIABLE_FORMAT_DEFAULT),
    );

    $form['format']['respect'] = array(
      '#type' => 'checkbox',
      '#title' => t('Respect provided e-mail format.'),
      '#default_value' => variable_get('swiftmailer_respect_format', SWIFTMAILER_VARIABLE_RESPECT_FORMAT_DEFAULT),
      '#description' => t('The header "Content-Type", if available, will be respected if you enable this setting.
        Settings such as e-mail format ("text/plain" or "text/html") and character set may be provided through this
        header. Unless your site somehow alters e-mails, enabling this setting will result in all e-mails to be sent
        as plain text as this is the content type Drupal by default will apply to all e-mails.'),
    );

    $form['convert'] = array(
      '#type' => 'fieldset',
      '#title' => t('Plain Text Version'),
      '#description' => t('An alternative plain text version can be generated based on the HTML version if no plain text version
        has been explicitly set. The plain text version will be used by e-mail clients not capable of displaying HTML content.'),
      '#states' => array(
        'visible' => array(
          'input[type=radio][name=format[type]]' => array('value' => SWIFTMAILER_FORMAT_HTML),
        ),
      ),
    );

    $form['convert']['mode'] = array(
      '#type' => 'checkbox',
      '#title' => t('Generate alternative plain text version.'),
      '#default_value' => variable_get('swiftmailer_convert_mode', SWIFTMAILER_VARIABLE_CONVERT_MODE_DEFAULT),
    );

    $form['convert']['library'] = array(
      '#type' => 'select',
      '#title' => t('Specify the library to be used for plain text conversion.'),
      '#default_value' => variable_get('swiftmailer_convert_library', SWIFTMAILER_VARIABLE_CONVERT_LIBRARY_DEFAULT),
      '#options' => array(
        SWIFTMAILER_VARIABLE_CONVERT_LIBRARY_DEFAULT => t('Html2Text'),
        SWIFTMAILER_VARIABLE_CONVERT_LIBRARY_MAILSYSTEM => t('Mail System'),
      ),
      '#description' => theme('item_list', array(
        'title' => t('Information about plain text converters:'),
        'items' => array(
          t('Html2Text: please refer to !link for more details about how the alternative plain text version will be generated.', array('!link' => l('html2text', 'http://www.chuggnutt.com/html2text'))),
          t('!link: this is an enhancement of the native <em>drupal_html_to_text()</em> Drupal Core function (see this <a href="!href">issue</a> for more information).', array('!link' => l('Mail System', 'http://drupal.org/project/mailsystem'), '!href' => 'https://www.drupal.org/node/299138')),
        ),
      )),
    );

    $form['character_set'] = array(
      '#type' => 'fieldset',
      '#title' => t('Character Set'),
      '#description' => '<p>' . t('E-mails need to carry details about the character set which the
        receiving client should use to understand the content of the e-mail.
        The default character set is UTF-8.') . '</p>',
    );

    $form['character_set']['type'] = array(
      '#type' => 'select',
      '#options' => swiftmailer_get_character_set_options(),
      '#default_value' => variable_get('swiftmailer_character_set', SWIFTMAILER_VARIABLE_CHARACTER_SET_DEFAULT),
    );

    $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Save'),
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
 * Submit handler for swiftmailer_admin_messages_form($form, &$form_state).
 */
function swiftmailer_admin_messages_form_submit($form, &$form_state) {

  if (isset($form_state['values']['format']['type'])) {
    variable_set('swiftmailer_format', $form_state['values']['format']['type']);
  }

  if (isset($form_state['values']['format']['respect'])) {
    variable_set('swiftmailer_respect_format', $form_state['values']['format']['respect']);
  }

  if (isset($form_state['values']['convert']['mode'])) {
    variable_set('swiftmailer_convert_mode', $form_state['values']['convert']['mode']);
  }

  if (isset($form_state['values']['convert']['library'])) {
    variable_set('swiftmailer_convert_library', $form_state['values']['convert']['library']);
  }

  if (isset($form_state['values']['character_set']['type'])) {
    variable_set('swiftmailer_character_set', $form_state['values']['character_set']['type']);
  }
}
