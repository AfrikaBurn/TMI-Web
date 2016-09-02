(function ($) {

Drupal.behaviors.liveThemer = {
  attach: function(context){

  var I = Drupal.liveThemer.inspector; // Store a reference to the Inspector.
  var V = Drupal.liveThemer.variations; // Store a reference to the variations object.
   
  //if the overlay is open we return to reduce JS conflicts. 
  if (window.location.href.indexOf('overlay') > 0){
    // Hide the inspector as it could be up having been added to the bage but not setup.  
    $('#lt-inspector').hide(); 

    return false; 
  }  
    
  // Kick things off, but only the first time this code is run.
  $('body').once('ltInspector', function(){
    Drupal.liveThemer.inspector.setup();
  });
  
  
  Drupal.liveThemer.highlighters.positionAllHighlighters();
  
  // Reposition our highlighters when the window is resized.
  $(window).resize(function(){
    Drupal.liveThemer.highlighters.positionAllHighlighters();
    
    // Reset the viewport width.
    V.variationsInfo.setViewportWidth();
  });
}

}

// We need to intercept Drupal's default collapseScrollIntoView because it messes with our inspector's settings forms' fieldsets.
// First, store the original
var originalCollapseScrollIntoView = Drupal.collapseScrollIntoView;

// Next write our own.
Drupal.collapseScrollIntoView = function (node) {
  // Only do the original collapseScrollIntoView if the inspector isn't active.
  if (!Drupal.liveThemer.inspector.container.hasClass("active")) {
    originalCollapseScrollIntoView(node);
  }
}

/*
$(window).scroll(function () { 
  return false;
});
*/


})(jQuery);