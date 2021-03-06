<?php

/**
 * ASU Brand administration functions.
 */

function asu_brand_get_block_configure_form($delta) {
  $form['asu_brand'] = array(
    '#type' => 'fieldset',
    '#title' => t('ASU Brand settings'),
    '#description' => t('This block is cached for %lifetime. To update now, <a href="@link">clear the cache</a>.', array('%lifetime' => format_interval(ASU_BRAND_CACHE_LIFETIME), '@link' => url('admin/config/development/performance'))),
  );
  $form['asu_brand']['asu_brand_header_version'] = array(
    '#type' => 'select',
    '#title' => t('ASU header version'),
    '#description' => t('Select the version of the ASU header. <strong>This setting is shared between all ASU Brand blocks.</strong>'),
    '#options' => asu_brand_get_version_options(),
    '#default_value' => variable_get('asu_brand_header_version', ASU_BRAND_HEADER_VERSION_DEFAULT),
  );
  $form['asu_brand']['asu_brand_header_basepath'] = array(
    '#type' => 'textfield',
    '#title' => t('ASU theme basepath'),
    '#description' => t('Enter the path to the asuthemes folder.'),
    '#default_value' => variable_get('asu_brand_header_basepath', ASU_BRAND_HEADER_BASEPATH_DEFAULT),
    '#description' => t(' This setting is shared between all ASU Brand blocks. The default is %default. To use a local path, use %local_path', array('%default' => ASU_BRAND_HEADER_BASEPATH_DEFAULT, '%local_path' => '/afs/asu.edu/www/asuthemes')),
    '#required' => TRUE,
  );
  
  switch ($delta) {
    case 'asu_brand_header':
      $form['asu_brand']['asu_brand_header_template'] = array(
        '#type' => 'textfield',
        '#title' => t('ASU header template key'),
        '#description' => t('Enter the key for your custom header.'),
        '#default_value' => variable_get('asu_brand_header_template', ASU_BRAND_HEADER_TEMPLATE_DEFAULT),
        '#description' => t('The default is %default. For a list of template keys, visit <a href="@template_path">@template_path</a>.', array('%default' => ASU_BRAND_HEADER_TEMPLATE_DEFAULT, '@template_path' => url('https://asu.edu/asuthemes/' . variable_get('asu_brand_header_version', ASU_BRAND_HEADER_VERSION_DEFAULT) . '/heads/'))),
        '#required' => TRUE,
      );
      break;
      
      case 'asu_brand_footer':
        $form['asu_brand']['asu_brand_footer_color'] = array(
          '#type' => 'select',
          '#title' => t('ASU footer color'),
          '#description' => t('Select the color of the footer.'),
          '#options' => array('' => 'Black', '_light_grey' => 'Light Grey', '_dark_grey' => 'Dark Grey'),
          '#default_value' => variable_get('asu_brand_footer_color', ASU_BRAND_FOOTER_COLOR_DEFAULT),
        );
        break;
      
      case 'asu_brand_students_footer':
        
        break;
  }
  
  return $form;
}

/**
 * Get the header version options as an associative array in the form of
 * array(
 *   'version' => description text,
 * );
 */
function asu_brand_get_version_options() {
  $options = array('' => t('Select a version'));
  
  // Use internal xml errors to provide user readable errors.
  libxml_use_internal_errors(TRUE);
  try {
    $items = new SimpleXMLElement(ASU_BRAND_HEADER_VERSION_XML_URL, 0, TRUE);

    if ($items) {
      foreach ($items->header as $header) {
        $options[(string) $header->version] = t((string) $header->name);
      }
    }
    else {
      // There was an error with loading the xml.
      $log_message = "Failed loading ASU header version XML file\n";
      foreach(libxml_get_errors() as $error) {
        $log_message .= "\t" . $error->message;
      }
      drupal_set_message($log_message, 'error');
    }
  }
  catch (Exception $e) {
    drupal_set_message('Failed loading ASU header version XML file. Please try again later. The full error description has been logged.', 'error');
    watchdog('asu_brand', $e, array(), WATCHDOG_ERROR);
  }
  
  return $options;
}