// ========== //
// My Account //
// ========== //

//Callback
function custom_pages_app_my_account() {
  var pageContainers = '';
  pageContainers += '<div id="app_my_account_content_uid_' + Drupal.user.uid + '"></div>';
  return pageContainers;
}

//PageShow
function custom_pages_app_my_account__ps() {
  user_load(Drupal.user.uid, {
    success: function(user) {
      //console.log(user);
      
      var userLocalsettings = variable_get('userLocalsettings');
      if (typeof userLocalsettings !== 'undefined') {
        userLocalsettings = JSON.parse(userLocalsettings);
      } else {
        userLocalsettings = {};
      }
      
      var content = '';
      //App Page Title
      //Goal Page Title
      content += '<div class="banner-icon banner-icon-account">';
      content += '  <div class="banner-icon--body">';
      content += '    <h2 class="banner-icon--title">View and edit your account settings</h2>';
      content += '  </div>';
      content += '</div>';
      
      //User Settings
      content += '<div class="section section-med user-info">';
      content += '  <h3 class="h3 -orange">User Settings</h3>';
      content += '  <div class="user-info-name m-btm">';
      content += '    <span class="t-detail t-italic">User Name: </span>';
      content += '    <br />';
      content += '    <span class="t-bold t-large">' + user.name + '</span>';
      content += '  </div>';
      content += '  <div class="user-info-email">';
      content += '    <span class="t-detail t-italic">Email: </span>';
      content += '    <br />';
      content += '    <span class="t-bold t-large">' + user.mail + '</span>';
      content += '  </div>';
      content += '</div>';
      
      //App Settings
      var pushNotEnabled = variable_get('app_settings_enable_push_notifications', 1);
      if (pushNotEnabled == '1' || pushNotEnabled == 1) {
        pushNotEnabled = 'Yes';
      } else {
        pushNotEnabled = 'No';
      }
      
      content += '<hr class="hr-section-separator">';
      content += '<div class="section app-info">';
      content += '  <h3 class="h3 -orange">App Settings</h3>';
      content += '  <div class="app-info-name">';
      content += '    <span class="t-italic">Push Notifications Enabled: </span>';
      content += '    <span class="t-bold">' + pushNotEnabled + '</span>';
      content += '  </div>';
      content += '</div>';
  
      //Use JS to insert the content
      $('#app_my_account_content_uid_' + Drupal.user.uid).html(content).trigger('create');
    }
  });
}


// ============================== //
// My Account: Edit User Settings //
// ============================== //

//Callback
function custom_pages_app_my_account_edit_user() {
  var pageContainers = '';
  pageContainers += '<div id="app_my_account_edit_user_uid_' + Drupal.user.uid + '"></div>';
  return pageContainers;
}

//PageShow
function custom_pages_app_my_account_edit_user__ps() {
  entity_load('user', Drupal.user.uid, {
    success: function(account) {
      //console.log(account);
      var content = '';
      
      //User Page Title
      content += '<div class="section section-title">';
      content += '  <h2 class="h2 -blue -line">My Account: Edit User Settings</h2>';
      content += '</div>';
      
      //User Settings Form
      content += '<div class="section section-med p-top-no  user-settings-form">';
      content += drupalgap_get_form('user_profile_form', account);
      content += '</div>';
    
      //Use JS to insert the content
      $('#app_my_account_edit_user_uid_' + Drupal.user.uid).html(content).trigger('create');
    }
  });
}

// ============================= //
// My Account: Edit App Settings //
// ============================= //

//Callback
function custom_pages_app_my_account_edit_app() {
  var pageContainers = '';
  pageContainers += '<div id="app_my_account_edit_app_uid_' + Drupal.user.uid + '"></div>';
  return pageContainers;
}

//PageShow
function custom_pages_app_my_account_edit_app__ps() {
  var content = '';
  
  //App Page Title
  content += '<div class="section section-title p-btm-no">';
  content += '  <h2 class="h2 -blue -line">My Account: Edit App Settings</h2>';
  content += '</div>';
  
  //User Settings Form
  content += '<div class="section section-med p-top-no user-settings-form">';
  content += drupalgap_get_form('custom_pages_app_my_account_edit_app__form');
  content += '</div>';

  //Use JS to insert the content
  $('#app_my_account_edit_app_uid_' + Drupal.user.uid).html(content).trigger('create');
}

//Account Edit Form
function custom_pages_app_my_account_edit_app__form(form, form_state, user) {
  
  //Set Up Fields
  // APP SETTINGS
  form.elements['app_settings_enable_push_notifications'] = {
    title: 'Recieve Push Notifications',
    type: 'checkbox',
    description: 'Check this box if you would like to recieve push notifications.',
    default_value: variable_get('app_settings_enable_push_notifications', 1)
  };
  return system_settings_form(form);
}

//Account Edit Form Submit
function custom_pages_app_my_account_edit_app__form_submit(form, form_state) {
  
  //Add remove push notifications token based on setting.
  //console.log(form_state.values);
  //Push Enabled
  if (drupalgap.settings.mode == 'phonegap' && user_access('register device token') && form_state.values['app_settings_enable_push_notifications'] == 1) {
    push_notifications_register();
  } else if (drupalgap.settings.mode == 'phonegap' && user_access('remove device token')) {
    push_notifications_delete_device_token();
  }
  
  //Message and redirect
  var msg = t('App Settings have been updated successfully.');
  drupalgap_set_message(msg);
  drupalgap_goto('app_my_account', {reloadPage:true});
}

// ============================== //
// My Account: Edit User Settings //
// ============================== //

//Callback
function custom_pages_app_my_account_force_reset_password() {
  var pageContainers = '';
  pageContainers += '<div id="app_my_account_edit_user_uid_' + Drupal.user.uid + '"></div>';
  return pageContainers;
}

//PageShow
function custom_pages_app_my_account_force_reset_password__ps() {
  entity_load('user', Drupal.user.uid, {
    success: function(account) {
      //console.log(account);
      var content = '';
      
      //User Page Title
      content += '<div class="section section-title p-btm-no">';
      content += '  <h2 class="h2 -blue -line">Password Expired: Please Reset Your Password</h2>';
      content += '</div>';
      
      //User Settings Form
      content += '<div class="section section-med p-top-no  user-settings-form">';
      content += drupalgap_get_form('user_profile_form', account);
      content += '</div>';
    
      //Use JS to insert the content
      $('#app_my_account_edit_user_uid_' + Drupal.user.uid).html(content).trigger('create');
    }
  });
}