<?php
/**
 * Sub function for adding admin pages for the overall side in hook_menu()
 */
function custom_admin_mobile_app_menu_items(&$items) {
  //Mobile App Site Settings
  $items['admin/site-admin/mobile-app'] = array(
    'title' => 'Mobile App Settings',
    'description' => 'This settings page will contain items that deal with the mobile app.',
    'page callback' => 'drupal_get_form',
    'page arguments' => array('custom_admin__mobile_app_settings'),
    'access arguments' => array('access custom administration mobile app settings'),
    'file' => 'inc/mobile_app/pages/overall_settings/custom_admin__mobile_app_settings.inc',
    'type' => MENU_NORMAL_ITEM,
    'weight' => -996,
  );
}

/**
 * Sub function for adding permissions for the overall side in hook_permissions()
 */
function custom_admin_mobile_app_permissions(&$permissions) {
  $permissions['access custom administration mobile app settings'] = array(
    'title' => t('Administer Custom Admin - Mobile App Settings'),
    'description' => t('Administer Custom Admin - Mobile App Settings'),
  );
}

/**
 * Sub function for adding form altering to the overall side in hook_form_alter()
 */
function custom_admin_mobile_app_form_alters(&$form, &$form_state, $form_id) {
  switch ($form_id) {
  }
}

/**
 * Sub function to add theme items to the system in hook_theme()
 */
function custom_admin_mobile_app_theme($existing, $type, $theme, $path, $module_path, &$theme_array) {
  
}

/*------------------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------*/
/*                                                 Setup Functions                                            */
/*------------------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------*/
