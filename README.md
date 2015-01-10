Travis Builder
==============

**Trigger [Travis CI][travis] builds within [Drupal][drupal].**

Why?  Perhaps you have a static site/app which uses the Drupal CMS as it's content souce.  You build/deploy the static app automatically, normally after successful tests upon a commit to master via the Travis continuous integration tool and some host.  Now you can use Drupal events (via Rules) to rebuild and deploy when: content is updated, you clear cache, on cron, or whenever

*"Headless Drupal is so hot right now."*

**Limitation:** Currently just one repository per site.

## Install
This modules has a few, beyond ordinary, installation steps...

### Composer
The modules uses the [l3l0/php-travis-client][phptravis] library for reaching out to Travis' API, which is available via composer.  To add this to your codebase you'll need Drush and [Composer Manager][comp] run `drush composer install` to download the dependecies into your `/sites/all/vendors` folder.  If you run into trouble you may need the `drush composer update` command as well.

### Travis token
Public repos can be triggers via standard account travis token. This can be generated using the Travis [command line tool][traviscli] Ruby gem. Here's the process...

1. `gem install travis`
2. `travis login`
2. `travis token`

Enter the access token into Drupal via `admin/config/system/travis-builder`.

### Private repos
In order to trigger private repo builds, you'll need to gerneate a "Travis token" using a Github authorization token.  The command is `travis login --github-token "YOUR GITHUB TOKEN"` but you can read more in the [API docs][travisapiauth].

## Curious about Travis?
Check out the [Travis eco-system]!

http://docs.travis-ci.com/api/#with-a-github-token

[travis]: https://travis-ci.com
[drupal]: https://www.drupal.org
[comp]: https://www.drupal.org/project/composer_manager
[phptravis]: https://github.com/l3l0/php-travis-client
[traviseco]: http://docs.travis-ci.com/user/apps
[traviscli]: http://blog.travis-ci.com/2013-01-14-new-client
[travisapiauth]: http://docs.travis-ci.com/api/?shell#with-a-github-token
