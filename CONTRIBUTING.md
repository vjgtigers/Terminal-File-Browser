# Contributing to Terminal-File-Browser
[Modified from Auth0](https://github.com/auth0/open-source-template/blob/master/GENERAL-CONTRIBUTING.md) <br>
A big welcome and thank you for considering contributing to open source projects! It’s people like you that make it a reality for users in our community.

Reading and following these guidelines will help us make the contribution process easy and effective for everyone involved. It also communicates that you agree to respect the time of the developers managing and developing these open source projects. In return, we will reciprocate that respect by addressing your issue, assessing changes, and helping you finalize your pull requests.



## Getting Started

Contributions are made to this repo via Issues and Pull Requests (PRs). A few general guidelines that cover both:
- Search for existing Issues and PRs before creating your own.

### Issues

Issues should be used to report problems with the library, request a new feature, or to discuss potential changes before a PR is created. When you create a new Issue, a template will be loaded that will guide you through collecting and providing the information we need to investigate.

If you find an Issue that addresses the problem you're having, please add your own reproduction information to the existing issue rather than creating a new one. Adding a [reaction](https://github.blog/2016-03-10-add-reactions-to-pull-requests-issues-and-comments/) can also help be indicating to our maintainers that a particular problem is affecting more than just the reporter.

### Pull Requests

PRs are always welcome and can be a quick way to get your fix or improvement slated for the next release. In general, PRs should:

- Only fix/add the functionality in question **OR** address wide-spread whitespace/style issues, not both.
- Add unit or integration tests for fixed or changed functionality (if a test suite already exists).
- Address a single concern in the least number of changed lines as possible.
- - Be accompanied by a complete Pull Request template (Work in Progress).

For changes that address core functionality or would require breaking changes (e.g. a major release), it's best to open an Issue to discuss your proposal first. This is not required but can save time creating and reviewing changes.

In general, we follow the ["fork-and-pull" Git workflow](https://github.com/susam/gitpr)

1. Fork the repository to your own Github account
2. Clone the project to your machine
3. Create a branch locally with a succinct but descriptive name
4. Commit changes to the branch
5. Following any formatting and testing guidelines specific to this repo
6. Push changes to your fork
7. Open a PR in our repository and follow the PR template so that we can efficiently review the changes.


# Contributing checklist

## Adding config option
1. Add the option to the setUserConfig function in configInfo.cpp
   * unordered map
   * switch statement
2. Add to createUserConfig function in configInfo.cpp
3. Add the option to the appropriate template
   * advancedCodes_template | advancedCodes
   * renderCodes_template | renderCodes
   * keyPressCodes_template | keyPressCodes
4. Add the default to the struct (probably in main.cpp)
5. Add the config option to CONFIG.md table
6. Add the config option to the TFV_config_template.txt in the appropriate place.


## Adding Command Line Command
1. Create the command function in the commands.cpp file
2. Add to commands.h file
3. Add the command name to the commandCalls function in the commandLine.cpp with the function call
4. Add a help page to the helpInfo folder, use the function name + .txt
5. Add the command to the README.md page table