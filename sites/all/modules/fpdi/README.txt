INSTRUCTIONS
-------------
Download the module.
Download the FPDI PHP library together with the FPDF_TPL library (http://www.setasign.com/products/fpdi/downloads/).
Place them under sites/all/libraries/fpdi so that the file can be found under sites/all/libraries/fpdi/fpdi.php and sites/all/libraries/fpdi/fpdf_tpl.php.
Enable the module.


This module does nothing by itself, it just provides the fpdi library so that other modules can use it.

You can load the library like this:
<?php
libraries_load('fpdi');
?>