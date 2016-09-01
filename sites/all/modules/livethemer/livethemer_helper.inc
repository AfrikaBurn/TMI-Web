<?php
/**
 * @file livethemer_helper.inc helper functions.
 */

/**
 * Check to see if the Livethemer module should be active.
 */
function livethemer_allowed() {
  return (arg(0) != 'admin' && arg(0) != 'system');
}

/**
 * Check to see if the inspector should be enabled.
 */
function livethemer_inspector_allowed() {
  return (user_access('modify theme dynamically') && livethemer_allowed());
}

/**
 * Return everything we know about the provided variation, or if a key is provided, we
 * return that portion of the variation information. 
 *
 * @param $variation_id
 *    The variation ID whose path we want.
 * @param $key
 *    The array key within the variation array eg path.
 * @return variation ID path.
 */
function variation_info($variation_id, $key = NULL) {
  $variations = _discover_variations();
  
  return $key ? $variations[$variation_id][$key] : $variations[$variation_id];
}

/**
 * @param $hook_filter
 * 
 * @return
 * An array keyed by each theme hook used by the variation types. eg the "typography" variation type
 * uses the "page" hook, OR just the subpart of that array as specified by $hook.
 */
function get_variation_types_by_hook($hook_filter = FALSE) {
  // Work out the list of variation types which actually have available variations.
  $variations = _discover_variations();
  $types_with_variations = array();

  foreach ($variations as $variation) {
    $types_with_variations[] =  $variation['variation_type'];
  }
  $types_with_variations = array_unique($types_with_variations);

  // Bring in all the variation-types includes  
  $files = include_livethemer_variation_types();

  $hooks = array();
  foreach ($files as $file) {
    $variation_type_id = $file->name;
    if (in_array($variation_type_id, $types_with_variations)) {
      $variation_type = discover_variation_type($variation_type_id);
      
      if ($variation_type) {
        $variation_type_hooks = (array) $variation_type['hook']; 
        foreach ($variation_type_hooks as $hook) {
          $hooks[$hook][$variation_type_id] = $variation_type; 
        }
      }
    }
  }


  // Sort the variation types inside each hook by their #weight value.
  foreach ($hooks as $hook => $variation_types) {
    uasort($variation_types, 'element_sort'); // Use the Drupal API's element_sort() function.
    $hooks[$hook] = $variation_types;
  }


  if ($hook_filter) {
    // First, make sure it's an array.
    if (!is_array($hook_filter)) $hook_filter = array($hook_filter);
    
    $rt = array();
    foreach ($hook_filter as $filter) {
      if (isset($hooks[$filter])) {
        $rt += $hooks[$filter];
      }
    }  
  }
  if (isset($rt)) {
    return $rt;
  }
  else {
    return $hooks;
  }
}

/**
 * @param $variation_type_id
 * 
 * @return
 * All known information about the supplied variation type.
 */
function discover_variation_type($variation_type_id) {
  $function_prefix = str_replace('-', '_', $variation_type_id);
  $function_name = $function_prefix . '_lt_themable';
  if (function_exists($function_name)) {
    $variation_type = call_user_func($function_name);
    $hooks = (array) $variation_type['hook'];
    
/*
    foreach ($hooks as $hook) {
      if (function_exists($hook . '_scopes')) {
        $variation_type['specific scopes'] = call_user_func($hook . '_scopes');
      }
    }

    $variation_type['broad scopes'] = livethemer_broad_scopes();
*/
    
    return $variation_type;
  }
}

/**
 * Define the generic set of scopes. These are known as the "broad scopes" because they do not require
 * that a specific object on the page was selected.
 * 
 * @return array of broad scopes
 */
function livethemer_broad_scopes() {
  return array(
    'this_page' => array(
      'title' => t('This page'),
      'description' => t('This page only.'),
      'css_class' => 'this-page',
      ),
    'pages_in_this_path' => array(
      'title' => t('Pages in this path'),
      'description' => t('All pages in this path.'),
      'css_class' => 'pages-in-this-path',
      ), 
    'sitewide' => array(
      'title' => t('All sitewide'),
      'description' => t('All sitewide.'),
      'css_class' => 'sitewide',
    ),
  );
}


/**
 * 
 * @param $scope
 * @param $request_uri
 * 
 * @return
 * The scope or path
 */
function broad_scope_identifier($scope, $request_uri) {

  switch ($scope) {
    case 'this_page':
      // Remove the base-path, and if we're left with nothing, use "/" to signify root.
      $path = ltrim($request_uri, base_path());
      return $path ? $path : '/';
      break;
    
    case 'pages_in_this_path':
      $return_path = ltrim($request_uri, base_path()); 
      $path_pieces = explode('/', $return_path);
      $last_piece = array_pop($path_pieces); // array_pop() removes the last item from the array.
      $trimmed_path = implode('/', $path_pieces) . '/';
      return $trimmed_path;
      break;

    case 'sitewide':
      return 'sitewide';
      break;
    
    default:
      break;
  }
    
  return NULL;
}

/**
 * 
 * @param $variation_type_id
 * @param $scope
 * @param $info array of information about the object being themed. (could be a element array)  
 * 
 * @return the scope identifier.
 */
function get_scope_id($hook, $scope, $info) {
  // To cope with the fact that json calls have the wrong URI, we set up $calling_uri in our json functions.
  global $_lt_calling_uri;
  $uri = isset($_lt_calling_uri) ? $_lt_calling_uri : request_uri();
  
  $object_scope_identifier = NULL;
  // Check the specific scopes first.
  $function_name = $hook . '_scope_identifier';
  
  if (function_exists($function_name)) {
    $object_scope_identifier = call_user_func($function_name, $scope, $info, $uri);
  }
  
  // Also check the broad scopes.
  $broad_scope_identifier = broad_scope_identifier($scope, $uri);
  
  // We convert the scope IDs to strings so we don't have type conversion issues in the javascript
  return ($object_scope_identifier !== NULL) ? (string)$object_scope_identifier : (string)$broad_scope_identifier;
}

/**
 * Get the applied variations. helper function.
 * @param $element
 * @return $applied_variations array().
 */
function get_applied_variations($element, $hook) {
  $livethemer_variables = get_set_livethemer_variables();
 
  $applied_variations = array();  
//  foreach ($hooks as $hook) {
    $variation_types = get_variation_types_by_hook($hook);
    foreach ($variation_types as $variation_type_id => $variation_info) {
      if (isset($livethemer_variables[$hook][$variation_type_id])) {                                     
        $scopes_used = $livethemer_variables[$hook][$variation_type_id];
     
      // Look at each scope that has been set for this hook, and check if our currently-being-themed object
      // matches this scope. eg, if the "block" hook has a variation applied for the "footer" region of the
      // scope "this region", and the currently-being-themed object is a block in the footer region, we
      // have made a match and will theme this object accordingly.
        foreach ($scopes_used as $scope => $scope_records) {
          $object_scope_identifier = get_scope_id($hook, $scope, $element);
          if (isset($scope_records[$object_scope_identifier])) {
            // We have found a match; the currently-being-themed object has a variation to apply.
            $applied_variations[$hook][$variation_type_id] = $scope_records[$object_scope_identifier]; //was $scope_record
           
            // We only want one match per scope per variation_type.
            break; // was "break 2"

          }
        }
      }
    }
//  }  
  return $applied_variations;
}


/**
 * Add a class; different method required depending on whether this uses a theme function or a template
 *
 * @param $variables
 * @param $hook
 * @param $class
 */
function add_class_to_variables(&$variables, $hooks, $class) {
  $hooks_registry = theme_get_registry();
  $hooks = (array) $hooks;
  
  foreach ($hooks as $hook) {
    // If the hook uses a template, then we believe it *always* uses classes_array.
    if (isset($hooks_registry[$hook]['template'])) {
      $variables['classes_array'][] = $class;
    }
    // If it doesn't use a template, it can either specify an array of 'variables'
    elseif (isset($hooks_registry[$hook]['variables'])) {
      $variables['attributes']['class'][] = $class;
    }
    // ...or it mmust otherwise specify a render element. 
    else {
      $render_element = get_render_element_id($hook);
      if (isset($variables[$render_element])) {
        $variables[$render_element]['#attributes']['class'][] = $class;
      }
    }
  }
}

function get_render_element_id($hook) {
  $hooks_registry = theme_get_registry();
//  kpr($hooks_registry[$hook]);
  return isset($hooks_registry[$hook]['render element']) ? $hooks_registry[$hook]['render element'] : NULL;
}

/**
 * Include all the variation include files from the Livethemer theme. Then return 
 * an array of the include files.
 * 
 * @return array of variation include files.
 */
function include_livethemer_variation_types() {
  // Static caching.
  static $files;
  if ($files) {
    return $files;
  }

  $themes = list_themes();
  $path = drupal_get_path('module', 'livethemer') . '/variation-types';
  $files = drupal_system_listing('/\.inc$/', $path, 'name', 0);
  foreach ($files as $file) {
    include_once($path . '/' . $file->filename);
  }
  return $files;
}

/**
 * Returns an array of all valid variations, keyed by variation ID.
 *
 * We search for variations in several locations, and also ensure that
 * we only return vartiations which meet their individual theme and module
 * requirements.
 *
 * @param String $type
 * Optionally, we can filter the results by variation type.
 * @return
 * The variation arrays.
 */
function _discover_variations($type = NULL) {
  // Static caching of both "all variations" and "variations filtered by type".
  static $all_variations, $variations_by_type;

  // If a type was specified AND we have the right bit cached previously, return that.
  if (isset($type) && !empty($variations_by_type)) {
    return $variations_by_type[$type];
  }
  // If a type was NOT specified AND we have the right bit cached previously, return that.
  elseif (!isset($type) && !empty($all_variations)) {
    return $all_variations;
  }
  // Find all the .variation files; look for them inside /variations
  // and /modules/livethemer/variations, both of which can be in any valid Drupal
  // directory for such things eg sites/all/x, sites/default/x, x
  $files  = drupal_system_listing('/\.variation$/', 'variations', 'name', 0);
  $files += drupal_system_listing('/\.variation$/', 'libraries/variations', 'name', 0);
  $files += drupal_system_listing('/\.variation$/', drupal_get_path('module', 'livethemer') . '/variations', 'name', 0);

  foreach ($files as $filename => $file) {
    // Read the variation file.
    $variation_id = $filename;
    $variation = drupal_parse_info_file(dirname($file->uri) . '/' . $file->name . '.variation');

    // Record the path to the variation (used by our JS)
    $variation['differentiating_class'] = LT_CLASS_PREFIX . $variation_id; 
    $variation['path'] = dirname($file->uri) . '/'; 
    $variation['variation_id'] = $variation_id;

    // Check if the theme dependancy and current theme match.
    $theme_match = TRUE;
    $version_match = TRUE;
    if (isset($variation['theme_dependency'])) {
      // Get info about the current theme.
      global $theme_info;
      $current_theme_name = $theme_info->name;
      $current_theme_version = isset($theme_info->info['version']) ? $theme_info->info['version'] : NULL;
    
      // Get compatibility info from the .variation file.
      $key = array_keys($variation['theme_dependency']);
      $depend_theme_name = $key[0];
      $depend_theme = reset($variation['theme_dependency']); // reset returns the first element in the array.
      if (isset($depend_theme['version'])) {
        $depend_theme_version = $depend_theme['version'];
        $version_match = ($current_theme_version == $depend_theme_version) ? TRUE : FALSE;
      }
     
      // Work out what matches.
      $name_match = ($current_theme_name == $depend_theme_name) ? TRUE : FALSE;
      
      // Equates to FALSE unless both are true.
      $theme_match = $name_match && $version_match;
    }
    
    // Check for module dependancy.
    $modules_installed = TRUE;
    if (isset($variation['module_dependency'])) {
      
      // Go through all the listed modules in the .variation file. 
      foreach ($variation['module_dependency'] as $depend_module_name => $depend_module) {
        // Check the module exists first.
        if (module_exists($depend_module_name)) {
          $depend_module_version = $depend_module['version'];
          
          // Get info on the module.
          $installed_module = system_get_info('module', $depend_module_name);
          //$installed_module_name = str_replace('.module', '', $installed_module['files'][0]);
          $installed_module_version = $installed_module['version'];
          
          // Work out what matches.
          //$name_match = ($depend_module_name == $installed_module_name) ? TRUE : FALSE;
          $modules_installed_array[] = ($depend_module_version == $installed_module_version) ? TRUE : FALSE;
          
          // Equates to FALSE unless both are true.
          //$modules_installed_array[] = $name_match * $version_match;
        }
        else {
          $modules_installed_array[] = FALSE;
        }
      }
      $modules_installed = array_product($modules_installed_array);
    }

    if ($theme_match && $modules_installed) {
      // Cache it in two different structures, so we can use it in either way when
      // we need it next.
      $var_type = $variation['variation_type'];
      $variations_by_type[$var_type][$variation_id] = $variation;
      $all_variations[$variation_id] = $variation;
    }
  }

  if ($type) {
    return $variations_by_type[$type];
  }
  else {
    return $all_variations;
  }
}

/**
 * @param $property
 * @return the value of a property from the livethemer settings object.
 * 
 */
function lt_get_path($property) {
  static $settings;
  global $theme_key;
  
  $settings_file = theme_get_setting('livethemer_settings_file', $theme_key);
  
  // Get the settings file's ID. We are given the full filepath including both
  // protocol, full file path, and ".settings".
  $last_slash_pos = strripos($settings_file, '/');
  $last_dot_pos = strripos($settings_file, '.');
  $length = $last_dot_pos - $last_slash_pos;
  $file_name = substr($settings_file, $last_slash_pos, $length);

  $settings['overrides_css'] = 'public://' . $file_name . '-overrides.css';
  
  // If the system variable is a dash then return null, same as if the var doesn't exist.
  $settings['data_file'] = ($settings_file == '-') ? NULL : $settings_file;
  
  if (variable_get('lt_development', FALSE)) {
    // TODO: remove? jh - 19 Feb 2011
    // For development, I need to be able to blow away the livetheme file every
    // minute or so. This makes it much easier.
           
    // If the data file doesn't exist, copy it from the default.settings in the module directory.
    if (!file_exists($settings['data_file'])) {
      $new_empty_file = 'public://testing.settings';
      file_put_contents($new_empty_file, array());
      
      $theme_settings =  variable_get('theme_' . $theme_key . '_settings', NULL);
      $theme_settings['livethemer_settings_file'] = $new_empty_file;
      variable_set('theme_' . $theme_key . '_settings', $theme_settings);
    }
  }

  return isset($settings[$property]) ? $settings[$property] : FALSE;
}

//todo - move back to livethemer.module
/**
 * @param $applied_variations
 * @return template $variables
 */
function set_template_vars(&$variables, $hook, $applied_variations) {
  $variations = _discover_variations();
  foreach ($applied_variations as $variation_type_id => $variation_info) {
    // Load everything we know about this variation.
    $variation_id   = $variation_info['variation_id'];
    $variation_data = $variation_info['variation_data'];
    if (isset($variations[$variation_id])) {
      // Retrieve all the theme's variations then get the one we're interested in.
      $variation = $variations[$variation_id];
     
    
      // Add our new information to $variables.
      if (isset($variation['template_file'])) {
        $template_file = $variation['template_file'];
        $variables['theme_hook_suggestions'][] = strtr($template_file, '-', '_');
        //$variables['theme_hook_suggestion'] = strtr($template_file, '-', '_'); 
      }
      
/*
      $variation_type = discover_variation_type($variation_type_id);
      $hooks = (array) $variation_type['hook'];
*/

      $class = LT_CLASS_PREFIX . $variation_id;
      add_class_to_variables($variables, $hook, $class);
  
      if ($variation_info['variation_data_class']) {
        add_class_to_variables($variables, $hook, $variation_info['variation_data_class']);
      }

      // Check the $variation_data values against the settings form for this variation, and act accordingly.
      //$function_name = include_variation_settings_form($variation);
      //if ($function_name && $variation_data) {
      if ($variation_data) {
       // print_r($variation); exit();
        $form = get_settings_form($variation);
        if ($form) {
          // $form = call_user_func($function_name, array());
          $form = flatten_form_array($form);
  
          // Go through each record of the $variation_data and process it.
          foreach ($variation_data as $field_id => $value) {
            if (isset($form[$field_id])) {
              $field = $form[$field_id];
              if ($field['#attributes']['update_action'] == 'tpl_variable_css_class') {
                $raw_class = $field['#attributes']['css_class'];
                $class = str_replace('%' . $field_id . '%', $value, $raw_class);
                
                // 
                if (function_exists('modify_for_inspector')) $class = modify_for_inspector($class);
  
                $variable_name = $field['#attributes']['tpl_variable'];
                if ($variable_name) {
                  $variables[$variable_name] = $class;
                }
                else {
                  $variables['lt_classes_array'][$field_id] = $class;
                  //add_class_to_variables($variables, $hook, $class);
                }
              }
            }
          }
        }
      }
    }
  } 
}

/**
 * Flatten the supplied FAPI form array, by removing the nesting of elements from inside fieldset array elements.
 * 
 * Warning: this function has a known limitation; if two FAPI fields are separately nested and have the same key,
 * this flattening function will actually only return the last found, which will overwrite any earlier fields found
 * with the same key.
 *
 * @param array $form
 * @return flatterned array (One level).
 */
function flatten_form_array($form) {
  $return = array();
  
  $children = element_children($form);
  foreach ($children as $key) {
    $grandchildren = element_children($form[$key]);
    if ($grandchildren) {
      $return = array_merge($return, flatten_form_array($form[$key]));
    }
    else {
      $return[$key] = $form[$key];
    }
  }
  
  return $return;
}

/** TODO: move to livethemer_inspector.module?
 * Find all the image files in the current theme's images directory. We narrow the search if
 * the optional directory argument is specified. 
 *
 * @param $subdirectory
 * @return array of image files.
 */

  
/*
$options = get_images_options(array(
  t('Tiles')        => '/tiles',
  t('Headers')      => '/headers',
));
*/

/*
function get_images_options($filters) {
  $options = array();
  $options['-'] = '-';
  
  foreach ($filters as $filter_title => $filter) {
    $files  = drupal_system_listing('/./', 'variations/images'. $filter, 'name', 0);
    $files += drupal_system_listing('/./', 'modules/livethemer/variations/images'. $filter, 'name', 0);
    foreach ($files as $file) {
      $info = image_get_info($file->uri);
      if ($info) {
        $options[$filter_title][$file->uri] = $file->name;
      }
    }
  }
    
  return $options;
}
*/

/**
 * Function_comment
 *
 * "pseudo stream wrappers"
 *
 * module://jeff.png - the Livethemer module comes with a variations/images subdirectory.
 * images://tiles/jefftile.png - the images folder must be in the public files directory.
 * variation-id:// - variations may provide their own images. These must be in an images subdirectory of the variation.
 *
 */
function get_global_images($filters = array('Headers' => '/headers', 'Tiles' => '/tiles', 'Icons' => '/icons')) {
  $options = array();
  $options['-'] = '-';

  $module_path = pseudo_stream_path('module');
  $filesimages_path = pseudo_stream_path('filesimages');;

  foreach ($filters as $filter_title => $filter_path) {
    $files  = drupal_system_listing('/./', $filesimages_path . $filter_path, 'name', 0);    
    $files += drupal_system_listing('/./', $module_path . '/variations/images' . $filter_path, 'name', 0);
    
    $files = add_pseudo_stream_info($files, 
      array(
        'filesimages' => $filesimages_path,
        'module' => $module_path,
      )
    );

    $images = _get_images($files);
    
    if (!empty($images)) {
      if (is_array($filters)) {
        $options[$filter_title] = $images;
      }
      else {
        $options = $images;
      }
    }
  }
  
  return $options;
}

/**
 * Variations can optionally supply images. Those images are found in an images
 * subdirectory only accessible by the variation that supplied them. They will
 * have a "pseudo stream" that is the variation ID. For example: sticky-note://
 * will refer to images that are found somewhere like:
 * sites/all/variations/block-designs/sticky-note/images/
 */
function get_images_from_variation($variation_id) {
  $variation_images_path = pseudo_stream_path($variation_id);  
  $options = array();
  $options['-'] = '-';
  
  // We just want to look for images contained in one variation.
  $files = file_scan_directory($variation_images_path, '/.*(png|jpg|gif)/');
  $files = add_pseudo_stream_info($files,
    array(
      $variation_id => $variation_images_path,
    )
  );
  
  $options = _get_images($files);
 
  return $options;
}

/**
 * Go through each supplied file, checking its path to see if it matches one of
 * the provided "pseudo stream wrapper" paths. If it does, record it's pseudo_stream
 * and relative_uri (which is its original path minus the path to the pseudo_stream's path).
 */
function add_pseudo_stream_info($files, $pseudo_streams = array()) {
  foreach ($files as $file) {
    // Work out which stream this file matches.
    foreach ($pseudo_streams as $pseudo_stream_id => $pseudo_stream_path) {
      // Does this file's path begin with the stream's path
      if (strpos($file->uri, $pseudo_stream_path) === 0) {
        $file->pseudo_stream = $pseudo_stream_id;
        $file->relative_uri = str_replace($pseudo_stream_path . '/', '', $file->uri);
        break; // Don't keep looking at the other URI's.
      }
    }  
  }
  return $files;
}

/**
 * Returns the real path, relative to Drupal root, of the provided URI.
 * Our "pseudo streams" such as images://, module:// or variation-id://
 * are decoded appropriately.
 */
function real_path_from_pseudo_stream($uri) {
  $parts = explode('://', $uri);
  if (count($parts) == 2) {
    $stream_id = $parts[0];
    $relative_path = $parts[1];
    
    $uri = pseudo_stream_path($stream_id) . '/' . $relative_path;
  }
  
  return $uri;
}

/**
 * Returns the path of the provided "pseudo stream" (relative to Drupal root).
 */
function pseudo_stream_path($stream_id) {
  switch ($stream_id) {
    case 'filesimages':
      return variable_get('file_public_path', conf_path() . '/files') . '/images';

    case 'module':
      return drupal_get_path('module', 'livethemer');

    default:
      // Check if the $stream_id is a known variation id. If so, return the path
      // to that variation.
      $variation_id = $stream_id;
      $path = variation_info($variation_id, 'path');
      if (isset($path)) return $path . 'images';
  }
}

/**
 *  Helper function to return an options array of images for a given path.
 * 
 * @param string $psuedo_uri specifies one of our pseudo stream wrapper types e.g. image, module, or a variation-id.
 * @param string $starting_dir
 */
function _get_images($files) {
  $options = array();

  foreach ($files as $file) {
    $info = image_get_info($file->uri);
    
    if ($info) {
      $psuedo_path = $file->pseudo_stream  . '://' . $file->relative_uri;
      $options[$psuedo_path] = $file->name;
    }
  }
  return $options;
}


/**
 * Wrapper functions for the datafile function. The datafile is a keyed array, and we want 
 * to be able to retrieve the keyed parts separately. 
 */
function get_set_livethemer_variables($set_variables = NULL) {
  return get_set_datafile('livethemer_variables', $set_variables);
}

function get_set_livethemer_metadata($set_metadata = NULL) {
  return get_set_datafile('metadata', $set_metadata);
}

function get_set_datafile($data_type = NULL, $new_data = NULL) {
   // Check we should be running. If not, return an empty array, as though
   // we have an empty settings file.
   if (!livethemer_allowed()) return array();

  // If we were passed some variables to set then serialise and save the data.
  if ($new_data) {
    $settings_data = read_write_settings_file();
    
    // Allow to either replace one part of the array, or all of it.
    if (isset($data_type)) {
      $settings_data[$data_type] = $new_data;
    }
    else {
      $settings_data = $new_data;
    }

    // Temporary code. Ultimately this should be user-facing via a settings administration area.
    if (!isset($settings_data['metadata'])) {
      $settings_data['metadata']['name'] = "Livethemer default";
      $settings_data['metadata']['version'] = "7.0.0";
    }
    
    read_write_settings_file($settings_data);

    // If a data type was passed return just that part of the array, otherwise return everything.
    return $data_type ? $settings_data[$data_type] : $settings_data;
  }
  // We're not setting any data so return existing from cache.
  else {
    $settings_data = read_write_settings_file();
    // If $settings_data[$data_type] is set then return it, otherwise just return an empty array.
    return (isset($settings_data[$data_type])) ? $settings_data[$data_type] : array();
  }
}

function read_write_settings_file($data_to_save = NULL, $settings_file = NULL) {
  static $settings_data;
  static $error_reported = FALSE;

  $file = isset($settings_file) ? $settings_file : lt_get_path('data_file');
  
  if ($data_to_save) {
    $settings_data = $data_to_save;
    if (empty($file)) watchdog('Livethemer', 'An empty file name was received by read_write_settings_file');
    file_unmanaged_save_data(serialize($settings_data), $file, FILE_EXISTS_REPLACE);
    return $settings_data;
  }
  elseif (empty($settings_file) && !empty($settings_data)) {
    return $settings_data;
  }
  else {
    // If $file is NULL we don't want to do anything else. 
    if ($file) {
      $file = drupal_realpath($file);
      // If we have a filepath, check that it exists, if it does then grab the contents of it.
      if (file_exists($file)) {
        $settings_data = unserialize(file_get_contents($file));
      }
      elseif ($error_reported !== TRUE) { 
        global $theme_info;
        $error_reported = TRUE; // Can't rely on the FALSE in dsm() because the l() function will send us back in here.
        
        // We can't load the file so set a message and let the user know.
        $theme_settings_page = l(t('theme settings page'), 'admin/appearance/settings/' . $theme_info->name);
        $message = t('Livethemer could not load the data file for the current theme (!theme_name). It may have been moved. Please visit the !theme_settings_page for !theme_name to set one.', array('!theme_name' => $theme_info->info['name'], '!theme_settings_page' => $theme_settings_page));
        drupal_set_message($message, 'error', FALSE);
      }
    }     
    return $settings_data;
  }
}

/**
 * @param String $needle
 * @param Array $elements
 * @return the array containing needle as a key or FALSE;
 */
function get_array_section($needle, $elements) {
  foreach ($elements AS $key => $value) { 
    if ($key === $needle) {
        return $elements;   
    } 
    if (is_array($value)) { 
      if (($result = get_array_section($needle, $value)) !== FALSE) {
        return $result; 
      }
    } 
  } 
  return FALSE; 
}

/**
 * runs a given function on each element of an array.
 * @param array $element
 * @param String $function_name
 */
function recursively_modify_render_array(&$element, $function_name) {  
  // If this element has children, deal with those.
  $children_keys = element_children($element);
  foreach ($children_keys as $key) {    
    recursively_modify_render_array($element[$key], $function_name);
  }
  // Make the actual changes to this one element.
  $element = call_user_func($function_name, $element);
  return $element;
}

function get_settings_form($variation) {
  $form = array();

  // Get the form from the variation type, if it has one.
  $safe_variation_type_id = str_replace('-', '_', $variation['variation_type']);
  $function_name = $safe_variation_type_id . '_settings_form';
  include_livethemer_variation_types();
  
  if (function_exists($function_name)) {
    $form = call_user_func($function_name);
  }

  // Get the form from the variation, if it has one.
  $function_name = include_variation_settings_form($variation);
  if (function_exists($function_name)) {
    $form = call_user_func($function_name, $form);
  }
  
  if ($form) {
    $form = recursively_modify_render_array($form, 'lt_set_option_default');
    
    // Add "Apply" and "Cancel" buttons to every form.
    $button_markup  = '<span class="apply-button"></span>';
    $button_markup .= '<span class="cancel-button"></span>';
  
    $form['buttons'] = array(
      '#markup' => $button_markup,
      '#weight' => 10,
    );
  }
  
  return empty($form) ? FALSE : $form;
}

/**
* Go through each of the select elements and mark the default with "~" 
* which signifies the variation default.
*/
function lt_set_option_default(&$form_element) {
  if (isset($form_element['#type']) && $form_element['#type'] == 'select') {
    $default = $form_element['#default_value'];
    if ($default != '' && $default != '-' && isset($form_element['#options'][$default])) {
      $form_element['#options'][$default] = $form_element['#options'][$default] . " ~";
    }  
  }
  return $form_element;
}

/**
 * Include the settings form for the supplied variation, and return the function name to call
 * to generate the form.
 *
 * @param array $variation
 */
function include_variation_settings_form($variation) {
  if (isset($variation['settings_form'])) {
    // Include the settings form definition code.
    include_once($variation['path'] . $variation['settings_form']);
    
    // Run the code to retrieve the $form.
    $safe_variation_id = str_replace('-', '_', $variation['variation_id']);
    $function_name = $safe_variation_id . '_settings_form';
    if (function_exists($function_name)) {
      return $function_name;
    }
  }
  
  return FALSE;
}

/**
 * Function_comment
 */
function initialise_array(&$array, $keys = array()) {
/*
  if (!isset($css_rules[$css_weight]) || !is_array($css_rules[$css_weight])) {
    $css_rules[$css_weight] = array();
  }
  if (!isset($css_rules[$variation_id]) || !is_array($css_rules[$variation_id])) {
    $css_rules[$variation_id] = array();
  }
  if (!isset($css_rules[$variation_id][$field_id]) || !is_array($css_rules[$variation_id][$field_id])) {
    $css_rules[$variation_id][$field_id] = array();
  }
  initialise_array($css_rules, array($css_weight, $variation_id, $field_id));
*/
  foreach ($keys as $key) {
    if (!isset($array[$key]) || !is_array($array[$key])) {
      $array[$key] = array();
      initialise_array($array[$key]);
    }
  }
}

/**
 * Create a CSS file containing any CSS rules required to replicate the settings chosen in any
 * variation's settings form fields.
 * 
 * @param unknown_type $file
 * @param unknown_type $format
 */
function generate_custom_css_file($format = 'file') {
  global $theme_key;

  $livethemer_variables = get_set_livethemer_variables();
  $variations = _discover_variations();
  $form = array();
  $css_rules = array();
  $css_array = array();
  $css = '';

  foreach ($livethemer_variables as $variation_type_ids) {
    foreach ($variation_type_ids as $scopes) {
      foreach ($scopes as $scope_records) {
        foreach ($scope_records as $item) {
          $variation_data = $item['variation_data'];
         
          if ($variation_data) {
            $variation_id = $item['variation_id'];
            if (isset($variations[$variation_id])) { 
              $variation = $variations[$variation_id];
              $css_weight = livethemer_inspector_get_css_weight($variation['variation_type']);
              $form = get_settings_form($variation);
              $form = flatten_form_array($form);
     
              // Prepare to do a "find-and-replace" of all the placeholders in the rule, inserting values
              // from the $livethemer_variables where required.          
              $replacement_tokens = (array)$variation_data;              
              $replacement_tokens['basepath'] = base_path(); 
              
              $placeholders = array();
              $token_values = array();

              foreach ($replacement_tokens as $token_variable => $token_value) {
                // First, see if this variation_data value starts with one
                // of our "pseudo streams" such as images://, module:// or variation-id://
                $token_value = real_path_from_pseudo_stream($token_value);

                $placeholders[] = '%' . $token_variable . '%';     
                $token_values[] = $token_value;
              } 
              
              // Build up string of CSS information, in order to build a CSS file to the user's
              // chosen settings form field values. First, go through each form field and check
              // if it is 'update_action' => 'css'. If it is, get its 'css_target' and 'css_rule'
              //
              // eg 'css_target' => '#header',
              //    'css_rule' => 'background-repeat:%header_background_repeat%;',
              //
              // and build up an string of CSS rules.
              foreach ($variation_data as $field_id => $value) {
                if (isset($form[$field_id]) && $value !='' && $value != NULL && $value != '-') { 
                  $field = $form[$field_id];
                  if ($field['#attributes']['update_action'] == 'css') {
                    $target = '';
                    if ($item['variation_data_class']) $target .= '.' . $item['variation_data_class'] . ' ';
                    $target .= $field['#attributes']['css_target'];
                    $target = trim($target); // Remove any whitespace due to variations of the above combinations.
                    
                    $rule = str_replace($placeholders, $token_values, $field['#attributes']['css_rule']);
                    
                    //need to clean up styles that have been set to none and were expecting a url.
                    if (strpos($rule, 'none') !== FALSE and strpos($rule, 'url(') !== FALSE) {
                      $rule = substr_replace($rule, 'none;', strpos($rule, ':')+1);
                    }
                    
                    $css_array[$css_weight][$target][] = $rule;

                    if ($rule  && $format == 'array') {
                      // todo: initialise_array($css_rules, array($css_weight, $variation_id, $field_id));
                      if (!isset($css_rules[$variation_id][$field_id][$target])) {
                        $css_rules[$css_weight][$variation_id][$field_id][$target] = "  $rule\n";
                      }
                      else {
                        $css_rules[$css_weight][$variation_id][$field_id][$target] .= "  $rule\n";
                      }  
                    }
                  }
                }
              }             
            }
            else {
              watchdog('Livethemer', 'In generate_custom_css_file we could not find the variation with id: ' . $variation_id);
            }
          }
        }
      }
    }
  }
  
  //This needs to be outside the loops so we don't suffer duplication.
  ksort($css_array);
  foreach ($css_array as $weight => $style_block) {
    foreach ($style_block as $target => $rules) {
      $css .= "$target {";
      $css .= "/* $weight */";
      foreach ($rules as $rule) {
        $pos = strpos($rule, 'rgba(');
        if ($pos !== FALSE) {
          //fallback to rgb.
          $newrule = substr_replace($rule, 'rgb(', $pos, 5);
          $lc= strripos($newrule, ',');
          $lb = strpos($newrule, ')');
          $newrule = substr_replace($newrule, '', $lc, $lb - $lc);
          $css .= "\n$newrule";
          watchdog('LT', $newrule);
        }
        $css .= "\n$rule";
      }
      $css .= "\n}\n\n";  
    } 
  }
  if ($format == 'array') {
    return $css_rules;
  }
  else{
    // If we are not generating this for the javascript then we
    // always want a css file, even if it's empty.
  
    // Generate a custom CSS file, and return the file object if it was successfully created.
    $file = lt_get_path('overrides_css');
    //variable_set($theme_key . '-overrides', $file);
    return file_unmanaged_save_data($css, $file, FILE_EXISTS_REPLACE);
  }
}


function livethemer_inspector_get_css_weight($variation_type) {
// Get the form from the variation type, if it has one.
  $safe_variation_type_id = str_replace('-', '_', $variation_type);
  $function_name = $safe_variation_type_id . '_lt_themable';
  include_livethemer_variation_types();
  $css_weight = 0;
  if (function_exists($function_name)) {
    $variation_type_array = call_user_func($function_name);
    $css_weight = $variation_type_array['#css_weight']? $variation_type_array['#css_weight']: 0;
  }
  return $css_weight;
} 
