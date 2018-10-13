(function ($) {
  // Hide fieldsets unless one of their fields is visible compatible with field groups.
  $(document).bind('state:visible', function(e) {
    if (e.trigger) {
      //Hide Fieldset Wrappers
      var $wrapper = $(e.target).closest('.fieldset-wrapper');
      if ($wrapper.length) {
        var fieldsets = $wrapper.closest('fieldset');
        fieldsets.each(function () {
          var button;
          var countHidden;
          var fieldset = $(this);
          var parentIndex = fieldset.index();
          var fswrapper = fieldset.children('.fieldset-wrapper');
          var fswrapperl = fswrapper.children().length;
          if ($(this).hasClass('horizontal-tabs-pane')) {
            /* Hide Horizontal Tabs and their buttons */
            button = fieldset.parent().prev().children('.horizontal-tab-button-'+parentIndex);
            countHidden = cjs_hef_CheckChildren(fswrapper);
            if(countHidden === fswrapperl) { 
              button.hide();
              fieldset.hide();
            } else {
              button.show();
              fieldset.show();
            }
          } else if ($(this).hasClass('vertical-tabs-pane')) {
            /* Hide Vertical Tabs */
            button = fieldset.parent().prev().children(':eq('+(parentIndex-1)+')');
            countHidden = cjs_hef_CheckChildren(fswrapper);
            if(countHidden === fswrapperl) { 
              button.hide();
              fieldset.hide();
            } else {
              button.show();
              //fieldset.show();
            }
          } else {
            /* Hide Basic Fieldsets */
            countHidden = cjs_hef_CheckChildren(fswrapper);
            if(countHidden === fswrapperl) { 
              fieldset.hide();
            } else {
              fieldset.show();
            }
          }
        });
      }
    }
  });
  
  // HELPER FUNCTIONS
  function cjs_hef_CheckChildren(fswrapper) {
    var countHidden = 0;
    fswrapper.children().each(function (cindex, cel) {
      if ($(this).css('display') === 'none') {
        countHidden++;
      }
    });
    return countHidden;
  }
  
})(jQuery);