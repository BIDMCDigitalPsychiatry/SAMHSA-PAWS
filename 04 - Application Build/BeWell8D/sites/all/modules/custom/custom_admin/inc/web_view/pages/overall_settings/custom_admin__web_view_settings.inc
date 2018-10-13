<?php

function custom_admin__web_view_settings($form, $form_state) {
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
    '#markup' => t('<h1 style="font-size:18px; padding-bottom:18px;">Web View Settings</h1>'),
  );

  $form['settings_tabs'] = array(
    '#type' => 'vertical_tabs',
    '#default_tab' => 'web-home',
  );

  // // ------------------------------- TAB SETTINGS ------------------------------

  $form['web-home'] = array(
    '#type' => 'fieldset',
    '#title' => t('Home'),
    '#collapsible' => TRUE,
    '#group' => 'settings_tabs',
  );
  $form['web-samhsa-footer'] = array(
    '#type' => 'fieldset',
    '#title' => t('SAMHSA Footer'),
    '#collapsible' => TRUE,
    '#group' => 'settings_tabs',
  );
  $form['web-push-notifications'] = array(
    '#type' => 'fieldset',
    '#title' => t('Push Notifications'),
    '#collapsible' => TRUE,
    '#group' => 'settings_tabs',
  );


  // // ------------------------------- TAB FIELDS -------------------------------
  include drupal_get_path('module','custom_admin').'/inc/web_view/pages/overall_settings/fields/web-home.inc';
  include drupal_get_path('module','custom_admin').'/inc/web_view/pages/overall_settings/fields/web-samhsa-footer.inc';
  include drupal_get_path('module','custom_admin').'/inc/web_view/pages/overall_settings/fields/web-push-notifications.inc';

  $form = system_settings_form($form);
  
  //Make sure custom submit runs first
  array_unshift($form['#submit'], 'custom_admin__web_view_settings_submit');
  
  return $form;
}

/**
 * We need a custom subit function to handle the submitting of images in a config form
 * to make sure the images save permanently as files in the system.
 */

function custom_admin__web_view_settings_submit($form, $form_state) {
  
  // Run Push Notifications Rules Events
  $current_push_value = variable_get('web_view__push_notifications_schedule_on_off', 'off');
  $new_push_value = $form_state['values']['web_view__push_notifications_schedule_on_off'];
  //dpm($current_push_value, '$current_push_value');
  //dpm($new_push_value, '$new_push_value');
    //Push Schedule On
    if ($current_push_value == 'off' && $new_push_value == 'on') {
      //drupal_set_message('Push Notifications Schedule has been turned (ON).');
      rules_invoke_event('custom_rules_push_notification_schedule_on');
    }
    //Push Schedule Off
    if ($new_push_value == 'off') {
      //drupal_set_message('Push Notifications Schedule has been turned (OFF).');
      rules_invoke_event('custom_rules_push_notification_schedule_off');
    }
}