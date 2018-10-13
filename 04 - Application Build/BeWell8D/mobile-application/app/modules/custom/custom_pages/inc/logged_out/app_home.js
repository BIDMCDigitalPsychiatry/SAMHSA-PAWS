// ========== //
//  APP HOME  //
// ========== //

// Callback
function custom_pages_app_home_page() {
  var pageContainers = '';
  pageContainers += '<div id="app_home_page_content"></div>';
  return pageContainers;
}

// PageShow
function custom_pages_app_home_page__ps() {
  var appVars = variable_get('appVars');
  if (typeof appVars !== 'undefined') {
    appVars = JSON.parse(appVars);
    
    //Set Home Page
    var content = '';
      
    //App Home Banner Image
    content += page_partial_icon_image_separator('page-top');
      
    //App Home Title
    content += '<div class="section section-med p-btm-no">';
    content += '  <h2 class="h2 -blue -line  page-title">Welcome to ' + appVars.appTitle + '</h2>';
    content += '</div>';
      
    //App Home Slider
    content += '<div class="section  home-slider">';
    content += '<ul class="home-slider-list cycle-slider" data-cycle-swipe="true" data-cycle-slides=".home-slider-item" data-cycle-log="false" data-cycle-fx="fade" data-cycle-swipe-fx="fade" data-cycle-timeout="0" data-cycle-auto-height="calc" data-cycle-pager=".home-slider-pager">';
    content += ' <li class="home-slider-item">';
    content += '   <div class="slide-content wysiwyg">';
    content += appVars.home.slider.slide1;
    content += '   </div>';
    content += ' </li>';
    content += ' <li class="home-slider-item">';
    content += '   <div class="slide-content wysiwyg">';
    content += appVars.home.slider.slide2;
    content += '   </div>';
    content += ' </li>';
    content += ' <li class="home-slider-item">';
    content += '   <div class="slide-content wysiwyg">';
    content += appVars.home.slider.slide3;
    content += '   </div>';
    content += ' </li>';
    content += '</ul>';
    content += '<div class="home-slider-pager"></div>';
    content += '</div>';
      
    //Page Links
    var tour_link = bl('Take a Tour', 'app_tour', {
      'attributes':  {
        'class': 'btn'
      }
    });
    var get_started_link = bl('Let\'s Get Started!', 'app_user_login', {
      'attributes':  {
        'class': 'btn'
      }
    });
    content += '<div class="section section-med">';
    content += '  <ul class="page-buttons -inline">';
    content += '    <li>' + tour_link + '</li>';
    content += '    <li>' + get_started_link + '</li>';
    content += '  </ul>';
    content += '</div>';
    
    //SAMHSA Logo Page Footer
    content += '<div class="section section-med bg-black-5">';
    content += '  <div class="samhsa-logo"></div>';
    content += '</div>';
  
    //Use JS to insert the content
    $('#app_home_page_content').html(content).trigger('create');
    
    //Initiate Cycle SLider
    $('.home-slider-list').cycle();
  }
}
