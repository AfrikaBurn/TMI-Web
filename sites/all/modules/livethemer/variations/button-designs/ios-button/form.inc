<?php
/**
 * @file
 * Implementation of variation_id_settings_form().
 */
function ios_button_settings_form($form) {
  $form['font'] = form_presets('fieldset', array('#title' => t('Font settings')));

  $form['font']['font_size']   = form_presets('font_size');
  $form['font']['line_height'] = form_presets('line_height');
  $form['font']['font_style']  = form_presets('font_style');

  return $form;
}
