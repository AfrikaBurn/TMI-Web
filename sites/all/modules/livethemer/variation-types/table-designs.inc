<?php
/**
 * @file table-designs.inc
 * Implementation of our "psuedo hook" hook_lt_themable().
 */
function table_designs_lt_themable() {
 return array(
   'title' => t('Table Styles'),
   'description' => t('Change table styles.'),
   'type' => 'table-designs', // used by the live_themer inspector etc
   'hook' => array('block'), // Which hook should invoke the theming of these variations?
   '#weight' => 12,
   '#css_weight' => 7,
   );
}

/**
 * Implementation of _settings_form().
 */
function table_designs_settings_form() {
  //$form = array();
  $form = table_presets();
  
  return $form;
}

