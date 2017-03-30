<?php
/**
 * @file block.inc a place to store hook implementations to make blocks "live-themer enabled".
 */

/**
 * Implementation of our "psuedo hook" hook_lt_themable().
 */
function image_designs_lt_themable() {
  return array(
    'title' => t('Image Designs'),
    'description' => t('Change image design.'),
    'type' => 'image-designs',
    'hook' => array('block'),
    '#weight' => 1,
    '#css_weight' => 7,
  );
}

/**
 * Implementation of _settings_form().
 */
function image_designs_settings_form() {
  $overrides = array('#attributes' => array('css_target' => 'img'));
  $form = array();
  $form['backgrounds'] = background_presets($overrides);
  $form['borders'] = border_presets($overrides);
  $form['dimensions'] = dimension_presets($overrides);
  //$form['fonts'] = font_presets($overrides);
  
  return $form;
}
