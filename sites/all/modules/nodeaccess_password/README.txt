
Node access password

CONTENTS OF THIS FILE
----------------------

  * Introduction
  * Installation
  * Configuration


INTRODUCTION
------------
Maintainer: Daniel Braksator (http://drupal.org/user/134005)

Instructions on http://drupal.org/project/nodeaccess_password.


INSTALLATION
------------
1. Copy nodeaccess_password folder to modules directory.
   Usually sites/all/modules
2. At admin/modules enable the Node access password module.
3. Enable permissions at admin/people/permissions.
4. Configure the module at admin/config/people/nodeaccess_password.


CONFIGURATION
-------------
If you want to generate a password to access a node, create a new realm in the
config.  You must give it a name, choose which node types it applies to, and 
which users will be checked for that password.

Now the idea is that someone in a high user role with the user permission 'view
node access passwords' will see the passwords on the node, and be able to give
the passwords to people who can sign up to the website and enter the password
into their profile to gain access to the node.

If a node belongs to any realms that allow entering the password on the access
denied page, then passwords can be entered directly on the node page.

There is a content field available to show permitted users the node passwords.

You can alternatively output the passwords with some PHP code:
To find out what the password for a node is you could print it out in the node
template with something like this:

if (user_access('view node access passwords') && is_array($node->nodeaccess_password)) {
  print '<div id="nodeaccess-password">';
  foreach ($node->nodeaccess_password as $realm_id => $password) {
    $realm = nodeaccess_password_realm_load($realm_id);
    print '<div class="nodeaccess-password">';
    print '<span class="realm">';
    $out .= check_plain($realm->name);
    print ':</span> ';
    print $password;
    print '</div>';
  }
  print '</div>';
}

To find out which realm has granted a user access to a node, then you could do
something like this:

global $user;
$my_realms = array();
foreach ($node->nodeaccess_password as $realm_id => $password) {
  if (strpos($user->nodeaccess_password, $password) !== FALSE) {
    $my_realms[] = $realm_id;
  }
}
// All the realm ids are now stored in the array $my_realms.
// To access realm data use:
// $realm = nodeaccess_password_realm_load($realm_id);