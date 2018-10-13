<?php
/**
 * @file
 * feature_general_config.default_picture_mapping.inc
 */

/**
 * Implements hook_default_picture_mapping().
 */
function feature_general_config_default_picture_mapping() {
  $export = array();

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'Banner Image';
  $picture_mapping->machine_name = 'banner_image';
  $picture_mapping->breakpoint_group = 'breakpoints_specific';
  $picture_mapping->mapping = array(
    'custom.user.mobile_only' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'banner_image_mobile',
      ),
    ),
    'custom.user.tablet_only' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'banner_image_tablet',
      ),
    ),
    'custom.user.laptop_only' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'banner_image_laptop',
      ),
    ),
    'custom.user.desktop_only' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'banner_image_desktop',
      ),
    ),
    'custom.user.widescreen_only' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'banner_image_widescreen',
      ),
    ),
  );
  $export['banner_image'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'Banner Image (Large)';
  $picture_mapping->machine_name = 'banner_image_large';
  $picture_mapping->breakpoint_group = 'breakpoints_specific';
  $picture_mapping->mapping = array(
    'custom.user.mobile_only' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'banner_image_large_mobile',
      ),
    ),
    'custom.user.tablet_only' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'banner_image_large_tablet',
      ),
    ),
    'custom.user.laptop_only' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'banner_image_large_laptop',
      ),
    ),
    'custom.user.desktop_only' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'banner_image_large_desktop',
      ),
    ),
    'custom.user.widescreen_only' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'banner_image_large_widescreen',
      ),
    ),
  );
  $export['banner_image_large'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'Content Image';
  $picture_mapping->machine_name = 'content_image';
  $picture_mapping->breakpoint_group = 'breakpoints_specific';
  $picture_mapping->mapping = array(
    'custom.user.mobile_only' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'content_image_mobile',
      ),
    ),
    'custom.user.tablet_only' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'content_image_tablet',
      ),
    ),
    'custom.user.laptop_only' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'content_image_laptop',
      ),
    ),
    'custom.user.desktop_only' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'content_image_desktop',
      ),
    ),
    'custom.user.widescreen_only' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'content_image_widescreen',
      ),
    ),
  );
  $export['content_image'] = $picture_mapping;

  return $export;
}
