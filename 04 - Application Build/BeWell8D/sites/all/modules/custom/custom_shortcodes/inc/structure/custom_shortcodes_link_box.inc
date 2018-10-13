  <?php
/**
 * Formats A Submitted ISO Date based on user settings.
 *
 * Calling
 * [iso_formater format="X"]ISODATEOUTPUTHERE[/iso_formater]
 */
function custom_shortcodes_link_box($attrs, $text) {
  $output = '';
  
  //Merge With defaults
  $init_attrs = shortcode_attrs(array(
      'title' => 'Enter Title',
      'link' => '<front>',
      'button_title' => 'Enter Title',
    ),
    $attrs
  );
  
  $vals = array();
  foreach ($init_attrs as $key => $value) {
    $vals[$key] = check_plain($value); 
  }
  
  $link = l(
    $vals['button_title'], 
    $vals['link'], 
    array(
      'attributes' => array(
        'title' => $vals['button_title'].' : '.$vals['title'],
      ),
    )
  );
  $output .= '<div class="shortcode-link-box">';
  $output .= '  <div class="shortcode-link-box-left">';
  $output .= '    <div class="shortcode-link-box-title">';
  $output .= '      <span>'.$vals['title'].'</span>';
  $output .= '    </div>';
  $output .= '  </div>';
  $output .= '  <div class="shortcode-link-box-right">';
  $output .= '    <div class="shortcode-link-box-link">';
  $output .= $link;
  $output .= '    </div>';
  $output .= '  </div>';
  $output .= '</div>';

  return $output;
}

/**
 * Adds shortcode attributes fields to edit shortcodes
 */
function custom_shortcodes_link_box_att($form, &$form_state) {
  
  $preview_image = base_path().drupal_get_path('module', 'custom_shortcodes').'/images/link-box.jpg';
  
  $form['preview_instructions'] = array(
    '#type' => 'markup',
    '#markup' => '<p>This shortcode allows you to insert a link box in your wysiwyg content styled specifically for the site.</p>
    <p>OUTPUTS:</p>
    <img src="'.$preview_image.'" style="width: 100%; height: auto;">
    <br/><br/>',
  );
  
  $form['link_box-title'] = array(
    '#title' => t('Title'),
    '#type' => 'textfield',
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'link_box'),
      ),
    ),
    '#description' => 'This is the text that will be displayed to the left of the link box button.',
    '#suffix' => '<br/>',
  );
  $form['link_box-link'] = array(
    '#title' => t('Link'),
    '#type' => 'textfield',
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'link_box'),
      ),
    ),
    '#description' => 'This is the url that the link box button will go to when clicked.',
    '#suffix' => '<br/>',
  );
  $form['link_box-button-title'] = array(
    '#title' => t('Link Box Button Title'),
    '#type' => 'textfield',
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'link_box'),
      ),
    ),
    '#description' => 'This is the title that will be used for the buttton of the link box.',
    '#suffix' => '<br/>',
  );

  return $form;
}

/**
 * Adds shortcode tips to the wysiwyg area for users to see how to use this shortcode.
 */
function custom_shortcodes_link_box_tip($format, $long) {
  $output = array();
  $output[] = '<p><strong>[link_box title="X" link="X" button_title="X"][/link_box]</strong><br/>';
  $output[] = t('Allows you to insert a link box styled specifically for the site.') . '</p>';

  return implode(' ', $output);
}
