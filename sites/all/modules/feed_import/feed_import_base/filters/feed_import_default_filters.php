<?php

/**
 * @file
 * Provides filters for feed import.
 */

/**
 * This class contains default filters for feed import.
 */
class FeedImportFilter {
  /**
   * Removes CDATA
   *
   * @param mixed $field
   *   A string or an array of strings
   *
   * @return mixed
   *   String/Array of strings with no CDATA
   */
  public static function removeCDATA($field) {
    if (is_array($field)) {
      foreach ($field as &$f) {
        $f = self::removeCDATA($f);
      }
      return $field;
    }
    if (!preg_match('/<!\[CDATA\[(.*?)\]\]>/is', $field, $matches)) {
      return $field;
    }
    return isset($matches[1]) ? $matches[1] : $field;
  }

  /**
   * Removes duplicate spaces
   *
   * @param mixed $field
   *   A string or an array of strings
   *
   * @return mixed
   *   Trimmed string/array of strings with no double whitespaces
   */
  public static function removeDoubleSpaces($field) {
    if (is_array($field)) {
      return array_map(array(__CLASS__, __FUNCTION__), $field);
    }
    return trim(preg_replace('@\s+@', ' ', $field));
  }

  /**
   * Splits content by delimiter
   *
   * @param mixed $field
   *   A string or an array of strings
   * @param string $glue
   *   Delimiter
   *
   * @return array
   *   An array containing splitted string
   */
  public static function split($field, $glue = PHP_EOL) {
    if (is_array($field)) {
      foreach ($field as &$f) {
        $f = self::split($f, $glue);
      }
      return $field;
    }
    return explode($glue, $field);
  }

  /**
   * Glue all lines
   *
   * @param mixed $field
   *   An array of strings
   * @param string $glue
   *   Delimiter
   *
   * @return string
   *   Joined string
   */
  public static function join($field, $glue = PHP_EOL) {
    if (is_array($field)) {
      return implode($glue, $field);
    }
    return $field;
  }

  /**
   * Merge all array levels
   *
   * @param array $field
   *   Array to merge
   *
   * @return array
   *   Merged array
   */
  public static function merge($field) {
    if (!is_array($field)) {
      return array($field);
    }
    $merged = array();
    foreach ($field as &$f) {
      if (is_array($f)) {
        $f = self::merge($f);
      }
      else {
        $f = array($f);
      }
      $merged = array_merge($merged, $f);
    }
    return $merged;
  }

/**
   * Set property to array or object
   *
   * @param array|object $field
   *   Where to set property
   *
   * @parem string $property
   *   Property name
   *
   * @param mixed $value
   *   Value of property
   *
   * @return mixed
   *   The field with property set
   */
  public static function setProperty($field, $property = NULL, $value = NULL) {
    if (!empty($property)) {
      if (is_array($field)) {
        $field[$property] = $value;
      }
      elseif (is_object($field)) {
        $field->$property = $value;
      }
    }
    return $field;
  }

  /**
   *
   * Returns first matched property
   *
   * @param mixed $field
   *    The searched vector
   * @param string $...
   *    Variable number of properties
   *
   * @return mixed
   *    Matched property or null
   */
  public static function getProperty($field) {
    $properties = func_get_args();
    array_shift($properties);
    if (!($count = count($properties))) {
      return $field;
    }
    $i = -1;
    if (is_array($field)) {
      while (++$i < $count) {
        if (isset($field[$properties[$i]])) {
          return $field[$properties[$i]];
        }
      }
    }
    elseif (is_object($field)) {
      while (++$i < $count) {
        if (isset($field->{$properties[$i]})) {
          return $field->{$properties[$i]};
        }
      }
    }
    return NULL;
  }

  /**
   * Removes a property
   *
   * @param mixed $field
   *   The field where to remove
   * @param string $property
   *   Property to remove
   *
   * @return mixed
   *   Field without property
   */
  public static function removeProperty($field, $property = NULL) {
    if ($property) {
      if (is_array($field)) {
        unset($field[$property]);
      }
      elseif (is_object($field)) {
        unset($field->{$property});
      }
    }
    return $field;
  }

  /**
   * Call object method
   *
   * @param object $field
   *   Object context
   * @param string $method
   *   Function to call
   *
   * @return mixed
   *   Result of called function
   */
  public static function callMethod($field, $method) {
    $args = func_get_args();
    // Remove $field.
    array_shift($args);
    // Remove $method.
    array_shift($args);
    return call_user_func_array(array($field, $method), $args);
  }

  /**
   * Cast to array.
   *
   * @param mixed $field
   *   What to cast
   *
   * @return array
   *   Resulted array
   */
  public static function toArray($field) {
    if (is_scalar($field)) {
      return array($field);
    }
    return (array) $field;
  }

  /**
   * Cast to object an array
   *
   * @param array $field
   *   The array to cast
   *
   * @return object
   *   Resulted object
   */
  public static function toObject($field) {
    return (object) $field;
  }

  /**
   * Create an object property.
   *
   * @param mixed $field
   *   Value of property.
   * @param string $property
   *   Property name.
   *
   * @return object
   *   Object with specified property.
   */
  public static function toProperty($field, $property = NULL) {
    if ($property) {
      return (object) array(
        $property => $field,
      );
    }
    return $field;
  }

  /**
   * Sets body format.
   *
   * @param mixed $field
   *   Values to set format on.
   * @param string $format
   *   What format to use.
   *
   * @return mixed
   *   Formatted result.
   */
  public static function setTextFormat($field, $format = 'full_html') {
    if (is_array($field)) {
      foreach ($field as &$f) {
        $f = self::setTextFormat($f, $format);
      }
      return $field;
    }
    return (object) array(
      'value' => $field,
      'format' => $format,
    );
  }

  /**
   * Replace content
   *
   * @param mixed $field
   *   Content to replace
   * @paream string $what
   *   String to replace
   * @param string $with
   *   Replace string with
   * @param bool $insensitive
   *   Case insensitive replace
   *
   * @return mixed
   *   Replaced content
   */
  public static function replace($field, $what = '', $with = '', $insensitive = FALSE) {
    if ($insensitive) {
      return str_ireplace($what, $with, $field);
    }
    return str_replace($what, $with, $field);
  }

  /**
   * Check if a string contains specified substring
   *
   * @param string $field
   *    The string to check on
   * @param string $what
   *    The substring
   * @param bool $insensitive
   *    Perform insensitive search
   *
   * @return mixed
   *    Value of $field if TRUE
   */
  public static function contains($field, $what, $insensitive = FALSE) {
    if ($insensitive) {
      return stripos($field, $what) !== FALSE ? $field : NULL;
    }
    return strpos($field, $what) !== FALSE ? $field : NULL;
  }

  /**
   * Check if a string starts with a specified substring
   *
   * @param string $field
   *    The string to check on
   * @param string $what
   *    The substring
   * @param bool $insensitive
   *    Perform insensitive search
   *
   * @return mixed
   *    Value of $field if TRUE
   */
  public static function startsWith($field, $what, $insensitive = FALSE) {
    if ($insensitive) {
      return stripos($field, $what) === 0 ? $field : NULL;
    }
    return strpos($field, $what) === 0 ? $field : NULL;
  }

  /**
   * Check if a string ends with a specified substring
   *
   * @param string $field
   *    The string to check on
   * @param string $what
   *    The substring
   * @param bool $insensitive
   *    Perform insensitive search
   *
   * @return mixed
   *    Value of $field if TRUE
   */
  public static function endsWith($field, $what, $insensitive = FALSE) {
    $len = strlen($field);
    $wlen = strlen($what);
    if ($insensitive) {
      return strripos($field, $what) + $wlen == $len ? $field : NULL;
    }
    return strrpos($field, $what) + $wlen == $len ? $field : NULL;
  }

  /**
   * Append text
   *
   * @param mixed $field
   *   A string or an array of strings
   * @param string $text
   *   Text to append
   *
   * @return mixed
   *   A string or an array of strings with text appended
   */
  public static function append($field, $text) {
    if (is_array($field)) {
      foreach ($field as &$f) {
        $f = self::append($f, $text);
      }
      return $field;
    }
    return $field . $text;
  }

  /**
   * Prepend text
   *
   * @param mixed $field
   *   A string or an array of strings
   * @param string $text
   *   Text to prepend
   *
   * @return mixed
   *   A string or an array of strings with text prepended
   */
  public static function prepend($field, $text) {
    if (is_array($field)) {
      foreach ($field as &$f) {
        $f = self::prepend($f, $text);
      }
      return $field;
    }
    return $text . $field;
  }

  /**
   * Trims a string or an array of strings
   *
   * @param mixed $field
   *   A string or an array of strings
   * @param string $chars
   *   Chars to trim
   *
   * @return mixed
   *   Trimmed string or array of strings
   */
  public static function trim($field, $chars = NULL) {
    if (is_array($field)) {
      foreach ($field as &$f) {
        $f = self::trim($f, $chars);
      }
      return $field;
    }
    return $chars ? trim($field, $chars) : trim($field);
  }

  /**
   * Convert encodings
   *
   * @param mixed $field
   *   A string or an array of strings
   * @param string $to
   *   Convert to encoding
   * @param string $from
   *   Convert from encoding
   *
   * @return mixed
   *   Encoded string or array of strings
   */
  public static function convertEncoding($field, $to = 'UTF-8', $from = 'ISO-8859-1// TRANSLIT') {
    if (is_array($field)) {
      foreach ($field as &$f) {
        $f = self::convertEncoding($f, $to, $from);
      }
      return $field;
    }
    return iconv($from, $to, $field);
  }

  /**
   * Decode html entities
   *
   * @param mixed $field
   *   A string or an array of strings
   *
   * @return mixed
   *   Decoded text
   */
  public static function decodeEntities($field) {
    if (is_array($field)) {
      foreach ($field as &$f) {
        $f = self::decodeEntities($f);
      }
      return $field;
    }
    return decode_entities($field);
  }

  /**
   * Gets vocabulary vid from name
   *
   * @param string $name
   *   Vocabulary name
   *
   * @return int
   *   Vocabulary vid
   */
  public static function getVidFromName($name, $by_machine_name = FALSE) {
    static $vids = array();
    $name = drupal_strtolower($name);
    if (isset($vids[$name])) {
      return $vids[$name];
    }
    $query = new EntityFieldQuery();
    $query = $query->entityCondition('entity_type', 'taxonomy_vocabulary')
                    ->propertyCondition($by_machine_name ? 'machine_name' : 'name', $name)
                    ->execute();
    if (empty($query)) {
      $vids[$name] = 0;
    }
    else {
      $query = reset($query['taxonomy_vocabulary']);
      $vids[$name] = $query->vid;
      unset($query);
    }
    return $vids[$name];
  }

  /**
   * Extract tids by term name and vocabulari id
   *
   * @param mixed $name
   *   A string or an array of strings
   * @param int|string $voc
   *   (optionally) Vocabulary id/name
   *
   * @return mixed
   *   Fetched tids
   */
  public static function getTaxonomyIdByName($name, $voc = 0) {
    if (!is_numeric($voc)) {
      // Get vid from name.
      $voc = self::getVidFromName($voc);
    }

    // Get tids.
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'taxonomy_term');
    $query->propertyCondition('name', $name);
    if ($voc) {
      $query->propertyCondition('vid', $voc);
    }
    $query = $query->execute();
    if (empty($query)) {
      return NULL;
    }
    else {
      return array_keys($query['taxonomy_term']);
    }
  }

  /**
   * Save specified taxonomy terms to vocabulary
   *
   * @param mixed $name
   *   A string or an array of strings
   * @param int|string $voc
   *   (optionally) Vocabulary id/name
   *
   * @return mixed
   *   Fetched and inserted tids
   */
  public static function setTaxonomyTerms($name, $voc = 0) {
    if (!is_numeric($voc)) {
      $voc = self::getVidFromName($voc);
    }
    if (!is_array($name)) {
      $name = array($name);
    }
    $tids = array();
    $existing = self::getTaxonomyIdByName($name, $voc);
    if (!empty($existing)) {
      $existing = taxonomy_term_load_multiple($existing, array('vid' => $voc));
      foreach ($existing as &$term) {
        $tids[drupal_strtolower($term->name)] = $term->tid;
        $term = NULL;
      }
    }
    unset($existing);

    foreach ($name as &$term) {
      $lterm = drupal_strtolower($term);
      if (!isset($tids[$lterm])) {
        $t = new stdClass();
        $t->vid = $voc;
        $t->name = $term;
        taxonomy_term_save($t);
        $tids[$lterm] = $t->tid;
        $t = NULL;
        $term = NULL;
      }
    }
    return $tids;
  }

  /**
   * Strips tags
   *
   * @param mixed $field
   *   A string or an array of strings
   * @param string $tags
   *   Allowed tags
   *
   * @return mixed
   *   Result without tags
   */
  public static function stripTags($field, $tags = '') {
    if (is_array($field)) {
      foreach ($field as &$f) {
        $f = self::stripTags($f, $tags);
      }
      return $field;
    }
    return strip_tags($field, $tags);
  }

  /**
   * Remove tags
   *
   * @param mixed $field
   *   A string or an array of strings
   * @param string $tags
   *   A string containing tags to remove separated by space or array of tags
   *
   * @return mixed
   *   Result without tags
   */
  public static function removeTags($field, $tags) {
    if (!is_array($tags)) {
      $tags = explode(' ', trim($tags));
    }
    if (is_array($field)) {
      foreach ($field as &$f) {
        $f = self::removeTags($f, $tags);
      }
      return $field;
    }
    foreach ($tags as &$tag) {
      $field = preg_replace('@<' . $tag . '( |>).*?</' . $tag . '>@si', '', $field);
    }
    return $field;
  }

  /**
   * Downloads and saves a file in a field
   *
   * @param mixed $field
   *   A string or an array of strings
   * @param string $path
   *   Where to save file. Default is public://
   * @param int $options
   *   Use 0 to rename existing file or 1 to replace it.
   *
   * @return mixed
   *   An object or an array of objects containing file info
   */
  public static function saveFile($field, $path = 'public://', $options = FILE_EXISTS_RENAME) {
    if (is_array($field)) {
      foreach ($field as &$f) {
        $f = self::saveFile($f, $path, $options);
      }
      return $field;
    }
    // Get file data.
    try {
      $image = file_get_contents($field);
    }
    catch (Exception $e) {
      return NULL;
    }
    $field = trim($field, '/');
    $field = drupal_substr($field, strrpos($field, '/') + 1);
    if (file_prepare_directory($path, FILE_CREATE_DIRECTORY | FILE_MODIFY_PERMISSIONS)) {
      return file_save_data($image, $path . $field, (int) $options);
    }
    return NULL;
  }

  /**
   * This is an alis for saveFile() function.
   */
  public static function saveImage($field, $path = 'public://', $options = FILE_EXISTS_RENAME) {
    return self::saveFile($field, $path, $options);
  }

  /**
   * Get only speecified properties
   *
   * @param mixed $field
   *   Array or object to get property
   * @param string $...
   *   Variable number of properties
   *
   * @return mixed
   *   Fetched properties
   */
  public static function getProperties($field) {
    // Get all properties.
    $params = func_get_args();
    // Remove $field.
    array_shift($params);
    // Check for params.
    if (empty($params) || is_scalar($field)) {
      return $field;
    }
    $properties = array();
    if (is_array($field)) {
      foreach ($params as &$param) {
        $properties[$param] = array_key_exists($param, $field) ? $field[$param] : NULL;
      }
    }
    elseif (is_object($field)) {
      foreach ($params as &$param) {
        $properties[$param] = isset($field->{$param}) ? $field->{$param} : NULL;
      }
    }
    if (count($properties) == 1) {
      return reset($properties);
    }
    else {
      return $properties;
    }
  }
  /**
   * This function hashes an user password
   *
   * @param mixed $field
   *   A string or an array of strings
   *
   * @return mixed
   *   Resulted hashes
   */
  public static function userHashPassword($field) {
    static $not_included = TRUE;
    if ($not_included) {
      require_once DRUPAL_ROOT . '/' . variable_get('password_inc', 'includes/password.inc');
      $not_included = FALSE;
    }
    if (is_array($field)) {
      return array_map(array(__CLASS__, __FUNCTION__), $field);
    }
    return user_hash_password($field);
  }

  /**
   * Gets the current prefiltered value.
   *
   * @param mixed $default
   *    Default value to return if no import
   *
   * @return mixed
   *    Prefiltered value
   */
  public static function usePrefilteredValue($default = NULL) {
    if (FeedImport::$activeImport) {
      return FeedImport::$activeImport->prefilteredValue;
    }
    return $default;
  }

  /**
   * Gets the current entity.
   *
   * @return mixed
   *    Prefiltered value
   */
  public static function &getCurrentEntity() {
    if (FeedImport::$activeImport) {
      return FeedImport::$activeImport->current;
    }
    $ret = NULL;
    return $ret;
  }

  /**
   * Returns false if field doesn't match regex.
   */
  public static function regexMatches($field, $regex) {
    if (is_array($field)) {
      foreach ($field as $f) {
        if (!preg_match($regex, $f)) {
          return FALSE;
        }
      }
      return $field;
    }
    return preg_match($regex, $field) ? $field : FALSE;
  }

  /**
   * Returns false if field matches regex.
   */
  public static function regexNotMatches($field, $regex) {
    if (($f = static::regexMatches($field, $regex)) === FALSE) {
      return $f;
    }
    return FALSE;
  }

  /**
   * Performs a regex replace.
   */
  public static function regexReplace($field, $regex, $new) {
    return preg_replace($regex, $new, $field);
  }

  /**
   * Returns the matchd groups of regex
   */
  public static function regex($field, $regex, $remove_indexes = FALSE) {
    if (is_array($field)) {
      foreach ($field as $key => &$f) {
        if (preg_match($regex, $f, $m)) {
          if ($remove_indexes) {
            $i = -1;
            while (isset($m[++$i])) {
              unset($m[$i]);
            }
          }
          else {
            array_shift($m);
          }
          $f = $m;
        }
        else {
          unset($field[$key]);
        }
      }
      return $field ? $field : NULL;
    }
    if (preg_match($regex, $field, $m)) {
      if ($remove_indexes) {
        $i = -1;
        while (isset($m[++$i])) {
          unset($m[$i]);
        }
      }
      else {
        array_shift($m);
      }
      return $m;
    }
    return NULL;
  }
}


/**
 * Implodes all arguments.
 */
function feed_import_implode() {
  $args = func_get_args();
  return implode(array_shift($args), $args);
}
