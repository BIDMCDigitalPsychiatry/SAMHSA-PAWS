<?php
/**
 * @file
 * feature_content_push_notification.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_content_push_notification_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function feature_content_push_notification_node_info() {
  $items = array(
    'push_notification' => array(
      'name' => t('Push Notification'),
      'base' => 'node_content',
      'description' => t('This content type will be used to create Push Notifications that will be sent out using a schedule via rules. Each notification can and will be attached to a "Eight Dimensions of Wellness" term.'),
      'has_title' => '1',
      'title_label' => t('Push Notification (Not Used In Push Notification)'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
