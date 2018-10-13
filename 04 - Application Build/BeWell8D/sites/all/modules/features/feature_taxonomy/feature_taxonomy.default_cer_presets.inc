<?php
/**
 * @file
 * feature_taxonomy.default_cer_presets.inc
 */

/**
 * Implements hook_default_cer().
 */
function feature_taxonomy_default_cer() {
  $export = array();

  $cnr_obj = new stdClass();
  $cnr_obj->disabled = FALSE; /* Edit this to true to make a default cnr_obj disabled initially */
  $cnr_obj->api_version = 1;
  $cnr_obj->entity_types_content_fields = 'taxonomy_term*eight_dimensions_of_wellness*field_activities*node*mobile_app_activities*field_wellness_goal_relation';
  $cnr_obj->enabled = 1;
  $export['taxonomy_term*eight_dimensions_of_wellness*field_activities*node*mobile_app_activities*field_wellness_goal_relation'] = $cnr_obj;

  $cnr_obj = new stdClass();
  $cnr_obj->disabled = FALSE; /* Edit this to true to make a default cnr_obj disabled initially */
  $cnr_obj->api_version = 1;
  $cnr_obj->entity_types_content_fields = 'taxonomy_term*eight_dimensions_of_wellness*field_badges*node*mobile_app_badges*field_wellness_goal_relation';
  $cnr_obj->enabled = 1;
  $export['taxonomy_term*eight_dimensions_of_wellness*field_badges*node*mobile_app_badges*field_wellness_goal_relation'] = $cnr_obj;

  $cnr_obj = new stdClass();
  $cnr_obj->disabled = FALSE; /* Edit this to true to make a default cnr_obj disabled initially */
  $cnr_obj->api_version = 1;
  $cnr_obj->entity_types_content_fields = 'taxonomy_term*eight_dimensions_of_wellness*field_resources*node*mobile_app_resources*field_wellness_goal_relation';
  $cnr_obj->enabled = 1;
  $export['taxonomy_term*eight_dimensions_of_wellness*field_resources*node*mobile_app_resources*field_wellness_goal_relation'] = $cnr_obj;

  return $export;
}
