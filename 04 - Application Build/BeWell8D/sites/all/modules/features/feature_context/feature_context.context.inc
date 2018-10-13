<?php
/**
 * @file
 * feature_context.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function feature_context_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'home_blocks';
  $context->description = 'Adds in blocks for the home page.';
  $context->tag = 'home';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
        'home' => 'home',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'custom_blocks-cb_app_title_block' => array(
          'module' => 'custom_blocks',
          'delta' => 'cb_app_title_block',
          'region' => 'headerfront',
          'weight' => '-10',
        ),
        'menu_block-1' => array(
          'module' => 'menu_block',
          'delta' => '1',
          'region' => 'headerfront',
          'weight' => '-9',
        ),
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '0',
        ),
        'custom_blocks-cb_samhsa_block' => array(
          'module' => 'custom_blocks',
          'delta' => 'cb_samhsa_block',
          'region' => 'content',
          'weight' => '1',
        ),
        'custom_blocks-cb_copyright_block' => array(
          'module' => 'custom_blocks',
          'delta' => 'cb_copyright_block',
          'region' => 'footerfront',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Adds in blocks for the home page.');
  t('home');
  $export['home_blocks'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'secondary_pages_blocks';
  $context->description = 'Sets blocks for specific secondary pages.';
  $context->tag = 'secondary';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'user' => 'user',
        'user/*' => 'user/*',
        'users' => 'users',
        'users/*' => 'users/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'custom_blocks-cb_breadcrumb_block' => array(
          'module' => 'custom_blocks',
          'delta' => 'cb_breadcrumb_block',
          'region' => 'headersecondarytop',
          'weight' => '-10',
        ),
        'menu_block-1' => array(
          'module' => 'menu_block',
          'delta' => '1',
          'region' => 'headersecondarytop',
          'weight' => '-9',
        ),
        'custom_blocks-cb_page_title_block' => array(
          'module' => 'custom_blocks',
          'delta' => 'cb_page_title_block',
          'region' => 'headersecondarybot',
          'weight' => '-10',
        ),
        'local_tasks_blocks-menu_menu_local_tasks_primary' => array(
          'module' => 'local_tasks_blocks',
          'delta' => 'menu_menu_local_tasks_primary',
          'region' => 'headersecondarybot',
          'weight' => '-9',
        ),
        'custom_blocks-cb_copyright_block' => array(
          'module' => 'custom_blocks',
          'delta' => 'cb_copyright_block',
          'region' => 'footersecondary',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Sets blocks for specific secondary pages.');
  t('secondary');
  $export['secondary_pages_blocks'] = $context;

  return $export;
}
