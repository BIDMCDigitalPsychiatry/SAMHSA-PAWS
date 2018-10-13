<?php
/**
 * @file
 * feature_user_config.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function feature_user_config_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_admin_only|user|user|form';
  $field_group->group_name = 'group_admin_only';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Admin Only',
    'weight' => '2',
    'children' => array(
      0 => 'masquerade',
      1 => 'ckeditor',
      2 => 'timezone',
      3 => 'field_user_settings_node',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-admin-only field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_admin_only|user|user|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Admin Only');

  return $field_groups;
}
