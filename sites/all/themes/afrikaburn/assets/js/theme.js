$(window).scroll(function() {
    var scrollHeight = $(window).scrollTop();
    if(scrollHeight  > 0) {
        $("a.back-to-top-button").addClass("show")
    }
	else {
	 	$("a.back-to-top-button").removeClass("show")
	}
});

/*----------------------------------------------------
ADD CLASS "HIGHLIGHTED" TO THE ACTIVE PARENT MENU ITEM
----------------------------------------------------*/

$("ul.nav-child").hover(parentColour, parentColour);
	function parentColour(){
	$(this).parent().toggleClass("highlighted");
}

function supportsPlaceholder() {
  return 'placeholder' in document.createElement('input');
}

function radioCheckBoxWrapper() {
	$("input:radio, input:checkbox")
	$("input:radio, input:checkbox").not(".radio-checkbox-wrapper input:radio, .radio-checkbox-wrapper input:checkbox").wrap("<div class='radio-checkbox-wrapper'></div>").after("<div class='radio-checkbox-dummy'></div>");
}

function inputTypeFile() {
	$("input:file").not(".input-file-wrapper input:file").wrap("<div class='input-file-wrapper'>Select file</div>");
	$(".input-file-wrapper").after("<div class='clr'></div><p class='selected-file'>Selected file: None selected</p>");
}

function rotateImages() {
  var oCurrentPhoto = jQuery("div.slide.current");
  var oNextPhoto = oCurrentPhoto.next("div.slide");
  if (oNextPhoto.length == 0)
    oNextPhoto = jQuery("div.slide:first");
    
  oCurrentPhoto.removeClass("current").addClass("previous");    
  oNextPhoto.css({opacity: 0.0}).addClass("current")
    .animate({opacity: 1.0}, 2000,
      function() {
        oCurrentPhoto.removeClass("previous");
      });
}


$(document).ready(function() {
  	radioCheckBoxWrapper();
  	inputTypeFile();
  	$("a.back-to-top-button").attr("href","javascript: void(0)");
  	$("input:file").change(function() {
		var selectedFile = jQuery(this).val().split('\\').pop();;
	  	$(this).parent().siblings('p.selected-file').html("Selected file: " + selectedFile);
	  	$(this).parent().addClass('file-selected');
	});
	$("a.back-to-top-button").click(function(event) {
		event.preventDefault();
		$("html, body").animate({"scrollTop": "0px"}, 300);
	});
	$(function() {
	  //setInterval("rotateImages()", 4000);
	});
	
	$("a.login-box-toggler").attr("href","javascript: void(0)").click(function(e) {
		$(".login-box").toggleClass("show-login");
		$(this).toggleClass("active");
		e.stopPropagation();
	});

	$(document).click(function(e) {
	    $(".login-box").removeClass("show-login");
	    $(this).removeClass("active");
	});

	$(".login-box").click(function(e) {
	    e.stopPropagation();
	});
});


