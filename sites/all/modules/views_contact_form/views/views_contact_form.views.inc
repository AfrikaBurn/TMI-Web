<?php

/**
 * Implementation of hook_views_plugins().
 */
function views_contact_form_views_plugins() {
  return array(
    'style' => array(
      'views_contact_form_style' => array(
        'title' => t('Views contact form'),
        'help' => t('Displays a contact form where the recipient is a value from a field.'),
        'handler' => 'views_contact_form_style',
        'path' => drupal_get_path('module', 'views_contact_form') . '/views',
        'uses fields' => TRUE,
        'uses row plugin' => FALSE,
        'uses options' => TRUE,
        'uses grouping' => FALSE,
        'type' => 'normal',
        'even empty' => FALSE,
      ),
    ),
  );
}

/**
 * Implementation of hook_views_handlers().
 */
function views_contact_form_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'views_contact_form') . '/views',
    ),
    'handlers' => array(
      'views_contact_form_handler' => array(
        'parent' => 'views_handler_field',
      ),
    ),
  );
}

/**
 * Implements hook_views_data().
 */
function views_contact_form_views_data_alter(&$data) {

  $data['users']['mail']['field']['handler'] = 'views_contact_form_handler';

}
