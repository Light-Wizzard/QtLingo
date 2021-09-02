# QtLingo

QtLingo is an Application to make Qt Translations easier,
the normal flow would have you edit files and replace words with their Translations,
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

## Status

[![Appveyor Build Status](https://ci.appveyor.com/api/projects/status/j7htumuwfx31elf6?svg=true)](https://ci.appveyor.com/project/Light-Wizzard/qtlingo)

### :package: **Downloads:**

- :penguin: [Linux x64 zip  ](https://github.com/Light-Wizzard/QtLingo/releases/download/continuous/QtLingo-Ubuntu-Release-x64.zip)
- :office:  [Windows x64 zip](https://github.com/Light-Wizzard/QtLingo/releases/download/continuous/QtLingo-Windows-Release-x64.zip)
- :apple:   [Apple x64 zip  ](https://github.com/Light-Wizzard/QtLingo/releases/download/continuous/QtLingo-MacOs-Release-x64.zip)

Windows (Tested on 7 and 10 let me know if 8 works): Download zip and extract it, 
and run the file QtLingo.exe inside of the deploy AppDir folder.

Apple not test since I do not have one.

# Documentaion

I am trying to get the Doxygen files to upload to this site, not working so far.
[Documentaion](https://light-wizzard.github.io/QtLingo/)

# GitHub Projects and other projects used

I use to GitHub Applications for this,
for Translations I use crow-translate at https://github.com/crow-translate/crow-translate,
and QOnlineTranslator at https://github.com/crow-translate/QOnlineTranslator,
and to parse the .ts files I use ts_tool at https://github.com/nen777w/ts_tool,
and I used https://wiki.qt.io/Simple_encryption_with_SimpleCrypt#Versions.

# Process

First click on Compile to update your projects Translations files according to the Languages you have chosen,
I call it compile because these are all the files get compiled into your app, 
then click on accept all or use Qt Lingustic to accet each translation,
then click on update the Help and ReadMe and Translations those files, 
creating files with a Language Code.

# Doxygen

I tried to document usign Doxygen, you can run it from the commands below.

```bash
doxygen Doxyfile 

or

doxywizard
```

# Problems

Dealing with Internet connection going down.

```
Critical: "Socket operation timed out" (../QtLingo/src/MainWindow.cpp:2280, MainWindow::translateWithReturn(const QString&, QOnlineTranslator::Engine, QOnlineTranslator::Language, QOnlineTranslator::Language, QOnlineTranslator::Language)::<lambda()>)
Critical: "Host www.bing.com not found" (../QtLingo/src/MainWindow.cpp:2280, MainWindow::translateWithReturn(const QString&, QOnlineTranslator::Engine, QOnlineTranslator::Language, QOnlineTranslator::Language, QOnlineTranslator::Language)::<lambda()>)
Critical: "Host translate.yandex.com not found" (../QtLingo/src/MainWindow.cpp:2280, MainWindow::translateWithReturn(const QString&, QOnlineTranslator::Engine, QOnlineTranslator::Language, QOnlineTranslator::Language, QOnlineTranslator::Language)::<lambda()>)
Critical: "Host translate.googleapis.com not found" (../QtLingo/src/MainWindow.cpp:2280, MainWindow::translateWithReturn(const QString&, QOnlineTranslator::Engine, QOnlineTranslator::Language, QOnlineTranslator::Language, QOnlineTranslator::Language)::<lambda()>)

```

# Credits

I used a few GitHub Projects that I listed above, everything else is
writen by Jeffrey Scott Flesher the Light Wizzard in the Flesh

### End of File
