function custom_blocks_eight_demensions_submenu(delta, region) {
  var content = '';
  content += '<div class="section custom_blocks_eight_demensions_submenu">';
  content += '  <ul class="ui-grid-a ui-listview" data-role="listview">';
  content += '    <li>';
  content += l('<span>About</span>', 'app_eight_demensions', {
                attributes: {
                  class: 'submenu-link'
                }
              });
  content += '    </li>';
  content += '    <li>';
  content += l('<span>Learn More</span>', 'app_eight_demensions_lm', {
                attributes: {
                  class: 'submenu-link'
                }
              });
  content += '    </li>';
  content += '  </ul>';
  content += '</div>';
  return content;
}
function custom_blocks_eight_demensions_submenu_access(options) {
  //console.log(options); // Un-comment to reveal info about the current context.
  var access = false;
  var args = arg(null, options.path);
  switch (args[0]) {
    case 'app_eight_demensions':
    case 'app_eight_demensions_lm':
      if (args.length == 1) {
        return true;
      }
      break;
  }
  return access;
}

//Wellness Demensions Submenu
function custom_blocks_wellness_demensions_submenu(delta, region) {
  var content = '';
  var tid = arg(1);
  content += '<div class="section custom_blocks_wellness_demensions_submenu">';
  content += '  <ul class="ui-grid-b ui-listview" data-role="listview">';
  content += '    <li>';
  content += l('<span>About</span>', 'app_wellness_goal/' + tid, {
                attributes: {
                  class: 'submenu-link'
                }
              });
  content += '    </li>';
  content += '    <li>';
  content += l('<span>Activities</span>', 'app_wellness_goal/' + tid + '/activities', {
                attributes: {
                  class: 'submenu-link'
                }
              });
  content += '    </li>';
  content += '    <li>';
  content += l('<span>Resources</span>', 'app_wellness_goal/' + tid + '/resources', {
                attributes: {
                  class: 'submenu-link'
                }
              });
  content += '    </li>';
  content += '  </ul>';
  content += '</div>';
  return content;
}
function custom_blocks_wellness_demensions_submenu_access(options) {
  //console.log(options); // Un-comment to reveal info about the current context.
  var access = false;
  var args = arg(null, options.path);
  switch (args[0]) {
    case 'app_wellness_goal':
      if (args.length == 2) {
        return true;
      }
      //Activities Tab
      if (args.length == 3 && args[2] == 'activities') {
        return true;
      }
      //Resources Tab
      if (args.length == 3 && args[2] == 'resources') {
        return true;
      }
      break;
  }
  return access;
}

//My Wellness Goal Submenu
function custom_blocks_my_wellness_goal_submenu(delta, region) {
  var content = '';
  var tid = arg(1);
  content += '<div class="section custom_blocks_wellness_demensions_submenu">';
  content += '  <ul class="ui-grid-b ui-listview" data-role="listview">';
  content += '    <li>';
  content += l('<span>Activities</span>', 'app_my_wellness_goal/' + tid, {
                attributes: {
                  class: 'submenu-link'
                }
              });
  content += '    </li>';
  content += '    <li>';
  content += l('<span>Resources</span>', 'app_my_wellness_goal/' + tid + '/resources', {
                attributes: {
                  class: 'submenu-link'
                }
              });
  content += '    </li>';
  content += '    <li>';
  content += l('<span>About</span>', 'app_my_wellness_goal/' + tid + '/about', {
                attributes: {
                  class: 'submenu-link'
                }
              });
  content += '    </li>';
  content += '  </ul>';
  content += '</div>';
  return content;
}
function custom_blocks_my_wellness_goal_submenu_access(options) {
  //console.log(options); // Un-comment to reveal info about the current context.
  var access = false;
  var args = arg(null, options.path);
  switch (args[0]) {
    case 'app_my_wellness_goal':
      if (args.length == 2) {
        return true;
      }
      //Resources Tab
      if (args.length == 3 && args[2] == 'resources') {
        return true;
      }
      //About Tab
      if (args.length == 3 && args[2] == 'about') {
        return true;
      }
      break;
  }
  return access;
}

//My Account Edit Submenu
function custom_blocks_my_account_edit_submenu(delta, region) {
  var content = '';
  content += '<div class="section custom_blocks_my_account_submenu">';
  content += '  <ul class="ui-grid-a ui-listview" data-role="listview">';
  content += '    <li>';
  content += l('<span>User Settings</span>', 'app_my_account/edit_user', {
                attributes: {
                  class: 'my-account-user-settings-submenu-link submenu-link'
                }
              });
  content += '    </li>';
  content += '    <li>';
  content += l('<span>App Settings</span>', 'app_my_account/edit_app', {
                attributes: {
                  class: 'my-account-app-settings-submenu-link submenu-link',
                }
              });
  content += '    </li>';
  content += '  </ul>';
  content += '</div>';
  return content;
}
function custom_blocks_my_account_edit_submenu_access(options) {
  //console.log(options); // Un-comment to reveal info about the current context.
  var access = false;
  var args = arg(null, options.path);
  switch (args[0]) {
    case 'app_my_account':
      if (args.length == 2 && (args[1] == 'edit_user' || args[1] == 'edit_app')) {
        return true;
      }
      break;
  }
  return access;
}

//My Achievements Submenu
function custom_blocks_my_achievements_submenu(delta, region) {
  var content = '';
  content += '<div class="section custom_blocks_my_account_submenu">';
  content += '  <ul class="ui-grid-a ui-listview" data-role="listview">';
  content += '    <li>';
  content += l('<span>Progress</span>', 'app_my_achievements', {
                attributes: {
                  class: 'my-achievements-submenu-link submenu-link'
                }
              });
  content += '    </li>';
  content += '    <li>';
  content += l('<span>Badges</span>', 'app_my_achievements/badges', {
                attributes: {
                  class: 'my-achievements-badges-submenu-link submenu-link',
                }
              });
  content += '    </li>';
  content += '  </ul>';
  content += '</div>';
  return content;
}
function custom_blocks_my_achievements_submenu_access(options) {
  //console.log(options); // Un-comment to reveal info about the current context.
  var access = false;
  var args = arg(null, options.path);
  switch (args[0]) {
    case 'app_my_achievements':
      if (args.length > 0) {
        return true;
      }
      break;
  }
  return access;
}