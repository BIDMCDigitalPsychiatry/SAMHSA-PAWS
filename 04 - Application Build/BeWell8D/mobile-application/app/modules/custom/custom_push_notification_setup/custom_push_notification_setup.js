/**
 * Implements hook_push_notifications_receive().
 **/
function custom_push_notification_setup_push_notifications_receive(data) {

  // data.message
  // data.title
  // data.count
  // data.sound
  // data.image
  // data.additionalData

  // Display the push notification.
  var pushNotEnabled = variable_get('app_settings_enable_push_notifications', 1);
  if (pushNotEnabled == 1) {
    drupalgap_alert(data.message, {
      title: drupalgap.settings.title,
      buttonName: 'OK'
    });
  }

}