<?php
/**
 * @file
 * user_settings.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function user_settings_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access all views'.
  $permissions['access all views'] = array(
    'name' => 'access all views',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'views',
  );

  // Exported permission: 'access private fields'.
  $permissions['access private fields'] = array(
    'name' => 'access private fields',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'access user profiles'.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      'Support' => 'Support',
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer exclude node title'.
  $permissions['administer exclude node title'] = array(
    'name' => 'administer exclude node title',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'exclude_node_title',
  );

  // Exported permission: 'administer field permissions'.
  $permissions['administer field permissions'] = array(
    'name' => 'administer field permissions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'administer permissions'.
  $permissions['administer permissions'] = array(
    'name' => 'administer permissions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer users'.
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(
      'Support' => 'Support',
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer views'.
  $permissions['administer views'] = array(
    'name' => 'administer views',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'views',
  );

  // Exported permission: 'cancel account'.
  $permissions['cancel account'] = array(
    'name' => 'cancel account',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'change own username'.
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'user',
  );

  // Exported permission: 'create field_bb_ab_history'.
  $permissions['create field_bb_ab_history'] = array(
    'name' => 'create field_bb_ab_history',
    'roles' => array(
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_bb_aint_no_party'.
  $permissions['create field_bb_aint_no_party'] = array(
    'name' => 'create field_bb_aint_no_party',
    'roles' => array(
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_bb_booze'.
  $permissions['create field_bb_booze'] = array(
    'name' => 'create field_bb_booze',
    'roles' => array(
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_bb_booze1'.
  $permissions['create field_bb_booze1'] = array(
    'name' => 'create field_bb_booze1',
    'roles' => array(
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_bb_complete'.
  $permissions['create field_bb_complete'] = array(
    'name' => 'create field_bb_complete',
    'roles' => array(
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_bb_dressed'.
  $permissions['create field_bb_dressed'] = array(
    'name' => 'create field_bb_dressed',
    'roles' => array(
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_bb_dressed1'.
  $permissions['create field_bb_dressed1'] = array(
    'name' => 'create field_bb_dressed1',
    'roles' => array(
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_bb_drone'.
  $permissions['create field_bb_drone'] = array(
    'name' => 'create field_bb_drone',
    'roles' => array(
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_bb_drone1'.
  $permissions['create field_bb_drone1'] = array(
    'name' => 'create field_bb_drone1',
    'roles' => array(
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_bb_firstburn'.
  $permissions['create field_bb_firstburn'] = array(
    'name' => 'create field_bb_firstburn',
    'roles' => array(
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_bb_haul'.
  $permissions['create field_bb_haul'] = array(
    'name' => 'create field_bb_haul',
    'roles' => array(
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_bb_haul2'.
  $permissions['create field_bb_haul2'] = array(
    'name' => 'create field_bb_haul2',
    'roles' => array(
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_bb_ice'.
  $permissions['create field_bb_ice'] = array(
    'name' => 'create field_bb_ice',
    'roles' => array(
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_bb_jol'.
  $permissions['create field_bb_jol'] = array(
    'name' => 'create field_bb_jol',
    'roles' => array(
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_bb_leave_no_trace'.
  $permissions['create field_bb_leave_no_trace'] = array(
    'name' => 'create field_bb_leave_no_trace',
    'roles' => array(
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_bb_madly_creative'.
  $permissions['create field_bb_madly_creative'] = array(
    'name' => 'create field_bb_madly_creative',
    'roles' => array(
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_bb_mutant'.
  $permissions['create field_bb_mutant'] = array(
    'name' => 'create field_bb_mutant',
    'roles' => array(
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_bb_mutant1'.
  $permissions['create field_bb_mutant1'] = array(
    'name' => 'create field_bb_mutant1',
    'roles' => array(
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_bb_not_music_festival'.
  $permissions['create field_bb_not_music_festival'] = array(
    'name' => 'create field_bb_not_music_festival',
    'roles' => array(
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_bb_part_of'.
  $permissions['create field_bb_part_of'] = array(
    'name' => 'create field_bb_part_of',
    'roles' => array(
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_bb_part_of1'.
  $permissions['create field_bb_part_of1'] = array(
    'name' => 'create field_bb_part_of1',
    'roles' => array(
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_bb_partisipating'.
  $permissions['create field_bb_partisipating'] = array(
    'name' => 'create field_bb_partisipating',
    'roles' => array(
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_bb_preamble'.
  $permissions['create field_bb_preamble'] = array(
    'name' => 'create field_bb_preamble',
    'roles' => array(
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_bb_principles'.
  $permissions['create field_bb_principles'] = array(
    'name' => 'create field_bb_principles',
    'roles' => array(
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_bb_read_survival_guide'.
  $permissions['create field_bb_read_survival_guide'] = array(
    'name' => 'create field_bb_read_survival_guide',
    'roles' => array(
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_bb_theme'.
  $permissions['create field_bb_theme'] = array(
    'name' => 'create field_bb_theme',
    'roles' => array(
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_field_bb_leave_no_trace2'.
  $permissions['create field_field_bb_leave_no_trace2'] = array(
    'name' => 'create field_field_bb_leave_no_trace2',
    'roles' => array(
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_imported_from_wordpress'.
  $permissions['create field_imported_from_wordpress'] = array(
    'name' => 'create field_imported_from_wordpress',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_moop_is_an_abbreviation_fo'.
  $permissions['create field_moop_is_an_abbreviation_fo'] = array(
    'name' => 'create field_moop_is_an_abbreviation_fo',
    'roles' => array(
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_updated'.
  $permissions['create field_updated'] = array(
    'name' => 'create field_updated',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_volunteer_ticket'.
  $permissions['create field_volunteer_ticket'] = array(
    'name' => 'create field_volunteer_ticket',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'delete terms in volunteer_ticket'.
  $permissions['delete terms in volunteer_ticket'] = array(
    'name' => 'delete terms in volunteer_ticket',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit field_bb_ab_history'.
  $permissions['edit field_bb_ab_history'] = array(
    'name' => 'edit field_bb_ab_history',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_bb_aint_no_party'.
  $permissions['edit field_bb_aint_no_party'] = array(
    'name' => 'edit field_bb_aint_no_party',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_bb_booze'.
  $permissions['edit field_bb_booze'] = array(
    'name' => 'edit field_bb_booze',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_bb_booze1'.
  $permissions['edit field_bb_booze1'] = array(
    'name' => 'edit field_bb_booze1',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_bb_complete'.
  $permissions['edit field_bb_complete'] = array(
    'name' => 'edit field_bb_complete',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_bb_dressed'.
  $permissions['edit field_bb_dressed'] = array(
    'name' => 'edit field_bb_dressed',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_bb_dressed1'.
  $permissions['edit field_bb_dressed1'] = array(
    'name' => 'edit field_bb_dressed1',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_bb_drone'.
  $permissions['edit field_bb_drone'] = array(
    'name' => 'edit field_bb_drone',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_bb_drone1'.
  $permissions['edit field_bb_drone1'] = array(
    'name' => 'edit field_bb_drone1',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_bb_firstburn'.
  $permissions['edit field_bb_firstburn'] = array(
    'name' => 'edit field_bb_firstburn',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_bb_haul'.
  $permissions['edit field_bb_haul'] = array(
    'name' => 'edit field_bb_haul',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_bb_haul2'.
  $permissions['edit field_bb_haul2'] = array(
    'name' => 'edit field_bb_haul2',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_bb_ice'.
  $permissions['edit field_bb_ice'] = array(
    'name' => 'edit field_bb_ice',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_bb_jol'.
  $permissions['edit field_bb_jol'] = array(
    'name' => 'edit field_bb_jol',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_bb_leave_no_trace'.
  $permissions['edit field_bb_leave_no_trace'] = array(
    'name' => 'edit field_bb_leave_no_trace',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_bb_madly_creative'.
  $permissions['edit field_bb_madly_creative'] = array(
    'name' => 'edit field_bb_madly_creative',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_bb_mutant'.
  $permissions['edit field_bb_mutant'] = array(
    'name' => 'edit field_bb_mutant',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_bb_mutant1'.
  $permissions['edit field_bb_mutant1'] = array(
    'name' => 'edit field_bb_mutant1',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_bb_not_music_festival'.
  $permissions['edit field_bb_not_music_festival'] = array(
    'name' => 'edit field_bb_not_music_festival',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_bb_part_of'.
  $permissions['edit field_bb_part_of'] = array(
    'name' => 'edit field_bb_part_of',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_bb_part_of1'.
  $permissions['edit field_bb_part_of1'] = array(
    'name' => 'edit field_bb_part_of1',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_bb_partisipating'.
  $permissions['edit field_bb_partisipating'] = array(
    'name' => 'edit field_bb_partisipating',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_bb_preamble'.
  $permissions['edit field_bb_preamble'] = array(
    'name' => 'edit field_bb_preamble',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_bb_principles'.
  $permissions['edit field_bb_principles'] = array(
    'name' => 'edit field_bb_principles',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_bb_read_survival_guide'.
  $permissions['edit field_bb_read_survival_guide'] = array(
    'name' => 'edit field_bb_read_survival_guide',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_bb_theme'.
  $permissions['edit field_bb_theme'] = array(
    'name' => 'edit field_bb_theme',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_field_bb_leave_no_trace2'.
  $permissions['edit field_field_bb_leave_no_trace2'] = array(
    'name' => 'edit field_field_bb_leave_no_trace2',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_imported_from_wordpress'.
  $permissions['edit field_imported_from_wordpress'] = array(
    'name' => 'edit field_imported_from_wordpress',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_moop_is_an_abbreviation_fo'.
  $permissions['edit field_moop_is_an_abbreviation_fo'] = array(
    'name' => 'edit field_moop_is_an_abbreviation_fo',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_updated'.
  $permissions['edit field_updated'] = array(
    'name' => 'edit field_updated',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_volunteer_ticket'.
  $permissions['edit field_volunteer_ticket'] = array(
    'name' => 'edit field_volunteer_ticket',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_bb_ab_history'.
  $permissions['edit own field_bb_ab_history'] = array(
    'name' => 'edit own field_bb_ab_history',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_bb_aint_no_party'.
  $permissions['edit own field_bb_aint_no_party'] = array(
    'name' => 'edit own field_bb_aint_no_party',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_bb_booze'.
  $permissions['edit own field_bb_booze'] = array(
    'name' => 'edit own field_bb_booze',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_bb_booze1'.
  $permissions['edit own field_bb_booze1'] = array(
    'name' => 'edit own field_bb_booze1',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_bb_complete'.
  $permissions['edit own field_bb_complete'] = array(
    'name' => 'edit own field_bb_complete',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_bb_dressed'.
  $permissions['edit own field_bb_dressed'] = array(
    'name' => 'edit own field_bb_dressed',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_bb_dressed1'.
  $permissions['edit own field_bb_dressed1'] = array(
    'name' => 'edit own field_bb_dressed1',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_bb_drone'.
  $permissions['edit own field_bb_drone'] = array(
    'name' => 'edit own field_bb_drone',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_bb_drone1'.
  $permissions['edit own field_bb_drone1'] = array(
    'name' => 'edit own field_bb_drone1',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_bb_firstburn'.
  $permissions['edit own field_bb_firstburn'] = array(
    'name' => 'edit own field_bb_firstburn',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_bb_haul'.
  $permissions['edit own field_bb_haul'] = array(
    'name' => 'edit own field_bb_haul',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_bb_haul2'.
  $permissions['edit own field_bb_haul2'] = array(
    'name' => 'edit own field_bb_haul2',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_bb_ice'.
  $permissions['edit own field_bb_ice'] = array(
    'name' => 'edit own field_bb_ice',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_bb_jol'.
  $permissions['edit own field_bb_jol'] = array(
    'name' => 'edit own field_bb_jol',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_bb_leave_no_trace'.
  $permissions['edit own field_bb_leave_no_trace'] = array(
    'name' => 'edit own field_bb_leave_no_trace',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_bb_madly_creative'.
  $permissions['edit own field_bb_madly_creative'] = array(
    'name' => 'edit own field_bb_madly_creative',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_bb_mutant'.
  $permissions['edit own field_bb_mutant'] = array(
    'name' => 'edit own field_bb_mutant',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_bb_mutant1'.
  $permissions['edit own field_bb_mutant1'] = array(
    'name' => 'edit own field_bb_mutant1',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_bb_not_music_festival'.
  $permissions['edit own field_bb_not_music_festival'] = array(
    'name' => 'edit own field_bb_not_music_festival',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_bb_part_of'.
  $permissions['edit own field_bb_part_of'] = array(
    'name' => 'edit own field_bb_part_of',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_bb_part_of1'.
  $permissions['edit own field_bb_part_of1'] = array(
    'name' => 'edit own field_bb_part_of1',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_bb_partisipating'.
  $permissions['edit own field_bb_partisipating'] = array(
    'name' => 'edit own field_bb_partisipating',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_bb_preamble'.
  $permissions['edit own field_bb_preamble'] = array(
    'name' => 'edit own field_bb_preamble',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_bb_principles'.
  $permissions['edit own field_bb_principles'] = array(
    'name' => 'edit own field_bb_principles',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_bb_read_survival_guide'.
  $permissions['edit own field_bb_read_survival_guide'] = array(
    'name' => 'edit own field_bb_read_survival_guide',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_bb_theme'.
  $permissions['edit own field_bb_theme'] = array(
    'name' => 'edit own field_bb_theme',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_field_bb_leave_no_trace2'.
  $permissions['edit own field_field_bb_leave_no_trace2'] = array(
    'name' => 'edit own field_field_bb_leave_no_trace2',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_imported_from_wordpress'.
  $permissions['edit own field_imported_from_wordpress'] = array(
    'name' => 'edit own field_imported_from_wordpress',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_moop_is_an_abbreviation_fo'.
  $permissions['edit own field_moop_is_an_abbreviation_fo'] = array(
    'name' => 'edit own field_moop_is_an_abbreviation_fo',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_updated'.
  $permissions['edit own field_updated'] = array(
    'name' => 'edit own field_updated',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_volunteer_ticket'.
  $permissions['edit own field_volunteer_ticket'] = array(
    'name' => 'edit own field_volunteer_ticket',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit terms in volunteer_ticket'.
  $permissions['edit terms in volunteer_ticket'] = array(
    'name' => 'edit terms in volunteer_ticket',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'exclude any node title'.
  $permissions['exclude any node title'] = array(
    'name' => 'exclude any node title',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'exclude_node_title',
  );

  // Exported permission: 'exclude own node title'.
  $permissions['exclude own node title'] = array(
    'name' => 'exclude own node title',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'exclude_node_title',
  );

  // Exported permission: 'import users'.
  $permissions['import users'] = array(
    'name' => 'import users',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user_import',
  );

  // Exported permission: 'limited user import'.
  $permissions['limited user import'] = array(
    'name' => 'limited user import',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user_import',
  );

  // Exported permission: 'select account cancellation method'.
  $permissions['select account cancellation method'] = array(
    'name' => 'select account cancellation method',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'use exclude node title'.
  $permissions['use exclude node title'] = array(
    'name' => 'use exclude node title',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'exclude_node_title',
  );

  // Exported permission: 'view field_bb_ab_history'.
  $permissions['view field_bb_ab_history'] = array(
    'name' => 'view field_bb_ab_history',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_bb_aint_no_party'.
  $permissions['view field_bb_aint_no_party'] = array(
    'name' => 'view field_bb_aint_no_party',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_bb_booze'.
  $permissions['view field_bb_booze'] = array(
    'name' => 'view field_bb_booze',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_bb_booze1'.
  $permissions['view field_bb_booze1'] = array(
    'name' => 'view field_bb_booze1',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_bb_complete'.
  $permissions['view field_bb_complete'] = array(
    'name' => 'view field_bb_complete',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_bb_dressed'.
  $permissions['view field_bb_dressed'] = array(
    'name' => 'view field_bb_dressed',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_bb_dressed1'.
  $permissions['view field_bb_dressed1'] = array(
    'name' => 'view field_bb_dressed1',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_bb_drone'.
  $permissions['view field_bb_drone'] = array(
    'name' => 'view field_bb_drone',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_bb_drone1'.
  $permissions['view field_bb_drone1'] = array(
    'name' => 'view field_bb_drone1',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_bb_firstburn'.
  $permissions['view field_bb_firstburn'] = array(
    'name' => 'view field_bb_firstburn',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_bb_haul'.
  $permissions['view field_bb_haul'] = array(
    'name' => 'view field_bb_haul',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_bb_haul2'.
  $permissions['view field_bb_haul2'] = array(
    'name' => 'view field_bb_haul2',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_bb_ice'.
  $permissions['view field_bb_ice'] = array(
    'name' => 'view field_bb_ice',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_bb_jol'.
  $permissions['view field_bb_jol'] = array(
    'name' => 'view field_bb_jol',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_bb_leave_no_trace'.
  $permissions['view field_bb_leave_no_trace'] = array(
    'name' => 'view field_bb_leave_no_trace',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_bb_madly_creative'.
  $permissions['view field_bb_madly_creative'] = array(
    'name' => 'view field_bb_madly_creative',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_bb_mutant'.
  $permissions['view field_bb_mutant'] = array(
    'name' => 'view field_bb_mutant',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_bb_mutant1'.
  $permissions['view field_bb_mutant1'] = array(
    'name' => 'view field_bb_mutant1',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_bb_not_music_festival'.
  $permissions['view field_bb_not_music_festival'] = array(
    'name' => 'view field_bb_not_music_festival',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_bb_part_of'.
  $permissions['view field_bb_part_of'] = array(
    'name' => 'view field_bb_part_of',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_bb_part_of1'.
  $permissions['view field_bb_part_of1'] = array(
    'name' => 'view field_bb_part_of1',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_bb_partisipating'.
  $permissions['view field_bb_partisipating'] = array(
    'name' => 'view field_bb_partisipating',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_bb_preamble'.
  $permissions['view field_bb_preamble'] = array(
    'name' => 'view field_bb_preamble',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_bb_principles'.
  $permissions['view field_bb_principles'] = array(
    'name' => 'view field_bb_principles',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_bb_read_survival_guide'.
  $permissions['view field_bb_read_survival_guide'] = array(
    'name' => 'view field_bb_read_survival_guide',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_bb_theme'.
  $permissions['view field_bb_theme'] = array(
    'name' => 'view field_bb_theme',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_field_bb_leave_no_trace2'.
  $permissions['view field_field_bb_leave_no_trace2'] = array(
    'name' => 'view field_field_bb_leave_no_trace2',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_imported_from_wordpress'.
  $permissions['view field_imported_from_wordpress'] = array(
    'name' => 'view field_imported_from_wordpress',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_moop_is_an_abbreviation_fo'.
  $permissions['view field_moop_is_an_abbreviation_fo'] = array(
    'name' => 'view field_moop_is_an_abbreviation_fo',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_updated'.
  $permissions['view field_updated'] = array(
    'name' => 'view field_updated',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_volunteer_ticket'.
  $permissions['view field_volunteer_ticket'] = array(
    'name' => 'view field_volunteer_ticket',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_bb_ab_history'.
  $permissions['view own field_bb_ab_history'] = array(
    'name' => 'view own field_bb_ab_history',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_bb_aint_no_party'.
  $permissions['view own field_bb_aint_no_party'] = array(
    'name' => 'view own field_bb_aint_no_party',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_bb_booze'.
  $permissions['view own field_bb_booze'] = array(
    'name' => 'view own field_bb_booze',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_bb_booze1'.
  $permissions['view own field_bb_booze1'] = array(
    'name' => 'view own field_bb_booze1',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_bb_complete'.
  $permissions['view own field_bb_complete'] = array(
    'name' => 'view own field_bb_complete',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_bb_dressed'.
  $permissions['view own field_bb_dressed'] = array(
    'name' => 'view own field_bb_dressed',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_bb_dressed1'.
  $permissions['view own field_bb_dressed1'] = array(
    'name' => 'view own field_bb_dressed1',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_bb_drone'.
  $permissions['view own field_bb_drone'] = array(
    'name' => 'view own field_bb_drone',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_bb_drone1'.
  $permissions['view own field_bb_drone1'] = array(
    'name' => 'view own field_bb_drone1',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_bb_firstburn'.
  $permissions['view own field_bb_firstburn'] = array(
    'name' => 'view own field_bb_firstburn',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_bb_haul'.
  $permissions['view own field_bb_haul'] = array(
    'name' => 'view own field_bb_haul',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_bb_haul2'.
  $permissions['view own field_bb_haul2'] = array(
    'name' => 'view own field_bb_haul2',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_bb_ice'.
  $permissions['view own field_bb_ice'] = array(
    'name' => 'view own field_bb_ice',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_bb_jol'.
  $permissions['view own field_bb_jol'] = array(
    'name' => 'view own field_bb_jol',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_bb_leave_no_trace'.
  $permissions['view own field_bb_leave_no_trace'] = array(
    'name' => 'view own field_bb_leave_no_trace',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_bb_madly_creative'.
  $permissions['view own field_bb_madly_creative'] = array(
    'name' => 'view own field_bb_madly_creative',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_bb_mutant'.
  $permissions['view own field_bb_mutant'] = array(
    'name' => 'view own field_bb_mutant',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_bb_mutant1'.
  $permissions['view own field_bb_mutant1'] = array(
    'name' => 'view own field_bb_mutant1',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_bb_not_music_festival'.
  $permissions['view own field_bb_not_music_festival'] = array(
    'name' => 'view own field_bb_not_music_festival',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_bb_part_of'.
  $permissions['view own field_bb_part_of'] = array(
    'name' => 'view own field_bb_part_of',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_bb_part_of1'.
  $permissions['view own field_bb_part_of1'] = array(
    'name' => 'view own field_bb_part_of1',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_bb_partisipating'.
  $permissions['view own field_bb_partisipating'] = array(
    'name' => 'view own field_bb_partisipating',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_bb_preamble'.
  $permissions['view own field_bb_preamble'] = array(
    'name' => 'view own field_bb_preamble',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_bb_principles'.
  $permissions['view own field_bb_principles'] = array(
    'name' => 'view own field_bb_principles',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_bb_read_survival_guide'.
  $permissions['view own field_bb_read_survival_guide'] = array(
    'name' => 'view own field_bb_read_survival_guide',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_bb_theme'.
  $permissions['view own field_bb_theme'] = array(
    'name' => 'view own field_bb_theme',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_field_bb_leave_no_trace2'.
  $permissions['view own field_field_bb_leave_no_trace2'] = array(
    'name' => 'view own field_field_bb_leave_no_trace2',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_imported_from_wordpress'.
  $permissions['view own field_imported_from_wordpress'] = array(
    'name' => 'view own field_imported_from_wordpress',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_moop_is_an_abbreviation_fo'.
  $permissions['view own field_moop_is_an_abbreviation_fo'] = array(
    'name' => 'view own field_moop_is_an_abbreviation_fo',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_updated'.
  $permissions['view own field_updated'] = array(
    'name' => 'view own field_updated',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_volunteer_ticket'.
  $permissions['view own field_volunteer_ticket'] = array(
    'name' => 'view own field_volunteer_ticket',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
