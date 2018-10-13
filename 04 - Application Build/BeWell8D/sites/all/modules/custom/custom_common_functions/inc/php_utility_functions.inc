<?php

/**
 * function to check user roles
 * @roles_allowed is an array of roles that will pass as true
 * @roles is an array of roles of the currently checked user
 */
function _array_in_array($needle, $haystack) {
  $truthiness = 'FALSE';
  foreach ($needle as $value) {
    if(in_array($value, array_values($haystack))) {
      $truthiness = 'TRUE';
    }
  }
  return $truthiness;
}

/**
 * Get The Next Item In an Array Based on Key
 */
function _array_previous($arr, $key, $circular = 'FALSE') {
  $keys = array_keys($arr);
  $keyIndexes = array_flip($keys);

  $return = '';
  if (isset($keys[$keyIndexes[$key]-1])) {
      $return = $keys[$keyIndexes[$key]-1];
  } elseif ($circular == 'FALSE') {
      $return = NULL;
  } else {
      $return = $keys[sizeof($keys)-1];
  }

  return $return;
}

/**
 * Return Next and Previous array items in associative array
 */

function _array_next($arr, $key, $circular = 'FALSE') {
  $keys = array_keys($arr);
  $keyIndexes = array_flip($keys);

  $return = '';

  if (isset($keys[$keyIndexes[$key]+1])) {
      $return = $keys[$keyIndexes[$key]+1];
  } elseif ($circular == 'FALSE') {
      $return = NULL;
  } else {
      $return = $keys[0];
  }

  return $return;
}

/**
 * Searches an array for how many times a key shows up and returns a count
 */
function _count_key($array, $key) {
    $count = 0;
    foreach($array as $k => $val) {
        if($k == $key)
            $count++;
        if(is_array($val))
        $count += count_key($val, $key);
    }
    return $count;
}

/**
 * Searches an array for how many times a value shows up and returns a count
 */
function _count_value($array, $value) {
    $count = 0;
    foreach($array as $k => $val) {
        if($val == $value)
            $count++;
        if(is_array($val))
        $count += count_value($val, $value);
    }
    return $count;
}

/**
 * Array slice for associative arrays
 */
function _array_slice_assoc($array, $key, $length, $preserve_keys = true) {
  $offset = array_search($key, array_keys($array));

  if (is_string($length)) {
    $length = array_search($length, array_keys($array)) - $offset;
  }

  return array_slice($array, $offset, $length, $preserve_keys);
}

/* Print R Clean Array */
function _print_r_html($arr, $return = TRUE) {
  return '<pre>' . print_r($arr, $return) . '</pre>';
}

/**
 * Replaces double line-breaks with paragraph elements.
 */
function _basic_text_formatter($text, $br = true) {
  $pre_tags = array();

  if ( trim($text) === '' )
    return '';

  $text = $text . "\n"; // just to make things a little easier, pad the end

  if ( strpos($text, '<pre') !== false ) {
    $text_parts = explode( '</pre>', $text );
    $last_pee = array_pop($text_parts);
    $text = '';
    $i = 0;

    foreach ( $text_parts as $text_part ) {
      $start = strpos($text_part, '<pre');

      // Malformed html?
      if ( $start === false ) {
        $text .= $text_part;
        continue;
      }

      $name = "<pre wp-pre-tag-$i></pre>";
      $pre_tags[$name] = substr( $text_part, $start ) . '</pre>';

      $text .= substr( $text_part, 0, $start ) . $name;
      $i++;
    }

    $text .= $last_pee;
  }

  $text = preg_replace('|<br />\s*<br />|', "\n\n", $text);
  // Space things out a little
  $allblocks = '(?:table|thead|tfoot|caption|col|colgroup|tbody|tr|td|th|div|dl|dd|dt|ul|ol|li|pre|select|option|form|map|area|blockquote|address|math|style|p|h[1-6]|hr|fieldset|noscript|samp|legend|section|article|aside|hgroup|header|footer|nav|figure|figcaption|details|menu|summary)';
  $text = preg_replace('!(<' . $allblocks . '[^>]*>)!', "\n$1", $text);
  $text = preg_replace('!(</' . $allblocks . '>)!', "$1\n\n", $text);
  $text = str_replace(array("\r\n", "\r"), "\n", $text); // cross-platform newlines
  if ( strpos($text, '<object') !== false ) {
    $text = preg_replace('|\s*<param([^>]*)>\s*|', "<param$1>", $text); // no pee inside object/embed
    $text = preg_replace('|\s*</embed>\s*|', '</embed>', $text);
  }
  $text = preg_replace("/\n\n+/", "\n\n", $text); // take care of duplicates
  // make paragraphs, including one at the end
  $texts = preg_split('/\n\s*\n/', $text, -1, PREG_SPLIT_NO_EMPTY);
  $text = '';
  foreach ( $texts as $tinkle )
    $text .= '<p>' . trim($tinkle, "\n") . "</p>\n";
  $text = preg_replace('|<p>\s*</p>|', '', $text); // under certain strange conditions it could create a P of entirely whitespace
  $text = preg_replace('!<p>([^<]+)</(div|address|form)>!', "<p>$1</p></$2>", $text);
  $text = preg_replace('!<p>\s*(</?' . $allblocks . '[^>]*>)\s*</p>!', "$1", $text); // don't pee all over a tag
  $text = preg_replace("|<p>(<li.+?)</p>|", "$1", $text); // problem with nested lists
  $text = preg_replace('|<p><blockquote([^>]*)>|i', "<blockquote$1><p>", $text);
  $text = str_replace('</blockquote></p>', '</p></blockquote>', $text);
  $text = preg_replace('!<p>\s*(</?' . $allblocks . '[^>]*>)!', "$1", $text);
  $text = preg_replace('!(</?' . $allblocks . '[^>]*>)\s*</p>!', "$1", $text);
  if ( $br ) {
    $text = preg_replace('|(?<!<br />)\s*\n|', "<br />\n", $text); // optionally make line breaks
    $text = str_replace('<WPPreserveNewline />', "\n", $text);
  }
  $text = preg_replace('!(</?' . $allblocks . '[^>]*>)\s*<br />!', "$1", $text);
  $text = preg_replace('!<br />(\s*</?(?:p|li|div|dl|dd|dt|th|pre|td|ul|ol)[^>]*>)!', '$1', $text);
  $text = preg_replace( "|\n</p>$|", '</p>', $text );

  if ( !empty($pre_tags) )
    $text = str_replace(array_keys($pre_tags), array_values($pre_tags), $text);

  return $text;
}

/**
 * Function to make URLs into links in a string
 */
function _string_make_links($string){
  /*** make sure there is an http:// on all URLs ***/
  $string = preg_replace("/([^\w\/])(www\.[a-z0-9\-]+\.[a-z0-9\-]+)/i", "$1http://$2",$string);
  /*** make all URLs links ***/
  $string = preg_replace("/([\w]+:\/\/[\w-?&;#~=\.\/\@]+[\w\/])/i","<a target=\"_blank\" href=\"$1\">$1</A>",$string);
  /*** make all emails hot links ***/
  $string = preg_replace("/([\w-?&;#~=\.\/]+\@(\[?)[a-zA-Z0-9\-\.]+\.([a-zA-Z]{2,3}|[0-9]{1,3})(\]?))/i","<A HREF=\"mailto:$1\">$1</A>",$string);
  return $string;
}

/**
 * Get youtube video id from url
 */
function _get_youtube_id($url) {

    $pattern = '%^
    (?:https?://)?  # Optional scheme. Either http or https
    (?:www\.)?      # Optional www subdomain
    (?:             # Group host alternatives
      youtu\.be/    # Either youtu.be,
    | youtube\.com  # or youtube.com
      (?:           # Group path alternatives
        /embed/     # Either /embed/
      | /v/         # or /v/
      | .*v=        # or /watch\?v=
      )             # End path alternatives.
    )               # End host alternatives.
    ([\w-]{10,12})  # Allow 10-12 for 11 char youtube id.
    ($|&).*         # if additional parameters are also in query string after video id.
    $%x';
    $result = preg_match($pattern, $url, $matches);
    if (FALSE !== $result) {
      return $matches[1];
    }
    return FALSE;
}

/**
 * Get either a Gravatar URL or complete image tag for a specified email address.
 *
 * @param string $email The email address
 * @param string $s Size in pixels, defaults to 80px [ 1 - 2048 ]
 * @param string $d Default imageset to use [ 404 | mm | identicon | monsterid | wavatar ]
 * @param string $r Maximum rating (inclusive) [ g | pg | r | x ]
 * @param boole $img True to return a complete IMG tag False for just the URL
 * @param array $atts Optional, additional key/value attributes to include in the IMG tag
 * @return String containing either just a URL or a complete image tag
 * @source http://gravatar.com/site/implement/images/php/
 */
function _get_gravatar( $email, $s = 80, $d = 'mm', $r = 'g', $img = false, $atts = array() ) {
    $url = 'http://www.gravatar.com/avatar/';
    $url .= md5( strtolower( trim( $email ) ) );
    $url .= "?s=$s&d=$d&r=$r";
    if ( $img ) {
        $url = '<img src="' . $url . '"';
        foreach ( $atts as $key => $val )
            $url .= ' ' . $key . '="' . $val . '"';
        $url .= ' />';
    }
    return $url;
}

/**
 * This function extracts the non-tags string and returns a correctly formatted string
 * It can handle all html entities e.g. &amp;, &quot;, etc..
 *
 * @param string $s
 * @param integer $srt
 * @param integer $len
 * @param bool/integer  Strict if this is defined, then the last word will be complete. If this is set to 2 then the last sentence will be completed.
 * @param string A string to suffix the value, only if it has been chopped.
 */
function _html_substr( $s, $srt, $len = NULL, $strict=false, $suffix = NULL )
{
  if ( is_null($len) ){ $len = strlen( $s ); }

  $f = 'static $strlen=0;
      if ( $strlen >= ' . $len . ' ) { return "><"; }
      $html_str = html_entity_decode( $a[1] );
      $subsrt   = max(0, ('.$srt.'-$strlen));
      $sublen = ' . ( empty($strict)? '(' . $len . '-$strlen)' : 'max(@strpos( $html_str, "' . ($strict===2?'.':' ') . '", (' . $len . ' - $strlen + $subsrt - 1 )), ' . $len . ' - $strlen)' ) . ';
      $new_str = substr( $html_str, $subsrt,$sublen);
      $strlen += $new_str_len = strlen( $new_str );
      $suffix = ' . (!empty( $suffix ) ? '($new_str_len===$sublen?"'.$suffix.'":"")' : '""' ) . ';
      return ">" . htmlentities($new_str, ENT_QUOTES, "UTF-8") . "$suffix<";';

  return preg_replace( array( "#<[^/][^>]+>(?R)*</[^>]+>#", "#(<(b|h)r\s?/?>){2,}$#is"), "", trim( rtrim( ltrim( preg_replace_callback( "#>([^<]+)<#", create_function(
            '$a',
          $f
        ), ">$s<"  ), ">"), "<" ) ) );
}

/**
 * Insersts a text string within the first html element of a given string.
 */
function _inner_perpend_html_first($insert, $explode, $html_string) {
  $html_implode = $html_string;
  if(!empty($insert)) {
    $exploded_html = explode($explode, $html_string);
    $exploded_html[1] = $insert.$exploded_html[1];
    $html_implode = implode($explode, $exploded_html);
  }
  return $html_implode;
}

/**
 * Function converts objects to arrays
 */
function _object_to_array($object)
{
  $array=array();
  foreach($object as $member=>$data)
  {
    $array[$member]=$data;
  }
  return $array;
}

/**
 * Function converts objects to arrays recursively
 */
function _object_to_array_recursive($obj) {
  if(is_object($obj)) {
    $obj = (array) $obj;
  }
  if(is_array($obj)) {
    $new = array();
    foreach($obj as $key => $val) {
      $new[$key] = recursive_object_to_array($val);
    }
  } else {
    $new = $obj;
  }
  return $new;
}

/**
 * Function runs ksort recursively
 */
function _recursive_ksort(&$array) {
   foreach ($array as &$value) {
      if (is_array($value)) recursive_ksort($value);
   }
   return ksort($array);
}

/**
 * Random String Generator.
 */
function _generate_random_string($length = 10) {
    $characters = '0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ';
    $randomString = '';
    for ($i = 0; $i < $length; $i++) {
        $randomString .= $characters[rand(0, strlen($characters) - 1)];
    }
    return $randomString;
}