(function ($) {
/**
* The Livethemer Color Picker, modifyed farbtastic.
*/
Drupal.liveThemer.colorPicker = {  
  /**
   * Check each field of the configuration form and see if it is a colour
   * field. If so, add an icon beside the field, and activate the colour picker widget.
   */
  addColorPickers: function(settingsForm){
    var I = Drupal.liveThemer.inspector; // Store a reference to the Inspector.
    // "static" variable to record which colour input field is active at
    // any given time, and which should thus take the value returned from Farbtastic.
    I.currentColourInput = {}; 
  
    // Check each field to see if it needs a farbtastic colour picker.
    $('.colourpick', settingsForm).each(function(i, domField) {
      thisField = $(domField);
      
      // Only add the colourpicker markup once.
      if ($('#colourpick').length === 0) {
        $('body').append('<div id="colourpick"><div id="chandle"><span title="close" class="close"></span></div><div id="thecolourwheel"></div><div id="alphaslide">Opacity</div></div>');
        $('#colourpick .close').click(function(){
          $('#colourpick').hide();
        });
        
        I.fb = $.farbtastic('#thecolourwheel', function(c){
          var alpha = $('#alphaslide').slider("value")/100;
          applycolour(c, alpha);
        });

        $('#alphaslide').slider({
          min: 0,
          max: 100,
          step: 5,
          slide: function(event, ui){
            var c = I.fb.color;
            applycolour(c, ui.value/100);
          }
        });
        
        $('#colourpick').draggable();
      }
      
      // React when the value in the colour textfield changes
      thisField.keyup(function() {
        var changedField = $(this);
        var val = changedField.val();

        I.currentColourInput = $(this);          
        changedField.css('background-color', val);
        
        presetColourPickerToFieldVal(changedField);
      });
      
      // Add the colourpicker icon and activate it.
      var fieldParent = thisField.parent();
      fieldParent.append('<a class="colourpop" title="colour picker"></a>');

      $('.colourpop', fieldParent).click(function(){
        var clickedIcon = $(this);
        I.currentColourInput = $('input', clickedIcon.parent());          
        I.currentColourInput.focus();
        
        presetColourPickerToFieldVal(I.currentColourInput);

        $('#colourpick').show();
      });

      // Pre-apply a background color to each colour field.
      var val = thisField.val();
      if (val) {
        thisField.css('background-color', val);
      }
    });
  
     /**
      * Function_comment
      */
     function applycolour(c, alpha){
        var hex = c.substring(1,7);
        var r = parseInt(hex.substring(0,2),16);
        var g = parseInt(hex.substring(2,4),16);
        var b = parseInt(hex.substring(4,6),16);
        
        if (alpha == 1) {
          // No transparency, so no need for the four parameter rgba.
          var colorString = c; //"rgb("+r+","+g+","+b+")";
        }
        else {
          var colorString = "rgba("+r+","+g+","+b+","+alpha+")";
        }
        
        I.currentColourInput.val(colorString).change();
      }
  
      function alphaValFromRGBA(rgba) {
        var sa = new Array();
        sa = rgba.split(',');
        if (sa && sa.length > 3) {
          var a = sa[3].split(')');
          return a[0];
        }
        return 1;
      }
      
      function hexFromRGBA(rgba){
        if (rgba.indexOf('#') == true) {
         //we have a hex value so return it.
         return rgba;
        }
        var spl = new Array();
        spl = rgba.split('(');
        spl = spl[1].split(')');
        spl = spl[0].split(',');
        
        // Ignore the last value, which is the alpha value.
        var items = 3;
    
        var hex = new Array();
        for(var x = 0; x < items; x++ ){
          v = spl[x];
          var h = parseInt(v).toString(16);
          if (h.length === 1){
            hex[x]="0"+h;
          } else {
            hex[x]=h;
          }
        }
        
        var out = hex.join("").toUpperCase();
        return '#'+out;
      }
      
      /**
       * Take the background value of a colour field and preselect that colour
       * in the colourpicker.
       */
      function presetColourPickerToFieldVal(field) { 
        var rgba = field.css('background-color');
        
        // Attempt to set the current alpha.
        var alpha = alphaValFromRGBA(rgba);//I.currentColourInput.val());
        $('#alphaslide').slider("option", "value", alpha * 100);

        // Set the colour picker default value.
        var hex = hexFromRGBA(rgba);
        if (hex.length === 7) {
          // Note: the following also triggers the fb callback, which passes the fb colour
          // and the alpha value (retrieved from the alpha slider value) through
          // to the applycolour() function. Hence this is critical to run AFTER the alpha
          // slider value is setup above.
          I.fb.setColor(hex);
        }
      }      
    }
  } 
})(jQuery);