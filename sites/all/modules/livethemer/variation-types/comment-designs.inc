<?php
/**
 * @file block.inc a place to store hook implementations to make blocks "live-themer enabled".
 */

/**
 * Implementation of our "psuedo hook" hook_lt_themable().
 */
function comment_designs_lt_themable() {
  return array(
    'title' => t('Designs'),
    'description' => t('Comment block design.'),
    'type' => 'comment-designs',
    'hook' => 'comment',
    '#weight' => 1,
    '#css_weight' => 7,
  );
}

/**
 * Implementation of _settings_form().
 */
function comment_designs_settings_form() {
  $form = array();
  $form['backgrounds'] = background_presets();
  $form['borders'] = border_presets();
  $form['dimensions'] = dimension_presets();
  $form['fonts'] = form_presets('fieldset', array(
    '#title' => t('Fonts'),
    '#collapsed' => TRUE,
    '#weight' => 2,
  ));
  $form['fonts']['title'] = font_reused( 'Title', 'h3 a', 'comment_heading');
  $form['fonts']['title']['#weight'] = 2;
  $form['fonts']['content'] = font_reused('Body', '.content', 'content');
  $form['fonts']['content']['#weight'] = 3;
  
  // User pics.
  $form['user_pic'] = form_presets('fieldset', array('#title' => t('Comment Author Picture')));
  $form['user_pic']['display'] = form_presets('wrapper', array('#title' => t('Display')));
  $form['user_pic']['display']['user_pic_toggle'] = array(
    '#type' => 'select', 
    '#title' => t('Picture Display'), 
    '#default_value' => 'on',
    '#multiple' => FALSE,
    '#options' => array(
      'block' => t('On'), 
      'none' => t('Off'),
    ),
    '#attributes' => array(
     'css_target' => '.user-picture', 
     'update_action' => 'css',
     'css_rule' => 'display:%user_pic_toggle%;', 
    ),
  );
  $form['user_pic']['display']['user_pic_position'] = array(
    '#type' => 'select', 
    '#title' => t('Picture Position'), 
    '#default_value' => 'left',
    '#multiple' => FALSE,
    '#options' => array(
      'none' => t('-'), 
      'left' => t('Left'), 
      'right' => t('Right'),
    ),
    '#attributes' => array(
     'css_target' => '.user-picture', 
     'update_action' => 'css',
     'css_rule' => 'float:%user_pic_position%;', 
    ),
  );
  
  $dimensions = dimension_reused('Dimensions', '.user-picture', 'user_pic_dimensions', 'wrapper');
  $form['user_pic']['margin'] = $dimensions['margin'];
  
  // Links.
  $form['links'] = form_presets('fieldset', array('#title' => t('Comment Links')));
  $form['links']['links_position'] = array(
    '#type' => 'select', 
    '#title' => t('Position'), 
    '#default_value' => 'left',
    '#multiple' => FALSE,
    '#options' => array(
      'left' => t('Left'), 
      'right' => t('Right'),
    ),
    '#attributes' => array(
     'css_target' => 'ul.links', 
     'update_action' => 'css',
     'css_rule' => 'float:%links_position%;', 
    ),
  );
  return $form;
}