<?php
/**
 * @file
 * performance_registration.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function performance_registration_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'multifield-field_fire_person-field_email_address'.
  $field_instances['multifield-field_fire_person-field_email_address'] = array(
    'bundle' => 'field_fire_person',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'email',
        'settings' => array(),
        'type' => 'email_default',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'multifield',
    'field_name' => 'field_email_address',
    'label' => 'Email Address',
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
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'multifield-field_fire_person-field_first_name'.
  $field_instances['multifield-field_fire_person-field_first_name'] = array(
    'bundle' => 'field_fire_person',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'multifield',
    'field_name' => 'field_first_name',
    'label' => 'First Name',
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
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'multifield-field_fire_person-field_last_name'.
  $field_instances['multifield-field_fire_person-field_last_name'] = array(
    'bundle' => 'field_fire_person',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'multifield',
    'field_name' => 'field_last_name',
    'label' => 'Last Name',
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
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'multifield-field_fire_person-field_phone_number'.
  $field_instances['multifield-field_fire_person-field_phone_number'] = array(
    'bundle' => 'field_fire_person',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_plain',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'multifield',
    'field_name' => 'field_phone_number',
    'label' => 'Phone Number',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'telephone',
      'settings' => array(
        'placeholder' => '',
      ),
      'type' => 'telephone_default',
      'weight' => 8,
    ),
  );

  // Exported field_instance:
  // 'multifield-field_team_structural_rep-field_email_address'.
  $field_instances['multifield-field_team_structural_rep-field_email_address'] = array(
    'bundle' => 'field_team_structural_rep',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'email',
        'settings' => array(),
        'type' => 'email_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'multifield',
    'field_name' => 'field_email_address',
    'label' => 'Email Address',
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
      'weight' => 3,
    ),
  );

  // Exported field_instance:
  // 'multifield-field_team_structural_rep-field_first_name'.
  $field_instances['multifield-field_team_structural_rep-field_first_name'] = array(
    'bundle' => 'field_team_structural_rep',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'multifield',
    'field_name' => 'field_first_name',
    'label' => 'First Name',
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

  // Exported field_instance:
  // 'multifield-field_team_structural_rep-field_last_name'.
  $field_instances['multifield-field_team_structural_rep-field_last_name'] = array(
    'bundle' => 'field_team_structural_rep',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'multifield',
    'field_name' => 'field_last_name',
    'label' => 'Last Name',
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
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'multifield-field_team_structural_rep-field_phone_number'.
  $field_instances['multifield-field_team_structural_rep-field_phone_number'] = array(
    'bundle' => 'field_team_structural_rep',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_plain',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'multifield',
    'field_name' => 'field_phone_number',
    'label' => 'Phone Number',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'telephone',
      'settings' => array(
        'placeholder' => '',
      ),
      'type' => 'telephone_default',
      'weight' => 4,
    ),
  );

  // Exported field_instance:
  // 'node-performance_registration-field_additional_docs'.
  $field_instances['node-performance_registration-field_additional_docs'] = array(
    'bundle' => 'performance_registration',
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
    'field_name' => 'field_additional_docs',
    'label' => 'Got additional documentation or PDF\'s? Add those here.',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'description_field' => 0,
      'file_directory' => 'performance',
      'file_extensions' => 'doc xls pdf ppt odt fodt ods fods odp fodp odg fodg odf',
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
      'weight' => 15,
    ),
  );

  // Exported field_instance:
  // 'node-performance_registration-field_anything_else'.
  $field_instances['node-performance_registration-field_anything_else'] = array(
    'bundle' => 'performance_registration',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Any other narrative or piece of information that that you feel we should know about you and/or your project? ',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
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
    'field_name' => 'field_anything_else',
    'label' => 'Anything Else?',
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
      'weight' => 69,
    ),
  );

  // Exported field_instance:
  // 'node-performance_registration-field_artwork_site_clean'.
  $field_instances['node-performance_registration-field_artwork_site_clean'] = array(
    'bundle' => 'performance_registration',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'It’s your responsibility to remove your creation from the site once the event is over, and to ensure that no trace of it remains afterward. <br>
If you\'re burning your artwork, it\'s also your responsibility to remove all burn debris left on your site, including ash and charcoal, nails, screws, wire and staples. <br>
Please bring along a bag and any equipment needed to do so (consider a magnet sweep if your piece features numerous small metal items).<br>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'multifield',
        'settings' => array(
          'view_mode' => 'default',
        ),
        'type' => 'multifield_default',
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
    'field_name' => 'field_artwork_site_clean',
    'label' => 'Artwork removal & site cleanup',
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
      'weight' => 52,
    ),
  );

  // Exported field_instance:
  // 'node-performance_registration-field_associated_projects'.
  $field_instances['node-performance_registration-field_associated_projects'] = array(
    'bundle' => 'performance_registration',
    'custom_add_another' => 'Add another associated project',
    'custom_remove' => 'Remove this project',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'List each associated project on a separate line.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'multifield',
        'settings' => array(
          'view_mode' => 'default',
        ),
        'type' => 'multifield_default',
        'weight' => 27,
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
    'label' => 'What\'s the name of the Theme Camp or Artwork your project is associated with?',
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
      'weight' => 22,
    ),
  );

  // Exported field_instance:
  // 'node-performance_registration-field_burn_safety_consideration'.
  $field_instances['node-performance_registration-field_burn_safety_consideration'] = array(
    'bundle' => 'performance_registration',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Depending on your answer we might have more questions for you...',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
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
    'field_name' => 'field_burn_safety_consideration',
    'label' => 'Please describe the fire element in your performance.',
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
      'weight' => 68,
    ),
  );

  // Exported field_instance:
  // 'node-performance_registration-field_contact_person'.
  $field_instances['node-performance_registration-field_contact_person'] = array(
    'bundle' => 'performance_registration',
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
      'weight' => 0,
    ),
  );

  // Exported field_instance:
  // 'node-performance_registration-field_creative_lead'.
  $field_instances['node-performance_registration-field_creative_lead'] = array(
    'bundle' => 'performance_registration',
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
    'field_name' => 'field_creative_lead',
    'label' => 'Creative lead',
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
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'node-performance_registration-field_crew_members'.
  $field_instances['node-performance_registration-field_crew_members'] = array(
    'bundle' => 'performance_registration',
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
    'field_name' => 'field_crew_members',
    'label' => 'Your crew members and their roles',
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
      'weight' => 5,
    ),
  );

  // Exported field_instance:
  // 'node-performance_registration-field_describe_your_project'.
  $field_instances['node-performance_registration-field_describe_your_project'] = array(
    'bundle' => 'performance_registration',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Briefly describe your performance. What is it? And is there a story behind it? <br>
(We\'re not looking for a two page essay, just enough for us to understand what the project is) ',
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
      'weight' => 12,
    ),
  );

  // Exported field_instance:
  // 'node-performance_registration-field_dimentions_m2'.
  $field_instances['node-performance_registration-field_dimentions_m2'] = array(
    'bundle' => 'performance_registration',
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
      'weight' => 59,
    ),
  );

  // Exported field_instance:
  // 'node-performance_registration-field_does_it_have_sound_effects'.
  $field_instances['node-performance_registration-field_does_it_have_sound_effects'] = array(
    'bundle' => 'performance_registration',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
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
    'field_name' => 'field_does_it_have_sound_effects',
    'label' => 'Does your performance have a sound component?',
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
      'weight' => 32,
    ),
  );

  // Exported field_instance: 'node-performance_registration-field_fire_person'.
  $field_instances['node-performance_registration-field_fire_person'] = array(
    'bundle' => 'performance_registration',
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
        'weight' => 37,
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
    'label' => 'You\'ll have to designate someone in your team specifically as the Pyro Person (This can be you).',
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
      'weight' => 69,
    ),
  );

  // Exported field_instance: 'node-performance_registration-field_fire_yn'.
  $field_instances['node-performance_registration-field_fire_yn'] = array(
    'bundle' => 'performance_registration',
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
    'field_name' => 'field_fire_yn',
    'label' => 'Is there a fire aspect to your performance?',
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
      'weight' => 67,
    ),
  );

  // Exported field_instance: 'node-performance_registration-field_fundraiser'.
  $field_instances['node-performance_registration-field_fundraiser'] = array(
    'bundle' => 'performance_registration',
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
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-performance_registration-field_history'.
  $field_instances['node-performance_registration-field_history'] = array(
    'bundle' => 'performance_registration',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Please list any projects you have worked on or generated in the default world.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
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
    'field_name' => 'field_history',
    'label' => 'Other projects',
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
  // 'node-performance_registration-field_if_in_south_africa_please_'.
  $field_instances['node-performance_registration-field_if_in_south_africa_please_'] = array(
    'bundle' => 'performance_registration',
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
      'weight' => 7,
    ),
  );

  // Exported field_instance:
  // 'node-performance_registration-field_image_project'.
  $field_instances['node-performance_registration-field_image_project'] = array(
    'bundle' => 'performance_registration',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Please give us details.',
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
      'weight' => 29,
    ),
  );

  // Exported field_instance:
  // 'node-performance_registration-field_location_map'.
  $field_instances['node-performance_registration-field_location_map'] = array(
    'bundle' => 'performance_registration',
    'custom_add_another' => '',
    'custom_remove' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'markup',
        'settings' => array(),
        'type' => 'markup_default',
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
    'field_name' => 'field_location_map',
    'label' => 'Placement map',
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
      'weight' => 19,
    ),
  );

  // Exported field_instance:
  // 'node-performance_registration-field_location_picker'.
  $field_instances['node-performance_registration-field_location_picker'] = array(
    'bundle' => 'performance_registration',
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
    'field_name' => 'field_location_picker',
    'label' => 'Choose Placement',
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
      'weight' => 20,
    ),
  );

  // Exported field_instance: 'node-performance_registration-field_materials'.
  $field_instances['node-performance_registration-field_materials'] = array(
    'bundle' => 'performance_registration',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Please list all materials to be used in this project. <br>
We encourage the use of waste, salvage, recyclable, environmentally friendly and reusable materials.  <br>
If you are considering to burn your artwork please read up about this on our website, and check what materials are acceptable to use.',
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
      'weight' => 61,
    ),
  );

  // Exported field_instance:
  // 'node-performance_registration-field_moop_representative'.
  $field_instances['node-performance_registration-field_moop_representative'] = array(
    'bundle' => 'performance_registration',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Your MOOP representative will be requested to read and accept the MOOP Manifesto, attend to workshops and briefs, fill in the MOOP form, and supply all details requested by our MOOP Squad.<br>
This person plays an active role in the education of the whole team and will be the difference between a red and a green score on the MOOP Map.<br>
Remember that the score of your project this year will affect every member of the team (eg: future funding and direct distribution of tickets). Choose wisely!',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'multifield',
        'settings' => array(
          'view_mode' => 'default',
        ),
        'type' => 'multifield_default',
        'weight' => 6,
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
    'label' => 'MOOP representative',
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

  // Exported field_instance:
  // 'node-performance_registration-field_name_of_collective'.
  $field_instances['node-performance_registration-field_name_of_collective'] = array(
    'bundle' => 'performance_registration',
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
    'field_name' => 'field_name_of_collective',
    'label' => 'Name of collective',
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

  // Exported field_instance: 'node-performance_registration-field_new_members'.
  $field_instances['node-performance_registration-field_new_members'] = array(
    'bundle' => 'performance_registration',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Sometimes there\'s human resources missing in a team and/or artistic elements that your team cannot bring to the project.<br>
This isn\'t reason to kill your project, it is an opportunity to promote Participation and Gifting and exercise Communal Effort!<br>
If you would like to collaborate with other participants and volunteers, please write up a brief description of your project and specify your needs and/or how you\'re envisioning collaboration.<br>
This information will be made public on our website to allow volunteers to choose the project(s) that they feel they can contribute to.<br>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
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
      'weight' => 11,
    ),
  );

  // Exported field_instance:
  // 'node-performance_registration-field_new_members_details'.
  $field_instances['node-performance_registration-field_new_members_details'] = array(
    'bundle' => 'performance_registration',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '<p>Brief description.</p>
<p>Who are you as a collective? What\'s your project about?</p>
<p>Are you looking for specific skills? Are you open to collaborating with other artists and getting their input?</p>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
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
    'field_name' => 'field_new_members_details',
    'label' => 'Tell them who you are and what you\'re looking for',
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
      'weight' => 12,
    ),
  );

  // Exported field_instance:
  // 'node-performance_registration-field_new_members_email'.
  $field_instances['node-performance_registration-field_new_members_email'] = array(
    'bundle' => 'performance_registration',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'This will be made public in the relevant section of our website, and interested collaborators can contact you directly.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'email',
        'settings' => array(),
        'type' => 'email_default',
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
    'field_name' => 'field_new_members_email',
    'label' => 'Contact email',
    'required' => 0,
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
      'weight' => 13,
    ),
  );

  // Exported field_instance: 'node-performance_registration-field_night'.
  $field_instances['node-performance_registration-field_night'] = array(
    'bundle' => 'performance_registration',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
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
    'field_name' => 'field_night',
    'label' => 'Will your performance have any lighting component?',
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
      'weight' => 27,
    ),
  );

  // Exported field_instance:
  // 'node-performance_registration-field_offsite_building'.
  $field_instances['node-performance_registration-field_offsite_building'] = array(
    'bundle' => 'performance_registration',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => array(
      0 => array(
        'field_when_are_you_planning_to_s' => array(
          'und' => array(
            0 => array(
              'value' => '2016-08-21 00:00:00',
              'show_todate' => FALSE,
              'timezone' => 'Africa/Johannesburg',
              'offset' => 7200,
              'offset2' => 7200,
              'value2' => '2016-08-21 00:00:00',
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
    'description' => 'Where are you going to build the physical structure of your project?
When are you planning to start building offsite?',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'multifield',
        'settings' => array(
          'view_mode' => 'default',
        ),
        'type' => 'multifield_default',
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
      'weight' => 48,
    ),
  );

  // Exported field_instance:
  // 'node-performance_registration-field_on_site_building'.
  $field_instances['node-performance_registration-field_on_site_building'] = array(
    'bundle' => 'performance_registration',
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
              'value' => '2016-08-21 00:00:00',
              'show_todate' => FALSE,
              'timezone' => 'Africa/Johannesburg',
              'offset' => 7200,
              'offset2' => 7200,
              'value2' => '2016-08-21 00:00:00',
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
    'description' => 'How long do you estimate it will take to install your piece on site?
When are you planning to start building on site?',
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
    'field_name' => 'field_on_site_building',
    'label' => 'On-site setup',
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
      'weight' => 50,
    ),
  );

  // Exported field_instance:
  // 'node-performance_registration-field_other_creative_projects'.
  $field_instances['node-performance_registration-field_other_creative_projects'] = array(
    'bundle' => 'performance_registration',
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
    'field_name' => 'field_other_creative_projects',
    'label' => 'Have you registered, or are you planning to register, any other creative project?',
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
      'weight' => 67,
    ),
  );

  // Exported field_instance:
  // 'node-performance_registration-field_person_lighting'.
  $field_instances['node-performance_registration-field_person_lighting'] = array(
    'bundle' => 'performance_registration',
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
      'weight' => 32,
    ),
  );

  // Exported field_instance:
  // 'node-performance_registration-field_philosophical_statement'.
  $field_instances['node-performance_registration-field_philosophical_statement'] = array(
    'bundle' => 'performance_registration',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'This is not a required field but do tell us if there is a story behind your project that might make us understand it better. ',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 15,
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
      'weight' => 13,
    ),
  );

  // Exported field_instance: 'node-performance_registration-field_placement'.
  $field_instances['node-performance_registration-field_placement'] = array(
    'bundle' => 'performance_registration',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Where would you like your project to happen? ​- - Try to give us an approximate location, using street names, artworks, Theme Camps and other reference points. You can also try describe the kind of space your performance needs... ',
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
      'weight' => 18,
    ),
  );

  // Exported field_instance:
  // 'node-performance_registration-field_planned_activities'.
  $field_instances['node-performance_registration-field_planned_activities'] = array(
    'bundle' => 'performance_registration',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Don\'t worry if you haven\'t yet worked out your performance down to the minute.
How many appearances are you planning during the event?
What is the duration of your performance/s?
Does your performance require a set-up time? Please describe.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
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
      'weight' => 17,
    ),
  );

  // Exported field_instance:
  // 'node-performance_registration-field_please_submit_concept_imag'.
  $field_instances['node-performance_registration-field_please_submit_concept_imag'] = array(
    'bundle' => 'performance_registration',
    'deleted' => 0,
    'description' => 'Image types allowed: png, jpg, jpeg 
Max Image size is 2 MB',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
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
    'field_name' => 'field_please_submit_concept_imag',
    'label' => 'Please submit a concept image',
    'required' => 1,
    'settings' => array(
      'alt_field' => 0,
      'custom_add_another' => '',
      'custom_remove' => '',
      'default_image' => 0,
      'file_directory' => '',
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
      'weight' => 14,
    ),
  );

  // Exported field_instance:
  // 'node-performance_registration-field_pr_structure_yn'.
  $field_instances['node-performance_registration-field_pr_structure_yn'] = array(
    'bundle' => 'performance_registration',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 51,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pr_structure_yn',
    'label' => 'Is there a physical structure associated with your performance?',
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
      'weight' => 58,
    ),
  );

  // Exported field_instance:
  // 'node-performance_registration-field_project_manager'.
  $field_instances['node-performance_registration-field_project_manager'] = array(
    'bundle' => 'performance_registration',
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
    'field_name' => 'field_project_manager',
    'label' => 'Project manager',
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
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'node-performance_registration-field_related_project'.
  $field_instances['node-performance_registration-field_related_project'] = array(
    'bundle' => 'performance_registration',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '​A Theme Camps, Artwork, Mutant Vehicle and/or another Performance?​',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 25,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_related_project',
    'label' => 'Is your performance associated with another registered project?',
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
      'weight' => 21,
    ),
  );

  // Exported field_instance: 'node-performance_registration-field_sound_level'.
  $field_instances['node-performance_registration-field_sound_level'] = array(
    'bundle' => 'performance_registration',
    'custom_add_another' => '',
    'custom_remove' => '',
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
        'weight' => 34,
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
    'label' => 'Please select the level of your sound component',
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
      'weight' => 33,
    ),
  );

  // Exported field_instance:
  // 'node-performance_registration-field_sound_person'.
  $field_instances['node-performance_registration-field_sound_person'] = array(
    'bundle' => 'performance_registration',
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
        'weight' => 35,
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
    'label' => 'Who is the sound co-ordinator in your team? (This can be you.)',
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
      'weight' => 35,
    ),
  );

  // Exported field_instance:
  // 'node-performance_registration-field_sound_safety'.
  $field_instances['node-performance_registration-field_sound_safety'] = array(
    'bundle' => 'performance_registration',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Depending on your answer we might have more questions for you...',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
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
    'field_name' => 'field_sound_safety',
    'label' => 'Please describe the nature and size of your sound.',
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
      'weight' => 34,
    ),
  );

  // Exported field_instance:
  // 'node-performance_registration-field_structural_safety'.
  $field_instances['node-performance_registration-field_structural_safety'] = array(
    'bundle' => 'performance_registration',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Your artwork needs to withstand extreme weather, including high winds. Make sure it\'s securely anchored, that it’s not going to fall over, and nothing will fall off. <br>
Describe how you intend to anchor it. What will you use to mark guy ropes and cover rebar? <br>
For large-scale installations, we\'ll need to have your piece signed off by an engineer. ',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
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
      'weight' => 62,
    ),
  );

  // Exported field_instance:
  // 'node-performance_registration-field_team_structural_rep'.
  $field_instances['node-performance_registration-field_team_structural_rep'] = array(
    'bundle' => 'performance_registration',
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
    'field_name' => 'field_team_structural_rep',
    'label' => 'Do you have in your team someone specifically responsible for assuring that the piece is structurally safe',
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
      'weight' => 63,
    ),
  );

  // Exported field_instance:
  // 'node-performance_registration-field_trailer_lighting'.
  $field_instances['node-performance_registration-field_trailer_lighting'] = array(
    'bundle' => 'performance_registration',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 29,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_trailer_lighting',
    'label' => 'Please describe your lighting plan.',
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

  // Exported field_instance: 'node-performance_registration-field_transport'.
  $field_instances['node-performance_registration-field_transport'] = array(
    'bundle' => 'performance_registration',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'How are you planning to transport your piece to Tankwa Town?',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
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
      'weight' => 49,
    ),
  );

  // Exported field_instance: 'node-performance_registration-field_website'.
  $field_instances['node-performance_registration-field_website'] = array(
    'bundle' => 'performance_registration',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'You don\'t have to have this, but you project will benefit from it. Think of fundraising campaigns, support from the community, collaboration with other creative teams, etc.
',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
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
      'weight' => 16,
    ),
  );

  // Exported field_instance:
  // 'node-performance_registration-field_where_are_you_based'.
  $field_instances['node-performance_registration-field_where_are_you_based'] = array(
    'bundle' => 'performance_registration',
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
        'weight' => 56,
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
    'label' => 'Where in the world are you, as a collective, based?',
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
      'weight' => 6,
    ),
  );

  // Exported field_instance:
  // 'node-performance_registration-field_who_are_you_brief_bio_'.
  $field_instances['node-performance_registration-field_who_are_you_brief_bio_'] = array(
    'bundle' => 'performance_registration',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'What do you and your team do in the default world? Please be brief (we\'re not after your CV). ',
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
    'field_name' => 'field_who_are_you_brief_bio_',
    'label' => 'Who are you?',
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

  // Exported field_instance:
  // 'node-performance_registration-field_year_and_name_of_prev'.
  $field_instances['node-performance_registration-field_year_and_name_of_prev'] = array(
    'bundle' => 'performance_registration',
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
        'weight' => 13,
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
      'weight' => 9,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('<p><b>Level 1</b> non-amplified sound: it includes instrumental music, as well as sound at the level of a normal (domestic hi-fi) stereo without sub woofers etc. This level permits you to play sound in most areas during the day unless it\'s a silent zone near the temple or other artworks.</p>

<p><b>Level 2</b> amplified sound: system with sub woofers. This can only be played in specified areas within the Binnekring during the day, and in Sound Zones at night. Please be very aware of Quiet Zones and where artworks require low sound in their surrounds, as well as which way your speakers point..</p>

<p><b>Level 3</b> very large club or stadium-size sound. These systems can only be played at full volume in Sound Zones with speakers orientated away from the Binnekring and camping areas. </p>');
  t('<p>Brief description.</p>
<p>Who are you as a collective? What\'s your project about?</p>
<p>Are you looking for specific skills? Are you open to collaborating with other artists and getting their input?</p>');
  t('Any other narrative or piece of information that that you feel we should know about you and/or your project? ');
  t('Anything Else?');
  t('Are you interested in collaborating with other artists and/or working with volunteers?');
  t('Are you planning any sort of projection, 3D Mapping, laser, etc?');
  t('Artwork removal & site cleanup');
  t('Briefly describe your performance. What is it? And is there a story behind it? <br>
(We\'re not looking for a two page essay, just enough for us to understand what the project is) ');
  t('Choose Placement');
  t('Contact email');
  t('Contact person');
  t('Creative lead');
  t('Depending on your answer we might have more questions for you...');
  t('Describe your project');
  t('Dimensions');
  t('Do you have in your team someone specifically responsible for assuring that the piece is structurally safe');
  t('Does your performance have a sound component?');
  t('Don\'t worry if you haven\'t yet worked out your performance down to the minute.
How many appearances are you planning during the event?
What is the duration of your performance/s?
Does your performance require a set-up time? Please describe.');
  t('Email Address');
  t('First Name');
  t('Fundraiser');
  t('Got additional documentation or PDF\'s? Add those here.');
  t('Have you registered, or are you planning to register, any other creative project?');
  t('How are you planning to transport your piece to Tankwa Town?');
  t('How long do you estimate it will take to install your piece on site?
When are you planning to start building on site?');
  t('If in South Africa, please select your municipal district');
  t('Image types allowed: png, jpg, jpeg 
Max Image size is 2 MB');
  t('Is there a fire aspect to your performance?');
  t('Is there a physical structure associated with your performance?');
  t('Is your performance associated with another registered project?');
  t('It’s your responsibility to remove your creation from the site once the event is over, and to ensure that no trace of it remains afterward. <br>
If you\'re burning your artwork, it\'s also your responsibility to remove all burn debris left on your site, including ash and charcoal, nails, screws, wire and staples. <br>
Please bring along a bag and any equipment needed to do so (consider a magnet sweep if your piece features numerous small metal items).<br>');
  t('Last Name');
  t('List each associated project on a separate line.');
  t('MOOP representative');
  t('Materials');
  t('Name of collective');
  t('Offsite building');
  t('On-site setup');
  t('Other projects');
  t('Philosophical statement');
  t('Phone Number');
  t('Placement');
  t('Placement map');
  t('Planned activities');
  t('Please describe the fire element in your performance.');
  t('Please describe the nature and size of your sound.');
  t('Please describe your lighting plan.');
  t('Please give us details.');
  t('Please list all materials to be used in this project. <br>
We encourage the use of waste, salvage, recyclable, environmentally friendly and reusable materials.  <br>
If you are considering to burn your artwork please read up about this on our website, and check what materials are acceptable to use.');
  t('Please list any projects you have worked on or generated in the default world.');
  t('Please select the level of your sound component');
  t('Please submit a concept image');
  t('Project manager');
  t('Sometimes there\'s human resources missing in a team and/or artistic elements that your team cannot bring to the project.<br>
This isn\'t reason to kill your project, it is an opportunity to promote Participation and Gifting and exercise Communal Effort!<br>
If you would like to collaborate with other participants and volunteers, please write up a brief description of your project and specify your needs and/or how you\'re envisioning collaboration.<br>
This information will be made public on our website to allow volunteers to choose the project(s) that they feel they can contribute to.<br>');
  t('Structural safety');
  t('Tell them who you are and what you\'re looking for');
  t('This is not a required field but do tell us if there is a story behind your project that might make us understand it better. ');
  t('This will be made public in the relevant section of our website, and interested collaborators can contact you directly.');
  t('Transport');
  t('Website');
  t('What do you and your team do in the default world? Please be brief (we\'re not after your CV). ');
  t('What\'s the name of the Theme Camp or Artwork your project is associated with?');
  t('Where are you going to build the physical structure of your project?
When are you planning to start building offsite?');
  t('Where in the world are you, as a collective, based?');
  t('Where would you like your project to happen? ​- - Try to give us an approximate location, using street names, artworks, Theme Camps and other reference points. You can also try describe the kind of space your performance needs... ');
  t('Who are you?');
  t('Who is the person in your team in charge of lighting?');
  t('Who is the sound co-ordinator in your team? (This can be you.)');
  t('Will your performance have any lighting component?');
  t('Year and name of previous projects');
  t('You don\'t have to have this, but you project will benefit from it. Think of fundraising campaigns, support from the community, collaboration with other creative teams, etc.
');
  t('You\'ll have to designate someone in your team specifically as the Pyro Person (This can be you).');
  t('Your MOOP representative will be requested to read and accept the MOOP Manifesto, attend to workshops and briefs, fill in the MOOP form, and supply all details requested by our MOOP Squad.<br>
This person plays an active role in the education of the whole team and will be the difference between a red and a green score on the MOOP Map.<br>
Remember that the score of your project this year will affect every member of the team (eg: future funding and direct distribution of tickets). Choose wisely!');
  t('Your artwork needs to withstand extreme weather, including high winds. Make sure it\'s securely anchored, that it’s not going to fall over, and nothing will fall off. <br>
Describe how you intend to anchor it. What will you use to mark guy ropes and cover rebar? <br>
For large-scale installations, we\'ll need to have your piece signed off by an engineer. ');
  t('Your crew members and their roles');
  t('​A Theme Camps, Artwork, Mutant Vehicle and/or another Performance?​');

  return $field_instances;
}
