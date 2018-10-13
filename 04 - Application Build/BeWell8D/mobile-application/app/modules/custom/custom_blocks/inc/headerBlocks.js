//App Title Header Block
function custom_blocks_app_title_header_block(delta, region) {
  var containers = '';
  var page_id = drupalgap_get_page_id();
  containers = '<h1 id="' + page_id + '-app-title" class="page-title"></h1>';
  containers += drupalgap_jqm_page_event_script_code({
      page_id: page_id,
      jqm_page_event: 'pageshow',
      jqm_page_event_callback: 'custom_blocks_app_title_header_block_pageshow',
      jqm_page_event_args: JSON.stringify({
          element: '#' + page_id + '-app-title'
      })
  });
  return containers;
}
function custom_blocks_app_title_header_block_pageshow(options) {
  var appVars = variable_get('appVars');
  if (typeof appVars !== 'undefined') {
    appVars = JSON.parse(appVars);
    var content = '';
    content = appVars.appTitle;
    $(options.element).html(content).trigger('create');
  } else {
    var content = '';
    content = 'App title Fail.';
    $(options.element).html(content).trigger('create');
  }
}
function custom_blocks_app_title_header_block_access(options) {
  //console.log(options); // Un-comment to reveal info about the current context.
  var access = false;
  var args = arg(null, options.path);
  switch (args[0]) {
    case 'app_home':
    case 'app_tour':
    case 'app_user_login':
    case 'app_user_pass':
    case 'app_user_reg':
      return true;
      break;
  }
  return access;
}

