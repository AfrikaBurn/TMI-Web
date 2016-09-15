<?php
/**
 * @file
 * theme_camps.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function theme_camps_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-theme_camps-field_compulsory_reading'.
  $field_instances['node-theme_camps-field_compulsory_reading'] = array(
    'bundle' => 'theme_camps',
    'custom_add_another' => '',
    'custom_remove' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'markup',
        'settings' => array(),
        'type' => 'markup_default',
        'weight' => 18,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_compulsory_reading',
    'label' => 'Compulsory reading!',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'markup',
      'settings' => array(),
      'type' => 'markup',
      'weight' => 11,
    ),
  );

  // Exported field_instance: 'node-theme_camps-field_extention_of_default'.
  $field_instances['node-theme_camps-field_extention_of_default'] = array(
    'bundle' => 'theme_camps',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Is your camp as a platform for marketing or branding exercise? Stop right there: that\'s not going to happen.

Please read up on the <a href="http://afrikaburn.com/about/guiding-principles" target="_blank"> guiding principles </a> of AfrikaBurn to find out why.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 8,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_extention_of_default',
    'label' => 'Is your Theme Camp an extension of the default world?',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'node-theme_camps-field_moop_score'.
  $field_instances['node-theme_camps-field_moop_score'] = array(
    'bundle' => 'theme_camps',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'If you were part of a Theme Camp in 2016 what was your <a href="http://www.afrikaburn.com/binnekringblog/moop-map-2016" target="_blank"> MOOP map </a> rating?<br>
Red, Yellow, Green',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 6,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_moop_score',
    'label' => 'Moop Map score in 2016',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'taxonomy',
      'settings' => array(
        'autocomplete_path' => 'taxonomy/autocomplete',
        'size' => 60,
      ),
      'type' => 'taxonomy_autocomplete',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'node-theme_camps-field_performer_types'.
  $field_instances['node-theme_camps-field_performer_types'] = array(
    'bundle' => 'theme_camps',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 21,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_performer_types',
    'label' => 'Performer types',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'node-theme_camps-field_tc_title_discription'.
  $field_instances['node-theme_camps-field_tc_title_discription'] = array(
    'bundle' => 'theme_camps',
    'custom_add_another' => '',
    'custom_remove' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'markup',
        'settings' => array(),
        'type' => 'markup_default',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_tc_title_discription',
    'label' => 'What\'s the name of the Theme Camp?',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'markup',
      'settings' => array(),
      'type' => 'markup',
      'weight' => 2,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Compulsory reading!');
  t('If you were part of a Theme Camp in 2016 what was your <a href="http://www.afrikaburn.com/binnekringblog/moop-map-2016" target="_blank"> MOOP map </a> rating?<br>
Red, Yellow, Green');
  t('Is your Theme Camp an extension of the default world?');
  t('Is your camp as a platform for marketing or branding exercise? Stop right there: that\'s not going to happen.

Please read up on the <a href="http://afrikaburn.com/about/guiding-principles" target="_blank"> guiding principles </a> of AfrikaBurn to find out why.');
  t('Moop Map score in 2016');
  t('Performer types');
  t('What\'s the name of the Theme Camp?');

  return $field_instances;
}
