<?php

/**
 * @file
 * Admin page
 */

/**
 * Create page with information about setting of Google reCAPTCHA
 * Is keys were input?
 * List of all protected forms
 * Statistics data - if was enabled (default)
 * Some module settings
 * Where to get additional information about Google reCAPTCHA
 *
 * @return string
 */
function g_summary() {
  $tune = variable_get('google_recaptcha');
  $output = theme_render_template(drupal_get_path('module', 'google_recaptcha') . '/google-recaptcha-summary.tpl.php', $tune);
  return $output;
}

/**
 * Create form for managing Google reCAPTCHA keys
 * and different settings
 *
 * @param $form
 * @param &$form_state
 *
 * @return array
 */
function g_tune($form, &$form_state) {
  $tune = variable_get('google_recaptcha');

  $form['#prefix'] = t('
Both keys You can create on <a href="@google-recaptcha-official-site" target="_blank">Google reCAPTCHA site.</a><br/>
Be careful if You have several sites - check that this pair of keys exactly for THIS site.', array('@google-recaptcha-official-site' => 'https://www.google.com/recaptcha'));

  $form['public_key'] = array(
    '#title' => t('Google reCAPTCHA public key'),
    '#type' => 'textfield',
    '#default_value' => empty($tune['public_key']) ? '' : $tune['public_key'],
    // may be without additional check?
    '#size' => 40,
    '#maxlength' => 40,
    '#required' => TRUE,
  );
  $form['secret_key'] = array(
    '#title' => t('Google reCAPTCHA secret key'),
    '#type' => 'textfield',
    '#default_value' => empty($tune['secret_key']) ? '' : $tune['secret_key'],
    '#size' => 40,
    '#maxlength' => 40,
    '#required' => TRUE,
  );
  $form['language'] = array(
    '#title' => t('Google reCAPTCHA language'),
    '#description' => t('Enter the language code that can be found here: https://developers.google.com/recaptcha/docs/language'),
    '#type' => 'textfield',
    '#default_value' => empty($tune['settings']['language']) ? 'en' : $tune['settings']['language'],
    '#size' => 10,
    '#maxlength' => 10,
  );
  $form['widget_size'] = array(
    '#title' => t('Widget size'),
    '#type' => 'select',
    '#options' => array('normal' => 'normal', 'compact' => 'compact'),
    '#default_value' => $tune['settings']['widget_size'],
  );
  $form['widget_theme'] = array(
    '#title' => t('Widget theme'),
    '#type' => 'select',
    '#options' => array('light' => 'light', 'dark' => 'dark'),
    '#default_value' => $tune['settings']['widget_theme'],
  );
  $form['collect_statistics'] = array(
    '#title' => t('Collect statistics'),
    '#type' => 'checkbox',
    '#default_value' => $tune['statistics']['status'],
    '#description' => t('
Count requests to Google reCAPTCHA servers and their responses. Useful for mainly understanding about the effectiveness this protection system<br/>
More detailed statistics data You may found in Your <a href="@google-recaptcha-control-panel" target="_blank">control panel</a>.', array('@google-recaptcha-control-panel' => 'https://www.google.com/recaptcha/admin#list')),
  );
  $form['write_log'] = array(
    '#title' => t('Write log'),
    '#type' => 'checkbox',
    '#default_value' => $tune['settings']['write_log'],
    '#description' => t('Write errors results of Google Recaptcha submission into log. Useful for debugging purpose.'),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save')
  );

  return $form;
}

/**
 * Validate handler
 *
 * @param $form
 * @param $form_state
 */
function g_tune_validate($form, &$form_state) {
  if (strlen($form_state['values']['public_key']) < 40) {
    form_set_error('public_key', t('Length of public key must be 40 symbols long.'));
  }
  if (strlen($form_state['values']['secret_key']) < 40) {
    form_set_error('secret_key', t('Length of secret key must be 40 symbols long.'));
  }
}

/**
 * Submit handler
 *
 * @param $form
 * @param $form_state
 */
function g_tune_submit($form, &$form_state) {
  $tune = variable_get('google_recaptcha');
  $tune['public_key'] = $form_state['values']['public_key'];
  $tune['secret_key'] = $form_state['values']['secret_key'];
  $tune['statistics']['status'] = $form_state['values']['collect_statistics'];
  $tune['settings']['write_log'] = $form_state['values']['write_log'];
  $tune['settings']['widget_size'] = $form_state['values']['widget_size'];
  $tune['settings']['widget_theme'] = $form_state['values']['widget_theme'];
  $tune['settings']['language'] = $form_state['values']['language'];

  // reset statistics data if was disabled
  if ($form_state['values']['collect_statistics'] == 0) {
    $tune['statistics']['requests'] = 0;
    $tune['statistics']['success'] = 0;
    $tune['statistics']['fails'] = 0;
  }

  variable_set('google_recaptcha', $tune);
  drupal_set_message(t('Google reCAPTCHA keys and settings were saved'));
  $form_state['redirect'] = 'admin/config/spam_protection/google_recaptcha';
}

/**
 * Create form for managing list of protected forms.
 *
 * @param $form
 * @param $form_state
 *
 * @return array
 */
function g_forms($form, &$form_state) {
  $tune = variable_get('google_recaptcha');

  // collect all form names
  $available_forms = array();

  if (module_exists('comment')) {
    // by default
    $available_forms['comment_'] = t('Comment');
  }
  if (module_exists('contact')) {
    // by default
    $available_forms['contact_site_form'] = t('Contact');
  }
  if (module_exists('poll')) {
    // by default
    $available_forms['poll_'] = t('Poll');
  }
  if (module_exists('search')) {
    $available_forms['search_'] = t('Search');
  }
  if (module_exists('webform')) {
    $q = db_select('node', 'n');
    $webforms = $q
      ->condition('n.type', 'webform')
      ->condition('n.status', 1)
      ->fields('n', array('nid', 'title'))
      ->execute()
      ->fetchAll();

    if (!empty($webforms)) {
      foreach ($webforms as $webform) {
        $available_forms['webform_client_form_' . $webform->nid] = $webform->title;
      }
    }
  }
  $available_forms['user_login'] = t('User Login') . ' <b>(' . t('recommended for security') . ')</b>';
  $available_forms['user_login_block'] = t('User Login Block') . ' <b>(' . t('recommended for security') . ')</b>';
  $available_forms['user_register_form'] = t('User Register') . ' <b>(' . t('recommended for security') . ')</b>';

  drupal_alter('google_recaptcha_available_forms', $available_forms);

  // create form
  $form['#prefix'] = '<p>' . t('Check forms which You want to protect with Google reCAPTCHA') . '</p>';
  $form['#prefix'] .= '<div class="description">' . t('For security usability reasons - form <b><i>"recovery pass"</i></b> is always protected!') . '</div>';

  foreach ($available_forms as $available_form_name => $available_form_title) {
    $form['available_forms'][$available_form_name] = array(
      '#title' => $available_form_title,
      '#type' => 'checkbox',
      '#default_value' => in_array($available_form_name, $tune['protected_forms']) ? 1 : 0,
    );
  }

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save')
  );

  $form['#tree'] = TRUE;

  return $form;
}

/**
 * Submit handler
 *
 * @param $form
 * @param $form_state
 */
function g_forms_submit($form, &$form_state) {
  $tune = variable_get('google_recaptcha');

  // reset list with protected forms
  // useful if some module which provided forms was disabled
  $tune['protected_forms'] = array();

  foreach ($form_state['values']['available_forms'] as $available_form_name => $available_form_status) {
    if ($available_form_status == 1) {
      $tune['protected_forms'][] = $available_form_name;
    }
  }

  drupal_set_message('Settings were saved.');

  variable_set('google_recaptcha', $tune);
}
