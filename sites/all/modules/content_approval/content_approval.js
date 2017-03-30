(function ($) {

  Drupal.behaviors.content_approvalFieldsetSummaries = {
    attach: function (context) {
      // node type edit form case
      $('fieldset.content_approval-node-type-edit-form-contact_informations', context).drupalSetSummary(function (context) {
        var value = $('.form-item-content-approval-setting-type input:checked').val();
        var roles_need_approval = Drupal.settings.content_approval_roles_need_approval;
        var out = 'Disabled';
        if (value) {
          out = 'Enabled' + (roles_need_approval? ', ' + roles_need_approval:'');
        }
        return Drupal.t('@summary', {
          '@summary': out
        });
      });
    }
  };

})(jQuery);