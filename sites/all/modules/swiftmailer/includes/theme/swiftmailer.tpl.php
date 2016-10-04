<?php
/**
 * @file
 * The default template file for e-mails.
 */
?>
<style type="text/css">
table tr td {
  font-family: Arial;
  font-size: 12px;
}
</style>

<div>
  <table width="800px" cellpadding="0" cellspacing="0">
    <tr>
      <td>
        <div style="padding: 0px 0px 0px 0px;">
          <?php print $body; ?>
        </div>
      </td>
    </tr>
  </table>
</div>
