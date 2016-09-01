<?php
/**
 * @file
 * Implementation of variation_id_settings_form().
 */
function starter_html_design_settings_form($form) {
  $form['background']['background_color']['#default_value'] = '#DFDFDF';
  return $form;
}
