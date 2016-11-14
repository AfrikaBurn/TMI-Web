<?php

/**
 * Form constructor for the Views contact form.
 *
 * @see views_contact_form_contact_form_validate()
 * @see views_contact_form_contact_form_submit()
 * @ingroup forms
 */
function views_contact_form_contact_form($form, &$form_state, $data) {
  if (db_table_exists('contact')) {
    $count = db_select('contact', 'contact')
      ->fields('contact')
      ->execute()
      ->rowCount();
    if ($count == 0) {
      drupal_set_message(
        t('Views Contact Form module is disabled because no contact category
           is found. To get this module working properly,
           the <a href="@modulepage">contact module from core</a> needs to be
           enabled and at least <a href="@contactpage">one category must
           exist</a>.
           If you don\'t want the module contact, just enable it, disable it,
           but don\'t uninstall it.',
          array(
            '@modulepage' => url('admin/modules'),
            '@contactpage' => url('admin/structure/contact')
          )
        )
        , 'warning');
      return array();
    }
  } else {
    drupal_set_message(
      t('Views Contact Form module is disabled because the contact
         table doesn\'t exists. To get this module working properly,
         the <a href="@modulepage">contact module from core</a> needs to be
         enabled and at least <a href="@contactpage">one category must
         exist</a>.
         If you don\'t want the contact module from core, just enable it,
         disable it, but don\'t uninstall it.',
        array(
          '@modulepage' => url('admin/modules'),
          '@contactpage' => url('admin/structure/contact')
        )
      )
      , 'warning'
    );
    return array();
  }

  // Load that page even if the module is not enabled.
  module_load_include('inc', 'contact', 'contact.pages');

  // Get Drupal's default contact form by default.
  $form = drupal_retrieve_form('contact_site_form', $form_state);

  // Remove categories business
  if (isset($form['cid'])) {
    unset($form['cid']);
  }

  // Add recipients using type value so it's not rendered on frontend.
  $form['to'] = array(
    '#type' => 'value',
    '#value' => $data
  );

  return $form;
}

/**
 * Form validation handler for views_contact_form_contact_form().
 *
 * @see views_contact_form_contact_form_submit()
 */
function views_contact_form_contact_form_validate($form, &$form_state) {
  if (!valid_email_address($form_state['values']['mail'])) {
    form_set_error('mail', t('You must enter a valid e-mail address.'));
  }
}

/**
 * Form submission handler for views_contact_form_contact_form().
 *
 * @see views_contact_form_contact_form_validate()
 */
function views_contact_form_contact_form_submit($form, &$form_state) {
  global $user, $language;

  $values = $form_state['values'];
  $values['sender'] = $user;
  $values['sender']->name = $values['name'];
  $values['sender']->mail = $values['mail'];
  $emails = $values['to'];

  // Save the anonymous user information to a cookie for reuse.
  if (!$user->uid) {
    user_cookie_save(array_intersect_key($values, array_flip(array('name', 'mail'))));
  }

  // Get the to and from e-mail addresses.
  $from = $values['sender']->mail;

  foreach ($emails['emails'] as $email) {
    drupal_mail('views_contact_form', 'views_contact_form_page_mail', $email, language_default(), $values, $from);
    if ($values['copy']) {
      drupal_mail('views_contact_form', 'views_contact_form_page_copy', $from, $language, $values, $from);
    }
    watchdog('mail', '%sender-name (@sender-from) sent an e-mail.', array('%sender-name' => $values['name'], '@sender-from' => $from));
  }

  flood_register_event('views_contact_form', variable_get('contact_threshold_window', 3600));
  drupal_set_message(t('Your message has been sent.'));
}
