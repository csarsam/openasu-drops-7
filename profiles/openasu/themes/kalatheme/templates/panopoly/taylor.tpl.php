<?php
/**
 * @file
 * Template for Panopoly Taylor.
 *
 * Variables:
 * - $css_id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 * panel of the layout. This layout supports the following sections:
 */
?>

<div class="panel-display taylor clearfix <?php !empty($class) ? print $class : ''; ?>" <?php !empty($css_id) ? print "id=\"$css_id\"" : ''; ?>>

  <section class='section alt' id='promo'>
    <div class='container'>
      <div class="taylor-container taylor-header clearfix panel-panel ">
        <div class="taylor-container-inner taylor-header-inner panel-panel-inner">
          <?php print $content['header']; ?>
        </div>
      </div>
    </div>
  </section>

  <section class='section'>
    <div class='container'>      
      <div class="taylor-container taylor-column-content clearfix row-fluid">
        <div class="taylor-column-content-region taylor-half taylor-column panel-panel span8">
          <div class="taylor-column-content-region-inner taylor-half-inner taylor-column-inner panel-panel-inner">
            <?php print $content['half']; ?>
          </div>
        </div>
        <div class="taylor-column-content-region taylor-quarter1 taylor-column panel-panel span4">
          <div class="taylor-column-content-region-inner taylor-quarter1-inner taylor-column-inner panel-panel-inner">
            <?php print $content['quarter1']; ?>
          </div>
        </div>
        <div class="taylor-column-content-region taylor-quarter2 taylor-column panel-panel span4">
          <div class="taylor-column-content-region-inner taylor-quarter2-inner taylor-column-inner panel-panel-inner">
            <?php print $content['quarter2']; ?>
          </div>
        </div>
      </div>
    </div>
  </section>

  <footer class='section' id='footer' role='contentinfo'>
    <div class='container'>    
      <div class="taylor-container taylor-footer clearfix panel-panel">
        <div class="taylor-container-inner taylor-footer-inner panel-panel-inner">
          <?php print $content['footer']; ?>
        </div>
      </div>
    </div>
  </footer>
    
</div><!-- /.taylor -->
