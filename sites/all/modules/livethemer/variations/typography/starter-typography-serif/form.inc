<?php
/**
 * Implementation of variation_id_settings_form().
 */
function starter_typography_serif_settings_form($form) {
  // Body.
  $form['body']['body_font_size']['#default_value'] = 14;
  $form['body']['body_font_color']['#default_value'] = '#111111';
  $form['body']['body_line_height']['#default_value'] = '161.8';
  
  // Headings.
  $form['h1']['h1_font_size']['#default_value'] = 59;
  $form['h1']['h1_line_height']['#default_value'] = 118;

  $form['h2']['h2_font_size']['#default_value'] = 37;
  $form['h2']['h2_line_height']['#default_value'] = 119;

  $form['h3']['h3_font_size']['#default_value'] = 23;
  $form['h3']['h3_line_height']['#default_value'] = 124;

  $form['h4']['h4_font_size']['#default_value'] = 18;
  $form['h4']['h4_line_height']['#default_value'] = 123;

  $form['h5']['h5_font_size']['#default_value'] = 16;
  $form['h5']['h5_line_height']['#default_value'] = 130;

  $form['h6']['h6_font_size']['#default_value'] = 16;
  $form['h6']['h6_line_height']['#default_value'] = 130;
  
  return $form;
}
