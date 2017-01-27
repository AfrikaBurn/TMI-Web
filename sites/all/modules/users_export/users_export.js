/**
 * @file
 * The main javascript file for the users_export module
 */
(function ($, Drupal) {
  Drupal.usersExport = {};
  Drupal.behaviors.usersExport = {};
  Drupal.behaviors.usersExport.attach = function (context, settings) {
    $('#edit-users-export-type').change(function () {
      var id        = $(this).val(),
          extension = Drupal.settings.usersExport[id].extension;
      $('#edit-users-export-filename+.field-suffix').html(extension);
    })
  }
})(jQuery, Drupal);
