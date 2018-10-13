// ========================= //
// My Wellness Goal Activity //
// ========================= //

//Callback
function custom_pages_app_my_wellness_goal_activity(param) {
  var params = param.split("-");
  var nid = params[0];
  var pageContainers = '';
  pageContainers += '<div id="app_my_wellness_goal_activity_content_nid_' + nid + '"></div>';
  return pageContainers;
}

//PageShow
function custom_pages_app_my_wellness_goal_activity__ps(param) {
  var params = param.split("-");
  var nid = params[0];
  node_load(nid, {
    success: function(node) {
      //console.log(node);
      //Load the parent Term
      taxonomy_term_load(node.field_wellness_goal_relation.und["0"].target_id, {
        success: function(wellnessGoal) {
          //console.log(wellnessGoal);
          var goalClass = wellnessGoal.field_class.und["0"].safe_value;
          var content = '';
          //Activity Title Section
          content += '<div class="section section-title goal-' + goalClass + '">';
          content += '  <h2 class="h2 -blue -line">' + node.title + '</h2>';
          content += '  <div class="wysiwyg">';
          content += node['field_body'].und['0'].safe_value;
          content += '  </div>';
          content += '  <div class="row-2 t-center">';
          content += '    <div class="col-1">';
          content += '      <span class="i-med i-time">'
          content += node.field_activity_duration_start.und["0"].value + ' - ' + node.field_activity_duration_end.und["0"].value + ' Minutes';
          content += '      </span>';
          content += '    </div>';
          content += '    <div class="col-1">';
          content += '      <span class="i-med i-exclamation-splash">'
          content += node.field_activity_type.und["0"].name;
          content += '      </span>';
          content += '    </div>';
          content += '  </div>';
          content += '</div>';
          
          //Activity Instructions Section
          content += '<div class="section section-med section-grey">';
          content += '  <h3 class="h3 -orange">Instructions</h3>';
          content += '  <div class="wysiwyg">';
          content += node['field_body_2'].und['0'].safe_value;
          content += '  </div>';
          content += '</div>';
          
          //Page Links
          var iPerformedActivity = bl('I did it!', 'app_my_wellness_goal_activity/' + nid + '-' + params[1] + '/complete', {
            'attributes':  {
              'class': 'btn'
            }
          });     
          var backPath = 'app_my_wellness_goal/' + wellnessGoal.tid;
          if (params[1] == 'all') {
            backPath = 'app_my_wellness_goal_all/' + Drupal.user.uid;
          }
          var hideButton = theme_button({
            text : 'Hide Activity',
            attributes: {
              onclick: "custom_pages_app_my_wellness_goal_activity_hide('" + nid + "', 'goto', '" + backPath + "');",
              title: "Hide Activity",
              class: "",
            }
          });
          content += '<div class="section section-med section-grey">';
          content += '  <ul class="page-buttons">';
          content += '    <li>' + iPerformedActivity + '<br></li>';
          content += '    <li><p>It\'s okay if you dont\'t want to do this activity. You can hide it from your activity lists - you can always restore it later. Keep going with other activities to improve your wellness!</p></li>';
          content += '    <li class="t-center t-medium">' + hideButton + '</li>';
          content += '  </ul>';
          content += '</div>';
      
          //Use JS to insert the content
          $('#app_my_wellness_goal_activity_content_nid_' + nid).html(content).trigger('create');
        }
      });
  
    }
  });
}

// ================================== //
// My Wellness Goal Activity Complete //
// ================================== //

//Callback
function custom_pages_app_my_wellness_goal_activity_complete(param) {
  var params = param.split("-");
  var nid = params[0];
  var pageContainers = '';
  pageContainers += '<div id="app_my_wellness_goal_activity_complete_content_nid_' + nid + '"></div>';
  pageContainers += '<div id="app_my_wellness_goal_activity_complete_badges_nid_' + nid + '"></div>';
  pageContainers += '<div id="app_my_wellness_goal_activity_complete_buttons_nid_' + nid + '"></div>';
  return pageContainers;
}

//PageShow
function custom_pages_app_my_wellness_goal_activity_complete__ps(param) {
  //Load Vars
  var params = param.split("-"),
      nid = params[0],
      userUID = Drupal.user.uid;
      
  node_load(nid, {
    success: function(activitynode) {
      
      //Get user settings.
      custom_user_settings_load(userUID, function(userSettings) {
            
        //Perform Activity Complete Actions
        custom_activity_complete_actions(userSettings, activitynode, function(vals) {
          
          //Save User Settings Changes
          custom_update_user_settings_node(vals.userSettings);
          
          //Set Page Content
          var content = '';
          //App Page Title
          content += '<div class="section banner banner-congrats">';
          content += '  <div class="banner--body">';
          content += '    <div class="banner--image -activity">';
          content += '      <div class="banner--image-text">Congratulations!</div>';
          content += '    </div>';
          content += '    <h2 class="banner--title banner--title-large">You Are Making Moves!</h2>';
          content += '    <p class="banner--text">Today you\'ve earned ' + vals.activity_earned_data.nw_points + ' points towards your ' + vals.wellnessGoalTitle + ' goal.</p>';
          content += '  </div>';
          content += '</div>';
          
          //Use JS to insert the content
          $('#app_my_wellness_goal_activity_complete_content_nid_' + nid).html(content).trigger('create');
          
          
          //--- Set Page BADGES ---//
          page_partial_my_wellness_goal_badge_list_view(vals.activity_earned_data.nw_b_str, 'app_my_wellness_goal_activity_complete_badges_nid_' + nid, 'You\'ve gained badges!', 'list');
          
          
          //--- Set Page BUTTONS ---//
          var content = '';
          //Buttons
          content += '<div class="section section-blue section-med  page-buttons">';
            //Go to my achievements button
            var returnPath = 'app_my_achievements';
            content += bl('Go to My Achievements', returnPath, {
                reloadPage: true,
                attributes: {
                  'class': 'btn btn-alt'
                }
            });
            
            //Go to my wellness goals button
            var returnPath = 'app_my_wellness_goals/' + userUID;
            content += bl('Go to My Wellness Goals', returnPath, {
                reloadPage: true,
                attributes: {
                  'class': 'btn btn-alt'
                }
            });
          content += '</div>';
          
          //Share Links
          var share_links_options = {
            socialMsg : 'Today I earned ' + vals.activity_earned_data.nw_points + ' points towards my ' + vals.wellnessGoalTitle + ' goal.',
            socialImg : 'img.jpg',
            socialUrl : Drupal.settings.site_path,
            emailMsg : 'Today I earned ' + vals.activity_earned_data.nw_points + ' points towards my ' + vals.wellnessGoalTitle + ' goal.',
            emailSub : 'Hey someone wanted to share with you their wellness goal achievement.',
          };
          content += '<div class="section section-blue section-med">';
          content += '  <ul class="page-buttons page-buttons-horizontal page-buttons-circles">';
          //Custom Common functions function.
          content += get_share_links(share_links_options);
          content += '  </ul>';
          content += '</div>';
          
          //Use JS to insert the content
          $('#app_my_wellness_goal_activity_complete_buttons_nid_' + nid).html(content).trigger('create');
        });
        
      });
      
    }
  });
}



// ================================== //
// Hide Wellness Goal Activity        //
// ================================== //

//Callback
function custom_pages_app_my_wellness_goal_activity_hide(nid, actionType, action) {
  //Load the User and add the Wellness goal to their user settings content.
  custom_user_settings_load(Drupal.user.uid, function(userSettings) {
    //console.log(userSettings);
    //Add Activity to userSettings
    userSettings = custom_entity_reference_add_value(userSettings, 'field_user_hidden_activities', nid);
    //Save the usersettings after editing goals
    custom_update_user_settings_node(userSettings);
    if (actionType == 'goto') {
      drupalgap_goto(action, {reloadPage:true});
    } else if (actionType == 'ajax') {
      var actionItem = $(action);
      actionItem.find('.hide-button').hide();
      actionItem.find('.show-button').show();
    }
  });
}

// ================================== //
// Show Wellness Goal Activity        //
// ================================== //

//Callback
function custom_pages_app_my_wellness_goal_activity_show(nid, actionType, action) {
  //Load the User and add the Wellness goal to their user settings content.
  custom_user_settings_load(Drupal.user.uid, function(userSettings) {
    //console.log(userSettings);
    if (typeof userSettings['field_user_hidden_activities'].und != 'undefined') {
      //Remove Activity from userSettings
      userSettings = custom_entity_reference_remove_value(userSettings, 'field_user_hidden_activities', nid);
      //Save the usersettings after editing goals
      custom_update_user_settings_node(userSettings);
      if (actionType == 'goto') {
        drupalgap_goto(action, {reloadPage:true});
      } else if (actionType == 'ajax') {
        var actionItem = $(action);
        actionItem.find('.show-button').hide();
        actionItem.find('.hide-button').show();
      }
    } else {
      //No goals added yet do nothing
    }
  });
}