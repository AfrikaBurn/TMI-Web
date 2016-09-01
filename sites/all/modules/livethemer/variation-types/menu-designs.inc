<?php
/**
 * @file menu.inc a place to store hook implementations to make menus "live-themer enabled".
 */

/**
 * Implementation of our "psuedo hook" hook_lt_themable().
 */
function menu_lt_themable() {
 return array(
   'title' => t('Menu'),
   'description' => t('Change menu styles.'),
   'type' => 'menu',
   'hook' => 'block',
   '#weight' => 6,
   '#css_weight' => 7,
   );
}

/**
 * Implementation of _settings_form().
 */
function menu_settings_form() {
  $form = array();
  
  return $form;
}