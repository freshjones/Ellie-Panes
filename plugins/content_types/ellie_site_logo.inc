<?php
/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t('Ellie Site Logo'),
  'description' => t('Ellie Site Logo'),
  // 'single' => TRUE means has no subtypes.
  'single' => TRUE,
  // Constructor.
  'content_types' => array('ellie_panes_content_type'),
  // Name of a function which will render the block.
  'render callback' => 'ellie_site_logo_render',
  // The default context.
  'defaults' => array(),
  // category in ctools modal
  'category' => array(t('Ellie'), -9),
  //'all contexts' => TRUE,
);

/**
 * Run-time rendering of the body of the block.
 *
 * @param $subtype
 * @param $conf
 *   Configuration as done at admin time.
 * @param $args
 * @param $context
 *   Context - in this case we don't have any.
 *
 * @return
 *   An object with at least title and content members.
 */
function ellie_site_logo_render($subtype, $conf, $args, $context) 
{
    $sitename = variable_get('site_name', 'Ellie');
    $link = l($sitename, NULL, array('absolute' => TRUE));    
    $block = new stdClass();
    $block->title = '';
    $block->content =  '<div class="logo">' . $link . '</div>';
    return $block;
}
