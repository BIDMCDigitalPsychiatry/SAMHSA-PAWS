<?php
/**
 * @file
 * feature_user_config.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function feature_user_config_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'realname_pattern';
  $strongarm->value = '[user:field_first_name] [user:field_last_name]';
  $export['realname_pattern'] = $strongarm;

  return $export;
}
