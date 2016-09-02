<?php
/**
 * @file
 * Implementation of variation_id_settings_form().
 */
function block_starter_settings_form($form) {
  $form['backgrounds']['background_color']['#default_value'] = '#DEDEDE';
 
  $form['borders']['border_color']['#default_value'] = '#666';
  $form['borders']['border_style']['#default_value'] = 'solid';
  $form['borders']['border_width']['#default_value'] = 'thin';
  $form['borders']['corner_radius']['#default_value'] = '10';
  
  $form['borders']['shadow_wrapper']['shadow']['shadow_color']['#default_value'] = '#CCC';
  $form['borders']['shadow_wrapper']['shadow']['blur']['#default_value'] = '5';
  $form['borders']['shadow_wrapper']['shadow']['hor_offset']['#default_value'] = '5';
  $form['borders']['shadow_wrapper']['shadow']['ver_offset']['#default_value'] = '5';
  
  $form['dimensions']['padding']['padding']['#default_value'] = '5';
  $form['dimensions']['margin']['margin']['#default_value'] = '5';
  
  return $form;
}