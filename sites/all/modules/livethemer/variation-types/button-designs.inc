<?php
/**
 * @file button.inc a place to store hook implementations to make buttons "live-themer enabled".
 */

/**
 * Implementation of our "psuedo hook" hook_lt_themable().
 */
function button_designs_lt_themable() {
  return array(
    'title' => t('Designs'),
    'description' => t('Change button design.'),
    'type' => 'button-designs',
    'hook' => 'button',
    '#weight' => 1,
    '#css_weight' => 0,
  );
}

/**
 * Implementation of _settings_form().
 */
function button_designs_settings_form() {
  $form = array();
  $form['backgrounds'] = background_presets();
  $form['borders'] = border_presets();
  $form['dimensions'] = dimension_presets();
  //$form['fonts'] = font_presets();
  
  return $form;
}