<?php

$tab = 'web-push-notifications';

//Push Notifications Schedule (On/Off)
$web_view__push_notifications_schedule_on_off = variable_get('web_view__push_notifications_schedule_on_off');
//dsm($web_view__push_notifications_schedule_on_off);
$form[$tab]['web_view__push_notifications_schedule_on_off'] = array(
  '#type' => 'radios',
  '#title' => t('Turn Push Notifications Schedule (On/Off)'),
  '#default_value' => (isset($web_view__push_notifications_schedule_on_off)) ? $web_view__push_notifications_schedule_on_off : 'off',
  '#description' => t('When this option is turned off, no scheduled app push notifications will be sent. <br>When push notifications are on, a schedule will start with the last dimension used notification set first.'),
  '#options' => array(
    'on' => 'On',
    'off' => 'Off',
  ),
);

// //Number Of (Days) Between Sheduled Push Notifications
// $web_view__push_notifications_days_between_schedule = variable_get('web_view__push_notifications_days_between_schedule');
// //dsm($web_view__push_notifications_days_between_schedule);
// $form[$tab]['web_view__push_notifications_days_between_schedule'] = array(
//   '#type' => 'textfield', 
//   '#title' => t('Number Of (Days) Between Sheduled Push Notifications'), 
//   '#default_value' => (isset($web_view__push_notifications_days_between_schedule)) ? $web_view__push_notifications_days_between_schedule : '4',
//   '#size' => 10, 
//   '#maxlength' => 10, 
//   '#required' => TRUE,
// );

?>
