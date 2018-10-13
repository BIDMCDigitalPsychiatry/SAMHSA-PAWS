if (typeof Drupal.settings.auth_initial_page != 'undefined') {
  var auth_alter_home_logged_page = Drupal.settings.auth_initial_page;
} else {
  var auth_alter_home_logged_page = 'app_eight_demensions';
}

if (typeof Drupal.settings.anon_initial_page != 'undefined') {
  var auth_alter_home_not_logged_page = Drupal.settings.anon_initial_page;
} else {
  var auth_alter_home_not_logged_page = 'app_home';
}

/**
 * Implements hook_services_request_pre_postprocess_alter().
 */
function auth_alter_home_services_request_pre_postprocess_alter(options, result) {
    // On a system connect preprocess, there is no guarantee the Drupal.user
  // object is accurate yet, so we need to look at the user object bundled in
  // the result instead.
  
  // Whenever a system connect is performed, check for anonymous users, if
  // they are anonymous, set the front page to the logged out page.
  // or if logged in set front page to logged in home page.
  if (options.service == 'system' && options.resource == 'connect') {
    if (result.user.uid == 0) { 
      drupalgap.settings.front = auth_alter_home_not_logged_page; 
    } else { 
      drupalgap.settings.front = auth_alter_home_logged_page; 
    }
  }
}

/**
 * Implements hook_services_postprocess().
 */
function auth_alter_home_services_postprocess(options, result) {
  // When the user login service resource is successful, set the front page
  // back to its original value.
  if (options.service == 'user') {
    if (options.resource == 'login') { 
      drupalgap.settings.front = auth_alter_home_logged_page;
    } else if (options.resource == 'logout') {
      drupalgap.settings.front = auth_alter_home_not_logged_page;
    }
  }
  
  //Redirect user if password is forced to being reset.
  if (typeof result.user !== 'undefined') {
    if (options.service == 'system') {
      if (options.resource == 'connect') { 
        custom_user_init_vars_load(result.user.uid, function(success, userInitVars) { 
          if (success === true) {
            if (userInitVars.password_blocked === true) {
              console.log(userInitVars);
              drupalgap_goto('app_my_account/force_reset_password');
            }
          } else {
            drupalgap_goto('app_home');
          }
        });
      }
    }
  }
  
}

