-- SUMMARY --
Provides a field type that can reference arbitrary entities.

-- FEATURES --
Module allows you to establish a relation between multiple entity types.

-- ENTITY PROPERTIES & ENTITY METADATA WRAPPERS --
To get all items:
  $wrapper->field_entityreference_multiple->value();
Result:
  array(2) {
    [0]=> array(2) {
      ["target_id"]=> string(1) "1"
      ["target_type"]=> string(4) "bean"
    }
    [1]=> array(2) {
      ["target_id"]=> string(1) "1"
      ["target_type"]=> string(4) "node"
    }
  }

To get first item:
  $wrapper->field_entityreference_multiple[0]->value();
Result:
  array(2) {
    ["target_id"]=> string(1) "1"
    ["target_type"]=> string(4) "bean"
  }

To get loaded entities:
  foreach ($wrapper->field_entityreference_multiple as $item) {
    $item->entity->value();
  }
Result:
  object(Bean) {}
  object(stdClass) {}

To get first loaded entity:
  $wrapper->field_entityreference_multiple[0]->entity->value();
Result:
  object(Bean) {}

To update field's multiple values:
  $items = array();
  $items[] = array('target_id' => 1, 'target_type' => 'node');
  $items[] = array('target_id' => 2, 'target_type' => 'bean');
  $wrapper->field_entityreference_multiple->set($items);

To update field's not-multiple values:
  $items = array();
  $items = array('target_id' => 1, 'target_type' => 'node');
  $wrapper->field_entityreference_multiple->set($items);

-- REQUIREMENTS --
https://www.drupal.org/project/entity

-- CONTACT --
Current maintainer:
* Harbuzau Yauheni - http://drupal.org/user/2123020

-- SPONSORS --
Adyax - http://www.adyax.com/
