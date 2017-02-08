# Field tokens

[![Build Status](https://travis-ci.org/Decipher/field_tokens.svg)](https://travis-ci.org/Decipher/field_tokens)

The Field tokens module add two additional types of field tokens; Formatted
fields and field properties.



### Formatted field tokens

Formatted Field tokens are tokens allowing one or many field values to be
rendered via the default or specified field formatter.

The format is:
```
[PREFIX:DELTA(S):FORMATTER:FORMATTER_SETTING_KEY-FORMATTER_SETTING_VALUE:...]
```

(e.g. **[node:field_image-formatted:0,1:image:image_style-thumbnail]**).



### Field property tokens

Field property tokens are tokens allowing access to field properties on one or
many fields.

Properties are dependent on the field type.

The format is:
```
[PREFIX:DELTA(S):PROPERTY]
```

(e.g. **[node:field_image-formatted:0:uri]**).



## Required modules

- [Token](https://www.drupal.org/project/token)



## Recommended modules

- [Token filter](https://www.drupal.org/project/token_filter)
