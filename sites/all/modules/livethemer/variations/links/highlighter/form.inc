<?php
/**
 * @file
 * Implementation of variation_id_settings_form().
 */
function highlighter_settings_form($form) {
  $form['bg'] = form_presets('fieldset', array('#title' => t('Background')));
  $form['bg']['highlighter_color'] = array(
    '#title' => 'Color',
    '#type' => 'select',
    '#default_value' => 'yellow',
    '#options' => array(
      '-' => '-',
      'yellow' => 'yellow',
      'pink' => 'pink',
      'green' => 'green',
    ),
    '#attributes' => array(
      'update_action' => 'tpl_variable_css_class',
      'css_class' => 'link-highlighter-%highlighter_color%',
      'tpl_variable' => '',
      //'css_target' => '.variation-highlighter a',
    ),
  );

  return $form;
}
