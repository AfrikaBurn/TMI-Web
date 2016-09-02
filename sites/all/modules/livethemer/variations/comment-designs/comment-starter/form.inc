<?php
/**
 * @file
 * Implementation of variation_id_settings_form().
 */
function comment_starter_settings_form($form) {
  // Border presets.
  $form['borders']['border_color']['#default_value'] = '#666';
  $form['borders']['border_style']['#default_value'] = 'solid';
  $form['borders']['border_width']['#default_value'] = 'thin';
  $form['borders']['corner_radius']['#default_value'] = '10';
  
  // Drop shadow presets.
  $form['borders']['shadow_wrapper']['shadow']['shadow_color']['#default_value'] = '#CCC';
  $form['borders']['shadow_wrapper']['shadow']['blur']['#default_value'] = '5';
  $form['borders']['shadow_wrapper']['shadow']['hor_offset']['#default_value'] = '0';
  $form['borders']['shadow_wrapper']['shadow']['ver_offset']['#default_value'] = '0';
  
  // Dimension presets.
  $form['dimensions']['padding']['padding']['#default_value'] = '10';
  //$form['dimensions']['margin']['margin']['#default_value'] = '10';
  
  // User pic presets.
  $form['user_pic']['margin']['sides']['user_pic_dimentions_margin_right']['#default_value'] = '20';
  $form['user_pic']['margin']['sides']['user_pic_dimentions_margin_bottom']['#default_value'] = '10';
  return $form;
}