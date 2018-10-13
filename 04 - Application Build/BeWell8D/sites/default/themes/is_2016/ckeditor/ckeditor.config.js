/*
---------INFORMATICS CUSTOM WYSISYG SETTINGS------------
*/
CKEDITOR.on('dialogDefinition', function( ev ) {
  var dialogName = ev.data.name;
  var dialogDefinition = ev.data.definition;
  
  // CUSTOM CKEDITOR SHORTCODE DIALOG
  if (dialogName === 'CustomShortcodeCkeditorUIDialog') {
    //console.log(dialogDefinition);
    dialogDefinition.dialog.parts.dialog.setStyles({
      position : 'absolute'
    });
  }

  // TABLE SETTINGS
  if(dialogName === 'table') {
    var infoTab = dialogDefinition.getContents('info');
    var cellSpacing = infoTab.get('txtCellSpace');
    cellSpacing['default'] = "0";
    var cellPadding = infoTab.get('txtCellPad');
    cellPadding['default'] = "0";
    var border = infoTab.get('txtBorder');
    border['default'] = "0";
    var txtWidth = infoTab.get('txtWidth');
    txtWidth['default'] = "";
  }

  // IMAGE SETTINGS
  if (dialogName == 'image') {
    var infoTab = dialogDefinition.getContents( 'info' );
    infoTab.remove( 'txtBorder' );
    infoTab.remove( 'txtHSpace' );
    infoTab.remove( 'txtVSpace' ); 
    infoTab.remove( 'txtWidth' ); 
    infoTab.remove( 'txtHeight' ); 
    infoTab.remove( 'cmbAlign' ); 
    console.log(infoTab);
}
});


// ADJUST EDITOR SKIN CSS
// Couldn't be done any other way without modifying library files skin (css)
var css = document.createElement("style");
css.type = "text/css";
css.innerHTML = ".cke_combopanel { width: 420px !important; }";
document.head.appendChild(css);