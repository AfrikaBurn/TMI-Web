<?php

/**
 * @file
 * Implementation of the webform component using the webform API.
 */

/**
 * Implements _webform_defaults_[component]().
 *
 * @return array
 *   An webform component array initialized with default values.
 */
function _webform_defaults_country_list() {
  $element = array(
    'name'      => 'Country',
    'form_key'  => NULL,
    'mandatory' => 0,
    'value'     => '',
    'extra'     => array(
      'available_countries' => array(),
      'private'             => FALSE,
    ),
  );

  return $element;
}

/**
 * Implements _webform_edit_[component]().
 *
 * Every country_list components stores the list of countries selected by the
 * user (available countries) in that order in the DB. Only the ISO codes are
 * saved in the DB.
 *
 * @param array $component
 *   A Webform component array.
 *
 * @return array
 *   An array of form items to be displayed on the edit component page.
 */
function _webform_edit_country_list(array $component) {
  include_once DRUPAL_ROOT . '/includes/locale.inc';
  $all_countries    = country_get_list();
  $delta            = 0;
  $nr_all_countries = count($all_countries);
  $form             = array(
    'extra' => array(
      'available_countries' => array(
        '#tree' => TRUE,
        '#type'     => 'container',
        '#attached' => array(
          'css' => array(drupal_get_path('module', 'webform_country_list') . '/webform_country_list.css'),
        ),
      ),
    ),
  );
  // Get the list of countries previously stored for this component.
  // The order is the same as in the DB.
  $avail_countries = $component['extra']['available_countries'];
  // Only country ISO codes are stored in the DB, get the country names.
  foreach ($avail_countries as $country_code) {
    $avail_countries[$country_code] = &$all_countries[$country_code];
    unset($all_countries[$country_code]);
  }
  // Prepare the complete country list: first the previously selected countries,
  // then the rest.
  $all_countries = $avail_countries + $all_countries;
  foreach ($all_countries as $country_code => $country) {
    $form_entry = &$form['extra']['available_countries'][$delta];
    $form_entry = array(
      '#type' => 'container',
    );
    $form_entry['available'] = array(
      '#type'          => 'checkbox',
      '#return_value'  => $country_code,
      '#default_value' => isset($avail_countries[$country_code]) ? $country_code : NULL,
      '#attributes'    => array('class' => array('country-list-available')),
    );
    $form_entry['country_code'] = array(
      '#markup' => $country_code,
      '#prefix' => '<span class="country-list-code">',
      '#suffix' => '</span>',
    );
    $form_entry['label'] = array(
      '#markup' => $country,
      '#prefix' => '<span class="country-list-country">',
      '#suffix' => '</span>',
    );

    $form_entry['#delta']  = $delta;
    $form_entry['#weight'] = $delta;
    $form_entry['_weight'] = array(
      '#type'          => 'weight',
      '#title'         => t('Weight for row @number', array('@number' => $delta + 1)),
      '#title_display' => 'invisible',
      '#delta'         => $nr_all_countries,
      '#default_value' => $delta,
      '#weight'        => 100,
    );
    $delta++;
  }
  $form['extra']['available_countries']['#theme'] = 'country_list_form';
  $form['extra']['available_countries']['#element_validate'] = array('_webform_country_list_edit_validate');

  return $form;
}

/**
 * Determines if parameter (weight) A is greater than B.
 *
 * Callback for usort() within _webform_country_list_edit_validate().
 *
 * @param array $a
 *   First country list entry to compare.
 * @param array $b
 *   Second country list entry to compare.
 *
 * @return int
 *   A value greater than 0 if $a is greater than $b, 0 if they're the same
 *   and a value smaller than 0 if $a is smaller than $b
 */
function _webform_country_list_cmp_weights(array $a, array $b) {
  return ($a['_weight'] - $b['_weight']);
}

/**
 * Implements callback_form_element_validate() for country_list elements.
 *
 * Ensures the countries are ordered in the form values array like the user did
 * in the UI. Selects those countries that where enabled by the user to be saved
 * for this component in the DB.
 *
 * @param array $element
 *   An form API element array.
 * @param array $form_state
 *   An form API array of the state of the form.
 */
function _webform_country_list_edit_validate(array &$element, array &$form_state) {
  $values = &drupal_array_get_nested_value($form_state['values'], $element['#parents']);
  // Sort the array by the values of their weight so it reflects the ordering
  // the user chose in the UI.
  usort($values, '_webform_country_list_cmp_weights');
  // Save those countries chosen by the user to save them later in the DB.
  $filtered = array();
  foreach ($values as $value) {
    if ($value['available'] !== 0) {
      $filtered[$value['available']] = $value['available'];
    }
  }
  $values = $filtered;
}

/**
 * Implements _webform_render_[component]().
 *
 * @param array $component
 *   A Webform component array.
 * @param array $value
 *   If editing an existing submission or resuming a draft, this will contain
 *   an array of values to be shown instead of the default in the component
 *   configuration. This value will always be an array, keyed numerically for
 *   each value saved in this field.
 * @param bool $filter
 *   Whether or not to filter the contents of descriptions and values when
 *   rendering the component. Values need to be unfiltered to be editable by
 *   Form Builder.
 *
 * @return array
 *   A renderable array
 */
function _webform_render_country_list(array $component, array $value = NULL, $filter = TRUE) {
  // Necessary for country_get_list()
  include_once DRUPAL_ROOT . '/includes/locale.inc';
  $all_countries       = country_get_list();
  $available_countries = empty($component['mandatory']) ? array('no_selection' => t('<Select a country>')) : array();

  foreach ($component['extra']['available_countries'] as $country_code) {
    $available_countries[$country_code] = $all_countries[$country_code];
  }
  if (count($available_countries) == 1 && isset($available_countries['no_selection'])) {
    $available_countries += $all_countries;
  }
  reset($available_countries);
  $default_ctry = key($available_countries);
  // If the PHP PECL geoip package is available set the default country to that
  // matching the geoip country.
  if (function_exists('geoip_country_code_by_name')) {
    // We use the PHP PECL geoip package to look up the IP address of the
    // user in the geoip IP database in order to find a matching country.
    // We get back the ISO country code for the user.
    $geoip_ctry_code = geoip_country_code_by_name(ip_address());
    if (isset($available_countries[$geoip_ctry_code])) {
      $default_ctry = $geoip_ctry_code;
    }
  }
  $element = array(
    '#type'           => 'select',
    '#title'          => $component['name'],
    '#title_display'  => isset($component['extra']['title_display']) ? $component['extra']['title_display'] : 'before',
    '#description'    => isset($component['extra']['description']) ? check_plain($component['extra']['description']) : NULL,
    '#options'        => $available_countries,
    '#default_value'  => empty($value) ? $default_ctry : $value,
    '#weight'         => isset($component['weight']) ? $component['weight'] : 0,
    '#required'       => $component['mandatory'],
    '#theme_wrappers' => array('webform_element'),
    '#translatable'   => array('title'),
  );

  return $element;
}

/**
 * Implements _webform_submit_[component]().
 *
 * @param array $component
 *   A Webform component array.
 * @param string $value
 *   The ISO code for the selected country or 'no_selection' for non mandatory
 *   fields where the user didn't choose a country
 *
 * @return array
 *   either the unchanged ISO code or NULL if the user didn't select a country
 */
function _webform_submit_country_list(array $component, $value) {
  if ($component['mandatory'] == 0 && $value == 'no_selection') {
    $value = NULL;
  }

  return $value;
}

/**
 * Implements _webform_display_[component]().
 *
 * @param array $component
 *   A Webform component array.
 * @param $value
 *   An array of information containing the submission result, directly
 *   correlating to the webform_submitted_data database table schema.
 * @param string $format
 *   Either 'html' or 'text'. Defines the format that the content should be
 *   returned as. Make sure that returned content is run through check_plain()
 *   or other filtering functions when returning HTML.
 *
 * @return array
 *   A renderable element
 */
function _webform_display_country_list(array $component, $value, $format = 'html') {
  return array(
    '#title'          => $component['name'],
    '#weight'         => $component['weight'],
    '#theme'          => 'webform_display_country_list',
    '#theme_wrappers' => $format == 'html' ? array('webform_element') : array('webform_element_text'),
    '#post_render'    => array('webform_element_wrapper'),
    '#component'      => $component,
    '#format'         => $format,
    '#value'          => isset($value) ? $value[0] : '',
    '#translatable'   => array('title'),
  );
}

/**
 * Implements _webform_theme_[component]().
 *
 * @return array
 *   An associative array of theme hook information.
 */
function _webform_theme_country_list() {
  return array(
    'country_list_form' => array(
      'render element' => 'element',
    ),
    'webform_display_country_list' => array(
      'render element' => 'element',
    ),
  );
}

/**
 * Implements _webform_table_[component]().
 *
 * @param array $component
 *   A Webform component array.
 * @param $value
 *   An array of information containing the submission result, directly
 *   correlating to the webform_submitted_data database schema.
 *
 * @return string
 *   Textual output formatted for human reading.
 */
function _webform_table_country_list(array $component, $value) {
  return !empty($value[0]) ? check_plain($value[0]) : '';
}

/**
 * Implements _webform_csv_headers_[component]().
 *
 * @param array $component
 *   A Webform component array.
 * @param array $export_options
 *   An array of options that may configure export of this field.
 *
 * @return array
 *   An array of data to be displayed in the first three rows of a CSV file, not
 *   including either prefixed or trailing commas.
 */
function _webform_csv_headers_country_list(array $component, array $export_options) {
  $header = array();

  $header[0] = array('');
  $header[1] = array('');
  $header[2] = $component['name'];

  return $header;
}

/**
 * Implements _webform_csv_data_[component]().
 *
 * @param array $component
 *   A Webform component array.
 * @param array $export_options
 *   An array of options that may configure export of this field.
 * @param array $value
 *   An array of information containing the submission result, directly
 *   correlating to the webform_submitted_data database schema.
 *
 * @return string
 *   An array of items to be added to the CSV file. Each value within the array
 *   will be another column within the file. This function is called once for
 *   every row of data.
 */
function _webform_csv_data_country_list(array $component, array $export_options, array $value) {
  return isset($value[0]) ? $value[0] : '';
}


/**********************************************************************/
/******************* FORM BUILDER INTEGRATION *************************/
/**********************************************************************/


/**
 * Implements _webform_form_builder_map_[form_builder type]().
 */
function _webform_form_builder_map_country_list() {
  $map['form_builder_type'] = 'country_list';
  $map['properties']        = array(
    'available_countries' => array(
      'storage_parents' => array('extra', 'available_countries'),
    ),
  );
  return $map;
}

/**
 * Implements _webform_form_builder_properties_[component]().
 *
 * Component specific properties.
 *
 * @see form_builder_webform_form_builder_properties().
 */
function _webform_form_builder_properties_country_list() {
  return array(
    'available_countries' => array(
      'form'   => 'webform_country_list_form_builder_property_country_list_form',
    ),
  );
}

/**
 * Callback set in _webform_form_builder_properties_country_list().
 */
function webform_country_list_form_builder_property_country_list_form(&$form_state, $form_type, $element, $property) {
  $edit = _webform_edit_country_list($element['#webform_component']);
  $form['available_countries'] = $edit['extra']['available_countries'] + array(
    '#form_builder' => array('property_group' => 'options'),
  );

  return $form;
}
