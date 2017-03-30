/**
 * @file
 * The main javascript file for the users_export module
 */
(function ($, Drupal) {
  Drupal.behaviors.usersExport = {
    attach: function (context, settings) {
      // Alter the extension suffix on the filename form input on the admin export form.
      $('#edit-users-export-type', context).change(function () {
        var id        = $(this).val(),
            extension = settings.usersExport[id].extension;
        $('#edit-users-export-filename+.field-suffix').html(extension);
      });
    }
  };
})(jQuery, Drupal);
