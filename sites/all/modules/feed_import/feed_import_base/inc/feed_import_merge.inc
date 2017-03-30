<?php

/**
 * @file
 * This file contains Feed Import field merge methods.
 */

/**
 * Class which merges field values checking for duplicates.
 * Default merge mode.
 */
class FeedImportMergeNoDuplicates extends FeedImportMergeField {
  
  /**
   * {@inheritdoc}
   */
  public function merge(array &$current, array &$new, array &$field) {
    $changed = FALSE;
    $cnt = count($new);
    if ($cnt == count($current)) {
      // Same number of items, it is possible that the
      // field is still the same
      // Just check if the items are the same.
      for ($i = 0; $i < $cnt; $i++) {
        if (!$field['compare']($new[$i], $current[$i])) {
          $changed = TRUE;
          break;
        }
      }
    }
    else {
      // Different number of items, the field is 100% changed.
      $changed = TRUE;
    }
    
    if ($changed) {
      // Get the new field values, but try to copy the existing ones.
      $temp = array();
      for ($i = 0; $i < $cnt; $i++) {
        $not_found = TRUE;
        foreach ($current as $key => &$val)  {
          // Compare by function.
          if ($field['compare']($new[$i], $val)) {
            // Value is the same, just get a reference.
            $temp[] = &$val;
            $not_found = FALSE;
            break;
          }
        }
        unset($val);
        if ($not_found) {
          // The value is new.
          $temp[] = &$new[$i];
        }
      }
      // Set current.
      $current = $temp;
    }
    
    return $changed;
  }
  
}

/**
 * Class which merges field values without checking for duplicates.
 */
class FeedImportMergeDuplicates extends FeedImportMergeField {
  
  /**
   * {@inheritdoc}
   */
  public function merge(array &$current, array &$new, array &$field) {
    if ($field['cardinality'] == -1) {
      $current = array_merge($current, $new);
      return TRUE;
    }
    elseif (($cnt = count($current)) < $field['cardinality']) {
      $cnt = $field['cardinality'] - $cnt;
      $current = array_merge($current, count($new) <= $cnt ? $new : array_slice($new, 0, $cnt));
      return TRUE;
    }
    return FALSE;
  }
  
}

/**
 * Class which overwrites values. A simple value by value comparison is made.
 * This also overwrites values if missing from source.
 */
class FeedImportMergeOverwrite extends FeedImportMergeField {
  
  /**
   * {@inheritdoc}
   */
  public function overwriteEmpty() {
    return TRUE;
  }
  
  /**
   * {@inheritdoc}
   */
  public function merge(array &$current, array &$new, array &$field) {
    $cnt = count($new);
    if ($cnt != count($current)) {
      // Different number of values.
      $current = $new;
      return TRUE;
    }

    // Same number of values. Might be the same.
    $changed = FALSE;
    for ($i = 0; $i < $cnt; $i++) {
      if (!$field['compare']($new[$i], $current[$i])) {
        $current[$i] = $new[$i];
        $changed = TRUE;
      }
    }
    return $changed;
  }
  
}

/**
 * This class just overwrites values without any checks.
 * Does not overwrites values if are missing from source.
 */
class FeedImportMergeOverwriteFast extends FeedImportMergeField {
  
  /**
   * {@inheritdoc}
   */
  public function merge(array &$current, array &$new, array &$field) {
    $current = $new;
    return TRUE;
  }
  
}
