(function($) {
  Drupal.behaviors.DatePopupTimepicker = {
    attach: function(context, settings) {
      for (var id in settings.datePopup) {
        // @todo Do we need to use .once() here? date_popup doesn't use it for some reason.
        if (settings.datePopup[id].func === 'date_popup_timepicker__timepicker') {
          $('#'+ id, context).once('date-popup-timepicker')
            .timepicker(settings.datePopup[id].settings);
        }
      }
    }
  };
})(jQuery);
