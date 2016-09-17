<?php
/**
 * @file
 * artwork_registration.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function artwork_registration_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-artwork_registration-field_additional_docs'.
  $field_instances['node-artwork_registration-field_additional_docs'] = array(
    'bundle' => 'artwork_registration',
    'custom_add_another' => '',
    'custom_remove' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 48,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_additional_docs',
    'label' => 'Got additional docs or PDF\'s? Add them here.',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'description_field' => 0,
      'file_directory' => 'artwork_registration',
      'file_extensions' => 'pdf docx xlsx pptx doc xls ppt odt fodt ods fods odp fodp odg fodg odf',
      'max_filesize' => '2 MB',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'progress_indicator' => 'bar',
      ),
      'type' => 'file_generic',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'node-artwork_registration-field_anything_else'.
  $field_instances['node-artwork_registration-field_anything_else'] = array(
    'bundle' => 'artwork_registration',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Any other narrative or piece of information that that you feel we should know about you and/or your project? ',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 30,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_anything_else',
    'label' => 'Anything else?',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 41,
    ),
  );

  // Exported field_instance:
  // 'node-artwork_registration-field_applying_for_grant'.
  $field_instances['node-artwork_registration-field_applying_for_grant'] = array(
    'bundle' => 'artwork_registration',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 61,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_applying_for_grant',
    'label' => 'Are you applying for a Creative Grant?',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 38,
    ),
  );

  // Exported field_instance:
  // 'node-artwork_registration-field_artwork_site_clean'.
  $field_instances['node-artwork_registration-field_artwork_site_clean'] = array(
    'bundle' => 'artwork_registration',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'It’s your responsibility to remove your piece once the event is over, and ensure that no trace remains. Nothing. Nada. Zilch. Zip. Zero. Fokol. <br>
If you\'re burning it, it\'s also your responsibility to remove all burn debris left on your site (including ash, charcoal, nails, screws, wire and staples etc). ',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'multifield',
        'settings' => array(
          'view_mode' => 'default',
        ),
        'type' => 'multifield_default',
        'weight' => 28,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_artwork_site_clean',
    'label' => 'Artwork removal & burn site cleanup',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'multifield',
      'settings' => array(),
      'type' => 'multifield_default',
      'weight' => 11,
    ),
  );

  // Exported field_instance:
  // 'node-artwork_registration-field_associated_projects'.
  $field_instances['node-artwork_registration-field_associated_projects'] = array(
    'bundle' => 'artwork_registration',
    'custom_add_another' => 'Add another associate project',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'multifield',
        'settings' => array(
          'view_mode' => 'default',
        ),
        'type' => 'multifield_default',
        'weight' => 45,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_associated_projects',
    'label' => 'Is your piece associated with any other projects at AfrikaBurn?',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'multifield',
      'settings' => array(),
      'type' => 'multifield_default',
      'weight' => 40,
    ),
  );

  // Exported field_instance:
  // 'node-artwork_registration-field_burn_safety_consideration'.
  $field_instances['node-artwork_registration-field_burn_safety_consideration'] = array(
    'bundle' => 'artwork_registration',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Burning requires particular construction materials and extra safety precautions, and also releases a significant amount of carbon into the environment.
We encourage artists to create pieces that can be re-used and enjoyed outside of Tankwa Town. ',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 40,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_burn_safety_consideration',
    'label' => 'What\'s your motivation to burn your piece?',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 36,
    ),
  );

  // Exported field_instance: 'node-artwork_registration-field_burning_yn'.
  $field_instances['node-artwork_registration-field_burning_yn'] = array(
    'bundle' => 'artwork_registration',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Remember: you don\'t have to burn your piece. 
You might think that burning it is an easy way to get rid of it (and not transport it back) - it\'s not: you\'d still have to clean up the burn site and remove all coals, rebar etc. 
So consider whether burning is important to the meaning of your piece carefulluy. 
We love works that can be used outside of the event again, whether as installations or at Decompression, Streetopia, Maker Faire etc.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 53,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_burning_yn',
    'label' => 'Are you planning to burn your artwork and/or does it have a fire component?',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 34,
    ),
  );

  // Exported field_instance: 'node-artwork_registration-field_contact_person'.
  $field_instances['node-artwork_registration-field_contact_person'] = array(
    'bundle' => 'artwork_registration',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'multifield',
        'settings' => array(
          'view_mode' => 'default',
        ),
        'type' => 'multifield_default',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_contact_person',
    'label' => 'Contact person',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'multifield',
      'settings' => array(),
      'type' => 'multifield_default',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'node-artwork_registration-field_creative_lead'.
  $field_instances['node-artwork_registration-field_creative_lead'] = array(
    'bundle' => 'artwork_registration',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'multifield',
        'settings' => array(
          'view_mode' => 'default',
        ),
        'type' => 'multifield_default',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_creative_lead',
    'label' => 'Creative Lead',
    'required' => FALSE,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'multifield',
      'settings' => array(),
      'type' => 'multifield_default',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'node-artwork_registration-field_crew_members'.
  $field_instances['node-artwork_registration-field_crew_members'] = array(
    'bundle' => 'artwork_registration',
    'custom_add_another' => 'Add Another Member',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'multifield',
        'settings' => array(
          'view_mode' => 'default',
        ),
        'type' => 'multifield_default',
        'weight' => 47,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_crew_members',
    'label' => 'Crew members and their roles',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'multifield',
      'settings' => array(),
      'type' => 'multifield_default',
      'weight' => 8,
    ),
  );

  // Exported field_instance:
  // 'node-artwork_registration-field_describe_your_project'.
  $field_instances['node-artwork_registration-field_describe_your_project'] = array(
    'bundle' => 'artwork_registration',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Briefly describe your artwork. What is it? What\'s it made of? Is it interactive? Does it have moving parts? Does it have wheels? And is there a story behind it? 
(We\'re not looking for a two page essay, just enough for us to understand what the artwork is) ',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 10,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_describe_your_project',
    'label' => 'Describe your project',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'node-artwork_registration-field_dimentions_m2'.
  $field_instances['node-artwork_registration-field_dimentions_m2'] = array(
    'bundle' => 'artwork_registration',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'multifield',
        'settings' => array(
          'view_mode' => 'default',
        ),
        'type' => 'multifield_default',
        'weight' => 65,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_dimentions_m2',
    'label' => 'Dimensions',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'multifield',
      'settings' => array(),
      'type' => 'multifield_default',
      'weight' => 42,
    ),
  );

  // Exported field_instance:
  // 'node-artwork_registration-field_do_you_have_a_stage'.
  $field_instances['node-artwork_registration-field_do_you_have_a_stage'] = array(
    'bundle' => 'artwork_registration',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 54,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_do_you_have_a_stage',
    'label' => 'Do you have a stage or performance area where you would welcome performers to?',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 12,
    ),
  );

  // Exported field_instance:
  // 'node-artwork_registration-field_does_it_have_sound_effects'.
  $field_instances['node-artwork_registration-field_does_it_have_sound_effects'] = array(
    'bundle' => 'artwork_registration',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 46,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_does_it_have_sound_effects',
    'label' => 'Does your artwork have a sound component?',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 18,
    ),
  );

  // Exported field_instance: 'node-artwork_registration-field_fire_person'.
  $field_instances['node-artwork_registration-field_fire_person'] = array(
    'bundle' => 'artwork_registration',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'multifield',
        'settings' => array(
          'view_mode' => 'default',
        ),
        'type' => 'multifield_default',
        'weight' => 39,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_fire_person',
    'label' => 'If you plan to burn your piece, you\'ll need a designated Pyro Co-ordinator (This can be you).',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'multifield',
      'settings' => array(),
      'type' => 'multifield_default',
      'weight' => 37,
    ),
  );

  // Exported field_instance: 'node-artwork_registration-field_fundraiser'.
  $field_instances['node-artwork_registration-field_fundraiser'] = array(
    'bundle' => 'artwork_registration',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'multifield',
        'settings' => array(
          'view_mode' => 'default',
        ),
        'type' => 'multifield_default',
        'weight' => 4,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_fundraiser',
    'label' => 'Fundraiser',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'multifield',
      'settings' => array(),
      'type' => 'multifield_default',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'node-artwork_registration-field_history'.
  $field_instances['node-artwork_registration-field_history'] = array(
    'bundle' => 'artwork_registration',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'List other projects you\'ve worked on or generated in the default world.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 9,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_history',
    'label' => 'Other projects',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 14,
    ),
  );

  // Exported field_instance:
  // 'node-artwork_registration-field_if_in_south_africa_please_'.
  $field_instances['node-artwork_registration-field_if_in_south_africa_please_'] = array(
    'bundle' => 'artwork_registration',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 7,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_if_in_south_africa_please_',
    'label' => 'If in South Africa, please select your municipal district',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 11,
    ),
  );

  // Exported field_instance: 'node-artwork_registration-field_image_project'.
  $field_instances['node-artwork_registration-field_image_project'] = array(
    'bundle' => 'artwork_registration',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 52,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_image_project',
    'label' => 'Are you planning any sort of projection, 3D Mapping, laser, etc?',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 28,
    ),
  );

  // Exported field_instance: 'node-artwork_registration-field_location_map'.
  $field_instances['node-artwork_registration-field_location_map'] = array(
    'bundle' => 'artwork_registration',
    'custom_add_another' => '',
    'custom_remove' => '',
    'deleted' => 0,
    'description' => 'If you know exactly where you want your piece to be, look at the map and select from the drop down list below.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'markup',
        'settings' => array(),
        'type' => 'markup_default',
        'weight' => 42,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_location_map',
    'label' => 'Placement Map',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'markup',
      'settings' => array(),
      'type' => 'markup',
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'node-artwork_registration-field_location_picker'.
  $field_instances['node-artwork_registration-field_location_picker'] = array(
    'bundle' => 'artwork_registration',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 43,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_location_picker',
    'label' => 'Select your placement location',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 12,
    ),
  );

  // Exported field_instance: 'node-artwork_registration-field_materials'.
  $field_instances['node-artwork_registration-field_materials'] = array(
    'bundle' => 'artwork_registration',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Please list all materials to be used in your project - and remember: we encourage the use of waste, salvage, recyclable, environmentally friendly and reusable materials. 
If you\'re considering burning your piece please read up about this on our website, and check what materials are acceptable to use.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 16,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_materials',
    'label' => 'Materials',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 44,
    ),
  );

  // Exported field_instance:
  // 'node-artwork_registration-field_moop_representative'.
  $field_instances['node-artwork_registration-field_moop_representative'] = array(
    'bundle' => 'artwork_registration',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Your MOOP Representative will be requested to read and accept the MOOP Manifesto, attend workshops and briefs, fill in the MOOP form, and supply all details requested by our MOOP Squad.<br>
This person plays an active role in the \'education\' of the whole team and will be the difference between a Red and a Green MOOP score on the MOOP Map.<br>
Remember that the MOOP Score of your project this year will affect every member of the team (and future possible funding and direct distribution of tickets). Choose wisely!',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'multifield',
        'settings' => array(
          'view_mode' => 'default',
        ),
        'type' => 'multifield_default',
        'weight' => 5,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_moop_representative',
    'label' => 'MOOP Representative',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'multifield',
      'settings' => array(),
      'type' => 'multifield_default',
      'weight' => 12,
    ),
  );

  // Exported field_instance:
  // 'node-artwork_registration-field_name_of_the_collective'.
  $field_instances['node-artwork_registration-field_name_of_the_collective'] = array(
    'bundle' => 'artwork_registration',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 58,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_name_of_the_collective',
    'label' => 'Name of the collective and/or creator',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'node-artwork_registration-field_new_members'.
  $field_instances['node-artwork_registration-field_new_members'] = array(
    'bundle' => 'artwork_registration',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Sometimes there\'s human resources missing in a team and/or artistic elements that your team can\'t bring to the project.
This isn\'t reason to kill your project: it\'s an opportunity to promote Participation and Gifting and exercise Communal Effort!<br>
If you\'d like to collaborate with other participants and volunteers, write a brief description of your project and specify your needs and/or how you envisage collaboration.
This info will be made public on our website to allow volunteers to choose the project(s) that they feel they can contribute to.<br>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 31,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_new_members',
    'label' => 'Are you interested in collaborating with other artists and/or working with volunteers?',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 15,
    ),
  );

  // Exported field_instance:
  // 'node-artwork_registration-field_new_members_details'.
  $field_instances['node-artwork_registration-field_new_members_details'] = array(
    'bundle' => 'artwork_registration',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '<p>Brief description.</p>
<p>Who are you as a collective? What\'s your project about?</p>
<p>Are you looking for specific skills? Are you open to collaborate with different arts and their input?</p>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 50,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_new_members_details',
    'label' => 'Tell them who you are and what you are looking for',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 16,
    ),
  );

  // Exported field_instance:
  // 'node-artwork_registration-field_new_members_email'.
  $field_instances['node-artwork_registration-field_new_members_email'] = array(
    'bundle' => 'artwork_registration',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Note, this will be made public for new members to contact.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'email',
        'settings' => array(),
        'type' => 'email_default',
        'weight' => 32,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_new_members_email',
    'label' => 'Contact email',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'email',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'email_textfield',
      'weight' => 17,
    ),
  );

  // Exported field_instance: 'node-artwork_registration-field_night'.
  $field_instances['node-artwork_registration-field_night'] = array(
    'bundle' => 'artwork_registration',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 49,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_night',
    'label' => 'Will your artwork have any lighting component?',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 25,
    ),
  );

  // Exported field_instance:
  // 'node-artwork_registration-field_offsite_building'.
  $field_instances['node-artwork_registration-field_offsite_building'] = array(
    'bundle' => 'artwork_registration',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => array(
      0 => array(
        'field_when_are_you_planning_to_s' => array(
          'und' => array(
            0 => array(
              'value' => '2017-04-24 00:00:00',
              'show_todate' => FALSE,
              'timezone' => 'Africa/Johannesburg',
              'offset' => 7200,
              'offset2' => 7200,
              'value2' => '2017-04-24 00:00:00',
            ),
          ),
        ),
        'field_munciple_district' => array(
          'und' => array(),
        ),
        'id' => NULL,
        'actions' => array(
          'remove_button' => 'Remove',
        ),
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'multifield',
        'settings' => array(
          'view_mode' => 'default',
        ),
        'type' => 'multifield_default',
        'weight' => 19,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_offsite_building',
    'label' => 'Offsite building',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'multifield',
      'settings' => array(),
      'type' => 'multifield_default',
      'weight' => 7,
    ),
  );

  // Exported field_instance:
  // 'node-artwork_registration-field_on_site_building'.
  $field_instances['node-artwork_registration-field_on_site_building'] = array(
    'bundle' => 'artwork_registration',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => array(
      0 => array(
        'field_how_long_do_you_estimate_i' => array(
          'und' => array(
            0 => array(
              'value' => '',
            ),
          ),
        ),
        'field_planning_to_start_building' => array(
          'und' => array(
            0 => array(
              'value' => '2017-04-24 00:00:00',
              'show_todate' => TRUE,
              'timezone' => 'Africa/Johannesburg',
              'offset' => 7200,
              'offset2' => 7200,
              'value2' => '2017-04-24 00:00:00',
            ),
          ),
        ),
        'id' => NULL,
        'actions' => array(
          'remove_button' => 'Remove',
        ),
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'multifield',
        'settings' => array(
          'view_mode' => 'default',
        ),
        'type' => 'multifield_default',
        'weight' => 21,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_on_site_building',
    'label' => 'Onsite building',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'multifield',
      'settings' => array(),
      'type' => 'multifield_default',
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'node-artwork_registration-field_performer_type'.
  $field_instances['node-artwork_registration-field_performer_type'] = array(
    'bundle' => 'artwork_registration',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 64,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_performer_type',
    'label' => 'Performer Types',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 14,
    ),
  );

  // Exported field_instance: 'node-artwork_registration-field_person_lighting'.
  $field_instances['node-artwork_registration-field_person_lighting'] = array(
    'bundle' => 'artwork_registration',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'multifield',
        'settings' => array(
          'view_mode' => 'default',
        ),
        'type' => 'multifield_default',
        'weight' => 57,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_person_lighting',
    'label' => 'Who is the person in your team in charge of lighting?',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'multifield',
      'settings' => array(),
      'type' => 'multifield_default',
      'weight' => 30,
    ),
  );

  // Exported field_instance:
  // 'node-artwork_registration-field_philosophical_statement'.
  $field_instances['node-artwork_registration-field_philosophical_statement'] = array(
    'bundle' => 'artwork_registration',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'This isn\'t a required field but you\'re free to tell us if there\'s a story behind your artwork that might help us understand it better. ',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 11,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_philosophical_statement',
    'label' => 'Philosophical statement',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'node-artwork_registration-field_placement'.
  $field_instances['node-artwork_registration-field_placement'] = array(
    'bundle' => 'artwork_registration',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Where would you ideally like to install your Artwork?
Are there any considerations we need to take into account when placing your artwork? Did you have a specific spot in mind when designing it? For example, it might be important for you to have it near your/a theme camp, “out far”, near the hubbub of Off-Centre Camp or a quiet reflective space, a particularly flat surface etc. 
Please note that we’ll try our best to accommodate your needs, but cannot guarantee any specific spots. 
NB: your intention to burn your piece, sound specifications, and planned activities play an important role in placement. ',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 22,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_placement',
    'label' => 'Placement',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 11,
    ),
  );

  // Exported field_instance:
  // 'node-artwork_registration-field_planned_activities'.
  $field_instances['node-artwork_registration-field_planned_activities'] = array(
    'bundle' => 'artwork_registration',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Planning performance or music to accompany your piece? Are there other participants involved? 
Give us an idea of the elements that are part of your artistic vision. 
If you\'re planning burning it, do you have any pre-, during, or post-burn plans? ',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 14,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_planned_activities',
    'label' => 'Planned activities',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 10,
    ),
  );

  // Exported field_instance:
  // 'node-artwork_registration-field_please_describe_your_light'.
  $field_instances['node-artwork_registration-field_please_describe_your_light'] = array(
    'bundle' => 'artwork_registration',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Even if you\'re not using light as an aesthetic component of your piece, you need to make it visible at night (including guy ropes/anchors).',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 23,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_please_describe_your_light',
    'label' => 'Describe your lighting plan',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 26,
    ),
  );

  // Exported field_instance:
  // 'node-artwork_registration-field_please_submit_concept_imag'.
  $field_instances['node-artwork_registration-field_please_submit_concept_imag'] = array(
    'bundle' => 'artwork_registration',
    'custom_add_another' => '',
    'custom_remove' => '',
    'deleted' => 0,
    'description' => 'Image types allowed: png, jpg, jpeg <br>
(max image size: 2 MB)',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 12,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_please_submit_concept_imag',
    'label' => 'Please submit concept images',
    'required' => 1,
    'settings' => array(
      'alt_field' => 0,
      'custom_add_another' => '',
      'custom_remove' => '',
      'default_image' => 0,
      'file_directory' => 'artwork_registration',
      'file_extensions' => 'png jpg jpeg',
      'max_filesize' => '2 MB',
      'max_resolution' => '',
      'min_resolution' => '250x250',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'bar',
      ),
      'type' => 'image_image',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'node-artwork_registration-field_power_sources'.
  $field_instances['node-artwork_registration-field_power_sources'] = array(
    'bundle' => 'artwork_registration',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 24,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_power_sources',
    'label' => 'Please describe your light output devices and power sources',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 27,
    ),
  );

  // Exported field_instance: 'node-artwork_registration-field_project_manager'.
  $field_instances['node-artwork_registration-field_project_manager'] = array(
    'bundle' => 'artwork_registration',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'multifield',
        'settings' => array(
          'view_mode' => 'default',
        ),
        'type' => 'multifield_default',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_project_manager',
    'label' => 'Project Manager',
    'required' => FALSE,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'multifield',
      'settings' => array(),
      'type' => 'multifield_default',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'node-artwork_registration-field_project_size'.
  $field_instances['node-artwork_registration-field_project_size'] = array(
    'bundle' => 'artwork_registration',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 62,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_project_size',
    'label' => 'In terms of size, how would you classify your project?',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 9,
    ),
  );

  // Exported field_instance:
  // 'node-artwork_registration-field_sound_description'.
  $field_instances['node-artwork_registration-field_sound_description'] = array(
    'bundle' => 'artwork_registration',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Depending on your answer we might have more questions for you...',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 55,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_sound_description',
    'label' => 'If yes, please describe the nature and size of your sound',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 20,
    ),
  );

  // Exported field_instance: 'node-artwork_registration-field_sound_level'.
  $field_instances['node-artwork_registration-field_sound_level'] = array(
    'bundle' => 'artwork_registration',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '<p><b>Level 1</b> non-amplified sound: it includes instrumental music, as well as sound at the level of a normal (domestic hi-fi) stereo without sub woofers etc. This level permits you to play sound in most areas during the day unless it\'s a silent zone near the temple or other artworks.</p>

<p><b>Level 2</b> amplified sound: system with sub woofers. This can only be played in specified areas within the Binnekring during the day, and in Sound Zones at night. Please be very aware of Quiet Zones and where artworks require low sound in their surrounds, as well as which way your speakers point..</p>

<p><b>Level 3</b> very large club or stadium-size sound. These systems can only be played at full volume in Sound Zones with speakers orientated away from the Binnekring and camping areas. </p>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 41,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_sound_level',
    'label' => 'Please select the level of your Sound',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 19,
    ),
  );

  // Exported field_instance: 'node-artwork_registration-field_sound_person'.
  $field_instances['node-artwork_registration-field_sound_person'] = array(
    'bundle' => 'artwork_registration',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'multifield',
        'settings' => array(
          'view_mode' => 'default',
        ),
        'type' => 'multifield_default',
        'weight' => 38,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_sound_person',
    'label' => 'Who is the sound co-ordinator on your crew? (This can be you.)',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'multifield',
      'settings' => array(),
      'type' => 'multifield_default',
      'weight' => 21,
    ),
  );

  // Exported field_instance:
  // 'node-artwork_registration-field_stage_performers_dscr'.
  $field_instances['node-artwork_registration-field_stage_performers_dscr'] = array(
    'bundle' => 'artwork_registration',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 59,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_stage_performers_dscr',
    'label' => 'Provide a description of the space and performers you are looking for',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 15,
    ),
  );

  // Exported field_instance:
  // 'node-artwork_registration-field_structural_safety'.
  $field_instances['node-artwork_registration-field_structural_safety'] = array(
    'bundle' => 'artwork_registration',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Your artwork needs to withstand extreme weather, including high winds. Make sure it\'s securely anchored, that it’s not going to fall over, and nothing will fall off. 
Describe how you intend to anchor it: what will you use to mark guy ropes and cover rebar?
For large-scale installations, we\'ll need to have your piece signed off by an engineer. ',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 17,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_structural_safety',
    'label' => 'Structural safety',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 45,
    ),
  );

  // Exported field_instance:
  // 'node-artwork_registration-field_team_structural_rep'.
  $field_instances['node-artwork_registration-field_team_structural_rep'] = array(
    'bundle' => 'artwork_registration',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'multifield',
        'settings' => array(
          'view_mode' => 'default',
        ),
        'type' => 'multifield_default',
        'weight' => 18,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_team_structural_rep',
    'label' => 'Do you have someone on your team responsible for assuring structural safety?',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'multifield',
      'settings' => array(),
      'type' => 'multifield_default',
      'weight' => 46,
    ),
  );

  // Exported field_instance: 'node-artwork_registration-field_transport'.
  $field_instances['node-artwork_registration-field_transport'] = array(
    'bundle' => 'artwork_registration',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'How are you planning to transport your artwork to Tankwa Town?',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 20,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_transport',
    'label' => 'Transport',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'node-artwork_registration-field_website'.
  $field_instances['node-artwork_registration-field_website'] = array(
    'bundle' => 'artwork_registration',
    'custom_add_another' => 'Add another web link',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'You don\'t have to have this, but your project will benefit from it. Think of fundraising campaigns, support from the community, collaboration with other creative teams, etc.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 33,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_website',
    'label' => 'Website',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'configurable_class' => 0,
        'configurable_title' => 0,
        'rel' => '',
        'target' => 'default',
        'title' => '',
      ),
      'custom_add_another' => '',
      'custom_remove' => '',
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'rel_remove' => 'default',
      'title' => 'none',
      'title_label_use_field_label' => 0,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 11,
    ),
  );

  // Exported field_instance:
  // 'node-artwork_registration-field_where_are_you_based'.
  $field_instances['node-artwork_registration-field_where_are_you_based'] = array(
    'bundle' => 'artwork_registration',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => array(
      0 => array(
        'iso2' => 'ZA',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'countries',
        'settings' => array(),
        'type' => 'country_default',
        'weight' => 60,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_where_are_you_based',
    'label' => 'Where are you, as a collective, based?',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 9,
    ),
  );

  // Exported field_instance:
  // 'node-artwork_registration-field_who_are_you_brief_bio_'.
  $field_instances['node-artwork_registration-field_who_are_you_brief_bio_'] = array(
    'bundle' => 'artwork_registration',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'What do you & your crew do in the default world? Keep it brief (we\'re not after your CV)',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 8,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_who_are_you_brief_bio_',
    'label' => 'Who are you? Provide a brief bio.',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 12,
    ),
  );

  // Exported field_instance:
  // 'node-artwork_registration-field_year_and_name_of_prev'.
  $field_instances['node-artwork_registration-field_year_and_name_of_prev'] = array(
    'bundle' => 'artwork_registration',
    'custom_add_another' => 'Add Another Project',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'multifield',
        'settings' => array(
          'view_mode' => 'default',
        ),
        'type' => 'multifield_default',
        'weight' => 44,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_year_and_name_of_prev',
    'label' => 'Year and name of previous projects',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'multifield',
      'settings' => array(),
      'type' => 'multifield_default',
      'weight' => 13,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('<p><b>Level 1</b> non-amplified sound: it includes instrumental music, as well as sound at the level of a normal (domestic hi-fi) stereo without sub woofers etc. This level permits you to play sound in most areas during the day unless it\'s a silent zone near the temple or other artworks.</p>

<p><b>Level 2</b> amplified sound: system with sub woofers. This can only be played in specified areas within the Binnekring during the day, and in Sound Zones at night. Please be very aware of Quiet Zones and where artworks require low sound in their surrounds, as well as which way your speakers point..</p>

<p><b>Level 3</b> very large club or stadium-size sound. These systems can only be played at full volume in Sound Zones with speakers orientated away from the Binnekring and camping areas. </p>');
  t('<p>Brief description.</p>
<p>Who are you as a collective? What\'s your project about?</p>
<p>Are you looking for specific skills? Are you open to collaborate with different arts and their input?</p>');
  t('Any other narrative or piece of information that that you feel we should know about you and/or your project? ');
  t('Anything else?');
  t('Are you applying for a Creative Grant?');
  t('Are you interested in collaborating with other artists and/or working with volunteers?');
  t('Are you planning any sort of projection, 3D Mapping, laser, etc?');
  t('Are you planning to burn your artwork and/or does it have a fire component?');
  t('Artwork removal & burn site cleanup');
  t('Briefly describe your artwork. What is it? What\'s it made of? Is it interactive? Does it have moving parts? Does it have wheels? And is there a story behind it? 
(We\'re not looking for a two page essay, just enough for us to understand what the artwork is) ');
  t('Burning requires particular construction materials and extra safety precautions, and also releases a significant amount of carbon into the environment.
We encourage artists to create pieces that can be re-used and enjoyed outside of Tankwa Town. ');
  t('Contact email');
  t('Contact person');
  t('Creative Lead');
  t('Crew members and their roles');
  t('Depending on your answer we might have more questions for you...');
  t('Describe your lighting plan');
  t('Describe your project');
  t('Dimensions');
  t('Do you have a stage or performance area where you would welcome performers to?');
  t('Do you have someone on your team responsible for assuring structural safety?');
  t('Does your artwork have a sound component?');
  t('Even if you\'re not using light as an aesthetic component of your piece, you need to make it visible at night (including guy ropes/anchors).');
  t('Fundraiser');
  t('Got additional docs or PDF\'s? Add them here.');
  t('How are you planning to transport your artwork to Tankwa Town?');
  t('If in South Africa, please select your municipal district');
  t('If yes, please describe the nature and size of your sound');
  t('If you know exactly where you want your piece to be, look at the map and select from the drop down list below.');
  t('If you plan to burn your piece, you\'ll need a designated Pyro Co-ordinator (This can be you).');
  t('Image types allowed: png, jpg, jpeg <br>
(max image size: 2 MB)');
  t('In terms of size, how would you classify your project?');
  t('Is your piece associated with any other projects at AfrikaBurn?');
  t('It’s your responsibility to remove your piece once the event is over, and ensure that no trace remains. Nothing. Nada. Zilch. Zip. Zero. Fokol. <br>
If you\'re burning it, it\'s also your responsibility to remove all burn debris left on your site (including ash, charcoal, nails, screws, wire and staples etc). ');
  t('List other projects you\'ve worked on or generated in the default world.');
  t('MOOP Representative');
  t('Materials');
  t('Name of the collective and/or creator');
  t('Note, this will be made public for new members to contact.');
  t('Offsite building');
  t('Onsite building');
  t('Other projects');
  t('Performer Types');
  t('Philosophical statement');
  t('Placement');
  t('Placement Map');
  t('Planned activities');
  t('Planning performance or music to accompany your piece? Are there other participants involved? 
Give us an idea of the elements that are part of your artistic vision. 
If you\'re planning burning it, do you have any pre-, during, or post-burn plans? ');
  t('Please describe your light output devices and power sources');
  t('Please list all materials to be used in your project - and remember: we encourage the use of waste, salvage, recyclable, environmentally friendly and reusable materials. 
If you\'re considering burning your piece please read up about this on our website, and check what materials are acceptable to use.');
  t('Please select the level of your Sound');
  t('Please submit concept images');
  t('Project Manager');
  t('Provide a description of the space and performers you are looking for');
  t('Remember: you don\'t have to burn your piece. 
You might think that burning it is an easy way to get rid of it (and not transport it back) - it\'s not: you\'d still have to clean up the burn site and remove all coals, rebar etc. 
So consider whether burning is important to the meaning of your piece carefulluy. 
We love works that can be used outside of the event again, whether as installations or at Decompression, Streetopia, Maker Faire etc.');
  t('Select your placement location');
  t('Sometimes there\'s human resources missing in a team and/or artistic elements that your team can\'t bring to the project.
This isn\'t reason to kill your project: it\'s an opportunity to promote Participation and Gifting and exercise Communal Effort!<br>
If you\'d like to collaborate with other participants and volunteers, write a brief description of your project and specify your needs and/or how you envisage collaboration.
This info will be made public on our website to allow volunteers to choose the project(s) that they feel they can contribute to.<br>');
  t('Structural safety');
  t('Tell them who you are and what you are looking for');
  t('This isn\'t a required field but you\'re free to tell us if there\'s a story behind your artwork that might help us understand it better. ');
  t('Transport');
  t('Website');
  t('What do you & your crew do in the default world? Keep it brief (we\'re not after your CV)');
  t('What\'s your motivation to burn your piece?');
  t('Where are you, as a collective, based?');
  t('Where would you ideally like to install your Artwork?
Are there any considerations we need to take into account when placing your artwork? Did you have a specific spot in mind when designing it? For example, it might be important for you to have it near your/a theme camp, “out far”, near the hubbub of Off-Centre Camp or a quiet reflective space, a particularly flat surface etc. 
Please note that we’ll try our best to accommodate your needs, but cannot guarantee any specific spots. 
NB: your intention to burn your piece, sound specifications, and planned activities play an important role in placement. ');
  t('Who are you? Provide a brief bio.');
  t('Who is the person in your team in charge of lighting?');
  t('Who is the sound co-ordinator on your crew? (This can be you.)');
  t('Will your artwork have any lighting component?');
  t('Year and name of previous projects');
  t('You don\'t have to have this, but your project will benefit from it. Think of fundraising campaigns, support from the community, collaboration with other creative teams, etc.');
  t('Your MOOP Representative will be requested to read and accept the MOOP Manifesto, attend workshops and briefs, fill in the MOOP form, and supply all details requested by our MOOP Squad.<br>
This person plays an active role in the \'education\' of the whole team and will be the difference between a Red and a Green MOOP score on the MOOP Map.<br>
Remember that the MOOP Score of your project this year will affect every member of the team (and future possible funding and direct distribution of tickets). Choose wisely!');
  t('Your artwork needs to withstand extreme weather, including high winds. Make sure it\'s securely anchored, that it’s not going to fall over, and nothing will fall off. 
Describe how you intend to anchor it: what will you use to mark guy ropes and cover rebar?
For large-scale installations, we\'ll need to have your piece signed off by an engineer. ');

  return $field_instances;
}
