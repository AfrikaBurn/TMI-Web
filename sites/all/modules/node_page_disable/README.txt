##Summary
Allows easy UI access and disabling of the path `/node` when not used.  This was inspired by a security consideration in the [Production Check Module](http://drupal.org/project/prod_check).

##Requirements
1. You only need this module if your front page is other than `/node` AND you do not wish for `/node` to be an active path.


##Installation
1. Download and unzip this module into your modules directory.
1. Goto Administer > Site Building > Modules and enable this module.
2. If your `site_frontpage` is not `/node` then `/node` will be deactivated when this module is enabled.
3. `/node` page visiblity will be returned to its default when you disable this module.


##Configuration
1. Visit `admin/config/system/site-information` and you will find a new checkbox below Default front page called **"Retain /node as an active url?"**
2. After changing your site frontpage from blank or `node`, uncheck this box and the url `/node` will be disabled when you save this form.
2. Disable this checkbox when you frontpage is NOT set to node and it will no longer be available as a valid path

![UI Screenshot](http://drupal.org/files/project-images/itls-screen-046.png)

##Similar Projects
1. [Node Page Admin](http://www.drupal.org/project/node_page_admin)

##Contact
**In the Loft Studios**  
Aaron Klump - Developer  
PO Box 29294 Bellingham, WA 98228-1294  
aim: theloft101  
skype: intheloftstudios  
<http://www.InTheLoftStudios.com>  
