<?php
$variables = array();
$year = date('Y');
$variables['year'] = $year;

$block['content'] = theme('cb_copyright_block', $variables);
