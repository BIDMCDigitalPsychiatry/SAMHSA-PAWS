<?php

$tab = 'web-samhsa-footer';

//Samhsa Footer Text
$web_view__samhsa_footer_text_area = variable_get('web_view__samhsa_footer_text_area');
//dsm($web_view__samhsa_footer_text_area);
$form[$tab]['web_view__samhsa_footer_text_area'] = array(
  '#type' => 'text_format',
  '#title' => t('SAMHSA Footer Text'),
  '#default_value' => (isset($web_view__samhsa_footer_text_area['value'])) ? $web_view__samhsa_footer_text_area['value'] : "SAMHSA Footer Text",
  '#required' => TRUE,
  '#base_type' => 'textarea',
  '#format' => (isset($web_view__samhsa_footer_text_area['format'])) ? $web_view__samhsa_footer_text_area['format'] : NULL,
);

?>
