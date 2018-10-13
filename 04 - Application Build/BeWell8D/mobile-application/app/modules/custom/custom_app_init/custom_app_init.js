
/**
 * Implements hook_deviceready().
 */
function custom_app_init_deviceready() {
  //Load initial site vars at the begining of app load every time.
  custom_site_vars_load(function(success) { 
    //Load the crisis lines info for offline view at app load time.
    node_load(5, {
      success: function(node) {
        variable_set('offline_crisis_lines_information', JSON.stringify(node));
        return success;
      }
    });
  });
  
}

