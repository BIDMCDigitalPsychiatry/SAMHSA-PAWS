/**
 * THis returns the list view for all pages that want the eight demensions list
 *
 */
function page_partial_eight_demensions_list_view(html_id) {
  var path_to_view = 'mobile/app/eight-dimensions-of-wellness-list';
  views_datasource_get_view_result(path_to_view, {
    success: function (data) {
      //console.log(data);
      var content = '';
      
      content += '<div class="section section-med bg-white">';
      content += '  <h2 class="h3 -blue  t-center">The Eight Dimensions of Wellness</h2>';
      content += '  <p class="t-center">Explore the Eight Dimensions of Wellness to learn about each one and set our goals.</p>';
      
      
      if (data.nodes.length > 0) {
        content += '<div class="nav-dimentions">';
        content += '  <ul class="row-4  menu-dimentions">';
        
        $.each(data.nodes, function(index, object){
            var term = object.node;
            var linkbody = '';
            linkbody += '<span>' + term.name + '</span>';
            var term_link = l(linkbody, 'app_wellness_goal/' + term.tid, {
              'attributes':  {
                'class': 'term-link  i-large i-' + term.class
              }
            });
            content += '<li class="spl-2 span-1 spl-t-4 span-t-1  menu-dimentions--item -' + term.class + '">' + term_link + '</li>';
            //console.log(term);
        });
        
        content += '  </ul>';
        content += '</div>';
      }
      
      content += '</div>';
  
      //Use JS to insert the content
      $('#' + html_id).html(content).trigger('create');
    },
    error: function (data) {
      //Set Home Page No Load of data
      var content = '';
      
      content += '<div class="section">';
      content += '  <h2 class="list-title">The Eight Dimensions of Wellness</h2>';
      content += '  <p>This list could not be loaded.</p>';
      content += '</div>';
  
      //Use JS to insert the content
      $('#' + html_id).html(content).trigger('create');
    }
  });
}

/**
 * THis returns the list view for all pages that want the eight demensions list
 *
 */
function page_partial_my_wellness_goals_list_view(uid, html_id, mode) {
  var path_to_view = 'mobile/app/my-wellness-goals-list/' + uid;
  views_datasource_get_view_result(path_to_view, {
    reset: true,
    success: function (data) {
      //console.log(data);
      var content = '';
      
      
      content += '<div class="section section-large  banner bg-img bg-img-splash">';
      content += '  <div class="group">';
      content += '    <div class="banner--body">';
      content += '      <h1 class="banner--title">';
      content += 'Perform activities and access resources to achieve your wellness goals.';
      content += '      </h1>';
      content += '    </div>';
      content += '  </div>';
      content += '</div>';
      
      // content += '<div>';
      
      if (data.nodes.length > 0) {
        var all_activities_count = 0;
        var all_resources_count = 0;
        
        content += '<ul class="list-goals">';
        
        $.each(data.nodes, function(index, object){
            var term = object.node;
            all_activities_count = all_activities_count + + term.activities;
            all_resources_count = all_resources_count + + term.resources;
            
            var linkbody = '';
            linkbody += '<div class="list-goals--title">' + term.name + '</div>';
            linkbody += '<div class="list-goals--subtitle">' + term.activities + ' Activities</div>';
            linkbody += '<div class="list-goals--subtitle">' + term.resources + ' Resources</div>';
            var term_link = l(linkbody, 'app_my_wellness_goal/' + term.tid, {
              'attributes':  {
                'class': 'list-goals--link  term-link demension-icon-' + term.class
              }
            });
            
            var removeWellnessGoalLink = theme_button({
              text : 'Remove',
              attributes: {
                onclick: "custom_pages_app_my_wellness_goal_remove('" + term.tid + "', 'ajax', '.list-goals--item.edit-item.-" + term.class + "');",
                title: "Remove Wellnes Goal",
                class: "list-goals--remove"
              }
            });
            
            switch (mode) {
              case 'edit':
                content += '<li class="list-goals--item edit-item -' + term.class + '">';
                content += term_link;
                content += removeWellnessGoalLink;
                content += '</li>';
                break;
              
              case 'default':
              default:
                content += '<li class="list-goals--item -arrow -' + term.class + '">';
                content += term_link;
                content += '</li>';
                break;
            }
            //console.log(term);
        });
        
        //All Sections Link
        if (mode == 'default') {
          var alllinkbody = '';
          alllinkbody += '<div class="list-goals--title">All Activities</div>';
          alllinkbody += '<div class="list-goals--subtitle">' + all_activities_count + ' Activities</div>';
          // alllinkbody += '<div class="list-goals--subtitle">' + all_resources_count + ' Resources</div>';
          var all_link = l(alllinkbody, 'app_my_wellness_goal_all/' + Drupal.user.uid, {
            'attributes':  {
              'class': 'list-goals--link term-link demension-icon-all'
            }
          });
          content += '<li class="list-goals--item -arrow -all">';
          content += all_link;
          content += '</li>';
        }
        
        content += '</ul>';
      } else {
        var eightDemensionsLink = l('View the Eight Demensions of Wellness', 'app_eight_demensions', {
          'attributes':  {
            'class': 'link'
          }
        });
        
        content += '<div class="section section-med">';
        content += '  <div class="no-results wysiwyg">';
        content += '  <p>You Currently Have no wellness goals. Please use the link bellow to browse the Eight Demensions of Wellness and add them to your goals list.</p>';
        content += eightDemensionsLink;
        content += '  </div>';
        content += '</div>';
      }
      
      // content += '</div>';
  
      //Use JS to insert the content
      $('#' + html_id).html(content).trigger('create');
    },
    error: function (data) {
      //Set Home Page No Load of data
      var content = '';
      
      content += '<div class="section">';
      content += '  <h2 class="list-title">The Eight Dimensions of Wellness</h2>';
      content += '  <p>This list could not be loaded.</p>';
      content += '</div>';
  
      //Use JS to insert the content
      $('#' + html_id).html(content).trigger('create');
    }
  });
}

/**
 * THis returns the list view for resources under eight demensions.
 *
 */
function page_partial_wellness_goal_resource_list_view(tid, html_id) {
  //Proccess The View
  var path_to_view = 'mobile/app/wellness-goal-resources-list/' + tid;
  views_datasource_get_view_result(path_to_view, {
    reset: true,
    success: function (data) {
      //console.log(data);
      var content = '';
      
      // content += '<div class="section">';
      
      if (data.nodes.length > 0) {
        
        content += '<ul class="list-resources">';
        
        $.each(data.nodes, function(index, object){
          var node = object.node;
          
          var linkbody = '';
          linkbody += '<div class="list-resources--title">' + node['name'] + '</div>';
          linkbody += '<div class="list-resources--subtitle">' + node['resource_author'] + '</div>';
          var node_link = l(linkbody, 'app_wellness_goal_resource/' + node.nid, {
            'attributes':  {
              'class': 'node-link demension-icon-' + node.class
            }
          });
          
          //Set the output
          content += '<li class="list-resources--item -resource -arrow  ' + node.class + ' resource-item-' + node.nid + '">';
          content += node_link;
          content += '</li>';
        });
        
        content += '</ul>';
      } else {
        content += '<div class="section section-med">';
        content += '  <div class="no-results wysiwyg">';
        content += '    <p>There are currently no resources to show.</p>';
        content += '  </div>';
        content += '</div>';
      }
      
      // content += '</div>';
  
      //Use JS to insert the content
      $('#' + html_id).html(content).trigger('create');
    },
    error: function (data) {
      //Set Home Page No Load of data
      var content = '';
      
      content += '<div class="section">';
      content += '  <h2 class="list-title">Resources</h2>';
      content += '  <p>This list could not be loaded.</p>';
      content += '</div>';
  
      //Use JS to insert the content
      $('#' + html_id).html(content).trigger('create');
    }
  });
}

/**
 * THis returns the list view for activities under eight demensions.
 *
 */
function page_partial_wellness_goal_activity_list_view(tid, html_id) {
  //Proccess The View
  var path_to_view = 'mobile/app/wellness-goal-activities-list/' + tid;
  views_datasource_get_view_result(path_to_view, {
    reset: true,
    success: function (data) {
      //console.log(data);
      var content = '';
      
      // content += '<div class="section">'; 
      
      if (data.nodes.length > 0) {
        
        content += '<ul class="list-activities">';
        
        $.each(data.nodes, function(index, object){
          var node = object.node;
          
          var linkbody = '';
          linkbody += '<div class="list-activities--title">' + node['name'] + '</div>';
          linkbody += '<div class="list-activities--subtitle">' + node['activity_type'] + '</div>';
          linkbody += '<div class="list-activities--subtitle">' + node['activity_dur_start'] + ' - ' + node['activity_dur_end'] + ' Minutes</div>';
          var node_link = l(linkbody, 'app_wellness_goal_activity/' + node.nid, {
            'attributes':  {
              'class': 'list-activities--link  node-link demension-icon-' + node.class
            }
          });
          
          //Set the output
          content += '<li class="list-activities--item -arrow -' + node.class + ' activity-item-' + node.nid + '">';
          content += node_link;
          content += '</li>';
        });
        
        content += '</ul>';
      } else {
        content += '<div class="section section-med">';
        content += '  <div class="no-results wysiwyg">';
        content += '    <p>There are currently no activities to show.</p>';
        content += '  </div>';
        content += '</div>';
      }
      
      // content += '</div>';
  
      //Use JS to insert the content
      $('#' + html_id).html(content).trigger('create');
    },
    error: function (data) {
      //Set Home Page No Load of data
      var content = '';
      
      content += '<div class="section">';
      content += '  <h2 class="list-title">Activities</h2>';
      content += '  <p>This list could not be loaded.</p>';
      content += '</div>';
  
      //Use JS to insert the content
      $('#' + html_id).html(content).trigger('create');
    }
  });
}



/**
 * This returns the list view for resources under my wellness goals.
 *
 */
function page_partial_my_wellness_goal_resource_list_view(tid, html_id, mode) {
  //Proccess The View
  var path_to_view = 'mobile/app/wellness-goal-resources-list/' + tid;
  views_datasource_get_view_result(path_to_view, {
    reset: true,
    success: function (data) {
      //console.log(data);
      var content = '';
      
      // content += '<div class="section">';
      
      if (data.nodes.length > 0) {
        
        content += '<ul class="list-resources">';
        
        $.each(data.nodes, function(index, object){
          var node = object.node;
          
          var linkbody = '';
          linkbody += '<div class="list-resources--title">' + node['name'] + '</div>';
          linkbody += '<div class="list-resources--subtitle">' + node['resource_author'] + '</div>';
          var node_link = l(linkbody, 'app_my_wellness_goal_resource/' + node.nid, {
            'attributes':  {
              'class': 'node-link demension-icon-' + node.class
            }
          });
          
          //Set the output
          content += '<li class="list-resources--item -resource -arrow  ' + node.class + ' resource-item-' + node.nid + '">';
          content += node_link;
          content += '</li>';
        });
        
        content += '</ul>';
      } else {
        content += '<div class="section section-med">';
        content += '  <div class="no-results wysiwyg">';
        content += '    <p>There are currently no resources to show.</p>';
        content += '  </div>';
        content += '</div>';
      }
      
      // content += '</div>';
  
      //Use JS to insert the content
      $('#' + html_id).html(content).trigger('create');
    },
    error: function (data) {
      //Set Home Page No Load of data
      var content = '';
      
      content += '<div class="section">';
      content += '  <h2 class="list-title">Resources</h2>';
      content += '  <p>This list could not be loaded.</p>';
      content += '</div>';
  
      //Use JS to insert the content
      $('#' + html_id).html(content).trigger('create');
    }
  });
}

/**
 * THis returns the list view for activities under my wellness goals.
 *
 */
function page_partial_my_wellness_goal_activity_list_view(uid, tid, html_id, mode) {
  var uid = Drupal.user.uid;
  //Load User Settings
  custom_user_settings_load(Drupal.user.uid, function(userSettings) {
    //Get users goal tids in contactinated string for view contextual filters.
    var tids = '';
    var userWellnessGoals = userSettings.field_wellness_goals.und;
    var userWellnessGoalsLen = userWellnessGoals.length;
    for (var goalIndex = 0; goalIndex < userWellnessGoalsLen; goalIndex++) {
      if (goalIndex == userWellnessGoalsLen - 1) {
        //Last item just add id
        tids += userWellnessGoals[goalIndex]['target_id'];
      } else {
        //Continuing item add id plus "+"
        tids += userWellnessGoals[goalIndex]['target_id'] + "+";
      }
    }
    //console.log(tids);
    
    //Proccess The View
    switch (mode) {
      case 'edit':
        var path_to_view = 'mobile/app/my-wellness-goal-activities-list-edit/' + tid;
        break;
      case 'all':
        var path_to_view = 'mobile/app/my-wellness-goal-activities-list/' + uid + '/' + tids;
        break;
      case 'all-edit':
        var path_to_view = 'mobile/app/my-wellness-goal-activities-list-edit/' + tids;
        break;
      
      case 'default':
      default:
        var path_to_view = 'mobile/app/my-wellness-goal-activities-list/' + uid + '/' + tid;
        break;
    }
    views_datasource_get_view_result(path_to_view, {
      reset: true,
      success: function (data) {
        //console.log(data);
        var content = '';
        
        // content += '<div class="section">';
        
        if (data.nodes.length > 0) {
          
          content += '<ul class="list-activities">';
          
          $.each(data.nodes, function(index, object){
              var node = object.node;
              
              var linkbody = '';
              linkbody += '<div class="list-activities--title">' + node['name'] + '</div>';
              linkbody += '<div class="list-activities--subtitle">' + node['activity_type'] + '</div>';
              linkbody += '<div class="list-activities--subtitle">' + node['activity_dur_start'] + ' - ' + node['activity_dur_end'] + ' Minutes</div>';
              
              //Determine based on mode if the item should be a link and set it
              switch (mode) {
                case 'edit':
                case 'all-edit':
                  //No Link to activity
                  var node_link = '<div class="list-activities--link  node-link node-nolink demension-icon-' + node.class + '">' + linkbody + '</div>';
                  break;
                
                case 'default':
                default:
                  //Link to activity
                  var backType = 'default';
                  if (mode == 'all') {
                    var backType = 'all';
                  }
                  var node_link = l(linkbody, 'app_my_wellness_goal_activity/' + node.nid + '-' + backType, {
                    'attributes':  {
                      'class': 'list-activities--link  node-link demension-icon-' + node.class
                    }
                  });
                  break;
              }
              
              //Build the item structure based on mode.
              switch (mode) {
                case 'edit':
                case 'all-edit':
                  //Check if the activity is hidden or not and display list view properly
                  //console.log(userSettings);
                  
                  //Attributes Base
                  var showAttributes = {
                    onclick: "custom_pages_app_my_wellness_goal_activity_show('" + node.nid + "', 'ajax', '.list-activities--item.edit-item.-" + node.class + ".activity-item-" + node.nid + "');",
                    title: "Show Activity",
                    class: "show-button",
                  };
                  var hideAttributes = {
                    onclick: "custom_pages_app_my_wellness_goal_activity_hide('" + node.nid + "', 'ajax', '.list-activities--item.edit-item.-" + node.class + ".activity-item-" + node.nid + "');",
                    title: "Hide Activity",
                    class: "hide-button",
                  };
                  
                  //Set wether the show or hide button is displayed.
                  //Set the defaults
                  hideAttributes['style'] = 'display: block;';
                  showAttributes['style'] = 'display: none;';
                  //Determine if in list of users hidden activities.
                  if (typeof userSettings.field_user_hidden_activities.und != 'undefined') {
                    var hiddenActivities = userSettings.field_user_hidden_activities.und;
                    for (var i = 0; i < hiddenActivities.length; i++) {
                      if (node.nid == hiddenActivities[i]['target_id']) {
                        hideAttributes['style'] = 'display: none;';
                        showAttributes['style'] = 'display: block;';
                      }
                    }
                  }
                  
                  //Create the buttons
                  var showButton = theme_button({
                    text : 'Show',
                    attributes: showAttributes
                  });
                  
                  var hideButton = theme_button({
                    text : 'Hide',
                    attributes: hideAttributes
                  });
                  
                  //Set the output 
                  content += '<li class="edit-item list-activities--item -icon -' + node.class + ' activity-item-' + node.nid + '">';
                  content += node_link;
                  content += '<div class="list-activities--btn show-hide-buttons">' + showButton + hideButton + '</div>';
                  content += '</li>';
                  break;
                
                case 'default':
                default:
                  //Set the output
                  content += '<li class="list-activities--item -arrow -' + node.class + ' activity-item-' + node.nid + '">';
                  content += node_link;
                  content += '</li>';
                  break;
              }
              //console.log(node);
          });
          
          content += '</ul>';
        } else {
          content += '  <div class="section section-med">';
          content += '    <div class="no-results wysiwyg">';
          content += '      <p>There are currently no visible activities to show. Please click the edit button above to show some activities.</p>';
          content += '    </div>';
          content += '  </div>';
        }
        
        // content += '</div>';
    
        //Use JS to insert the content
        $('#' + html_id).html(content).trigger('create');
      },
      error: function (data) {
        //Set Home Page No Load of data
        var content = '';
        
        content += '<div class="section">';
        content += '  <h2 class="list-title">Activities</h2>';
        content += '  <p>This list could not be loaded.</p>';
        content += '</div>';
    
        //Use JS to insert the content
        $('#' + html_id).html(content).trigger('create');
      }
    });
    //End Processing the view
  });
}

/**
 * This returns the list view for BADGES.
 *
 */
function page_partial_my_wellness_goal_badge_list_view(nids, html_id, secTitle, mode) {
  //Proccess The View
  var path_to_view = '';
  switch (mode) {
    case 'list':
    default:
      path_to_view = 'mobile/app/my-wellness-goal-activity-badge-list/' + nids;
      break;
  }
  views_datasource_get_view_result(path_to_view, {
    reset: true,
    success: function (data) {
      //console.log(data);
      var content = '';
      
      if (data.nodes.length > 0) {
        
        content += '<div class="section section-med section-tp">';
        
        if (secTitle !== null) {
          content += '<div class="t-bold t-center t-large m-btm">' + secTitle + '</div>';
        }
        
        switch (mode) {
          case 'list':
          default:
            content += '<ul class="wellness-goal-badge-item-list  list-badges">';
        
            $.each(data.nodes, function(index, object){
              var node = object.node;
              var subline = '';
              switch (node['badge_type']) {
                case 'Points Accumulated':
                  subline += node['points_acc'] + ' Points Earned';
                  break;
                case 'Specific Activity Type Complete':
                  var activity_type = node['activity_type'].replace("Activity", "Activities");
                  subline += 'Completed All ' + activity_type;
                  break;
                case 'All Activities Complete':
                  subline += 'Completed All Activities';
                  break;
              }
              
              //Set the output
              content += '<li class="list-badges--item -congrats -' + node['wg_class'] + ' badge-item-' + node.nid + '">';
              content += '  <div class="list-badges--body -congrats">';
              content += '    <div class="badge-title t-bold">' + node['title'] + '</div>';
              content += '    <div class="badge-wellness-goal t-small">' + node['wellness_goal'] + '</div>';
              content += '    <div class="badge-desc" t-small>'+ subline +'</div>';
              content += '  </div>';
              content += '</li>';
            });
            
            content += '</ul>';
            break;
        }
        
        content += '</div>';
        
      }
  
      //Use JS to insert the content
      $('#' + html_id).html(content).trigger('create');
    },
    error: function (data) {
      //Set Home Page No Load of data
      // var content = '';
      
      // content += '<div class="section section-med section-tp">';
      // content += '  <h2 class="list-title">Badges</h2>';
      // content += '  <p>This list could not be loaded.</p>';
      // content += '</div>';
  
      // //Use JS to insert the content
      // $('#' + html_id).html(content).trigger('create');
    }
  });
}