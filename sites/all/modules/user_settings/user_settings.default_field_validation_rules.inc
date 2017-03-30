<?php
/**
 * @file
 * user_settings.default_field_validation_rules.inc
 */

/**
 * Implements hook_default_field_validation_rule().
 */
function user_settings_default_field_validation_rule() {
  $export = array();

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'bb booze blank';
  $rule->name = 'bb_booze_blank';
  $rule->field_name = 'field_booze_p2';
  $rule->col = 'value';
  $rule->entity_type = 'user';
  $rule->bundle = 'user';
  $rule->validator = 'field_validation_oneofseveral_validator';
  $rule->settings = array(
    'data' => '',
    'bypass' => 1,
    'roles' => array(
      1 => '1',
      4 => '4',
      3 => '3',
      2 => 0,
    ),
    'errors' => 0,
    'condition' => 0,
    'condition_wrapper' => array(
      'condition_field' => '',
      'condition_operator' => 'equals',
      'condition_value' => '',
    ),
  );
  $rule->error_message = 'Please click an option under the \'Gifting booze\' question';
  $export['bb_booze_blank'] = $rule;

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'bb Camp mates blank';
  $rule->name = 'bb_camp_mates_blank';
  $rule->field_name = 'field_moop_revised_burner_bio2';
  $rule->col = 'value';
  $rule->entity_type = 'user';
  $rule->bundle = 'user';
  $rule->validator = 'field_validation_oneofseveral_validator';
  $rule->settings = array(
    'data' => '',
    'bypass' => 1,
    'roles' => array(
      1 => '1',
      4 => '4',
      3 => '3',
      2 => 0,
    ),
    'errors' => 0,
    'condition' => 0,
    'condition_wrapper' => array(
      'condition_field' => '',
      'condition_operator' => 'equals',
      'condition_value' => '',
    ),
  );
  $rule->error_message = 'Please click an option under \'But do you your campmates know?\' ';
  $export['bb_camp_mates_blank'] = $rule;

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'bb Drone blank';
  $rule->name = 'bb_drone_blank';
  $rule->field_name = 'field_drone_update_p2';
  $rule->col = 'value';
  $rule->entity_type = 'user';
  $rule->bundle = 'user';
  $rule->validator = 'field_validation_oneofseveral_validator';
  $rule->settings = array(
    'data' => '',
    'bypass' => 1,
    'roles' => array(
      1 => '1',
      4 => '4',
      3 => '3',
      2 => 0,
    ),
    'errors' => 0,
    'condition' => 0,
    'condition_wrapper' => array(
      'condition_field' => '',
      'condition_operator' => 'equals',
      'condition_value' => '',
    ),
  );
  $rule->error_message = 'Please click an option under the question about Drones ';
  $export['bb_drone_blank'] = $rule;

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'bb MV blank';
  $rule->name = 'bb_mv_blank';
  $rule->field_name = 'field_mutant_registration_p2';
  $rule->col = 'value';
  $rule->entity_type = 'user';
  $rule->bundle = 'user';
  $rule->validator = 'field_validation_oneofseveral_validator';
  $rule->settings = array(
    'data' => '',
    'bypass' => 1,
    'roles' => array(
      1 => '1',
      4 => '4',
      3 => '3',
      2 => 0,
    ),
    'errors' => 0,
    'condition' => 0,
    'condition_wrapper' => array(
      'condition_field' => '',
      'condition_operator' => 'equals',
      'condition_value' => '',
    ),
  );
  $rule->error_message = 'Please click an option about Mutant Vehicles ';
  $export['bb_mv_blank'] = $rule;

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'bb pink blank';
  $rule->name = 'bb_pink_blank';
  $rule->field_name = 'field_pink_bangle_p2';
  $rule->col = 'value';
  $rule->entity_type = 'user';
  $rule->bundle = 'user';
  $rule->validator = 'field_validation_oneofseveral_validator';
  $rule->settings = array(
    'data' => '',
    'bypass' => 1,
    'roles' => array(
      1 => '1',
      4 => '4',
      3 => '3',
      2 => 0,
    ),
    'errors' => 0,
    'condition' => 0,
    'condition_wrapper' => array(
      'condition_field' => '',
      'condition_operator' => 'equals',
      'condition_value' => '',
    ),
  );
  $rule->error_message = 'Please click an option under the Pink Wristband question';
  $export['bb_pink_blank'] = $rule;

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'bb Plug and Play';
  $rule->name = 'bb_plug_and_play';
  $rule->field_name = 'field_bb_plug_and_play_2b';
  $rule->col = 'value';
  $rule->entity_type = 'user';
  $rule->bundle = 'user';
  $rule->validator = 'field_validation_oneofseveral_validator';
  $rule->settings = array(
    'data' => '',
    'bypass' => 1,
    'roles' => array(
      1 => '1',
      4 => '4',
      3 => '3',
      2 => 0,
    ),
    'errors' => 0,
    'condition' => 0,
    'condition_wrapper' => array(
      'condition_field' => '',
      'condition_operator' => 'equals',
      'condition_value' => '',
    ),
  );
  $rule->error_message = 'Please click an option under the question about Plug and Play';
  $export['bb_plug_and_play'] = $rule;

  return $export;
}
