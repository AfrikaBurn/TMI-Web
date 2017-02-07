<?php

/**
 * Implements hook_views_data_alter().
 */
function multifield_views_data_alter(array &$data) {
  // Remove any references to the fake multifield table.
  unset($data['multifield']);
  unset($data['entity_multifield']);
  unset($data['views_entity_multifield']);
  foreach ($data as &$table) {
    unset($table['table']['join']['multifield']);
    unset($table['table']['default_relationship']['multifield']);
  }
}

/**
 * Implements hook_field_views_data().
 */
function multifield_field_views_data($field) {
  $field_name = $field['field_name'];
  $machine_name = multifield_extract_multifield_machine_name($field);
  $subfield_names = multifield_type_get_subfields($machine_name);
  $data = field_views_field_default_views_data($field);
  $all_subfield_data = _multifield_subfield_views_data($field);

  foreach ($data as &$table) {
    if (isset($table[$field_name]['field'])) {
      foreach ($subfield_names as $subfield_name) {
        $subfield = field_info_field($subfield_name);
        $subfield_data = $all_subfield_data[$subfield_name];
        $new_name = $field_name . '_' . $subfield_name;
        $f_data = $subfield_data['field_data_' . $subfield_name][$subfield_name];
        $f_data['table'] = $table[$field_name]['field']['table'];
        $f_data['field']['table'] = $table[$field_name]['field']['table'];
        $f_data['field']['entity_tables'] = $table[$field_name]['field']['entity_tables'];
        foreach ($f_data['field']['additional fields'] as $index => &$_additional) {
          if (!in_array($_additional, array('delta', 'language', 'bundle'))) {
            $_additional = $field_name . '_' . $_additional;
          }
        }
        foreach ($f_data['field']['additional fields'] as $index => $additional) {
          if (!in_array($additional, array('delta', 'language', 'bundle'))) {
            $source_field = substr($f_data['field']['additional fields'][$index], strlen($field_name . '_'));
            if (($key = array_search($f_data['field']['additional fields'][$index], $table[$field_name]['field']['additional fields'])) !== false) {
              unset($table[$field_name]['field']['additional fields'][$f_data['field']['additional fields'][$index]]);
            }
            $table[$f_data['field']['additional fields'][$index]]['field'] = $f_data['field'];
            $table[$f_data['field']['additional fields'][$index]]['field']['handler'] = 'MultifieldViewsHandler';
            $table[$f_data['field']['additional fields'][$index]]['field']['subfield_name'] = $f_data['field']['field_name'];
            $table[$f_data['field']['additional fields'][$index]]['field']['field_name'] = $field_name;
            if (isset($subfield_data['field_data_' . $subfield_name][$source_field]['field'])) {
              $table[$f_data['field']['additional fields'][$index]]['field']['subfield handler'] = $subfield_data['field_data_' . $subfield_name][$source_field]['field']['handler'];
            }
            else {
              $table[$f_data['field']['additional fields'][$index]]['field']['subfield handler'] = $f_data['field']['handler'];
            }
            foreach (array('argument', 'filter', 'sort') as $handler) {
              if (isset($subfield_data['field_data_' . $subfield_name][$source_field][$handler]) && isset($table[$f_data['field']['additional fields'][$index]][$handler])) {
                // Overwrite field_name.
                $table[$f_data['field']['additional fields'][$index]][$handler]['field_name'] = $subfield_data['field_data_' . $subfield_name][$source_field][$handler]['field_name'];
                // Overwrite handler.
                $table[$f_data['field']['additional fields'][$index]][$handler]['handler'] = $subfield_data['field_data_' . $subfield_name][$source_field][$handler]['handler'];
                // Add additional options without overwriting table etc.
                $table[$f_data['field']['additional fields'][$index]][$handler] += $subfield_data['field_data_' . $subfield_name][$source_field][$handler];
              }
            }
            if (isset($subfield_data['field_data_' . $subfield_name][$source_field]['relationship'])) {
              $table[$f_data['field']['additional fields'][$index]]['relationship'] = $subfield_data['field_data_' . $subfield_name][$source_field]['relationship'];
            }
          }
        }
        $table[$new_name] = $f_data;
        $table[$new_name]['field']['handler'] = 'MultifieldViewsHandler';
        $table[$new_name]['field']['subfield_name'] = $f_data['field']['field_name'];
        $table[$new_name]['field']['field_name'] = $field_name;
        $table[$new_name]['field']['subfield handler'] = $f_data['field']['handler'];
      }
    }
  }
  return $data;
}

function _multifield_subfield_views_data($field) {
  $data = array();
  $machine_name = multifield_extract_multifield_machine_name($field);
  foreach (multifield_type_get_subfields($machine_name) as $subfield_name) {
    $subfield = field_info_field($subfield_name);
    if ($subfield['storage']['type'] != 'field_sql_storage') {
      continue;
    }

    $result = (array) module_invoke($subfield['module'], 'field_views_data', $subfield);

    if (empty($result)) {
      $result = field_views_field_default_views_data($subfield);
    }
    drupal_alter('field_views_data', $result, $subfield, $subfield['module']);
    $data[$subfield_name] = $result;
  }

  return $data;
}
