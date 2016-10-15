<?php
/**
 * @file layout.inc a place to store hook implementations to make layouts "live-themer enabled".
 */

/**
 * Implementation of our "psuedo hook" hook_lt_themable().
 */
function html_designs_lt_themable() {
  return array(
    'title' => t('Designs'),
    'description' => t('Change overall window design.'),
    'type' => 'html-designs',
    'hook' => 'html',
    '#weight' => 1,
    '#css_weight' => 1,
  );
}

/**
 * Implementation of _settings_form().
 */
function html_designs_settings_form() {
  $form['background'] = background_presets();
  $form['border'] = border_presets();
    
  return $form;
}

