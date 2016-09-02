<?php
/**
 * @file
 * Implementation of variation_id_settings_form().
 */
function starter_page_settings_form($form) {

  $form['backgrounds']['background_color']['#default_value'] = '#FFF';
 
  $form['borders']['shadow_wrapper']['shadow']['shadow_color']['#default_value'] = '#000';
  $form['borders']['shadow_wrapper']['shadow']['hor_offset']['#default_value'] = '0'; 
  $form['borders']['shadow_wrapper']['shadow']['ver_offset']['#default_value'] = '0';
  $form['borders']['shadow_wrapper']['shadow']['blur']['#default_value'] = '15';

  return $form;
}
