<?php

$tab = 'app-home';

//Slide Body Area
$mobile_app__home_slide_1_body_area = variable_get('mobile_app__home_slide_1_body_area');
//dsm($mobile_app__home_slide_1_body_area);
$form[$tab]['mobile_app__home_slide_1_body_area'] = array(
  '#type' => 'text_format',
  '#title' => t('Slider - Slide 1 Body'),
  '#default_value' => (isset($mobile_app__home_slide_1_body_area['value'])) ? $mobile_app__home_slide_1_body_area['value'] : "Slide Body Area",
  '#required' => TRUE,
  '#base_type' => 'textarea',
  '#format' => (isset($mobile_app__home_slide_1_body_area['format'])) ? $mobile_app__home_slide_1_body_area['format'] : NULL,
);

$form[$tab]['slide_sep_1'] = array(
  '#type' => 'markup',
  '#markup' => t('<hr style="margin: 50px 0px; " />'),
);


//Slide Body Area
$mobile_app__home_slide_2_body_area = variable_get('mobile_app__home_slide_2_body_area');
//dsm($mobile_app__home_slide_2_body_area);
$form[$tab]['mobile_app__home_slide_2_body_area'] = array(
  '#type' => 'text_format',
  '#title' => t('Slider - Slide 2 Body'),
  '#default_value' => (isset($mobile_app__home_slide_2_body_area['value'])) ? $mobile_app__home_slide_2_body_area['value'] : "Slide Body Area",
  '#required' => TRUE,
  '#base_type' => 'textarea',
  '#format' => (isset($mobile_app__home_slide_2_body_area['format'])) ? $mobile_app__home_slide_2_body_area['format'] : NULL,
);

$form[$tab]['slide_sep_2'] = array(
  '#type' => 'markup',
  '#markup' => t('<hr style="margin: 50px 0px; " />'),
);


//Slide Body Area
$mobile_app__home_slide_3_body_area = variable_get('mobile_app__home_slide_3_body_area');
//dsm($mobile_app__home_slide_3_body_area);
$form[$tab]['mobile_app__home_slide_3_body_area'] = array(
  '#type' => 'text_format',
  '#title' => t('Slider - Slide 3 Body'),
  '#default_value' => (isset($mobile_app__home_slide_3_body_area['value'])) ? $mobile_app__home_slide_3_body_area['value'] : "Slide Body Area",
  '#required' => TRUE,
  '#base_type' => 'textarea',
  '#format' => (isset($mobile_app__home_slide_3_body_area['format'])) ? $mobile_app__home_slide_3_body_area['format'] : NULL,
);



?>
