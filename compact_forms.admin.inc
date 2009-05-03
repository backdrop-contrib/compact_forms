<?php
// $Id$

/**
 * @file
 * Compact Forms administration functions.
 */

/**
 * Form builder function for Compact Forms settings.
 */
function compact_forms_admin_form() {
  $form['compact_forms_ids'] = array(
    '#type' => 'textarea',
    '#title' => t('Form CSS ids'),
    '#rows' => 3,
    '#cols' => 40,
    '#default_value' => variable_get('compact_forms_ids', 'user-login-form'),
    '#description' => t('The CSS ids of forms that shall be displayed compact. One per line.'),
  );
  $form['compact_forms_colons'] = array(
    '#type' => 'checkbox',
    '#title' => t('Keep trailing colons in labels'),
    '#default_value' => variable_get('compact_forms_colons', 0),
    '#description' => t('When enabled, trailing colons after the field label will be removed.'),
  );
  $form['compact_forms_stars'] = array(
    '#type' => 'radios',
    '#title' => t('Required field handling'),
    '#options' => array(
      0 => t('Remove star'),
      1 => t('Leave star attached to label'),
      2 => t('Append star after the field'),
    ),
    '#default_value' => variable_get('compact_forms_stars', 2),
    '#description' => t('Defines how required field indicators should be altered.'),
  );
  $form['compact_forms_field_size'] = array(
    '#type' => 'textfield',
    '#title' => t('Textfield size'),
    '#size' => 3,
    '#default_value' => variable_get('compact_forms_field_size', ''),
    '#description' => t("Optionally override the 'size' attribute (width) of all text fields in compact forms. Leave empty to use the default sizes defined by the original forms."),
  );
  $form['compact_forms_descriptions'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show field descriptions'),
    '#default_value' => variable_get('compact_forms_descriptions', 1),
    '#description' => t('When enabled, form element descriptions will be hidden.'),
  );

  return system_settings_form($form);
}

