<?php

/**
 * @file
 * Contains default rule.
 */

/**
 * Implements hook_default_rules_configuration().
 */
function flush_facebook_cache_rules_default_rules_configuration() {
  $configs = array();

  $rule = '{ "rules_facebook" : {
    "LABEL" : "Flush Facebook cache when a node is saved",
    "PLUGIN" : "reaction rule",
    "OWNER" : "rules",
    "REQUIRES" : [ "flush_facebook_cache_rules", "rules" ],
    "ON" : { "node_update" : [] },
    "DO" : [ { "flush_facebook_cache_rules" : { "node" : [ "node" ] } } ]
  }
}';

  $configs['rules_facebook'] = rules_import($rule);

  return $configs;
}
