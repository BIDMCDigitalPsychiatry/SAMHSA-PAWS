<?php

$tab = 'app-user';

//User Login Page Text
$mobile_app__user_login_page_text = variable_get('mobile_app__user_login_page_text');
//dsm($mobile_app__user_login_page_text);
$form[$tab]['mobile_app__user_login_page_text'] = array(
  '#type' => 'text_format',
  '#title' => t('User Login Page Text'),
  '#default_value' => (isset($mobile_app__user_login_page_text['value'])) ? $mobile_app__user_login_page_text['value'] : "User Login Text",
  '#required' => TRUE,
  '#base_type' => 'textarea',
  '#format' => (isset($mobile_app__user_login_page_text['format'])) ? $mobile_app__user_login_page_text['format'] : NULL,
);

$form[$tab]['field_sep_1'] = array(
  '#type' => 'markup',
  '#markup' => t('<hr style="margin: 50px 0px; " />'),
);

//User Registration Page Text
$mobile_app__user_registration_page_text = variable_get('mobile_app__user_registration_page_text');
//dsm($mobile_app__user_registration_page_text);
$form[$tab]['mobile_app__user_registration_page_text'] = array(
  '#type' => 'text_format',
  '#title' => t('User Registration Page Text'),
  '#default_value' => (isset($mobile_app__user_registration_page_text['value'])) ? $mobile_app__user_registration_page_text['value'] : "User Registration Text",
  '#required' => TRUE,
  '#base_type' => 'textarea',
  '#format' => (isset($mobile_app__user_registration_page_text['format'])) ? $mobile_app__user_registration_page_text['format'] : NULL,
);

$form[$tab]['field_sep_2'] = array(
  '#type' => 'markup',
  '#markup' => t('<hr style="margin: 50px 0px; " />'),
);

//User Forgot Password Page Text
$mobile_app__user_pass_page_text = variable_get('mobile_app__user_pass_page_text');
//dsm($mobile_app__user_pass_page_text);
$form[$tab]['mobile_app__user_pass_page_text'] = array(
  '#type' => 'text_format',
  '#title' => t('User Forgot Password Page Text'),
  '#default_value' => (isset($mobile_app__user_pass_page_text['value'])) ? $mobile_app__user_pass_page_text['value'] : "User Forgot Password Text",
  '#required' => TRUE,
  '#base_type' => 'textarea',
  '#format' => (isset($mobile_app__user_pass_page_text['format'])) ? $mobile_app__user_pass_page_text['format'] : NULL,
);



?>
