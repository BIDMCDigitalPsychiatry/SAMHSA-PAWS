// =================== //
//  APP USER Password  //
// =================== //

//Callback
function custom_pages_app_user_pass_page() {
  var pageContainers = '';
  pageContainers += '<div id="app_user_pass_page_content"></div>';
  return pageContainers;
}

//PageShow
function custom_pages_app_user_pass_page__ps() {
  var appVars = variable_get('appVars');
  if (typeof appVars !== 'undefined') {
    appVars = JSON.parse(appVars);
      
    var content = '';
    
    //App User Login Banner Image
    // content += page_partial_icon_image_separator('page-top');
    
    //App Page Title
    content += '<div class="banner-icon banner-icon-account">';
    content += '  <div class="banner-icon--body">';
    content += '    <h1 class="banner-icon--title">Forgot Your Password?</h1>';
    content += '    <div class="banner-icon--title wysiwyg">' + appVars.user.passText + '</div>';
    content += '  </div>';
    content += '</div>';
    
    //App User Pass Form
    content += '<div class="section m-top-large">';
    content += drupalgap_get_form('user_pass_form');
    content += '</div>';
    
    //Page Links
    var cance_link = bl('Cancel', '#app_user_login', {
      'attributes':  {
        'class': 'btn btn-alt'
      }
    });
    content += '<div class="section section-med p-top-no">';
    content += '  <ul class="page-buttons">';
    content += '    <li>' + cance_link + '</li>';
    content += '  </ul>';
    content += '</div>';
    
    //Use JS to insert the content
    $('#app_user_pass_page_content').html(content).trigger('create');
  }
}
