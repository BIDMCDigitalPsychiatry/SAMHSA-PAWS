<header id="header" class="header -secondary">
  <?php if (isset($page['headersecondarytop']) && !empty($page['headersecondarytop'])): ?>
    <?php print render($page['headersecondarytop']); ?>
  <?php endif; ?>
  <?php if (isset($page['headersecondarybot']) && !empty($page['headersecondarybot'])): ?>
    <?php print render($page['headersecondarybot']); ?>
  <?php endif; ?>
</header>

<div id="page" class="page -secondary">
  <?php if ($messages): ?>
  <div id="console" class="section p-top-small clearfix"><?php print $messages; ?></div>
  <?php endif; ?>
  <div id="content" class="clearfix">
    <div class="element-invisible">
      <a id="main-content"></a>
    </div>
    <?php print render($page['content']); ?>
  </div>
</div>

<footer id="footer" class="footer -secondary">
  <?php if (isset($page['footersecondary']) && !empty($page['footersecondary'])): ?>
    <?php print render($page['footersecondary']); ?>
  <?php endif; ?>
</footer>