(function ($) {  
  // SCOPE SELECTION AREA ///////////////////////////////////////////////////////////////////////////////////////
  Drupal.liveThemer.inspector.scopes = {
  /* 
   * Set up the inspector's SCOPE SELECTION area
   */
  scopeSelection: $('.lt-inspector-section-scope-selection', this.liveThemerInspectorBody),
  
  initialiseScopeSelection: function() {
    var I = Drupal.liveThemer.inspector; // Store a reference to the Inspector.
    var S = this;
    if (S.scopeSelection.length == 0) {
      // Markup hasn't been added to the DOM as yet, so do it now.
     var markup = '<div class="lt-inspector-section-scope-selection">';
      markup += '<h2></h2>';
      markup += '<label>Theming scope:</label><ul class="scope-selector"></ul>';
      markup += '</div>';
  
      I.liveThemerInspectorBody.append(markup);
      S.scopeSelection = $('.lt-inspector-section-scope-selection', I.liveThemerInspectorBody);
      S.scopeSelection.hide();
    }
  },
      
  /* 
   * Load all the variation types and then fade in. 
   */
  loadVariationType: function(variationTypeId){
    var I = Drupal.liveThemer.inspector; // Store a reference to the Inspector.
    var S = this;
    var V = Drupal.liveThemer.variations;
    I.currentVariationTypeId = variationTypeId;
    I.currentVariationType = I.variationTypes[variationTypeId];

    // Load the scopes available for this variation type into the inspector's scope selection area.
    S.loadScopes(I.currentVariationType);

    // Load the variations available for this variation type into the inspector's variations area.
    V.loadVariations();
    
    $('div.variations-list').data('scrollable', '');
    $('div.variations-list ul').css('left', '0');
    //console.log(I);
    // Set up the pager on the variations list.
    V.variations.pager = $('div.variations-list').scrollable({
      api: true, 
      clickable: true,
      size: V.variationsInfo.visibleListItems(),
      speed: 700,
      onReload: function(){
      var L = this; //scrollable list. 
        // This shouldn't be necessary because we are calling .reload() everytime.
        var visibleLi = V.variationsInfo.visibleListItems();
        var totalLi = L.getItems().length;
        var nav = L.getNaviButtons();
        
        if (totalLi > visibleLi ) {
          nav.filter('.nextPage').removeClass('disabled');
        } 
        else {
          nav.filter('.nextPage').addClass('disabled');
        } 
      }
    });

    V.variationsMakeActive();
    
    // Hide the spinner.        
    I.hideSpinner();
    
  },

  /* 
   * Load all the scopes and then fade in. 
   */
  loadScopes: function(currentVariationType){
    var I = Drupal.liveThemer.inspector; // Store a reference to the Inspector.
    var S = this;
    var scopes = currentVariationType.scopes;
    //var hook = self.currentHook; // remove -- not used in this function

    $('span.info', '#lt-inspector-header').html('Modifying - '+ currentVariationType.variationTypeName);
   // $('#homeicon').show();
    // Make two arrays to store the broad and specific objects. 
    var scopesBroad = [];
    var scopesSpecific = [];
    
    $.each(scopes, function(i, thisScope){
      thisScope.scopeIndex = i;
      if (thisScope.specificOrBroad === 'broad') {
        scopesBroad.push(thisScope);
      }
      else if (thisScope.specificOrBroad === 'specific') {
        scopesSpecific.push(thisScope);
      }
    });

    // Find the scope list and empty it.
    var scopeList = S.scopeSelection.find('ul.scope-selector');
    var initialScope;
    scopeList.empty();

    // Was an object on the page clicked on? If so, the "specific scopes" should be active.
    var objectIdSuppliedBool = (parseInt(I.selectedObjId) == I.selectedObjId);

    // Add each "specific scope":
    $.each(scopesSpecific, function(i, thisScope){
      // Build the list item and make it a jQuery object.
      if (objectIdSuppliedBool) {
        var item = $('<li><a href="">' + thisScope.title + '</a></li>');
      }
      else {
        var item = $('<li class="inactive">' + thisScope.title + '</li>');
      }
      
      // TODO: This wasn't here before and I don't know why, as far as I can see it's def needed, just hope 
      // it doesn't break something else.
      if (thisScope.appliedVariation) {
        item.addClass('has-variation');
        if (!initialScope) {
          initialScope = thisScope;
        }
      }

      item.attr('scopeIndex', thisScope.scopeIndex);

      // Append the li to the select list.
      scopeList.append(item);
    });

    // Add each "broad scope":
    $.each(scopesBroad, function(i, thisScope){
      // Build the list item and make it a jQuery object.
      var item = $('<li><a href="">' + thisScope.title + '</a></li>');

      if (thisScope.appliedVariation) {
        item.addClass('has-variation');
        if (!initialScope) {
          initialScope = thisScope;
        }
      }
      
      item.attr('scopeIndex', thisScope.scopeIndex);

      // Append the li to the select list.
      scopeList.append(item);
    });

    // Attach a click event to the scope list.        
    scopeList.find('li').click(function(){
      // Fire changeScope() when a user selects a different scope.
      S.changeScope($(this), currentVariationType);
    });

    // todo: allow var types to specify the starting scope?
    // If no scopes have been used, work out which scope to select by default.
    if (!initialScope) {
      // If we got here by clicking on an object, select the MOST specific scope.
      // Otherwise, if we got here directly from the inspector homepage, select
      // the LEAST specific scope.
      if (objectIdSuppliedBool && scopesSpecific.length > 0) {
        initialScope = scopesSpecific.shift();
      }
      else {
        initialScope = scopesBroad.pop();
      }
    }

    scopeList.find('[scopeIndex = '+ initialScope.scopeIndex +']').click();

    // Fade in the scope selection.
    S.scopeSelection.fadeIn('fast');
  },
  
  /*
   * Select the appropriate highlighter DIVs for all objects of the selected scope.
   */
  changeScope: function(scope, currentVariationType){
    var I = Drupal.liveThemer.inspector; // Store a reference to the Inspector.
    var S = this;
    var V = Drupal.liveThemer.variations;
    // Set up a couple of properties for use here and elsewhere.
    S.currentScope = [];
    var thisScopeIndex = scope.attr('scopeIndex');
    S.currentScope = currentVariationType.scopes[thisScopeIndex];
    S.currentScope.matchingObjectIds = [];
    
    // Add active class to the clicked scope and remove it from the previously active one.
    scope.siblings().removeClass('active');
    scope.addClass('active');

    // Remove the lt-selected class from all objects so we can add it to all the objects in the chosen scope.
    $('.livethemer-highlighter').removeClass('lt-selected').removeClass('lt-candidate');
   
    // Work out which scope each object has been themed at previously, if any. We don't want
    // to apply a variation to any object which has already been themed at a more specific scope
    // than this scope. ScopeIds are integers where 0 is the most specific scope.
    $.each(S.currentScope.candidateObjectIds, function(i, objectId){
      //remove any scope descriptions
      $('.livethemer-highlighter .highscope').empty();
      //if (inspector.themableObjects[objectId].scopesUsed){
        scopesUsed = I.themableObjects[I.currentObjHook][objectId].scopesUsed[currentVariationType.variationTypeId];
      //}
      var scopeIndexUsed = 999; // Any large number will do nicely.

      $.each(scopesUsed, function(scopeIndex, val){
        if (val == true) {
          scopeIndexUsed = scopeIndex;
          return false; // Break out of the loop.
        }
      })
      
      if (S.currentScope.scopeIndex > scopeIndexUsed) {
        //Do NOT apply variation changes
        $('.livethemer-highlighter[data-objid=' + objectId + '][data-objhook=' + I.currentObjHook + ']')
          .addClass('lt-candidate');
      }
      else {
        //console.log(self.currentScope.description);
        //Do apply variation changes
        S.currentScope.matchingObjectIds.push(objectId);
        $('.livethemer-highlighter[data-objid='+ objectId +'][data-objhook=' + I.currentObjHook + ']')
        .addClass('lt-selected');
        //Adding scope info to the highlighter.
      }
    });
    $('.lt-selected .highscope').text( 'Scope: '+ S.currentScope.description);
  

    V.variationsMakeActive();
  }
 }
})(jQuery); 