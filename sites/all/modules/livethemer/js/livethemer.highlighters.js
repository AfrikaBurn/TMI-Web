(function ($) {

/**
 * Livethemer Highlighters
 * The highlighter DIVs are transparent DIVs with borders which overlay livetheable
 * objects, in order to provide a means of selecting the objects below. We don't
 * simply click on the objects themselves, 
 */
Drupal.liveThemer.highlighters = {
  setup: function () {
    var I = Drupal.liveThemer.inspector; // Store a reference to the Inspector.
    var H = this;
    
    // Hide the highlighters at the very beginning of things.
    H.liveThemerHighlighters.hide();
    
    // Attach events to each highlighter DIV.
    $('.livethemer-highlighter').each(function(i,val) {
      var thisHighlighter = $(this); // The object returned by the .each()
      
      // Position the highlighters.
      H.positionHighlighter(thisHighlighter);

      thisHighlighter
        .hover(
          function(e){
            // Mouse Over       
            thisHighlighter.addClass("lt-hover");
          },
          function(e){
            // Mouse Out    
            thisHighlighter.removeClass("lt-hover");        
          }
        )
        .click(function(){
          var objId = thisHighlighter.attr('data-objid');
          var objHook = thisHighlighter.attr('data-objhook');
          if (objId == I.selectedObjId) {
            return false;
          }
          
          $('.lt-selected').removeClass("lt-selected");
          thisHighlighter.addClass("lt-selected");
          //var scope = themableObj.lastUsedScope; todo -- doesn't seem to be used? je
          I.loadObject(objId, objHook);
          
          return false;
        });
    });
  },
  
  positionAllHighlighters: function(){
    var H = this; // Store a reference to the highlighters object.
    H.actuallyPositionAllHighlighters();
    
    // Lost track of why we needed to delay highlighters.
    //window.setTimeout(H.actuallyPositionAllHighlighters, 250, true);
  },

  actuallyPositionAllHighlighters: function(){
    var H = this; // Store a reference to the highlighters object.
    $('.livethemer-highlighter').each(function(i,val) {
      H.positionHighlighter($(this));
    });
  },
  
  positionHighlighter: function(highlighter){
    var I = Drupal.liveThemer.inspector; // Store a reference to the Inspector.
    
    // Retrieve the associated themable object that this highlighter belongs to.
    var objId = parseInt($(highlighter).attr('data-objid')); // Convert to an integer.
    var objHook = $(highlighter).attr('data-objhook'); 
    
    //Another overlay check 
    var themableObj = (I.themableObjects[objHook][objId])? $(I.themableObjects[objHook][objId].domObj):false;
    
    // Position the highlighting DIV over its object, to catch any clicks above the object and
    // to show the highlighting effects
    // Some themable objects (eg page) won't have dimensions and such.
    if (themableObj && themableObj.offset()) {
      // Store the transforms (angle of rotation), then remove it so we can get accurate top
      // and left, then reapply it.
      var webkitTransformation = themableObj.css('-webkit-transform');
      var mozTransformation = themableObj.css('-moz-transform');

      var objTop    = (themableObj.offset().top);
      var objLeft   = (themableObj.offset().left);
      var objWidth  = themableObj.innerWidth();
      var objHeight = (themableObj.innerHeight());
      var zIndex    = 2000;// - objId; >> z-index is sequential now that we get our objects in the order that the theme layer calls them.
      
      var css = {
        top: objTop,
        left: objLeft,
        width: objWidth,
        height: objHeight,
        'z-index': zIndex,
        '-webkit-transform': webkitTransformation,     
        '-moz-transform': mozTransformation        
      };
                
      $(highlighter).css(css);
    }
    else {
      // If this object doesn't have dimensions (eg page) then hide its
      // highlighter DIV - we won't be using it for UI.
      $(highlighter).hide();
    }
  },
}

})(jQuery);