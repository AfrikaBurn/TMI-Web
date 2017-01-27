<?php
/**
 * @file
 * feature_core_fields.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function feature_core_fields_field_default_field_instances() {
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
      'custom_add_another' => '',
      'custom_remove' => '',
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
      'custom_add_another' => '',
      'custom_remove' => '',
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
      'custom_add_another' => '',
      'custom_remove' => '',
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
        'weight' => 0,
      ),
    ),
    'entity_type' => 'multifield',
    'field_name' => 'field_theme_camp',
    'label' => 'What is the name(s) of that/those project(s)?',
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
  // 'multifield-field_contact_person-field_email_address'.
  $field_instances['multifield-field_contact_person-field_email_address'] = array(
    'bundle' => 'field_contact_person',
    'custom_add_another' => '',
    'custom_remove' => '',
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
      'multifield_view' => array(
        'label' => 'above',
        'module' => 'email',
        'settings' => array(),
        'type' => 'email_default',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'multifield',
    'field_name' => 'field_email_address',
    'label' => ' Email Address',
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
  // 'multifield-field_contact_person-field_first_name'.
  $field_instances['multifield-field_contact_person-field_first_name'] = array(
    'bundle' => 'field_contact_person',
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
        'weight' => 0,
      ),
      'multifield_view' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'multifield',
    'field_name' => 'field_first_name',
    'label' => ' First Name',
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

  // Exported field_instance: 'multifield-field_contact_person-field_last_name'.
  $field_instances['multifield-field_contact_person-field_last_name'] = array(
    'bundle' => 'field_contact_person',
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
      'multifield_view' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'multifield',
    'field_name' => 'field_last_name',
    'label' => ' Last Name',
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
  // 'multifield-field_contact_person-field_phone_number'.
  $field_instances['multifield-field_contact_person-field_phone_number'] = array(
    'bundle' => 'field_contact_person',
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
        'type' => 'text_plain',
        'weight' => 3,
      ),
      'multifield_view' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_plain',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'multifield',
    'field_name' => 'field_phone_number',
    'label' => ' Phone Number',
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
  // 'multifield-field_crew_members-field_email_address'.
  $field_instances['multifield-field_crew_members-field_email_address'] = array(
    'bundle' => 'field_crew_members',
    'custom_add_another' => '',
    'custom_remove' => '',
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
    'label' => 'Email',
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
  // 'multifield-field_crew_members-field_phone_number'.
  $field_instances['multifield-field_crew_members-field_phone_number'] = array(
    'bundle' => 'field_crew_members',
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
        'type' => 'text_plain',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'multifield',
    'field_name' => 'field_phone_number',
    'label' => 'Phone',
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
      'weight' => 0,
    ),
  );

  // Exported field_instance:
  // 'multifield-field_dimentions_m2-field_approx_weight'.
  $field_instances['multifield-field_dimentions_m2-field_approx_weight'] = array(
    'bundle' => 'field_dimentions_m2',
    'custom_add_another' => '',
    'custom_remove' => '',
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
        'weight' => 3,
      ),
    ),
    'entity_type' => 'multifield',
    'field_name' => 'field_approx_weight',
    'label' => 'Approx Weight',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
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
  // 'multifield-field_dimentions_m2-field_foot_print_area'.
  $field_instances['multifield-field_dimentions_m2-field_foot_print_area'] = array(
    'bundle' => 'field_dimentions_m2',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'in metres square',
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
    'field_name' => 'field_foot_print_area',
    'label' => 'Foot Print Area',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
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

  // Exported field_instance: 'multifield-field_dimentions_m2-field_height'.
  $field_instances['multifield-field_dimentions_m2-field_height'] = array(
    'bundle' => 'field_dimentions_m2',
    'custom_add_another' => '',
    'custom_remove' => '',
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
    'field_name' => 'field_height',
    'label' => 'Height',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
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
  // 'multifield-field_dimentions_m2-field_other_relevant_phisical_at'.
  $field_instances['multifield-field_dimentions_m2-field_other_relevant_phisical_at'] = array(
    'bundle' => 'field_dimentions_m2',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Is it round? A string of balloons? A tree? etc.',
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
    'field_name' => 'field_other_relevant_phisical_at',
    'label' => 'Other Relevant Phisical Attributes',
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
      'weight' => 3,
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
  // 'multifield-field_offsite_building-field_munciple_district'.
  $field_instances['multifield-field_offsite_building-field_munciple_district'] = array(
    'bundle' => 'field_offsite_building',
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
        'weight' => 2,
      ),
    ),
    'entity_type' => 'multifield',
    'field_name' => 'field_munciple_district',
    'label' => 'Muncipal District',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'select_or_other',
      'settings' => array(
        'available_options' => '',
        'other' => 'Other',
        'other_size' => 60,
        'other_title' => '',
        'other_unknown_defaults' => 'other',
        'sort_options' => 0,
      ),
      'type' => 'select_or_other',
      'weight' => 0,
    ),
  );

  // Exported field_instance:
  // 'multifield-field_offsite_building-field_when_are_you_planning_to_s'.
  $field_instances['multifield-field_offsite_building-field_when_are_you_planning_to_s'] = array(
    'bundle' => 'field_offsite_building',
    'custom_add_another' => '',
    'custom_remove' => '',
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
    'label' => 'When are you planning to start building offsite?',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'default_value' => 'strtotime',
      'default_value2' => 'same',
      'default_value_code' => '24 April 2017',
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
  // 'multifield-field_on_site_building-field_how_long_do_you_estimate_i'.
  $field_instances['multifield-field_on_site_building-field_how_long_do_you_estimate_i'] = array(
    'bundle' => 'field_on_site_building',
    'custom_add_another' => '',
    'custom_remove' => '',
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
    'label' => 'How long do you estimate it will take to install your piece on site?',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
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
    'custom_add_another' => '',
    'custom_remove' => '',
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
    'label' => 'When are you planning to start building on site?',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'default_value' => 'strtotime',
      'default_value2' => 'same',
      'default_value_code' => '24 April 2017',
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

  // Exported field_instance: 'multifield-field_sound_person-field_first_name'.
  $field_instances['multifield-field_sound_person-field_first_name'] = array(
    'bundle' => 'field_sound_person',
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

  // Translatables
  // Included for use with string extractors like potx.
  t(' Email Address');
  t(' First Name');
  t(' Last Name');
  t(' Phone Number');
  t('Approx Weight');
  t('Email');
  t('Email Address');
  t('First Name');
  t('Foot Print Area');
  t('Height');
  t('How is it related?');
  t('How long do you estimate it will take to install your piece on site?');
  t('How long do you estimate that it will take');
  t('How many people do you have to help you clean up your site after removal or burn of the artwork');
  t('Is it round? A string of balloons? A tree? etc.');
  t('Last Name');
  t('Muncipal District');
  t('Other Relevant Phisical Attributes');
  t('Phone');
  t('Phone Number');
  t('Role');
  t('What is the name(s) of that/those project(s)?');
  t('When are you planning to start building offsite?');
  t('When are you planning to start building on site?');
  t('in metres square');

  return $field_instances;
}
