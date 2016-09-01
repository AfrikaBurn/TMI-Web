This document is a work in progress.

TECHNICAL OVERVIEW
Livethemer watches for the use of certain theme hooks when rendering a page (eg block, page, comment etc). When Drupal's theme engine renders one of these, Livethemer stores the args sent to the theme_hook() function in question, so it can later regenerate the same theme hook but with a different *.tpl.php file.

The Javascript UI allows a user to dynamically select from the variations available for each of these theme hooks, thereby allowing to assign specific *.tpl.php templates to specific objects on the page.

Further, variations may also (or only) contain css or javascript. If there is only a css or js addition, the markup for the object is not regenerated; the css or js is dynamically added to the dom and a unique class is added to the object on the page.



There are some concepts used throughout the Livethemer module which bear more detailed explanation.

================================================================
VARIATIONS
Each variation provides a modification to the style or behaviour of an
object on the page, or of the page itself. The elements available for
modification are defined by the "themable objects" described below.

A variation is a collection of files, of which only the .inc file is 
mandatory. Together these files provide information which Livethemer uses 
to modify the page. These files are:

variation-filename.livethemer.inc
- contains a hook-like function which describes one or more variations to Livethemer. This function name must begin with the same name as the beginning of this include file ie "variation-filename" in this example. The function returns an array as  in the following example:

  $variations['block_var1a'] = array(     // block_var1a is the unique Id for this variation
    'template_file' => 'block-var1',      // This is the name of the theme template file (tpl.php) being exposed to live-themer.
    'type' => 'block',                    // The themable object for which this is a variation. Only one variation will be allowed per themable object
    'form' => $form,                      // Optionally, a FAPI form can be provided, allowing direct user customisation of tpl variables
    'title' => t('Block variation 1a'),   // The title helps the user identify this variation.
    'description' => t('Block with interesting variation'), // The description helps the user identify this variation.
    'keywords' => 'blue, retro, natural', // The keywords help the user identify this variation.
    'thumbnail' => 'block-var1a.png',     // The thumbnail helps the user identify this variation.
    'css' => 'block-var1',                // Every rule in this stylesheet MUST be prefixed with a class based on this variation's unique Id. In this example the class is: .variation-block_var1a
    'js' => '',                           // This javascript should only act on a DOM object (or objects it contains) where the object has a class as per the css class above. If using jQuery, this will look something like $('.variation-block_var1a').yourCodeHere
  );


variation-filename.tpl.php

variation-filename.png

variation-filename.css

variation-filename.js


================================================================
THEMABLE OBJECTS
Themable objects describe different categories of variations which may be applied. Each themable object is described by an .inc file which tells Livethemer which Drupal theme hook relates to the themable object, what scopes are available for the themable object, and various other descriptive information about the themable object.


================================================================
SCOPES
