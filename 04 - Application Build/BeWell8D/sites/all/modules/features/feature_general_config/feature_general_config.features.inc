<?php
/**
 * @file
 * feature_general_config.features.inc
 */

/**
 * Implements hook_default_cer().
 */
function feature_general_config_default_cer() {
  $items = array();
  $items['node:mobile_app_activities:field_wellness_goal_relation*taxonomy_term:eight_dimensions_of_wellness:field_activities'] = entity_import('cer', '{
    "cer_bidirectional" : { "und" : [ { "value" : "1" } ] },
    "cer_enabled" : { "und" : [ { "value" : "1" } ] },
    "cer_left" : { "und" : [ { "path" : "node:mobile_app_activities:field_wellness_goal_relation" } ] },
    "cer_right" : { "und" : [
        { "path" : "taxonomy_term:eight_dimensions_of_wellness:field_activities" }
      ]
    },
    "cer_weight" : { "und" : [ { "value" : "-50" } ] },
    "identifier" : "node:mobile_app_activities:field_wellness_goal_relation*taxonomy_term:eight_dimensions_of_wellness:field_activities",
    "rdf_mapping" : []
  }');
  $items['node:mobile_app_badges:field_wellness_goal_relation*taxonomy_term:eight_dimensions_of_wellness:field_badges'] = entity_import('cer', '{
    "cer_bidirectional" : { "und" : [ { "value" : "1" } ] },
    "cer_enabled" : { "und" : [ { "value" : "1" } ] },
    "cer_left" : { "und" : [ { "path" : "node:mobile_app_badges:field_wellness_goal_relation" } ] },
    "cer_right" : { "und" : [ { "path" : "taxonomy_term:eight_dimensions_of_wellness:field_badges" } ] },
    "cer_weight" : { "und" : [ { "value" : "-46" } ] },
    "identifier" : "node:mobile_app_badges:field_wellness_goal_relation*taxonomy_term:eight_dimensions_of_wellness:field_badges",
    "rdf_mapping" : []
  }');
  $items['node:mobile_app_resources:field_wellness_goal_relation*taxonomy_term:eight_dimensions_of_wellness:field_resources'] = entity_import('cer', '{
    "cer_bidirectional" : { "und" : [ { "value" : "1" } ] },
    "cer_enabled" : { "und" : [ { "value" : "1" } ] },
    "cer_left" : { "und" : [ { "path" : "node:mobile_app_resources:field_wellness_goal_relation" } ] },
    "cer_right" : { "und" : [
        { "path" : "taxonomy_term:eight_dimensions_of_wellness:field_resources" }
      ]
    },
    "cer_weight" : { "und" : [ { "value" : "-48" } ] },
    "identifier" : "node:mobile_app_resources:field_wellness_goal_relation*taxonomy_term:eight_dimensions_of_wellness:field_resources",
    "rdf_mapping" : []
  }');
  $items['taxonomy_term:eight_dimensions_of_wellness:field_activities*node:mobile_app_activities:field_wellness_goal_relation'] = entity_import('cer', '{
    "cer_bidirectional" : { "und" : [ { "value" : "1" } ] },
    "cer_enabled" : { "und" : [ { "value" : "1" } ] },
    "cer_left" : { "und" : [
        { "path" : "taxonomy_term:eight_dimensions_of_wellness:field_activities" }
      ]
    },
    "cer_right" : { "und" : [ { "path" : "node:mobile_app_activities:field_wellness_goal_relation" } ] },
    "cer_weight" : { "und" : [ { "value" : "-49" } ] },
    "identifier" : "taxonomy_term:eight_dimensions_of_wellness:field_activities*node:mobile_app_activities:field_wellness_goal_relation",
    "rdf_mapping" : []
  }');
  $items['taxonomy_term:eight_dimensions_of_wellness:field_badges*node:mobile_app_badges:field_wellness_goal_relation'] = entity_import('cer', '{
    "cer_bidirectional" : { "und" : [ { "value" : "1" } ] },
    "cer_enabled" : { "und" : [ { "value" : "1" } ] },
    "cer_left" : { "und" : [ { "path" : "taxonomy_term:eight_dimensions_of_wellness:field_badges" } ] },
    "cer_right" : { "und" : [ { "path" : "node:mobile_app_badges:field_wellness_goal_relation" } ] },
    "cer_weight" : { "und" : [ { "value" : "-45" } ] },
    "identifier" : "taxonomy_term:eight_dimensions_of_wellness:field_badges*node:mobile_app_badges:field_wellness_goal_relation",
    "rdf_mapping" : []
  }');
  $items['taxonomy_term:eight_dimensions_of_wellness:field_resources*node:mobile_app_resources:field_wellness_goal_relation'] = entity_import('cer', '{
    "cer_bidirectional" : { "und" : [ { "value" : "1" } ] },
    "cer_enabled" : { "und" : [ { "value" : "1" } ] },
    "cer_left" : { "und" : [
        { "path" : "taxonomy_term:eight_dimensions_of_wellness:field_resources" }
      ]
    },
    "cer_right" : { "und" : [ { "path" : "node:mobile_app_resources:field_wellness_goal_relation" } ] },
    "cer_weight" : { "und" : [ { "value" : "-47" } ] },
    "identifier" : "taxonomy_term:eight_dimensions_of_wellness:field_resources*node:mobile_app_resources:field_wellness_goal_relation",
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_general_config_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "backup_migrate" && $api == "backup_migrate_exportables") {
    return array("version" => "1");
  }
  if ($module == "breakpoints" && $api == "default_breakpoint_group") {
    return array("version" => "1");
  }
  if ($module == "breakpoints" && $api == "default_breakpoints") {
    return array("version" => "1");
  }
  if ($module == "picture" && $api == "default_picture_mapping") {
    return array("version" => "2");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function feature_general_config_image_default_styles() {
  $styles = array();

  // Exported image style: banner_image_desktop.
  $styles['banner_image_desktop'] = array(
    'label' => 'banner_image_desktop',
    'effects' => array(
      8 => array(
        'name' => 'focal_point_scale_and_crop',
        'data' => array(
          'width' => 1400,
          'height' => 614,
          'focal_point_advanced' => array(
            'shift_x' => '',
            'shift_y' => '',
          ),
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: banner_image_laptop.
  $styles['banner_image_laptop'] = array(
    'label' => 'banner_image_laptop',
    'effects' => array(
      7 => array(
        'name' => 'focal_point_scale_and_crop',
        'data' => array(
          'width' => 1200,
          'height' => 526,
          'focal_point_advanced' => array(
            'shift_x' => '',
            'shift_y' => '',
          ),
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: banner_image_large_desktop.
  $styles['banner_image_large_desktop'] = array(
    'label' => 'banner_image_large_desktop',
    'effects' => array(
      13 => array(
        'name' => 'focal_point_scale_and_crop',
        'data' => array(
          'width' => 1400,
          'height' => 913,
          'focal_point_advanced' => array(
            'shift_x' => '',
            'shift_y' => '',
          ),
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: banner_image_large_laptop.
  $styles['banner_image_large_laptop'] = array(
    'label' => 'banner_image_large_laptop',
    'effects' => array(
      12 => array(
        'name' => 'focal_point_scale_and_crop',
        'data' => array(
          'width' => 1200,
          'height' => 783,
          'focal_point_advanced' => array(
            'shift_x' => '',
            'shift_y' => '',
          ),
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: banner_image_large_mobile.
  $styles['banner_image_large_mobile'] = array(
    'label' => 'banner_image_large_mobile',
    'effects' => array(
      10 => array(
        'name' => 'focal_point_scale_and_crop',
        'data' => array(
          'width' => 600,
          'height' => 800,
          'focal_point_advanced' => array(
            'shift_x' => '',
            'shift_y' => '',
          ),
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: banner_image_large_tablet.
  $styles['banner_image_large_tablet'] = array(
    'label' => 'banner_image_large_tablet',
    'effects' => array(
      18 => array(
        'name' => 'focal_point_scale_and_crop',
        'data' => array(
          'width' => 800,
          'height' => 1067,
          'focal_point_advanced' => array(
            'shift_x' => '',
            'shift_y' => '',
          ),
        ),
        'weight' => 3,
      ),
    ),
  );

  // Exported image style: banner_image_large_widescreen.
  $styles['banner_image_large_widescreen'] = array(
    'label' => 'banner_image_large_widescreen',
    'effects' => array(
      15 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 1800,
          'height' => 1174,
          'upscale' => 1,
        ),
        'weight' => -10,
      ),
      14 => array(
        'name' => 'focal_point_scale_and_crop',
        'data' => array(
          'width' => 1800,
          'height' => 1174,
          'focal_point_advanced' => array(
            'shift_x' => '',
            'shift_y' => '',
          ),
        ),
        'weight' => -9,
      ),
    ),
  );

  // Exported image style: banner_image_mobile.
  $styles['banner_image_mobile'] = array(
    'label' => 'banner_image_mobile',
    'effects' => array(
      6 => array(
        'name' => 'focal_point_scale_and_crop',
        'data' => array(
          'width' => 600,
          'height' => 511,
          'focal_point_advanced' => array(
            'shift_x' => '',
            'shift_y' => '',
          ),
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: banner_image_tablet.
  $styles['banner_image_tablet'] = array(
    'label' => 'banner_image_tablet',
    'effects' => array(
      5 => array(
        'name' => 'focal_point_scale_and_crop',
        'data' => array(
          'width' => 800,
          'height' => 351,
          'focal_point_advanced' => array(
            'shift_x' => '',
            'shift_y' => '',
          ),
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: banner_image_widescreen.
  $styles['banner_image_widescreen'] = array(
    'label' => 'banner_image_widescreen',
    'effects' => array(
      9 => array(
        'name' => 'focal_point_scale_and_crop',
        'data' => array(
          'width' => 1800,
          'height' => 587,
          'focal_point_advanced' => array(
            'shift_x' => '',
            'shift_y' => '',
          ),
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: content_image_desktop.
  $styles['content_image_desktop'] = array(
    'label' => 'content_image_desktop',
    'effects' => array(
      22 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 700,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: content_image_laptop.
  $styles['content_image_laptop'] = array(
    'label' => 'content_image_laptop',
    'effects' => array(
      21 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 600,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: content_image_mobile.
  $styles['content_image_mobile'] = array(
    'label' => 'content_image_mobile',
    'effects' => array(
      19 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 400,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: content_image_tablet.
  $styles['content_image_tablet'] = array(
    'label' => 'content_image_tablet',
    'effects' => array(
      20 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 540,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: content_image_widescreen.
  $styles['content_image_widescreen'] = array(
    'label' => 'content_image_widescreen',
    'effects' => array(
      23 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 900,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
