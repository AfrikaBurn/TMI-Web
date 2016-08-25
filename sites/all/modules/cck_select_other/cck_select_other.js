/**
 * @file
 * cck_select_other javascript file
 */

(function ($) {
  Drupal.behaviors.cckSelectOther = {
    attach: function (context, settings) {

      var ActionBind = this.getActionBind();

      // Prevent errors
      if (typeof settings.CCKSelectOther != 'object') return;

      $.each(settings.CCKSelectOther, function(n,MyCCKSelectOther){

        // Prevent errors
        if (typeof MyCCKSelectOther.field_id == 'undefined') return;

        var field_id = new String(MyCCKSelectOther.field_id);
        var select_id = new String(field_id + '-select-other-list');
        var text_id = new String(field_id + '-select-other-text-input');

        $(document).ready( function() {
          // We need to go up further up the element chain to work around 'add another item'
          $('select#edit-' + select_id).bind(ActionBind, function() {
            // Add parent() to hide input wrapper
            $(this).children(':selected').each(function() {
              if($(this).val() === 'other'){
                $('input#edit-' + text_id).parent().show();
              } else{
                $('input#edit-' + text_id).parent().hide();
              }
            });
          }).trigger(ActionBind);
        });
      });
    },
    /**
     * Provides a backwards-compatible way of supporting Drupal 7 core jQuery,
     * and contemporary versions of jQuery without browser detection support.
     *
     * @returns {string}
     */
    getActionBind: function() {
      var action = 'change';
      if (undefined !== $.browser && $.browser.msie === true) {
        action = 'click';
      }
      return action;
    }
  }
})(jQuery);
