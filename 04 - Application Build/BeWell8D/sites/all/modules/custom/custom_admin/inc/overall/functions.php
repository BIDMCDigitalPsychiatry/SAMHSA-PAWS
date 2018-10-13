<?php
/**
 * Sub function for adding admin pages for the overall side in hook_menu()
 */
function custom_admin_overall_menu_items(&$items) {
  //Set up the main structure page for the tif apr system admin
  $items['admin/site-admin'] = array(
    'title' => 'Site Admin',
    'description' => 'In this area you will find all custom administration sections.',
    'page callback' => 'custom_admin__overall_main',
    'access arguments' => array('access custom administration pages'),
    'weight' => -999,
    'type' => MENU_NORMAL_ITEM,
    'file' => 'inc/overall/pages/custom_admin__overall_main.inc',
  );
  
  //Overall Site Settings
  $items['admin/site-admin/overall'] = array(
    'title' => 'Site - Overall Settings',
    'description' => 'This settings page will contain items that deal with the overall system.',
    'page callback' => 'drupal_get_form',
    'page arguments' => array('custom_admin__overall_settings'),
    'access arguments' => array('access custom administration pages'),
    'file' => 'inc/overall/pages/overall_settings/custom_admin__overall_settings.inc',
    'type' => MENU_NORMAL_ITEM,
    'weight' => -997,
  );
}

/**
 * Sub function for adding permissions for the overall side in hook_permissions()
 */
function custom_admin_overall_permissions(&$permissions) {
  $permissions['access custom administration pages'] = array(
    'title' => t('Access Custom Administration Section'),
    'description' => t('Access Custom Administration Section'),
  );
  $permissions['access custom administration overall settings'] = array(
    'title' => t('Administer Custom Admin - Overall Settings'),
    'description' => t('Administer Custom Admin - Overall Settings'),
  );
}

/**
 * Sub function for adding form altering to the overall side in hook_form_alter()
 */
function custom_admin_overall_form_alters(&$form, &$form_state, $form_id) {
  switch ($form_id) {
  }
}

/**
 * Sub function to add theme items to the system in hook_theme()
 */
function custom_admin_overall_theme($existing, $type, $theme, $path, $module_path, &$theme_array) {
  
  //Site Admin Main Page
  $theme_array['custom_admin__overall_main'] = array(
    'variables' => array(
      'home_vars' => NULL,
    ),
    'template' => 'custom-admin--overall-main',
    'type' => 'theme',
    'path' => $module_path.'/inc/overall/theme',
  );
  
}

/*------------------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------*/
/*                                                 Setup Functions                                            */
/*------------------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------*/
