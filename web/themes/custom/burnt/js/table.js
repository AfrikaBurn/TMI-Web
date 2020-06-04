/**
 * @file
 * Burnt table javascript.
 */

'use strict';

(function ($) {

  var
    $body = $('body'),
    $layout = $('.layout-container')

  // Main table handler
  class table {

    constructor(tableElement){

      // DOM manipulation
      this.$table = $(tableElement)
      this.$header = this.$table.siblings('table.sticky-header')
      this.$table.wrap('<div class="table-wrapper">')
      this.$tableWrapper = this.$table.parent()
      this.$header.wrap('<div class="table-header-wrapper">')
      this.$headerWrapper = this.$header.parent().appendTo($body)

      // Event binding
      this.$tableWrapper.resize(() => this.resize()).resize()
      this.$tableWrapper.scroll(() => this.sideScroll())
      $layout.scroll(() => this.floatHeader())

    }

    /* Resizes the table, header and recalculates sizes */
    resize(){

      var
        contentWidth = this.$table.outerWidth(),
        viewportWidth = this.$tableWrapper.innerWidth()

      this.$headerWrapper.width(this.$tableWrapper.width())
      this.scrollRange = parseInt(contentWidth - viewportWidth)
      this.offset = parseInt($body.css('padding-top').replace(/px$/, ''))

      this.$headerWrapper.css(
        {
          top: this.offset,
          left: this.$tableWrapper.offset().left,
          height: $('tr', this.$tableWrapper).outerHeight()
        }
      )

      this.floatHeader()
    }

    /* Show or hide the floating header */
    floatHeader(){

      var
        tablePos = this.$tableWrapper.offset().top,
        tableHeight = this.$tableWrapper.height() - this.$headerWrapper.height()

      tablePos < this.offset && tablePos > - tableHeight
        ? this.$headerWrapper.css('display', 'block')
        : this.$headerWrapper.css('display', 'none')
      this.sideScroll()
    }

    /* Handle sideways scroll of the table */
    sideScroll(){

      var
        scrollPosition =  this.$tableWrapper.scrollLeft(),
        ratio = scrollPosition / this.scrollRange,
        style = {
          boxShadow: (
            this.scrollRange > 0
              ? (ratio * 60 - 30) + 'px 0px 30px -30px inset #0005'
              : ''
          )
        }

      this.$tableWrapper.css(style)
      this.$headerWrapper.css(style).scrollLeft(scrollPosition)
    }
  }

  // Attach behaviours to DOM
  Drupal.behaviors.afrikaburnTable = {
    attach: function (context, settings) {
      if (context == document) $(
        function(){
          $('table.sticky-enabled').scroll().each(
            function(){
              new table(this)
            }
          )
        }
      )
    }
  }
})(jQuery)