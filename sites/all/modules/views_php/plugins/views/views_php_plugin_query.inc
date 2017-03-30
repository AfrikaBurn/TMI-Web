<?php

/**
 * A (fake) pager plugin that wraps around the actual query.
 *
 * @ingroup views_query_plugins
 */
class views_php_plugin_query extends views_php_plugin_wrapper {

  /**
   * Implements views_plugin_query#execute().
   */
  function execute(&$view) {
    $pager = new views_php_plugin_pager();
    $pager->php_wrap($this->wrapped->pager);

    $this->wrapped->execute($view);

    // We cannot unwrap here because we need to run the pre_render functions.
    // See: views_php_plugin_pager::pre_render()
    //$pager->php_unwrap();
  }
}
