<?php
function custom_page__mobile_app_my_achievements_progress_json($user_uid) {
  $variables = array();
  global $user;
  $user_account = user_load($user_uid);
  $user_settings = node_load($user_account->field_user_settings_node['und'][0]['target_id']);
  
  //Check to make sure current user is looking for the correct results
  if (isset($user_settings->nid) && $user->uid == $user_settings->uid) {
    if (isset($user_settings->field_user_wellness_goal_points['und'][0]['value'])) {
      $user_wg_pnts_ary = json_decode($user_settings->field_user_wellness_goal_points['und'][0]['value'], true);
    } else {
      $user_wg_pnts_ary = array();
    }

    //Get array of all taxonomy terms for demensions$query = new EntityFieldQuery();
    $vid = 1; //Eight demensions voc.
    $query = new EntityFieldQuery();
    $result = $query
    ->entityCondition('entity_type', 'taxonomy_term')
    ->propertyCondition('vid', (int) $vid, '=')
    ->propertyOrderBy('weight')
    ->execute();
    $taxonomy_term_ids = array();
    foreach ($result['taxonomy_term'] as $term) {
      $taxonomy_term_ids[$term->tid] = $term->tid;
    }
    $taxonomy_term_entities = taxonomy_term_load_multiple($taxonomy_term_ids);
    
    //Get allready completed activity nids
    $comp_act_str = '';
    $comp_act_ary = array();
    if (isset($user_settings->field_user_completed_activities['und'])) {
      $ae_count = count($user_settings->field_user_completed_activities['und']);
      for ($ae_counter = 0; $ae_counter < $ae_count; $ae_counter++) {
        if (!in_array($user_settings->field_user_completed_activities['und'][$ae_counter]['target_id'], $comp_act_ary) && $ae_counter == 0) {
          $comp_act_str .=  $user_settings->field_user_completed_activities['und'][$ae_counter]['target_id'];
          $comp_act_ary[] = $user_settings->field_user_completed_activities['und'][$ae_counter]['target_id'];
        } elseif (!in_array($user_settings->field_user_completed_activities['und'][$ae_counter]['target_id'], $comp_act_ary)) {
          $comp_act_str .=  '+' . $user_settings->field_user_completed_activities['und'][$ae_counter]['target_id'];
          $comp_act_ary[] = $user_settings->field_user_completed_activities['und'][$ae_counter]['target_id'];
        }
      }
    }
    
    $variables['progress'] = array();
    $progress = &$variables['progress'];
    
    //Wg Progress
    foreach ($taxonomy_term_entities as $term_id => $term) {
      //Term Name
      $progress[$term_id]['wg_name'] = check_plain($term->name);
      $progress[$term_id]['wg_class'] = $term->field_class['und'][0]['value'];
      $progress[$term_id]['wg_id'] = $term_id;
      //Determine Points
      if (isset($user_wg_pnts_ary[$term_id])) {
        $points = (int) $user_wg_pnts_ary[$term_id];
      } else {
        $points = 0;
      }
      $progress[$term_id]['points'] = $points;
      $progress[$term_id]['points_fmt'] = number_format($points);
      
      //Determine Activities Completed
      $act_res_minus_cmplt = views_get_view_result('mobile_app_my_wellness_goal_activities', 'activities_check', 'all', $term_id, $comp_act_str);
      $act_res_minus_cmplt_count = count($act_res_minus_cmplt);
      $act_res_all = views_get_view_result('mobile_app_my_wellness_goal_activities', 'activities_check', 'all', $term_id, 'all');
      $act_res_all_count = count($act_res_all);
      
      $progress[$term_id]['act_comp'] = $act_res_all_count - $act_res_minus_cmplt_count;
      $progress[$term_id]['act_all'] = $act_res_all_count;
      
      if($progress[$term_id]['act_comp'] !== 0) {
        $progress[$term_id]['act_prcnt_comp'] = $progress[$term_id]['act_comp']/$progress[$term_id]['act_all'];
        $progress[$term_id]['act_prcnt_comp_cln'] = number_format( $progress[$term_id]['act_prcnt_comp'] * 100 );
      } else {
        $progress[$term_id]['act_prcnt_comp'] = 0;
        $progress[$term_id]['act_prcnt_comp_cln'] = 0;
      }

    }
    
    //Global Progress
    $progress['global']['wg_name'] = 'Global';
    $progress['global']['wg_class'] = 'global';
    $progress['global']['wg_id'] = 'global';
    $global_points = (isset($user_settings->field_user_total_activity_points['und'][0]['value']) ? (int) $user_settings->field_user_total_activity_points['und'][0]['value'] : 0);
    $progress['global']['points'] = $global_points;
    $progress['global']['points_fmt'] = number_format($global_points);
    
    //Determine Activities Completed
    $act_res_minus_cmplt = views_get_view_result('mobile_app_my_wellness_goal_activities', 'global_activities_check', 'all', $comp_act_str);
    $act_res_minus_cmplt_count = count($act_res_minus_cmplt);
    $act_res_all = views_get_view_result('mobile_app_my_wellness_goal_activities', 'global_activities_check', 'all', 'all');
    $act_res_all_count = count($act_res_all);
    
    $progress['global']['act_comp'] = $act_res_all_count - $act_res_minus_cmplt_count;
    $progress['global']['act_all'] = $act_res_all_count;
    
    if($progress['global']['act_comp'] !== 0) {
      $progress['global']['act_prcnt_comp'] = $progress['global']['act_comp']/$progress['global']['act_all'];
      $progress['global']['act_prcnt_comp_cln'] = number_format( $progress['global']['act_prcnt_comp'] * 100 );
    } else {
      $progress['global']['act_prcnt_comp'] = 0;
      $progress['global']['act_prcnt_comp_cln'] = 0;
    }
    
    //Rekey Prgress
    $progress = array_values($progress);

  }
  
  return $variables;

}
