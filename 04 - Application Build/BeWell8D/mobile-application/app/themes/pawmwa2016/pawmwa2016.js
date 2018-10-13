/**
 * Implements DrupalGap's template_info() hook.
 */
function pawmwa2016_info() {
  var theme = {
    name: 'pawmwa2016',
    regions: {
      header: {
        attributes: {
          'data-tap-toggle': 'false',
          'data-role': 'header',
          'data-position': 'fixed',
          'class': 'section',
        },
      },
      sub_header: {
        attributes: {
          'data-role': 'header'
        }
      },
      navigation: {
        attributes: {
          'data-role': 'navbar'
        }
      },
      content: {
        attributes: {
          'class': 'ui-content',
          'role': 'main'
        }
      }
      /*,
      footer: {
        attributes: {
          'data-role': 'footer',
          'data-position': 'fixed',
          'class': 'hide'
        }
      }*/
    }
  };
  return theme;
}

