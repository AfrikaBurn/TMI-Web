<?php
/**
 * @file layout.inc a place to store hook implementations to make layouts "live-themer enabled".
 */

/**
 * Implementation of our "psuedo hook" hook_lt_themable().
 */
function page_layouts_lt_themable() {
  return array(
    'title' => t('Page Layouts'),
    'description' => t('Change page layout.'),
    'type' => 'page-layouts',
    'hook' => 'page',
    '#weight' => 1,
    '#css_weight' => 0,
  );
}

/**
 * Implementation of _settings_form().
 */
function page_layouts_settings_form() {
  $form = array();
  
  $form['dimensions'] = dimension_presets();
  unset($form['dimensions']['size']);

  return $form;
}

