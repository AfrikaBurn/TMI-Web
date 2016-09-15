<?php
/**
 * @file
 * theme_camps.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function theme_camps_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-theme_camps-field_compulsory_reading'.
  $field_instances['node-theme_camps-field_compulsory_reading'] = array(
    'bundle' => 'theme_camps',
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
    'field_name' => 'field_compulsory_reading',
    'label' => 'Compulsory reading!',
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
      'weight' => 11,
    ),
  );

  // Exported field_instance: 'node-theme_camps-field_creative_lead'.
  $field_instances['node-theme_camps-field_creative_lead'] = array(
    'bundle' => 'theme_camps',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'The camp lead is responsible for all correspondence, including Creative Crew tickets, Early Arrivals passes and camp logistics. 
Please use the same email address that you used on your Burner Bio and make sure you check it regularly. <br>',
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
    'label' => 'Who\'s the Camp Lead?',
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

  // Exported field_instance: 'node-theme_camps-field_describe_your_project'.
  $field_instances['node-theme_camps-field_describe_your_project'] = array(
    'bundle' => 'theme_camps',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'What are you planning to offer? How? When? Give us a general idea of what you\'re planning for your Theme Camp. ',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
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
    'field_name' => 'field_describe_your_project',
    'label' => 'Tell us about your camp for 2017',
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

  // Exported field_instance: 'node-theme_camps-field_do_you_have_a_stage'.
  $field_instances['node-theme_camps-field_do_you_have_a_stage'] = array(
    'bundle' => 'theme_camps',
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
    'field_name' => 'field_do_you_have_a_stage',
    'label' => 'Do you have a stage or performance area where performers are welcome?',
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
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'node-theme_camps-field_extention_of_default'.
  $field_instances['node-theme_camps-field_extention_of_default'] = array(
    'bundle' => 'theme_camps',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Is your camp as a platform for marketing or branding exercise? Stop right there: that\'s not going to happen.

Please read up on the <a href="http://afrikaburn.com/about/guiding-principles" target="_blank"> guiding principles </a> of AfrikaBurn to find out why.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
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
    'field_name' => 'field_extention_of_default',
    'label' => 'Is your Theme Camp an extension of the default world?',
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

  // Exported field_instance: 'node-theme_camps-field_moop_score'.
  $field_instances['node-theme_camps-field_moop_score'] = array(
    'bundle' => 'theme_camps',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'If you were part of a Theme Camp in 2016 what was your <a href="http://www.afrikaburn.com/binnekringblog/moop-map-2016" target="_blank"> MOOP map </a> rating?<br>
Red, Yellow, Green',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
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
    'field_name' => 'field_moop_score',
    'label' => 'Moop Map score in 2016',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'taxonomy',
      'settings' => array(
        'autocomplete_path' => 'taxonomy/autocomplete',
        'size' => 60,
      ),
      'type' => 'taxonomy_autocomplete',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'node-theme_camps-field_name_of_collective'.
  $field_instances['node-theme_camps-field_name_of_collective'] = array(
    'bundle' => 'theme_camps',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Name of collective putting together your Theme Camp.',
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
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-theme_camps-field_new_members'.
  $field_instances['node-theme_camps-field_new_members'] = array(
    'bundle' => 'theme_camps',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
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
    'field_name' => 'field_new_members',
    'label' => 'Are you open to new members?',
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
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'node-theme_camps-field_new_members_details'.
  $field_instances['node-theme_camps-field_new_members_details'] = array(
    'bundle' => 'theme_camps',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
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
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'node-theme_camps-field_new_members_email'.
  $field_instances['node-theme_camps-field_new_members_email'] = array(
    'bundle' => 'theme_camps',
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
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'node-theme_camps-field_performer_types'.
  $field_instances['node-theme_camps-field_performer_types'] = array(
    'bundle' => 'theme_camps',
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
    'field_name' => 'field_performer_types',
    'label' => 'Performer types',
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
      'type' => 'options_buttons',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'node-theme_camps-field_philosophical_statement'.
  $field_instances['node-theme_camps-field_philosophical_statement'] = array(
    'bundle' => 'theme_camps',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'What makes you want to go through all this trouble and pull this Theme Camp together?',
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
    'field_name' => 'field_philosophical_statement',
    'label' => 'What motivates you to be involved in a Theme Camp?',
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
      'weight' => 6,
    ),
  );

  // Exported field_instance:
  // 'node-theme_camps-field_please_submit_concept_imag'.
  $field_instances['node-theme_camps-field_please_submit_concept_imag'] = array(
    'bundle' => 'theme_camps',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
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
    'field_name' => 'field_please_submit_concept_imag',
    'label' => 'Please submit a concept image',
    'required' => 1,
    'settings' => array(
      'alt_field' => 0,
      'custom_add_another' => '',
      'custom_remove' => '',
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
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

  // Exported field_instance: 'node-theme_camps-field_stage_performers_dscr'.
  $field_instances['node-theme_camps-field_stage_performers_dscr'] = array(
    'bundle' => 'theme_camps',
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
    'field_name' => 'field_stage_performers_dscr',
    'label' => 'Provide info on the space and kind of performers you\'re looking for',
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
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'node-theme_camps-field_tc_title_discription'.
  $field_instances['node-theme_camps-field_tc_title_discription'] = array(
    'bundle' => 'theme_camps',
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
    'field_name' => 'field_tc_title_discription',
    'label' => 'What\'s the name of the Theme Camp?',
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
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-theme_camps-field_who_are_you_brief_bio_'.
  $field_instances['node-theme_camps-field_who_are_you_brief_bio_'] = array(
    'bundle' => 'theme_camps',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Provide info on who you are, what you do, where you come from & your history at AfrikaBurn.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
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
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'node-theme_camps-field_year_and_name_of_prev'.
  $field_instances['node-theme_camps-field_year_and_name_of_prev'] = array(
    'bundle' => 'theme_camps',
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
    'field_name' => 'field_year_and_name_of_prev',
    'label' => 'Year and name of previous theme camp(s)',
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
      'weight' => 6,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Are you open to new members?');
  t('Compulsory reading!');
  t('Contact email');
  t('Do you have a stage or performance area where performers are welcome?');
  t('If you were part of a Theme Camp in 2016 what was your <a href="http://www.afrikaburn.com/binnekringblog/moop-map-2016" target="_blank"> MOOP map </a> rating?<br>
Red, Yellow, Green');
  t('Is your Theme Camp an extension of the default world?');
  t('Is your camp as a platform for marketing or branding exercise? Stop right there: that\'s not going to happen.

Please read up on the <a href="http://afrikaburn.com/about/guiding-principles" target="_blank"> guiding principles </a> of AfrikaBurn to find out why.');
  t('Moop Map score in 2016');
  t('Name of collective');
  t('Name of collective putting together your Theme Camp.');
  t('Performer types');
  t('Please submit a concept image');
  t('Provide info on the space and kind of performers you\'re looking for');
  t('Provide info on who you are, what you do, where you come from & your history at AfrikaBurn.');
  t('Tell them who you are and what you are looking for');
  t('Tell us about your camp for 2017');
  t('The camp lead is responsible for all correspondence, including Creative Crew tickets, Early Arrivals passes and camp logistics. 
Please use the same email address that you used on your Burner Bio and make sure you check it regularly. <br>');
  t('What are you planning to offer? How? When? Give us a general idea of what you\'re planning for your Theme Camp. ');
  t('What makes you want to go through all this trouble and pull this Theme Camp together?');
  t('What motivates you to be involved in a Theme Camp?');
  t('What\'s the name of the Theme Camp?');
  t('Who are you?');
  t('Who\'s the Camp Lead?');
  t('Year and name of previous theme camp(s)');

  return $field_instances;
}
