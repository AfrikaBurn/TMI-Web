/**
 * Returns the real path, relative to Drupal root, of the provided URI.
 * Our "pseudo streams" such as images://, module:// or variation-id://
 * are decoded appropriately.
 *
 * This is a javascript equivalent of our PHP real_path_from_pseudo_stream() function.
 */
function realPathFromPseudoStream(uri) {
  var parts = uri.split('://');
  if (parts.length == 2) {
    var streamId = parts[0];
    var relativePath = parts[1];
    
    uri = pseudoStreamPath(streamId) +'/'+ relativePath;
  }
  
  return uri;
}

/**
 * Returns the path of the provided "pseudo stream" (relative to Drupal root).
 *
 * This is a javascript equivalent of our PHP pseudo_stream_path() function.
 */
function pseudoStreamPath(streamId) {
  var I = Drupal.liveThemer.inspector;
  switch (streamId) {
    case 'filesimages':
      return Drupal.settings.pathToFilesImages;
      break;
      
    case 'module':
      return Drupal.settings.pathToLiveThemer;
      break;    
    
    default:
      // Check if the streamId is a known variation id. If so, return the path
      // to that variation.      
      if (I.currentVariationType.availableVariations[streamId].path) {
        return I.currentVariationType.availableVariations[streamId].path +'images';
      }
  }
}

// go through every single stylesheet currently in the dom
// go through every single rule and console.log() any which have "dotted" in their rule.

/*
  console.log(Drupal.liveThemer.inspector.livethemerRules.rules);
  for (var i = 0; i < document.styleSheets.length; i++) {
    var styleshe = document.styleSheets.item(i);
    for (var j = 0; j < styleshe.rules.length; j++) {
      rule = styleshe.rules.item(j);
      if (rule.cssText.indexOf("dotted") != -1) {
          console.log('b) rule '+j);
          console.log(rule);
          console.log(Drupal.liveThemer.inspector.livethemerRules.rules[j]);
      }
    }
  }
*/

function log(str) {
	if (Drupal.liveThemer.env == 'development' && typeof(console) !== "undefined") {
		console.log('lt: ' + str);
		console.trace();
	}
}
