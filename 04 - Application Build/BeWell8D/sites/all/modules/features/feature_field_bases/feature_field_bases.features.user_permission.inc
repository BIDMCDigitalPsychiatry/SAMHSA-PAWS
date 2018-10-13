<?php
/**
 * @file
 * feature_field_bases.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function feature_field_bases_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create field_class'.
  $permissions['create field_class'] = array(
    'name' => 'create field_class',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_class'.
  $permissions['edit field_class'] = array(
    'name' => 'edit field_class',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_class'.
  $permissions['edit own field_class'] = array(
    'name' => 'edit own field_class',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_class'.
  $permissions['view field_class'] = array(
    'name' => 'view field_class',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_class'.
  $permissions['view own field_class'] = array(
    'name' => 'view own field_class',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
