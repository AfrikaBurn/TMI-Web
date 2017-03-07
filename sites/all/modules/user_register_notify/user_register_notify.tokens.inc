<?php

/**
 * @file
 * Builds placeholder replacement tokens for user-related data.
 */

/**
 * Implements hook_token_info().
 */
function user_register_notify_token_info() {
  $user = array();

  $user['user-register-notify-og-groups'] = array(
    'name' => t('User registration notify - Organic groups'),
    'description' => t('The OG role names the user account is a member of as comma separated list.'),
    'needs-data' => 'user',
  );

  return array(
    'tokens' => array('user' => $user),
  );
}

/**
 * Implements hook_tokens().
 */
function user_register_notify_tokens($type, $tokens, array $data = array(), array $options = array()) {
  $sanitize = !empty($options['sanitize']);
  $replacements = array();

  if ($type == 'user' && !empty($data['user']->roles)) {
    $account = $data['user'];

    foreach ($tokens as $name => $original) {
      switch ($name) {
        // Organic groups list.
        case 'user-register-notify-og-groups':
          if (module_exists('og')) {
            $result = db_query("SELECT o.og_description, n.title FROM {og_uid} u INNER JOIN {og} o ON o.nid = u.nid INNER JOIN {node} n on n.nid = u.nid WHERE u.uid = :uid", array(':uid' => $account->uid));

            $og_groups = '';
            while ($og = $result->fetchObject()) {
              $og_groups .= sprintf("%s - %s\n", $og->title, $og->og_description);
            }

            $og_data = t("Organic groups belonged to:\n@og_groups", array('@og_groups' => $og_groups));
          }
          else {
            $og_data = t("Organic groups module is not installed.\n");
          }

          $replacements[$original] = $sanitize ? check_plain($og_data) : $og_data;
          break;
      }
    }
  }

  return $replacements;
}
