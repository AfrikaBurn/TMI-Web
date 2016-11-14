/**
 * @file
 * Settings restricted values on date fieldset.
 */

(function ($) {
  Drupal.behaviors.blockByDateSettings = {
    attach: function (context) {
      $('fieldset#edit-dates-between', context).drupalSetSummary(function (context) {
        var vals = [];
        $('#edit-from-date-timeEntry-popup-1').keydown(function(e) {
          if (e.keyCode == 8) {
            $('#edit-from-date-timeEntry-popup-1').val("");
          }
        });
        $('#edit-to-date-timeEntry-popup-1').keydown(function(e) {
          if (e.keyCode == 8) {
            $('#edit-to-date-timeEntry-popup-1').val("");
          }
        });
        var todate_checkbox = $('input[type="checkbox"]:checked', context).val();
        if ($('#edit-from-date-datepicker-popup-0', context).val() != undefined) {
          var from_date = $('#edit-from-date-datepicker-popup-0', context).val();
        }
        else {
          var from_date = $('#edit-from-date-year', context).val();
        }
        if ($('#edit-to-date-datepicker-popup-0', context).val() != undefined) {
          var to_date = $('#edit-to-date-datepicker-popup-0', context).val();
        }
        else {
          var to_date = $('#edit-to-date-year', context).val();
        }
        if (from_date != '' || todate_checkbox != undefined && to_date != '') {
          if (from_date != '' && todate_checkbox == undefined && to_date == '') {
            vals.push(Drupal.t('Restricted by From Date.'));
          }
          else if (from_date != '' && todate_checkbox == undefined && to_date != '') {
            vals.push(Drupal.t('Restricted by From Date.'));
          }
          else if (from_date != '' && todate_checkbox == 1 && to_date == '') {
            vals.push(Drupal.t('Restricted by From Date.'));
          }
          else if ((from_date != '' && todate_checkbox != undefined && to_date != '') || (from_date == '' && todate_checkbox != undefined && to_date != '')) {
            vals.push(Drupal.t('Restricted by certain from and to dates.'));
          }
        }
        else {
          vals.push(Drupal.t('Not restricted'));
        }
        return vals;
      });
    }
  }
})(jQuery);
