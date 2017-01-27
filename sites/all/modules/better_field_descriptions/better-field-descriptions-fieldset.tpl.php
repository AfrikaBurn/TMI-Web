<?php

/**
 * @file
 * Better field descriptions theme implementation of a fieldset description.
 *
 * Available variables:
 * - $variables['label']: The label of the description.
 * - $variables['description']: The description itself.
 */
?>
<fieldset class="collapsible collapsed form-wrapper better-descriptions">
  <legend><span class="fieldset-legend"><?php print ($variables['label']); ?></span></legend>
  <div class="fieldset-wrapper"><?php print ($variables['description']); ?></div>
</fieldset>
