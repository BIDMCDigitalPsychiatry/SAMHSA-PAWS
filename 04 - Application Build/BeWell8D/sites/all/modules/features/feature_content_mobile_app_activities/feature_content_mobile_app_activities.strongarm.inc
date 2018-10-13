<?php
/**
 * @file
 * feature_content_mobile_app_activities.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function feature_content_mobile_app_activities_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__mobile_app_activities';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'drupalgap' => array(
        'custom_settings' => TRUE,
      ),
      'ief_table' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '7',
        ),
      ),
      'display' => array(
        'title' => array(
          'ief_table' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
        'status' => array(
          'ief_table' => array(
            'weight' => '5',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__mobile_app_activities'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_mobile_app_activities';
  $strongarm->value = array();
  $export['menu_options_mobile_app_activities'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_mobile_app_activities';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_mobile_app_activities'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_mobile_app_activities';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_mobile_app_activities'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_mobile_app_activities';
  $strongarm->value = '0';
  $export['node_preview_mobile_app_activities'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_mobile_app_activities';
  $strongarm->value = 0;
  $export['node_submitted_mobile_app_activities'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_mobile_app_activities_pattern';
  $strongarm->value = 'activity/[node:title]/[node:nid]';
  $export['pathauto_node_mobile_app_activities_pattern'] = $strongarm;

  return $export;
}
