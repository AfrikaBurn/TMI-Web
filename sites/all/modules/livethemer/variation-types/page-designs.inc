<?php
/**
 * @file layout.inc a place to store hook implementations to make layouts "live-themer enabled".
 */

/**
 * Implementation of our "psuedo hook" hook_lt_themable().
 */
function page_designs_lt_themable() {
  return array(
    'title' => t('Page Designs'),
    'description' => t('Change page design.'),
    'type' => 'page-designs',
    'hook' => 'page',
    '#weight' => 1,
    '#css_weight' => 0,
  );
}

/**
 * Implementation of _settings_form().
 */
function page_designs_settings_form() {
  $form = array();
  
  $form['backgrounds'] = background_presets();
  $form['borders'] = border_presets();

  return $form;
}

