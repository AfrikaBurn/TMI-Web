node_limit Module

This module allows administrators to limit the number of nodes that users may create.  This limitation may be done on a per-role or per-user basis.

INSTALLATION:

- Put the module in your drupal modules directory and enable it in admin/modules/list.
- Only users with the "administer node limits" permissions will be able to edit node limits.
- The administration page is at admin/structure/node_limit

DETAILS:

- Node limits do not apply to user 1.
- If a user belongs to roles A and B, which have limits of 3 and 4 (respectively), the user will have a node limit of 3.

FUTURE PLANS:

- Allow for time-based node limits (a limit for a certain time period, or a limit that expires on a certain date or after a certain interval)
- Integration with other modules that segregate content, such as Organic Groups

HOOKS FOR SUBMODULES:

See node_limit.api.php
  