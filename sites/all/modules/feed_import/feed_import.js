
/**
 * @file
 * Javascript helper for Feed Import module
 */

(function ($) {
  Drupal.behaviors.feed_import = {
    attach: function (context, settings) {
      var fsets = $('fieldset[id^="item_container_"]', context);
      var addevent = false;
      if (context == document) {
        $('[name="add_new_item"]').bind('click', function () {
          if ($('#add-new-item-mode').attr('checked')) {
            $('#add-new-item-field option:selected').remove();
          }
          else {
            var val = $('#add-new-item-manual').val();
            $('#add-new-item-field option[value="' + val + '"]').remove();
          }
          $('#add-new-item-manual').val('');
        });
        $('[name="add_new_func"]').bind('click', function() {
          $('#func-name').val('');
        });
        addevent = true;
      }
      else if (fsets.length == 1) {
        addevent = true;
      }
      if (addevent) {
        // Get selects.
        $('select[id^="default_action_"]', fsets).each(function () {
          Drupal.behaviors.feed_import.checkSelectVisibility(this);
          $(this).bind('change', function() {
            Drupal.behaviors.feed_import.checkSelectVisibility(this);
          });
        });
        // Function names
        $('input[id^="func_name_"]', fsets).each(function () {
          Drupal.behaviors.feed_import.changeFieldsetTitle(this);
          $(this).bind('keyup', function() {
            Drupal.behaviors.feed_import.changeFieldsetTitle(this);
          });
        });
      }
    },
    checkSelectVisibility: function (elem) {
      var val = $(elem).val();
      var target = $('div[rel="' + $(elem).attr('id') + '"]');
      if (val == '0' || val == '1') {
        target.show();
      }
      else {
        target.hide();
      }
    },
    changeFieldsetTitle: function (elem) {
      var fs = $(elem).closest('fieldset[id^="item_container_"]');
      fs = fs.find('legend .fieldset-title').contents().filter(function() {
        return this.nodeType == 3 && this.nodeValue.replace(/\s*/i, '') != '';
      });
      var pos;
      if (fs.length && (pos = fs.text().indexOf(' _')) > -1) {
        var txt = fs.text().substr(0, pos + 1) + $(elem).val();
        fs.get(0).nodeValue = txt;
      }
    }
  }
}
)(jQuery);
