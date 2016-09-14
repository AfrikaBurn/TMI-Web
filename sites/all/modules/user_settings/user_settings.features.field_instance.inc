<?php
/**
 * @file
 * user_settings.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function user_settings_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'multifield-field_bb_minors_details-field_bb_gardien_yn'.
  $field_instances['multifield-field_bb_minors_details-field_bb_gardien_yn'] = array(
    'bundle' => 'field_bb_minors_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'multifield',
    'field_name' => 'field_bb_gardien_yn',
    'label' => 'Are you their Parent or Legal Gardian',
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
      'weight' => 4,
    ),
  );

  // Exported field_instance:
  // 'multifield-field_bb_minors_details-field_bb_guardian_letter'.
  $field_instances['multifield-field_bb_minors_details-field_bb_guardian_letter'] = array(
    'bundle' => 'field_bb_minors_details',
    'deleted' => 0,
    'description' => 'Only required when you wish to purchase their ticket.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 6,
      ),
    ),
    'entity_type' => 'multifield',
    'field_name' => 'field_bb_guardian_letter',
    'label' => 'Signed Copy of Guardian Authorization Letter',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'custom_add_another' => '',
      'custom_remove' => '',
      'default_image' => 0,
      'file_directory' => 'guardian',
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
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 6,
    ),
  );

  // Exported field_instance:
  // 'multifield-field_bb_minors_details-field_bb_parents_id'.
  $field_instances['multifield-field_bb_minors_details-field_bb_parents_id'] = array(
    'bundle' => 'field_bb_minors_details',
    'deleted' => 0,
    'description' => 'Gardian\'s ID required to be able to purchase a ticket',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'multifield',
    'field_name' => 'field_bb_parents_id',
    'label' => 'Copy of Parent\'s ID',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'custom_add_another' => '',
      'custom_remove' => '',
      'default_image' => 0,
      'file_directory' => 'guardian',
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
      'weight' => 5,
    ),
  );

  // Exported field_instance:
  // 'multifield-field_bb_minors_details-field_date_of_birth'.
  $field_instances['multifield-field_bb_minors_details-field_date_of_birth'] = array(
    'bundle' => 'field_bb_minors_details',
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
        'weight' => 2,
      ),
    ),
    'entity_type' => 'multifield',
    'field_name' => 'field_date_of_birth',
    'label' => 'Date of Birth',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
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
        'year_range' => '-3:+3',
      ),
      'type' => 'date_popup',
      'weight' => 3,
    ),
  );

  // Exported field_instance:
  // 'multifield-field_bb_minors_details-field_email_address'.
  $field_instances['multifield-field_bb_minors_details-field_email_address'] = array(
    'bundle' => 'field_bb_minors_details',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Required if they will be over the age of thirteen on the first day of the event.',
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
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'multifield-field_bb_minors_details-field_first_name'.
  $field_instances['multifield-field_bb_minors_details-field_first_name'] = array(
    'bundle' => 'field_bb_minors_details',
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
  // 'multifield-field_bb_minors_details-field_last_name'.
  $field_instances['multifield-field_bb_minors_details-field_last_name'] = array(
    'bundle' => 'field_bb_minors_details',
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
  // 'multifield-field_previous_envolvement-field_previous_participation'.
  $field_instances['multifield-field_previous_envolvement-field_previous_participation'] = array(
    'bundle' => 'field_previous_envolvement',
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
    'field_name' => 'field_previous_participation',
    'label' => 'How did you participate? Did you volunteer, and if so, how?',
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
      'weight' => 3,
    ),
  );

  // Exported field_instance:
  // 'multifield-field_previous_envolvement-field_year_and_event_name'.
  $field_instances['multifield-field_previous_envolvement-field_year_and_event_name'] = array(
    'bundle' => 'field_previous_envolvement',
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
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'user-user-field_bb_ab_history'.
  $field_instances['user-user-field_bb_ab_history'] = array(
    'bundle' => 'user',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '(see <a href="http://afrikaburn.com/binnekringblog/roots-fruits-and-offshoots" target="_blank">  this page </a> for more info on the historical roots of AfrikaBurn)',
    'display' => array(
      'anonymous_user' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
      'full' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 23,
      ),
      'user_admin_edit' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
      'user_admin_view' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
      'user_edit_view' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
      'user_view' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_bb_ab_history',
    'label' => 'Did you know that AfrikaBurn\'s history is rooted in:',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => 1,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'user-user-field_bb_agree'.
  $field_instances['user-user-field_bb_agree'] = array(
    'bundle' => 'user',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'anonymous_user' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 35,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 35,
      ),
      'full' => array(
        'label' => 'inline',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 4,
      ),
      'user_admin_edit' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 35,
      ),
      'user_admin_view' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 35,
      ),
      'user_edit_view' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 35,
      ),
      'user_view' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 35,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_bb_agree',
    'label' => 'Agree',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => 1,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 0,
      ),
      'type' => 'options_onoff',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'user-user-field_bb_aint_no_party'.
  $field_instances['user-user-field_bb_aint_no_party'] = array(
    'bundle' => 'user',
    'custom_add_another' => '',
    'custom_remove' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'anonymous_user' => array(
        'label' => 'above',
        'module' => 'markup',
        'settings' => array(),
        'type' => 'markup_default',
        'weight' => 13,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'markup',
        'settings' => array(),
        'type' => 'markup_default',
        'weight' => 13,
      ),
      'full' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 29,
      ),
      'user_admin_edit' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 13,
      ),
      'user_admin_view' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 13,
      ),
      'user_edit_view' => array(
        'label' => 'above',
        'module' => 'markup',
        'settings' => array(),
        'type' => 'markup_default',
        'weight' => 13,
      ),
      'user_view' => array(
        'label' => 'above',
        'module' => 'markup',
        'settings' => array(),
        'type' => 'markup_default',
        'weight' => 13,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_bb_aint_no_party',
    'label' => 'ain\'t no party',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'markup',
      'settings' => array(),
      'type' => 'markup',
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'user-user-field_bb_booze'.
  $field_instances['user-user-field_bb_booze'] = array(
    'bundle' => 'user',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'anonymous_user' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 32,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 32,
      ),
      'full' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 49,
      ),
      'user_admin_edit' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 32,
      ),
      'user_admin_view' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 32,
      ),
      'user_edit_view' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 32,
      ),
      'user_view' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 32,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_bb_booze',
    'label' => '(this is to identify who’s OK (and not OK)  to gift your drink to)',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => 1,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 31,
    ),
  );

  // Exported field_instance: 'user-user-field_bb_booze1'.
  $field_instances['user-user-field_bb_booze1'] = array(
    'bundle' => 'user',
    'custom_add_another' => '',
    'custom_remove' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'anonymous_user' => array(
        'label' => 'above',
        'module' => 'markup',
        'settings' => array(),
        'type' => 'markup_default',
        'weight' => 33,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'markup',
        'settings' => array(),
        'type' => 'markup_default',
        'weight' => 33,
      ),
      'full' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 50,
      ),
      'user_admin_edit' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 33,
      ),
      'user_admin_view' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 33,
      ),
      'user_edit_view' => array(
        'label' => 'above',
        'module' => 'markup',
        'settings' => array(),
        'type' => 'markup_default',
        'weight' => 33,
      ),
      'user_view' => array(
        'label' => 'above',
        'module' => 'markup',
        'settings' => array(),
        'type' => 'markup_default',
        'weight' => 33,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_bb_booze1',
    'label' => 'bb_booze',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'markup',
      'settings' => array(),
      'type' => 'markup',
      'weight' => 30,
    ),
  );

  // Exported field_instance: 'user-user-field_bb_complete'.
  $field_instances['user-user-field_bb_complete'] = array(
    'bundle' => 'user',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '(Tip: you can dig for that answer <a href="http://www.afrikaburn.com/about/guiding-principles" target="_blank">here</a>)',
    'display' => array(
      'anonymous_user' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 12,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 12,
      ),
      'full' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 28,
      ),
      'user_admin_edit' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 12,
      ),
      'user_admin_view' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 12,
      ),
      'user_edit_view' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 12,
      ),
      'user_view' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 12,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_bb_complete',
    'label' => 'Complete the following sentence: “Gifting does not contemplate...',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'text_processing' => 0,
      'user_register_form' => 1,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'user-user-field_bb_dressed'.
  $field_instances['user-user-field_bb_dressed'] = array(
    'bundle' => 'user',
    'custom_add_another' => '',
    'custom_remove' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'anonymous_user' => array(
        'label' => 'above',
        'module' => 'markup',
        'settings' => array(),
        'type' => 'markup_default',
        'weight' => 25,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'markup',
        'settings' => array(),
        'type' => 'markup_default',
        'weight' => 25,
      ),
      'full' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 41,
      ),
      'user_admin_edit' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 25,
      ),
      'user_admin_view' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 25,
      ),
      'user_edit_view' => array(
        'label' => 'above',
        'module' => 'markup',
        'settings' => array(),
        'type' => 'markup_default',
        'weight' => 25,
      ),
      'user_view' => array(
        'label' => 'above',
        'module' => 'markup',
        'settings' => array(),
        'type' => 'markup_default',
        'weight' => 25,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_bb_dressed',
    'label' => 'dressed',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'markup',
      'settings' => array(),
      'type' => 'markup',
      'weight' => 21,
    ),
  );

  // Exported field_instance: 'user-user-field_bb_dressed1'.
  $field_instances['user-user-field_bb_dressed1'] = array(
    'bundle' => 'user',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'anonymous_user' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 26,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 26,
      ),
      'full' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 42,
      ),
      'user_admin_edit' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 26,
      ),
      'user_admin_view' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 26,
      ),
      'user_edit_view' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 26,
      ),
      'user_view' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 26,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_bb_dressed1',
    'label' => 'unicorns, superheroes, fairytale characters (or even undressed)?',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => 1,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 22,
    ),
  );

  // Exported field_instance: 'user-user-field_bb_drone'.
  $field_instances['user-user-field_bb_drone'] = array(
    'bundle' => 'user',
    'custom_add_another' => '',
    'custom_remove' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'anonymous_user' => array(
        'label' => 'above',
        'module' => 'markup',
        'settings' => array(),
        'type' => 'markup_default',
        'weight' => 27,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'markup',
        'settings' => array(),
        'type' => 'markup_default',
        'weight' => 27,
      ),
      'full' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 43,
      ),
      'user_admin_edit' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 27,
      ),
      'user_admin_view' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 27,
      ),
      'user_edit_view' => array(
        'label' => 'above',
        'module' => 'markup',
        'settings' => array(),
        'type' => 'markup_default',
        'weight' => 27,
      ),
      'user_view' => array(
        'label' => 'above',
        'module' => 'markup',
        'settings' => array(),
        'type' => 'markup_default',
        'weight' => 27,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_bb_drone',
    'label' => 'drone',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'markup',
      'settings' => array(),
      'type' => 'markup',
      'weight' => 23,
    ),
  );

  // Exported field_instance: 'user-user-field_bb_drone1'.
  $field_instances['user-user-field_bb_drone1'] = array(
    'bundle' => 'user',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'anonymous_user' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 28,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 28,
      ),
      'full' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 44,
      ),
      'user_admin_edit' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 28,
      ),
      'user_admin_view' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 28,
      ),
      'user_edit_view' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 28,
      ),
      'user_view' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 28,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_bb_drone1',
    'label' => '(this is so that nobody is injured by flying chunks of metal)',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => 1,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 24,
    ),
  );

  // Exported field_instance: 'user-user-field_bb_firstburn'.
  $field_instances['user-user-field_bb_firstburn'] = array(
    'bundle' => 'user',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'anonymous_user' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 8,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 8,
      ),
      'full' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 24,
      ),
      'user_admin_edit' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 8,
      ),
      'user_admin_view' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 8,
      ),
      'user_edit_view' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 8,
      ),
      'user_view' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 8,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_bb_firstburn',
    'label' => 'Will this be your first burn?',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => 1,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'user-user-field_bb_haul'.
  $field_instances['user-user-field_bb_haul'] = array(
    'bundle' => 'user',
    'custom_add_another' => '',
    'custom_remove' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'anonymous_user' => array(
        'label' => 'above',
        'module' => 'markup',
        'settings' => array(),
        'type' => 'markup_default',
        'weight' => 16,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'markup',
        'settings' => array(),
        'type' => 'markup_default',
        'weight' => 16,
      ),
      'full' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 32,
      ),
      'user_admin_edit' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 16,
      ),
      'user_admin_view' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 16,
      ),
      'user_edit_view' => array(
        'label' => 'above',
        'module' => 'markup',
        'settings' => array(),
        'type' => 'markup_default',
        'weight' => 16,
      ),
      'user_view' => array(
        'label' => 'above',
        'module' => 'markup',
        'settings' => array(),
        'type' => 'markup_default',
        'weight' => 16,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_bb_haul',
    'label' => 'haul',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'markup',
      'settings' => array(),
      'type' => 'markup',
      'weight' => 12,
    ),
  );

  // Exported field_instance: 'user-user-field_bb_haul2'.
  $field_instances['user-user-field_bb_haul2'] = array(
    'bundle' => 'user',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'anonymous_user' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 17,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 17,
      ),
      'full' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 34,
      ),
      'user_admin_edit' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 17,
      ),
      'user_admin_view' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 17,
      ),
      'user_edit_view' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 17,
      ),
      'user_view' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 17,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_bb_haul2',
    'label' => 'Where you’re expected to rely on your own abilities to survive for the entire time?',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => 1,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 13,
    ),
  );

  // Exported field_instance: 'user-user-field_bb_ice'.
  $field_instances['user-user-field_bb_ice'] = array(
    'bundle' => 'user',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'anonymous_user' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 21,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 21,
      ),
      'full' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 37,
      ),
      'user_admin_edit' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 21,
      ),
      'user_admin_view' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 21,
      ),
      'user_edit_view' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 21,
      ),
      'user_view' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 21,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_bb_ice',
    'label' => 'Are you aware that there’s nothing sold on site at all except ice?',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => 1,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 17,
    ),
  );

  // Exported field_instance: 'user-user-field_bb_jol'.
  $field_instances['user-user-field_bb_jol'] = array(
    'bundle' => 'user',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'anonymous_user' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 14,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 14,
      ),
      'full' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 30,
      ),
      'user_admin_edit' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 14,
      ),
      'user_admin_view' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 14,
      ),
      'user_edit_view' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 14,
      ),
      'user_view' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 14,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_bb_jol',
    'label' => 'So...are you expecting a jol?',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => 1,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'user-user-field_bb_leave_no_trace'.
  $field_instances['user-user-field_bb_leave_no_trace'] = array(
    'bundle' => 'user',
    'custom_add_another' => '',
    'custom_remove' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'anonymous_user' => array(
        'label' => 'above',
        'module' => 'markup',
        'settings' => array(),
        'type' => 'markup_default',
        'weight' => 23,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'markup',
        'settings' => array(),
        'type' => 'markup_default',
        'weight' => 23,
      ),
      'full' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 39,
      ),
      'user_admin_edit' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 23,
      ),
      'user_admin_view' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 23,
      ),
      'user_edit_view' => array(
        'label' => 'above',
        'module' => 'markup',
        'settings' => array(),
        'type' => 'markup_default',
        'weight' => 23,
      ),
      'user_view' => array(
        'label' => 'above',
        'module' => 'markup',
        'settings' => array(),
        'type' => 'markup_default',
        'weight' => 23,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_bb_leave_no_trace',
    'label' => 'Leave No Trace',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'markup',
      'settings' => array(),
      'type' => 'markup',
      'weight' => 19,
    ),
  );

  // Exported field_instance: 'user-user-field_bb_madly_creative'.
  $field_instances['user-user-field_bb_madly_creative'] = array(
    'bundle' => 'user',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '(it\'s OK to just describe it briefly - save the long version for your Art, Mutant Vehicle, Theme Camp or Performance registration)',
    'display' => array(
      'anonymous_user' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 20,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 20,
      ),
      'full' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 36,
      ),
      'user_admin_edit' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 20,
      ),
      'user_admin_view' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 20,
      ),
      'user_edit_view' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 20,
      ),
      'user_view' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 20,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_bb_madly_creative',
    'label' => 'Insert your madly creative project and / or gifting idea here:',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'text_processing' => 0,
      'user_register_form' => 1,
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

  // Exported field_instance: 'user-user-field_bb_minors_details'.
  $field_instances['user-user-field_bb_minors_details'] = array(
    'bundle' => 'user',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => array(
      0 => array(
        'field_first_name' => array(
          'und' => array(
            0 => array(
              'value' => '',
            ),
          ),
        ),
        'field_last_name' => array(
          'und' => array(
            0 => array(
              'value' => '',
            ),
          ),
        ),
        'field_date_of_birth' => array(
          'und' => array(
            0 => array(
              'value' => '2016-09-13T00:00:00',
              'show_todate' => TRUE,
              'timezone' => 'Africa/Johannesburg',
              'offset' => 7200,
              'offset2' => 7200,
              'value2' => '2016-09-13T00:00:00',
            ),
          ),
        ),
        'field_email_address' => array(
          'und' => array(
            0 => array(
              'email' => '',
            ),
          ),
        ),
        'field_bb_gardien_yn' => array(
          'und' => array(
            0 => array(
              'value' => NULL,
            ),
          ),
        ),
        'field_bb_parents_id' => array(
          'und' => array(
            0 => array(
              'UPLOAD_IDENTIFIER' => 1095950196,
              'fid' => 0,
              'display' => 1,
              'description' => '',
              'upload_button' => 'Upload',
              'remove_button' => 'Remove',
              'upload' => '',
              'alt' => '',
              'title' => '',
            ),
          ),
        ),
        'field_bb_guardian_letter' => array(
          'und' => array(
            0 => array(
              'fid' => 0,
              'display' => 1,
              'description' => '',
              'upload_button' => 'Upload',
              'remove_button' => 'Remove',
              'upload' => '',
              'alt' => '',
              'title' => '',
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
      'anonymous_user' => array(
        'label' => 'above',
        'module' => 'multifield',
        'settings' => array(
          'view_mode' => 'default',
        ),
        'type' => 'multifield_default',
        'weight' => 45,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'multifield',
        'settings' => array(
          'view_mode' => 'default',
        ),
        'type' => 'multifield_default',
        'weight' => 45,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'multifield',
        'settings' => array(
          'view_mode' => 'default',
        ),
        'type' => 'multifield_default',
        'weight' => 14,
      ),
      'user_admin_edit' => array(
        'label' => 'above',
        'module' => 'multifield',
        'settings' => array(
          'view_mode' => 'default',
        ),
        'type' => 'multifield_default',
        'weight' => 45,
      ),
      'user_admin_view' => array(
        'label' => 'above',
        'module' => 'multifield',
        'settings' => array(
          'view_mode' => 'default',
        ),
        'type' => 'multifield_default',
        'weight' => 45,
      ),
      'user_edit_view' => array(
        'label' => 'above',
        'module' => 'multifield',
        'settings' => array(
          'view_mode' => 'default',
        ),
        'type' => 'multifield_default',
        'weight' => 45,
      ),
      'user_view' => array(
        'label' => 'above',
        'module' => 'multifield',
        'settings' => array(
          'view_mode' => 'default',
        ),
        'type' => 'multifield_default',
        'weight' => 45,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_bb_minors_details',
    'label' => 'Minor\'s details',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'multifield',
      'settings' => array(),
      'type' => 'multifield_default',
      'weight' => 15,
    ),
  );

  // Exported field_instance: 'user-user-field_bb_minors_yn'.
  $field_instances['user-user-field_bb_minors_yn'] = array(
    'bundle' => 'user',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Under 18\'s are anyone defined as not being 18 on the first day of the event, 24 April 2017.',
    'display' => array(
      'anonymous_user' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 44,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 44,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 13,
      ),
      'user_admin_edit' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 44,
      ),
      'user_admin_view' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 44,
      ),
      'user_edit_view' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 44,
      ),
      'user_view' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 44,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_bb_minors_yn',
    'label' => 'Are you bringing any under 18\'s with you?',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => 1,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 14,
    ),
  );

  // Exported field_instance: 'user-user-field_bb_mutant'.
  $field_instances['user-user-field_bb_mutant'] = array(
    'bundle' => 'user',
    'custom_add_another' => '',
    'custom_remove' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'anonymous_user' => array(
        'label' => 'above',
        'module' => 'markup',
        'settings' => array(),
        'type' => 'markup_default',
        'weight' => 29,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'markup',
        'settings' => array(),
        'type' => 'markup_default',
        'weight' => 29,
      ),
      'full' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 45,
      ),
      'user_admin_edit' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 29,
      ),
      'user_admin_view' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 29,
      ),
      'user_edit_view' => array(
        'label' => 'above',
        'module' => 'markup',
        'settings' => array(),
        'type' => 'markup_default',
        'weight' => 29,
      ),
      'user_view' => array(
        'label' => 'above',
        'module' => 'markup',
        'settings' => array(),
        'type' => 'markup_default',
        'weight' => 29,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_bb_mutant',
    'label' => 'bb_mutant',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'markup',
      'settings' => array(),
      'type' => 'markup',
      'weight' => 25,
    ),
  );

  // Exported field_instance: 'user-user-field_bb_mutant1'.
  $field_instances['user-user-field_bb_mutant1'] = array(
    'bundle' => 'user',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'anonymous_user' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 30,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 30,
      ),
      'full' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 46,
      ),
      'user_admin_edit' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 30,
      ),
      'user_admin_view' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 30,
      ),
      'user_edit_view' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 30,
      ),
      'user_view' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 30,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_bb_mutant1',
    'label' => 'Scooters, land boards and quads are not Mutants: mutate it - and register it - or park it.',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => 1,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 26,
    ),
  );

  // Exported field_instance: 'user-user-field_bb_not_music_festival'.
  $field_instances['user-user-field_bb_not_music_festival'] = array(
    'bundle' => 'user',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'anonymous_user' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 6,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 6,
      ),
      'full' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 22,
      ),
      'user_admin_edit' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 6,
      ),
      'user_admin_view' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 6,
      ),
      'user_edit_view' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 6,
      ),
      'user_view' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 6,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_bb_not_music_festival',
    'label' => 'Did you know that AfrikaBurn\'s not a party or music festival?',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => 1,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'user-user-field_bb_part_of'.
  $field_instances['user-user-field_bb_part_of'] = array(
    'bundle' => 'user',
    'custom_add_another' => '',
    'custom_remove' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'anonymous_user' => array(
        'label' => 'above',
        'module' => 'markup',
        'settings' => array(),
        'type' => 'markup_default',
        'weight' => 18,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'markup',
        'settings' => array(),
        'type' => 'markup_default',
        'weight' => 18,
      ),
      'full' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 33,
      ),
      'user_admin_edit' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 18,
      ),
      'user_admin_view' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 18,
      ),
      'user_edit_view' => array(
        'label' => 'above',
        'module' => 'markup',
        'settings' => array(),
        'type' => 'markup_default',
        'weight' => 18,
      ),
      'user_view' => array(
        'label' => 'above',
        'module' => 'markup',
        'settings' => array(),
        'type' => 'markup_default',
        'weight' => 18,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_bb_part_of',
    'label' => 'bb_part_of',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'markup',
      'settings' => array(),
      'type' => 'markup',
      'weight' => 14,
    ),
  );

  // Exported field_instance: 'user-user-field_bb_part_of1'.
  $field_instances['user-user-field_bb_part_of1'] = array(
    'bundle' => 'user',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Don\'t know what MOOP is? Find out more about it <a href="http://www.afrikaburn.com/the-event/participation/leave-no-trace" target="_blank"> here </a>.',
    'display' => array(
      'anonymous_user' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 19,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 19,
      ),
      'full' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 35,
      ),
      'user_admin_edit' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 19,
      ),
      'user_admin_view' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 19,
      ),
      'user_edit_view' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 19,
      ),
      'user_view' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 19,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_bb_part_of1',
    'label' => 'Or do you have a plan to set up an amazing camp and proceed to become part of the community by participating?',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => 1,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 15,
    ),
  );

  // Exported field_instance: 'user-user-field_bb_partisipating'.
  $field_instances['user-user-field_bb_partisipating'] = array(
    'bundle' => 'user',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'anonymous_user' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 9,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 9,
      ),
      'full' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 25,
      ),
      'user_admin_edit' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 9,
      ),
      'user_admin_view' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 9,
      ),
      'user_edit_view' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 9,
      ),
      'user_view' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 9,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_bb_partisipating',
    'label' => 'Are you aware that by participating, you\'re headed into a radical experiment in community and creativity?',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => 1,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'user-user-field_bb_pledge'.
  $field_instances['user-user-field_bb_pledge'] = array(
    'bundle' => 'user',
    'custom_add_another' => '',
    'custom_remove' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'anonymous_user' => array(
        'label' => 'above',
        'module' => 'markup',
        'settings' => array(),
        'type' => 'markup_default',
        'weight' => 34,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'markup',
        'settings' => array(),
        'type' => 'markup_default',
        'weight' => 34,
      ),
      'full' => array(
        'label' => 'inline',
        'module' => 'markup',
        'settings' => array(),
        'type' => 'markup_default',
        'weight' => 3,
      ),
      'user_admin_edit' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 34,
      ),
      'user_admin_view' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 34,
      ),
      'user_edit_view' => array(
        'label' => 'above',
        'module' => 'markup',
        'settings' => array(),
        'type' => 'markup_default',
        'weight' => 34,
      ),
      'user_view' => array(
        'label' => 'above',
        'module' => 'markup',
        'settings' => array(),
        'type' => 'markup_default',
        'weight' => 34,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_bb_pledge',
    'label' => 'pledge',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'markup',
      'settings' => array(),
      'type' => 'markup',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'user-user-field_bb_preamble'.
  $field_instances['user-user-field_bb_preamble'] = array(
    'bundle' => 'user',
    'custom_add_another' => '',
    'custom_remove' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'anonymous_user' => array(
        'label' => 'above',
        'module' => 'markup',
        'settings' => array(),
        'type' => 'markup_default',
        'weight' => 2,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'markup',
        'settings' => array(),
        'type' => 'markup_default',
        'weight' => 2,
      ),
      'full' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 51,
      ),
      'user_admin_edit' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
      'user_admin_view' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
      'user_edit_view' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
      'user_view' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_bb_preamble',
    'label' => 'Preamble',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'markup',
      'settings' => array(),
      'type' => 'markup',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'user-user-field_bb_principles'.
  $field_instances['user-user-field_bb_principles'] = array(
    'bundle' => 'user',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Tip: They aren\'t rules, or commandments. Read all about them here: <a href="http://www.afrikaburn.com/about/guiding-principles" target="_blank"> 11 Principles </a>',
    'display' => array(
      'anonymous_user' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 11,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 11,
      ),
      'full' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 27,
      ),
      'user_admin_edit' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 11,
      ),
      'user_admin_view' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 11,
      ),
      'user_edit_view' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 11,
      ),
      'user_view' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 11,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_bb_principles',
    'label' => 'Did you know AfrikaBurn’s informed by a set of guidelines known as the 11 Principles?',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => 1,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'user-user-field_bb_read_survival_guide'.
  $field_instances['user-user-field_bb_read_survival_guide'] = array(
    'bundle' => 'user',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'No? Seriously, read our <a href="http://afrikaburn.com/the-event/preparation/survival-guide" target="_blank"> Survival Guide </a> before you hit the road.',
    'display' => array(
      'anonymous_user' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 15,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 15,
      ),
      'full' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 31,
      ),
      'user_admin_edit' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 15,
      ),
      'user_admin_view' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 15,
      ),
      'user_edit_view' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 15,
      ),
      'user_view' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 15,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_bb_read_survival_guide',
    'label' => 'Have you read the Survival Guide?',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => 1,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 11,
    ),
  );

  // Exported field_instance: 'user-user-field_bb_theme'.
  $field_instances['user-user-field_bb_theme'] = array(
    'bundle' => 'user',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '(tip: head to <a href="http://www.afrikaburn.com/the-event/2017-theme-play" target="_blank"> this page </a> to find out)',
    'display' => array(
      'anonymous_user' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 10,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 10,
      ),
      'full' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 26,
      ),
      'user_admin_edit' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 10,
      ),
      'user_admin_view' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 10,
      ),
      'user_edit_view' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 10,
      ),
      'user_view' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 10,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_bb_theme',
    'label' => 'The theme for AfrikaBurn 2017 is...?',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => 1,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'user-user-field_booze_p1'.
  $field_instances['user-user-field_booze_p1'] = array(
    'bundle' => 'user',
    'custom_add_another' => '',
    'custom_remove' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'anonymous_user' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 65,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 65,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'user_admin_edit' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'user_admin_view' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'user_edit_view' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'user_view' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_booze_p1',
    'label' => 'booze p1',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'markup',
      'settings' => array(),
      'type' => 'markup',
      'weight' => 39,
    ),
  );

  // Exported field_instance: 'user-user-field_booze_p2'.
  $field_instances['user-user-field_booze_p2'] = array(
    'bundle' => 'user',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'anonymous_user' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 66,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 66,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'user_admin_edit' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'user_admin_view' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'user_edit_view' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'user_view' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_booze_p2',
    'label' => 'so you’re able to identify who’s OK (and not OK) to gift your drink to?',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 40,
    ),
  );

  // Exported field_instance: 'user-user-field_date_of_birth'.
  $field_instances['user-user-field_date_of_birth'] = array(
    'bundle' => 'user',
    'custom_add_another' => '',
    'custom_remove' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'anonymous_user' => array(
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
        'weight' => 41,
      ),
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
        'weight' => 41,
      ),
      'full' => array(
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
        'weight' => 11,
      ),
      'user_admin_edit' => array(
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
        'weight' => 41,
      ),
      'user_admin_view' => array(
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
        'weight' => 41,
      ),
      'user_edit_view' => array(
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
        'weight' => 41,
      ),
      'user_view' => array(
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
        'weight' => 41,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_date_of_birth',
    'label' => 'Date of Birth',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'default_value' => 'now',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'user_register_form' => 1,
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
        'year_range' => '-110:+0',
      ),
      'type' => 'date_select',
      'weight' => 13,
    ),
  );

  // Exported field_instance: 'user-user-field_drone_update'.
  $field_instances['user-user-field_drone_update'] = array(
    'bundle' => 'user',
    'custom_add_another' => '',
    'custom_remove' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'anonymous_user' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 59,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 59,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'user_admin_edit' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'user_admin_view' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'user_edit_view' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'user_view' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_drone_update',
    'label' => 'Are you aware that in order to fly a drone or remotely-operated aircraft of any description, you have to contact our Airspace cr',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'markup',
      'settings' => array(),
      'type' => 'markup',
      'weight' => 33,
    ),
  );

  // Exported field_instance: 'user-user-field_drone_update_p2'.
  $field_instances['user-user-field_drone_update_p2'] = array(
    'bundle' => 'user',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'anonymous_user' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 60,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 60,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'user_admin_edit' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'user_admin_view' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'user_edit_view' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'user_view' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_drone_update_p2',
    'label' => '(so that nobody is injured by flying chunks of metal)? ',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 34,
    ),
  );

  // Exported field_instance: 'user-user-field_field_bb_leave_no_trace2'.
  $field_instances['user-user-field_field_bb_leave_no_trace2'] = array(
    'bundle' => 'user',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'anonymous_user' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 24,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 24,
      ),
      'full' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 40,
      ),
      'user_admin_edit' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 24,
      ),
      'user_admin_view' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 24,
      ),
      'user_edit_view' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 24,
      ),
      'user_view' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 24,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_field_bb_leave_no_trace2',
    'label' => 'Because you’re expected to bring everything in, and take it all away again?',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => 1,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 20,
    ),
  );

  // Exported field_instance: 'user-user-field_first_name'.
  $field_instances['user-user-field_first_name'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'anonymous_user' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 36,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 36,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 5,
      ),
      'user_admin_edit' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 36,
      ),
      'user_admin_view' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 36,
      ),
      'user_edit_view' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 36,
      ),
      'user_view' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 36,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_first_name',
    'label' => 'First Name',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'text_processing' => 0,
      'user_register_form' => 1,
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

  // Exported field_instance: 'user-user-field_gaurdian'.
  $field_instances['user-user-field_gaurdian'] = array(
    'bundle' => 'user',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Who\'s your guardian at the event? This is only mandatory if you are under 18 on the first day of the event. 
This will also link to their account to allow them to directly purchase your event ticket if they choose.
(if your 18th birthday is during the event, you can speak to the gate crew about a new armband on your birthday, if you have your ID with you.)',
    'display' => array(
      'anonymous_user' => array(
        'label' => 'above',
        'module' => 'email',
        'settings' => array(),
        'type' => 'email_default',
        'weight' => 43,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'email',
        'settings' => array(),
        'type' => 'email_default',
        'weight' => 43,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'email',
        'settings' => array(),
        'type' => 'email_default',
        'weight' => 12,
      ),
      'user_admin_edit' => array(
        'label' => 'above',
        'module' => 'email',
        'settings' => array(),
        'type' => 'email_default',
        'weight' => 43,
      ),
      'user_admin_view' => array(
        'label' => 'above',
        'module' => 'email',
        'settings' => array(),
        'type' => 'email_default',
        'weight' => 43,
      ),
      'user_edit_view' => array(
        'label' => 'above',
        'module' => 'email',
        'settings' => array(),
        'type' => 'email_default',
        'weight' => 43,
      ),
      'user_view' => array(
        'label' => 'above',
        'module' => 'email',
        'settings' => array(),
        'type' => 'email_default',
        'weight' => 43,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_gaurdian',
    'label' => 'Guardian or person buying your ticket.',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => 1,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'email',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'email_textfield',
      'weight' => 16,
    ),
  );

  // Exported field_instance: 'user-user-field_gender'.
  $field_instances['user-user-field_gender'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'anonymous_user' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 47,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 47,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 16,
      ),
      'user_admin_edit' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 47,
      ),
      'user_admin_view' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 47,
      ),
      'user_edit_view' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 47,
      ),
      'user_view' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 47,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_gender',
    'label' => 'Gender',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => 1,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 17,
    ),
  );

  // Exported field_instance: 'user-user-field_i_agree_to_the_terms_condi'.
  $field_instances['user-user-field_i_agree_to_the_terms_condi'] = array(
    'bundle' => 'user',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'anonymous_user' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 52,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 52,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 21,
      ),
      'user_admin_edit' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 52,
      ),
      'user_admin_view' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 52,
      ),
      'user_edit_view' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 52,
      ),
      'user_view' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 52,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_i_agree_to_the_terms_condi',
    'label' => 'I agree to the Terms & Conditions of the Burner Bio',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => 1,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 0,
      ),
      'type' => 'options_onoff',
      'weight' => 25,
    ),
  );

  // Exported field_instance: 'user-user-field_imported_from_wordpress'.
  $field_instances['user-user-field_imported_from_wordpress'] = array(
    'bundle' => 'user',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'anonymous_user' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 68,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 68,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'user_admin_edit' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'user_admin_view' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'user_edit_view' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'user_view' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_imported_from_wordpress',
    'label' => 'Imported from wordpress',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 42,
    ),
  );

  // Exported field_instance: 'user-user-field_last_name'.
  $field_instances['user-user-field_last_name'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'anonymous_user' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 37,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 37,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 6,
      ),
      'user_admin_edit' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 37,
      ),
      'user_admin_view' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 37,
      ),
      'user_edit_view' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 37,
      ),
      'user_view' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 37,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_last_name',
    'label' => 'Last Name',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'text_processing' => 0,
      'user_register_form' => 1,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'user-user-field_mobile_number'.
  $field_instances['user-user-field_mobile_number'] = array(
    'bundle' => 'user',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Don\'t want to enter your number for privacy reasons? No problem - just enter \'NO\' and proceed. (just be aware that once your ticket\'s purchased, one of the ways you\'re notified is by a text to your number - and if there are any last-minute updates, which are also sent via mail & text, a text is the best way to get it to you soonest)',
    'display' => array(
      'anonymous_user' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 48,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 48,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 17,
      ),
      'user_admin_edit' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 48,
      ),
      'user_admin_view' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 48,
      ),
      'user_edit_view' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 48,
      ),
      'user_view' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 48,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_mobile_number',
    'label' => 'Mobile Number',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'text_processing' => 0,
      'user_register_form' => 1,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 18,
    ),
  );

  // Exported field_instance: 'user-user-field_moop_is_an_abbreviation_fo'.
  $field_instances['user-user-field_moop_is_an_abbreviation_fo'] = array(
    'bundle' => 'user',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'anonymous_user' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 22,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 22,
      ),
      'full' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 38,
      ),
      'user_admin_edit' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 22,
      ),
      'user_admin_view' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 22,
      ),
      'user_edit_view' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 22,
      ),
      'user_view' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 22,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_moop_is_an_abbreviation_fo',
    'label' => 'MOOP is an abbreviation for:',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => 1,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 18,
    ),
  );

  // Exported field_instance: 'user-user-field_moop_revised_burner_bio'.
  $field_instances['user-user-field_moop_revised_burner_bio'] = array(
    'bundle' => 'user',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'anonymous_user' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 54,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 54,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'user_admin_edit' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 54,
      ),
      'user_admin_view' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'user_edit_view' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 54,
      ),
      'user_view' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 54,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_moop_revised_burner_bio',
    'label' => 'moop revised burner bio',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'markup',
      'settings' => array(),
      'type' => 'markup',
      'weight' => 31,
    ),
  );

  // Exported field_instance: 'user-user-field_moop_revised_burner_bio2'.
  $field_instances['user-user-field_moop_revised_burner_bio2'] = array(
    'bundle' => 'user',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'anonymous_user' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 55,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 55,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'user_admin_edit' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 55,
      ),
      'user_admin_view' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'user_edit_view' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_key',
        'weight' => 55,
      ),
      'user_view' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 55,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_moop_revised_burner_bio2',
    'label' => 'But do your campmates know?',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 32,
    ),
  );

  // Exported field_instance: 'user-user-field_munciple_district'.
  $field_instances['user-user-field_munciple_district'] = array(
    'bundle' => 'user',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'anonymous_user' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 46,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 46,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 15,
      ),
      'user_admin_edit' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 46,
      ),
      'user_admin_view' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 46,
      ),
      'user_edit_view' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 46,
      ),
      'user_view' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 46,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_munciple_district',
    'label' => 'Muncipal District',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => 1,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 11,
    ),
  );

  // Exported field_instance: 'user-user-field_mutant_registration_p1'.
  $field_instances['user-user-field_mutant_registration_p1'] = array(
    'bundle' => 'user',
    'custom_add_another' => '',
    'custom_remove' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'anonymous_user' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 61,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 61,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'user_admin_edit' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'user_admin_view' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'user_edit_view' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'user_view' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_mutant_registration_p1',
    'label' => 'Mutant registration_p1',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'markup',
      'settings' => array(),
      'type' => 'markup',
      'weight' => 35,
    ),
  );

  // Exported field_instance: 'user-user-field_mutant_registration_p2'.
  $field_instances['user-user-field_mutant_registration_p2'] = array(
    'bundle' => 'user',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'anonymous_user' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 62,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 62,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'user_admin_edit' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'user_admin_view' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'user_edit_view' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'user_view' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_mutant_registration_p2',
    'label' => 'Scooters, land boards and quads are not Mutants: mutate it - and register it - or park it.',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 36,
    ),
  );

  // Exported field_instance: 'user-user-field_newsletter'.
  $field_instances['user-user-field_newsletter'] = array(
    'bundle' => 'user',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'anonymous_user' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 58,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 58,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'user_admin_edit' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'user_admin_view' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'user_edit_view' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'user_view' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_newsletter',
    'label' => 'Sign up for our newsletter. ',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => 1,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 0,
      ),
      'type' => 'options_onoff',
      'weight' => 22,
    ),
  );

  // Exported field_instance: 'user-user-field_other_burns'.
  $field_instances['user-user-field_other_burns'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'If so how where you involved',
    'display' => array(
      'anonymous_user' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 50,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 50,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 19,
      ),
      'user_admin_edit' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 50,
      ),
      'user_admin_view' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 50,
      ),
      'user_edit_view' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 50,
      ),
      'user_view' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 50,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_other_burns',
    'label' => 'Have you been to other burns?',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'text_processing' => 0,
      'user_register_form' => 0,
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

  // Exported field_instance: 'user-user-field_pink_bangle_p1'.
  $field_instances['user-user-field_pink_bangle_p1'] = array(
    'bundle' => 'user',
    'custom_add_another' => '',
    'custom_remove' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'anonymous_user' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 63,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 63,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'user_admin_edit' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'user_admin_view' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'user_edit_view' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'user_view' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_pink_bangle_p1',
    'label' => 'pink bangle p1',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'markup',
      'settings' => array(),
      'type' => 'markup',
      'weight' => 37,
    ),
  );

  // Exported field_instance: 'user-user-field_pink_bangle_p2'.
  $field_instances['user-user-field_pink_bangle_p2'] = array(
    'bundle' => 'user',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'anonymous_user' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 64,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 64,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'user_admin_edit' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'user_admin_view' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'user_edit_view' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'user_view' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_pink_bangle_p2',
    'label' => 'They’re a visual signal that the wearer is not interested in being captured on photo, or video.',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 38,
    ),
  );

  // Exported field_instance: 'user-user-field_previous_envolvement'.
  $field_instances['user-user-field_previous_envolvement'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Been part of a Theme Camp, Artwork, Performance or Mutant crew? Volunteered?',
    'display' => array(
      'anonymous_user' => array(
        'label' => 'above',
        'module' => 'multifield',
        'settings' => array(
          'view_mode' => 'default',
        ),
        'type' => 'multifield_default',
        'weight' => 49,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'multifield',
        'settings' => array(
          'view_mode' => 'default',
        ),
        'type' => 'multifield_default',
        'weight' => 49,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'multifield',
        'settings' => array(
          'view_mode' => 'default',
        ),
        'type' => 'multifield_default',
        'weight' => 18,
      ),
      'user_admin_edit' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 49,
      ),
      'user_admin_view' => array(
        'label' => 'above',
        'module' => 'multifield',
        'settings' => array(
          'view_mode' => 'default',
        ),
        'type' => 'multifield_default',
        'weight' => 49,
      ),
      'user_edit_view' => array(
        'label' => 'above',
        'module' => 'multifield',
        'settings' => array(
          'view_mode' => 'default',
        ),
        'type' => 'multifield_default',
        'weight' => 49,
      ),
      'user_view' => array(
        'label' => 'above',
        'module' => 'multifield',
        'settings' => array(
          'view_mode' => 'default',
        ),
        'type' => 'multifield_default',
        'weight' => 49,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_previous_envolvement',
    'label' => 'Please let us know about your previous participation at AfrikaBurn.',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'multifield',
      'settings' => array(),
      'type' => 'multifield_default',
      'weight' => 19,
    ),
  );

  // Exported field_instance: 'user-user-field_sa_id_or_passport_number'.
  $field_instances['user-user-field_sa_id_or_passport_number'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'anonymous_user' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 39,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 39,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 9,
      ),
      'user_admin_edit' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 39,
      ),
      'user_admin_view' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 39,
      ),
      'user_edit_view' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 39,
      ),
      'user_view' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 39,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_sa_id_or_passport_number',
    'label' => 'SA ID or Passport Number',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'text_processing' => 0,
      'user_register_form' => 1,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'user-user-field_secondary_email_address'.
  $field_instances['user-user-field_secondary_email_address'] = array(
    'bundle' => 'user',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'anonymous_user' => array(
        'label' => 'above',
        'module' => 'email',
        'settings' => array(),
        'type' => 'email_default',
        'weight' => 38,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'email',
        'settings' => array(),
        'type' => 'email_default',
        'weight' => 38,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'email',
        'settings' => array(),
        'type' => 'email_default',
        'weight' => 8,
      ),
      'user_admin_edit' => array(
        'label' => 'above',
        'module' => 'email',
        'settings' => array(),
        'type' => 'email_default',
        'weight' => 38,
      ),
      'user_admin_view' => array(
        'label' => 'above',
        'module' => 'email',
        'settings' => array(),
        'type' => 'email_default',
        'weight' => 38,
      ),
      'user_edit_view' => array(
        'label' => 'above',
        'module' => 'email',
        'settings' => array(),
        'type' => 'email_default',
        'weight' => 38,
      ),
      'user_view' => array(
        'label' => 'above',
        'module' => 'email',
        'settings' => array(),
        'type' => 'email_default',
        'weight' => 38,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_secondary_email_address',
    'label' => 'Secondary email address',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => 1,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'email',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'email_textfield',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'user-user-field_terms_and_conditions'.
  $field_instances['user-user-field_terms_and_conditions'] = array(
    'bundle' => 'user',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'anonymous_user' => array(
        'label' => 'above',
        'module' => 'markup',
        'settings' => array(),
        'type' => 'markup_default',
        'weight' => 51,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'markup',
        'settings' => array(),
        'type' => 'markup_default',
        'weight' => 51,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'markup',
        'settings' => array(),
        'type' => 'markup_default',
        'weight' => 20,
      ),
      'user_admin_edit' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 51,
      ),
      'user_admin_view' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 51,
      ),
      'user_edit_view' => array(
        'label' => 'above',
        'module' => 'markup',
        'settings' => array(),
        'type' => 'markup_default',
        'weight' => 51,
      ),
      'user_view' => array(
        'label' => 'above',
        'module' => 'markup',
        'settings' => array(),
        'type' => 'markup_default',
        'weight' => 51,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_terms_and_conditions',
    'label' => 'terms and conditions',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'markup',
      'settings' => array(),
      'type' => 'markup',
      'weight' => 24,
    ),
  );

  // Exported field_instance: 'user-user-field_updated'.
  $field_instances['user-user-field_updated'] = array(
    'bundle' => 'user',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'anonymous_user' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 69,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 69,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'user_admin_edit' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'user_admin_view' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'user_edit_view' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'user_view' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_updated',
    'label' => 'User updated',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 43,
    ),
  );

  // Exported field_instance: 'user-user-field_volunteer_ticket'.
  $field_instances['user-user-field_volunteer_ticket'] = array(
    'bundle' => 'user',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'anonymous_user' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 67,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 67,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'user_admin_edit' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'user_admin_view' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'user_edit_view' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'user_view' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_volunteer_ticket',
    'label' => 'Volunteer Ticket',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 41,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('(Tip: you can dig for that answer <a href="http://www.afrikaburn.com/about/guiding-principles" target="_blank">here</a>)');
  t('(it\'s OK to just describe it briefly - save the long version for your Art, Mutant Vehicle, Theme Camp or Performance registration)');
  t('(see <a href="http://afrikaburn.com/binnekringblog/roots-fruits-and-offshoots" target="_blank">  this page </a> for more info on the historical roots of AfrikaBurn)');
  t('(so that nobody is injured by flying chunks of metal)? ');
  t('(this is so that nobody is injured by flying chunks of metal)');
  t('(this is to identify who’s OK (and not OK)  to gift your drink to)');
  t('(tip: head to <a href="http://www.afrikaburn.com/the-event/2017-theme-play" target="_blank"> this page </a> to find out)');
  t('Agree');
  t('Are you aware that by participating, you\'re headed into a radical experiment in community and creativity?');
  t('Are you aware that in order to fly a drone or remotely-operated aircraft of any description, you have to contact our Airspace cr');
  t('Are you aware that there’s nothing sold on site at all except ice?');
  t('Are you bringing any under 18\'s with you?');
  t('Are you their Parent or Legal Gardian');
  t('Because you’re expected to bring everything in, and take it all away again?');
  t('Been part of a Theme Camp, Artwork, Performance or Mutant crew? Volunteered?');
  t('But do your campmates know?');
  t('Complete the following sentence: “Gifting does not contemplate...');
  t('Copy of Parent\'s ID');
  t('Date of Birth');
  t('Did you know AfrikaBurn’s informed by a set of guidelines known as the 11 Principles?');
  t('Did you know that AfrikaBurn\'s history is rooted in:');
  t('Did you know that AfrikaBurn\'s not a party or music festival?');
  t('Don\'t know what MOOP is? Find out more about it <a href="http://www.afrikaburn.com/the-event/participation/leave-no-trace" target="_blank"> here </a>.');
  t('Don\'t want to enter your number for privacy reasons? No problem - just enter \'NO\' and proceed. (just be aware that once your ticket\'s purchased, one of the ways you\'re notified is by a text to your number - and if there are any last-minute updates, which are also sent via mail & text, a text is the best way to get it to you soonest)');
  t('Email');
  t('First Name');
  t('Gardian\'s ID required to be able to purchase a ticket');
  t('Gender');
  t('Guardian or person buying your ticket.');
  t('Have you been to other burns?');
  t('Have you read the Survival Guide?');
  t('How did you participate? Did you volunteer, and if so, how?');
  t('I agree to the Terms & Conditions of the Burner Bio');
  t('If so how where you involved');
  t('Imported from wordpress');
  t('Insert your madly creative project and / or gifting idea here:');
  t('Last Name');
  t('Leave No Trace');
  t('MOOP is an abbreviation for:');
  t('Minor\'s details');
  t('Mobile Number');
  t('Muncipal District');
  t('Mutant registration_p1');
  t('No? Seriously, read our <a href="http://afrikaburn.com/the-event/preparation/survival-guide" target="_blank"> Survival Guide </a> before you hit the road.');
  t('Only required when you wish to purchase their ticket.');
  t('Or do you have a plan to set up an amazing camp and proceed to become part of the community by participating?');
  t('Please let us know about your previous participation at AfrikaBurn.');
  t('Preamble');
  t('Required if they will be over the age of thirteen on the first day of the event.');
  t('SA ID or Passport Number');
  t('Scooters, land boards and quads are not Mutants: mutate it - and register it - or park it.');
  t('Secondary email address');
  t('Sign up for our newsletter. ');
  t('Signed Copy of Guardian Authorization Letter');
  t('So...are you expecting a jol?');
  t('The theme for AfrikaBurn 2017 is...?');
  t('They’re a visual signal that the wearer is not interested in being captured on photo, or video.');
  t('Tip: They aren\'t rules, or commandments. Read all about them here: <a href="http://www.afrikaburn.com/about/guiding-principles" target="_blank"> 11 Principles </a>');
  t('Under 18\'s are anyone defined as not being 18 on the first day of the event, 24 April 2017.');
  t('User updated');
  t('Volunteer Ticket');
  t('Where you’re expected to rely on your own abilities to survive for the entire time?');
  t('Who\'s your guardian at the event? This is only mandatory if you are under 18 on the first day of the event. 
This will also link to their account to allow them to directly purchase your event ticket if they choose.
(if your 18th birthday is during the event, you can speak to the gate crew about a new armband on your birthday, if you have your ID with you.)');
  t('Will this be your first burn?');
  t('Year and Event Name');
  t('ain\'t no party');
  t('bb_booze');
  t('bb_mutant');
  t('bb_part_of');
  t('booze p1');
  t('dressed');
  t('drone');
  t('haul');
  t('moop revised burner bio');
  t('pink bangle p1');
  t('pledge');
  t('so you’re able to identify who’s OK (and not OK) to gift your drink to?');
  t('terms and conditions');
  t('unicorns, superheroes, fairytale characters (or even undressed)?');

  return $field_instances;
}
