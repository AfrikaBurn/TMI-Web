<?php

/**
 * @file
 * Preprocessors and helper functions to make theming easier.
 */

/**
 * Returns HTML for the label for the empty value.
 *
 * @param array $variables
 *   An associative array containing:
 *   - instance: An array representing the widget requesting the options.
 *
 * @return string
 *   The label for empty value.
 */
function theme_entity_reference_multiple_none($variables) {
  $option = $variables['option'];
  $output = ($option == 'option_none' ? t('- None -') : t('- Select a value -'));
  return $output;
}

/**
 * Returns HTML for the settings table of the short codes.
 *
 * @param array $variables
 *   An associative array containing:
 *   - element: An associative array containing the properties of the element.
 *
 * @return string
 *   The settings table of the short codes.
 */
function theme_entity_reference_multiple_short_codes_settings_table($variables) {
  $path = drupal_get_path('module', 'entity_reference_multiple');
  drupal_add_css($path . '/css/entity-reference-multiple.css');

  $element = $variables['element'];

  $rows = array();
  foreach (element_children($element) as $key) {
    foreach (element_children($element[$key]) as $element_children) {
      $rows[$key][] = render($element[$key][$element_children]);
    }
  }

  return theme('table', array(
    'header' => array(t('Label'), t('Machine name'), t('Short code')),
    'rows' => $rows,
    'attributes' => array(
      'class' => array('entity-reference-multiple-short-codes-settings'),
    ),
  ));
}
