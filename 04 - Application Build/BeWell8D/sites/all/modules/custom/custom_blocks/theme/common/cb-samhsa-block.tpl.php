<?php
//Available Variables
// $global_user == $user;
// $base_path == base_path();
// $path_to_theme == path_to_theme();
// $logo_path == path to logo image;
// $logo_image == logo image html
// $logo_link == drupal linked logo image;
?>
<div class="section p-top-large p-btm-large  samhsa-block">
  <div class="row-12 dividers-v">
    <div class="col-7 wysiwyg samhsa-block-text  equalheight">
      <p><?php print $text; ?></p>
    </div>
    <div class="col-5  samhsa-block-logo  equalheight">
      <?php print $logo_link; ?>
    </div>
  </div>
</div>
