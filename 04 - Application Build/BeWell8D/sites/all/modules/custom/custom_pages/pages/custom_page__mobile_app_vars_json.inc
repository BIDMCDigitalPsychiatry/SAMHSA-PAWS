<?php
function custom_page__mobile_app_vars_json() {
  $variables = array();
  
  //App Title
  $mobile_app__app_title = variable_get('mobile_app__app_title', 'No Title Set');
  $variables['appTitle'] = $mobile_app__app_title;
  
  //Home
  $home_slide_1_body = variable_get('mobile_app__home_slide_1_body_area');
  $home_slide_1_body_markup = check_markup($home_slide_1_body['value'], $home_slide_1_body['format'], '', FALSE);
  $home_slide_2_body = variable_get('mobile_app__home_slide_2_body_area');
  $home_slide_2_body_markup = check_markup($home_slide_2_body['value'], $home_slide_2_body['format'], '', FALSE);
  $home_slide_3_body = variable_get('mobile_app__home_slide_3_body_area');
  $home_slide_3_body_markup = check_markup($home_slide_3_body['value'], $home_slide_3_body['format'], '', FALSE);
  $variables['home']['slider'] = array(
    'slide1' => $home_slide_1_body_markup,
    'slide2' => $home_slide_2_body_markup,
    'slide3' => $home_slide_3_body_markup,  
  );
  
  //Tour
  $tour_overall_body = variable_get('mobile_app__tour_overall_body_area');
  $tour_overall_body_markup = check_markup($tour_overall_body['value'], $tour_overall_body['format'], '', FALSE);
  $tour_section_1_body = variable_get('mobile_app__tour_section_1_body_area');
  $tour_section_1_body_markup = check_markup($tour_section_1_body['value'], $tour_section_1_body['format'], '', FALSE);
  $tour_section_2_body = variable_get('mobile_app__tour_section_2_body_area');
  $tour_section_2_body_markup = check_markup($tour_section_2_body['value'], $tour_section_2_body['format'], '', FALSE);
  $tour_section_3_body = variable_get('mobile_app__tour_section_3_body_area');
  $tour_section_3_body_markup = check_markup($tour_section_3_body['value'], $tour_section_3_body['format'], '', FALSE);
  $tour_section_4_body = variable_get('mobile_app__tour_section_4_body_area');
  $tour_section_4_body_markup = check_markup($tour_section_4_body['value'], $tour_section_4_body['format'], '', FALSE);
  $tour_section_5_body = variable_get('mobile_app__tour_section_5_body_area');
  $tour_section_5_body_markup = check_markup($tour_section_5_body['value'], $tour_section_5_body['format'], '', FALSE);
  $variables['tour']['overallText'] = $tour_overall_body_markup;
  $variables['tour']['sections'] = array(
    'section1' => $tour_section_1_body_markup,
    'section2' => $tour_section_2_body_markup,
    'section3' => $tour_section_3_body_markup,  
    'section4' => $tour_section_4_body_markup,  
    'section5' => $tour_section_5_body_markup,  
  );
  
  
  //User Pages
  $user_login_page_text = variable_get('mobile_app__user_login_page_text');
  $user_login_page_text_markup = check_markup($user_login_page_text['value'], $user_login_page_text['format'], '', FALSE);
  $user_registration_page_text = variable_get('mobile_app__user_registration_page_text');
  $user_registration_page_text_markup = check_markup($user_registration_page_text['value'], $user_registration_page_text['format'], '', FALSE);
  $user_pass_page_text = variable_get('mobile_app__user_pass_page_text');
  $user_pass_page_text_markup = check_markup($user_pass_page_text['value'], $user_pass_page_text['format'], '', FALSE);
  $variables['user']['loginText'] = $user_login_page_text_markup;
  $variables['user']['regText'] = $user_registration_page_text_markup;
  $variables['user']['passText'] = $user_pass_page_text_markup;
  
  return $variables;

}
