<?php
function custom_page__home() {
  $variables = array();
  global $user;
  
  $variables['global_user'] = $user;
  
  return theme('custom_page__home', $variables);

}
