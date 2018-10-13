<?php
/**
 * @file
 * feature_content_mobile_app_badges.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_content_mobile_app_badges_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "cer" && $api == "default_cer_presets") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function feature_content_mobile_app_badges_node_info() {
  $items = array(
    'mobile_app_badges' => array(
      'name' => t('Mobile App Badges'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
