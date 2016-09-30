
<?php
/**
 * @file
 * Hooks provided by Google Recaptcha module.
 */

/**
 * @addtogroup hooks
 * @{
 */

/**
 * Alters the list of always protected forms.
 *
 * @param array $always_protected
 *   List of always protected forms.
 */
function hook_google_recaptcha_always_protect_alter(&$always_protected) {
  // Add search form to the list of always protected forms.
//  $always_protected[] = 'search_form'; todo to think about it :)
// todo provide description for other how to use hook for their custom forms via FORM_ID 
}

/**
 * Alters the list of available forms.
 *
 * @param array $available_forms
 *   List of available forms.
 */
function hook_google_recaptcha_available_forms_alter(&$available_forms) {
  // Add search form to the list of always protected forms.
//  $always_protected['search_'] = t('Search');
}

/**
 * @} End of "addtogroup hooks".
 */
