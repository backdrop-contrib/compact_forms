<?php

/**
 * @file
 * Compact Forms administration functions.
 */

/**
 * Form constructor for Compact Forms settings.
 */
function compact_forms_admin_form($form, &$form_state) {
  $config = config('compact_forms.settings');

  $form['form_ids'] = array(
    '#type' => 'textarea',
    '#title' => t('Form CSS IDs'),
    '#rows' => 3,
    '#cols' => 40,
    '#default_value' => $config->get('form_ids'),
    '#description' => t('Enter the CSS IDs of the forms to display compact. One per line.'),
  );
  $form['descriptions'] = array(
    '#type' => 'checkbox',
    '#title' => t('Hide field descriptions'),
    '#default_value' => $config->get('descriptions'),
  );
  $form['stars'] = array(
    '#type' => 'radios',
    '#title' => t('Required field marker'),
    '#options' => array(
      0 => t('Remove star'),
      1 => t('Leave star after the label'),
      2 => t('Append star after the form element'),
    ),
    '#default_value' => $config->get('stars'),
  );
  $form['field_size'] = array(
    '#type' => 'textfield',
    '#title' => t('Enforced text field size'),
    '#size' => 3,
    '#default_value' => $config->get('field_size'),
    '#field_suffix' => t('characters'),
    '#description' => t("If not empty, the size of all text fields in compact forms will be set to the entered size."),
  );

  // Add a submit button.
  $form['actions'] = array(
    '#type' => 'actions',
    'submit' => array(
      '#type' => 'submit',
      '#value' => t('Save configuration'),
    ),
  );

  return $form;
}

/**
 * Submit handler for compact_forms_admin_form().
 */
function compact_forms_admin_form_submit($form, &$form_state) {
  $config = config('compact_forms.settings');
  $config->set('form_ids', $form_state['values']['form_ids']);
  $config->set('descriptions', $form_state['values']['descriptions']);
  $config->set('stars', $form_state['values']['stars']);
  $config->set('field_size', $form_state['values']['field_size']);
  $config->save();

  backdrop_set_message(t('The configuration options have been saved.'));
}

