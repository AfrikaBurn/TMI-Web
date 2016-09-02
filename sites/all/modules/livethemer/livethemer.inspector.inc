<?php
/**
 * @file
 * Code to provide the markup for the Livethemer inspector.
 *
 */
function _load_inspector() {
  $output = NULL;
  $output .= '<div id="lt-inspector">';
  
  $output .= '<div id="lt-inspector-header">';
  $output .= '<img id="homeicon" src="' . base_path() . drupal_get_path('module', 'livethemer') . '/images/house.png" width="11" height="11" alt="Inspector Home" />';
  $output .= '<img id="lt-inspector-logo" src="' . base_path() . drupal_get_path('module', 'livethemer') . '/images/lt-logo-small.png" width="75" height="19" alt="Livethemer" />';
  $output .= '<span class="info"></span>'; //added a span for use later in js.
  $output .= '<ul class="var-type-tabs"></ul>';
  $output .= '<span class="close"></span>';
  $output .= '</div>';

  $output .= '<div id="lt-inspector-body">';
  $output .= _inspector_home();
  $output .= '</div>';
  $output .= '</div>';
  
  return $output;
}

/*
 * Create a list of the available hooks, with all their variation types beside them.
 */
function _inspector_home() {
  // If a settings file hasn't been set then we need to tell the user to fix it.
  global $theme_key;

  $file_path = lt_get_path('data_file');
  
  if (!file_exists($file_path)) {
    $theme_settings_page = l(t('theme settings page'), 'admin/appearance/settings/' . $theme_key);
    
    $output = '<div id="lt-inspector-home" class="error">';
    $output .= '<p>You have not selected a Livethemer settings file for this theme.</p>
                <p>Please visit the ' . $theme_settings_page . ' to set one.</p>';
    $output .= '</div>';
    
    // Also put a message in the log.   
    watchdog('Livethemer', 'To use Livethemer, you need to select a Livethemer settings file  for your current theme.');

    return $output;
  }
  else {
    // We know the file exists so we check whether we may need to copy the file.
    // The file is copied if it's not writable or it is in our module directory or
    // livethemer_base theme directory. In these cases we copy it somewhere writable.
    // See also livethemer.module : get_settings_options()
    $module_path = drupal_get_path('module', 'livethemer');
    $theme_path = drupal_get_path('theme', 'livethemer_base');
    
    $writable = is_writable($file_path);
    $in_module_dir = strpos($file_path, $module_path) === 0;
    $in_theme_dir = !empty($theme_path) ? strpos($file_path, $theme_path) === 0 : false;    

    if (!$writable || $in_module_dir || $in_theme_dir) {
      $new_file_path = 'public://' . basename($file_path); // .'.settings';
      $file_path = file_unmanaged_copy($file_path, $new_file_path);
      if ($file_path) {       
        $theme_settings =  variable_get('theme_' . $theme_key . '_settings', NULL);
        $theme_settings['livethemer_settings_file'] = $file_path;
        variable_set('theme_' . $theme_key . '_settings', $theme_settings);
       // variable_set('livethemer_settings_file_' . $theme_key, $file_path);
      }
      else {
        $output  = '<div id="lt-inspector-home" class="error">';
        $output .= '<p>The Livethemer settings file could not be copied.</p>';
        $output .= '<p>Please check your file system configuration (';
        $output .= l('admin/config/media/file-system', 'admin/config/media/file-system') . ').</p>';
        $output .= '</div>';
        
        // Also put a message in the log.   
        watchdog('Livethemer', 'The Livethemer settings file could not be copied. Please check your file system configuration at ' . l('admin/config/media/file-system', 'admin/config/media/file-system'));
    
        return $output;
      }
    }
  }
  
  $hooks = get_filtered_variation_types();

  $list = array();
  foreach ($hooks as $hook => $variation_types) {
    $links = array();
    foreach ($variation_types as $variation_type) {
      $links[] = l($variation_type['title'], '',
        array('attributes' => array(
          'title' => $variation_type['description'], 
          'class' => 'lt-load-object', 
          'arg' => $variation_type['type'],
          'hook' => $hook,
          )
        )
      );
    }  
    $list[] = livethemer_hook_name($hook) . ' - ' . implode(', ', $links);
  }

  $output = '<div id="lt-inspector-home">';
  if ($list) {
    $output .= '<p class="lt-home">Click an object on the page to change its style, or select one of the following:</p>';
    $output .= theme('item_list', array('items' => $list, 'type' => 'ul', 'attributes' => array('class' => 'lt-javascript-link')));
  }
  else {
    $output .= '<p class="lt-home">There are no variations available for the current theme.</p>';
  }
  $output .= '</div>';
  
  return $output;
}
