/*
Copyright (c) 2003-2013, CKSource - Frederico Knabben. All rights reserved.
For licensing, see LICENSE.html or http://ckeditor.com/license
*/

/*
 * This file is used/requested by the 'Styles' button.
 * The 'Styles' button is not enabled by default in DrupalFull and DrupalFiltered toolbars.
 */
if(typeof(CKEDITOR) !== 'undefined') {
  CKEDITOR.addStylesSet( 'drupal',
  [

    { name : 'Text: Smaller', element : 'span', attributes : { 'class' : 'fw-text smaller' } },
    { name : 'Text: Small', element : 'span', attributes : { 'class' : 'fw-text small' } },
    { name : 'Text: Medium', element : 'span', attributes : { 'class' : 'fw-text med' } },
    { name : 'Text: Large', element : 'span', attributes : { 'class' : 'fw-text large' } },
    { name : 'Text: Larger', element : 'span', attributes : { 'class' : 'fw-text larger' } },
    { name : 'Text: Light', element : 'span', attributes : { 'class' : 'fw-text light' } },
    { name : 'Text: Semibold', element : 'span', attributes : { 'class' : 'fw-text semibold' } },
    { name : 'Text: Gray', element : 'span', attributes : { 'class' : 'fw-text c-black-65' } },
    { name : 'Text: GrayLight', element : 'span', attributes : { 'class' : 'fw-text c-black-45' } },
    { name : 'Text: Orange', element : 'span', attributes : { 'class' : 'fw-text c-orange' } },
    { name : 'Text: OrangeDark', element : 'span', attributes : { 'class' : 'fw-text c-orangedark' } },
    { name : 'Text: Brown', element : 'span', attributes : { 'class' : 'fw-text c-brown' } },
    { name : 'Text: Green', element : 'span', attributes : { 'class' : 'fw-text c-green' } },
    { name : 'Faux: Headline 5', element : 'span', attributes : { 'class' : 'h3' } },
    { name : 'Faux: Headline 6', element : 'span', attributes : { 'class' : 'h6' } },
    { name : 'List: No Style', element : 'ul', attributes : { 'class' : 'fw-list-plain' } },
    { name : 'List: Small', element : ['ul', 'ol'], attributes : { 'class' : 'fw-wysiwyg-list-small' } },
    { name : 'Link: External', element : 'a', attributes : { 'class' : 'fw-icon-after icon-share' } },
    { name : 'Button', element : 'a', attributes : { 'class' : 'fw-wysiwyg-btn' } },
    { name : 'Button: Arrow', element : 'a', attributes : { 'class' : 'fw-wysiwyg-btn fw-icon-after icon-next' } },
    { name : 'Callout Box', element : 'span', attributes : { 'class' : 'fw-callout' } },
    { name : 'Callout Box (list)', element : ['ul', 'ol'], attributes : { 'class' : 'fw-wysiwyg-callout-list' } },
    { name : 'Title Box (Dark)', element : 'span', attributes : { 'class' : 'box-title' } },
    { name : 'Title Box (Light)', element : 'span', attributes : { 'class' : 'box-title-light' } },
    { name : 'Image Thumbnails', element : 'span', attributes : { 'class' : 'fw-wysiwyg-thumbs' } },
    { name : 'Image Full Width', element : 'img', attributes : { 'class' : 'fw-full' } },
    { name : 'Quote: Image', element : 'img', attributes : { 'class' : 'fw-wysiwyg-circle-thumb' } },
    { name : 'Quote: Name', element : 'span', attributes : { 'class' : 'fw-quote-title' } },
    { name : 'Quote: Text', element : 'span', attributes : { 'class' : 'fw-quote-text' } },
    { name : 'Image: Left', element : 'p', attributes : { 'class' : 'fw-wysiwyg-img-float-left' } },

  ]);
}
