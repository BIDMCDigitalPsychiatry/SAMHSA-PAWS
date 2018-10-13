<?php
$variables = array();
global $user;
$variables['global_user'] = $user;
$variables['base_path'] = base_path();
$variables['path_to_theme'] = path_to_theme();
$variables['logo_path'] = base_path().path_to_theme().'/images/global/samhsa-logo.png';
$variables['logo_image'] = '<img src="'.$variables['logo_path'].'" alt="SAMHSA Logo" />';
$variables['logo_link'] = l($variables['logo_image'], 'https://www.samhsa.gov/', array(
    'query' => array(),
    'attributes' => array(
      'title' => t('SAMHSA'),
      'class' => array('samhsa-logo-link'),
    ),
    'html' => TRUE,
  )
);

//App Title
$mobile_app__app_title = variable_get('mobile_app__app_title', 'No Title Set');
$variables['app_title'] = $mobile_app__app_title;

$web_view__samhsa_footer_text_area = variable_get('web_view__samhsa_footer_text_area');
$web_view__samhsa_footer_text_area_markup = check_markup($web_view__samhsa_footer_text_area['value'], $web_view__samhsa_footer_text_area['format'], '', FALSE);
$variables['text'] = $web_view__samhsa_footer_text_area_markup;

$block['content'] = theme('cb_samhsa_block', $variables);
