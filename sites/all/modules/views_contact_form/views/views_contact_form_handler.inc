<?php

class views_contact_form_handler extends views_handler_field_user_mail {

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['link_to_user']['#options']['views_contact_form'] = t('Contact form');
  }

  function render($values) {
    if ($this->options['link_to_user'] == 'views_contact_form') {
      // The view is empty, abort.
      if (empty($this->view->result)) {
        return;
      }

      $email = $this->sanitize_value($this->get_value($values));

      if (valid_email_address($email)) {
        $emails = array($email);
      }

      $form = drupal_get_form('views_contact_form_contact_form', $emails);
      return drupal_render($form);
    }
  }
}
