<?php

/**
 * @file
 * Token functions for Field tokens module.
 */

/**
 * Implements hook_token_info().
 */
function field_tokens_token_info() {
  $field_types = field_info_field_types();
  $formatters  = field_info_formatter_types();

  $types['field_property'] = array(
    'name'        => t('Field properties'),
    'description' => t(''),
    'needs-data'  => 'field_property',
  );

  $tokens['field_property']['?'] = array(
    'name'        => t('Property name'),
    'description' => t('A property of the specified field; Replace \'?\' with a valid property for the specified field (e.g., value).'),
  );

  // Build token types for each field type.
  foreach ($field_types as $field_type_name => $field_type_info) {
    $types["formatted_field-{$field_type_name}"] = array(
      'name'        => t('Formatted @label field', array('@label' => $field_type_info['label'])),
      'description' => t('Tokens related to Formatted @label fields.', array('@label' => $field_type_info['label'])),
      'needs-data'  => "formatted_field-{$field_type_name}",
    );

    // Build tokens for each formatter of the current field type.
    foreach ($formatters as $formatter_name => $formatter_info) {
      if (in_array($field_type_name, $formatter_info['field types'])) {
        $tokens["formatted_field-{$field_type_name}"]["{$formatter_name}"] = array(
          'name'        => $formatter_info['label'],
          'description' => t('@label formatter.', array('@label' => $formatter_info['label'])) . ' ',
          'dynamic'     => TRUE,
        );

        // Adjust token name and description if formatter has no settings.
        if (empty($formatter_info['settings'])) {
          $tokens["formatted_field-{$field_type_name}"]["{$formatter_name}"]['description'] .= t('Has no settings.');
          unset($tokens["formatted_field-{$field_type_name}"]["{$formatter_name}"]['dynamic']);
        }

        // Append settings list to description.
        else {
          $settings = array();
          foreach ($formatter_info['settings'] as $key => $default) {
            $settings[] = $key;
          }
          $tokens["formatted_field-{$field_type_name}"]["{$formatter_name}"]['description'] .= t('Replace \'?\' with formatter settings in the following format: \'SETTING-VALUE:SETTING-VALUE-...\'.<br /> Available settings: @settings', array('@settings' => implode(', ', $settings)));
        }
      }
    }
  }

  return array(
    'types'  => $types,
    'tokens' => $tokens,
  );
}

/**
 * Implements hook_token_info_alter().
 */
function field_tokens_token_info_alter(&$data) {
  $token_info = _token_field_info();

  foreach ($token_info as $field_name => $info) {
    $field = field_info_field($field_name);
    foreach ($info['token types'] as $token_type) {
      if (isset($data['tokens'][$token_type])) {
        // Formatted field tokens.
        $data['tokens'][$token_type]["{$field_name}-formatted"] = array(
          'name'        => t('@label: Formatted field', array('@label' => $info['label'])),
          'description' => t('The formatted value of one or more @label field values. Replace \'?\' with a comma seperated list of deltas (e.g., \'0,1\').', array('@label' => $info['label'])),
          'type'        => "formatted_field-{$field['type']}",
          'dynamic'     => TRUE,
        );

        // Field property tokens.
        $data['tokens'][$token_type]["{$field_name}-property"] = array(
          'name'        => t('@label: Field properties', array('@label' => $info['label'])),
          'description' => t('Field properties from one or more @label field values. Replace \'?\' with a comma seperated list of deltas (e.g., \'0,1\').', array('@label' => $info['label'])),
          'type'        => 'field_property',
          'dynamic'     => TRUE,
        );
      }
    }
  }
}

/**
 * Implements hook_tokens().
 */
function field_tokens_tokens($type, $tokens, array $data = array(), array $options = array()) {
  $url_options   = array('absolute' => TRUE);
  $language_code = NULL;
  if (isset($options['language'])) {
    $url_options['language'] = $options['language'];
    $language_code           = $options['language']->language;
  }
  $sanitize = !empty($options['sanitize']);

  $token_info   = _token_field_info();
  $replacements = array();

  $token_types = array(
    'formatted' => array(
      'token_type' => 'formatted_field',
      'field_type' => TRUE
    ),
    'property'  => array(
      'token_type' => 'field_property',
      'field_type' => FALSE
    ),
  );

  // Entity tokens.
  if ($type == 'entity' && !empty($data['entity'])) {
    $entity      = $data['entity'];
    $entity_type = $data['entity_type'];
    list($id, $vid, $bundle_name) = entity_extract_ids($entity_type, $data['entity']);
    $instances = field_info_instances($entity_type, $bundle_name);

    foreach ($token_info as $field_name => $token_field_info) {
      if (isset($instances[$field_name])) {
        $instance = $instances[$field_name];
        foreach ($token_types as $token_type => $token_type_info) {
          $field_tokens = token_find_with_prefix($tokens, "{$field_name}-{$token_type}");
          if ($field_tokens) {
            $field           = field_info_field($field_name);
            $langcode        = field_language($entity_type, $entity, $field_name);
            $token_data_type = $token_type_info['field_type'] ? "{$token_type_info['token_type']}-{$field['type']}" : $token_type_info['token_type'];
            foreach ($field_tokens as $name => $original) {
              $items = field_get_items($entity_type, $entity, $field_name);
              if (!empty($items)) {
                $parts  = explode(':', $name);
                $deltas = explode(',', array_shift($parts));

                $diff = array_diff(array_values($deltas), array_keys($items));
                if (empty($diff)) {
                  $token_items = array();
                  foreach ($deltas as $delta) {
                    $token_items[] = $items[$delta];
                  }

                  // Invoke MODULE_field_load().
                  $function = "{$field['module']}_field_load";
                  if (function_exists($function)) {
                    $items = array($token_items);
                    $function($entity_type, array($entity), $field, array($instance), $langcode, $items, FIELD_LOAD_CURRENT);
                    $token_items = $items[0];
                  }

                  // Invoke MODULE_field_is_empty().
                  foreach ($token_items as $item) {
                    $function = "{$field['module']}_field_is_empty";
                    if ((function_exists($function) && $function($item, $field))) {
                      continue(2);
                    }
                  }

                  // Pass through to chained field tokens.
                  $chained_data = $data + array(
                      $token_data_type => $token_items,
                      'field_name'     => $field_name
                    );
                  $replacements += token_generate($token_data_type, array(implode(':', $parts) => $original), $chained_data, $options);
                }
              }
            }
          }
        }
      }
    }
  }

  // Formatted field tokens.
  elseif (strpos($type, 'formatted_field') === 0 && isset($data[$type]) && isset($data['entity_type']) && isset($data['entity'])) {
    list(, $field_type) = explode('-', $type);
    $entity_type = $data['entity_type'];
    $entity      = $data['entity'];
    $entity_info = entity_get_info($entity_type);
    $field_name  = $data['field_name'];
    $field       = field_info_field_types($field_type);
    list($id, $vid, $bundle_name) = entity_extract_ids($entity_type, $entity);
    $instance   = field_info_instance($entity_type, $field_name, $bundle_name);
    $display    = $instance['display']['default'];
    $langcode   = field_language($entity_type, $entity, $field_name);
    $items      = $data[$type];
    $formatters = field_info_formatter_types();

    foreach ($tokens as $args => $original) {
      $args = explode(':', $args);
      if (empty($args[0])) {
        $formatter          = $field['default_formatter'];
        $formatter_settings = array();
      }
      else {
        $formatter          = array_shift($args);
        $formatter_settings = array();
        foreach ($args as $formatter_setting) {
          list($name, $value) = explode('-', $formatter_setting);
          $formatter_settings[$name] = $value;
        }
      }

      if (!is_null($formatter) && isset($formatters[$formatter]) && in_array($field_type, $formatters[$formatter]['field types'])) {
        if (!empty($formatters[$formatter]['settings'])) {
          $formatter_settings += $formatters[$formatter]['settings'];
        }

        // Inject formatter and formatter settings into $display.
        $display['type']     = $formatter;
        $display['settings'] = isset($formatter_settings) ? $formatter_settings : $formatters[$formatter]['settings'];

        // Clone entity, adjust state and attach specified items.
        $cloned_entity = clone $entity;
        unset($cloned_entity->_field_view_prepared);
        $cloned_entity->_field_tokens            = TRUE;
        $cloned_entity->{$field_name}[$langcode] = $items;

        $output = '';
        field_attach_prepare_view($entity_type, array($cloned_entity->{$entity_info['entity keys']['id']} => $cloned_entity), 'full');
        $element = field_view_field($entity_type, $cloned_entity, $field_name, $display, $langcode);
        if ($element) {
          foreach (element_children($element) as $delta) {
            $output .= render($element[$delta]);
          }
        }
        if (!empty($output)) {
          $replacements[$original] = $output;
        }
      }
    }
  }

  // Field property tokens.
  elseif ($type == 'field_property') {
    foreach ($tokens as $args => $original) {
      $output = array();

      $args     = explode(':', $args);
      $property = array_shift($args);
      foreach ($data['field_property'] as $item) {
        if (isset($item[$property])) {
          $output[] = $item[$property];
        }
      }

      if (!empty($output)) {
        $replacements[$original] = implode(', ', $output);
      }
    }
  }

  return $replacements;
}
