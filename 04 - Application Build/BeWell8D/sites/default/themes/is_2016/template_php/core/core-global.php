<?php
/* Function to set global vars on every page */
function _global_global_vars(&$variables) {
  //Path Variables
  $variables['path_vars']['current_path'] = current_path();
  $variables['path_vars']['path_alias'] = drupal_lookup_path('alias', $variables['path_vars']['current_path']);
  if($variables['path_vars']['path_alias']){
    $variables['path_vars']['path_arr'] = explode('/', $variables['path_vars']['path_alias']);
  } else {
    $variables['path_vars']['path_arr'] = explode('/', $variables['path_vars']['current_path']);
  }
  
  //Clean Args
  $args_not_clean = arg();
  foreach ($args_not_clean as $value) {
    $variables['clean_args'][] = check_plain($value);
  }
  
  //Clean Query
  $query_not_clean = drupal_get_query_parameters();
  foreach ($query_not_clean as $key => $value) {
    if (is_array($value)) {
      foreach ($value as $val) {
        $variables['clean_query'][$key][] = check_plain($val);
      }
    } else {
      $variables['clean_query'][$key] = check_plain($value);
    }
  }
  
  _custom_global_vars($variables);
}

/* Function to add drupal libraries to pages globally or partially */
function _global_drupal_libraries(&$variables, $type) {
  switch ($type) {
    case 'html':
      //Add Ajax Form Functionality Gloabally
      drupal_add_library('system', 'drupal.ajax');
      drupal_add_library('system', 'jquery.form');
      break;
    case 'page':
      break;
  }
}

/* Function to add theme_hook_suggestions */
function _global_theme_hook_suggestions(&$variables, $type) {
  //Specific Types
  switch ($type) {
    case 'page':
      //========================================
      // Custom Error Pages ====================
      //========================================
      $header = drupal_get_http_header("status");
      if($header == "404 Not Found") {
        $variables['theme_hook_suggestions'][] = 'page__404';
      }
      if($header == "403 Forbidden") {
        $variables['theme_hook_suggestions'][] = 'page__403';
      }
      //========================================
      // Field Based Page Templates ============
      //========================================
      if (isset($variables['node'])) {
        $node = $variables['node']; //dpm($node);
        //Add Custom Template Suggestions Based on a field in node.
        $custom_page_template = field_get_items('node', $node, 'field_custom_page_template');
        if (!empty($custom_page_template) && !empty($custom_page_template[0]['value'])) {
          $variables['theme_hook_suggestions'][] = 'page__'.check_plain($custom_page_template[0]['value']);
        }
      }
      break;
    case 'node':
      //========================================
      // Field Based Node Templates ============
      //========================================
      if (isset($variables['node'])) {
        $node = $variables['node']; //dpm($node);
        //Add Custom Template Suggestions Based on a field in node.
        $custom_node_template = field_get_items('node', $node, 'field_custom_node_template');
        if (!empty($custom_node_template) && !empty($custom_node_template[0]['value'])) {
          $variables['theme_hook_suggestions'][] = 'node__'.check_plain($custom_node_template[0]['value']);
        }
      }
      break;
  }
}

/* Regions Anywhere */
function _global_regions_anywhere(&$variables, $type = false) {
  //-------------------------------------------------
  // Adding Ability to add regions anywhere ---------
  //-------------------------------------------------
  // Get a list of all the regions for this theme
  // Usage: print render($region['region_name']);
  switch ($type) {
    case 'page':
      foreach (system_region_list($GLOBALS['theme']) as $region_key => $region_name) {
        // Set the region to null initially
        $variables['region'][$region_key] = null;
        // Get the content for each region and add it to the $region variable
        if (isset($variables['page'][$region_key]) && !empty($variables['page'][$region_key])) {
          $variables['region'][$region_key] = $variables['page'][$region_key];
        }
      }
      break;
    case 'views_view':
    case 'block':
    default:
      // Set regions for printing in views templates
      /* Usage: 
      <?php 
      if(isset($regions['sidebarmain'])) {
        foreach ($regions['sidebarmain'] as $weight => $block_data) {
          $block = block_load($block_data['module'], $block_data['delta']);
          $block = _block_render_blocks(array($block));
          $block = _block_get_renderable_array($block);
          print drupal_render($block);
        }
      } ?>*/
      $contexts = context_active_contexts(); //dsm($contexts);
      foreach ($contexts as $context_key => $context_value) {
        if (isset($contexts[$context_key]->reactions['block']['blocks']) && !empty($contexts[$context_key]->reactions['block']['blocks'])) {
          $blocks = $contexts[$context_key]->reactions['block']['blocks'];
          foreach ($blocks as $block_name => $block_value) {
            $variables['regions'][$block_value['region']][$block_value['weight']] = array(
              'module' => $block_value['module'],
              'delta' => $block_value['delta'],
            );
          }
        }
      }
      foreach ($variables['regions'] as $region => $region_value) {
        ksort($variables['regions'][$region]);
      }
      break;
  }
}