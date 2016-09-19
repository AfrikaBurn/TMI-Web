<?php
/**
 * @file
 * performance_registration.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function performance_registration_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_building|node|performance_registration|form';
  $field_group->group_name = 'group_building';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'performance_registration';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Building, Transport, Installation',
    'weight' => '8',
    'children' => array(
      0 => 'field_offsite_building',
      1 => 'field_transport',
      2 => 'field_on_site_building',
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
        'classes' => 'group-building field-group-div',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_fire|node|performance_registration|form';
  $field_group->group_name = 'group_fire';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'performance_registration';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Fire',
    'weight' => '6',
    'children' => array(
      0 => 'field_fire_person',
      1 => 'field_burn_safety_consideration',
      2 => 'field_fire_yn',
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
        'classes' => 'group-fire field-group-div',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_moop|node|performance_registration|form';
  $field_group->group_name = 'group_moop';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'performance_registration';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Moop',
    'weight' => '52',
    'children' => array(
      0 => 'field_artwork_site_clean',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Moop',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-moop field-group-div',
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
  $field_group->identifier = 'group_other|node|performance_registration|form';
  $field_group->group_name = 'group_other';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'performance_registration';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Other',
    'weight' => '56',
    'children' => array(
      0 => 'field_anything_else',
      1 => 'field_other_creative_projects',
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
        'classes' => 'group-other field-group-div',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pr_lighting|node|performance_registration|form';
  $field_group->group_name = 'group_pr_lighting';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'performance_registration';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Lighting',
    'weight' => '4',
    'children' => array(
      0 => 'field_night',
      1 => 'field_trailer_lighting',
      2 => 'field_image_project',
      3 => 'field_person_lighting',
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
        'classes' => 'group-pr-lighting field-group-div',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pr_project|node|performance_registration|form';
  $field_group->group_name = 'group_pr_project';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'performance_registration';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'The Project',
    'weight' => '3',
    'children' => array(
      0 => 'field_describe_your_project',
      1 => 'field_philosophical_statement',
      2 => 'field_please_submit_concept_imag',
      3 => 'field_website',
      4 => 'field_planned_activities',
      5 => 'field_placement',
      6 => 'field_location_map',
      7 => 'field_location_picker',
      8 => 'field_related_project',
      9 => 'field_associated_projects',
      10 => 'field_additional_docs',
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
        'classes' => 'group-pr-project field-group-div',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pr_sound|node|performance_registration|form';
  $field_group->group_name = 'group_pr_sound';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'performance_registration';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Sound',
    'weight' => '5',
    'children' => array(
      0 => 'field_does_it_have_sound_effects',
      1 => 'field_sound_safety',
      2 => 'field_sound_level',
      3 => 'field_sound_person',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Sound',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-pr-sound field-group-div',
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
  $field_group->identifier = 'group_pr_team|node|performance_registration|form';
  $field_group->group_name = 'group_pr_team';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'performance_registration';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'The Team',
    'weight' => '2',
    'children' => array(
      0 => 'field_contact_person',
      1 => 'field_creative_lead',
      2 => 'field_project_manager',
      3 => 'field_fundraiser',
      4 => 'field_moop_representative',
      5 => 'field_crew_members',
      6 => 'field_if_in_south_africa_please_',
      7 => 'field_who_are_you_brief_bio_',
      8 => 'field_history',
      9 => 'field_year_and_name_of_prev',
      10 => 'field_new_members',
      11 => 'field_new_members_details',
      12 => 'field_new_members_email',
      13 => 'field_where_are_you_based',
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
        'classes' => 'group-pr-team field-group-div',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_structure|node|performance_registration|form';
  $field_group->group_name = 'group_structure';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'performance_registration';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'The Structure',
    'weight' => '7',
    'children' => array(
      0 => 'field_dimensions',
      1 => 'field_materials',
      2 => 'field_structural_safety',
      3 => 'field_team_structural_rep',
      4 => 'field_pr_structure_yn',
      5 => 'field_dimentions_m2',
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
        'classes' => 'group-structure field-group-div',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups[''] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Building, Transport, Installation');
  t('Fire');
  t('Lighting');
  t('Moop');
  t('Other');
  t('Sound');
  t('The Project');
  t('The Structure');
  t('The Team');

  return $field_groups;
}
