<?php
/**
 * @file
 * feature_general_config.default_breakpoint_group.inc
 */

/**
 * Implements hook_default_breakpoint_group().
 */
function feature_general_config_default_breakpoint_group() {
  $export = array();

  $breakpoint_group = new stdClass();
  $breakpoint_group->disabled = FALSE; /* Edit this to true to make a default breakpoint_group disabled initially */
  $breakpoint_group->api_version = 1;
  $breakpoint_group->machine_name = 'breakpoints_ascending';
  $breakpoint_group->name = 'Breakpoints Ascending';
  $breakpoint_group->breakpoints = array(
    0 => 'custom.user.mobile_up',
    1 => 'custom.user.tablet_up',
    2 => 'custom.user.laptop_up',
    3 => 'custom.user.desktop_up',
    4 => 'custom.user.widescreen_up',
  );
  $breakpoint_group->type = 'custom';
  $breakpoint_group->overridden = 0;
  $export['breakpoints_ascending'] = $breakpoint_group;

  $breakpoint_group = new stdClass();
  $breakpoint_group->disabled = FALSE; /* Edit this to true to make a default breakpoint_group disabled initially */
  $breakpoint_group->api_version = 1;
  $breakpoint_group->machine_name = 'breakpoints_descending';
  $breakpoint_group->name = 'Breakpoints Descending';
  $breakpoint_group->breakpoints = array(
    0 => 'custom.user.mobile',
    1 => 'custom.user.tablet',
    2 => 'custom.user.laptop',
    3 => 'custom.user.desktop',
    4 => 'custom.user.widescreen',
  );
  $breakpoint_group->type = 'custom';
  $breakpoint_group->overridden = 0;
  $export['breakpoints_descending'] = $breakpoint_group;

  $breakpoint_group = new stdClass();
  $breakpoint_group->disabled = FALSE; /* Edit this to true to make a default breakpoint_group disabled initially */
  $breakpoint_group->api_version = 1;
  $breakpoint_group->machine_name = 'breakpoints_specific';
  $breakpoint_group->name = 'Breakpoints Specific';
  $breakpoint_group->breakpoints = array(
    0 => 'custom.user.mobile_only',
    1 => 'custom.user.tablet_only',
    2 => 'custom.user.laptop_only',
    3 => 'custom.user.desktop_only',
    4 => 'custom.user.widescreen_only',
  );
  $breakpoint_group->type = 'custom';
  $breakpoint_group->overridden = 0;
  $export['breakpoints_specific'] = $breakpoint_group;

  return $export;
}
