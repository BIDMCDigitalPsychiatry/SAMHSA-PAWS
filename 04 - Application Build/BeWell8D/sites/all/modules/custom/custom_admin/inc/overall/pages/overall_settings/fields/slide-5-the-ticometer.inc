<?php

$tab = 'slide-5';

//Slide top image background.
$form[$tab]['hp_slide_5_feat_img'] = array(
  '#type' => 'managed_file',
  '#title' => t('Slide Top Image'),
  '#required' => TRUE,
  '#description' => t('Allowed extensions: gif png jpg jpeg'),
  '#default_value' => variable_get('hp_slide_5_feat_img', ''),
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
$hp_slide_5_title = variable_get('hp_slide_5_title');
//dsm($hp_slide_5_title);
$form[$tab]['hp_slide_5_title'] = array(
  '#type' => 'textfield',
  '#title' => t('Slide Title'),
  '#default_value' => (isset($hp_slide_5_title)) ? $hp_slide_5_title : NULL,
  '#size' => 60,
  '#maxlength' => 60,
  '#required' => FALSE,
);

//Slide Body Area
$hp_slide_5_body_area = variable_get('hp_slide_5_body_area');
//dsm($hp_slide_5_body_area);
$form[$tab]['hp_slide_5_body_area'] = array(
  '#type' => 'text_format',
  '#title' => t('Slide Body'),
  '#default_value' => (isset($hp_slide_5_body_area['value'])) ? $hp_slide_5_body_area['value'] : "Slide Body Area",
  '#required' => TRUE,
  '#base_type' => 'textarea',
  '#format' => (isset($hp_slide_5_body_area['format'])) ? $hp_slide_5_body_area['format'] : NULL,
);

$form[$tab]['slide_sep_2'] = array(
  '#type' => 'markup',
  '#markup' => t('<hr style="margin: 50px 0px; " />'),
);

//Slide Sidbar Area
$hp_slide_5_sidebar_area = variable_get('hp_slide_5_sidebar_area');
//dsm($hp_slide_5_sidebar_area);
$form[$tab]['hp_slide_5_sidebar_area'] = array(
  '#type' => 'text_format',
  '#title' => t('Slide Sidebar'),
  '#default_value' => (isset($hp_slide_5_sidebar_area['value'])) ? $hp_slide_5_sidebar_area['value'] : "Slide Sidebar Area",
  '#required' => FALSE,
  '#base_type' => 'textarea',
  '#format' => (isset($hp_slide_5_sidebar_area['format'])) ? $hp_slide_5_sidebar_area['format'] : NULL,
);


/******************************
 * SECTIONS                   *
 ******************************/

$form[$tab]['slide_5_sections_brd'] = array(
  '#type' => 'markup',
  '#markup' => t('<hr style="margin: 50px 0px; " />'),
);

$form[$tab]['slide_5_sections_heading'] = array(
  '#type' => 'markup',
  '#markup' => t('<h2 style="font-size:15px; padding:10px; background-color:#cccccc;">Sections</h2>'),
);

/******************************
 * SECTIONS - 1               *
 ******************************/
$form[$tab]['section_01'] = array(
  '#type' => 'fieldset',
  '#title' => t('Section 1'),
  '#collapsible' => TRUE,
  '#collapsed' => TRUE,

);

$hp_slide_5_section_1_title = variable_get('hp_slide_5_section_1_title');
$form[$tab]['section_01']['hp_slide_5_section_1_title'] = array(
  '#type' => 'textfield',
  '#title' => t('Title'),
  '#default_value' => (isset($hp_slide_5_section_1_title)) ? $hp_slide_5_section_1_title : NULL,
  '#size' => 60,
  '#maxlength' => 60,
  '#required' => FALSE,
);

$hp_slide_5_section_1_subhead = variable_get('hp_slide_5_section_1_subhead');
$form[$tab]['section_01']['hp_slide_5_section_1_subhead'] = array(
  '#type' => 'textfield',
  '#title' => t('Subheading'),
  '#default_value' => (isset($hp_slide_5_section_1_subhead)) ? $hp_slide_5_section_1_subhead : '',
  '#size' => 60,
  '#maxlength' => 60,
  '#required' => FALSE,
);

$hp_slide_5_section_1_link = variable_get('hp_slide_5_section_1_link');
$form[$tab]['section_01']['hp_slide_5_section_1_link'] = array(
  '#type' => 'textfield',
  '#title' => t('Learn More Link URL'),
  '#description' => t('Be sure to use the full url for an external link. For an internal link use the relative path eg.(understanding-trauma/facts).'),
  '#default_value' => (isset($hp_slide_5_section_1_link)) ? $hp_slide_5_section_1_link : '',
  '#size' => 60,
  '#maxlength' => 60,
  '#required' => FALSE,
);

$hp_slide_5_section_1_body = variable_get('hp_slide_5_section_1_body');
//dsm($hp_slide_5_sidebar_area);
$form[$tab]['section_01']['hp_slide_5_section_1_body'] = array(
  '#type' => 'text_format',
  '#title' => t('Body'),
  '#default_value' => (isset($hp_slide_5_section_1_body['value'])) ? $hp_slide_5_section_1_body['value'] : '',
  '#required' => FALSE,
  '#base_type' => 'textarea',
  '#format' => (isset($hp_slide_5_section_1_body['format'])) ? $hp_slide_5_section_1_body['format'] : NULL,
);
/* -------------------------------------------------------------------------- */

/******************************
 * SECTIONS - 2               *
 ******************************/
$form[$tab]['section_02'] = array(
  '#type' => 'fieldset',
  '#title' => t('Section 2'),
  '#collapsible' => TRUE,
  '#collapsed' => TRUE,
);

$hp_slide_5_section_2_title = variable_get('hp_slide_5_section_2_title');
$form[$tab]['section_02']['hp_slide_5_section_2_title'] = array(
  '#type' => 'textfield',
  '#title' => t('Title'),
  '#default_value' => (isset($hp_slide_5_section_2_title)) ? $hp_slide_5_section_2_title : '',
  '#size' => 60,
  '#maxlength' => 60,
  '#required' => FALSE,
);

$hp_slide_5_section_2_subhead = variable_get('hp_slide_5_section_2_subhead');
$form[$tab]['section_02']['hp_slide_5_section_2_subhead'] = array(
  '#type' => 'textfield',
  '#title' => t('Subheading'),
  '#default_value' => (isset($hp_slide_5_section_2_subhead)) ? $hp_slide_5_section_2_subhead : '',
  '#size' => 60,
  '#maxlength' => 60,
  '#required' => FALSE,
);

$hp_slide_5_section_2_link = variable_get('hp_slide_5_section_2_link');
$form[$tab]['section_02']['hp_slide_5_section_2_link'] = array(
  '#type' => 'textfield',
  '#title' => t('Learn More Link URL'),
  '#description' => t('Be sure to use the full url for an external link. For an internal link use the relative path eg.(understanding-trauma/facts).'),
  '#default_value' => (isset($hp_slide_5_section_2_link)) ? $hp_slide_5_section_2_link : '',
  '#size' => 60,
  '#maxlength' => 60,
  '#required' => FALSE,
);

$hp_slide_5_section_2_body = variable_get('hp_slide_5_section_2_body');
//dsm($hp_slide_5_sidebar_area);
$form[$tab]['section_02']['hp_slide_5_section_2_body'] = array(
  '#type' => 'text_format',
  '#title' => t('Body'),
  '#default_value' => (isset($hp_slide_5_section_2_body['value'])) ? $hp_slide_5_section_2_body['value'] : '',
  '#required' => FALSE,
  '#base_type' => 'textarea',
  '#format' => (isset($hp_slide_5_section_2_body['format'])) ? $hp_slide_5_section_2_body['format'] : NULL,
);


/* -------------------------------------------------------------------------- */

/******************************
 * SECTIONS - 3               *
 ******************************/
$form[$tab]['section_03'] = array(
  '#type' => 'fieldset',
  '#title' => t('Section 3'),
  '#collapsible' => TRUE,
  '#collapsed' => TRUE,
);

$hp_slide_5_section_3_title = variable_get('hp_slide_5_section_3_title');
$form[$tab]['section_03']['hp_slide_5_section_3_title'] = array(
  '#type' => 'textfield',
  '#title' => t('Title'),
  '#default_value' => (isset($hp_slide_5_section_3_title)) ? $hp_slide_5_section_3_title : '',
  '#size' => 60,
  '#maxlength' => 60,
  '#required' => FALSE,
);

$hp_slide_5_section_3_subhead = variable_get('hp_slide_5_section_3_subhead');
$form[$tab]['section_03']['hp_slide_5_section_3_subhead'] = array(
  '#type' => 'textfield',
  '#title' => t('Subheading'),
  '#default_value' => (isset($hp_slide_5_section_3_subhead)) ? $hp_slide_5_section_3_subhead : '',
  '#size' => 60,
  '#maxlength' => 60,
  '#required' => FALSE,
);

$hp_slide_5_section_3_link = variable_get('hp_slide_5_section_3_link');
$form[$tab]['section_03']['hp_slide_5_section_3_link'] = array(
  '#type' => 'textfield',
  '#title' => t('Learn More Link URL'),
  '#description' => t('Be sure to use the full url for an external link. For an internal link use the relative path eg.(understanding-trauma/facts).'),
  '#default_value' => (isset($hp_slide_5_section_3_link)) ? $hp_slide_5_section_3_link : '',
  '#size' => 60,
  '#maxlength' => 60,
  '#required' => FALSE,
);

$hp_slide_5_section_3_body = variable_get('hp_slide_5_section_3_body');
//dsm($hp_slide_5_sidebar_area);
$form[$tab]['section_03']['hp_slide_5_section_3_body'] = array(
  '#type' => 'text_format',
  '#title' => t('Body'),
  '#default_value' => (isset($hp_slide_5_section_3_body['value'])) ? $hp_slide_5_section_3_body['value'] : '',
  '#required' => FALSE,
  '#base_type' => 'textarea',
  '#format' => (isset($hp_slide_5_section_3_body['format'])) ? $hp_slide_5_section_3_body['format'] : NULL,
);

/* -------------------------------------------------------------------------- */

$form[$tab]['slide_sep_3'] = array(
  '#type' => 'markup',
  '#markup' => t('<hr style="margin: 50px 0px; " />'),
);

$form[$tab]['config_bottom_link_markup'] = array(
  '#type' => 'markup',
  '#markup' => t('<h2 style="font-size:15px; padding:10px; background-color:#cccccc;">Configurable Bottom Link</h2>'),
);

$hp_slide_5_btm_link_enable_disable = variable_get('hp_slide_5_btm_link_enable_disable');
//dsm($hp_slide_5_btm_link_enable_disable);
$form[$tab]['hp_slide_5_btm_link_enable_disable'] = array(
  '#type' => 'checkbox',
  '#title' => t('"DISABLE" the configurable link section at the bottom of the slide.'),
  '#default_value' => (isset($hp_slide_5_btm_link_enable_disable)) ? $hp_slide_5_btm_link_enable_disable : 0,
  '#required' => FALSE,
);

$hp_slide_5_btm_link_title = variable_get('hp_slide_5_btm_link_title');
//dsm($hp_slide_5_btm_link_title);
$form[$tab]['hp_slide_5_btm_link_title'] = array(
  '#type' => 'textfield',
  '#title' => t('Configurable link section title'),
  '#default_value' => (isset($hp_slide_5_btm_link_title)) ? $hp_slide_5_btm_link_title : NULL,
  '#size' => 60,
  '#maxlength' => 60,
  '#required' => FALSE,
);

$hp_slide_5_btm_link_description = variable_get('hp_slide_5_btm_link_description');
//dsm($home_top_area_text);
$form[$tab]['hp_slide_5_btm_link_description'] = array(
  '#title' => t('Configurable link section description'),
  '#type' => 'textarea',
  '#required' => FALSE,
  '#default_value' => (isset($hp_slide_5_btm_link_description)) ? $hp_slide_5_btm_link_description : NULL,
);

$hp_slide_5_btm_link_link_text = variable_get('hp_slide_5_btm_link_link_text');
//dsm($hp_slide_5_btm_link_link_text);
$form[$tab]['hp_slide_5_btm_link_link_text'] = array(
  '#type' => 'textfield',
  '#title' => t('Configurable link section link text.'),
  '#default_value' => (isset($hp_slide_5_btm_link_link_text)) ? $hp_slide_5_btm_link_link_text : NULL,
  '#description' => t('THis will be the text representation of the link used in the block.'),
  '#size' => 60,
  '#maxlength' => 60,
  '#required' => FALSE,
);

$hp_slide_5_btm_link_link = variable_get('hp_slide_5_btm_link_link');
//dsm($hp_slide_5_btm_link_link);
$form[$tab]['hp_slide_5_btm_link_link'] = array(
  '#type' => 'textfield',
  '#title' => t('Configurable link section link.'),
  '#default_value' => (isset($hp_slide_5_btm_link_link)) ? $hp_slide_5_btm_link_link : NULL,
  '#description' => t('Be sure to use the full url for an external link. For an internal link use the relative path eg.(node/1).'),
  '#size' => 60,
  '#maxlength' => 300,
  '#required' => FALSE,
);

?>
