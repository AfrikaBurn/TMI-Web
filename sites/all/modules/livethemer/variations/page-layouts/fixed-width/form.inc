<?php
/**
 * @file form.inc
 * Implementation of variation_id_settings_form().
 */
function fixed_width_settings_form($form) {
  $form['fixed'] = form_presets('fieldset', array('#title' => t('Page width'), '#weight' => 0));

  $form['fixed']['page_width'] = form_presets('page_width');
   // '#prefix' => '<div class="slider"></div>',
   
   
  $form['fixed']['align'] = array(
    '#type' => 'select',
    '#title' => 'Page alignment', 
    '#default_value' => 'center', 
    '#options' => array('left' => 'left', 'center' => 'center', 'right' => 'right'),  
    '#attributes' => array( 
      'update_action' => 'tpl_variable_css_class',
      'css_class' => 'align-%align%',
      'css_target' => '.page',
      // We keep tpl_variable blank as we are only adding a class to the element,
      // not replacing the template.
      'tpl_variable' => '',
     ),
  );
  
  return $form;
}
