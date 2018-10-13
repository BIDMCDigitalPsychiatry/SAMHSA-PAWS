<?php

$tab = 'web-home';

//Home Page Body Area
$web_view__home_page_body_area = variable_get('web_view__home_page_body_area');
//dsm($web_view__home_page_body_area);
$form[$tab]['web_view__home_page_body_area'] = array(
  '#type' => 'text_format',
  '#title' => t('Home Page Body'),
  '#default_value' => (isset($web_view__home_page_body_area['value'])) ? $web_view__home_page_body_area['value'] : "Home Page Body Area",
  '#required' => TRUE,
  '#base_type' => 'textarea',
  '#format' => (isset($web_view__home_page_body_area['format'])) ? $web_view__home_page_body_area['format'] : NULL,
);
?>
