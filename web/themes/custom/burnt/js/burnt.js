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

          $('.path-admin .view-content', context).scroll(
            function(){
              var
                $this = $(this),
                viewport = $this.outerWidth(),
                content = $this.children('table').outerWidth(),
                range = content - viewport,
                position =  $this.scrollLeft(),
                ratio = position / range

              $this.css(
                'box-shadow',
                (ratio * 60 - 30) + 'px 0px 30px -30px inset #0005'
              )
            }
          ).scroll()

        }
      )
    }
  }

})(jQuery)