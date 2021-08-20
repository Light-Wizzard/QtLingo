# QtLingo About

QtLingo is an Application to make Qt Computer Translations easier,
and something I have never seen before,
so it is a new concept for Qt Translations.

The normal flow would have you edit files and replace words with their Translations,
this is too much work for me to do,
so I decided to make it easier,
run this Application and set up a project by giving it the folder location and name of your project,
give it the location for where you want the .ts files,
and a destination for the .qm files,
and compile it,
and it will give you the configuration for qmake or cmake,
and just update your files with that code,
and deploy your project,
it is all done, nothing more to do.

I use to GitHub Applications for this,
for Translations I use crow-translate at https://github.com/crow-translate/crow-translate,
and QOnlineTranslator at https://github.com/crow-translate/QOnlineTranslator,
and to parse the .ts files I use ts_tool at https://github.com/nen777w/ts_tool.

First I will update your projects Translations files according to the Languages you have chosen,
then I will translate all the Languages,
then update the Translations files and compile them into .qm files for deployment.

Writen by Jeffrey Scott Flesher
