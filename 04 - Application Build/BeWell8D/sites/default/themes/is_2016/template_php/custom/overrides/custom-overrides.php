<?php

/**
 * Return a themed breadcrumb trail.
 *
 * @param $breadcrumb
 *   An array containing the breadcrumb links.
 * @return a string containing the breadcrumb output.
 */
function _custom_breadcrumb($variables) {
  $breadcrumb = $variables['breadcrumb'];
  $crumbs = '';
  if (!empty($breadcrumb)) {
    $array_size = count($breadcrumb);
    $i = 0;
    while ( $i < $array_size) {
      $crumbs .= '<span>'.$breadcrumb[$i].'</span>';
      if ($i < $array_size - 1) {
        $crumbs .= '<span>&nbsp;&gt;&nbsp;</span>';
      }
      $i++;
    }
    //$crumbs .= '<span>'.drupal_get_title().'</span>';
    return $crumbs;
  } else {
    return null;
  }
}

/**
 * Implements theme_menu_link().
 * Adds Spans inside all links.
 */
function _custom_menu_link($variables) {
  $element = $variables['element'];
  $sub_menu = '';

  if ($element['#below']) {
    $sub_menu = drupal_render($element['#below']);
  }
  if (empty($element['#localized_options'])) {
    $element['#localized_options'] = array();
  }

  $element['#localized_options']['html'] = TRUE; //let l function know that our link title includes html
  $output = l('<span>'.$element['#title'].'</span>', $element['#href'], $element['#localized_options']);
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}