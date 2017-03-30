<?php
/**
 * @file
 * Views Galleriffic theme wrapper.
 *
 * @ingroup views_templates
 */

?>
<div id="galleriffic" class="clearfix">
  <div id="thumbs" class="navigation">
    <a class="pageLink prev" style="visibility: hidden;" href="#" title="Previous Page"></a>
    <ul class="thumbs noscript">
      <?php foreach ($rows as $row): ?>
        <?php print $row?>
      <?php endforeach; ?>
    </ul>
    <a class="pageLink next" style="visibility: hidden;" href="#" title="Next Page"></a>
  </div>
  <div id="gallery" class="content">
    <div id="controls" class="controls"></div>
    <div id="slideshow-container">
      <div id="loading" class="loader"></div>
      <div id="slideshow"></div>
    </div>
    <div id="caption" class="caption-container"></div>
  </div>
</div>
