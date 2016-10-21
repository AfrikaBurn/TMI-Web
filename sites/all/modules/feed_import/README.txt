FEED IMPORT

Project page: https://drupal.org/project/feed_import

This module only provides an UI for Feed Import Base module.
Checkout the examples of how to use this UI https://drupal.org/node/2190315

Hooks
-----------

For examples, check feed_import.module file.

To register new settings:

function hook_feed_import_setting_types() {
  return array(
    'setting-name' => array(
      'hook' => 'hook_to_invoke',
      'base' => 'BaseClass',
    );
  );
}

To register a reader:

function hook_feed_import_reader_info() {
  return array(
    'my_reader' => array(
      // Reader name
      'name' => t('Reader name'),
      // Reader description
      'description' => t('Description'),
      // If you want to extend other reader and use its options you can specify
      // here the name of parent reader. You can reorder options using #wight,
      // you can remove options by setting it to false, you can change it by
      // adding properties to options or you can add new options.
      'inherit_options' => 'processor name or FALSE if no options are inherited',
      // The class that handles this reader (extending FeedImportReader)
      'class' => 'ReaderNameClass',
      // Options are form elements which must have a default value
      'options' => array(
        'option1' => array(
          '#type' => 'textfield',
          '#title' => t('Option1'),
          '#description' => t('Description 1'),
          '#default_value' => '1',
          '#required' => TRUE,
          '#maxlength' => 1024,
          // validate option by using #element_validate
          '#element_validate' => array('my_element_validate_function'),
        ),
        'optionx' => array(
          '#type' => 'textarea',
          '#title' => t('Option X)'),
          '#description' => t('Description of X'),
          '#default_value' => '',
        ),
        // Other options
      )
    ),
  );
}

To register a new processor:

function hook_feed_import_processor_info() {
  // similar to hook_feed_import_reader_info().
}

To register a new hash manager:

function hook_feed_import_hash_manager_info() {
  // similar to hook_feed_import_reader_info().
}

To register a new filter handler:

function hook_feed_import_filter_info() {
  // similar to hook_feed_import_reader_info().
}
