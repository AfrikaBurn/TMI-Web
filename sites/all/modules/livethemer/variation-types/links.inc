<?php
/**
 * @file topography.inc a place to store hook implementations to make topography "live-themer enabled".
 */

/**
 * Implementation of our "psuedo hook" hook_lt_themable().
 */
function links_lt_themable() {
 return array(
   'title' => t('Links'),
   'description' => t('Change links.'),
   'type' => 'links',
   'hook' => array('block'),
   '#weight' => 6,
   '#css_weight' => 7,
   );
}

/**
 * Implementation of _settings_form().
 */
function links_settings_form() {
  $form = array();
  
  $form['backgrounds'] = background_presets();
  $form['borders'] = border_presets();
  $form['dimensions'] = dimension_presets();
  $form['fonts'] = font_presets();

  // Rearrange the form so that visted/hover/active are all in the one fieldset.
  $form['links'] = array(
    '#type' => 'fieldset',
    '#title' => 'Links',
    'links' => form_presets('wrapper'),
    'hover' => form_presets('wrapper'),
    'visited' => form_presets('wrapper'),
    'active' => form_presets('wrapper'),
  );
  
  $form['links']['links'] = array_merge($form['links']['links'], $form['fonts']['links']);
  $form['links']['links']['#type'] = 'item';
  $form['links']['links']['#title'] = 'Default';

  $form['links']['hover'] = array_merge($form['links']['hover'], $form['fonts']['links_hover']);
  $form['links']['hover']['#type'] = 'item';
  $form['links']['hover']['#title'] = 'Hover';
  
  $form['links']['visited'] = array_merge($form['links']['visited'], $form['fonts']['links_visited']);
  $form['links']['visited']['#type'] = 'item';
  $form['links']['visited']['#title'] = 'Visited';

  $form['links']['active'] = array_merge($form['links']['active'], $form['fonts']['links_active']);
  $form['links']['active']['#type'] = 'item';
  $form['links']['active']['#title'] = 'Active';

  // Turn off everything else that we don't want from the fonts fieldset.
  unset($form['fonts']);

  return $form;
}

