/**
 * @file
 * Burnt shared javascript.
 */

'use strict';

(function ($) {

  Drupal.behaviors.burnt = {
    attach: function (context, settings) {

      $(
        function(){

          var
            $parents = $('.view-book-pages li').has('ul'),
            $currentParents = $('.view-book-pages .current').parents('li')

          $parents
            .addClass('collapsible-book-page')
            .not($currentParents)
            .addClass('collapsed-book-page')

          $('.collapsible-book-page > .views-field .field-content').click(
            function(){
              $(this)
                .parents('.collapsible-book-page')
                .first()
                .toggleClass('collapsed-book-page')
            }
          )

        }
      )
    }
  }

})(jQuery)