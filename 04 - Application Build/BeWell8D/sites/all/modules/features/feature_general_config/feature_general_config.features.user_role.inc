<?php
/**
 * @file
 * feature_general_config.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function feature_general_config_user_default_roles() {
  $roles = array();

  // Exported role: site_admin.
  $roles['site_admin'] = array(
    'name' => 'site_admin',
    'weight' => 2,
    'uuid' => '48d4a041-10a1-4b30-aed4-72bc11775b47',
  );

  // Exported role: superadmin.
  $roles['superadmin'] = array(
    'name' => 'superadmin',
    'weight' => 3,
    'uuid' => '2b4e022b-7558-4108-b0f7-e2654fdccf27',
  );

  return $roles;
}
