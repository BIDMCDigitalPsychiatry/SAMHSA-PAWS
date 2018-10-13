<?php

/**
 * function to check user roles
 * @roles_allowed is an array of roles that will pass as true
 * @roles is an array of roles of the currently checked user
 */
function _drupal_user_check_roles($roles_allowed, $roles) {
  $truthiness = 'FALSE';
  foreach ($roles_allowed as $value) {
    if(in_array($value, array_values($roles))) {
      $truthiness = 'TRUE';
    }
  }
  return $truthiness;
}

/**
 * Returns a clean string based on perams using ctools_cleanstring
 * function found at modules/contrib/ctools/includes/cleanstring.inc
 */
function _drupal_get_cleanstring($string, $settings = array()) {
  //My Defaults that can be overridden
  $settings += array(
    'clean slash' => TRUE,
    'ignore words' => array(),
    'separator' => '-',
    'replacements' => array(),
    'transliterate' => FALSE,
    'reduce ascii' => TRUE,
    'max length' => FALSE,
    'lower case' => TRUE,
  );

  if(module_exists('ctools') !== FALSE) {
    ctools_include('cleanstring');
    if (function_exists('ctools_cleanstring')) {
      $output =  ctools_cleanstring($string, $settings);
    } else {
      $output = "null";
    }
  } else {
    $output = "null";
  }

  return $output;
}

/*Get Active Trail Top Level Title or Title Class*/
function _drupal_get_menu_top_level_active_trail($type = 'MENU', $style = 'TITLE') {
  $activetrail = menu_get_active_trail();
  $topparent_title = '';
  $topparent_title_class = 'none';
  
  dsm($activetrail);

  //Get the active trial
  if (isset($activetrail[1]['title']) && !empty($activetrail[1]['title']) && $activetrail[1]['menu_name'] != 'navigation') {
    if ($type == 'MENU') {
      //Menu Based
      $topparent_title = $activetrail[1]['title'];
      $topparent_title_class = _drupal_get_cleanstring($topparent_title);
    }
    elseif ($type == 'CONTENT' && !empty($activetrail[1]['link_path'])) {
      //Content Title Based
      $explode_path = explode('/', $activetrail[1]['link_path']);
      switch ($explode_path[0]) {
        case 'node':
          $title = db_query('SELECT title FROM {node} WHERE nid = :nid', array(':nid' => $explode_path[1]))->fetchField();
          $topparent_title = check_plain($title);
          $topparent_title_class = _drupal_get_cleanstring($topparent_title);
          break;
      }
    }
  } else {
    //Content Title Based
    $current_path = current_path();
    $explode_path = explode('/', $current_path);
    switch ($explode_path[0]) {
      case 'node':
        $title = db_query('SELECT title FROM {node} WHERE nid = :nid', array(':nid' => $explode_path[1]))->fetchField();
        $topparent_title = check_plain($title);
        $topparent_title_class = _drupal_get_cleanstring($topparent_title);
        break;
    }
  }

  //Trail overrides
  /*if (isset($activetrail[3]) && $activetrail[3]['title'] == 'Pathway Analyses Toolkit') {
    $topparent_title = 'Pathway Analyses Toolkit';
    $topparent_title_class = 'pathway-analyses-toolkit';
  }*/

  //Output
  if (!empty($topparent_title)) {
    switch ($style) {
      case 'TITLE':
        return $topparent_title;
        break;

      case 'CLASS':
        return $topparent_title_class;
        break;

      default:
        return $topparent_title;
        break;
    }
  } else {
    switch ($style) {
      case 'TITLE':
        return '';
        break;

      case 'CLASS':
        return 'none';
        break;

      default:
        return '';
        break;
    }
  }
}

/**
 * Get Drupal List Field Value from key
 */
function _drupal_get_list_value_from_key($field_name = '', $key_value = '') {
  $fields = field_info_fields();
  $allowed_values = list_allowed_values($fields[$field_name]);
  //dsm($allowed_values);
  return $allowed_values[$key_value];
}

/**
 * Get the users name from their id and possible the realname version
 */
function _drupal_get_username_from_uid($id, $use_realname = FALSE) {
  $username = NULL;
  if($use_realname === FALSE) {
    $sql = "SELECT name FROM {users} WHERE uid = ".$id;
    $results = db_query($sql);
    foreach ($results as $key => $result) {
      $username = $result->name;
    }
    return $username;
  } else if ($use_realname === TRUE) {
    $sql = "SELECT realname FROM {realname} WHERE uid = ".$id;
    $results = db_query($sql);
    foreach ($results as $key => $result) {
      $username = $result->realname;
    }
    return $username;
  }
}

/**
 * Use these to functions to get next/previous links for a menu page your currently on
 */
function _drupal_get_menu_next_prev_links($menu_name = 'primary-links'){
  $links = array();

  // get current mid
  $trail = menu_get_active_trail(); //dsm($trail);
  $trail_length = count($trail) - 1;
  if (isset($trail[1]['mlid']) && !empty($trail[1]['mlid'])) {
    $links['current-mid'] = $trail[$trail_length]['mlid'];
  }

  // get current menu item
  $current_menu_item = menu_get_item();
  if($current_menu_item){
    if(isset($links['current-mid']) && !empty($links['current-mid'])){
      // path is in menu so traverse and flatten all menu items
      $menu_links_tree = menu_tree_all_data($menu_name);
      $links['all'] = $menu_links_tree;
      $menu_links_tree_flattened = _drupal_get_menu_next_prev_links_flatten_tree($menu_links_tree);
      $links['allflat'] = $menu_links_tree_flattened;
      // get index of current menu item in flattened tree to determin next previous by position in array
      $mlid_tree_index = array_search(intval($links['current-mid']), $menu_links_tree_flattened);
      if(is_int($mlid_tree_index)){
        if($mlid_tree_index == 0){
          //first item in tree
          $links['next'] = menu_link_load($menu_links_tree_flattened[$mlid_tree_index+1]);
          $links['prev'] = menu_link_load($menu_links_tree_flattened[count($menu_links_tree_flattened)-1]);
        } else if ($mlid_tree_index == ( count($menu_links_tree_flattened) -1 ) ) {
          //last item in tree
          $links['next'] = menu_link_load($menu_links_tree_flattened[0]);
          $links['prev'] = menu_link_load($menu_links_tree_flattened[$mlid_tree_index-1]);
        } else {
          //normal
          $links['next'] = menu_link_load($menu_links_tree_flattened[$mlid_tree_index+1]);
          $links['prev'] = menu_link_load($menu_links_tree_flattened[$mlid_tree_index-1]);
        }
      }
    }
  }
  //dsm($links);
  return $links;
}
function _drupal_get_menu_next_prev_links_flatten_tree($tree){
  $links = array();
  foreach($tree as $item){
    $links[] = intval($item['link']['mlid']);
    if(is_array($item['below'])){
      $links = array_merge_recursive($links,_drupal_get_menu_next_prev_links_flatten_tree($item['below']));
    }
  }
  return $links;
}