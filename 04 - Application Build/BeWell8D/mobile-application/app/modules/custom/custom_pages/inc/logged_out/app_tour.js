// ========== //
//  APP TOUR  //
// ========== //

//Callback
function custom_pages_app_tour_page() {
  var pageContainers = '';
  pageContainers += '<div id="app_tour_page_content"></div>';
  return pageContainers;
}

//Page Show
function custom_pages_app_tour_page__ps() {
  var appVars = variable_get('appVars');
  if (typeof appVars !== 'undefined') {
    appVars = JSON.parse(appVars);
    
    var content = '';
    
    //App Tour Banner Image
    content += page_partial_icon_image_separator('page-top');
    
    
    //App Tour Overview
    content += '<div class="section section-med">';
    //App Tour Title
    content += '  <h2 class="h2 -blue -line">' + appVars.appTitle + ' Features</h2>';
    content +=   '<div class="wysiwyg">';
    content += appVars.tour.overallText;
    content +=   '</div>';
    content += '</div>';
    
    //App Tour - Set Goals
    content += '<div class="section section-med section-grey">';
    content += '  <h2 class="h3 -orange">Set Your Goals</h2>';
    content += '  <div class="wysiwyg">';
    content += appVars.tour.sections.section1;
    content += '  </div>';
    content += '  <div class="section--pull  img-content -phones">';
    content += '  </div>';
    content += '</div>';
    
    //App Tour - Activities
    content += '<div class="section section-med  tour-act">';
    content += '  <h2 class="h3 -orange">Activities</h2>';
    content += '  <div class="wysiwyg  tour-act--body">';
    content += appVars.tour.sections.section2;
    content += '  </div>';
    content += '</div>';
    
    //App Tour - Resources
    content += '<div class="section section-med section-grey  tour-resources">';
    content += '  <h2 class="h3 -orange">Resources</h2>';
    content += '  <div class="tour-resources--body wysiwyg">';
    content += appVars.tour.sections.section3;
    content += '  </div>';
    content += '  <div class="section--pull  img-content -screens">';
    content += '  </div>';
    content += '</div>';
    
    //App Tour - Track Your Progress
    content += '<div class="section section-med  tour-typ">';
    content += '  <div class="img-content -track">';
    content += '  </div>';
    content += '  <hr class="hr-large">';
    content += '  <h2 class="h3 -orange">Track Your Progress</h2>';
    content += '  <div class="tour-typ--body  wysiwyg">';
    content += appVars.tour.sections.section4;
    content += '  </div>';
    content += '</div>';
    
    //App Tour - Recieve Messages
    content += '<div class="section section-med section-grey  tour-rm">';
    content += '  <div class="m-btm  img-content -messages">';
    content += '  </div>';
    content += '  <h2 class="h3 -orange">Recieve Messages</h2>';
    content += '  <div class="tour-rm--body  wysiwyg">';
    content += appVars.tour.sections.section5;
    content += '  </div>';
    content += '</div>';
    
    //Page Links
    var get_started_link = bl('Let\'s Get Started!', 'app_user_login', {
      'attributes':  {
        'class': 'btn'
      }
    });
    content += '<div class="section section-large  separator-circles -footer">';
    content += '  <ul class="page-buttons">';
    content += '    <li>' + get_started_link + '</li>';
    content += '  </ul>';
    content += '</div>';
    
    //Use JS to insert the content
    $('#app_tour_page_content').html(content).trigger('create');
  }
}