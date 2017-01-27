##Summary
A module wrapper integrating [Loft Data Grids](https://github.com/aklump/loft_data_grids) with Drupal.

##Installation

1. Download and unzip this module into your `modules` directory.
1. Now go to Administer > Site Building > Modules and enable this module.

_If you happen to have the [PHPExcel Drupal module](https://drupal.org/project/phpexcel) installed, be aware that this module ignores it and uses it's own dependency code for PHPExcel contained in the `vendor` directory of this module._

### User Permissions: UI Only
Drupal permissions are provided to limit exporter visibility in UI functions only.  The distinction is that any function in this module that provides UI elements (option list, etc) will respect these permissions, however api functions will not.

These permissions can be used globally to remove certain exporters from the UI for any dependent module that uses this module's UI functions.

## Upgrade to 2.x
We have now included the dependencies in the distribution of this module, rather than requiring that [Composer](http://getcomposer.org) be installed on your system to install this module.  This decision was made in an effort to make this a more "turn-key" solution for users not familiar yet with [Composer](http://getcomposer.org).

The 2.x branch no longer uses the [Libraries API](https://drupal.org/project/libraries).

### Required
1. Update the module to the 2.x version.
1. Delete the folder `libraries/loft_data_grids` and all it's contents.

### Optional
1. You may disable [Libraries API](https://drupal.org/project/libraries) if it is not required by any other module.  If unsure, to be safe just leave it alone.
1. Remove all instances of `library_load('loft_data_grids')` from your code, as it is not longer relevant.

##Code Example
To use any of the classes in [Loft Data Grids](https://github.com/aklump/loft_data_grids) in your own module, do something like this:

    <?php
    $data = loft_data_grids_export_data();
    $data->add('first', 'Aaron');
    $data->add('last', 'Klump');
    $output = loft_data_grids_exporter($data, 'CSVExporter')->export();
    ?>
    
Refer to the library for more info.  It also contains Doxygene docs.

##Contact
* **In the Loft Studios**
* Aaron Klump - Developer
* PO Box 29294 Bellingham, WA 98228-1294
* _aim_: theloft101
* _skype_: intheloftstudios
* _d.o_: aklump
* <http://www.InTheLoftStudios.com>

[phpexcel]: https://drupal.org/project/phpexcel