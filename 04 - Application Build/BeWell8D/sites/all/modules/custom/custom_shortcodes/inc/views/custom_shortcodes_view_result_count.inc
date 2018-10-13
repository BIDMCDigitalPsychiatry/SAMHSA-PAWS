  <?php
/**
 * Formats A Submitted ISO Date based on user settings.
 *
 * Calling
 * [view_result_count view="X" display="X" args="X|X|X" /]
 */
function custom_shortcodes_view_result_count($attrs, $text) {
  $init_attrs = shortcode_attrs(array(
      'view' => '',
      'display' => '',
      'args' => '',
    ),
    $attrs
  );
  $vals = array();
  foreach ($init_attrs as $key => $value) {
    $vals[$key] = check_plain($value); 
  }

  if (!empty($vals['view'])) {
    $args = array($vals['view'], $vals['display']);
    if (!empty($vals['args'])) {
      $explod_args = explode('|', $vals['args']);
      foreach ($explod_args as $key => $value) {
        if (!empty($value)) {
          $args[] = $value;
        }
      }
    }

    $view_results = call_user_func_array('views_get_view_result', $args);
    return count($view_results);
  } else {
    return '*';
  }
}

/**
 * Adds shortcode attributes fields to edit shortcodes
 */
function custom_shortcodes_view_result_count_att($form, &$form_state) {
  
  $form['preview_instructions'] = array(
    '#type' => 'markup',
    '#markup' => '<p>This shortcode allows you to output a single views result count number.</p>
    <p>OUTPUTS:</p>
    <p>A Number</p>
    <br/><br/>',
  );
  
  $form['view_result_count-view'] = array(
    '#title' => t('View'),
    '#type' => 'textfield',
    '#description' => 'The View Machine Name',
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'view_result_count'),
      ),
    ),
  );
  $form['view_result_count-display'] = array(
    '#title' => t('Display'),
    '#type' => 'textfield',
    '#description' => 'The View Display Machine Name',
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'view_result_count'),
      ),
    ),
  );
  $form['view_result_count-args'] = array(
    '#title' => t('Args'),
    '#type' => 'textfield',
    '#description' => 'View Args seperated by "|"',
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'view_result_count'),
      ),
    ),
  );

  return $form;
}

/**
 * Adds shortcode tips to the wysiwyg area for users to see how to use this shortcode.
 */
function custom_shortcodes_view_result_count_tip($format, $long) {
  $output = array();
  $output[] = '<p><strong>[view_result_count view="X" display="X" args="X|X|X" /]</strong><br/>';
  $output[] = t('Lets a user see the number of results for any view. With arguments.') . '</p>';

  return implode(' ', $output);
}
