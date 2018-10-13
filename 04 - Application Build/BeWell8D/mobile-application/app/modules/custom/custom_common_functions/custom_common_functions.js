function custom_user_settings_load(userUID, _callback) {
  user_load(userUID, {
    success: function(userAccount) {
      //console.log(userAccount);
      var userSettingsNID = userAccount['field_user_settings_node'].und['0']['target_id'];
      _entity_local_storage_delete('node', userSettingsNID);
      node_load(userSettingsNID, {
        success: function(userSettings) {
          _callback(userSettings);
        }
      });
      
    }
  });
}

function custom_site_vars_load(_callback) {
  var appVars = variable_get("appVars");
  //console.log(appVars);
  
  var path_to_view = 'mobile/app/vars/vars.json';
  views_datasource_get_view_result(path_to_view, {
    success: function (data) {
      //Set Variables
      variable_set('appVars', JSON.stringify(data));
      _callback(true);
      //console.log(data);
    },
    error: function () {
      _callback(false);
    }
  });
}

function custom_user_init_vars_load(user_id, _callback) {
  var userInitVars = variable_get("userInitVars");
  //console.log(userInitVars);
  
  var path_to_view = 'mobile/app/vars/' + user_id + '/user-vars.json';
  views_datasource_get_view_result(path_to_view, {
    success: function (data) {
      //Set Variables
      variable_set('userInitVars', JSON.stringify(data));
      _callback(true, data);
      //console.log(data);
    },
    error: function () {
      _callback(false, data);
    }
  });
}

/**
 * The custom request new password form submission handler.
 */
function custom_update_user_settings_node(node) {
  //Reconfigure Entity Reference fields so that node update doesn't error.
  //Converting Value Into an Array.
  var entRefFields = ['field_wellness_goals',
    'field_user_completed_activities',
    'field_user_hidden_activities',
    'field_user_earned_badges',
    'field_user_new_earned_badges'];
  for (var fieldIndex = 0, fieldLen = entRefFields.length; fieldIndex < fieldLen; fieldIndex++) {
    if (typeof node[entRefFields[fieldIndex]]['und'] != 'undefined') {
      var field = node[entRefFields[fieldIndex]]['und'];
      var fieldVals = [];
      for (var valIndex = 0, valLen = field.length; valIndex < valLen; valIndex++) {
        fieldVals.push(field[valIndex]['target_id']); 
      }
      
      //Make sure we only have unique values
      var uniqVals = fieldVals.reduce(function(a,b){
        if (a.indexOf(b) < 0 ) a.push(b);
        return a;
      },[]);
      
      node[entRefFields[fieldIndex]]['und'] = uniqVals;
    }
  }
  node_update(node, {
    success: function() {
      //console.log('node saved');
    },
    error: function() {
      //console.log('node failed to save');
    }
  });
}

/**
 * Entity refference add value
 */
function custom_entity_reference_add_value(entity, field, value) {
  if (Array.isArray(value)) {
    if (typeof entity[field].und != 'undefined') {
      //Existing Goals Set add if not allready added.
      for (var i = 0; i < value.length; i++) {
        entity[field]['und'].push({ 'target_id' : value[i] });
      }
    } else {
      //No goals added yet set up new goals
      entity[field] = {};
      entity[field]['und'] = [];
      for (var i = 0; i < value.length; i++) {
        entity[field]['und'].push({ 'target_id' : value[i] });
      }
    }
  } else {
    if (typeof entity[field].und != 'undefined') {
      //Existing Goals Set add if not allready added.
      entity[field]['und'].push({ 'target_id' : value });
    } else {
      //No goals added yet set up new goals
      entity[field] = {};
      entity[field]['und'] = [];
      entity[field]['und'].push({ 'target_id' : value });
    }
  }
  
  return entity;
}

/**
 * Entity refference remove value
 */
function custom_entity_reference_remove_value(entity, field, value) {
  if (Array.isArray(value)) {
    if (typeof entity[field].und != 'undefined') {
      //Get list of index deltas to remove
      var entRefField = entity[field].und;
      var indexRemove = [];
      for (var i = 0; i < value.length; i++) {
        for (var valIndex = 0, fieldLen = entRefField.length; valIndex < fieldLen; valIndex++) {
          var val = entity[field].und[valIndex];
          if (val['target_id'] == value[i]) {
            indexRemove.push(valIndex);
          }
        }
      }
      //Remove the items
      for (var j = 0; j < indexRemove.length; j++) {
        if (typeof indexRemove[j] != 'undefined') {
          entity[field].und.splice(indexRemove[j], 1);
        }
      }
    }
  } else {
    if (typeof entity[field].und != 'undefined') {
      //Get list of index deltas to remove
      var entRefField = entity[field].und;
      var indexRemove = [];
      for (var valIndex = 0, fieldLen = entRefField.length; valIndex < fieldLen; valIndex++) {
        var val = entity[field].und[valIndex];
        if (val['target_id'] == value) {
          indexRemove.push(valIndex);
        }
      }
      //Remove the items
      for (var j = 0; j < indexRemove.length; j++) {
        if (typeof indexRemove[j] != 'undefined') {
          entity[field].und.splice(indexRemove[j], 1);
        }
      }
    }
  }
  
  return entity;
}

/**
 * User Number Field Value Increase value
 */
function custom_number_field_value_increase_value(entity, field, value) {
  if (typeof entity[field].und != 'undefined') {
    var existingValue = entity[field]['und']['0']['value'];
    //Existing Goals Set add if not allready added.
    entity[field]['und']['0']['value'] = parseInt(value) + parseInt(existingValue);
  } else {
    //No number added yet set up new number
    entity[field] = {};
    entity[field]['und'] = [{ 'value' : parseInt(value) }];
  }
  return entity;
}

/**
 * User Per Goal Number JSON Field Value Increase value
 */
function custom_field_update_value(entity, field, delta, value) {
  if (typeof entity[field].und != 'undefined') {
    entity[field]['und'][delta]['value'] = value;
  } else {
    //No number added yet set up new number
    entity[field] = {};
    entity[field]['und'] = [];
    entity[field]['und'][delta] = { 'value' : value };
  }
  return entity;
}

/**
 * Activity Complete Actions
 */
function custom_activity_complete_actions(userSettings, activitynode, _callback) {
  //Vars
  var vals = {};
  vals.activity_earned_data = {};
  vals.userSettings = userSettings,
  vals.userSettingsNID = vals.userSettings.nid,
  vals.activitynode = activitynode,
  vals.activityNID = activitynode.nid,
  vals.wellnessGoalTitle = activitynode.field_wellness_goal_relation.und["0"].name,
  vals.wellnessGoalID = activitynode.field_wellness_goal_relation.und["0"].target_id;
  
  //Get Calculated values returned from the server
  var activity_complete_check_path = 'mobile/app/activity-complete/'+ vals.userSettingsNID +'/'+ vals.activityNID + '/'+ vals.wellnessGoalID +'/activity-complete.json';
  views_datasource_get_view_result(activity_complete_check_path, {
    reset: true,
    success: function (activity_earned_data) {
      //Add returned json data to vals
      vals.activity_earned_data = activity_earned_data;
      
      //Add activity to completed activities.
      vals.userSettings = custom_entity_reference_add_value(vals.userSettings, 'field_user_completed_activities', vals.activityNID);
      
      //Add Points To users total points.
      if (typeof activity_earned_data['nw_gl_points'] != 'undefined') {
        vals.userSettings = custom_field_update_value(vals.userSettings, 'field_user_total_activity_points', '0', activity_earned_data['nw_gl_points']);
      }
      
      //Add Points To users wellness goal points.
      if (typeof activity_earned_data['nw_wg_points_json'] != 'undefined') {
        var wellnessGoalJSON = JSON.stringify(activity_earned_data['nw_wg_points_json']);
        vals.userSettings = custom_field_update_value(vals.userSettings, 'field_user_wellness_goal_points', '0', wellnessGoalJSON);
      }
      
      //Add new badges to user settings for new badges (clear out old new badges first).
      if (typeof vals.activity_earned_data['nw_b_ary'] != 'undefined' && vals.activity_earned_data['nw_b_ary'].length > 0) {
        //Clear new badges for new list of new badges
        vals.userSettings['field_user_new_earned_badges'] = [];
        
        //Add in the newest badges
        for (var nbindex = 0; nbindex < vals.activity_earned_data['nw_b_ary'].length; nbindex++) {
          custom_entity_reference_add_value(vals.userSettings, 'field_user_new_earned_badges', vals.activity_earned_data['nw_b_ary'][nbindex]);
        }
      }
      
      //Add new badges to user settings for running list of user earned badges.
      if (typeof vals.activity_earned_data['nw_b_ary'] != 'undefined' && vals.activity_earned_data['nw_b_ary'].length > 0) {
        //Add in the newest badges
        for (var nbindex = 0; nbindex < vals.activity_earned_data['nw_b_ary'].length; nbindex++) {
          custom_entity_reference_add_value(vals.userSettings, 'field_user_earned_badges', vals.activity_earned_data['nw_b_ary'][nbindex]);
        }
      }
      
      //Perform Callback to display results to the activity complete page.
      //console.log('vals');
      //console.log(vals);
      _callback(vals);
    }
  });
}

/**
 * Return social share link li's
 *
 */
function get_share_links(options) {
  var settings = {
    socialMsg : 'Message',
    socialImg : 'img.jpg',
    socialUrl : 'http://google.com/',
    emailMsg : 'Hey i just did this!',
    emailSub : 'Someone shared tis with you.',
  };
  jQuery.extend(settings, options);
  
  var content = '';
  //https://github.com/EddyVerbruggen/SocialSharing-PhoneGap-Plugin
  content += '<li><button class="twitter" onclick="' + "window.plugins.socialsharing.shareViaTwitter('" + settings.socialMsg + "', '" + settings.socialImg + "', '" + settings.socialUrl + "')" + '">Share via Twitter</button></li>';
  content += '<li><button class="facebook" onclick="' + "window.plugins.socialsharing.shareViaFacebook('" + settings.socialMsg + "', '" + settings.socialImg + "', '" + settings.socialUrl + "', null, null)" + '">Share via Facebook</button></li>';
  content += '<li><button class="email" onclick="' + "window.plugins.socialsharing.shareViaEmail('" + settings.emailMsg + "','" + settings.emailSub + "',null,null,null,null,null,null);" + '">Mail Share</button></li>';
  return content;
}


/**
 * Custom Function that downloads a file
 */
function custom_file_download(urlToFile) {
  //If phongap is not set and we are on web app just return.
  if (drupalgap.settings.mode != 'phonegap') { return; }
  
  var fileTransfer = new FileTransfer();
  var fileURL = cordova.file.dataDirectory + "test.txt";

  var uri = encodeURI(urlToFile);

  fileTransfer.download(
      uri,
      fileURL,
      function(entry) {
          drupalgap_alert('File has successfully downloaded.');
          //console.log("download complete: " + entry.toURL());
      },
      function(error) {
          drupalgap_alert('File has failed to download.');
          //console.log("download error source " + error.source);
          //console.log("download error target " + error.target);
          //console.log("download error code" + error.code);
      }
  );
}