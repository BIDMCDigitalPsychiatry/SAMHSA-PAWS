<?php
function custom_page__mobile_app_user_vars_json($user_uid) {
  $variables = array();
  global $user;
  $user_account = user_load($user_uid);
  
  //Check to make sure current user is looking for the correct results
  if ($user->uid == $user_account->uid) {
    $variables['user_wrong'] = false;
    $variables['password_blocked'] = (isset($user_account->force_password_change) && $user_account->force_password_change == 1 ? true : false);
  } else {
    $variables['user_wrong'] = true;
  }
  
  return $variables;
}
