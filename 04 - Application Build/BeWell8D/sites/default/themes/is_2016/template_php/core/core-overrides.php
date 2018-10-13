<?php
/**
 * Return a themed breadcrumb trail.
 *
 * @param $breadcrumb
 *   An array containing the breadcrumb links.
 * @return a string containing the breadcrumb output.
 */
function is_2016_breadcrumb($variables) {
  $custom = _custom_breadcrumb($variables);
  return $custom;
}

/**
 * Implements theme_menu_link().
 * Adds Spans inside all links.
 */
function is_2016_menu_link($variables) {
  $custom = _custom_menu_link($variables);
  return $custom;
}
