<?php
/**
 * @file block.inc a place to store hook implementations to make blocks "live-themer enabled".
 */

/**
 * Implementation of our "psuedo hook" hook_lt_themable().
 */
function node_designs_lt_themable() {
  return array(
    'title' => t('Designs'),
    'description' => t('node block design.'),
    'type' => 'node-designs',
    'hook' => 'node',
    '#weight' => 1,
    '#css_weight' => 5,
  );
}

/**
 * Implementation of _settings_form().
 */
function node_designs_settings_form() {
  $form = array();
  
  // Full Display.
  $target = '.node-view-full';
  $field_prefix = 'full_display';

  $form['full'] = form_presets('fieldset', array('#title' => t('Full Display'), '#collapsed' => TRUE));
  $form['full']['backgrounds'] = background_reused('Background', '.node-view-full', $field_prefix . '_background', 'fieldset');
  $form['full']['borders'] = border_reused('Border', $target, $field_prefix . '_border', 'fieldset');
  $form['full']['dimensions'] = dimension_reused('Dimensions', $target, $field_prefix . '_dimensions', 'fieldset');
  $form['full']['fonts'] = font_reused('Fonts', $target . ' .content', $field_prefix . '_content');
  $form['full']['fonts']['#weight'] = 2;
  
  // User pics.
	// Note that the css_target of these two fields assumes .user-picture is a direct descendant of the target in order 
	// that this rule will leave the comment author pictures alone.  
	$form['full']['user_pic'] = form_presets('fieldset', array('#title' => t('User Picture')));
  $form['full']['user_pic']['display'] = form_presets('wrapper', array('#title' => t('Display')));
  $form['full']['user_pic']['display'][$field_prefix . '_user_pic_toggle'] = array(
    '#type' => 'select', 
    '#title' => t('Picture Display'), 
    '#default_value' => 'on',
    '#multiple' => FALSE,
    '#options' => array(
      'block' => t('On'), 
      'none' => t('Off'),
    ),
    '#attributes' => array(
     'css_target' => $target . ' > .user-picture', 
     'update_action' => 'css',
     'css_rule' => 'display:%' . $field_prefix . '_user_pic_toggle%;',
    ),
  );
  $form['full']['user_pic']['display'][$field_prefix . '_user_pic_position'] = array(
    '#type' => 'select', 
    '#title' => t('Picture Position'), 
    '#default_value' => 'right',
    '#multiple' => FALSE,
    '#options' => array(
      'none' => t('-'), 
      'left' => t('Left'), 
      'right' => t('Right'),
    ),
    '#attributes' => array(
     'css_target' => $target . ' > .user-picture',
     'update_action' => 'css',
     'css_rule' => 'float:%' . $field_prefix . '_user_pic_position%;',
    ),
  );
  
  $dimensions = dimension_reused('Dimensions', $target . ' .user-picture', $field_prefix . '_user_pic_dimensions', 'wrapper');
  $form['full']['user_pic']['margin'] = $dimensions['margin'];

  // Teaser Display.
  $target = '.node-view-teaser';
  $field_prefix = 'teaser_display';
  
  $form['teaser'] = form_presets('fieldset', array('#title' => t('Teaser Display'), '#collapsed' => TRUE));
  $form['teaser']['backgrounds'] = background_reused('Background', $target, $field_prefix . '_background', 'fieldset');
  $form['teaser']['borders'] = border_reused('Border', $target, $field_prefix . '_border', 'fieldset');

  $form['teaser']['dimensions'] = dimension_reused('Dimensions', $target, $field_prefix . '_dimensions', 'fieldset');
  $form['teaser']['fonts'] = form_presets('fieldset', array(
    '#title' => t('Fonts'),
    '#collapsed' => TRUE,
    '#weight' => 2,
  ));
  $form['teaser']['fonts']['title'] = font_reused( 'Title', $target . ' h2 a', $field_prefix . '_node_heading');
  $form['teaser']['fonts']['title']['#weight'] = 2;
  $form['teaser']['fonts']['content'] = font_reused('Body', $target . ' .content', $field_prefix . '_content');
  $form['teaser']['fonts']['content']['#weight'] = 3;
  
  // User pics.
  $form['teaser']['user_pic'] = form_presets('fieldset', array('#title' => t('User Picture')));
  $form['teaser']['user_pic']['display'] = form_presets('wrapper', array('#title' => t('Display')));
  $form['teaser']['user_pic']['display'][$field_prefix . '_user_pic_toggle'] = array(
    '#type' => 'select', 
    '#title' => t('Picture Display'),
    '#default_value' => 'on',
    '#multiple' => FALSE,
    '#options' => array(
      'block' => t('On'), 
      'none' => t('Off'),
    ),
    '#attributes' => array(
     'css_target' => $target . ' .user-picture',
     'update_action' => 'css',
     'css_rule' => 'display:%' . $field_prefix . '_user_pic_toggle%;',
    ),
  );
  $form['teaser']['user_pic']['display'][$field_prefix . '_user_pic_position'] = array(
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
     'css_target' => $target . ' .user-picture',
     'update_action' => 'css',
     'css_rule' => 'float:%' . $field_prefix . '_user_pic_position%;',
    ),
  );
  
  $dimensions = dimension_reused('Dimensions', $target . ' .user-picture', $field_prefix . '_user_pic_dimensions', 'wrapper');
  $form['teaser']['user_pic']['margin'] = $dimensions['margin'];
   
  return $form;
}