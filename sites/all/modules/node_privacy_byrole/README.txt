
WHAT IT DOES:
-------------
This module allows users, when creating or editing a node, to select
which roles of users on a site will have 'view' permissions for the
node and which users on a site will have 'edit' permissions for the
node.  Roles given edit permissions are automatically given view
permissions even if the user tries to give 'edit' permissions to
a particular role, but not view permissions.

TO INSTALL:
-----------
Drop the node_privacy_byrole directory into the modules directory
of your Drupal installation. In most cases, your modules should be
located at sites/all/modules in your Drupal filesystem structure.

TO ENABLE:
----------
Enable the module as you would any other module at
  Administer > Modules
  location: admin/modules

"View/Edit Permissions" will be a new option when editing nodes.

"Node privacy by role" will be a new fieldset for making default
permissions on specific content types at
  Administer > Content management > Content types
  location: admin/content/types

Managing each content type is where you grant permissions for
roles with rights to update permissions. Without doing this, you
won't see the new "View/Edit Permissions" box when editing nodes as
as a non-superuser account.

TO DISABLE:
-----------
Don't forget to run the Uninstall process after disabling the module:
  Adminster  > Modules > Uninstall tab
  location: admin/modules/uninstall

According to http://drupal.org/node/178903, there are certain instances
where all nodes may loose all permissions when node_privacy_byrole is
disabled in Drupal 5.x. To repair this issue, run
Rebuild permissions at:
  Administer > Content management > Post settings
  location: admin/content/node-settings

Drupal 6 should handle the reversal process automatically.

OTHER NOTES:
------------
If the module is enabled, by-role permissions are set by users for
their nodes, and then the module is disabled, the default permissions
scheme will be in effect again, in which all users have view permissions
for all nodes.

After changing the default options for content types, you can mass
update nodes created before the default permissions change by using
the Rebuild permissions option at
  Administer > Content management > Post settings
  location: admin/content/node-settings
