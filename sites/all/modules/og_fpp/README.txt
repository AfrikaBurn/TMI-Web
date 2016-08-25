This is a bridge module to ease simultaneous usage of Organic Groups, Fieldable
Panel Panels and Panelizer. Panelizer is not a technical dependency for this
module though it is involved in the most likely use case.

USE CASE

-A University uses Organic Groups to segment content by academic department. So
"Chemistry Department" and "English Department" are group nodes.
-Panelizer is used to custom layouts on a node by node basis.
-Departments used Fieldable Panel Panes to common sidebar elements like
"Chemistry Department's quick links"
-Because Fieldable Panel Panes are an entity type they can belong to an Organic
Group. So the "Chemistry Department's quick links" pane can be designated as
belonging to the Chemistry group.
-Fieldable Pane Panels can be reusable so they show up in the CTools modal that
lists available panes when panelizing a node.
-This module filters the list of available Fieldable Panel Panes in the CTools
modal based on the Organic Group of the node being panelized and the Organic
Groups of the individual Fieldable Panel Panes.


SPONSORSHIP

Development of this module was sponsored by Palantir.net and California State
University Northridge.


COMPATIBILITY

This module was written for the 2.x branch of Organic Groups and the 3.x branch
of Panelizer. There may be compatibility issues with other versions. The example
feature module was created with the 2.x branch of Features module.


TESTING THIS MODULE WITH THE EXAMPLE FEATURE

-Install clean instance of Drupal 7.
-Install the 2.x branch of Features module.
-Install the 3.x branch of Panelizer and the 2.x branch of Organic Groups.
-Other dependent modules do not have version requirements and will be downloaded
as needed by running "drush en og_fpp_example"
-Create example content
---Create group nodes
-----One titled "English Department"
-----One titled "Chemistry Department"
---Create page nodes
-----One titled "English Department Landing Page"
-----One titled "Chemistry Department Landing Page"
-----Select the appropriate organic group for both page nodes.
---Create Two Fieldable Panel Panes
-----One title "English Department Sidebar Blurb"
-----One title "Chemistry Department Sidebar Blurb"
-----Use the same title for the "Administrative title" field
-----Select the appropriate organic group for both panes.
-----Use "Fieldable Panel Panes" as the category.
-Go to the Panelizer setting for the English Department Landing Page. If you
have created the nodes in the order listed above, the URL will be
/node/3/panelizer/page_manager/content
---Click to add a pane to this layout.
---Click on the Fieldable Panel Panes category
---Verify that "English Department Sidebar Blurb" is present.
---Verify that "Chemistry Department Sidebar Blurb" is not present.
-Disable the og_fpp module.
---Visit the same page and Verify that both "blurb" panes are present.
