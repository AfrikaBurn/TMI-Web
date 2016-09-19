<?php

/* vim: set filetype=php: */

/**
 * @file
 * Draw chart for the visitors module.
 */

require_once VISITORS_MODULE_CHART_DIR . '/pDraw.class.php';
require_once VISITORS_MODULE_CHART_DIR . '/pImage.class.php';
require_once VISITORS_MODULE_CHART_DIR . '/pData.class.php';

/**
 * Get chart width.
 *
 * @return
 *   int chart width
 */
function visitors_get_chart_width() {
  $width = (int) variable_get('visitors_chart_width', 700);
  return (($width <= 0) ? 700 : $width);
}

/**
 * Get chart height.
 *
 * @return
 *   int chart height
 */
function visitors_get_chart_height() {
  $height = (int) variable_get('visitors_chart_height', 430);
  return (($height <= 0) ? 430 : $height);
}

/**
 * Draw chart.
 *
 * @values
 *   int array y-axis values
 * @x_array
 *   array x-axis params
 */
function visitors_chart($values, $x_array = NULL) {
  $width  = visitors_get_chart_width();
  $height = visitors_get_chart_height();

  // Dataset definition
  $MyData = new pData;
  $MyData->addPoints($values,'serie1');

  if ($x_array !== NULL) {
    $MyData->addPoints($x_array,'serie2');
    $MyData->setAbscissa('serie2');
  }

  $myPicture = new pImage($width,$height,$MyData);

  $myPicture->setFontProperties(array(
    'FontName' => dirname(__FILE__) . '/pChart/fonts/calibri.ttf',
    'FontSize' => 10
  ));

  /* Draw the scale  */
  $myPicture->setGraphArea(50, 30, $width - 20, $height - 30);
  $myPicture->drawRoundedFilledRectangle(
    7, 7, $width - 7, $height - 7, 5,
    array('R' => 245, 'G' => 245, 'B' => 240)
  );

  $myPicture->drawRoundedRectangle(
    5, 5, $width - 5, $height - 5, 5,
    array('R' => 230,'G' => 230,'B' => 230)
  );

 $myPicture->drawScale(array(
    'Mode' => SCALE_MODE_START0,
    'CycleBackground' => TRUE,
    'DrawSubTicks' => TRUE,
    'GridR' => 200,
    'GridG' => 200,
    'GridB' => 200)
  );

  /* Turn on shadow computing */
  $myPicture->setShadow(
    FALSE,
    array('X' => 1,'Y' => 1,'R' => 0,'G' => 0,'B' => 0,'Alpha' => 10)
  );

  /* Draw the chart */
  $settings = array(
    'Gradient' => TRUE,
    'DisplayPos' => LABEL_POS_INSIDE,
    'DisplayValues' => FALSE,
    'DisplayR' => 255,
    'DisplayG' => 255,
    'DisplayB' => 255,
    'DisplayShadow' => TRUE,
    'Surrounding' => 10
  );

  $myPicture->drawBarChart($settings);

  /* Render the picture (choose the best way) */
  $myPicture->autoOutput();
  exit();
}

