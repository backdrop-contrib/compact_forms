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
    '#title' => t('Form IDs'),
    '#rows' => 3,
    '#cols' => 40,
    '#default_value' => variable_get('compact_forms_ids', 'user-login-form'),
    '#description' => 'Enter the CSS #id of the forms that you want to activate compact_forms for. One per line.',
  );
  $form['compact_forms_stars'] = array(
    '#title' => t('"Required field" - stars'),
    '#type' => 'radios',
    '#options' => array(
      0 => t('Remove "required" stars'),
      1 => t('Leave "required" stars attached to label'),
      2 => t('Insert "required" stars after the field'),
    ),
    '#default_value' => variable_get('compact_forms_stars', 2),
    '#description' => t('How to deal with the stars added by Drupal to indicate required fields.'),
  );
  $form['compact_forms_colons'] = array(
    '#title' => t('Trailing colons in labels'),
    '#type' => 'radios',
    '#options' => array(
      0 => t('Remove trailing colons from the label'),
      1 => t('Keep trailing colons'),
    ),
    '#default_value' => variable_get('compact_forms_colons', 0),
  );
  $form['compact_forms_field_size'] = array(
    '#title' => t('Textfield size'),
    '#type' => 'textfield',
    '#size' => 3,
    '#default_value' => variable_get('compact_forms_field_size', ''),
    '#description' => t('Optionally override the width of all text fields in the selected forms'),
  );
  $form['compact_forms_descriptions'] = array(
    '#title' => t('Textfield descriptions'),
    '#type' => 'radios',
    '#options' => array(
      0 => t('Hide descriptions'),
      1 => t('Show descriptions'),
    ),
    '#default_value' => variable_get('compact_forms_descriptions', 1),
    '#description' => t('Optionally hide descriptions of all textfields (in general not recommended).'),
  );

  return system_settings_form($form);
}

