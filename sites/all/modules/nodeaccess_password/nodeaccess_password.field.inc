<?php

/**
 * @file
 * Node access password integration with the Field API.
 */

/**
 * Implements hook_field_info().
 */
function nodeaccess_password_field_info() {
  return array(
    'nodeaccess_password' => array(
      'label' => t('Node access password'),
      'description' => t("This field stores whether to show the Node access password."),
      'settings' => array(),
      'default_widget' => 'nodeaccess_password',
      'default_formatter' => 'nodeaccess_password_default',
    ),
  );
}

/**
 * Implements hook_field_schema().
 */
function nodeaccess_password_field_schema($field) {
  switch ($field['type']) {
    case 'nodeaccess_password':
      $columns = array(
        'value' => array(
          'type' => 'int',
          'size' => 'tiny',
          'default' => '0',
        ),
      );
      break;
  }
  return array('columns' => $columns);
}

/**
 * Implements hook_field_widget_info().
 */
function nodeaccess_password_field_widget_info() {
  return array(
    'nodeaccess_password' => array(
      'label' => t('Node access password'),
      'field types' => array('nodeaccess_password'),
      'behaviors' => array(
        'multiple values' => FIELD_BEHAVIOR_DEFAULT,
        'default value' => FIELD_BEHAVIOR_DEFAULT,
      ),
    ),
  );
}

/**
 * Implements hook_field_widget_form().
 */
function nodeaccess_password_field_widget_form(&$form, &$form_state, $field, $instance, $langcode, $items, $delta, $element) {
  $element['value'] = array(
    '#type' => 'checkbox',
    '#title' => $instance['label'],
    '#default_value' => isset($items[$delta]['value']) ? $items[$delta]['value'] : 0,
  );
  return $element;
}

/**
 * Implements hook_field_formatter_info().
 */
function nodeaccess_password_field_formatter_info() {
  return array(
    'nodeaccess_password_default' => array(
      'label' => t('Default'),
      'field types' => array('nodeaccess_password'),
    ),
  );
}

/**
 * Implements hook_field_formatter_view().
 */
function nodeaccess_password_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $element = array();
  switch ($display['type']) {
    case 'nodeaccess_password_default':
      // Only users with permission will see the password printed on the node.
      if (user_access('view node access passwords')) {  
        // More elaborate formatters can defer to a theme function for easier
        // customization.
        foreach ($items as $delta => $item) {
          $element[$delta] = array(
            '#theme' => 'nodeaccess_password_formatter_default',
            '#data' => $item,
            '#node' => $entity,
          );
        }
      }
      break;
  }
  return $element;
}

/**
 * Implements hook_field_is_empty().
 */
function nodeaccess_password_field_is_empty($item, $field) {
  return empty($item['value']);
}

/**
 * Theme function for 'default' formatter.
 */
function theme_nodeaccess_password_formatter_default($variables) {
  $out = '';

  // Only use the first delta.
  $element = &$variables['element'];

  $node = $element['#node'];
  if ($element['#data']['value'] && !empty($node->nodeaccess_password)) {
    $out .= '<div id="nodeaccess-password">';
    foreach ($node->nodeaccess_password as $realm_id => $password) {
      $realm = nodeaccess_password_realm_load($realm_id);
      $out .= '<div class="nodeaccess-password">';
      $out .= '<span class="realm">';
      $out .= check_plain($realm->name);
      $out .= ':</span> ';
      $out .= $password;
      $out .= '</div>';
    }
    $out .= '</div>';
  }
  return $out;
}