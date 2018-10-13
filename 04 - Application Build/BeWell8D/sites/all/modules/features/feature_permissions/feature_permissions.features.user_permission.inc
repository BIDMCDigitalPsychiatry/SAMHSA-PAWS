<?php
/**
 * @file
 * feature_permissions.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function feature_permissions_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access administration menu'.
  $permissions['access administration menu'] = array(
    'name' => 'access administration menu',
    'roles' => array(
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'access administration pages'.
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access all views'.
  $permissions['access all views'] = array(
    'name' => 'access all views',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'views',
  );

  // Exported permission: 'access backup and migrate'.
  $permissions['access backup and migrate'] = array(
    'name' => 'access backup and migrate',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'access backup files'.
  $permissions['access backup files'] = array(
    'name' => 'access backup files',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'access ckeditor link'.
  $permissions['access ckeditor link'] = array(
    'name' => 'access ckeditor link',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'ckeditor_link',
  );

  // Exported permission: 'access content'.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access content overview'.
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access custom administration mobile app settings'.
  $permissions['access custom administration mobile app settings'] = array(
    'name' => 'access custom administration mobile app settings',
    'roles' => array(
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'custom_admin',
  );

  // Exported permission: 'access custom administration overall settings'.
  $permissions['access custom administration overall settings'] = array(
    'name' => 'access custom administration overall settings',
    'roles' => array(
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'custom_admin',
  );

  // Exported permission: 'access custom administration pages'.
  $permissions['access custom administration pages'] = array(
    'name' => 'access custom administration pages',
    'roles' => array(
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'custom_admin',
  );

  // Exported permission: 'access custom administration web view settings'.
  $permissions['access custom administration web view settings'] = array(
    'name' => 'access custom administration web view settings',
    'roles' => array(
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'custom_admin',
  );

  // Exported permission: 'access custom shortcode ckeditor ui'.
  $permissions['access custom shortcode ckeditor ui'] = array(
    'name' => 'access custom shortcode ckeditor ui',
    'roles' => array(
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'custom_shortcode_ckeditor_ui',
  );

  // Exported permission: 'access private fields'.
  $permissions['access private fields'] = array(
    'name' => 'access private fields',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'access rules debug'.
  $permissions['access rules debug'] = array(
    'name' => 'access rules debug',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'access site in maintenance mode'.
  $permissions['access site in maintenance mode'] = array(
    'name' => 'access site in maintenance mode',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access site reports'.
  $permissions['access site reports'] = array(
    'name' => 'access site reports',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access site_admin profiles'.
  $permissions['access site_admin profiles'] = array(
    'name' => 'access site_admin profiles',
    'roles' => array(
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'view_profiles_perms',
  );

  // Exported permission: 'access superadmin profiles'.
  $permissions['access superadmin profiles'] = array(
    'name' => 'access superadmin profiles',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'view_profiles_perms',
  );

  // Exported permission: 'access user profiles'.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'user',
  );

  // Exported permission: 'access users overview'.
  $permissions['access users overview'] = array(
    'name' => 'access users overview',
    'roles' => array(
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: 'administer actions'.
  $permissions['administer actions'] = array(
    'name' => 'administer actions',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer all default images'.
  $permissions['administer all default images'] = array(
    'name' => 'administer all default images',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'default_image_ft',
  );

  // Exported permission: 'administer backup and migrate'.
  $permissions['administer backup and migrate'] = array(
    'name' => 'administer backup and migrate',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'administer blocks'.
  $permissions['administer blocks'] = array(
    'name' => 'administer blocks',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'block',
  );

  // Exported permission: 'administer breakpoints'.
  $permissions['administer breakpoints'] = array(
    'name' => 'administer breakpoints',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'breakpoints',
  );

  // Exported permission: 'administer browser class'.
  $permissions['administer browser class'] = array(
    'name' => 'administer browser class',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'browserclass',
  );

  // Exported permission: 'administer cer settings'.
  $permissions['administer cer settings'] = array(
    'name' => 'administer cer settings',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'cer',
  );

  // Exported permission: 'administer ckeditor'.
  $permissions['administer ckeditor'] = array(
    'name' => 'administer ckeditor',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'ckeditor',
  );

  // Exported permission: 'administer ckeditor link'.
  $permissions['administer ckeditor link'] = array(
    'name' => 'administer ckeditor link',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'ckeditor_link',
  );

  // Exported permission: 'administer content types'.
  $permissions['administer content types'] = array(
    'name' => 'administer content types',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer contexts'.
  $permissions['administer contexts'] = array(
    'name' => 'administer contexts',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'context_ui',
  );

  // Exported permission: 'administer custom shortcode ckeditor ui'.
  $permissions['administer custom shortcode ckeditor ui'] = array(
    'name' => 'administer custom shortcode ckeditor ui',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'custom_shortcode_ckeditor_ui',
  );

  // Exported permission: 'administer date tools'.
  $permissions['administer date tools'] = array(
    'name' => 'administer date tools',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'date_tools',
  );

  // Exported permission: 'administer dependencies'.
  $permissions['administer dependencies'] = array(
    'name' => 'administer dependencies',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'conditional_fields',
  );

  // Exported permission: 'administer drupalgap'.
  $permissions['administer drupalgap'] = array(
    'name' => 'administer drupalgap',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'drupalgap',
  );

  // Exported permission: 'administer features'.
  $permissions['administer features'] = array(
    'name' => 'administer features',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'features',
  );

  // Exported permission: 'administer field permissions'.
  $permissions['administer field permissions'] = array(
    'name' => 'administer field permissions',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'administer fieldgroups'.
  $permissions['administer fieldgroups'] = array(
    'name' => 'administer fieldgroups',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'field_group',
  );

  // Exported permission: 'administer fields'.
  $permissions['administer fields'] = array(
    'name' => 'administer fields',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'field',
  );

  // Exported permission: 'administer filters'.
  $permissions['administer filters'] = array(
    'name' => 'administer filters',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'administer image styles'.
  $permissions['administer image styles'] = array(
    'name' => 'administer image styles',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'image',
  );

  // Exported permission: 'administer imce'.
  $permissions['administer imce'] = array(
    'name' => 'administer imce',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'imce',
  );

  // Exported permission: 'administer mailsystem'.
  $permissions['administer mailsystem'] = array(
    'name' => 'administer mailsystem',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'mailsystem',
  );

  // Exported permission: 'administer masquerade'.
  $permissions['administer masquerade'] = array(
    'name' => 'administer masquerade',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'masquerade',
  );

  // Exported permission: 'administer menu'.
  $permissions['administer menu'] = array(
    'name' => 'administer menu',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'menu',
  );

  // Exported permission: 'administer menu attributes'.
  $permissions['administer menu attributes'] = array(
    'name' => 'administer menu attributes',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'menu_attributes',
  );

  // Exported permission: 'administer module filter'.
  $permissions['administer module filter'] = array(
    'name' => 'administer module filter',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'module_filter',
  );

  // Exported permission: 'administer modules'.
  $permissions['administer modules'] = array(
    'name' => 'administer modules',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer nodes'.
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer page titles'.
  $permissions['administer page titles'] = array(
    'name' => 'administer page titles',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'page_title',
  );

  // Exported permission: 'administer password policies'.
  $permissions['administer password policies'] = array(
    'name' => 'administer password policies',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'password_policy',
  );

  // Exported permission: 'administer pathauto'.
  $permissions['administer pathauto'] = array(
    'name' => 'administer pathauto',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'pathauto',
  );

  // Exported permission: 'administer permissions'.
  $permissions['administer permissions'] = array(
    'name' => 'administer permissions',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer pictures'.
  $permissions['administer pictures'] = array(
    'name' => 'administer pictures',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'picture',
  );

  // Exported permission: 'administer rules'.
  $permissions['administer rules'] = array(
    'name' => 'administer rules',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'administer services'.
  $permissions['administer services'] = array(
    'name' => 'administer services',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'services',
  );

  // Exported permission: 'administer site configuration'.
  $permissions['administer site configuration'] = array(
    'name' => 'administer site configuration',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer software updates'.
  $permissions['administer software updates'] = array(
    'name' => 'administer software updates',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer taxonomy'.
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'administer themes'.
  $permissions['administer themes'] = array(
    'name' => 'administer themes',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer url aliases'.
  $permissions['administer url aliases'] = array(
    'name' => 'administer url aliases',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'path',
  );

  // Exported permission: 'administer user expire settings'.
  $permissions['administer user expire settings'] = array(
    'name' => 'administer user expire settings',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'user_expire',
  );

  // Exported permission: 'administer users'.
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer uuid'.
  $permissions['administer uuid'] = array(
    'name' => 'administer uuid',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'uuid',
  );

  // Exported permission: 'administer views'.
  $permissions['administer views'] = array(
    'name' => 'administer views',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'views',
  );

  // Exported permission: 'assign all roles'.
  $permissions['assign all roles'] = array(
    'name' => 'assign all roles',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'assign site_admin role'.
  $permissions['assign site_admin role'] = array(
    'name' => 'assign site_admin role',
    'roles' => array(
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'block IP addresses'.
  $permissions['block IP addresses'] = array(
    'name' => 'block IP addresses',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'system',
  );

  // Exported permission: 'bypass node access'.
  $permissions['bypass node access'] = array(
    'name' => 'bypass node access',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'bypass rules access'.
  $permissions['bypass rules access'] = array(
    'name' => 'bypass rules access',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'cancel account'.
  $permissions['cancel account'] = array(
    'name' => 'cancel account',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'user',
  );

  // Exported permission: 'cancel users with role 2'.
  $permissions['cancel users with role 2'] = array(
    'name' => 'cancel users with role 2',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: 'cancel users with role 3'.
  $permissions['cancel users with role 3'] = array(
    'name' => 'cancel users with role 3',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: 'change own username'.
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'user',
  );

  // Exported permission: 'context ajax block access'.
  $permissions['context ajax block access'] = array(
    'name' => 'context ajax block access',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'context_ui',
  );

  // Exported permission: 'create mobile_app_activities content'.
  $permissions['create mobile_app_activities content'] = array(
    'name' => 'create mobile_app_activities content',
    'roles' => array(
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create mobile_app_badges content'.
  $permissions['create mobile_app_badges content'] = array(
    'name' => 'create mobile_app_badges content',
    'roles' => array(
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create mobile_app_page content'.
  $permissions['create mobile_app_page content'] = array(
    'name' => 'create mobile_app_page content',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create mobile_app_resources content'.
  $permissions['create mobile_app_resources content'] = array(
    'name' => 'create mobile_app_resources content',
    'roles' => array(
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create mobile_app_user_settings content'.
  $permissions['create mobile_app_user_settings content'] = array(
    'name' => 'create mobile_app_user_settings content',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create page content'.
  $permissions['create page content'] = array(
    'name' => 'create page content',
    'roles' => array(
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create push_notification content'.
  $permissions['create push_notification content'] = array(
    'name' => 'create push_notification content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create url aliases'.
  $permissions['create url aliases'] = array(
    'name' => 'create url aliases',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'path',
  );

  // Exported permission: 'create users'.
  $permissions['create users'] = array(
    'name' => 'create users',
    'roles' => array(
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: 'customize ckeditor'.
  $permissions['customize ckeditor'] = array(
    'name' => 'customize ckeditor',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'ckeditor',
  );

  // Exported permission: 'delete any mobile_app_activities content'.
  $permissions['delete any mobile_app_activities content'] = array(
    'name' => 'delete any mobile_app_activities content',
    'roles' => array(
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any mobile_app_badges content'.
  $permissions['delete any mobile_app_badges content'] = array(
    'name' => 'delete any mobile_app_badges content',
    'roles' => array(
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any mobile_app_page content'.
  $permissions['delete any mobile_app_page content'] = array(
    'name' => 'delete any mobile_app_page content',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any mobile_app_resources content'.
  $permissions['delete any mobile_app_resources content'] = array(
    'name' => 'delete any mobile_app_resources content',
    'roles' => array(
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any mobile_app_user_settings content'.
  $permissions['delete any mobile_app_user_settings content'] = array(
    'name' => 'delete any mobile_app_user_settings content',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any page content'.
  $permissions['delete any page content'] = array(
    'name' => 'delete any page content',
    'roles' => array(
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any push_notification content'.
  $permissions['delete any push_notification content'] = array(
    'name' => 'delete any push_notification content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete backup files'.
  $permissions['delete backup files'] = array(
    'name' => 'delete backup files',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'delete own mobile_app_activities content'.
  $permissions['delete own mobile_app_activities content'] = array(
    'name' => 'delete own mobile_app_activities content',
    'roles' => array(
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own mobile_app_badges content'.
  $permissions['delete own mobile_app_badges content'] = array(
    'name' => 'delete own mobile_app_badges content',
    'roles' => array(
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own mobile_app_page content'.
  $permissions['delete own mobile_app_page content'] = array(
    'name' => 'delete own mobile_app_page content',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own mobile_app_resources content'.
  $permissions['delete own mobile_app_resources content'] = array(
    'name' => 'delete own mobile_app_resources content',
    'roles' => array(
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own mobile_app_user_settings content'.
  $permissions['delete own mobile_app_user_settings content'] = array(
    'name' => 'delete own mobile_app_user_settings content',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own page content'.
  $permissions['delete own page content'] = array(
    'name' => 'delete own page content',
    'roles' => array(
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own push_notification content'.
  $permissions['delete own push_notification content'] = array(
    'name' => 'delete own push_notification content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete revisions'.
  $permissions['delete revisions'] = array(
    'name' => 'delete revisions',
    'roles' => array(
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in activity_type'.
  $permissions['delete terms in activity_type'] = array(
    'name' => 'delete terms in activity_type',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in eight_dimensions_of_wellness'.
  $permissions['delete terms in eight_dimensions_of_wellness'] = array(
    'name' => 'delete terms in eight_dimensions_of_wellness',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'display drupal links'.
  $permissions['display drupal links'] = array(
    'name' => 'display drupal links',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'drupalgap get terms'.
  $permissions['drupalgap get terms'] = array(
    'name' => 'drupalgap get terms',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'drupalgap',
  );

  // Exported permission: 'drupalgap get vocabularies'.
  $permissions['drupalgap get vocabularies'] = array(
    'name' => 'drupalgap get vocabularies',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'drupalgap',
  );

  // Exported permission: 'edit any mobile_app_activities content'.
  $permissions['edit any mobile_app_activities content'] = array(
    'name' => 'edit any mobile_app_activities content',
    'roles' => array(
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any mobile_app_badges content'.
  $permissions['edit any mobile_app_badges content'] = array(
    'name' => 'edit any mobile_app_badges content',
    'roles' => array(
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any mobile_app_page content'.
  $permissions['edit any mobile_app_page content'] = array(
    'name' => 'edit any mobile_app_page content',
    'roles' => array(
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any mobile_app_resources content'.
  $permissions['edit any mobile_app_resources content'] = array(
    'name' => 'edit any mobile_app_resources content',
    'roles' => array(
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any mobile_app_user_settings content'.
  $permissions['edit any mobile_app_user_settings content'] = array(
    'name' => 'edit any mobile_app_user_settings content',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any page content'.
  $permissions['edit any page content'] = array(
    'name' => 'edit any page content',
    'roles' => array(
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any push_notification content'.
  $permissions['edit any push_notification content'] = array(
    'name' => 'edit any push_notification content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit mimemail user settings'.
  $permissions['edit mimemail user settings'] = array(
    'name' => 'edit mimemail user settings',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'mimemail',
  );

  // Exported permission: 'edit own mobile_app_activities content'.
  $permissions['edit own mobile_app_activities content'] = array(
    'name' => 'edit own mobile_app_activities content',
    'roles' => array(
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own mobile_app_badges content'.
  $permissions['edit own mobile_app_badges content'] = array(
    'name' => 'edit own mobile_app_badges content',
    'roles' => array(
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own mobile_app_page content'.
  $permissions['edit own mobile_app_page content'] = array(
    'name' => 'edit own mobile_app_page content',
    'roles' => array(
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own mobile_app_resources content'.
  $permissions['edit own mobile_app_resources content'] = array(
    'name' => 'edit own mobile_app_resources content',
    'roles' => array(
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own mobile_app_user_settings content'.
  $permissions['edit own mobile_app_user_settings content'] = array(
    'name' => 'edit own mobile_app_user_settings content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own page content'.
  $permissions['edit own page content'] = array(
    'name' => 'edit own page content',
    'roles' => array(
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own push_notification content'.
  $permissions['edit own push_notification content'] = array(
    'name' => 'edit own push_notification content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit terms in activity_type'.
  $permissions['edit terms in activity_type'] = array(
    'name' => 'edit terms in activity_type',
    'roles' => array(
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in eight_dimensions_of_wellness'.
  $permissions['edit terms in eight_dimensions_of_wellness'] = array(
    'name' => 'edit terms in eight_dimensions_of_wellness',
    'roles' => array(
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit users with role 2'.
  $permissions['edit users with role 2'] = array(
    'name' => 'edit users with role 2',
    'roles' => array(
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: 'edit users with role 3'.
  $permissions['edit users with role 3'] = array(
    'name' => 'edit users with role 3',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: 'flush caches'.
  $permissions['flush caches'] = array(
    'name' => 'flush caches',
    'roles' => array(
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'force password change'.
  $permissions['force password change'] = array(
    'name' => 'force password change',
    'roles' => array(
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'password_policy',
  );

  // Exported permission: 'generate features'.
  $permissions['generate features'] = array(
    'name' => 'generate features',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'features',
  );

  // Exported permission: 'get a system variable'.
  $permissions['get a system variable'] = array(
    'name' => 'get a system variable',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'services',
  );

  // Exported permission: 'get any binary files'.
  $permissions['get any binary files'] = array(
    'name' => 'get any binary files',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'services',
  );

  // Exported permission: 'get own binary files'.
  $permissions['get own binary files'] = array(
    'name' => 'get own binary files',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'services',
  );

  // Exported permission: 'grant content access'.
  $permissions['grant content access'] = array(
    'name' => 'grant content access',
    'roles' => array(
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'content_access',
  );

  // Exported permission: 'grant own content access'.
  $permissions['grant own content access'] = array(
    'name' => 'grant own content access',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'content_access',
  );

  // Exported permission: 'manage features'.
  $permissions['manage features'] = array(
    'name' => 'manage features',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'features',
  );

  // Exported permission: 'masquerade as admin'.
  $permissions['masquerade as admin'] = array(
    'name' => 'masquerade as admin',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'masquerade',
  );

  // Exported permission: 'masquerade as any user'.
  $permissions['masquerade as any user'] = array(
    'name' => 'masquerade as any user',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'masquerade',
  );

  // Exported permission: 'masquerade as user'.
  $permissions['masquerade as user'] = array(
    'name' => 'masquerade as user',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'masquerade',
  );

  // Exported permission: 'notify of path changes'.
  $permissions['notify of path changes'] = array(
    'name' => 'notify of path changes',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'pathauto',
  );

  // Exported permission: 'perform backup'.
  $permissions['perform backup'] = array(
    'name' => 'perform backup',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'perform unlimited index queries'.
  $permissions['perform unlimited index queries'] = array(
    'name' => 'perform unlimited index queries',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'services',
  );

  // Exported permission: 'preview focal point'.
  $permissions['preview focal point'] = array(
    'name' => 'preview focal point',
    'roles' => array(
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'focal_point',
  );

  // Exported permission: 'recompute computed fields'.
  $permissions['recompute computed fields'] = array(
    'name' => 'recompute computed fields',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'computed_field_tools',
  );

  // Exported permission: 'register device token'.
  $permissions['register device token'] = array(
    'name' => 'register device token',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'superadmin' => 'superadmin',
    ),
    'module' => 'push_notifications',
  );

  // Exported permission: 'remove device token'.
  $permissions['remove device token'] = array(
    'name' => 'remove device token',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'superadmin' => 'superadmin',
    ),
    'module' => 'push_notifications',
  );

  // Exported permission: 'rename features'.
  $permissions['rename features'] = array(
    'name' => 'rename features',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'features',
  );

  // Exported permission: 'restore from backup'.
  $permissions['restore from backup'] = array(
    'name' => 'restore from backup',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'revert revisions'.
  $permissions['revert revisions'] = array(
    'name' => 'revert revisions',
    'roles' => array(
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'run cron debug'.
  $permissions['run cron debug'] = array(
    'name' => 'run cron debug',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'cron_debug',
  );

  // Exported permission: 'save file information'.
  $permissions['save file information'] = array(
    'name' => 'save file information',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'services',
  );

  // Exported permission: 'select account cancellation method'.
  $permissions['select account cancellation method'] = array(
    'name' => 'select account cancellation method',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'user',
  );

  // Exported permission: 'send arbitrary files'.
  $permissions['send arbitrary files'] = array(
    'name' => 'send arbitrary files',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'mimemail',
  );

  // Exported permission: 'send push notifications'.
  $permissions['send push notifications'] = array(
    'name' => 'send push notifications',
    'roles' => array(
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'push_notifications',
  );

  // Exported permission: 'set a system variable'.
  $permissions['set a system variable'] = array(
    'name' => 'set a system variable',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'services',
  );

  // Exported permission: 'set page title'.
  $permissions['set page title'] = array(
    'name' => 'set page title',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'page_title',
  );

  // Exported permission: 'set user expiration'.
  $permissions['set user expiration'] = array(
    'name' => 'set user expiration',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'user_expire',
  );

  // Exported permission: 'show format selection for cer'.
  $permissions['show format selection for cer'] = array(
    'name' => 'show format selection for cer',
    'roles' => array(),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for node'.
  $permissions['show format selection for node'] = array(
    'name' => 'show format selection for node',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for rules_config'.
  $permissions['show format selection for rules_config'] = array(
    'name' => 'show format selection for rules_config',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for taxonomy_term'.
  $permissions['show format selection for taxonomy_term'] = array(
    'name' => 'show format selection for taxonomy_term',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for user'.
  $permissions['show format selection for user'] = array(
    'name' => 'show format selection for user',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format tips'.
  $permissions['show format tips'] = array(
    'name' => 'show format tips',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show more format tips link'.
  $permissions['show more format tips link'] = array(
    'name' => 'show more format tips link',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'unblock expired accounts'.
  $permissions['unblock expired accounts'] = array(
    'name' => 'unblock expired accounts',
    'roles' => array(
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'password_policy',
  );

  // Exported permission: 'use browsersync'.
  $permissions['use browsersync'] = array(
    'name' => 'use browsersync',
    'roles' => array(
      'superadmin' => 'superadmin',
    ),
    'module' => 'browsersync',
  );

  // Exported permission: 'use ctools import'.
  $permissions['use ctools import'] = array(
    'name' => 'use ctools import',
    'roles' => array(),
    'module' => 'ctools',
  );

  // Exported permission: 'use text format basic_html'.
  $permissions['use text format basic_html'] = array(
    'name' => 'use text format basic_html',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format full_html'.
  $permissions['use text format full_html'] = array(
    'name' => 'use text format full_html',
    'roles' => array(
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format full_html_mobile_app'.
  $permissions['use text format full_html_mobile_app'] = array(
    'name' => 'use text format full_html_mobile_app',
    'roles' => array(
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'view any unpublished content'.
  $permissions['view any unpublished content'] = array(
    'name' => 'view any unpublished content',
    'roles' => array(
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished mobile_app_activities content'.
  $permissions['view any unpublished mobile_app_activities content'] = array(
    'name' => 'view any unpublished mobile_app_activities content',
    'roles' => array(
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished mobile_app_badges content'.
  $permissions['view any unpublished mobile_app_badges content'] = array(
    'name' => 'view any unpublished mobile_app_badges content',
    'roles' => array(
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished mobile_app_page content'.
  $permissions['view any unpublished mobile_app_page content'] = array(
    'name' => 'view any unpublished mobile_app_page content',
    'roles' => array(
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished mobile_app_resources content'.
  $permissions['view any unpublished mobile_app_resources content'] = array(
    'name' => 'view any unpublished mobile_app_resources content',
    'roles' => array(
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished mobile_app_user_settings content'.
  $permissions['view any unpublished mobile_app_user_settings content'] = array(
    'name' => 'view any unpublished mobile_app_user_settings content',
    'roles' => array(
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished page content'.
  $permissions['view any unpublished page content'] = array(
    'name' => 'view any unpublished page content',
    'roles' => array(
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished push_notification content'.
  $permissions['view any unpublished push_notification content'] = array(
    'name' => 'view any unpublished push_notification content',
    'roles' => array(),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view date repeats'.
  $permissions['view date repeats'] = array(
    'name' => 'view date repeats',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'date_repeat_field',
  );

  // Exported permission: 'view device tokens'.
  $permissions['view device tokens'] = array(
    'name' => 'view device tokens',
    'roles' => array(
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'push_notifications',
  );

  // Exported permission: 'view expiring users report'.
  $permissions['view expiring users report'] = array(
    'name' => 'view expiring users report',
    'roles' => array(
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'user_expire',
  );

  // Exported permission: 'view own unpublished content'.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view revisions'.
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view the administration theme'.
  $permissions['view the administration theme'] = array(
    'name' => 'view the administration theme',
    'roles' => array(
      'site_admin' => 'site_admin',
      'superadmin' => 'superadmin',
    ),
    'module' => 'system',
  );

  return $permissions;
}
