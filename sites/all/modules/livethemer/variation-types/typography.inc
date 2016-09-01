<?php
/**
 * @file topography.inc a place to store hook implementations to make topography "live-themer enabled".
 */

/**
 * Implementation of our "psuedo hook" hook_lt_themable().
 */
function typography_lt_themable() {
 return array(
   'title' => t('Typography'),
   'description' => t('Change typography.'),
   'type' => 'typography',
   'hook' => 'page',
   '#weight' => 15,
   '#css_weight' => 2,
   );
}

/**
 * Implementation of _settings_form().
 *
 * We are unsetting all the font_family options because all typography variations
 * except "advanced typography" should mandate a specific font, in order to impose
 * good design practice. Also, many of the typography variations are called something
 * like "sans serif typography" which implies a specific 
 */
function typography_settings_form() {
  $form = array();
  $form['h1'] = font_reused( 'H1', 'h1', 'h1');
  unset($form['h1']['h1_font_family']);
  $form['h2'] = font_reused( 'H2', 'h2', 'h2');
  unset($form['h2']['h2_font_family']);
  $form['h3'] = font_reused( 'H3', 'h3', 'h3');
  unset($form['h3']['h3_font_family']);
  $form['h4'] = font_reused( 'H4', 'h4', 'h4');
  unset($form['h4']['h4_font_family']);
  $form['h5'] = font_reused( 'H5', 'h5', 'h5');
  unset($form['h5']['h5_font_family']);
  $form['h6'] = font_reused( 'H6', 'h6', 'h6');
  unset($form['h6']['h6_font_family']);
  $form['body'] = font_reused( 'Body', '.content', 'body');
  unset($form['body']['body_font_family']);
  $form['p'] = dimension_reused('Paragraph','p', 'p');
  
  unset($form['p']['size']);
  unset($form['p']['padding']);
  
  // We decided there was no need to allow users to adjust left and right margins.
  unset($form['p']['margin']['p_margin']);
  unset($form['p']['margin']['sides']['p_margin_left']);
  unset($form['p']['margin']['sides']['p_margin_right']);

  $form['p']['margin']['sides']['p_margin_top']['#field_suffix'] = 'em';
  $form['p']['margin']['sides']['p_margin_top']['#default_value'] = '0.8';
  $form['p']['margin']['sides']['p_margin_top']['#attributes']['css_rule'] = 'margin-top:%p_margin_top%em;';

  $form['p']['margin']['sides']['p_margin_bottom']['#default_value'] = '0.8';
  $form['p']['margin']['sides']['p_margin_bottom']['#field_suffix'] = 'em';
  $form['p']['margin']['sides']['p_margin_bottom']['#attributes']['css_rule'] = 'margin-bottom:%p_margin_bottom%em;';
  
  return $form;
}
