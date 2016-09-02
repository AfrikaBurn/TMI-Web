/**
 * @file
 * JavaScript behaviors for the mathfield module.
 */

(function ($) {
  /**
   * Custom AJAX command to update mathfields dependent on other mathfields.
   */
  Drupal.ajax.prototype.commands.mathfieldUpdate = function(ajax, response, status) {
    if (status == 'success' && ajax.event == 'mathfield:evaluate') {
      var name = $(ajax.element).attr('name');

      // Blur the mathfield element to update chained expressions.
      $(document).find('input[name="' + name + '"]').trigger('blur');
    }
  }

  /**
   * Dynamically perform trigger math expression fields.
   */
  Drupal.behaviors.mathfieldMathExpressionForm = {
    attach: function (context, settings) {
      var fields = settings.mathfield;
      for (var i in fields) {
        if (fields.hasOwnProperty(i)) {
          var $mathfield = $('input[name="' + fields[i].name + '"]', context);
          if (!$.isEmptyObject(fields[i].tokens)) {
            for (var token in fields[i].tokens) {
              if (fields[i].tokens.hasOwnProperty(token)) {
                var selector = fields[i].tokens[token].selector,
                    event = fields[i].tokens[token].event;
                $(context).delegate(selector, event, {mathfield: $mathfield}, function (e) {
                  // Trigger the mathfield ajax when a dependent field is changed.
                  e.data.mathfield.trigger({type : 'mathfield:evaluate', mathfield : $mathfield});
                });
              }
            }
          }
        }
      }
    }
  }

})(jQuery);
