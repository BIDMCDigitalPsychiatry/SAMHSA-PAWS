//Custom Back Button
function custom_blocks_custom_back_button(delta, region) {
  var content = '';
  var args = arg();
  switch (args[0]) {
    case 'app_wellness_goal':
      var returnPath = 'app_eight_demensions';
      content = l('Back', returnPath, {
          attributes: {
              class: 'ui-btn-left back-button',
          }
      });
      break;
    case 'app_my_wellness_goal':
    case 'app_my_wellness_goal_all':
      var returnPath = 'app_my_wellness_goals/' + Drupal.user.uid;
      content = l('Back', returnPath, {
          reloadPage:true,
          attributes: {
              class: 'ui-btn-left back-button',
          }
      });
      break;
    
    default:
      content = l('Back', '#', {
          attributes: {
              class: 'ui-btn-left back-button',
              onclick: 'javascript:drupalgap_back();'
          }
      });
  }
  return content;
}
function custom_blocks_custom_back_button_access(options) {
  //console.log(options); // Un-comment to reveal info about the current context.
  var access = false;
  var args = arg(null, options.path);
  switch (args[0]) {
    case 'app_wellness_goal':
    case 'app_wellness_goal_activity':
    case 'app_wellness_goal_resource':
    case 'app_my_wellness_goal':
    case 'app_my_wellness_goal_all':
    case 'app_my_wellness_goal_activity':
    case 'app_my_wellness_goal_resource':
      if (args.length == 2 || args.length == 3) {
        return true;
      }
      break;
    case 'app_my_account':
      if (args[1] == 'force_reset_password') {
        return false;
      } else if (args.length == 2 || args.length == 3) {
        return true;
      }
      break;
  }
  return access;
}

//Custom Cancel Button
function custom_blocks_custom_cancel_button(delta, region) {
  var content = '';
  var args = arg();
  switch (args[0]) {
    case 'app_my_wellness_goals':
      var returnPath = 'app_my_wellness_goals/' + arg(1);
      content = l('Done', returnPath, {
          reloadPage:true,
          attributes: {
              class: 'ui-btn-right done-button',
          }
      });
      break;
    case 'app_my_wellness_goal_activities':
      var returnPath = 'app_my_wellness_goal/' + arg(1);
      content = l('Done', returnPath, {
          reloadPage:true,
          attributes: {
              class: 'ui-btn-right done-button',
          }
      });
      break;
    case 'app_my_wellness_goal_all_activities':
      var returnPath = 'app_my_wellness_goal_all/' + arg(1);
      content = l('Done', returnPath, {
          reloadPage:true,
          attributes: {
              class: 'ui-btn-right done-button',
          }
      });
      break;
    case 'app_my_account':
      var returnPath = 'app_my_account';
      content = l('Cancel', returnPath, {
          reloadPage:true,
          attributes: {
              class: 'ui-btn-right cancel-button',
          }
      });
      break;
    
    default:
      content = l('Cancel', '#', {
          attributes: {
              class: 'ui-btn-right cancel-button',
              onclick: 'javascript:drupalgap_back();'
          }
      });
  }
  return content;
}
function custom_blocks_custom_cancel_button_access(options) {
  //console.log(options); // Un-comment to reveal info about the current context.
  var access = false;
  var args = arg(null, options.path);
  switch (args[0]) {
    case 'app_my_wellness_goals':
      if (args.length == 3 && args[2] == 'edit') {
        return true;
      }
      break;
    case 'app_my_wellness_goal_activities':
      if (args.length == 3 && args[2] == 'edit') {
        return true;
      }
      break;
    case 'app_my_wellness_goal_all_activities':
      if (args.length == 3 && args[2] == 'edit') {
        return true;
      }
      break;
    case 'app_my_account':
      if (args[1] == 'force_reset_password') {
        return false;
      } else if (args.length == 2) {
        return true;
      }
      break;
  }
  return access;
}

//My Wellness Goals Edit Button
function custom_blocks_custom_edit_button(delta, region) {
  var content = '';
  var args = arg();
  switch (args[0]) {
    case 'app_my_wellness_goals':
      content = l('Edit', 'app_my_wellness_goals/' + Drupal.user.uid + '/edit', {
          reloadPage: true,
          attributes: {
              class: 'ui-btn-right edit-button',
          }
      });
      break;
    case 'app_my_wellness_goal':
      var tid = args[1];
      content = l('Edit', 'app_my_wellness_goal_activities/' + tid + '/edit', {
          reloadPage: true,
          attributes: {
              class: 'ui-btn-right edit-button',
          }
      });
      break;
    case 'app_my_wellness_goal_all':
      var uid = args[1];
      content = l('Edit', 'app_my_wellness_goal_all_activities/' + uid + '/edit', {
          reloadPage: true,
          attributes: {
              class: 'ui-btn-right edit-button',
          }
      });
      break;
    case 'app_my_account':
      content = l('Edit', 'app_my_account/edit_user', {
          reloadPage: true,
          attributes: {
              class: 'ui-btn-right edit-button',
          }
      });
      break;
  }
  return content;
}
function custom_blocks_custom_edit_button_access(options) {
  //console.log(options); // Un-comment to reveal info about the current context.
  var access = false;
  var args = arg(null, options.path);
  switch (args[0]) {
    case 'app_my_wellness_goals':
    case 'app_my_wellness_goal':
    case 'app_my_wellness_goal_all':
      if (args.length == 2) {
        return true;
      }
      break;
    case 'app_my_account':
      if (args.length == 1) {
        return true;
      }
      break;
  }
  return access;
}