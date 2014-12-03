<?php

/**
 * Implements settings for the module.
 */
function travisbuilder_settings_form($form_state) {
  $module_name = 'travisbuilder_';
  $form = array();

  $form[$module_name . 'repo'] = array(
    '#type' => 'textfield',
    '#title' => t('Travis repository'),
    '#default_value' => variable_get($module_name . 'repo', ''),
    '#description' => t('Travis repo to trigger a build. Example: username/my-project-repo'),
  );

  // @todo Use a temporary token generated each time.
  // http://docs.travis-ci.com/api/#creating-a-temporary-github-token
  $form[$module_name . 'github_token'] = array(
    '#type' => 'textfield',
    '#title' => t('GitHub token'),
    '#default_value' => variable_get($module_name . 'github_token', ''),
    '#description' => t('Token from GitHub service allowing authentication into this repository.'),
  );

  $form[$module_name . 'schedule'] = array(
    '#type' => 'select',
    '#title' => t('Build trigger schedule'),
    '#default_value' => variable_get($module_name . 'schedule', ''),
    '#description' => t('Automated build schedule timeline.'),
    '#options' => array(
      3600 => t('1 hour'),
      10800 => t('3 hours'),
      21600 => t('6 hours'),
      43200 => t('12 hours'),
      86400 => t('1 day'),
      259200 => t('3 days'),
      604800 => t('1 week'),
      2592000 => t('1 month'),
    ),
    '#default_value' => variable_get($module_name . 'schedule', array()),
  );

  // @ todo Allow separate repos to trigger as ctools configs.
  $repository = variable_get('travisbuilder_repo', '');
  $form['build_list'] = array(
    '#markup' => _travisbuilder_list_builds($repository),
  );

  return system_settings_form($form);
}
