<?php
/**
 * @file
 * feature_content_push_notification.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function feature_content_push_notification_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'node-push_notification-field_push_notification_message'.
  $field_instances['node-push_notification-field_push_notification_message'] = array(
    'bundle' => 'push_notification',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Enter a "plain" text message for this push notification.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'drupalgap' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_push_notification_message',
    'label' => 'Push Notification Message (Used In Push Notification)',
    'required' => 1,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'basic_html' => 'basic_html',
          'full_html' => 'full_html',
          'full_html_mobile_app' => 'full_html_mobile_app',
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'basic_html' => array(
              'weight' => -9,
            ),
            'full_html' => array(
              'weight' => -10,
            ),
            'full_html_mobile_app' => array(
              'weight' => 0,
            ),
            'plain_text' => array(
              'weight' => 10,
            ),
          ),
        ),
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'disable_resizable_textarea' => 0,
        'rows' => 10,
      ),
      'type' => 'text_textarea',
      'weight' => -4,
    ),
  );

  // Exported field_instance:
  // 'node-push_notification-field_wellness_goal_relation'.
  $field_instances['node-push_notification-field_wellness_goal_relation'] = array(
    'bundle' => 'push_notification',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 1,
      ),
      'drupalgap' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_wellness_goal_relation',
    'label' => 'Wellness Goal Relation',
    'required' => 1,
    'settings' => array(
      'behaviors' => array(
        'taxonomy-index' => array(
          'status' => TRUE,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => -3,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Enter a "plain" text message for this push notification.');
  t('Push Notification Message (Used In Push Notification)');
  t('Wellness Goal Relation');

  return $field_instances;
}
