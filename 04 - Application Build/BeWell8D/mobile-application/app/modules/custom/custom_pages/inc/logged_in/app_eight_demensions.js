// ========================================================================== //
// Eight Dimensions of Wellness                                               //
// ========================================================================== //

// ================================== //
// About Eight Dimensions of Wellness //

//Callback
function custom_pages_app_eight_demensions() {
  var pageContainers = '';
  pageContainers += '<div id="app_eight_demensions_content_nid_1"></div>';
  pageContainers += page_partial_icon_image_separator('gradient');
  pageContainers += '<div id="app_eight_demensions_list_view"></div>';
  return pageContainers;
}
//PageShow
function custom_pages_app_eight_demensions__ps() {
  node_load(1, {
    success: function(node) {
      //console.log(node);
      var content = '';
      //App Page Title
      content += '<div class="section section-title">';
      content += '  <h2 class="h2 -blue -line">' + node.title + '</h2>';
      //Content Body
      content += '  <div class="wysiwyg">';
      content += node['field_body'].und['0'].safe_value;
      content += '  </div>';
      content += '</div>';
  
      //Use JS to insert the content
      $('#app_eight_demensions_content_nid_1').html(content).trigger('create');
    }
  });
  
  //Eight Demensions View
  page_partial_eight_demensions_list_view('app_eight_demensions_list_view');
}


// ============================================= //
// Learn More About Eight Dimensions of Wellness //

//Callback
function custom_pages_app_eight_demensions_lm() { 
  var pageContainers = '';
  pageContainers += '<div id="app_eight_demensions_lm_content_nid_2"></div>';
  pageContainers += page_partial_icon_image_separator('gradient');
  pageContainers += '<div id="app_eight_demensions_list_view_learn_more"></div>';
  return pageContainers;
}
//Pageshow
function custom_pages_app_eight_demensions_lm__ps() {
  node_load(2, {
    success: function(node) {
      //console.log(node);
      var content = '';
      //App Page Title
      content += '<div class="section section-title">';
      content += '  <h2 class="h2 -blue -line">' + node.title + '</h2>';
      //Content Body
      content += '  <div class="wysiwyg">';
      content += node['field_body'].und['0'].safe_value;
      content += '  </div>';
      content += '</div>';
  
      //Use JS to insert the content
      $('#app_eight_demensions_lm_content_nid_2').html(content).trigger('create');
    }
  });
  
  //Eight Demensions View
  page_partial_eight_demensions_list_view('app_eight_demensions_list_view_learn_more');
}




// ========================================================================== //
// Wellness Goal                                                              //
// ========================================================================== //

// ============================ //
// Wellness Goal Title Callback //

//Title Callback
function custom_pages_app_wellness_goal_title_callback(callback, tid) {
  taxonomy_term_load(tid, {
    success: function(term) {
      //console.log(term);
      callback.call(null, term.name);
    }
  });
}

// =================== //
// About Wellness Goal //

//Callback
function custom_pages_app_wellness_goal(tid) {
  var pageContainers = '';
  pageContainers += '<div id="app_wellness_goal_content_tid_' + tid + '"></div>';
  // pageContainers += page_partial_icon_image_separator('default');
  pageContainers += '<div id="app_wellness_goal_list_view_tid_' + tid + '"></div>';
  return pageContainers;
}
//PageShow
function custom_pages_app_wellness_goal__ps(tid) {
  taxonomy_term_load(tid, {
    success: function(term) {
      //console.log(term);
      //Load the User Settings and determine if goal has allready been added.
      custom_user_settings_load(Drupal.user.uid, function(userSettings) {
        //console.log(userSettings);
        var linkUsed = 'default';
        var wellnessGoalLink = bl('Add to My Wellness Goals', 'app_my_wellness_goal_add/' + term.tid, {
          'attributes':  {
            'class': 'btn'
          }
        });
        
        // Determine WHat link to show. and any extra content
        if (typeof userSettings['field_wellness_goals'].und != 'undefined') {
          //Existing Goals Set remove the requested goal.
          var entRefField = userSettings['field_wellness_goals'].und;
          for (var valIndex = 0, fieldLen = entRefField.length; valIndex < fieldLen; valIndex++) {
            var val = userSettings['field_wellness_goals'].und[valIndex];
            if (val['target_id'] == tid) {
              linkUsed = 'existing';
              wellnessGoalLink = bl('Go to My Wellness Goals', 'app_my_wellness_goals/' + Drupal.user.uid, {
                'attributes':  {
                  'class': 'btn'
                }
              });
            }
          }
        }
        
        var content = '';
        
        //Goal Page Title
        content += '<div class="banner-icon banner-icon-' + term.field_class.und["0"].safe_value + '">';
        content += '  <div class="banner-icon--body">';
        content += '    <h2 class="banner-icon--title">About ' + term.name + '</h2>';
        content += '  </div>';
        content += '</div>';
        
        //Goal Description
        content += '<div class="section section-med">';
        content += '  <div class="wysiwyg">';
        content += term['description'];
        content += '  </div>';
        content += '</div>';
        
        //Goal Details
        content += '<div class="section section-med section-grey">';
        content += '  <div class="goal-details-body wysiwyg">';
        try { 
          content += term.field_body.und["0"].safe_value; 
        } catch (error) {}
        content += '  </div>';
        content += '  <div class="goal-checklist">';
        content += '    <ul class="goal-checklist--list -' + term.tid + '">';
        var checklistLength = term.field_details_checklist_items.und.length;
        var checkedItems = variable_get('goal-checklist-checked-items', '');
        var checkedItemsArr = [];
        if (checkedItems !== '') {
          checkedItemsArr = checkedItems.split("||");
        }
        for (var checklistCounter = 0; checklistCounter < checklistLength; checklistCounter++) {
          var checklistItem = term.field_details_checklist_items.und[checklistCounter].safe_value;
          if ($.inArray('checklist-item-' + term.tid + '-' + checklistCounter, checkedItemsArr) > -1) {
            content += '      <li id="checklist-item-' + term.tid + '-' + checklistCounter + '" class="goal-checklist--item -checked">' + checklistItem + '</li>';
          } else {
            content += '      <li id="checklist-item-' + term.tid + '-' + checklistCounter + '" class="goal-checklist--item">' + checklistItem + '</li>';
          }
        }
        content += '    </ul>';
        content += '  </div>';
        if (linkUsed == 'existing') {
          content += '  <div class="m-top-large t-center t-bold">';
          content += '    <p>This goal already exists in your personal wellness goals.</p>';
          content += '  </div>';
        }
        content += wellnessGoalLink;
        content += '</div>';
        
        //Use JS to insert the content
        $('#app_wellness_goal_content_tid_' + tid).html(content).trigger('create');
        $('#app_wellness_goal_content_tid_' + tid).goalChecklistSet();
        
        //Eight Demensions View
        page_partial_eight_demensions_list_view('app_wellness_goal_list_view_tid_' + tid);
      });
      
    }
  });
}

// ======================== //
// Wellness Goal Activities //

//Callback
function custom_pages_app_wellness_goal_activities(tid) {
  var pageContainers = '';
    pageContainers += '<div id="app_wellness_goal_activities_tid_' + tid + '"></div>';
    pageContainers += '<div id="app_wellness_goal_activities_list_view_tid_' + tid + '"></div>';
  return pageContainers;
}
//PageShow
function custom_pages_app_wellness_goal_activities__ps(tid) {
  taxonomy_term_load(tid, {
    success: function(term) {
      //console.log(term);
      var content = '';
      //App Page Title
      content += '<div class="banner-icon banner-icon-' + term.field_class.und["0"].safe_value + '">';
      content += '  <div class="banner-icon--body">';
      content += '    <h2 class="banner-icon--title">' + term.name + ' Activities</h2>';
      content += '  </div>';
      content += '</div>';
      
      /*//Content Body
      content += '<div class="section wysiwyg">';
      content += node['field_body'].und['0'].safe_value;
      content += '</div>';*/
      
      //Use JS to insert the content
      $('#app_wellness_goal_activities_tid_' + tid).html(content).trigger('create');
    }
  });
  
  //Goal Activity Listview View
  page_partial_wellness_goal_activity_list_view(tid, 'app_wellness_goal_activities_list_view_tid_' + tid);
}

// ======================= //
// Wellness Goal Resources //

//Callback
function custom_pages_app_wellness_goal_resources(tid) {
  var pageContainers = '';
    pageContainers += '<div id="app_wellness_goal_resources_content_tid_' + tid + '"></div>';
    pageContainers += '<div id="app_wellness_goal_resources_list_view_tid_' + tid + '"></div>';
  return pageContainers;
}
//PageShow
function custom_pages_app_wellness_goal_resources__ps(tid) {
  taxonomy_term_load(tid, {
    success: function(term) {
      //console.log(term);
      var content = '';
      //App Page Title
      content += '<div class="banner-icon banner-icon-' + term.field_class.und["0"].safe_value + '">';
      content += '  <div class="banner-icon--body">';
      content += '    <h2 class="banner-icon--title">' + term.name + ' Resources</h2>';
      content += '  </div>';
      content += '</div>';
      
      /*//Content Body
      content += '<div class="section wysiwyg">';
      content += node['field_body'].und['0'].safe_value;
      content += '</div>';*/
  
      //Use JS to insert the content
      $('#app_wellness_goal_resources_content_tid_' + tid).html(content).trigger('create');
    }
  });
  
  //Goal Activity Listview View
  page_partial_wellness_goal_resource_list_view(tid, 'app_wellness_goal_resources_list_view_tid_' + tid);
}




// ====================== //
// Wellness Goal Activity //

//Callback
function custom_pages_app_wellness_goal_activity(nid) {
  var pageContainers = '';
  pageContainers += '<div id="app_wellness_goal_activity_content_nid_' + nid + '"></div>';
  return pageContainers;
}
//PageShow
function custom_pages_app_wellness_goal_activity__ps(nid) {
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
      
          //Use JS to insert the content
          $('#app_wellness_goal_activity_content_nid_' + nid).html(content).trigger('create');
        }
      });
  
    }
  });
}


// ====================== //
// Wellness Goal Resource //

//Callback
function custom_pages_app_wellness_goal_resource(nid) {
  var pageContainers = '';
  pageContainers += '<div id="app_wellness_goal_resource_content_nid_' + nid + '"></div>';
  pageContainers += page_partial_icon_image_separator('bottom');
  return pageContainers;
}
//PageShow
function custom_pages_app_wellness_goal_resource__ps(nid) {
  node_load(nid, {
    success: function(node) {
      //console.log(node);
      var content = '';
      //App Page Title
      content += '<div class="section section-title">';
      content += '  <h2 class="h2 -blue -line">' + node.title + '</h2>';
      
      //Content Body
      content += '<div class="wysiwyg">';
      content += node['field_body'].und['0'].safe_value;
      content += '</div>';
      
      //Content File
      try {
        content += '<div class="section file-download">';
        switch (node.field_resource_upload_link.und["0"].value) {
          case 'link':
            var file_url = node.field_resource_link.und["0"].url;
            var file_link = '<a href="'+ file_url +'" target="_blank" rel="nofollow" class="file-download-button btn ui-link">View Resource</a>';
            content += file_link;
            break;
          case 'upload':
            var file_url = drupalgap_image_path(node.field_resource_file.und["0"].uri);
            var file_link = '<a href="#" onclick="javascript:custom_file_download(\'' + file_url + '\');" target="_blank" rel="nofollow" class="file-download-button btn ui-link">Download Resource</a>';
            content += file_link;
            break;
        }
        content += '</div>';
      } catch (e) {}
      
      //Use JS to insert the content
      $('#app_wellness_goal_resource_content_nid_' + nid).html(content).trigger('create');
    }
  });
}




