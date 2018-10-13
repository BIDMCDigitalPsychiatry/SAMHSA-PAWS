<?php
/*----------------------------------------*/
/* User Redirect When not specific roles  */
/*----------------------------------------*/
//If not user 1 and page is not error page
$bypass_html_status_allowed = array('404 Not Found');
$bypass_html_status = drupal_get_http_header("status");
global $user;
if ($user->uid != '1' && !in_array($bypass_html_status, $bypass_html_status_allowed)) {
  $bypass_user_roles = array('site_admin','superadmin');
  $bypass_user = _drupal_user_check_roles($bypass_user_roles, $user->roles);
  //User allowed to bypass based on roles.
  if ($bypass_user) {
    //User cant bypass so redirect if trying to access a page they shouldn't
    $allowed_arg0 = array('user', 'home');
    $arg0 = arg(0);
    $arg1 = arg(1);
    if ($arg0 == 'user' && $arg1 == 'register') {
      drupal_set_message('User registrations are only allowed through the app. Please download the app to register.');
      drupal_goto('<front>');
    }
    if (!in_array($arg0, $allowed_arg0)) {
      drupal_set_message('You are not allowed to access this page.');
      drupal_goto('<front>');
    }
  }
}

/*--------------------*/
/* Alter Page titles. */
/*--------------------*/
$args = arg();
switch ($args['0']) {
  //User Pages
  case 'user':
    switch ($args['1']) {
      //User Password reset page.
      case 'password':
        drupal_set_title('Forgot Password?');
        break;
    }
    break;
}