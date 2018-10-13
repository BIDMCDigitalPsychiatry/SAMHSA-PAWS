<?php
/**
 * @file
 * feature_taxonomy.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function feature_taxonomy_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_activities|taxonomy_term|eight_dimensions_of_wellness|form';
  $field_group->group_name = 'group_activities';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'eight_dimensions_of_wellness';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_dimension_fields';
  $field_group->data = array(
    'label' => 'Activities',
    'weight' => '2',
    'children' => array(
      0 => 'field_activities',
      1 => 'field_tagline',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-activities field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_activities|taxonomy_term|eight_dimensions_of_wellness|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_admin_only|taxonomy_term|eight_dimensions_of_wellness|form';
  $field_group->group_name = 'group_admin_only';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'eight_dimensions_of_wellness';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_dimension_fields';
  $field_group->data = array(
    'label' => 'Admin Only',
    'weight' => '5',
    'children' => array(
      0 => 'field_class',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-admin-only field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_admin_only|taxonomy_term|eight_dimensions_of_wellness|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_badges|taxonomy_term|eight_dimensions_of_wellness|form';
  $field_group->group_name = 'group_badges';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'eight_dimensions_of_wellness';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_dimension_fields';
  $field_group->data = array(
    'label' => 'Badges',
    'weight' => '3',
    'children' => array(
      0 => 'field_badges',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-badges field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_badges|taxonomy_term|eight_dimensions_of_wellness|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_basic_info|taxonomy_term|eight_dimensions_of_wellness|form';
  $field_group->group_name = 'group_basic_info';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'eight_dimensions_of_wellness';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_dimension_fields';
  $field_group->data = array(
    'label' => 'Basic Information',
    'weight' => '1',
    'children' => array(
      0 => 'field_body',
      1 => 'name',
      2 => 'description',
      3 => 'field_details_checklist_items',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-basic-info field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_basic_info|taxonomy_term|eight_dimensions_of_wellness|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dimension_fields|taxonomy_term|eight_dimensions_of_wellness|form';
  $field_group->group_name = 'group_dimension_fields';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'eight_dimensions_of_wellness';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Dimension Fields',
    'weight' => '0',
    'children' => array(
      0 => 'group_basic_info',
      1 => 'group_activities',
      2 => 'group_admin_only',
      3 => 'group_resources',
      4 => 'group_badges',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-dimension-fields field-group-tabs',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_dimension_fields|taxonomy_term|eight_dimensions_of_wellness|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_resources|taxonomy_term|eight_dimensions_of_wellness|form';
  $field_group->group_name = 'group_resources';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'eight_dimensions_of_wellness';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_dimension_fields';
  $field_group->data = array(
    'label' => 'Resources',
    'weight' => '4',
    'children' => array(
      0 => 'field_resources',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-resources field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_resources|taxonomy_term|eight_dimensions_of_wellness|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Activities');
  t('Admin Only');
  t('Badges');
  t('Basic Information');
  t('Dimension Fields');
  t('Resources');

  return $field_groups;
}
