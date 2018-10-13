<?php

function custom_admin__mobile_app_settings($form, $form_state) {
  global $user;
  $form = array();
  $form['#attached']['css'] = array(
    drupal_get_path('module', 'field_group') . '/horizontal-tabs/horizontal-tabs.css',
  );
  $form['#attached']['js'] = array(
    drupal_get_path('module', 'field_group') . '/horizontal-tabs/horizontal-tabs.js',
  );
  $form['settings_markup'] = array(
    '#type' => 'markup',
    '#markup' => t('<h1 style="font-size:18px; padding-bottom:18px;">Mobile App Settings</h1>'),
  );

  $form['settings_tabs'] = array(
    '#type' => 'vertical_tabs',
    '#default_tab' => 'app-all',
  );

  // // ------------------------------- TAB SETTINGS ------------------------------

  $form['app-all'] = array(
    '#type' => 'fieldset',
    '#title' => t('All Pages'),
    '#collapsible' => TRUE,
    '#group' => 'settings_tabs',
  );
  $form['app-user'] = array(
    '#type' => 'fieldset',
    '#title' => t('User Authentication/Registration Pages'),
    '#collapsible' => TRUE,
    '#group' => 'settings_tabs',
  );
  $form['app-home'] = array(
    '#type' => 'fieldset',
    '#title' => t('Home'),
    '#collapsible' => TRUE,
    '#group' => 'settings_tabs',
  );
  $form['app-tour'] = array(
    '#type' => 'fieldset',
    '#title' => t('Tour'),
    '#collapsible' => TRUE,
    '#group' => 'settings_tabs',
  );


  // // ------------------------------- TAB FIELDS -------------------------------
  include drupal_get_path('module','custom_admin').'/inc/mobile_app/pages/overall_settings/fields/app-all.inc';
  include drupal_get_path('module','custom_admin').'/inc/mobile_app/pages/overall_settings/fields/app-user.inc';
  include drupal_get_path('module','custom_admin').'/inc/mobile_app/pages/overall_settings/fields/app-home.inc';
  include drupal_get_path('module','custom_admin').'/inc/mobile_app/pages/overall_settings/fields/app-tour.inc';

  $form = system_settings_form($form);
  //$form['#submit'][] = 'custom_admin__mobile_app_settings_submit';

  return $form;
}

/**
 * We need a custom subit function to handle the submitting of images in a config form
 * to make sure the images save permanently as files in the system.
 */

function custom_admin__mobile_app_settings_submit($form, $form_state) {
}