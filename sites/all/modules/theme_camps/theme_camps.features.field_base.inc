<?php
/**
 * @file
 * theme_camps.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function theme_camps_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_compulsory_reading'.
  $field_bases['field_compulsory_reading'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_compulsory_reading',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'markup',
    'settings' => array(
      'markup' => array(
        'format' => 'filtered_html',
        'value' => '<p>Before you register your Theme Camp, please read through these important docs:</p>

<p><a href="http://www.afrikaburn.com/wp-content/uploads/2016/09/AB-Theme-Camp-Handbook.pdf" target="_blank">Theme Camp Handbook</a></p>

<p><a href="http://www.afrikaburn.com/wp-content/uploads/2016/09/Theme-Camp-Safety-Bullet-Points_Feb-2016.pdf" target="_blank">Theme Camp Safety</a></p>

<p><a href="http://afrikaburn.com/wp-content/uploads/2014/11/Theme-Camp-Placement-Guidelines-2015.pdf" target="_blank">Theme Camp Placement</a></p>

<p><a href="http://afrikaburn.com/wp-content/uploads/2014/03/Sound-Guidelines-AfrikaBurn-2015.pdf" target="_blank">Sound Policy</a></p>

<p><a href="http://www.afrikaburn.com/wp-content/uploads/2016/09/MOOP-Info-for-Theme-Camps.pdf" target="_blank">Moop Guidelines</a></p>
',
      ),
    ),
    'translatable' => 0,
    'type' => 'markup',
  );

  // Exported field_base: 'field_extention_of_default'.
  $field_bases['field_extention_of_default'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_extention_of_default',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'Yes' => 'Yes',
        'No' => 'No',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_moop_score'.
  $field_bases['field_moop_score'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_moop_score',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'moop_score',
          'parent' => 0,
        ),
      ),
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  // Exported field_base: 'field_performer_types'.
  $field_bases['field_performer_types'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_performer_types',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'performer_types',
          'parent' => 0,
        ),
      ),
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  // Exported field_base: 'field_tc_title_discription'.
  $field_bases['field_tc_title_discription'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_tc_title_discription',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'markup',
    'settings' => array(
      'markup' => array(
        'format' => 'filtered_html',
        'value' => '<p>This is the name of your Theme Camp, as it will appear on the map, event guide and everything else. If you change the name, please update this entry and let us know.</p>
',
      ),
    ),
    'translatable' => 0,
    'type' => 'markup',
  );

  return $field_bases;
}
