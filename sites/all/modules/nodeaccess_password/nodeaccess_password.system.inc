<?php

/**
 * @file
 * Node access password integration with the system module.
 */

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * @see system_site_information_settings().
 * @see hook_form_FORM_ID_alter().
 */
function nodeaccess_password_form_system_site_information_settings_alter(&$form, &$form_state, $form_id) {
  if (variable_get('site_403', '') == 'nodeaccess_password_403') {
    $form['error_page']['site_403']['#value'] = variable_get('nodeaccess_password_old_403', '');
    $form['error_page']['site_403']['#disabled'] = TRUE;
    $form['error_page']['site_403']['#element_validate'][] = 'nodeaccess_password_form_system_site_information_settings_validate';
    $form['error_page']['site_403']['#description'] = t('This error page has been usurped by the <em>node access password</em> module.');
  }
}

/**
 * Element validate callback for site_403 in system_site_information_settings().
 */
function nodeaccess_password_form_system_site_information_settings_validate($element, &$form_state, $form) {
  form_set_value($element, 'nodeaccess_password_403', $form_state);
}