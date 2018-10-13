/**************|
 * Development |
 **************/
// Uncomment to clear the app's local storage cache each time the app loads.
//window.localStorage.clear();
// Set to true to see console.log() messages. Set to false when publishing app.
Drupal.settings.debug = true;
Drupal.settings.browsersync = true;


/****************************************|
 * Drupal Settings (provided by jDrupal) |
 ****************************************/
/* DRUPAL PATHS */
// Default Services Endpoint Path
Drupal.settings.endpoint = 'drupalgap';

// Files Directory Paths (use one or the other)
Drupal.settings.file_public_path = 'sites/default/files';
//Drupal.settings.file_private_path = 'system/files';

// The Default Language Code
Drupal.settings.language_default = 'und';

/* CACHING AND PERFORMANCE */
// Entity Caching
Drupal.settings.cache.entity = {
  /* Globals (will be used if not overwritten below) */
  enabled: false,
  expiration: 60, // # of seconds to cache, set to 0 to cache forever
  /* Entity types */
  entity_types: {
    /* Comments */
    // comment: {
    // bundles: {}
    // },
     
    /* Files */
    // file: {
    // bundles: {}
    // },
     
    /* Nodes */
    // node: {
    //   // Node Globals (will be used if not overwritten below)
    //   enabled: true,
    //   expiration: 120,
    //   // Content types (aka bundles)
    //   bundles: {
    //     article: {
    //       expiration: 3600
    //     },
    //     page: {
    //       enabled: false
    //     }
    //   }
    // },

    /* Terms */
    // taxonomy_term: {
    //  bundles: {}
    //  },

    /* Vocabularies */
    // taxonomy_vocabulary: {
    // bundles: {}
    // },

    /* Users */
    // user: {
    //  bundles: {}
    //  }
  }
};

/* Views Caching */
Drupal.settings.cache.views = {
  enabled: false,
  expiration: 3600
};



/*********************|
 * DrupalGap Settings |
 *********************/
// DrupalGap Mode (defaults to 'web-app')
//  'web-app' - use this mode to build a web application for a browser window
//  'phonegap' - use this mode to build a mobile application with phonegap
drupalgap.settings.mode = 'web-app';
//drupalgap.settings.mode = 'phonegap';
// Language Files - locale/[language-code].json
drupalgap.settings.locale = {
   /* es: { } */
};



/*************|
 * Appearance |
 *************/
// App Title
drupalgap.settings.title = 'BeWell8D';
// App Front Page
drupalgap.settings.front = 'app_home';
// Theme
drupalgap.settings.theme = 'pawmwa2016';
// Logo
drupalgap.settings.logo = 'themes/pawmwa2016/images/drupalgap.jpg';
// Offline Warning Message. Set to false to hide message.
drupalgap.settings.offline_message = 'No connection found!';
// Exit app message.
drupalgap.settings.exit_message = 'Exit ' + drupalgap.settings.title + '?';
// Loader Animations - http://demos.jquerymobile.com/1.4.0/loader/
drupalgap.settings.loader = {
  loading: {
    text: 'Loading...',
    textVisible: false,
    theme: 'b'
  },
  saving: {
    text: 'Saving...',
    textVisible: false,
    theme: 'b'
  },
  deleting: {
    text: 'Deleting...',
    textVisible: false,
    theme: 'b'
  }
};



/*****************************************|
 * Modules - http://drupalgap.org/node/74 |
 *****************************************/
/** Contributed Modules - www/app/modules **/
Drupal.modules.contrib['entityreference'] = {};
Drupal.modules.contrib['push_notifications'] = {};

/** Custom Modules - www/app/modules/custom **/
Drupal.modules.custom['custom_app_init'] = {};
Drupal.modules.custom['custom_common_functions'] = {};
Drupal.modules.custom['custom_blocks'] = {};
Drupal.modules.custom['custom_pages'] = {};
Drupal.modules.custom['auth_alter_home'] = {};
Drupal.modules.custom['custom_form_alters'] = {};
Drupal.modules.custom['custom_push_notification_setup'] = {};



/***************************************|
 * Menus - http://drupalgap.org/node/85 |
 ***************************************/
drupalgap.settings.menus = {}; // Do not remove this line.



/****************************************|
 * Blocks - http://drupalgap.org/node/83 |
 ****************************************/
drupalgap.settings.blocks = {}; // Do not remove this line.
drupalgap.settings.blocks.pawmwa2016 = {
  header: {
    _prefix: {
      slide_menu_block: {
        access_callback: 'custom_blocks_slide_menu_block_access'
      }
    },
    slide_menu_block_button: {
      access_callback: 'custom_blocks_slide_menu_block_button_access'
    },
    custom_edit_button: {
      access_callback: 'custom_blocks_custom_edit_button_access'
    },
    custom_cancel_button: {
      access_callback: 'custom_blocks_custom_cancel_button_access'
    },
    custom_back_button: {
      access_callback: 'custom_blocks_custom_back_button_access'
    },
    title: {
      access_callback: 'custom_blocks_title_header_block_access'
    },
    app_title_header_block: {
      access_callback: 'custom_blocks_app_title_header_block_access'
    },
  },
  sub_header: {
  },
  navigation: {
    eight_demensions_submenu: {
      access_callback: 'custom_blocks_eight_demensions_submenu_access'
    },
    wellness_demensions_submenu: {
      access_callback: 'custom_blocks_wellness_demensions_submenu_access'
    },
    my_wellness_goal_submenu: {
      access_callback: 'custom_blocks_my_wellness_goal_submenu_access'
    },
    my_account_edit_submenu: {
      access_callback: 'custom_blocks_my_account_edit_submenu_access'
    },
    my_achievements_submenu: {
      access_callback: 'custom_blocks_my_achievements_submenu_access'
    },
  },
  content: {
    messages: { },
    main: { }
  },
  footer: {
  }
};


/****************************************************|
 * Region Menu Links - http://drupalgap.org/node/173 |
 ****************************************************/
drupalgap.settings.menus.regions = {}; // Do not remove this line.


/*********|
 * Camera |
 **********/
drupalgap.settings.camera = {
  quality: 90
};



/***********************|
 * Performance Settings |
 ***********************/
drupalgap.settings.cache = {}; // Do not remove this line.

// Theme Registry - Set to true to load the page.tpl.html contents from cache.
drupalgap.settings.cache.theme_registry = true;



/*****************************|
 * PUSH NOTIFICATION Settings |
 *****************************/
drupalgap.settings.push_notifications = {
  android: {
    senderID: "588306743907"
  },
  browser: {
      pushServiceURL: 'http://push.api.phonegap.com/v1/push'
  },
  ios: {
    alert: "true",
    badge: "true",
    sound: "true"
  },
  windows: {}
};
