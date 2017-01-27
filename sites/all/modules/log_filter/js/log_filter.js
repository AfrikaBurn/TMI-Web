/**
 * @file
 *  Drupal Log Filter module
 */


/*jslint browser: true, continue: true, indent: 2, newcap: true, nomen: true, plusplus: true, regexp: true, white: true, ass: true*/
/*global alert: false, confirm: false, console: false*/
/*global jQuery: false, Drupal: false, inspect: false, Judy: false*/

/**
 * @param {function} $
 * @returns {object}
 */
(function($) {
  'use strict';

  /**
   * Singleton, instantiated to itself.
   * @constructor
   * @namespace
   * @name LogFilter
   * @singleton
   * @param {function} $
   */
  var LogFilter = function($) {
    /**
     * @ignore
     * @private
     * @type {LogFilter}
     */
    var self = this,
    /**
     * @ignore
     * @private
     * @type {string}
     */
    _name = "LogFilter",
    /**
     * @ignore
     * @private
     * @type {object}
     */
    _errorCodes = {
      unknown: 1,
      //  Programmatic errors and wrong use of program.
      algo: 100,
      use: 101,
      //  Missing permission.
      perm_general: 200,
      form_expired: 201,
      perm_filter_crud: 202,
      perm_filter_restricted: 203,
      //  Database.
      db_general: 500,
      //  Misc.
      filter_name_composition: 1001,
      filter_name_nonunique: 1002,
      filter_doesnt_exist: 1003,
      bad_filter_condition: 1010
    },
    /**
     * @ignore
     * @private
     * @type {object}
     */
    _ = {
      //  {arr}
      errors: [],
      dateFormat: "YYYY-MM-DD",
      dateFormat_datepicker: "yy-mm-dd",
      mode: "default", // default | adhoc | stored | create | edit | delete_filter
      modePrevious: "default",
      name: "",
      origin: "",
      crudFilters: false,
      recordedValues: { // For some fields (having pattern validation) we have to record last value to safely detect change.
        time_range: "",
        uid: "",
        hostname: "",
        location: "",
        referer: "",
        orderBy: [],
        type_options: []
      },
      deleteLogs_allowed: false,
      saveEditFilterAjaxed: false, // Save/update filter using AJAX or ordinary POST request?
      listMessageTruncate: 250,
      adminOverlayOffset: 80, // Module Overlay.
      currentOffset: 0,
      currentMax: 100,
      logs: {},
      library_judy_version: 2.1,
      library_judy_compatible: true
    },
    /**
     * @ignore
     * @private
     * @type {array}
     */
    _severity = ['emergency', 'alert', 'critical', 'error', 'warning', 'notice', 'info', 'debug'],
    /**
     * @ignore
     * @private
     * @type {boolean|undefined}
     */
    _submitted,
    /**
     * @ignore
     * @private
     * @type {boolean|undefined}
     */
    _ajaxRequestingBlocking,
    /**
     * List of previously used localized labels/messages.
     *
     * @ignore
     * @private
     * @type {object}
     */
    _local = {},
    /**
     * @ignore
     * @private
     * @type {object}
     */
    _selectors = {
      page: "div#page",
      form: "form#log-filter-form",
      settings: {
        mode: "input[name='log_filter_mode']",
        onlyOwn: "input[name='log_filter_only_own']",
        delete_logs_max: "input[name='log_filter_delete_logs_max']", // May not exist.
        translate: "input[name='log_filter_translate']",
        pager_range: "input[name='log_filter_pager_range']"
      },
      filter: {
        filter: "select[name='log_filter_filter']",
        name: "input[name='log_filter_name']", // Hidden.
        origin: "input[name='log_filter_origin']", // Hidden.
        name_suggest: "input[name='log_filter_name_suggest']",
        description: "textarea[name='log_filter_description']",
        require_admin: "input[name='log_filter_require_admin']" // May not exist.
      },
      conditions: {
        time_range: "input[name='log_filter_time_range']", // For iteration: must go before the other time fields.
        time_from: "input[name='log_filter_time_from']",
        time_from_proxy: "input[name='log_filter_time_from_proxy']",
        time_to: "input[name='log_filter_time_to']",
        time_to_proxy: "input[name='log_filter_time_to_proxy']",
        severity_any: "input[name='log_filter_severity[-1]']", // For iteration: must go before severity_some.
        severity_some: "div#edit-log-filter-severity input:not([name='log_filter_severity[-1]'])", // More elements.
        type_any: "input[name='log_filter_type_wildcard']", // For iteration: must go before type_proxy.
        type_some: "textarea[name='log_filter_type']", // For iteration: must go before type_proxy.
        type_proxy: "div#edit-log-filter-type-proxy input", // We only store the first, because we only need one for getting/setting value.
        role: "select[name='log_filter_role']", // For iteration: must go before uid.
        uid: "input[name='log_filter_uid']",
        username: "input[name='log_filter_username']",
        hostname: "input[name='log_filter_hostname']",
        location: "input[name='log_filter_location']",
        referer: "input[name='log_filter_referer']"
      },
      orderBy: {
        options: "div.filter-orderby select",
        bools: "div.filter-orderby input[type='checkbox']"
      },
      buttons: {
        //  Not part of filter dialog.
        submit: "input#edit-submit",
        update_list: "input[name='log_filter_update_list']",
        reset: "input[name='log_filter_reset']",
        //  Filter dialog.
        create: "input[name='log_filter_create']",
        edit: "input[name='log_filter_edit']",
        delete_filter: "input[name='log_filter_delete']",
        cancel: "input[name='log_filter_cancel']",
        save: "input[name='log_filter_save']", // Doesnt exist if user isnt permitted to create|edit|save filter.
        delete_logs_button: "input[name='log_filter_delete_logs_button']"
      },
      pager: {
        first: 'div#log_filter_pager_first',
        previous: 'div#log_filter_pager_previous',
        current: 'div#log_filter_pager_current',
        progress: 'div#log_filter_pager_progress',
        next: 'div#log_filter_pager_next',
        last: 'div#log_filter_pager_last'
      },
      misc: {
        title: "#log_filter_title_display"
      }
    },
    _elements = {
      settings: {},
      filter: {},
      conditions: {},
      orderBy: [], // Array.
      buttons: {
        crudFilters: [] // create, edit, delete_filter, cancel, save.
      },
      pager: {
      },
      misc: {
      }
    },
    /**
     * @ignore
     * @private
     * @type {array}
     */
    _filters = [],
    /**
     * @ignore
     * @private
     * @type {object}
     */
    _logs = {},

    //  Declare private methods, to make IDEs list them
    _errorHandler, _oGet, _toAscii,
    _textareaRemoveWrapper,
    _machineNameConvert, _machineNameIllegals, _machineNameValidate,
    _validateTimeSequence,
    _url, _submit, _typeProxyHandler, _prepareForm, _setMode, _crudRelay, _changedCriterion, _resetCriteria, _deleteLogs, _filterByEventColumn,
    _getLogList, _listLogs,
    _ajaxResponse, _ajaxRequest;
    /**
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
      if(typeof window.inspect === "function" && inspect.tcepsni) {
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
          o.category = "log_filter";
          inspect.errorHandler(error, variable, o);
        }
        else {
          inspect.console("Please update Inspect.");
        }
      }
    };
    /**
     * Object/function property getter, Object.hasOwnproperty() alternative.
     *
     * @ignore
     * @param {object} o
     * @param {string|integer} k0
     * @param {string|integer} [k1]
     * @return {mixed}
     *  - undefined: o not object, or o doesnt have property k0, or the value of o[k1] is undefined; and the same goes if arg k1 is used
     */
    _oGet = function(o, k0, k1) {
      var t = typeof o;
      return o && (t === "object" || t === "function") && o.hasOwnProperty(k0) ?
          (k1 === undefined ? o[k0] : (
              (o = o[k0]) && ((t = typeof o) === "object" || t === "function") && o.hasOwnProperty(k1) ? o[k1] : undefined
          ) ) : undefined;
    };
    _toAscii = function(s) {
      var ndl = _toAscii.needles, rpl = _toAscii.replacers, le = ndl.length, i, u;
      if(typeof ndl[0] === "string") { // First time called.
        u = ndl.concat();
        for(i = 0; i < le; i++) {
            ndl[i] = new RegExp("\\u" + Judy.toLeading(u[i].charCodeAt(0).toString(16), 4), "g");
        }
      }
      for(i = 0; i < le; i++) {
          s = s.replace(ndl[i], rpl[i]);
      }
      return s;
    };
    /**
     * Removes parent form-textarea-wrapper div from (non-resizable) textarea, for easier (standard) DOM access.
     *
     * @ignore
     * @param {element} elm
     * @return {void}
     */
    _textareaRemoveWrapper = function(elm) {
      var jq;
      if ((jq = $(elm.parentNode)).hasClass("form-textarea-wrapper")) {
        jq.after( $(elm).remove() );
        jq.remove();
      }
    };
    _toAscii.needles = [
      //  iso-8859-1
  //JSLINT_IGNORE--- jslint unsafe chars,but _toAscii() starts out converting them to \uNNNN regexes.
      "Ä","Æ","ä","æ","Ö","Ø","ö","ø","Ü","ü","ß","Å","å","À","Á","Â","Ã","à","á","â","ã","Ç","ç","Ð","ð","È","É","Ê","Ë","è","é","ê","ë","Ì","Í","Î","Ï","ì","í","î","ï","Ñ","ñ","Ò","Ó","Ô","Õ","ò","ó","ô","õ","Ù","Ú","Û","ù","ú","û","Ý","ý","ÿ","Þ","þ"
  //---JSLINT_IGNORE
    ];
    _toAscii.replacers = [
      //  iso-8859-1
      "Ae","Ae","ae","ae","Oe","Oe","oe","oe","Ue","ue","ss","Aa","aa","A","A","A","A","a","a","a","a","C","c","D","d","E","E","E","E","e","e","e","e","I","I","I","I","i","i","i","i","N","n","O","O","O","O","o","o","o","o","U","U","U","u","u","u","Y","y","y","Th","th"
    ];
    /**
     * @ignore
     * @return {void}
     */
    _machineNameConvert = function() {
      var v = this.value, rgx = /^[a-z\d_]$/;
      if(v.length > 1 && !rgx.test(v)) {
        if(!rgx.test(v = v.toLowerCase())) {
          if(!rgx.test(v = v.replace(/[ \-]/g, "_"))) {
            if(!rgx.test(v = _toAscii(v))) {
              v = v.replace(/[^a-z\d_]/g, "_");
            }
          }
        }
        this.value = v;
      }
    };
    /**
     * @ignore
     * @type {array}
     */
    _machineNameIllegals = [
      "log_filter",
      "default",
      "adhoc"
    ];
    /**
     * @ignore
     * @param {Event|falsy} evt
     *  - default: falsy (~ use arg elm)
     * @param {element} [elm]
     *  - default: falsy (~ use arg value)
     * @param {string} [value]
     * @param {boolean} [noFeedback]
     *  - default: false (~ do pop alert upon validation failure)
     * @return {boolean}
     */
    _machineNameValidate = function(evt, elm, value, noFeedback) {
      var v = evt ? this.value : (elm ? elm.value : value), le = v.length;
      if(le < 2 || le > 32 || !/[a-z_]/.test(v.charAt(0)) || !/[a-z\d_]/.test(v) || $.inArray(v.toLowerCase(), _machineNameIllegals) > -1) {
        if(!noFeedback) {
          self.Message.set( self.local("error_machine_name_composition", {"!illegals": _machineNameIllegals.join(", ")}), "warning", {
            modal: true,
            close: function() {
              Judy.focus(_elements.filter.name_suggest);
            }
          });
        }
        return false;
      }
      return true;
    };
    /**
     * @ignore
     * @param {string} nm
     * @param {boolean} [date]
     * @return {boolean}
     */
    _validateTimeSequence = function(nm, date) {
      var o = _elements.conditions, v, from = (v = o.time_from.value) ? parseInt(v, 10) : 0, to;
      if (from && (to = (v = o.time_to.value) ? parseInt(v, 10) : 0) && from > to) {
        // Date To and From must be allowed to be the same, otherwise user can't enter same date.
        if (date && $.trim(o.time_to_proxy.value) === $.trim(o.time_from_proxy.value)) {
          return true;
        }
        o[ "time_" + nm ].value = o[ "time_" + nm + "_proxy" ].value = o[ "time_" + nm + "_time" ].value = "";
        self.Message.set( self.local("invalid_timeSequence_" + nm), "warning", { modal: true });
        return false;
      }
      return true;
    };
    /**
     * @ignore
     * @param {boolean} [top]
     *  - default: false (~ use current window's location, not top.location)
     * @return {string}
     */
    _url = function(top) {
      var loc = (!top ? window : top).location, v;
      return loc.protocol + "//" + loc.hostname + (!(v = loc.port) ? "" : (":" + v)) + loc.pathname.replace(/\/dblog(\/.+)?$/, "/dblog/log_filter");
    };
    /**
     * @ignore
     * @return {void}
     */
    _submit = function() {
      var nm = "", elm;
      if(_submitted) {
        return;
      }
      _submitted = true;
      switch(_.mode) {
        case "adhoc":
          nm = "adhoc";
          break;
        case "stored":
          nm = _.name;
          break;
      }
      // Add filter name to action url.
      _elements.form.setAttribute(
        "action",
        _elements.form.getAttribute("action").replace(/\/dblog(\/[^\?&]+)([\?&].+)?$/, "/dblog/log_filter/" + nm + "$2")
      );
      //  Delay; otherwise it may in some situations not submit, presumably because Judy.enable() hasnt finished it's job yet(?).
      setTimeout(function() {
        $(_elements.buttons.submit).trigger("click");
      }, 100);
    };
    /**
     * @ignore
     * @return {void}
     */
    _typeProxyHandler = function() {
      var v, i;
      if(this.checked) { // Un-check type_any.
        _elements.conditions.type_any.checked = false;
        // Pass value to type_some.
        if (Judy.arrayIndexOf(v = $.trim(_elements.conditions.type_some.value).split(/\n/), this.value) === -1) {
          v.push(this.value);
          _elements.conditions.type_some.value = $.trim(v.join("\n"));
        }
      }
      else {
        // Remove from hidden type_some.
        if ((i = Judy.arrayIndexOf(v = $.trim(_elements.conditions.type_some.value).split(/\n/), this.value)) > -1) {
          v.splice(i, 1);
          if (v.length) {
            _elements.conditions.type_some.value = $.trim(v.join("\n"));
          }
          else {
            _elements.conditions.type_some.value = "";
            _elements.conditions.type_any.checked = "checked";
          }
        }
      }
      _changedCriterion();
    };
    /**
     * @ignore
     * @return {void}
     */
    _prepareForm = function() {
      var oSels, oElms, nm, jq, elm, par, aElms, a, le, i, v, nOrderBy, u, elm2, d;
      try {
        _elements.page = $(_selectors.page).get(0);
        _elements.form = $(_selectors.form).get(0);
        //  Filter; do first because we need references to name and origin.
        oSels = _selectors.filter;
        oElms = _elements.filter;
        for(nm in oSels) {
          if(oSels.hasOwnProperty(nm) && (elm = (jq = $(oSels[nm])).get(0))) {
            oElms[nm] = elm;
            switch(nm) {
              case "filter":
                //  Selecting a stored filter means submit form.
                jq.change(function() {
                  var v;
                  _elements.filter.name.value = _.name = v = Judy.fieldValue(this);
                  _elements.settings.mode.value = _.mode = v ? "stored" : "default";
                  if(!v) { // default|adhoc
                    _resetCriteria(null, "default");
                    return;
                  }
                  Judy.overlay(1, false, self.local("wait")); // Transparent.
                  _submit();
                });
                break;
              case "name_suggest": // May not exist.
                jq.keyup(_machineNameConvert);
                break;
              case "description": // May not exist.
                _textareaRemoveWrapper(elm); // Remove parent form-textarea-wrapper.
                jq.change(function() {
                  var v;
                  if((v = this.value)) {
                    this.value = Judy.stripTags(v);
                  }
                });
                break;
            }
          }
        }
        _.name = _elements.filter.name.value;
        _.origin = _elements.filter.origin.value;
        //  Fields; get element references, and fix some issues.
        //  Settings.
        oSels = _selectors.settings;
        oElms = _elements.settings;
        for(nm in oSels) {
          if(oSels.hasOwnProperty(nm) && (elm = (jq = $(oSels[nm])).get(0))) {
            oElms[nm] = elm;
            switch(nm) {
              case "mode":
                //  Get mode.
                _.mode = elm.value;
                break;
              case "onlyOwn": // May not exist.
                //  Submit if user (un)checks filter_only_own.
                jq.change(function() {
                  if(_.mode === "stored") {
                    _elements.settings.mode.value = "adhoc";
                    Judy.fieldValue(_elements.filter.filter, null, "");
                    _elements.filter.origin.value = _.name; // Pass name to origin.
                    _elements.filter.name.value = "";
                  }
                  Judy.overlay(1, false, self.local("wait")); // Transparent.
                  _submit();
                });
                break;
              case "delete_logs_max": // May not exist.
                jq.change(function() {
                  var v = this.value;
                  if(v !== "") {
                    if((v = $.trim(v)) !== "" && !/^[1-9]\d*$/.test(v)) {
                      v = "";
                    }
                    this.value = v;
                  }
                });
                break;
              case "pager_range":
                _.currentMax = parseInt(elm.value, 10);
                // Pass value to delete max logs field.
                if ($(_selectors.buttons.delete_logs_button).get(0)) {
                  oElms.delete_logs_max.value = _.currentMax;
                }
                jq.change(function() {
                  var v = this.value, n, m;
                  if(v !== "") {
                    if((v = $.trim(v)) !== "" && /^\d+$/.test(v)) {
                      _.currentMax = n = parseInt(v, 10);
                      if (_.deleteLogs_allowed &&
                        ((m = _elements.settings.delete_logs_max.value) === '' || (m = parseInt(m, 10)) > n)
                      ) {
                        _elements.settings.delete_logs_max.value = n;
                      }
                    }
                    else {
                      v = "";
                    }
                    this.value = v;
                  }
                });
                break;
            }
          }
        }
        //  Conditions.
        oSels = _selectors.conditions;
        oElms = _elements.conditions;
        for(nm in oSels) {
          if(oSels.hasOwnProperty(nm) && (elm = (jq = $(oSels[nm])).get(0))) {
            switch(nm) {
              case "time_range":
                oElms[nm] = elm;
                _.recordedValues[nm] = elm.value;
                //  Clear time_to and time_from when setting a time_range.
                jq.change(function() {
                  var v = this.value, o;
                  if(v !== "") {
                    this.value = v = $.trim(v);
                  }
                  if(v !== "") {
                    if(v === "0" || !/^[1-9]\d*$/.test(v)) {
                      this.value = v = "";
                    }
                    else {
                      if (v.length > 4) {
                        this.value = v = '9999';
                      }
                      (o = _elements.conditions).time_from.value =
                        o.time_from_proxy.value =
                        o.time_from_time.value =
                        o.time_to.value =
                        o.time_to_proxy.value =
                        o.time_to_time.value = "";
                    }
                  }
                  if(v !== _.recordedValues.time_range) {
                    _.recordedValues.time_range = v;
                    _changedCriterion();
                  }
                });
                break;
              case "time_from": // Hidden fields.
              case "time_to":
                oElms[nm] = elm;
                break;
              case "time_from_proxy":
              case "time_to_proxy":
                oElms[nm] = elm;
                u = nm === "time_from_proxy" ? "from" : "to";
                //  Create time field.
                jq.after(
                  "<input class=\"form-text\" type=\"text\" maxlength=\"8\" size=\"8\" value=\"\" name=\"log_filter_time_" + u + "_time\" autocomplete=\"off\" />"
                );
                //  Put jQuery UI datepicker on time fields.
                jq.datepicker({
                  dateFormat: _.dateFormat_datepicker
                });
                //  Refer time field.
                oElms[ "time_" + u + "_time" ] = elm2 = $("input[name=\'log_filter_time_" + u + "_time\']").get(0);
                //  Set datepicker and time field values.
                if((v = _elements.conditions[ u === "from" ? "time_from" : "time_to" ].value) && (v = parseInt(v, 10))) {
                  jq.datepicker("setDate", d = new Date(v * 1000));
                  elm2.value = Judy.timeFormat(d);
                }
                //  Date proxy field handler.
                jq.change(function() {
                  var v, d, nm = this.name.indexOf("from") > 1 ? "from" : "to", r = _elements.conditions[ "time_" + nm ],
                    rT = _elements.conditions[ "time_" + nm + "_time" ];
                  if((v = $.trim(this.value)).length) {
                    if((d = Judy.dateFromFormat(v, _.dateFormat))) {
                      _.recordedValues.time_range = _elements.conditions.time_range.value = ""; // Clear time_range.
                      rT.value = Judy.timeFormat(d, rT.value);
                      r.value = v = Math.floor(d.getTime() / 1000);
                      //  If time_to, and same as time_from, and no hours/minutes/seconds: make time_to the end of the day.
                      if(nm === "to" && ("" + v) === _elements.conditions.time_from.value &&
                        d.getHours() === 0 && d.getMinutes() === 0 && d.getSeconds() === 0
                      ) {
                        rT.value = Judy.timeFormat(d, "24");
                        r.value = Math.floor(d.getTime() / 1000);
                      }
                      else {
                        _validateTimeSequence(nm, true);
                      }
                    }
                    else {
                      self.Message.set( self.local("invalid_date", {"!date": v, "!format": _.dateFormat}), "warning", { modal: true });
                      r.value = "";
                      return; // No change, skip _changedCriterion()
                    }
                  }
                  _changedCriterion();
                });
                //  Time field handler.
                $(elm2).change(function() {
                  var nm = this.name.indexOf("from") > -1 ? "from" : "to", rD = _elements.conditions[ "time_" + nm ], d;
                  //  Cant set time when no date.
                  if(!(d = rD.value)) {
                    this.value = "";
                    return;
                  }
                  d = new Date(d * 1000);
                  this.value = Judy.timeFormat(d, this.value);
                  rD.value = Math.floor(d / 1000);
                  _validateTimeSequence(nm);
                  _changedCriterion();
                });
                break;
              case "severity_any":
                oElms[nm] = elm;
                //  Un-check specific severities upon checking severity:any.
                jq.change(function() {
                  var a = _elements.conditions.severity_some, le = a.length, i, v;
                  if(this.checked) { // Un-check all severity_some.
                    for(i = 0; i < le; i++) {
                      a[i].checked = false;
                    }
                  }
                  else { // If no severity_some, re-check severity_any.
                    for(i = 0; i < le; i++) {
                      if(a[i].checked) {
                        v = true;
                        break;
                      }
                    }
                    if(!v) {
                      this.checked = "checked";
                      return; // No change.
                    }
                  }
                  _changedCriterion();
                });
                break;
              case "severity_some": // More elements.
                oElms[nm] = jq.get();
                //  Un-check severity:any upon change in list of severity.
                jq.change(function() {
                  var a, le, i, someChecked;
                  if(this.checked) {
                    _elements.conditions.severity_any.checked = false;
                  }
                  else {
                    le = (a = _elements.conditions.severity_some).length;
                    for(i = 0; i < le; i++) {
                      if(a[i].checked) {
                        someChecked = true;
                        break;
                      }
                    }
                    if(!someChecked) {
                      _elements.conditions.severity_any.checked = "checked";
                    }
                  }
                  _changedCriterion();
                });
                break;
              case "type_any": // check list
                oElms[nm] = elm;
                jq.change(function() {
                  var elm;
                  if(this.checked) {
                    _elements.conditions.type_some.value = "";
                    Judy.fieldValue(_elements.conditions.type_proxy, null, "", "checkboxes");
                  }
                  _changedCriterion();
                });
                break;
              case "type_some": // Real name: log_filter_type.
                oElms[nm] = elm;
                _textareaRemoveWrapper(elm);
                elm.value = elm.value.replace(/\r/g, '');
                break;
              case "type_proxy": // check list
                oElms[nm] = elm;
                // Un-name checklist options, to prevent backend validation error (Illegal choice...).
                // And make list of all options.
                $("input[type='checkbox']", par = Judy.ancestor(elm, 'div.form-checkboxes')).each(function() {
                  this.id = '';
                  this.setAttribute('name', '');
                  _.recordedValues.type_options.push(this.value);
                });
                // Pass values from type_some (hidden textarea; real name: log_filter_type).
                Judy.fieldValue(_elements.conditions.type_proxy, _elements.form, $.trim(_elements.conditions.type_some.value).split(/\n/), "checkboxes");
                jq.change(_typeProxyHandler);
                // Insert 'Add type' option.
                $(par).prepend(
                  '<div class="form-item form-type-checkbox">' +
                    '<input type="checkbox" class="form-checkbox" value="" name="log_filter_type_proxy_add_item" autocomplete="off" />' +
                    ' <input type="text" value="" name="log_filter_type_proxy_add_item_value" autocomplete="off" class="form-text" placeholder="' +
                      self.local('add_type_item') + '" />' +
                  '</div>'
                );
                $('input[name="log_filter_type_proxy_add_item"]', _elements.form).change(function() {
                  var elm, v;
                  if (this.checked) {
                    elm = $('input[name="log_filter_type_proxy_add_item_value"]', _elements.form).get(0);
                    if ((v = elm.value) && (v = $.trim(Judy.stripTags(v.replace(/[\r\n]/g, ''))))) {
                      if (Judy.arrayIndexOf(_.recordedValues.type_options, v) === -1) { // IDE may wrongly report error.
                        _.recordedValues.type_options.push(v);
                        _elements.conditions.type_some.value += (_elements.conditions.type_some.value ? "\n" : '') + v;
                        $(elm.parentNode).after(
                          '<div class="form-item form-type-checkbox">' +
                            '<input type="checkbox" class="form-checkbox" value="' + v + '" checked="checked" />' +
                            ' <label class="option">' + v + '</label>' +
                           '</div>'
                        );
                        $('input[value="' + v +'"]', par).change(_typeProxyHandler);
                        _elements.conditions.type_any.checked = false;
                      }
                      else {
                        self.Message.set(self.local('type_option_dupe', { '!option': v }), "warning", {
                          modal: true,
                          close: function() {
                            Judy.focus(elm);
                          }
                        });
                      }
                    }
                    this.checked = false;
                    elm.value = '';
                  }
                });
                break;
              case "role":
                oElms[nm] = elm;
                //  Clear uid when selecting a role.
                jq.change(function() {
                  if(Judy.fieldValue(this)) {
                    _elements.conditions.uid.value = _elements.conditions.username.value = "";
                  }
                  _changedCriterion();
                });
                break;
              case "uid":
                oElms[nm] = elm;
                _.recordedValues[nm] = elm.value;
                //  Clear role when setting a uid.
                jq.change(function() {
                  var v = this.value;
                  if(v !== "") {
                    this.value = v = $.trim(v);
                  }
                  if(v !== "") {
                    if(!/^\d+$/.test(v)) {
                      self.Message.set( self.local("invalid_uid"), "warning", {
                        modal: true,
                        close: function() {
                          Judy.focus(_elements.conditions.uid);
                        }
                      });
                      this.value = v = "";
                    }
                    else {
                      // Clear role when setting a uid.
                      Judy.fieldValue(_elements.conditions.role, null, "");
                      _elements.conditions.username.value = '';
                    }
                  }
                  // Always clear username when setting uid.
                  _elements.conditions.username.value = '';
                  if(v !== _.recordedValues.uid) {
                    _.recordedValues.uid = v;
                    _changedCriterion();
                  }
                });
                break;
              case "username":
                oElms[nm] = elm;
                $(elm).autocomplete({
                  source: "/log_filter/ajax/username_autocomplete",
                  minLength: 2,
                  select: function(event, ui) {
                    var v;
                    if (ui.item) {
                      _elements.conditions.uid.value = (v = ui.item.value);
                      _elements.conditions.username.value = ui.item.label;
                      if(v !== _.recordedValues.uid) {
                        _.recordedValues.uid = v;
                        Judy.fieldValue(_elements.conditions.role, null, ""); // Clear role when setting a uid.
                        _changedCriterion();
                      }
                    }
                    return false;
                  }
                }).bind('autocompletesearch', function() {
                  $(this).addClass('throbbing');
                }).bind('autocompleteresponse', function() { // Doesnt work, propably old version of jQuery UI.
                  $(this).removeClass('throbbing');
                });
                Judy.ajaxcomplete(_selectors.conditions.username, '/log_filter/ajax/username_autocomplete', function(event) { // This works, instead.
                  $(this).removeClass('throbbing');
                });
                break;
              case "hostname":
                oElms[nm] = elm;
                _.recordedValues[nm] = elm.value;
                jq.change(function() {
                  var v = this.value;
                  if(v !== "") {
                    this.value = v = Judy.stripTags(v);
                  }
                  if(v !== _.recordedValues.hostname) {
                    _.recordedValues.hostname = v;
                    _changedCriterion();
                  }
                });
                break;
              case "location":
              case "referer":
                oElms[nm] = elm;
                _.recordedValues[nm]= elm.value;
                //  Check for url pattern.
                jq.change(function() {
                  var v = $.trim(this.value), nm = this.name === "log_filter_location" ? "location" : "referer"; // Not the same nm as iteration nm ;-)
                  if(nm === "referer" && (v === "none" || v === "<none>")) {
                    this.value = "none";
                  }
                  else {
                    if(v !== "") {
                      this.value = v = Judy.stripTags(v);
                    }
                    if(v !== "" && v !== "*" && !/^https?:\/\/.+$/.test(v)) {
                      if(!/^https?:\/\/.+$/.test(v = "http://" + v)) {
                        self.Message.set( self.local(nm === "location" ? "invalid_location" : "invalid_referer"), "warning", {
                            modal: true,
                            close: function() {
                              Judy.focus(_elements.conditions[ nm ]);
                            }
                        });
                        this.value = v = "";
                      }
                      else {
                        this.value = v;
                      }
                    }
                  }
                  if(v !== _.recordedValues[nm]) {
                    _.recordedValues[nm] = v;
                    _changedCriterion();
                  }
                });
                break;
              default:
                oElms[nm] = elm;
                jq.change(_changedCriterion); // Criterion change handler.
            }
          }
        }
        //  Order by.
        oElms = _elements.orderBy; // Array.
        if((nOrderBy = (aElms = $(_selectors.orderBy.options).get()).length)) {
          for(i = 0; i < nOrderBy; i++) {
            oElms.push(
              [ elm = aElms[i] ]
            );
            _.recordedValues.orderBy.push(Judy.fieldValue(elm));
            //  There can't be two orderBys having same value.
            $(elm).change(function() {
              var v, index, i, a;
              if((v = Judy.fieldValue(this)) && v !== "_none") {
                index = parseInt(this.name.replace(/^log_filter_orderby_/, ""), 10) - 1;
                a = _elements.orderBy;
                for(i = 0; i < nOrderBy; i++) {
                  if(i !== index && Judy.fieldValue(a[i][0]) === v) {
                    Judy.fieldValue(this, null, v = "");
                    break;
                  }
                }
              }
              if(v !== _.recordedValues.orderBy[index]) {
                _.recordedValues.orderBy[index] = v;
                _changedCriterion();
              }
            });
          }
          if((le = (aElms = $(_selectors.orderBy.bools).get()).length)) {
            for(i = 0; i < le; i++) {
              oElms[i].push(
                elm = aElms[i]
              );
              $(elm).change(_changedCriterion);
            }
          }
        }

        //  Miscellaneous.
        oSels = _selectors.pager;
        oElms = _elements.pager;
        for(nm in oSels) {
          if(oSels.hasOwnProperty(nm) && (elm = (jq = $(oSels[nm])).get(0))) {
            oElms[nm] = elm;
            switch(nm) {
              case "first":
                jq.click(function() {
                  _ajaxRequestingBlocking = true; // Prevent consecutive clicks on update buttons.
                  _getLogList(0, 0);
                });
                break;
              case "previous":
                jq.click(function() {
                  _ajaxRequestingBlocking = true; // Prevent consecutive clicks on update buttons.
                  _getLogList(0, (v = _.currentOffset - _.currentMax) > 0 ? v : 0);
                });
                break;
              case "current":
                jq.click(function() {
                  _ajaxRequestingBlocking = true; // Prevent consecutive clicks on update buttons.
                  _getLogList();
                });
                break;
              case "next":
                jq.click(function() {
                  _ajaxRequestingBlocking = true; // Prevent consecutive clicks on update buttons.
                  _getLogList(0, _.currentOffset + _.currentMax);
                });
                break;
              case "last":
                jq.click(function() {
                  _ajaxRequestingBlocking = true; // Prevent consecutive clicks on update buttons.
                  _getLogList(0, -1);
                });
                break;
            }
          }
        }

        //  Miscellaneous.
        oSels = _selectors.misc;
        oElms = _elements.misc;
        for(nm in oSels) {
          if(oSels.hasOwnProperty(nm) && (elm = (jq = $(oSels[nm])).get(0))) {
            oElms[nm] = elm;
          }
        }

        //  Buttons; get element references, and fix some issues.
        oSels = _selectors.buttons;
        oElms = _elements.buttons;
        for(nm in oSels) {
          if(oSels.hasOwnProperty(nm) && (elm = (jq = $(oSels[nm])).get(0))) {
            switch(nm) {
              case "submit":
                //  Hidden, but we do submit by triggering a click on it anyway, in case Form API sets some javascript behaviour on it.
                //  ...jQuery behaviour, really. Because a jQuery(elm).trigger("click") apparantly doesnt trigger a real click event(?).
                oElms[nm] = elm;
                break;
              case "update_list":
                oElms[nm] = elm;
                elm.setAttribute("type", "button");
                jq.unbind(); // Remove Drupal native button handlers.
                jq.click(function() {
                  _ajaxRequestingBlocking = true; // Prevent consecutive clicks on update buttons.
                  _getLogList();
                });
                Judy.keydown(document.documentElement, "ctr+u cmd+u", function(event) {
                  event.preventDefault();
                  _ajaxRequestingBlocking = true; // Prevent consecutive clicks on update buttons.
                  _getLogList();
                });
                break;
              default:
                oElms[nm] = elm;
                elm.setAttribute("type", "button"); // Fix type (apparant Form API shortcoming).
                jq.unbind(); // Remove Drupal native button handlers.
                switch(nm) {
                  case "create":
                  case "edit":
                  case "delete_filter":
                  case "cancel":
                  case "save":
                    _.crudFilters = true;
                    oElms.crudFilters.push(elm);
                    jq.click(_crudRelay); // Set our common button handler.
                    break;
                  case "delete_logs_button":
                    _.deleteLogs_allowed = true;
                    Judy.disable(elm, null, self.local("deleteLogs_prohibit"));
                    jq.click(_crudRelay); // Set our common button handler.
                    break;
                  case "reset":
                    jq.click(_resetCriteria);
                    break;
                }
            }
          }
        }

        //  Prevent click on hover title label span from resulting in checking/unchecking checkbox.
        $("label span").click(function(evt) {
          evt.stopPropagation();
          return false;
        });
      }
      catch(er) {
        _errorHandler(er, 0, _name + "._prepareForm()");
      }
    };

    self.inspector = function(u) {
      inspect(u, {wrappers:1});
    };

    /**
     * Sets current mode.
     *
     * Values:
     * - default
     * - adhoc
     * - stored
     * - create
     * - edit
     * - delete
     *
     * @ignore
     * @param {string} mode
     * @param {boolean} [submit]
     * @param {boolean} [initially]
     * @return {void}
     */
    _setMode = function(mode, submit, initially) {
      var fromMode = _.mode, doSubmit, elm, nm;
      try {
        if(_submitted) {
          return;
        }
        if(!initially && mode !== "delete_filter") {
          if(!submit && _.crudFilters) {
            //  Hide all filter buttons.
            $(_elements.buttons.crudFilters).hide();
          }
        }
        switch(mode) {
          case "default":
            $("option[value='']", _elements.filter.filter).html( self.local("default") ); // Set visual value of filter selector's empty option.
            $(_elements.misc.title).html(self.local("default"));
            if(!initially) {
              Judy.fieldValue(_elements.filter.filter, null, "");
              _elements.filter.name.value = _.name = _elements.filter.origin.value = _.origin = "";
            }
            if(_.crudFilters) {
              $(_elements.settings.onlyOwn.parentNode).show();
              $(_elements.buttons.create).show();
              if ((elm = _elements.filter.require_admin)) {
                $(elm.parentNode).hide();
              }
              $(_elements.filter.name_suggest.parentNode).hide();
              $(_elements.filter.description.parentNode).hide();
            }
            if(_.deleteLogs_allowed) {
              $(_elements.settings.delete_logs_max).show();
              $(elm = _elements.buttons.delete_logs_button).show();
              $(elm.parentNode).show();
            }
            if(fromMode === "create") {
              fromMode = ""; // Dont keep 'create' as _.modePrevious.
            }
            break;
          case "adhoc":
            if(!initially) {
              Judy.fieldValue(_elements.filter.filter, null, "");
            }
            if(fromMode === "stored") {
              //  Pass current name to origin field.
              _elements.filter.origin.value = _.origin = nm = _.name;
              _elements.filter.name.value = _.name = "";
              $("option[value='']", _elements.filter.filter).html("(" + nm + ")"); // Set visual value of filter selector's empty option.
              $(_elements.misc.title).html( self.local("adhocForOrigin", {"!origin": nm} ) );
            }
            else {
              fromMode = ""; // Dont keep 'create' as _.modePrevious.
              $("option[value='']", _elements.filter.filter).html(self.local("adhoc")); // Set visual value of filter selector's empty option.
              $(_elements.misc.title).html(self.local("adhoc"));
            }
            if(_.crudFilters) {
              $(_elements.settings.onlyOwn.parentNode).show();
              $(_elements.buttons.create).show();
              if ((elm = _elements.filter.require_admin)) {
                $(elm.parentNode).hide();
              }
              $(_elements.filter.name_suggest.parentNode).hide();
              $(_elements.filter.description.parentNode).hide();
            }
            if(_.deleteLogs_allowed) {
              $(_elements.settings.delete_logs_max).show();
              $(elm = _elements.buttons.delete_logs_button).show();
              $(elm.parentNode).show();
            }
            break;
          case "stored": // stored mode may only appear on page load and after cancelling create.
            if(!initially) {
              if(fromMode === "create") {
                _elements.filter.name.value = _.name = _.origin;
                _elements.filter.origin.value = _.origin = "";
              }
              Judy.fieldValue(elm = _elements.filter.filter, null, nm = _.name);
              $("option[value='']", elm).html( self.local("default") ); // Set visual value of filter selector's empty option.
              $(_elements.misc.title).html( nm );
              if(_.crudFilters) {
                if ((elm = _elements.filter.require_admin)) {
                  $(elm.parentNode).hide();
                }
                $(_elements.filter.name_suggest.parentNode).hide();
                $(_elements.filter.description.parentNode).hide();
              }
            }
            if(_.crudFilters) {
              $(_elements.settings.onlyOwn.parentNode).show();
              $(_elements.buttons.create).show();
              $(_elements.buttons.edit).show();
              $(_elements.buttons.delete_filter).show();
            }
            if(_.deleteLogs_allowed) {
              $(_elements.settings.delete_logs_max).show();
              $(elm = _elements.buttons.delete_logs_button).show();
              $(elm.parentNode).show();
            }
            switch(fromMode) {
              case "create":
              case "edit":
                fromMode = "stored"; // Dont keep 'create' as _.modePrevious.
                break;
            }
            break;
          case "create":
            if(!_.crudFilters) {
              throw new Error("Mode[" + mode + "] not allowed.");
            }
            switch(fromMode) {
              case "default":
              case "adhoc":
                $("option[value='']", _elements.filter.filter).html("(" + self.local("newName") + ")"); // Set visual value of filter selector's empty option.
                $(_elements.misc.title).html( self.local("newTitle") );
                break;
              case "stored":
                Judy.fieldValue(_elements.filter.filter, null, "");
                //  Pass current name to origin field.
                _elements.filter.origin.value = _.origin = nm = _.name;
                _elements.filter.name.value = _.name = "";
                $("option[value='']", _elements.filter.filter).html("(" + nm + ")"); // Set visual value of filter selector's empty option.
                $(_elements.misc.title).html( self.local("newForOrigin", {"!origin": nm} ) );
                break;
              default:
                throw new Error("Cant create from mode[" + fromMode + "].");
            }
            $(_elements.settings.onlyOwn.parentNode).hide();
            $(_elements.filter.name_suggest.parentNode).show();
            if ((elm = _elements.filter.require_admin)) {
              $(elm.parentNode).show();
            }
            $(_elements.filter.description.parentNode).show();
            $(_elements.buttons.save).show();
            $(_elements.buttons.cancel).show();
            if(_.deleteLogs_allowed) {
              $(_elements.buttons.delete_logs_button.parentNode).hide();
            }
            break;
          case "edit":
            if(!_.crudFilters) {
              throw new Error("Mode[" + mode + "] not allowed.");
            }
            if(fromMode === "create") {
              //  If going from create to edit: memorize mode right before create, to prevent ending up having (useless) create as previous mode.
              fromMode = _.modePrevious;
              $("option[value='']", elm = _elements.filter.filter).after(
                "<option value=\"" + (nm = _.name) + "\">" + nm + "</option>"
              );
              $("option[value='']", elm).html( self.local("default") );
              Judy.fieldValue(elm, null, nm);
            }
            if ((elm = _elements.filter.require_admin)) {
              $(elm.parentNode).show();
            }
            $(_elements.filter.name_suggest.parentNode).hide();
            $(_elements.filter.description.parentNode).show();
            $(_elements.buttons.cancel).show();
            $(_elements.buttons.save).show();
            $(_elements.settings.onlyOwn.parentNode).hide();
            if(_.deleteLogs_allowed) {
              $(_elements.buttons.delete_logs_button.parentNode).hide();
            }
            break;
          case "delete_filter": // Pop confirm(), and submit upon positive confirmation.
            if(!_.crudFilters) {
              throw new Error("Mode[" + mode + "] not allowed.");
            }
            Judy.overlay(1, true); // Opaque.
            if (_elements.filter.name.value) {
              if(!confirm( self.local(
                "confirmDelete",
                {"!filter": _elements.filter.name.value}
              ))) {
                Judy.overlay(0);
                return;
              }
              doSubmit = true;
              Judy.overlay(1, false, self.local("wait")); // Transparent.
            }
            else {
              throw new Error("Cant delete filter having empty name[" + _elements.filter.name.value + "].");
            }
            break;
          default:
            throw new Error("Mode[" + mode + "] not supported.");
        }
        _.modePrevious = fromMode;
        _elements.settings.mode.value = _.mode = mode;
        if(submit || doSubmit) {
          _submit();
        }
      }
      catch(er) {
        _errorHandler(er, 0, _name + "._setMode()");
      }
    };
    /**
     * Common handler for all CRUD buttons.
     *
     * @ignore
     * @return {boolean}
     */
    _crudRelay = function() {
      var nm = this.name, // The element's name, not _.name.
        elm, v, rqa;
      try {
        switch(nm) {
          case "log_filter_reset":
            _resetCriteria();
            break;
          case "log_filter_create":
            _setMode("create");
            Judy.focus(_elements.filter.name_suggest);
            break;
          case "log_filter_edit":
            _setMode("edit");
            break;
          case "log_filter_delete":
            _setMode("delete_filter");
            break;
          case "log_filter_cancel":
            switch(_.mode) {
              case "create":
              case "edit":
                switch(_.modePrevious) {
                  case "default":
                  case "adhoc":
                    break;
                  case "stored":
                    break;
                  default:
                    throw new Error("Previous mode[" + _.modePrevious + "] not supported when cancelling.");
                }
                _setMode(_.modePrevious);
                break;
              default:
                throw new Error("Cant cancel in mode[" + _.mode + "].");
            }
            break;
          case "log_filter_save":
            if(_.mode === "edit" && !_.saveEditFilterAjaxed) {
              Judy.overlay(1, false, self.local("wait_" + _.mode));
              _submit();
              return false;
            }
            else {
              //  Prevent double-click.
              if(_ajaxRequestingBlocking) {
                return false; // false for IE<9's sake.
              }
              if(_.mode === "create") {
                //  No reason to trim(), because change handler (_machineNameChange()) replaces spaces with underscores.
                if(!_machineNameValidate(null, null, v = (elm = _elements.filter.name_suggest).value)) {
                  Judy.focus(elm);
                  return false; // false for IE<9's sake.
                }
                if($.inArray(v, _filters) > -1) {
                  Judy.overlay(1, true);
                  if (!confirm(self.local("error_filter_name_nonunique", {"!name": v}))) {
                    Judy.overlay(0);
                    return false;
                  }
                  else {
                    Judy.overlay(1, false, self.local("wait_edit"));
                    _elements.settings.mode.value = _.mode = "edit";
                    _elements.filter.name.value = v;
                    _submit();
                    return false;
                  }
                }
                nm = v;
                rqa = _elements.filter.require_admin ? 1 : 0; // Create with require_admin if the element exists (the user has the permission).
              }
              else {
                nm = _.name;
                rqa = (elm = _elements.filter.require_admin) && Judy.fieldValue(elm);
              }
              Judy.overlay(1, false, self.local("wait_" + _.mode));
              _ajaxRequestingBlocking = true;
              v = self.getCriteria();
              _ajaxRequest("filter_" + _.mode, { // filter_create|filter_edit
                name: nm,
                filter: {
                  require_admin: rqa,
                  description: $.trim(Judy.stripTags(_elements.filter.description.value).replace(/[\r\n\t]/g, " ").replace(/\ +/g, " ")).substr(0, 255)
                },
                conditions: v.conditions,
                order_by: v.order_by
              });
            }
            break;
          case "log_filter_delete_logs_button":
            if(_.deleteLogs_allowed) {
              Judy.overlay(1, false, self.local("wait"));
              setTimeout(_deleteLogs, 200);
            }
            else {
              throw new Error("Button name[" + nm + "] not allowed.");
            }
            break;
          default:
            throw new Error("Unsupported button name[" + nm + "].");
        }
      }
      catch(er) {
        _errorHandler(er, 0, _name + "._crudRelay()");
      }
      return false; // false for IE<9's sake.
    };
    /**
     * Change handler for all condition and orderBy fields.
     *
     * @ignore
     * @return {void}
     */
    _changedCriterion = function() {
      if(_.deleteLogs_allowed) {
        Judy.disable(_elements.buttons.delete_logs_button, null, self.local("deleteLogs_prohibit"));
      }
      try {
        switch(_.mode) {
          case "default":
            _setMode("adhoc");
            break;
          case "adhoc":
            break;
          case "stored":
            //  A change of a stored filter triggers edit mode if the user is allowed to edit filters.
            _setMode(!_.crudFilters ? "adhoc" : "edit");
            break;
          case "create":
            break;
          case "edit":
            break;
          case "delete_filter":
            break;
          default:
            throw new Error("Mode[" + _.mode + "] not supported.");
        }
      }
      catch(er) {
        _errorHandler(er, 0, _name + "._changedCriterion()");
      }
    };
    /**
     * Clear all condition and orderby fields, and set defaults.
     *
     * @ignore
     * @param {Event} [evt]
     *  - when used as event handler
     * @param {string|falsy} [mode]
     *  - set mode to that
     * @param {boolean} [noModeChange]
     *  - do not change mode
     * @return {void}
     */
    _resetCriteria = function(evt, mode, noModeChange) {
      var o = _elements.conditions, nm, r, a, le, i;
      if(_.deleteLogs_allowed) {
        Judy.disable(_elements.buttons.delete_logs_button, null, self.local("deleteLogs_prohibit"));
      }
      for(nm in o) {
        if(o.hasOwnProperty(nm)) {
          r = o[nm];
          //  Default to severity any and type any.
          switch(nm) {
            case "severity_any":
            case "type_any":
              r.checked = true;
              break;
            case "severity_some": // Array.
              le = r.length;
              for(i = 0; i < le; i++) {
                r[i].checked = false;
              }
              break;
            case "type_proxy":
              if(r) { // Doesnt exists if no logs at all.
                Judy.fieldValue(r, null, "", "checkboxes");
              }
              break;
            default:
              r.value = "";
          }
        }
      }
      le = (a = _elements.orderBy).length;
      //  Default to order by time ascending, only.
      for(i = 0; i < le; i++) {
        Judy.fieldValue(a[i][0], null, i ? "" : "time");
        a[i][1].checked = i ? false : "checked";
      }
      if(!noModeChange) {
        //  Degrade mode.
        if(mode) {
          _setMode(mode);
        }
        else {
          _setMode("default");
        }
      }
    };
    /**
     * @ignore
     * @return {void}
     */
    _deleteLogs = function() {
      var o = self.getCriteria(), v, offset = _.currentOffset, max = (v = _elements.settings.delete_logs_max.value) !== "" ? parseInt(v) : 0;
      if(!o.nConditions) { // Even stored filters go here; if a stored filter has no conditions, than THAT is the important thing.
        //  We warn every time, when no conditions at all.
        if(!max) {
          if (!offset) {
            if(!confirm( self.local("deleteLogs_all") )) {
              Judy.overlay(0);
              Judy.focus(_elements.settings.delete_logs_max);
              return;
            }
          }
          else if(!confirm( self.local("deleteLogs_noMax", {"!offset": offset}) )) {
            Judy.overlay(0);
            Judy.focus(_elements.settings.delete_logs_max);
            return;
          }
        }
        else if (!offset) {
          if(!confirm( self.local("deleteLogs_noOffset", {"!max": max}) )) {
            Judy.overlay(0);
            Judy.focus(_elements.settings.delete_logs_max);
            return;
          }
        }
        else if(!confirm( self.local("deleteLogs_noConditions", {"!offset": offset, "!max": max}) )) {
          Judy.overlay(0);
          Judy.focus(_elements.settings.delete_logs_max);
          return;
        }
      }
      else if(_.mode === "stored") {
        if(!max) {
          if (!offset) {
            if(!confirm( self.local("deleteLogs_storedAll", {"!name": _.name}) )) {
              Judy.overlay(0);
              Judy.focus(_elements.settings.delete_logs_max);
              return;
            }
          }
          else if(!confirm( self.local("deleteLogs_storedNoMax", {"!offset": offset, "!name": _.name}) )) {
            Judy.overlay(0);
            Judy.focus(_elements.settings.delete_logs_max);
            return;
          }
        }
        else if (!offset) {
          if(!confirm( self.local("deleteLogs_storedNoOffset", {"!max": max, "!name": _.name}) )) {
            Judy.overlay(0);
            Judy.focus(_elements.settings.delete_logs_max);
            return;
          }
        }
        else if(!confirm( self.local("deleteLogs_stored", {"!offset": offset, "!max": max, "!name": _.name}) )) {
          Judy.overlay(0);
          Judy.focus(_elements.settings.delete_logs_max);
          return;
        }
      }
      else if(!max) {
        if (!offset) {
          if(!confirm( self.local("deleteLogs_adhocAll") )) {
            Judy.overlay(0);
            Judy.focus(_elements.settings.delete_logs_max);
            return;
          }
        }
        else if(!confirm( self.local("deleteLogs_adhocNoMax", {"!offset": offset}) )) {
          Judy.overlay(0);
          Judy.focus(_elements.settings.delete_logs_max);
          return;
        }
      }
      else if (!offset) {
        if(!confirm( self.local("deleteLogs_adhocNoOffset", {"!max": max}) )) {
          Judy.overlay(0);
          Judy.focus(_elements.settings.delete_logs_max);
          return;
        }
      }
      else if(!confirm( self.local("deleteLogs_adhoc", {"!offset": offset, "!max": max}) )) {
        Judy.overlay(0);
        Judy.focus(_elements.settings.delete_logs_max);
        return;
      }
      _ajaxRequestingBlocking = true;
      v = self.getCriteria();
      _ajaxRequest("delete_logs", {
        conditions: v.conditions,
        order_by: v.order_by,
        offset: offset,
        max: max
      });
    };

    /**
     * @ignore
     * @param {Event} evt
     * @return {void}
     */
    _filterByEventColumn = function(evt) {
      var that = evt.target, tag, logId, col, log, u, o = _elements.conditions, elm, elm1, v, v1, a, vShow, username;
      if (evt.type === 'contextmenu') {
        evt.preventDefault();
      }
      // Get out if not td or link within td.
      switch ((tag = that.tagName || 'none').toLowerCase()) {
        case 'td':
          break;
        case 'a': // User column may contain link.
          username = $(that).text();
          that = that.parentNode;
          break;
        default:
          return;
      }
      // The td must have column attribute.
      if (!(col = that.getAttribute('log_filter_list_event_column'))) {
        return;
      }
      // Parent tr must have a log id attribute, and the log must exist.
      if (!(logId = that.parentNode.getAttribute('log_filter_list_event_id')) ||
        !(log = _logs['_' + logId]) || !_logs.hasOwnProperty('_' + logId)
      ) {
        return;
      }

      switch (col) {
        case 'severity':
          vShow = self.local(_severity[ log.severity ]);
          v = log.severity || 'zero';
          if ((a = Judy.fieldValue(elm = o.severity_some, _elements.form, undefined, 'checklist'))) {
            a.push(v);
            v = a;
          }
          Judy.fieldValue(elm, _elements.form, v, 'checklist');
          $(elm).trigger('change');
          break;
        case 'type':
          // If no such option exists yet: add it.
          if (Judy.arrayIndexOf(_.recordedValues.type_options, v = log.type) === -1) {
            $('input[name="log_filter_type_proxy_add_item_value"]', _elements.form).val(v);
            $('input[name="log_filter_type_proxy_add_item"]', _elements.form).get(0).checked = 'checked';
            $('input[name="log_filter_type_proxy_add_item"]', _elements.form).trigger('change');
          }
          else {
            if ((a = Judy.fieldValue(elm = o.type_proxy, _elements.form, undefined, 'checklist'))) {
              a.push(v);
              v = a;
            }
            Judy.fieldValue(elm, _elements.form, v, 'checklist');
            $('div#edit-log-filter-type-proxy input[value="' + v + '"]').trigger('change');
          }
          vShow = v;
          break;
        case 'time': // Time: right-click/f means Time From, shift+f means Time To.
          u = evt.type === 'keydown' && evt.keystrokes !== 'f' ? 'time_to' : 'time_from';
          (elm = o[u + '_proxy']).value = v = log.time.substr(0, 10);
          $(elm).trigger('change');
          (elm1 = o[u + '_time']).value = v1 = log.time.substr(11);
          $(elm1).trigger('change');
          if (elm.value !== v || elm1.value !== v1) {
            return; // Dont set message.
          }
          col = u; // For Message.
          vShow = log.time;
          break;
        default:
          (elm = o[col]).value = vShow = v = log[col];
          $(elm).trigger('change');
          if (col === 'uid' && username) {
            _elements.conditions.username.value = username;
          }
      }
      self.Message.set( self.local("filtered_event_column", { '!column': self.local('log_' + col), '!value': vShow }), "info");
    };

    /**
     * @ignore
     * @param {integer} [wid]
     *  - for single log view
     * @param {integer|undefined} [offset]
     *  - default: current offset
     *  - minus one means last
     * @return {void}
     */
    _getLogList = function(wid, offset) {
      var v = self.getCriteria();
      Judy.overlay(1, false, self.local("wait"));
      if(wid) {
        v.conditions = {
          wid: wid
        };
        offset = 0;
      }
      _ajaxRequest("list_logs", {
        conditions: v.conditions,
        order_by: v.order_by,
        offset: offset || offset === 0 ? offset : _.currentOffset,
        max: _.currentMax,
        translate: Judy.fieldValue(_elements.settings.translate)
      });
      $(_elements.pager.first).addClass("log-filter-pager-button-disabled");
      $(_elements.pager.previous).addClass("log-filter-pager-button-disabled");
      $(_elements.pager.current).hide();
      $(_elements.pager.progress).show();
      $(_elements.pager.next).addClass("log-filter-pager-button-disabled");
      $(_elements.pager.last).addClass("log-filter-pager-button-disabled");
    };

    /**
     * @ignore
     * @param {array} logs
     * @param {object} conditions
     *  - list of conditions used, values are always true (except for the 'wid' condition)
     * @param {integer} offset
     * @param {integer} nTotal
     * @return {void}
     */
    _listLogs = function(logs, conditions, offset, nTotal) {
      var le = logs.length, i, o, v, css = 'log-filter-list', s, nCols = 5, wid, optionalColumns = {}, tabindex = 999;
      _logs = {};
      _.currentOffset = offset || 0;
      if(le) {
        for(i = 0; i < le; i++) {
          o = logs[i];
          //  Replace variables if exist and not done already by backend (is done if translate is on).
          if(o.variables) {
            o.message = Drupal.formatString(o.message, o.variables);
          }
          delete o.variables;
          //  Resolve severity.
          o.severity = parseInt('' + o.severity, 10);
          o.severity_string = _severity[o.severity];
          // Set other properties.
          o.time = Judy.dateTime(new Date(o.timestamp * 1000));
          if (!o.uid || o.uid === "0") {
            o.uid = 0;
            o.name = self.local("anonymous_user");
          }
          _logs[ "_" + o.wid ] = o;
        }
      }
      // Render.
      s = '<table id="log_filter_log_list_table" class="sticky-enabled" tabindex="' + (++tabindex) + '"><thead><tr>' +
        '<th>' + Drupal.t('Severity') + '</th>' +
        '<th>' + Drupal.t('Type') + '</th>' +
        '<th>' + Drupal.t('Time') + '</th>' +
        '<th>' + Drupal.t('User') + '</th>';
      if(conditions.hostname || _elements.conditions.hostname.value === '*') {
        ++nCols;
        optionalColumns.hostname = true;
        s += '<th>' + Drupal.t('Hostname') + '</th>';
      }
      if(conditions.location || _elements.conditions.location.value === '*') {
        ++nCols;
        optionalColumns.location = true;
        s += '<th>' + Drupal.t('Location') + '</th>';
      }
      if(conditions.referer || _elements.conditions.referer.value === '*') {
        ++nCols;
        optionalColumns.referer = true;
        s += '<th>' + Drupal.t('Referrer') + '</th>';
      }
      s += '<th>' + Drupal.t('Message') + '</th>' +
        '</tr></thead><tbody>';
      if(le) {
        // Listing only a single log (from url)?
        if ((wid = conditions.wid) && conditions.hasOwnProperty('wid')) {
          s += '<tr class="even">' +
            '<td class="' + css + '-event-from-url" colspan="' + nCols + '">' +
            self.local('event_from_url', { '!number': wid }) +
            '</td>' +
            '</tr>';
          setTimeout(function() {
            self.displayLog(wid);
          }, 100);
        }
        for(i = 0; i < le; i++) {
          o = logs[i];
          s += '<tr id="log_filter_list_log_' + o.wid + '" log_filter_list_event_id="' + o.wid + '" onclick="LogFilter.displayLog(' + o.wid +
              ');" class="' + (i % 2 ? 'even' : 'odd') + '" title="' + self.local("eventItem_display", { '!logId': o.wid }) + '">' +
            '<td log_filter_list_event_column="severity" class="' + css + '-severity ' + css + '-' + (v = o.severity_string) + '" title="' +
              self.local('eventItemHover_severity', { '!logId': o.wid, '!severity': self.local(v) }) + '" tabindex="' + (++tabindex) +
              '" onmouseover="focus(this);">&#160;</td>' +
            '<td log_filter_list_event_column="type" class="' + css + '-type" title="' +
              self.local('eventItemHover_filter', { '!logId': o.wid, '!filter': self.local('log_type') }) +
              '" tabindex="' + (++tabindex) + '" onmouseover="focus(this);">' + o.type + '</td>' +
            '<td log_filter_list_event_column="time" class="' + css + '-time" title="' + self.local('eventItemHover_time', { '!logId': o.wid }) +
              '" tabindex="' + (++tabindex) + '" onmouseover="focus(this);">' + o.time + '</td>' +
            '<td log_filter_list_event_column="uid" class="' + css + '-user" title="' +
              self.local('eventItemHover_user', { '!logId': o.wid, '!uid': o.uid }) + '"' +
              (!o.uid || o.name === null ? (!o.uid ? (' onmouseover="focus(this);">' + (o.name)) : ('>-' + self.local("deleted_user") + '-')) :
                ('><a href="/user/' + o.uid + '" onmouseover="focus(this);">' + o.name + '</a>')) +
              '</td>' +
            (!optionalColumns.hostname ? '' :
              '<td log_filter_list_event_column="hostname" class="' + css + '-hostname" title="' +
                self.local('eventItemHover_filter', { '!logId': o.wid, '!filter': self.local('log_hostname') }) +
                '" tabindex="' + (++tabindex) + '" onmouseover="focus(this);">' + o.hostname + '</td>') +
            (!optionalColumns.location ? '' :
              '<td log_filter_list_event_column="location" class="' + css + '-location" title="' +
                self.local('eventItemHover_filter', { '!logId': o.wid, '!filter': self.local('log_location') }) +
                '" tabindex="' + (++tabindex) + '" onmouseover="focus(this);">' + o.location + '</td>') +
            (!optionalColumns.referer ? '' :
              '<td log_filter_list_event_column="referer" class="' + css + '-referer" title="' +
                self.local('eventItemHover_filter', { '!logId': o.wid, '!filter': self.local('log_referer') }) +
                '" tabindex="' + (++tabindex) + '" onmouseover="focus(this);">' + o.referer + '</td>') +
            '<td class="' + css + '-message"><div>' +
              Judy.stripTags(o.message.replace(/\r?\n/g, " ")).substr(0, _.listMessageTruncate) + '</div></td>' +
            '</tr>';
        }
        // Pager.
        $(_elements.pager.progress).hide();
        if (offset) {
          $(_elements.pager.first).removeClass("log-filter-pager-button-disabled");
          $(_elements.pager.previous).removeClass("log-filter-pager-button-disabled");
        }
        $(_elements.pager.current).html(self.local('pager_current', { '!first': (offset + 1), '!last': (offset + le), '!total': nTotal })).show();
        if (offset + le < nTotal) {
          $(_elements.pager.next).removeClass("log-filter-pager-button-disabled");
          $(_elements.pager.last).removeClass("log-filter-pager-button-disabled");
        }
      }
      else {
        s += '<tr class="odd">' +
          '<td class="' + css + '-no-match" colspan="' + nCols + '">' +
          (!conditions.wid ? self.local('no_event_matches') : self.local('non_existing_event', { '!number': conditions.wid })) +
          '</td>' +
          '</tr>';
        // Pager.
        $(_elements.pager.progress).hide();
        if (offset) {
          $(_elements.pager.first).removeClass("log-filter-pager-button-disabled");
          $(_elements.pager.previous).removeClass("log-filter-pager-button-disabled");
        }
        if (!nTotal) {
          $(_elements.pager.current).html(self.local('pager_current_none')).show();
        }
        else {
          $(_elements.pager.current).html(self.local('pager_current_outofrange', { '!offset': offset, '!total': nTotal })).show();
        }
      }
      s += "</tbody></table>";
      // Display the table, after updating pager (displaying the table may take some time).
      $("#log_filter_log_list").html(s);

      setTimeout(function() {
        // Apply Drupal tableheader.
        $('#log_filter_log_list table.sticky-enabled').once('tableheader', function () {
          $(this).data("drupal-tableheader", new Drupal.tableHeader(this));
        });
        // Add filter by event column value handlers.
        $('table#log_filter_log_list_table').bind('contextmenu', _filterByEventColumn);
        Judy.keydown('table#log_filter_log_list_table', 'f shift+f', _filterByEventColumn, true); // preventDefault
      }, 100);
    };

    /**
     * @ignore
     * @param {string} action
     * @param {object} oData
     * @return {void}
     */
    _ajaxRequest = function(action, oData) {
      $.ajax({
        url: "/log_filter/ajax/" + action,
        type: "POST",
        data: oData,
        dataType: "json", // expects json formatted response data
        cache: false,
        /**
          * @return {void}
          * @param {object} oResp
          *  - (string) action
          *  - (boolean) success
          *  - (string) error
          *  - (integer) error_code
          * @param {string} textStatus
          * @param {object} jqXHR
          */
        success: function(oResp, textStatus, jqXHR) {
          var o;
          if(textStatus === "success" && typeof action === "string" && $.type(oResp) === "object") {
            _ajaxResponse(action, oResp);
          }
          else {
            o = {
              source: "ajax request",
              action: action,
              textStatus: textStatus,
              oResp: oResp
            };
            _.errors.push(o);
            _errorHandler(null, o, _name + "._ajaxRequest()");
          }
        },
        error: function(jqXHR, textStatus, errorThrown) {
          var o;
          if(jqXHR && jqXHR.status === 403) {
            _ajaxResponse(action, { success: false, error_code: _errorCodes.perm_general });
          }
          else {
            o = {
              source: "ajax request",
              action: action,
              textStatus: textStatus,
              errorThrown: errorThrown
            };
            _.errors.push(o);
            _errorHandler(null, o, _name + "._ajaxRequest()");
          }
        }
      });
    };
    /**
     * @ignore
     * @param {string} action
     * @param {object} oResp
     * @return {void}
     */
    _ajaxResponse = function(action, oResp) {
      var errorCode = oResp.error_code || 0, url;
      //  Handle general errors.
      if (!oResp.success || errorCode) {
        switch(errorCode) {
          //  General errors.
          case _errorCodes.perm_general: // Probably session timeout.
            //  Reload page, to get 403. And remove form.
            $(_elements.form).html("");
            self.Message.set( self.local("error_form_expired", { "!url": url = _url() }), "warning", { // In case Javascript redirect fails.
                modal: true,
                close: function() {
                  window.location.href = url;
                }
            });
            return;
          case _errorCodes.form_expired:
            self.Message.set( self.local("error_form_expired", { "!url": url = _url() }), "warning", {
                modal: true,
                close: function() {
                  window.location.href = url;
                }
            });
            return;
          //  Errors by more than one request type.
          case _errorCodes.perm_filter_crud:
            self.Message.set( self.local("error_perm_filter_crud"), "warning", {
                modal: true,
                close: function() {
                  window.location.href = _url(); // Reload to make GUI reflect permissions; omitting create/edit/save/delete controls.
                }
            });
            return;
          case _errorCodes.db_general: // Database error.
            self.Message.set( self.local("error_db_general"), "error", {
                modal: true,
                close: function() {
                  window.location.href = _url();
                }
            });
            break;
          // default: Let action function handle the error, and optionally return false if it doesnt know that error code.
        }
      }
      if(_ajaxResponse.hasOwnProperty(action)) { // IE<9 wont like that, has no function.hasOwnProperty() method ;-)
        if(!_ajaxResponse[action](oResp)) {
          _errorHandler(null, oResp, _name + "._ajaxResponse." + action + "()");
          self.Message.set( self.local("error_unknown"), "error", {
              modal: true,
              close: function() {
                window.location.href = _url();
              }
          });
        }
      }
      else {
        _errorHandler(null, oResp, _name + "._ajaxResponse(), unsupported action[" + action + "]");
      }
    };
    /**
     * @ignore
     * @param {object} oResp
     * @return {boolean}
     */
    _ajaxResponse.filter_create = function(oResp) { // Only saves a default filter with a name; progress to edit mode on success.
      var nm = oResp.name;
      if(oResp.success) {
        _elements.filter.name_suggest.value = "";
        _elements.filter.origin.value = _.origin = _.name;
        _elements.filter.name.value = _.name = nm;
        _filters.push(nm);
        _setMode("edit");
        $(_elements.misc.title).html(nm + "<span> - " + oResp.description + "</span>");
        Judy.overlay(0);
        self.Message.set(self.local("savedNew", {"!filter": nm}));
      }
      else {
        switch(oResp.error_code) {
          case _errorCodes.filter_name_composition: // Invalid machine name.
            Judy.overlay(0);
            self.Message.set( self.local("error_machine_name_composition"), "warning", {
                modal: true,
                close: function() {
                  Judy.focus(_elements.filter.name_suggest);
                }
            });
            break;
          case _errorCodes.filter_name_nonunique: // Filter name already exists.
            Judy.overlay(0);
            self.Message.set( self.local("error_filter_name_nonunique", {"!name": nm}), "warning", {
                modal: true,
                close: function() {
                  Judy.focus(_elements.filter.name_suggest);
                }
            });
            break;
          default: // Unknown error code.
            return false;
        }
      }
      _ajaxRequestingBlocking = false;
      return true;
    };
    /**
     * @ignore
     * @param {object} oResp
     * @return {boolean}
     */
    _ajaxResponse.filter_edit = function(oResp) {
      var nm = oResp.name;
      if(oResp.success) {
        $("span", _elements.misc.title).html(" - " + oResp.description);
        Judy.overlay(0);
        self.Message.set(self.local("saved", {"!filter": nm}));
      }
      else if(oResp.error_code === _errorCodes.filter_doesnt_exist) {
        self.Message.set( self.local("error_filter_doesnt_exist", {"!name": nm}), "warning", {
            modal: true,
            close: function() {
              window.location.href = _url(); // Reload to make GUI reflect missing filter.
            }
        });
      }
      else if(oResp.error_code === _errorCodes.perm_filter_restricted) {
        self.Message.set( self.local("error_perm_filter_restricted"), "error", {
            modal: true,
            close: function() {
              window.location.href = _url(); // Reload to make get out of that situation.
            }
        });
      }
      else {
        return false;
      }
      _ajaxRequestingBlocking = false;
      return true;
    };
    /**
     * @ignore
     * @param {object} oResp
     * @return {boolean}
     */
    _ajaxResponse.list_logs = function(oResp) {
      var nm = oResp.name, conditions = oResp.log_list[1];
      if(oResp.success) {
        _listLogs(oResp.log_list[0], oResp.log_list[1], oResp.log_list[2], oResp.log_list[3]);
        //  Deleting logs is allowed when evenever the log list reflects the filter.
        if(_.deleteLogs_allowed &&
          // If wid condition, we list a single log (from url) and thus the list doesnt reflect current filter.
          (!conditions.wid || !conditions.hasOwnProperty('wid'))
        ) {
          Judy.enable(_elements.buttons.delete_logs_button, null, "");
        }
        Judy.overlay(0);
      }
      else {
        return false;
      }
      _ajaxRequestingBlocking = false;
      return true;
    };
    /**
     * @ignore
     * @param {object} oResp
     * @return {boolean}
     */
    _ajaxResponse.delete_logs = function(oResp) {
      if(oResp.success) {
        self.Message.set(self.local("deleteLogs_success", { "!number": oResp.delete_logs }), "notice", { noFade: false });
        _getLogList();
        return true;
      }
      else {
        return false;
      }
    };

    /**
     * Does nothing if no Inspect module (or no-action version of Inspect; user not allowed to use frontend instection).
     *
     * @function
     * @name LogFilter.inspect
     * @param {string|falsy} [prop]
     * @return {void}
     */
    this.inspect = function(prop) {
      if(typeof window.inspect === "function" && inspect.tcepsni === true) {
        inspect(!prop ? _ : _[prop], _name + (!prop ? "" : (" - " + prop)));
      }
    };
    /**
     * @function
     * @name LogFilter.inspectElements
     * @param {string|falsy} [group]
     * @return {void}
     */
    this.inspectElements = function(group) {
      if(typeof window.inspect === "function" && inspect.tcepsni === true) {
        inspect(!group ? _elements : _elements[group], "_elements" + (!group ? "" : ("." + group)));
      }
    };
    /**
     * Caches translated labels/message having no replacers.
     *
     * @function
     * @name LogFilter.local
     * @param {string} name
     * @param {object|falsy} [replacers]
     * @return {string}
     */
    this.local = function(name, replacers) {
      var nm = name, s;
      //  S.... Drupal.t() doesnt use the 'g' flag when replace()'ing, so Drupal.t() replacement is utterly useless - and nowhere to report the bug :-(
      if(!(s = _oGet(_local, nm))) {
        switch(nm) {
          case "default":
            _local[nm] = s = Drupal.t("Default");
            break;
          case "adhoc":
            _local[nm] = s = Drupal.t("Ad hoc");
            break;
          case "adhocForOrigin":
            //  {"!origin": nm}
            s = Drupal.t("Ad hoc - based on !origin", replacers );
            break;
          case "newForOrigin":
            //  {"!origin": nm}
            s = Drupal.t("New - based on !origin", replacers );
            break;
          case "newTitle":
            _local[nm] = s = Drupal.t("New");
            break;
          case "newName":
            _local[nm] = s = Drupal.t("new");
            break;
          case "savedNew":
            //  { "!filter": name }
            s = Drupal.t("Saved new filter '!filter'.", replacers);
            break;
          case "saved":
            //  { "!filter": name }
            s = Drupal.t("Saved filter '!filter'.", replacers);
            break;
          case "confirmDelete":
            //  { "!filter": _elements.filter.name.value }
            s = Drupal.t("Are you sure you want to delete the filter!newline!filter?", replacers);
            break;
          case "invalid_date":
            //  {"!date": v, "!format": _.dateFormat}
            s = Drupal.t("The date '!date' is not valid!newline- please use the format: !format", replacers);
            break;
          case "invalid_timeSequence_from":
            _local[nm] = s = Drupal.t("'From' time cannot be later than 'To' time.");
            break;
          case "invalid_timeSequence_to":
            _local[nm] = s = Drupal.t("'To' time cannot be earlier than 'From' time.");
            break;
          case "invalid_uid":
            _local[nm] = s = Drupal.t("User ID must be a positive number, or empty.");
            break;
          case "invalid_location":
            _local[nm] = s = Drupal.t("Requested URL must be a URL, or empty.");
            break;
          case "invalid_referer":
            _local[nm] = s = Drupal.t("Referrer URL must be a URL, 'none', or empty.");
            break;
          case "error_machine_name_composition":
            //  { "!illegals": "default, adhoc" }
            s = Drupal.t("The filter name:!newline- must be 2 to 32 characters long!newline- must only consist of the characters a-z, letters, and underscore (_)!newline- cannot start with a number!newline- cannot be: !illegals", replacers);
            break;
          case "error_filter_name_nonunique":
            //  {"!name": name}
            s = Drupal.t("There's already a filter named!newline'!name'.!newlineDo you want to overwrite that filter?", replacers);
            break;
          case "error_filter_doesnt_exist":
            //  {"!name": name}
            s = Drupal.t("There's no filter named!newline'!name'.", replacers);
            break;
          case "wait":
            _local[nm] = s = Drupal.t("Please wait a sec...");
            break;
          case "wait_create":
            _local[nm] = s = Drupal.t("Creating new filter. Please wait a sec...");
            break;
          case "wait_ereate":
            _local[nm] = s = Drupal.t("Saving filter changes. Please wait a sec...");
            break;
          case "deleteLogs_prohibit":
            _local[nm] = s = Drupal.t("Only allowed when the log list is freshly updated,!newlinereflecting current filter - press the 'Update list' button.");
            break;
          case "deleteLogs_all":
            _local[nm] = s = Drupal.t("Do you want to delete!newlineALL logs?");
            break;
          case "deleteLogs_noMax":
            //  {"!offset": offset}
            s = Drupal.t("Do you want to delete!newlineALL logs after event no. !offset?", replacers);
            break;
          case "deleteLogs_noOffset":
            //  {"!max": max}
            s = Drupal.t("Do you want to delete logs!newlinewithout ANY condition!newlineexcept limited by a maximum of !max?", replacers);
            break;
          case "deleteLogs_noConditions":
            //  {"!offset": offset, "!max": max}
            s = Drupal.t("Do you want to delete logs after event no. !offset!newlinewithout ANY condition!newlineexcept limited by a maximum of !max?", replacers);
            break;
          case "deleteLogs_storedAll":
            //  {"!name": name}
            s = Drupal.t("Do you want to delete all logs matching!newlinethe '!name' filter!newlinelimited by NO maximum?", replacers);
            break;
          case "deleteLogs_storedNoMax":
            //  {"!offset": offset, !name": name}
            s = Drupal.t("Do you want to delete all logs matching!newlinethe '!name' filter!newlineafter matching event no. !offset!newlinelimited by NO maximum?", replacers);
            break;
          case "deleteLogs_storedNoOffset":
            //  {"!offset": offset, !name": name}
            s = Drupal.t("Do you want to delete all logs matching!newlinethe '!name' filter!newlineexcept limited by a maximum of !max?", replacers);
            break;
          case "deleteLogs_stored":
            //  {"!offset": offset, "!max": max, "!name": name}
            s = Drupal.t("Do you want to delete all logs matching!newlinethe '!name' filter!newlineafter matching event no. !offset!newlinelimited by a maximum of !max?", replacers);
            break;
          case "deleteLogs_adhocAll":
            _local[nm] = s = Drupal.t("Do you want to delete all logs!newlinematching current ad hoc filter!newlinelimited by NO maximum?");
            break;
          case "deleteLogs_adhocNoMax":
            //  {"!offset": offset}
            s = Drupal.t("Do you want to delete all logs!newlinematching current ad hoc filter!newlineafter matching event no. !offset!newlinelimited by NO maximum?", replacers);
            break;
          case "deleteLogs_adhocNoOffset":
            //  {"!max": max}
            s = Drupal.t("Do you want to delete all logs!newlinematching current ad hoc filter!newlineexcept limited by a maximum of !max?", replacers);
            break;
          case "deleteLogs_adhoc":
            //  {"!offset": offset, "!max": max}
            s = Drupal.t("Do you want to delete all logs!newlinematching current ad hoc filter!newlineafter matching event no. !offset!newlinelimited by a maximum of !max?", replacers);
            break;
          case "deleteLogs_success":
            //  {"!number": integer}
            s = Drupal.t("Deleted !number log events.", replacers);
            break;
          case "error_form_expired":
            //  {"!url": url}
            s = Drupal.t("The form has become outdated!newline- please <a href=\"!url\">reload this page</a>.", replacers);
            break;
          case "error_perm_filter_crud":
            _local[nm] = s = Drupal.t("Sorry, you're not allowed to edit saveable filters.");
            break;
          case "error_perm_filter_restricted":
            _local[nm] = s = Drupal.t("You're not allowed to use that filter.");
            break;
          case "error_db_general":
            _local[nm] = s = Drupal.t("Sorry, failed to save data.");
            break;
          case "error_unknown":
            _local[nm] = s = Drupal.t("Sorry, something unexpected happened.");
            break;
          case "emergency":
            _local[nm] = s = Drupal.t("emergency");
            break;
          case "alert":
            _local[nm] = s = Drupal.t("alert");
            break;
          case "critical":
            _local[nm] = s = Drupal.t("critical");
            break;
          case "error":
            _local[nm] = s = Drupal.t("error");
            break;
          case "warning":
            _local[nm] = s = Drupal.t("warning");
            break;
          case "notice":
            _local[nm] = s = Drupal.t("notice");
            break;
          case "info":
            _local[nm] = s = Drupal.t("info");
            break;
          case "debug":
            _local[nm] = s = Drupal.t("debug");
            break;
          case "anonymous_user":
            _local[nm] = s = Drupal.t("anonymous");
            break;
          case "deleted_user":
            _local[nm] = s = Drupal.t("deleted");
            break;
          case "log_event":
            _local[nm] = s = Drupal.t("Event");
            break;
          case "log_severity":
            _local[nm] = s = Drupal.t("Severity");
            break;
          case "log_type":
            _local[nm] = s = Drupal.t("Type");
            break;
          case "log_time":
            _local[nm] = s = Drupal.t("Time");
            break;
          case "log_time_from":
            _local[nm] = s = Drupal.t("Time From");
            break;
          case "log_time_to":
            _local[nm] = s = Drupal.t("Time To");
            break;
          case "log_user":
          case "log_uid":
            _local[nm] = s = Drupal.t("User");
            break;
          case "log_location":
            _local[nm] = s = Drupal.t("Location");
            break;
          case "log_referer":
            _local[nm] = s = Drupal.t("Referrer");
            break;
          case "log_hostname":
            _local[nm] = s = Drupal.t("Hostname");
            break;
          case "log_message":
            _local[nm] = s = Drupal.t("Message");
            break;
          case "log_link":
            _local[nm] = s = Drupal.t("Link");
            break;
          case "eventItem_display":
            //  {"!logId": integer}
            s = Drupal.t("Event !logId", replacers);
            break;
          case "eventItemHover_filter":
            //  {"!logId": logId, '!filter': filter }
            s = Drupal.t("Event !logId - press F key (or right-click) to filter !filter", replacers);
            break;
          case "eventItemHover_severity":
            //  {"!logId": logId, '!severity': severity}
            s = Drupal.t("Event !logId (!severity) - press F key (or right-click) to filter Severity", replacers);
            break;
          case "eventItemHover_time":
            //  {"!logId": logId }
            s = Drupal.t("Event !logId!newline - press F key (or right-click) to filter Time From!newline - press shift+F to filter Time To", replacers);
            break;
          case "eventItemHover_user":
            //  {"!logId": logId, '!uid': uid}
            s = Drupal.t("Event !logId (user !uid) - press F key (or right-click) to filter User", replacers);
            break;
          case "filtered_event_column":
            //  {"!logId": logId, '!value': value }
            s = Drupal.t("Filter !column by '!value'.", replacers);
            break;
          case "event_link":
            _local[nm] = s = Drupal.t("Link to this log event");
            break;
          case "no_event_matches":
            _local[nm] = s = Drupal.t("The current filter matches no events.");
            break;
          case "non_existing_event":
            //  {"!number": integer}
            s = Drupal.t("Event ID !number doesn't exist.", replacers);
            break;
          case "event_from_url":
            //  {"!number": integer}
            s = Drupal.t("Listing event ID !number, according to URL. Press 'Update list' button to reflect current filter.", replacers);
            break;
          case "add_type_item":
            _local[nm] = s = Drupal.t("Add type...");
            break;
          case "type_option_dupe":
            //  {"!option": string}
            s = Drupal.t("Type !option already exists.", replacers);
            break;
          case "pager_current":
            //  { '!first': (offset + 1), '!last': (offset + le), '!total': nTotal }
            s = Drupal.t("!first-!last of !total", replacers);
            break;
          case "pager_current_none":
            _local[nm] = s = Drupal.t("None");
            break;
          case "pager_current_outofrange":
            //  { '!offset': offset, '!total': nTotal }
            s = Drupal.t("None after !offset, of !total", replacers);
            break;
          case "library_judy_incompatible":
            //  { '!version': version }
            s = Drupal.t("Log Filter doesn't work without the Judy library, version !version or newer.", replacers);
            break;
          default:
            s = "[LOCAL: " + nm + "]";
        }
      }
      return s.replace(/\!newline/g, "\n");
    };

    /**
     * For querying backend.
     *
     * Must be called delayed (after displaying overlay) to secure that validation (set-up in _prepareForm()) has done it's job.
     *
     * @function
     * @name LogFilter.getCriteria
     * @return {object}
     */
    this.getCriteria = function() {
      var n = 0, conditions = {}, order_by = [], oElms = _elements.conditions, nm, r, v, le, i;
      try {
        //  Rely on validation set-up in _prepareForm(), dont do the same thing once over.
        for(nm in oElms) {
          if(oElms.hasOwnProperty(nm)) {
            r = oElms[nm];
            switch(nm) {
              case "time_from_proxy":
              case "time_to_proxy":
              case "time_from_time":
              case "time_to_time":
                break;
              case "time_range":
              case "time_from":
              case "time_to":
              case "uid":
                if((v = r.value) !== "" && (v = $.trim(v)).length && (v = parseInt(v, 10)) > -1) {
                  ++n;
                  conditions[nm] = v;
                }
                break;
              case "username":
                // Skip, we use uid instead.
                break;
              case "role":
                if((v = Judy.fieldValue(r)) !== "" && v !== "_none" && (v = $.trim(v)) && (v = parseInt(v, 10))) {
                  ++n;
                  conditions[nm] = v;
                }
                break;
              case "severity_any":
              case "type_any":
              case "type_proxy":
                //  Check at severity_some/type_some instead.
                break;
              case "severity_some":
                if(!oElms.severity_any.checked) {
                  v = [];
                  le = r.length;
                  for(i = 0; i < le; i++) {
                    if(r[i].checked) {
                      v.push(r[i].value);
                    }
                  }
                  if(v.length) {
                    ++n;
                    conditions.severity = v;
                  }
                }
                break;
              case "type_some":
                if((v = r.value) !== "" && (v = $.trim(v))) {
                  ++n;
                  conditions.type = v.split(/\n/);
                }
                break;
              case "hostname":
              case "location":
              case "referer":
                if((v = r.value) !== "" && (v = $.trim(v)) && v !== '*') {
                  ++n;
                  conditions[nm] = v;
                }
                break;
              default:
                throw new Error("Condition[" + nm + "] not supported.");
            }
          }
        }
        le = (oElms = _elements.orderBy).length;
        for(i = 0; i < le; i++) {
          if((v = Judy.fieldValue(oElms[i][0])) && v !== "_none" && (v = $.trim(v))) {
            order_by.push([
              v,
              oElms[i][1].checked ? "DESC" : "ASC"
            ]);
          }
        }
      }
      catch(er) {
        _errorHandler(er, 0, _name + ".getCriteria()");
      }
      return {
        nConditions: n,
        conditions: conditions,
        order_by: order_by
      };
    };

    /**
     * Singleton, instantiated to itself.
     * @constructor
     * @namespace
     * @name LogFilter.Message
     * @singleton
     */
    this.Message = function() {
      var _self = this,
      _n = -1,
      _htmlList = "<div id=\"log_filter__message\"><div><div id=\"log_filter__message_list\"></div></div></div>",
      _htmlItem = "<div id=\"log_filter__message___NO__\" class=\"log-filter-message-__TYPE__\"><div class=\"log-filter--message-content\"><span>__CONTENT__</span></div><div title=\"" +
          Drupal.t("Close") + "\">x</div></div>",
      _list,
      _faders = {},
      /**
      * @function
      * @name LogFilter.Message._close
      * @return {void}
      */
      _close = function() {
        $(this.parentNode).hide();
      },
      /**
      * Message item fader.
      *
      * Not prototypal because the 'this' of prototypal methods as event handlers is masked by jQuery's element 'this' (or for inline handlers the global window 'this').
      * Could use prototypal methods if we passed the the 'this' of the fader to jQuery handlers, but that would result in lots of references to the fader object (and probably more overall overhead).
      *
      * @constructor
      * @class
      * @name LogFilter.Message._fader
      * @param {string} selector
      * @param {integer|float|falsy} [delay]
      *  - default: 3000 (milliseconds)
      *  - if less than 1000 it will be used as multiplier against the default delay
      */
      _fader = function(selector, delay) {
        var __self = this,
        /**
        * Default delay.
        *
        * @name LogFilter.Message._fader#_delayDefault
        * @type integer
        */
        _delayDefault = 3000,
        /**
        * Interval setting.
        *
        * @name LogFilter.Message._fader#_pause
        * @type integer
        */
        _pause = 150, // Milliseconds.
        /**
        * Opacity decrease factor setting.
        *
        * @name LogFilter.Message._fader#_factor
        * @type float
        */
        _factor = 1.2,
        /**
        * State.
        *
        * @name LogFilter.Message._fader#_stopped
        * @type boolean
        */
        _stopped,
        /**
        * @name LogFilter.Message._fader#_opacity
        * @type integer
        */
        _opacity = 100,
        /**
        * @name LogFilter.Message._fader#_subtractor
        * @type integer
        */
        _subtractor = 1,
        /**
        * @function
        * @name LogFilter.Message._fader#_start
        * @return {void}
        */
        _start = function() {
          /** @ignore */
          __self._interval = setInterval(_fade, _pause)
        },
        /**
        * @function
        * @name LogFilter.Message._fader#_fade
        * @return {void}
        */
        _fade = function() {
          var n = _opacity, jq = __self._jq;
          if(!_stopped) {
            if((_opacity = (n -= (_subtractor *= _factor))) > 0) {
              if(Judy.browserIE < 11) {
                jq.css("opacity", n / 100);
              }
              else {
                jq.css({
                  "-ms-filter": "progid:DXImageTransform.Microsoft.Alpha(Opacity=" + (n = Math.round(n)) + ")",
                  filter: "alpha(opacity=" + n + ")"
                });
              }
            }
            else {
              _stopped = true;
              clearInterval(__self._interval);
              jq.hide();
            }
          }
        },
        /** @ignore */
        jq;
        /**
        * @function
        * @name LogFilter.Message._fader#stop
        * @return {void}
        */
        this.stop = function() {
          if(!_stopped) {
            _stopped = true;
            clearTimeout(__self._timeout);
            clearInterval(__self._interval);
          }
        };
        /**
        * @function
        * @name LogFilter.Message._fader#unfade
        * @return {void}
        */
        this.unfade = function() {
          __self.stop();
          if(_opacity < 100) {
            if(Judy.browserIE < 11) {
              __self._jq.css("opacity", 1);
            }
            else {
              __self._jq.css({
                "-ms-filter": "progid:DXImageTransform.Microsoft.Alpha(Opacity=100)",
                filter: "alpha(opacity=100)"
              });
            }
          }
        };
        /**
        * @function
        * @name LogFilter.Message._fader#destroy
        * @return {void}
        */
        this.destroy = function() {
          __self.stop();
          delete __self._jq;
        };
        //  Construction logics.
        if((jq = $(selector)).get(0)) {
          /**
          * @name LogFilter.Message._fader#_jq
          * @type jquery
          */
          this._jq = jq;
          /** @ignore */
          this._timeout = setTimeout(
              _start,
              !delay ? _delayDefault : (delay < 1000 ? Math.floor(delay * _delayDefault) : _delayDefault)
          );
        }
      };
      /**
      * @function
      * @name LogFilter.Message.setup
      * @return {void}
      */
      this.setup = function() {
        var elm, jq;
        if((elm = document.getElementById("console"))) {
          $(elm).after(_htmlList);
        }
        else {
          $("#content").prepend(_htmlList);
        }
        _list = document.getElementById("log_filter__message_list");
        //  Draggable.
        if((jq = $(_list)).draggable) {
          jq.draggable({ handle: "div.log-filter--message-content", cancel: "span", cursor: "move" });
        }
      };
      /**
      * @function
      * @name LogFilter.Message.set
      * @param {mixed} txt
      * @param {string} [type]
      *  - default: 'status'
      *  - values: 'status' | 'info' |  'notice' |  'warning' | 'error'
      * @param {object} [options]
      *  - (boolean) noFade: default false ~ a 'status' or 'info' message will eventually fade away, unless clicked/mousedowned
      *  - (number) fadeDelay: default zero ~ use default delay before starting fade ('status' message only)
      *  - (number) fadeDelay: >1000 ~ use that delay | < 1000 multiply default delay with that number (both 'status' message only)
      *  - (boolean) modal: default false ~ do not display blocking overlay
      *  - (function) close: function to execute upon click on close button
      * @param {integer} [delay]
      *  - default: 4000 (milliseconds)
      * @return {void}
      */
      this.set = function(txt, type, options) {
        var t = type || "status", s, f, k, jq, o = {
          noFade: true,
          fadeDelay: 0,
          modal: false,
          close: null
        };
        switch(t) {
          case "status":
          case "info":
            o.noFade = false;
            break;
          case "notice":
          case "warning":
            break;
          default:
            t = "error";
        }
        if(options) {
          for(k in o) {
            if(o.hasOwnProperty(k) && options.hasOwnProperty(k)) {
              o[k] = options[k];
            }
          }
        }
        //  Add message to DOM.
        $(_list).prepend(
          _htmlItem.replace(/__NO__/, ++_n).replace(/__TYPE__/, t).replace(/__CONTENT__/, txt ? txt.replace(/\n/g, "<br/>") : "")
        );
        //  Close behaviours.
        (jq = $((s = "#log_filter__message_" + _n) + " > div:last-child")).click(_close);
        //  If modal, show overlay.
        if(o.modal) {
          jq.click(Judy.overlay); // And hide it on close click.
          Judy.overlay(1, true); // Opaque, no hover title.
        }
        //  Close function.
        if(o.close) {
          jq.click(o.close);
        }
        //  If to be fading, make click on message content unfade the message.
        if(!o.noFade) {
          _faders[ "_" + _n ] = f = new _fader(s, o.fadeDelay);
          $(s + " > div:first-child").bind("click mousedown", f.unfade); // And mousedown, otherwise dragging wont prevent fade.
        }
        //  Display the message.
        $(s).show();
      };
      /**
      * @function
      * @name LogFilter.Message.showAll
      * @return {void}
      */
      this.showAll = function() {
        var le = _n + 1, i, f;
        for(i = 0; i < le; i++) {
          if((f = _faders[ "_" + i ]) && _faders.hasOwnProperty("_" + i)) {
            f.unfade();
          }
          $("#log_filter__message_" + i).show();
        }
      };
    };

    /**
     * @param {integer|falsy|string} logId
     * @return {void}
     */
    this.displayLog = function(logId) {
      var o, s, v, css = 'log-filter-log-display', dialId = 'log_filter_logDisplay_' + logId, elm, $dialOuter, dialInner;
      if ((o = _logs['_' + logId]) && _logs.hasOwnProperty('_' + logId)) {
        // If already open: close the dialog.
        if ((elm = document.getElementById(dialId))) {
          $('#log_filter_list_log_' + logId).removeClass('log-filter-list-displayed');
          Judy.dialog(dialId, "close");
        }
        else {
          $('#log_filter_list_log_' + logId).addClass('log-filter-list-displayed');
          o = _logs['_' + logId];
          s = '<div class="' + css + '">' +
              '<table class="dblog-event"><tbody>' +
              '<tr class="odd"><th>' + self.local('log_severity') + '</th>' +
                '<td>' + (v = o.severity_string) + '<div class="' + css + '-severity ' + css + '-' + v + '">&#160;</div></td></tr>' +
              '<tr class="even"><th>' + self.local('log_type') + '</th><td>' + o.type + '</td></tr>' +
              '<tr class="odd"><th>' + self.local('log_time') + '</th><td>' + o.time + '</td></tr>' +
              '<tr class="even"><th>' + self.local('log_user') + '</th>' +
                '<td>' + (!o.uid ? o.name : ('<a href="/user/' + o.uid + '" title="' + o.uid + '">(' + o.uid + ') ' + o.name + '</a>')) +
                ' &#160; &bull; &#160; ' + self.local('log_hostname') + ': ' + o.hostname + '</td></tr>' +
              '<tr class="odd"><th>' + self.local('log_location') + '</th><td><a href="' + o.location + '">' + o.location + '</a></td></tr>' +
              '<tr class="even"><th>' + self.local('log_referer') + '</th>' +
                '<td>' + (!o.referer ? '&#160;' : ('<a href="' + o.referer + '">' + o.referer + '</a>')) + '</td></tr>' +
              '<tr class="odd"><th>' + self.local('log_message') + '</th><td>' + o.message + '</td></tr>' +
              (!o.link ? '' : ('<tr class="even"><th>' + self.local('log_link') + '</th><td><a href="' + o.link + '">' + o.link + '</a></td></tr>')) +
              '</tbody></table>' +
            '</div>';
          Judy.dialog(dialId, {
            title: '<a href="' + _url() + '/' + o.wid + '" title="' + self.local('event_link') + '">' + self.local('log_event') + ': ' + o.wid + '</a>',
            content: s,
            fixed: true,
            resizable: false,
            closeOnEscape: false, // Set behaviour that closes all log filter dialogs on escape, disregarding current focus.
            dialogClass: "log-filter-log-display-dialog",
            contentClass: "log-filter-log-display-content",
            autoOpen: false,
            close: function(event, ui) {
              setTimeout(function() {
                $('#log_filter_logDisplay_' + logId).dialog('destroy').remove();
                $('#log_filter_list_log_' + logId).removeClass('log-filter-list-displayed');
              });
            }
          });
          ($dialOuter = $( (dialInner = $('#' + dialId).get(0)).parentNode )).css({
            visibility: 'hidden',
            overflow: 'visible'
          });
          Judy.dialog(dialId, "open");
          Judy.outerWidth($dialOuter, true, Judy.innerWidth(window) - 200, 2);
          Judy.outerHeight('#' + dialId, true,
            Judy.outerHeight($dialOuter, true, Judy.outerHeight(window) - 10, 1) -
              Judy.outerHeight($('div.ui-dialog-titlebar', $dialOuter)) -
              Math.ceil(parseFloat($dialOuter.css("padding-top")) + parseFloat($dialOuter.css("padding-bottom"))) -
              _.adminOverlayOffset,
            1
          );

          $dialOuter.css({
            visibility: 'visible',
            left: '150px', // jQuery UI dialog position apparantly doesnt work well when css position is fixed.
            top: (4 + _.adminOverlayOffset) + 'px'
          });

          // Apply behaviours (if any).
          Drupal.attachBehaviors($dialOuter.get(0));
        }
      }
    };

    /**
     * Called before page load.
     *
     * @function
     * @name LogFilter.init
     * @param {boolean|integer} useModuleCss
     * @param {string} theme
     * @return {void}
     */
    this.init = function(useModuleCss, theme) {
      var v;
      /** @ignore */
      self.init = function() {};

      // Make sure Judy exists and is version 2.0+.
      if (typeof window.Judy !== 'object' || !(v = Judy.version) || Judy.version < _.library_judy_version) {
        _.library_judy_compatible = false;
        return;
      }

      //  Tell styles about theme.
      if((_.useModuleCss = useModuleCss)) {
        $("div#page").addClass("theme-" + theme);
      }
      //	Set overlay, to prevent user from doing anything before page load and after form submission.
      Judy.overlay(1, false, self.local("wait"));
    };
    /**
     * Called upon page load.
     *
     * @function
     * @name LogFilter.setup
     * @param {object} [filters]
     * @param {array} [messages]
     * @return {void}
     */
    this.setup = function(filters, messages) {
      var a = messages, le, i, o = { fadeDelay: 2 }, url, wid; // Long (double) delay when at page load.
      /** @ignore */
      self.setup = function() {};
      _filters = filters || [];

      if (!_.library_judy_compatible) {
        alert(self.local('library_judy_incompatible', { '!version': _.library_judy_version }));
        return;
      }

      _prepareForm();
      _setMode(_.mode, false, true);

      //  Display messages, if any.
      (self.Message = new self.Message()).setup();
      if(a) {
        le = a.length;
        //  Check if any message isnt of type status; status message should fade, unless there's another message of a different (more urgent) type.
        for(i = 0; i < le; i++) {
          if(a[i][1] && a[i][1] !== "status") {
            o.noFade = true;
            break;
          }
        }
        for(i = 0; i < le; i++) {
          self.Message.set(a[i][0], a[i][1], o);
        }
      }

      // Set title attribute of all labels containing a span that has a non-empty title attribute.
      $('label > span[title]').each(function() {
        var t = this.getAttribute('title');
        if (t) {
          this.parentNode.setAttribute('title', t);
        }
      });

      // Check if administrative Overlay is on.
      if (!/^#overlay=admin\//.test(top.location.hash)) {
        url = window.location.href;
        _.adminOverlayOffset = 0;
      }
      else {
        url = top.location.href + top.location.hash;
      }

      //  Prepare log list.
      _getLogList(
        // Check if url ends with /integer ~ single log view.
        /^.+\/(\d+)\/?$/.test(url) && (wid = parseInt(url.replace(/^.+\/(\d+)\/?$/, '$1'), 10)) &&
          wid <= Math.pow(2, 31) ? wid : 0
      );

      // Make all event dialogs close on escape, and no matter what has focus.
      Judy.keydown(document.documentElement, "escape", function() {
        $('div.log-filter-log-display-content').each(function() {
          $(this).dialog("close");
        });
      });

      Judy.overlay(0);
    };
  }
  window.LogFilter = new LogFilter($);

})(jQuery);
