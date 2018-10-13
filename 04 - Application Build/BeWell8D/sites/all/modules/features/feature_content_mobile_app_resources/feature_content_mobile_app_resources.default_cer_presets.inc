<?php
/**
 * @file
 * feature_content_mobile_app_resources.default_cer_presets.inc
 */

/**
 * Implements hook_default_cer().
 */
function feature_content_mobile_app_resources_default_cer() {
  $export = array();

  $cnr_obj = new stdClass();
  $cnr_obj->disabled = FALSE; /* Edit this to true to make a default cnr_obj disabled initially */
  $cnr_obj->api_version = 1;
  $cnr_obj->entity_types_content_fields = 'node*mobile_app_resources*field_wellness_goal_relation*taxonomy_term*eight_dimensions_of_wellness*field_resources';
  $cnr_obj->enabled = 1;
  $export['node*mobile_app_resources*field_wellness_goal_relation*taxonomy_term*eight_dimensions_of_wellness*field_resources'] = $cnr_obj;

  return $export;
}
