<?php
/**
 * @file
 * feature_taxonomy.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function feature_taxonomy_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_activity_type_pattern';
  $strongarm->value = '[term:vocabulary]/[term:name]/[term:tid]';
  $export['pathauto_taxonomy_term_activity_type_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_eight_dimensions_of_wellness_pattern';
  $strongarm->value = '[term:vocabulary]/[term:name]/[term:tid]';
  $export['pathauto_taxonomy_term_eight_dimensions_of_wellness_pattern'] = $strongarm;

  return $export;
}
