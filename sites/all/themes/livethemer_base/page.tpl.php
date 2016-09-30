<?php
/**
 * @file
 * Theme implementation to display a single Drupal page.
 *
 * @see modules/system/page.tpl.php
 *
 * regions[pre_header]     = pre-header
 * regions[header]         = Header
 * regions[pre_content]    = pre content 
 * regions[highlighted]    = highlighted
 * regions[help]           = help
 * regions[content]        = Content
 * regions[post_content]   = post content
 * regions[sidebar_first]  = First sidebar
 * regions[sidebar_second] = Second sidebar
 * regions[footer]         = Footer
 * regions[post_footer]    = Post-footer
 */ 
?>
  <div id="page-wrapper"><div id="page">
    <?php if ($page['pre_header']): ?>
    <div id="pre_header"><div class="section clearfix">
      <?php print render($page['pre_header']); ?>
    </div></div>
    <?php endif; ?>
    
    <div id="header"><div class="section clearfix">
      <?php if ($logo): ?>
        <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" id="logo">
          <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
        </a>
      <?php endif; ?>

      <?php if ($site_name || $site_slogan): ?>
        <div id="name-and-slogan">
          <?php if ($site_name): ?>
            <?php if ($title): ?>
              <div id="site-name"><strong>
                <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home"><span><?php print $site_name; ?></span></a>
              </strong></div>
            <?php else: /* Use h1 when the content title is empty */ ?>
              <h1 id="site-name">
                <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home"><span><?php print $site_name; ?></span></a>
              </h1>
            <?php endif; ?>
          <?php endif; ?>

          <?php if ($site_slogan): ?>
            <div id="site-slogan"><?php print $site_slogan; ?></div>
          <?php endif; ?>
        </div> <!-- /#name-and-slogan -->
      <?php endif; ?>

      <?php print render($page['header']); ?>

    </div></div> <!-- /.section /#header -->

    <div id="main-wrapper"><div id="main" class="clearfix">
	    <?php if ($breadcrumb): ?>
	      <div id="breadcrumb"><?php print $breadcrumb; ?></div>
	    <?php endif; ?>

      <?php if ($messages): ?>
      <div id="set-messages">
        <?php print $messages; ?>
      </div>
      <?php endif; ?>
      <div id="pre-columns">
        <?php print render($page['pre_columns']) ?>
      </div>
      
      <div class="clearfix">
	      <div id="content" class="column clearfix"><div class="section">
	        <a id="main-content"></a>
	        <?php print render($title_prefix); ?>
	        <?php if ($title): ?><h1 class="title" id="page-title"><?php print $title; ?></h1><?php endif; ?>
	        <?php print render($title_suffix); ?>
	        <?php if ($tabs): ?><div class="tabs"><?php print render($tabs); ?></div><?php endif; ?>
	        <?php print render($page['help']); ?>
	        <?php if ($action_links): ?><ul class="action-links"><?php print render($action_links); ?></ul><?php endif; ?>
	        <?php if ($page['pre_content']): ?>
	        <div id="pre-content"><?php print render($page['pre_content']); ?></div>
	        <?php endif; ?>
	        
	        <?php print render($page['content']); ?>
	        
	        <?php if ($page['post_content']): ?>
	        <div id="post-content"><?php print render($page['post_content']); ?></div>
	        <?php endif; ?>
	        <?php print $feed_icons; ?>
	      </div></div> <!-- /.section, /#content -->
	
	      <?php if ($page['sidebar_first']): ?>
	        <div id="sidebar-first" class="column sidebar"><div class="section">
	          <?php print render($page['sidebar_first']); ?>
	        </div></div> <!-- /.section, /#sidebar-first -->
	      <?php endif; ?>
	
	      <?php if ($page['sidebar_second']): ?>
	        <div id="sidebar-second" class="column sidebar"><div class="section">
	          <?php print render($page['sidebar_second']); ?>
	        </div></div> <!-- /.section, /#sidebar-second -->
	      <?php endif; ?>
			</div>
			
      <div id="post-columns" class="clearfix">
        <?php print render($page['post_columns']) ?>
      </div>

    </div></div> <!-- /#main, /#main-wrapper -->

  	<?php if ($page['footer']): ?>
    <div id="footer" class="clearfix"><div class="section">
      <?php print render($page['footer']); ?>
    </div></div> <!-- /.section, /#footer -->
  	<?php endif; ?>
  </div></div> <!-- /#page, /#page-wrapper -->
    
  <?php if ($page['post_footer']): ?>
  <div id="post-footer" class="clearfix">
  	<?php print render($page['post_footer']); ?>
  </div>
  <?php endif; ?>
