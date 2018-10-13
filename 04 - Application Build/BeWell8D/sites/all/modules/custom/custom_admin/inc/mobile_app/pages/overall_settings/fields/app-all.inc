<?php

$tab = 'app-all';

$mobile_app__app_title = variable_get('mobile_app__app_title');
//dsm($mobile_app__app_title);
$form[$tab]['mobile_app__app_title'] = array(
  '#type' => 'textfield',
  '#title' => t('App Title'),
  '#default_value' => (isset($mobile_app__app_title)) ? $mobile_app__app_title : NULL,
  '#size' => 60,
  '#maxlength' => 60,
  '#required' => TRUE,
);


?>
