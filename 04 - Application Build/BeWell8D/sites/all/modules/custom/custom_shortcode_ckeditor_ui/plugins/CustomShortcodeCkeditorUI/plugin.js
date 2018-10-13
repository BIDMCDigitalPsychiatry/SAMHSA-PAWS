(function ($) {
  $(document).ready( function( evt ) {
    CKEDITOR.plugins.add( 'CustomShortcodeCkeditorUI', {
      icons: 'CustomShortcodeCkeditorUI',
      init: function( editor ) {
          
          editor.addCommand( 'CustomShortcodeCkeditorUIDialog', new CKEDITOR.dialogCommand( 'CustomShortcodeCkeditorUIDialog' ) );
          
          editor.ui.addButton( 'CustomShortcodeCkeditorUI', {
              label: 'Insert Shortcode',
              command: 'CustomShortcodeCkeditorUIDialog',
              toolbar: 'insert'
          });
    
          CKEDITOR.dialog.add( 'CustomShortcodeCkeditorUIDialog', this.path + 'dialogs/CustomShortcodeCkeditorUIDialog.js' );
      
      }
    });
  });
})(jQuery);
