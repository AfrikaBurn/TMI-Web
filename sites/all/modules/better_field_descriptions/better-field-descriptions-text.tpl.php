<?php

/**
 * @file
 * Better field descriptions theme implementation of a pure text description.
 *
 * Available variables:
 * - $variables['label']: The label of the description.
 * - $variables['description']: The description itself.
 */
?>
<?php if (empty($variables['label']) == FALSE): ?>
  <div class="better-descriptions label"><?php print ($variables['label']); ?></div>
<?php endif; ?>
<div class="better-descriptions description"><?php print ($variables['description']); ?></div>
