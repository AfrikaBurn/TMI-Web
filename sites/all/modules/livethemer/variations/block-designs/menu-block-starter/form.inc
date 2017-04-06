<?php
/**
 * @file
 * Implementation of variation_id_settings_form().
 */
function menu_block_starter_settings_form($form) {
  $form['menu_item_display'] = form_presets('fieldset', array('#title' => 'Menu Item Display'));
  $form['menu_item_display']['bullets'] = array(
    '#type' => 'select',
    '#title' => 'Bullet type',
    '#default_value' => 'none',
    '#options' => array(
      'none' => t('None'),
      'disc' => t('Disc'),
      'square' => t('Square'),
      'circle' => t('Circle'),
    ),
    '#attributes' => array(
     'css_target' => 'ul.menu li', 
     'update_action' => 'css',
     'css_rule' => 'list-style-type:%bullets%;', 
    ),
  );
  
  $form['menu_item_display']['menu_item_margin'] = array(
    '#type' => 'textfield',
    '#title' => 'Space between items',
    '#size' => 5,
    '#default_value' => 15,
    '#field_suffix' => 'px',
    '#attributes' => array(
     'css_target' => 'ul.menu li', 
     'update_action' => 'css',
     'css_rule' => 'margin-right:%menu_item_margin%px;', 
    ),
  );
  
  $form['heading'] = form_presets('fieldset', array('#title' => t('Heading')));
  $form['heading']['hide'] = array(
   '#type' => 'select',
   '#title' => t('Show or Hide the block heading'),
   '#default_value' => 'none',
   '#options' => array( 'block' => 'show', 'none' => 'hide'),
   '#default_value' => 'none', 
   '#attributes' => array(
     'css_target' => 'h2', 
     'update_action' => 'css',
     'css_rule' => 'display:%hide%;', 
    ),
  );

  return $form;
}