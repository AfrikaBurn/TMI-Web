<?php
/**
 * @file
 * artwork_registration_features_download.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function artwork_registration_features_download_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'multifield-field_artwork_site_clean-field_long_to_clean_up'.
  $field_instances['multifield-field_artwork_site_clean-field_long_to_clean_up'] = array(
    'bundle' => 'field_artwork_site_clean',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_integer',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'multifield',
    'field_name' => 'field_long_to_clean_up',
    'label' => 'How long do you estimate that it will take',
    'required' => 1,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => 'hours',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'multifield-field_artwork_site_clean-field_people_do_you_have'.
  $field_instances['multifield-field_artwork_site_clean-field_people_do_you_have'] = array(
    'bundle' => 'field_artwork_site_clean',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_integer',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'multifield',
    'field_name' => 'field_people_do_you_have',
    'label' => 'How many people do you have to help you clean up your site after removal or burn of the artwork',
    'required' => 1,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => 'people',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'multifield-field_associated_projects-field_how_is_it_related_'.
  $field_instances['multifield-field_associated_projects-field_how_is_it_related_'] = array(
    'bundle' => 'field_associated_projects',
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
    'field_name' => 'field_how_is_it_related_',
    'label' => 'How is it related?',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 3,
      ),
      'type' => 'text_textarea',
      'weight' => 3,
    ),
  );

  // Exported field_instance:
  // 'multifield-field_associated_projects-field_theme_camp'.
  $field_instances['multifield-field_associated_projects-field_theme_camp'] = array(
    'bundle' => 'field_associated_projects',
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
    'field_name' => 'field_theme_camp',
    'label' => 'What\'s the name of the projects that you are associated with?',
    'required' => 1,
    'settings' => array(
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
  // 'multifield-field_contact_person-field_email_address'.
  $field_instances['multifield-field_contact_person-field_email_address'] = array(
    'bundle' => 'field_contact_person',
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
  // 'multifield-field_contact_person-field_first_name'.
  $field_instances['multifield-field_contact_person-field_first_name'] = array(
    'bundle' => 'field_contact_person',
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

  // Exported field_instance: 'multifield-field_contact_person-field_last_name'.
  $field_instances['multifield-field_contact_person-field_last_name'] = array(
    'bundle' => 'field_contact_person',
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
  // 'multifield-field_contact_person-field_phone_number'.
  $field_instances['multifield-field_contact_person-field_phone_number'] = array(
    'bundle' => 'field_contact_person',
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
  // 'multifield-field_creative_lead-field_email_address'.
  $field_instances['multifield-field_creative_lead-field_email_address'] = array(
    'bundle' => 'field_creative_lead',
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

  // Exported field_instance: 'multifield-field_creative_lead-field_first_name'.
  $field_instances['multifield-field_creative_lead-field_first_name'] = array(
    'bundle' => 'field_creative_lead',
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

  // Exported field_instance: 'multifield-field_creative_lead-field_last_name'.
  $field_instances['multifield-field_creative_lead-field_last_name'] = array(
    'bundle' => 'field_creative_lead',
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
  // 'multifield-field_creative_lead-field_phone_number'.
  $field_instances['multifield-field_creative_lead-field_phone_number'] = array(
    'bundle' => 'field_creative_lead',
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
  // 'multifield-field_crew_members-field_email_address'.
  $field_instances['multifield-field_crew_members-field_email_address'] = array(
    'bundle' => 'field_crew_members',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'email',
        'settings' => array(),
        'type' => 'email_default',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'multifield',
    'field_name' => 'field_email_address',
    'label' => 'Email Address',
    'required' => 1,
    'settings' => array(
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

  // Exported field_instance: 'multifield-field_crew_members-field_first_name'.
  $field_instances['multifield-field_crew_members-field_first_name'] = array(
    'bundle' => 'field_crew_members',
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

  // Exported field_instance: 'multifield-field_crew_members-field_last_name'.
  $field_instances['multifield-field_crew_members-field_last_name'] = array(
    'bundle' => 'field_crew_members',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'multifield',
    'field_name' => 'field_last_name',
    'label' => 'Last Name',
    'required' => 1,
    'settings' => array(
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
  // 'multifield-field_crew_members-field_phone_number'.
  $field_instances['multifield-field_crew_members-field_phone_number'] = array(
    'bundle' => 'field_crew_members',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_plain',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'multifield',
    'field_name' => 'field_phone_number',
    'label' => 'Phone Number',
    'required' => 1,
    'settings' => array(
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

  // Exported field_instance: 'multifield-field_crew_members-field_role'.
  $field_instances['multifield-field_crew_members-field_role'] = array(
    'bundle' => 'field_crew_members',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'multifield',
    'field_name' => 'field_role',
    'label' => 'Role',
    'required' => 1,
    'settings' => array(
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
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'multifield-field_dimensions-field_approx_weight'.
  $field_instances['multifield-field_dimensions-field_approx_weight'] = array(
    'bundle' => 'field_dimensions',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_integer',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'multifield',
    'field_name' => 'field_approx_weight',
    'label' => 'Approx Weight',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => 'Kilograms',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'multifield-field_dimensions-field_depth'.
  $field_instances['multifield-field_dimensions-field_depth'] = array(
    'bundle' => 'field_dimensions',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_integer',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'multifield',
    'field_name' => 'field_depth',
    'label' => 'Depth',
    'required' => 1,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => 'Metres',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'multifield-field_dimensions-field_height'.
  $field_instances['multifield-field_dimensions-field_height'] = array(
    'bundle' => 'field_dimensions',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_integer',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'multifield',
    'field_name' => 'field_height',
    'label' => 'Height',
    'required' => 1,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => 'Metres',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 0,
    ),
  );

  // Exported field_instance:
  // 'multifield-field_dimensions-field_other_relevant_phisical_at'.
  $field_instances['multifield-field_dimensions-field_other_relevant_phisical_at'] = array(
    'bundle' => 'field_dimensions',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Is it round? A string of balloons? A tree? etc.',
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
    'field_name' => 'field_other_relevant_phisical_at',
    'label' => 'Other Relevant Phisical Attributes',
    'required' => 1,
    'settings' => array(
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
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'multifield-field_dimensions-field_width'.
  $field_instances['multifield-field_dimensions-field_width'] = array(
    'bundle' => 'field_dimensions',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_integer',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'multifield',
    'field_name' => 'field_width',
    'label' => 'Width',
    'required' => 1,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => 'Metres',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 1,
    ),
  );

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

  // Exported field_instance: 'multifield-field_fundraiser-field_email_address'.
  $field_instances['multifield-field_fundraiser-field_email_address'] = array(
    'bundle' => 'field_fundraiser',
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

  // Exported field_instance: 'multifield-field_fundraiser-field_first_name'.
  $field_instances['multifield-field_fundraiser-field_first_name'] = array(
    'bundle' => 'field_fundraiser',
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

  // Exported field_instance: 'multifield-field_fundraiser-field_last_name'.
  $field_instances['multifield-field_fundraiser-field_last_name'] = array(
    'bundle' => 'field_fundraiser',
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

  // Exported field_instance: 'multifield-field_fundraiser-field_phone_number'.
  $field_instances['multifield-field_fundraiser-field_phone_number'] = array(
    'bundle' => 'field_fundraiser',
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
  // 'multifield-field_moop_representative-field_email_address'.
  $field_instances['multifield-field_moop_representative-field_email_address'] = array(
    'bundle' => 'field_moop_representative',
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
  // 'multifield-field_moop_representative-field_first_name'.
  $field_instances['multifield-field_moop_representative-field_first_name'] = array(
    'bundle' => 'field_moop_representative',
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
  // 'multifield-field_moop_representative-field_last_name'.
  $field_instances['multifield-field_moop_representative-field_last_name'] = array(
    'bundle' => 'field_moop_representative',
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
  // 'multifield-field_moop_representative-field_phone_number'.
  $field_instances['multifield-field_moop_representative-field_phone_number'] = array(
    'bundle' => 'field_moop_representative',
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
  // 'multifield-field_offsite_building-field_when_are_you_planning_to_s'.
  $field_instances['multifield-field_offsite_building-field_when_are_you_planning_to_s'] = array(
    'bundle' => 'field_offsite_building',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'long',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
          'show_remaining_days' => FALSE,
          'show_repeat_rule' => 'show',
        ),
        'type' => 'date_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'multifield',
    'field_name' => 'field_when_are_you_planning_to_s',
    'label' => 'When are you planning to start building offsite',
    'required' => 1,
    'settings' => array(
      'default_value' => 'now',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'display_all_day' => 0,
        'increment' => 15,
        'input_format' => 'Y-m-d H:i:s',
        'input_format_custom' => '',
        'label_position' => 'above',
        'no_fieldset' => 0,
        'repeat_collapsed' => 0,
        'text_parts' => array(),
        'year_range' => '-0:+1',
      ),
      'type' => 'date_popup',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'multifield-field_offsite_building-field_where_are_you_going_to_bui'.
  $field_instances['multifield-field_offsite_building-field_where_are_you_going_to_bui'] = array(
    'bundle' => 'field_offsite_building',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'multifield',
    'field_name' => 'field_where_are_you_going_to_bui',
    'label' => 'Where are you going to build your artwork',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'cck_select_other',
      'settings' => array(
        'select_list_options' => 'Eastern_Cape_Barkly_East|Eastern Cape→Barkly East
Eastern_Cape_East_London|Eastern Cape→East London
Eastern_Cape_Mount_Ayliff|Eastern Cape→Mount Ayliff
Eastern_Cape_Mthatha|Eastern Cape→Mthatha
Eastern_Cape_Port_Elizabeth|Eastern Cape→Port Elizabeth
Eastern_Cape_Queenstown|Eastern Cape→Queenstown
Free_State_Bloemfontein|Free State→Bloemfontein
Free_State_Phuthaditjhaba|Free State→Phuthaditjhaba
Free_State_Sasolburg|Free State→Sasolburg
Free_State_Trompsburg|Free State→Trompsburg
Free_State_Welkom|Free State→Welkom
Gauteng_Germiston|Gauteng→Germiston
Gauteng_Johannesburg|Gauteng→Johannesburg
Gauteng_Pretoria|Gauteng→Pretoria
Gauteng_Randfontein|Gauteng→Randfontein
Gauteng_Vereeniging|Gauteng→Vereeniging
KwaZulu_Natal_Dundee|KwaZulu-Natal→Dundee
KwaZulu_Natal_Durban|KwaZulu-Natal→Durban
KwaZulu_Natal_Ixopo|KwaZulu-Natal→Ixopo
KwaZulu_Natal_KwaDukuza|KwaZulu-Natal→KwaDukuza
KwaZulu_Natal_Ladysmith|KwaZulu-Natal→Ladysmith
KwaZulu_Natal_Mkuze|KwaZulu-Natal→Mkuze
KwaZulu_Natal_Newcastle|KwaZulu-Natal→Newcastle
KwaZulu_Natal_Pietermaritzburg|KwaZulu-Natal→Pietermaritzburg
KwaZulu_Natal_Port_Shepstone|KwaZulu-Natal→Port Shepstone
KwaZulu_Natal_Richards_Bay|KwaZulu-Natal→Richards Bay
KwaZulu_Natal_Ulundi|KwaZulu-Natal→Ulundi
Limpopo_Giyani|Limpopo→Giyani
Limpopo_Groblersdal|Limpopo→Groblersdal
Limpopo_Modimolle|Limpopo→Modimolle
Limpopo_Polokwane|Limpopo→Polokwane
Limpopo_Thohoyandou|Limpopo→Thohoyandou
Mpumalanga_Middelburg|Mpumalanga→Middelburg
Mpumalanga_Nelspruit|Mpumalanga→Nelspruit
Mpumalanga_Secunda|Mpumalanga→Secunda
North_West_Klerksdorp|North West→Klerksdorp
North_West_Mafikeng|North West→Mafikeng
North_West_Rustenburg|North West→Rustenburg
North_West_Vryburg|North West→Vryburg
Northern_Cape_De_Aar|Northern Cape→De Aar
Northern_Cape_Kimberley|Northern Cape→Kimberley
Northern_Cape_Kuruman|Northern Cape→Kuruman
Northern_Cape_Springbok|Northern Cape→Springbok
Northern_Cape_Upington|Northern Cape→Upington
Western_Cape_Beaufort_West|Western Cape→Beaufort West
Western_Cape_Bredasdorp|Western Cape→Bredasdorp
Western_Cape_Cape_Town|Western Cape→Cape Town
Western_Cape_George|Western Cape→George
Western_Cape_Moorreesburg|Western Cape→Moorreesburg
Western_Cape_Worcester|Western Cape→Worcester
other|Not in South Africa (Please specify where: Country and City)',
        'select_list_options_fieldset' => array(
          'advanced_options' => array(
            'select_list_options_php' => '',
          ),
        ),
      ),
      'type' => 'cck_select_other',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'multifield-field_on_site_building-field_how_long_do_you_estimate_i'.
  $field_instances['multifield-field_on_site_building-field_how_long_do_you_estimate_i'] = array(
    'bundle' => 'field_on_site_building',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_integer',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'multifield',
    'field_name' => 'field_how_long_do_you_estimate_i',
    'label' => 'How long do you estimate it will take to install your piece on site',
    'required' => 1,
    'settings' => array(
      'max' => '',
      'min' => 1,
      'prefix' => '',
      'suffix' => 'Days',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'multifield-field_on_site_building-field_planning_to_start_building'.
  $field_instances['multifield-field_on_site_building-field_planning_to_start_building'] = array(
    'bundle' => 'field_on_site_building',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'long',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
          'show_remaining_days' => FALSE,
          'show_repeat_rule' => 'show',
        ),
        'type' => 'date_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'multifield',
    'field_name' => 'field_planning_to_start_building',
    'label' => 'When are you planning to start building on site',
    'required' => 1,
    'settings' => array(
      'default_value' => 'now',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'display_all_day' => 0,
        'increment' => 15,
        'input_format' => 'Y-m-d H:i:s',
        'input_format_custom' => '',
        'label_position' => 'above',
        'no_fieldset' => 0,
        'repeat_collapsed' => 0,
        'text_parts' => array(),
        'year_range' => '-0:+1',
      ),
      'type' => 'date_popup',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'multifield-field_person_lighting-field_email_address'.
  $field_instances['multifield-field_person_lighting-field_email_address'] = array(
    'bundle' => 'field_person_lighting',
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
  // 'multifield-field_person_lighting-field_first_name'.
  $field_instances['multifield-field_person_lighting-field_first_name'] = array(
    'bundle' => 'field_person_lighting',
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
      'weight' => 0,
    ),
  );

  // Exported field_instance:
  // 'multifield-field_person_lighting-field_last_name'.
  $field_instances['multifield-field_person_lighting-field_last_name'] = array(
    'bundle' => 'field_person_lighting',
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
  // 'multifield-field_person_lighting-field_phone_number'.
  $field_instances['multifield-field_person_lighting-field_phone_number'] = array(
    'bundle' => 'field_person_lighting',
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
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'telephone',
      'settings' => array(
        'placeholder' => '',
      ),
      'type' => 'telephone_default',
      'weight' => 5,
    ),
  );

  // Exported field_instance:
  // 'multifield-field_project_manager-field_email_address'.
  $field_instances['multifield-field_project_manager-field_email_address'] = array(
    'bundle' => 'field_project_manager',
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
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'email',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'email_textfield',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'multifield-field_project_manager-field_first_name'.
  $field_instances['multifield-field_project_manager-field_first_name'] = array(
    'bundle' => 'field_project_manager',
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
      'weight' => 0,
    ),
  );

  // Exported field_instance:
  // 'multifield-field_project_manager-field_last_name'.
  $field_instances['multifield-field_project_manager-field_last_name'] = array(
    'bundle' => 'field_project_manager',
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
  // 'multifield-field_project_manager-field_phone_number'.
  $field_instances['multifield-field_project_manager-field_phone_number'] = array(
    'bundle' => 'field_project_manager',
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
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'telephone',
      'settings' => array(
        'placeholder' => '',
      ),
      'type' => 'telephone_default',
      'weight' => 3,
    ),
  );

  // Exported field_instance:
  // 'multifield-field_sound_person-field_email_address'.
  $field_instances['multifield-field_sound_person-field_email_address'] = array(
    'bundle' => 'field_sound_person',
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

  // Exported field_instance: 'multifield-field_sound_person-field_first_name'.
  $field_instances['multifield-field_sound_person-field_first_name'] = array(
    'bundle' => 'field_sound_person',
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
    'required' => 0,
    'settings' => array(
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

  // Exported field_instance: 'multifield-field_sound_person-field_last_name'.
  $field_instances['multifield-field_sound_person-field_last_name'] = array(
    'bundle' => 'field_sound_person',
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

  // Exported field_instance:
  // 'multifield-field_sound_person-field_phone_number'.
  $field_instances['multifield-field_sound_person-field_phone_number'] = array(
    'bundle' => 'field_sound_person',
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
  // 'multifield-field_year_and_name_of_prev-field_previous_project'.
  $field_instances['multifield-field_year_and_name_of_prev-field_previous_project'] = array(
    'bundle' => 'field_year_and_name_of_prev',
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
    'field_name' => 'field_previous_project',
    'label' => 'Previous Project',
    'required' => 0,
    'settings' => array(
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
  // 'multifield-field_year_and_name_of_prev-field_year_and_event_name'.
  $field_instances['multifield-field_year_and_name_of_prev-field_year_and_event_name'] = array(
    'bundle' => 'field_year_and_name_of_prev',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'multifield',
    'field_name' => 'field_year_and_event_name',
    'label' => 'Year and Event Name',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'options',
      'settings' => array(
        'autocomplete_path' => 'taxonomy/autocomplete',
        'size' => 60,
      ),
      'type' => 'options_select',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'node-artwork_registration-field_additional_docs'.
  $field_instances['node-artwork_registration-field_additional_docs'] = array(
    'bundle' => 'artwork_registration',
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
    'label' => 'Got additional documentation or PDF\'s, please add them',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'file_directory' => '',
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
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'node-artwork_registration-field_anything_else'.
  $field_instances['node-artwork_registration-field_anything_else'] = array(
    'bundle' => 'artwork_registration',
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
    'label' => 'Anything Else',
    'required' => 1,
    'settings' => array(
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
    'label' => 'Are you applying for a Creative Grant from AfrikaBurn',
    'required' => 1,
    'settings' => array(
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
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'It’s your responsibility to remove your creation from the AfrikaBurn location once the event is over, and to ensure that no trace of it remains in Tankwa Town afterward. Nothing. Nada. Zilch. Zip. Zero. Fokol. <br>
If you are burning your artwork, it\'s also your responsibility to remove all burn debris left on your site, including ash and charcoal, nails, screws, wire and staples. ',
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
    'label' => 'Artwork Removal Site Clean Up',
    'required' => 1,
    'settings' => array(
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
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Burning requires particular construction materials and extra safety precautions, and it also releases a significant amount of carbon into the environment. <br>
We encourage artists to create pieces that can be enjoyed outside of Tankwa Town. ',
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
    'label' => 'What is your Burn Motivation?',
    'required' => 1,
    'settings' => array(
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
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Just because this is AfrikaBurn, it doesn\'t mean that you have to burn your piece. 
You might think that burning your artwork is an easy way to get rid of it (and don\'t have to transport it back to town) - It is not!
Consider carefully whether burning is important to the meaning of your piece. 
We love works that can be used outside of the event again. - Think Decompression, Streetopia, Maker Faire, ParkOff, etc.',
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
    'label' => 'Contact Person',
    'required' => 1,
    'settings' => array(
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
    'label' => 'Your Crew Members and their Roles',
    'required' => 1,
    'settings' => array(
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

  // Exported field_instance: 'node-artwork_registration-field_dimensions'.
  $field_instances['node-artwork_registration-field_dimensions'] = array(
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
    'field_name' => 'field_dimensions',
    'label' => 'Dimensions',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'multifield',
      'settings' => array(),
      'type' => 'multifield_default',
      'weight' => 6,
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
    'label' => 'You\'ll have to designate someone in your team specifically as the Pyro Person (This can be you).',
    'required' => 1,
    'settings' => array(
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
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Please list any projects you have worked on or generated in the default world.',
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
    'label' => 'Other Projects',
    'required' => 1,
    'settings' => array(
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
    'label' => 'If in South Africa Please select you Municpal District',
    'required' => 1,
    'settings' => array(
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
    'label' => 'Are you planning any sort of projection, 3D Mapping, Laser, etc',
    'required' => 1,
    'settings' => array(
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
    'deleted' => 0,
    'description' => 'If you know already exactly where you want your piece to be, please look at the map and select from the drop down list bellow',
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
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'markup',
      'settings' => array(),
      'type' => 'markup',
      'weight' => 11,
    ),
  );

  // Exported field_instance: 'node-artwork_registration-field_location_picker'.
  $field_instances['node-artwork_registration-field_location_picker'] = array(
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
    'label' => 'Pick Placement',
    'required' => 1,
    'settings' => array(
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
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Please list all materials to be used in this project. <br>
We encourage the use of waste, salvage, recyclable, environmentally friendly and reusable materials. <br>
If you are considering to burn your artwork please read up about this on our website, and check what materials are acceptable to use.',
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
      'weight' => 7,
    ),
  );

  // Exported field_instance:
  // 'node-artwork_registration-field_moop_representative'.
  $field_instances['node-artwork_registration-field_moop_representative'] = array(
    'bundle' => 'artwork_registration',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Your MOOP Representative will be requested to read and accept the MOOP Manifesto, attend to workshops and briefs, fill in the MOOP form, and supply all details requested by our MOOP Squad.<br>
This person plays an active role in the \'education\' of the whole team and will be the difference between a Red and a Green MOOP Score.<br>
Remember that the MOOP Score of your project this year will affect every member of the team (eg.: future funding and direct distribution of tickets). Choose wisely!',
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
    'label' => 'Name of the Collective and/or Creator',
    'required' => 1,
    'settings' => array(
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
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Who are you as a project?<br>
Are you looking for any one with specific skills?<br>
Any commitments? ',
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
    'label' => 'Contact Email',
    'required' => 1,
    'settings' => array(
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
    'label' => 'Offsite Building',
    'required' => 1,
    'settings' => array(
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
    'label' => 'On Site Building',
    'required' => 1,
    'settings' => array(
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

  // Exported field_instance: 'node-artwork_registration-field_performer_types'.
  $field_instances['node-artwork_registration-field_performer_types'] = array(
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
        'weight' => 63,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_performer_types',
    'label' => 'Performer Types',
    'required' => FALSE,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 13,
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
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'This is not a required field but do tell us if there is a story behind your artwork that might make us understand it better. ',
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
    'label' => 'Philosophical Statement',
    'required' => 0,
    'settings' => array(
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
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Where would you ideally like to install your Artwork?
Are there any considerations we need to take into account when placing your artwork? Did you have a specific spot in mind when designing it? For example, it might be important for you to have it near your/a theme camp, “out far”, near the hubbub of Off-Centre Camp or a quiet reflective space, a particularly flat surface etc. 
Please note that we’ll try our best to accommodate your needs, but cannot guarantee any specific spots. 
Also, your intention to burn your artwork or not, your sound specifications, and your planned activities at your artwork, play an important role in its placement. ',
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
  // 'node-artwork_registration-field_planned_activities'.
  $field_instances['node-artwork_registration-field_planned_activities'] = array(
    'bundle' => 'artwork_registration',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Are you planning a performance or music to accompany your piece, and are there other participants involved? <br>
Give us an idea of the elements that are part of your artistic vision. <br>
If your burning it, do you have any pre-, during, or post-burn plans? ',
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
    'label' => 'Planned Activities',
    'required' => 1,
    'settings' => array(
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
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Even if you are not using light as an aesthetic component of your piece, you need to make it visible at night, including guy ropes.',
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
    'label' => 'Please describe your lighting plan',
    'required' => 1,
    'settings' => array(
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
      'weight' => 19,
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
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 21,
    ),
  );

  // Exported field_instance: 'node-artwork_registration-field_sound_person'.
  $field_instances['node-artwork_registration-field_sound_person'] = array(
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
    'label' => 'Who is the Sound Person in your team? (This can be you.)',
    'required' => 1,
    'settings' => array(
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
  // 'node-artwork_registration-field_stage_performers_dscr'.
  $field_instances['node-artwork_registration-field_stage_performers_dscr'] = array(
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
  // 'node-artwork_registration-field_structural_safety'.
  $field_instances['node-artwork_registration-field_structural_safety'] = array(
    'bundle' => 'artwork_registration',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Your artwork needs to withstand extreme weather, including high winds. Make sure it\'s securely anchored, that it’s not going to fall over, and nothing will fall off. 
Describe how you intend to anchor it. What will you use to mark guy ropes and cover rebar?
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
    'label' => 'Structural Safety',
    'required' => 1,
    'settings' => array(
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
  // 'node-artwork_registration-field_team_structural_rep'.
  $field_instances['node-artwork_registration-field_team_structural_rep'] = array(
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
    'label' => 'Do you have in your team someone specifically responsible for assuring that the piece is structurally safe',
    'required' => 1,
    'settings' => array(
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
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'You don\'t have to have this, but you project will benefit from it. Think of fundraising campaigns, support from the community, collaboration with other creative teams, etc.',
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
    'label' => 'Where in the world are you, as a Collective, based?',
    'required' => 1,
    'settings' => array(
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
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'What do you and your team do in the default world? Please be brief, we\'re not after your CV. ',
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
    'label' => 'Who are you? Brief Bio.',
    'required' => 1,
    'settings' => array(
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
  t('Any other narrative or piece of information that that you feel we should know about you and/or your project? ');
  t('Anything Else');
  t('Approx Weight');
  t('Are you applying for a Creative Grant from AfrikaBurn');
  t('Are you interested in collaborating with other artists and/or working with volunteers?');
  t('Are you planning a performance or music to accompany your piece, and are there other participants involved? <br>
Give us an idea of the elements that are part of your artistic vision. <br>
If your burning it, do you have any pre-, during, or post-burn plans? ');
  t('Are you planning any sort of projection, 3D Mapping, Laser, etc');
  t('Are you planning to burn your artwork and/or does it have a fire component?');
  t('Artwork Removal Site Clean Up');
  t('Briefly describe your artwork. What is it? What\'s it made of? Is it interactive? Does it have moving parts? Does it have wheels? And is there a story behind it? 
(We\'re not looking for a two page essay, just enough for us to understand what the artwork is) ');
  t('Burning requires particular construction materials and extra safety precautions, and it also releases a significant amount of carbon into the environment. <br>
We encourage artists to create pieces that can be enjoyed outside of Tankwa Town. ');
  t('Contact Email');
  t('Contact Person');
  t('Creative Lead');
  t('Depending on your answer we might have more questions for you...');
  t('Depth');
  t('Describe your project');
  t('Dimensions');
  t('Do you have a stage or performance area where you would welcome performers to?');
  t('Do you have in your team someone specifically responsible for assuring that the piece is structurally safe');
  t('Does your artwork have a sound component?');
  t('Email Address');
  t('Even if you are not using light as an aesthetic component of your piece, you need to make it visible at night, including guy ropes.');
  t('First Name');
  t('Fundraiser');
  t('Got additional documentation or PDF\'s, please add them');
  t('Height');
  t('How are you planning to transport your artwork to Tankwa Town?');
  t('How is it related?');
  t('How long do you estimate it will take to install your piece on site');
  t('How long do you estimate that it will take');
  t('How many people do you have to help you clean up your site after removal or burn of the artwork');
  t('If in South Africa Please select you Municpal District');
  t('If yes, please describe the nature and size of your sound');
  t('If you know already exactly where you want your piece to be, please look at the map and select from the drop down list bellow');
  t('Image types allowed: png, jpg, jpeg 
Max Image size is 2 MB');
  t('In terms of size, how would you classify your project?');
  t('Is it round? A string of balloons? A tree? etc.');
  t('Is your piece associated with any other projects at AfrikaBurn?');
  t('It’s your responsibility to remove your creation from the AfrikaBurn location once the event is over, and to ensure that no trace of it remains in Tankwa Town afterward. Nothing. Nada. Zilch. Zip. Zero. Fokol. <br>
If you are burning your artwork, it\'s also your responsibility to remove all burn debris left on your site, including ash and charcoal, nails, screws, wire and staples. ');
  t('Just because this is AfrikaBurn, it doesn\'t mean that you have to burn your piece. 
You might think that burning your artwork is an easy way to get rid of it (and don\'t have to transport it back to town) - It is not!
Consider carefully whether burning is important to the meaning of your piece. 
We love works that can be used outside of the event again. - Think Decompression, Streetopia, Maker Faire, ParkOff, etc.');
  t('Last Name');
  t('MOOP Representative');
  t('Materials');
  t('Name of the Collective and/or Creator');
  t('Note, this will be made public for new members to contact.');
  t('Offsite Building');
  t('On Site Building');
  t('Other Projects');
  t('Other Relevant Phisical Attributes');
  t('Performer Types');
  t('Philosophical Statement');
  t('Phone Number');
  t('Pick Placement');
  t('Placement');
  t('Placement Map');
  t('Planned Activities');
  t('Please describe your light output devices and power sources');
  t('Please describe your lighting plan');
  t('Please give us details.');
  t('Please list all materials to be used in this project. <br>
We encourage the use of waste, salvage, recyclable, environmentally friendly and reusable materials. <br>
If you are considering to burn your artwork please read up about this on our website, and check what materials are acceptable to use.');
  t('Please list any projects you have worked on or generated in the default world.');
  t('Please select the level of your Sound');
  t('Please submit concept images');
  t('Previous Project');
  t('Project Manager');
  t('Provide a description of the space and performers you are looking for');
  t('Role');
  t('Sometimes there\'s human resources missing in a team and/or artistic elements that your team cannot bring to the project.<br>
This isn\'t reason to kill your project, it is an opportunity to promote Participation and Gifting and exercise Communal Effort!<br>
If you would like to collaborate with other participants and volunteers, please write up a brief description of your project and specify your needs and/or how you\'re envisioning collaboration.<br>
This information will be made public on our website to allow volunteers to choose the project(s) that they feel they can contribute to.<br>');
  t('Structural Safety');
  t('Tell them who you are and what you are looking for');
  t('This is not a required field but do tell us if there is a story behind your artwork that might make us understand it better. ');
  t('Transport');
  t('Website');
  t('What do you and your team do in the default world? Please be brief, we\'re not after your CV. ');
  t('What is your Burn Motivation?');
  t('What\'s the name of the projects that you are associated with?');
  t('When are you planning to start building offsite');
  t('When are you planning to start building on site');
  t('Where are you going to build your artwork');
  t('Where in the world are you, as a Collective, based?');
  t('Where would you ideally like to install your Artwork?
Are there any considerations we need to take into account when placing your artwork? Did you have a specific spot in mind when designing it? For example, it might be important for you to have it near your/a theme camp, “out far”, near the hubbub of Off-Centre Camp or a quiet reflective space, a particularly flat surface etc. 
Please note that we’ll try our best to accommodate your needs, but cannot guarantee any specific spots. 
Also, your intention to burn your artwork or not, your sound specifications, and your planned activities at your artwork, play an important role in its placement. ');
  t('Who are you as a project?<br>
Are you looking for any one with specific skills?<br>
Any commitments? ');
  t('Who are you? Brief Bio.');
  t('Who is the Sound Person in your team? (This can be you.)');
  t('Who is the person in your team in charge of lighting?');
  t('Width');
  t('Will your artwork have any lighting component?');
  t('Year and Event Name');
  t('Year and name of previous projects');
  t('You don\'t have to have this, but you project will benefit from it. Think of fundraising campaigns, support from the community, collaboration with other creative teams, etc.');
  t('You\'ll have to designate someone in your team specifically as the Pyro Person (This can be you).');
  t('Your Crew Members and their Roles');
  t('Your MOOP Representative will be requested to read and accept the MOOP Manifesto, attend to workshops and briefs, fill in the MOOP form, and supply all details requested by our MOOP Squad.<br>
This person plays an active role in the \'education\' of the whole team and will be the difference between a Red and a Green MOOP Score.<br>
Remember that the MOOP Score of your project this year will affect every member of the team (eg.: future funding and direct distribution of tickets). Choose wisely!');
  t('Your artwork needs to withstand extreme weather, including high winds. Make sure it\'s securely anchored, that it’s not going to fall over, and nothing will fall off. 
Describe how you intend to anchor it. What will you use to mark guy ropes and cover rebar?
For large-scale installations, we\'ll need to have your piece signed off by an engineer. ');

  return $field_instances;
}
