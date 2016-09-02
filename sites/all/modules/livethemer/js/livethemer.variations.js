(function ($) {  
  
  Drupal.liveThemer.variations = {
  //var V = this;
    /* 
   * Set up the inspector's VARIATIONS area. 
   */
  variations: $('.lt-inspector-section-variation'),

  variationsInfo: {
    viewportWidth: null,
    
    setViewportWidth: function(){
      var vInfo = this; // Store a reference to the variationsInfo object.
      vInfo.viewportWidth =  parseInt($('div.variations-list').width());
    },
    
    pages: function(){
      var vInfo = this; // Store a reference to the variationsInfo object.

      var liWidth = vInfo.listItemWidth();
      var viewportWidth = vInfo.viewportWidth();
      
      var pageSize = parseInt(viewportWidth / liWidth);
      //var jumpDistance = variationWidth * numberCurrentlyVisible;
      return pageSize;
    },
    
    listItemWidth: function(){
      return $('ul.variation-list li').outerWidth(true);
    },
    
    visibleListItems: function(){
      var vInfo = this; // Store a reference to the variationsInfo object.

      // Set the viewport width.
      vInfo.setViewportWidth();
      
      // Return the amount list items that would fit in the viewport.
      return parseInt(vInfo.viewportWidth / vInfo.listItemWidth());
    }
  },

  /**
   * Add a class to the active variation.
   */      
  variationsMakeActive: function(variationId){
    var V = this;
    var I = Drupal.liveThemer.inspector; // Store a reference to the Inspector.
    var S = I.scopes;
    // If a variation type has been previously selected then find the corresponding list
    // item, otherwise find the 'default'/noVariation list item.
    if (typeof S.currentScope.appliedVariation === 'object') {
      var currentVarId = S.currentScope.appliedVariation.variation_id;
      var activeVariation = V.variations.find('li.'+currentVarId);
    }
    else {
      var activeVariation = V.variations.find('li.noVariation')
    }
    
    // Click it!!    //TODO: check we have activeVariation.
    activeVariation.click();
  },

  initialiseVariations: function(){
    var V = this;
    var I = Drupal.liveThemer.inspector; // Store a reference to the Inspector.
    if (V.variations.length == 0) {
      markup = '<div class="lt-inspector-section-variation">';
      markup += '<div class="variations-list">';
      markup += '<ul class="variation-list clear-block"></ul>';
      markup += '</div>';
      markup += '</div>';
      
      // Append the empty variations list ready to have variations loaded into it, then hide it.
      I.liveThemerInspectorBody.append(markup);
      V.variations = $('.lt-inspector-section-variation');
      //this.variations.hide();
      
      // Add the prev/next buttons.
      V.variationsScroll.setup();
    }        
  },
        
  /**
   * Scrolling behaviours for the variations area. 
   */
  variationsScroll: {        
    /**
     * Initial setup to add the markup
     */
    setup: function(){
      var varScroll = this;
      var I = Drupal.liveThemer.inspector;//varScroll.I;
      var V = Drupal.liveThemer.variations;
      var prev = $('<span class="prevPage variations-control"></span>');
      var next = $('<span class="nextPage variations-control"></span>');
      var variationsList = V.variations.find('div.variations-list');

      // Add the prev and next buttons.
      variationsList.before(prev).after(next);
      
      // Find the prev/next buttons and hide them.
      varScroll.controls = V.variations.find('.variations-control');
    },
  },
        
  /* 
   * Load all the variations and then fade in. 
   */
  loadVariations: function () {
    var V = this; // Store a reference to the Inspector.
    var I = Drupal.liveThemer.inspector;
    var S = I.scopes;
    var variationTypeId = I.currentVariationTypeId;

    var currentVariationType = I.variationTypes[variationTypeId];
    var variations = currentVariationType.availableVariations;
    var pathToLiveThemer = Drupal.settings.pathToLiveThemer;

    // Find the variations list and empty it (whether there was something in there or not).
    var variationsList = V.variations.find('ul');
    variationsList.empty();
    
    // Add the "no variation" option which is always there.
   	variations.noVariation = {
   	  name: 'No Variation at this scope',
   	  variation_id: 'noVariation',
	      thumbnail: '/no-variation.png',
	      path: pathToLiveThemer + '/images'
   	};

   	variations.moreVariations = {
   	  name: 'Get More variations',
   	  variation_id: 'moreVariations',
	      thumbnail: '/more-variations.png',
	      path: pathToLiveThemer + '/images'
   	};

    // For each variation:
    $.each(variations, function(variationId, variationObj){
      var basePath = Drupal.settings.basePath;
      // Build a list item and make it a jQuery object.
      var thumb = basePath + pathToLiveThemer + '/images/lt-default-thumb.png';
      if( variationObj.thumbnail) {
        thumb = basePath + variationObj.path + variationObj.thumbnail;
      }  
      var listItem = $('<li><img src="' + thumb + '"><h3>' + variationObj.name + '</h3></li>');

      // Add all the list items to the variations list and give them an appropriate class.
      listItem.hide();
      variationsList.append(listItem);
      listItem.fadeIn('slow');
      listItem.addClass(variationId);
      
      // We want to add a click event that applies the selected style to all objects in the selected scope 
      // and display the configure cog.
      listItem.click(function(){
        // Stop the click if this list item is already active.
        if ($(this).hasClass('active')) {
          return false;
        }

        if (variationId == 'moreVariations') {
          window.open('http://livethemer.com/incoming/'+currentVariationType.variationTypeId, '_blank');
          return false;
        }
      
        // Reset any form field settings that may have been made previously.
        I.currentSettingsFormData = null;
        I.currentSettingsFormDataClass = null;
        I.currentListItem = $(this);

        // Set some properties for use later.
        I.selectedVariationId = variationId;           

        // If the variation type has NOT been changed as a result of this click, we must have arrived
        // here via a programatic .click() as part of the setup, so we don't want to do
        // things like applying this variation, or saving. However we do want to load the settings form associated with 
        // this variation if there is one.
        //
        // The current object might also have never had a variation applied, in which case the variation_id
        // will be "noVariation".
        if (typeof S.currentScope.appliedVariation === 'object') {
          if (S.currentScope.appliedVariation.variation_id == variationId) {
            if (I.variationHasSettingsForm()) {
              I.loadVariationSettingsForm();
            }
            return false;
          }
        }
        else {
          // Do nothing more if the previous selection was noVariation and this variation is also noVariation.
          if (variationId === 'noVariation') {
            return false;
          }
        }

        // Add or remove the 'has-variation' class from the active scope list item depending on what was clicked.
        var currentScopeId = S.currentScope.scopeIndex;
        var currentScopeLi = $('ul.scope-selector li[scopeindex = '+ currentScopeId +']');

        if ($(this).hasClass('noVariation')) {
          currentScopeLi.removeClass('has-variation');
        }
        else if(!currentScopeLi.hasClass('has-variation')) {
          currentScopeLi.addClass('has-variation');
        }

        // Apply the variation.
        V.applyVariation(variationId, variationTypeId);
        return false;
      });
    });

    // Move the "no variation" option to the very start of the list
    var noVariationItem = variationsList.find('li.noVariation');
    variationsList.prepend(noVariationItem);
    
    if (typeof V.variations.pager == 'object') {
      V.variations.pager.reload();
    }
    
    // Fade in the variations.
    V.variations.show();
  },
  
  /*
   * Apply the given variation to the group of objects specified in inspector.currentScope
   */
  applyVariation: function(variationId, variationTypeId) {
    var V = this;
    var I = Drupal.liveThemer.inspector; // Store a reference to the Inspector.
    var S = I.scopes;
    
    // Reset a few inspector properties.
    var currentVariationType = I.variationTypes[variationTypeId];
    var variations = currentVariationType.availableVariations;
    var newVariation = variations[variationId];
    var newVariationClass = I.classPrefix + variationId;
    var objectsToRebuild = [];

    $.each(S.currentScope.matchingObjectIds, function(i, objectId){
      var oldVariationId = '';
      var oldVariationClass = '';
      var thisObject = $('.livethemer-object-' + objectId + '.livethemer-hook-'+ I.currentObjHook);
      var classes = thisObject.attr('class').split(' ');          
      var variationClassesFound = [];

      // Go through each of the classes on this object. We're looking for
      // the existence of the differentiating class.
      $.each(classes, function(i, val){
        // Have we found a differentiator class?
        if (val.match(I.classPrefix) == I.classPrefix) {
          // This object contains a class variation-varid, meaning we have
          // themed this object with Livethemer previously.
          variationClassesFound.push(classes[i]);
        }
      });
                
      // Did we find a differentiator class?
      if (variationClassesFound.length > 0) {
        // Go through each variation class found and see if any are of the
        // same variation type as the one we are applying.
        $.each(variationClassesFound, function(i, variationClass){
          tempVariationId = variationClass.replace(I.classPrefix, '');
          if (typeof variations[tempVariationId] == 'object') {
            oldVariationId = tempVariationId;
            oldVariationClass = I.classPrefix + oldVariationId;
            return true; // Break out of the .each() loop.
          }           
        })
      }

      // Drupal 7 provides html.tpl.php but we don't allow that to be
      // switched dynamically. However, we do allow switching page.tpl.php variations.
      // Since we don't want to ever rebuild html-hook objects, we force our way
      // as needed through the logic in the rest of this function.
      var objectIsHtml = (I.currentObjHook === 'html');
      // thisObject.attr('tagName') === 'BODY';  //check for BODY which should be the HTML hook.

      // See if this object has already been themed using the same template file as the new variation
      // -- OR -- the variation has the regenerate_markup flag set to true.
      // If neither are true, we will add it to an array of objects to fetch from json.            
      var existingVariation = variations[oldVariationId] || {};
      var thisVarMustRegen = ("regenerate_markup" in newVariation) ? newVariation.regenerate_markup : false;
      var regenMarkup = (
        existingVariation.template_file !== newVariation.template_file 
        || thisVarMustRegen == true
      );
     
      var switchingToNoVariation = (variationId === 'noVariation');
      
      var scopesUsed = I.themableObjects[I.currentObjHook][objectId].scopesUsed[variationTypeId];
      var currentScopeIndex = S.currentScope.scopeIndex;

      if (!regenMarkup || objectIsHtml || switchingToNoVariation) {
       
        // It's a css- or js-only change, not a markup change, so just add a class now to make it all happen.
        // First though we must remove any classes that were added for the existing (old) variation eg
        // variation-school-desk AND variation-school-desk-node-this-page
        foundVariationClass = I.classPrefix + oldVariationId;
        thisObject.removeClass(foundVariationClass);
        
        // Remove existing class(es) that begin with oldVariationClass +'-'
        // eg variation-block-green-5-this-object
        //
        // TODO: jh Apr 14: should we only be removing the class that's
        // here for the currently active scope? *********************************************
        var objectClasses = thisObject.attr('class').split(' ');
        var str = oldVariationClass +'-';
        $.each(objectClasses, function(i, myClass) {
          if (myClass.match("^"+str)==str) {
            thisObject.removeClass(myClass);
          }
        });
        
        // The new variation may be "noVariation" but we'll only get here if it's the page object, which
        // we're handling as a special case. 
        thisObject.addClass(newVariationClass);
          
        if (variationId != 'noVariation') {
          // Store the fact that we just set a variation on this object for this scope Id. We want to know
          // this so that we don't apply variations for broader scopes than this one.
          scopesUsed[currentScopeIndex] = true;
        }
        else {
          // The user has just removed a variation setting for this scope, so set the current scope's
          // record to false for this object.
          scopesUsed[currentScopeIndex] = false;
        }

        // Now that we've removed the old variation class, see if any still
        // exist in the DOM. If there aren't any, then we know that variation
        // is no longer in use, so we will remove its CSS and JS.
        if (existingVariation && $('.' + foundVariationClass).length == 0) {
          // Remove the stylesheet(s).
          $(existingVariation.stylesheets).each(function(i){
            $('link[href*="' + existingVariation.stylesheets[i] + '"]').remove();
          });
          
          // Remove the javascript(s).
          $(existingVariation.scripts).each(function(i){
            $('script[src*="' + existingVariation.scripts[i] + '"]').remove();
          });
          
        }
      }
      else {
        objectsToRebuild.push(objectId);
          
        // Store the fact that we just set a variation on this object for this scope Id. We want to know
        // this so that we don't apply variations for broader scopes than this one.
        scopesUsed[currentScopeIndex] = true;
      }
      
/*
      // Remove existing class(es) that begin with newVariationClass +'-' eg variation-block-green-5-this-object
      var objectClasses = thisObject.attr('class').split(' ');
      var str = newVariationClass +'-';
      $.each(objectClasses, function(i, myClass) {
        var classFound = (myClass.match("^"+str)==str);
        if (classFound) {
          thisObject.removeClass(myClass);
        }
      });
*/

      // Add a class to allow us to target changes made in the settings form, if any.
      var settingsFormIdentifyingClass  = newVariationClass +'-'+ I.objectScopeIds[objectId].cssClass[currentScopeIndex];              

      thisObject.addClass(settingsFormIdentifyingClass);
    });

    S.currentScope.appliedVariation = newVariation;

    // objectsToRebuild is a list of all the objects which need their markup regenerated
    I.objectsToRebuild = objectsToRebuild;

    // Load the settings form (if there is one) for the variation that was just applied.
    if (I.variationHasSettingsForm()) {
      I.loadVariationSettingsForm();
    }
    else {
      I.saveAndUpdate();
    }
    
   var now = new Date(); //?? TODO: What's this for?

          
    if (variationId == 'noVariation') {
      //console.log('TODO: check to see if there is a less specific scope and apply that.');
    }
  },
  }
})(jQuery);  