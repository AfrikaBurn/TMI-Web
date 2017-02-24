/**
 * @file
 * D3.js tooltip extensions
 */
(function($) {
  d3 = d3 || {};

  /**
   * Creates a tooltip-like popup in svg
   *
   * @param tipjar
   *   Container to put the tooltip
   * @param x
   *   X axis of container group
   * @param y
   *   Y axis of container group
   * @param txt
   *   Text to display inside the popup
   *   @todo make more customizable
   * @param h
   *   height of container group
   * @param w
   *   width of container group
   */
  d3.tooltip = function(tipjar, txt, h, w) {

    var tooltip = {
      w: 65,
      h: 40,
      tip: {
        // The width of the triangular tip as it is on the base
        width: 12,
        // Tip length, vertically
        length: 9,
        // Tip offset point, from the very tip to the middle of the square
        offset: 22,
      },
    };

    var svg = tipjar.node();
    while (svg.tagName != "svg" && svg.parentNode) {
      svg = svg.parentNode;
    }
    w = parseInt(svg.attributes.width.textContent, 10);
    h = parseInt(svg.attributes.height.textContent, 10);

    //Precomputing the x and y attributes is difficult. Need to find a new way.
    //console.log(tipjar.node().getBBox());

    // Create a container for the paths specifically
    var img = tipjar.append("g");
    // Creates 3 identical paths with different opacities
    // to create a shadow effect
    var path = d3.tooltip.tooltipPath(tooltip);
    for (var x = 2; x >= 0; x--) {
      img.append('path')
        .attr("d", path)
        .attr("fill", (x == 0) ? '#fff' : '#ccc')
        .attr('transform', 'translate(' + x + ',' + x + ')')
        .attr('stroke', '#ccc')
        .attr('fill-opacity', function(d) {
          switch (x) {
            case 0:
              return 1;
              break;

            case 1:
              return 0.6;
              break;

            case 2:
              return 0.4;
              break;

          }
        })
        .attr('stroke-width', (x == 0) ? 1 : 0);
    }

    var offset = (tooltip.w / 2) - (tooltip.tip.offset - tooltip.tip.width);

    var textbox = tipjar.append('g')
      .attr('class', 'text')
      .attr('transform', function(d) { return 'translate(-' + offset + ',-' + tooltip.h + ')'});

    textbox.append('text')
      .text('Value:')
      .attr('text-anchor', 'start')
      .attr('dx', 5)
      .attr('dy', 8)
      .attr('font-family', 'Arial,sans-serif')
      .attr('font-size', '12')
      .attr('font-weight', 'bold');

    textbox.append('text')
      .text(txt)
      .attr('text-anchor', 'start')
      .attr('dx', 5)
      .attr('dy', 25)
      .attr('font-family', 'Arial,sans-serif')
      .attr('font-size', '12')
      .attr('font-weight', 'normal');
  };

  d3.tooltip.tooltipDefault = {
    w: 65,
    h: 40,
    // The width of the triangular tip as it is on the base
    tip : {width: 12,
    // Tip length, vertically
    length: 9,
    // Tip offset point, from the very tip to the middle of the square
    offset: 22, },
  };
  d3.tooltip.tooltipPath = function (tooltip) {
    tooltip = $.extend(true, {}, d3.tooltip.tooltipDefault, tooltip);
    return "M0,0"
      + 'l' + tooltip.tip.offset+',-' + tooltip.tip.length
      + 'l' + ((tooltip.w / 2) - tooltip.tip.width) + ',0'
      + 'l0,-' + tooltip.h + ''
      + 'l-' + tooltip.w + ',0'
      + 'l0, ' + tooltip.h
      + 'l' + (tooltip.w / 2) +',0'
      + "L0,0";
  };

})(jQuery);
