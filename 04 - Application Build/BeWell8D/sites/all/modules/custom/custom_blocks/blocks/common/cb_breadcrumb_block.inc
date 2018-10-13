<?php
$variables = array();

//Breadcrumb
$breadcrumb = drupal_get_breadcrumb();
$variables['breadcrumb'] = theme('breadcrumb', array('breadcrumb'=>$breadcrumb));

$block['content'] = theme('cb_breadcrumb_block', $variables);
