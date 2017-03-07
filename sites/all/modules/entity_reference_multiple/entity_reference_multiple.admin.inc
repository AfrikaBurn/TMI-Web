<?php

/**
 * @file
 * Administration related functionality for the module.
 */

/**
 * Form builder for the entities short codes settings.
 *
 * @see entity_reference_multiple_settings_form_validate()
 * @see entity_reference_multiple_settings_form_submit()
 * @ingroup forms
 */
function entity_reference_multiple_settings_form($form, $form_state) {
  $short_codes = variable_get('entity_reference_multiple:short-codes', array());

  foreach (entity_get_info() as $entity_type => $entity_info) {
    $form[$entity_type] = array(
      '#type' => 'fieldset',
      '#title' => $entity_info['label'],
      '#tree' => TRUE,
    );

    $form[$entity_type]['conf'] = array(
      '#theme' => 'entity_reference_multiple_short_codes_settings_table',
    );

    foreach ($entity_info['bundles'] as $bundle => $bundle_info) {
      $form[$entity_type]['conf'][$bundle]['label'] = array(
        '#markup' => $bundle_info['label'],
      );

      $form[$entity_type]['conf'][$bundle]['bundle'] = array(
        '#markup' => $bundle,
      );

      $form[$entity_type]['conf'][$bundle]['short_code'] = array(
        '#type' => 'textfield',
        '#title' => t('Short code'),
        '#title_display' => 'invisible',
        '#default_value' => isset($short_codes[$entity_type][$bundle]) ? $short_codes[$entity_type][$bundle] : '',
        '#size' => 10,
      );
    }
  }

  $form['actions'] = array('#type' => 'actions');

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save configuration'),
  );

  return $form;
}

/**
 * Form validation handler for entity_reference_multiple_settings_form().
 *
 * @see entity_reference_multiple_settings_form()
 * @see entity_reference_multiple_settings_form_submit()
 */
function entity_reference_multiple_settings_form_validate($form, &$form_state) {
  foreach (entity_get_info() as $entity_type => $entity_info) {
    if (!empty($form_state['values'][$entity_type])) {
      $short_codes = array();
      foreach ($form_state['values'][$entity_type]['conf'] as $bundle => $conf) {
        if (!empty($conf['short_code'])) {
          if (in_array($conf['short_code'], $short_codes)) {
            $parents = array($entity_type, 'conf', $bundle, 'short_code');
            form_set_error(implode('][', $parents), t('Short code must be unique.'));
          }
          $short_codes[] = $conf['short_code'];
        }
      }
    }
  }
}

/**
 * Form validation handler for entity_reference_multiple_settings_form().
 *
 * @see entity_reference_multiple_settings_form()
 * @see entity_reference_multiple_settings_form_validate()
 */
function entity_reference_multiple_settings_form_submit($form, &$form_state) {
  // Exclude unnecessary elements.
  form_state_values_clean($form_state);

  $short_codes = array();
  foreach ($form_state['values'] as $entity_type => $conf) {
    $short_codes[$entity_type] = array();
    foreach ($conf['conf'] as $bundle => $value) {
      $short_codes[$entity_type][$bundle] = $value['short_code'];
    }
  }

  variable_set('entity_reference_multiple:short-codes', $short_codes);
  drupal_set_message(t('The configuration options have been saved.'));
}
