<?php
/**
 * @file
 * creative_grants.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function creative_grants_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_fund_raising|node|creative_grant_application|form';
  $field_group->group_name = 'group_fund_raising';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'creative_grant_application';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Fund Raising',
    'weight' => '15',
    'children' => array(
      0 => 'field_team_contributions',
      1 => 'field_would_you_like_to_give_us_',
      2 => 'field_application_amount',
      3 => 'field_other_funding',
      4 => 'field_other_funding_details',
      5 => 'field_short_fall_plan',
      6 => 'field_grant_other_info',
      7 => 'field_short_fall_plan_details',
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
        'classes' => 'group-fund-raising field-group-div',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_grant|node|creative_grant_application|form';
  $field_group->group_name = 'group_grant';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'creative_grant_application';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Creative Grant Application',
    'weight' => '1',
    'children' => array(
      0 => 'field_breakdown_of_expenses',
      1 => 'field_this_is_the_total_price_of',
      2 => 'field_registered_artwork',
      3 => 'title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Creative Grant Application',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-grant field-group-div',
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
  $field_group->identifier = 'group_spending_your_money|node|creative_grant_application|form';
  $field_group->group_name = 'group_spending_your_money';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'creative_grant_application';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Project Expenses',
    'weight' => '5',
    'children' => array(
      0 => 'field_material',
      1 => 'field_tools',
      2 => 'field_services',
      3 => 'field_locations',
      4 => 'field_health_safety',
      5 => 'field_transport_cost',
      6 => 'field_lighting',
      7 => 'field_pyrothecnics',
      8 => 'field_other_specify',
      9 => 'field_total',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Project Expenses',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-spending-your-money field-group-div',
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
  t('Creative Grant Application');
  t('Fund Raising');
  t('Project Expenses');

  return $field_groups;
}
