<?php
/**
 * @file topography.inc a place to store hook implementations to make topography "live-themer enabled".
 */

/**
 * Implementation of our "psuedo hook" hook_lt_themable().
 */
function region_designs_lt_themable() {
 return array(
   'title' => t('Designs'),
   'description' => t('Style regions.'),
   'type' => 'region-designs',
   'hook' => array('region'),
   '#weight' => 6,
   '#css_weight' => 3,
   );
}

/**
 * Implementation of _settings_form().
 */
function region_designs_settings_form() {
  $form = array();
  
  $form['bg'] = background_presets();
  $form['dimensions'] = dimension_presets();
  $form['borders'] = border_presets();
  
  return $form;
}

