<?php
/**
 * @file
 * user_settings.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function user_settings_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_2017-theme-play:http://www.afrikaburn.com/the-event/2017-theme-play.
  $menu_links['main-menu_2017-theme-play:http://www.afrikaburn.com/the-event/2017-theme-play'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'http://www.afrikaburn.com/the-event/2017-theme-play',
    'router_path' => '',
    'link_title' => '2017 Theme Play',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_2017-theme-play:http://www.afrikaburn.com/the-event/2017-theme-play',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'main-menu_the-event:http://www.afrikaburn.com/the-event',
  );
  // Exported menu link: main-menu_about:http://www.afrikaburn.com/about.
  $menu_links['main-menu_about:http://www.afrikaburn.com/about'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'http://www.afrikaburn.com/about',
    'router_path' => '',
    'link_title' => 'About',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_about:http://www.afrikaburn.com/about',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: main-menu_afrikaburn-financials:http://www.afrikaburn.com/about/afrikaburn-financials.
  $menu_links['main-menu_afrikaburn-financials:http://www.afrikaburn.com/about/afrikaburn-financials'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'http://www.afrikaburn.com/about/afrikaburn-financials',
    'router_path' => '',
    'link_title' => 'AfrikaBurn Financials',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_afrikaburn-financials:http://www.afrikaburn.com/about/afrikaburn-financials',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
    'parent_identifier' => 'main-menu_about:http://www.afrikaburn.com/about',
  );
  // Exported menu link: main-menu_afrikaburn-images:http://www.afrikaburn.com/gallery/general-photo-galleries.
  $menu_links['main-menu_afrikaburn-images:http://www.afrikaburn.com/gallery/general-photo-galleries'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'http://www.afrikaburn.com/gallery/general-photo-galleries',
    'router_path' => '',
    'link_title' => 'AfrikaBurn Images',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_afrikaburn-images:http://www.afrikaburn.com/gallery/general-photo-galleries',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'main-menu_gallery:http://www.afrikaburn.com/gallery',
  );
  // Exported menu link: main-menu_afrikaburn-videos:http://www.afrikaburn.com/gallery/general-video-galleries.
  $menu_links['main-menu_afrikaburn-videos:http://www.afrikaburn.com/gallery/general-video-galleries'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'http://www.afrikaburn.com/gallery/general-video-galleries',
    'router_path' => '',
    'link_title' => 'AfrikaBurn Videos',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_afrikaburn-videos:http://www.afrikaburn.com/gallery/general-video-galleries',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'main-menu_gallery:http://www.afrikaburn.com/gallery',
  );
  // Exported menu link: main-menu_afrikaburn-year-round:http://www.afrikaburn.com/community/afrikaburn-year-round.
  $menu_links['main-menu_afrikaburn-year-round:http://www.afrikaburn.com/community/afrikaburn-year-round'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'http://www.afrikaburn.com/community/afrikaburn-year-round',
    'router_path' => '',
    'link_title' => 'AfrikaBurn Year Round',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_afrikaburn-year-round:http://www.afrikaburn.com/community/afrikaburn-year-round',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'main-menu_community:http://www.afrikaburn.com/community',
  );
  // Exported menu link: main-menu_binnekring-blog:http://www.afrikaburn.com/binnekringblog.
  $menu_links['main-menu_binnekring-blog:http://www.afrikaburn.com/binnekringblog'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'http://www.afrikaburn.com/binnekringblog',
    'router_path' => '',
    'link_title' => 'Binnekring Blog',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_binnekring-blog:http://www.afrikaburn.com/binnekringblog',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'main-menu_news:http://www.afrikaburn.com/news',
  );
  // Exported menu link: main-menu_community-links:http://www.afrikaburn.com/community/community-links.
  $menu_links['main-menu_community-links:http://www.afrikaburn.com/community/community-links'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'http://www.afrikaburn.com/community/community-links',
    'router_path' => '',
    'link_title' => 'Community Links',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_community-links:http://www.afrikaburn.com/community/community-links',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
    'parent_identifier' => 'main-menu_community:http://www.afrikaburn.com/community',
  );
  // Exported menu link: main-menu_community:http://www.afrikaburn.com/community.
  $menu_links['main-menu_community:http://www.afrikaburn.com/community'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'http://www.afrikaburn.com/community',
    'router_path' => '',
    'link_title' => 'Community',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_community:http://www.afrikaburn.com/community',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
  );
  // Exported menu link: main-menu_contact:http://www.afrikaburn.com/participation-forms/contact.
  $menu_links['main-menu_contact:http://www.afrikaburn.com/participation-forms/contact'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'http://www.afrikaburn.com/participation-forms/contact',
    'router_path' => '',
    'link_title' => 'Contact',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_contact:http://www.afrikaburn.com/participation-forms/contact',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -44,
    'customized' => 1,
  );
  // Exported menu link: main-menu_dpw:http://www.afrikaburn.com/dpw.
  $menu_links['main-menu_dpw:http://www.afrikaburn.com/dpw'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'http://www.afrikaburn.com/dpw',
    'router_path' => '',
    'link_title' => 'DPW',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_dpw:http://www.afrikaburn.com/dpw',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'parent_identifier' => 'main-menu_community:http://www.afrikaburn.com/community',
  );
  // Exported menu link: main-menu_faq:http://www.afrikaburn.com/the-event/faq.
  $menu_links['main-menu_faq:http://www.afrikaburn.com/the-event/faq'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'http://www.afrikaburn.com/the-event/faq',
    'router_path' => '',
    'link_title' => 'FAQ',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_faq:http://www.afrikaburn.com/the-event/faq',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -43,
    'customized' => 1,
    'parent_identifier' => 'main-menu_the-event:http://www.afrikaburn.com/the-event',
  );
  // Exported menu link: main-menu_fundraiser-info:http://www.afrikaburn.com/the-event/fundraiser-info.
  $menu_links['main-menu_fundraiser-info:http://www.afrikaburn.com/the-event/fundraiser-info'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'http://www.afrikaburn.com/the-event/fundraiser-info',
    'router_path' => '',
    'link_title' => 'Fundraiser Info',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_fundraiser-info:http://www.afrikaburn.com/the-event/fundraiser-info',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'parent_identifier' => 'main-menu_the-event:http://www.afrikaburn.com/the-event',
  );
  // Exported menu link: main-menu_gallery:http://www.afrikaburn.com/gallery.
  $menu_links['main-menu_gallery:http://www.afrikaburn.com/gallery'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'http://www.afrikaburn.com/gallery',
    'router_path' => '',
    'link_title' => 'Gallery',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_gallery:http://www.afrikaburn.com/gallery',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
  );
  // Exported menu link: main-menu_get-involved:http://www.afrikaburn.com/community/get-involved.
  $menu_links['main-menu_get-involved:http://www.afrikaburn.com/community/get-involved'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'http://www.afrikaburn.com/community/get-involved',
    'router_path' => '',
    'link_title' => 'Get Involved',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_get-involved:http://www.afrikaburn.com/community/get-involved',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'main-menu_community:http://www.afrikaburn.com/community',
  );
  // Exported menu link: main-menu_getting-there:http://www.afrikaburn.com/the-event/getting-there.
  $menu_links['main-menu_getting-there:http://www.afrikaburn.com/the-event/getting-there'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'http://www.afrikaburn.com/the-event/getting-there',
    'router_path' => '',
    'link_title' => 'Getting There',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_getting-there:http://www.afrikaburn.com/the-event/getting-there',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'parent_identifier' => 'main-menu_the-event:http://www.afrikaburn.com/the-event',
  );
  // Exported menu link: main-menu_governance-transparency:http://www.afrikaburn.com/about/governance-transparency.
  $menu_links['main-menu_governance-transparency:http://www.afrikaburn.com/about/governance-transparency'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'http://www.afrikaburn.com/about/governance-transparency',
    'router_path' => '',
    'link_title' => 'Governance Transparency',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_governance-transparency:http://www.afrikaburn.com/about/governance-transparency',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
    'parent_identifier' => 'main-menu_about:http://www.afrikaburn.com/about',
  );
  // Exported menu link: main-menu_guiding-principles:http://www.afrikaburn.com/about/guiding-principles.
  $menu_links['main-menu_guiding-principles:http://www.afrikaburn.com/about/guiding-principles'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'http://www.afrikaburn.com/about/guiding-principles',
    'router_path' => '',
    'link_title' => 'Guiding Principles',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_guiding-principles:http://www.afrikaburn.com/about/guiding-principles',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'parent_identifier' => 'main-menu_about:http://www.afrikaburn.com/about',
  );
  // Exported menu link: main-menu_home:<front>.
  $menu_links['main-menu_home:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Home',
    'options' => array(
      'identifier' => 'main-menu_home:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: main-menu_latest-news:http://www.afrikaburn.com/news/latest-news/.
  $menu_links['main-menu_latest-news:http://www.afrikaburn.com/news/latest-news/'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'http://www.afrikaburn.com/news/latest-news/',
    'router_path' => '',
    'link_title' => 'Latest News',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_latest-news:http://www.afrikaburn.com/news/latest-news/',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'main-menu_news:http://www.afrikaburn.com/news',
  );
  // Exported menu link: main-menu_mission-statement:http://www.afrikaburn.com/about/mission-statement.
  $menu_links['main-menu_mission-statement:http://www.afrikaburn.com/about/mission-statement'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'http://www.afrikaburn.com/about/mission-statement',
    'router_path' => '',
    'link_title' => 'Mission Statement',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_mission-statement:http://www.afrikaburn.com/about/mission-statement',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'main-menu_about:http://www.afrikaburn.com/about',
  );
  // Exported menu link: main-menu_news:http://www.afrikaburn.com/news.
  $menu_links['main-menu_news:http://www.afrikaburn.com/news'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'http://www.afrikaburn.com/news',
    'router_path' => '',
    'link_title' => 'News',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_news:http://www.afrikaburn.com/news',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
  );
  // Exported menu link: main-menu_outreach-home:http://www.afrikaburn.com/community/outreach-home.
  $menu_links['main-menu_outreach-home:http://www.afrikaburn.com/community/outreach-home'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'http://www.afrikaburn.com/community/outreach-home',
    'router_path' => '',
    'link_title' => 'Outreach Home',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_outreach-home:http://www.afrikaburn.com/community/outreach-home',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'parent_identifier' => 'main-menu_community:http://www.afrikaburn.com/community',
  );
  // Exported menu link: main-menu_participation:http://www.afrikaburn.com/the-event/participation.
  $menu_links['main-menu_participation:http://www.afrikaburn.com/the-event/participation'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'http://www.afrikaburn.com/the-event/participation',
    'router_path' => '',
    'link_title' => 'Participation',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_participation:http://www.afrikaburn.com/the-event/participation',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -44,
    'customized' => 1,
    'parent_identifier' => 'main-menu_the-event:http://www.afrikaburn.com/the-event',
  );
  // Exported menu link: main-menu_past-events:http://www.afrikaburn.com/the-event/past-events.
  $menu_links['main-menu_past-events:http://www.afrikaburn.com/the-event/past-events'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'http://www.afrikaburn.com/the-event/past-events',
    'router_path' => '',
    'link_title' => 'Past Events',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_past-events:http://www.afrikaburn.com/the-event/past-events',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -42,
    'customized' => 1,
    'parent_identifier' => 'main-menu_the-event:http://www.afrikaburn.com/the-event',
  );
  // Exported menu link: main-menu_photography-and-media:http://www.afrikaburn.com/the-event/press-media.
  $menu_links['main-menu_photography-and-media:http://www.afrikaburn.com/the-event/press-media'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'http://www.afrikaburn.com/the-event/press-media',
    'router_path' => '',
    'link_title' => 'Photography and Media',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_photography-and-media:http://www.afrikaburn.com/the-event/press-media',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -41,
    'customized' => 1,
    'parent_identifier' => 'main-menu_the-event:http://www.afrikaburn.com/the-event',
  );
  // Exported menu link: main-menu_preparation:http://www.afrikaburn.com/the-event/preparation.
  $menu_links['main-menu_preparation:http://www.afrikaburn.com/the-event/preparation'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'http://www.afrikaburn.com/the-event/preparation',
    'router_path' => '',
    'link_title' => 'Preparation',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_preparation:http://www.afrikaburn.com/the-event/preparation',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
    'parent_identifier' => 'main-menu_the-event:http://www.afrikaburn.com/the-event',
  );
  // Exported menu link: main-menu_tankwa-town:http://www.afrikaburn.com/the-event/tankwa-town.
  $menu_links['main-menu_tankwa-town:http://www.afrikaburn.com/the-event/tankwa-town'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'http://www.afrikaburn.com/the-event/tankwa-town',
    'router_path' => '',
    'link_title' => 'Tankwa Town',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_tankwa-town:http://www.afrikaburn.com/the-event/tankwa-town',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
    'parent_identifier' => 'main-menu_the-event:http://www.afrikaburn.com/the-event',
  );
  // Exported menu link: main-menu_the-event:http://www.afrikaburn.com/the-event.
  $menu_links['main-menu_the-event:http://www.afrikaburn.com/the-event'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'http://www.afrikaburn.com/the-event',
    'router_path' => '',
    'link_title' => 'The Event',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_the-event:http://www.afrikaburn.com/the-event',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: main-menu_the-organisation:http://www.afrikaburn.com/about/the-organisation.
  $menu_links['main-menu_the-organisation:http://www.afrikaburn.com/about/the-organisation'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'http://www.afrikaburn.com/about/the-organisation',
    'router_path' => '',
    'link_title' => 'The Organisation',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_the-organisation:http://www.afrikaburn.com/about/the-organisation',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'parent_identifier' => 'main-menu_about:http://www.afrikaburn.com/about',
  );
  // Exported menu link: main-menu_tickets:http://www.afrikaburn.com/the-event/tickets.
  $menu_links['main-menu_tickets:http://www.afrikaburn.com/the-event/tickets'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'http://www.afrikaburn.com/the-event/tickets',
    'router_path' => '',
    'link_title' => 'Tickets',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_tickets:http://www.afrikaburn.com/the-event/tickets',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'main-menu_the-event:http://www.afrikaburn.com/the-event',
  );
  // Exported menu link: main-menu_what-is-afrikaburn:http://www.afrikaburn.com/about/what-is-afrikaburn.
  $menu_links['main-menu_what-is-afrikaburn:http://www.afrikaburn.com/about/what-is-afrikaburn'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'http://www.afrikaburn.com/about/what-is-afrikaburn',
    'router_path' => '',
    'link_title' => 'What is AfrikaBurn',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_what-is-afrikaburn:http://www.afrikaburn.com/about/what-is-afrikaburn',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'main-menu_about:http://www.afrikaburn.com/about',
  );
  // Exported menu link: user-menu_log-out:user/logout.
  $menu_links['user-menu_log-out:user/logout'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user/logout',
    'router_path' => 'user/logout',
    'link_title' => 'Log out',
    'options' => array(
      'identifier' => 'user-menu_log-out:user/logout',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
  );
  // Exported menu link: user-menu_login:user/login.
  $menu_links['user-menu_login:user/login'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user/login',
    'router_path' => 'user/login',
    'link_title' => 'Login',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'user-menu_login:user/login',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: user-menu_register:user/register.
  $menu_links['user-menu_register:user/register'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user/register',
    'router_path' => 'user/register',
    'link_title' => 'Register',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'user-menu_register:user/register',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: user-menu_user-account:user.
  $menu_links['user-menu_user-account:user'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user',
    'router_path' => 'user',
    'link_title' => 'User account',
    'options' => array(
      'alter' => TRUE,
      'identifier' => 'user-menu_user-account:user',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('2017 Theme Play');
  t('About');
  t('AfrikaBurn Financials');
  t('AfrikaBurn Images');
  t('AfrikaBurn Videos');
  t('AfrikaBurn Year Round');
  t('Binnekring Blog');
  t('Community');
  t('Community Links');
  t('Contact');
  t('DPW');
  t('FAQ');
  t('Fundraiser Info');
  t('Gallery');
  t('Get Involved');
  t('Getting There');
  t('Governance Transparency');
  t('Guiding Principles');
  t('Home');
  t('Latest News');
  t('Log out');
  t('Login');
  t('Mission Statement');
  t('News');
  t('Outreach Home');
  t('Participation');
  t('Past Events');
  t('Photography and Media');
  t('Preparation');
  t('Register');
  t('Tankwa Town');
  t('The Event');
  t('The Organisation');
  t('Tickets');
  t('User account');
  t('What is AfrikaBurn');

  return $menu_links;
}
