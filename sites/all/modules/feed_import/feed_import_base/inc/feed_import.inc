<?php

/**
 * @file
 * This file contains Feed Import helpers.
 */

/**
 * This class provides helper functions for feed import.
 */
class FeedImport {

  // Constants
  const FEED_OK = 1;
  const FEED_SOURCE_ERR = 2;
  const FEED_ITEMS_ERR = 3;
  const FEED_OVERLAP_ERR = 4;
  const FEED_CONFIG_ERR = 5;

  // Entity info cache.
  protected static $entityInfo = array();
  
  // Default compare function.
  

  /**
   * Gets info about an entity.
   * This info is cached.
   *
   * @param string $entity_name The entity name
   *
   * @return object An object that describes entity
   */
  public static function getEntityInfo($entity_name) {
    if (empty($entity_name)) {
      return FALSE;
    }
    elseif (isset(static::$entityInfo[$entity_name])) {
      return static::$entityInfo[$entity_name];
    }

    if (!($entity = entity_get_info($entity_name))) {
      return FALSE;
    }

    // Set main entity info.
    $info = (object) array(
      'name' => $entity_name,
      'idKey' => isset($entity['entity keys']['id']) ?
                    $entity['entity keys']['id'] : NULL,
      'langKey' => isset($entity['entity keys']['language']) ?
                    $entity['entity keys']['language'] : 'language',
      'bundleKey' => isset($entity['entity keys']['bundle']) ?
                    $entity['entity keys']['bundle'] : NULL,
      'createCallback' => isset($entity['creation callback']) ?
                          $entity['creation callback'] : NULL,
      'saveCallback' => isset($entity['save callback']) ?
                          $entity['save callback'] : NULL,
      'deleteCallback' => isset($entity['deletion callback']) ?
                            $entity['deletion callback'] : NULL,
      'controller' => entity_get_controller($entity_name),
      'properties' => array(),
      'fields' => array(),
    );
    
    if ($info->controller) {
      $info->controller->canCreate = method_exists($info->controller, 'create');
      $info->controller->canSave = method_exists($info->controller, 'save');
      $info->controller->canDelete = method_exists($info->controller, 'delete');
      $info->controller->canResetCache = method_exists($info->controller, 'resetCache');
    }
    else {
      $info->controller = (object) array(
        'canCreate' => FALSE,
        'canSave' => FALSE,
        'canDelete' => FALSE,
        'canResetCache' => FALSE,
      );
    }
    
    if (!$info->saveCallback && function_exists($entity_name . '_save')) {
      $info->saveCallback = $entity_name . '_save';
    }

    if (!$info->deleteCallback && function_exists($entity_name . '_delete')) {
      $info->deleteCallback = $entity_name . '_delete';
    }

    // Get fields info.
    if ($fieldlist = field_info_instances($entity_name)) {
      foreach ($fieldlist as &$fields) {
        foreach ($fields as &$field) {
          if (!empty($field['deleted']) || isset($info->fields[$field['field_name']])) {
            continue;
          }
          $field_info = field_info_field($field['field_name']);
          $info->fields[$field['field_name']] = array(
            'name' => $field['field_name'],
            'column' => key($field_info['columns']),
            'columns' => array_keys($field_info['columns']),
            'cardinality' => $field_info['cardinality'],
            'type' => $field_info['type'],
            'module' => $field_info['module'],
          );
        }
      }
    }

    if (function_exists('entity_get_property_info')) {
      // Get properties info.
      $prop_info = entity_get_property_info($entity_name);
      if (isset($prop_info['properties'])) {
        foreach ($prop_info['properties'] as $pname => $pval) {
          if (isset($pval['schema field'])) {
            $pval = $pval['schema field'];
          }
          else {
            $pval = $pname;
          }
          if (!isset($info->fields[$pval])) {
            $info->properties[] = $pval;
          }
        }
        $info->properties = array_unique($info->properties);
      }
    }
    elseif (isset($entity['schema_fields_sql']['base table'])) {
      $info->properties = array_diff(
        $entity['schema_fields_sql']['base table'],
        array_keys($info->fields)
      );
    }

    return static::$entityInfo[$entity_name] = $info;
  }

  /**
   * Cache used for entity names.
   */
  protected static $entityNames = array();

  /**
   * Get all entity names.
   *
   * @return array
   *    List of all entity names.
   */
  public static function getAllEntities() {
    if (!static::$entityNames) {
      foreach (entity_get_info() as $entity => $info) {
        static::$entityNames[$entity] = $info['label'];
      }
    }
    return static::$entityNames;
  }

  // Default field compare function.
  public static $defaultFieldCompareFunction = '_feed_import_base_compare_other_fields';

  /**
   * Sets processor settings.
   *
   * @param FeedImportProcessor $fi
   *    The processor
   * @param object $feed
   *     Feed settings
   * @param string $filter_dir
   *     Path to extra filters dir
   *
   * @return FeedImportProcessor
   *     An instance of FeedImportProcessor or FALSE on error
   */
  public static function setProcessorSettings(FeedImportProcessor $fi, $feed, $filter_dir) {
    $s = $feed->settings;

    $ok = TRUE;
    $ok = $ok && $fi->setEntityInfo(static::getEntityInfo($feed->entity));
    $ok = $ok && $fi->setOptions($s['processor']['options']);
    if (!isset($s['functions'])) {
      $s['functions'] = NULL;
    }
    $ok = $ok && $fi->setFilter(
      new $s['filter']['class']($filter_dir, $s['filter']['options']),
      $s['functions']
    );
    $ok = $ok && $fi->setReader(new $s['reader']['class']($s['reader']['options']));

    $hm = new $s['hashes']['class']($feed->entity, $feed->machine_name);
    $hm->setOptions($s['hashes']['options']);

    $ok = $ok && $fi->setHashManager($hm);
    $ok = $ok && $fi->setUniq($s['uniq_path']);
    $ok = $ok && $fi->setFields($s['fields'], $s['static_fields'],
                                static::getFieldsCompareFunctions(),
                                static::getMergeFieldClasses(),
                                static::$defaultFieldCompareFunction);

    $ok = $ok && $fi->setCustomSettings(array_diff_key($s, array(
      'uniq_path' => 1, 'processor' => 1, 'reader' => 1, 'hashes' => 1,
      'filter' => 1, 'fields' => 1, 'static_fields' => 1, 'feed' => 1,
      'functions' => 1,
    )));

    return $ok ? TRUE : $fi->getErrors();
  }
  
  /**
   * Returns field compare functions.
   */
  public static function getFieldsCompareFunctions() {
    $funcs = module_invoke_all('feed_import_field_compare_functions');
    foreach ($funcs as $type => &$f) {
      if (is_array($f)) {
        for ($i = 0, $max = count($f); $i < $max; $i++) {
          if (is_callable($f[$i]))  {
            $f = $f[$i];
            continue 2;
          }
        }
        unset($funcs[$type]);
      }
      elseif (!is_callable($f)) {
        unset($funcs[$type]); 
      }
    }
    return $funcs;
  }

  /**
   * Gets the classes used to merge field values.
   *
   * @return array
   *    An array of classes keyed by merge mode.
   */
  public static function getMergeFieldClasses() {
    $classes = module_invoke_all('feed_import_field_merge_classes');
    foreach ($classes as $key => &$class) {
      if (isset($class['class'])) {
        $class = $class['class'];
      }
      else {
        unset($classes[$key]);
      }
    }
    return $classes;
  }

  // A list of all feeds configuration.
  protected static $feedsList = array();

  /**
   * Get a list with all feeds.
   */
  public static function loadAllFeeds() {
    if (static::$feedsList) {
      return static::$feedsList;
    }
    $feeds = db_select('feed_import_settings', 'f')
            ->fields('f')
            ->orderBy('id', 'DESC')
            ->execute()
            ->fetchAll();
    $ret = array();
    foreach ($feeds as &$feed) {
      $feed->settings = unserialize($feed->settings);
      $ret[$feed->machine_name] = $feed;
    }
    return static::$feedsList = $ret;
  }

  /**
   * Loads a feed from database
   *
   * @param int|string $name
   *    Feed machine name or id
   *
   * @return object
   *    Feed object or FALSE
   */
  public static function loadFeed($name) {
    $feed = db_select('feed_import_settings', 'f')
                ->fields('f')
                ->condition(((int) $name) ? 'id' : 'machine_name', $name, '=')
                ->range(0, 1)
                ->execute()
                ->fetchObject();
    if (!$feed) {
      return FALSE;
    }
    $feed->settings = unserialize($feed->settings);
    return $feed;
  }

  /**
   * Deletes a feed.
   *
   * @param object $feed
   *    Feed info
   * @param bool $hashes
   *    Also remove hashes
   */
  public static function deleteFeed($feed, $hashes = TRUE) {
    db_delete('feed_import_settings')
      ->condition('machine_name', $feed->machine_name)
      ->execute();
    if ($hashes && isset($feed->settings['hashes']['class'])) {
      $class = $feed->settings['hashes']['class'];
      $class::deleteByFeed($feed->machine_name);
    }
  }


  /**
   * Gets a new empty feed configuration.
   *
   * @return array
   *     An empty feed configuration.
   */
  public static function getEmptyFeed() {
    return array(
      'name' => NULL,
      'machine_name' => NULL,
      'entity' => NULL,
      'cron_import' => 0,
      'last_run' => 0,
      'last_run_duration' => 0,
      'last_run_items' => 0,
      'settings' => array(
        'uniq_path' => NULL,
        'preprocess' => NULL,
        'feed' => array(
          'protect_on_invalid_source' => FALSE,
          'protect_on_fewer_items' => 0,
        ),
        'processor' => array(
          'name' => 'default',
          'class' => 'FeedImportProcessor',
          'options' => array(
            'items_count' => 0,
            'skip_imported' => FALSE,
            'reset_cache' => 100,
            'break_on_undefined_filter' => TRUE,
            'skip_defined_functions_check' => FALSE,
            'updates_only' => FALSE,
          ),
        ),
        'reader' => array(
          'name' => 'xml',
          'class' => 'SimpleXMLFIReader',
          'options' => array(),
        ),
        'hashes' => array(
          'name' => 'sql',
          'class' => 'FeedImportSQLHashes',
          'options' => array(
            'ttl' => 0,
            'insert_chunk' => 300,
            'update_chunk' => 300,
            'group' => '',
          ),
        ),
        'filter' => array(
          'name' => 'default',
          'class' => 'FeedImportMultiFilter',
          'options' => array(
            'param' => '[field]',
            'include' => NULL,
          ),
        ),
        'fields' => array(),
        'static_fields' => array(),
        'functions' => array(),
      ),
    );
  }

  /**
   * Saves a feed in database
   *
   * @param object $feed
   *    Feed info
   */
  public static function saveFeed($feed) {
    if (empty($feed->name) || empty($feed->machine_name) ||
        empty($feed->entity) || empty($feed->settings)) {
      return FALSE;
    }
    if (!isset($feed->cron_import)) {
      $feed->cron_import = 0;
    }
    $fields = array(
      'name' => $feed->name,
      'machine_name' => $feed->machine_name,
      'entity' => $feed->entity,
      'cron_import' => (int) $feed->cron_import,
      'settings' => serialize($feed->settings),
    );
    if (isset($feed->id)) {
      db_update('feed_import_settings')
        ->fields($fields)
        ->condition('id', $feed->id)
        ->execute();
    }
    else {
      $fields += array(
        'last_run' => 0,
        'last_run_duration' => 0,
        'last_run_items' => 0,
      );
      db_insert('feed_import_settings')
        ->fields($fields)
        ->execute();
    }
    return TRUE;
  }

  /**
   * Saves feed import status
   */
  public static function saveFeedImportStatus($feed) {
    db_update('feed_import_settings')
      ->fields(array(
        'last_run' => (int) $feed->last_run,
        'last_run_duration' => (int) $feed->last_run_duration,
        'last_run_items' => (int) $feed->last_run_items,
      ))
      ->condition('machine_name', $feed->machine_name)
      ->execute();
  }


  // Active import
  public static $activeImport = NULL;

  /**
   * Imports a feed.
   *
   * @param object $feed
   *    Feed info
   * @param string $filters_dir
   *    Path to filters dir
   */
  public static function import($feed, $filters_dir) {
    if (!empty($feed->settings['preprocess'])
        && function_exists($feed->settings['preprocess'])) {
      // Preprocess feed before import.
      call_user_func($feed->settings['preprocess'], $feed);
    }
    $class = $feed->settings['processor']['class'];
    $fi = new $class($feed->machine_name);
    $fi->setErrorHandler(TRUE);
    $f = static::setProcessorSettings($fi, $feed, $filters_dir);
    if ($f !== TRUE) {
      $fi->setErrorHandler(FALSE);
      return array(
        'init_error' => TRUE,
        'errors' => $f,
      );
    }
    unset($f);
    $lastimport = static::$activeImport;
    static::$activeImport = $fi;
    $f = $fi->process();
    static::$activeImport = $lastimport;
    $fi->setErrorHandler(FALSE);
    return $f;
  }

  /**
   * Gets all hash manager classes used by feeds.
   *
   * @return array
   *    An array of classes
   */
  public static function getHashManagers() {
    static $hm = array();
    if (!$hm) {
      foreach (static::loadAllFeeds() as $feed) {
        if (!empty($feed->settings['hashes']['class'])) {
          $hm[] = $feed->settings['hashes']['class'];
        }
      }
      $hm = array_unique($hm);
    }
    return $hm;
  }

  /**
   * Delete all expired items.
   *
   * @param int $max
   *    Max number of entity ids to delete from
   *    a hash manager
   *
   * @return int
   *    Number of deleted entities
   */
  public static function deleteExpired($max = 0) {
    $deleted = 0;
    foreach (static::loadAllFeeds() as $feed) {
      if (empty($feed->settings['hashes']['class'])) {
        continue;
      }
      $class = $feed->settings['hashes']['class'];
      $items = $class::getExpired($feed->machine_name, $max);
      foreach ($items as $e => &$ids) {
        $entity = static::getEntityInfo($e);
        // Delete entities.
        if ($entity->deleteCallback) {
          $f = $entity->deleteCallback . '_multiple';
          if (function_exists($f)) {
            $f($ids);
          }
          else {
            array_map($entity->deleteCallback, $ids);
          }
        }
        else {
          $entity->controller->delete($ids);
        }
        // Delete hashes.
        $class::delete(array_keys($ids));
        $deleted += count($ids);
        unset($items[$e], $entity);
      }
    }
    return $deleted;
  }

  // Deleted entities.
  protected static $deletedEntities = array();

  /**
   * Schedule a deleted entity to be removed from hashes.
   *
   * @param string $entity_type
   *    Entity type
   * @param int $id
   *    Entity id
   */
  public static function addDeletedEntity($entity_type, $id) {
    static $unregistered = TRUE;
    if ($unregistered) {
      $unregistered = FALSE;
      register_shutdown_function(array(__CLASS__, 'removeEntityHashes'));
    }
    static::$deletedEntities[$entity_type][] = $id;
  }

  /**
   * Removes entity hashes.
   */
  public static function removeEntityHashes($entities = NULL) {
    if ($entities == NULL) {
      $entities = &static::$deletedEntities;
    }
    foreach (static::getHashManagers() as $hm) {
      array_walk($entities, array($hm, 'deleteEntities'));
    }
    $entities = NULL;
  }

}

/**
 * Class that processess the import.
 */
class FeedImportProcessor extends FeedImportConfigurable {

  // No duplicates
  const UPDATE_COMBINE = 0;
  // Duplicates
  const UPDATE_MERGE = 1;
  // Overwrite
  const UPDATE_OVERWRITE = 2;
  // Overwrite fast
  const UPDATE_OVERWRITE_FAST = 3;

  // No field value actions.
  const ACTION_DEFAULT_VALUE = 0;
  const ACTION_DEFAULT_FILTERED_VALUE = 1;
  const ACTION_IGNORE_FIELD = 2;
  const ACTION_SKIP_ITEM = 3;

  // Action before/after combine entities
  const ENTITY_CONTINUE = 0;
  const ENTITY_RESCHEDULE = 1;
  const ENTITY_SKIP = 2;
  const ENTITY_NO_COMBINE = 3;
  const ENTITY_MARK_PROTECTED = 4;
  // Action before/after create/save entity
  const ENTITY_SKIP_CREATE = 5;
  const ENTITY_SKIP_SAVE = 6;

  // Hash property name.
  const TEMP_HASH = '$_FI~HASH_$';

  // Fields imported.
  protected $fields = array();
  // Static fields.
  protected $staticFields = array();
  // Base entity.
  protected $baseEntity = array();
  // Fields info.
  protected $fieldsInfo = array();
  // Uniq path.
  protected $uniq;
  // Feed group.
  protected $group;
  // Feed machine name.
  protected $machineName;
  // Flag to skip imported items.
  protected $skipImportedItems = FALSE;
  // Flag to only apply updates.
  protected $updatesOnly = FALSE;
  // Entity info.
  protected $entityInfo;
  // Current reader.
  protected $reader;
  // Current hash manager.
  protected $hashes;
  // Filters
  protected $filters;
  // After how many of entities to save.
  protected $itemsCount = 0;
  // After how many items to reset entity static cache.
  protected $resetStaticCache = 0;
  // Number entities in static cache.
  protected $staticCacheEntities = 0;
  // Callbacks for before/after combine entities
  protected $beforeCombine = FALSE;
  protected $afterCombine  = FALSE;
  // Callbacks for before/after create/save entities
  protected $beforeCreate  = FALSE;
  protected $beforeSave    = FALSE;
  protected $afterSave     = FALSE;
  // List of missing entities (as hash ids)
  protected $orphanHashes = array();
  // A null value.
  protected $NULL = NULL;
  // Flag indicating to skip creating dynamic functions if already exists.
  protected $skipDefFunChk = FALSE;
  // This will break import if a filter function is missing.
  protected $breakOnUndefinedFilter = TRUE;
  // Reports.
  protected $report = array(
    'total' => 0,
    'updated' => 0,
    'new' => 0,
    'rescheduled' => 0,
    'skipped' => 0,
    'protected' => 0,
    'protected_skipped' => 0,
    'missing' => 0,
    'started' => 0,
    'finished' => 0,
    'errors' => array(),
  );

  // Current entities in work.
  public $current;
  // Current prefiltered values.
  public $prefilteredValue;
  // Callback to alter uniq value
  protected $uniqAlter = FALSE;

  /**
   * Constructor.
   */
  public function __construct($machine_name) {
    $this->machineName = $machine_name;
  }

  // Error handler status.
  protected $errHandlerEnabled = FALSE;

  /**
   * Enables/disables error handler.
   *
   * @param bool $enable
   *    Whatever to enable or disable the error handler
   */
  public function setErrorHandler($enable) {
    if ($enable) {
      if (!$this->errHandlerEnabled) {
        // Set error handler.
        $this->errHandlerEnabled = TRUE;
        set_error_handler(array($this, 'errorHandler'));
      }
    }
    elseif ($this->errHandlerEnabled) {
      // Resore eror handler.
      $this->errHandlerEnabled = FALSE;
      restore_error_handler();
    }
  }

  // Max number of errors to report.
  protected $errorsLeft = 100;
  protected $throwException = TRUE;

  /**
   * Error handler callback
   * This is setted with set_error_handling()
   */
  public function errorHandler($errno, $errmsg, $file, $line) {

    // Handle silenced errors with @.
    if (error_reporting() == 0) {
      return FALSE;
    }

    // Add error to reports.
    if ($this->errorsLeft) {
      $this->report['errors'][] = array(
        'error' => $errmsg,
        'error number' => $errno,
        'line' => $line,
        'file' => $file,
      );
      $this->errorsLeft--;
    }

    // Throw an exception to be caught by a try-catch statement.
    if ($this->throwException) {
      throw new Exception("(Uncaught Feed Import Exception) [$errmsg; file: $file; line: $line]", $errno);
    }
  }

  /**
   * Gets an array with errors.
   *
   * @return array
   *    An array of errors
   */
  public function getErrors() {
    return $this->report['errors'];
  }

  /**
   * Adds an error to report
   *
   * @param string $errmsg
   *    Error message
   * @param int $errno
   *    Error number
   * @param int $line
   *    Error line
   * @param string $file
   *    Error file
   */
  public function addError($errmsg, $errno = 0, $line = NULL, $file = NULL) {
    $this->report['errors'][] = array(
      'error' => $errmsg,
      'error number' => $errno,
      'line' => $line,
      'file' => $file,
    );
  }

  /**
   * {@inheritdoc}
   */
  public function setOptions(array $options, $overwrite = FALSE) {
    if (isset($options['items_count']) && $options['items_count'] >= 0) {
      $this->itemsCount = (int) $options['items_count'];
    }
    if (isset($options['skip_imported'])) {
      $this->skipImportedItems = (bool) $options['skip_imported'];
    }
    if (isset($options['max_reported_errors'])) {
      $this->errorsLeft = (int) $options['max_reported_errors'];
    }
    if (isset($options['throw_exception'])) {
      $this->throwException = (bool) $options['throw_exception'];
    }
    if (isset($options['reset_cache']) && $options['reset_cache'] >= 0) {
      $this->resetStaticCache = (int) $options['reset_cache'];
    }
    if (isset($options['skip_defined_functions_check'])) {
      $this->skipDefFunChk = (bool) $options['skip_defined_functions_check'];
    }
    if (isset($options['break_on_undefined_filter'])) {
      $this->breakOnUndefinedFilter = (bool) $options['break_on_undefined_filter'];
    }
    if (isset($options['updates_only'])) {
      $this->updatesOnly = (bool) $options['updates_only'];
    }
    
    $cbks = array(
      'before_combine' => &$this->beforeCombine,
      'after_combine'  => &$this->afterCombine,
      'before_create'  => &$this->beforeCreate,
      'before_save'    => &$this->beforeSave,
      'after_save'     => &$this->afterSave,
      'uniq_callback'     => &$this->uniqAlter,
    );
    
    foreach ($cbks as $opt => &$val) {
      if (!empty($options[$opt])) {
        $val = $options[$opt];
      }
    }
    
    return TRUE;
  }

  /**
   * Sets the entity info object.
   */
  public function setEntityInfo($entity_info) {
    if (!$entity_info) {
      $this->addError('No entity info provided');
      return FALSE;
    }
    $this->entityInfo = $entity_info;
    return TRUE;
  }

  /**
   * Sets the filters object.
   *
   * @param FeedImportMultiFilter $filter
   *    An instance of FeedImportMultiFilter
   * @param array $functions
   *    An array of functions to create
   * @return bool
   *    TRUE on success
   */
  public function setFilter(FeedImportMultiFilter $filter, $functions = array()) {
    $this->filters = $filter;
    if ($functions) {
      foreach ($functions as &$f) {
        if ($this->skipDefFunChk && function_exists($f['name'])) {
          continue;
        }
        $msg = $this->filters->createFunction($f['name'], $f['args'], $f['body']);
        if ($msg !== TRUE) {
          $this->addError($msg);
          return FALSE;
        }
      }
    }
    return TRUE;
  }

  /**
   * Sets the reader and inits it
   *
   * @param FeedImportReader $reader
   *     An instance of reader
   *
   * @return boolean
   *     TRUE if success
   */
  public function setReader(FeedImportReader $reader) {
    $this->reader = $reader;
    $this->throwException = FALSE;
    $ok = $this->reader->init();
    $this->throwException = TRUE;
    return $ok;
  }


  /**
   * Sets uniq path for monitoring items.
   *
   * @param string $uniq
   *     A path.
   *
   * @return boolean
   *     TRUE if success
   */
  public function setUniq($uniq) {
    if ($uniq == NULL) {
      return TRUE;
    }
    if ($this->reader) {
      $this->uniq = $this->reader->formatPath($uniq);
      if (is_scalar($this->uniq)) {
        if ((string) $this->uniq === '') {
          $this->uniq = NULL;
        }
      }
      elseif (empty($this->uniq)) {
        $this->uniq = NULL;
      }
      return TRUE;
    }
    $this->addError('You must have a reader to add unique path');
    return FALSE;
  }

  /**
   * Sets the hash manager
   *
   * @param FeedImportHashManager $hm
   *     An instance of FeedImportHashManager
   */
  public function setHashManager(FeedImportHashManager $hm) {
    $this->hashes = $hm;
    return TRUE;
  }

  /**
   * Sets entity fields.
   *
   * @param array $fields
   *     List of dynamic fields
   * @param array $static_fields
   *     List of static fields
   * @param array $compare_functions
   *     List of compare functions
   * @param string $default_compare
   *     Default compare function
   *
   * @return boolean
   *     TRUE if fields were set
   */
  public function setFields(array $fields = array(), array $static_fields = array(), array $compare_functions = array(), array $merge_classes = array(), $default_compare = '_feed_import_base_compare_other_fields') {

    // Check for requirements.
    if (!$this->entityInfo || !$this->reader || !$this->filters || !empty($this->baseEntity)) {
      $this->addError('Could not set fields because there are missing dependencies or fields were already added');
      return FALSE;
    }
    
    // Create default merge
    if (!isset($merge_classes[static::UPDATE_COMBINE])) {
      $this->addError(sprintf('Merge field default class found!'));
      return FALSE;
    }
    $class = $merge_classes[static::UPDATE_COMBINE];
    if (!class_exists($class)) {
      $this->addError(sprintf('Merge field default class %s was not found!', $class));
      return FALSE;
    }
    elseif (!is_subclass_of($class, 'FeedImportMergeField')) {
      $this->addError(sprintf(
        'Merge field default class %s must extend % class!',
        $class,
        'FeedImportMergeField'
      ));
      return FALSE;
    }
    $merge_classes[static::UPDATE_COMBINE] = new $class();

    // Create format paths callback.
    $fp = array($this->reader, 'formatPath');

    // Get language key.
    $lk = $this->entityInfo->langKey;

    // Set static fields.
    $this->staticFields = &$static_fields;

    // Parse all fields.
    foreach ($fields as &$f) {

      // Set field info.
      $this->fieldsInfo[$f['field']] = &$f;
      
      if (!isset($merge_classes[$f['update_mode']])) {
        $this->addError(sprintf('No field merge class found for field %s!', $f['field']));
        return FALSE;
      }
      
      if (is_string($merge_classes[$f['update_mode']])) {
        $class = $merge_classes[$f['update_mode']];
        if (!class_exists($class)) {
          $this->addError(sprintf(
            'Merge field class %s for field %s was not found!',
            $class,
            $f['field']
          ));
          return FALSE;
        }
        elseif (!is_subclass_of($class, 'FeedImportMergeField')) {
          $this->addError(sprintf(
            'Merge field class %s for field %s must extend % class!',
            $class,
            $f['field'],
            'FeedImportMergeField'
          ));
          return FALSE;
        }
        $merge_classes[$f['update_mode']] = new $class();
      }
      
      $f['update_mode'] = $merge_classes[$f['update_mode']];
      $f['overwrite'] = $f['update_mode']->overwriteEmpty();
      
      // Add cardinality
      $f['cardinality'] = isset($this->entityInfo->fields[$f['field']]['cardinality'])
                            ? $this->entityInfo->fields[$f['field']]['cardinality']
                            : 1;

      // Add compare function
      if ($f['column']) {
        $f['compare'] = $this->entityInfo->fields[$f['field']]['module'] . ':' . $this->entityInfo->fields[$f['field']]['type'];
        if (isset($compare_functions[$f['compare']])) {
          $f['compare'] = $compare_functions[$f['compare']];
        }
        else {
          $f['compare'] = $default_compare;
        }
      }
      
      // Check if column must be guessed.
      if ($f['column'] === TRUE && isset($this->entityInfo->fields[$f['field']])) {
        $f['column'] = $this->entityInfo->fields[$f['field']]['column'];
      }

      // Get paths count
      $f['paths_count'] = count($f['paths']);

      // Check if can be used as static field to improve performance
      if (!$f['paths_count'] && $f['default_action'] == 'default_value') {
        if ($f['column']) {
          // Its a field, add it to static fields.
          $this->staticFields[$f['field']][$f['column']] = $f['default_value'];
        }
        else {
          // Its a property.
          $this->staticFields[$f['field']] = $f['default_value'];
        }
        // Ignore filters.
        $f['prefilters'] = $f['filters'] = FALSE;
        // Next field.
        continue;
      }

      // Check (pre)filters
      foreach (array('prefilters', 'filters') as $fgroup) {
        if ($f[$fgroup]) {
          $ok = TRUE;
          // Add filters
          foreach ($f[$fgroup] as &$v) {
            if (!$this->filters->add($fgroup, $f['field'], $v['function'], $v['params'])) {
              $ok = FALSE;
              $this->addError(sprintf(
                'Could not add function %s in %s for %s field because is not defined',
                $v['function'],
                $fgroup,
                $f['field']
              ));
              if ($this->breakOnUndefinedFilter) {
                $this->addError('Import stopped because a filter function is missing!');
                return FALSE;
              }
            }
          }
          $f[$fgroup] = $ok;
        }
        else {
          // No filters
          $f[$fgroup] = FALSE;
        }
      }

      // Format paths
      $f['paths'] = array_map($fp, $f['paths']);

      // Add to fields
      $this->fields[$f['field']] = &$f;
    }

    // Remove reference to $f.
    unset($f);

    // Set all static fields properties.
    // In the end just fields remain in static fields (no properties).
    foreach ($this->staticFields as $f => &$value) {
      if (is_scalar($value)) {
        if (!isset($this->fieldsInfo[$f])) {
          $this->fieldsInfo[$f] = array(
            'field' => $f,
            'column' => FALSE,
            'update_mode' => $merge_classes[static::UPDATE_COMBINE],
            'overwrite' => $merge_classes[static::UPDATE_COMBINE]->overwriteEmpty(),
            'cardinality' => 1,
          );
        }
        $this->baseEntity[$f] = $value;
        unset($this->staticFields[$f]);
      }
      elseif (!isset($this->fieldsInfo[$f])) {
        $this->fieldsInfo[$f] = array(
          'field' => $f,
          'column' => isset($this->entityInfo->fields[$f]) ?
                      $this->entityInfo->fields[$f]['column'] : 'value',
          'update_mode' => $merge_classes[static::UPDATE_COMBINE],
          'overwrite' => $merge_classes[static::UPDATE_COMBINE]->overwriteEmpty(),
          'cardinality' => isset($this->entityInfo->fields[$f]['cardinality']) ?
                            $this->entityInfo->fields[$f]['cardinality'] : 1,
        );
      }
    }

    // There isn't lang in base entity nor in fields so use default.
    if (!isset($this->baseEntity[$lk]) && !isset($this->fields[$lk])) {
      $this->baseEntity[$lk] = LANGUAGE_NONE;
    }

    // Check for language in base entity.
    if (isset($this->baseEntity[$lk])) {
      // We have lang so set static fields in base entity.
      $lang = $this->baseEntity[$lk];
      foreach ($this->staticFields as $f => &$value) {
        if (!isset($this->fields[$f])) {
          // This field is not dynamically generated so use it in base entity.
          $this->baseEntity[$f][$lang][] = $value;
          // Remove it from static fields because now is part of base entity.
          unset($this->staticFields[$f]);
        }
      }
    }
    else {
      // No language, it means language is dynamically created.
      // Move language on top to be available for other fields.
      $this->fields = array_merge(array($lk => NULL), $this->fields);
      // However, set it to NONE, and if used will be overwritten.
      $this->baseEntity[$lk] = LANGUAGE_NONE;
    }

    return TRUE;
  }

  /**
   * Sets custom settings, after base settings were set.
   * Can be used by child classes.
   *
   * @param array $settings
   *    An array of settings.
   *
   * @return bool
   *    TRUE if success. If not, the import will be stopped.
   */
  public function setCustomSettings(array $settings) {
    return TRUE;
  }


  /**
   * Checks if a variable has content
   *
   * @param mixed &$var
   *     Variable to check
   *
   * @return bool
   *     TRUE if there is content FALSE otherwise
   */
  protected function hasContent(&$var) {
    if (is_scalar($var)) {
      return ((string) $var) !== '';
    }
    return !empty($var);
  }

  /**
   * Attaches a field value to entity.
   *
   * @param array &$entity
   *     Entity where to attach field.
   * @param array &$field
   *     Field settings.
   * @param mixed &$value
   *     Field value.
   */
  protected function attachField(array &$entity, &$field, &$value) {
    if ($field['column']) {
      // It is a field.
      $fn = &$field['field'];
      $fc = &$field['column'];

      $lang = &$entity[$this->entityInfo->langKey];
      // Check if field exists.
      if (!isset($entity[$fn][$lang])) {
        $entity[$fn][$lang] = array();
      }

      // Get field reference.
      $ef = &$entity[$fn][$lang];

      // Check for static fields.
      $st = FALSE;
      if (!empty($this->staticFields[$fn])) {
        $st = &$this->staticFields[$fn];
      }

      // Make it look multivalued.
      if (!is_array($value)) {
        $value = array($value);
      }
      elseif ($field['cardinality'] != -1 && ($cnt = count($value)) > $field['cardinality']) {
        // Remove extra values.
        array_splice($value, $field['cardinality'], $cnt - $field['cardinality'], NULL);
      }

      // Set field properties.
      if ($st) {
        // There are static field props.
        $fa = array($fc => NULL);
        $fv = &$fa[$fc];
        foreach ($value as &$v) {
          if (is_object($v)) {
            $ef[] = ((array) $v) + $st;
          }
          else {
            $fv = $v;
            $ef[] = $fa + $st;
          }
        }
      }
      else {
        // No static field props.
        foreach ($value as &$v) {
          if (is_object($v)) {
            $ef[] = (array) $v;
          }
          else {
            $ef[][$fc] = $v;
          }
        }
      }
    }
    else {
      // If this is a property then get only first value.
      if (is_array($value) || is_object($value)) {
        // This still can be array but if so then problem is elsewhere.
        $value = reset($value);
      }
      // Set property.
      $entity[$field['field']] = $value;
    }
  }


  /**
   * Creates a new entity.
   *
   * @param mixed $item
   *     Item to be mapped to entity
   *
   * @return object
   *     An array containing the entity or NULL
   */
  protected function &createEntity(&$item) {
    // Create the entity.
    $entity = $this->baseEntity;
    // Set a ref for current entity.
    $this->current = &$entity;
    // Check for unique id of item.
    if ($this->uniq === NULL) {
      // No hash, so not monitored.
      $entity[static::TEMP_HASH] = NULL;
    }
    else {
      // Get uniq.
      $uniq = $this->reader->map($item, $this->uniq);
      if (is_array($uniq)) {
        $uniq = isset($uniq[0]) ? $uniq[0] : reset($uniq);
      }
      // Check if uniq alter callback exists.
      if ($this->uniqAlter) {
        $uniq = call_user_func($this->uniqAlter, $uniq);
      }
      // Create hash.
      $entity[static::TEMP_HASH] = $this->hashes->hash($uniq);
    }

    // Set entity fields.
    foreach ($this->fields as $name => &$field) {
      // Get filtered field value.
      $val = NULL; $i = -1;
      while (++$i < $field['paths_count']) {
        // Get value for specified path.
        $val = $this->reader->map($item, $field['paths'][$i]);
        // Check if passes prefilter.
        if ($field['prefilters']) {
          $this->prefilteredValue = $this->filters->apply("prefilters", $name, $val);
          if (!$this->hasContent($this->prefilteredValue)) {
            $val = $this->prefilteredValue = NULL;
            // If item doesn't pass prefilter than go to next path.
            continue;
          }
        }
        if ($this->hasContent($val)) {
          // We have content, check for filters.
          if ($field['filters']) {
            $val = $this->filters->apply("filters", $name, $val);
            if (!$this->hasContent($val)) {
              $val = NULL;
            }
          }
          // We matched one path.
          break;
        }
        else {
          $val = NULL;
        }
      }
      // Check if default action is needed.
      if ($val === NULL) {
        switch ($field['default_action']) {
          // Provide default value.
          // This is also default action.
          case static::ACTION_DEFAULT_VALUE:
          default:
            $val = $field['default_value'];
            break;
          // Provide filtered default value.
          case static::ACTION_DEFAULT_FILTERED_VALUE:
            $val = $this->filters->apply("filters", $name, $field['default_value']);
            break;
          // Skip this item by returning NULL.
          case static::ACTION_SKIP_ITEM:
            $this->report['skipped']++;
            $this->current = $this->prefilteredValue = NULL;
            return $this->NULL;
          // Don't add this field to entity.
          case static::ACTION_IGNORE_FIELD:
            $this->prefilteredValue = NULL;
            continue 2;
        }
      }

      // Remove prefiltered value.
      $this->prefilteredValue = NULL;

      // Set field value in entity.
      $this->attachField($entity, $field, $val);

      // Not needed anymore.
      unset($val);
    }

    // Remove current reference.
    unset($this->current);
    $this->current = NULL;

    // Return the entity array.
    return $entity;
  }


  /**
   * Combines two entities.
   *
   * @param array $new
   *     Created entity
   * @param object $curr
   *     Current entity
   *
   * @return boolean
   *     TRUE if current entity was changed
   */
  protected function combineEntities(array &$new, $curr) {

    // Initial entity status.
    $changed = FALSE;

    // Get entity language
    $lang = &$new[$this->entityInfo->langKey];

    // Compare fields from entities.
    foreach ($this->fieldsInfo as &$field) {
      // Get field name and column.
      $fn = &$field['field'];
      $fc = &$field['column'];

      if ($fc) {
        // It is a field
        if (isset($new[$fn][$lang])) {
          if (isset($curr->{$fn}[$lang])) {
            if ($field['update_mode']->merge($curr->{$fn}[$lang], $new[$fn][$lang], $field)) {
              // Mark as changed.
              $changed = TRUE;
            }
          }
          else {
            // Overwrite.
            $curr->{$fn}[$lang] = $new[$fn][$lang];
            // Mark as changed.
            $changed = TRUE;
          }
        }
        elseif ($field['overwrite'] && isset($curr->{$fn}[$lang])) {
          // Forced update mode.
          unset($curr->{$fn}[$lang]);
          // Don't leave an empty property.
          if (empty($curr->{$fn})) {
            unset($curr->{$fn});
          }
          // Mark as changed.
          $changed = TRUE;
        }
      }
      else {
        // It is a property.
        if (isset($new[$fn])) {
          if (isset($curr->{$fn}) && $curr->{$fn} == $new[$fn]) {
            // Nothing changed.
            continue;
          }
          // Set the new property value.
          $curr->{$fn} = $new[$fn];
          // Mark as changed.
          $changed = TRUE;
          // Remove from memory.
          unset($new[$fn]);
        }
        elseif ($field['overwrite'] && isset($curr->{$fn})) {
          // Forced update mode is selected.
          unset($curr->{$fn});
          // Mark as changed.
          $changed = TRUE;
        }
      }
    }

    return $changed;
  }

  /**
   * Saves created entities.
   *
   * @param array &$entities
   *   An array of entities to be saved
   */
  protected function saveEntities(array &$entities) {
    static $loadArr = array(NULL);
    // Number of entities.
    $total = count($entities);
    $this->report['total'] += $total;

    // Get ids from hashes.
    $ids = $this->hashes->get();

    // Entity create callback.
    $createCallback = &$this->entityInfo->createCallback;
    // Entity save callback.
    $saveCallback = &$this->entityInfo->saveCallback;
    // Entity before combine callback
    $beforeCombine = &$this->beforeCombine;
    // Entity after combine callback
    $afterCombine = &$this->afterCombine;
    // Entity before create callback
    $beforeCreate = &$this->beforeCreate;
    // Entity before save callback
    $beforeSave = &$this->beforeSave;
    // Entity after save callback
    $afterSave = &$this->afterSave;

    // Entity load id.
    $loadId = &$loadArr[0];

    $i = -1;
    // Save each entity.
    while (++$i < $total) {
      $entity = &$entities[$i];
      unset($entities[$i]);
      if ($entity == NULL) {
        continue;
      }
      // Save hash.
      $hash = &$entity[static::TEMP_HASH];
      // Not needed anymore.
      unset($entity[static::TEMP_HASH]);
      // Check if item is already imported or is not monitored.
      if ($hash !== NULL && isset($ids[$hash])) {
        // Check if is used option to skip item if already imported
        // or entity is protected (import cannot make changes).
        if ($this->skipImportedItems ||
            $ids[$hash]->expire == FeedImportHashManager::MARK_PROTECTED) {
          $this->report[$this->skipImportedItems ? 'skipped' : 'protected_skipped']++;
          unset($ids[$hash]);
          continue;
        }

        // Current entity id.
        $loadId = $ids[$hash]->entity_id;

        // Load current entity.
        $current = entity_load($this->entityInfo->name, $loadArr);

        // If entity is missing then skip.
        if (!isset($current[$loadId])) {
          $this->report['missing']++;
          $this->orphanHashes[] = $ids[$hash]->id;
          unset($ids[$hash], $current);
          continue;
        }
        // Get current entity value.
        $current = &$current[$loadId];
        // Entity might be in static cache.
        $this->staticCacheEntities++;

        // Merge status of entity.
        $changed = FALSE;

        // Check for before combine callback.
        if ($beforeCombine) {
          switch ($beforeCombine($entity, $current, $changed)) {
            case static::ENTITY_RESCHEDULE:
              $this->report['rescheduled']++;
              goto ADD_HASH_UPDATE;
            case static::ENTITY_SKIP:
              $this->report['skipped']++;
              goto UNSET_VARS;
            case static::ENTITY_NO_COMBINE:
              goto COMBINE_FINISHED;
            case static::ENTITY_MARK_PROTECTED:
              $this->report['protected']++;
              $this->hashes->protect($ids[$hash]->id);
              goto UNSET_VARS;
          }
        }

        // Check for diff.
        $changed = $this->combineEntities($entity, $current);

        // Check for after combine callback.
        if ($afterCombine) {
          switch ($afterCombine($entity, $current, $changed)) {
            case static::ENTITY_RESCHEDULE:
              $this->report['rescheduled']++;
              goto ADD_HASH_UPDATE;
            case static::ENTITY_SKIP:
              $this->report['skipped']++;
              goto UNSET_VARS;
            case static::ENTITY_MARK_PROTECTED:
              $this->report['protected']++;
              $this->hashes->protect($ids[$hash]->id);
              goto UNSET_VARS;
          }
        }

        COMBINE_FINISHED:
        // Not needed anymore.
        unset($entity);
        // Check if entity is changed and save changes.
        if ($changed) {
          // Save entity.
          if ($saveCallback) {
            $saveCallback($current);
          }
          elseif (method_exists($current, 'save')) {
            if (!$current->save()) {
              unset($current);
              continue;
            }
          }
          elseif ($this->entityInfo->controller->canSave) {
            if (!$this->entityInfo->controller->save($current)) {
              unset($current);
              continue;
            }
          }
          else {
            // Don't know how to save entity...
            unset($current);
            continue;
          }

          // Set report about updated items.
          $this->report['updated']++;
          // Check after save callback
          $afterSave && $afterSave($current, FALSE);
        }
        else {
          // Set report about rescheduled items.
          $this->report['rescheduled']++;
        }
        ADD_HASH_UPDATE:
        // Add to update ids.
        $this->hashes->update($ids[$hash]->id);
        UNSET_VARS:
        // Free some memory.
        unset($ids[$hash], $current, $entity, $hash);
      }
      else {
        // Check if this imports accepts only updates.
        if ($this->updatesOnly) {
          $this->report['skipped']++;
          goto UNSET_E_VARS;
        }
        // Check before save callback
        if ($beforeCreate) {
          switch ($beforeCreate($entity)) {
            case static::ENTITY_SKIP:
              $this->report['skipped']++;
              goto UNSET_E_VARS;
            case static::ENTITY_SKIP_CREATE:
              goto ENTITY_SAVE;
            case static::ENTITY_SKIP_SAVE:
              goto ENTITY_SAVED;
          }
        }
        
        // Create a new entity.
        if ($createCallback) {
          $entity = $createCallback($entity, $this->entityInfo->name);
        }
        elseif ($this->entityInfo->controller->canCreate) {
          $entity = $this->entityInfo->controller->create($entity);
        }
        else {
          $entity = (object) $entity;
        }
        
        ENTITY_SAVE:
        // Check before save callback
        if ($beforeSave) {
          switch ($beforeSave($entity)) {
            case static::ENTITY_SKIP:
              $this->report['skipped']++;
              goto UNSET_E_VARS;
            case static::ENTITY_SKIP_SAVE:
              goto ENTITY_SAVED;
          }
        }
        
        // No entity to save.
        if (!$entity) {
          unset($entity);
          continue;
        }
        elseif ($saveCallback) {
          $saveCallback($entity);
        }
        elseif (method_exists($entity, 'save')) {
          if (!$entity->save()) {
            unset($entity);
            continue;
          }
        }
        elseif ($this->entityInfo->controller->canSave) {
          if (!$this->entityInfo->controller->save($entity)) {
            unset($entity);
            continue;
          }
        }
        else {
          // Don't know how to save entity...
          unset($entity);
          continue;
        }
        
        ENTITY_SAVED:
        // Entity might be added in static cache.
        $this->staticCacheEntities++;
        
        // Check after save callback
        $afterSave && $afterSave($entity, TRUE);

        // Check if is monitored.
        if ($hash !== NULL) {
          // Insert into feed import hash table.
          $this->hashes->insert($entity->{$this->entityInfo->idKey}, $hash);
        }
        // Set report about new items.
        $this->report['new']++;
        
        UNSET_E_VARS:
        // Not needed anymore.
        unset($entity, $hash);
      }
      // Remove entity cache.
      if ($this->staticCacheEntities == $this->resetStaticCache) {
        $this->entityInfo->controller->canResetCache && $this->entityInfo->controller->resetCache();
        $this->staticCacheEntities = 0;
      }
    }
  }

  /**
   * Processes the import.
   */
  public function process() {
    // Give import time (for large imports).
    // Well, if safe mode is on this cannot be done so it may break import.
    if (!ini_get('safe_mode')) {
      set_time_limit(0);
    }
    // Reset report.
    $this->report['started'] = time();
    $entities = array();
    $reader = $this->reader;
    if ($this->itemsCount) {
      $current = 0;
      // Get next item from reader.
      while ($item = $reader->get()) {
        // Create the entity.
        $entities[] = &$this->createEntity($item);
        // Check for save.
        if (++$current == $this->itemsCount) {
          unset($item);
          $this->saveEntities($entities);
          $current = 0;
          $entities = array();
        }
      }
    }
    else {
      // Get next item from reader.
      while ($item = $reader->get()) {
        // Create entity.
        $entities[] = &$this->createEntity($item);
      }
    }
    // Check for left over entities.
    if ($entities) {
      $this->saveEntities($entities);
    }

    // Not needed anymore.
    unset($entities, $reader);

    // Reset the static cache.
    if ($this->staticCacheEntities && $this->resetStaticCache) {
      $this->entityInfo->controller->canResetCache && $this->entityInfo->controller->resetCache();
      $this->staticCacheEntities = 0;
    }

    // Commit left over hash updates.
    $this->hashes->updateCommit();
    // Also the new hash inserts.
    $this->hashes->insertCommit();
    // Remove orphan hashes.
    if ($this->orphanHashes) {
      $this->hashes->delete($this->orphanHashes);
      $this->orphanHashes = array();
    }

    $this->report['finished'] = time();
    $report = $this->report;
    // Reset report
    $this->report = array(
      'total' => 0,
      'updated' => 0,
      'new' => 0,
      'rescheduled' => 0,
      'skipped' => 0,
      'protected' => 0,
      'protected_skipped' => 0,
      'missing' => 0,
      'started' => 0,
      'finished' => 0,
      'errors' => array(),
    );
    return $report;
  }

}


/**
 * This class implements SQL hash storage
 */
class FeedImportSQLHashes extends FeedImportHashManager {

  // Feed machine name.
  protected $feedName;

  // Entity name.
  protected $entity;

  // Insert format.
  protected $insertFormat;
  // Update format.
  protected $updateFormat;

  // Reuseable db objects.
  protected $select;
  protected $insert;
  protected $update;

  // Options
  protected $updateChunkSize = 500;
  protected $insertChunkSize = 500;
  protected $group = '';

  /**
   * {@inheritdoc}
   */
  public function __construct($entity_name, $feed_machine_name) {
    $this->entity = $entity_name;
    $this->feedName = $feed_machine_name;
  }

  /**
   * {@inheritdoc}
   */
  public function setOptions(array $options, $overwrite = FALSE) {
    if (isset($options['ttl']) && $options['ttl'] >= 0) {
      $this->ttl = (int) $options['ttl'];
    }
    if (isset($options['update_chunk']) && $options['update_chunk'] > 0) {
      $this->updateChunkSize = (int) $options['update_chunk'];
    }
    if (isset($options['insert_chunk']) && $options['insert_chunk'] > 0) {
      $this->insertChunkSize = (int) $options['insert_chunk'];
    }
    if (isset($options['group'])) {
      $this->group = $options['group'];
    }

    // Create insert format.
    $this->insertFormat = array(
      $this->feedName,
      $this->group,
      $this->entity,
      0, // holds id
      NULL, // holds hash
      0, // holds expire
    );

    // Create select object.
    $this->select = db_select('feed_import_hashes', 'f')
                      ->fields('f', array('hash', 'id', 'entity_id', 'expire'))
                      ->condition('feed_group', $this->group)
                      ->condition('entity', $this->entity)
                      ->condition('hash', array(), 'IN');

    // Create update object.
    $this->update = db_update('feed_import_hashes')
                    ->condition('feed_group', $this->group)
                    ->condition('entity', $this->entity);

    // Create update format.
    $this->updateFormat = array('expire' => 0);

    // Create insert object.
    $this->insert = db_insert('feed_import_hashes')
                      ->fields(array('feed_machine_name', 'feed_group', 'entity', 'entity_id', 'hash', 'expire'));
  }

  /**
   * {@inheritdoc}
   */
  public function hash(&$uniq) {
    return $this->generatedHashes[] = md5($uniq);
  }

  /**
   * {@inheritdoc}
   */
  public function get() {
    if (!$this->generatedHashes) {
      return array();
    }
    // Get select conditions (reuse same select object).
    $cond = &$this->select->conditions();
    // Remove last condition.
    array_pop($cond);
    // Return hashes.
    $hashes = $this->select
        ->condition('hash', $this->generatedHashes, 'IN')
        ->execute()
        ->fetchAllAssoc('hash');
    $this->generatedHashes = array();
    return $hashes;
  }

  // Items left to insert.
  protected $toInsert = 0;

  /**
   * {@inheritdoc}
   */
  public function insert($id, $hash) {
    $this->insertFormat[3] = $id;
    $this->insertFormat[4] = $hash;
    $this->insertFormat[5] = $this->ttl ? $this->ttl + time() : 0;

    $this->insert->values($this->insertFormat);

    // Commit insert.
    if (++$this->toInsert == $this->insertChunkSize) {
      $this->insertCommit();
    }
  }

  /**
   * {@inheritdoc}
   */
  public function insertCommit() {
    if ($this->toInsert) {
      $this->insert->execute();
      $this->toInsert = 0;
    }
  }

  // Ids that need to be updated.
  protected $updateIds = array();
  protected $toUpdate = 0;

  /**
   * {@inheritdoc}
   */
  public function update($id) {
    $this->updateIds[] = $id;
    if (++$this->toUpdate == $this->updateChunkSize) {
      $this->_update($this->updateIds, $this->ttl ? $this->ttl + time() : 0);
      $this->toUpdate = 0;
    }
  }

  // Ids that need to be protected.
  protected $protectIds = array();
  protected $toProtect = 0;

  /**
   * {@inheritdoc}
   */
  public function protect($id) {
    $this->protectIds[] = $id;
    if (++$this->toProtect == $this->updateChunkSize) {
      $this->_update($this->protectIds, static::MARK_PROTECTED);
      $this->toProtect = 0;
    }
  }

  /**
   * {@inheritdoc}
   */
  public function updateCommit() {
    if ($this->toUpdate) {
      $this->_update($this->updateIds, $this->ttl ? $this->ttl + time() : 0);
      $this->toUpdate = 0;
    }
    if ($this->toProtect) {
      $this->_update($this->protectIds, static::MARK_PROTECTED);
      $this->toProtect = 0;
    }
  }

  /**
   * Makes an update.
   */
  protected function _update(array &$ids, $expire) {
    $this->updateFormat['expire'] = $expire;
    $this->update->fields($this->updateFormat);
    // Get update conditions.
    $conditions = &$this->update->conditions();
    if (count($ids) <= $this->updateChunkSize) {
      // Update hashes.
      $this->update->condition('id', $ids, 'IN')->execute();
      // Remove last IN condition.
      array_pop($conditions);
      // Clear array.
      $ids = array();
    }
    else {
      // Split ids in chunks.
      $ids = array_chunk($ids, $this->updateChunkSize);
      for ($i = 0, $m = count($ids); $i < $m; $i++) {
        // Update hashes.
        $this->update->condition('id', $ids[$i], 'IN')->execute();
        unset($ids[$i]);
        // Remove last IN condition.
        array_pop($conditions);
      }
    }
  }

  /**
   * {@inheritdoc}
   */
  public static function delete(array $ids) {
    db_delete('feed_import_hashes')
      ->condition('id', $ids)
      ->execute();
  }

  /**
   * {@inheritdoc}
   */
  public static function deleteByFeed($name) {
    db_delete('feed_import_hashes')
      ->condition('feed_machine_name', $name)
      ->execute();
  }

  /**
   * {@inheritdoc}
   */
  public static function deleteByGroup($group) {
    db_delete('feed_import_hashes')
      ->condition('feed_group', $group)
      ->execute();
  }

  /**
   * {@inheritdoc}
   */
  public static function deleteEntities($ids, $entity_type) {
    db_delete('feed_import_hashes')
      ->condition('entity', $entity_type)
      ->condition('entity_id', $ids)
      ->execute();
  }

  /**
   * {@inheritdoc}
   */
  public static function getExpired($name, $max = 0) {
    $q = db_select('feed_import_hashes', 'f')
          ->fields('f', array('entity', 'id', 'entity_id'))
          ->condition('feed_machine_name', $name)
          ->condition('expire', array(static::MARK_PROTECTED + 1, time()), 'BETWEEN');
    if ($max) {
      $q->range(0, $max);
    }
    $q = $q->execute();
    $ret = array();
    while ($r = $q->fetch(PDO::FETCH_ASSOC)) {
      $ret[$r['entity']][$r['id']] = $r['entity_id'];
    }
    return $ret;
  }

  /**
   * {@inheritdoc}
   */
  public static function rescheduleAll($name, $ttl) {
    if ($ttl) {
      $ttl += time();
    }
    db_update('feed_import_hashes')
      ->condition('feed_machine_name', $name)
      ->condition('expire', static::MARK_PROTECTED, '>')
      ->fields(array('expire' => $ttl))
      ->execute();
  }

  /**
   * {@inheritdoc}
   */
  public static function totalHashes($name = NULL) {
    $q = db_select('feed_import_hashes', 'f')
          ->fields('f', array('feed_machine_name'));
    if ($name) {
      $q->condition('feed_machine_name', $name);
    }
    $q->addExpression('COUNT(*)', 'cnt');
    $q = $q->groupBy('feed_machine_name')
            ->execute()
            ->fetchAllKeyed();
    if ($name && is_scalar($name)) {
      return isset($q[$name]) ? $q[$name] : 0;
    }
    return $q;
  }


}

/**
 * This class implements SQL hash storage compatible with version 2.x
 */
class FeedImportSQLHashesv2Compatible extends FeedImportSQLHashes {
  // Used to generate hash.
  protected $hashPart;

  /**
   * {@inheritdoc}
   */
  public function hash(&$uniq) {
    return $this->generatedHashes[] = md5($uniq . $this->hashPart);
  }

  /**
   * {@inheritdoc}
   */
  public function setOptions(array $options, $overwrite = FALSE) {
    parent::setOptions($options, $overwrite);
    $this->hashPart = '/' . $this->group . '/' . $this->entity;
  }
}
