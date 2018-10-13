<?php
/**
 * @file
 * feature_general_config.default_breakpoints.inc
 */

/**
 * Implements hook_default_breakpoints().
 */
function feature_general_config_default_breakpoints() {
  $export = array();

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.desktop';
  $breakpoint->name = 'desktop';
  $breakpoint->breakpoint = 'screen and (max-width: 1350px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 5;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.desktop'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.desktop_only';
  $breakpoint->name = 'desktop-only';
  $breakpoint->breakpoint = 'screen and (max-width: 1600px) and (min-width: 1025px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 10;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.desktop_only'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.desktop_up';
  $breakpoint->name = 'desktop-up';
  $breakpoint->breakpoint = 'screen and (min-width: 1025px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 15;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.desktop_up'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.laptop';
  $breakpoint->name = 'laptop';
  $breakpoint->breakpoint = 'screen and (max-width: 1024px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 4;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.laptop'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.laptop_only';
  $breakpoint->name = 'laptop-only';
  $breakpoint->breakpoint = 'screen and (max-width: 1024px) and (min-width: 769px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 9;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.laptop_only'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.laptop_up';
  $breakpoint->name = 'laptop-up';
  $breakpoint->breakpoint = 'screen and (min-width: 769px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 14;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.laptop_up'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.mobile';
  $breakpoint->name = 'mobile';
  $breakpoint->breakpoint = 'screen and (max-width: 480px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 2;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.mobile'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.mobile_only';
  $breakpoint->name = 'mobile-only';
  $breakpoint->breakpoint = 'screen and (max-width: 480px) and (min-width: 0px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 7;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.mobile_only'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.mobile_up';
  $breakpoint->name = 'mobile-up';
  $breakpoint->breakpoint = 'screen and (min-width: 0px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 12;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.mobile_up'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.tablet';
  $breakpoint->name = 'tablet';
  $breakpoint->breakpoint = 'screen and (max-width: 768px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 3;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.tablet'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.tablet_only';
  $breakpoint->name = 'tablet-only';
  $breakpoint->breakpoint = 'screen and (max-width: 768px) and (min-width: 481px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 8;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.tablet_only'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.tablet_up';
  $breakpoint->name = 'tablet-up';
  $breakpoint->breakpoint = 'screen and (min-width: 481px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 13;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.tablet_up'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.widescreen';
  $breakpoint->name = 'widescreen';
  $breakpoint->breakpoint = 'screen and (min-width: 1351px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 6;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.widescreen'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.widescreen_only';
  $breakpoint->name = 'widescreen-only';
  $breakpoint->breakpoint = 'screen and (min-width: 1601px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 11;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.widescreen_only'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.widescreen_up';
  $breakpoint->name = 'widescreen-up';
  $breakpoint->breakpoint = 'screen and (min-width: 1600px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 16;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.widescreen_up'] = $breakpoint;

  return $export;
}
