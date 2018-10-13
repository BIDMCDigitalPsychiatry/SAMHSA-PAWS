<?php

$tab = 'app-tour';

//Section Body Area
$mobile_app__tour_overall_body_area = variable_get('mobile_app__tour_overall_body_area');
//dsm($mobile_app__tour_overall_body_area);
$form[$tab]['mobile_app__tour_overall_body_area'] = array(
  '#type' => 'text_format',
  '#title' => t('Tour - Main'),
  '#default_value' => (isset($mobile_app__tour_overall_body_area['value'])) ? $mobile_app__tour_overall_body_area['value'] : "Overall Body Area",
  '#required' => TRUE,
  '#base_type' => 'textarea',
  '#format' => (isset($mobile_app__tour_overall_body_area['format'])) ? $mobile_app__tour_overall_body_area['format'] : NULL,
);

$form[$tab]['section_sep_1'] = array(
  '#type' => 'markup',
  '#markup' => t('<hr style="margin: 50px 0px; " />'),
);

//Section Body Area
$mobile_app__tour_section_1_body_area = variable_get('mobile_app__tour_section_1_body_area');
//dsm($mobile_app__tour_section_1_body_area);
$form[$tab]['mobile_app__tour_section_1_body_area'] = array(
  '#type' => 'text_format',
  '#title' => t('Tour - Set Your Goals'),
  '#default_value' => (isset($mobile_app__tour_section_1_body_area['value'])) ? $mobile_app__tour_section_1_body_area['value'] : "Section Body Area",
  '#required' => TRUE,
  '#base_type' => 'textarea',
  '#format' => (isset($mobile_app__tour_section_1_body_area['format'])) ? $mobile_app__tour_section_1_body_area['format'] : NULL,
);

$form[$tab]['section_sep_2'] = array(
  '#type' => 'markup',
  '#markup' => t('<hr style="margin: 50px 0px; " />'),
);


//Section Body Area
$mobile_app__tour_section_2_body_area = variable_get('mobile_app__tour_section_2_body_area');
//dsm($mobile_app__tour_section_2_body_area);
$form[$tab]['mobile_app__tour_section_2_body_area'] = array(
  '#type' => 'text_format',
  '#title' => t('Tour - Activities'),
  '#default_value' => (isset($mobile_app__tour_section_2_body_area['value'])) ? $mobile_app__tour_section_2_body_area['value'] : "Section Body Area",
  '#required' => TRUE,
  '#base_type' => 'textarea',
  '#format' => (isset($mobile_app__tour_section_2_body_area['format'])) ? $mobile_app__tour_section_2_body_area['format'] : NULL,
);

$form[$tab]['section_sep_3'] = array(
  '#type' => 'markup',
  '#markup' => t('<hr style="margin: 50px 0px; " />'),
);


//Section Body Area
$mobile_app__tour_section_3_body_area = variable_get('mobile_app__tour_section_3_body_area');
//dsm($mobile_app__tour_section_3_body_area);
$form[$tab]['mobile_app__tour_section_3_body_area'] = array(
  '#type' => 'text_format',
  '#title' => t('Tour - Resources'),
  '#default_value' => (isset($mobile_app__tour_section_3_body_area['value'])) ? $mobile_app__tour_section_3_body_area['value'] : "Section Body Area",
  '#required' => TRUE,
  '#base_type' => 'textarea',
  '#format' => (isset($mobile_app__tour_section_3_body_area['format'])) ? $mobile_app__tour_section_3_body_area['format'] : NULL,
);

$form[$tab]['section_sep_4'] = array(
  '#type' => 'markup',
  '#markup' => t('<hr style="margin: 50px 0px; " />'),
);


//Section Body Area
$mobile_app__tour_section_4_body_area = variable_get('mobile_app__tour_section_4_body_area');
//dsm($mobile_app__tour_section_4_body_area);
$form[$tab]['mobile_app__tour_section_4_body_area'] = array(
  '#type' => 'text_format',
  '#title' => t('Tour - Track Your Progress'),
  '#default_value' => (isset($mobile_app__tour_section_4_body_area['value'])) ? $mobile_app__tour_section_4_body_area['value'] : "Section Body Area",
  '#required' => TRUE,
  '#base_type' => 'textarea',
  '#format' => (isset($mobile_app__tour_section_4_body_area['format'])) ? $mobile_app__tour_section_4_body_area['format'] : NULL,
);

$form[$tab]['section_sep_5'] = array(
  '#type' => 'markup',
  '#markup' => t('<hr style="margin: 50px 0px; " />'),
);


//Section Body Area
$mobile_app__tour_section_5_body_area = variable_get('mobile_app__tour_section_5_body_area');
//dsm($mobile_app__tour_section_5_body_area);
$form[$tab]['mobile_app__tour_section_5_body_area'] = array(
  '#type' => 'text_format',
  '#title' => t('Tour - Recieve Messages'),
  '#default_value' => (isset($mobile_app__tour_section_5_body_area['value'])) ? $mobile_app__tour_section_5_body_area['value'] : "Section Body Area",
  '#required' => TRUE,
  '#base_type' => 'textarea',
  '#format' => (isset($mobile_app__tour_section_5_body_area['format'])) ? $mobile_app__tour_section_5_body_area['format'] : NULL,
);

?>
