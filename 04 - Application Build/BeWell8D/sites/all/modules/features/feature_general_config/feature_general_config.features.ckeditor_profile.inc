<?php
/**
 * @file
 * feature_general_config.features.ckeditor_profile.inc
 */

/**
 * Implements hook_ckeditor_profile_defaults().
 */
function feature_general_config_ckeditor_profile_defaults() {
  $data = array(
    'CKEditor Global Profile' => array(
      'name' => 'CKEditor Global Profile',
      'settings' => array(
        'ckeditor_path' => '%l/ckeditor',
      ),
      'input_formats' => array(),
    ),
    'basic_html' => array(
      'name' => 'basic_html',
      'settings' => array(
        'ss' => 2,
        'toolbar' => '[
    [\'Maximize\',\'Bold\',\'Italic\',\'Underline\',\'Strike\'],
    [\'Subscript\',\'Superscript\'],
    [\'Outdent\',\'Indent\',\'BulletedList\',\'NumberedList\'],
    [\'JustifyLeft\',\'JustifyCenter\',\'JustifyRight\'],
    [\'Link\',\'Unlink\']
]',
        'expand' => 't',
        'default' => 't',
        'show_toggle' => 't',
        'uicolor' => 'default',
        'uicolor_user' => '#747A7A',
        'width' => '100%',
        'lang' => 'en',
        'auto_lang' => 't',
        'language_direction' => 'default',
        'allowed_content' => 't',
        'extraAllowedContent' => '',
        'enter_mode' => 'p',
        'shift_enter_mode' => 'br',
        'font_format' => 'p;div;pre;address',
        'custom_formatting' => 'f',
        'formatting' => array(
          'custom_formatting_options' => array(
            'indent' => 'indent',
            'breakBeforeOpen' => 'breakBeforeOpen',
            'breakAfterOpen' => 'breakAfterOpen',
            'breakAfterClose' => 'breakAfterClose',
            'breakBeforeClose' => 0,
            'pre_indent' => 0,
          ),
        ),
        'css_mode' => 'self',
        'css_path' => '%tcss/wysiwyg.css',
        'css_style' => 'self',
        'styles_path' => '%tckeditor/ckeditor.styles.js',
        'filebrowser' => 'none',
        'filebrowser_image' => '',
        'filebrowser_flash' => '',
        'UserFilesPath' => '%b%f/',
        'UserFilesAbsolutePath' => '%d%b%f/',
        'forcePasteAsPlainText' => 't',
        'html_entities' => 'f',
        'scayt_autoStartup' => 'f',
        'theme_config_js' => 't',
        'js_conf' => 'config.allowedContent = true;',
        'loadPlugins' => array(
          'ckeditor_link' => array(
            'name' => 'drupal_path',
            'desc' => 'CKEditor Link - A plugin to easily create links to Drupal internal paths',
            'path' => '%base_path%sites/all/modules/contrib/ckeditor_link/plugins/link/',
          ),
        ),
      ),
      'input_formats' => array(
        'basic_html' => 'Basic HTML',
      ),
    ),
    'full_html' => array(
      'name' => 'full_html',
      'settings' => array(
        'ss' => 2,
        'toolbar' => '[
    [\'Maximize\',\'Source\'],
    [\'Undo\',\'Redo\'],
    [\'Paste\',\'RemoveFormat\'],
    [\'Image\',\'IMCE\',\'CustomShortcodeCkeditorUI\',\'HorizontalRule\'],
    [\'Link\',\'Unlink\',\'Anchor\'],
    \'/\',
    [\'Format\',\'Styles\'],
    [\'Bold\',\'Italic\',\'Underline\',\'Strike\',\'Subscript\',\'Superscript\'],
    [\'BulletedList\',\'NumberedList\',\'Outdent\',\'Indent\'],
    [\'Table\',\'Blockquote\']
]',
        'expand' => 't',
        'default' => 't',
        'show_toggle' => 't',
        'uicolor' => 'default',
        'uicolor_user' => 'default',
        'width' => '100%',
        'lang' => 'en',
        'auto_lang' => 't',
        'language_direction' => 'default',
        'allowed_content' => 't',
        'extraAllowedContent' => '',
        'enter_mode' => 'p',
        'shift_enter_mode' => 'br',
        'font_format' => 'p;h2;h3;h4;h5;h6',
        'custom_formatting' => 'f',
        'formatting' => array(
          'custom_formatting_options' => array(
            'indent' => 0,
            'breakBeforeOpen' => 0,
            'breakAfterOpen' => 0,
            'breakBeforeClose' => 0,
            'breakAfterClose' => 0,
            'pre_indent' => 0,
          ),
        ),
        'css_mode' => 'self',
        'css_path' => '%tcss/wysiwyg.css',
        'css_style' => 'self',
        'styles_path' => '%tckeditor/ckeditor.styles.js',
        'filebrowser' => 'imce',
        'filebrowser_image' => 'imce',
        'filebrowser_flash' => 'imce',
        'UserFilesPath' => '%b%f/',
        'UserFilesAbsolutePath' => '%d%b%f/',
        'forcePasteAsPlainText' => 't',
        'html_entities' => 'f',
        'scayt_autoStartup' => 't',
        'theme_config_js' => 't',
        'js_conf' => 'config.allowedContent = true;
// config.extraPlugins = \'devtools\';',
        'loadPlugins' => array(
          'CustomShortcodeCkeditorUI' => array(
            'name' => 'CustomShortcodeCkeditorUI',
            'desc' => 'Custom Shortcode CKEditor UI - A plugin to easily insert shortcodes via CKEditor',
            'path' => '%base_path%sites/all/modules/custom/custom_shortcode_ckeditor_ui/plugins/CustomShortcodeCkeditorUI/',
            'default' => 't',
            'buttons' => array(
              'CustomShortcodeCkeditorUI' => array(
                'label' => 'Insert Shortcode',
                'icon' => 'icons/CustomShortcodeCkeditorUI.png',
              ),
            ),
          ),
          'ckeditor_link' => array(
            'name' => 'drupal_path',
            'desc' => 'CKEditor Link - A plugin to easily create links to Drupal internal paths',
            'path' => '%base_path%sites/all/modules/contrib/ckeditor_link/plugins/link/',
          ),
          'drupalbreaks' => array(
            'name' => 'drupalbreaks',
            'desc' => 'Plugin for inserting Drupal teaser and page breaks.',
            'path' => '%plugin_dir%drupalbreaks/',
            'buttons' => array(
              'DrupalBreak' => array(
                'label' => 'DrupalBreak',
                'icon' => 'images/drupalbreak.png',
              ),
            ),
            'default' => 't',
          ),
          'imce' => array(
            'name' => 'imce',
            'desc' => 'Plugin for inserting files from IMCE without image dialog',
            'path' => '%plugin_dir%imce/',
            'buttons' => array(
              'IMCE' => array(
                'label' => 'IMCE',
                'icon' => 'images/icon.png',
              ),
            ),
            'default' => 'f',
          ),
          'mediaembed' => array(
            'name' => 'mediaembed',
            'desc' => 'Plugin for embedding HTML snippets',
            'path' => '%plugin_dir%mediaembed/',
            'buttons' => array(
              'MediaEmbed' => array(
                'label' => 'MediaEmbed',
                'icon' => 'images/icon.png',
              ),
            ),
            'default' => 'f',
          ),
          'picture_ckeditor' => array(
            'name' => 'picture_ckeditor',
            'desc' => 'Support responsive images with the Picture module.',
            'buttons' => FALSE,
            'path' => '%base_path%sites/all/modules/contrib/picture/ckeditor/plugins/',
            'default' => 't',
          ),
        ),
      ),
      'input_formats' => array(
        'full_html' => 'Full HTML',
      ),
    ),
    'full_html_mobile_app' => array(
      'name' => 'full_html_mobile_app',
      'settings' => array(
        'ss' => 2,
        'toolbar' => '[
    [\'Maximize\',\'Source\'],
    [\'Undo\',\'Redo\'],
    [\'Paste\',\'RemoveFormat\'],
    [\'Image\',\'CustomShortcodeCkeditorUI\',\'HorizontalRule\'],
    [\'Link\',\'Unlink\',\'Anchor\'],
    \'/\',
    [\'Format\',\'Styles\'],
    [\'Bold\',\'Italic\',\'Underline\',\'Strike\',\'Subscript\',\'Superscript\'],
    [\'BulletedList\',\'NumberedList\',\'Outdent\',\'Indent\'],
    [\'Table\',\'Blockquote\']
]',
        'expand' => 't',
        'default' => 't',
        'show_toggle' => 't',
        'uicolor' => 'default',
        'uicolor_user' => 'default',
        'width' => '100%',
        'lang' => 'en',
        'auto_lang' => 't',
        'language_direction' => 'default',
        'allowed_content' => 't',
        'extraAllowedContent' => '',
        'enter_mode' => 'p',
        'shift_enter_mode' => 'br',
        'font_format' => 'p;h2;h3;h4;h5;h6',
        'custom_formatting' => 'f',
        'formatting' => array(
          'custom_formatting_options' => array(
            'indent' => 0,
            'breakBeforeOpen' => 0,
            'breakAfterOpen' => 0,
            'breakBeforeClose' => 0,
            'breakAfterClose' => 0,
            'pre_indent' => 0,
          ),
        ),
        'css_mode' => 'self',
        'css_path' => '%tcss/mobile-wysiwyg.css',
        'css_style' => 'self',
        'styles_path' => '%tckeditor/ckeditor.styles-mobile.js',
        'filebrowser' => 'imce',
        'filebrowser_image' => 'imce',
        'filebrowser_flash' => 'imce',
        'UserFilesPath' => '%b%f/',
        'UserFilesAbsolutePath' => '%d%b%f/',
        'forcePasteAsPlainText' => 't',
        'html_entities' => 'f',
        'scayt_autoStartup' => 't',
        'theme_config_js' => 't',
        'js_conf' => 'config.allowedContent = true;
// config.extraPlugins = \'devtools\';',
        'loadPlugins' => array(
          'CustomShortcodeCkeditorUI' => array(
            'name' => 'CustomShortcodeCkeditorUI',
            'desc' => 'Custom Shortcode CKEditor UI - A plugin to easily insert shortcodes via CKEditor',
            'path' => '%base_path%sites/all/modules/custom/custom_shortcode_ckeditor_ui/plugins/CustomShortcodeCkeditorUI/',
            'default' => 't',
            'buttons' => array(
              'CustomShortcodeCkeditorUI' => array(
                'label' => 'Insert Shortcode',
                'icon' => 'icons/CustomShortcodeCkeditorUI.png',
              ),
            ),
          ),
          'ckeditor_link' => array(
            'name' => 'drupal_path',
            'desc' => 'CKEditor Link - A plugin to easily create links to Drupal internal paths',
            'path' => '%base_path%sites/all/modules/contrib/ckeditor_link/plugins/link/',
          ),
          'drupalbreaks' => array(
            'name' => 'drupalbreaks',
            'desc' => 'Plugin for inserting Drupal teaser and page breaks.',
            'path' => '%plugin_dir%drupalbreaks/',
            'buttons' => array(
              'DrupalBreak' => array(
                'label' => 'DrupalBreak',
                'icon' => 'images/drupalbreak.png',
              ),
            ),
            'default' => 't',
          ),
          'imce' => array(
            'name' => 'imce',
            'desc' => 'Plugin for inserting files from IMCE without image dialog',
            'path' => '%plugin_dir%imce/',
            'buttons' => array(
              'IMCE' => array(
                'label' => 'IMCE',
                'icon' => 'images/icon.png',
              ),
            ),
            'default' => 'f',
          ),
          'mediaembed' => array(
            'name' => 'mediaembed',
            'desc' => 'Plugin for embedding HTML snippets',
            'path' => '%plugin_dir%mediaembed/',
            'buttons' => array(
              'MediaEmbed' => array(
                'label' => 'MediaEmbed',
                'icon' => 'images/icon.png',
              ),
            ),
            'default' => 'f',
          ),
          'picture_ckeditor' => array(
            'name' => 'picture_ckeditor',
            'desc' => 'Support responsive images with the Picture module.',
            'buttons' => FALSE,
            'path' => '%base_path%sites/all/modules/contrib/picture/ckeditor/plugins/',
            'default' => 't',
          ),
        ),
      ),
      'input_formats' => array(
        'full_html_mobile_app' => 'Full HTML - Mobile App',
      ),
    ),
  );
  return $data;
}
