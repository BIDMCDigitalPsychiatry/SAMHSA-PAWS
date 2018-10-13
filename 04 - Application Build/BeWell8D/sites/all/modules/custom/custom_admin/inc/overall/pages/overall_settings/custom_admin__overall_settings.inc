<?php

function custom_admin__overall_settings($form, $form_state) {
  global $user;
  $form = array();
  $form['#attached']['css'] = array(
    drupal_get_path('module', 'field_group') . '/horizontal-tabs/horizontal-tabs.css',
  );
  $form['#attached']['js'] = array(
    drupal_get_path('module', 'field_group') . '/horizontal-tabs/horizontal-tabs.js',
  );
  $form['settings_markup'] = array(
    '#type' => 'markup',
    '#markup' => t('<h1 style="font-size:18px; padding-bottom:18px;">Overall Site Settings</h1>'),
  );
  $form['settings_markup_no_settings'] = array(
    '#type' => 'markup',
    '#markup' => t('<p>Currently, there are no settings to change.</p>'),
  );

  /*$form['settings_tabs'] = array(
    '#type' => 'vertical_tabs',
    '#default_tab' => 'slide-1',
  );

  // // ------------------------------- TAB SETTINGS ------------------------------

  $form['slide-1'] = array(
    '#type' => 'fieldset',
    '#title' => t('Slide 1: Welcome'),
    '#collapsible' => TRUE,
    '#group' => 'settings_tabs',
  );
  $form['slide-2'] = array(
    '#type' => 'fieldset',
    '#title' => t('Slide 2: Trauma Care'),
    '#collapsible' => TRUE,
    '#group' => 'settings_tabs',
  );
  $form['slide-3'] = array(
    '#type' => 'fieldset',
    '#title' => t('Slide 3: Training Materials'),
    '#collapsible' => TRUE,
    '#group' => 'settings_tabs',
  );
  $form['slide-4'] = array(
    '#type' => 'fieldset',
    '#title' => t('Slide 4: Who We Are'),
    '#collapsible' => TRUE,
    '#group' => 'settings_tabs',
  );
  $form['slide-5'] = array(
    '#type' => 'fieldset',
    '#title' => t('Slide 5: The Ticometer'),
    '#collapsible' => TRUE,
    '#group' => 'settings_tabs',
  );

  //Common field variables
  $slide_image_max_demensions = '2500x2500';
  $slide_image_min_demensions = '1200x212';


  // // ------------------------------- TAB FIELDS -------------------------------
  include drupal_get_path('module','custom_admin').'/inc/overall/pages/overall_settings/fields/slide-1-welcome.inc';
  include drupal_get_path('module','custom_admin').'/inc/overall/pages/overall_settings/fields/slide-2-trauma-care.inc';
  include drupal_get_path('module','custom_admin').'/inc/overall/pages/overall_settings/fields/slide-3-training-materials.inc';
  include drupal_get_path('module','custom_admin').'/inc/overall/pages/overall_settings/fields/slide-4-who-we-are.inc';
  include drupal_get_path('module','custom_admin').'/inc/overall/pages/overall_settings/fields/slide-5-the-ticometer.inc';

  $form = system_settings_form($form);
  $form['#submit'][] = 'custom_admin__overall_settings_submit';*/

  return $form;
}

/**
 * We need a custom subit function to handle the submitting of images in a config form
 * to make sure the images save permanently as files in the system.
 */

function custom_admin__overall_settings_submit($form, $form_state) {

  //Make sure that the managed fields are saved permanantly for top slide images.
  $featured_top_images_total = array(1,2,3,4,5);
  foreach ($featured_top_images_total as $key => $fieldnum) {
    if (isset($form_state['values']['hp_slide_'.$fieldnum.'_feat_img']) && !empty($form_state['values']['hp_slide_'.$fieldnum.'_feat_img'])) {
      $file = file_load($form_state['values']['hp_slide_'.$fieldnum.'_feat_img']);
      // Change status to permanent.
      $file->status = FILE_STATUS_PERMANENT;
      // Save.
      file_save($file);
      //Record that the module is using the file.
      file_usage_add($file, 'custom_admin', 'node', 1);
    } else {
      variable_del('hp_slide_'.$fieldnum.'_feat_img');
    }
  }
}