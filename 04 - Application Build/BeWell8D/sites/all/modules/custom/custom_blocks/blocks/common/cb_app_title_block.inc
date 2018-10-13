<?php
$variables = array();

//App Title
$mobile_app__app_title = variable_get('mobile_app__app_title', 'No Title Set');
$variables['app_title'] = $mobile_app__app_title;

$block['content'] = theme('cb_app_title_block', $variables);
