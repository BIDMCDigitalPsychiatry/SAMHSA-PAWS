// ======================= //
//  APP USER Registration  //
// ======================= //

//Callback
function custom_pages_app_user_reg_page() {
  var pageContainers = '';
  pageContainers += '<div id="app_user_reg_page_content"></div>';
  return pageContainers;
}

//PageShow
function custom_pages_app_user_reg_page__ps() {
  var appVars = variable_get('appVars');
  if (typeof appVars !== 'undefined') {
    appVars = JSON.parse(appVars);
      
    var content = '';
    
    //App Banner Image
    // content += page_partial_icon_image_separator('page-top');
    
    //App Page Title
    content += '<div class="banner-icon banner-icon-account">';
    content += '  <div class="banner-icon--body">';
    content += '    <div class="banner-icon--title">' + appVars.user.regText + '</div>';
    content += '  </div>';
    content += '</div>';
    
    //App User Registration From
    content += '<div class="section m-top-large">';
    content += drupalgap_get_form('user_register_form');
    content += '</div>';
    
    //Page Links
    var cance_link = bl('Cancel', 'app_user_login', {
      'attributes':  {
        'class': 'btn btn-alt'
      }
    });
    content += '<div class="section">';
    content += '  <ul class="page-buttons">';
    content += '    <li>' + cance_link + '</li>';
    content += '  </ul>';
    content += '</div>';
    
    //Go back to Login Section
    var login_link = bl('Sign In', 'app_user_login');
    content += '<div class="section section-med t-center">';
    content += '  <p>Already have an account?<br>' + login_link + '</p>';
    content += '</div>';
    
    //Use JS to insert the content
    $('#app_user_reg_page_content').html(content).trigger('create');
  }
}