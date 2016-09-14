<?php
/**
 * @file form.inc
 * Implementation of variation_id_settings_form().
 */
function horizontal_nav_bar_settings_form($form) {
  $form['color'] = form_presets('fieldset', array('#title' => t('Link Color')));
  $form['color']['link_font_color'] = form_presets('font_color', array(
    '#title' => 'a:link',
    '#default_value' => '#FFF',
    '#attributes' => array(
      'css_target' => 'a:link',
      'css_rule' => 'color: %link_font_color%;',
    ),
  ));
  $form['color']['visited_font_color'] = form_presets('font_color', array(
    '#title' => 'a:visited',
    '#default_value' => '#FFF',
    '#attributes' => array(
      'css_target' => 'a:visited',
      'css_rule' => 'color: %visited_font_color%;',
    ),
  ));
  $form['color']['hover_font_color'] = form_presets('font_color', array(
    '#title' => 'a:hover',
    '#attributes' => array(
      'css_target' => 'a:hover',
      'css_rule' => 'color: %hover_font_color%;',
    ),
  ));
  $form['color']['focus_font_color'] = form_presets('font_color', array(
    '#title' => 'a:focus',
    '#attributes' => array(
      'css_target' => 'a:focus',
      'css_rule' => 'color: %focus_font_color%;',
    ),
  ));
  $form['color']['active_font_color'] = form_presets('font_color', array(
    '#title' => 'a:active',
    '#attributes' => array(
      'css_target' => 'a:active',
      'css_rule' => 'color: %active_font_color%;',
    ),
  ));
  
  $form['style'] = form_presets('fieldset', array('#title' => t('Link Style')));
  $form['style']['link_underline'] = array(
    '#type' => 'select', 
    '#default_value' => 'none', 
    '#title' => 'Underline',
    '#options' => array(
      '-' => '-',
      'none' => t('none'),
      'underline' => t('underline'),
      'overline' => t('overline'),
      'line-through' => t('line-through'),
    ),
    '#attributes' => array(
      'update_action' => 'css',
      'css_target' => 'a',
      'css_rule' => '  text-decoration: %link_underline%;',
    ),
  );

  $form['style']['link_style'] = form_presets('font_style', array(
    '#title' => 'Style',
    '#attributes' => array(
      'update_action' => 'css',
      'css_target' => 'a',
      'css_rule' => '%link_style%;',
    ))
  );
  
  $form['style']['text_transform'] =  form_presets('text_transform', array(
    '#attributes' => array(
      'css_target' => '',
      'css_rule' => '%text_transform%',
    ),
  ));
    
  $form['bar'] = form_presets('fieldset', array('#title' => t('Bar Color')));  
  $form['bar']['background_color']  = form_presets('background_color', array(
    '#title' => 'Bar color',
    '#default_value' => '#036',
    '#attributes' => array(
      'update_action' => 'css',
      'css_target' => '.content',
      'css_rule' => 'background-color: %background_color%;',
      'class' => array('colourpick'),
    ),
  ));
 
   $form['bar']['hover_background_color']  = form_presets('background_color', array(
    '#title' => 'Hover background color',
    '#default_value' => '#036',
    '#attributes' => array(
      'update_action' => 'css',
      'css_target' => 'a:hover',
      'css_rule' => 'background-color: %hover_background_color%;',
      'class' => array('colourpick'),
    ),
  ));
  
   
  $form['heading'] = form_presets('fieldset', array('#title' => t('Heading')));
  $form['heading']['hide'] = array(
   '#type' => 'select',
   '#title' => t('Show or Hide the block heading'),
   '#options' => array( 'block' => 'show', 'none' => 'hide'),
   '#attributes' => array(
     'css_target' => 'h2', 
     'update_action' => 'css',
     'css_rule' => 'display:%hide%;', 
    ),
  );
 
  return $form;
}