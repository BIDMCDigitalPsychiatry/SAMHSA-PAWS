<?php

function custom_admin__overall_main() {
  $variables = array();
  global $user;
  
  $variables['global_user'] = $user;
  
  return theme('custom_admin__overall_main', $variables);
}