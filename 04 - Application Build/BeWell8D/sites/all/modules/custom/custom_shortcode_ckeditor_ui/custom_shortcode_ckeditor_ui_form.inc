<?php
/**
 * Provides page callback for Shortcode Wysiwyg form.
 */
function custom_shortcode_ckeditor_ui_form($form, &$form_state, $format_id) {
  $options = $form = array();
  module_load_include('inc', 'shortcode', 'shortcode');
  drupal_set_title(t('Shortcode'));

  $format_id = str_replace("format", "", $format_id);
  $shortcodes = shortcode_list_all_enabled($format_id);
  
  $options['_none'] = '-- SELECT A SHORTCODE --';
  foreach ($shortcodes as $name => $shortcode) {
    $options[$name] = $shortcode['title'];
  }

  $form['shortcode'] = array(
    '#type' => 'select',
    '#title' => t('Choose the Shortcode you want to insert.'),
    '#options' => $options,
    '#description' => t('This Shortcode will be inserted in your textfield.'),
    '#attributes' => array(
      'class' => array('custom-shortcode-ckeditor-ui-selector'),  
    ),
  );
  
  if ($format_id !== '_none') {
    foreach ($shortcodes as $name => $shortcode) {
      $form[$name] = array( 
        '#type' => 'fieldset', 
        '#title' => t($name), 
        '#collapsed' => FALSE, 
        '#group' => 'additional_settings',
        '#attributes' => array(
          'style' => 'display: none; visibility: hidden;',  
        ),
      );
      if (isset($shortcode['attributes callback'])) {
        $form[$name][$name+"_fields"] = call_user_func_array($shortcode['attributes callback'], array(array(), $form_state));
      }
    }
  }

  return $form;
}
