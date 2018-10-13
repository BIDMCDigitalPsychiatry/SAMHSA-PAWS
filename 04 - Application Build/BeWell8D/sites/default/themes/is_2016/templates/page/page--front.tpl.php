<header id="header" class="header -front">
  <?php if (isset($page['headerfront']) && !empty($page['headerfront'])): ?>
    <?php print render($page['headerfront']); ?>
  <?php endif; ?>
</header>

<div id="page" class="page -front">
  <div id="content" class="clearfix">
    <div class="element-invisible">
      <a id="main-content"></a>
    </div>
    <?php if ($messages): ?>
    <div id="console" class="clearfix p-top-small section"><?php print $messages; ?></div>
    <?php endif; ?>
    <?php print render($page['content']); ?>
  </div>
</div>

<footer id="footer" class="footer -front">
  <?php if (isset($page['footerfront']) && !empty($page['footerfront'])): ?>
    <?php print render($page['footerfront']); ?>
  <?php endif; ?>
</footer>
