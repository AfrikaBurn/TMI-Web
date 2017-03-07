/**
 * @file
 * Select All functionality for the Taxonomy Group Field widget.
 */
(function ($) {
  $(document).ready(function() {
    // Turn a group on or off if the Parent/Select All box is selected
    $("input[tgf-selector]").each(function() {
      var gid = $(this).attr('tgf-selector');
      var group = $("input[tgf-group='" + gid + "']");

      $(this).click(function() {
        group.attr('checked', $(this).is(':checked'));
      });
    });

    // Do some validation when children are clicked
    $("input[tgf-group]").click(function() {
      var gid = $(this).attr('tgf-group');
      var sibs = $("input[tgf-group='" + gid + "']");
      var checked = $("input[tgf-group='" + gid + "']:checked");

      // Unselect the parent if a child is unselected
      if ($(this).not(':checked')) {
        $("input[tgf-selector='" + gid + "']").attr('checked', false);
      }

      // Select the parent if all children are selected
      if (sibs.length == checked.length) {
        $("input[tgf-selector='" + gid + "']").attr('checked', true);
      }
    });

    // On the field settings form, remove options that do not apply to the selected
    // cardinality.
    var recheck = false;
    $("form#field-ui-field-edit-form #edit-field-cardinality").change(function() {
      var card = $(this);
      var opt_one = $("#edit-instance-tgf-parent-selectable-1");
      var opt_all = $("#edit-instance-tgf-parent-selectable-2");

      if (card.val() == 1) {
        opt_all.parent('.form-item').hide();
        if (opt_all.is(":checked")) {
          recheck = true;
          opt_one.click();
        }
        else {
          recheck = false;
        }
      }
      else {
        if (opt_one.is(":checked") && recheck) {
          opt_all.click();
        }
        opt_all.parent('.form-item').show();
      }
    });

    // Call an initial change event to set the properties.
    $("form#field-ui-field-edit-form #edit-field-cardinality").change();
  });
})(jQuery);
