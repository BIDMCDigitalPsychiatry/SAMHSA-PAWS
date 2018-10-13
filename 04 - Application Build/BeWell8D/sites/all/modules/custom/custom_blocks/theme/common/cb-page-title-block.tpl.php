<?php
$current_path = current_path();
$path_alias = drupal_lookup_path('alias',$current_path);

if($path_alias){
  $path = explode('/', $path_alias);
} else {
  $path = explode('/', $current_path);
}
?>
<?php switch($path[0]): 
case 'SOMETHINGALTERNATE': ?>
  <h1 class="h1 <?php print $special_class; ?> p-btm page-title"><?php print $page_title; ?></h1>
  <?php break; ?>
<?php case 'SOMETHINGALTERNATE2': ?>
  <h1 class="h1 <?php print $special_class; ?> p-btm page-title"><?php print $page_title; ?></h1>
  <?php break; ?>
<?php default: ?>
  <h1 class="h1 <?php print $special_class; ?> p-btm page-title"><?php print $page_title; ?></h1>
  <?php break; ?>
<?php endswitch; ?>


