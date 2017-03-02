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

function toggleContactForm(clickedElement) {
	var contactForm = clickedElement.next();
	if (contactForm.hasClass('hidden')) {
		contactForm.slideDown( "slow", function() {
		 	contactForm.toggleClass('hidden');
		 	var scrollBarPosition = clickedElement.offset().top - 15;
        	$('html,body').animate({scrollTop: scrollBarPosition}, 300);
		});
	} else {
		contactForm.slideUp( "slow", function() {
			 contactForm.toggleClass('hidden');
		});
	}
}


$(document).ready(function() {
  	radioCheckBoxWrapper();
  	inputTypeFile();
  	$("a.back-to-top-button").attr("href","javascript: void(0)");
  	$("input:file").change(function() {
		var selectedFile = jQuery(this).val().split('\\').pop();;
	  	$(this).parent().siblings('p.selected-file').html("Selected file: <span class='file-name'>" + selectedFile + "</span>");
	  	$(this).parent().addClass('file-selected');
	});
	$("a.back-to-top-button").click(function(event) {
		event.preventDefault();
		$("html, body").animate({"scrollTop": "0px"}, 100);
	});
	$(function() {
	  setInterval("rotateImages()", 5000);
	});
	
	$(".user-menu-icon").click(function(e) {
		$(".user-menu").toggleClass("show");
		$(this).toggleClass("active");
		e.stopPropagation();
	});

	$(".user-menu ul li a").each(function(e) {
		var href = $(this).attr('href').split('/');
		var slug = href[href.length-1];
	    $(this).addClass(slug);
	})
	

	$(document).click(function(e) {
	    $(".user-menu").removeClass("show");
	    $(this).removeClass("active");
	});

	$(".user-menu").click(function(e) {
	    e.stopPropagation();
	});

	$("div.messages").prepend("<span class='icon'></span>");

	//Add scroll top behaviour when accordion item is opened. Must add class 'open' in addition to the classes added by jQuery ui, because of the order in which the code is run.
	$(".ui-accordion .ui-accordion-header.ui-state-active").addClass("open");
	$(".ui-accordion .ui-accordion-header.ui-state-default").on('click', function(){
		if (!$(this).hasClass("open")) {
			var scrollBarPosition = $(this).offset().top - 15;
        	$('html,body').animate({scrollTop: scrollBarPosition}, 300);
		}
		$(this).toggleClass("open");
		
    }); 

    // var heading = $('.page-theme-camps-form-1-registered .views-row h1.field-content').text();
    // console.log(heading);
    // $('.page-theme-camps-form-1-registered .views-field-field-creative-lead label.views-label-field-creative-lead').text($(this).parent().parent()));

	

	$('.page-community .views-field-field-creative-lead > .field-content,' +
		'.page-community .views-field-field-new-members-email > .field-content').addClass('hidden');

    $('.page-community .views-field-field-creative-lead label.views-label-field-creative-lead,' +
    	'.page-community .views-field-field-new-members-email label.views-label-field-new-members-email').click(function(e) {
    		var clickedElement = $(this);
    		toggleContactForm(clickedElement);
    });

    //$('div.field-type-multifield.field-name-field-creative-lead').after("<div class='description'>we encourage you to have a team, but under stand some small vehicles may not need the support.</div><button id='copy-contact-person'>*Use above details</button>");

    $('input#edit-field-solo-project-und').change(function() {
    	if (this.checked) {
    		var firstName = $('body.page-node-add-mutant-vehicles fieldset#edit-field-contact-person-und-0 div.field-name-field-first-name input').val();
    		var lastName = $('body.page-node-add-mutant-vehicles fieldset#edit-field-contact-person-und-0 div.field-name-field-last-name input').val();
    		var emailAddress = $('body.page-node-add-mutant-vehicles fieldset#edit-field-contact-person-und-0 div.field-name-field-email-address input').val();
    		var phoneNumber = $('body.page-node-add-mutant-vehicles fieldset#edit-field-contact-person-und-0 div.field-name-field-phone-number input').val();
    		$('body.page-node-add-mutant-vehicles fieldset#edit-field-creative-lead-und-0 div.field-name-field-first-name input').val(firstName);
    		$('body.page-node-add-mutant-vehicles fieldset#edit-field-creative-lead-und-0 div.field-name-field-last-name input').val(lastName);
    		$('body.page-node-add-mutant-vehicles fieldset#edit-field-creative-lead-und-0 div.field-name-field-email-address input').val(emailAddress);
    		$('body.page-node-add-mutant-vehicles fieldset#edit-field-creative-lead-und-0 div.field-name-field-phone-number input').val(phoneNumber);
    	}
    });

    $('body.page-node-add-mutant-vehicles fieldset#edit-field-contact-person-und-0 input,' +
    	'body.page-node-add-mutant-vehicles fieldset#edit-field-creative-lead-und-0 input').focus(function(e) {
    	console.log($(this).attr('name'));
    });

    $('input.form-text.form-autocomplete').wrap("<div class='autocomplete-wrapper'></div>");
    //$(".field-group-div").not(":has(.field)").remove();

    $('body.page-user-login form#user-login').after("<a href='/user/password?'>Forgot Password</a>");
});



//Toggle visibility of the contact forms on the 



