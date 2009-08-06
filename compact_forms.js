// $Id$

(function ($) {

/**
 * Compact Forms jQuery plugin.
 */
$.fn.compactForm = function (stars, colons) {
  stars = stars || 0;
  colons = colons || 0;

  this.each(function () {
    $(this).addClass('compact-form').find('label').each(function () {
      var context = this.form;
      var $label = $(this);
      var $field = $('#' + $label.attr('for'), context);
      if (!$field.is('input:text,input:password,textarea')) {
        return;
      }

      if ($field.val() != '') {
        $label.fadeOut(1);
      }

      $label.parent().addClass('compact-form-wrapper');
      $label.addClass('compact-form-label');
      $field.addClass('compact-form-field');

      if (stars === 0) {
        $label.find('.form-required').hide();
      }
      else if (stars === 2) {
        $label.find('.form-required').insertAfter($field).prepend('&nbsp;');
      }

      if (colons === 0) {
        var lbl = $label.html();
        lbl = lbl.replace(/:/,' ');
        $label.html(lbl);
      }

      $field.focus(function () {
        if($(this).val() === '') {
          $label.fadeOut('fast');
        }
      });

      $field.blur(function () {
        if($(this).val() === '') {
          $label.fadeIn('slow');
        }
      });
    });
  });
};

Drupal.behaviors.compactForms = function (context) {
  if (!Drupal.settings || !Drupal.settings.compactForms) {
    return;
  }
  $('#' + Drupal.settings.compactForms.forms.join(',#'), context).compactForm(Drupal.settings.compactForms.stars, Drupal.settings.compactForms.colons);
};

})(jQuery);
