<?php
/**
 * @file
 * Rules integration.
 */

function travisbuilder_rules_action_info() {
  return array(
    'travisbuilder_action_trigger_build' => array(
      'label' => t('Trigger a Travis build'),
      'group' => t('System'),
      'parameter' => array(
        'ignore_lifetime' => array(
          'type' => 'boolean',
          'label' => t('Ignore lifetime'),
          'description' => t('Ignore the recent build minimum lifetime when triggering Travis from this rule action.'),
          'restriction' => 'input',
          'save' => TRUE,
        ),
      ),
      'base' => 'travisbuilder_action_trigger_build',
    ),
  );
}


function travisbuilder_action_trigger_build() {
  // @ todo Allow separate repos to trigger as ctools configs.
  $repository = check_plain(variable_get('travisbuilder_repo', ''));

  _travisbuilder_trigger_build($repository);
}
