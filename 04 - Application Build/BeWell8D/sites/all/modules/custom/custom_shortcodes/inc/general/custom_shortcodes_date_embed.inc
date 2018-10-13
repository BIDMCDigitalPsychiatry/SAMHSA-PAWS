  <?php
/**
 * Embeds a node via shortcode.
 */
function custom_shortcodes_date_embed($attrs, $text) {
  $attrs = shortcode_attrs(array(
    'time' => 'now',
    'format' => 'Y-m-d',
      ), $attrs
  );
  $time = check_plain($attrs['time']);
  $format = check_plain($attrs['format']);
  $date_string = date($format, strtotime($time));
  return '<span class="date-embed">'.$date_string.'</span>';
}

/**
 * Adds shortcode attributes fields to edit shortcodes
 */
function custom_shortcodes_date_embed_att($form, &$form_state) {
  $form['date_embed-time'] = array(
    '#title' => t('Time'),
    '#type' => 'textfield',
    '#description' => 'Time like exapmles from <a href="http://php.net/manual/en/function.strtotime.php">PHP Docs</a> eg:"now +1 day" or "January 1, 2016"',
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'date_embed'),
      ),
    ),
  );
  $form['date_embed-format'] = array(
    '#title' => t('Format'),
    '#type' => 'textfield',
    '#description' => 'Custom PHP Format from <a href="http://php.net/manual/en/function.date.php">PHP Docs</a> like "Y-m-d".',
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'date_embed'),
      ),
    ),
  );

  return $form;
}

/**
 * Adds shortcode tips to the wysiwyg area for users to see how to use this shortcode.
 */
function custom_shortcodes_date_embed_tip($format, $long) {
  $output = array();
  $output[] = '<p><strong>' . t('[date time="now" format="Y-m-d" /]') . '</strong> ';
  if ($long) {
    $output[] = t('Embeds date with given time and format.') . '</p>';
  }
  else {
    $output[] = t('Embeds date with given time and format. For example: [date format="Y-m-d" /] or [date time="now" format="Y-m-d" /]. Default is time="now" format="Y-m-d". <strong>time</strong> can be any string which supports by <a href="http://php.net/manual/en/function.strtotime.php" target="_blank" >strtotime()</a> and <strong>format</strong> can be any string which supports by <a href="http://php.net/manual/en/function.date.php" target="_blank" >date()</a>.') . '</p>';
  }
  return implode(' ', $output);
}
