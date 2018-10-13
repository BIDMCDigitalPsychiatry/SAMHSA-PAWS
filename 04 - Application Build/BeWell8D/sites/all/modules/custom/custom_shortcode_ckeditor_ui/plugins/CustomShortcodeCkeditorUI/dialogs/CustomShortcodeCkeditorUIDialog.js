'use strict';

(function ($) {
  var text;
  CKEDITOR.dialog.add( 'CustomShortcodeCkeditorUIDialog', function( editor ) {
    // Return the dialog definition
    return {
      title: 'Insert Shortcode',
      minWidth: 400,
      minHeight: 400,
      contents: [
        {
          id: 'shortcodes',
          label: 'Shortcodes',
          elements: [
            {
              type: 'html',
              html: '<div id="custom-shortcode-ckeditor-ui-body"></div>'
            }
          ]
        }
      ],
      buttons: [
        CKEDITOR.dialog.cancelButton,
        CKEDITOR.dialog.okButton
      ],
      onShow: function() {
        // Get the current selected text.
        text = getSelectionHtml(editor);
        var currentInstanceName = CKEDITOR.currentInstance.name;
        var currentFormatter = $('#'+currentInstanceName.replace('value','format'));
            currentFormatter = currentFormatter.find('select').val();
        // Location, where to fetch the dialog.
        var aurl = Drupal.settings.basePath + 'index.php?q=custom_shortcode_ckeditor_ui/'+currentFormatter+'/_none';
        var tmpdiv = $('<div id="custom-shortcode-ckeditor-ui-body"></div>');
        // Ajax Load the form from drupal
        tmpdiv.load(aurl, function () {
          
          var dialog = CKEDITOR.dialog.getCurrent();
          dialog.parts.dialog.setStyles({
            position : 'absolute'
          });
          dialog = $(dialog.parts.contents.$);
          var scBody = dialog.find('#custom-shortcode-ckeditor-ui-body'),
              shortcodeForm = $(this).find('#custom-shortcode-ckeditor-ui-form');
                        
          // Set the dialog for content
          shortcodeForm = shortcodeForm.get(0).outerHTML;
          scBody.html(shortcodeForm);    
          
          //Form JS
          var shortcodeForm = scBody.find('#custom-shortcode-ckeditor-ui-form'),
              shortcodeSelect = scBody.find('.custom-shortcode-ckeditor-ui-selector'),
              shortcodeSelectFieldset = '_none',
              shortcodeFieldsets = scBody.find('fieldset'),
              formfields = scBody.find('input, select, textarea');
          
          //Empty Form Fields
          $('.cke_button__customshortcodeckeditorui').on('click', function() {
            formfields.val(null);
            shortcodeSelect.val('_none');
            shortcodeFieldsets.css({
              'visibility' : 'hidden',
              'display' : 'none',
            });
          });
          
          //Detect when the shortcode selector changes
          shortcodeSelect.change(function(event) {
            shortcodeSelectFieldset = '#edit-'+$(this).val().replace(/_/g, "-");
            shortcodeFieldsets.css({
              'visibility' : 'hidden',
              'display' : 'none',
            });
            $('fieldset'+shortcodeSelectFieldset).css({
              'visibility' : 'visible',
              'display' : 'block',
            });
          });
        });
      },
      onOk: function() {
        var dialog = CKEDITOR.dialog.getCurrent();
            dialog = $(dialog.parts.contents.$);
        var scBody = dialog.find('#custom-shortcode-ckeditor-ui-body');
        
        var shortcodeSelect = scBody.find('.custom-shortcode-ckeditor-ui-selector');
        var shortcode = shortcodeSelect.val();
        var options = [];
        
        var shortcodeSelectFieldset = '#edit-'+shortcode.replace(/_/g, "-");
        var curShortcode = scBody.find('fieldset'+shortcodeSelectFieldset).find('input,select,textarea');
        //Iterate through the current shortcodes values.
        curShortcode.each(function () {
          var $this = $(this), name = $this.attr('name'), val = '', params;
          // This allows a form field for text and not assuming the user selected the
          // text that will need to be wrapped
          if(name == 'text' && val.length) {
            text = $this.val();
          }
          // Encode textarea content to avoid breakage and obscure dangerous markup.
          // Any shortcodes that use textarea form elements will need to urldecode the
          // results.
          else if ($this.is('textarea')) {
            val = encodeURIComponent($this.val());
          }
          // For radio buttons and checkboxes, only get the value if selected
          else if (val.length && (($this.attr('type') == 'radio' || $this.attr('type') == 'checkbox') && $this.is(':checked')) || ($this.attr('type') != 'radio' && $this.attr('type') != 'checkbox')) {
            val = $this.val();
          }
          // Strip the shortcode prefix from the attribute.
          name = name.replace(shortcode + '-', '');
          // Offer an opportunity for any other modules to alter the value
          // before it's put into the shortcode
          params = {
            element: this,
            shortcode: shortcode,
            name: name,
            value: val
          };
          $(document).trigger('shortcodeWYSIWYG.optionValueAlter', params);
          // Save the option for use in the shortcode that is rendered to
          // the WYSIWYG
          val = params.value;
          if (val.length) {
            options.push(name + '="' + val + '"');
          }
        });
        // Check if we have a hidden field with custom code.
        if( $('#edit-custom').length ) {
          shortcode = $('#edit-custom').val();
        } else {
          shortcode = '[' + shortcode + (options.length ? ' ' + options.join(' ') : '') + ']' + text + '[/' + shortcode + ']';
        }
        editor.insertHtml(shortcode);
      }
    };
    
  });
  
  function getSelectionHtml(editor) {
    var sel = editor.getSelection();
    var ranges = sel.getRanges();
    var el = new CKEDITOR.dom.element("div");
    for (var i = 0, len = ranges.length; i < len; ++i) {
      el.append(ranges[i].cloneContents());
    }
    return el.getHtml();
  }
})(jQuery);

