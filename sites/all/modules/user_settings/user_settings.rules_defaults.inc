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
  $items['rules_login_bio_check'] = entity_import('rules_config', '{ "rules_login_bio_check" : {
      "LABEL" : "Login bio check",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "login user burner bio" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "user_login" : [] },
      "IF" : [
        { "data_is_empty" : { "data" : [ "site:current-user:field-bb-agree" ] } }
      ],
      "DO" : [ { "redirect" : { "url" : "user\\/[account:uid]\\/edit" } } ]
    }
  }');
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
