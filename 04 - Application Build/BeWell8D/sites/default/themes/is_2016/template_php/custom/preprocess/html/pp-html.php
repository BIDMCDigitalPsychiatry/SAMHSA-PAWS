<?php
$path = path_to_theme();
/*------------------------------------*/
/* Add Variables Accessible in all js */
/*------------------------------------*/
//ex. Drupal.settings.basePath <--- Allready exists no need to add
//Adding the absolute base_path() in javascript
drupal_add_js('jQuery.extend(Drupal.settings, { 
"absBasePath": "' . url('', array('absolute' => true)) . '", 
"pathToTheme": "' . $path . '/",
"absPathToTheme": "' . url($path, array('absolute' => true)) . '/"
});', 'inline');


/*-----------------------*/
/* Add Libraries JS/CSS  */
/*-----------------------*/
// ADD HEADER JS: drupal_add_js($path . '/js/PATH.js', array('scope' => 'head_scripts', 'weight' => WEIGHT, 'preprocess' => false));
// ADD FOOTER JS: drupal_add_js($path . '/js/PATH.js', array('weight' => -1));
// ADD JS LIB CSS: drupal_add_css($path . '/js/lib/PATH.css', array('weight' => -1));
 
//Head Scripts
drupal_add_js($path . '/js/lib/modernizr/2.8.3/modernizr.min.js', array('scope' => 'head_scripts', 'weight' => -1, 'preprocess' => false));
//Footer Scripts
drupal_add_js($path . '/js/scripts.js', array('weight' => 999));