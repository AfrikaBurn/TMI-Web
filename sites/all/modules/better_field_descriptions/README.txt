Readme file for the Better Descriptions module for Drupal
-------------------------------------------------------

Installation:
-------------
 - Extract the files in your module directory (typically sites/all/modules)
 - Visit the modules page and enable the module
 - From the modules page you will find links to
    - permission settings
    - configuration
    - help

How it works:
-------------
Users having the permission 'Administer better field descriptions' will get a
list of all fields across all content types. You can then select which fields
should have a better description.

Users having the permission 'Add a better descriptions to selected fields' can
then add descriptions in a different form for all selected fields.

Both users also need the permission 'Use the administration pages and help'.

Additionally, you can select if the individual description should be placed
above or below the field itself.

You can also provide a label for each description or use a default for all
descriptions.

Descriptions are rendered via a template file. There are two provided with the
module; better-field-descriptions-text and better-field-descriptions-fieldset.

The first provides a simple and clean text, the second wraps the description in
a fieldset using the label as the legend of the fieldset.

You can make your own template and put it in the templates folder of your theme.
The new template will be picked up automatically. Note that changing the
template will trigger a theme registry rebuild.

If you create a template that can be useful for others, please share it in the
issue queue and they might be included in the module with proper attribution.

Known unknowns:
---------------
Better Description has not been thoroughly tested and never on multilingual
sites.

Contact:
--------
Please provide feedback to the issue queue if you have problems, comments,
patches, praise or ideas.
