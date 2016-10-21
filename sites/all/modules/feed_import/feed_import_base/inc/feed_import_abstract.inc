<?php

/**
 * @file
 * This file contains abstract classes and interfaces for feed import.
 */


/**
 * This class provides methods to set options.
 */
abstract class FeedImportConfigurable {

  // Class options
  protected $options = array();

  /**
   * Sets options for this instance
   *
   * @param array $options
   *    An assoc array containig options
   * @param bool $overwrite
   *    TRUE if the options should pe overwritten, FALSE to merge them
   */
  public function setOptions(array $options, $overwrite = FALSE) {
    if ($overwrite) {
      $this->options = $options;
    }
    else {
      $this->options = $options + $this->options;
    }
  }

  /**
   * Helper function to get lines of a string
   *
   * @param string $str
   *    The string to get non empty lines from
   *
   * @return array
   *    An array of strings
   */
  public static function cleanLines($str) {
    return preg_split('/\r?\n/', $str);
  }
}


/**
 * Abstract implementation of reader.
 */
abstract class FeedImportReader extends FeedImportConfigurable {

  // Used to store items.
  protected $items = array();

  /**
   * Constructor of reader. Constructor is final but you'll have to
   * implement init() to init your reader.
   *
   * @param array $options An array of options to pass to reader
   */
  final public function __construct(array $options = array()) {
    $this->setOptions($options);
  }

  /**
   * Destructor.
   */
  public function __destruct() {
    unset($this->items, $this->options);
  }

  /**
   * Here you'll init your reader.
   */
  abstract public function init();

  /**
   * This method returns the next available item or NULL if there are no items
   * left.
   *
   * @return mixed The read item
   */
  abstract public function get();

  /**
   * Returns a value mapped from obj by path.
   *
   * @param mixed $obj  Variable to search
   * @param mixed $path Path to value
   *
   * @return mixed Mapped value
   */
  abstract public function map(&$obj, &$path);

  /**
   * Override this to preprocess your paths before they are used in map().
   *
   * @param string $path Path to format
   *
   * @return mixed Formatted path
   */
  public function formatPath($path) {
    return $path;
  }

  /**
   * Returns a stream context
   *
   * @param mixed $ctx
   *    Context options
   *
   * @return resource
   *    Stream context or NULL on failure
   */
  public function getStreamContext($ctx) {
    if ($ctx && (
      is_array($ctx) ||
      (is_scalar($ctx) && ($ctx = json_decode($ctx, TRUE)))
      )) {
      return stream_context_create($ctx);
    }
    return NULL;
  }

}


/**
 * This class is a helper for xpath readers using SimpleXMLElement.
 */
abstract class FeedImportSimpleXPathReader extends FeedImportReader {

  /**
   * {@inheritdoc}
   */
  public function map(&$item, &$xpath) {
    // Get values and handle xpath exceptions.
    try {
      $values = $item->xpath($xpath);
    }
    catch (Exception $e) {
      return NULL;
    }

    // Xpath gave no values return null.
    if (!$values) {
      return NULL;
    }

    // Get the number of values.
    $count = count($values);
    $i = -1;
    while (++$i < $count) {
      // Get each value.
      $values[$i] = (string) $values[$i][0];
    }

    // Return values.
    return $count == 1 ? $values[0] : $values;
  }

}

/**
 * This class provides a helper for dom xpath queries.
 */
abstract class FeedImportDomXPathReader extends FeedImportReader {

  // DomXPath instance
  protected $xpath;

  // Bool, see DomXPath::evaluate
  protected $xpathRegisterNodeNS = TRUE;

  /**
   * {@inheritdoc}
   */
  public function map(&$item, &$path) {
    $values = $this->xpath->evaluate($path, $item, $this->xpathRegisterNodeNS);
    if ($values instanceof DOMNodeList) {
      if (!($len = $values->length)) {
        return NULL;
      }
      elseif ($len == 1) {
        return $values->item(0)->nodeValue;
      }
      $i = 0;
      $ret = array();
      while ($i < $len) {
        $ret[] = $values->item($i++)->nodeValue;
      }
      return $ret;
    }
    return $values;
  }

}



/**
 * This class is a helper for vector (n dimensions) reader.
 * Path format is like a/b/c which results in [a, b, c] array.
 */
abstract class FeedImportVectorReader extends FeedImportReader {

  const WILDCARD = '*';
  
  /**
   * {@inheritdoc}
   */
  public function map(&$vector, &$path) {
    $ret = array();
    $count = 0;
    foreach ($path as $p) {
      if (($p = $this->submap($vector, $p)) !== NULL) {
        if ($p instanceof ArrayObject) {
          $ret = array_merge($ret, $p->getArrayCopy());
          $count += count($p);
        }
        else {
          $ret[] = $p;
          $count++;
        }
      }
    }
    return $count == 0 ? NULL : ($count == 1 ? $ret[0] : $ret);
  }

  /**
   * Gets an element by path.
   *
   * @param mixed $vector
   *    The vector to search
   * @param array $path
   *    Path parts
   * @param int $index
   *    Path index
   *
   * @return mixed
   *    Found value or NULL
   */
  public function submap(&$vector, &$path, $index = 0) {
    while (isset($path[$index])) {
      $p = &$path[$index++];
      if ($p == static::WILDCARD) {
        if (is_scalar($vector)) {
          return NULL;
        }
        $result = new ArrayObject();
        foreach ($vector as &$value) {
          if (($res = $this->submap($value, $path, $index)) !== NULL) {
            if ($res instanceof ArrayObject) {
              foreach ($res as &$r) {
                $result[] = $r;
              }
              unset($r);
            }
            else {
              $result[] = $res;
            }
          }
          unset($res);
        }
        return $result ? $result : NULL;
      }
      elseif (is_array($vector)) {
        if (isset($vector[$p])) {
          $vector = &$vector[$p];
          continue;
        }
      }
      elseif (is_object($vector)) {
        if (isset($vector->$p)) {
          $vector = &$vector->$p;
          continue;
        }
      }
      return NULL;
    }
    return $vector;
  }

  /**
   * {@inheritdoc}
   */
  public function formatPath($path) {
    $path = preg_split('/(\s?\|\s?)/', $path, -1, PREG_SPLIT_NO_EMPTY);
    foreach ($path as &$p) {
      $p = explode('/', $p);
    }
    return $path;
  }
}


/**
 * This class is a helper for unidimensional vector reader.
 * This can be used for CSV, SQL results, etc.
 */
abstract class FeedImportUniVectorReader extends FeedImportReader {

  /**
   * {@inheritdoc}
   */
  public function map(&$vector, &$path) {
    if (is_array($vector)) {
      $count = 0;
      $ret = array();
      foreach ($path as $p) {
        if (isset($vector[$p])) {
          $ret[] = $vector[$p];
          $count++;
        }
      }
      return $count == 0 ? NULL : ($count == 1 ? $ret[0] : $ret);
    }
    elseif (is_object($vector)) {
      $count = 0;
      $ret = array();
      foreach ($path as $p) {
        if (isset($vector->$p)) {
          $ret[] = $vector->$p;
          $count++;
        }
      }
      return $count == 0 ? NULL : ($count == 1 ? $ret[0] : $ret);
    }
    return NULL;
  }

  /**
   * {@inheritdoc}
   */
  public function formatPath($path) {
    return preg_split('/(\s?\|\s?)/', $path, -1, PREG_SPLIT_NO_EMPTY);
  }

}

/**
 * Static methods for hash manager
 */
interface FeedImportStaticHashManager {

  /**
   * Deletes hashes from database.
   *
   * @param array $ids
   *    Hash ids to delete
   */
  public static function delete(array $ids);

  /**
   * Deletes entities by type and id
   *
   * @param int|array $ids
   *    Entity ids
   * @param string $entity_type
   *    Entity type
   */
  public static function deleteEntities($ids, $entity_type);

  /**
   * Deletes all hashes of specified group
   *
   * @param string $group
   *    Group name
   */
  public static function deleteByGroup($group);

  /**
   * Deletes all hashes for specified feed name
   *
   * @param string $name
   *    Feed machine name
   */
  public static function deleteByFeed($name);

  /**
   * Returns an array of expired entity ids keyed by entity name
   *
   * @param string $name
   *    Feed machine name
   * @param int $max
   *    Max number of ids or 0 for all
   * @return array
   *    An array of expired items. Format:
   *    entity_name:
   *      hash_id: enity_id
   */
  public static function getExpired($name, $max = 0);

  /**
   * Reschedules all entities
   *
   * @param string $name
   *    Feed machine name
   * @param int $ttl
   *    Time to live
   */
  public static function rescheduleAll($name, $ttl);

  /**
   * Returns total number of hashes for desired feeds.
   *
   * @param mixed $name
   *    The feed machine name (array for multiple) or NULL for all.
   * @return mixed $name
   *    Number of hashes (groupped by name for multiple)
   */
  public static function totalHashes($name = NULL);

}

/**
 * Class which provides methods to manage hashes.
 */
abstract class FeedImportHashManager extends FeedImportConfigurable implements FeedImportStaticHashManager {

  // Expire entities.
  protected $ttl = 0;

  // Generated hashes.
  protected $generatedHashes = array();

  // Item is marked as protected for updates.
  const MARK_PROTECTED = 1;

  /**
   * Constructor.
   */
  abstract public function __construct($entity_name, $feed_machine_name);

  /**
   * Returns an array of entity keyed by hash,
   * using generated hashes.
   *
   * @return array
   *     An array containing entity ids keyed by hash.
   */
  abstract public function get();

  /**
   * Inserts a new hash.
   *
   * @param integer $id
   *     Entity id
   * @param mixed $hash
   *     Unique hash coresponding to entity id
   * @param int $expire
   *     Time to live
   */
  abstract public function insert($id, $hash);

  /**
   * Commits the insert to storage.
   */
  abstract public function insertCommit();

  /**
   * Updates hashes.
   *
   * @param integer $id
   *     Hash id
   * @param int $expire
   *     Time to live
   */
  abstract public function update($id);

  /**
   * Protects a hash for updates
   *
   * @param integer $id
   *    Hash id
   */
  abstract public function protect($id);

  /**
   * Commits the update to storage.
   */
  abstract public function updateCommit();

  /**
   * Creates a hash, based on uniq
   * Also adds it on generated hashes
   *
   * @param mixed $uniq
   *     Unique identifier.
   *
   * @return string
   *     A hash for specified identifier.
   */
  abstract public function hash(&$uniq);

}

/**
 * Abstract class that helps merging fields on update.
 */
abstract class FeedImportMergeField {
  
  /**
   * Remove field if is missing from source.
   *
   * @return bool
   *    True to overwrite
   */
  public function overwriteEmpty() {
    return FALSE;
  }
  
  /**
   * Merge the new and current field values.
   * The merge should be set in $current ref. variable
   *
   * @param array $current
   *    Current field values
   * @param array $new
   *    New field values
   * @param array $field
   *    Field info
   *      cardinality - field cardinality
   *      compare - compare function for field value
   *
   * @return bool
   *    True if $current was changed
   */
  abstract public function merge(array &$current, array &$new, array &$field);
  
}
