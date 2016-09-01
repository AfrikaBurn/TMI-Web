<?php

/**
 * @file
 * Hooks provided by Math Field.
 */

/**
 * Get the jQuery selector and event to trigger the evaluation of a mathfield.
 *
 * This hook is invoked on the module that defines the tokens' field type. To
 * change the token info for a field defined in a different module, use
 * hook_mathfield_get_token_alter() or hook_mathfield_get_token_MODULE_alter().
 *
 * @param array $context
 *   An associative array with the following keys:
 *   - 'field_name': The machine name of the token field.
 *   - 'delta': The delta value of the token field for multivalue fields.
 *              Default is 0.
 *   - 'column': The source column of the token field. Default is 'value'.
 *   - 'token': The token used in the math expression.
 *   - 'field': The field definition of the token field.
 *   - 'instance': The field instance definition of the token field.
 *   - 'element': The mathfield form element.
 *
 * @return array
 *   An associative array with the following keys:
 *   - 'selector': The jQuery selector for the form element that will tirgger
 *                 the mathfield evaluation.
 *   - 'event': The jQuery event that will trigger the mathfield evaluation.
 *              Typically, blur of text input and change for select lists and
 *              radios/checkboxes.
 */
function hook_mathfield_get_token($context) {
  $field_name = $context['field']['field_name'];
  $name = strtr('@field_name[@parts]', array(
    '@field_name' => $field_name,
    '@parts' => implode('][', array(
       $context['element']['#language'],
       $context['delta'],
       $context['column'],
    )),
  ));
  return array(
    'selector' => 'input[name="' . $name . '"]',
    'event' => 'blur',
  );
}

/**
 * Alter the jQuery selector and event for triggering a mathfield.
 *
 * This hook allows other modules to change the jQuery selector or event
 * for a field type defined in other modules. The source module may be found
 * in $context['field']['module'].
 *
 * @param array $data
 *   The current token data. An assoicative array with the following keys:
 *   - 'selector': The jQuery selector for the form element that will tirgger
 *                 the mathfield evaluation.
 *   - 'event': The jQuery event that will trigger the mathfield evaluation.
 *              Typically, blur of text input and change for select lists and
 *              radios/checkboxes.
 * @param array $context
 *   An associative array with the following keys:
 *   - 'field_name': The machine name of the token field.
 *   - 'delta': The delta value of the token field for multivalue fields.
 *              Default is 0.
 *   - 'column': The source column of the token field. Default is 'value'.
 *   - 'token': The token used in the math expression.
 *   - 'field': The field definition of the token field.
 *   - 'instance': The field instance definition of the token field.
 *   - 'element': The mathfield form element.
 */
function hook_mathfield_get_token_alter(&$data, $context) {
  if (empty($data)) {
    $field_name = $context['field']['field_name'];
    $name = strtr('@field_name[@parts]', array(
      '@field_name' => $field_name,
      '@parts' => implode('][', array(
         $context['element']['#language'],
         $context['delta'],
         $context['column'],
      )),
    ));
    $data = array(
      'selector' => 'input[name="' . $name . '"]',
      'event' => 'blur',
    );
  }
}

/**
 * Alter the jQuery selector and event for triggering a mathfield for a module.
 *
 * This hook allows other modules to change the jQuery selector or event
 * for a field type defined in the module MODULE.
 *
 * @param array $data
 *   The current token data. An assoicative array with the following keys:
 *   - 'selector': The jQuery selector for the form element that will tirgger
 *                 the mathfield evaluation.
 *   - 'event': The jQuery event that will trigger the mathfield evaluation.
 *              Typically, blur of text input and change for select lists and
 *              radios/checkboxes.
 * @param array $context
 *   An associative array with the following keys:
 *   - 'field_name': The machine name of the token field.
 *   - 'delta': The delta value of the token field for multivalue fields.
 *              Default is 0.
 *   - 'column': The source column of the token field. Default is 'value'.
 *   - 'token': The token used in the math expression.
 *   - 'field': The field definition of the token field.
 *   - 'instance': The field instance definition of the token field.
 *   - 'element': The mathfield form element.
 */
function hook_mathfield_get_token_MODULE_alter(&$data, $context) {
  if (empty($data)) {
    $field_name = $context['field']['field_name'];
    $name = strtr('@field_name[@parts]', array(
      '@field_name' => $field_name,
      '@parts' => implode('][', array(
         $context['element']['#language'],
         $context['delta'],
         $context['column'],
      )),
    ));
    $data = array(
      'selector' => 'input[name="' . $name . '"]',
      'event' => 'blur',
    );
  }
}

/**
 * Get the value of a field token for use in a math expression.
 *
 * This hook is invoked on the module that defines the token's field type. To
 * change the valuefor a field defined in a different module, use
 * hook_mathfield_get_token_value alter() or
 * hook_mathfield_get_token_value_MODULE_alter().
 *
 * @param array $context
 *   An associative array with the following keys:
 *   - 'field_name': The machine name of the token field.
 *   - 'delta': The delta value of the token field for multivalue fields.
 *              Default is 0.
 *   - 'column': The source column of the token field. Default is 'value'.
 *   - 'token': The token used in the math expression.
 *   - 'field': The field definition of the token field.
 *   - 'instance': The field instance definition of the token field.
 *   - 'element': The mathfield form element.
 *   - 'form_state' The entire form_state array including submitted values.
 *                  The token value is usually extracted from
 *                  $context['form_state']['values'].
 *
 * @return int|float|bool
 *   This hook should return a numeric value to replace the token in the math
 *   expression or FALSE if the value could not be determined.
 */
function hook_mathfield_get_token_value($context) {
  $values = $context['form_state']['values'];
  $field_name = $context['field_name'];
  $language = $context['element']['#language'];
  $delta = $context['delta'];
  $column = $context['column'];

  if (isset($values[$field_name][$language][$delta][$column]) && is_numeric($values[$field_name][$language][$delta][$column])) {
    return $values[$field_name][$language][$delta][$column];
  }
  return FALSE;
}

/**
 * Alter the value of a field token for use in a math expression.
 *
 * This hook allows other modules to change the replacement value of a token
 * for a field type defined in other modules. The source module may be found
 * in $context['field']['module'].
 *
 * @param int|float|bool $value
 *   The current numeric value of the field or FALSE.
 * @param array $context
 *   An associative array with the following keys:
 *   - 'field_name': The machine name of the token field.
 *   - 'delta': The delta value of the token field for multivalue fields.
 *              Default is 0.
 *   - 'column': The source column of the token field. Default is 'value'.
 *   - 'token': The token used in the math expression.
 *   - 'field': The field definition of the token field.
 *   - 'instance': The field instance definition of the token field.
 *   - 'element': The mathfield form element.
 *   - 'form_state' The entire form_state array including submitted values.
 *                  The token value is usually extracted from
 *                  $context['form_state']['values'].
 */
function hook_mathfield_get_token_value_alter(&$value, $context) {
  $values = $context['form_state']['values'];
  $field_name = $context['field_name'];
  $language = $context['element']['#language'];
  $delta = $context['delta'];
  $column = $context['column'];

  if (isset($values[$field_name][$language][$delta][$column]) && is_numeric($values[$field_name][$language][$delta][$column])) {
    $value = $values[$field_name][$language][$delta][$column];
  }
}

/**
 * Alter the value of a field token of a module for use in a math expression.
 *
 * This hook allows other modules to change the replacement value of a token
 * for a field type defined in the module MODULE.
 *
 * @param int|float|bool $value
 *   The current numeric value of the field or FALSE.
 * @param array $context
 *   An associative array with the following keys:
 *   - 'field_name': The machine name of the token field.
 *   - 'delta': The delta value of the token field for multivalue fields.
 *              Default is 0.
 *   - 'column': The source column of the token field. Default is 'value'.
 *   - 'token': The token used in the math expression.
 *   - 'field': The field definition of the token field.
 *   - 'instance': The field instance definition of the token field.
 *   - 'element': The mathfield form element.
 *   - 'form_state' The entire form_state array including submitted values.
 *                  The token value is usually extracted from
 *                  $context['form_state']['values'].
 */
function hook_mathfield_get_token_value_MODULE_alter(&$value, $context) {
  $values = $context['form_state']['values'];
  $field_name = $context['field_name'];
  $language = $context['element']['#language'];
  $delta = $context['delta'];
  $column = $context['column'];

  if (isset($values[$field_name][$language][$delta][$column]) && is_numeric($values[$field_name][$language][$delta][$column])) {
    $value = $values[$field_name][$language][$delta][$column];
  }
}
