<?php
/**
 * @file
 * artwork_registration.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function artwork_registration_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ar_building|node|artwork_registration|form';
  $field_group->group_name = 'group_ar_building';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'artwork_registration';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Building, Transport, Installation',
    'weight' => '6',
    'children' => array(
      0 => 'field_offsite_building',
      1 => 'field_transport',
      2 => 'field_on_site_building',
      3 => 'field_placement',
      4 => 'field_location_map',
      5 => 'field_location_picker',
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
        'classes' => 'group-ar-building field-group-div',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ar_lighting|node|artwork_registration|form';
  $field_group->group_name = 'group_ar_lighting';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'artwork_registration';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Lighting',
    'weight' => '7',
    'children' => array(
      0 => 'field_please_describe_your_light',
      1 => 'field_power_sources',
      2 => 'field_night',
      3 => 'field_image_project',
      4 => 'field_person_lighting',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Lighting',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-ar-lighting field-group-div',
        'description' => 'As an aesthetic element, and for safety reasons, it\'s mandatory to light your piece. Lighting protects it from accidental damage, and from accidentally damaging someone or something in the dark. You can go all out with parcans and a generator, or go green with solar power, go low-tech with candles in jars, or anything in between.',
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
  $field_group->identifier = 'group_ar_structure|node|artwork_registration|form';
  $field_group->group_name = 'group_ar_structure';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'artwork_registration';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'The Structure',
    'weight' => '5',
    'children' => array(
      0 => 'field_materials',
      1 => 'field_structural_safety',
      2 => 'field_team_structural_rep',
      3 => 'field_dimentions_m2',
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
        'classes' => 'group-ar-structure field-group-div',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ar_team|node|artwork_registration|form';
  $field_group->group_name = 'group_ar_team';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'artwork_registration';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'The Team',
    'weight' => '3',
    'children' => array(
      0 => 'field_contact_person',
      1 => 'field_creative_lead',
      2 => 'field_project_manager',
      3 => 'field_fundraiser',
      4 => 'field_if_in_south_africa_please_',
      5 => 'field_who_are_you_brief_bio_',
      6 => 'field_history',
      7 => 'field_new_members',
      8 => 'field_new_members_details',
      9 => 'field_new_members_email',
      10 => 'field_year_and_name_of_prev',
      11 => 'field_crew_members',
      12 => 'field_where_are_you_based',
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
        'classes' => 'group-ar-team field-group-div',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_burn|node|artwork_registration|form';
  $field_group->group_name = 'group_burn';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'artwork_registration';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Burn',
    'weight' => '9',
    'children' => array(
      0 => 'field_fire_person',
      1 => 'field_burn_safety_consideration',
      2 => 'field_burning_yn',
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
        'classes' => 'group-burn field-group-div',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_moop|node|artwork_registration|form';
  $field_group->group_name = 'group_moop';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'artwork_registration';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Moop',
    'weight' => '10',
    'children' => array(
      0 => 'field_moop_representative',
      1 => 'field_artwork_site_clean',
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
        'classes' => 'group-moop field-group-div',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_other|node|artwork_registration|form';
  $field_group->group_name = 'group_other';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'artwork_registration';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Other',
    'weight' => '11',
    'children' => array(
      0 => 'field_anything_else',
      1 => 'field_associated_projects',
      2 => 'field_applying_for_grant',
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
  $field_group->identifier = 'group_pr_sound|node|artwork_registration|form';
  $field_group->group_name = 'group_pr_sound';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'artwork_registration';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Sound',
    'weight' => '8',
    'children' => array(
      0 => 'field_sound_person',
      1 => 'field_sound_level',
      2 => 'field_does_it_have_sound_effects',
      3 => 'field_sound_description',
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
        'classes' => 'group-pr-sound field-group-div',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups[''] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('  The Project');
  t('Building, Transport, Installation');
  t('Burn');
  t('Lighting');
  t('Moop');
  t('Other');
  t('Sound');
  t('The Structure');
  t('The Team');

  return $field_groups;
}
