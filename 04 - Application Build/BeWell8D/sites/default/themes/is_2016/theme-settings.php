<?php

/**
 * @file
 * Theme setting callbacks for the theme.
 *
 * Getting the settings’ values in your theme files
 * <?php $foo_example = theme_get_setting('foo_example'); ?>
 *
 * Setting Default Value in .info file
 * settings[foo_example] = blue bikeshed
 *
 * Form api Ref: "http://api.drupal.org/api/drupal/developer!topics!forms_api_reference.html/7"
 */

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * @param $form
 *   The form.
 * @param $form_state
 *   The form state.
 */
/*function THEMENAME_form_system_theme_settings_alter(&$form, $form_state) {
  $form['foo_example'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Widget'),
    '#default_value' => theme_get_setting('foo_example'),
    '#description'   => t("Place this text in the widget spot on your site."),
  );
}*/


