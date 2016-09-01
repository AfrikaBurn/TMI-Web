<?php
/**
 * @file block.inc a place to store hook implementations to make blocks "live-themer enabled".
 */

/**
 * Implementation of our "psuedo hook" hook_lt_themable().
 */
function block_designs_lt_themable() {
  return array(
    'title' => t('Block Designs'),
    'description' => t('Change block design.'),
    'type' => 'block-designs',
    'hook' => 'block',
    '#weight' => 1,
    '#css_weight' => 9,
  );
}

/**
 * Implementation of _settings_form().
 */
function block_designs_settings_form() {
  $form = array();
  $form['backgrounds'] = background_presets();
  $form['borders'] = border_presets();
  $form['dimensions'] = dimension_presets();
  $form['fonts'] = form_presets('fieldset', array(
    '#title' => t('Fonts'),
    '#collapsed' => TRUE,
    '#weight' => 2,
  ));
  $form['fonts']['title'] = font_reused( 'Title', 'h2', 'h2');
  $form['fonts']['title']['#weight'] = 2;
  $form['fonts']['content'] = font_reused('Body', '.content', 'content');
  $form['fonts']['content']['#weight'] = 3;
  
  return $form;
}
