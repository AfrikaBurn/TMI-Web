/**
 * @file
 *  Drupal Judy module
 */

/*jslint browser: true, continue: true, indent: 2, newcap: true, nomen: true, plusplus: true, regexp: true, white: true, ass: true*/
/*global alert: false, confirm: false, console: false*/
/*global jQuery: false, Drupal: false, inspect: false, Judy: false*/

(function($) {
  'use strict';
/**
 * Judy/Drupal.Judy - Javascript utility library.
 *
 * General stuff:
 * - methods having a selector parameter only work on a single element (not a collection); except {@link Judy.keydown}(), {@link Judy.keyup}(), {@link Judy.disable}(), {@link Judy.enable}(), {@link Judy.scrollTrap}()
 * - argument defaults are always falsy
 * - complex methods, with notable risk of user error (bad argument) or program error, log errors via Inspect (if exists)
 * - Judy is type sensitive, all comparisons are ===; "0" is not 0 (and btw "0" is never falsy in Javascript; only in PHP)
 *
 * Type:
 * &bull; {@link Judy.typeOf}()
 * &bull; {@link Judy.isContainer}() &bull; {@link Judy.isArray}()
 * &bull; {@link Judy.isNumber}() &bull; {@link Judy.isInt}()
 *
 * Objects and Arrays:
 * &bull; {@link Judy.toArray}()
 * &bull; {@link Judy.objectGet}()
 * &bull; {@link Judy.objectKeys}()
 * &bull; {@link Judy.objectKeyOf}()
 * &bull; {@link Judy.arrayIndexOf}()
 * &bull; {@link Judy.objectSort}() &bull; {@link Judy.objectKeySort}()
 * &bull; {@link Judy.merge}()
 * &bull; {@link Judy.containerCopy}()
 *
 * String:
 * &bull; {@link Judy.stripTags}()
 * &bull; {@link Judy.toLeading}()
 * &bull; {@link Judy.toUpperCaseFirst}()
 * &bull; {@link Judy.randName}()
 *
 * Number:
 * &bull; {@link Judy.numberToFormat}() &bull; {@link Judy.numberFromFormat}()
 * &bull; {@link Judy.rand}()
 *
 * Date:
 * &bull; {@link Judy.isLeapYear}()
 * &bull; {@link Judy.dateISO}() &bull; {@link Judy.dateTime}()
 * &bull; {@link Judy.dateFromFormat}() &bull; {@link Judy.dateToFormat}()
 * &bull; {@link Judy.timeFormat}()
 *
 * Form fields:
 * &bull; {@link Judy.fieldValue}()
 * &bull; {@link Judy.isField}()
 * &bull; {@link Judy.fieldType}()
 * &bull; {@link Judy.disable}() &bull; {@link Judy.enable}()
 *
 * Style:
 * &bull; {@link Judy.innerWidth}() &bull; {@link Judy.innerHeight}() &bull; {@link Judy.outerWidth}() &bull; {@link Judy.outerHeight}()
 * &bull; {@link Judy.scrollTrap}() &bull; {@link Judy.scrollTo}()
 *
 * DOM:
 * &bull; {@link Judy.ancestor}()
 *
 * Event:
 * &bull; {@link Judy.keydown}() &bull; {@link Judy.keyup}()
 * &bull; {@link Judy.ajaxcomplete}() &bull; {@link Judy.ajaxcomplete_off}()
 *
 * UI:
 * &bull; {@link Judy.overlay}()
 * &bull; {@link Judy.dialog}()
 *
 * Miscellaneous:
 * &bull; {@link Judy.focus}()
 * &bull; {@link Judy.timer}()
 * &bull; {@link Judy.browserIE}
 * &bull; {@link Judy.yduJ} &bull; {@link Judy.yduj}
 *
 * @constructor
 * @namespace
 * @name Judy
 * @singleton
 * @requires jQuery
 * @param {jQuery} $
 */
var Judy = function($) {
  /**
   * @ignore
   * @private
   * @type {State}
   */
  var self = this,
  _name = "Judy",
  _nonObj = ["window","document","document.documentElement","element","image","textNode","attributeNode","otherNode","event","date","regexp","jquery"],
  _uaIe = 0,
  _dateFrmt, _dateTz,
  _nonInputFlds = ["textarea", "select"],
  _dataName,
  _dialEvts = ["beforeClose", "create", "open", "focus", "dragStart", "drag", "dragStop", "resizeStart", "resize", "resizeStop", "close"],
  _dialOpts = [
      "appendTo", "autoOpen", "buttons", "closeOnEscape", "closeText", "dialogClass", "draggable", "height", "hide",
      "maxHeight", "maxWidth", "minHeight", "minWidth", "modal", "position", "resizable", "show", "title", "width"
  ],
  _dialMthds = ["close", "destroy", "isOpen", "moveToTop", "open", "option", "widget"],
  _dialogs = [],
  _acInit, _acLstnrs = {}, _acFltrs = [
    // These may tear down the browser.
    { '!url': /\/inspect\/ajax/ },
    { '!url': /\/log_filter\/ajax/ }
  ],
  _checklist = "checkboxes", _radio = "radios", // Drupal Form API calls a checkbox list 'checkboxes' and a radio list 'radios'
  _jqOvrly, _ovrlyRsz, // Overlay.

  /**
   * Error handler, give it an error or a variable.
   *
   * Does nothing if no Inspect module, or if Inspect's 'Enable frontend javascript variable/trace inspector' permission is missing for current user.
   *
   * @see inspect.errorHandler
   * @ignore
   * @private
   * @param {Error} [error]
   * @param {mixed} [variable]
   * @param {object|integer|boolean|string} [options]
   * @return {void}
   */
  _errorHandler = function(error, variable, options) {
    var u = options, o = {}, t;
    //  Do nothing, if inspect is the 'no action' type.
    if(typeof window.inspect === "function" && inspect.tcepsnI) {
      if(typeof inspect.errorHandler === "function") {
        if(u) {
          if((t = typeof u) === "string") {
            o.message = u;
            o.wrappers = 1; // This function wraps Inspect.errorHandler().
          }
          else if(t === "object") {
            o = u;
            o.wrappers = !u.wrappers ? 1 : (u.wrappers + 1);
          }
          //  Otherwise: ignore; use object argument for options if other properties are needed.
        }
        o.category = "Judy";
        inspect.errorHandler(error, variable, o);
      }
      else {
        inspect.console("Please update Inspect.");
      }
    }
  },
  /**
   * Resolve element(s).
   *
   * Logs error if failing to establish such element, unless noError.
   *
   * @ignore
   * @param {boolean} list
   *  - false: return first element
   *  - true: return list of elements
   * @param {string|element|array|jquery} u
   * @param {string|object|falsy} [cntxt]
   *  - like jQuery() context argument
   * @param {string} [mthd]
   *  - method name
   * @param {boolean} [noError]
   *  - do not log error
   * @return {element|undefined}
   */
  _elm = function(list, u, cntxt, mthd, noError) {
    var li = !list ? 0 : undefined, t, s = u, jq, le, i, f;
    if(u) {
      if((t = typeof u) === "object") {
        //  Element?
        if(u === window || u === document || u.getAttributeNode) {
          return !list ? u : [u];
        }
        //  jquery object
        if(typeof u.jquery === "string") {
          if(u.length) {
            if(!cntxt) {
              return u.get(li);
            }
            if((jq = $(u, cntxt)).length) {
              return jq.get(li);
            }
          }
          s = u.selector;
        }
        else if(self.isArray(u) && (le = u.length)) {
          for(i = 0; i < le; i++) {
            if(!(u[i] === window || u[i] === document || u[i].getAttributeNode)) {
              f = true;
              break;
            }
            else if(!i && !list) {
              return u[0];
            }
          }
          if(!f) {
            return u;
          }
        }
      }
      else if(t === "string" && (jq = $(u)).length) {
        return jq.get(li);
      }
    }
    if(!noError) {
      try {
        throw new Error("selector[" + s + "], type[" + self.typeOf(u) + "], doesnt resolve to element");
      }
      catch(er) {
        _errorHandler(er, null, _name + "." + mthd + "()");
      }
    }
    return undefined;
  },
  /**
   * object and button elements arent supported, but input button/submit/reset is.
   *
   * @ignore
   * @param {element} r
   * @param {boolean} [b]
   *  - allow button (input type:button|submit|reset)
   * @return {string}
   *  - empty: not a field
   */
  _fieldType = function(r, b) {
    var t = r.tagName.toLowerCase();
    if(t === "input") {
      if((t = r.getAttribute("type"))) { // Secure against getAttribute returning undefined or other non-string falsy (unlikely, but anyway).
        switch(t) {
          case "button":
          case "submit":
          case "reset":
            return !b ? "" : t;
          case "radio":
            return _radio;
          case "checkbox":
            return self.ancestor(r, "div.form-checkboxes", 3) ? _checklist : "checkbox";
          default:
            return t;
        }
      }
      return "";
    }
    return self.arrayIndexOf(_nonInputFlds, t) > -1 ? t : "";
  },
  /**
   * Handles all field types (also checkbox, checkboxes/check list, and radios), and adds/removes css class 'form-button-disabled' to button.
   *
   * @ignore
   * @param {boolean} nbl
   * @param {string|element|array|jquery} slctr
   *  - works on multiple elements
   * @param {element|string|falsy} [cntxt]
   *  - default: document is context
   * @param {string} [ttl]
   *  - update the element's (hover) title attribute
   * @return {void}
   */
  _disable = function(nbl, slctr, cntxt, ttl) {
    var a = _elm(true, slctr, cntxt, !nbl ? "disable" : "enable"), le, i, r;
    if(a) {
      le = a.length;
      for(i = 0; i < le; i++) {
        (r = a[i]).disabled = !nbl ? "disabled" : false;
        if(typeof ttl === "string") {
          r.setAttribute("title", ttl);
        }
        switch(_fieldType(r, true)) { // Allow button.
          case "checkbox":
            $(r).unbind("click." + _name + ".disabled");
            if(!nbl) {
              $(r).bind("click." + _name + ".disabled", function() {
                return false;
              });
            }
            break;
          case _checklist:
            $("input[type='checkbox']", r).each(function(){
              $(r).unbind("click." + _name + ".disabled");
              if(!nbl) {
                $(this).bind("click." + _name + ".disabled", function() {
                  return false;
                });
              }
            });
            break;
          case _radio:
            $("input[name='" + r.getAttribute("name") + "']", cntxt).each(function(){
              this.disabled = !nbl ? "disabled" : false;
            });
            break;
          case "button":
          case "submit":
          case "reset":
            $(r)[ !nbl ? "addClass" : "removeClass" ]("form-button-disabled");
            break;
        }
      }
    }
  },
  /**
   * Get/set value checkbox field.
   *
   * Getting means getting the value attribute (if on), or empty string if off.
   *
   * Setting only means setting checked or not - does not change the value attribute of the field.
   *
   * @ignore
   * @function
   * @name Judy._valCheckbox
   * @param {element} r
   * @param {boolean|undefined} [val]
   *  - default: undefined (~ get value, dont set)
   *  - truthy: check it
   * @return {string|integer|undefined}
   *  - empty string if not checked
   *  - true if setting succeeded
   *  - undefined if no such field exist
   */
  _valCheckbox = function(r, val) {
    //  get
    if(val === undefined) {
      return r.checked ? r.value : "";
    }
    //  set
    r.checked = (val ? "checked" : false);
    return true;
  },
  /**
   * Get/set checked value of radio list field.
   *
   * If arg val is empty string: unchecks all radio options.
   *
   * If the radio element has no name attribute, then works like a checkbox; returns the value of that element if checked (ignores other radio elements).
   *
   * @ignore
   * @function
   * @name Judy._valRadio
   * @param {element} r
   * @param {element|string|falsy} [context]
   *  - default: document is context
   * @param {string|integer|undefined} [val]
   *  - default: undefined (~ get value, dont set)
   * @return {string|boolean|undefined}
   *  - empty string (getting only) if none checked
   *  - true if setting and that value is an option
   *  - false if setting and that value isnt an option
   *  - undefined if no such input field exist
   */
  _valRadio = function(r, context, val) {
    var nm = r.getAttribute("name"), a, le, i, v;
    if(!nm) { // No name works like a checkbox.
      return _valCheckbox(r, val);
    }
    //  get ------------------------------------
    if(val === undefined) {
      return (v = $("input[name='" + nm + "']:checked", context).val()) !== undefined ? v : "";
    }
    //  set ------------------------------------
    if( (le = (a = $().get("input[name='" + nm + "']", context)).length) ) {
      //  If real empty value, and not "0".
      if((v = "" + val) === "") {
        for(i = 0; i < le; i++) {
          a[i].checked = false; // we dont care which was checked, just uncheck all
        }
        return true;
      }
      //  non-empty value, check the one that has that particular value (if exists)
      for(i = 0; i < le; i++) {
        if(a[i].value === v) {
          a[i].checked = "checked";
          return true;
        }
      }
      return false;
    }
    return undefined; // Shouldnt be possible, .fieldValue() should catch non-existing; but anyway.
  },
  /**
   * Get/set selected value(s) of select field.
   *
   * Supports multiple.
   *
   * When getting:
   *  - option value "_none" translates to ""
   *  - multiple select returns array if any option selected, otherwise returns ""
   *
   * When setting, arg val is:
   *  - empty string or array, or [""]: un-selects all, no matter if the select is multiple or not
   *  - array, and select is non-multiple: uses only the first bucket of the array
   *  - non-empty string, and select is multiple: uses val as bucket in array having a single bucket
   *
   * Arg val will be stringified before comparison with option values (multiple: the buckets are stringified, in a copy of arg val).
   *
   * @ignore
   * @function
   * @name Judy._valSelect
   * @param {element} r
   * @param {array|string|mixed|undefined} [val]
   *  - default: undefined (~ get value, dont set)
   * @return {string|array|boolean|undefined}
   *  - array if getting multiple select, unless none (then empty string)
   *  - empty string (getting only) if none selected
   *  - true if clearing all options
   *  - integer if selecting some option(s); zero if none of this/those options exist
   *  - undefined if no such select field exist
   */
  _valSelect = function(r, val) {
    var multi, ndx = -1, rOpts, nOpts, rOpt, nVals, i, vals = [], v, set = 0;
    //  get ------------------------------------
    if(val === undefined &&
        ((ndx = r.selectedIndex) === undefined || ndx < 0)) {
      return "";
    }
    //  getting and setting
    multi = r.multiple;
    nOpts = (rOpts = $("option", r).get()).length;
    //  get ----------------
    //  Translating selectedIndex to actual option is weird/error prone, so we use jQuery list of options instead.
    if(val === undefined) {
      if(!multi) {
        return (v = rOpts[ndx].value) !== "_none" ? v : "";
      }
      //  multi
      for(i = 0; i < nOpts; i++) {
        if((rOpt = rOpts[i]).selected &&
            (v = rOpt.value) !== "" && v !== "_none") {
          vals.push(v);
        }
      }
      return vals.length ? vals : "";
    }
    //  set ------------------------------------
    //  start by clearing all
    //  r.selectedIndex = -1; ...is seriously unhealthy, may effectively ruin the select.
    for(i = 0; i < nOpts; i++) {
      rOpts[i].selected = false;
    }
    if(val === "" || val === "_none") {
      return true; // all done
    }
    //  secure array
    if(!self.isArray(val)) {
      v = ["" + val];
    }
    else {
      if(!(nVals = val.length) ||
          (nVals === 1 && (val[0] === "" || val[0] === "_none"))
      ) {
        return true; // all done
      }
      v = val.concat();
      for(i = 0; i < nVals; i++) { // stringify for comparison
        v[i] = "" + v[i];
      }
    }
    for(i = 0; i < nOpts; i++) {
      if( ( (rOpt = rOpts[i]).selected =
          self.arrayIndexOf(v, rOpt.value) > -1 ? "selected" : false)
      ) { // set? and count
        ++set;
        if(!multi) {
          return 1;
        }
      }
    }
    return set;
  },
  /**
   * Get/set selected values of checkbox list field (Drupal special).
   *
   * When getting:
   * - returns array if any option selected, otherwise returns ""
   *
   * When setting, arg val is:
   * - empty string or array, or [""]: un-selects all
   * - non-empty string or not array: sets that single value (if stringified value equals one of the options available)
   *
   * Setting effectively means 1. resetting the whole list, and then 2. selecting the value(s) passed by the val argument.
   * If you dont want to reset, but only make sure to select some value(s) - see the example.
   *
   * Arg val will be stringified before comparison with option values (array: the buckets are stringified, in a copy of arg val).
   *
   * Warning - empty value:
   * - a check list should ideally not have an empty value (neither "" nor "_none"); instead, a check list is empty when no option is selected
   * - if you really want an emptyish value, make it "_none" ("_none" is for this method a normal value, whereas "" means none selected at all)
   *
   * @example // Checking some option, but not resetting the whole list:
var values = Judy.fieldValue("some_field[und][whatever]"), checkOption = "some_option";
if(values) { // not simply "" ~ empty
  values.push(checkOption); // no matter if "some_option" is already checked, no prop if an option appears more than once when setting
}
else {
  values = checkOption;
}
Judy.fieldValue("some_field[und][whatever]", null, values);
   *
   * @ignore
   * @function
   * @name Judy._valChecklist
   * @param {element} r
   * @param {array|string|mixed|undefined} [val]
   *  - default: undefined (~ get value, dont set)
   *  - empty string or array or [""] translates to clear all options
   *  - non-empty string or not array: sets that single value (stringified)
   * @return {array|string|integer|boolean|undefined}
   *  - array if getting and any option is selected
   *  - empty string if getting and no option selected
   *  - true if clearing all options
   *  - integer if selecting some option(s); zero if none of this/those options exist
   *  - undefined if not a checklist field
   */
  _valChecklist = function(r, val) { // NB: hidden 5th argument used internally
    var par, rOpts, nOpts, rOpt, nVals, i, v = [], set = 0;
    if((par = self.ancestor(r, "div.form-checkboxes", 3))) {
      nOpts = (rOpts = $("input[type='checkbox']", par).get()).length;
      //  get ------------------------------------
      if(val === undefined) {
        for(i = 0; i < nOpts; i++) {
          if((rOpt = rOpts[i]).checked) {
            v.push(rOpt.value);
          }
        }
        return v.length ? v : "";
      }
      //  set ------------------------------------
      //  let empty be undefined, otherwise secure array
      v = !self.isArray(val) ? (
              val === "" ? undefined : [val]
          ) : (
              !(nVals = val.length) || (nVals === 1 && val[0] === "") ? undefined :
                  val.concat() // do copy array, because we stringify values
          );
      if(v === undefined) { // unset all
        for(i = 0; i < nOpts; i++) {
          rOpts[i].checked = false;
        }
        return true;
      }
      for(i = 0; i < nVals; i++) { // stringify all buckets, because field values are always strings (~> comparison)
        v[i] = "" + v[i];
      }
      for(i = 0; i < nOpts; i++) {
        if( ( (rOpt = rOpts[i]).checked =
            self.arrayIndexOf(v, rOpt.value) > -1 ? "checked" : false)
        ) { // set? and count
          ++set;
        }
      }
      return set;
    }
    return undefined; // IDE (wrongly) complains otherwise
  },
  /**
   * @ignore
   * @param {object} o
   * @param {array} fltr
   * @return {boolean}
   */
  _filter = function(o, fltr) {
    var le = fltr.length, i, k, x, not, v;
    for (i = 0; i < le; i++) {
      for (k in fltr[i]) {
        v = null; // Clear reference (loop).
        if (fltr[i].hasOwnProperty(k)) {
          x = k;
          if ((not = x.charAt(0) === '!')) {
            x = x.substr(1);
          }
          if (o.hasOwnProperty(x)) {
            if ((v = fltr[i][k]) && v instanceof RegExp) {
              if (typeof o[x] === 'string') {
                if (v.test(o[x])) {
                  if (not) {
                    return false;
                  }
                }
                else if (!not) {
                  return false;
                }
              }
            }
            else if (o[x] === v) {
              if (not) {
                return false;
              }
            }
            else if (!not) {
                return false;
              }
          }
        }
      }
    }
    return true;
  },
  /**
   * ajaxcomplete.off() helper.
   *
   * @ignore
   * @param {string} u
   * @param {string} s
   * @param {string} [nm]
   * @param {function} [h]
   * @return {void}
   */
  _acOff = function(u, s, nm, h) {
    var le, i, rm = [], n, sbtrt;
    if (_acLstnrs[u] && _acLstnrs.hasOwnProperty(u)) {
      le = _acLstnrs[u].length;
      for (i = 0; i < le; i++) {
        if ((_acLstnrs[u][i][0] === s || (nm && _acLstnrs[u][i][1] === nm)) &&
          (!h || _acLstnrs[u][i][2] === h)
        ) {
          rm.push(i);
        }
      }
      if ((n = rm.length)) {
        if (n === le) {
          delete _acLstnrs[u];
        }
        else {
          sbtrt = 0;
          for (i = 0; i < n; i++) {
            _acLstnrs[u].splice(rm[i] - sbtrt, 1);
            ++sbtrt;
          }
        }
      }
    }
  },
  /** Convert human readable keydown_keystroke sequence to _NNNNNNN.
   * ctr, meta and cmd count as a single key, because it makes sense across OSes (Windows vs. Apple), and because ctr also fires meta on Windows.
   * @ignore
   * @private
   * @memberOf Judy
   * @throws {Error}
   *  - (UNCAUGHT) if empty or bad sequence (missing plain key, or containing unsupported char) etc.
   *  - "_1001055", false on error
   * @param {string} keystrokes
   *  - like: "ctr_shift_7" | "7"
   * @return {string|false}
   */
  _keyMask = function(keystrokes) {
    var aK = keystrokes.toUpperCase().split(/_/), nK = aK.length, k = 0, ky, cK, i;
    for(i = 0; i < nK; i++) {
      switch((ky = aK[i])) {
        //  modifiers ------------------------------------
        case "CTR": case "CTRL":
        case "CMD": case "META":k += 100000;break;
        case "ALT":k += 10000;break;
        case "SHIFT":k += 1000;break;
        //  plain key ------------------------------------
        case "ENTER": case "RETURN":k += 13;break;
        case "ESC": case "ESCAPE":k += 27;break;
        case "TAB":k += 9;break;
        case "SPACE":k += 32;break;
        case "BACKSPACE":k += 8;break;
        case "INS": case "INSERT":k += 45;break;
        case "DEL": case "DELETE":k += 46;break;
        case "HOME":k += 36;break;
        case "END":k += 35;break;
        case "PGUP": case "PAGEUP":k += 33;break;
        case "PGDN": case "PAGEDOWN":k += 34;break;
        case "PAUSE": case "BREAK":k += 19;break;
        case "STAR":k += 106;break;
        case "-": case "MINUS": case "HYPHEN":k += 109;break;
        case "+": case "PLUS":k += 107;break;
        case "LEFT":k += 37;break;
        case "UP":k += 38;break;
        case "RIGHT":k += 39;break;
        case "DOWN":k += 40;break;
        case "F1":k += 112;break;
        case "F2":k += 113;break;
        case "F3":k += 114;break;
        case "F4":k += 115;break;
        case "F5":k += 116;break;
        case "F6":k += 117;break;
        case "F7":k += 118;break;
        case "F8":k += 119;break;
        case "F9":k += 120;break;
        case "F10":k += 121;break;
        case "F11":k += 122;break;
        case "F12":k += 123;break;
        default:
          cK = ky.charCodeAt(0);
          if(cK >= 96 && cK <= 105) { // numpad numbers ~> numbers
            k += (cK - 48);
          }
          else if((cK >= 65 && cK <= 90) || (cK >= 48 && cK <= 57)) {
            k += cK;
          }
          else { //  skip anything else
            throw new Error("unsupported char["+ky+"] in keystrokes["+keystrokes+"]");
          }
      }
    }
    if(k && k % 1000 > 0) {
      return "_" + k;
    }
    throw new Error("keystrokes["+keystrokes+"] " + (!k ? "evaluates to nothing" : "all modifiers, no plain keys"));
  },
  /** Convert keystrokes of an event to key mask.
   * @ignore
   * @private
   * @memberOf Judy
   * @throws {Error}
   *  - (UNCAUGHT) if empty or bad sequence (missing plain key, or containing unsupported char) etc.
   * @param {event} e
   * @return {integer}
   */
  _keystrokes = function(e) {
    var k = 0, kC;
    //  all key events are executed, no matter what keystrokes, so here we have to check if the keystrokes
    //  this method got as argument are the same as the ones pressed by the user
    if(e.ctrlKey || e.metaKey) { // command key, not IE
      k += 100000;
    }
    if(e.altKey) {
      k += 10000;
    }
    if(e.shiftKey) {
      k += 1000;
    }
    if((kC = e.keyCode)) {
      switch(kC) { // when more keys evaluates to same, they have to be translated to common
        case 61: // hyphen ~> numpad minus
          k += 107;
          break;
        case 189: // plus ~> numpad plus
          k += 109;
          break;
        default:
          if(kC >= 96 && kC <= 105) { // numpad numbers ~> numbers
            k += (kC - 48);
          }
          else {
            k += kC;
          }
      }
    }
    return k;
  },
  /* Un-format keystroke string, for human readable output.
   * No error checking, do or die.
   * @ignore
   * @private
   * @memberOf Judy
   * @param {string} keyMask
   *  - like "_1001055"
   * @return {string} like "ctr_shift_7"
   *
  this.keystrokes = function(keyMask) {
    if(keyMask.charAt(0) !== "_") { // if not starting with underscore it is not formatted
      return keyMask;
    }
    var k = parseInt(keyMask.substr(1), 10), ks = "";
    if(k > 100000) {
      ks += "ctr_";
      k -= 100000;
    }
    if(k > 10000) {
      ks += "alt_";
      k -= 10000;
    }
    if(k > 1000) {
      ks += "shift_";
      k -= 1000;
    }
    switch(k) {
      case 13:ks += "enter";break;
      case 27:ks += "escape";break;
      case 9:ks += "tab";break;
      case 32:ks += "space";break;
      case 8:ks += "backspace";break;
      case 45:ks += "insert";break;
      case 46:ks += "delete";break;
      case 36:ks += "home";break;
      case 35:ks += "end";break;
      case 33:ks += "pageup";break;
      case 34:ks += "pagedown";break;
      case 19:ks += "pause";break;
      case 106:ks += "star";break;
      case 109:ks += "minus";break;
      case 107:ks += "plus";break;
      case 37:ks += "left";break;
      case 38:ks += "up";break;
      case 39:ks += "right";break;
      case 40:ks += "down";break;
      default:
        if(k >= 112 && k <= 123) {
          ks += "f" + (k - 111);
        } // f keys
        else {
          ks += String.fromCharCode(k).toLowerCase();
        }
    }
    return ks;
  },*/
  /**
   * @ignore
   * @param {string} et
   *  - keydown|keyup
   * @param {array} as
   *  - caller arguments
   * @return {boolean}
   */
  _bindKeys = function(et, as) {
    var jq = $(as[0]), jqMthd = typeof jq.on === "function" ? "on" : "bind",
    nAs = as.length, qualifiers = "", nQs, iQ, q, nm, kms = {}, km,
    rs = jq.get(), nRs = jq.length, r,
    hndlr, dat, pdef = false, i, jq1, d, e, j, le, kyHndlrs, f;
    if(nAs < 3) {
      throw new Error("requires at least 3 args");
    }
    if(!nRs) {
      throw new Error("No element like selector[" + as[0] + "], type[" + self.typeOf(as[0]) + "]");
    }
    //  Find handler + data (if any) + preventDefault (if any).
    for(i = 1; i < 5; i++) {
      switch(typeof as[i]) {
        case "string":
          qualifiers = as[1];
          break;
        case "function":
          hndlr = as[i];
          break;
        case "object":
          dat = as[i];
          break;
        case "boolean":
          pdef = as[i];
          break;
      }
    }
    if(!hndlr) {
      throw new Error("No handler function arg found");
    }
    //  For every qualifier.
    nQs = (qualifiers = qualifiers.split(" ")).length;
    for(iQ = 0; iQ < nQs; iQ++) {
      //  Remove keydown_|keyup_, if given qualifiers arg "keydown_qualifiers" instead of just "qualifiers".
      if((q = qualifiers[iQ]).indexOf("key") === 0) {
        q = q.replace(/^key[^_]+_(.+)$/, "$1");
      }
      //  If event type not qualified; let normal jQuery.on|bind() do all work.
      if(!q || q === "*") {
        jq[jqMthd].apply(jq, !dat ? [et, hndlr] : [et, dat, hndlr]);
        return true;
      }
      //  Extract namespace.
      nm = "";
      if(q.indexOf(".") > -1) {
        nm = q.replace(/^[^\.]+\.(.+)$/, "$1");
        q = q.replace(/^([^\.]+)\..+$/, "$1");
      }
      //  Translate to keymask.
      km = _keyMask( // _keymask() throws error upon failure.
        q.replace(/[_\+]\+/, "_plus").replace(/\+/g, "_") // Support plus spacers as well as underscore spacers.
      );
      //  Skip if keymask evaluates to already listed keymask (ctr_7 ~ cmd_7 ~ meta_7).
      if(iQ && kms[km] && kms.hasOwnProperty(km)) {
        continue;
      }
      kms[km] = {
        handler: hndlr,
        data: dat,
        namespace: nm,
        type: q,
        preventDefault: pdef
      }
    }
    //  For every element of the jQuery object.
    for(i = 0; i < nRs; i++) {
      //  check that key event isnt set on unsupported element type
      if((r = rs[i]) !== document.documentElement) { // propably the most usual key event element
        if(r === window) {
          if(_uaIe) { // ie
            throw new Error("IE key event on window illegal, do set it on document.documentElement");
          }
        }
        else if(!_uaIe) { // gecko and webkit; the element must be focusable.
          switch(r.tagName.toLowerCase()) {
            case "textarea":  case "input":
              break;
            default:
              if(!r.hasAttribute("tabindex")) {
                throw new Error("non-IE key event on tag-type["+r.tagName+"] without tabindex not possible");
              }
          }
        }
      }
      //  Find common keydown/keyup handler, if exists.
      kyHndlrs = null;
      if((d = (jq1 = $(r)).data("events")) && (e = d[et]) && d.hasOwnProperty(et)) {
        le = e.length;
        //  For every listener to keydown|keyup.
        for(j = 0; j < le; j++) {
          if(e[j].namespace === _dataName) {
            kyHndlrs = e[j].handler.judy_keyMask_handlers;
            break;
          }
        }
      }
      //  No common keydown/keyup handler; create that.
      if(!kyHndlrs) {
        f = function(evt) {
          var o, k, a, pd, le, i, lstnr, e;
          if((a = (o = f.judy_keyMask_handlers)[ k = "_" + _keystrokes(evt) ]) && o.hasOwnProperty(k) && (le = a.length)) {
            for(i = 0; i < le; i++) {
              lstnr = a[i];
              if(!pd && lstnr.preventDefault) {
                pd = true;
                evt.preventDefault();
              }
              evt.data = lstnr.data;
              evt.keystrokes = lstnr.type;
              lstnr.handler.apply(this, [evt]);
            }
          }
        };
        kyHndlrs = f.judy_keyMask_handlers = {};
        jq1[jqMthd](et + "." + _dataName, f);
      }
      //  For every keymask.
      for(km in kms) {
        if(kms.hasOwnProperty(km)) {
          if(kyHndlrs[km] && kyHndlrs.hasOwnProperty(km)) {
            kyHndlrs[km].push( kms[km] );
          }
          else {
            kyHndlrs[km] = [
              kms[km]
            ];
          }
        }
      }
    }
    return undefined; // For IDE.
  },
  /**
   * Timezone offset, in positive milliseconds, or as a (hour) string.
   * Native method getTimezoneOffset() returns negative (sic!) value, in minutes - alltogether fairly useless.
   * @ignore
   * @param {Date} dt
   * @param {boolean} [asHourStr]
   * @return {integer|str} milliseconds | "+/-NN" hours
   */
  _dateTz = function(dt, asHourStr) {
      var z = dt.getTimezoneOffset(), zu;
      return !asHourStr ? (-(z * 60 * 1000)) :
              (z ? (((zu = z > 0) ? "-" : "+") + ((zu = ((zu ? z : z * -1) / 60)) < 10 ? "0" : "") +
                      Math.floor(zu)) : "+00");
  },
  /**
   * Helper for iso-8601 formats
   * @ignore
   * @param {Date} dt
   * @param {boolean} d - truthy: YYYY-MM-DD
   * @param {boolean} t - truthy: HH:ii:ss
   * @param {boolean} m - truthy: mmm
   * @param {boolean} UTC - truthy: get in Universal Time
   * @param {boolean} iso - use T and Z markers
   * @return {string}
   */
  _dateFrmt = function(dt, d, t, m, UTC, iso) {
    var u, f = UTC ? "getUTC" : "get";
    return (d ? (
                dt[f+"FullYear"]() + "-" +
                ((u = dt[f+"Month"]() + 1) < 10 ? ("0" + u) : u) + "-" +
                ((u = dt[f+"Date"]()) < 10 ? ("0" + u) : u)
            ) : ""
        ) +
        (d && t ? (iso ? "T" : " ") : "") +
        (t ? (
            (
                ( (u = dt[f+"Hours"]()) < 10 ? ("0" + u) : u) + ":" +
                ( (u = dt[f+"Minutes"]()) < 10 ? ("0" + u) : u) + ":" +
                ( (u = dt[f+"Seconds"]()) < 10 ? ("0" + u) : u)
            ) +
                (m ? (
                    (iso ? "." : " ") +
                    ( (u = dt[f+"Milliseconds"]()) < 10 ? ("00" + u) : (u < 100 ? ("0" + u) : u) )
                ) : "")
            ) : ""
        ) +
        (!iso ? "" : (UTC ? "Z" : (_dateTz(dt, 1) + ":00")));
  },
  /**
   * Measures inner width or height of an element, padding subtracted (unlike jQuery's innerWidth()).
   *
   * Also usable as alternative to jQuery(window).width/height(), which may give wrong result for mobile browsers.
   *
   * @ignore
   * @param {string} d
   *  - Width|Height
   * @param {string|element|array|jquery} slctr
   *  - if window, document.documentElement or document.body: the method disregards other args
   * @param {boolean} [ignorePadding]
   *  - default: false (~ subtract padding, unlike jQuery)
   * @return {integer|undefined}
   */
  _dimInner = function(d, slctr, ignorePadding) {
    var u = slctr, r, dE = document.documentElement, jq, v, p;
    if(u === window) {
      return dE[ "client" + d ]; // clientWidth/clientHeight
    }
    if(u === dE || u === document.body) {
      return dE[ "scroll" + d ]; // scrollWidth/scrollHeight
    }
    if((r = _elm(0, u, 0, "inner" + d))) {
      v = r[ "client" + d ]; // clientWidth/clientHeight
      if(!ignorePadding) {
        if((p = (jq = $(r)).css( "padding-" + (d === "Width" ? "left" : "top") )).indexOf("px") > -1) {
          v -= parseFloat(p);
        }
        if((p = jq.css( "padding-" + (d === "Width" ? "right" : "bottom") )).indexOf("px") > -1) {
          v -= parseFloat(p);
        }
        v = Math.round(v);
      }
      return v;
    }
    return undefined;
  },
  /**
   * Measures or sets effective outer width or height of an element, including padding, border and optionally margin.
   *
   * The width/height will be set on the element itself, in pixels.
   *
   * If selector is window, then window scrollbar is included.
   *
   * @ignore
   * @param {string} d
   *  - Width|Height
   * @param {string|element|array|jquery} slctr
   *  - if window, document.documentElement or document.body: the method disregards other args and simply measures
   * @param {boolean} [includeMargin]
   *  - default: false (~ dont check margin)
   * @param {integer|falsy} [set]
   *  - set outer width/height (including padding, and optionally also margin) to that number of pixels
   * @param {boolean|integer|falsy} [max]
   *  - default: false (~ set width)
   *  - true|one: set max-width/height, not width/height
   *  - two: set both
   * @return {integer|undefined}
   */
  _dimOuter = function(d, slctr, includeMargin, set, max) {
    var u = slctr, r, dE = document.documentElement, jq, v;
    if(u === window) {
      return dE[ "inner" + d ] || dE[ "client" + d ]; // innerWidth/innerHeight includes scrollbar
    }
    if(u === dE || u === document.body) {
      return dE[ "scroll" + d ];
    }
    if((r = _elm(0, u, 0, "outer" + d))) {
      v = (jq = $(r))[ "outer" + d ](includeMargin); // Let jQuery do the clientWidth + border (+ margin)
      if(!set || // if only measuring
          set === v) { // or dimension correct
        return v;
      }
      v = _dimInner(d, u) + (set - v);
      if(!max || max === 2) {
        jq.css(d.toLowerCase(), v + "px");
      }
      if(max) {
        jq.css("max-" + d.toLowerCase(), v + "px");
      }
      return set;
    }
    return undefined;
  },
  /**
   * Resizes the overlay to fill whole window/document; handler for window resize event.
   *
	 * @ignore
   * @return {void}
	 */
	_ovrlyRsz = function() {
		var w = window, d = document.documentElement, dW, dD;
		_jqOvrly.css({
			width: ((dD = self.innerWidth(d)) > (dW = self.innerWidth(w)) ? dD : dW) + "px",
			height: ((dD = self.innerHeight(d)) > (dW = self.innerHeight(w)) ? dD : dW) + "px"
		});
	};

  /**
   * Use for checking if that window.Judy is actually the one we are looking for (see example).
   * @example
if(typeof window.Judy === "object" && Judy.yduj) {
  ...
}
   * @name Judy.yduj
   * @type boolean
  */
  this.yduj = true;
  /**
   * Use for checking if that window.Judy is actually the one we are looking for (see example).
   * @example
if(typeof window.Judy === "object" && Judy.yduJ) {
  ...
}
   * @name Judy.yduJ
   * @type boolean
  */
  this.yduJ = true;
  /**
   * @name Judy.version
   * @type float
   */
  this.version = 2.1;
  /**
   * Is the browser Internet Explorer, and if so, the version as float.
   *
   * @name Judy.browserIE
   * @type integer|float
   *  - zero if not IE
   */
  this.browserIE = _uaIe = (function() {
    var u;
    if ((u = window.navigator) && (u = u.userAgent)) {
      if (/; MSIE \d{1,2}\.\d/.test(u)) {
        return (u = parseFloat(u.replace(/^.+; MSIE (\d{1,2}\.\d).+/, '$1'))) ? u : 0;
      }
      if (/; Trident\/\d+\.\d+;/.test(u) && /; rv:\d+\.\d+[;\)]/.test(u)) {
        return (u = parseFloat(u.replace(/^.+; rv:(\d+\.\d+)[;\)].+$/, '$1'))) ? u : 0;
      }
    }
    return 0;
  }());
  /**
   * @ignore
   * @return {void}
   */
  this.setup = function() {
    /** @ignore */
    self.setup = function() {}; // Prevent second call.
    _dataName = "judy_" + self.randName();
  };
  //  Type.
  /**
   * All native types are reported in lowercase (like native typeof does).
   *
   * If given no arguments: returns "Judy".
   * Types are:
   * - native, typeof: object string number
   * - native, corrected: function array date regexp image
   * - window, document, document.documentElement (not lowercase)
   * - element, checked via .getAttributeNode
   * - text node: textNode
   * - attribute node: attributeNode
   * - event: event (native and prototyped W3C Event and native IE event)
   * - jquery
   * - emptyish and bad: undefined, null, NaN, infinite
   * - custom or prototyped native: all classes having a typeOf() method.
   *
   * RegExp is an object of type regexp (not a function - gecko/webkit/chromium).
   * Does not check if Date object is NaN.
   *
   * Is same as Inspect.typeOf().
   * @function
   * @name Judy.typeOf
   * @param {mixed} u
   * @return {string}
   */
  this.typeOf = function(u) {
    var t = typeof u;
    if(!arguments.length) {
      return "Judy";
    }
    switch(t) {
      case "boolean":
      case "string":
        return t;
      case "number":
        return isFinite(u) ? t : (isNaN(u) ? "NaN" : "infinite");
      case "object":
        if(u === null) {
          return "null";
        }
        //  Accessing properties of object may err for various reasons, like missing permission (Gecko).
        try {
          if(u.typeOf && typeof u.typeOf === "function") {
            return u.typeOf();
          }
          else if(typeof u.length === "number" && !(u.propertyIsEnumerable("length")) && typeof u.splice === "function") {
            return "array";
          }
          else if(u === window) {
            return "window";
          }
          else if(u === document) {
            return "document";
          }
          else if(u === document.documentElement) {
            return "document.documentElement";
          }
          else if(u.getAttributeNode) { // element
            //  document has getElementsByTagName, but not getAttributeNode -  document.documentElement has both
            return u.tagName.toLowerCase === "img" ? "image" : "element";
          }
          else if(u.nodeType) {
            switch(u.nodeType) {
              case 3:return "textNode";
              case 2:return "attributeNode";
            }
            return "otherNode";
          }
          else if(typeof u.stopPropagation === "function" ||
              (u.cancelBubble !== undefined && typeof u.cancelBubble !== "function" &&
              typeof u.boundElements === "object")) {
            return "event";
          }
          else if(typeof u.getUTCMilliseconds === "function") {
            return "date";
          }
          else if(typeof u.exec === "function" && typeof u.test === "function") {
            return "regexp";
          }
          else if(u.hspace && typeof u.hspace !== "function") {
            return "image";
          }
          else if(u.jquery && typeof u.jquery === "string" && !u.hasOwnProperty("jquery")) {
            return "jquery";
          }
        }
        catch(er) {
        }
        return t;
      case "function":
        //  gecko and webkit reports RegExp as function instead of object
        return (u.constructor === RegExp || (typeof u.exec === "function" && typeof u.test === "function")) ?
          "regexp" : t;
    }
    return t;
  };
  /**
   * Is container Object or Array (if arg orArray), and not a built-in type or jquery.
   *
   * Non-containers; built-in types and jquery:
   * - window, document, document.documentElement, element
   * - textNode, attributeNode, otherNode
   * - image
   * - event
   * - date
   * - regexp
   * - jquery
   *
   * @function
   * @name Judy.isContainer
   * @param {mixed} u
   * @param {boolean} [orArray]
   *  - allow array
   * @return {string|boolean}
   *  - string: 'object' (any kind of non-array container) or 'array'
   *  - false: not a container
   */
  this.isContainer = function(u, orArray) {
    var t;
    return u && typeof u === "object" &&
        (
          (t = self.typeOf(u)) === "object" || (orArray && t === "array") || (
            t !== "array" &&
            self.arrayIndexOf(_nonObj, t) === -1 )
        ) ? (!orArray || t !== "array" ? "object" : t) : false;
  };
  /**
   * @function
   * @name Judy.isArray
   * @param {mixed} u
   * @return {boolean}
   */
  this.isArray = function(u) {
    //  Douglas Crockford's expression:
    return (u && typeof u === "object" &&
        typeof u.length === "number" && !(u.propertyIsEnumerable("length")) && typeof u.splice === "function");
  };
  /**
   * A "number" is not a number, use jQuery.isNumeric() for more lenient check.
   * @function
   * @name Judy.isNumber
   * @param {mixed} u
   * @return {boolean}
   */
  this.isNumber = function(u) {
    return typeof u === "number" && isFinite(u);
  };
  /**
   * @function
   * @name Judy.isInt
   * @param {mixed} u
   * @param {boolean} [nonNegative]
   *  - default: false (~ allow negative integer)
   * @return {boolean}
   */
  this.isInt = function(u, nonNegative) {
    return typeof u === "number" && isFinite(u) && (u % 1 === 0) && (!nonNegative || u > -1);
  };

  //  Containers.
  /**
   * Alternative to clone, when arg u is a simple Object container or array.
   *
   * Optionally copies child objects|arrays instead of referring them.
   * Checks self-references in depth 1.
   *
   * No support for arguments collection in old browsers; see {@link Judy.toArray}().
   * @function
   * @name Judy.containerCopy
   * @see Judy.toArray()
   * @param {object|arr} oa
   * @param {boolean} [shallow]
   *  - default: false (~ recursive, also child objects will be copies)
   *  - truthy: child objects are references
   * @return {mixed}
   */
  this.containerCopy = function(oa, shallow) {
    var t, c = {}, p, v;
    if(!oa || !(t = self.isContainer(oa, true))) {
      return oa;
    }
    if(t === "array") {
      if(shallow) {
        return oa.concat();
      }
      c = [];
    }
    for(p in oa) {
      if(oa.hasOwnProperty(p)) {
        c[p] = ((v = oa[p]) && typeof v === "object") ?
            (v === oa ? c : (!shallow ? self.containerCopy(v, false) : v)) :
            v;
      }
    }
    return c;
  };
  /**
   * Get property of simple or multidimensional object/array.
   *
   * Doesnt check for bad number key args; infinite, NaN.
   * @example // Get value of o.some.deep[3].bucket, if exists:
Judy.objectGet(o, some, deep, 3, bucket);
   * @function
   * @name Judy.objectGet
   * @throws Error
   *  - (caught) if bad arg(s): only one arg | first arg not object | a later arg not integer or non-empty string
   * @param {object} o
   * @param {string|integer} anyNumberOfKeys
   * @return {mixed|undefined}
   */
  this.objectGet = function(o, anyNumberOfKeys) {
    var a = arguments, le = a.length, u = o, p, i;
    try {
      if(!u || typeof u !== "object") {
        throw new Error("arg o isnt object");
      }
      if(le < 2) {
        throw new Error("no key arg");
      }
      for(i = 1; i < le; i++) {
        if(i > 1 && (!u || typeof u !== "object")) {
          return undefined;
        }
        if((!(p = a[i]) && p !== 0) || !(p = "" + p)) { // try stringing it, to make it err at right place
          throw new Error("arg #"+i+"["+p+"] type[" + self.typeOf(p) + "] isnt integer or non-empty string");
        }
        if(u.hasOwnProperty(p)) {
          u = u[p];
        }
        else {
          return undefined;
        }
      }
      return u;
    }
    catch(er) {
      _errorHandler(er, null, _name + ".objectGet()");
    }
    return undefined;
  };
  /**
   * Like Object.keys(), which may not be implemented by current browser (ECMAScript 5).
   * @function
   * @name Judy.objectKeys
   * @param {object} o
   * @return {array|null}
   *  - null if not object
   */
  this.objectKeys = function(o) {
    var a, k;
    if(!o || typeof o !== "object") {
      return null;
    }
    if(typeof Object.keys === "function") {
      return Object.keys(o);
    }
    a = [];
    for(k in o) {
      if(o.hasOwnProperty(k)) {
        a.push(k);
      }
    }
    return a;
  };
  /**
   * Value-to-key mapper - String.indexOf() for objects.
   * @function
   * @name Judy.objectKeyOf
   * @param {object} o
   * @param {mixed} v
   * @return {mixed}
   *  - undefined if arg v is undefined, or arg o isnt object, or arg o doesnt contain arg v value
   */
  this.objectKeyOf = function(o, v) {
    var k;
    if(v !== undefined && o || typeof o === "object") {
      for(k in o) {
        if(o.hasOwnProperty(k) && o[k] === v) {
          return k;
        }
      }
    }
    return undefined;
  }
  /**
   * Get copy of object, sorted by value.
   *
   * If two or more buckets have the same value, the last bucket will overwrite the previous.
   *
   * Will not sort right if a bucket is a string whose first char is DEL (ascii 127).
   *
   * @function
   * @name Judy.objectSort
   * @param {object} o
   * @return {object}
   */
  this.objectSort = function(o) {
    var a = [], oByVal = {}, os = {}, k, v, cNum = String.fromCharCode(127), le, i = 0;
    if(!o || typeof o !== "object") {
      return o;
    }
    //  make object mapping value to key, and array of values
    for(k in o) {
      if(o.hasOwnProperty(k)) {
        ++i;
        //  prefix DEL if number
        oByVal[ (typeof (v = o[k]) !== "number" ? "" : cNum) + v ] = k;
        a.push(v);
      }
    }
    if(!i) {
      return o;
    }
    le = i;
    a.sort();
    for(i = 0; i < le; i++) {
      os[ oByVal[ (typeof (v = a[i]) !== "number" ? "" : cNum) + v ] ] = v;
    }
    return os;
  };
  /**
   * Get copy of object, sorted by key.
   * @function
   * @name Judy.objectKeySort
   * @param {object} o
   * @return {o|null}
   */
  this.objectKeySort = function(o) {
    var a, os = {}, le, i;
    if(!(a = self.objectKeys(o)) || (le = a.length) < 2) {
      return a ? o : null;
    }
    a.sort();
    for(i = 0; i < le; i++) {
      os[ a[i] ] = o[ a[i] ];
    }
    return os;
  };
  /**
   * Copy object's public properties to an array.
   *
   * Particularly handy for function arguments.
   * Arguments is a collection, not an array, and in older browsers (IE<9) it may not even have .hasOwnProperty().
   * @function
   * @name Judy.toArray
   * @param {object} o
   * @return {array|null}
   *  - null if arg o isnt an object
   */
  this.toArray = function(o) {
    var a, le, i;
    if(o && typeof o === "object") {
      if(typeof o.hasOwnProperty === "function") { // Should catch rubbish IE<9 arguments collection.
        return Array.prototype.slice.call(o);
      }
      a = [];
      le = o.length;
      for(i = 0; i < le; i++) {
        a.push(o[i]);
      }
      return a;
    }
    return null;
    //  When IE<9 is history:
    //  return o && typeof o === "object" ? Array.prototype.slice.call(o) : null;
  };
  /**
   * String.indexOf for Array.
   *
   * Values are === checked; i.e. type sensitive ("0" is not 0).
   * And for objects and arrays - as value - requiring identity; one {} does not === equal another {} in Javascript.
   *
   * No argument error checking; this method has to be as fast as possible.
   *
   * @example // Looking for an 'inArray' method?
if (Judy.arrayIndexOf(arr, val) > -1) { ...
   * @function
   * @name Judy.arrayIndexOf
   * @param {array} a
   * @param {mixed} v
   * @return {integer}
   *  - minus 1 if not found
   */
  this.arrayIndexOf = function(a, v) {
    var le = a.length, i;
    for(i = 0; i < le; i++) {
      if(a[i] === v) {
        return i;
      }
    }
    return -1;
  };
  /**
   * Merge two objects or two arrays recursive, let second object|array's attributes overwrite first object|array's attributes.
   *
   * The first arg object/array will be changed (return value is boolean), but sub objects/arrays are mostly copies (not references).
   *
   * Skips overriding when:
   * - overwriter bucket is undefined (but exists anyways)
   * - overwriter bucket is null, and original bucket isnt undefined (a concession to PHP; which has no undefined, only null)
   *
   * Which object types arent considered 'object': see {@link Judy.isContainer}().
   *
   * Max recursion depth: 10.
   * @function
   * @name Judy.merge
   * @throws {TypeError}
   *  - (caught) if oa and overrider arent both object or both array
   * @throws {Error}
   *  - (caught) if recursing deeper than 10
   * @param {object|arr} oa
   * @param {object|arr} oa1
   * @param {integer|undefined} [isContainer]
   *  - falsy: dont know
   *  - 1: args oa and overrider are both know to be objects (and not built-in types {@link Judy.isContainer} or jQuery)
   *  - 2: args oa and overrider are both know to be arrays
   * @return {boolean}
   *  - success/error; doesnt return object/array, changes arg oa
   */
  /*
  this.merge = function(oa, oa1, isContainer, _depth) {
    var tc = isContainer !== true ? isContainer : 0, // fix fairly obvious arg error
        t = tc || self.isContainer(oa), t1 = tc || self.isContainer(oa1),
        d = arguments[3] || 0, // depth
        p, le, le1, v, v1, tSub;
    try {
      if(d < 10) {
        if(t === 1) {
          if(t1 === 1) {
            for(p in oa1) {
              if(oa1.hasOwnProperty(p) &&
                  (v1 = oa1[p]) !== undefined) { // undefined must never overwrite anything
                //  if original doesnt have any (or it is undefined, sic), its simple
                if((v = oa[p]) === undefined || !oa.hasOwnProperty(p)) {
                  oa[p] = v1; // null might overwrite undefined
                }
                else if(v1 !== null) { // null must never overwrite anything but undefined
                  if(!(tSub = self.isContainer(v)) || self.isContainer(v1) !== tSub) {
                    oa[p] = v1;
                  }
                  else {
                    self.merge(v, v1, tSub, d + 1);
                  }
                }
              }
            }
            return true;
          }
          throw new TypeError("Second arg object/array isnt object, but " + self.typeOf(oa1));
        }
        else if(t === 2) {
          if(t1 === 2) {
            if((le1 = oa1.length)) { // does overwriter contain anything at all?
              if(!(le = oa.length)) {
                oa = oa1.concat(); // copy
              }
              else {
                for(p = 0; p < le1; p++) {
                  if((v1 = oa1[p]) !== undefined) { // undefined must never overwrite anything
                    if(p >= le) { // if original isnt that long, append
                      oa.push(v1);
                    }
                    else if((v = oa[p]) === undefined) { // if original's is undefined, overwrite
                      oa[p] = v1;
                    }
                    else if(v1 !== null) { // null must never overwrite anything but undefined
                      if(!(tSub = self.isContainer(v)) || self.isContainer(v1) !== tSub) {
                        oa[p] = v1;
                      }
                      else {
                        self.merge(v, v1, tSub, d + 1);
                      }
                    }
                  }
                }
              }
            }
            return true;
          }
          throw new TypeError("Second arg object/array isnt array, but " + self.typeOf(oa1));
        }
        throw new TypeError("First arg object/array is " + self.typeOf(oa1));
      }
      throw new Error("Cant recurse > 10, circular ref?");
    }
    catch(er) {
      _errorHandler(er, null, _name + ".merge()");
    }
    return false;
  };
  */
  this.merge = function(oa, oa1, isContainer, _depth) {
    var tBoth = isContainer !== true ? isContainer : 0, // fix fairly obvious arg error
        t = tBoth || self.isContainer(oa, true), t1 = tBoth || self.isContainer(oa1, true),
        d = _depth || 0,
        p, le, le1, v, v1;
    try {
      if(d < 10) {
        if(t && t1) {
          if(t === "object") {
            if(t1 === "object") { // Both object.
              for(p in oa1) {
                if(oa1.hasOwnProperty(p) &&
                    (v1 = oa1[p]) !== undefined) { // undefined must never overwrite anything
                  //  if original doesnt have any (or it is undefined, sic), its simple
                  if((v = oa[p]) === undefined || !oa.hasOwnProperty(p)) {
                    oa[p] = v1; // null might overwrite undefined
                  }
                  else if(v1 !== null) { // null must never overwrite anything but undefined
                    if(!(t = self.isContainer(v, true)) || self.isContainer(v1, true) !== t) {
                      oa[p] = v1;
                    }
                    else {
                      self.merge(v, v1, t, d + 1);
                    }
                  }
                }
              }
              return true;
            }
            throw new TypeError("Type mismatch, first is object type[" + self.typeOf(oa) + "], second is array");
          }
          else if(t1 === "array") { // Both array.
            if((le1 = oa1.length)) { // does overwriter contain anything at all?
              if(!(le = oa.length)) {
                oa = oa1.concat(); // copy
              }
              else {
                for(p = 0; p < le1; p++) {
                  if((v1 = oa1[p]) !== undefined) { // undefined must never overwrite anything
                    if(p >= le) { // if original isnt that long, append
                      oa.push(v1);
                    }
                    else if((v = oa[p]) === undefined) { // if original's is undefined, overwrite
                      oa[p] = v1;
                    }
                    else if(v1 !== null) { // null must never overwrite anything but undefined
                      if(!(t = self.isContainer(v, true)) || self.isContainer(v1, true) !== t) {
                        oa[p] = v1;
                      }
                      else {
                        self.merge(v, v1, t, d + 1);
                      }
                    }
                  }
                }
              }
            }
            return true;
          }
          throw new TypeError("Type mismatch, first is array, second is type[" + self.typeOf(oa1) + "]");
        }
        throw new TypeError("First arg is type[" + self.typeOf(oa) + "], second is type[" + self.typeOf(oa1) + "]");
      }
      throw new Error("Cant recurse > 10, circular ref?");
    }
    catch(er) {
      _errorHandler(er, null, _name + ".merge()");
    }
    return false;
  };

  //  DOM.
  /**
   * Get an ancestor element, of a particular type and/or having id and/or having css class(es).
   *
   * No support for selector name attribute.
   *
   * Dont look for body element as ancestor; returns when reaching body (or 100th ancestor) and doesnt check whether body matches arg selector.
   *
   * @function
   * @name Judy.ancestor
   * @param {string|element|array|jquery} selector
   *  - jQuery/css selector or element (not window or document.documentElement)
   * @param {string} [parentSelector]
   *  - if falsy: returns immediate parent (except if arg element is window)
   *  - like jQuery() selector arg: tagName and/or id and/or css class(es), name name attribute not supported, and class(es) cant go before #id
   * @param {integer} [max]
   *  - default: no maximum
   *  - positive number: dont look any further, 1 ~ parent | 2 ~ grand parent | etc.
   * @return {element|undefined|false}
   *  - false if arg element isnt an element or window
   *  - undefined if no such parent, or arg element is window
   *  - undefined if reaches the body element, and selector doesnt suggest the the body element
   */
  this.ancestor = function(selector, parentSelector, max) {
    var u, r = _elm(0, selector, null, "ancestor"), tt = parentSelector, lim = max && max > 0 ? (max + 1) : 101, id, aCls, tn, cls, le, i;
    if(!r || r === window || r === document.documentElement) {
      return undefined;
    }
    if(!tt || !(tt = $.trim(""+tt))) {
      return r.parentNode;
    }
    if(tt.indexOf("#") > -1) {
      u = tt.replace(/^([^\#]+)?\#([^\.]+)(\..+)?$/, "$2,$1$3").split(",");
      id = u[0];
      tt = u[1] || "";
    }
    if(tt.indexOf(".") > -1) {
      aCls = tt.split(".");
      tt = aCls[0];
      aCls.splice(0, 1);
      le = aCls.length;
    }
    tt = tt.toLowerCase();
    while((--lim) && (r = r.parentNode)) {
      if(r.nodeType !== 1 ||
          tn === "body") { // check from last level (first time tn is falsy)
        return undefined;
      }
      tn = r.tagName.toLowerCase();
      if( (tt && tn !== tt) ||
          (id && r.id !== id) ) {
        continue;
      }
      if(le) {
        if(!(cls = r.className).length) {
          continue;
        }
        cls = " " + cls + " ";
        u = 0;
        for(i = 0; i < le; i++) {
          if(cls.indexOf(aCls[i]) === -1) {
            continue;
          }
          ++u;
        }
        if(u < le) {
          continue;
        }
      }
      return r;
    }
    return undefined;
  };

  //  Event.

  /**
   * Establishes a single CSS/jQuery selector string.
   *
   *  (string) selector:
   *  - doesnt check existance of such element(s), because must be usable for future elements as well
   *  - doesnt check validity of the CSS expression
   *
   * window, document, document.documentElement translate to _win_, _doc_, _docElm_.
   *
   * @function
   * @name Judy.selector
   * @param {string|element} selector
   * @param {boolean} [findName]
   *  - look for name attribute, and return array
   * @return {string|Array|null}
   *  - array: if findName; [ selector ] or [ selector, name ]
   *  - null on error
   */
  this.selector = function(selector, findName) {
    var s = selector, f = findName, t = typeof s, x, v, tg;
    try {
      if (!s) {
        throw new Error('Falsy selector, type[' + t + ']');
      }
      if (t === 'string') {
        // Test name attribute.
        return !f ? s : (s.indexOf('[name=') === -1 ? [s] : [s, s.replace(/^.*\[name=['\"]([^'\"]+)['\"]\].*$/, '$1') ]);
      }
      else if (t === 'object') {
        if ($.isWindow(s)) {
          x = '_win_';
        }
        else if (s === document) {
          x = '_doc_';
        }
        else if (s === document.documentElement) {
          x = '_docElm_';
        }
        if (x) {
          return !f ? x : [x];
        }
        if (typeof s.getAttributeNode !== 'function' || typeof s.getAttribute !== 'function') {
          throw new Error('Selector, type[' + t + '], isnt non-empty string|element');
        }
        tg = s.tagName.toLowerCase();
        if ((v = s.getAttribute('name'))) {
          x = tg + '[name="' + v + '"]';
          return !f ? x : [ x, v ];
        }
        if ((v = s.id)) {
          x = '#' + v;
        }
        else if ((v = s.className)) {
          x = tg + '.' + v.replace(/ +/g, '.');
        }
        else if ((v = s.getAttribute('type'))) {
          x = tg + '[type="' + v + '"]';
        }
        else {
          x = tg;
        }
        return !f ? x : [x];
      }
      else {
        throw new Error('Selector, type[' + t + '], isnt non-empty string|element');
      }
    }
    catch (er) {
      _errorHandler(er, null, _name + '.selector()')
    }
    return null;
  };
  /**
   * Like jQuery().delegate and .on() the listener will apply now and in the future, no matter if such element(s) exist when calling this method.
   *
   * @example
Judy.ajaxcomplete(slctr, '/some/url', oData, fHandler, oFilter);
Judy.ajaxcomplete(slctr, '/some/url', oData, fHandler);
Judy.ajaxcomplete(slctr, '/some/url', fHandler, oFilter);
Judy.ajaxcomplete(slctr, '/some/url', fHandler);
   * @function
   * @name Judy.ajaxcomplete
   * @param {string|element|array|jquery} selector
   * @param {string} url
   *  - '*' means all responses
   *  - use '/system/ajax' for Drupal Form API AJAX
   *  - protocol and domain gets stripped off, and full path isnt necessary (is being matched against start of any AJAX url)
   * @param {object} [data]
   *  - or (function) handler
   * @param {function} [handler]
   *  - or (object) filter
   * @param {object|array} [filter]
   *  - object keying properties of ajax settings object ('!key's mean exclude), values may be simple variables and regexes
   *  - or an array of such
   * @return {void}
   */
  this.ajaxcomplete = function(selector, url, data, handler, filter) {
    var s = selector, t = typeof s, nm, u = url, d = data, h = handler, f = filter, a, le, i, v;
    try {
      if (!s) {
        throw new Error('Falsy selector, type[' + t + ']');
      }
      if (t === 'object') {
        if (s instanceof $) {
          s = s.selector || s.get();
        }
        if ($.isArray(s)) {
          if (!(le = s.length)) {
            throw new Error('Empty selector, type array or jquery');
          }
          for (i = 0; i < le; i++) {
            self.ajaxcomplete(s[i], u, d, h, f);
            return;
          }
        }
      }
      if (!(a = self.selector(s, true))) {
        throw new Error('Bad selector, see previous error');
      }
      nm = a[1]; // name attribute (if any), for matching against Drupal Form API ajax.settings._triggering_element_name.
      s = a[0];
      // Resolve other arguments.
      if (!u || typeof u !== 'string') {
        throw new Error('Url type[' + self.typeOf(v) + '] isnt non-empty string');
      }
      if (u !== '*') {
        if (u.indexOf('http') === 0) {
          u = u.replace(/^https?:\/\/[^\/]+(\/.+)$/, '$1');
        }
        else if (u.charAt(0) !== '/') {
          u = '/' + u;
        }
      }
      if (h) {
        if (typeof h === 'object') {
          f = h;
          h = null;
        }
      }
      if (d && typeof d === 'function') {
        h = d;
        d = null;
      }
      if (!h) {
        throw new Error('Cant resolve a handler');
      }
      // Initialise jQuery ajaxComplete listening.
      if (!_acInit) {
        $(document).ajaxComplete(function(event, xhr, settings) {
          var url = self.objectGet(settings, 'url'), all = [], nm, val, le, i, n, j, k, $jq, nElms, fElms, elms, elm, lstnr, h, d, evt;
          if (url) {
            if (url.indexOf('http') === 0) { // Non-Form API urls apparently include protocol and domain.
              url = url.replace(/^https?:\/\/[^\/]+(\/.+)$/, '$1');
            }
            for (k in _acLstnrs) {
              if (_acLstnrs.hasOwnProperty(k) && url.indexOf(k) === 0) {
                all.push(_acLstnrs[k]);
              }
            }
            if (_acLstnrs['*'] && _acLstnrs.hasOwnProperty('*')) {
              all.push(_acLstnrs['*']);
            }
            if ((le = all.length)) {
              // If Drupal Form API _triggering_element_name we will only go for that particular selector.
              if ((nm = self.objectGet(settings, 'extraData', '_triggering_element_name'))) { // Drupal Form API property.
                if (!($jq = $('[name="' + nm + '"]')).length) {
                  return;
                }
                if ((val = self.objectGet(settings, 'extraData', '_triggering_element_value')) !== undefined) { // Drupal Form API property.
                  if (!($jq = $jq.filter('[value="' + val + '"]')).length) {
                    return;
                  }
                }
                nElms = (fElms = $jq.get()).length;
              }
              for (i = 0; i < le; i++) {
                n = all[i].length;
                for (j = 0; j < n; j++) {
                  lstnr = $jq = elms = h = d = evt = null; // Clear references (loop).
                  lstnr = all[i][j];
                  if (nm) {
                    if (lstnr[1] !== nm || (lstnr[4] && !_filter(settings, lstnr[4]))) {
                      continue;
                    }
                    elms = fElms;
                  }
                  else {
                    nElms = 1;
                    switch (lstnr[0]) {
                      case '_win_':
                        elms = [window];
                        break;
                      case '_doc_':
                        elms = [document];
                        break;
                      case '_docElm_':
                        elms = [document.documentElement];
                        break;
                      default:
                        nElms = (elms = $(lstnr[0]).get()).length;
                    }
                    if (!nElms || (lstnr[4] && !_filter(settings, lstnr[4]))) {
                      continue;
                    }
                  }
                  h = lstnr[2];
                  d = lstnr[3];
                  evt = !d ? {
                    type: 'ajaxcomplete'
                  } : {
                    type: 'ajaxcomplete',
                    data: d
                  };
                  evt.ajax = settings;
                  for (k = 0; k < nElms; k++) {
                    elm = null; // Clear references (loop);
                    elm = elms[k];
                    h.apply(
                      elm,
                      [evt]
                    );
                  }
                }
              }
            }
          }
        });
        _acInit = true;
      }
      // Resolve filter.
      if (f) {
        if (!$.isArray(f)) {
          f = [f];
        }
        if (u === '*') { // Add safe filters if responding to wildcard url, to prevent risk of perpetual logging etc.
          f = f.concat(_acFltrs);
        }
      }
      else if (u === '*') { // Add safe filters if responding to wildcard url, to prevent risk of perpetual logging etc.
        f = _acFltrs;
      }
      // Add listeners, keyed by url.
      if (!_acLstnrs[u]) {
        _acLstnrs[u] = [
          [s, nm, h, d, f]
        ];
      }
      else {
        _acLstnrs[u].push(
          [s, nm, h, d, f]
        );
      }
    }
    catch (er) {
      _errorHandler(er, null, _name + '.ajaxcomplete()')
    }
  };
  /**
   * NB: .ajaxcomplete.off (not .ajaxcomplete_off); jsDoc failure.
   *
   * @example
Judy.ajaxcomplete.off(slctr, sUrl, fHandler);
Judy.ajaxcomplete.off(slctr, sUrl);
Judy.ajaxcomplete.off(slctr, fHandler);
Judy.ajaxcomplete.off(slctr);
   * @function
   * @name Judy.ajaxcomplete_off
   * @param {string|element|array|jquery} selector
   * @param {string|falsy} [url]
   * @param {function|falsy} [handler]
   * @return {void}
   */
  this.ajaxcomplete.off = function(selector, url, handler) {
    var s = selector, t = typeof s, u = url, h = handler, nm, lstnrs, a, le, i, rm = [], sbtrt;
    try {
      if (!_acInit) {
        return;
      }
      if (!s) {
        throw new Error('Falsy selector, type[' + t + ']');
      }
      if (t === 'object') {
        if (s instanceof $) {
          s = s.selector || s.get();
        }
        if ($.isArray(s)) {
          if (!(le = s.length)) {
            throw new Error('Empty selector, type array or jquery');
          }
          for (i = 0; i < le; i++) {
            self.ajaxcomplete.off(s[i], u, h);
            return;
          }
        }
      }
      if (!(a = self.selector(s, true))) {
        throw new Error('Bad selector, see previous error');
      }
      nm = a[1]; // name attribute (if any), for matching against Drupal Form API ajax.settings._triggering_element_name.
      s = a[0];
      // Resolve other arguments.
      if (u) {
        if ((t = typeof u) === 'function') {
          h = u;
          u = null;
        }
        else {
          if (t !== 'string') {
            throw new Error('Url type[' + self.typeOf(v) + '] isnt non-empty string');
          }
          if (u.indexOf('http') === 0) {
            u = u.replace(/^https?:\/\/[^\/]+(\/.+)$/, '$1');
          }
          else if (u.charAt(0) !== '/') {
            u = '/' + u;
          }
        }
      }
      // Remove.
      if (u) {
        _acOff(u, s, nm, h);
      }
      else {
        for (u in _acLstnrs) {
          _acOff(u, s, nm, h);
        }
      }
    }
    catch (er) {
      _errorHandler(er, null, _name + '.ajaxcomplete.off()')
    }
  };

  /**
   * Add keystrokes qualified keydown event handler to one or more elements.
   *
   * The preventDefault arg is ignored for unqualifed event types.
   * Any order of parameters data, handler and preventDefault will do (finds args via type check; object vs. function vs. boolean).
   * Uses jQuery().on() if exists, otherwise .bind().
   *
   * @function
   * @name Judy.keydown
   * @example
//  Qualified event type, e.g. specific keystroke combination:
Judy.keydown(selector, "ctr_shift_7"|"keydown_ctr_shift_7"|"ctr_shift_7 ctr_s", handler);
Judy.keydown(selector, "ctr_shift_7"|"keydown_ctr_shift_7", data, handler);
Judy.keydown(selector, "ctr_shift_7"|"keydown_ctr_shift_7", data, handler, preventDefault);
Judy.keydown(selector, "ctr_shift_7"|"keydown_ctr_shift_7", handler, preventDefault);
//  Unqualified event type (no specific keystrokes) is handled by jQuery(selector).keydown(...) directly:
Judy.keydown(selector, handler);
Judy.keydown(selector, data, handler);
Judy.keydown(selector, ""|"*"|"keydown", handler);
Judy.keydown(selector, ""|"*"|"keydown", data, handler);
   * @param {string|element|array|jquery} selector
   *  - works on multiple elements
   * @param {string} [events]
   *  - see example
   *  - default: * (~ any keystroke)
   * @param {object} [data]
   * @param {func} handler
   * @param {boolean} [preventDefault]
   * @return {boolean}
   */
  this.keydown = function() {
    try {
      _bindKeys("keydown", arguments);
      return true;
    }
    catch(er) {
      _errorHandler(er, null, _name + ".keydown()");
    }
    return false;
  };

  /**
   * Add keystrokes qualified keyup event handler to one or more elements.
   *
   * @see Judy.keydown()
   * @function
   * @name Judy.keyup
   * @param {string|element|array|jquery} selector
   *  - works on multiple elements
   * @param {string} [events]
   *  - see .keydown() example
   *  - default: * (~ any keystroke)
   * @param {object} [data]
   * @param {func} handler
   * @param {boolean} [preventDefault]
   * @return {boolean}
   */
  this.keyup = function() {
    try {
      _bindKeys("keyup", arguments);
      return true;
    }
    catch(er) {
      _errorHandler(er, null, _name + ".keyup()");
    }
    return false;
  };
  /**
   * List event handlers added via jQuery.
   *
   * @function
   * @name Judy.eventList
   * @throws {Error}
   *  - (caught) if bad arg, or jQuery .data("Judy") isnt object or undefined
   * @param {string|element|array|jquery} selector
   *  - only works on a single (first) element
   * @param {string} [type]
   * @return {object|array|null|undefined}
   *  - object: all event types
   *  - arr: single event type
   *  - null: no events/no events of that type
   *  - undefined: selector matches no element
   */
  this.eventList = function(selector, type) {
    var r = _elm(0, selector, null, "eventList"), jq, o, k;
    if(!r) {
      return undefined;
    }
    jq = $(r);
    if((o = jq.data())) {
      //  Sometimes jQuery's data, like events, arent residing in the object root, but in a sub-object keyed jquery[lots hex chars]???
      if(!o.hasOwnProperty("events")) {
        for(k in o) {
          if(k.length > 7 && o.hasOwnProperty(k) && k.indexOf("jQuery") === 0) {
            if(!(o = o[k]) || !o.events || !o.hasOwnProperty("events")) {
              return null;
            }
          }
        }
      }
    }
    if(!o) {
      return null;
    }
    if(!type) {
      return o.events;
    }
    o = o.events;
    for(k in o) {
      if(k === type && o.hasOwnProperty(k)) {
        return o[k];
      }
    }
    return null;
  };

  //  Fields.
   /**
   * Check if element is a form field.
   *
   * Usable when setting key event on document.documentElement or another container, and action on a form field isnt desired.
   *
   * object and button elements arent supported, but input button/submit/reset is.
   *
   * @function
   * @name Judy.isField
   * @param {element} elm
   *  - element, not css-selector
   * @param {boolean} [button]
   *  - allow button (input type:button|submit|reset)
   * @return {boolean|undefined}
   *  - undefined: arg element isnt an element
   */
  this.isField = function(elm, button) {
    return typeof elm === "object" && elm.tagName ? (_fieldType(elm, button) ? true : false) : undefined;
  };
  /**
   * Get type of a field or input button element.
   *
   * object and button elements arent supported, but input button/submit/reset is.
   *
   * @function
   * @name Judy.fieldType
   * @param {string|element|array|jquery} selector
   *  - only works on a single (first) element
   * @param {string|element|jquery} [context]
   *  - default: document is context
   * @param {boolean} [button]
   *  - allow button (input type:button|submit|reset)
   * @return {string|undefined}
   *  - undefined: no such element
   */
  this.fieldType = function(selector, context, button) {
    var r = _elm(0, selector, context, "fieldType");
    return r ? _fieldType(r, button) : undefined;
  };

  /**
   * Get/set value of any kind of field or button, even radios and Drupal checkbox list.
   *
   * Do not use "" as empty option for select or check list ('checkboxes'); use "_none" instead.
   *
   * If arg type, then the method trusts that; doesnt check if it's correct.
   *
   * object and button elements arent supported, but input button/submit/reset is.
   *
   * @function
   * @name Judy.fieldValue
   * @param {string|element|array|jquery} selector
   *  - only works on a single (first) element
   * @param {element|string|falsy} [context]
   *  - default: document is context
   * @param {string|number|array|undefined} [val]
   *  - default: undefined (~ get value, dont set)
   * @param {string|undefined} [type]
   *  - optional field type hint (text|textarea|checkbox|checkboxes|radios|select|other input type)
   * @return {string|array|boolean|undefined}
   *  - empty string (getting only) if empty value or none checked|selected
   *  - array (getting only) if check list or multiple select, and some option(s) checked/selected
   *  - true if setting succeeded
   *  - false if setting failed
   *  - undefined if no such field exist, or this method doesnt support the field type
   */
  this.fieldValue = function(selector, context, val, type) {
    var r = _elm(0, selector, context, "fieldValue"), t;
    if(r && (t = type || _fieldType(r, true))) {
      switch(t) {
        case "select":
          return _valSelect(r, val);
        case "checkbox":
          return _valCheckbox(r, val);
        case "checkboxes":
        case "checklist":
          return _valChecklist(r, val);
        case "radio":
        case "radios":
          return _valRadio(r, context, val);
        case "image":
          t = "src";
        default:
          t = "";
      }
      if(val === undefined) {
        return !t ? r.value : r.getAttribute(t);
      }
      if(!t) {
        r.value = "" + val;
      }
      else {
        r.setAttribute(t, "" + val);
      }
      return true;
    }
    return undefined;
  };
  /**
   * Handles all field types (also checkbox, checkboxes/check list, and radios), and adds css class 'form-button-disabled' to button.
   *
   * @function
   * @name Judy.disable
   * @param {string|element|array|jquery} selector
   *  - works on multiple elements
   * @param {element|string|falsy} [context]
   *  - default: document is context
   * @param {string} [hoverTitle]
   *  - update the element's (hover) title attribute
   * @return {void}
   */
  this.disable = function(selector, context, hoverTitle) {
    _disable(0, selector, context, hoverTitle);
  };
  /**
   * Handles all field types (also checkbox, checkboxes/check list, and radios), and removes css class 'form-button-disabled' to button.
   *
   * @function
   * @name Judy.enable
   * @param {string|element|array|jquery} selector
   *  - works on multiple elements
   * @param {element|string|falsy} [context]
   *  - default: document is context
   * @param {string} [hoverTitle]
   *  - update the element's (hover) title attribute
   * @return {void}
   */
  this.enable = function(selector, context, hoverTitle) {
    _disable(1, selector, context, hoverTitle);
  };

  /**
   * Confine vertical scrolling of a container to that container; prevent from escalating to enclosing elements.
   *
   * Wraps child elements in div, unless there's only a single child element.
   * Adds css class 'scroll-trapped' to the container.
   *
   * Does nothing if the container is empty, or if the container already has the 'scroll-trapped' css class.
   *
   * @function
   * @name Judy.scrollTrap
   * @param {string|element|array|jquery} selector
   *  - works on multiple elements
   * @param {element|string|falsy} [context]
   *  - default: document is context
   * @param {string} [eventName]
   *  - default: 'Judy.scrollTrap'
   * @return {void}
   */
  this.scrollTrap = function(selector, context, eventName) {
    var a = _elm(true, selector, context, "scrollTrap"), nm = eventName || (_name + ".scrollTrap");
    if(a) {
      $(a).each(function () {
        var preventZone = 100, halfZone, s = this.scrollTop, $self = $(this), $chlds, le, $chld, h;
        if (!$self.hasClass("scroll-trapped")) {
          //  If contains a single element, set scroll-back zone on that element.
          if ((le = ($chlds = $self.children()).get().length) === 1) {
            $chld = $($chlds.get(0));
          }
          else if (le) { // Contains more elements, wrap and set scroll-back zone on the wrapper.
            $chld = $chlds.wrapAll("<div />").parent();
          }
          else { // No children at all, cannot do anything, has to called again (upon insertion of something into the .scrollable).
            return;
          }
          //  Dont do this again.
          $self.addClass("scroll-trapped");
          //  Add scroll-back zone to top and bottom.
          if ((h = this.clientHeight) < 1.5 * preventZone) { // The scroll-back zone shan"t be more than 2/3 of .scrollable"s height.
            preventZone = Math.floor(h / 1.5);
          }
          halfZone = Math.floor(preventZone / 2);
          $chld.css({
            "margin-top": preventZone + "px",
            "margin-bottom": preventZone + "px"
          });
          //  Reset current scroll.
          this.scrollTop = s + preventZone;
          //  Add scroll-back handler.
          $self.bind("scroll." + nm, function() {
            var that = this, s = that.scrollTop, h;
            // if (s < preventZone) {
            //   this.scrollTop = preventZone;
            // }
            // else if (s > (h = that.scrollHeight - that.clientHeight - preventZone)) {
            //   this.scrollTop = h;
            // }
            if (s < halfZone) { // Top.
              that.scrollTop = halfZone; // Scroll half way now.
              setTimeout(function() { // Scroll all the way later.
                that.scrollTop = preventZone;
              }, 100);
            }
            else if (s > (h = that.scrollHeight - that.clientHeight) - halfZone) { // Bottom.
              that.scrollTop = h - halfZone;
              setTimeout(function() {
                that.scrollTop = h - preventZone;
              }, 100);
            }
          });
        }
      });
    }
  };
  /**
   * Make a scrollable element scroll vertically to a numeric offset or the offset of one of it's child elements.
   *
   * @function
   * @name Judy.scrollTo
   * @param {string|element|array|jquery} selector
   *  - only works on a single (first) element
   * @param {element|string|falsy} [context]
   *  - default: document is context
   * @param {number|string|element|array|jquery} offset
   *  - default: zero (~ scroll to top)
   *  - number: scroll to that offset
   *  - string|element|array|jquery: scroll to first matching child element
   * @param {number|undefined} [pad]
   *  - default: zero (~ scroll to exact offset)
   * @return {void}
   */
  this.scrollTo = function(selector, context, offset, pad) {
    var u, par, r, to = offset, p = pad || 0, num, $par, chld, prvntZn = 0, max = -1;
    if((par = _elm(0, selector, context, "scrollTo"))) {
      //  Number or no such child element.
      if (!to || typeof to === "number" || !(r = _elm(0, to, par, "", true))) {
        num = true;
        to = !to || !isFinite(to) || to < 0 ? 0 : to;
      }
      //  Find scroll-back zone, if confined scroll.
      if(($par = $(par)).hasClass("scroll-trapped") && (chld = $par.children().get(0))) {
        prvntZn = parseInt($(chld).css("margin-top").replace(/px/, ""), 10);
        max = par.scrollHeight - par.clientHeight - Math.floor(prvntZn * 0.75); // Stop at a quarter instead half of scroll-back zone.
      }
      //  Numeric; simple.
      if(num) {
        to += prvntZn;
      }
      //  Offset of child element.
      else {
        par.scrollTop = prvntZn; // Scroll to enable measuring position of parent and child relative to document.
        to = (r.offsetTop - par.offsetTop);
      }
      //  Add padding, but prevent negative padding from being larger than a quarter of the scroll-back zone.
      if(p && prvntZn && p < 0 && (p * -1) > (u = Math.floor(prvntZn / 4))) {
        p = -u;
      }
      to += p;
      //  Make sure we dont scroll to far for scroll-trapped parent; scrolling to half-zone (or more) would provoke scroll-back.
      if(max > 0 && to > max) {
        to = max;
      }
      par.scrollTop = to;
    }
  };

  /**
   * Try setting focus on an element, slightly delayed.
   *
   * Attempting to set focus on element may prove fatal, and it is often desirable to postpone focusing until some current procedure has run to its end.
   * This method handles both issues.
   *
   * @function
   * @name Judy.focus
   * @param {string|element|array|jquery} selector
   *  - only works on a single (first) element
   * @param {element|string|falsy} [context]
   *  - default: document is context
   * @param {integer|undefined} [delay]
   *  - default: 20 milliseconds
   * @return {boolean|undefined}
   *  - undefined if no such field exists
   */
  this.focus = function(selector, context, delay) {
    var d = delay || 0, to;
    if(selector) {
      to = setTimeout(function(){ // jslint doesnt like instantiation without a reference to hold the instance.
        var r;
        if((r = _elm(0, selector, context, "", true))) { // No error.
          try {
            r.focus();
          }
          catch(er) {}
        }
      }, d >= 0 ? d : 20);
    }
  };

  //  Style.
  /**
   * Measures inner width of an element, padding subtracted (unlike jQuery's innerWidth()).
   *
   * Also usable as alternative to jQuery(window).width(), which may give wrong result for mobile browsers.
   *
   * @function
   * @name Judy.innerWidth
   * @param {string|element|array|jquery} selector
   *  - only works on a single (first) element
   *  - if window, document.documentElement or document.body: the method disregards other args
   * @param {boolean} [ignorePadding]
   *  - default: false (~ subtract padding, unlike jQuery)
   * @return {integer|undefined}
   */
  this.innerWidth = function(selector, ignorePadding) {
    return _dimInner("Width", selector, ignorePadding);
  };
  /**
   * Measures inner height of an element, padding subtracted (unlike jQuery's innerHeight()).
   *
   * Also usable as alternative to jQuery(window).height(), which may give wrong result for mobile browsers.
   *
   * @function
   * @name Judy.innerHeight
   * @param {string|element|array|jquery} selector
   *  - only works on a single (first) element
   *  - if window, document.documentElement or document.body: the method disregards other args
   * @param {boolean} [ignorePadding]
   *  - default: false (~ exclude padding, unlike jQuery)
   *  - ignored if element is window
   * @return {integer|undefined}
   */
  this.innerHeight = function(selector, ignorePadding) {
    return _dimInner("Height", selector, ignorePadding);
  };
  /**
   * Measures or sets effective outer width of an element, including padding, border and optionally margin.
   *
   * The width will be set on the element itself, in pixels.
   *
   * If selector is window, then window scrollbar is included.
   *
   * @function
   * @name Judy.outerWidth
   * @param {string|element|array|jquery} selector
   *  - only works on a single (first) element
   *  - if window, document.documentElement or document.body: the method disregards other args and simply measures
   * @param {boolean} [includeMargin]
   *  - default: false (~ dont check margin)
   * @param {integer|falsy} [set]
   *  - set outer width (including padding, and optionally also margin) to that number of pixels
   * @param {boolean|integer|falsy} [max]
   *  - default: false (~ set width)
   *  - true|one: set max-width, not width
   *  - two: set both
   * @return {integer|undefined}
   */
  this.outerWidth = function(selector, includeMargin, set, max) {
    return _dimOuter("Width", selector, includeMargin, set, max);
  };
  /**
   * Measures or sets effective outer height of an element, including padding, border and optionally margin.
   *
   * The height will be set on the element itself, in pixels.
   *
   * If selector is window, then window scrollbar is included.
   *
   * @function
   * @name Judy.outerHeight
   * @param {string|element|array|jquery} selector
   *  - only works on a single (first) element
   *  - if window, document.documentElement or document.body: the method disregards other args and simply measures
   * @param {boolean} [includeMargin]
   *  - default: false (~ dont check margin)
   * @param {integer|falsy} [set]
   *  - set outer width (including padding, and optionally also margin) to that number of pixels
   * @param {boolean|integer|falsy} [max]
   *  - default: false (~ set height)
   *  - true|one: set max-height, not height
   *  - two: set both
   * @return {integer|undefined}
   */
  this.outerHeight = function(selector, includeMargin, set, max) {
    return _dimOuter("Height", selector, includeMargin, set, max);
  };

  //  String.
  /**
   * Strip tags, reduce consecutive spaces, and trim spaces.
   *
   * @function
   * @name Judy.stripTags
   * @param {mixed} u
   *  - will be stringed
   * @return {string}
   */
  this.stripTags = function(u) {
    return $.trim(("" + u).replace(/<[^<>]+>/g, " ").replace(/[ ]+/g, " "));
  };
  /**
   * Prepends zero(s) to arg length.
   *
   * @example // converting a newline to \uNNNN format
var s = "\\"+"u" + Judy.toLeading("\n".charCodeAt(0).toString(16), 4); // -> "\u000a"
   * @function
   * @name Judy.toLeading
   * @param {mixed} u - will be stringed
   * @param {integer} [length] default: one
   * @return {string}
   */
  this.toLeading = function(u, length) {
    var le = length || 1;
    return (new Array(le).join("0") + u).substr(-le, le);
  };
  /**
   * @function
   * @name Judy.toUpperCaseFirst
   * @param {mixed} u
   *  - anything stringable
   * @return {string}
   */
  this.toUpperCaseFirst = function(u) {
    var s = ""+u, le = s.length;
    return !le ? "" : (s.charAt(0).toUpperCase() + (le < 2 ? "" : s.substr(1)));
  };

  //  Date.
  /**
   * @function
   * @name Judy.isLeapYear
   * @param {Date|integer|str} u
   * @return {boolean|null}
   *  - null if bad arg
   */
  this.isLeapYear = function(u) {
    var y;
    switch(self.typeOf(u)) {
      case "date":
        y = u.getFullYear();
        break;
      case "number":
        y = u;
        break;
      case "string":
        y = parseInt(u, 10);
        break;
      default:
        return null;
    }
    if(isFinite(y) && u > -1 && u % 1 === 0) {
      return (!(y % 4) && (y % 100)) || !(y % 400);
    }
    return null;
  };
  /**
   * Get Date as iso-8601 string, including milliseconds.
   *
   * @function
   * @name Judy.dateISO
   * @param {Date|falsy} [date]
   *  - default: now
   * @param {boolean} [UTC]
   *  - default: false (~ local time, 1970-01-01T01:00:00.001+01:00)
   *  - truthy: 1970-01-01T00:00:00.001Z
   * @return {string}
   */
  this.dateISO = function(date, UTC) {
    var d = date || new Date();
    return UTC && Date.prototype.toISOString ? d.toISOString() : _dateFrmt(d, 1, 1, 1, UTC, 1);
  };
  /**
   * Get Date as iso-8601 string without milliseconds, T and timezone.
   *
   * @function
   * @name Judy.dateTime
   * @param {Date|falsy} [date]
   *  - default: now
   * @param {boolean} [UTC]
   *  - default: false (~ local time, 1970-01-01 01:00:00)
   *  - truthy: 1970-01-01 00:00:00
   * @return {string}
   */
  this.dateTime = function(date, UTC) {
    var d = date || new Date();
    return UTC && Date.prototype.toISOString ? d.toISOString().replace(/T/, " ").replace(/\.\d{3}Z$/, "") : _dateFrmt(d, 1, 1, 0, UTC);
  };
  /**
   * Translate a Date into a string - like the value of a text field.
   *
   * Supported formats, dot means any (non-YMD) character:
   * - YYYY.MM.DD [HH][:II][:SS][ mmm]
   * - MM.DD.YYYY [HH][:II][:SS][ mmm]
   * - DD.MM.YYYY [HH][:II][:SS][ mmm]
   *
   * @function
   * @name Judy.dateToFormat
   * @param {Date} date
   *  - no default, because empty/wrong arg must be detectable
   * @param {string} [sFormat]
   *  - default: YYYY-MM-DD, omitting hours etc.
   * @return {string}
   *  - empty if arg dt isnt Date object, or unsupported format
   */
  this.dateToFormat = function(date, sFormat) {
    var u = date, fmt = sFormat || "YYYY-MM-DD", le, y, m, d, s, a, b;
    if(u && typeof u === "object" && u.getFullYear) {
      y = u.getFullYear();
      m = self.toLeading(u.getMonth() + 1, 2);
      d = self.toLeading(u.getDate(), 2);
      if((a = (s = fmt.substr(0, 10)).replace(/[MDY]/g, "")).length < 2) {
        return "";
      }
      b = a.charAt(1);
      a = a.charAt(0);
      switch(s.replace(/[^MDY]/g, "")) {
        case "YYYYMMDD":
          s = y + a + m + b + d;
          break;
        case "MMDDYYYY":
          s = m + a + d + b + y;
          break;
        case "DDMMYYYY":
          s = d + a + m + b + y;
          break;
        default:
          return "";
      }
      if((le = fmt.length) > 11) {
        s += " " + self.toLeading(u.getHours(), 2);
        if(le > 14) {
          s += ":" + self.toLeading(u.getMinutes(), 2);
          if(le > 17) {
            s += ":" + self.toLeading(u.getSeconds(), 2);
            if(le > 20) {
              s += " " + self.toLeading(u.getMilliseconds(), 3);
            }
          }
        }
      }
      return s;
    }
    else {
      try {
        throw new Error("date[" + u + "] type[" + self.typeOf(u) + "] is not a non-empty Date");
      }
      catch(er) {
        _errorHandler(er, null, _name + ".dateToFormat()");
      }
      return "";
    }
  };
  /**
   * Translate string - like the value of a text field - to Date.
   *
   * Supported formats, dot means any (non-YMD) character:
   * - YYYY.MM.DD
   * - MM.DD.YYYY
   * - DD.MM.YYYY
   *
   * No support for hours etc.
   * @function
   * @name Judy.dateFromFormat
   * @param {string} s
   * @param {string} [sFormat]
   *  - default: YYYY-MM-DD
   *  - delimiters are ignored, only looks for the position of YYYY, MM and DD in the format string
   * @return {Date|null}
   *  - null if arg str isnt non-empty string, or impossible month or day, or unsupported format
   */
  this.dateFromFormat = function(sDate, sFormat) {
    var s = sDate, dt = new Date(), fmt = sFormat || "YYYY-MM-DD", y, m, d;
    if(s && typeof s === "string") {
      if(/^YYYY.MM.DD$/.test(fmt)) { // iso
        y = s.substr(0, 4);
        m = s.substr(5, 2);
        d = s.substr(8, 2);
      }
      else if(/^MM.DD.YYYY$/.test(fmt)) { // English
        y = s.substr(6, 4);
        m = s.substr(0, 2);
        d = s.substr(3, 2);
      }
      else if(/^DD.MM.YYYY$/.test(fmt)) { // continental
        y = s.substr(6, 4);
        m = s.substr(3, 2);
        d = s.substr(0, 2);
      }
      else {
        return null;
      }
      y = parseInt(y, 10);
      d = parseInt(d, 10);
      switch((m = parseInt(m, 10))) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
          if(d > 31) {
            return null;
          }
          break;
        case 4:
        case 6:
        case 9:
        case 11:
          if(d > 30) {
            return null;
          }
          break;
        case 2:
          if(d > 29 || (d === 29 && !self.isLeapYear(y))) {
            return null;
          }
          break;
        default:
          return null;
      }
      dt.setFullYear(y, m - 1, d );
      dt.setHours(0, 0, 0);
      dt.setMilliseconds(0);
      return dt;
    }
    else {
      try {
        throw new Error("date[" + s + "] type[" + self.typeOf(s) + "] is not non-empty string");
      }
      catch(er) {
        _errorHandler(er, null, _name + ".dateFromFormat()");
      }
      return null;
    }
  };
  /**
   * Modifies a date with evaluated value of a time string, or creates time string based upon the date.
   *
   * If hours evaluate to 24:
   * - if minutes and seconds are zero, then converts to 23:59:59; because 00:00:00 is today, whereas 24:00:00 is tomorrow
   * - otherwise sets hours as zero
   *
   * @example
//  Get time of a date:
Judy.timeFormat(date);
//  Modify time of a date:
Judy.timeFormat(date, "17:30");
   * @function
   * @name Judy.timeFormat
   * @param {Date} date
   *  - by reference
   *  - now default, logs error if falsy
   * @param {string|falsy} [sTime]
   *  - empty: creates time string according to arg date
   *  - non-empty: sets time of arg date
   *  - any kinds of delimiters are supported; only looks for integers
   *  - N, NN, NNNN and NNNNNN are also supported
   * @return {string}
   *  - time NN:NN:NN
   */
  this.timeFormat = function(date, sTime) {
    var d = date, t = sTime ? $.trim(sTime) : 0, h = 0, i = 0, s = 0, le, v;
    if(d && typeof d === "object" && d.getFullYear) {
      //  Modify date.
      if(t) {
        if(/^\d+$/.test(t)) {
          h = t.substr(0, 2);
          if((le = t.length) > 3) {
            i = t.substr(2, 2);
            if(le > 5) {
              s = t.substr(4, 2);
            }
          }
        }
        else if( (le = (t = t.split(/[^\d]/)).length) ) {
          h = t[0];
          if(le > 1) {
            i = t[1];
            if(le > 2) {
              s = t[2];
            }
          }
        }
        if(h) {
          h = isFinite(v = parseInt(h, 10)) && v < 25 ? v : 0;
          if(i) {
            i = isFinite(v = parseInt(i, 10)) && v < 60 ? v : 0;
          }
          if(s) {
            s = isFinite(v = parseInt(s, 10)) && v < 60 ? v : 0;
          }
          if(h === 24) {
            if(!i && !s) {
              h = 23;
              i = s = 59;
            }
            else {
              h = 0;
            }
          }
        }
        d.setHours(h, i, s);
      }
      //  Create time string from date.
      else {
        h = d.getHours();
        i = d.getMinutes();
        s = d.getSeconds();
      }
      return "" + (h < 10 ? "0" : "") + h + ":" + (i < 10 ? "0" : "") + i + ":" + (s < 10 ? "0" : "") + s;
    }
    else {
      try {
        throw new Error("date[" + d + "] type[" + self.typeOf(d) + "] is not a non-empty Date");
      }
      catch(er) {
        _errorHandler(er, null, _name + ".timeFormat()");
      }
      return "00:00:00";
    }
  };
  /**
   * Converts a number to formatted string.
   *
   * oFormat:
   * - (str) type, default integer; values integer|float|decimal
   * - (str) thousand_separator, default space
   * - (str) decimal_separator, default dot
   * - (int) scale, default 2
   *
   * @function
   * @name Judy.numberToFormat
   * @param {number} num
   * @param {object} [oFormat]
   * @return {number}
   */
  this.numberToFormat = function(num, oFormat) {
    var n = num || 0, s, sgn = "", o, isInt, kSep, scale, u, le, d, i;
    if(!n) {
      return "0";
    }
    if(n < 0) {
      n *= -1;
      sgn = "-";
    }
    isInt = !(u = (o = oFormat || {}).type) || u === "integer";
    kSep = (u = o.thousand_separator) || u === "" ? u : " ";
    //  Extract decimals.
    if((d = n % 1)) {
      n = Math.round(n);
    }
    s = "" + n;
    //  Thousand separation.
    if(kSep && (le = s.length) > 3) {
      n = s;
      s = n.substr(0, i = le % 3);
      while(i < le) {
        s += (i ? kSep : "") + n.substr(i, 3);
        i += 3;
      }
    }
    scale = o.scale || 2;
    return sgn + s +
        (isInt ? "" : (
            ((u = o.decimal_separator) || u === "" ? u : ".") +
            ( (d ? ("" + Math.round(d * Math.pow(10, scale))) : "") + // Round decimals.
            new Array( scale + 1 ).join("0") ).substr(0, scale)
        ) );
  };
  /**
   * Converts a numberish string containing thousand separators and/or decimal marker to number.
   *
   * Validates that the string matches the format; detects if there's a non-number somewhere after a decimal marker.
   *
   * Also handles currency slash dash (and equivalent) endings; like 15/- or 15,-
   *
   * oFormat:
   * - (str) type, default integer; values integer|float|decimal
   * - (str) thousand_separator, default space
   * - (str) decimal_separator, default dot
   *
   * @function
   * @name Judy.numberFromFormat
   * @param {string} str
   * @param {object} [oFormat]
   * @return {number|boolean}
   *  - false: arg str doesnt match the format
   */
  this.numberFromFormat = function(str, oFormat) {
    var s = $.trim(str), sgn = 1, o, isInt, dSep, u, p, d, n;
    if(!s || s === "0" || s === "-0") {
      return 0;
    }
    if(s.charAt(0) === "-") {
      sgn = -1;
      s = s.substr(1);
    }
    //  Remove trailing decimal marker or currency slash. Remove leading separator and leading zeros.
    if((s = s.replace(/^(.*\d)\D+$/, "$1").
        replace(/^[^1-9]+([1-9].*)$/, "$1"))
    ) {
      //  Prepare format.
      isInt = !(u = (o = oFormat || {}).type) || u === "integer";
      dSep = o.decimal_separator || ".";
      //  Validate - check if there's a non-number somewhere after decimal marker.
      if(new RegExp("\\" + dSep + "\\d*\\D").test(s)) {
        return false;
      }
      //  Extract decimals.
      if((p = s.indexOf(dSep)) > -1) {
        d = s.substr(p).replace(/\D/g, "");
        s = s.substr(0, p);
      }
      //  Remove thousand separators.
      n = parseInt(
          s.replace(/\D/g, ""),
          10
      );
      if(d) {
        n += parseInt(d, 10) / Math.pow(10, d.length);
      }
      return sgn * (!isInt ? n : Math.round(n));
    }
    return 0;
  };

  //  Miscellaneous.
  /**
   * Random number.
   *
   * @function
   * @name Judy.rand
   * @param {integer} [min]
   *  - default: zero
   * @param {integer} [max]
   *  - default: 9e15 (~ almost 9007199254740992 aka 2^53, the largest representable integer in Javascript)
   * @return {integer}
   */
  this.rand = function(min, max) {
    var m = min || 0;
    return m + Math.floor( ( Math.random() * ( ((max || 9e15) - m) + 1 ) ) + 1 ) - 1;
  };
  /**
   * Random name.
   *
   * Default length 20 chars, starts with a letter, the rest is a base 36 string.
   *
   * Slight performance hit when passing lengths 12, 23, 34 etc. ~ (n*11)+1
   * - because iterates for approximately every 11 char ~ (n*11)+1
   * - the most economical lengths are probably one less (11, 21, 31)
   *
   * Approximate bit-size when using length:
   *  - 12 ~ 54-bit (53-bit plus sqrt(26)~4.5 minus 3.5 for always making large numbers (filling up all digits))
   *  - 20 ~ 90-bit (estimated)
   *  - 23 ~ 107-bit
   *  - 34 ~ 160-bit
   *  - a-z0-9, first character is always a letter
   * @function
   * @name Judy.randName
   * @param {integer} [length]
   *  - default: 20
   * @return {string}
   */
  this.randName = function(length) {
    var al = length || 20, l, s = String.fromCharCode(Math.floor(Math.random()*26)+97); // first char letter
    while((l = s.length) < al) {
      s += Math.floor(Math.random()*9e15).toString(36); // convert to base 36 for shorter string length
    }
    return l > al ? s.substr(0, al) : s;
  };

  /**
   * NOT relevant in Drupal context, because GET parameters arent used that way in Drupal.
   *
   * Set url parameter.
   *
   * @ignore
   * @function
   * @name Judy.setUrlParam
   * @param {string} url
   *  - full url, or just url query (~ window.location.search)
   * @param {string|object} name
   * @param {string|number|falsy} [value]
   *  - ignored if arg name is object
   *  - falsy and not zero: unsets the parameter
   * @return {string}
   *
  this.setUrlParam = function(url, name, value) {
    var u = url || "", a = u, h = "", o = name, oS = {}, p, le, i, k, v;
    if(u && (p = u.indexOf("#")) > -1) {
      h = u.substr(p);
      u = u.substr(0, p);
    }
    if(u && (p = u.indexOf("?")) > -1) {
      a = u.substr(p + 1);
      u = u.substr(0, p);
    }
    else {
      a = "";
    }
    if(typeof o !== "object") {
      o = {};
      o[name] = value;
    }
    if(a) {
      le = (a = a.split(/&/g)).length;
      for(i = 0; i < le; i++) {
        if((p = a[i].indexOf("=")) > 0) {
          oS[ a[i].substr(0, p) ] = a[i].substr(p + 1);
        }
        else if(p) { // Dont use it if starts with =.
          oS[ a[i] ] = "";
        }
      }
    }
    a = [];
    for(k in oS) {
      if(oS.hasOwnProperty(k)) {
        if(o.hasOwnProperty(k)) {
          if((v = o[k]) || v === 0) { // Falsy and not zero: unsets the parameter.
            a.push(k + "=" + encodeURIComponent(v));
          }
          delete o[k];
        }
        else {
          a.push(k + "=" + oS[k]);
        }
      }
    }
    for(k in o) {
      if(o.hasOwnProperty(k) && (v = o[k]) || v === 0) {
        a.push(k + "=" + v);
      }
    }
    return u + (a.length ? ("?" + a.join("&")) : "") + h;
  };*/

  //  UI.
  /**
   * Show/hide overlay.
   *
   * Adds an overlay element to DOM, if not yet done and arg show evaluates to show.
   *
   * @function
   * @name Judy.overlay
   * @param {boolean|integer|Event} [show]
   *  - default: falsy (~ hide)
   *  - Event|object: hide (because may be used as event handler)
   * @param {boolean} [opaque]
   *  - default: false
   *  - truthy: add css class 'module-judy-overlay-opaque'
   * @param {string|falsy} [hoverTitle]
   *  - default: falsy (~ no hover title)
   *  - truthy: set the overlay's title attribute, and add css class 'module-judy-overlay-hovertitled'
   * @return {void}
   */
  this.overlay = function(show, opaque, hoverTitle) {
    var hide = !show || typeof show === "object", ttl = hoverTitle || "",
      clsO = "module-judy-overlay-opaque", clsT = "module-judy-overlay-hovertitled";
    if(!_jqOvrly) {
      if(hide) { // Dont want to build it until it's actually gonna be used.
        return;
      }
      $(document.body).append(
          "<div id=\"module_judy_overlay\" class=\"" +
          (opaque ? clsO : "") + (opaque && ttl ? " " : "") + (ttl ? clsT : "") +
          "\"></div>"
      );
      _jqOvrly = $("div#module_judy_overlay");
      _ovrlyRsz();
      $(window).resize(function() {
        _ovrlyRsz();
      });
    }
    else if(hide) {
      _jqOvrly.hide();
      return;
    }
    else {
      _jqOvrly[ opaque ? "addClass" : "removeClass" ](clsO)[ ttl ? "addClass" : "removeClass" ](clsT).get(0).setAttribute("title", ttl);
    }
    _jqOvrly.show();
  };
  /**
   * jQuery ui dialog wrapper/factory, which makes it easier to create a dialog and maintain a reference to it.
   *
   * The reference is the dialog's name, which is returned on creation and usable as selector arg when calling the dialog later.
   *
   * Creates or re-uses existing content element, and creates or re-uses related jQuery ui dialog box.
   *
   * Non-standard options/methods:
   * - (str) content: sets the HTML content of the selector (dialog content element)
   * - (bool) fixed: css-positions the dialog to fixed relative to document body; ignored after dialog creation
   * - (str) contentClass: sets that/these css class(es) on the content element
   * - getContent(): get dialog content, excluding buttons
   *
   * Supported standard options:
   * - appendTo
   * - autoOpen: default true
   * - buttons
   * - closeOnEscape
   * - closeText
   * - dialogClass
   * - draggable
   * - height
   * - hide
   * - maxHeight
   * - maxWidth
   * - minHeight
   * - minWidth
   * - modal: only works on creation (make more dedicated modal/non-modal dialogs)
   * - position
   * - resizable
   * - show
   * - title
   * - width
   *
   * Standard events:
   * - beforeClose
   * - create
   * - open
   * - focus
   * - dragStart
   * - drag
   * - dragStop
   * - resizeStart
   * - resize
   * - resizeStop
   * - close
   *
   * Supported standard methods:
   * - close
   * - destroy
   * - isOpen
   * - moveToTop
   * - open
   * - option
   * - widget
   *
   * Open/close (show/hide) will always be applied in a manner so as to prevent display of other changes.
   *
   * @example
//  Add new element to the DOM and attach new dialog to it; and then modify the dialog:
var random_name = Judy.dialog("", { title: "Randomly named", content: "The content", fixed: true } );
Judy.dialog(random_name, "content", "Changed content of existing dialog named " + random_name);
//  Find existing element - or create new having that id and/or class - and attach new dialog:
var name_as_element_id = Judy.dialog("#some_element.some-class", { title: "Named by element id", content: "The content" });
Judy.dialog(name_as_element_id, "content", "Changed content of new or existing dialog named " + name_as_element_id);
Judy.dialog("#" + name_as_element_id, "title", "Doesnt matter if using # when calling existing");
//  Get content of existing dialog:
console.log(Judy.dialog(name_as_element_id, "getContent"));
   * @function
   * @name Judy.dialog
   * @param {string|element|array|jquery} selector
   *  - only works on a single (first) element
   *  - default, empty: new random html id
   *  - default, non-empty having no . or #: dialog content element's html id
   *  - other non-empty: like jQuery() selector arg: tagName and/or id and/or css class(es), but name no attribute, and class(es) cannot go before #id
   * @param {string|object} [option]
   *  - string: single option or method
   *  - object: list of options/methods
   * @param {mixed} [value]
   *  - value of option, if arg option is string; otherwise ignored
   * @return {string|mixed|bool}
   *  - string: at dialog creation, element id of the dialog box (at dialog creation, and when called later with option object)
   *  - mixed: when called later using one of the methods; return value of that method call
   *  - false if no jQuery ui dialog support
   */
  this.dialog = function(selector, option, value) {
    var sl = selector, u = option, t, s, o, v = value, keys, a, tg = "", id = "", cls = "module-judy-dialog", cls1 = "", elm, jq, dialExists, fxd,
      title, doOpen, autoOpenLater, to;
    if($.ui && typeof $.ui.dialog === "function") {
      if(u) {
        if((t = typeof u) === "string") {
          if(u !== "option") {
            s = u;
          }
          else if(v && typeof v === "object") { // silly: option "option", value {option:value}
            o = self.containerCopy(v); // because we later delete from it
          }
        }
        else if(t === "object") {
          o = self.containerCopy(u); // because we later delete from it
        }
      }
      if(sl) {
        if(typeof sl === "string") {
          if(sl.indexOf("#") === -1 && sl.indexOf(".") === -1) {
            if((elm = document.getElementById(id = sl)) &&
                self.arrayIndexOf(_dialogs, id) > -1) {
              dialExists = true;
            }
          }
          else if((elm = $(sl).get(0))) { // jQuery selector
            if((id = elm.id)) {
              if(self.arrayIndexOf(_dialogs, id) > -1) {
                dialExists = true;
              }
            }
            else {
              id = elm.id = self.randName();
            }
          }
          else { // Create new element; having same element, name and class.
            a = sl.replace(/^([a-z\d_\-]+)?(\#[a-z\d_\-]+)?(\.[a-z\d_\-]+)?$/, "$1,$2,$3").split(",");
            tg = a[0];
            id = a[1] ? a[1].substr(1) : self.randName();
            if(a[2]) {
              cls1 = " " + a[2].split(/\./).join(" ")
            }
          }
        }
        else if(typeof sl === "object" && sl.getAttributeNode) {
          if((id = elm.id)) {
            if(self.arrayIndexOf(_dialogs, id) > -1) {
              dialExists = true;
            }
          }
          else {
            id = elm.id = self.randName();
          }
        }
      }
      else {
        id = self.randName();
      }
      //  existing dialog box --------------------
      if(dialExists) {
        doOpen = false; // Default; dont change current open/close state.
        jq = $(elm);
        if(o) {
          delete o.fixed; // Only usable at instantiation.
          if((keys = self.objectKeys(o)).length === 1) { // Extract that single option; may be method, and then we want to return it.
            v = o[ s = keys[0] ];
          }
        }
        if(s) {
          if(s === "content") {
            if(jq.dialog("isOpen")) {
              doOpen = true;
            }
            jq.html(v);
            if(doOpen) {
              if(doOpen) { // give the browser a sec to re-render
                to = setTimeout(function(){
                  jq.dialog("open");
                }, 100);
              }
            }
            return id;
          }
          if(s === "getContent") {
            return jq.html();
          }
          // There is no native option title (when updating), and we furthermore want to allow HTML (not textnode).
          if (s === 'title') {
            $('.ui-dialog-title', $(elm.parentNode)).html(v);
            return id;
          }
          else if(self.arrayIndexOf(_dialOpts, s) > -1 || self.arrayIndexOf(_dialEvts, s) > -1) {
            jq.dialog("option", s, v);
          }
          if(self.arrayIndexOf(_dialMthds, s) > -1) {
            return jq.dialog(s);
          }
          jq.dialog(s, v);
          return id;
        }
        else if(o) {
          if(jq.dialog("isOpen")) {
            doOpen = true;
            jq.dialog("close"); // do always close before changing anything else
          }
          if(o.close && o.hasOwnProperty("close") && typeof o.close !== "function") {
            doOpen = false;
            delete o.close;
          }
          if(o.content !== undefined && o.hasOwnProperty("content")) {
            jq.html(v);
            delete o.content;
          }
          if(o.open && o.hasOwnProperty("open")) {
            doOpen = true;
            delete o.open;
          }
          jq.dialog(o);
          if(doOpen) { // give the browser a sec to re-render
            to = setTimeout(function(){
              jq.dialog("open");
            }, 100);
          }
        }
        return id;
      }
      //  new dialog box -------------------------
      doOpen = true; // Default for new; autoOpen default for jQuery UI Dialog is true.
      if(!o) {
        o = {};
        if(s) {
          o[s] = v;
        }
      }
      if(!elm) {
        $(document.body).append("<" + (tg || "div") + " id=\"" + id + "\" class=\"" + cls + cls1 +
          (!o.contentClass ? '' : (' ' + o.contentClass)) + "\"></" + (tg || "div") + ">");
        elm = document.getElementById(id);
      }
      jq = $(elm);
      if(o.open && o.hasOwnProperty("open")) {
        delete o.open; // We want to do it ourselves, a bit later.
      }
      if(!o.autoOpen && o.hasOwnProperty("autoOpen")) { // autoOpen:true is the default of jQuery UI Dialog.
        doOpen = false;
      }
      else {
        autoOpenLater = true; // We want to do it ourselves, a bit later.
        o.autoOpen = false;
      }
      if((u = self.objectGet(o, "content"))) {
        jq.html(u);
        delete o.content;
      }
      if(o.fixed && o.hasOwnProperty("fixed")) {
        fxd = true;
        delete o.fixed;
      }
      // Allow HTML title (not textnode).
      if(o.title && o.hasOwnProperty("title")) {
        title = o.title;
        delete o.title;
      }
      //  Instantiate jQuery UI dialog, and fix properties of that container which the jQuery UI dialog wraps around the content element.
      jq.dialog(o);
      u = $(elm.parentNode);
      if(fxd) {
        u.css("position", "fixed");
      }
      if (title !== undefined) {
        $('.ui-dialog-title', u).html(title);
      }
      u.addClass(cls + "-container");
      //  Register.
      _dialogs.push(id);
      if(doOpen) { // give the browser a sec to re-render
        to = setTimeout(function(){
          jq.dialog("open");
          if(autoOpenLater) {
            jq.dialog("autoOpen", true);
          }
        }, 100);
      }
      return id;
    }
    try {
      throw new Error("jQuery UI Dialog not included");
    }
    catch(er) {
      _errorHandler(er, null, _name + ".dialog()");
    }
    return false;
  };

  //  Timer.
  /**
   * setTimeout alternative - executes the function in try-catch, and supports checking if the function has been executed yet.
   *
   * Convenience method for new Judy.Timer().
   * @example
var doooh = function(ms) { jQuery(this).html("&lt;h1&gt;"+ms+"&lt;/h1&gt;"); };
Judy.timer(document.body, doooh, ["Doooh!"], 1000);
   * @function
   * @name Judy.timer
   * @param {object|falsy} o
   *  - object to apply() arg func on, if desired
   * @param {func} func
   * @param {array|falsy} [args]
   *  - arguments to apply() on arg func, if arg o is object (truthy)
   * @param {integer} [delay]
   *  - default: zero milliseconds
   */
  this.timer = function(o, func, args, delay) {
    return new self.Timer(o, func, args, delay);
  };
  /**
   * setTimeout alternative - executes the function in try-catch, and supports checking if the function has been executed yet.
   *
   * @example
var doooh = function(ms) { jQuery(this).html("&lt;h1&gt;"+ms+"&lt;/h1&gt;"); },
t = new Judy.Timer(document.body, doooh, ["Doooh!"], 1000);
   * @constructor
   * @namespace
   * @name Judy.Timer
   * @param {object|falsy} o
   *  - object to apply() arg func on, if desired
   * @param {func} func
   * @param {array|falsy} [args]
   *  - arguments to apply() on arg func, if arg o is object (truthy)
   * @param {integer} [delay]
   *  - default: zero milliseconds
   */
  this.Timer = function(o, func, args, delay) {
    var a = args || [], fired = false,
      f = o ? function() {
        fired = true;
        try {
          func.apply(o, a);
        }
        catch(er) {}
      } : function() {
        fired = true;
        try {
          func();
        }
        catch(er) {}
      },
      t = window.setTimeout(f, delay || 0);
    /**
     * Check if the function has been executed yet.
     * @function
     * @memberOf Judy.Timer
     * @name Judy.Timer#fired
     * @return {boolean}
     */
    this.fired = function() {
      return fired;
    }
    /**
     * Cancel execution of the function.
     * @function
     * @memberOf Judy.Timer
     * @name Judy.Timer#cancel
     * @return {void}
     */
    this.cancel = function() {
      window.clearTimeout(t);
    };
  };
};

(Drupal.Judy = window.Judy = window.judy = new Judy($)).setup();

})(jQuery);