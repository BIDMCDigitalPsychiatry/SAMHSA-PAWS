<?php
function custom_page__mobile_app_activity_complete_json($user_settings_nid, $activity_complete_nid, $wellness_goal_nid) {
  $variables = array();
  global $user;
  $user_settings = node_load($user_settings_nid);
  $activity_complete = node_load($activity_complete_nid);
  $wellness_goal = taxonomy_term_load($wellness_goal_nid);
  
  //Check to make sure current user is looking for the correct results
  if (isset($user_settings->nid) && isset($activity_complete->nid) && isset($wellness_goal->tid) && $user->uid == $user_settings->uid) {
    $activity_type = $activity_complete->field_activity_type['und'][0]['target_id'];
    
    //Base Vars
    $variables['comp_act_ary']        = array($activity_complete_nid);
    $variables['comp_act_str']        = (string) $activity_complete_nid;
    $variables['ae_b_ary']            = array(); 
    $variables['ae_b_str']            = 'all';
    $variables['ae_gl_points']        = (isset($user_settings->field_user_total_activity_points['und'][0]['value']) ? (int) $user_settings->field_user_total_activity_points['und'][0]['value'] : 0);
    $variables['ae_wg_points_json']   = null;
    $variables['ae_wg_points']        = null;
    $variables['nw_b_ary']            = array(); 
    $variables['nw_b_str']            = ''; 
    $variables['nw_b_node_ary']       = array(); 
    $variables['nw_points']           = (int) $activity_complete->field_activity_points['und'][0]['value'];
    $variables['nw_gl_points']        = $variables['nw_points'] + $variables['ae_gl_points'];
    $variables['nw_wg_points_json']   = null;
    $variables['nw_wg_points']        = null;
    
    //Reference base vars for cleaner code.
    $comp_act_ary        = &$variables['comp_act_ary'];
    $comp_act_str        = &$variables['comp_act_str'];
    $ae_b_ary            = &$variables['ae_b_ary']; 
    $ae_b_str            = &$variables['ae_b_str'];
    $ae_gl_points        = &$variables['ae_gl_points'];
    $ae_wg_points_json   = &$variables['ae_wg_points_json'];
    $ae_wg_points        = &$variables['ae_wg_points'];
    $nw_b_ary            = &$variables['nw_b_ary']; 
    $nw_b_str            = &$variables['nw_b_str']; 
    $nw_b_node_ary       = &$variables['nw_b_node_ary']; 
    $nw_points           = &$variables['nw_points'];
    $nw_gl_points        = &$variables['nw_gl_points'];
    $nw_wg_points_json   = &$variables['nw_wg_points_json'];
    $nw_wg_points        = &$variables['nw_wg_points'];
    
    //Get allready earned badge nids
    if (isset($user_settings->field_user_earned_badges['und'])) {
      $ae_count = count($user_settings->field_user_earned_badges['und']);
      $ae_b_str = '';
      for ($ae_counter = 0; $ae_counter < $ae_count; $ae_counter++) {
        if ($ae_counter != $ae_count - 1) {
          $ae_b_str .= $user_settings->field_user_earned_badges['und'][$ae_counter]['target_id'] . '+';
          $ae_b_ary[] = $user_settings->field_user_earned_badges['und'][$ae_counter]['target_id'];
        } else {
          $ae_b_str .= $user_settings->field_user_earned_badges['und'][$ae_counter]['target_id'];
          $ae_b_ary[] = $user_settings->field_user_earned_badges['und'][$ae_counter]['target_id'];
        }
      }
    }
    
    //Get allready completed activity nids
    if (isset($user_settings->field_user_completed_activities['und'])) {
      $ae_count = count($user_settings->field_user_completed_activities['und']);
      for ($ae_counter = 0; $ae_counter < $ae_count; $ae_counter++) {
        if (!in_array($user_settings->field_user_completed_activities['und'][$ae_counter]['target_id'], $comp_act_ary)) {
          $comp_act_str .=  '+' . $user_settings->field_user_completed_activities['und'][$ae_counter]['target_id'];
          $comp_act_ary[] = $user_settings->field_user_completed_activities['und'][$ae_counter]['target_id'];
        }
      }
    }
    
    //Set new wg total points and points json
    if (isset($user_settings->field_user_wellness_goal_points['und'][0]['value']) && !empty($user_settings->field_user_wellness_goal_points['und'][0]['value'])) {
      $ae_wg_points_json = json_decode($user_settings->field_user_wellness_goal_points['und'][0]['value'], true);
      $nw_wg_points_json = $ae_wg_points_json;
    } else {
      $ae_wg_points_json = array();
      $nw_wg_points_json = array();
    }
    if (isset($ae_wg_points_json[$wellness_goal_nid]) && !empty($ae_wg_points_json[$wellness_goal_nid])) {
      $ae_wg_points = $ae_wg_points_json[$wellness_goal_nid];
    } else {
      $ae_wg_points = 0;
    }
    $nw_wg_points = $nw_points + $ae_wg_points;
    $nw_wg_points_json[$wellness_goal_nid] = $nw_wg_points;
    
    // ==== Get Results for each metric and add values to $variables for json return ==== //
    // --------------------- //
    // ----- WG CHECKS ----- //
    // --------------------- //
    //Wellness Goal Points Accumulated Check/Add {poionts_accumulated}
    $badge_results = views_get_view_result('mobile_app_my_wellness_goal_activity_badges', 'badges_check', 'poionts_accumulated', 'all', $wellness_goal_nid, $comp_act_str);
      //dpm($badge_results, '$badge_results -- Wellness Goal Points Accumulated Check/Add {poionts_accumulated}');
      if (!empty($badge_results)) {
        foreach ($badge_results as $key => $badge) {
          if (!in_array((string) $badge->nid, $ae_b_ary)) {
            if ($nw_wg_points >= (int) $badge->field_field_badge_points_accumulated[0]['rendered']['#markup']) {
              $nw_b_ary[] = $badge->nid;
              $nw_b_node_ary[] = $badge;
            }
          }
        }
      }
      
    //Wellness Goal Activity Type Complete Check/Add {activity_type_complete}
    $badge_results = views_get_view_result('mobile_app_my_wellness_goal_activity_badges', 'badges_check', 'activity_type_complete', $activity_type, $wellness_goal_nid, $ae_b_str);
    $activity_results = views_get_view_result('mobile_app_my_wellness_goal_activities', 'activities_check', $activity_type, $wellness_goal_nid, $comp_act_str);
      //dpm($badge_results, '$badge_results -- Wellness Goal Activity Type Complete Check/Add {activity_type_complete}');
      //dpm($activity_results, '$activity_results -- Wellness Goal Activity Type Complete Check/Add {activity_type_complete}');
      if (empty($activity_results) && !empty($badge_results)) {
        foreach ($badge_results as $key => $badge) {
          if ($badge->field_field_activity_type[0]['rendered']['#markup'] == $activity_type) {
            $nw_b_ary[] = $badge->nid;
            $nw_b_node_ary[] = $badge;
          }
        }
      }
      
    //Wellness Goal All Activity Type Complete Check/Add {all_activities_complete}
    $badge_results = views_get_view_result('mobile_app_my_wellness_goal_activity_badges', 'badges_check', 'all_activities_complete', 'all', $wellness_goal_nid, $ae_b_str);
    $activity_results = views_get_view_result('mobile_app_my_wellness_goal_activities', 'activities_check', 'all', $wellness_goal_nid, $comp_act_str);
      //dpm($badge_results, '$badge_results -- Wellness Goal All Activity Type Complete Check/Add {all_activities_complete}');
      //dpm($activity_results, '$activity_results -- Wellness Goal All Activity Type Complete Check/Add {all_activities_complete}');
      if (empty($activity_results) && !empty($badge_results)) {
        foreach ($badge_results as $key => $badge) {
          $nw_b_ary[] = $badge->nid;
          $nw_b_node_ary[] = $badge;
        }
      }
    
    
    // --------------------- //
    // ----- GL CHECKS ----- //
    // --------------------- //
    //Global Points Accumulated Check/Add {poionts_accumulated}
    $badge_results = views_get_view_result('mobile_app_my_wellness_goal_activity_badges', 'global_badges_check', 'poionts_accumulated', 'all', $ae_b_str);
      //dpm($badge_results, '$badge_results -- Global Points Accumulated Check/Add {poionts_accumulated}');
      if (!empty($badge_results)) {
        foreach ($badge_results as $key => $badge) {
          if (!in_array((string) $badge->nid, $ae_b_ary)) {
            if ($nw_gl_points >= (int) $badge->field_field_badge_points_accumulated[0]['rendered']['#markup']) {
              $nw_b_ary[] = $badge->nid;
              $nw_b_node_ary[] = $badge;
            }
          }
        }
      }
      
    //Global Activity Type Complete Check/Add {activity_type_complete}
    $badge_results = views_get_view_result('mobile_app_my_wellness_goal_activity_badges', 'global_badges_check', 'activity_type_complete', $activity_type, $ae_b_str);
    $activity_results = views_get_view_result('mobile_app_my_wellness_goal_activities', 'global_activities_check', $activity_type, $comp_act_str);
      //dpm($badge_results, '$badge_results -- Global Activity Type Complete Check/Add {activity_type_complete}');
      //dpm($activity_results, '$activity_results -- Global Activity Type Complete Check/Add {activity_type_complete}');
      if (empty($activity_results) && !empty($badge_results)) {
        foreach ($badge_results as $key => $badge) {
          if ($badge->field_field_activity_type[0]['rendered']['#markup'] == $activity_type) {
            $nw_b_ary[] = $badge->nid;
            $nw_b_node_ary[] = $badge;
          }
        }
      }
      
    //Global All Activity Type Complete Check/Add {all_activities_complete}
    $badge_results = views_get_view_result('mobile_app_my_wellness_goal_activity_badges', 'global_badges_check', 'all_activities_complete', 'all', $ae_b_str);
    $activity_results = views_get_view_result('mobile_app_my_wellness_goal_activities', 'global_activities_check', 'all', $comp_act_str);
      //dpm($badge_results, '$badge_results -- Global All Activity Type Complete Check/Add {all_activities_complete}');
      //dpm($activity_results, '$activity_results -- Global All Activity Type Complete Check/Add {all_activities_complete}');
      if (empty($activity_results) && !empty($badge_results)) {
        foreach ($badge_results as $key => $badge) {
          $nw_b_ary[] = $badge->nid;
          $nw_b_node_ary[] = $badge;
        }
      }
  }
  
  //Combine new badges into string for views
  if (!empty($nw_b_ary)) {
    $nw_b_str = implode('+', $nw_b_ary);
  }
    
  //dsm($variables, 'All Variables');
  
  return $variables;

}
