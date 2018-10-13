  <?php
/**
 * Formats A Mobile App Accordion based on user settings.
 *
 * Calling
 * [mobile_app_accordion title="X"]ACCORDIONBODYHERE[/mobile_app_accordion]
 */
function custom_shortcodes_mobile_app_accordion($attrs, $text) {
  $output = '';
  
  //Merge With defaults
  $init_attrs = shortcode_attrs(array(
      'title' => 'Enter Accordion Title',
    ),
    $attrs
  );
  
  $vals = array();
  foreach ($init_attrs as $key => $value) {
    $vals[$key] = check_plain($value); 
  }
  
  $output .= '<div class="accordion-item"><button class="accordion-toggle">'.$vals['title'].'</button><div class="accordion-contents">';
  $output .= $text;
  $output .= '</div></div>';
  
  return $output;
}

/**
 * Adds shortcode attributes fields to edit shortcodes
 */
function custom_shortcodes_mobile_app_accordion_att($form, &$form_state) {
  
  $preview_image = base_path().drupal_get_path('module', 'custom_shortcodes').'/images/accordions-example.png';
  
  $form['preview_instructions'] = array(
    '#type' => 'markup',
    '#markup' => '<p>This shortcode allows you to insert an accordion item styled specifically for the mobile app.</p>
    <p>OUTPUTS:</p>
    <img src="'.$preview_image.'" style="width: 100%; height: auto;">
    <br/><br/>',
  );
  
  $form['mobile_app_accordion-title'] = array(
    '#title' => t('Accordion Title'),
    '#type' => 'textfield',
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'mobile_app_accordion'),
      ),
    ),
    '#description' => 'This is the text that will be set as the title of the accordion item.',
    '#suffix' => '<br/>',
  );

  return $form;
}

/**
 * Adds shortcode tips to the wysiwyg area for users to see how to use this shortcode.
 */
function custom_shortcodes_mobile_app_accordion_tip($format, $long) {
  $output = array();
  $output[] = '<p><strong>[mobile_app_accordion title="X"]ACCORDIONBODYHERE[/mobile_app_accordion]</strong><br/>';
  $output[] = t('Allows you to insert an accordion item styled specifically for the mobile app.') . '</p>';

  return implode(' ', $output);
}
