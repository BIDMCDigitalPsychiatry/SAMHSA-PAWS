// ================= //
// My Wellness Goals //
// ================= //

//Callback
function custom_pages_app_my_wellness_goals(uid) {
  var pageContainers = '';
  pageContainers += '<div id="app_my_wellness_goals_content_uid_' + uid + '"></div>';
  return pageContainers;
}

//PageShow
function custom_pages_app_my_wellness_goals__ps(uid) {
  //My Wellness Goals View
  page_partial_my_wellness_goals_list_view(uid, 'app_my_wellness_goals_content_uid_' + uid, 'default');
}

// ====================== //
// Edit My Wellness Goals //

//Callback
function custom_pages_app_my_wellness_goals_edit(uid) {
  var pageContainers = '';
  pageContainers += '<div id="app_my_wellness_goals_content_edit_uid_' + uid + '"></div>';
  return pageContainers;
}

//PageShow
function custom_pages_app_my_wellness_goals_edit__ps(uid) {
  //My Wellness Goals Edit View
  page_partial_my_wellness_goals_list_view(uid, 'app_my_wellness_goals_content_edit_uid_' + uid, 'edit');
}





// ================ //
// My Wellness Goal //
// ================ //

//Title Callback
function custom_pages_app_my_wellness_goal_title_callback(callback, tid) {
  taxonomy_term_load(tid, {
    success: function(term) {
      //console.log(term);
      callback.call(null, term.name);
    }
  });
}

// =========================== //
// Activities My Wellness Goal //

//Callback
function custom_pages_app_my_wellness_goal(tid) {
  var pageContainers = '';
  pageContainers += '<div id="app_my_wellness_goal_content_tid_' + tid + '"></div>';
  pageContainers += '<div id="app_my_wellness_goal_activity_list_view_tid_' + tid + '"></div>';
  return pageContainers;
}

//PageShow
function custom_pages_app_my_wellness_goal__ps(tid) {
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
      $('#app_my_wellness_goal_content_tid_' + tid).html(content).trigger('create');
    }
  });
  
  //Goal Activity Listview View
  page_partial_my_wellness_goal_activity_list_view(Drupal.user.uid, tid, 'app_my_wellness_goal_activity_list_view_tid_' + tid);
}

// ================================ //
// Activities Edit My Wellness Goal //

//Callback
function custom_pages_app_my_wellness_goal_activities_edit(tid) {
  var pageContainers = '';
  pageContainers += '<div id="app_my_wellness_goal_activies_edit_content_tid_' + tid + '"></div>';
  return pageContainers;
}

//PageShow
function custom_pages_app_my_wellness_goal_activities_edit__ps(tid) {
  //Goal Activity Listview View
  page_partial_my_wellness_goal_activity_list_view(Drupal.user.uid, tid, 'app_my_wellness_goal_activies_edit_content_tid_' + tid, 'edit');
}

// ========================== //
// Resources My Wellness Goal //

//Callback
function custom_pages_app_my_wellness_goal_resources(tid) {
  var pageContainers = '';
  pageContainers += '<div id="app_my_wellness_goal_resources_content_tid_' + tid + '"></div>';
  pageContainers += '<div id="app_my_wellness_goal_resources_list_view_tid_' + tid + '"></div>';
  return pageContainers;
}

//PageShow
function custom_pages_app_my_wellness_goal_resources__ps(tid) {
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
      $('#app_my_wellness_goal_resources_content_tid_' + tid).html(content).trigger('create');
    }
  });
  
  //Goal Activity Listview View
  page_partial_my_wellness_goal_resource_list_view(tid, 'app_my_wellness_goal_resources_list_view_tid_' + tid);
}

// ====================== //
// About My Wellness Goal //

//Callback
function custom_pages_app_my_wellness_goal_about(tid) {
  var pageContainers = '';
  pageContainers += '<div id="app_my_wellness_goal_about_content_tid_' + tid + '"></div>';
  return pageContainers;
}

//PageShow
function custom_pages_app_my_wellness_goal_about__ps(tid) {
  taxonomy_term_load(tid, {
    success: function(term) {
      //console.log(term);
      var content = '';
      //Goal Page Title
      content += '<div class="banner-icon banner-icon-' + term.field_class.und["0"].safe_value + '">';
      content += '  <div class="banner-icon--body">';
      content += '    <h2 class="banner-icon--title">About ' + term.name + '</h2>';
      content += '  </div>';
      content += '</div>';
      
      //Goal Description
      content += '<div class="section section-med wysiwyg">';
      content += term['description'];
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
      content += '</div>';
  
      //Use JS to insert the content
      $('#app_my_wellness_goal_about_content_tid_' + tid).html(content).trigger('create');
      $('#app_my_wellness_goal_about_content_tid_' + tid).goalChecklistSet();
    }
  });
}

// ================================== //
// Add Wellness Goal                  //

//Callback
function custom_pages_app_my_wellness_goal_add(tid) {
  var pageContainers = '';
  pageContainers += '<div id="app_my_wellness_goal_add_content_tid_' + tid + '"></div>';
  // pageContainers += page_partial_icon_image_separator('default');
  pageContainers += '<div id="app_my_wellness_goal_add_demensions_list_view_tid_' + tid + '"></div>';
  return pageContainers;
}

//PageShow
function custom_pages_app_my_wellness_goal_add__ps(tid) {
  // Update Settings
  //Load the User and add the Wellness goal to their user settings content.
  custom_user_settings_load(Drupal.user.uid, function(userSettings) {

    //Add Goal to userSettings
    userSettings = custom_entity_reference_add_value(userSettings, 'field_wellness_goals', tid);
    //Save the usersettings after editing goals
    custom_update_user_settings_node(userSettings);
    
  });

  // Load the Page
  node_load(9, {
    success: function(node) {
      //console.log(term);
      var content = '';
      //App Page Title
      content += '<div class="section banner banner-congrats p-btm-no">';
      content += '  <div class="banner--body">';
      content += '    <div class="banner--image -goal">';
      content += '      <div class="banner--image-text">Congratulations!</div>';
      content += '    </div>';
      content += '    <h2 class="banner--title banner--title-large  m-btm">You Are Making Progress!</h2>';
      // content += '    <div class="banner--text">';
      // content += node['field_body'].und['0'].safe_value;
      // content += '    </div>';
      content += '  </div>';
      content += '</div>'
      
      
      
      //Go to my wellness goals button & text
      var returnPath = 'app_my_wellness_goals/' + Drupal.user.uid;
      content += '<div class="section bg-blue  page-buttons  p-btm-large-x">';
      content += '  <div class="t-white t-center">';
      content += node['field_body'].und['0'].safe_value;
      content +=   '</div>';
      content += bl('Go to My Wellness Goals', returnPath, {
          reloadPage:true,
          attributes: {
            'class': 'btn btn-alt'
          }
      });
      content += '</div>';
      
      //Share Links
      // var share_links_options = {};
      // content += '<div class="section horizontal-sahre-links circle-buttons"><ul>';
      // //Custom Common functions function.
      // content += get_share_links(share_links_options);
      // content += '</ul></div>';
  
      //Use JS to insert the content
      $('#app_my_wellness_goal_add_content_tid_' + tid).html(content).trigger('create');
    }
  });
  
  //Eight Demensions View
  page_partial_eight_demensions_list_view('app_my_wellness_goal_add_demensions_list_view_tid_' + tid);
}

// ================================== //
// Remove Wellness Goal               //

//Callback
function custom_pages_app_my_wellness_goal_remove(tid, actionType, action) {
  //Load the User and add the Wellness goal to their user settings content.
  custom_user_settings_load(Drupal.user.uid, function(userSettings) {
    //console.log(userSettings);
    //Remove Goal from userSettings
    userSettings = custom_entity_reference_remove_value(userSettings, 'field_wellness_goals', tid);
    //Save the usersettings after editing goals
    custom_update_user_settings_node(userSettings);
    if (actionType == 'goto') {
      drupalgap_goto(action, {reloadPage:true});
    } else if (actionType == 'ajax') {
      $(action).remove();
    }
  });
}




// =============================== //
// All Activities My Wellness Goal //
// =============================== //

//Callback
function custom_pages_app_my_wellness_goal_all(uid) {
  var pageContainers = '';
  pageContainers += '<div id="app_my_wellness_goal_all_content"></div>';
  pageContainers += '<div id="app_my_wellness_goal_all_activity_list_view"></div>';
  return pageContainers;
}

//PageShow
function custom_pages_app_my_wellness_goal_all__ps(uid) {
  var content = '';
  //App Page Title
  content += '<div class="banner-icon banner-icon-all-activities">';
  content += '  <div class="banner-icon--body">';
  content += '    <h2 class="banner-icon--title">View All Your Activities.</h2>';
  content += '  </div>';
  content += '</div>';
  

  
  
  /*//Content Body
  content += '<div class="section wysiwyg">';
  content += node['field_body'].und['0'].safe_value;
  content += '</div>';*/
  
  //Use JS to insert the content
  $('#app_my_wellness_goal_all_content').html(content).trigger('create');
  
  //Goal Activity Listview View
  page_partial_my_wellness_goal_activity_list_view(uid, 'all', 'app_my_wellness_goal_all_activity_list_view', 'all');
}


// ========================== //
// Resources My Wellness Goal //

//Callback
function custom_pages_app_my_wellness_goal_all_resources(uid) {
  var pageContainers = '';
  pageContainers += '<div id="app_my_wellness_goal_all_resources"></div>';
  return pageContainers;
}

//PageShow
function custom_pages_app_my_wellness_goal_all_resources__ps(uid) {
  var content = '';
  //App Page Title
  content += '<div class="section">';
  content += '  <h2 class="page-title">All Resources</h2>';
  content += '</div>';

  //Use JS to insert the content
  $('#app_my_wellness_goal_all_resources').html(content).trigger('create');
}


// ========================= //
// Resource My Wellness Goal //

//Callback
function custom_pages_app_my_wellness_goal_resource(nid) {
  var pageContainers = '';
  pageContainers += '<div id="app_my_wellness_goal_resource_content_nid_' + nid + '"></div>';
  pageContainers += page_partial_icon_image_separator('bottom');
  return pageContainers;
}
//PageShow
function custom_pages_app_my_wellness_goal_resource__ps(nid) {
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
      
      //Content File Download
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
      $('#app_my_wellness_goal_resource_content_nid_' + nid).html(content).trigger('create');
      
    }
  });
}

// ==================================== //
// All Activities Edit My Wellness Goal //

//Callback
function custom_pages_app_my_wellness_goal_all_activities_edit(uid) {
  var pageContainers = '';
  pageContainers += '<div id="app_my_wellness_goal_all_activies_edit"></div>';
  return pageContainers;
}

//PageShow
function custom_pages_app_my_wellness_goal_all_activities_edit__ps(uid) {
  //Goal Activity Listview View
  page_partial_my_wellness_goal_activity_list_view(uid, 'all', 'app_my_wellness_goal_all_activies_edit', 'all-edit');
}
