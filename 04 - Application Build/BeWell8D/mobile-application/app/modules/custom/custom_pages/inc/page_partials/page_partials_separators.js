//Icon Circle Image Separator
function page_partial_icon_image_separator(type) {
  switch (type) {
    case 'page-top':
      return '<div class="separator-circles -top-crop"></div>';
      break;
    case 'gradient':
      return '<div class="section  separator-circles -grad"></div>';
      break;
    case 'bottom':
      return '<div class="separator-circles -bottom"></div>';
      break;
    case 'default':
      return '<div class="section  separator-circles"></div>';
      break;
  }
}