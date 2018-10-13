<?php
$variables = array();
global $user;
$variables['page_title'] = drupal_get_title();

$block['content'] = theme('cb_page_title_block', $variables);
