<?php
$variables = array();
global $user;
$variables['global_user'] = $user;
$variables['base_path'] = base_path();
$variables['path_to_theme'] = path_to_theme();
$variables['logo_path'] = base_path().path_to_theme().'/images/header/t3-trauma-institute-logo.png';
$variables['logo_image'] = '<img src="'.$variables['logo_path'].'" alt="C4SI Logo" />';
$variables['logo_link'] = l($variables['logo_image'], '<front>', array(
    'query' => array(),
    'attributes' => array(
      'title' => t('C4SI Logo'),
      'class' => array('logo-link'),
    ),
    'html' => TRUE,
  )
);

$block['content'] = theme('cb_logo_block', $variables);
