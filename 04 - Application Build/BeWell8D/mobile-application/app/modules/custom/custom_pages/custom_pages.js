/**
 * Implements hook_install().
 * Used to include our pages in seperate files.
 */
function custom_pages_install() {
  //Page Partials
  drupalgap_add_js('app/modules/custom/custom_pages/inc/page_partials/page_partials_views.js');
  drupalgap_add_js('app/modules/custom/custom_pages/inc/page_partials/page_partials_separators.js');
  
  //Logged Out
  drupalgap_add_js('app/modules/custom/custom_pages/inc/logged_out/app_home.js');
  drupalgap_add_js('app/modules/custom/custom_pages/inc/logged_out/app_tour.js');
  drupalgap_add_js('app/modules/custom/custom_pages/inc/logged_out/app_user_login.js');
  drupalgap_add_js('app/modules/custom/custom_pages/inc/logged_out/app_user_reg.js');
  drupalgap_add_js('app/modules/custom/custom_pages/inc/logged_out/app_user_pass.js');
  
  //Logged In
  drupalgap_add_js('app/modules/custom/custom_pages/inc/logged_in/app_eight_demensions.js');
  drupalgap_add_js('app/modules/custom/custom_pages/inc/logged_in/app_how_to_use.js');
  drupalgap_add_js('app/modules/custom/custom_pages/inc/logged_in/app_disclaimers.js');
  drupalgap_add_js('app/modules/custom/custom_pages/inc/logged_in/app_crisis_lines.js');
  drupalgap_add_js('app/modules/custom/custom_pages/inc/logged_in/app_my_wellness_goal.js');
  drupalgap_add_js('app/modules/custom/custom_pages/inc/logged_in/app_my_wellness_goal_activity.js');
  drupalgap_add_js('app/modules/custom/custom_pages/inc/logged_in/app_my_wellness_goal_activity_badge.js');
  drupalgap_add_js('app/modules/custom/custom_pages/inc/logged_in/app_my_achievements.js');
  drupalgap_add_js('app/modules/custom/custom_pages/inc/logged_in/app_my_account.js');
  
  //Offline
  drupalgap_add_js('app/modules/custom/custom_pages/inc/offline/app_offline.js');
}


/**
 * Implements hook_menu().
 */
function custom_pages_menu() {
  var items = {};
  
  //============//
  // Logged Out //
  //============//
  
  //Home
  items['app_home'] = {
    title: 'Welcome to AppNAME',
    page_callback: 'custom_pages_app_home_page',
    pageshow: 'custom_pages_app_home_page__ps',
  };
  
  //Tour
  items['app_tour'] = {
    title: 'Tour',
    page_callback: 'custom_pages_app_tour_page',
    pageshow: 'custom_pages_app_tour_page__ps',
  };
  
  //User Login
  items['app_user_login'] = {
    title: 'User Login',
    page_callback: 'custom_pages_app_user_login_page',
    pageshow: 'custom_pages_app_user_login_page__ps',
    options: {reloadPage: true},
  };
  
  //Usr Registration
  items['app_user_reg'] = {
    title: 'Create User Account',
    page_callback: 'custom_pages_app_user_reg_page',
    pageshow: 'custom_pages_app_user_reg_page__ps',
    options: {reloadPage: true},
  };
  
  //User Password Reset
  items['app_user_pass'] = {
    title: 'Request New Password',
    page_callback: 'custom_pages_app_user_pass_page',
    pageshow: 'custom_pages_app_user_pass_page__ps',
    options: {reloadPage: true},
  };
  
  //===========//
  // Logged In //
  //===========//
  
  //Eight Demensions Of Wellness
  items['app_eight_demensions'] = {
    title: 'Eight Dimensions of Wellness', //About Page
    page_callback: 'custom_pages_app_eight_demensions',
    pageshow: 'custom_pages_app_eight_demensions__ps',
  };
      items['app_eight_demensions_lm'] = {
        title: 'Eight Dimensions of Wellness', //Learn More Page
        page_callback: 'custom_pages_app_eight_demensions_lm',
        pageshow: 'custom_pages_app_eight_demensions_lm__ps',
      };
      
      //Wellness Goal
      items['app_wellness_goal/%'] = {
        title: 'Wellness Dimensions', //About Page
        title_callback: 'custom_pages_app_wellness_goal_title_callback',
        title_arguments: [1],
        page_callback: 'custom_pages_app_wellness_goal',
        page_arguments: [1],
        pageshow: 'custom_pages_app_wellness_goal__ps',
        options: {reloadPage: true},
      };
        items['app_wellness_goal/%/activities'] = {
          title: 'Wellness Dimensions', //Activities Page
          title_callback: 'custom_pages_app_wellness_goal_title_callback',
          title_arguments: [1],
          page_callback: 'custom_pages_app_wellness_goal_activities',
          page_arguments: [1],
          pageshow: 'custom_pages_app_wellness_goal_activities__ps',
        };
        items['app_wellness_goal/%/resources'] = {
          title: 'Wellness Dimensions', //Resources Page
          title_callback: 'custom_pages_app_wellness_goal_title_callback',
          title_arguments: [1],
          page_callback: 'custom_pages_app_wellness_goal_resources',
          page_arguments: [1],
          pageshow: 'custom_pages_app_wellness_goal_resources__ps',
        };
        
          //Activity
          items['app_wellness_goal_activity/%'] = {
            title: 'Wellness Activity', //Resources Page
            page_callback: 'custom_pages_app_wellness_goal_activity',
            page_arguments: [1],
            pageshow: 'custom_pages_app_wellness_goal_activity__ps',
          };
          //Resource
          items['app_wellness_goal_resource/%'] = {
            title: 'Wellness Resource', //Resources Page
            page_callback: 'custom_pages_app_wellness_goal_resource',
            page_arguments: [1],
            pageshow: 'custom_pages_app_wellness_goal_resource__ps',
          };
    
  //How To Use
  items['app_how_to_use'] = {
    title: 'How to Use This App',
    page_callback: 'custom_pages_app_how_to_use',
    pageshow: 'custom_pages_app_how_to_use__ps',
  };
  
  //Disclaimers
  items['app_disclaimers'] = {
    title: 'Disclaimers and Acknowledgements',
    page_callback: 'custom_pages_app_disclaimers',
    pageshow: 'custom_pages_app_disclaimers__ps',
  };
  
  //Crisis Lines
  items['app_crisis_lines'] = {
    title: 'Crisis Lines',
    page_callback: 'custom_pages_app_crisis_lines',
    pageshow: 'custom_pages_app_crisis_lines__ps',
  };
  
  //My Wellness Goals
  items['app_my_wellness_goals/%'] = {
    title: 'My Wellness Goals',
    page_callback: 'custom_pages_app_my_wellness_goals',
    page_arguments: [1],
    pageshow: 'custom_pages_app_my_wellness_goals__ps',
    options: {reloadPage: true},
  };
    items['app_my_wellness_goals/%/edit'] = {
      title: 'My Wellness Goals',
      page_callback: 'custom_pages_app_my_wellness_goals_edit',
      page_arguments: [1],
      pageshow: 'custom_pages_app_my_wellness_goals_edit__ps',
      options: {reloadPage: true},
    };
  
    //My Wellness Goal
    items['app_my_wellness_goal/%'] = {
      title: 'Wellness Goal',
      title_callback: 'custom_pages_app_my_wellness_goal_title_callback',
      title_arguments: [1],
      page_callback: 'custom_pages_app_my_wellness_goal',
      page_arguments: [1],
      pageshow: 'custom_pages_app_my_wellness_goal__ps',
      options: {reloadPage: true},
    };
      items['app_my_wellness_goal/%/resources'] = {
        title: 'Wellness Goal', //Resources Page
        title_callback: 'custom_pages_app_my_wellness_goal_title_callback',
        title_arguments: [1],
        page_callback: 'custom_pages_app_my_wellness_goal_resources',
        page_arguments: [1],
        pageshow: 'custom_pages_app_my_wellness_goal_resources__ps',
      };
      items['app_my_wellness_goal/%/about'] = {
        title: 'Wellness Goal', //Activities Page
        title_callback: 'custom_pages_app_my_wellness_goal_title_callback',
        title_arguments: [1],
        page_callback: 'custom_pages_app_my_wellness_goal_about',
        page_arguments: [1],
        pageshow: 'custom_pages_app_my_wellness_goal_about__ps',
      };
      items['app_my_wellness_goal_activities/%/edit'] = {
        title: 'Edit Activities',
        page_callback: 'custom_pages_app_my_wellness_goal_activities_edit',
        page_arguments: [1],
        pageshow: 'custom_pages_app_my_wellness_goal_activities_edit__ps',
        options: {reloadPage: true},
      };
    items['app_my_wellness_goal_all/%'] = {
      title: 'All My Activities',
      page_callback: 'custom_pages_app_my_wellness_goal_all',
      page_arguments: [1],
      pageshow: 'custom_pages_app_my_wellness_goal_all__ps',
      options: {reloadPage: true},
    };
      items['app_my_wellness_goal_all/%/resources'] = {
        title: 'All My Resources', //Resources Page
        page_callback: 'custom_pages_app_my_wellness_goal_all_resources',
        page_arguments: [1],
        pageshow: 'custom_pages_app_my_wellness_goal_all_resources__ps',
      };
      items['app_my_wellness_goal_all_activities/%/edit'] = {
        title: 'Edit All My Activities',
        page_callback: 'custom_pages_app_my_wellness_goal_all_activities_edit',
        page_arguments: [1],
        pageshow: 'custom_pages_app_my_wellness_goal_all_activities_edit__ps',
        options: {reloadPage: true},
      };
    items['app_my_wellness_goal_add/%'] = {
      title: 'Added Wellness Goal',
      page_callback: 'custom_pages_app_my_wellness_goal_add',
      page_arguments: [1],
      pageshow: 'custom_pages_app_my_wellness_goal_add__ps',
      options: {reloadPage: true},
    };
  
    //My Wellness Goal Activity
    items['app_my_wellness_goal_activity/%'] = {
      title: 'My Wellness Activity',
      page_callback: 'custom_pages_app_my_wellness_goal_activity',
      page_arguments: [1,2],
      pageshow: 'custom_pages_app_my_wellness_goal_activity__ps',
    };
      items['app_my_wellness_goal_activity/%/complete'] = {
        title: 'Wellness Activity Complete',
        page_callback: 'custom_pages_app_my_wellness_goal_activity_complete',
        page_arguments: [1,2],
        pageshow: 'custom_pages_app_my_wellness_goal_activity_complete__ps',
        options: {reloadPage: true},
      };
  
    //My Wellness Goal Resource
    items['app_my_wellness_goal_resource/%'] = {
      title: 'My Wellness Resource',
      page_callback: 'custom_pages_app_my_wellness_goal_resource',
      page_arguments: [1],
      pageshow: 'custom_pages_app_my_wellness_goal_resource__ps',
    };
    
  //My Achievements
  items['app_my_achievements'] = {
    title: 'My Achievements',
    page_callback: 'custom_pages_app_my_achievements',
    page_arguments: [1],
    pageshow: 'custom_pages_app_my_achievements__ps',
    options: {reloadPage: true},
  };
    items['app_my_achievements/badges'] = {
      title: 'My Achievements',
      page_callback: 'custom_pages_app_my_achievements_badges',
      page_arguments: [1],
      pageshow: 'custom_pages_app_my_achievements_badges__ps',
      options: {reloadPage: true},
    };
    
  //My Account
  items['app_my_account'] = {
    title: 'My Account',
    page_callback: 'custom_pages_app_my_account',
    pageshow: 'custom_pages_app_my_account__ps',
    options: {reloadPage: true},
  };
  items['app_my_account/edit_user'] = {
    title: 'Edit User Settings',
    page_callback: 'custom_pages_app_my_account_edit_user',
    pageshow: 'custom_pages_app_my_account_edit_user__ps',
    options: {reloadPage: true},
  };
  items['app_my_account/force_reset_password'] = {
    title: 'Password Expired',
    page_callback: 'custom_pages_app_my_account_force_reset_password',
    pageshow: 'custom_pages_app_my_account_force_reset_password__ps',
    options: {reloadPage: true},
  };
  items['app_my_account/edit_app'] = {
    title: 'Edit App Settings',
    page_callback: 'custom_pages_app_my_account_edit_app',
    pageshow: 'custom_pages_app_my_account_edit_app__ps',
    options: {reloadPage: true},
  };
  
  
  return items; 
}

/**
 * Implements hook_deviceready().
 * Used to alter pages before show
 */
function custom_pages_deviceready() {
  //Used to alter existing pages.
  //console.log(drupalgap);
  
  //Set the offline page
  drupalgap.menu_links['offline'].title = 'No Connection: Offline';
  drupalgap.menu_links['offline'].page_callback = 'app_offline_page';
  drupalgap.menu_links['offline'].pageshow = 'app_offline_page__ps';
  
  //Add No Nav Classes
  //drupalgap.menu_links['app_home'].options.attributes.class += 'no-app-nav ';
  //drupalgap.menu_links['app_tour'].options.attributes.class += 'no-app-nav ';
  //drupalgap.menu_links['app_user_login'].options.attributes.class += 'no-app-nav ';
  //drupalgap.menu_links['app_user_pass'].options.attributes.class += 'no-app-nav ';
  //drupalgap.menu_links['app_user_reg'].options.attributes.class += 'no-app-nav ';
  
  //Transparent Header
  drupalgap.menu_links['app_my_wellness_goal_add/%'].options.attributes.class += 'header-transparent  bg-img bg-img--splash ';
  drupalgap.menu_links['app_my_wellness_goal_activity/%/complete'].options.attributes.class += 'header-transparent  bg-img bg-img--splash ';

  
  //No Sub Nav
  drupalgap.menu_links['app_home'].options.attributes.class += 'no-app-sub-nav ';
  drupalgap.menu_links['app_tour'].options.attributes.class += 'no-app-sub-nav ';
  drupalgap.menu_links['app_user_login'].options.attributes.class += 'no-app-sub-nav ';
  drupalgap.menu_links['app_user_pass'].options.attributes.class += 'no-app-sub-nav ';
  drupalgap.menu_links['app_user_reg'].options.attributes.class += 'no-app-sub-nav ';
  drupalgap.menu_links['app_my_wellness_goal_add/%'].options.attributes.class += 'no-app-sub-nav ';
}

/**
 * Implements hook_services_postprocess().
 * @param {Object} options
 * @param {Object} result
 */
function custom_pages_services_postprocess(options, result) {
  try {
    $args = arg();
    switch ($args[0]) {
      case 'app_user_login':
      case 'app_user_pass':
      case 'app_user_reg':
        // If there were any form errors, alert them to the user.
        if (!result.responseText) { return; }
        var response = JSON.parse(result.responseText);
        if ($.isArray(response)) {
          var msg = '';
          for (var index in response) {
              if (!response.hasOwnProperty(index)) { continue; }
              var message = response[index];
              msg += t(message) + '\n';
          }
          if (msg != '') { drupalgap_alert(msg); }
        }
        break;
      
      default:
        return;
    }
  }
  catch (error) { console.log('custom_pages_services_postprocess - ' + error); }
}