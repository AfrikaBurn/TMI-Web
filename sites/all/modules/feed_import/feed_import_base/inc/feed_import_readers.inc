<?php

/**
 * @file
 * This file contains implementations of feed import readers.
 */


/**
 * SimpleXML Reader class, good for small-medium XML files.
 */
class SimpleXMLFIReader extends FeedImportSimpleXPathReader {

  // Namespace uris.
  protected $nsuri;
  // Namespace names.
  protected $nsname;
  // Namespace functions.
  protected $nsfunc;

  /**
   * {@inheritdoc}
   */
  public function init() {
    // Set default required options.
    $this->options += array(
      'class' => 'SimpleXMLElement',
      'options' => array(LIBXML_NOCDATA),
      'raw' => '',
      'stream' => NULL,
    );
    $opts = 0;
    foreach ($this->options['options'] as $opt) {
      $opts |= $opt;
    }
    $this->items = FALSE;
    // Try to fetch from URL.
    if ($this->options['url']) {
      if ($ctx = $this->getStreamContext($this->options['stream'])) {
        libxml_set_streams_context($ctx);
      }
      $this->items = simplexml_load_file($this->options['url'], $this->options['class'], $opts);
    }
    // Check if raw value is submitted.
    elseif ($this->options['raw'] = trim($this->options['raw'])) {
      $this->items = simplexml_load_string($this->options['raw'], $this->options['class'], $opts);
    }
    else {
      // No raw or url resource provided.
      return FALSE;
    }
    
    // Add X inclusions, using a simple hack for SimpleXMLElement
    if (($this->items instanceof SimpleXMLElement) && ($opts & LIBXML_XINCLUDE)) {
      dom_import_simplexml($this->items)->ownerDocument->xinclude();
    }
    
    if (!$this->items) {
      return FALSE;
    }

    // Not needed anymore.
    unset($this->options['raw'], $opts);

    // Check for namespace settings.
    if (!empty($this->options['namespaces'])) {
      if (!is_array($this->options['namespaces'])) {
        $this->options['namespaces'] = static::cleanLines($this->options['namespaces']);
      }
      $this->nsname = $this->nsuri = array();
      foreach ($this->options['namespaces'] as $key => &$ns) {
        $ns = explode('=', $ns, 2);
        if (count($ns) != 2 || empty($ns[0]) || empty($ns[1])) {
          unset($this->options['namespaces'][$key]);
          continue;
        }
        list($this->nsname[], $this->nsuri[]) = $ns;
        // Set namespace.
        $this->items->registerXPathNamespace($ns[0], $ns[1]);
      }

      // Not needed anymore.
      unset($this->options['namespaces'], $ns);
      if ($this->nsname) {
        $this->nsfunc = array(NULL, 'registerXPathNamespace');
      }
    }
    else {
      $this->nsname = $this->nsuri = NULL;
    }

    if (!($this->items = $this->items->xpath($this->options['parent']))) {
      return FALSE;
    }

    return TRUE;
  }

  /**
   * {@inheritdoc}
   */
  public function get() {
    // Get next item.
    $item = array_shift($this->items);
    // Register namespaces if needed.
    if ($this->nsfunc) {
      $this->nsfunc[0] = &$item;
      array_map($this->nsfunc, $this->nsname, $this->nsuri);
    }
    return $item;
  }

}


/**
 * DomDocument XML reader
 */
class DomXMLFIReader extends FeedImportDomXPathReader {

  // Number of items returned by parent xpath
  protected $totalItems = 0;
  // Current item.
  protected $currentItem = 0;

  /**
   * {@inheritdoc}
   */
  public function init() {
    if (empty($this->options['parent']) || empty($this->options['format'])) {
      return FALSE;
    }
    $this->options += array(
      'url' => NULL,
      'raw' => NULL,
      'options' => array(LIBXML_NOCDATA),
      'php_func' => NULL,
      'recover' => FALSE,
      'normalizeDocument' => FALSE,
      'strictErrorChecking' => FALSE,
      'preserveWhiteSpace' => FALSE,
      'resolveExternals' => FALSE,
      'stream' => NULL,
      'silence_load_errors' => FALSE,
    );

    $opts = 0;
    foreach ($this->options['options'] as $opt) {
      $opts |= $opt;
    }

    list($majorv, $minorv) = explode('.', phpversion());
    $htmlok = $majorv >= 5 && $minorv >= 4;

    $doc = new DOMDocument();
    $doc->strictErrorChecking = $this->options['strictErrorChecking'];
    $doc->preserveWhiteSpace = $this->options['preserveWhiteSpace'];
    $doc->resolveExternals = $this->options['resolveExternals'];

    $silence_load = $this->options['silence_load_errors'];
    $loaded = FALSE;
    if ($this->options['url']) {
      if ($ctx = $this->getStreamContext($this->options['stream'])) {
        libxml_set_streams_context($ctx);
      }
      if ($this->options['format'] == 'html') {
        if ($htmlok) {
          $loaded = $silence_load
                      ? @$doc->loadHTMLFile($this->options['url'], $opts)
                      : $doc->loadHTMLFile($this->options['url'], $opts);
        }
        else {
          $loaded = $silence_load
                      ? @$doc->loadHTMLFile($this->options['url'])
                      : $doc->loadHTMLFile($this->options['url']);
        }
      }
      else {
        $loaded = $silence_load
                    ? @$doc->load($this->options['url'], $opts)
                    : $doc->load($this->options['url'], $opts);
      }
    }
    elseif ($this->options['raw']) {
      if ($this->options['format'] == 'html') {
        if ($htmlok) {
          $loaded = $silence_load
                      ? @$doc->loadHTML($this->options['raw'], $opts)
                      : $doc->loadHTML($this->options['raw'], $opts);
        }
        else {
          $loaded = $silence_load
                      ? @$doc->loadHTML($this->options['raw'])
                      : $doc->loadHTML($this->options['raw']);
        }
      }
      else {
        $loaded = $silence_load
                    ? @$doc->loadXML($this->options['raw'], $opts)
                    : $doc->loadXML($this->options['raw'], $opts);
      }
    }

    if (!$loaded) {
      return FALSE;
    }
    
    // Add X inclusions
    if ($opts & LIBXML_XINCLUDE) {
      $doc->xinclude();
    }
    
    unset($this->options['raw'], $opts, $opt, $htmlok, $loaded, $e);

    $doc->recover = $this->options['recover'];
    if ($this->options['normalizeDocument']) {
      $doc->normalizeDocument();
    }

    // Create xpath object.
    $this->xpath = new DOMXPath($doc);

    if ($this->options['php_func']) {
      if (!is_array($this->options['php_func'])) {
        $this->options['php_func'] = static::cleanLines($this->options['php_func']);
      }
      $this->xpath->registerNamespace('php', 'http://php.net/xpath');
      $this->xpath->registerPhpFunctions($this->options['php_func']);
    }
    
    // Check for namespace settings.
    if (!empty($this->options['namespaces'])) {
      if (!is_array($this->options['namespaces'])) {
        $this->options['namespaces'] = static::cleanLines($this->options['namespaces']);
      }
      foreach ($this->options['namespaces'] as $key => &$ns) {
        $ns = explode('=', $ns, 2);
        if (count($ns) == 2 && !empty($ns[0]) && !empty($ns[1])) {
          $this->xpath->registerNamespace($ns[0], $ns[1]);
        }
      }
      // Not needed anymore.
      unset($this->options['namespaces'], $ns);
    }
    
    $this->items = $this->xpath->query($this->options['parent']);
    if ($this->items === FALSE) {
      return FALSE;
    }
    $this->totalItems = $this->items->length;
    return TRUE;
  }

  /**
   * {@inheritdoc}
   */
  public function get() {
    if ($this->currentItem < $this->totalItems) {
      return $this->items->item($this->currentItem++);
    }
    unset($this->items);
    return NULL;
  }

}

/**
 * CunkedXML Reader class, used for huge XML files.
 */
class ChunkedXMLFIReader extends FeedImportSimpleXPathReader {
  // Default xml properties.
  protected $properties = '<?xml version="1.0" encoding="utf-8"?>';
  // Substring function.
  protected $substr = 'substr';
  // Chunk size.
  protected $size = 8192;
  // XML parent.
  protected $root;
  // SimpleXMLElement class
  protected $sxclass = 'SimpleXMLElement';

  // Tags info.
  protected $tagOpen;
  protected $tagClose;
  protected $tagLen;
  protected $tagCloseLen;

  // Read content.
  protected $content = '';
  // Fiel handle.
  protected $fh;

  /**
   * {@inheritdoc}
   */
  public function init() {
    // Check for resource location and parent xpath.
    if (empty($this->options['url']) || empty($this->options['parent'])) {
      return FALSE;
    }
    $this->options += array('stream' => NULL);

    // Check for stream options.
    if ($ctx = $this->getStreamContext($this->options['stream'])) {
      // Open the file using stream options.
      $this->fh = fopen($this->options['url'], 'rb', FALSE, $ctx);
    }
    else {
      // Open the file.
      $this->fh = fopen($this->options['url'], 'rb');
    }

    if (!$this->fh) {
      return FALSE;
    }

    // Get tag info.
    $this->root = $this->options['parent'];
    $tag = explode('/', $this->options['parent']);
    unset($this->options['parent']);
    list($tag) = explode('[', trim(end($tag)));
    if (!$tag || $tag == '*' || $tag[0] == '@') {
      return FALSE;
    }
    $this->tagOpen = "<$tag";
    $this->tagClose = "</$tag>";
    $this->tagLen = strlen($tag);
    $this->tagCloseLen = strlen($this->tagClose);

    // Create an empty array of read items.
    $this->items = array();

    return TRUE;
  }

  /**
   * {@inheritdoc}
   */
  public function get() {
    return ($this->items || $this->read()) ? array_shift($this->items) : NULL;
  }

  /**
   * {@inheritdoc}
   */
  public function setOptions(array $options, $overwrite = FALSE) {
    parent::setOptions($options, $overwrite);
    // Set substr function.
    if (!empty($this->options['substr']) && function_exists($this->options['substr'])) {
      $this->substr = $this->options['substr'];
    }

    // Set XML properties.
    if (!empty($this->options['properties'])) {
      $this->properties = $this->options['properties'];
    }

    // Set chunk size.
    if (!empty($this->options['size'])) {
      $this->size = (int) $this->options['size'];
    }

    // Check SXE class
    if (isset($this->options['class'])) {
      $this->sxclass = $this->options['class'];
    }
  }

  /**
   * Populates the $items array with xml nodes.
   */
  protected function read() {
    $substr = &$this->substr;
    // To the end of file.
    while (!feof($this->fh)) {
      // Append read content.
      if (!($this->content .= fread($this->fh, $this->size))) {
        continue;
      };
      // Loop until match some elements.
      while (TRUE) {
        // Tag open position.
        $openpos = strpos($this->content, $this->tagOpen);
        // Tag close position.
        $openposclose = $openpos + $this->tagLen + 1;
        if ($openpos === FALSE ||
            // Tag isn't finished
            !isset($this->content[$openposclose]) ||
            // Check for close tag
            !($closepos = strpos($this->content, $this->tagClose, $openposclose))) {
          if ($this->items) {
            // We have some items.
            break;
          }
          else {
            // Read more data.
            continue 2;
          }
        }
        elseif (isset($this->content[$openposclose]) &&
                $this->content[$openposclose] != ' ' &&
                $this->content[$openposclose] != '>') {
          // Remove data read so far to save memory.
          $this->content = $substr($this->content, $openposclose);
          // Not searched tag, keep looking.
          continue;
        }

        // We have data.
        $closepos += $this->tagCloseLen;

        // Create item.
        $item = $this->properties . $substr($this->content, $openpos, $closepos - $openpos);

        // Remove read data.
        $this->content = $substr($this->content, $closepos);

        // Create xml object.
        try {
          $item = simplexml_load_string($item, $this->sxclass, LIBXML_NOCDATA);
        }
        catch (Exception $e) {
          continue;
        }

        // Apply root.
        if ($item = $item->xpath($this->root)) {
          // Add to items.
          $this->items[] = reset($item);
        }
        unset($item);
      }
      // We have part of items so just return OK.
      if ($this->items) {
        return TRUE;
      }
    }
    $this->content = '';
    return FALSE;
  }

  /**
   * {@inheritdoc}
   */
  public function __destruct() {
    // Close file handle if any.
    if ($this->fh) {
      try {
        fclose($this->fh);
      }
      catch (Exception $e) {
      }
    }
  }

}

/**
 * SQL Reader class, used te read data with SQL queries.
 */
class SQLFIReader extends FeedImportUniVectorReader {

  /**
   * {@inheritdoc}
   */
  public function init() {
    // Require dsn and query.
    if (empty($this->options['dsn']) || empty($this->options['query'])) {
      return FALSE;
    }
    // Set default options.
    $this->options += array(
      'user' => 'root',
      'pass' => NULL,
      'params' => array(),
    );

    // Parse params if needed.
    if (!is_array($this->options['params'])) {
      $params = static::cleanLines($this->options['params']);
      $this->options['params'] = array();
      foreach ($params as &$param) {
        $param = explode('=', $param, 2);
        if (count($param) == 2) {
          $this->options['params'][$param[0]] = $param[1];
        }
        else {
          $this->options['params'][] = $param[0];
        }
      }
      unset($param, $params);
    }

    // Connect to db.
    $db = new PDO(
      $this->options['dsn'],
      $this->options['user'],
      $this->options['pass']
    );

    if (!$db) {
      return FALSE;
    }

    // Prepare query.
    $this->items = $db->prepare(
      $this->options['query'],
      array(PDO::ATTR_CURSOR => PDO::CURSOR_FWDONLY)
    );

    // Execute query
    if (!$this->items->execute($this->options['params'])) {
      return FALSE;
    }

    return TRUE;
  }

  /**
   * {@inheritdoc}
   */
  public function get() {
    return $this->items->fetch(PDO::FETCH_ASSOC, PDO::FETCH_ORI_NEXT);
  }

}

/**
 * CSV Reader class, used to read csv files.
 */
class CSVFIReader extends FeedImportUniVectorReader {

  // File handle.
  protected $fh;

  // Column names.
  protected $columns = FALSE;

  /**
   * {@inheritdoc}
   */
  public function init() {
    // Require url.
    if (empty($this->options['url'])) {
      return FALSE;
    }

    // Set default options.
    $this->options += array(
      'length' => 0,
      'delimiter' => ',',
      'enclosure' => '"',
      'escape' => '\\',
      'use_column_names' => FALSE,
      'stream' => NULL,
    );

    // Check for stream options.
    if ($ctx = $this->getStreamContext($this->options['stream'])) {
      // Open the file using stream options.
      $this->fh = fopen($this->options['url'], 'rb', FALSE, $ctx);
    }
    else {
      // Open the file.
      $this->fh = fopen($this->options['url'], 'rb');
    }

    if (!$this->fh) {
      return FALSE;
    }

    // Check to see if column names are used.
    if ($this->options['use_column_names']) {
      if ($this->columns = $this->get()) {
        $this->columns = array_flip($this->columns);
      }
      else {
        return FALSE;
      }
    }

    return TRUE;
  }

  /**
   * {@inheritdoc}
   */
  public function get() {
    return fgetcsv(
      $this->fh,
      $this->options['length'],
      $this->options['delimiter'],
      $this->options['enclosure'],
      $this->options['escape']
    );
  }

  /**
   * {@inheritdoc}
   */
  public function formatPath($path) {
    $path = parent::formatPath($path);
    if ($this->columns) {
      foreach ($path as &$p) {
        if (isset($this->columns[$p])) {
          $p = $this->columns[$p];
        }
      }
    }
    return $path;
  }

  /**
   * {@inheritdoc}
   */
  public function __destruct() {
    // Close file handle if any.
    if ($this->fh) {
      try {
        fclose($this->fh);
      }
      catch (Exception $e) {
      }
    }
  }

}

/**
 * JSON Reader class, used to read data from json files.
 */
class JSONFIReader extends FeedImportVectorReader {

  /**
   * {@inheritdoc}
   */
  public function init() {

    // Set default params
    $this->options += array(
      'stream' => NULL,
      'parent' => NULL,
      'raw' => NULL,
      'url' => NULL,
    );

    if ($this->options['url']) {
      // Check for stream options.
      if ($ctx = $this->getStreamContext($this->options['stream'])) {
        // Open the file using stream options.
        $this->items = json_decode(file_get_contents($this->options['url'], FALSE, $ctx));
      }
      else {
        // Open the file.
        $this->items = json_decode(file_get_contents($this->options['url']));
      }
    }
    elseif ($this->options['raw']) {
      $this->items = json_decode($this->options['raw']);
    }

    if (!$this->items) {
      return FALSE;
    }

    unset($this->options['raw']);

    // Check for parent
    if ($this->options['parent']) {
      $this->options['parent'] = $this->formatPath($this->options['parent']);
      $this->items = $this->map($this->items, $this->options['parent']);
    }

    return TRUE;
  }

  /**
   * {@inheritdoc}
   */
  public function get() {
    return array_shift($this->items);
  }

}
