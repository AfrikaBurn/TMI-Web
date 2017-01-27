<?php
/**
 * @file
 * theme_camps.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function theme_camps_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tc_compulsory_reading|node|theme_camps|form';
  $field_group->group_name = 'group_tc_compulsory_reading';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'theme_camps';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Recommended Reading',
    'weight' => '0',
    'children' => array(
      0 => 'field_compulsory_reading',
      1 => 'title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Recommended Reading',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-tc-compulsory-reading field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tc_who_are_you|node|theme_camps|form';
  $field_group->group_name = 'group_tc_who_are_you';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'theme_camps';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Who are you?',
    'weight' => '1',
    'children' => array(
      0 => 'field_name_of_collective',
      1 => 'field_tc_title_discription',
      2 => 'field_creative_lead',
      3 => 'field_who_are_you_brief_bio_',
      4 => 'field_year_and_name_of_prev',
      5 => 'field_moop_score',
      6 => 'field_new_members_details',
      7 => 'field_new_members',
      8 => 'field_new_members_email',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => 'group-tc-who-are-you field-group-div',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups[''] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Recommended Reading');
  t('Who are you?');

  return $field_groups;
}
