<?php
/**
 * @file
 * feature_general_config.backup_migrate_exportables.inc
 */

/**
 * Implements hook_exportables_backup_migrate_destinations().
 */
function feature_general_config_exportables_backup_migrate_destinations() {
  $export = array();

  $item = new stdClass();
  $item->disabled = FALSE; /* Edit this to true to make a default item disabled initially */
  $item->api_version = 1;
  $item->machine_name = 'default_site_destination';
  $item->name = 'Default Site Destination';
  $item->subtype = 'file';
  $item->location = 'sites/default/files/private/back-ups-abc123';
  $item->settings = array(
    'chmod' => '',
    'chgrp' => '',
  );
  $export['default_site_destination'] = $item;

  return $export;
}

/**
 * Implements hook_exportables_backup_migrate_schedules().
 */
function feature_general_config_exportables_backup_migrate_schedules() {
  $export = array();

  $item = new stdClass();
  $item->disabled = FALSE; /* Edit this to true to make a default item disabled initially */
  $item->api_version = 1;
  $item->machine_name = 'every_four_hours_backup_db';
  $item->name = 'Every 4 Hours Backup Database';
  $item->source_id = 'db';
  $item->destination_id = 'default_site_destination';
  $item->copy_destination_id = '';
  $item->profile_id = 'default';
  $item->keep = 10;
  $item->period = 14400;
  $item->enabled = TRUE;
  $item->cron = 'builtin';
  $item->cron_schedule = '0 4 * * *';
  $export['every_four_hours_backup_db'] = $item;

  return $export;
}
