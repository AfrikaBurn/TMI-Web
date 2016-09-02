<?php
/**
 * @file block.inc a place to store hook implementations to make blocks "live-themer enabled".
 */

/**
 * Implementation of our "psuedo hook" hook_lt_themable().
 */
function pager_designs_lt_themable() {
  return array(
    'title' => t('Pager Designs'),
    'description' => t('Change pager design.'),
    'type' => 'pager-designs',
    'hook' => 'pager',
    '#weight' => 0,
    '#css_weight' => 9,
  );
}

/**
 * Implementation of _settings_form().
 */
function pager_designs_settings_form() {
  $form = array();
  
  return $form;
}
