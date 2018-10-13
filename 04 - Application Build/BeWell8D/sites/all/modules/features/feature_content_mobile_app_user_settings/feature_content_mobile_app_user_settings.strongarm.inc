<?php
/**
 * @file
 * feature_content_mobile_app_user_settings.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function feature_content_mobile_app_user_settings_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__mobile_app_user_settings';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '8',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__mobile_app_user_settings'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_mobile_app_user_settings';
  $strongarm->value = array();
  $export['menu_options_mobile_app_user_settings'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_mobile_app_user_settings';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_mobile_app_user_settings'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_mobile_app_user_settings';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_mobile_app_user_settings'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_mobile_app_user_settings';
  $strongarm->value = '0';
  $export['node_preview_mobile_app_user_settings'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_mobile_app_user_settings';
  $strongarm->value = 0;
  $export['node_submitted_mobile_app_user_settings'] = $strongarm;

  return $export;
}
