<?php
/**
 * @file
 * Functions for providing support with Google reCaptcha.
 */

/**
 * Add captcha
 */
function g_add_captcha(&$form, $form_id) {
  $tune = variable_get('google_recaptcha');

  $url = 'https://www.google.com/recaptcha/api.js?onload=google_recaptcha_onload&render=explicit';
  if (!empty($tune['settings']['language'])) {
    $url .= '&hl=' . $tune['settings']['language'];
  }

  $recaptcha_api = array(
    'data' => $url,
    'scope' => 'footer',
    'type' => 'external',
    'defer' => TRUE,
    // and we waiting when 'async' param will be in core....
  );
  $form['#attached']['js'][] = $recaptcha_api;

  $captcha_form_name = 'google_recaptcha_' . $form_id;
  $captcha_container = '<div id="' . $captcha_form_name . '"></div>';

  $widget_size = $form_id == 'user_login_block' ? 'compact' : $tune['settings']['widget_size'];
  $widget_theme = $tune['settings']['widget_theme'];

  $captcha_js = 'grecaptcha.render("' . $captcha_form_name . '", {
    "sitekey" : "' . $tune['public_key'] . '", 
    "size" : "' . $widget_size . '", 
    "theme" : "' . $widget_theme . '"});
  ';

  $recaptcha_load = array(
    'data' => 'var google_recaptcha_onload = function() {' . $captcha_js . '};',
    'scope' => 'header',
    'type' => 'inline',
  );
  $form['#attached']['js'][] = $recaptcha_load;

  $form['actions']['submit']['#prefix'] = empty($form['actions']['submit']['#prefix']) ? $captcha_container : $captcha_container . $form['actions']['submit']['#prefix'];
  $form['#validate'][] = 'g_validate_submission';
}

/**
 * Additional validation function for protected form
 * Here we ask from Google - is this submission ok?
 *
 * @param $form
 * @param $form_state
 */
function g_validate_submission($form, &$form_state) {
  $tune = variable_get('google_recaptcha');
  $secret = !empty($tune['secret_key']) ? $tune['secret_key'] : '';
  $response = isset($_POST['g-recaptcha-response']) ? $_POST['g-recaptcha-response'] : '';
  $remote_ip = ip_address();

  $answer = g_ask_google($secret, $response, $remote_ip);

  // collect statistics about requests and responses (if enabled)
  if ($tune['statistics']['status'] == 1) {
    $tune['statistics']['requests'] += 1;
    empty($answer) ? $tune['statistics']['fails'] += 1 : $tune['statistics']['success'] += 1;
  }
  variable_set('google_recaptcha', $tune);

  // Google think this is the bad submission, return form error (aha!)
  if (!$answer) {
    form_set_error('submit', t('Google reCAPTCHA does not accept this submission. Try again please, or contact to Site support services.'));
  }
}

/**
 * Ask from Google is this submission ok
 * https://developers.google.com/recaptcha/docs/verify
 *
 * @param $secret
 * @param $response
 * @return bool
 */
function g_ask_google($secret, $response, $remoteip) {
  $tune = variable_get('google_recaptcha');
  $answer = FALSE;

  $request_data = array(
    'secret' => $secret,
    'response' => $response,
    'remoteip' => $remoteip,
  );

  $ch = curl_init('https://www.google.com/recaptcha/api/siteverify');

  curl_setopt($ch, CURLOPT_RETURNTRANSFER, TRUE);
  curl_setopt($ch, CURLOPT_POST, TRUE);
  curl_setopt($ch, CURLOPT_POSTFIELDS, $request_data);

  $response = curl_exec($ch);
  curl_close($ch);

  $response = json_decode($response, TRUE);

  if ($response['success'] == FALSE) {

    $error_codes = array(
      'missing-input-secret' => 'The secret parameter is missing.',
      'invalid-input-secret' => 'The secret parameter is invalid or malformed.',
      'missing-input-response' => 'The response parameter is missing.',
      'invalid-input-response' => 'The response parameter is invalid or malformed.',
    );

    if (!empty($response['error-codes']) && $tune['settings']['write_log'] == 1) {
      $log_vars = array(
        '@error' => $error_codes[$response['error-codes'][0]],
        '@remoteip' => $remoteip,
      );
      watchdog('Google reCAPTCHA', 'Google service returned error "@error". Site visitor address: @remoteip', $log_vars, WATCHDOG_WARNING);
    }
  }
  elseif ($response['success'] == TRUE) {
    $answer = TRUE;
  }

  return $answer;
}





