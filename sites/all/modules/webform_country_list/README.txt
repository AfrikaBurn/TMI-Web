PURPOSE OF THIS MODULE
======================

webform_country_list is a simple addon module for the webform module that
defines a new webform component. It is compatible with both, webform version 3
and version 4.

It's a webform component that lets the user select a country out of a list that
you can configure.

To configure, you choose a set of countries (out of the complete list of all
countries) that can be selected. You can also change the order in which they
appear in the select box.

If the PHP PECL package geoip is available and it detects the country of the
visitor, and this country is in the list of available countries,
webform_country_list preselects the geoip country as default.


RELATED MODULES
===============

[countries] https://www.drupal.org/project/countries
[Piped lists of countries] https://www.drupal.org/node/221490


CONFIGURATION
=============

When adding a new component to your webform choose 'Country List' as type.

When editing the component check the 'available' checkbox for all countries that
you want to include in the select box.
By draging and dropping the "cross" sign you can also change the order in which
the countries appear in the select box.

If no country is selected when editing the component, all countries will be
available in the webform.


INSTALLING
==========

Nothing special, if you're using drush that would be

drush dl webform_country_list

drush en webform_country_list -y

You can find more information about installing contributed modules here:
https://www.drupal.org/documentation/install/modules-themes/modules-7

Instructions for installing geoip can be found here:
http://php.net/manual/en/geoip.setup.php.


DEPENDENCIES
============

Hard dependencies:
   * webform (version 3 or 4)

Soft dependencies:
   * geoip
   * form_builder

Indirect dependencies from webform 4:
   * ctools
   * views
