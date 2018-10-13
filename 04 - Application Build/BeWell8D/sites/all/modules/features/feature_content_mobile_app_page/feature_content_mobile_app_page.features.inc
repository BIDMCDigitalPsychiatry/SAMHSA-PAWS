<?php
/**
 * @file
 * feature_content_mobile_app_page.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_content_mobile_app_page_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function feature_content_mobile_app_page_node_info() {
  $items = array(
    'mobile_app_page' => array(
      'name' => t('Mobile App Page'),
      'base' => 'node_content',
      'description' => t('These are the pages that will be created an used in the mobile app.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
