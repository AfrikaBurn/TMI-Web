<?php

/**
 * @file
 * Default theme implementation to display a single Drupal page.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/bartik.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the
 *   site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title: The page title, for use in the actual HTML content.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * - $messages: HTML for status and error messages. Should be displayed
 *   prominently.
 * - $tabs (array): Tabs linking to any sub-pages beneath the current page
 *   (e.g., the view and edit tabs when displaying a node).
 * - $action_links (array): Actions local to the page, such as 'Add menu' on the
 *   menu administration interface.
 * - $feed_icons: A string of all feed icons for the current page.
 * - $node: The node object, if there is an automatically-loaded node
 *   associated with the page, and the node ID is the second argument
 *   in the page's path (e.g. node/12345 and node/12345/revisions, but not
 *   comment/reply/12345).
 *
 * Regions:
 * - $page['help']: Dynamic help text, mostly for admin pages.
 * - $page['highlighted']: Items for the highlighted content region.
 * - $page['content']: The main content of the current page.
 * - $page['sidebar_first']: Items for the first sidebar.
 * - $page['sidebar_second']: Items for the second sidebar.
 * - $page['header']: Items for the header region.
 * - $page['footer']: Items for the footer region.
 *
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see template_process()
 */
    global $user;
    function afrikaburn_css_alter(&$css) {
            // Remove defaults.css file.
            //unset($css['misc/ui/jquery.ui.core.css']);
            //unset($css['misc/ui/jquery.ui.core.css']);
            //unset($css['misc/ui/jquery.ui.theme.css']);
            //unset($css['misc/ui/jquery.ui.datepicker.css']);
            unset($css['modules/system/system.base.css']);
            unset($css['modules/system/system.base.css']);
            unset($css['modules/system/system.menus.css']);
            unset($css['modules/system/system.messages.css']);
            unset($css['modules/system/system.theme.css']);
            unset($css['modules/overlay/overlay-parent.css']);
            unset($css['modules/comment/comment.css']);
            unset($css['modules/field/theme/field.css']);
            unset($css['modules/node/node.css']);
            unset($css['modules/search/search.css']);
            unset($css['modules/user/user.css']);
            unset($css['modules/shortcut/shortcut.css']);
            unset($css['modules/toolbar/toolbar.css']);
            unset($css['modules/poll/poll.css']);
            unset($css['modules/forum/forum.css']);
            unset($css['modules/file/file.css']);
            unset($css['modules/image/image.css']);
            unset($css['sites/all/modules/ctools/css/ctools.css']);
            unset($css['sites/all/modules/panels/css/panels.css']);
            unset($css['sites/all/modules/toolbar_hide/toolbar_hide.css']);
            unset($css['sites/all/modules/date/date_api/date.css']); 
            unset($css['sites/all/modules/date/date_popup/themes/datepicker.1.7.css']);
            unset($css['sites/all/modules/date/date_repeat_field/date_repeat_field.css']);
            unset($css['sites/all/modules/livethemer/css/livethemer.css']);
            unset($css['sites/all/modules/logintoboggan/logintoboggan.css']);
            unset($css['sites/all/modules/views/css/views.css']);
            unset($css['sites/all/modules/date/date_popup/themes/jquery.timeentry.css']);
            unset($css['sites/all/modules/ckeditor/css/ckeditor.css']);
            unset($css['sites/all/modules/field_group/field_group.field_ui.css']);
        }
?>

 <div id="top-bar">
        <div class="container-2">
            <div class="container-1">
                <div class='logo-container'>
                      <a href="http://www.afrikaburn.com">
                          <img src="<?php print base_path() . path_to_theme(); ?>/assets/images/date-badge-2017.png" />
                      </a>
                  </div>
            </div>
            <?php print render($page['create-tickets']); ?>
            <div class='user-menu'>
               <?php print render($page['user-menu']); ?>
            </div>
            <div class='user-greeting'>
                  <?php print render($page['user-greeting']); ?>
                  <?php if($user->uid > 0): ?>
                      <div class="user-menu-icon">
                          <span class="user-icon-bar"></span>
                          <span class="user-icon-bar"></span>
                          <span class="user-icon-bar"></span>
                      </div>
                <?php endif; ?>
            </div>
                <div class='social-media-links hide-below-979px'>
                    <div class='sm-link twitter'>
                        <a href='https://www.twitter.com/afrikaburn' title='Afrikaburn on Twitter' target='_blank'></a>
                    </div>
                    <div class='sm-link facebook'>
                        <a href='https://www.facebook.com/afrikaburn' title='Afrikaburn on Facebook' target='_blank'></a>
                    </div>
                </div>
        </div>
    </div>
    <div class="container-3 show-below-979px" id="mobile-menu-bar">
        <div class="container-2">
            <div class="container-1">
                <div class= "row-fluid navbar-outer">
                  <nav class="navbar">
                      <div class="navbar-inner">
                          <div class="container-fluid">
                              <a class="btn btn-navbar" data-toggle="collapse" data-target="#main-nav">
                              <span class="icon-bar"></span> 
                              <span class="icon-bar"></span> 
                              <span class="icon-bar"></span>
                              </a>
                              <div class="nav-collapse collapse" id="main-nav">
                                <?php print render($page['main-menu']); ?>
                            </div>
                        </div>
                      </div>
                  </div>
                </nav>
                <div class= "clear"></div>
            </div>
        </div>
    </div>
    <div id="header">
        <div class="container-2">
            <div class="container-1">
                <div class="banners">
                    <div class="dummy">
                        <img src="<?php print base_path() . path_to_theme(); ?>/assets/images/banners/dummy.png" />
                    </div>
                    <div class="slide current first">
                        <img src="<?php print base_path() . path_to_theme(); ?>/assets/images/banners/daisies-sean-f.jpg" />
                    </div>
                    <div class="slide">
                        <img src="<?php print base_path() . path_to_theme(); ?>/assets/images/banners/death-ride-2012b.jpg" />
                    </div>
                    <div class="slide">
                        <img src="<?php print base_path() . path_to_theme(); ?>/assets/images/banners/earth-pods-simon-o.jpg" />
                    </div>
                    <div class="slide">
                        <img src="<?php print base_path() . path_to_theme(); ?>/assets/images/banners/flames-clan-brendon-salzer.jpg" />
                    </div>
                    <div class="slide">
                        <img src="<?php print base_path() . path_to_theme(); ?>/assets/images/banners/origami-2012d.jpg" />
                    </div>
                    <div class="slide">
                        <img src="<?php print base_path() . path_to_theme(); ?>/assets/images/banners/panorama-sean-f.jpg" />
                    </div>
                    <div class="slide">
                        <img src="<?php print base_path() . path_to_theme(); ?>/assets/images/banners/sanclan-2012f.jpg" />
                    </div>
                    <div class="slide">
                        <img src="<?php print base_path() . path_to_theme(); ?>/assets/images/banners/stasie-kafee-2012a.jpg" />
                    </div>
                    <div class="slide">
                        <img src="<?php print base_path() . path_to_theme(); ?>/assets/images/banners/sunset-sean-f.jpg" />
                    </div>
                    <div class="slide">
                        <img src="<?php print base_path() . path_to_theme(); ?>/assets/images/banners/temple-2014-brendon-salzer.jpg" />
                    </div>
                </div>
            </div>
        </div>  
    </div>
    <div class= "clear"></div>
    <div class="container-3 hide-below-979px" id="menu-bar">
        <div class="container-2">
            <div class="container-1">
                <div class= "row-fluid navbar-outer">
                  <nav class="navbar">
                      <div class="navbar-inner">
                          <div class="container-fluid">
                              <div class="nav-collapse collapse" id="main-nav">
                                <?php print render($page['main-menu']); ?>
                            </div>
                        </div>
                      </div>
                  </div>
                </nav>
                <div class= "clear"></div>
            </div>
        </div>
    </div>
    <div class="container-3 show-below-979px" id="social-media-links-bar">
        <div class="container-2">
            <div class="container-1">
                <div class='social-media-links'>
                   <div class='sm-link twitter'>
                       <a href='https://www.twitter.com/afrikaburn' title='Afrikaburn on Twitter' target='_blank'></a>
                   </div>
                   <div class='sm-link facebook'>
                       <a href='https://www.facebook.com/afrikaburn' title='Afrikaburn on Facebook' target='_blank'></a>
                   </div>
                </div>
            </div>
            <div class='clr'></div>
        </div>
    </div>
    <section id="main-content-strip" class="container-3">
        <div class='container-2'>
            <div class='container-1'>
                    <?php print render($title_prefix); ?>
                    <?php if ($title): ?><h1><?php print $title; ?></h1><?php endif; ?>
                    <?php print render($title_suffix); ?>
                     <div class="body-content">
                        <?php print $messages; ?>
                        <?php if ($tabs): ?><div class="tabs"><?php print render($tabs); ?></div><?php endif; ?>
                        <?php print render($page['help']); ?>
                        <?php if ($action_links): ?><ul class="action-links"><?php print render($action_links); ?></ul><?php endif; ?>
                        <?php print render($page['content']); ?>           
                        <?php print $feed_icons; ?>
                    </div>
                <div class='clr'></div>
            </div>
        </div>
    </section>
    <?php /*
       <section id="social-icons">
            <div class='container-2'>
                <?php print render($page['social']); ?>
            </div>
        </section> 
    */ ?>
    <section id="footer">
        <div class='container-2'>
            <div class='container-1'>
                <h2>Volunteer now!</h2>
                <div class='body-content'>

                    <div class="blocks-container footer three-column">
                        <div class='block-outer'>
                            <div class='block-inner'>
                            <?php print render($page['footer_left']); ?>
                            </div>
                        </div>
                             <div class='block-outer'>
                                <div class='block-inner'>
                            <?php print render($page['footer_centre']); ?>
                            </div>
                        </div>
                             <div class='block-outer'>
                                <div class='block-inner'>
                                <div class="fb-page" data-href="https://www.facebook.com/afrikaburn/" data-tabs="timeline" data-height="322" data-small-header="true" data-adapt-container-width="true" data-hide-cover="false" data-show-facepile="false"><blockquote cite="https://www.facebook.com/afrikaburn/" class="fb-xfbml-parse-ignore"><a href="https://www.facebook.com/afrikaburn/">AfrikaBurn</a></blockquote></div>                                </div>
                        </div>
                    </div>
                    <div class='clr'></div>
                </div>
            </div>
        </div>
    </section>
    <section id="copyright">
        <div class="copyright-inner">
            <?php print render($page['copyright']); ?>
        </div>
    </section>