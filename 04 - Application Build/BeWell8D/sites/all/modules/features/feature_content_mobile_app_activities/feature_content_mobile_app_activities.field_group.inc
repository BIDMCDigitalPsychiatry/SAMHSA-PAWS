<?php
/**
 * @file
 * feature_content_mobile_app_activities.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function feature_content_mobile_app_activities_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_activity_duration|node|activities|form';
  $field_group->group_name = 'group_activity_duration';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'mobile_app_activities';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Activity Duration',
    'weight' => '6',
    'children' => array(
      0 => 'field_activity_duration_end',
      1 => 'field_activity_duration_start',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Activity Duration',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-activity-duration field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_activity_duration|node|activities|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Activity Duration');

  return $field_groups;
}
