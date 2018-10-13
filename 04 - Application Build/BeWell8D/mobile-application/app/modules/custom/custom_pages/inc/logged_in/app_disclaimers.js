// ================================ //
// Disclaimers and Acknowledgements //
// ================================ //

//Callback
function custom_pages_app_disclaimers() {
  var pageContainers = '';
  pageContainers += '<div id="app_disclaimers_content_nid_4"></div>';
  return pageContainers;
}

//PageShow
function custom_pages_app_disclaimers__ps() {
  node_load(4, {
    success: function(node) {
      //console.log(node);
      var content = '';
      //App Page Title
      content += '<div class="section section-med">';
      content += '  <h2 class="h2 -line -blue">' + node.title + '</h2>';
      //Content Body
      content += '  <div class="wysiwyg">';
      content += node['field_body'].und['0'].safe_value;
      content += '  </div>';
      content += '</div>';
  
      //Use JS to insert the content
      $('#app_disclaimers_content_nid_4').html(content).trigger('create');
    }
  });
}