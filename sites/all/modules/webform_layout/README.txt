Description
-----------
This module adds a new type of Webform component: the layout box. By placing webform fields inside layout boxes, you can arrange them into rows and columns.

How to use
----------
- Go to the main field list of a webform.
- Add a layout box to your form.
- For alignment, choose "Horizontal" or "Equal Width" to divide the space equally.
- Save the component.
- Add or drag other fields into the container.
- To create columns, add any number of vertically-aligned layout boxes inside a horizontally-aligned one.
- Be careful, some components are too wide by default (e.g. textfield). So, you may need to adjust them in order to fit side-by-side.
- If you need a title and/or description for your group you can add markup to the form, or insert the layout container into a fieldset.
- Note: The "Equal Width" feature works up to 9 children.
- To output the values separately in a submission e-mail, use the following token: [submission:values:layoutboxkey:key]