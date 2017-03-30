<?php

/**
 * @file
 * SimpleMailMailSystem class definition.
 */

class SimpleMailMailSystem extends DefaultMailSystem {
  /**
   * Format a message.
   */
  public function format(array $message) {
    $message['body'] = implode("\n\n", $message['body']);
    $message['body'] = drupal_wrap_mail($message['body']);
    return $message;
  }
}
