<?php

/**
 * @file
 * The Select (or other) field widget.
 */

/**
 * Implements hook_field_widget_info().
 */
function select_or_other_field_widget_info() {
  $field_types = array(
    'text',
    'number_integer',
    'number_decimal',
    'number_float',
    'taxonomy_term_reference',
  );
  $settings = array(
    'available_options' => '',
    'other' => t('Other'),
    'other_title' => '',
    'other_unknown_defaults' => 'other',
    'other_size' => 60,
  );
  return array(
    'select_or_other' => array(
      'label' => t('Select (or other) list'),
      'field types' => $field_types,
      'behaviors' => array(
        'multiple values' => FIELD_BEHAVIOR_CUSTOM,
        'default value' => FIELD_BEHAVIOR_DEFAULT,
      ),
      'settings' => $settings,
      'weight' => 2,
    ),
    'select_or_other_sort' => array(
      'label' => t('Select (or other) drag and drop lists [deprecated in favor of Field Collection]'),
      'field types' => $field_types,
      'behaviors' => array(
        'multiple values' => FIELD_BEHAVIOR_DEFAULT,
        'default value' => FIELD_BEHAVIOR_DEFAULT,
      ),
      'settings' => $settings,
      'weight' => 2,
    ),
    'select_or_other_buttons' => array(
      'label' => t('Select (or other) check boxes/radio buttons'),
      'field types' => $field_types,
      'behaviors' => array(
        'multiple values' => FIELD_BEHAVIOR_CUSTOM,
        'default value' => FIELD_BEHAVIOR_DEFAULT,
      ),
      'settings' => $settings,
      'weight' => 2,
    ),
  );
}

/**
 * Prepare a single option.
 */
function select_or_other_field_widget_form_prepare_option(&$options, $key, $opt) {
  $opt = trim($opt);
  if (empty($opt)) {
    return;
  }
  // Sanitize the user input with a permissive filter.
  $opt = filter_xss($opt);
  // If option has a key specified
  if (strpos($opt, '|') !== FALSE) {
    list($key, $value) = explode('|', $opt);
    $options[$key] = (isset($value) && $value !== '') ? html_entity_decode($value) : $key;
  }
  // If option has no key specified
  else {
    $options[$opt] = html_entity_decode($opt);
  }
}

/**
 * Helper function to get a list of options from the settings.
 * @param $instance
 *  Instance settings array.
 * @param $field
 *  Field info array.
 * @return array
 *  Available options.
 */
function _select_or_other_field_widget_get_available_options($instance, $field) {
  $options = array();

  if ($field['type'] == 'taxonomy_term_reference') {
    if (module_exists('i18n_taxonomy')) {
      $options_list = i18n_taxonomy_allowed_values($field);
    }
    else {
      $options_list = taxonomy_allowed_values($field);
    }
    foreach ($options_list as $key => $val) {
      // $select_or_other_field_widget_list[] = "{$key}|{$val}";
      $options[] = $val;
    }
  }
  else {
    $options = _select_or_other_invoke_available_options($instance);
    $options = array_merge($options, explode("\n", $instance['widget']['settings']['available_options']));
  }
  return $options;
}

/**
 * Prepare options for the widget list.
 */
function select_or_other_field_widget_form_prepare_options($field, $instance, $has_value = FALSE) {
  $options = array();

  $list = _select_or_other_field_widget_get_available_options($instance, $field);

  foreach ($list as $key => $opt) {
    if (is_array($opt)) {
      $optgroup_options = array();
      foreach ($opt as $optgroup_key => $optgroup_opt) {
        select_or_other_field_widget_form_prepare_option($optgroup_options, $optgroup_key, $optgroup_opt);
        $options[$key] = $optgroup_options;
      }
    }
    else {
      select_or_other_field_widget_form_prepare_option($options, $key, $opt);
    }
  }

  $required = (isset($instance['required']) && $instance['required']);
  $multiple = (($instance['widget']['type'] == 'select_or_other' && $field['cardinality'] == -1)
    || ($instance['widget']['type'] == 'select_or_other_sort'));
  $multiple_checkbox = ($instance['widget']['type'] == 'select_or_other_buttons' && $field['cardinality'] == -1);

  $empty_option = array('_none' => theme('select_or_other_none', array('instance' => $instance)));
  // Multiple select.
  if ($multiple) {
    // Add a 'none' option for non-required fields.
    if (!$required) {
      $options = $empty_option + $options;
    }
  }
  // Single select.
  elseif (!$multiple_checkbox) {
    // Add a 'none' option for non-required fields, and a 'select a value'
    // option for required fields that do not come with a value selected.
    if (!$required) {
      $options = $empty_option + $options;
    }
  }

  // @todo: This isset() can probably be taken out in drupal 8.
  if (isset($settings['sort_options']) && $settings['sort_options']) {
    natcasesort($options);
  }

  return $options;
}

/**
 * Helper function to get the default taxonomy value.
 */
function select_or_other_taxonomy_default_value($items, $delta) {
  // @todo this code seems odd. why perform the same check twice.
  if (!empty($items[$delta]['tid'])) {
    $term = taxonomy_term_load_multiple(array($items[$delta]['tid']));
    $default_value = $items[$delta]['tid'] !== 'autocreate' ? $term[$items[$delta]['tid']]->name : NULL;
  }
  else {
    $default_value = NULL;
  }
  return $default_value;
}

/**
 * Implements hook_field_widget_form().
 */
function select_or_other_field_widget_form(&$form, &$form_state, $field, $instance, $langcode, $items, $delta, $element) {
  if ($field['type'] == 'taxonomy_term_reference') {
    $default_value = select_or_other_taxonomy_default_value($items, $delta);
  }
  else {
    $default_value = isset($items[$delta]['value']) ? $items[$delta]['value'] : NULL;
  }

  // Construct the element.
  $element = $element + array(
    '#type' => 'select_or_other',
    '#other' => isset($instance['widget']['settings']['other']) ? $instance['widget']['settings']['other'] : t('Other'),
    '#other_title' => !empty($instance['widget']['settings']['other_title']) ? $instance['widget']['settings']['other_title'] : NULL,
    '#other_size' => $instance['widget']['settings']['other_size'],
    '#default_value' => $default_value,
    '#options' => select_or_other_field_widget_form_prepare_options($field, $instance, !empty($items[$delta])),
    '#description' => isset($instance['description']) ? $instance['description'] : '',
    '#multiple' => $field['cardinality'] == 1 ? FALSE : $field['cardinality'],
    '#required' => $instance['required'],
    //'#other_delimiter' => $field['widget']['settings']['other_delimiter'] == 'FALSE' ? FALSE : $field['widget']['settings']['other_delimiter'],
    '#other_delimiter' => FALSE,
    '#other_unknown_defaults' => isset($instance['widget']['settings']['other_unknown_defaults']) ? $instance['widget']['settings']['other_unknown_defaults'] : 'other',
    '#element_validate' => array('select_or_other_field_widget_validate'),
    '#field_widget' => $instance['widget']['type'],
  );
  if (!empty($field['settings']['max_length'])) {
    $element['#maxlength'] = $field['settings']['max_length'];
  }

  // Set select type's.
  switch ($instance['widget']['type']) {
    case 'select_or_other':
      $element['#select_type'] = 'select';
      break;

    case 'select_or_other_sort':
      $element['#select_type'] = 'select';
      // Also disable multiples for this select type.
      $element['#multiple'] = FALSE;
      break;

    case 'select_or_other_buttons':
      $element['#select_type'] = $field['cardinality'] == 1 ? 'radios' : 'checkboxes';
      break;
  }

  // In situations where we handle our own multiples (checkboxes and multiple selects) set defaults differently.
  if ($element['#multiple']) {
    $element['#default_value'] = array();
    foreach ($items as $delta => $item) {
      if ($field['type'] == 'taxonomy_term_reference') {
        $element['#default_value'][$delta] = select_or_other_taxonomy_default_value($items, $delta);
      }
      else {
        $element['#default_value'][$delta] = $item['value'];
      }
    }
  }

  return $element;
}

/**
 * Helper function which invokes hook_select_or_other_available_options.
 *
 * @param $instance
 *  Field instance array.
 * @return array
 *  Available options.
 */
function _select_or_other_invoke_available_options($instance){
  $entity_type = $instance['entity_type'];
  $bundle = $instance['bundle'];
  $field_name = $instance['field_name'];

  $available_options = module_invoke_all('select_or_other_available_options', $entity_type, $bundle, $field_name);
  foreach ($available_options as $key => $value) {
    if (!strpos($value, '|')) {
      $available_options[$key] = "{$value}|{$value}";
    }
  }
  return $available_options;
}

/**
 * Implements hook_field_widget_settings_form().
 */
function select_or_other_field_widget_settings_form($field, $instance) {
  $form = array();

  $settings = &$instance['widget']['settings'];
  $provided_available_options = _select_or_other_invoke_available_options($instance);

  if ($field['type'] != 'taxonomy_term_reference') {
    $form['available_options'] = array(
      '#type' => 'textarea',
      '#title' => t('Available options'),
      '#description' => t('A list of values that are, by default, available for selection. Enter one value per line, in the format key|label. The key is the value that will be stored in the database, and the label is what will be displayed to the user.'),
      '#default_value' => isset($settings['available_options']) ? $settings['available_options'] : '',
    );
    if($provided_available_options){
      $form['provided_available_options'] = array(
        '#type' => 'textarea',
        '#disabled' => TRUE,
        '#title' => t('Module provided Available options'),
        '#description' => t('A list of values that are, by default, available for selection. These are provided by a module and not editable. Displayed in format key|label. The key is the value that will be stored in the database, and the label is what will be displayed to the user.'),
        '#value' => implode("\r\n", $provided_available_options),
      );
    }
  }
  $form['other'] = array(
    '#type' => 'textfield',
    '#title' => t('<em>Other</em> option'),
    '#description' => t('Label for the option that the user will choose when they want to supply an <em>other</em> value.'),
    '#default_value' => isset($settings['other']) ? $settings['other'] : t('Other'),
    '#required' => TRUE,
  );
  $form['other_title'] = array(
    '#type' => 'textfield',
    '#title' => t('<em>Other</em> field title'),
    '#description' => t('Label for the field in which the user will supply an <em>other</em> value.'),
    '#default_value' => isset($settings['other_title']) ? $settings['other_title'] : '',
  );

  if ($field['type'] != 'taxonomy_term_reference') {
    $form['other_unknown_defaults'] = array(
      '#type' => 'select',
      '#title' => t('<em>Other</em> value as default value'),
      '#description' => t("If any incoming default values do not appear in <em>available options</em> (i.e. set as <em>other</em> values), what should happen?"),
      '#options' => array(
        'other' => t('Add the values to the other textfield'),
        'append' => t('Append the values to the current list'),
        'available' => t('Append the values to the available options'),
        'ignore' => t('Ignore the values'),
      ),
      '#default_value' => isset($settings['other_unknown_defaults']) ? $settings['other_unknown_defaults'] : 'other',
      '#required' => TRUE,
    );
  }

  $form['other_size'] = array(
    '#type' => 'textfield',
    '#title' => t('<em>Other</em> field size'),
    '#default_value' => $settings['other_size'],
    '#required' => TRUE,
    '#element_validate' => array('element_validate_integer_positive'),
  );
  $form['sort_options'] = array(
    '#type' => 'checkbox',
    '#title' => t('Sort options'),
    '#description' => t("Sorts the options in the list alphabetically by value."),
    '#default_value' => isset($settings['sort_options']) ? $settings['sort_options'] : 0,
  );
  /*
  There are design issues with saving multiple other values with some field widgets - this needs a rethink.

  $form['other_delimiter'] = array(
    '#type' => 'textfield',
    '#title' => t('Other delimiter'),
    '#description' => t("Delimiter string to delimit multiple 'other' values into the <em>other</em> textfield.  If you enter <em>FALSE</em> only the last value will be used."),
    '#default_value' => isset($settings['other_delimiter']) ? $settings['other_delimiter'] : ', ',
    '#required' => TRUE,
    '#size' => 5,
  );
  */
  return $form;
}

/**
 * Transforms submitted form values into field storage format.
 * Align with Drupal core select list, NULL (-None-) value.
 * http://drupal.org/node/1830090
 */
function _select_or_other_options_form_to_storage($value) {
  if (isset($value[0])) {
    $index = array_search('_none', $value[0], TRUE);
    if ($index !== FALSE) {
      unset($value[0][$index]);
    }
  }
  return $value;
}

/**
 * Form element validate handler for taxonomy term element.
 */
function select_or_other_taxonomy_validate($element, &$form_state) {
  // Autocomplete widgets do not send their tids in the form, so we must detect
  // them here and process them independently.
  $value = array();

  // Get the selected tags and unset the select_or_other option.
  $tags = drupal_map_assoc((array) $element['select']['#value']);
  // Get the other value and prepare it for processing.
  if(isset($tags['select_or_other'])){
    unset($tags['select_or_other']);
    $tags += drupal_explode_tags($element['other']['#value']);
  }
  // Unset the _none value to prevent PDO exceptions.
  unset($tags['_none']);

  if ($tags) {
    // Collect candidate vocabularies.
    $field = field_widget_field($element, $form_state);
    $vocabularies = array();
    foreach ($field['settings']['allowed_values'] as $tree) {
      if ($vocabulary = taxonomy_vocabulary_machine_name_load($tree['vocabulary'])) {
        $vocabularies[$vocabulary->vid] = $vocabulary;
      }
    }

    // Translate term names into actual terms.
    foreach ($tags as $tag) {
      // See if the term exists in the chosen vocabulary and return the tid;
      // otherwise, create a new 'autocreate' term for insert/update.
      if ($possibilities = taxonomy_term_load_multiple(array(), array('name' => trim($tag), 'vid' => array_keys($vocabularies)))) {
        $term = (array) array_pop($possibilities);
      }
      else {
        $vocabulary = reset($vocabularies);
        $term = array(
          'tid' => 'autocreate',
          'vid' => $vocabulary->vid,
          'name' => $tag,
          'vocabulary_machine_name' => $vocabulary->machine_name,
        );
      }
      if ($term['tid'] !== 'autocreate'){
        $value[$term['tid']] = $term;
      }
      else {
        $value[] = $term;
      }
    }
  }

  form_set_value($element, $value, $form_state);
}

/**
 * Helper function to retrieve the other value from an element.
 */
function _fetch_other_value($element, $return_array = TRUE){
  $other_value = array();

  if ($element['other']['#value']) {
    // If the value in the other element was already a valid option, we want to
    // store that value instead of the one in the other field.
    foreach ($element['#options'] as $key => $option) {
      if($element['other']['#value'] === $option){
        $other_value[$key] = $option;
        break;
      }
    }

    if (!$other_value){
      $other_value[$element['other']['#value']] = $element['other']['#value'];
    }
  }

  if ($return_array){
    return $other_value;
  }
  else{
    $keys = array_keys($other_value);
    return array_pop($keys);
  }
}

/**
 * Element validate callback for a Select (or other) field widget.
 */
function select_or_other_field_widget_validate($element, &$form_state) {
  $field_name = $element['#field_name'];
  $field_info = field_info_field($field_name);

  $value = $element['select']['#value'];
  if (is_array($value) && isset($value['select_or_other'])) {
    // This is a multiselect which uses associated arrays.
    unset($value['select_or_other']);
    $value  += _fetch_other_value($element);
  }
  elseif ($value === 'select_or_other') {
    // This is a single select which uses strings.
    $other_value = _fetch_other_value($element, FALSE);
    if (!$other_value) {
      form_error($element['other'], t('!name: !title is required', array('!name' => t($element['select']['#title']), '!title' => $element['#other'])));
    }
    else{}
      $value = $other_value;
  }

  if ($value !== "") {
    if (in_array($element['#field_widget'], array('select_or_other', 'select_or_other_buttons'))) {
      // Filter out 'none' value (if present, will always be in key 0)
      if (isset($items[0]['value']) && $items[0]['value'] === '') {
        unset($items[0]);
      }
      if ($element['#multiple'] >= 2 && count($value) > $element['#multiple']) {
        form_error($element['select'], t('!name: cannot hold more than @count values.', array('!name' => t($element['select']['#title']), '@count' => $element['#multiple'])));
      }
      $delta = 0;
      $values = array();
      foreach ((array)$value as $v) {
        if ($field_info['type'] == 'number_integer' && !preg_match('/^-?\d+$/', $v) && $v != '_none') {
          form_error($element, t('!name field must be a valid integer.', array('!name' => t($element['select']['#title']))));
          break;
        }
        if (($field_info['type'] == 'number_float' || $field_info['type'] == 'number_decimal') && !is_numeric($v)) {
          form_error($element, t('!name field must be a valid integer or decimal.', array('!name' => t($element['select']['#title']))));
          break;
        }
        elseif ($field_info['type'] == 'text' && drupal_strlen($v) > $field_info['settings']['max_length']) {
          form_error($element, t('!name field must be a string at most @max characters long.', array('!name' => t($element['select']['#title']), '@max' => $field_info['settings']['max_length'])));
          break;
        }

        $values[$delta++]['value'] = $v;
      }
      $value = $values;
    }
    elseif ($element['#field_widget'] == 'select_or_other_sort') {
      $value = array('value' => $value);
    }

    // @todo Align with Drupal core select list, NULL (-None-) value.
    // http://drupal.org/node/1830090
    $value = _select_or_other_options_form_to_storage($value);

    form_set_value($element, $value, $form_state);
    $form_state['clicked_button']['#post'][$element['#name']] = $value; // Is this something we should do?
  }
  else {
    if ($field_info['type'] == 'taxonomy_term_reference') {
      form_set_value($element, array(array('tid' => '')), $form_state);
    }
    else {
      form_set_value($element, array(array('value' => '')), $form_state);
    }
  }

  if ($field_info['type'] == 'taxonomy_term_reference' && is_array($value)) {
    $terms = array();
    foreach ($value as $val) {
      if (isset($val['value'])) {
        $terms[] = $val['value'];
      }
    }
    $element['#value'] = drupal_implode_tags($terms);
    select_or_other_taxonomy_validate($element, $form_state);
    return;
  }

  // Add values to available options is configured to do so.
  if (!empty($form_state['field'][$field_name][$element['#parents'][1]]['instance'])) {
    $instance = $form_state['field'][$field_name][$element['#parents'][1]]['instance'];
  }
  else {
    $instance = field_widget_instance($element, $form_state);
  }

  if ($instance['widget']['settings']['other_unknown_defaults'] == 'available') {
    if (
      ($element['select']['#value'] == 'select_or_other' || (is_array($element['select']['#value']) && isset($element['select']['#value']['select_or_other']))) &&
      !empty($element['other']['#value']) &&
      !isset($element['#options'][$element['other']['#value']])
    ) {
      // Get the latest instance.
      $instance = field_read_instance($instance['entity_type'], $instance['field_name'], $instance['bundle']);
      // Make the change.
      $instance['widget']['settings']['available_options'] .= "\n" . $element['other']['#value'];
      // Save the instance.
      field_update_instance($instance);
    }
  }

  //return $element;
}

/**
 * Implements hook_field_formatter_info().
 */
function select_or_other_field_formatter_info() {
  return array(
    'select_or_other_formatter' => array(
      'label' => t('Select or other'),
      'field types' => array('text', 'number_integer', 'number_decimal', 'number_float'),
    ),
  );
}

/**
 * Implements hook_field_formatter_view().
 */
function select_or_other_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $element = array();
  $field_options = array();

  if (isset($instance['widget']['settings']['available_options'])) {
    $field_options = explode("\n", $instance['widget']['settings']['available_options']);
    $pos = strpos($instance['widget']['settings']['available_options'], '|');

    if ($pos !== FALSE) {
      // There are keys.
      $temp_options = array();
      foreach ($field_options as $field_item) {
        $exploded = explode('|', $field_item);
        $temp_options[$exploded[0]] = $exploded[1];
      }
      $field_options = $temp_options;
    }
  }

  foreach ($items as $delta => $item) {
    if (array_key_exists($item['value'], $field_options)) {
      $element[$delta] = array('#markup' => $field_options[$item['value']]);
    }
    else {
      $element[$delta] = array('#markup' => $item['value']);
    }
  }

  return $element;
}


/**
 * Implements hook_field_widget_error().
 */
function select_or_other_field_widget_error($element, $error, $form, &$form_state) {
  form_error($element, $error['message']);
}
