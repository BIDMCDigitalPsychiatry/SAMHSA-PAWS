// ============ //
// Crisis Lines //
// ============ //

//Callback
function custom_pages_app_crisis_lines() {
  var pageContainers = '';
  pageContainers += '<div id="app_crisis_lines_content_nid_5"></div>';
  return pageContainers;
}

//PageShow
function custom_pages_app_crisis_lines__ps() {
  node_load(5, {
    success: function(node) {
      //console.log(node);
      var content = '';
      //Goal Page Title
      content += '<div class="banner-icon banner-icon-crisis-lines">';
      content += '  <div class="banner-icon--body">';
      content += '    <h2 class="banner-icon--title">If You Are in Immediate Danger Call 911</h2>';
      content += '  </div>';
      content += '</div>';

      //App Page Title
      // content += '<div class="section">';
      // content += '  <h2 class="page-title">' + node.title + '</h2>';
      // content += '</div>';
      
      //Content Body
      content += '<div class="section section-med">';
      content += '  <div class="wysiwyg">';
      try {
        content += node['field_body'].und['0'].safe_value;
      } catch (e) {}
      content += '  </div>';
      content += '</div>';

      //Additonal Crisis Lines
      content += '<div class="section section-med section-grey">';
      content += '<h2 class="h3 -blue -line">Additional Crisis Lines</h2>';
      content += '  <div class="wysiwyg">';
      try {
        content += node['field_body_2'].und['0'].safe_value;
      } catch (e) {}
      content += '  </div>';
      content += '</div>';
  
      //Use JS to insert the content
      $('#app_crisis_lines_content_nid_5').html(content).trigger('create');
    }
  });
}