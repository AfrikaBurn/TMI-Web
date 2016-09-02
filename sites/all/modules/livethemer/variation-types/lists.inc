<?php
/**
 * @file topography.inc a place to store hook implementations to make topography "live-themer enabled".
 */

/**
 * Implementation of our "psuedo hook" hook_lt_themable().
 */
function lists_lt_themable() {
  return array(
    'title' => t('Lists'),
    'description' => t('Change block lists.'),
    'type' => 'lists',
    'hook' => 'block',
    '#weight' => 2,
    '#css_weight' => 7,
  );
}

/**
 * Implementation of _settings_form().
 */
function lists_settings_form() {
  $form = array();
  $form['backgrounds'] = background_presets();
  $form['borders'] = border_presets();
  $form['uldimensions'] = dimension_reused( 'UL dimensions', 'ul, ul.menu, div.item-list ul, ul.links', 'ul');
  $form['lidimensions'] = dimension_reused( 'LI dimensions', 'li, ul.menu li, div.item-list ul li, ul.links li', 'li');
  $form['fonts'] = font_reused( 'Fonts', 'ul', 'ul');
  
  return $form;
}
