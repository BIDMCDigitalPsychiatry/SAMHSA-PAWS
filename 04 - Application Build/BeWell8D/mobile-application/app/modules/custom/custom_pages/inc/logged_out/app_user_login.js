// ================ //
//  APP USER LOGIN  //
// ================ //

//Callback
function custom_pages_app_user_login_page() {
  var pageContainers = '';
  pageContainers += '<div id="app_user_login_page_content"></div>';
  return pageContainers;
}

//PageShow
function custom_pages_app_user_login_page__ps() {
  var appVars = variable_get('appVars');
  if (typeof appVars !== 'undefined') {
    appVars = JSON.parse(appVars);
    
    var content = '';
    
    //App User Login Banner Image
    // content += page_partial_icon_image_separator('page-top');
    
    //App Page Title
    content += '<div class="banner-icon banner-icon-account">';
    content += '  <div class="banner-icon--body">';
    content += '    <h2 class="banner-icon--title">'+appVars.user.loginText+'</h2>';
    content += '  </div>';
    content += '</div>';
    
    //App User Login Form
    content += '<div class="section p-top">';
    //content += '  <div class="wysiwyg m-btm">' +  + '</div>';
    content += drupalgap_get_form('user_login_form');
    content += '</div>';
    
    //Page Links
    var create_new_account_link = bl('Create new account', 'app_user_reg', {
      'attributes':  {
        'class': 'btn btn-alt'
      }
    });
    var forgot_password_link = bl('Forgot Password?', 'app_user_pass', {
      'attributes':  {
        'class': 'btn btn-alt'
      }
    });
    content += '<div class="section section-med p-top-no">';
    content += '  <ul class="page-buttons">';
    content += '    <li>' + create_new_account_link + '</li>';
    content += '    <li>' + forgot_password_link + '</li>';
    content += '  </ul>';
    content += '</div>';
    
    //Use JS to insert the content
    $('#app_user_login_page_content').html(content).trigger('create');
  }
}