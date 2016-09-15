<?php
/**
 * @file
 * feature_core_fields..inc
 */

/**
 * Implements hook_multifield_default_multifield().
 */
function feature_core_fields_multifield_default_multifield() {
  $export = array();

  $multifield = new stdClass();
  $multifield->disabled = FALSE; /* Edit this to true to make a default multifield disabled initially */
  $multifield->machine_name = 'field_artwork_site_clean';
  $multifield->label = 'field_artwork_site_clean';
  $multifield->description = '';
  $export['field_artwork_site_clean'] = $multifield;

  $multifield = new stdClass();
  $multifield->disabled = FALSE; /* Edit this to true to make a default multifield disabled initially */
  $multifield->machine_name = 'field_associated_projects';
  $multifield->label = 'field_associated_projects';
  $multifield->description = '';
  $export['field_associated_projects'] = $multifield;

  $multifield = new stdClass();
  $multifield->disabled = FALSE; /* Edit this to true to make a default multifield disabled initially */
  $multifield->machine_name = 'field_contact_person';
  $multifield->label = 'field_contact_person';
  $multifield->description = '';
  $export['field_contact_person'] = $multifield;

  $multifield = new stdClass();
  $multifield->disabled = FALSE; /* Edit this to true to make a default multifield disabled initially */
  $multifield->machine_name = 'field_creative_lead';
  $multifield->label = 'field_creative_lead';
  $multifield->description = '';
  $export['field_creative_lead'] = $multifield;

  $multifield = new stdClass();
  $multifield->disabled = FALSE; /* Edit this to true to make a default multifield disabled initially */
  $multifield->machine_name = 'field_crew_members';
  $multifield->label = 'field_crew_members';
  $multifield->description = '';
  $export['field_crew_members'] = $multifield;

  $multifield = new stdClass();
  $multifield->disabled = FALSE; /* Edit this to true to make a default multifield disabled initially */
  $multifield->machine_name = 'field_dimentions_m2';
  $multifield->label = 'field_dimentions_m2';
  $multifield->description = '';
  $export['field_dimentions_m2'] = $multifield;

  $multifield = new stdClass();
  $multifield->disabled = FALSE; /* Edit this to true to make a default multifield disabled initially */
  $multifield->machine_name = 'field_fire_person';
  $multifield->label = 'field_fire_person';
  $multifield->description = '';
  $export['field_fire_person'] = $multifield;

  $multifield = new stdClass();
  $multifield->disabled = FALSE; /* Edit this to true to make a default multifield disabled initially */
  $multifield->machine_name = 'field_fundraiser';
  $multifield->label = 'field_fundraiser';
  $multifield->description = '';
  $export['field_fundraiser'] = $multifield;

  $multifield = new stdClass();
  $multifield->disabled = FALSE; /* Edit this to true to make a default multifield disabled initially */
  $multifield->machine_name = 'field_moop_representative';
  $multifield->label = 'field_moop_representative';
  $multifield->description = '';
  $export['field_moop_representative'] = $multifield;

  $multifield = new stdClass();
  $multifield->disabled = FALSE; /* Edit this to true to make a default multifield disabled initially */
  $multifield->machine_name = 'field_offsite_building';
  $multifield->label = 'field_offsite_building';
  $multifield->description = '';
  $export['field_offsite_building'] = $multifield;

  $multifield = new stdClass();
  $multifield->disabled = FALSE; /* Edit this to true to make a default multifield disabled initially */
  $multifield->machine_name = 'field_on_site_building';
  $multifield->label = 'field_on_site_building';
  $multifield->description = '';
  $export['field_on_site_building'] = $multifield;

  $multifield = new stdClass();
  $multifield->disabled = FALSE; /* Edit this to true to make a default multifield disabled initially */
  $multifield->machine_name = 'field_person_lighting';
  $multifield->label = 'field_person_lighting';
  $multifield->description = '';
  $export['field_person_lighting'] = $multifield;

  $multifield = new stdClass();
  $multifield->disabled = FALSE; /* Edit this to true to make a default multifield disabled initially */
  $multifield->machine_name = 'field_project_manager';
  $multifield->label = 'field_project_manager';
  $multifield->description = '';
  $export['field_project_manager'] = $multifield;

  $multifield = new stdClass();
  $multifield->disabled = FALSE; /* Edit this to true to make a default multifield disabled initially */
  $multifield->machine_name = 'field_sound_person';
  $multifield->label = 'field_sound_person';
  $multifield->description = '';
  $export['field_sound_person'] = $multifield;

  $multifield = new stdClass();
  $multifield->disabled = FALSE; /* Edit this to true to make a default multifield disabled initially */
  $multifield->machine_name = 'field_team_structural_rep';
  $multifield->label = 'field_team_structural_rep';
  $multifield->description = '';
  $export['field_team_structural_rep'] = $multifield;

  $multifield = new stdClass();
  $multifield->disabled = FALSE; /* Edit this to true to make a default multifield disabled initially */
  $multifield->machine_name = 'field_year_and_name_of_prev';
  $multifield->label = 'field_year_and_name_of_prev';
  $multifield->description = '';
  $export['field_year_and_name_of_prev'] = $multifield;

  return $export;
}
