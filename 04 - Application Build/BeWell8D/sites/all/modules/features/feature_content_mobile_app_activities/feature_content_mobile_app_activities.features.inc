<?php
/**
 * @file
 * feature_content_mobile_app_activities.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_content_mobile_app_activities_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "cer" && $api == "default_cer_presets") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function feature_content_mobile_app_activities_node_info() {
  $items = array(
    'mobile_app_activities' => array(
      'name' => t('Mobile App Activities'),
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
