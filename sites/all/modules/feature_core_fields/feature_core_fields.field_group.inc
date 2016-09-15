<?php
/**
 * @file
 * feature_core_fields.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function feature_core_fields_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ar_project|node|artwork_registration|form';
  $field_group->group_name = 'group_ar_project';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'artwork_registration';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '  The Project',
    'weight' => '4',
    'children' => array(
      0 => 'field_describe_your_project',
      1 => 'field_philosophical_statement',
      2 => 'field_please_submit_concept_imag',
      3 => 'field_planned_activities',
      4 => 'field_website',
      5 => 'field_additional_docs',
      6 => 'field_do_you_have_a_stage',
      7 => 'field_stage_performers_dscr',
      8 => 'field_project_size',
      9 => 'field_performer_type',
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
        'classes' => 'group-ar-project field-group-div',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tc_about|node|theme_camps|form';
  $field_group->group_name = 'group_tc_about';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'theme_camps';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tell us about your camp',
    'weight' => '2',
    'children' => array(
      0 => 'field_describe_your_project',
      1 => 'field_extention_of_default',
      2 => 'field_please_submit_concept_imag',
      3 => 'field_philosophical_statement',
      4 => 'field_do_you_have_a_stage',
      5 => 'field_stage_performers_dscr',
      6 => 'field_performer_types',
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
        'classes' => 'group-tc-about field-group-div',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups[''] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('  The Project');
  t('Tell us about your camp');

  return $field_groups;
}
