<?php
/**
 * Sub function for adding admin pages for the overall side in hook_menu()
 */
function custom_admin_web_view_menu_items(&$items) {
  //Web View Site Settings
  $items['admin/site-admin/web-view'] = array(
    'title' => 'Web View Settings',
    'description' => 'This settings page will contain items that deal with the web view.',
    'page callback' => 'drupal_get_form',
    'page arguments' => array('custom_admin__web_view_settings'),
    'access arguments' => array('access custom administration web view settings'),
    'file' => 'inc/web_view/pages/overall_settings/custom_admin__web_view_settings.inc',
    'type' => MENU_NORMAL_ITEM,
    'weight' => -996,
  );
}

/**
 * Sub function for adding permissions for the overall side in hook_permissions()
 */
function custom_admin_web_view_permissions(&$permissions) {
  $permissions['access custom administration web view settings'] = array(
    'title' => t('Administer Custom Admin - Web View Settings'),
    'description' => t('Administer Custom Admin - Web View Settings'),
  );
}

/**
 * Sub function for adding form altering to the overall side in hook_form_alter()
 */
function custom_admin_web_view_form_alters(&$form, &$form_state, $form_id) {
  switch ($form_id) {
  }
}

/**
 * Sub function to add theme items to the system in hook_theme()
 */
function custom_admin_web_view_theme($existing, $type, $theme, $path, $module_path, &$theme_array) {
  
}

/*------------------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------*/
/*                                                 Setup Functions                                            */
/*------------------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------*/
