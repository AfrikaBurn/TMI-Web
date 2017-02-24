<?php
/**
 * @file
 * artwork_registration.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function artwork_registration_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'clone_of_user_edit_profile';
  $context->description = '';
  $context->tag = 'user profile edit';
  $context->conditions = array(
    'user' => array(
      'values' => array(
        'authenticated user' => 'authenticated user',
      ),
    ),
    'user_page' => array(
      'values' => array(
        'form' => 'form',
        'register' => 'register',
        'view' => 'view',
      ),
      'options' => array(
        'mode' => 'all',
      ),
    ),
  );
  $context->reactions = array(
    'context_reaction_view_mode' => array(
      'entity_types' => array(
        'country' => array(
          'country' => 'none',
        ),
        'fieldable_panels_pane' => array(
          'fieldable_panels_pane' => 'none',
        ),
        'message_type_category' => array(
          'message_type_category' => 'none',
        ),
        'message_type' => array(
          'message_type' => 'none',
        ),
        'message' => array(
          'og_new_content' => 'none',
        ),
        'multifield' => array(
          'field_contact_person' => 'none',
          'field_creative_lead' => 'none',
          'field_project_manager' => 'none',
          'field_fundraiser' => 'none',
          'field_health_safety_contact_pers' => 'none',
          'field_health_and_safety_contact_' => 'none',
          'field_health_and_safety' => 'none',
          'field_moop_representative' => 'none',
          'field_dimensions' => 'none',
          'field_do_you_have_in_your_team_s' => 'none',
          'field_memeber_for_structural_saf' => 'none',
          'field_team_structural_rep' => 'none',
          'field_offsite_building' => 'none',
          'field_on_site_building' => 'none',
          'field_artwork_removal_site_clean' => 'none',
          'field_artwork_removal_clean' => 'none',
          'field_artwork_site_clean' => 'none',
          'field_name_and_years_of_previous' => 'none',
          'field_field_year_and_name_of_pre' => 'none',
          'field_year_and_name_of_prev' => 'none',
          'field_crew_members' => 'none',
          'field_associated_projects' => 'none',
          'field_sound_person' => 'none',
          'field_fire_person' => 'none',
          'field_bb_minors_details' => 'none',
          'field_previous_envolvement' => 'none',
          'field_person_lighting' => 'none',
          'field_breakdown_of_expenses' => 'none',
        ),
        'node' => array(
          'article' => 'none',
          'artwork_registration' => 'none',
          'page' => 'none',
          'creative_grant_application' => 'none',
          'feed' => 'none',
          'feed_item' => 'none',
          'forum' => 'none',
          'group' => 'none',
          'mutant_vehicles' => 'none',
          'mutant_vehicles_grant' => 'none',
          'panel' => 'none',
          'performance_registration' => 'none',
          'poll' => 'none',
          'post' => 'none',
          'theme_camps' => 'none',
          'webform' => 'none',
        ),
        'og_membership_type' => array(
          'og_membership_type' => 'none',
        ),
        'og_membership' => array(
          'og_membership_type_default' => 'none',
          'test_memebership_type' => 'none',
        ),
        'file' => array(
          'file' => 'none',
        ),
        'taxonomy_term' => array(
          'tags' => 'none',
          'forums' => 'none',
          'event_years' => 'none',
          'moop_score' => 'none',
          'mutant_vehicles_base' => 'none',
          'sound_level' => 'none',
          'artwork_placement' => 'none',
          'municpal_district' => 'none',
          'project_size' => 'none',
          'number_of_passengers' => 'none',
          'performer_types' => 'none',
          'trailer_size' => 'none',
          'migrate_example_beer_styles' => 'none',
          'migrate_example_wine_varieties' => 'none',
          'migrate_example_wine_regions' => 'none',
          'migrate_example_wine_best_with' => 'none',
          'cost_estimates' => 'none',
          'type_of_expence' => 'none',
          'volunteer_ticket' => 'none',
        ),
        'user' => array(
          'user' => 'user_edit_view',
        ),
        'rules_config' => array(
          'rules_config' => 'none',
        ),
        'reactions__plugins__context_reaction_view_mode__entity_types__active_tab' => 'edit-reactions-plugins-context-reaction-view-mode-entity-types-user',
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('user profile edit');
  $export['clone_of_user_edit_profile'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'not_logged_in_user';
  $context->description = '';
  $context->tag = 'Not Logged in User';
  $context->conditions = array(
    'user' => array(
      'values' => array(
        'anonymous user' => 'anonymous user',
      ),
    ),
  );
  $context->reactions = array(
    'context_reaction_view_mode' => array(
      'entity_types' => array(
        'country' => array(
          'country' => 'none',
        ),
        'fieldable_panels_pane' => array(
          'fieldable_panels_pane' => 'none',
        ),
        'message_type_category' => array(
          'message_type_category' => 'none',
        ),
        'message_type' => array(
          'message_type' => 'none',
        ),
        'message' => array(
          'og_new_content' => 'none',
        ),
        'multifield' => array(
          'field_contact_person' => 'none',
          'field_creative_lead' => 'none',
          'field_project_manager' => 'none',
          'field_fundraiser' => 'none',
          'field_health_safety_contact_pers' => 'none',
          'field_health_and_safety_contact_' => 'none',
          'field_health_and_safety' => 'none',
          'field_moop_representative' => 'none',
          'field_dimensions' => 'none',
          'field_do_you_have_in_your_team_s' => 'none',
          'field_memeber_for_structural_saf' => 'none',
          'field_team_structural_rep' => 'none',
          'field_offsite_building' => 'none',
          'field_on_site_building' => 'none',
          'field_artwork_removal_site_clean' => 'none',
          'field_artwork_removal_clean' => 'none',
          'field_artwork_site_clean' => 'none',
          'field_name_and_years_of_previous' => 'none',
          'field_field_year_and_name_of_pre' => 'none',
          'field_year_and_name_of_prev' => 'none',
          'field_crew_members' => 'none',
          'field_associated_projects' => 'none',
          'field_sound_person' => 'none',
          'field_fire_person' => 'none',
          'field_bb_minors_details' => 'none',
          'field_previous_envolvement' => 'none',
          'field_person_lighting' => 'none',
          'field_breakdown_of_expenses' => 'none',
        ),
        'node' => array(
          'article' => 'none',
          'artwork_registration' => 'none',
          'page' => 'full',
          'creative_grant_application' => 'none',
          'feed' => 'none',
          'feed_item' => 'none',
          'forum' => 'none',
          'group' => 'none',
          'mutant_vehicles' => 'none',
          'mutant_vehicles_grant' => 'none',
          'panel' => 'none',
          'performance_registration' => 'none',
          'poll' => 'none',
          'post' => 'none',
          'theme_camps' => 'none',
          'webform' => 'none',
        ),
        'og_membership_type' => array(
          'og_membership_type' => 'none',
        ),
        'og_membership' => array(
          'og_membership_type_default' => 'none',
          'test_memebership_type' => 'none',
        ),
        'file' => array(
          'file' => 'none',
        ),
        'taxonomy_term' => array(
          'tags' => 'none',
          'forums' => 'none',
          'event_years' => 'none',
          'moop_score' => 'none',
          'mutant_vehicles_base' => 'none',
          'sound_level' => 'none',
          'artwork_placement' => 'none',
          'municpal_district' => 'none',
          'project_size' => 'none',
          'number_of_passengers' => 'none',
          'performer_types' => 'none',
          'trailer_size' => 'none',
          'migrate_example_beer_styles' => 'none',
          'migrate_example_wine_varieties' => 'none',
          'migrate_example_wine_regions' => 'none',
          'migrate_example_wine_best_with' => 'none',
          'cost_estimates' => 'none',
          'type_of_expence' => 'none',
          'volunteer_ticket' => 'none',
        ),
        'user' => array(
          'user' => 'anonymous_user',
        ),
        'rules_config' => array(
          'rules_config' => 'none',
        ),
        'reactions__plugins__context_reaction_view_mode__entity_types__active_tab' => 'edit-reactions-plugins-context-reaction-view-mode-entity-types-user',
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Not Logged in User');
  $export['not_logged_in_user'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'use_view_profile';
  $context->description = '';
  $context->tag = 'user View Profile';
  $context->conditions = array(
    'user' => array(
      'values' => array(
        'authenticated user' => 'authenticated user',
      ),
    ),
    'user_page' => array(
      'values' => array(
        'form' => 'form',
        'view' => 'view',
      ),
      'options' => array(
        'mode' => 'all',
      ),
    ),
  );
  $context->reactions = array(
    'context_reaction_view_mode' => array(
      'entity_types' => array(
        'country' => array(
          'country' => 'none',
        ),
        'fieldable_panels_pane' => array(
          'fieldable_panels_pane' => 'none',
        ),
        'message_type_category' => array(
          'message_type_category' => 'none',
        ),
        'message_type' => array(
          'message_type' => 'none',
        ),
        'message' => array(
          'og_new_content' => 'none',
        ),
        'multifield' => array(
          'field_contact_person' => 'none',
          'field_creative_lead' => 'none',
          'field_project_manager' => 'none',
          'field_fundraiser' => 'none',
          'field_health_safety_contact_pers' => 'none',
          'field_health_and_safety_contact_' => 'none',
          'field_health_and_safety' => 'none',
          'field_moop_representative' => 'none',
          'field_dimensions' => 'none',
          'field_do_you_have_in_your_team_s' => 'none',
          'field_memeber_for_structural_saf' => 'none',
          'field_team_structural_rep' => 'none',
          'field_offsite_building' => 'none',
          'field_on_site_building' => 'none',
          'field_artwork_removal_site_clean' => 'none',
          'field_artwork_removal_clean' => 'none',
          'field_artwork_site_clean' => 'none',
          'field_name_and_years_of_previous' => 'none',
          'field_field_year_and_name_of_pre' => 'none',
          'field_year_and_name_of_prev' => 'none',
          'field_crew_members' => 'none',
          'field_associated_projects' => 'none',
          'field_sound_person' => 'none',
          'field_fire_person' => 'none',
          'field_bb_minors_details' => 'none',
          'field_previous_envolvement' => 'none',
          'field_person_lighting' => 'none',
          'field_breakdown_of_expenses' => 'none',
        ),
        'node' => array(
          'article' => 'none',
          'artwork_registration' => 'none',
          'page' => 'none',
          'creative_grant_application' => 'none',
          'feed' => 'none',
          'feed_item' => 'none',
          'forum' => 'none',
          'group' => 'none',
          'mutant_vehicles' => 'none',
          'mutant_vehicles_grant' => 'none',
          'panel' => 'none',
          'performance_registration' => 'none',
          'poll' => 'none',
          'post' => 'none',
          'theme_camps' => 'none',
          'webform' => 'none',
        ),
        'og_membership_type' => array(
          'og_membership_type' => 'none',
        ),
        'og_membership' => array(
          'og_membership_type_default' => 'none',
          'test_memebership_type' => 'none',
        ),
        'file' => array(
          'file' => 'none',
        ),
        'taxonomy_term' => array(
          'tags' => 'none',
          'forums' => 'none',
          'event_years' => 'none',
          'moop_score' => 'none',
          'mutant_vehicles_base' => 'none',
          'sound_level' => 'none',
          'artwork_placement' => 'none',
          'municpal_district' => 'none',
          'project_size' => 'none',
          'number_of_passengers' => 'none',
          'performer_types' => 'none',
          'trailer_size' => 'none',
          'migrate_example_beer_styles' => 'none',
          'migrate_example_wine_varieties' => 'none',
          'migrate_example_wine_regions' => 'none',
          'migrate_example_wine_best_with' => 'none',
          'cost_estimates' => 'none',
          'type_of_expence' => 'none',
        ),
        'user' => array(
          'user' => 'user_view',
        ),
        'rules_config' => array(
          'rules_config' => 'none',
        ),
        'reactions__plugins__context_reaction_view_mode__entity_types__active_tab' => 'edit-reactions-plugins-context-reaction-view-mode-entity-types-user',
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('user View Profile');
  $export['use_view_profile'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'user_admin_edit';
  $context->description = '';
  $context->tag = 'admin user edit';
  $context->conditions = array(
    'user' => array(
      'values' => array(
        'administrator' => 'administrator',
      ),
    ),
    'user_page' => array(
      'values' => array(
        'form' => 'form',
      ),
      'options' => array(
        'mode' => 'all',
      ),
    ),
  );
  $context->reactions = array(
    'context_reaction_view_mode' => array(
      'entity_types' => array(
        'country' => array(
          'country' => 'none',
        ),
        'fieldable_panels_pane' => array(
          'fieldable_panels_pane' => 'none',
        ),
        'message_type_category' => array(
          'message_type_category' => 'none',
        ),
        'message_type' => array(
          'message_type' => 'none',
        ),
        'message' => array(
          'og_new_content' => 'none',
        ),
        'multifield' => array(
          'field_contact_person' => 'none',
          'field_creative_lead' => 'none',
          'field_project_manager' => 'none',
          'field_fundraiser' => 'none',
          'field_health_safety_contact_pers' => 'none',
          'field_health_and_safety_contact_' => 'none',
          'field_health_and_safety' => 'none',
          'field_moop_representative' => 'none',
          'field_dimensions' => 'none',
          'field_do_you_have_in_your_team_s' => 'none',
          'field_memeber_for_structural_saf' => 'none',
          'field_team_structural_rep' => 'none',
          'field_offsite_building' => 'none',
          'field_on_site_building' => 'none',
          'field_artwork_removal_site_clean' => 'none',
          'field_artwork_removal_clean' => 'none',
          'field_artwork_site_clean' => 'none',
          'field_name_and_years_of_previous' => 'none',
          'field_field_year_and_name_of_pre' => 'none',
          'field_year_and_name_of_prev' => 'none',
          'field_crew_members' => 'none',
          'field_associated_projects' => 'none',
          'field_sound_person' => 'none',
          'field_fire_person' => 'none',
          'field_bb_minors_details' => 'none',
          'field_previous_envolvement' => 'none',
          'field_person_lighting' => 'none',
          'field_breakdown_of_expenses' => 'none',
        ),
        'node' => array(
          'article' => 'none',
          'artwork_registration' => 'none',
          'page' => 'none',
          'creative_grant_application' => 'none',
          'feed' => 'none',
          'feed_item' => 'none',
          'forum' => 'none',
          'group' => 'none',
          'mutant_vehicles' => 'none',
          'mutant_vehicles_grant' => 'none',
          'panel' => 'none',
          'performance_registration' => 'none',
          'poll' => 'none',
          'post' => 'none',
          'theme_camps' => 'none',
          'webform' => 'none',
        ),
        'og_membership_type' => array(
          'og_membership_type' => 'none',
        ),
        'og_membership' => array(
          'og_membership_type_default' => 'none',
          'test_memebership_type' => 'none',
        ),
        'file' => array(
          'file' => 'none',
        ),
        'taxonomy_term' => array(
          'tags' => 'none',
          'forums' => 'none',
          'event_years' => 'none',
          'moop_score' => 'none',
          'mutant_vehicles_base' => 'none',
          'sound_level' => 'none',
          'artwork_placement' => 'none',
          'municpal_district' => 'none',
          'project_size' => 'none',
          'number_of_passengers' => 'none',
          'performer_types' => 'none',
          'trailer_size' => 'none',
          'migrate_example_beer_styles' => 'none',
          'migrate_example_wine_varieties' => 'none',
          'migrate_example_wine_regions' => 'none',
          'migrate_example_wine_best_with' => 'none',
          'cost_estimates' => 'none',
          'type_of_expence' => 'none',
          'volunteer_ticket' => 'none',
        ),
        'user' => array(
          'user' => 'user_admin_edit',
        ),
        'rules_config' => array(
          'rules_config' => 'none',
        ),
        'reactions__plugins__context_reaction_view_mode__entity_types__active_tab' => 'edit-reactions-plugins-context-reaction-view-mode-entity-types-user',
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('admin user edit');
  $export['user_admin_edit'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'user_admin_view';
  $context->description = 'user view for admin';
  $context->tag = 'admin user view';
  $context->conditions = array(
    'user' => array(
      'values' => array(
        'administrator' => 'administrator',
      ),
    ),
    'user_page' => array(
      'values' => array(
        'view' => 'view',
      ),
      'options' => array(
        'mode' => 'all',
      ),
    ),
  );
  $context->reactions = array(
    'context_reaction_view_mode' => array(
      'entity_types' => array(
        'country' => array(
          'country' => 'none',
        ),
        'fieldable_panels_pane' => array(
          'fieldable_panels_pane' => 'none',
        ),
        'message_type_category' => array(
          'message_type_category' => 'none',
        ),
        'message_type' => array(
          'message_type' => 'none',
        ),
        'message' => array(
          'og_new_content' => 'none',
        ),
        'multifield' => array(
          'field_contact_person' => 'none',
          'field_creative_lead' => 'none',
          'field_project_manager' => 'none',
          'field_fundraiser' => 'none',
          'field_health_safety_contact_pers' => 'none',
          'field_health_and_safety_contact_' => 'none',
          'field_health_and_safety' => 'none',
          'field_moop_representative' => 'none',
          'field_dimensions' => 'none',
          'field_do_you_have_in_your_team_s' => 'none',
          'field_memeber_for_structural_saf' => 'none',
          'field_team_structural_rep' => 'none',
          'field_offsite_building' => 'none',
          'field_on_site_building' => 'none',
          'field_artwork_removal_site_clean' => 'none',
          'field_artwork_removal_clean' => 'none',
          'field_artwork_site_clean' => 'none',
          'field_name_and_years_of_previous' => 'none',
          'field_field_year_and_name_of_pre' => 'none',
          'field_year_and_name_of_prev' => 'none',
          'field_crew_members' => 'none',
          'field_associated_projects' => 'none',
          'field_sound_person' => 'none',
          'field_fire_person' => 'none',
          'field_bb_minors_details' => 'none',
          'field_previous_envolvement' => 'none',
          'field_person_lighting' => 'none',
          'field_breakdown_of_expenses' => 'none',
        ),
        'node' => array(
          'article' => 'none',
          'artwork_registration' => 'none',
          'page' => 'none',
          'creative_grant_application' => 'none',
          'feed' => 'none',
          'feed_item' => 'none',
          'forum' => 'none',
          'group' => 'none',
          'mutant_vehicles' => 'none',
          'mutant_vehicles_grant' => 'none',
          'panel' => 'none',
          'performance_registration' => 'none',
          'poll' => 'none',
          'post' => 'none',
          'theme_camps' => 'none',
          'webform' => 'none',
        ),
        'og_membership_type' => array(
          'og_membership_type' => 'none',
        ),
        'og_membership' => array(
          'og_membership_type_default' => 'none',
          'test_memebership_type' => 'none',
        ),
        'file' => array(
          'file' => 'none',
        ),
        'taxonomy_term' => array(
          'tags' => 'none',
          'forums' => 'none',
          'event_years' => 'none',
          'moop_score' => 'none',
          'mutant_vehicles_base' => 'none',
          'sound_level' => 'none',
          'artwork_placement' => 'none',
          'municpal_district' => 'none',
          'project_size' => 'none',
          'number_of_passengers' => 'none',
          'performer_types' => 'none',
          'trailer_size' => 'none',
          'migrate_example_beer_styles' => 'none',
          'migrate_example_wine_varieties' => 'none',
          'migrate_example_wine_regions' => 'none',
          'migrate_example_wine_best_with' => 'none',
          'cost_estimates' => 'none',
          'type_of_expence' => 'none',
        ),
        'user' => array(
          'user' => 'user_admin_view',
        ),
        'rules_config' => array(
          'rules_config' => 'none',
        ),
        'reactions__plugins__context_reaction_view_mode__entity_types__active_tab' => 'edit-reactions-plugins-context-reaction-view-mode-entity-types-user',
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('admin user view');
  t('user view for admin');
  $export['user_admin_view'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'user_edit_profile';
  $context->description = '';
  $context->tag = 'User Edit Profile';
  $context->conditions = array(
    'user' => array(
      'values' => array(
        'authenticated user' => 'authenticated user',
      ),
    ),
    'user_page' => array(
      'values' => array(
        'form' => 'form',
        'register' => 'register',
        'view' => 'view',
      ),
      'options' => array(
        'mode' => 'current',
      ),
    ),
  );
  $context->reactions = array(
    'context_reaction_view_mode' => array(
      'entity_types' => array(
        'country' => array(
          'country' => 'none',
        ),
        'fieldable_panels_pane' => array(
          'fieldable_panels_pane' => 'none',
        ),
        'message_type_category' => array(
          'message_type_category' => 'none',
        ),
        'message_type' => array(
          'message_type' => 'none',
        ),
        'message' => array(
          'og_new_content' => 'none',
        ),
        'multifield' => array(
          'field_contact_person' => 'none',
          'field_creative_lead' => 'none',
          'field_project_manager' => 'none',
          'field_fundraiser' => 'none',
          'field_health_safety_contact_pers' => 'none',
          'field_health_and_safety_contact_' => 'none',
          'field_health_and_safety' => 'none',
          'field_moop_representative' => 'none',
          'field_dimensions' => 'none',
          'field_do_you_have_in_your_team_s' => 'none',
          'field_memeber_for_structural_saf' => 'none',
          'field_team_structural_rep' => 'none',
          'field_offsite_building' => 'none',
          'field_on_site_building' => 'none',
          'field_artwork_removal_site_clean' => 'none',
          'field_artwork_removal_clean' => 'none',
          'field_artwork_site_clean' => 'none',
          'field_name_and_years_of_previous' => 'none',
          'field_field_year_and_name_of_pre' => 'none',
          'field_year_and_name_of_prev' => 'none',
          'field_crew_members' => 'none',
          'field_associated_projects' => 'none',
          'field_sound_person' => 'none',
          'field_fire_person' => 'none',
          'field_bb_minors_details' => 'none',
          'field_previous_envolvement' => 'none',
          'field_person_lighting' => 'none',
          'field_breakdown_of_expenses' => 'none',
        ),
        'node' => array(
          'article' => 'none',
          'artwork_registration' => 'none',
          'page' => 'none',
          'creative_grant_application' => 'none',
          'feed' => 'none',
          'feed_item' => 'none',
          'forum' => 'none',
          'group' => 'none',
          'mutant_vehicles' => 'none',
          'mutant_vehicles_grant' => 'none',
          'panel' => 'none',
          'performance_registration' => 'none',
          'poll' => 'none',
          'post' => 'none',
          'theme_camps' => 'none',
          'webform' => 'none',
        ),
        'og_membership_type' => array(
          'og_membership_type' => 'none',
        ),
        'og_membership' => array(
          'og_membership_type_default' => 'none',
          'test_memebership_type' => 'none',
        ),
        'file' => array(
          'file' => 'none',
        ),
        'taxonomy_term' => array(
          'tags' => 'none',
          'forums' => 'none',
          'event_years' => 'none',
          'moop_score' => 'none',
          'mutant_vehicles_base' => 'none',
          'sound_level' => 'none',
          'artwork_placement' => 'none',
          'municpal_district' => 'none',
          'project_size' => 'none',
          'number_of_passengers' => 'none',
          'performer_types' => 'none',
          'trailer_size' => 'none',
          'migrate_example_beer_styles' => 'none',
          'migrate_example_wine_varieties' => 'none',
          'migrate_example_wine_regions' => 'none',
          'migrate_example_wine_best_with' => 'none',
          'cost_estimates' => 'none',
          'type_of_expence' => 'none',
          'volunteer_ticket' => 'none',
        ),
        'user' => array(
          'user' => 'user_view',
        ),
        'rules_config' => array(
          'rules_config' => 'none',
        ),
        'reactions__plugins__context_reaction_view_mode__entity_types__active_tab' => 'edit-reactions-plugins-context-reaction-view-mode-entity-types-user',
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('User Edit Profile');
  $export['user_edit_profile'] = $context;

  return $export;
}
