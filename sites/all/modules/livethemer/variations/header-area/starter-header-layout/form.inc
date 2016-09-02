<?php
/**
 * @file
 * Implementation of variation_id_settings_form().
 */
function starter_header_layout_settings_form($form) { 
  $form['header_dimensions']['size']['height']['#default_value'] = 150;
  
  $form['logo']['position']['logo_position']['#default_value'] = 'position:absolute;';
  $form['logo']['position']['logo_position_top']['#default_value'] = 10;
  $form['logo']['position']['logo_position_left']['#default_value'] = 10;
  
  $form['site_name']['position']['sitename_position']['#default_value'] = 'position:absolute;';
  $form['site_name']['position']['sitename_position_top']['#default_value'] = 10; 
  $form['site_name']['position']['sitename_position_left']['#default_value'] = 150; 
  
  $form['site_name']['font']['sitename_text_decoration']['#default_value'] = 'none'; 
  return $form;
}
