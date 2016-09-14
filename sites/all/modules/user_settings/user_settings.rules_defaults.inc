<?php
/**
 * @file
 * user_settings.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function user_settings_default_rules_configuration() {
  $items = array();
  $items['rules_user_updated'] = entity_import('rules_config', '{ "rules_user_updated" : {
      "LABEL" : "User Updated",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "user update bb" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "user_insert" : [], "user_update" : [] },
      "DO" : [
        { "data_set" : {
            "data" : [ "site:current-user:field-updated" ],
            "value" : [ "site:current-user:field-updated" ]
          }
        }
      ]
    }
  }');
  return $items;
}
