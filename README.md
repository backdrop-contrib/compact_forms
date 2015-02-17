Compact Forms
=============

Compact Forms presents text fields for selected forms in a more compact fashion
using jQuery.

The form item/element fields are overlaid with their respective labels. When the
user focuses a field the label fades away nicely, and if the field is left empty
the label fades back in again.

By default, only the user login block is switched to compact style, but the
behavior can be added to any form by adding the corresponding CSS IDs to the
Compact Forms configuration.

- Degrades back to the original form when JavaScript is switched off.
- Fields like checkboxes are currently not affected.
- Inspired by [A List Apart](http://www.alistapart.com/articles/makingcompactformsmoreaccessible/)


Installation
------------

- Install this module using the official Backdrop CMS instructions at
  https://backdropcms.org/guide/modules

- Visit the configuration page under Administration > Configuration > User
  Interface > Compact Forms (admin/config/user-interface/compact_forms) and
  enter the CSS IDs of forms that should be made compact.

- To programmatically disable the compact forms behavior on a particular form,
  set the following property on the $form element in your form constructor
  function or via hook_form_alter():

  `$form['#compact_forms'] = FALSE;`


License
-------

This project is GPL v2 software. See the LICENSE.txt file in this directory for
complete text.


Credits
-------

This module was originally written for Drupal by
[Tom Sundström](https://github.com/tomsun).

