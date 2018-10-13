<?php
# Patch file is relevant to the Drupal root directory. This example would refer
# a patch file that is located one directory up from the Drupal root. Define
# this option to save typing when running Drush commands for your project.
$options['patch-file'] = 'sites/all/drush/is_patches.make';


#Module Download dir
$command_specific['dl'] = array('destination' => 'sites/all/modules/contrib');