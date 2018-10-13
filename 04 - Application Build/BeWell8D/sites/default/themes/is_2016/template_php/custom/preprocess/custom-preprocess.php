<?php

/* Custom Preprocess */
function _custom_preprocess(&$variables, $type) {
  switch ($type) {
    case 'html':
      include (path_to_theme()."/template_php/custom/preprocess/html/pp-html.php");
      break;
    case 'page':
      include (path_to_theme()."/template_php/custom/preprocess/page/pp-page.php");
      break;
    case 'maintenance_page':
      //include (path_to_theme()."/template_php/custom/preprocess/maintenance-page/pp-maintenance-page.php");
      break;
    case 'entity':
      //include (path_to_theme()."/template_php/custom/preprocess/entity/pp-entity.php");
      break;
    case 'node':
      //include (path_to_theme()."/template_php/custom/preprocess/node/pp-node.php");
      break;
    case 'user_profile':
      //include (path_to_theme()."/template_php/custom/preprocess/user/pp-user-profile.php");
      break;
    case 'username':
      //include (path_to_theme()."/template_php/custom/preprocess/user/pp-username.php");
      break;
    case 'user_picture':
      //include (path_to_theme()."/template_php/custom/preprocess/user/pp-user-picture.php");
      break;
    case 'views_view':
      //include (path_to_theme()."/template_php/custom/preprocess/views/pp-views-view.php");
      break;
    case 'views_view_fields':
      //include (path_to_theme()."/template_php/custom/preprocess/views/pp-views-view-fields.php");
      break;
    case 'views_view_field':
      //include (path_to_theme()."/template_php/custom/preprocess/views/pp-views-view-field.php");
      break;
    case 'views_exposed_form':
      //include (path_to_theme()."/template_php/custom/preprocess/views/pp-views-exposed-form.php");
      break;
    case 'taxonomy_term':
      //include (path_to_theme()."/template_php/custom/preprocess/taxonomy/pp-taxonomy-term.php");
      break;
    case 'region':
      //include (path_to_theme()."/template_php/custom/preprocess/region/pp-region.php");
      break;
    case 'block':
      //include (path_to_theme()."/template_php/custom/preprocess/block/pp-block.php");
      break;
    case 'comment_wrapper':
      //include (path_to_theme()."/template_php/custom/preprocess/comment/pp-comment_wrapper.php");
      break;
    case 'comment':
      //include (path_to_theme()."/template_php/custom/preprocess/comment/pp-comment.php");
      break;
    case 'field':
      //include (path_to_theme()."/template_php/custom/preprocess/field/pp-field.php");
      break;
    case 'image':
      //include (path_to_theme()."/template_php/custom/preprocess/image/pp-image.php");
      break;
    case 'mimemail_message':
      //include (path_to_theme()."/template_php/custom/preprocess/mimemail/pp-mimemail-message.php");
      break;
  }
}









