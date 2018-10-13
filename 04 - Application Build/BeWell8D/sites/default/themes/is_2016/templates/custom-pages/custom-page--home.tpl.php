<?php 
$mobile_app__app_title = variable_get('mobile_app__app_title', 'No Title Set'); 
$web_view__home_page_body_area = variable_get('web_view__home_page_body_area');
$web_view__home_page_body_area_markup = check_markup($web_view__home_page_body_area['value'], $web_view__home_page_body_area['format'], '', FALSE);
?>
<div class="section p-top-large p-btm-large">
  <div class="row-12">
    <div class="col-7 p-btm">
      <h2 class="h2 p-btm">Welcome to <?php print $mobile_app__app_title; ?></h2>
      <div class="wysiwyg">
        <?php print $web_view__home_page_body_area_markup; ?>
      </div>
      <ul class="p-top app-buttons">
        <li><a href="#" title="Dowload on the App Store">
          <img src="<?php print path_to_theme().'/images/global/app-download-button-ios.png'; ?>" alt="iOS App Download Button" />
        </a></li>
        <li><a href="#" title="Get it on Google play.">
          <img src="<?php print path_to_theme().'/images/global/app-download-button-android.png'; ?>" alt="Android Download Button" />
        </a></li>
      </ul>
    </div>
    <div class="col-5">
      <div class="side-image two-phones">
        <img src="<?php print path_to_theme().'/images/home/phones-large.png'; ?>" alt="Picture of two phones displaying the app." />
      </div>
    </div>
  </div>
</div>