//Slide Menu Block
function custom_blocks_slide_menu_block(delta, region) {
  var content = '';
  
  var attrs = {
    id: drupalgap_panel_id(delta),
    'data-role': 'panel',
    'data-position': 'left', // left or right
    'data-display': 'overlay' // overlay, reveal or push
  };
  
  content += '<div ' + drupalgap_attributes(attrs) + '>';
  //Section 1
  content += '<ul class="menu-slide--section">';
  content += '  <li>' + l('Eight Dimensions of Wellness', 'app_eight_demensions', {
        attributes: {
          'class': 'menu-slide--item -dimension'
        }
    }) + '</li>';
  content += '</ul>';
  //Section 2
  content += '<ul class="menu-slide--section">';
  content += '  <li>' + l('My Wellness Goals', 'app_my_wellness_goals/' + Drupal.user.uid, {
        attributes: {
          'class': 'menu-slide--item -wellness-goals'
        }
    }) + '</li>';
  content += '  <li>' + l('My Achievements', 'app_my_achievements', {
        attributes: {
          'class': 'menu-slide--item -achievements'
        }
    }) + '</li>';
  content += '</ul>';
  //Section 3
  content += '<ul class="menu-slide--section">';
  content += '  <li>' + l('My Account', 'app_my_account', {
        attributes: {
          'class': 'menu-slide--item -account'
        }
    }) + '</li>';
  content += '  <li>' + l('How to Use This App', 'app_how_to_use', {
        attributes: {
          'class': 'menu-slide--item -how-to-use'
        }
    }) + '</li>';
  content += '  <li>' + l('Disclaimers and Acknowledgements', 'app_disclaimers', {
        attributes: {
          'class': 'menu-slide--item -disclaimers'
        }
    }) + '</li>';
  content += '</ul>';
  //Section 4
  content += '<ul class="menu-slide--section">';
  content += '  <li>' + l('Crisis Lines', 'app_crisis_lines', {
        attributes: {
          'class': 'menu-slide--item -crisis-lines'
        }
    }) + '</li>';
  content += '</ul>';
  //Section 5
  content += '<ul class="menu-slide--section">';
  content += '  <li>' + l('Sign Out', 'user/logout', {
        attributes: {
          'class': 'menu-slide--item -logout'
        }
    }) + '</li>';
  content += '</ul>';
  content += '</div>';
        
  return content;
}
function custom_blocks_slide_menu_block_access(options) {
  //console.log(options); // Un-comment to reveal info about the current context.
  if (Drupal.user.uid) {
    var access = true;
    var args = arg(null, options.path);
    switch (args[0]) {
      case 'app_home':
      case 'app_tour':
      case 'app_user_login':
      case 'app_user_pass':
      case 'app_user_reg':
      case 'offline':
        return false;
        break;
      case 'app_wellness_goal_activity':
      case 'app_wellness_goal_resource':
      case 'app_my_wellness_goal':
      case 'app_my_wellness_goal_all':
      case 'app_my_wellness_goal_activity':
      case 'app_my_wellness_goal_activities':
      case 'app_my_wellness_goal_resource':
      case 'app_my_account':
        if (args.length == 2 || args.length == 3) {
          return false;
        }
        break;
      case 'app_wellness_goal':
        if (args.length == 2 || args.length == 3) {
          return false;
        }
        break;
    }
    return access;
  } else {
    return false;
  }
}

//Slide Menu Block Button
function custom_blocks_slide_menu_block_button(delta, region) {
  var content = '';
  
  content = l('Menu', '#' + drupalgap_panel_id('slide_menu_block'), {
      attributes: {
      }
  });
  
  return content;
}
function custom_blocks_slide_menu_block_button_access(options) {
  //console.log(options); // Un-comment to reveal info about the current context.
  
  //Pull in the same options as the menu because these ojects should always show together or not
  return custom_blocks_slide_menu_block_access(options);
}