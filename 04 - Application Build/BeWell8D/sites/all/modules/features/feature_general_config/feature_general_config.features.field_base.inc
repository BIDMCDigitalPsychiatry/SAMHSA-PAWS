<?php
/**
 * @file
 * feature_general_config.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function feature_general_config_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'cer_bidirectional'.
  $field_bases['cer_bidirectional'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'cer_bidirectional',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => 0,
        1 => 1,
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  // Exported field_base: 'cer_enabled'.
  $field_bases['cer_enabled'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'cer_enabled',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 1,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => 0,
        1 => 1,
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  // Exported field_base: 'cer_left'.
  $field_bases['cer_left'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'cer_left',
    'indexes' => array(),
    'locked' => 1,
    'module' => 'field_object',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'field_object',
  );

  // Exported field_base: 'cer_right'.
  $field_bases['cer_right'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'cer_right',
    'indexes' => array(),
    'locked' => 1,
    'module' => 'field_object',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'field_object',
  );

  // Exported field_base: 'cer_weight'.
  $field_bases['cer_weight'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'cer_weight',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(),
      'allowed_values_function' => 'cer_weight_options',
    ),
    'translatable' => 0,
    'type' => 'list_integer',
  );

  return $field_bases;
}
