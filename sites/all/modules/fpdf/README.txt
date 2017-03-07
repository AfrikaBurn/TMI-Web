INSTRUCTIONS
-------------
Download the module.
Download the fpdf php library (http://www.fpdf.org/).
Place it under sites/all/libraries/fpdf so that the file can be found under sites/all/libraries/fpdf/fpdf.php.
Enable the module.


This module does nothing by itself, it just provides the fpdf library so that other modules can use it.

You can load the library like this:
<?php
libraries_load('fpdf');
?>