<?php
/**
 * @file
 * feature_views.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function feature_views_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'admin_manage_global_badges_';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Admin: Manage Global Badges ';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Admin: Manage Global Badges ';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    4 => '4',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'editableviews_table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_badge_type' => 'field_badge_type',
    'field_badge_points_accumulated' => 'field_badge_points_accumulated',
    'field_activity_type' => 'field_activity_type',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_badge_type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_badge_points_accumulated' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_activity_type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['batch_size'] = '10';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'Create Badge Link';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<h3><a href="/node/add/mobile-app-badges?destination=/admin/site-admin/mobile-app/manage-global-badges"><strong>+ Create New Badge</strong></a></h3>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Badge Type */
  $handler->display->display_options['fields']['field_badge_type']['id'] = 'field_badge_type';
  $handler->display->display_options['fields']['field_badge_type']['table'] = 'field_data_field_badge_type';
  $handler->display->display_options['fields']['field_badge_type']['field'] = 'field_badge_type';
  /* Field: Content: Points Accumulated */
  $handler->display->display_options['fields']['field_badge_points_accumulated']['id'] = 'field_badge_points_accumulated';
  $handler->display->display_options['fields']['field_badge_points_accumulated']['table'] = 'field_data_field_badge_points_accumulated';
  $handler->display->display_options['fields']['field_badge_points_accumulated']['field'] = 'field_badge_points_accumulated';
  $handler->display->display_options['fields']['field_badge_points_accumulated']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Activity Type Completed */
  $handler->display->display_options['fields']['field_activity_type']['id'] = 'field_activity_type';
  $handler->display->display_options['fields']['field_activity_type']['table'] = 'field_data_field_activity_type';
  $handler->display->display_options['fields']['field_activity_type']['field'] = 'field_activity_type';
  $handler->display->display_options['fields']['field_activity_type']['label'] = 'Activity Type';
  $handler->display->display_options['fields']['field_activity_type']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  /* Sort criterion: Content: Badge Type (field_badge_type) */
  $handler->display->display_options['sorts']['field_badge_type_value']['id'] = 'field_badge_type_value';
  $handler->display->display_options['sorts']['field_badge_type_value']['table'] = 'field_data_field_badge_type';
  $handler->display->display_options['sorts']['field_badge_type_value']['field'] = 'field_badge_type_value';
  $handler->display->display_options['sorts']['field_badge_type_value']['order'] = 'DESC';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'mobile_app_badges' => 'mobile_app_badges',
  );
  /* Filter criterion: Content: Wellness Goal Relation (field_wellness_goal_relation) */
  $handler->display->display_options['filters']['field_wellness_goal_relation_target_id']['id'] = 'field_wellness_goal_relation_target_id';
  $handler->display->display_options['filters']['field_wellness_goal_relation_target_id']['table'] = 'field_data_field_wellness_goal_relation';
  $handler->display->display_options['filters']['field_wellness_goal_relation_target_id']['field'] = 'field_wellness_goal_relation_target_id';
  $handler->display->display_options['filters']['field_wellness_goal_relation_target_id']['operator'] = 'empty';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/site-admin/mobile-app/manage-global-badges';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Manage Global Badges ';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['admin_manage_global_badges_'] = $view;

  $view = new view();
  $view->name = 'admin_manage_push_notifications';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Admin: Manage Push Notifications';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Admin: Manage Push Notifications';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    4 => '4',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_push_notification_message' => 'field_push_notification_message',
    'field_wellness_goal_relation' => 'field_wellness_goal_relation',
    'uid' => 'uid',
    'created' => 'created',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_push_notification_message' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_wellness_goal_relation' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'uid' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<h3><a href="/node/add/push-notification?destination=/admin/site-admin/web-view/manage-push-notifications"><strong>+ Create Push Notification</strong></a></h3>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Push Notification Message (Used In Push Notification) */
  $handler->display->display_options['fields']['field_push_notification_message']['id'] = 'field_push_notification_message';
  $handler->display->display_options['fields']['field_push_notification_message']['table'] = 'field_data_field_push_notification_message';
  $handler->display->display_options['fields']['field_push_notification_message']['field'] = 'field_push_notification_message';
  $handler->display->display_options['fields']['field_push_notification_message']['label'] = 'Push Notification Message';
  $handler->display->display_options['fields']['field_push_notification_message']['alter']['max_length'] = '300';
  $handler->display->display_options['fields']['field_push_notification_message']['alter']['more_link_text'] = 'Read More';
  $handler->display->display_options['fields']['field_push_notification_message']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_push_notification_message']['type'] = 'text_plain';
  /* Field: Content: Wellness Goal Relation */
  $handler->display->display_options['fields']['field_wellness_goal_relation']['id'] = 'field_wellness_goal_relation';
  $handler->display->display_options['fields']['field_wellness_goal_relation']['table'] = 'field_data_field_wellness_goal_relation';
  $handler->display->display_options['fields']['field_wellness_goal_relation']['field'] = 'field_wellness_goal_relation';
  $handler->display->display_options['fields']['field_wellness_goal_relation']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Content: Author uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'node';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = 'Author';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Edit';
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = 'Delete';
  $handler->display->display_options['fields']['delete_node']['text'] = 'Delete';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'push_notification' => 'push_notification',
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Content: Wellness Goal Relation (field_wellness_goal_relation) */
  $handler->display->display_options['filters']['field_wellness_goal_relation_target_id']['id'] = 'field_wellness_goal_relation_target_id';
  $handler->display->display_options['filters']['field_wellness_goal_relation_target_id']['table'] = 'field_data_field_wellness_goal_relation';
  $handler->display->display_options['filters']['field_wellness_goal_relation_target_id']['field'] = 'field_wellness_goal_relation_target_id';
  $handler->display->display_options['filters']['field_wellness_goal_relation_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_wellness_goal_relation_target_id']['expose']['operator_id'] = 'field_wellness_goal_relation_target_id_op';
  $handler->display->display_options['filters']['field_wellness_goal_relation_target_id']['expose']['label'] = 'Wellness Goal Relation';
  $handler->display->display_options['filters']['field_wellness_goal_relation_target_id']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['field_wellness_goal_relation_target_id']['expose']['operator'] = 'field_wellness_goal_relation_target_id_op';
  $handler->display->display_options['filters']['field_wellness_goal_relation_target_id']['expose']['identifier'] = 'field_wellness_goal_relation_target_id';
  $handler->display->display_options['filters']['field_wellness_goal_relation_target_id']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_wellness_goal_relation_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/site-admin/web-view/manage-push-notifications';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Manage Push Notifications';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['admin_manage_push_notifications'] = $view;

  $view = new view();
  $view->name = 'eight_dimensions_of_wellness_list';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Mobile App: Eight Dimensions of Wellness List';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Eight Dimensions of Wellness List';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    2 => '2',
    3 => '3',
    4 => '4',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'views_json';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Field: Taxonomy term: Class */
  $handler->display->display_options['fields']['field_class']['id'] = 'field_class';
  $handler->display->display_options['fields']['field_class']['table'] = 'field_data_field_class';
  $handler->display->display_options['fields']['field_class']['field'] = 'field_class';
  $handler->display->display_options['fields']['field_class']['label'] = 'class';
  /* Field: Taxonomy term: Term description */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  $handler->display->display_options['fields']['description']['label'] = 'description';
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'eight_dimensions_of_wellness' => 'eight_dimensions_of_wellness',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Field: Taxonomy term: Class */
  $handler->display->display_options['fields']['field_class']['id'] = 'field_class';
  $handler->display->display_options['fields']['field_class']['table'] = 'field_data_field_class';
  $handler->display->display_options['fields']['field_class']['field'] = 'field_class';
  $handler->display->display_options['fields']['field_class']['label'] = 'class';
  /* Field: Taxonomy term: Term description */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  $handler->display->display_options['fields']['description']['label'] = 'description';
  /* Field: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['label'] = 'tid';
  $handler->display->display_options['fields']['tid']['separator'] = '';
  $handler->display->display_options['path'] = 'mobile/app/eight-dimensions-of-wellness-list';
  $export['eight_dimensions_of_wellness_list'] = $view;

  $view = new view();
  $view->name = 'mobile_app_my_wellness_goal_activities';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Mobile App: My Wellness Goal Activities';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    2 => '2',
    3 => '3',
    4 => '4',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_json';
  $handler->display->display_options['style_options']['plaintext_output'] = 1;
  $handler->display->display_options['style_options']['remove_newlines'] = 0;
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['style_options']['using_views_api_mode'] = 0;
  $handler->display->display_options['style_options']['object_arrays'] = 0;
  $handler->display->display_options['style_options']['numeric_strings'] = 0;
  $handler->display->display_options['style_options']['bigint_string'] = 0;
  $handler->display->display_options['style_options']['pretty_print'] = 0;
  $handler->display->display_options['style_options']['unescaped_slashes'] = 0;
  $handler->display->display_options['style_options']['unescaped_unicode'] = 0;
  $handler->display->display_options['style_options']['char_encoding'] = array();
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'nid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Activity Points */
  $handler->display->display_options['fields']['field_activity_points']['id'] = 'field_activity_points';
  $handler->display->display_options['fields']['field_activity_points']['table'] = 'field_data_field_activity_points';
  $handler->display->display_options['fields']['field_activity_points']['field'] = 'field_activity_points';
  $handler->display->display_options['fields']['field_activity_points']['label'] = 'activity_points';
  $handler->display->display_options['fields']['field_activity_points']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Field: Content: Activity Type Completed */
  $handler->display->display_options['fields']['field_activity_type']['id'] = 'field_activity_type';
  $handler->display->display_options['fields']['field_activity_type']['table'] = 'field_data_field_activity_type';
  $handler->display->display_options['fields']['field_activity_type']['field'] = 'field_activity_type';
  $handler->display->display_options['fields']['field_activity_type']['label'] = 'activity_type';
  $handler->display->display_options['fields']['field_activity_type']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_activity_type']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Activity Type Completed */
  $handler->display->display_options['fields']['field_activity_type_1']['id'] = 'field_activity_type_1';
  $handler->display->display_options['fields']['field_activity_type_1']['table'] = 'field_data_field_activity_type';
  $handler->display->display_options['fields']['field_activity_type_1']['field'] = 'field_activity_type';
  $handler->display->display_options['fields']['field_activity_type_1']['label'] = 'activity_type_name';
  $handler->display->display_options['fields']['field_activity_type_1']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Wellness Goal Relation */
  $handler->display->display_options['fields']['field_wellness_goal_relation']['id'] = 'field_wellness_goal_relation';
  $handler->display->display_options['fields']['field_wellness_goal_relation']['table'] = 'field_data_field_wellness_goal_relation';
  $handler->display->display_options['fields']['field_wellness_goal_relation']['field'] = 'field_wellness_goal_relation';
  $handler->display->display_options['fields']['field_wellness_goal_relation']['label'] = 'wellness_goal';
  $handler->display->display_options['fields']['field_wellness_goal_relation']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_wellness_goal_relation']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Wellness Goal Relation */
  $handler->display->display_options['fields']['field_wellness_goal_relation_1']['id'] = 'field_wellness_goal_relation_1';
  $handler->display->display_options['fields']['field_wellness_goal_relation_1']['table'] = 'field_data_field_wellness_goal_relation';
  $handler->display->display_options['fields']['field_wellness_goal_relation_1']['field'] = 'field_wellness_goal_relation';
  $handler->display->display_options['fields']['field_wellness_goal_relation_1']['label'] = 'wellness_goal_name';
  $handler->display->display_options['fields']['field_wellness_goal_relation_1']['settings'] = array(
    'link' => 0,
  );
  /* Contextual filter: Content: Activity Type Completed (field_activity_type) */
  $handler->display->display_options['arguments']['field_activity_type_target_id']['id'] = 'field_activity_type_target_id';
  $handler->display->display_options['arguments']['field_activity_type_target_id']['table'] = 'field_data_field_activity_type';
  $handler->display->display_options['arguments']['field_activity_type_target_id']['field'] = 'field_activity_type_target_id';
  $handler->display->display_options['arguments']['field_activity_type_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_activity_type_target_id']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['field_activity_type_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_activity_type_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_activity_type_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_activity_type_target_id']['break_phrase'] = TRUE;
  /* Contextual filter: Content: Wellness Goal Relation (field_wellness_goal_relation) */
  $handler->display->display_options['arguments']['field_wellness_goal_relation_target_id']['id'] = 'field_wellness_goal_relation_target_id';
  $handler->display->display_options['arguments']['field_wellness_goal_relation_target_id']['table'] = 'field_data_field_wellness_goal_relation';
  $handler->display->display_options['arguments']['field_wellness_goal_relation_target_id']['field'] = 'field_wellness_goal_relation_target_id';
  $handler->display->display_options['arguments']['field_wellness_goal_relation_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_wellness_goal_relation_target_id']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['field_wellness_goal_relation_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_wellness_goal_relation_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_wellness_goal_relation_target_id']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['index'] = '4';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = TRUE;
  $handler->display->display_options['arguments']['nid']['not'] = TRUE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'mobile_app_activities' => 'mobile_app_activities',
  );

  /* Display: Activity Check */
  $handler = $view->new_display('page', 'Activity Check', 'activities_check');
  $handler->display->display_options['path'] = 'mobile/app/my-wellness-goal-activities-check/%/%/%';

  /* Display: Global Activity Check */
  $handler = $view->new_display('page', 'Global Activity Check', 'global_activities_check');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Activity Type Completed (field_activity_type) */
  $handler->display->display_options['arguments']['field_activity_type_target_id']['id'] = 'field_activity_type_target_id';
  $handler->display->display_options['arguments']['field_activity_type_target_id']['table'] = 'field_data_field_activity_type';
  $handler->display->display_options['arguments']['field_activity_type_target_id']['field'] = 'field_activity_type_target_id';
  $handler->display->display_options['arguments']['field_activity_type_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_activity_type_target_id']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['field_activity_type_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_activity_type_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_activity_type_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_activity_type_target_id']['break_phrase'] = TRUE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['index'] = '3';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = TRUE;
  $handler->display->display_options['arguments']['nid']['not'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'mobile_app_activities' => 'mobile_app_activities',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['path'] = 'mobile/app/my-wellness-goal-activities-global-check/%/%';
  $export['mobile_app_my_wellness_goal_activities'] = $view;

  $view = new view();
  $view->name = 'mobile_app_my_wellness_goal_activities_list';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Mobile App: My Wellness Goal Activities List';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'My Wellness Goal Activities List';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    2 => '2',
    3 => '3',
    4 => '4',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'views_json';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_activities_target_id']['id'] = 'field_activities_target_id';
  $handler->display->display_options['relationships']['field_activities_target_id']['table'] = 'field_data_field_activities';
  $handler->display->display_options['relationships']['field_activities_target_id']['field'] = 'field_activities_target_id';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_user_hidden_activities_node']['id'] = 'reverse_field_user_hidden_activities_node';
  $handler->display->display_options['relationships']['reverse_field_user_hidden_activities_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_user_hidden_activities_node']['field'] = 'reverse_field_user_hidden_activities_node';
  $handler->display->display_options['relationships']['reverse_field_user_hidden_activities_node']['relationship'] = 'field_activities_target_id';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_user_hidden_activities_target_id']['id'] = 'field_user_hidden_activities_target_id';
  $handler->display->display_options['relationships']['field_user_hidden_activities_target_id']['table'] = 'field_data_field_user_hidden_activities';
  $handler->display->display_options['relationships']['field_user_hidden_activities_target_id']['field'] = 'field_user_hidden_activities_target_id';
  $handler->display->display_options['relationships']['field_user_hidden_activities_target_id']['relationship'] = 'reverse_field_user_hidden_activities_node';
  /* Field: Taxonomy term: Activities */
  $handler->display->display_options['fields']['field_activities']['id'] = 'field_activities';
  $handler->display->display_options['fields']['field_activities']['table'] = 'field_data_field_activities';
  $handler->display->display_options['fields']['field_activities']['field'] = 'field_activities';
  $handler->display->display_options['fields']['field_activities']['label'] = 'name';
  $handler->display->display_options['fields']['field_activities']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_activities']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_activities']['delta_offset'] = '0';
  /* Field: Content: Activity Type Completed */
  $handler->display->display_options['fields']['field_activity_type']['id'] = 'field_activity_type';
  $handler->display->display_options['fields']['field_activity_type']['table'] = 'field_data_field_activity_type';
  $handler->display->display_options['fields']['field_activity_type']['field'] = 'field_activity_type';
  $handler->display->display_options['fields']['field_activity_type']['relationship'] = 'field_activities_target_id';
  $handler->display->display_options['fields']['field_activity_type']['label'] = 'activity_type';
  $handler->display->display_options['fields']['field_activity_type']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'field_activities_target_id';
  $handler->display->display_options['fields']['nid']['label'] = 'nid';
  /* Field: Content: Activity Duration Start (Minutes) */
  $handler->display->display_options['fields']['field_activity_duration_start']['id'] = 'field_activity_duration_start';
  $handler->display->display_options['fields']['field_activity_duration_start']['table'] = 'field_data_field_activity_duration_start';
  $handler->display->display_options['fields']['field_activity_duration_start']['field'] = 'field_activity_duration_start';
  $handler->display->display_options['fields']['field_activity_duration_start']['relationship'] = 'field_activities_target_id';
  $handler->display->display_options['fields']['field_activity_duration_start']['label'] = 'activity_dur_start';
  $handler->display->display_options['fields']['field_activity_duration_start']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Activity Duration End (Minutes) */
  $handler->display->display_options['fields']['field_activity_duration_end']['id'] = 'field_activity_duration_end';
  $handler->display->display_options['fields']['field_activity_duration_end']['table'] = 'field_data_field_activity_duration_end';
  $handler->display->display_options['fields']['field_activity_duration_end']['field'] = 'field_activity_duration_end';
  $handler->display->display_options['fields']['field_activity_duration_end']['relationship'] = 'field_activities_target_id';
  $handler->display->display_options['fields']['field_activity_duration_end']['label'] = 'activity_dur_end';
  $handler->display->display_options['fields']['field_activity_duration_end']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Taxonomy term: Class */
  $handler->display->display_options['fields']['field_class']['id'] = 'field_class';
  $handler->display->display_options['fields']['field_class']['table'] = 'field_data_field_class';
  $handler->display->display_options['fields']['field_class']['field'] = 'field_class';
  $handler->display->display_options['fields']['field_class']['label'] = 'class';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'goal_name';
  /* Sort criterion: Content: Activity Duration Start (Minutes) (field_activity_duration_start) */
  $handler->display->display_options['sorts']['field_activity_duration_start_value']['id'] = 'field_activity_duration_start_value';
  $handler->display->display_options['sorts']['field_activity_duration_start_value']['table'] = 'field_data_field_activity_duration_start';
  $handler->display->display_options['sorts']['field_activity_duration_start_value']['field'] = 'field_activity_duration_start_value';
  $handler->display->display_options['sorts']['field_activity_duration_start_value']['relationship'] = 'field_activities_target_id';
  /* Sort criterion: Content: Activity Duration End (Minutes) (field_activity_duration_end) */
  $handler->display->display_options['sorts']['field_activity_duration_end_value']['id'] = 'field_activity_duration_end_value';
  $handler->display->display_options['sorts']['field_activity_duration_end_value']['table'] = 'field_data_field_activity_duration_end';
  $handler->display->display_options['sorts']['field_activity_duration_end_value']['field'] = 'field_activity_duration_end_value';
  $handler->display->display_options['sorts']['field_activity_duration_end_value']['relationship'] = 'field_activities_target_id';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['relationship'] = 'field_activities_target_id';
  /* Contextual filter: Content: Author uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'reverse_field_user_hidden_activities_node';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['not'] = TRUE;
  /* Contextual filter: Taxonomy term: Term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['break_phrase'] = TRUE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'eight_dimensions_of_wellness' => 'eight_dimensions_of_wellness',
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'field_activities_target_id';
  $handler->display->display_options['filters']['title']['operator'] = 'not empty';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Author uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'reverse_field_user_hidden_activities_node';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['not'] = TRUE;
  /* Contextual filter: Taxonomy term: Term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['break_phrase'] = TRUE;
  $handler->display->display_options['path'] = 'mobile/app/my-wellness-goal-activities-list/%/%';

  /* Display: Edit Page */
  $handler = $view->new_display('page', 'Edit Page', 'page_1');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Taxonomy term: Term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['break_phrase'] = TRUE;
  $handler->display->display_options['path'] = 'mobile/app/my-wellness-goal-activities-list-edit/%';
  $export['mobile_app_my_wellness_goal_activities_list'] = $view;

  $view = new view();
  $view->name = 'mobile_app_my_wellness_goal_activity_badges';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Mobile App: My Wellness Goal Activity Badges';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    2 => '2',
    3 => '3',
    4 => '4',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_json';
  $handler->display->display_options['style_options']['plaintext_output'] = 1;
  $handler->display->display_options['style_options']['remove_newlines'] = 0;
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['style_options']['using_views_api_mode'] = 0;
  $handler->display->display_options['style_options']['object_arrays'] = 0;
  $handler->display->display_options['style_options']['numeric_strings'] = 0;
  $handler->display->display_options['style_options']['bigint_string'] = 0;
  $handler->display->display_options['style_options']['pretty_print'] = 0;
  $handler->display->display_options['style_options']['unescaped_slashes'] = 0;
  $handler->display->display_options['style_options']['unescaped_unicode'] = 0;
  $handler->display->display_options['style_options']['char_encoding'] = array();
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'nid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Activity Type Completed */
  $handler->display->display_options['fields']['field_activity_type']['id'] = 'field_activity_type';
  $handler->display->display_options['fields']['field_activity_type']['table'] = 'field_data_field_activity_type';
  $handler->display->display_options['fields']['field_activity_type']['field'] = 'field_activity_type';
  $handler->display->display_options['fields']['field_activity_type']['label'] = 'activity_type_comp';
  $handler->display->display_options['fields']['field_activity_type']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_activity_type']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Activity Type Completed */
  $handler->display->display_options['fields']['field_activity_type_1']['id'] = 'field_activity_type_1';
  $handler->display->display_options['fields']['field_activity_type_1']['table'] = 'field_data_field_activity_type';
  $handler->display->display_options['fields']['field_activity_type_1']['field'] = 'field_activity_type';
  $handler->display->display_options['fields']['field_activity_type_1']['label'] = 'activity_type_name';
  $handler->display->display_options['fields']['field_activity_type_1']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Badge Type */
  $handler->display->display_options['fields']['field_badge_type']['id'] = 'field_badge_type';
  $handler->display->display_options['fields']['field_badge_type']['table'] = 'field_data_field_badge_type';
  $handler->display->display_options['fields']['field_badge_type']['field'] = 'field_badge_type';
  $handler->display->display_options['fields']['field_badge_type']['label'] = 'badge_type';
  $handler->display->display_options['fields']['field_badge_type']['type'] = 'list_key';
  /* Field: Content: Badge Type */
  $handler->display->display_options['fields']['field_badge_type_1']['id'] = 'field_badge_type_1';
  $handler->display->display_options['fields']['field_badge_type_1']['table'] = 'field_data_field_badge_type';
  $handler->display->display_options['fields']['field_badge_type_1']['field'] = 'field_badge_type';
  $handler->display->display_options['fields']['field_badge_type_1']['label'] = 'badge_type_name';
  /* Field: Content: Points Accumulated */
  $handler->display->display_options['fields']['field_badge_points_accumulated']['id'] = 'field_badge_points_accumulated';
  $handler->display->display_options['fields']['field_badge_points_accumulated']['table'] = 'field_data_field_badge_points_accumulated';
  $handler->display->display_options['fields']['field_badge_points_accumulated']['field'] = 'field_badge_points_accumulated';
  $handler->display->display_options['fields']['field_badge_points_accumulated']['label'] = 'points_earned';
  $handler->display->display_options['fields']['field_badge_points_accumulated']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_badge_points_accumulated']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Wellness Goal Relation */
  $handler->display->display_options['fields']['field_wellness_goal_relation']['id'] = 'field_wellness_goal_relation';
  $handler->display->display_options['fields']['field_wellness_goal_relation']['table'] = 'field_data_field_wellness_goal_relation';
  $handler->display->display_options['fields']['field_wellness_goal_relation']['field'] = 'field_wellness_goal_relation';
  $handler->display->display_options['fields']['field_wellness_goal_relation']['label'] = 'wellness_goal';
  $handler->display->display_options['fields']['field_wellness_goal_relation']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_wellness_goal_relation']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Wellness Goal Relation */
  $handler->display->display_options['fields']['field_wellness_goal_relation_1']['id'] = 'field_wellness_goal_relation_1';
  $handler->display->display_options['fields']['field_wellness_goal_relation_1']['table'] = 'field_data_field_wellness_goal_relation';
  $handler->display->display_options['fields']['field_wellness_goal_relation_1']['field'] = 'field_wellness_goal_relation';
  $handler->display->display_options['fields']['field_wellness_goal_relation_1']['label'] = 'wellness_goal_name';
  $handler->display->display_options['fields']['field_wellness_goal_relation_1']['settings'] = array(
    'link' => 0,
  );
  /* Contextual filter: Content: Badge Type (field_badge_type) */
  $handler->display->display_options['arguments']['field_badge_type_value']['id'] = 'field_badge_type_value';
  $handler->display->display_options['arguments']['field_badge_type_value']['table'] = 'field_data_field_badge_type';
  $handler->display->display_options['arguments']['field_badge_type_value']['field'] = 'field_badge_type_value';
  $handler->display->display_options['arguments']['field_badge_type_value']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_badge_type_value']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_badge_type_value']['default_argument_options']['index'] = '2';
  $handler->display->display_options['arguments']['field_badge_type_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_badge_type_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_badge_type_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_badge_type_value']['limit'] = '0';
  $handler->display->display_options['arguments']['field_badge_type_value']['break_phrase'] = TRUE;
  /* Contextual filter: Content: Activity Type Completed (field_activity_type) */
  $handler->display->display_options['arguments']['field_activity_type_target_id']['id'] = 'field_activity_type_target_id';
  $handler->display->display_options['arguments']['field_activity_type_target_id']['table'] = 'field_data_field_activity_type';
  $handler->display->display_options['arguments']['field_activity_type_target_id']['field'] = 'field_activity_type_target_id';
  $handler->display->display_options['arguments']['field_activity_type_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_activity_type_target_id']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['field_activity_type_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_activity_type_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_activity_type_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_activity_type_target_id']['break_phrase'] = TRUE;
  /* Contextual filter: Content: Wellness Goal Relation (field_wellness_goal_relation) */
  $handler->display->display_options['arguments']['field_wellness_goal_relation_target_id']['id'] = 'field_wellness_goal_relation_target_id';
  $handler->display->display_options['arguments']['field_wellness_goal_relation_target_id']['table'] = 'field_data_field_wellness_goal_relation';
  $handler->display->display_options['arguments']['field_wellness_goal_relation_target_id']['field'] = 'field_wellness_goal_relation_target_id';
  $handler->display->display_options['arguments']['field_wellness_goal_relation_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_wellness_goal_relation_target_id']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['field_wellness_goal_relation_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_wellness_goal_relation_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_wellness_goal_relation_target_id']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['index'] = '5';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = TRUE;
  $handler->display->display_options['arguments']['nid']['not'] = TRUE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'mobile_app_badges' => 'mobile_app_badges',
  );

  /* Display: Badge Check */
  $handler = $view->new_display('page', 'Badge Check', 'badges_check');
  $handler->display->display_options['path'] = 'mobile/app/my-wellness-goal-activities-badge-check/%/%/%/%';

  /* Display: Global Badge Check */
  $handler = $view->new_display('page', 'Global Badge Check', 'global_badges_check');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Badge Type (field_badge_type) */
  $handler->display->display_options['arguments']['field_badge_type_value']['id'] = 'field_badge_type_value';
  $handler->display->display_options['arguments']['field_badge_type_value']['table'] = 'field_data_field_badge_type';
  $handler->display->display_options['arguments']['field_badge_type_value']['field'] = 'field_badge_type_value';
  $handler->display->display_options['arguments']['field_badge_type_value']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_badge_type_value']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_badge_type_value']['default_argument_options']['index'] = '2';
  $handler->display->display_options['arguments']['field_badge_type_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_badge_type_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_badge_type_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_badge_type_value']['limit'] = '0';
  $handler->display->display_options['arguments']['field_badge_type_value']['break_phrase'] = TRUE;
  /* Contextual filter: Content: Activity Type Completed (field_activity_type) */
  $handler->display->display_options['arguments']['field_activity_type_target_id']['id'] = 'field_activity_type_target_id';
  $handler->display->display_options['arguments']['field_activity_type_target_id']['table'] = 'field_data_field_activity_type';
  $handler->display->display_options['arguments']['field_activity_type_target_id']['field'] = 'field_activity_type_target_id';
  $handler->display->display_options['arguments']['field_activity_type_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_activity_type_target_id']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['field_activity_type_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_activity_type_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_activity_type_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_activity_type_target_id']['break_phrase'] = TRUE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['index'] = '4';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = TRUE;
  $handler->display->display_options['arguments']['nid']['not'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'mobile_app_badges' => 'mobile_app_badges',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Wellness Goal Relation (field_wellness_goal_relation) */
  $handler->display->display_options['filters']['field_wellness_goal_relation_target_id']['id'] = 'field_wellness_goal_relation_target_id';
  $handler->display->display_options['filters']['field_wellness_goal_relation_target_id']['table'] = 'field_data_field_wellness_goal_relation';
  $handler->display->display_options['filters']['field_wellness_goal_relation_target_id']['field'] = 'field_wellness_goal_relation_target_id';
  $handler->display->display_options['filters']['field_wellness_goal_relation_target_id']['operator'] = 'empty';
  $handler->display->display_options['path'] = 'mobile/app/my-wellness-goal-activities-global-badge-check/%/%/%';
  $export['mobile_app_my_wellness_goal_activity_badges'] = $view;

  $view = new view();
  $view->name = 'mobile_app_my_wellness_goal_activity_badges_list';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Mobile App: My Wellness Goal Activity Badges List';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Mobile App: My Wellness Goal Activity Badges List';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    4 => '4',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'views_json';
  $handler->display->display_options['style_options']['plaintext_output'] = 1;
  $handler->display->display_options['style_options']['remove_newlines'] = 0;
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['style_options']['using_views_api_mode'] = 0;
  $handler->display->display_options['style_options']['object_arrays'] = 0;
  $handler->display->display_options['style_options']['numeric_strings'] = 0;
  $handler->display->display_options['style_options']['bigint_string'] = 0;
  $handler->display->display_options['style_options']['pretty_print'] = 0;
  $handler->display->display_options['style_options']['unescaped_slashes'] = 0;
  $handler->display->display_options['style_options']['unescaped_unicode'] = 0;
  $handler->display->display_options['style_options']['char_encoding'] = array();
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_wellness_goal_relation_target_id']['id'] = 'field_wellness_goal_relation_target_id';
  $handler->display->display_options['relationships']['field_wellness_goal_relation_target_id']['table'] = 'field_data_field_wellness_goal_relation';
  $handler->display->display_options['relationships']['field_wellness_goal_relation_target_id']['field'] = 'field_wellness_goal_relation_target_id';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'nid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Taxonomy term: Class */
  $handler->display->display_options['fields']['field_class_1']['id'] = 'field_class_1';
  $handler->display->display_options['fields']['field_class_1']['table'] = 'field_data_field_class';
  $handler->display->display_options['fields']['field_class_1']['field'] = 'field_class';
  $handler->display->display_options['fields']['field_class_1']['relationship'] = 'field_wellness_goal_relation_target_id';
  $handler->display->display_options['fields']['field_class_1']['label'] = 'grouping';
  $handler->display->display_options['fields']['field_class_1']['empty'] = 'global';
  $handler->display->display_options['fields']['field_class_1']['empty_zero'] = TRUE;
  /* Field: Content: Wellness Goal Relation */
  $handler->display->display_options['fields']['field_wellness_goal_relation']['id'] = 'field_wellness_goal_relation';
  $handler->display->display_options['fields']['field_wellness_goal_relation']['table'] = 'field_data_field_wellness_goal_relation';
  $handler->display->display_options['fields']['field_wellness_goal_relation']['field'] = 'field_wellness_goal_relation';
  $handler->display->display_options['fields']['field_wellness_goal_relation']['label'] = 'wellness_goal';
  $handler->display->display_options['fields']['field_wellness_goal_relation']['empty'] = 'Global';
  $handler->display->display_options['fields']['field_wellness_goal_relation']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_wellness_goal_relation']['settings'] = array(
    'link' => 0,
  );
  /* Field: Taxonomy term: Class */
  $handler->display->display_options['fields']['field_class']['id'] = 'field_class';
  $handler->display->display_options['fields']['field_class']['table'] = 'field_data_field_class';
  $handler->display->display_options['fields']['field_class']['field'] = 'field_class';
  $handler->display->display_options['fields']['field_class']['relationship'] = 'field_wellness_goal_relation_target_id';
  $handler->display->display_options['fields']['field_class']['label'] = 'wg_class';
  $handler->display->display_options['fields']['field_class']['empty'] = 'global';
  /* Field: Content: Activity Type Completed */
  $handler->display->display_options['fields']['field_activity_type']['id'] = 'field_activity_type';
  $handler->display->display_options['fields']['field_activity_type']['table'] = 'field_data_field_activity_type';
  $handler->display->display_options['fields']['field_activity_type']['field'] = 'field_activity_type';
  $handler->display->display_options['fields']['field_activity_type']['label'] = 'activity_type';
  $handler->display->display_options['fields']['field_activity_type']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Badge Type */
  $handler->display->display_options['fields']['field_badge_type']['id'] = 'field_badge_type';
  $handler->display->display_options['fields']['field_badge_type']['table'] = 'field_data_field_badge_type';
  $handler->display->display_options['fields']['field_badge_type']['field'] = 'field_badge_type';
  $handler->display->display_options['fields']['field_badge_type']['label'] = 'badge_type';
  /* Field: Content: Points Accumulated */
  $handler->display->display_options['fields']['field_badge_points_accumulated']['id'] = 'field_badge_points_accumulated';
  $handler->display->display_options['fields']['field_badge_points_accumulated']['table'] = 'field_data_field_badge_points_accumulated';
  $handler->display->display_options['fields']['field_badge_points_accumulated']['field'] = 'field_badge_points_accumulated';
  $handler->display->display_options['fields']['field_badge_points_accumulated']['label'] = 'points_acc';
  $handler->display->display_options['fields']['field_badge_points_accumulated']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_badge_points_accumulated']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Taxonomy term: Weight */
  $handler->display->display_options['fields']['weight']['id'] = 'weight';
  $handler->display->display_options['fields']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['weight']['field'] = 'weight';
  $handler->display->display_options['fields']['weight']['relationship'] = 'field_wellness_goal_relation_target_id';
  $handler->display->display_options['fields']['weight']['label'] = 'wg_weight';
  $handler->display->display_options['fields']['weight']['separator'] = '';
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['relationship'] = 'field_wellness_goal_relation_target_id';
  /* Contextual filter: Badge Nids */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['ui_name'] = 'Badge Nids';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = TRUE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'mobile_app_badges' => 'mobile_app_badges',
  );

  /* Display: By Nid */
  $handler = $view->new_display('page', 'By Nid', 'badges_by_nid');
  $handler->display->display_options['path'] = 'mobile/app/my-wellness-goal-activity-badge-list/%';

  /* Display: By Nid (Grouped WG) */
  $handler = $view->new_display('page', 'By Nid (Grouped WG)', 'badges_by_nid_grouped');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_json';
  $handler->display->display_options['style_options']['plaintext_output'] = 1;
  $handler->display->display_options['style_options']['remove_newlines'] = 0;
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['style_options']['using_views_api_mode'] = 0;
  $handler->display->display_options['style_options']['object_arrays'] = 0;
  $handler->display->display_options['style_options']['numeric_strings'] = 0;
  $handler->display->display_options['style_options']['bigint_string'] = 0;
  $handler->display->display_options['style_options']['pretty_print'] = 0;
  $handler->display->display_options['style_options']['unescaped_slashes'] = 0;
  $handler->display->display_options['style_options']['unescaped_unicode'] = 0;
  $handler->display->display_options['style_options']['char_encoding'] = array();
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['path'] = 'mobile/app/my-wellness-goal-activity-badge-list-grouped/%';
  $export['mobile_app_my_wellness_goal_activity_badges_list'] = $view;

  $view = new view();
  $view->name = 'mobile_app_user_settings_lists';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Mobile App: User Settings Lists';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    2 => '2',
    3 => '3',
    4 => '4',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'views_json';
  $handler->display->display_options['style_options']['plaintext_output'] = 1;
  $handler->display->display_options['style_options']['remove_newlines'] = 0;
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['style_options']['using_views_api_mode'] = 0;
  $handler->display->display_options['style_options']['object_arrays'] = 0;
  $handler->display->display_options['style_options']['numeric_strings'] = 0;
  $handler->display->display_options['style_options']['bigint_string'] = 0;
  $handler->display->display_options['style_options']['pretty_print'] = 0;
  $handler->display->display_options['style_options']['unescaped_slashes'] = 0;
  $handler->display->display_options['style_options']['unescaped_unicode'] = 0;
  $handler->display->display_options['style_options']['char_encoding'] = array();
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'No Wellness Goals';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<p>Sorry You Have no Wellness Goals Yet.</p>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_wellness_goals_target_id']['id'] = 'field_wellness_goals_target_id';
  $handler->display->display_options['relationships']['field_wellness_goals_target_id']['table'] = 'field_data_field_wellness_goals';
  $handler->display->display_options['relationships']['field_wellness_goals_target_id']['field'] = 'field_wellness_goals_target_id';
  $handler->display->display_options['relationships']['field_wellness_goals_target_id']['required'] = TRUE;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['label'] = 'user_settings_owner';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'settings_title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: User Wellness Goals */
  $handler->display->display_options['fields']['field_wellness_goals']['id'] = 'field_wellness_goals';
  $handler->display->display_options['fields']['field_wellness_goals']['table'] = 'field_data_field_wellness_goals';
  $handler->display->display_options['fields']['field_wellness_goals']['field'] = 'field_wellness_goals';
  $handler->display->display_options['fields']['field_wellness_goals']['label'] = 'name';
  $handler->display->display_options['fields']['field_wellness_goals']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_wellness_goals']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_wellness_goals']['delta_offset'] = '0';
  /* Field: Taxonomy term: Class */
  $handler->display->display_options['fields']['field_class']['id'] = 'field_class';
  $handler->display->display_options['fields']['field_class']['table'] = 'field_data_field_class';
  $handler->display->display_options['fields']['field_class']['field'] = 'field_class';
  $handler->display->display_options['fields']['field_class']['relationship'] = 'field_wellness_goals_target_id';
  $handler->display->display_options['fields']['field_class']['label'] = 'class';
  /* Field: Taxonomy term: Term description */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  $handler->display->display_options['fields']['description']['relationship'] = 'field_wellness_goals_target_id';
  $handler->display->display_options['fields']['description']['label'] = 'description';
  /* Field: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['relationship'] = 'field_wellness_goals_target_id';
  $handler->display->display_options['fields']['tid']['label'] = 'tid';
  /* Field: Taxonomy term: Activities */
  $handler->display->display_options['fields']['field_activities']['id'] = 'field_activities';
  $handler->display->display_options['fields']['field_activities']['table'] = 'field_data_field_activities';
  $handler->display->display_options['fields']['field_activities']['field'] = 'field_activities';
  $handler->display->display_options['fields']['field_activities']['relationship'] = 'field_wellness_goals_target_id';
  $handler->display->display_options['fields']['field_activities']['label'] = 'activities';
  $handler->display->display_options['fields']['field_activities']['type'] = 'field_count_text';
  $handler->display->display_options['fields']['field_activities']['settings'] = array(
    'prefix' => '',
    'suffix' => '',
    'displayonempty' => 1,
  );
  $handler->display->display_options['fields']['field_activities']['delta_offset'] = '0';
  /* Field: Taxonomy term: Resources */
  $handler->display->display_options['fields']['field_resources']['id'] = 'field_resources';
  $handler->display->display_options['fields']['field_resources']['table'] = 'field_data_field_resources';
  $handler->display->display_options['fields']['field_resources']['field'] = 'field_resources';
  $handler->display->display_options['fields']['field_resources']['relationship'] = 'field_wellness_goals_target_id';
  $handler->display->display_options['fields']['field_resources']['label'] = 'resources';
  $handler->display->display_options['fields']['field_resources']['type'] = 'field_count_text';
  $handler->display->display_options['fields']['field_resources']['settings'] = array(
    'prefix' => '',
    'suffix' => '',
    'displayonempty' => 1,
  );
  $handler->display->display_options['fields']['field_resources']['delta_offset'] = '0';
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['relationship'] = 'field_wellness_goals_target_id';
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['index'] = '2';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['use_alias'] = TRUE;
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'mobile_app_user_settings' => 'mobile_app_user_settings',
  );

  /* Display: My Wellness Goals */
  $handler = $view->new_display('page', 'My Wellness Goals', 'page_1');
  $handler->display->display_options['path'] = 'mobile/app/my-wellness-goals-list/%';
  $export['mobile_app_user_settings_lists'] = $view;

  $view = new view();
  $view->name = 'mobile_app_wellness_goal_activities_list';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Mobile App: Wellness Goal Activities List';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'My Wellness Goal Activities List';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    2 => '2',
    3 => '3',
    4 => '4',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'views_json';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_activities_target_id']['id'] = 'field_activities_target_id';
  $handler->display->display_options['relationships']['field_activities_target_id']['table'] = 'field_data_field_activities';
  $handler->display->display_options['relationships']['field_activities_target_id']['field'] = 'field_activities_target_id';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_user_hidden_activities_node']['id'] = 'reverse_field_user_hidden_activities_node';
  $handler->display->display_options['relationships']['reverse_field_user_hidden_activities_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_user_hidden_activities_node']['field'] = 'reverse_field_user_hidden_activities_node';
  $handler->display->display_options['relationships']['reverse_field_user_hidden_activities_node']['relationship'] = 'field_activities_target_id';
  /* Field: Taxonomy term: Activities */
  $handler->display->display_options['fields']['field_activities']['id'] = 'field_activities';
  $handler->display->display_options['fields']['field_activities']['table'] = 'field_data_field_activities';
  $handler->display->display_options['fields']['field_activities']['field'] = 'field_activities';
  $handler->display->display_options['fields']['field_activities']['label'] = 'name';
  $handler->display->display_options['fields']['field_activities']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_activities']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_activities']['delta_offset'] = '0';
  /* Field: Content: Activity Type Completed */
  $handler->display->display_options['fields']['field_activity_type']['id'] = 'field_activity_type';
  $handler->display->display_options['fields']['field_activity_type']['table'] = 'field_data_field_activity_type';
  $handler->display->display_options['fields']['field_activity_type']['field'] = 'field_activity_type';
  $handler->display->display_options['fields']['field_activity_type']['relationship'] = 'field_activities_target_id';
  $handler->display->display_options['fields']['field_activity_type']['label'] = 'activity_type';
  $handler->display->display_options['fields']['field_activity_type']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'field_activities_target_id';
  $handler->display->display_options['fields']['nid']['label'] = 'nid';
  /* Field: Content: Activity Duration Start (Minutes) */
  $handler->display->display_options['fields']['field_activity_duration_start']['id'] = 'field_activity_duration_start';
  $handler->display->display_options['fields']['field_activity_duration_start']['table'] = 'field_data_field_activity_duration_start';
  $handler->display->display_options['fields']['field_activity_duration_start']['field'] = 'field_activity_duration_start';
  $handler->display->display_options['fields']['field_activity_duration_start']['relationship'] = 'field_activities_target_id';
  $handler->display->display_options['fields']['field_activity_duration_start']['label'] = 'activity_dur_start';
  $handler->display->display_options['fields']['field_activity_duration_start']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Activity Duration End (Minutes) */
  $handler->display->display_options['fields']['field_activity_duration_end']['id'] = 'field_activity_duration_end';
  $handler->display->display_options['fields']['field_activity_duration_end']['table'] = 'field_data_field_activity_duration_end';
  $handler->display->display_options['fields']['field_activity_duration_end']['field'] = 'field_activity_duration_end';
  $handler->display->display_options['fields']['field_activity_duration_end']['relationship'] = 'field_activities_target_id';
  $handler->display->display_options['fields']['field_activity_duration_end']['label'] = 'activity_dur_end';
  $handler->display->display_options['fields']['field_activity_duration_end']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Taxonomy term: Class */
  $handler->display->display_options['fields']['field_class']['id'] = 'field_class';
  $handler->display->display_options['fields']['field_class']['table'] = 'field_data_field_class';
  $handler->display->display_options['fields']['field_class']['field'] = 'field_class';
  $handler->display->display_options['fields']['field_class']['label'] = 'class';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'goal_name';
  /* Sort criterion: Content: Activity Duration Start (Minutes) (field_activity_duration_start) */
  $handler->display->display_options['sorts']['field_activity_duration_start_value']['id'] = 'field_activity_duration_start_value';
  $handler->display->display_options['sorts']['field_activity_duration_start_value']['table'] = 'field_data_field_activity_duration_start';
  $handler->display->display_options['sorts']['field_activity_duration_start_value']['field'] = 'field_activity_duration_start_value';
  $handler->display->display_options['sorts']['field_activity_duration_start_value']['relationship'] = 'field_activities_target_id';
  /* Sort criterion: Content: Activity Duration End (Minutes) (field_activity_duration_end) */
  $handler->display->display_options['sorts']['field_activity_duration_end_value']['id'] = 'field_activity_duration_end_value';
  $handler->display->display_options['sorts']['field_activity_duration_end_value']['table'] = 'field_data_field_activity_duration_end';
  $handler->display->display_options['sorts']['field_activity_duration_end_value']['field'] = 'field_activity_duration_end_value';
  $handler->display->display_options['sorts']['field_activity_duration_end_value']['relationship'] = 'field_activities_target_id';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['relationship'] = 'field_activities_target_id';
  /* Contextual filter: Content: Author uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'reverse_field_user_hidden_activities_node';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['not'] = TRUE;
  /* Contextual filter: Taxonomy term: Term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['break_phrase'] = TRUE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'eight_dimensions_of_wellness' => 'eight_dimensions_of_wellness',
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'field_activities_target_id';
  $handler->display->display_options['filters']['title']['operator'] = 'not empty';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Taxonomy term: Term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['break_phrase'] = TRUE;
  $handler->display->display_options['path'] = 'mobile/app/wellness-goal-activities-list/%';
  $export['mobile_app_wellness_goal_activities_list'] = $view;

  $view = new view();
  $view->name = 'mobile_app_wellness_goal_resources_list';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Mobile App: Wellness Goal Resources List';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Wellness Goal Resources List';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    2 => '2',
    3 => '3',
    4 => '4',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'views_json';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_resources_target_id']['id'] = 'field_resources_target_id';
  $handler->display->display_options['relationships']['field_resources_target_id']['table'] = 'field_data_field_resources';
  $handler->display->display_options['relationships']['field_resources_target_id']['field'] = 'field_resources_target_id';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_resources_taxonomy_term']['id'] = 'reverse_field_resources_taxonomy_term';
  $handler->display->display_options['relationships']['reverse_field_resources_taxonomy_term']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_resources_taxonomy_term']['field'] = 'reverse_field_resources_taxonomy_term';
  $handler->display->display_options['relationships']['reverse_field_resources_taxonomy_term']['relationship'] = 'field_resources_target_id';
  /* Field: Taxonomy term: Class */
  $handler->display->display_options['fields']['field_class']['id'] = 'field_class';
  $handler->display->display_options['fields']['field_class']['table'] = 'field_data_field_class';
  $handler->display->display_options['fields']['field_class']['field'] = 'field_class';
  $handler->display->display_options['fields']['field_class']['label'] = 'class';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'goal_name';
  /* Field: Taxonomy term: Resources */
  $handler->display->display_options['fields']['field_resources']['id'] = 'field_resources';
  $handler->display->display_options['fields']['field_resources']['table'] = 'field_data_field_resources';
  $handler->display->display_options['fields']['field_resources']['field'] = 'field_resources';
  $handler->display->display_options['fields']['field_resources']['label'] = 'name';
  $handler->display->display_options['fields']['field_resources']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_resources']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_resources']['delta_offset'] = '0';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'field_resources_target_id';
  $handler->display->display_options['fields']['nid']['label'] = 'nid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_resources_target_id';
  $handler->display->display_options['fields']['title']['label'] = 'title';
  /* Field: Content: Resource Author */
  $handler->display->display_options['fields']['field_resource_author']['id'] = 'field_resource_author';
  $handler->display->display_options['fields']['field_resource_author']['table'] = 'field_data_field_resource_author';
  $handler->display->display_options['fields']['field_resource_author']['field'] = 'field_resource_author';
  $handler->display->display_options['fields']['field_resource_author']['relationship'] = 'field_resources_target_id';
  $handler->display->display_options['fields']['field_resource_author']['label'] = 'resource_author';
  /* Field: Field: Body */
  $handler->display->display_options['fields']['field_body']['id'] = 'field_body';
  $handler->display->display_options['fields']['field_body']['table'] = 'field_data_field_body';
  $handler->display->display_options['fields']['field_body']['field'] = 'field_body';
  $handler->display->display_options['fields']['field_body']['relationship'] = 'field_resources_target_id';
  $handler->display->display_options['fields']['field_body']['label'] = 'body';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['relationship'] = 'field_resources_target_id';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Author uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'reverse_field_user_hidden_activities_node';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['not'] = TRUE;
  /* Contextual filter: Taxonomy term: Term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['break_phrase'] = TRUE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'eight_dimensions_of_wellness' => 'eight_dimensions_of_wellness',
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'field_resources_target_id';
  $handler->display->display_options['filters']['title']['operator'] = 'not empty';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Taxonomy term: Term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['break_phrase'] = TRUE;
  $handler->display->display_options['path'] = 'mobile/app/wellness-goal-resources-list/%';
  $export['mobile_app_wellness_goal_resources_list'] = $view;

  $view = new view();
  $view->name = 'rules_view_get_random_push_notification';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Rules View - Get Random Push Notification ';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Wellness Goal Relation */
  $handler->display->display_options['fields']['field_wellness_goal_relation']['id'] = 'field_wellness_goal_relation';
  $handler->display->display_options['fields']['field_wellness_goal_relation']['table'] = 'field_data_field_wellness_goal_relation';
  $handler->display->display_options['fields']['field_wellness_goal_relation']['field'] = 'field_wellness_goal_relation';
  $handler->display->display_options['fields']['field_wellness_goal_relation']['label'] = '';
  $handler->display->display_options['fields']['field_wellness_goal_relation']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_wellness_goal_relation']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Push Notification Message (Used In Push Notification) */
  $handler->display->display_options['fields']['field_push_notification_message']['id'] = 'field_push_notification_message';
  $handler->display->display_options['fields']['field_push_notification_message']['table'] = 'field_data_field_push_notification_message';
  $handler->display->display_options['fields']['field_push_notification_message']['field'] = 'field_push_notification_message';
  $handler->display->display_options['fields']['field_push_notification_message']['label'] = '';
  $handler->display->display_options['fields']['field_push_notification_message']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_push_notification_message']['type'] = 'text_plain';
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  /* Contextual filter: Content: Wellness Goal Relation (field_wellness_goal_relation) */
  $handler->display->display_options['arguments']['field_wellness_goal_relation_target_id']['id'] = 'field_wellness_goal_relation_target_id';
  $handler->display->display_options['arguments']['field_wellness_goal_relation_target_id']['table'] = 'field_data_field_wellness_goal_relation';
  $handler->display->display_options['arguments']['field_wellness_goal_relation_target_id']['field'] = 'field_wellness_goal_relation_target_id';
  $handler->display->display_options['arguments']['field_wellness_goal_relation_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_wellness_goal_relation_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_wellness_goal_relation_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_wellness_goal_relation_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_wellness_goal_relation_target_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_wellness_goal_relation_target_id']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_wellness_goal_relation_target_id']['validate_options']['vocabularies'] = array(
    'eight_dimensions_of_wellness' => 'eight_dimensions_of_wellness',
  );
  $handler->display->display_options['arguments']['field_wellness_goal_relation_target_id']['validate']['fail'] = 'ignore';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'push_notification' => 'push_notification',
  );

  /* Display: Random Push */
  $handler = $view->new_display('panel_pane', 'Random Push', 'panel_pane_1');
  $export['rules_view_get_random_push_notification'] = $view;

  return $export;
}
