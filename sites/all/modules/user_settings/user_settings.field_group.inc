<?php
/**
 * @file
 * user_settings.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function user_settings_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_bb_update|user|user|form';
  $field_group->group_name = 'group_bb_update';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Burner Bio Update',
    'weight' => '2',
    'children' => array(
      0 => 'field_moop_revised_burner_bio',
      1 => 'field_moop_revised_burner_bio2',
      2 => 'field_drone_update',
      3 => 'field_drone_update_p2',
      4 => 'field_mutant_registration_p1',
      5 => 'field_mutant_registration_p2',
      6 => 'field_pink_bangle_p1',
      7 => 'field_pink_bangle_p2',
      8 => 'field_booze_p1',
      9 => 'field_booze_p2',
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
        'classes' => 'group-bb-update field-group-div',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pledge|user|user|form';
  $field_group->group_name = 'group_pledge';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Pledge',
    'weight' => '3',
    'children' => array(
      0 => 'field_bb_pledge',
      1 => 'field_bb_agree',
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
        'classes' => 'group-pledge field-group-div',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_questionaire|user|user|form';
  $field_group->group_name = 'group_questionaire';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Questionaire',
    'weight' => '1',
    'children' => array(
      0 => 'field_bb_not_music_festival',
      1 => 'field_bb_ab_history',
      2 => 'field_bb_firstburn',
      3 => 'field_bb_partisipating',
      4 => 'field_bb_theme',
      5 => 'field_bb_principles',
      6 => 'field_bb_complete',
      7 => 'field_bb_aint_no_party',
      8 => 'field_bb_jol',
      9 => 'field_bb_read_survival_guide',
      10 => 'field_bb_haul',
      11 => 'field_bb_haul2',
      12 => 'field_bb_part_of',
      13 => 'field_bb_part_of1',
      14 => 'field_bb_madly_creative',
      15 => 'field_bb_ice',
      16 => 'field_moop_is_an_abbreviation_fo',
      17 => 'field_bb_leave_no_trace',
      18 => 'field_field_bb_leave_no_trace2',
      19 => 'field_bb_dressed',
      20 => 'field_bb_dressed1',
      21 => 'field_bb_drone',
      22 => 'field_bb_drone1',
      23 => 'field_bb_mutant',
      24 => 'field_bb_mutant1',
      25 => 'field_bb_pink',
      26 => 'field_bb_booze',
      27 => 'field_bb_booze1',
      28 => 'field_pink_arm_bands',
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
        'classes' => 'group-questionaire field-group-div',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_terms|user|user|form';
  $field_group->group_name = 'group_terms';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Terms and Conditions',
    'weight' => '5',
    'children' => array(
      0 => 'field_terms_and_conditions',
      1 => 'field_i_agree_to_the_terms_condi',
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
        'classes' => 'group-terms field-group-div',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user|user|user|form';
  $field_group->group_name = 'group_user';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Burner Bio Registration',
    'weight' => '4',
    'children' => array(
      0 => 'field_first_name',
      1 => 'field_last_name',
      2 => 'field_secondary_email_address',
      3 => 'field_sa_id_or_passport_number',
      4 => 'field_date_of_birth',
      5 => 'field_gaurdian',
      6 => 'field_bb_minors_yn',
      7 => 'field_bb_minors_details',
      8 => 'field_munciple_district',
      9 => 'field_gender',
      10 => 'field_mobile_number',
      11 => 'field_previous_envolvement',
      12 => 'field_other_burns',
      13 => 'field_where_are_you_based',
      14 => 'field_newsletter',
      15 => 'ckeditor',
      16 => 'account',
      17 => 'picture',
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
        'classes' => 'group-user field-group-div',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_welcome|user|user|form';
  $field_group->group_name = 'group_welcome';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '',
    'weight' => '0',
    'children' => array(
      0 => 'field_bb_preamble',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => '',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-welcome field-group-div',
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

  // Translatables
  // Included for use with string extractors like potx.
  t('Burner Bio Registration');
  t('Burner Bio Update');
  t('Pledge');
  t('Questionaire');
  t('Terms and Conditions');

  return $field_groups;
}
