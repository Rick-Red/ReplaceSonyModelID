'newid' - Simple utility for Sony ARW files to replace 'SonyModelId'.

Helps to open an ARW file from "unsupported" camera in your 'old' but
trusty ACR or etc.

Simple 'surgical' mod of Dave Coffin's 'dcraw'

Example to replace A6400 wth A6300:

$newid 357 DSC07946.ARW
$/EXIF/MakerNoteSony5/SonyModelID/371, replaced by 357

to see all the SonyModelID's, run 'newid 0'

