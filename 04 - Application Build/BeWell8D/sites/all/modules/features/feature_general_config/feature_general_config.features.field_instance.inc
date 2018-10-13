<?php
/**
 * @file
 * feature_general_config.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function feature_general_config_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'cer-cer-cer_bidirectional'.
  $field_instances['cer-cer-cer_bidirectional'] = array(
    'bundle' => 'cer',
    'default_value' => array(
      0 => array(
        'value' => 1,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'cer',
    'field_name' => 'cer_bidirectional',
    'label' => 'Bidirectional',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'cer-cer-cer_enabled'.
  $field_instances['cer-cer-cer_enabled'] = array(
    'bundle' => 'cer',
    'default_value' => array(
      0 => array(
        'value' => 1,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'cer',
    'field_name' => 'cer_enabled',
    'label' => 'Enabled',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'cer-cer-cer_left'.
  $field_instances['cer-cer-cer_left'] = array(
    'bundle' => 'cer',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'field_object',
        'settings' => array(),
        'type' => 'field_object_label',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'cer',
    'field_name' => 'cer_left',
    'label' => 'Left Field',
    'required' => 1,
    'settings' => array(
      'function' => 'CerFieldChain::collectAll',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'cer-cer-cer_right'.
  $field_instances['cer-cer-cer_right'] = array(
    'bundle' => 'cer',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'field_object',
        'settings' => array(),
        'type' => 'field_object_label',
        'weight' => 6,
      ),
    ),
    'entity_type' => 'cer',
    'field_name' => 'cer_right',
    'label' => 'Right Field',
    'required' => 1,
    'settings' => array(
      'function' => 'CerFieldChain::collectAll',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'cer-cer-cer_weight'.
  $field_instances['cer-cer-cer_weight'] = array(
    'bundle' => 'cer',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'cer',
    'field_name' => 'cer_weight',
    'label' => 'Weight',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 4,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Bidirectional');
  t('Enabled');
  t('Left Field');
  t('Right Field');
  t('Weight');

  return $field_instances;
}
