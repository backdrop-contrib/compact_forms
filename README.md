Compact Forms
=============

Compact Forms simplifies forms by hiding field labels and using placeholder text
instead.

By default, only the user login block is switched to the compact style, but the
behaviour can be added to any form by adding the form's ID to the Compact Forms
settings page.

Installation
------------

- Install this module using the official Backdrop CMS instructions at
  https://backdropcms.org/guide/modules

- Visit the configuration page under Administration > Configuration > User
  Interface > Compact Forms (admin/config/user-interface/compact_forms) and
  enter the form ID of any form that should be made compact.

- Configure the other settings appropriately.

- To programmatically disable the compact forms behaviour on a particular form,
  set the following property on the `$form` element in your form constructor
  function or via `hook_form_alter()`:

  `$form['#compact_forms'] = FALSE;`

Issues
------

Bugs and feature requests should be reported in the Issue Queue:
https://github.com/backdrop-contrib/compact_forms/issues

Current Maintainers
-------------------

- Seeking maintainer(s)

Credits
-------

- Ported to Backdrop CMS by [Peter Anderson](https://github.com/BWPanda)
- Originally written for Drupal by [Tom Sundström](https://github.com/tomsun)

License
-------

This project is GPL v2 software.
See the LICENSE.txt file in this directory for complete text.
