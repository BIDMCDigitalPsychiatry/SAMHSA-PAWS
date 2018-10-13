// =================== //
// How to Use This App //
// =================== //

//Callback
function custom_pages_app_how_to_use() {
  var pageContainers = '';
  pageContainers += '<div id="app_how_to_use_content_nid_3"></div>';
  return pageContainers;
}

//PageShow
function custom_pages_app_how_to_use__ps() {
  node_load(3, {
    success: function(node) {
      //console.log(node);
      var content = '';
      //App Page Title
      content += '<div class="section section-med">';
      
      content += '  <p class="t-small t-detail t-italic m-btm-small">How to Use This App</p>';
      
      //Content Body
      content += '  <div class="wysiwyg">'
      content += node['field_body'].und['0'].safe_value;
      content += '  </div>';
      content += '</div>';
  
      //Use JS to insert the content
      $('#app_how_to_use_content_nid_3').html(content).trigger('create');
      
      //Run Accordions
      $(this).collapsiblesBundle();
    }
  });
}