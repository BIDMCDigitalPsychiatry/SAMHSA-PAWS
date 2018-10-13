<?php
/**
 * Implements hook_css_alter().
 */
function is_2016_css_alter(&$css) {
  // dpm($css);
  unset($css[drupal_get_path('module','system').'/drupal.base.css']);
  unset($css[drupal_get_path('module','system').'/system.module.css']);
  unset($css[drupal_get_path('module','system').'/system.messages.css']);
  unset($css[drupal_get_path('module','system').'/system.menus.css']);
  unset($css[drupal_get_path('module','system').'/system.theme.css']);
  unset($css[drupal_get_path('module','taxonomy').'/taxonomy.css']);
  unset($css[drupal_get_path('module','system').'/views.module.css']);
  // Custom Alters
  _custom_css_alter($css);
}

/**
 * Implements hook_css_alter().
 */
function is_2016_js_alter(&$javascript) {
  unset($css[drupal_get_path('module','jquery_update').'/replace/jquery/1.10/jquery.min.js']);
}

/**
 * Implementation of hook_menu_alter().
 */
function is_2016_menu_alter(&$items) {
  //Removes the /node path and page from your website, forever.
  unset($items['node']);
  
  //Rename menu button for request new password
  $items['user/password']['title'] = t('Forgot Password?');
  
  // Custom Alters
  _custom_menu_alter($items);
}