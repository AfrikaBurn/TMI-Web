(function ($) {

// Set up our object first time around.
Drupal.liveThemer = Drupal.liveThemer || {}

// Set to development mode.
Drupal.liveThemer.env = 'development';


/**
 * Setup the Livethemer Inspector.
 */
Drupal.liveThemer.inspector = {  
  // PROPERTIES
  container: {},
  liveThemerInspectorBody: {},
  liveThemerInspectorHome: {},
  liveThemerInspectorHomeIcon: {},
  liveThemerInspectorHeaderElements: {},
  
  themableObjects: {},
  themableTypes: [],
  settingsFormOpen: false,
  renderedForms: {},
  currentListItem: false,
  livethemerRules: {},

  requestId: {},
  classPrefix: {},
  basePath: {}, 

  // METHODS
  setup: function(){
    var I = this; // Store a reference to the Inspector.
    var S = I.scopes;
    var V = Drupal.liveThemer.variations;
    
    // Populate a few properties; the DOM will have fully loaded by now.
    I.container = $('#lt-inspector');
    I.liveThemerInspectorBody = $('#lt-inspector-body');
    I.liveThemerInspectorHome = $('#lt-inspector-home');
    I.liveThemerInspectorHomeIcon = $('#homeicon');
    I.liveThemerInspectorHeaderElements = $('#lt-inspector-header > *:not(h2):not(img)');
        
    I.requestId = Drupal.settings.fileId;
    I.classPrefix = Drupal.settings.classPrefix;
    I.basePath = Drupal.settings.basePath;
        
    // Stop the user closing the window if they haven't saved.
    window.onbeforeunload = function() {
      if (I.settingsFormOpen) {
        var closeDialog = $('<div id="ltdialog" title="Do you want to save?">You have unsaved changes in your settings form. Would you like to save the changes before navigating away from this page?</div>').dialog({
          resizable:false,
          modal: true,
          zIndex: 9999,
          buttons:{
            "Save": function(){
              // This will make all ajax calls to run syncronously from this point on.
              $.ajaxSetup({
                async: false
              });
              // Click the settings form Apply button.
              var settingsForm = $('form', I.settingsForm);
              $('.apply-button', settingsForm).click();
              $(this).dialog("close");            
              I.toggleInspector();
              window.location.reload();
            },
            "Discard": function(){
              $(this).dialog("close");
              I.toggleInspector();
             },
           },
         });
      }
    };

    // Drupal will have given us TWO "overrides" css files; we need to remove one entirely, and
    // preprocess the other, gleaning some useful information from it in the process.
    I.preprocessCSSfiles();
    
    // Hide the inspector upon initial page load.
    I.liveThemerInspectorBody.hide();
    I.liveThemerInspectorHomeIcon.click(function(){
      I.showHome();
    }); 
    
    $('body').click(function(){
      if (I.settingsFormOpen == true) {
        return false;
      }
      I.showHome();
    });
    
    // Set up a click function on the inspector header to open the inspector, return false if it's already open. 
    $('#lt-inspector #lt-inspector-header').click(function(){
      if (I.container.hasClass('active')) {
        return false;
      }
      else {
        I.toggleInspector();
        return false;
      }
    });
    
    $('#lt-inspector-header span.close', I.container).click(function(){
        I.toggleInspector();
        return false;
    });
            
    // Catch any clicks inside the inspector so that they aren't confused with clicks on the body.
    I.liveThemerInspectorBody.click(function(){
      // If we're flagging an error on the home page then let the clicks through so that we can link to other pages.
      if ($(this).find('#lt-inspector-home').hasClass('error')) {
        return true;
      }
      else {
        return false;
      }
    });
    
    I.setupThemableObjects();
     
    // Attach events to anchor tags in the inspector home page.
    $('a.lt-load-object', I.liveThemerInspectorHome).each(
      function(){ 
         var hook = $(this).attr('hook');
         if (I.themableTypes.indexOf(hook) >= 0) { 
           $(this).click(function(){
             I.loadObject($(this).attr('arg'), $(this).attr('hook'));
           });
         }else{
           $(this).addClass('disabled');
         }
       }    
    );
    
    // Set up the spinner.
    I.ltSpinnerBlocker();
   
    S.initialiseScopeSelection();
    V.initialiseVariations();
    I.initialiseSettingsForm();
   
    Drupal.liveThemer.highlighters.setup(); // highlighters
    I.showHome();
  },
  
  // Turn the Livethemer window on/off.
  toggleInspector: function(){
    var I = this; // Store a reference to the Inspector.
    var H = Drupal.liveThemer.highlighters;
    
    I.container.toggleClass("active");
    if (I.container.hasClass("active")) {
      H.positionAllHighlighters();
      H.liveThemerHighlighters.fadeIn('fast');
      I.liveThemerInspectorBody.slideDown("fast"); // Down actually means IN!
      I.liveThemerInspectorHeaderElements.fadeIn(1000);
      I.showBlocker();
    }
    else {
      $('#colourpick').fadeOut('fast');
      H.liveThemerHighlighters.fadeOut('fast');
      I.liveThemerInspectorBody.slideUp("slow"); // By up I mean down. :o
      I.liveThemerInspectorHeaderElements.fadeOut('slow');
      I.hideBlocker();   
    }
  },
  
  /*
   * Show the inspector "home page" (which is the one with the instructions, and the list of themable object types).
   */
  showHome: function(){
    var I = this; // Store a reference to the Inspector.

    $('#lt-inspector-header span.info').empty();
    $('#lt-inspector-header .var-type-tabs').empty();
    
    // Deselect everything
    $('.lt-selected').removeClass('lt-selected');  
    I.liveThemerInspectorBody.children().hide();
    I.liveThemerInspectorHome.fadeIn('fast');
    I.liveThemerInspectorHomeIcon.addClass('inactive');
  },
  
  /*
   * Set up some markup for a "busy spinner" (and a "blocker" div to stop anything being done while it's active)
   */
  ltSpinnerBlocker: function(){
    var I = this; // Store a reference to the Inspector.

    spinner = $('<div id="lt-spinner">Working</div>');
    blocker = $('<div id="lt-blocker"></div>');
            
    // Append the spinner just inside the inspector body.
    I.container.append(spinner);
    
    spinner.click(function(){
      return false;
    });
    
    // Append the blocker just inside the document body so we can cover the whole window with it.
    $('body').append(blocker);
    
    blocker.click(function(){
      return false;
    });
        
    // Set the spinner and blocker properties.
    I.ltSpinnerBlocker.spinner = $('#lt-spinner').hide();
    I.ltSpinnerBlocker.blocker = $('#lt-blocker').hide();
  },

  // Disable everything and show the spinner.
  showSpinner: function(msg){
    var I = this; // Store a reference to the Inspector.

    I.blockerZindex('top');
    I.ltSpinnerBlocker.spinner.html('<span>' + msg + '</span>').show();
    $('#lt-inspector-header span.close', I.container).addClass('spinner');
  },
    
  // Hide the spinner.
  hideSpinner: function(){
    var I = this; // Store a reference to the Inspector.
    
    I.ltSpinnerBlocker.spinner.fadeOut('fast');
    $('#lt-inspector-header span.close', I.container).removeClass('spinner');
    if(I.settingsFormOpen == true){
      I.blockerZindex('up');
    }else{
      I.blockerZindex('reset');
    }
  },
  
  // Show the blocker
  showBlocker: function(){
    var I = this; // Store a reference to the Inspector.
    I.ltSpinnerBlocker.blocker.show();
  },
  
  // Hide the blocker
  hideBlocker: function(){
    var I = this; // Store a reference to the Inspector.
    I.ltSpinnerBlocker.blocker.fadeOut('fast');
  },
  
  // Adjust the z-index of the blocker div depending on what we need to obscure.
  blockerZindex: function(action){
    var I = this; // Store a reference to the Inspector.
    
    // Above everything except the inspector.
    if (action == 'up') {
      var zIndex = 3000; // some highlighters had z-index of 2000
    }
    else if (action == 'top') {
      var zIndex = 9990;
    }
    // Above the page but below the highlighter divs and the inspector.
    else if (action == 'reset') {
      var zIndex = 1000;
    } 
    // This condition is untested. Make sure it works before you use it.
    else if (!isNaN(action)) {
      var zIndex = action;
    }
    
    // Adjust the z-index.
    I.ltSpinnerBlocker.blocker.css('z-index', zIndex);
  },
 
  
  // Load a themable object into the inspector. This may be either a specific object_Id eg 5,
  // or a variation type eg layout.
  loadObject: function(selectedObjId, selectedObjHook){
    var I = this; // Store a reference to the Inspector.
    var S = I.scopes;
    
    I.liveThemerInspectorHome.hide();
    I.liveThemerInspectorHomeIcon.removeClass('inactive');
   
   // this.liveThemerInspectorHomeIcon.show();
    // Only create a new scope objects variable for caching if one doesn't already exist.
   /*
    if (typeof self.loadObject.jsonCache != 'object') {
      self.loadObject.jsonCache = {};
    }
    */
    
    // Is something selected on the page eg has a block been clicked? If an object has been
    // clicked, this function will have recieved a number, otherwise if nothing was clicked
    // it will receieve a word describing the variation type that was clicked eg layout
    I.selectedObjId = selectedObjId;
    I.currentObjHook = selectedObjHook;
    var url = Drupal.settings.ltURL.themableObjectInfo +'/' + I.requestId + '/' + selectedObjId + '/' + selectedObjHook;

    //Show the spinner with a nice message.
    I.showSpinner('Loading object information.');   

    $('#lt-spinner').ajaxError(function(event, xhr, settings, exception) {
      I.showSpinner('Ajax error.');
      $(this).addClass('lt-error');
    });
        
    $.getJSON(url, function(json){
      // Store the variation types on the inspector so that we can load them in at will.
      I.variationTypes = json.availableVariationTypes;
      //self.currentHook = json.hook;
      I.objectScopeIds = json.objectScopeIds;

      // Our JSON describes which objects on the page have a variation applied at each possible scope,
      // for each variation type. For example, is there a "typography" variation chosen for scope "this object" for
      // object ID 0?
      $.each(json.objectsWithScopeVariation, function(objectId, variationTypeIdScopesUsed){
        I.themableObjects[selectedObjHook][objectId].scopesUsed = variationTypeIdScopesUsed; 
      })

      // There may well be more than one variation type for the given hook. 
      // If there is then we want to provide each as a tab across the top of the inspector.          
      var listItems = '';

      $.each(json.availableVariationTypes, function(variationTypeId, variationObj){
        //var anchor = Drupal.theme('link', variationTypeId, '#');
        
        //Find out if this tab has any variations applied.
        var appliedClass = '';
        for (x = 0; x < variationObj.scopes.length; x++ ) {
          if (variationObj.scopes[x].appliedVariation) {
             appliedClass = 'has-variation';
             break;
          } 
        }  
        listItems += '<li class="var-type-'+ variationTypeId +' '+ appliedClass+'" vartypeId="'+ variationTypeId +'" title ="'+ variationObj.description +'"><a href="">'+ variationObj.title +'</a></li>';
      });
      //var tabMarkup = Drupal.theme('itemList', listItems, {'class': 'tabs'});
      
      // If the ul already exists, just empty it and show it, otherwise build the markup.
    //  var ul = ($('ul.var-type-tabs').length > 0) ? $('ul.var-type-tabs').empty().show() : '<ul class="var-type-tabs clear-block"></ul>';
     // self.liveThemerInspectorBody.append(ul);
    //  var tabs = self.liveThemerInspectorBody.find('ul.var-type-tabs').append(listItems);
      $('ul.var-type-tabs').empty().show() ;
      var tabs = $('ul.var-type-tabs').append(listItems);
      var tabItems = tabs.find('li');
      
      // When a tab is clicked, add an active class and load the variation type. 
      tabItems.click(function(){
        if (I.settingsFormOpen == true) {
          return false;
        }
      
        tabItems.filter('.active').removeClass('active');
        $(this).addClass('active');
        
        S.loadVariationType($(this).attr('vartypeId'));
      });
     
      // Activate the tab for this selected object id. 
      var intCheck = parseInt(selectedObjId);
      if (isNaN(intCheck)) {
        $('ul.var-type-tabs li.var-type-'+ selectedObjId).click();
      }
      else {
        $(tabItems[0]).click();
      }
    });

  },

  
  /*
  * Save the information required to reproduce the user's choices in the
  * Drupal theme layer. Then, get the markup for any objects which are being
  * rethemed at a markup level (as opposed to just css or js changes).
  * We need to do the json call to get the new template markup, which will
  * come with a new diff class. eg variationId = 'block_var1'
  *
  * @param ???
  *   The array of the ????
  *
  */
  saveAndUpdate: function(objectsToRebuild) {
    var I = this; // Store a reference to the Inspector.
    var H = Drupal.liveThemer.highlighters;
    var S = I.scopes;
    var basePath = Drupal.settings.basePath;
    
    var objectsToRebuild = (typeof I.objectsToRebuild === 'object') ? I.objectsToRebuild : {};
    
    // If we don't have a currentScope.appliedVariation then we're saving the
    // default form values and as such currentScope.appliedVariation won't
    // exist yet. So we're using inspector.selectedVariationId instead. Without this
    // the default styling from the settings form won't be applied on page load.
    var appliedVariation = S.currentScope.appliedVariation;
    var newVariation = appliedVariation ? appliedVariation : I.selectedVariationId;
    //var newVariation = self.currentScope.appliedVariation;
    var variationId = newVariation.variation_id;
    // Set up the variation settings form data, if there is any.
    var variationData = '';
    var variationDataClass = '';
    if (typeof I.currentSettingsFormData == 'object') {
      variationDataClass = I.currentSettingsFormDataClass;
      variationData = JSON.stringify(I.currentSettingsFormData);
    }
    
    var url = Drupal.settings.ltURL.saveUpdate +'/' + I.requestId;
    I.showSpinner('Saving.');
    
    $('#lt-spinner').ajaxError(function(e, xhr, settings, exception) {
      I.showSpinner('Ajax error.');
      $(this).addClass('lt-error');
    });

    $.post(url,
      {currentVariationTypeId: I.currentVariationTypeId,
      currentObjectHook: I.currentObjHook,
      currentScope: S.currentScope.scopeId,
      objectId: I.selectedObjId,
      variationId: variationId,
      variationDataClass: variationDataClass,
      variationData: variationData,
      objectIdsToRebuild: objectsToRebuild.toString()
      },
    function(json) {
      // If there are objects that need rebuilding...
      if (objectsToRebuild.length > 0) {
        // We need to do the json call to get the new template markup, which will come with a new diff class.
        // eg variationId = 'block_var1'
        //var url = Drupal.settings.basePath + 'lt-json/retheme-objects/' + I.requestId + '/' + variationId + '/' + objectsToRebuild.toString();

        I.showSpinner('Fetching variation.');

        // For each matched object, update its markup dynamically
        changedObjects = [];
        for (i in json.objectsMarkup) {
          var jsonObj = json.objectsMarkup[i];
          var objId = jsonObj['id'];
          var thisObject = $('.livethemer-object-' + objId + '.livethemer-hook-'+ I.currentObjHook);
          thisObject.hide();

          if (jsonObj['markup']) {
            // Change this object, then re-get it (due to a js oop quirk)
            thisObject.replaceWith(jsonObj['markup']);
            var thisObject = $('.livethemer-object-' + objId + '.livethemer-hook-'+ I.currentObjHook);

/*
            // Attach each new themable object as a property of its highlighter object. We may
            // have many, as one new object may contain other themable objects.
            inspector.setupThemableObjects();
*/
            
            changedObjects.push(thisObject);
          }
          
          // Switch the differentiating class on each object.
          //var currentObj = $('.livethemer-object-' + objId);
          thisObject.fadeIn("slow");
                        
          // Reposition the highlighters. We probably don't need this anymore because we are repositioning at the top
          //var highlighter = $('.livethemer-highlighter[objid='+jsonObj['id']+']').attr('objid', jsonObj['id']);
          //self.positionHighlighter(highlighter);
          //self.hideSpinner();
        }
        
        // Attach each new themable object as a property of its highlighter object. We may
        // have many, as one new object may contain other themable objects.
        I.setupThemableObjects();

        Drupal.attachBehaviors(changedObjects); // Reattach behaviours, to attach our click() behaviour to any content newly added by the above json call

      }
      
      // Load the CSS and JS for the new variation if it has them
      if (newVariation.stylesheets) {
        $.each(newVariation.stylesheets, function(i, stylesheet){
          var cssFile = basePath + newVariation.path + stylesheet + '?';
          // Pause everything while we load the file, so we know the code following this (such as highlighter
          // div positioning) will run instantly. 
          $.ajax({
            url: cssFile,
            async: false,
          });
          
          // Only add a new stylesheet if it's hasn't already been added. Note the ^= (starts with) 
          // because when the page is rebuilt the href can have a letter after the ? eg ?Y.
          if ($('head').find('link[href ^= "'+cssFile+'"]').length == 0) {
            // adding a title attribute to this link caused the css to not be added properly.
            // Strange but true. Stupid thing is that it was working just fine before.
            var overrides_stylesheet = $('head').find('style[title = livethemer-overrides]');

            overrides_stylesheet.before('<link type="text/css" rel="stylesheet" media="all" href="'+cssFile+ I.randomAlphNum()+'" />');
          }
        });
      }

      if (newVariation.scripts) {
        // "scripts" property is an array of javascript files to add.
        $.each(newVariation.scripts, function(i, scriptFilename){
          var scriptFile = basePath + newVariation.path + scriptFilename + '?';

          if ($('script[src ^= "'+scriptFile+'"]').length == 0) {
            // We have to do this old school because of the way jQuery handles script tags. 
            // See: http://stackoverflow.com/questions/610995/jquery-cant-append-script-element
            var script   = document.createElement("script");
            script.type  = "text/javascript";
            script.src   = scriptFile + I.randomAlphNum();    
            $('head').append(script);
            
            // Pause everything while we load the file, so we know the code following this (such as 
            // Drupal.attachBehaviors) will run instantly. 
            $.ajax({
              url: scriptFile,
              async: false,
            });

          }
        });
        
        
        // todo: josh, any idea why we have to delay the following? :( I even put in a preloader for the js
        // file above in case the file hadn't yet been loaded by the time this code ran but still no luck.
        Drupal.attachBehaviors();
       // window.setTimeout(Drupal.attachBehaviors, 500, true); // is 500 enough only because of my server speed?
      }

      // Replace Drupal.settings.livethemerVariables with the new variables.
      Drupal.settings.livethemerVariables = json.livethemerVariables;
      
      // Make sure the form override stylesheet is still the last css file in the head.
      // inspector.reorderStylesheets(); //TA not needed?
      
      // Reposition the highlighter. --TODO: this doesn't seem to be late
      // enough in some cases. Not sure why -Josh.
      H.positionAllHighlighters();
      
      // Hide the spinner.
      I.hideSpinner();
      
    },
    'json'); // Give us the results as JSON please.
  },
  
  setupThemableObjects: function() {
    var I = this; // Store a reference to the Inspector.
    var H = Drupal.liveThemer.highlighters;
    
    var highlighters = '';
    //$('.livethemer-highlighter').remove();

    // Set up the themableObjects as an array of all themable objects on the page.        
    $('*[class*="livethemer-object-"]').each(function(i, val) {

      // This DOM object contains a class livethemer-object-x and livethemer-hook-x. We need to
      // extract the value of x from this class, as this tells us the object id/hook.
      var classes = $(this).attr('class').split(' ');
      var objId;
      var objHook;
      $.each(classes, function(i, thisClass){
        var obj = thisClass.indexOf('livethemer-object-');            
        if (obj !== -1) {
          objId = thisClass.replace('livethemer-object-', '');
        }
        var hook = thisClass.indexOf('livethemer-hook-');            
        if (hook !== -1) {
          objHook = thisClass.replace('livethemer-hook-', '');
        }
      });

      // Add the highlighter DIV markup if it wasn't already added previously,
      // and initialise the themableObjects array.
      if ($('.livethemer-highlighter[data-objid='+ objId +'][data-objhook='+ objHook +']').length === 0) {
        var highlighter = '<div class="livethemer-highlighter" data-objid="' + objId +'" data-objhook="' + objHook + '"><span class="highinfo">' + objHook + ' - ' + objId + '</span><span class="highscope"></span></div>';
        highlighters += highlighter;
      
        // Initialise this the first time around.
        if (typeof I.themableObjects[objHook] !== 'object') {
          I.themableTypes.push(objHook);
          I.themableObjects[objHook] = {};
        }
        if (typeof I.themableObjects[objHook][objId] !== 'object') {
          I.themableObjects[objHook][objId] = {};
        }
        I.themableObjects[objHook][objId].highlighter = $(highlighter);
      }
      
      
      I.themableObjects[objHook][objId].domObj = $(this);   

    });
    
    $('body').append(highlighters);
    H.liveThemerHighlighters = $('.livethemer-highlighter');
  },

////
  
  getSelectedVarition: function(){
    var I = this; // Store a reference to the Inspector.

    var varType = I.currentVariationTypeId;
    var varId = I.selectedVariationId;
    return I.variationTypes[varType].availableVariations[varId];
  },
    
  /* 
   * Set up the inspector's Variation Settings Form area.
   */
  settingsForm: $('#lt-inspector-settings-form', this.liveThemerInspectorBody),
  
  initialiseSettingsForm: function() {
    var I = this; // Store a reference to the Inspector.

    if (I.settingsForm.length == 0) {
      // Markup hasn't been added to the DOM as yet, so do it now.
      markup = '<div id="lt-inspector-settings-form">';
      markup += '<h3 class="settings-form-header">header; todo: remove this text</h3>';
      markup += '<div class="settings-form-body">todo remove this too</div>';
      I.liveThemerInspectorBody.append(markup);
    }
    I.settingsForm = $('#lt-inspector-settings-form', I.liveThemerInspectorBody);
  },
  
  variationSettingsFormToggle: function(action){
    var I = this; // Store a reference to the Inspector.

    //var settings = $('ul.variation-list li.active span.settings');
    // todo: could we now do var settings = inspector.currentSettingsForm;
    //var settings = inspector.currentSettingsForm;
    
    switch (action){
      case 'open':
        var top = -280;
      
      // Bump up the z-index of the blocker div so that it obscures everything except the inspector.
      I.blockerZindex('up');
      I.container.addClass('no-header');
      // Set the settingsFormOpen flag.
      I.settingsFormOpen = true;
      // Grab the settings container and stick it inside the body, positioned appropriately.
      I.settingsForm.css({
        position: 'absolute',
        top: 280,
        left: 0,
        right: 0,
        width: '100%'
      });
      
      // Show the form, add active class.
      I.settingsForm.show(); 
      I.settingsForm.addClass('active');
      
      break;  
      
      case 'close':
        var top = 0;
        
        // Bump down the z-index of the blocker div so that it doesn't obscure anything.
        I.blockerZindex('reset');
        I.container.removeClass('no-header');
        // Close the colour picker if it's open.
        $('#colourpick').fadeOut('fast');

        // Set the settingsFormOpen flag.
        I.settingsFormOpen = false;
        
        // Remove the inline styling from the settings container and put it back where it came from.
        var callback = function(){                            
          // Hide the form.
          I.settingsForm.hide();
  
          // Remove the active class from the container and fade the config cog back in.
          I.settingsForm.removeClass('active');
        }
      break;
     }
    

    // Animate it. 
    $('#lt-inspector-body').animate({
      top: top
    }, 300, callback);
  },
  
  
  /**
   * Method for adding the configuration form for variations that have one.
   * Add the configure button and a span to stick the settings form in.
   */
  variationSettingsFormSetup: function(listItem, settingsForm){
    var I = this; // Store a reference to the Inspector.

    // First check that the current variation actually has a settings form.
    if (!I.variationHasSettingsForm()) return;
     
    // Store the default values as a custom attribute so we can revert to them later on.
    var showForm = false;
    $(':input[update_action]', settingsForm).each(function(i, formField) {
      $(formField).attr('default_value', $(formField).val());
      if ($(formField).attr('type') !== 'hidden'){
        showForm = true; 
      }  
    });
    
    if (showForm) {
      listItem.append('<a class="configure" title="Configure"></a>');
      var cog = $('a.configure', listItem);
      cog.click(function(){
        I.variationSettingsFormToggle('open');
        return false; // Don't let the click event fall through any further.
      })
    };

  },
  
  /**
   * Load the variation settings form via ajax or retrieve it from cache if we already have one. 
   */
  loadVariationSettingsForm: function(){
    var I = this; // Store a reference to the Inspector.
    var S = I.scopes;
    var settings = I.settingsForm;
   
    var variationTypeId       = I.currentVariationTypeId;
    var currentVariationType  = I.variationTypes[variationTypeId];
    var selectedVariationId   = I.selectedVariationId;
    var variation             = currentVariationType.availableVariations[selectedVariationId];
    var selectedVariation     = I.getSelectedVarition();

    if (typeof I.renderedForms[selectedVariationId] == 'object' && false) {
      // The form is already in cache so use it again.
      var settingsForm = inspector.renderedForms[selectedVariationId];
      $('h3.settings-form-header', settings).html('Settings for ' + selectedVariation.name);
      $('.settings-form-body', settings).html(settingsForm);
            
      // Add the settings form cog if needed.
      I.variationSettingsFormSetup(I.currentListItem, settingsForm);            
      
      //inspector.currentSettingsForm = settingsForm;
      I.activateVariationSettingsForm();

      // Go through the form and apply any previously saved values from Drupal.settings.livethemerVariables
      I.variationSettingsFormPrepopulate();

      I.convertFieldsToWidgets(settingsForm);

      // PROPOSE WE DO A SAVE AND UPDATE
      I.saveAndUpdate();

    }
    else {
      // Fetch it from Drupal via json.
      I.showSpinner('Loading variation settings form.');
      
      var url = Drupal.settings.ltURL.settingsForm +'/' + I.requestId;
      var currentScopeId = S.currentScope.scopeId;
      var currentScopeIndex = S.currentScope.scopeIndex;
      
      // If only one object is selected, use its Id; if a broad scope is selected, look at the first
      // object only, as all selected objects will have the same broad scope identifiers.
     // var objectIdSuppliedBool = (parseInt(self.selectedObjId) == self.selectedObjId);
      if (parseInt(I.selectedObjId) == I.selectedObjId) {
        var selectedObjId = I.selectedObjId;            
      }
      else {
        var selectedObjId = S.currentScope.matchingObjectIds[0];
      }
      // Hit the php to get the form.
      var objectScopeIdentifier = I.objectScopeIds[selectedObjId].rawScopeId[currentScopeIndex];
      $.post(url,{
          //currentScopeId: currentScopeId,
          variationId: selectedVariationId
          //objectScopeIdentifier: objectScopeIdentifier,
        }, function(json) {
          if (json !== null && json.settings_form !== '') {
            var settingsForm = $(json.settings_form);
          }
          else {
            var settingsForm = $('<p class="error">Error: The settings form for this variation was not loaded. Check the url for json results. </p><p class="error">'+ url +' with '+ selectedVariationId +'</p>');
          }

          // Store this settings form so we don't have to ask Drupal for it next time.
          // Note: we are storing as a jQuery object.
          I.renderedForms[I.selectedVariationId] = settingsForm;

          // Add the settings form into the DOM.
          $('h3.settings-form-header', settings).html('Settings for ' + selectedVariation.name);
          $('.settings-form-body', settings).html(settingsForm);

          // Add the settings form cog if needed.
          I.variationSettingsFormSetup(I.currentListItem, settingsForm);       

          // Add some useful methods to the form and to each field in it eg .apply()
          I.activateVariationSettingsForm();

          // Go through the form and get any previously saved values
          // from Drupal.settings.livethemerVariables, set the fields
          // to these values, and apply to the site.
          I.variationSettingsFormPrepopulate();

					// c) make the fields look nice: make ordinary fields into magical widgets
					// (eg colourpicker, ui sliders, whatever)
					I.convertFieldsToWidgets(settingsForm);

          // PROPOSE WE DO A SAVE AND UPDATE
          I.saveAndUpdate();

          // Finish up by hiding the spinner.
          I.hideSpinner();
        },
      'json'); // Give us the results as JSON please.
    }
  },
  
  /**
   * Function_comment
   */
  convertFieldsToWidgets: function(settingsForm) {
    var I = this; // Store a reference to the Inspector.
		Drupal.liveThemer.colorPicker.addColorPickers(settingsForm);
		I.addSliders(settingsForm);
  },

  variationHasSettingsForm: function(){
    var I = this; // Store a reference to the Inspector.
    var varType = I.currentVariationTypeId;
    var varId = I.selectedVariationId;
    return (typeof I.variationTypes[varType].availableVariations[varId].settings_form == 'string') ? true : false;
  },

  /**
   *  Go through Drupal.settings.livethemerVariables and apply any changes we find there.
   */
  variationSettingsFormPrepopulate: function(){
    var I = this; // Store a reference to the Inspector.
    var S = I.scopes; // Store a reference to the scopes.
    var settingsForm = $('form', I.settingsForm);
    var hook = I.currentObjHook;
    var variationTypeId = I.currentVariationTypeId;
    var scopeId = S.currentScope.scopeId        
    var currentScopeIndex = S.currentScope.scopeIndex;
    var formAlreadyApplied = false;
    
    // If only one object is selected, use its Id; if a broad scope is selected, look at the first
    // object only, as all selected objects will have the same broad scope identifiers.
    //var objectIdSuppliedBool = (parseInt(self.selectedObjId) == self.selectedObjId);
    if (parseInt(I.selectedObjId) == I.selectedObjId) {
      var selectedObjId = I.selectedObjId;            
    }
    else {
      var selectedObjId = S.currentScope.candidateObjectIds[0];
    }
    
    var objectScopeIdentifier = I.objectScopeIds[selectedObjId].rawScopeId[currentScopeIndex];
    var ltVars = Drupal.settings.livethemerVariables;
    var currentVariation = I.getSelectedVarition();

    // If there's a rule in our data file for this variation, get its data
    if (typeof ltVars[hook] == 'object' &&
        typeof ltVars[hook][variationTypeId] == 'object' &&
        typeof ltVars[hook][variationTypeId][scopeId] == 'object' &&
        typeof ltVars[hook][variationTypeId][scopeId][objectScopeIdentifier] == 'object' &&
        ltVars[hook][variationTypeId][scopeId][objectScopeIdentifier].variation_id == currentVariation.variation_id) {
      var storedValue = ltVars[hook][variationTypeId][scopeId][objectScopeIdentifier].variation_data;
      
      // This settings form has already had its fields take effect on the DOM.
      formAlreadyApplied = true;
    }
    else {
      var storedValue = null;
    }
   
/*
    // Go through all of the form fields. If there are stored values (from our settings file) then
    // apply them, if not, then reset to its default.
    // $(':input:not([type = hidden])', settingsForm).each(function(i, formField) {
    $(':input[update_action]', settingsForm).each(function(i, formField) {
      var name = $(formField).attr('name');
      if ((storedValue != null) && (storedValue[name] != null)) {
        // We found a stored value for this field, so we now apply it.
        $(formField).val(storedValue[name]);
        if (!formAlreadyApplied) formField.apply();
      }
      else {
        // This field has no stored value, AND THE FORM ITS IN HAS NEVER BEEN MODIFIED so we set it to its default value (as
        // given to us by the variation's Drupal form array) if it has one.        
        var fieldValue = $(formField).attr('default_value');
        if ((fieldValue !== undefined || fieldValue !== '-' || fieldValue !== '') && !formAlreadyApplied) {
          $(formField).val(fieldValue);
          formField.apply();
        }
      }
      
      // Store the field's val right now so we can reset to it if the form cancel button is clicked.
      formField.lastAppliedVal = $(formField).val();
    });
*/
        

    //
    $(':input[update_action]', settingsForm).each(function(i, formField) {
      var name = $(formField).attr('name');
    
      if (formAlreadyApplied) {
        // The form has fields with their values changed, so:
        //  -- see if this field has a (non-null) value in the settings; if so, use it and apply it
        //  -- if no value in settings, don't apply anything, just set selected to - if it is a select field
        if ((storedValue != null) && (storedValue[name] != null)) {
          $(formField).val(storedValue[name]);
          formField.apply();
        }
        else {
        // if the field is a select, check what key is for the option with the text of '-'
          $(formField).val('');
        }
      }
      else {
        // The form has no fields with values in the settings file, so:
        // see if this field has a (non-null) fapi default; if so, set the field to it and apply it
        var fieldValue = $(formField).attr('default_value');
        if ((fieldValue !== undefined || fieldValue !== '-' || fieldValue !== '') && !formAlreadyApplied) {
          $(formField).val(fieldValue);
          formField.apply();
        }
        else {
          $(formField).val('');
        }
      }
      
      // Store the field's val right now so we can reset to it if the form cancel button is clicked.
      formField.lastAppliedVal = $(formField).val();
    }); 

        
        

    
    // Remove the 'collapsed-processed' class from any fieldset legends in
    // the form so that Drupal.attachBehaviors will reprocess
    // them and make them collapsible if necessary. 
    $('legend.collapse-processed', settingsForm).removeClass('collapse-processed');

    // Attach behaviours so that our fieldsets become collapsible. 
    Drupal.attachBehaviors(settingsForm);

    // Pseudo click the apply button so that we store, save and update everything properly. 
    // Bad idea? Not sure, but it seems to work for now.
    // jh/ta: 17 Feb shouldn't be saving in here: $('.apply-button', settingsForm).click();
    
    // Store all the field values before we close.
    I.variationSettingsFormStore();
      
    // Close the form.
    I.variationSettingsFormToggle('close');
  },
  
  addSliders: function(settingsForm) {
    $( ".slider", settingsForm ).slider({
      min:100, max:1400, step:100,
      change: function(event, ui) {
        $(this).parent().find('input').val(ui.value);
      }
   });
  },  
  

    
  /**
   * Method for activating the configuration form.
   */
  activateVariationSettingsForm: function() {
    var I = this; // Store a reference to the Inspector.
    var settingsForm = $('form', I.settingsForm);
    
    // Settings form Apply button.
    $('.apply-button', settingsForm).click(function(){
      
      // Store all the field values before we close.
      I.variationSettingsFormStore();
      
      // Close the form.
      I.variationSettingsFormToggle('close');
      
      // Save and Update.
      I.objectsToRebuild = {}; // Don't rebuild any objects (for now
      // -- todo, when we handle other 'update_action's)
      I.saveAndUpdate();
    });

    // Settings form Cancel button.
    $('.cancel-button', settingsForm).click(function(){
      // Revert any changes.
      //$(':input:not([type = hidden])', settingsForm).each(function(i, formField) {
      $(':input[update_action]', settingsForm).each(function(i, formField) {
        formField.resetToOriginal();
      });
      
      // Close the form.
      I.variationSettingsFormToggle('close');
    });
    
    // Go through each input in the settings form and make its value update the page accordingly.
    I.setupFormFields(settingsForm);
  },

  /**
   * Attach clever methods and properties to each form field.
   */
  setupFormFields: function(settingsForm){
    var I = this; // Store a reference to the Inspector.
    var S = I.scopes;
    
    var fieldObjectPrototype = {        
      // Apply the settings in the supplied form item so the DOM reflects the settings. This could involve 
      // applying some CSS, or inserting something new where a tpl.php variable has been printed in the
      // markup, or even totally rebuilding the markup of the currently selected objects.
      apply: function(){
        // Only enter the function if there are objects on this page
        // (matchingObjectIds) to apply the changes to.
        if (S.currentScope.matchingObjectIds.length === 0) return false;
      
        // The apply method is on a DOM object, but we want a jQuery 'this' object below.
        var thisField = $(this);
        var lastAppliedVal = this.lastAppliedVal;

        // Put together the class that is common to all the currently
        // selected objects, for this settings form.
        // eg variation-block-green-16-this-object
        // Just use the first available object - the scope ID for each
        // global scope ID is the same. 
        var objectId = S.currentScope.matchingObjectIds[0];
        var selectedObjectsClass = I.classPrefix + I.selectedVariationId +'-';
        selectedObjectsClass    += I.objectScopeIds[objectId].cssClass[S.currentScope.scopeIndex];
        I.currentSettingsFormDataClass = selectedObjectsClass;

        // Add the form settings class to each object 
        $.each(S.currentScope.matchingObjectIds, function(i, matchingObjectId){
          $(I.themableObjects[I.currentObjHook][matchingObjectId].domObj).addClass(selectedObjectsClass);
        });
        
        // Do different things depending on what the update action of this form field is.
        var updateAction = thisField.attr("update_action");
        switch (updateAction){
          // Handle fields which modify CSS attributes.
          case 'css':
            var fieldId    = thisField.attr('name');
            var cssRule    = thisField.attr("css_rule");
            var cssTarget  = thisField.attr("css_target") ? " " + thisField.attr("css_target") : "";
            var fieldValue = thisField.val();

            // If the field has been set to nothing (or '-' which is used
            // in select lists), then we will want to remove the rule.              
            if (fieldValue == undefined || fieldValue == '-' || fieldValue == '') cssRule = '';
           
            // Values with urls need to be replaced completely. Might be other special cases?
            if (cssRule.indexOf('url(') >=0 && fieldValue == 'none') {
              var spot = cssRule.indexOf(':');
              cssRule = cssRule.substring(0, spot)+':'+fieldValue+';';      
            }
            
            cssRule = I.ruleTokenReplacement(cssRule);

            I.updateStylesheet(fieldId, '.'+ selectedObjectsClass + cssTarget, cssRule);      
          break;
          case 'placeholder':
            //find the field that has the css_rule and apply.
            var fieldId = thisField.attr('update_field');
            $('input[name="'+fieldId+'"]', I.settingsForm)[0].apply();
          break;
          
          // Handle fields which modify template variables.
          case 'tpl_variable_live_update':
            var fieldValue = thisField.val();
            var tplVariable = thisField.attr("tpl_variable");
          break;

          // Handle fields which modify template classes.
          case 'tpl_variable_css_class':  
          
            // Adding a timeout here to cater for async. Bodgy but it works
            // for now. We need to fix this though. TODO: is this still a problem?
            // We have reduced to 5ms with no apparent downsides.
            window.setTimeout(function(){
              // Get the name of the current variation.
              var fieldId = thisField.attr('name');
              var cssTarget = thisField.attr('css_target');

              var objIds = S.currentScope.matchingObjectIds;
              $.each(objIds, function(i, objId){                
                // Find the element that has the class that we want to swap.
                var targetElement = cssTarget ? $(cssTarget) : $('.livethemer-object-' + objId + '.livethemer-hook-'+ I.currentObjHook);
                
                if (targetElement.length > 0) {
                  // Get all the classes, split them into an array.
                  var targetAllClasses = targetElement.attr('class');
                  var classesArray = targetAllClasses.split(' ');
                  // Work out the class we are looking for.
                  var settingsFieldClass = 'settings-field-' + fieldId;
                
                  // Find the class that we want to replace, it will always be the one after the target class.
                  var classIndex = ($.inArray(settingsFieldClass, classesArray)) + 1;
                  
                 /* if (classIndex == 0) {
                     console.error('could not find a class to replace');
                  }*/
                  
                  // Work out what the replacement class should be and then replace.
                  var replacementClass = thisField.attr('css_class').replace('%'+fieldId+'%', thisField.val());
                  var newClasses = targetAllClasses.replace(classesArray[classIndex], replacementClass);

                  // Replace the classes on the target element with the updated class string.
                  targetElement.attr('class', newClasses);
                }
              });
              Drupal.liveThemer.highlighters.positionAllHighlighters();
            }, 5, true);
          break;
          
          default:
          //console.error('this form doesn\'t have an update action');
         }

         // Store all the field values before we finish.
         //I.variationSettingsFormStore();
        
        // The changes made above will often change the physical layout of the page, so we need to
        // reposition our highlighter DIVs.
        Drupal.liveThemer.highlighters.positionAllHighlighters();
      },

      // Reset the form to the value it was when the form was first opened.
      resetToOriginal: function(){
        $(this).val(this.lastAppliedVal);
        this.apply();
      },

      // Remove any effects the form field may have made; triggered when we unapply a variation.
      unapply: function(){
        // Check what the field's update_action is.
        //    case 'tpl_variable_css_class':  

        // Work out what the field's "handle class" is, find it, and replace the following class with
        // the placeholder class. See livethemer_inspector.module's livethemer_inspector_postprocess()
        //$(this).val(this.lastAppliedVal);
        
        // josh to fill in the blanks
        
        this.apply();
      },
    };

    // Go through each input in the form, ignoring hidden inputs. 
    // Note ':input' so we get all input types (eg. input, select, textarea), not the input tag.
    //$(':input:not([type = hidden])', settingsForm).each(function(i, formField) {
    $(':input[update_action]', settingsForm).each(function(i, formField) {
      // Store the original values so we can revert if need be.
      // done above... formField.lastAppliedVal = $(formField).val();

      // Add our "prototype" methods (defined above) to each field.
      $.extend(formField, fieldObjectPrototype);
      
      // When the inputs value changes, use the apply() method attached to it.
      $(formField)
      .keyup(function(event){
        if(event.keyCode >= 48 || event.keyCode == 8) {
          $(this)[0].apply();
        }
      })
      .change(function(){
        $(this)[0].apply();  
      });
    });
  },
              
  /**
   * Store any changed settings (or pre-supplied defaults) in the form, for use elsewhere.
   */
  variationSettingsFormStore: function(){
    var I = this; // Store a reference to the Inspector.

    var settingsForm = $('form', I.settingsForm);

    // We will look at each field in the form, and if its value changed from the
    // original value it came with, we will record the field's ID and its new value.
    var fieldValues = {};
    var updateSettings = false;
   // $(':input:not([type = hidden])', settingsForm).each(function(i, formField) {
    $(':input[update_action]', settingsForm).each(function(i, formField) {
      $formField = $(formField);
      
      fieldValues[$formField.attr('name')] = $formField.val();
      updateSettings = true;

      // Store the value we have just saved for this field.
      formField.lastAppliedVal = $formField.val();
    });

    // Save the settings. fieldValues will have no entries if we didn't actually change the settings at all.
    if (updateSettings) {
      I.currentSettingsFormData = fieldValues;
    }
  },
  
  /**
   * Find the style tag where we are storing form overrides. 
   * Return just the index so that the calling function can modify document.styleSheets directly.
   */
  formOverridesStylesheetIndex: function(){
    for (var i = document.styleSheets.length-1; i > 0; i--) {
      stylesheet = document.styleSheets.item(i);
      if (stylesheet.title && stylesheet.title === "livethemer-overrides") {
        return i;
      }
    }
    return false;
  },
  
  /**
   * Build a CSS rule like "selector {rule}" where any instances of %form_field% are replaced
   * by the current value of that field in the form.
   */
  ruleTokenReplacement: function(rule) {
    var I = this; // Store a reference to the Inspector.

    // Go through each field in the form and see if the current field's css rule contains tokens
    // from those other fields, and if so, replace them.

    // We would like a regex to pull the %field-id%'s out of the rule
    // and thus only work with those that we know are actually referenced
    // in the rule. However such a regex is likely to be complex as it needs
    // to deal with the following edge cases:
/*
    line-height: %line_height%%;

    padding-left: 32px; background: url(%basepath%%h2_icon%) no-repeat left centre;
    
    -webkit-border-radius: %corner_radius%px;
    -moz-border-radius: %corner_radius%px;
    border-radius: %corner_radius%px;
    
    background-position: %background_image_position_x% %background_image_position_y%;
    
    -moz-box-shadow: %hor_offset%px %ver_offset%px %blur%px %shadow_color%;
    -webkit-box-shadow: %hor_offset%px %ver_offset%px %blur%px %shadow_color%;
    box-shadow: %hor_offset%px %ver_offset%px %blur%px %shadow_color%;
            
    -webkit-border-radius: %corner_radius%%;
    -moz-border-radius: %corner_radius%%;
    border-radius: %corner_radius%%;
    
    // nb: Tony suggests using a character other than % as our token delimiter.
*/
   var settingsForm = I.renderedForms[I.selectedVariationId];
   
   // Check the rule to see if we have our markers for replacement.
   // First split on %.
   var ruleArray =  rule.split('%');
   var pattern = /\W/; //Non word characters and underscore.
   $(ruleArray).each(function(i, ruleField) {
      // make sure we don't have any funky characters.
      if(pattern.test(ruleField) === false) {
        var field = $(':input[name="'+ruleField+'"]', settingsForm);
        // make sure we have a field.
        if(field.length > 0){
          var fieldValue = field.val();
          fieldValue = realPathFromPseudoStream(fieldValue);
          var regex = new RegExp('%'+ ruleField +'%', 'g');
          rule = rule.replace(regex, fieldValue);
        }
      }
    });

    // Replace a token or two of our own.
    var regex = new RegExp('%basepath%', 'g');
    rule = rule.replace(regex, Drupal.settings.basePath);
    return rule;
  },
  
  updateStylesheet: function(fieldId, selector, rule) {
    var I = this; // Store a reference to the Inspector.
    var S = I.scopes;
    
    if (!typeof(S.currentScope.appliedVariation.variation_id) == 'object'){
      //console.log('and here');
    }
    var currentVariationId = S.currentScope.appliedVariation.variation_id;
    var currentVariationType = I.currentVariationType;

    var ssIndex = I.formOverridesStylesheetIndex();  
    var stylesheet = document.styleSheets.item(ssIndex);
    var ruleCountPrior = stylesheet.cssRules.length;
    var cssWeight = I.currentVariationType.cssWeight;

    I.livethemerRules.addRule(stylesheet, selector, rule, currentVariationId, fieldId, cssWeight);
  },
  
  /**
   * Create an object which can store metadata about the rules Livethemer
   * creates dynamically. This object has some helpful methods to manage
   * this data.
   */      
  livethemerRules: {
    currentIndex: 0,
    rules: [],
    
    addRule: function(stylesheet, selector, rule, variationId, fieldId, cssWeight) {
      
      var ltRules = this; // Store a reference to the livethemerRules object.
      
      ltRules.currentIndex ++;
      var ltSelector = '#lt-'+ ltRules.currentIndex;
      
      // Add this rule to the DOM stylesheet. First work out where to put it, based on cssWeights.
      for (var rulePosition = 0; rulePosition < ltRules.rules.length; rulePosition++) {
        var info = ltRules.rules[rulePosition];
        if (info.cssWeight > cssWeight) break;

        // See if there's an existing rule for this field. If there is, there'll be only one, which
        // we flag for deletion.
        if (info.cssSelector == selector && info.fieldId == fieldId) {
          var itemToDelete = rulePosition;
        }
      }

      if (typeof itemToDelete === 'number') {        
        ltRules.removeRule(stylesheet, itemToDelete);
        rulePosition--; // Reset our position.
      }
      
      // We've removed any existing matching rule for this. Now, if
      // it's got an empty field value, we bail out and don't add a new rule for it. 
      if (rule.length === 0) return;
	
			// Under obscure circumstances we have received a null selector, which caused the insertRule to fail.
			if (selector === '') {
				log('An empty string was received instead of a valid selector.'); return;
			}
			else {
	      var ruleIndex = stylesheet.insertRule(ltSelector +', '+ selector +' { ' + rule + ' }', rulePosition);
			}
			
      // Store information about this rule in our own object.
      var info = {
        variationId: variationId,
        fieldId: fieldId,
        cssWeight: cssWeight,
        ltIndex: ltRules.currentIndex,
        ltSelector: ltSelector,
        cssSelector: selector
      };
      ltRules.rules.splice(rulePosition, 0, info);
      
    },
            
    removeRule: function(stylesheet, ruleIndex) {
      var ltRules = this;
      stylesheet.deleteRule(ruleIndex);
      ltRules.rules.splice(ruleIndex, 1); // Remove one element, at ruleIndex
    },
    
    getRuleInfoByRule: function (cssRule) {
      var ltRules = this;
      var ruleIndex = inspector.getRuleLivethemerId(cssRule);
      var ltSelector = '#lt-'+ ruleIndex;
      
      for (var i = 0; i < ltRules.rules.length; i++) {
        if (ltRules.rules[i].ltSelector == ltSelector) {
          return ltRules.rules[i];
        }
      }          
    },
    
    getRuleInfoById: function(ruleIndex) {
      var ltRules = this;
      return ltRules.rules[ruleIndex];
    }
  },

  /**
   * Build a css style tag conataining all the css passed through in Drupal.settings.livethemerCSSoverrides by the php.
   */
  preprocessCSSfiles: function() {
    var I = this; // Store a reference to the Inspector.

    // Disable the normal overrides CSS file. 
    $('link[href *= "overrides.css"]').attr('disabled', true);
    
    // Add the style tag where we're going to stick all the css.
    // Use jQuery's .append to add it as the last item.
    $('head').append('<style type="text/css" title="livethemer-overrides"></style>');
    var ssheet = document.styleSheets.item(document.styleSheets.length -1);
        
    // Get the array of CSS override rules, and build a stylesheet from them.
    var overrides = Drupal.settings.livethemerCSSoverrides; 

    $.each(overrides, function(cssWeight, appliedVariations){
      $.each(appliedVariations, function(variationId, fields){
        $.each(fields, function(fieldId, styles){
          $.each(styles, function(selector, style){
            // insertRule() returns the index of the rule it just inserted,
            // handy so we can add our field id.
            var ruleCountPrior = ssheet.cssRules.length;
            // Add the rule. This will also store some "metadata" about each rule in our own special object.
            I.livethemerRules.addRule(ssheet, selector, style, variationId, fieldId, cssWeight);
          });
        });
      });
    });
  },
        
  /**
   * Retrieve the field ID that was stored against the supplied CSS rule. It is stored in the format:
   * #livethemer-xxx, .original-rule-selector(s)-here
   */
  getRuleLivethemerId: function(rule) {
    var selector = rule.selectorText;
    var fieldId = 'x';
    
    // Dig out the field Id from the CSS rule's selector.
    var regex = new RegExp('\#lt-(.*), .');
    var result = regex.exec(selector);
    return result[1];
  },
  
  // A random alphanumeric generator needed for cache busting in our file refs. I totally wrote this myself.
  randomAlphNum: function(){
    var possible = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    return possible.charAt(Math.floor(Math.random() * possible.length));
  }
}

})(jQuery);