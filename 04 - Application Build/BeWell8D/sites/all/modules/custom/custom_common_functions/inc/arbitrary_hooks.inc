<?php
//-------------------------------------------
// CKEDITOR
//-------------------------------------------
function custom_common_functions_ckeditor_settings_alter(&$settings, $conf) {
  // Change the ckeditor config path.
  $settings['customConfig'] = 'https://'.$_SERVER['HTTP_HOST'] .'/'. drupal_get_path('theme', variable_get('theme_default', NULL)).'/ckeditor/ckeditor.config.js';
  //dpm($settings, 'Settings');
}