<?php
/**
 * @file
 * feature_rules.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function feature_rules_default_rules_configuration() {
  $items = array();
  $items['rules_new_user_create_user_settings'] = entity_import('rules_config', '{ "rules_new_user_create_user_settings" : {
      "LABEL" : "New User - Create User Settings",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Mobile App", "User" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "user_insert" : [], "user_login" : [] },
      "IF" : [
        { "data_is_empty" : { "data" : [ "account:field-user-settings-node" ] } }
      ],
      "DO" : [
        { "entity_create" : {
            "USING" : {
              "type" : "node",
              "param_type" : "mobile_app_user_settings",
              "param_title" : "[account:name] - [account:uid]",
              "param_author" : [ "account" ]
            },
            "PROVIDE" : { "entity_created" : { "new_user_settings_created" : "Created User Settings" } }
          }
        },
        { "entity_save" : { "data" : [ "new-user-settings-created" ], "immediate" : "1" } },
        { "data_set" : {
            "data" : [ "account:field-user-settings-node" ],
            "value" : [ "new-user-settings-created" ]
          }
        }
      ]
    }
  }');
  $items['rules_push_notifications_schedule_off_'] = entity_import('rules_config', '{ "rules_push_notifications_schedule_off_" : {
      "LABEL" : "Push Notifications - Schedule (Off)",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Push Notifications" ],
      "REQUIRES" : [ "rules", "rules_scheduler", "custom_rules_is" ],
      "ON" : { "custom_rules_push_notification_schedule_off" : [] },
      "DO" : [
        { "drupal_message" : { "message" : "Push Notifications Schedule has been turned (OFF)." } },
        { "schedule_delete" : { "component" : "rules_send_push_notification_reschedule" } }
      ]
    }
  }');
  $items['rules_push_notifications_schedule_on_'] = entity_import('rules_config', '{ "rules_push_notifications_schedule_on_" : {
      "LABEL" : "Push Notifications - Schedule (On)",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Push Notifications" ],
      "REQUIRES" : [ "rules", "custom_rules_is", "rules_scheduler" ],
      "ON" : { "custom_rules_push_notification_schedule_on" : [] },
      "DO" : [
        { "drupal_message" : { "message" : "Push Notifications Schedule has been turned (ON)." } },
        { "cr_set_current_push_scheduled_dimension_term" : { "PROVIDE" : { "dimension_term_id_current" : { "dimension_term_id_current" : "Current Scheduled Dimension Term ID." } } } },
        { "schedule" : {
            "component" : "rules_send_push_notification_reschedule",
            "date" : "+1 hour",
            "identifier" : "Push Notification || Dimension: [dimension-term-id-current:value]"
          }
        }
      ]
    }
  }');
  $items['rules_send_push_notification_reschedule'] = entity_import('rules_config', '{ "rules_send_push_notification_reschedule" : {
      "LABEL" : "Send Push Notification \\u0026 Reschedule",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "Push Notifications" ],
      "REQUIRES" : [ "custom_rules_is", "rules", "push_notifications", "rules_scheduler" ],
      "DO" : [
        { "cr_set_current_push_scheduled_dimension_term" : { "PROVIDE" : { "dimension_term_id_current" : { "dimension_term_id_current" : "Current Scheduled Dimension Term ID." } } } },
        { "cr_get_random_push_notification_content" : { "PROVIDE" : {
              "push_notification_nid" : { "push_notification_nid" : "Push Notification - NID" },
              "push_notification_title" : { "push_notification_title" : "Push Notification - Title" },
              "push_notification_relation" : { "push_notification_relation" : "Push Notification - Relation" },
              "push_notification_message" : { "push_notification_message" : "Push Notification - Message" }
            }
          }
        },
        { "push_notifications_send_message_bulk" : { "message" : "[push-notification-message:value]" } },
        { "cr_set_next_push_scheduled_dimension_term" : { "PROVIDE" : { "dimension_term_id_next" : { "dimension_term_id_next" : "Next Scheduled Dimension Term ID." } } } },
        { "schedule" : {
            "component" : "rules_send_push_notification_reschedule",
            "date" : "+4 days",
            "identifier" : "Push Notification || Dimension: [dimension-term-id-next:value]"
          }
        }
      ]
    }
  }');
  $items['rules_user_removed_delete_settings'] = entity_import('rules_config', '{ "rules_user_removed_delete_settings" : {
      "LABEL" : "User Removed - Delete Settings",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Mobile App", "User" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "user_delete" : [] },
      "DO" : [
        { "entity_delete" : { "data" : [ "account:field-user-settings-node" ] } }
      ]
    }
  }');
  return $items;
}
