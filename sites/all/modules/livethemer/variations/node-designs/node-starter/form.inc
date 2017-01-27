<?php
/**
 * @file form.inc
 * Implementation of variation_id_settings_form().
 */
function node_starter_settings_form($form) {
  // ---- Full dispaly ---- ///
  $prefix = 'full_display';
  
  // Padding presets.
  $form['full']['dimensions']['padding'][$prefix . '_dimensions_padding']['#default_value'] = '10';
  
  // User pic presets.
  $form['full']['user_pic']['margin']['sides'][$prefix . '_user_pic_dimensions_margin_left']['#default_value'] = '20';
  $form['full']['user_pic']['margin']['sides'][$prefix . '_user_pic_dimensions_margin_bottom']['#default_value'] = '10';


  // ---- Teaser display ---- ///
  $prefix = 'teaser_display';

  // User pic presets.
  $form['teaser']['user_pic']['margin']['sides'][$prefix . '_user_pic_dimensions_margin_right']['#default_value'] = '20';
  $form['teaser']['user_pic']['margin']['sides'][$prefix . '_user_pic_dimensions_margin_bottom']['#default_value'] = '10';
  $form['teaser']['user_pic']['margin']['sides'][$prefix . '_user_pic_dimensions_margin_left']['#default_value'] = '0';

  $form['teaser']['dimensions']['margin']['sides'][$prefix . '_dimensions_margin_bottom']['#default_value'] = '20';

  return $form;
}