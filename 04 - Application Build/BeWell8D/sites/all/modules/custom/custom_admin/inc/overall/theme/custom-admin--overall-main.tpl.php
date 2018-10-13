<?php
print 'Custom Admin - Overall Main';
?>
<ul class="overall-main">
  <li><?php print l(
      t('Overall Settings'), 
      'admin/site-admin/overall', 
      array(
          'query' => drupal_get_destination(), 
          'attributes' => array(
              'title' => t('Administer Overall Site Settings.')
          ),
          'html' => TRUE
      )
  ); ?></li>
  <li><?php print l(
      t('Mobile App Settings'), 
      'admin/site-admin/mobile-app', 
      array(
          'query' => drupal_get_destination(), 
          'attributes' => array(
              'title' => t('Administer Mobile App Settings.')
          ),
          'html' => TRUE
      )
  ); ?></li>
</ul>