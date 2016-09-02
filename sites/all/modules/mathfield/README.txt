Math Field
Author: draenen <https://www.drupal.org/u/draenen>

REQUIREMENTS
------------

This module requires the following modules:
 * Field (core)
 * cTools (https://www.drupal.org/project/ctools)

DESCRIPTION
------------

The Math Field module defines a new field type to dynamically calculate values
on entity forms. This is an alternative to Computed Field
(https://www.drupal.org/project/computed_field) that does not require the use of
PHP Filter.

Math fields are dynamically updated via ajax on the entity form as soon as all
necessary fields are populated. If JavaScript is disabled, the field will be
evaluated when the form is submitted. The result is stored in the database.

Math Field uses the cTools math expression library and supports all the basic
operators (+-*/^) as well as constants 'pi' and 'e' and the following functions:
  sin, sinh, arcsin, asin, arcsinh, asinh,
  cos, cosh, arccos, acos, arccosh, acosh,
  tan, tanh, arctan, atan, arctanh, atanh,
  pow, exp, sqrt, abs, ln, log, time, ceil,
  floor, min, max, round

You can also define and evaluate your own functions separated by a ';'. For
example:

f(x) = x + 2; f(3)

Other fields may be included in math expressions using tokens with the form
[$field_name:$delta:$column] where $field_name is the machine name of a
supported field, $delta is the index for multivalue fields ($delta begins with
0), and $column is the column name for multicolumn fields. $delta and/or
$column may be omitted if the field only has one value or column respectively.

Out of the box, Math Field supports the following numeric field types:

  * Integer and List (integer)
  * Float and List (float)

Modules that define fields may add support for Math Field by implementing
hook_mathfield_get_token() and hook_mathfield_get_token_value().


KNOWN ISSUES
-------------

The cTools math expression library causes an error when using function that take
more than one parameter. This effects pow(), min(), max().
See https://www.drupal.org/node/1958538.

Math Field does not yet support multivalue options fields (checkboxes, or
multiselect). See https://www.drupal.org/node/2483453.
