  <?php
/**
 * Embeds a node via shortcode.
 */
function custom_shortcodes_gmap_embed($attrs, $text) {
  $init_attrs = shortcode_attrs(array(
    'include_map' => TRUE,
    'include_link' => FALSE,
    'include_text' => FALSE,
    'width' => '100%',
    'height' => '300',
    'address' => '',
    'zoom' => 19,
    'information_bubble' => TRUE,
    'link_text' => t('View larger map'),
    'address_text' => '',
    'map_type' => 'm',
    'langcode' => '',
    'url_suffix' => '',
    ), $attrs
  );
  $vals = array();
  foreach ($init_attrs as $name => $value) {
    $vals[$name] = check_plain($value);
  }
  
  if (!empty($text)) {
    $vals['address'] = $text;
  }

  if (empty($vals['address_text'])) {
    $vals['address_text'] = $vals['address'];
  }

  if (empty($vals['langcode'])) {
    $vals['langcode'] = $GLOBALS['language']->language;
  }

  if (!empty($vals['address'])) {
    $vals['url_suffix'] = urlencode($vals['address']);
  }

  switch ($vals['map_type']) {
    case 'k':
    case 'satellite':
      $vals['map_type'] = 'k';
      break;

    case 'h':
    case 'hybrid':
      $vals['map_type'] = 'h';
      break;

    case 'p':
    case 'terrain':
      $vals['map_type'] = 'p';
      break;

    default:
      $vals['map_type'] = 'm';
      break;

  }
  $vals['include_map'] = shortcode_bool($vals['include_map']);
  $vals['include_link'] = shortcode_bool($vals['include_link']);
  $vals['include_text'] = shortcode_bool($vals['include_text']);
  $vals['information_bubble'] = shortcode_bool($vals['information_bubble']);
  
  $map = '';

  if ($vals['include_map']) {
    $map .= '<iframe frameborder="0" scrolling="no" marginheight="0" marginwidth="0"'
      . ' width="' . $vals['width'] . '"'
      . ' height="' . $vals['height'] . '"'
      . ' src="https://maps.google.com/maps?hl='
        . $vals['langcode']
        . '&amp;q=' . $vals['url_suffix']
        . '&amp;iwloc=' . ($vals['information_bubble'] ? 'A' : 'near')
        . '&amp;z=' . $vals['zoom']
        . '&amp;t=' . $vals['map_type']
      . '&amp;output=embed"></iframe>';
  }

  if ($vals['include_link']) {
    $map .= '<p class="simple-gmap-link"><a href="https://maps.google.com/maps?q='
      . $vals['url_suffix']
      . '&amp;hl=' . $vals['langcode']
      . '&amp;iwloc=' . ($vals['information_bubble'] ? 'A' : 'near')
      . '&amp;z=' . $vals['zoom']
      . '&amp;t=' . $vals['map_type']
      . '" target="_blank">'
      . $vals['link_text']
      . '</a></p>';
  }

  if (!empty($vals['include_text']) && !empty($vals['address_text'])) {
    $map .= '<p class="simple-gmap-address">' . $vals['address_text'] . '</p>';
  }

  return $map;
}

/**
 * Adds shortcode attributes fields to edit shortcodes
 */
function custom_shortcodes_gmap_embed_att($form, &$form_state) {
  $form['gmap_embed-include_map'] = array(
    '#title' => t('Include Map'),
    '#type' => 'select',
    '#options' => array(1 => 'TRUE', 0 => 'FALSE'),
    '#description' => 'Do you want to include the map embed?',
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'gmap_embed'),
      ),
    ),
  );
  $form['gmap_embed-include_link'] = array(
    '#title' => t('Include Link'),
    '#type' => 'select',
    '#options' => array(0 => 'FALSE', 1 => 'TRUE'),
    '#description' => 'Do you want to include a link to the map?',
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'gmap_embed'),
      ),
    ),
  );
  $form['gmap_embed-include_text'] = array(
    '#title' => t('Include Text'),
    '#type' => 'select',
    '#options' => array(0 => 'FALSE', 1 => 'TRUE'),
    '#description' => 'Do you wan to include text below the map?',
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'gmap_embed'),
      ),
    ),
  );
  $form['gmap_embed-width'] = array(
    '#title' => t('Map Width'),
    '#type' => 'textfield',
    '#description' => 'Set the Map WIDTH: (100%, 80%, 300)',
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'gmap_embed'),
      ),
    ),
  );
  $form['gmap_embed-height'] = array(
    '#title' => t('Map Height'),
    '#type' => 'textfield',
    '#description' => 'Set the Map HEIGHT: (200, 150, 300)',
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'gmap_embed'),
      ),
    ),
  );
  $form['gmap_embed-address'] = array(
    '#title' => t('Map Center Address'),
    '#type' => 'textfield',
    '#description' => 'Please enter the address where the map with be centered on load.',
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'gmap_embed'),
      ),
    ),
  );
  $form['gmap_embed-zoom'] = array(
    '#title' => t('Map Zoom Level'),
    '#type' => 'select',
    '#options' => array(
      0 => '0 - World',
      1 => '1',
      2 => '2',
      3 => '3',
      4 => '4',
      5 => '5 - Landmass/continent',
      6 => '6',
      7 => '7',
      8 => '8',
      9 => '9',
      10 => '10 - City',
      11 => '11',
      12 => '12',
      13 => '13',
      14 => '14',
      15 => '15 - Streets',
      16 => '16',
      17 => '17',
      18 => '18',
      19 => '19',
      20 => '20 - Buildings',
      21 => '21',
    ),
    '#description' => 'Map Zoom Level: 0-21 (0 = zoomed far - 21 = zoomed close)',
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'gmap_embed'),
      ),
    ),
  );
  $form['gmap_embed-information_bubble'] = array(
    '#title' => t('Map Info Bubble Text'),
    '#type' => 'textfield',
    '#description' => 'Text that will be placed in the map info bubble.',
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'gmap_embed'),
      ),
    ),
  );
  $form['gmap_embed-link_text'] = array(
    '#title' => t('Map Link Text'),
    '#type' => 'textfield',
    '#description' => 'Textual representation of map link.',
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'gmap_embed'),
      ),
    ),
  );
  $form['gmap_embed-address_text'] = array(
    '#title' => t('Bottom Text'),
    '#type' => 'textarea',
    '#description' => 'Text that will be output under the map embed and map link.',
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'gmap_embed'),
      ),
    ),
  );
  $form['gmap_embed-map_type'] = array(
    '#title' => t('Map Type'),
    '#type' => 'select',
    '#options' => array('m' => 'Default', 'k' => 'Satellite', 'h' => 'Hybrid', 'p' => 'Terrain'),
    '#description' => 'For the map embed what style should it display?',
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'gmap_embed'),
      ),
    ),
  );
  
  return $form;
}

/**
 * Adds shortcode tips to the wysiwyg area for users to see how to use this shortcode.
 */
function custom_shortcodes_gmap_embed_tip($format, $long) {
  $output = array();
  return implode(' ', $output);
}
