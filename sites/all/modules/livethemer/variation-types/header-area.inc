<?php
/**
 * @file region-region.inc a place to store hook implementations to make region regions "live-themer enabled".
 */

/**
 * Implementation of our "psuedo hook" hook_lt_themable().
 */
function header_area_lt_themable() {
  return array(
    'title' => t('Header Area'),
    'description' => t('Change the Header Area (styling for site name, slogan etc).'),
    'type' => 'header-area',
    'hook' => 'page',
    '#weight' => 5,
    '#css_weight' => 2,
  );
}

/**
 * Implementation of _settings_form().
 */
function header_area_settings_form() {
  $form = array();

  $overrides = array('#attributes' => array('css_target' => '#header'));
  $form['header_backgrounds'] = background_presets($overrides);
  $form['header_backgrounds']['#weight'] = '0';
  
  $form['header_borders'] = border_presets($overrides);
  $form['header_borders']['#weight'] = '1';
  
  $form['header_dimensions'] = dimension_presets($overrides);
  $form['header_dimensions']['#title'] = 'Dimensions';
  $form['header_dimensions']['#description'] = 'Please note: you need to set a height on your header to prevent it from collapsing when elements inside it are positioned.';
  $form['header_dimensions']['#weight'] = '2';
   
  $form['logo'] = form_presets('fieldset', array('#title' => 'Logo', '#collapsed' => TRUE)); 
  $form['logo']['position'] = position_reused('Position', '#logo', 'logo', 'wrapper');

  $form['logo']['position']['logo_position'] = form_presets('position_yes_no', array('#attributes' => array('css_rule' => '%logo_position%',  'css_target' => '#logo')));
  $form['logo']['#weight'] = '3';
  
  $form['site_name'] = form_presets('fieldset', array('#title' => 'Site Name', '#collapsed' => TRUE)); 
  $form['site_name']['font'] = font_reused('Font', '#site-name a, #site-name', 'sitename', 'wrapper'); 
  $form['site_name']['position'] = position_reused('Position', '#site-name', 'sitename', 'wrapper');
  $form['site_name']['position']['sitename_position'] = form_presets('position_yes_no', array('#attributes' => array('css_rule' => '%sitename_position%',  'css_target' => '#site-name')));
  $form['site_name']['#weight'] = '4';
  
  $form['site_slogan'] = form_presets('fieldset', array('#title' => 'Site Slogan', '#collapsed' => TRUE)); 
  $form['site_slogan']['font'] = font_reused('Font', '#site-slogan', 'slogan', 'wrapper'); 
  $form['site_slogan']['position'] = position_reused('Position', '#site-slogan', 'slogan', 'wrapper');
  $form['site_slogan']['position']['slogan_position'] = form_presets('position_yes_no', array('#attributes' => array('css_rule' => '%slogan_position%',  'css_target' => '#site-slogan')));
  
  $form['site_slogan']['#weight'] = '5';

  return $form;
}
