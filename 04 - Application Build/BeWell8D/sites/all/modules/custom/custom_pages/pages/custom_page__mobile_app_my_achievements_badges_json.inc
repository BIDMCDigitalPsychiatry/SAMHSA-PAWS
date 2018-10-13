<?php
function custom_page__mobile_app_my_achievements_badges_json($user_uid) {
  $variables = array();
  global $user;
  $user_account = user_load($user_uid);
  $user_settings = node_load($user_account->field_user_settings_node['und'][0]['target_id']);
  
  $ae_b_str = '';
  $ae_b_ary = array();
  
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
  
  //Check to make sure current user is looking for the correct results
  if (isset($user_settings->nid) && $user->uid == $user_settings->uid) {
    //Get users current badges
    $badge_results = views_get_view_result('mobile_app_my_wellness_goal_activity_badges_list', 'badges_by_nid', $ae_b_str);
    foreach ($badge_results as $badge) {
      $badge_id = (int) $badge->nid;
      $badge_name = $badge->node_title;
      $badge_type = $badge->field_field_badge_type[0]['rendered']['#markup'];
      if (isset($badge->field_field_activity_type[0]['rendered']['#markup'])) {
        $badge_act_type = $badge->field_field_activity_type[0]['rendered']['#markup'];
      } else {
        $badge_act_type = null;
      }
      if (isset($badge->field_field_badge_points_accumulated[0]['rendered']['#markup'])) {
        $badge_pnts = $badge->field_field_badge_points_accumulated[0]['rendered']['#markup'];
      } else {
        $badge_pnts = null;
      }
      
      if (isset($badge->field_field_wellness_goal_relation[0]['rendered']['#markup'])) {
        //This is a WG Badge
        $wg_name = $badge->field_field_wellness_goal_relation[0]['rendered']['#markup'];
        $wg_id = (int) $badge->field_field_wellness_goal_relation[0]['raw']['target_id'];
        $wg_entity = $badge->field_field_wellness_goal_relation[0]['raw']['entity'];
        //dpm($wg_entity);
        $wg_weight = (int) $wg_entity->weight;
        $wg_class = $wg_entity->field_class['und'][0]['safe_value'];
        foreach ($wg_entity->field_badges['und'] as $wg_entity_badge_delta => $wg_entity_badge) {
          if ($wg_entity_badge['target_id'] == $badge_id) {
            $badge_delta = (int) $wg_entity_badge_delta;
          }
        }
        
        $variables['badges'][$wg_weight][$badge_delta]['wg_name'] = $wg_name;
        $variables['badges'][$wg_weight][$badge_delta]['wg_id'] = $wg_id;
        $variables['badges'][$wg_weight][$badge_delta]['wg_class'] = $wg_class;
        
        $variables['badges'][$wg_weight][$badge_delta]['badge_id'] = $badge_id;
        $variables['badges'][$wg_weight][$badge_delta]['badge_delta'] = $badge_delta;
        $variables['badges'][$wg_weight][$badge_delta]['badge_name'] = $badge_name;
        $variables['badges'][$wg_weight][$badge_delta]['badge_type'] = $badge_type;
        $variables['badges'][$wg_weight][$badge_delta]['badge_act_type'] = $badge_act_type;
        $variables['badges'][$wg_weight][$badge_delta]['badge_pnts'] = $badge_pnts;
      } else {
        //This is a global Badge
        $variables['badges'][9999][$badge_id]['wg_name'] = 'Global';
        $variables['badges'][9999][$badge_id]['wg_id'] = 'global';
        $variables['badges'][9999][$badge_id]['wg_class'] = 'global';
        
        $variables['badges'][9999][$badge_id]['badge_id'] = $badge_id;
        $variables['badges'][9999][$badge_id]['badge_delta'] = '0';
        $variables['badges'][9999][$badge_id]['badge_name'] = $badge_name;
        $variables['badges'][9999][$badge_id]['badge_type'] = $badge_type;
        $variables['badges'][9999][$badge_id]['badge_act_type'] = $badge_act_type;
        $variables['badges'][9999][$badge_id]['badge_pnts'] = $badge_pnts;
      }
    }
    
    //Sort Array
    ksort($variables['badges']);
    foreach ($variables['badges'] as $wg_key => $wg) {
      ksort($variables['badges'][$wg_key]);
    }
    
    //Rekey Array
    $variables['badges'] = array_values($variables['badges']);
    foreach ($variables['badges'] as $wg_key => $wg) {
      $variables['badges'][$wg_key] = array_values($variables['badges'][$wg_key]);
    }
    
    //dpm($variables['badges'], 'User Badges');
  }
  
  return $variables;
}
