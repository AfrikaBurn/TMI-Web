<?php

/**
 * @file
 * Documents nodeaccess_passwords's hooks for api reference.
 */

/**
 * Act on node access password realms.
 *
 * @param &$object
 *   The realm.
 * @param $op
 *   The operation, indicates where/when this is being invoked.  Possible values:
 *   - "nodeaccess_password_realm_load"
 *   - "nodeaccess_password_realm_insert"
 *   - "nodeaccess_password_realm_update"
 *   - "nodeaccess_password_realm_delete"
 * @param $a3
 *   - Currently no operations support this parameter.
 * @param $a4
 *   - Currently no operations support this parameter.
 * @return
 *   The returned value of the invoked hooks:
 *   - Currently no operations support a return value.
 */
function hook_nodeaccess_password_realm_api(&$object, $op, $a3 = NULL, $a4 = NULL) {
  // no example code
}

/**
 * Modify the 403 page render array.
 */
function hook_nodeaccess_password_403_alter(&$return) {
  // no example code
}