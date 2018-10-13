<?php
/**
 * @file
 * feature_content_mobile_app_user_settings.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_content_mobile_app_user_settings_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function feature_content_mobile_app_user_settings_node_info() {
  $items = array(
    'mobile_app_user_settings' => array(
      'name' => t('Mobile App User Settings'),
      'base' => 'node_content',
      'description' => t('This will hold all user settings information.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
