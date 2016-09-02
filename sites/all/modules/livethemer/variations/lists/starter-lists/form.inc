<?php
/**
 * @file
 * Implementation of variation_id_settings_form().
 */
function starter_lists_settings_form($form) {
  
  // List item.
  $form['item'] = form_presets('fieldset', array('#title' => t('Item')));

  // Find available image files. 
  $options = get_images_from_variation('starter-lists');

  // Bullet.
  $form['item']['bullet'] = form_presets('wrapper', array('#title' => t('Item Bullet')));
  $form['item']['bullet']['item_bullet_type'] = array(
    '#type' => 'select', 
    '#title' => t('Bullet Type'), 
    '#default_value' => 'square',
    '#options' => array(
      'inherit' => '-',
      'none' => t('None'),
      'disc' => t('Disc'),
      'circle' => t('Circle'),
      'square' => t('Square'),
    ),
    '#attributes' => array(
      'update_action' => 'css',
      'css_target' => 'ul li',
      'css_rule' => 'list-style-type: %item_bullet_type%;',
    ),
  );
  $form['item']['bullet']['item_bullet_image'] = array(
    '#type' => 'select',
    '#title' => t('Bullet Image'),
    '#default_value' => '-',
    '#options' => array(
      '-' => '-',
      'none' => t('None'),
      )+$options,
    '#attributes' => array(
      'update_action' => 'css',
      'css_target' => 'ul li',
      'css_rule' => 'list-style-image: url(%basepath%%item_bullet_image%);',
      'css_default' => 'none',
    ),
  );
  $form['item']['bullet']['item_bullet_position'] = array(
    '#type' => 'select', 
    '#title' => t('Bullet Position'), 
    '#default_value' => '-', 
    '#options' => array(
      'inherit' => '-',
      'inside' => t('Inside'),
      'outside' => t('Outside'),
    ),
    '#attributes' => array(
      'update_action' => 'css',
      'css_target' => 'li',
      'css_rule' => 'list-style-position: %item_bullet_position%;',
    ),
  );

  return $form;
}