<?php

function custom_shortcode_ckeditor_ui_settings_form() {
  $form['general'] = array(
    '#type' => 'fieldset',
    '#title' => t('General settings'),
  );

  return system_settings_form($form);
}
