<?php
/**
 * @file tabs.inc a place to store hook implementations to make tabs "live-themer enabled".
 */

/**
 * Implementation of our "psuedo hook" hook_lt_themable().
 */
function tab_designs_lt_themable() {
  return array(
    'title' => t('Designs'),
    'description' => t('Change tab design.'),
    'type' => 'tab-designs',
    'hook' => 'menu_local_tasks',
    '#weight' => 1,
    '#css_weight' => 5,
  );
}

/**
 * Implementation of _settings_form().
 */
function tab_designs_settings_form() {
  $form = array();
  
  return $form;
}
