<?php
/**
 * @file form_presets.inc
 */

/**
 * Provides preset forms API fields to reduce effort building settings forms.
 *
 * TODO: refactor along the lines of system_element_info()
 * http://api.drupal.org/api/drupal/modules--system--system.module/function/system_element_info/7
 * This isn't so much about the array structure, but usage. It should use #type like so:
 
  $form['note_color'] = array(
    '#type' => 'background_color',  // background_color is defined below
    '#something' => 'override #something's value here', 
  )
 
 */
function form_presets($preset_id, $overrides = array()) {  
  // Generic FAPI
  $form['fieldset'] = array(
    '#type' => 'fieldset', 
    '#title' => t('Group'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['wrapper'] = array(
    '#type' => 'item', 
    '#title' => t('Wrapper'),
    '#prefix' => '<div class="form-items-wrapper clearfix">', 
    '#suffix' => '</div>', 
  );
  // Padding
  $form['padding'] = array(
    '#title' => t('Padding'), 
    '#type' => 'textfield', 
    '#field_suffix' => 'px', 
    '#size' => 3, 
    '#maxlength' => 3, 
    '#default_value' => '', 
    '#attributes' => array(
      'update_action' => 'css',
      'css_target' => '',
      'css_rule' => 'padding: %padding%px;',
    ),
  );
  $form['padding_top'] = array(
    '#title' => t('Padding Top'), 
    '#type' => 'textfield', 
    '#field_suffix' => 'px', 
    '#size' => 3, 
    '#maxlength' => 3, 
    '#default_value' => '', 
    '#attributes' => array(
      'update_action' => 'css',
      'css_target' => '',
      'css_rule' => 'padding-top: %padding_top%px;',
    ),
  );
  $form['padding_bottom'] = array(
    '#title' => t('Padding Bottom'), 
    '#type' => 'textfield', 
    '#field_suffix' => 'px', 
    '#size' => 3, 
    '#maxlength' => 3, 
    '#default_value' => '', 
    '#attributes' => array(
      'update_action' => 'css',
      'css_target' => '',
      'css_rule' => 'padding-bottom: %padding_bottom%px;',
    ),
  );
  $form['padding_left'] = array(
    '#title' => t('Padding Left'), 
    '#type' => 'textfield', 
    '#field_suffix' => 'px', 
    '#size' => 3, 
    '#maxlength' => 3, 
    '#default_value' => '', 
    '#attributes' => array(
      'update_action' => 'css',
      'css_target' => '',
      'css_rule' => 'padding-left: %padding_left%px;',
    ),
  );
  $form['padding_right'] = array(
    '#title' => t('Padding Right'), 
    '#type' => 'textfield', 
    '#field_suffix' => 'px', 
    '#size' => 3, 
    '#maxlength' => 3, 
    '#default_value' => '', 
    '#attributes' => array(
      'update_action' => 'css',
      'css_target' => '',
      'css_rule' => 'padding-right: %padding_right%px;',
    ),
  );

  // Margins
  $form['margin'] = array(
    '#title' => t('Margins'), 
    '#type' => 'textfield', 
    '#field_suffix' => 'px', 
    '#size' => 3, 
    '#maxlength' => 3, 
    '#default_value' => '', 
    '#attributes' => array(
      'update_action' => 'css',
      'css_target' => '',
      'css_rule' => 'margin: %margin%px;',
    ),
  );
  $form['margin_top'] = array(
    '#title' => t('Margin Top'), 
    '#type' => 'textfield', 
    '#field_suffix' => 'px', 
    '#size' => 3, 
    '#maxlength' => 3, 
    '#default_value' => '', 
    '#attributes' => array(
      'update_action' => 'css',
      'css_target' => '',
      'css_rule' => 'margin-top: %margin_top%px;',
    ),
  );
  $form['margin_bottom'] = array(
    '#title' => t('Margin Bottom'), 
    '#type' => 'textfield', 
    '#field_suffix' => 'px', 
    '#size' => 3, 
    '#maxlength' => 3, 
    '#default_value' => '', 
    '#attributes' => array(
      'update_action' => 'css',
      'css_target' => '',
      'css_rule' => 'margin-bottom: %margin_bottom%px;',
    ),
  );
  $form['margin_left'] = array(
    '#title' => t('Margin Left'), 
    '#type' => 'textfield', 
    '#field_suffix' => 'px', 
    '#size' => 3, 
    '#maxlength' => 3, 
    '#default_value' => '', 
    '#attributes' => array(
      'update_action' => 'css',
      'css_target' => '',
      'css_rule' => 'margin-left: %margin_left%px;',
    ),
  );
  $form['margin_right'] = array(
    '#title' => t('Margin Right'), 
    '#type' => 'textfield', 
    '#field_suffix' => 'px', 
    '#size' => 3, 
    '#maxlength' => 3, 
    '#default_value' => '', 
    '#attributes' => array(
      'update_action' => 'css',
      'css_target' => '',
      'css_rule' => 'margin-right: %margin_right%px;',
    ),
  );

  // Typography
  $form['font_size'] = array(
    '#title' => t('Font Size'), 
    '#type' => 'textfield', 
    '#field_suffix' => 'px', 
    '#size' => 3, 
    '#maxlength' => 2, 
    '#default_value' => '', 
    '#attributes' => array(
      'update_action' => 'css',
      'css_target' => '',
      'css_rule' => 'font-size: %font_size%px;',
    ),
  );
  
  $form['text_transform'] = array(
    '#type' => 'select',
    '#title' => t('Text transform'),
    '#default_value' => '-',
    '#options' => array(
      '-' => '-',
      'none' => t('none'),
      'capitalize' => t('Title case'),
      'lowercase' => t('Lowercase'),
      'uppercase' => t('Uppercase'),
    ),
    '#attributes' => array(
      'update_action' => 'css',
      'css_target' => '',
      'css_rule' => 'text-transform:%text_transform%;',
    ),
  );

  $form['font_variant'] = array(
    '#type' => 'select', 
    '#title' => t('Font variant'), 
    '#default_value' => '-', 
    '#options' => array(
      '-' => '-',
      'normal' => t('Normal'),
      'small-caps' => t('Small Caps'),
    ),
    '#attributes' => array(
      'update_action' => 'css',
      'css_target' => '',
      'css_rule' => 'font-variant: %font_variant%;',
    ),
  );
  
  $form['text_decoration'] = array(
    '#type' => 'select', 
    '#title' => t('Text Decoration'), 
    '#default_value' => '-', 
    '#options' => array(
      '-' => '-',
      'none' => t('None'),
      'underline' => t('Underline'),
      'line-through' => t('Line-through'),
      'overline' => t('Overline'),
    ),
    '#attributes' => array(
      'update_action' => 'css',
      'css_target' => '',
      'css_rule' => 'text-decoration: %link_underline%;',
    ),
  );
  
  $form['text_align'] = array(
    '#type' => 'select',
    '#title' => t('Text Align'),
    '#default_value' => '-',
    '#options' => array(
      '-' => '-',
      'left' => t('left'),
      'center' => t('center'),
      'justify' => t('justify'),
      'right' => t('right'),
    ),
    '#attributes' => array(
      'update_action' => 'css',
      'css_target' => '',
      'css_rule' => 'text-align: %text_align%;',
    ),
  );

  $form['line_height'] = array(
    '#type' => 'textfield', 
    '#title' => t('Line Height'), 
    '#size' => 3, 
    '#field_suffix' => '%', 
    '#maxlength' => 3, 
    '#default_value' => '', 
    '#attributes' => array(
      'update_action' => 'css',
      'css_target' => '',
      'css_rule' => 'line-height: %line_height%%;',
    ),
  );
  
  $form['font_style'] = array(
    '#type' => 'select', 
    '#title' => t('Font Style'), 
    '#default_value' => '-', 
    '#options' => array(
      '-' => '-',
      'font-weight: normal;font-style: normal' => t('none'),
      'font-weight: bold' => t('Bold'),
      'font-weight: bold; font-style: italic' => t('Bold + Italic'),
      'font-style: italic' => t('Italic'),
    ),
    '#attributes' => array(
      'update_action' => 'css',
      'css_target' => '',
      'css_rule' => '%font_style%',
    ),
  );

  $form['font_family'] = array(
    '#type' => 'select', 
    '#title' => t('Font Family'), 
    '#default_value' => '-', 
    '#options' => array(
      '-' => '-',
      '"Helvetica Neue", Helvetica, Arial, sans-serif' => t('Helvetica'),
      'Georgia, "Times New Roman", Times, serif'       => t('Georgia'),
      '"Lucida Grande", Verdana, sans-serif'            => t('Lucida Grande'),
    ),
    '#attributes' => array(
      'update_action' => 'css',
      'css_target' => '',
      'css_rule' => 'font-family: %font_family%;',
    ),
  );

  $form['font_color'] = array(
    '#type' => 'textfield', 
    '#title' => t('Font Color'), 
    '#size' => 20,
    '#maxlength' => 30,
    '#default_value' => '', 
    '#attributes' => array(
      'update_action' => 'css',
      'css_target' => '',
      'css_rule' => 'color: %font_color%;',
      'class' => array('colourpick'),
    ),
  );
  $form['icon'] = array(
    '#title' => t('Icon'), 
    '#type' => 'select', 
    '#default_value' => '', 
    '#multiple' => FALSE,
    '#options' => array(),
    '#attributes' => array(
      'update_action' => 'css',
      'css_target' => '',
      'css_rule' => 'padding-left: 32px; background: url(%basepath%%h2_icon%) no-repeat left center;',
    ),
  );

  // Images and backgrounds
  $form['background_image'] = array(
    '#title' => t('Image'), 
    '#type' => 'select', 
    '#default_value' => '-', 
    '#multiple' => FALSE,
    '#options' => array(),
    '#attributes' => array(
      'update_action' => 'css',
      'css_target' => '',
      'css_rule' => 'background-image: url(%basepath%%background_image%);',
    ),
  );
  $form['background_image_repeat'] = array(
    '#title' => t('Repeat'), 
    '#type' => 'select', 
    '#default_value' => '-', 
    '#multiple' => FALSE,
    '#options' => array(
      '-'         => '-',
      'repeat'    => 'Tile in both directions',
      'repeat-x'  => 'Tile horizontally',
      'repeat-y'  => 'Tile vertically',
      'no-repeat' => 'Do not tile',
    ),    
    '#attributes' => array(
      'update_action' => 'css',
      'css_target' => '',
      'css_rule' => 'background-repeat:%background_image_repeat%;',
    ),
  );
  $form['background_image_position_y'] = array(
    '#title' => t('Position Y'), 
    '#type' => 'select', 
    '#default_value' => '-', 
    '#multiple' => FALSE,
    '#options' => array(
      '-'      => '-',
      '0'   => 'None',
      'top'   => 'Top',
      'center' => 'Center',
      'bottom'  => 'Bottom',
    ),    
    '#attributes' => array(
      'update_action' => 'css',
      'css_target' => '',
      'css_rule' => 'background-position: %background_image_position_x% %background_image_position_y%;',
    ),
  );
  $form['background_image_position_x'] = array(
    '#title' => t('Position X'), 
    '#type' => 'select', 
    '#default_value' => '-', 
    '#multiple' => FALSE,
    '#options' => array(
      '-'      => '-',
      '0'      => 'None',
      'left'   => 'Left',
      'center' => 'Center',
      'right'  => 'Right',
    ),    
    '#attributes' => array(
      'update_action' => 'css',
      'css_target' => '',
      'css_rule' => 'background-position: %background_image_position_x% %background_image_position_y%;',
    ),
  );
  $form['background_color'] = array(
    '#type' => 'textfield', 
    '#title' => t('Background Color'), 
    '#size' => 20,
    '#maxlength' => 30,
    '#default_value' => '', 
    '#attributes' => array(
      'update_action' => 'css',
      'css_target' => '',
      'css_rule' => 'background-color: %background_color%;',
      'class' => array('colourpick'),
    ),
  );
  
  // Grid-unit field: this field will need its #attributes overriden in each instance.
  $form['grid_units'] = array(
    '#type' => 'select', 
    '#title' => t('Grid Units'), 
    '#default_value' => 1,
    '#multiple' => FALSE,
    '#options' => array(
      '-' => '-', 
      '1' => '1', 
      '2' => '2', 
      '3' => '3',
      '4' => '4',
      '5' => '5',
      '6' => '6',
      '7' => '7',
      '8' => '8',
      '9' => '9',
      '10' => '10',
      '11' => '11',
      '12' => '12',
    ),
    '#attributes' => array(
      'update_action' => 'tpl_variable_css_class',
      'css_class' => 'grid-%grid_units%',
      'tpl_variable' => 'grid_units',
      'css_target' => '',
    ),
  );
  $form['page_width'] = array(
    '#title' => t('Width'), 
    '#type' => 'select', 
    '#field_suffix' => 'px', 
    '#options' => array('760' => '760', '960' => '960', '1240' => '1240', '1580' => '1580' ),
    '#default_value' => '960', 
    '#attributes' => array(
      'update_action' => 'css',
      'css_target' => '',
      'css_rule' => 'width: %page_width%px;',
    ),
  );

 //Borders
  $form['border_color'] = array(
    '#type' => 'textfield', 
    '#title' => t('Border Color'), 
    '#size' => 20,
    '#maxlength' => 30,
    '#default_value' => '', 
    '#attributes' => array(
      'update_action' => 'css',
      'css_target' => '',
      'css_rule' => 'border-color: %border_color%;',
      'class' => array('colourpick'),
    ),
  );
  $form['border_style'] = array(
    '#type' => 'select',
    '#default_value' => '-', 
    '#options' => array(
      '-' => '-', 
      'none' => 'none',
      'solid' => 'solid', 
      'dashed' => 'Dashed',
      'dotted' => 'Dotted', 
      'double' => 'Double', 
      'groove' => 'Groove', 
      'inset' => 'Inset',      
      'outset' => 'Outset', 
      'ridge' => 'Ridge',     
    ),
    '#attributes' => array(
      'update_action' => 'css',
      'css_target' => '',
      'css_rule' => 'border-style: %border_style%;',
    ),
  );
  $form['border_width'] =  array(
    '#type' => 'select',
    '#default_value' => '-',
    '#options' => array(
      '-' => '-',
      'thin' => 'thin',
      'medium' => 'medium',
      'thick' => 'thick'
    ),
    '#multiple' => FALSE,
    '#attributes' => array(
      'update_action' => 'css',
      'css_target' => '',
      'css_rule' => 'border-width: %border_width%;'
    ),
  );
  $form['border_collapse'] = array(
    '#title' => t('Border Collapse'),
    '#type' => 'select',
    '#default_value' => '-',
    '#options' => array( 
      '-' => '-',
      'collapse' => 'collapse',
      'separate' => 'separate'
    ),
    '#multiple' => FALSE,
    '#attributes' => array(
      'update_action' => 'css',
      'css_target' => 'table',
      'css_rule' => 'border-collapse: %border_collapse%;'
    ),
  );
  // Border radius.
  $form['corner_radius'] = array(
    '#title' => t('Corner Radius'), 
    '#type' => 'textfield', 
    '#size' => 2, 
    '#field_suffix' => 'px', 
    '#maxlength' => 2, 
    '#default_value' => '', 
    '#attributes' => array(
      'update_action' => 'css',
      'css_target' => '',
      'css_rule' => '-webkit-border-radius: %corner_radius%px;
  -moz-border-radius: %corner_radius%px;
  border-radius: %corner_radius%px;',
    ),
  );
  
  // Positioning
  $form['position_yes_no'] = array(
    '#title' => t('Position'),
    '#type' => 'select',
    '#default_value' => '-',
    '#options' => array( 
      '-' => '-', 
      'position:absolute;' => t('yes'), 
      'position:static;' => t('no')
    ),
    '#multiple' => FALSE,
    '#attributes' => array(
      'update_action' => 'css',
      'css_target' => '',
      'css_rule' => '%position_yes_no%;'
    ),
  );
  $form['position'] = array(
    '#title' => t('Position'),
    '#type' => 'select',
    '#default_value' => '-', 
    '#options' => array( 
      '-' => '-', 
      'static' => t('static'), 
      'relative' => t('relative'), 
      'absolute' => t('absolute')
    ),
    '#multiple' => FALSE, 
    '#attributes' => array(
      'update_action' => 'css',
      'css_target' => '',
      'css_rule' => 'position: %position%;'
    ),
  );
  $form['position_left'] = array(
    '#type' => 'textfield', 
    '#title' => t('Left'), 
    '#size' => 6, 
    '#maxlength' => 7, 
    '#field_suffix' => 'px', 
    '#default_value' => '', 
    '#attributes' => array(
      'update_action' => 'css',
      'css_target' => '',
      'css_rule' => 'left: %position_left%px;',
    ),
  );
  $form['position_right'] = array(
    '#type' => 'textfield', 
    '#title' => t('Right'), 
    '#size' => 6, 
    '#maxlength' => 7, 
    '#field_suffix' => 'px', 
    '#default_value' => '', 
    '#attributes' => array(
      'update_action' => 'css',
      'css_target' => '',
      'css_rule' => 'right: %position_right%px;',
    ),
  );
  $form['position_top'] = array(
    '#type' => 'textfield', 
    '#title' => t('Top'), 
    '#size' => 6, 
    '#maxlength' => 7, 
    '#field_suffix' => 'px', 
    '#default_value' => '', 
    '#attributes' => array(
      'update_action' => 'css',
      'css_target' => '',
      'css_rule' => 'top: %position_top%px;',
    ),
  );
  $form['position_bottom'] = array(
    '#type' => 'textfield', 
    '#title' => t('Bottom'), 
    '#size' => 6, 
    '#maxlength' => 7, 
    '#field_suffix' => 'px', 
    '#default_value' => '', 
    '#attributes' => array(
      'update_action' => 'css',
      'css_target' => '',
      'css_rule' => 'bottom: %position_bottom%px;',
    ),
  );
   $form['width'] = array(
    '#title' => t('Width'),
    '#type' => 'textfield',
    '#field_suffix' => 'px', 
    '#size' => 3, 
    '#maxlength' => 3, 
    '#default_value' => '', 
    '#attributes' => array(
      'css_target' => '', 
      'update_action' => 'css',
      'css_rule' => 'width:%width%px;', 
    ),
  );
  $form['height'] = array(
    '#title' => t('Height'),
    '#type' => 'textfield',
    '#field_suffix' => 'px', 
    '#size' => 3, 
    '#maxlength' => 3, 
    '#default_value' => '', 
    '#attributes' => array(
      'css_target' => '', 
      'update_action' => 'css',
      'css_rule' => 'height:%height%px;', 
    ),
  );
  $form['overflow'] = array(
   '#title' => t('Overflow'), 
    '#type' => 'select',  
    '#options' => array( 
      '-' => '-', 
      'visible' => t('visible'),
      'auto' => t('auto'), 
      'hidden' => t('hidden'), 
      'scroll' => t('scroll') 
    ),
    '#default_value' => '-', 
    '#attributes' => array(
      'update_action' => 'css',
      'css_target' => '',
      'css_rule' => 'overflow: %overflow%;',
    ),
  );
  
  //return array_join($form[$preset_id], $overrides);
  return lt_array_replace_recursive($form[$preset_id], $overrides);
}

/**
 * CSS3 Box shadow form filelds
 */
function shadow_presets($overrides = array()) {
  $form['shadow_color'] = array(
    '#type' => 'textfield', 
    '#title' => t('Color'), 
    '#size' => 20, 
    '#maxlength' => 20, 
    '#default_value' => '', 
    '#attributes' => array(
      'update_action' => 'placeholder',
      'update_field' => 'blur',
      'class' => array('colourpick'),
    ),
  );
  $form['hor_offset'] = array(
   '#title' => t('Horizontal Offset'), 
    '#type' => 'textfield', 
    '#size' => 2, 
    '#field_suffix' => 'px', 
    '#maxlength' => 2, 
    '#default_value' => '', 
    '#attributes' => array(
      'update_action' => 'placeholder',
      'update_field' => 'blur',
    )
  );
  $form['ver_offset'] = array(
   '#title' => t('Vertical Offset'), 
    '#type' => 'textfield', 
    '#size' => 2, 
    '#field_suffix' => 'px', 
    '#maxlength' => 2, 
    '#default_value' => '', 
    '#attributes' => array(
      'update_action' => 'placeholder',
      'update_field' => 'blur',
    )
  );
  $form['blur'] = array(
    '#title' => t('Blur Radius'), 
    '#type' => 'textfield', 
    '#size' => 2, 
    '#field_suffix' => 'px', 
    '#maxlength' => 2, 
    '#default_value' => '', 
    '#attributes' => array(
      'update_action' => 'css',
      'css_target' => '',
      'css_rule' => ' -moz-box-shadow: %hor_offset%px %ver_offset%px %blur%px %shadow_color%;
  -webkit-box-shadow: %hor_offset%px %ver_offset%px %blur%px %shadow_color%;
  box-shadow: %hor_offset%px %ver_offset%px %blur%px %shadow_color%;',
    ),
  );
  return lt_nested_form_replace_recursive($form, $overrides);
}

/**
 * Border form fields.
 * @param $overrides
 */
function border_presets($overrides = array(), $wrapper = 'fieldset') {
  $form = form_presets($wrapper, array(
    '#title' => t('Border'),
    '#collapsed' => TRUE,
    '#weight' => 4,
  ));

  $form['border_color'] = form_presets('border_color', $overrides);
  $form['border_style'] = form_presets('border_style', $overrides);
  $form['border_width'] = form_presets('border_width', $overrides);
  $form['corner_radius'] = form_presets('corner_radius', $overrides);
  $form['shadow_wrapper'] = form_presets($wrapper, array('#title' => t('Shadow')));
  $form['shadow_wrapper']['shadow'] = shadow_presets($overrides);

  return $form;
}

/**
 * Border form fields that can be reused multiple times in a single form.
 * 
 * @param string $title
 * @param string $target
 * @param string $field_prefix
 */ 
function border_reused($title = 'Border', $target ='', $field_prefix = '', $wrapper = 'fieldset') {
  $form = form_presets($wrapper, array(
    '#title' =>  $title,
    '#collapsed' => TRUE,
    '#weight' => 5,
  ));
  
  $fields = array(
    'border_color' => 'border-color: %' . $field_prefix . '_border_color%;',
    'border_style' => 'border-style: %' . $field_prefix . '_border_style%;',
    'border_width' => 'border-width: %' . $field_prefix . '_border_width%;',
    'corner_radius' => '-webkit-border-radius: %' . $field_prefix . '_corner_radius%px;
                       -moz-border-radius: %' . $field_prefix . '_corner_radius%px;
                       border-radius: %' . $field_prefix . '_corner_radius%px;',
  );
  $form = lt_add_form_field($form, $fields, $field_prefix, $target);
  
  $form['shadow_wrapper'] = form_presets('wrapper', array('#title' =>  'Shadow'));

  $form['shadow_wrapper']['shadow'] = shadow_presets(array(
    '#attributes' => array(
      'update_field' => $field_prefix . '_blur',
      'css_target' => $target,
      'css_rule' => ' -moz-box-shadow: %' . $field_prefix . '_hor_offset%px %' . $field_prefix . '_ver_offset%px %' . $field_prefix . '_blur%px %' . $field_prefix . '_shadow_color%;
                      -webkit-box-shadow: %' . $field_prefix . '_hor_offset%px %' . $field_prefix . '_ver_offset%px %' . $field_prefix . '_blur%px %' . $field_prefix . '_shadow_color%;
                      box-shadow: %' . $field_prefix . '_hor_offset%px %' . $field_prefix . '_ver_offset%px %' . $field_prefix . '_blur%px %' . $field_prefix . '_shadow_color%;',
    ),
  ));
  
  foreach ($form['shadow_wrapper']['shadow'] as $key => $value) {
    $form['shadow_wrapper']['shadow'][$field_prefix . '_' . $key] = $form['shadow_wrapper']['shadow'][$key];
    unset($form['shadow_wrapper']['shadow'][$key]);
  }
  
  return $form;
}

/**
 * Background form fields.
 */ 
function background_presets($overrides = array()) {
   $form = form_presets('fieldset', array(
    '#title' => t('Background'),
    '#collapsed' => TRUE,
    '#weight' => 3,
  ));
  
  // Find available image files. 
  $options = get_global_images(array('Headers' => '/headers', 'Tiles' => '/tiles'));
  $image_options = array('#options' => $options);
  
  // Merge the image options with the overrides passed in.
  $bg_overrides = array_merge_recursive($image_options, $overrides);
  $form['background_image'] = form_presets('background_image', $bg_overrides);
  
  $form['background_image_repeat'] = form_presets('background_image_repeat', $overrides);
  $form['background_image_position_x'] = form_presets('background_image_position_x', $overrides);
  $form['background_image_position_y'] = form_presets('background_image_position_y', $overrides);
  $form['background_color'] = form_presets('background_color', $overrides);

  return $form;
}

/**
 * Background form fields that can be reused multiple times in a single form.
 * 
 * @param string $title
 * @param string $target
 * @param string $field_prefix
 */
function background_reused($title = 'Background', $target ='', $field_prefix = '', $wrapper = 'fieldset') {
  $form = form_presets($wrapper, array(
    '#title' =>  $title,
    '#collapsed' => TRUE,
    '#weight' => 5,
  ));
  
  $fields = array(
    'background_image' => 'background-image: url(%basepath%%' . $field_prefix . '_background_image%);',
    'background_image_repeat' => 'background-repeat:%' . $field_prefix . '_background_image_repeat%;',
    'background_image_position_x' => 'background-position: %' . $field_prefix . '_background_image_position_x% %' . $field_prefix . '_background_image_position_y%;',
    'background_image_position_y' => 'background-position: %' . $field_prefix . '_background_image_position_x% %' . $field_prefix . '_background_image_position_y%;',
    'background_color' => 'background-color: %' . $field_prefix . '_background_color%;',
  );
  $form = lt_add_form_field($form, $fields, $field_prefix, $target);
  
  // Find available image files and add them to the background image field. 
  $options = get_global_images(array('Headers' => '/headers', 'Tiles' => '/tiles'));
  $image_options = array('#options' => $options);

  $form[$field_prefix . '_background_image']['#options']  = $options;
  
  return $form;
}

/**
 * Dimension form fields.
 * @param unknown_type $overrides
 */
function dimension_presets($overrides = array()) {
   $form = form_presets('fieldset', array(
    '#title' => t('Dimensions'),
    '#collapsed' => TRUE,
    '#weight' => 5,
  ));
  $form['size'] = form_presets('wrapper', array('#title' => t('Size')));
  $form['size']['width']  = form_presets('width', $overrides);
  $form['size']['height']  = form_presets('height', $overrides);
  $form['size']['overflow']  = form_presets('overflow', $overrides);
    
  // content Padding
  $form['padding'] = form_presets('wrapper', array('#title' => t('Padding')));
  $form['padding']['padding'] = form_presets('padding', $overrides);
    
  $form['padding']['sides']['padding_top'] = form_presets('padding_top', $overrides);
  $form['padding']['sides']['padding_right'] = form_presets('padding_right', $overrides);
  $form['padding']['sides']['padding_bottom'] = form_presets('padding_bottom', $overrides);
  $form['padding']['sides']['padding_left'] = form_presets('padding_left', $overrides);

  // content Margins
  $form['margin'] = form_presets('wrapper', array('#title' => t('Margin')));
  $form['margin']['margin'] = form_presets('margin');
  
  $form['margin']['sides']['margin_top'] = form_presets('margin_top', $overrides);
  $form['margin']['sides']['margin_right'] = form_presets('margin_right', $overrides);
  $form['margin']['sides']['margin_bottom'] = form_presets('margin_bottom', $overrides);
  $form['margin']['sides']['margin_left'] = form_presets('margin_left', $overrides);
 
  return $form;
}

/**
 * dimension form fields that can be reused multiple times in a single form.
 * 
 * @param string $title
 * @param string $target
 * @param string $field_prefix
 */
function dimension_reused($title = 'Dimensions', $target ='', $field_prefix = '', $wrapper = 'fieldset') {
  $form = form_presets($wrapper, array(
    '#title' =>  $title,
    '#collapsed' => TRUE,
    '#weight' => 5,
  ));
  $form['size'] = form_presets('wrapper', array('#title' => t('Size')));
  $form['size'][$field_prefix . '_width']  = form_presets('width',  array( '#attributes' => array('css_target' => $target, 'css_rule' => 'width:%' . $field_prefix . '_width%px;' )));
  $form['size'][$field_prefix . '_height']  = form_presets('height',  array( '#attributes' => array('css_target' => $target, 'css_rule' => 'height:%' . $field_prefix . '_height%px;' )));
  $form['size'][$field_prefix . '_overflow']  = form_presets('overflow', array( '#attributes' => array('css_target' => $target, 'css_rule' => 'overflow%' . $field_prefix . '_overflow%;' )));
    
  // content Padding
  $form['padding'] = form_presets('wrapper', array('#title' => t('Padding')));
  $form['padding'][$field_prefix . '_padding'] = form_presets('padding',  array( '#attributes' => array('css_target' => $target, 'css_rule' => 'padding:%' . $field_prefix . '_padding%px;' )));
  
  $form['padding']['sides'][$field_prefix . '_padding_top'] = form_presets('padding_top',  array( '#attributes' => array('css_target' => $target, 'css_rule' => 'padding-top:%' . $field_prefix . '_padding_top%px;' )));
  $form['padding']['sides'][$field_prefix . '_padding_right'] = form_presets('padding_right',  array( '#attributes' => array('css_target' => $target, 'css_rule' => 'padding-right:%' . $field_prefix . '_padding_right%px;' )));
  $form['padding']['sides'][$field_prefix . '_padding_bottom'] = form_presets('padding_bottom',  array( '#attributes' => array('css_target' => $target, 'css_rule' => 'padding-bottom:%' . $field_prefix . '_padding_bottom%px;' )));
  $form['padding']['sides'][$field_prefix . '_padding_left'] = form_presets('padding_left',  array( '#attributes' => array('css_target' => $target, 'css_rule' => 'padding-left:%' . $field_prefix . '_padding_left%px;' )));

  // content Margins
  $form['margin'] = form_presets('wrapper', array('#title' => t('Margin')));
  $form['margin'][$field_prefix . '_margin'] = form_presets('margin', array( '#attributes' => array('css_target' => $target, 'css_rule' => 'margin:%' . $field_prefix . '_margin%px;' )));
  
  $form['margin']['sides'][$field_prefix . '_margin_top'] = form_presets('margin_top',  array( '#attributes' => array('css_target' => $target, 'css_rule' => 'margin-top:%' . $field_prefix . '_margin_top%px;'  )));
  $form['margin']['sides'][$field_prefix . '_margin_right'] = form_presets('margin_right',  array( '#attributes' => array('css_target' => $target, 'css_rule' => 'margin-right:%' . $field_prefix . '_margin_right%px;'  )));
  $form['margin']['sides'][$field_prefix . '_margin_bottom'] = form_presets('margin_bottom',  array( '#attributes' => array('css_target' => $target, 'css_rule' => 'margin-bottom:%' . $field_prefix . '_margin_bottom%px;'  )));
  $form['margin']['sides'][$field_prefix . '_margin_left'] = form_presets('margin_left',  array( '#attributes' => array('css_target' => $target, 'css_rule' => 'margin-left:%' . $field_prefix . '_margin_left%px;'  )));
 
  return $form;
}  

/**
 * position form fields.
 * @param array $overrides
 */
function position_presets( $overrides = array()) {
   $form = form_presets('fieldset', array(
    '#title' => t('Position'),
    '#collapsed' => TRUE,
    '#weight' => 5,
  ));
  $form['position'] = form_presets('position', $overrides);
  $form['top'] = form_presets('position_top', $overrides);
  $form['left'] = form_presets('position_left', $overrides);
  $form['bottom'] = form_presets('position_bottom', $overrides);
  $form['right'] = form_presets('position_right', $overrides);
  
  return $form;
}  

/**
 * Position form fields that can be reused multiple times in a single form.
 * 
 * @param string $title
 * @param string $target
 * @param string $field_prefix
 */
function position_reused($title, $target, $field_prefix, $wrapper = 'fieldset') {
   $form = form_presets($wrapper, array(
    '#title' => t($title),
    '#collapsed' => TRUE,
  ));
  
  $fields = array(
    'position' => "position:%key%;",
    'position_top' => "top:%key%px;",
    'position_left' => "left:%key%px;",
    'position_bottom' => "bottom:%key%px;",
    'position_right' => "right:%key%px;",
  );
 
  foreach ($fields as $field => $rule) {
    $key = $field_prefix . '_' . $field;
    $css_rule = str_replace('%key%', "%$key%", $rule);
    $overrides =  array( '#attributes' => array('css_target' => $target, 'css_rule' => $css_rule ));
    $form[$key] = form_presets($field, $overrides); 
  }
  return $form;
}  

/**
 * Font form fields that can be reused multiple times in a single form.
 * 
 * @param string $title
 * @param string $target
 * @param string $field_prefix
 */
function font_reused($title, $target, $field_prefix, $wrapper = 'fieldset') { 
  $form = form_presets($wrapper, array(
    '#title' => t($title),
    '#collapsed' => TRUE,
  ));
  
  $fields = array(
    'font_family' => "font-family:%key%;",
    'font_size' => "font-size:%key%px;",
    'font_color' => "color:%key%;",
    'font_style' => "%key%;",
    'line_height' => "line-height: %key%%;",
    'text_transform' => "text-transform:%key%;",
    'font_variant' => "font-variant:%key%;",
    'text_decoration' => "text-decoration:%key%;",
    'text_align' => "text-align:%key%",
  );
  foreach ($fields as $field => $rule) {
    $key = $field_prefix . '_' . $field;
    $css_rule = str_replace('%key%', "%$key%", $rule);
    $overrides =  array( '#attributes' => array('css_target' => $target, 'css_rule' => $css_rule ));
    $form[$key] = form_presets($field, $overrides); 
  }
 
  return $form;
}

/*
 * Font field presets.
 */
function font_presets() { 
  $form = form_presets('fieldset', array(
    '#title' => t('Fonts'),
    '#collapsed' => TRUE,
    '#weight' => 2,
  ));
  $form['general_fonts'] = font_reused('General', '.page', 'general');
  //$form['title'] = font_reused( 'Title', 'h1.title', 'title');
  $form['h1'] = font_reused( 'H1', 'h1', 'h1');
  $form['h2'] = font_reused( 'H2', 'h2', 'h2');
  $form['h3'] = font_reused( 'H3', 'h3', 'h3');
  $form['h4'] = font_reused( 'H4', 'h4', 'h4');
  $form['h5'] = font_reused( 'H5', 'h5', 'h5');
  $form['h6'] = font_reused( 'H6', 'h6', 'h6');
  $form['links'] = font_reused( 'Link', 'a', 'link'); 
  $form['links_visited'] = font_reused( 'Links visited', 'a:visited', 'visited'); 
  $form['links_hover'] = font_reused( 'Link hover', 'a:hover', 'hover');   
  $form['links_active'] = font_reused( 'Link active', 'a:active', 'active'); 
   
  return $form;
}


/*
 * table field presets.
 */
function table_presets() {
  $form['table'] = form_presets('fieldset', array(
    '#title' => t('Table'),
    '#collapsed' => TRUE,
    '#weight' => 2,
  ));

  //borders (table, td)
  $form['table']['table_border'] = border_reused('Table Border', 'table', '', 'fieldset');
  $form['table']['table_border']['collapse'] = form_presets('border_collapse');

  $form['tr'] = form_presets('fieldset', array(
    '#title' => t('Table Rows'),
    '#collapsed' => TRUE,
    '#weight' => 2,
  ));
  $form['tr']['odd_bg'] = background_reused('Odd row background', 'tr.odd', 'odd',  'fieldset');
  $form['tr']['even_bg'] = background_reused('Even row background', 'tr.even', 'even', 'fieldset');

  $form['td'] = form_presets('fieldset', array(
    '#title' => t('Table data'),
    '#collapsed' => TRUE,
    '#weight' => 2,
  ));
  $form['td']['fonts'] = font_reused('text', 'table td', '');
  $form['td']['table_border'] = border_reused('TD Border', 'table td', '', 'fieldset');
  $form['td']['table_border']['collapse'] = form_presets('border_collapse',  array( '#attributes' => array('css_target' => 'table td' )));
  //padding (td)
  $form['td']['padding'] = form_presets('wrapper', array('#title' => t('Padding')));
  $form['td']['padding']['padding'] = form_presets('padding',  array( '#attributes' => array('css_target' => 'table td', 'css_rule' => 'padding:%padding%px;' )));

  $form['td']['padding']['sides']['padding_top'] = form_presets('padding_top',  array( '#attributes' => array('css_target' => 'table td', 'css_rule' => 'padding-top:%padding_top%px;' )));
  $form['td']['padding']['sides']['padding_right'] = form_presets('padding_right',  array( '#attributes' => array('css_target' => 'table td', 'css_rule' => 'padding-right:%padding_right%px;' )));
  $form['td']['padding']['sides']['padding_bottom'] = form_presets('padding_bottom',  array( '#attributes' => array('css_target' => 'table td', 'css_rule' => 'padding-bottom:%padding_bottom%px;' )));
  $form['td']['padding']['sides']['padding_left'] = form_presets('padding_left',  array( '#attributes' => array('css_target' => 'table td', 'css_rule' => 'padding-left:%padding_left%px;' )));

  return $form;
}


/**
 * Unfortunately only PHP >=5.3 has the function array_replace_recursive() so here's our own, from
 * comments on http://www.php.net/manual/en/function.array-replace-recursive.php
 */
function array_join() { 
    // Get array arguments 
    $arrays = func_get_args(); 

    // Define the original array 
    $original = array_shift($arrays); 

    // Loop through arrays 
    foreach ($arrays as $array) { 
        // Loop through array key/value pairs 
        foreach ($array as $key => $value) { 
            // Value is an array 
            if (is_array($value)) { 
                // Traverse the array; replace or add result to original array 
                $original[$key] = array_join($original[$key], $array[$key]); 
            } 

            // Value is not an array 
            else { 
                // Replace or add current value to original array 
                $original[$key] = $value; 
            } 
        } 
    } 

    // Return the joined array 
    return $original; 
}

function lt_array_replace_recursive($array, $array1) {
  foreach ($array1 as $key => $value) {
    // create new key in $array, if it is empty or not an array
    if (!isset($array[$key]) || (isset($array[$key]) && !is_array($array[$key]))) {
      $array[$key] = array();
    }

    // overwrite the value in the base array
    if (is_array($value)) {
      $value = lt_array_replace_recursive($array[$key], $value);
    }
    $array[$key] = $value;
  }
  
  return $array;
}

/**
 * A function to apply overrides to a nested form array. 
 */
function lt_nested_form_replace_recursive($form, $overrides) {
  foreach ($form as $key => $below) {
    $hash = stristr($key, '#');
    if (!$hash) {
      $form[$key] = lt_array_replace_recursive($below, $overrides);
      lt_nested_form_replace_recursive($form[$key], $overrides);
    } 
  }
  return $form;
}

/**
 * A function to populate the attributes hash of each form element. 
 * There are lots of functions in this file that need to be converted to using 
 * this because they are doing this same thing mulitple times for their forms.
 */
function lt_add_form_field($form, $fields, $field_prefix, $target) {
  foreach ($fields as $field => $rule) {
    $form[$field_prefix . '_' . $field]  = form_presets($field,  array(
      '#attributes' => array(
        'css_target' => $target, 
        'css_rule' => $rule
      ))
    );
  }
  return $form;
}
