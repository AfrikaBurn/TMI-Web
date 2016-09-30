Take control and Rule your Tokens.

The Rule Tokens module allows (mostly) any token to be passed through a Rule
component allowing you to change the output as you and your Rule see fit.

Example: If token is 'node:title' and today is Talk like a pirate day, translate
         the token value.


Rule Tokens was written by Stuart Clark (deciphered) and is maintained by
Stuart Clark and Brian Gilbert (realityloop) of Realityloop Pty Ltd.
- http://www.realityloop.com
- http://twitter.com/realityloop



Required Modules
--------------------------------------------------------------------------------

* Rules - http://drupal.org/project/rules



Recommended Modules
--------------------------------------------------------------------------------

* Token - http://drupal.org/project/token



How to use
--------------------------------------------------------------------------------

1. Install/Enable as per https://drupal.org/node/895232

2. Create a 'Rule' Rules component (admin/config/workflow/rules/components/add)
   with the following Variables in the following order:


   * Value; The variable containing the Token value which you will be altering:

     - Data type: Text
     - Label: Value
     - Machine name: value
     - Usage: Parameter + Provided


  * (optional) Type; The Token type:

    - Data type: Text
    - Label: Type
    - Machine name: type
    - Usage: Parameter


  * (optional) Token; The Token pattern (without brackets):

    - Data type: Text
    - Label: Token
    - Machine name: token
    - Usage: Parameter


  * (optional) Entity; The Tokens data (Node, User, etc):

    - Data type: [Type of entity]
    - Label: Entity
    - Machine name: entity
    - Usage: Parameter


3. Add any conditions and actions (Data comparison, Set a data value), making
   any required changes to the 'Value' parameter.

4. Implement your rule token wherever applicable by appending ":rule_tokens:?"
   to an existing token, where '?' is the machine name of your Rules component.

   Example: [node:title] with a component named 'rules_demo' would be invoked
            as [node:title:rule_tokens:rules_demo].
