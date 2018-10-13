<?php

$tab = 'slide-4';

//Slide top image background.
$form[$tab]['hp_slide_4_feat_img'] = array(
  '#type' => 'managed_file',
  '#title' => t('Slide Top Image'),
  '#required' => TRUE,
  '#description' => t('Allowed extensions: gif png jpg jpeg'),
  '#default_value' => variable_get('hp_slide_4_feat_img', ''),
  '#upload_location' => 'public://home-page/slide-image',
  '#upload_validators' => array(
    'file_validate_extensions' => array('gif png jpg jpeg'),
    // Pass the maximum and minimum file resolutiuon
    'file_validate_image_resolution' => array($slide_image_max_demensions, $slide_image_min_demensions),
  ),
);

$form[$tab]['slide_sep_1'] = array(
  '#type' => 'markup',
  '#markup' => t('<hr style="margin: 50px 0px; " />'),
);

// Slide Title
$hp_slide_4_title = variable_get('hp_slide_4_title');
//dsm($hp_slide_4_title);
$form[$tab]['hp_slide_4_title'] = array(
  '#type' => 'textfield',
  '#title' => t('Slide Title'),
  '#default_value' => (isset($hp_slide_4_title)) ? $hp_slide_4_title : NULL,
  '#size' => 60,
  '#maxlength' => 60,
  '#required' => FALSE,
);

//Slide Body Area
$hp_slide_4_body_area = variable_get('hp_slide_4_body_area');
//dsm($hp_slide_4_body_area);
$form[$tab]['hp_slide_4_body_area'] = array(
  '#type' => 'text_format',
  '#title' => t('Slide Body'),
  '#default_value' => (isset($hp_slide_4_body_area['value'])) ? $hp_slide_4_body_area['value'] : "Slide Body Area",
  '#required' => TRUE,
  '#base_type' => 'textarea',
  '#format' => (isset($hp_slide_4_body_area['format'])) ? $hp_slide_4_body_area['format'] : NULL,
);

$form[$tab]['slide_sep_2'] = array(
  '#type' => 'markup',
  '#markup' => t('<hr style="margin: 50px 0px; " />'),
);

//Slide Sidbar Area
$hp_slide_4_sidebar_area = variable_get('hp_slide_4_sidebar_area');
//dsm($hp_slide_4_sidebar_area);
$form[$tab]['hp_slide_4_sidebar_area'] = array(
  '#type' => 'text_format',
  '#title' => t('Slide Sidebar'),
  '#default_value' => (isset($hp_slide_4_sidebar_area['value'])) ? $hp_slide_4_sidebar_area['value'] : "Slide Sidebar Area",
  '#required' => FALSE,
  '#base_type' => 'textarea',
  '#format' => (isset($hp_slide_4_sidebar_area['format'])) ? $hp_slide_4_sidebar_area['format'] : NULL,
);

$form[$tab]['slide_sep_3'] = array(
  '#type' => 'markup',
  '#markup' => t('<hr style="margin: 50px 0px; " />'),
);

$form[$tab]['config_bottom_link_markup'] = array(
  '#type' => 'markup',
  '#markup' => t('<h2 style="font-size:15px; padding:10px; background-color:#cccccc;">Configurable Bottom Link</h2>'),
);

$hp_slide_4_btm_link_enable_disable = variable_get('hp_slide_4_btm_link_enable_disable');
//dsm($hp_slide_4_btm_link_enable_disable);
$form[$tab]['hp_slide_4_btm_link_enable_disable'] = array(
  '#type' => 'checkbox',
  '#title' => t('"DISABLE" the configurable link section at the bottom of the slide.'),
  '#default_value' => (isset($hp_slide_4_btm_link_enable_disable)) ? $hp_slide_4_btm_link_enable_disable : 0,
  '#required' => FALSE,
);

$hp_slide_4_btm_link_title = variable_get('hp_slide_4_btm_link_title');
//dsm($hp_slide_4_btm_link_title);
$form[$tab]['hp_slide_4_btm_link_title'] = array(
  '#type' => 'textfield',
  '#title' => t('Configurable link section title'),
  '#default_value' => (isset($hp_slide_4_btm_link_title)) ? $hp_slide_4_btm_link_title : NULL,
  '#size' => 60,
  '#maxlength' => 60,
  '#required' => FALSE,
);

$hp_slide_4_btm_link_description = variable_get('hp_slide_4_btm_link_description');
//dsm($home_top_area_text);
$form[$tab]['hp_slide_4_btm_link_description'] = array(
  '#title' => t('Configurable link section description'),
  '#type' => 'textarea',
  '#required' => FALSE,
  '#default_value' => (isset($hp_slide_4_btm_link_description)) ? $hp_slide_4_btm_link_description : NULL,
);

$hp_slide_4_btm_link_link_text = variable_get('hp_slide_4_btm_link_link_text');
//dsm($hp_slide_4_btm_link_link_text);
$form[$tab]['hp_slide_4_btm_link_link_text'] = array(
  '#type' => 'textfield',
  '#title' => t('Configurable link section link text.'),
  '#default_value' => (isset($hp_slide_4_btm_link_link_text)) ? $hp_slide_4_btm_link_link_text : NULL,
  '#description' => t('THis will be the text representation of the link used in the block.'),
  '#size' => 60,
  '#maxlength' => 60,
  '#required' => FALSE,
);

$hp_slide_4_btm_link_link = variable_get('hp_slide_4_btm_link_link');
//dsm($hp_slide_4_btm_link_link);
$form[$tab]['hp_slide_4_btm_link_link'] = array(
  '#type' => 'textfield',
  '#title' => t('Configurable link section link.'),
  '#default_value' => (isset($hp_slide_4_btm_link_link)) ? $hp_slide_4_btm_link_link : NULL,
  '#description' => t('Be sure to use the full url for an external link. For an internal link use the relative path eg.(node/1).'),
  '#size' => 60,
  '#maxlength' => 300,
  '#required' => FALSE,
);

?>
