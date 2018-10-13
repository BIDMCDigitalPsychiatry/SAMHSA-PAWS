<?php

/**
 * Override or insert variables into the html template.
 */
function is_2016_preprocess_html(&$variables) {
  //Gloabl Vars
  _global_global_vars($variables);
  //Add Libraries to pages
  _global_drupal_libraries($variables, 'html');
  //Custom preprocess HTML
  _custom_preprocess($variables, 'html');
  //dpm($variables);
}

/**
 * Implements hook_process_html().
 */
function is_2016_process_html(&$variables) {
  //Set header scripts
  $variables['head_scripts'] = drupal_get_js('head_scripts');
  //dpm($variables);
}

/**
 * Override or insert variables into the page template.
 */
function is_2016_preprocess_page(&$variables) {
  //Gloabl Vars
  _global_global_vars($variables);
  //Regions Anywhere
  _global_regions_anywhere($variables, 'page');
  //Theme Hook Suggestions
  _global_theme_hook_suggestions($variables, 'page');
  //Custom preprocess page
  _custom_preprocess($variables, 'page');

  //======================================================================================
  //Removing The No Content classified with this term message from taxonomy-term pages ===
  //======================================================================================
  if(isset($variables['page']['content']['system_main']['term_heading']['term']) && isset($variables['page']['content']['system_main']['no_content'])) {
    unset($variables['page']['content']['system_main']['no_content']);
  }
  //======================================================================================
  //Removing The Node Listing from taxonomy-term pages ===================================
  //======================================================================================
  if(isset($variables['page']['content']['system_main']['term_heading']['term']) && isset($variables['page']['content']['system_main']['nodes'])) {
    unset($variables['page']['content']['system_main']['nodes']);
  }
  if(isset($variables['page']['content']['system_main']['term_heading']['term']) && isset($variables['page']['content']['system_main']['pager'])) {
    unset($variables['page']['content']['system_main']['pager']);
  }
  
  //dpm($variables);
}

/**
 * Override or insert variables into the maintenance page template.
 */
function is_2016_preprocess_maintenance_page(&$variables) {
  //Page Content CHeck
  $variables['messages_exist'] = !empty($variables['messages']);
  //Gloabl Vars
  _global_global_vars($variables);
  //Regions Anywhere
  _global_regions_anywhere($variables, 'page');
  //Custom preprocess page
  _custom_preprocess($variables, 'maintenance_page');
  //dpm($variables);
}

/**
 * Override or insert variables into entity templates.
 */
function is_2016_preprocess_entity(&$variables, $hook) {
  //Gloabl Vars
  _global_global_vars($variables);
  //Custom preprocess page
  _custom_preprocess($variables, 'entity');
  //dpm($variables);
}

/**
 * Override or insert variables into the node template.
 */
function is_2016_preprocess_node(&$variables) {
  //Gloabl Vars
  _global_global_vars($variables);
  //Theme Hook Suggestions
  _global_theme_hook_suggestions($variables, 'node');
  //Custom preprocess page
  _custom_preprocess($variables, 'node');
  //dpm($variables);
}

/**
 * Override or insert variables into the user profile template.
 */
function is_2016_preprocess_user_profile(&$variables) {
  //Gloabl Vars
  _global_global_vars($variables);
  //Custom preprocess page
  _custom_preprocess($variables, 'user_profile');
  //dpm($variables);
}

/**
 * Override or insert variables into the user_picture template.
 */
function is_2016_preprocess_user_picture(&$variables) {
  //dpm($variables);
  //Gloabl Vars
  _global_global_vars($variables);
  //Custom preprocess page
  _custom_preprocess($variables, 'user_picture');
}

/**
 * Override or insert variables into the username template.
 */
function is_2016_preprocess_username(&$variables) {
  //dpm($variables);
  //Gloabl Vars
  _global_global_vars($variables);
  //Custom preprocess page
  _custom_preprocess($variables, 'username');
}

/**
 * Override or insert variables into the user profile template.
 */
function is_2016_preprocess_views_view(&$variables) {
  //Gloabl Vars
  _global_global_vars($variables);
  //Custom preprocess page
  _custom_preprocess($variables, 'views_view');
}

/**
 * Override or insert variables into the views_view_fields template.
 */
function is_2016_preprocess_views_view_fields(&$variables) {
  //dpm($variables);
  //Gloabl Vars
  _global_global_vars($variables);
  //Custom preprocess page
  _custom_preprocess($variables, 'views_view_fields');
}

/**
 * Override or insert variables into the views_view_field template.
 */
function is_2016_preprocess_views_view_field(&$variables) {
  //dpm($variables);
  //Gloabl Vars
  _global_global_vars($variables);
  //Custom preprocess page
  _custom_preprocess($variables, 'views_view_field');
}

/**
 * Override or insert variables into the views_exposed_form template.
 */
function is_2016_preprocess_views_exposed_form(&$variables) {
  //dpm($variables);
  //Gloabl Vars
  _global_global_vars($variables);
  //Custom preprocess page
  _custom_preprocess($variables, 'views_exposed_form');
}

/**
 * Override or insert variables into the taxonomy term template.
 */
function is_2016_preprocess_taxonomy_term(&$variables) {
  //Gloabl Vars
  _global_global_vars($variables);
  //Custom preprocess page
  _custom_preprocess($variables, 'taxonomy_term');
  //dpm($variables);
}

/**
 * Override or insert variables into the region template.
 */
function is_2016_preprocess_region(&$variables) {
  //Gloabl Vars
  _global_global_vars($variables);
  //Custom preprocess page
  _custom_preprocess($variables, 'region');
}

/**
 * Override or insert variables into the block template.
 */
function is_2016_preprocess_block(&$variables) {
  //Gloabl Vars
  _global_global_vars($variables);
  //Custom preprocess page
  _custom_preprocess($variables, 'block');
  //dpm($variables);
}

/**
 * Override or insert variables into the comment_wrapper template.
 */
function is_2016_preprocess_comment_wrapper(&$variables) {
  //dpm($variables);
  //Gloabl Vars
  _global_global_vars($variables);
  //Custom preprocess page
  _custom_preprocess($variables, 'comment_wrapper');
}

/**
 * Override or insert variables into the comment template.
 */
function is_2016_preprocess_comment(&$variables) {
  //dpm($variables);
  //Gloabl Vars
  _global_global_vars($variables);
  //Custom preprocess page
  _custom_preprocess($variables, 'comment');
}

/**
 * Override or insert variables into the field template.
 */
function is_2016_preprocess_field(&$variables) {
  //dpm($variables);
  //Gloabl Vars
  _global_global_vars($variables);
  //Custom preprocess page
  _custom_preprocess($variables, 'field');
}

/**
 * Override or insert variables into the image template.
 */
function is_2016_preprocess_image(&$variables) {
  //dpm($variables);
  //Gloabl Vars
  _global_global_vars($variables);
  //Custom preprocess page
  _custom_preprocess($variables, 'image');
}

/**
 * Override or insert variables into the mimemail_message template.
 */
function is_2016_preprocess_mimemail_message(&$variables) {
  //dpm($variables);
  //Gloabl Vars
  _global_global_vars($variables);
  //Custom preprocess page
  _custom_preprocess($variables, 'mimemail_message');
}