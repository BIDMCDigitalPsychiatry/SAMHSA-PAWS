// ====================== //
// Offline - crisis_lines //
// ====================== //

//Callback
function app_offline_page() {
  var pageContainers = '';
  pageContainers += '<div id="app_offline_crisis_lines_content_nid_5"></div>';
  return pageContainers;
}

//PageShow
function app_offline_page__ps() {
  var content = '';
  //Goal Page Title
  content += '<div class="banner-icon banner-icon-crisis-lines">';
  content += '  <div class="banner-icon--body">';
  content += '    <h2 class="banner-icon--title">You are currently offline, have no connection, or the app is currently under maintenance. Please use the following information in case of emergency. If You Are in Immediate Danger Call 911.</h2>';
  content += '  </div>';
  content += '</div>';
  
  var crisis_linesInfo = variable_get('offline_crisis_lines_information', '');
  
  if (crisis_linesInfo !== '') {
    //Convert variable back to json object
    var node = {};
    try {
      node = JSON.parse(crisis_linesInfo);
    } catch (ex) {
      //console.log(ex);
    }
    //console.log(node);
    
    //Content Body
    content += '<div class="section section-med">';
    content += '  <div class="wysiwyg">';
    try {
      content += node['field_body'].und['0'].safe_value;
    } catch (e) {}
    content += '  </div>';
    content += '</div>';
  
    //Additonal Crisis Lines
    content += '<div class="section section-med section-grey">';
    content += '  <div class="wysiwyg">';
    try {
      content += node['field_body_2'].und['0'].safe_value;
    } catch (e) {}
    content += '  </div>';
    content += '</div>';
  } else {
    
    //Content Body
    content += '<div class="section section-med">';
    content += '  <div class="wysiwyg">';
    content += '    <p>You haven\'t used this app online before. Please load the app over a connection before you can see the Crisis Lines inforomation offline.</p>';
    content += '  </div>';
    content += '</div>';
  }
  
  //Use JS to insert the content
  $('#app_offline_crisis_lines_content_nid_5').html(content).trigger('create');
  
}