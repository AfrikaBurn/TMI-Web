CONTENTS OF THIS FILE
---------------------

 * Introduction
 * Installation & Usage


INTRODUCTION
------------

With Bulk Media Upload you can upload a bunch of (media) files and a new node will be created for every file. The files are selected via a browser file upload dialog and can be stored in a media, file or image field.
Also default values can be chosen for the other fields assigned to the new node.




INSTALLATION & USAGE
------------

1.  Install plupload and token. (Dont forget their dependencies!)
2.  Download plupload from plupload.com and copy the files into
    sites/all/libraries/plupload
3.  Create a nodetype with at least one media-, image- or file-field
4.  Go to admin/config/media/bulk_media_upload and choose your nodetype and
    the created media-, image- or file-field
5.  Visit admin/content/media/bulk_upload, fill out the form and start uploading
