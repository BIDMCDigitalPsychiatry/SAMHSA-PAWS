/**
 * Implements hook_install().
 * Used to include our blocks in seperate files.
 */
function custom_blocks_install() {
  //Slide Menu
  drupalgap_add_js('app/modules/custom/custom_blocks/inc/headerMenus.js');
      
  //SubMenus
  drupalgap_add_js('app/modules/custom/custom_blocks/inc/subMenus.js');
      
  //Header Buttons
  drupalgap_add_js('app/modules/custom/custom_blocks/inc/headerButtons.js');
  
  //Header Blocks
  drupalgap_add_js('app/modules/custom/custom_blocks/inc/headerBlocks.js')
}

/**
 * Implements hook_block_info().
 */
function custom_blocks_block_info() {
  var blocks = {};
  //Header Menus
  blocks['slide_menu_block'] = {
    delta: 'slide_menu_block',
    module: 'custom_blocks'
  };
  blocks['slide_menu_block_button'] = {
    delta: 'slide_menu_block_button',
    module: 'custom_blocks'
  };
  
  //Header Buttons
  blocks['custom_back_button'] = {
    delta: 'custom_back_button',
    module: 'custom_blocks'
  };
  blocks['custom_cancel_button'] = {
    delta: 'custom_cancel_button',
    module: 'custom_blocks'
  };
  blocks['custom_edit_button'] = {
    delta: 'custom_edit_button',
    module: 'custom_blocks'
  };
  
  //Header Blocks
  blocks['app_title_header_block'] = {
    delta: 'app_title_header_block',
    module: 'custom_blocks'
  };
      
  //SubMenus
  blocks['eight_demensions_submenu'] = {
    delta: 'eight_demensions_submenu',
    module: 'custom_blocks'
  };
  blocks['wellness_demensions_submenu'] = {
    delta: 'wellness_demensions_submenu',
    module: 'custom_blocks'
  };
  blocks['my_wellness_goal_submenu'] = {
    delta: 'my_wellness_goal_submenu',
    module: 'custom_blocks'
  };
  blocks['my_account_edit_submenu'] = {
    delta: 'my_account_edit_submenu',
    module: 'custom_blocks'
  };
  blocks['my_achievements_submenu'] = {
    delta: 'my_achievements_submenu',
    module: 'custom_blocks'
  };
  return blocks;
}

/**
 * Implements hook_block_view().
 */
function custom_blocks_block_view(delta, region) {
  switch (delta) {
    //Header Menus
    case 'slide_menu_block':
      return custom_blocks_slide_menu_block(delta, region);
      break;
    case 'slide_menu_block_button':
      return custom_blocks_slide_menu_block_button(delta, region);
      break;
    
    //HeaderButtons
    case 'custom_back_button':
      return custom_blocks_custom_back_button(delta, region);
      break;
    case 'custom_cancel_button':
      return custom_blocks_custom_cancel_button(delta, region);
      break;
    case 'custom_edit_button':
      return custom_blocks_custom_edit_button(delta, region);
      break;
      
    //Header Blocks
    case 'app_title_header_block':
      return custom_blocks_app_title_header_block(delta, region);
      break;
      
    //SubMenus
    case 'eight_demensions_submenu':
      return custom_blocks_eight_demensions_submenu(delta, region);
      break;
    case 'wellness_demensions_submenu':
      return custom_blocks_wellness_demensions_submenu(delta, region);
      break;
    case 'my_wellness_goal_submenu':
      return custom_blocks_my_wellness_goal_submenu(delta, region);
      break;
    case 'my_account_edit_submenu':
      return custom_blocks_my_account_edit_submenu(delta, region);
      break;
    case 'my_achievements_submenu':
      return custom_blocks_my_achievements_submenu(delta, region);
      break;
  }
}

//Default Drupalgap Access Callbacks
function custom_blocks_title_header_block_access(options) {
  //console.log(options); // Un-comment to reveal info about the current context.
  var access = true;
  var args = arg(null, options.path);
  switch (args[0]) {
    case 'app_home':
    case 'app_tour':
    case 'app_user_login':
    case 'app_user_pass':
    case 'app_user_reg':
    case 'app_my_wellness_goal_add':
      return false;
      break;
  }
  return access;
}
