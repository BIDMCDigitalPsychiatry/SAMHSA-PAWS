// ======================== //
// My Achievements Progress //
// ======================== //

//Callback
function custom_pages_app_my_achievements() {
  var pageContainers = '';
  pageContainers += '<div id="app_my_achievements_progress_uid_' + Drupal.user.uid + '"></div>';
  return pageContainers;
}

//PageShow
function custom_pages_app_my_achievements__ps() {
  //Get Calculated values returned from the server
  var my_achievements_path = 'mobile/app/my-achievments/'+ Drupal.user.uid +'/progress.json';
  views_datasource_get_view_result(my_achievements_path, {
    reset: true,
    success: function (data) {
      //console.log(data);
      var progress = data.progress;
      var content = '';
      
      content += '<ul class="achv-progress t-center">';
      
      for (var progCount = 0; progCount < progress.length; progCount++) {
        content += '<li class="section achv-progress--item -' + progress[progCount].wg_class + '">';
        content += '  <h3 class="h3 -orange  achv-progress--title">' + progress[progCount].wg_name + '</h3>';
        content += '  <div id="prog-chart-id-' + progress[progCount].wg_id + '" class="achv-chart -' + progress[progCount].wg_class + ' scrollpoint" data-min="' + progress[progCount].act_comp + '" data-max="' + progress[progCount].act_all + '"></div>';
        content += '  <div class="achv-progress--earned t-large">';
        content += '    <span class="achv-progress--earned-points">' + progress[progCount].points_fmt + '</span>';
        content += '    <span class="achv-progress--earned-text t-detail"> Points Earned</span>';
        content += '  </div>';
        content += '  <div class="achv-progress--completed">';
        content += '    <div class="achv-progress--completed-range  t-large-x">';
        content += '      <span>' + progress[progCount].act_comp + '</span>';
        content += '      <span class="t-detail"> of </span>';
        content += '      <span>' + progress[progCount].act_all + '</span>';
        content += '    </div>';
        content += '    <div class="t-large t-detail">';
        content += '      Activities Completed';
        content += '    </div>';
        content += '  </div>';
        content += '</li>';
      }
      
      content += '</ul>';
      
      $('#app_my_achievements_progress_uid_' + Drupal.user.uid).html(content).trigger('create');
      
      //Run chart JS Here
      $(this).progressCharts();
    }
  });
}

// ====================== //
// My Achievements Badges //
// ====================== //

//Callback
function custom_pages_app_my_achievements_badges() {
  var pageContainers = '';
  pageContainers += '<div id="app_my_achievements_badges_uid_' + Drupal.user.uid + '"></div>';
  return pageContainers;
}

//PageShow
function custom_pages_app_my_achievements_badges__ps() {
  //Get Calculated values returned from the server
  var my_achievements_path = 'mobile/app/my-achievments/'+ Drupal.user.uid +'/badges.json';
  views_datasource_get_view_result(my_achievements_path, {
    reset: true,
    success: function (data) {
      //console.log(data);
      var content = '';
      
      var badges = data.badges;
      
      //Loop and output badge info
      content += '<ul>';
      for (var goalCount = 0; goalCount < badges.length; goalCount++) {
        content += '  <li class="p-top-large">';
        content += '    <h3 class="section h3 -orange">' + badges[goalCount][0].wg_name + '</h3>';
        content += '    <ul class="list-badges">';
        for (var badgeCount = 0; badgeCount < badges[goalCount].length; badgeCount++) {
          var badge = badges[goalCount][badgeCount];
          var subline = '';
          switch (badge['badge_type']) {
            case 'Points Accumulated':
              subline += badge['badge_pnts'] + ' Points Earned';
              break;
            case 'Specific Activity Type Complete':
              var activity_type = badge['badge_act_type'].replace("Activity", "Activities");
              subline += 'Completed All ' + activity_type;
              break;
            case 'All Activities Complete':
              subline += 'Completed All Activities';
              break;
          }
          
          //Set the output
          content += '<li class="section  list-badges--item -' + badge['wg_class'] + ' badge-item-' + badge['badge_id'] + '">';
          content += '  <div class="list-badges--body">';
          content += '    <div>' + badge['badge_name'] + '</div>';
          content += '    <div class="t-detail">'+ subline +'</div>';
          content += '  </div>';
          content += '</li>';
        }
        content += '    </ul>';
        content += '</li>';
      }
      content += '</ul>';

      //Use JS to insert the content
      $('#app_my_achievements_badges_uid_' + Drupal.user.uid).html(content).trigger('create');
    }
  });
}