<?php
/**
 * @file
 * Implementation of variation_id_settings_form().
 */
function starter_links_settings_form($form) {
  $form['links']['links']['link_font_color']['#default_value'] = '#1764e8';
  $form['links']['links']['link_text_decoration']['#default_value'] = 'none';
  $form['links']['hover']['hover_font_color']['#default_value'] = '#002e75';
  $form['links']['hover']['hover_text_decoration']['#default_value'] = 'underline';
  $form['links']['visited']['visited_font_color']['#default_value'] = '#a6c2ed';
  $form['links']['active']['active_font_color']['#default_value'] = '#005eff';
  
  return $form;
}
