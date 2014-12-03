<?php
/**
 * @file
 * Rules integration.
 */

function travisbuilder_rules_action_info() {
  return array(
    'trigger_build' => array(
      'label' => t('Trigger a Travis build'),
      'group' => t('System'),
      'base' => 'travisbuilder_rules_action_trigger_build',
    ),
  );
}

function travisbuilder_rules_action_trigger_build() {
  // @ todo Allow separate repos to trigger as ctools configs.
  $repository = variable_get('travisbuilder_repo', '');

  _travisbuilder_trigger_build($repository);
}
