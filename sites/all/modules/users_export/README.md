##Summary:
Allows admins to export users in several different formats included Excel, CSV and XML. Also adds a handy screen to help locate users by email or username.


##Installation
1. Download and unzip this module into your modules directory. **Do not enable this module until you have downloaded the dependencies.**
1. **DEPENDENCY 1**: Download, unzip and rename the wrapper module [Drupal Loft Data Grids][drupal_loft_data_grids] as `sites/modules/contrib/drupal_loft_data_grids`.  If you've not downloaded from GitHub before, you will find a button called `Download ZIP` in a side column; click that button to get the module files.  
1. **DEPENDENCY 2**: Review the installation options in the [README][read_me] and then follow the installation instructions to install [Loft Data Grids Library][loft_data_grids].
1. Goto Administer > Site Building > Modules and enable this module.


##Upgrade from 1.1 to 2.x
The 2.x branch of this module uses a library called [Loft Data Grids] [loft_data_grids], while the 1.x branch did not.  Therefore to upgrade from 1.x to 2.x you will need to download these two additional items:

1. The library itself: [Loft Data Grids Library] [loft_data_grids]
2. And a Drupal wrapper for the library: [Drupal Loft Data Grids][drupal_loft_data_grids]
3. **Please read carefully, the `README` file found in the wrapper module regarding installation of dependencies.**  This is paramount if you are wanting to have support for Excel exporting!
4. Make sure `loft_data_grids` Drupal module is enabled before continuing!
4. Finally, run `update.php` to complete the upgrade to 2.x.


##Configuration:
* The functions of this module are given to users with the correct permissions.  You can enable per-file-format permissions to user roles.


##Exporting:
* Visit `admin/people/export`, adjust your settings and click Download File.

## Troubleshooting:

Large user counts will try to consume a good deal of memory and may exceed the PHP maximum execution time.  In the advanced settings on the export form, you may attempt to increase both of these values, but their efficacy is dependent upon the security settings of your server.  You may have to alter these values at the server level if you continue to have export problems with large numbers of users.

*To test this you should enable the test mode and you will get a file of 10 users.  If this works, but when unchecked, the export fails, you are most likely running into limits of either memory or time.*

##Searching:
* Visit `admin/people/find`, enter search criteria and submit the form.


##API:
* Refer to `users_export.api.php` for api functions and hooks.


##Contact
* **In the Loft Studios**
* Aaron Klump - Developer
* PO Box 29294 Bellingham, WA 98228-1294
* _aim_: theloft101
* _skype_: intheloftstudios
* _d.o_: aklump
* <http://www.InTheLoftStudios.com>

[drupal_loft_data_grids]: https://github.com/aklump/drupal_loft_data_grids
[loft_data_grids]: https://github.com/aklump/loft_data_grids
[read_me]: https://github.com/aklump/drupal_loft_data_grids/blob/7.x-1.x/README.md#important--please-read-regarding-dependencies