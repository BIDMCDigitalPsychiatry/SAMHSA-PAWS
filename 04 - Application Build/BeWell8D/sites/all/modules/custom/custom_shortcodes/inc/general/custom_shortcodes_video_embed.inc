  <?php
/**
 * Embeds a node via shortcode.
 */
function custom_shortcodes_video_embed($attrs, $text) {
  $init_attrs = shortcode_attrs(array(
      'type' => '_none',
      'videourl' => '',
      'class' => '',
      'width' => '',
      'height' => '',
      'sub' => '',
      'forcesub' => FALSE,
    ),
    $attrs
  );
  $vals = array();
  foreach ($init_attrs as $name => $value) {
    $vals[$name] = check_plain($value);
  }
  
  
  $video_url = decode_entities($vals['videourl']);
  $url = drupal_parse_url($video_url);
  // Get provider.
  $m = array();
  preg_match('!^.*\:\/\/(www\.)?([^\.]*?)\.([^\.]*?)[\/|\?](.*?)$!', $video_url, $m);
  $provider = strtolower($m[2]);
  $output = '';
  switch ($vals['type']) {
    case 'youtube':
      switch ($provider) {
        case 'youtu':
          $url['query']['v'] = $m[4];
        case 'youtube':
          $embed_url = 'https://www.youtube.com/embed/';
          if (!empty($url['query']['v'])) {
            $params = $url['query'];
            $params['video_id'] = $url['query']['v'];
            unset($params['v']);
            unset($url['query']['v']);
            $params['attributes'] = $vals;
          }
          else {
            $params = _custom_shortcodes_video_embed_get_youtube_videoid($m);
            $params['attributes'] = $vals;
          }
          if (!empty($params['video_id'])) {
            if ($vals['sub']) {
              $url['query']['hl'] = $vals['sub'];
            }
            $vals['forcesub'] = shortcode_bool($vals['forcesub']);
            if ($vals['forcesub']) {
              $url['query']['fs'] = 1;
            }
            $params['video_url'] = url($embed_url . $params['video_id'], $url);
            $output = _custom_shortcodes_video_embed_youtube_theme($params);
          }
          break;
          
        default:
          $params = array('video_url' => $video_url);
          $output = _custom_shortcodes_video_embed_no_provider($params);
          break;
      }
      break;
    
    case 'vimeo':
      switch ($provider) {
        case 'vimeo':
          $params = _custom_shortcodes_video_embed_get_vimeo_videoid($m);
          if (!empty($params['video_id'])) {
            $params['attributes'] = $vals;
            $output = _custom_shortcodes_video_embed_vimeo_theme($params);
          }
          break;
    
        default:
          $params = array('video_url' => $video_url);
          $output = _custom_shortcodes_video_embed_no_provider($params);
          break;
      }
      break;

    default:
      $params = array('video_url' => $video_url);
      $output = _custom_shortcodes_video_embed_no_provider($params);
      break;
  }
  return $output;
}

/**
 * Adds shortcode attributes fields to edit shortcodes
 */
function custom_shortcodes_video_embed_att($form, &$form_state) {
  $form['video_embed-type'] = array(
    '#title' => t('Video Provider'),
    '#type' => 'select',
    '#options' => array(
      '_none' => '-- Select Video Type --',
      'youtube' => 'Youtube',
      'vimeo' => 'Vimeo'
    ),
    '#description' => 'Select the video type.',
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'video_embed'),
      ),
    ),
  );
  $form['video_embed-videourl'] = array(
    '#title' => t('Video Url'),
    '#type' => 'textfield',
    '#description' => 'URL for the Video',
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'video_embed'),
      ),
    ),
  );
  $form['video_embed-width'] = array(
    '#title' => t('Width'),
    '#type' => 'textfield',
    '#description' => 'Width of the Video',
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'video_embed'),
      ),
    ),
  );
  $form['video_embed-height'] = array(
    '#title' => t('Height'),
    '#type' => 'textfield',
    '#description' => 'Height of the Video',
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'video_embed'),
      ),
    ),
  );
  $form['video_embed-forcesub'] = array(
    '#title' => t('Force Subs'),
    '#type' => 'select',
    '#options' => array(
      '0' => 'FALSE',
      '1' => 'TRUE'
    ),
    '#description' => 'Force video subs.',
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'video_embed'),
      ),
    ),
  );
  $form['video_embed-class'] = array(
    '#title' => t('class'),
    '#type' => 'textfield',
    '#description' => 'Custom css class for the Video',
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'video_embed'),
      ),
    ),
  );
  return $form;
}

/**
 * Adds shortcode tips to the wysiwyg area for users to see how to use this shortcode.
 */
function custom_shortcodes_video_embed_tip($format, $long) {
  $output = array();
  $output[] = '<p><strong>' . t('[video]video url[/video]') . '</strong> ';
  if ($long) {
    $output[] = t('Embeds the video into the text.') . '</p>';
  }
  else {
    $output[] = t('Embeds video into the content text. With the <em>width</em> and <em>height</em> parameter you can specify the video size.') . '</p>';
    $output[] = '<p>' . t('For YouTube videos you can specify the width with 420, 480, 640, 960 as the default videos sizes, then the height of the video will be added according to the default embed sizes. The default video size is 480x360px.') . '</p>';
  }
  return implode(' ', $output);
}

/**
 * Provides helper for get Youtube videoid.
 */
function _custom_shortcodes_video_embed_get_youtube_videoid($m) {
  $params = array();
  // $m[4] contains the video url from the end of the provider url to the end of
  // the given text. Maybe it contains HTML (</iframe> tag).
  $nm = array();
  preg_match('!^([^\/]*).?([^\/\?\&]*)!', $m[4], $nm);
  switch($nm[1]) {
    case 'v':
      $params['video_id'] = $nm[2];
      break;

    case 'watch':
      $mm = array();
      preg_match('!\?v=([^\&]*?)$!', $m[4], $mm);
      if (!empty($mm[1])) {
        $params['video_id'] = $mm[1];
      }
      break;

    case 'embed':
      $mm = array();
      preg_match('!^embed\/(.*?)\?!', $m[4], $mm);
      if (!empty($mm[1])) {
        $params['video_id'] = $mm[1];
      }
      break;

    default:
      $params['video_id'] = '';
      break;
  }

  return $params;
}

/**
 * Provides YouTube video embed theme function.
 */
function _custom_shortcodes_video_embed_youtube_theme($variables) {
  $vals = $variables['attributes'];

  $height = empty($vals['height']) ? 0 : intval($vals['height']);
  $width = empty($vals['width']) ? 0 : intval($vals['width']);

  // Set defaults.
  if (empty($width) && empty($height)) {
    $width = 480;
    $height = 360;
  }
  elseif ($width && empty($height)) {
    $height = intval($width * 0.75);
  }
  elseif ($height && empty($width)) {
    $width = intval($height * 1.33);
  }

  $width = $width ? ' width="' . $width . '"' : '';
  $height = $height ? ' height="' . $height . '"' : '';
  $out = '<div class="video-container">';
  $out .= '<iframe' . $width . $height . ' src="' . $variables['video_url'] . '" frameborder="0" allowfullscreen></iframe>';
  $out .= '</div>';

  return $out;
}


/**
 * Provides helper for get Vimeo videoid.
 */
function _custom_shortcodes_video_embed_get_vimeo_videoid($m) {
  $params = array();
  // $m[4] contains the video id.
  $params['video_id'] = '';

  if (is_numeric($m[4])) {
    $params['video_id'] = $m[4];
  }

  return $params;
}
 
/**
 * Provides Vimeo video embed theme function.
 */
function _custom_shortcodes_video_embed_vimeo_theme($variables) {
  $vals = $variables['attributes'];

  $height = empty($vals['height']) ? 0 : intval($vals['height']);
  $width = empty($vals['width']) ? 0 : intval($vals['width']);

  // Set defaults.
  if (empty($width) && empty($height)) {
    $width = 480;
    $height = 360;
  }
  elseif ($width && empty($height)) {
    $height = intval($width * 0.75);
  }
  elseif ($height && empty($width)) {
    $width = intval($height * 1.33);
  }

  $width = $width ? ' width="' . $width . '"' : '';
  $height = $height ? ' height="' . $height . '"' : '';

  $out = '<div class="video-container">';
  $out .= '<iframe src="https://player.vimeo.com/video/' . $variables['video_id'] . '" ' . $width . $height . ' frameborder="0" webkitallowfullscreen mozallowfullscreen allowfullscreen></iframe>';
  $out .= '</div>';

  return $out;
}

/**
 * Provides video no provider theme function.
 */
function _custom_shortcodes_video_embed_no_provider($variables) {
  return '<span class="' . $variables['class'] . '">' . check_plain($variables['video_url']) . '</span>';
}