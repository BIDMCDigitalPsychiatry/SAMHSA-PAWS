<?php
/* Custom CSS Alters */
function _custom_css_alter(&$css) {
  //eg. unset($css[drupal_get_path('module','system').'/views.module.css']); 
}

/* Custom Menu Alters */
function _custom_menu_alter(&$items) {
  //eg. unset($items['node']);
  
  //Remove create new account tab
  unset($items['user/register']);
}