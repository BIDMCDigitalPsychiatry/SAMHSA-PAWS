<?php
/**
 * @file
 * feature_content_mobile_app_badges.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function feature_content_mobile_app_badges_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__mobile_app_badges';
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
          'weight' => '6',
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
            'weight' => '4',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__mobile_app_badges'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_mobile_app_badges';
  $strongarm->value = array();
  $export['menu_options_mobile_app_badges'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_mobile_app_badges';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_mobile_app_badges'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_mobile_app_badges';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_mobile_app_badges'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_mobile_app_badges';
  $strongarm->value = '0';
  $export['node_preview_mobile_app_badges'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_mobile_app_badges';
  $strongarm->value = 1;
  $export['node_submitted_mobile_app_badges'] = $strongarm;

  return $export;
}
