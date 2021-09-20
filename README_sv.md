# QtLingo

QtLingo är en applikation för att göra Qt -översättningar enklare,
det normala flödet skulle få dig att redigera filer och ersätta ord med deras översättningar,
Detta är för mycket arbete för mig att göra,
så jag bestämde mig för att göra det lättare,
kör den här applikationen och skapa ett projekt genom att ge den mappens plats och namn på ditt projekt,
ge den platsen där du vill ha .ts -filerna,
och en destination för .qm -filerna,
och sammanställ det,
och det ger dig konfigurationen för qmake eller cmake,
och bara uppdatera dina filer med den koden,
och distribuera ditt projekt,
allt är gjort, inget mer att göra.

## Status

[! [Status för Appveyor Build] [https://ci.appveyor.com/api/projects/status/j7htumuwfx31elf6?svg=true]] (https://ci.appveyor.com/project/Light-Wizzard/qtlingo)

###: paket: ** Nedladdningar: **

-: penguin: [Linux x64 zip] (https://github.com/Light-Wizzard/QtLingo/releases/download/continuous/QtLingo-Ubuntu-Release-x64.zip)
-: office: [Windows x64 zip] (https://github.com/Light-Wizzard/QtLingo/releases/download/continuous/QtLingo-Windows-Release-x64.zip)
-: apple: [Apple x64 zip] (https://github.com/Light-Wizzard/QtLingo/releases/download/continuous/QtLingo-MacOs-Release-x64.zip)

Windows (Testad på 7 och 10 meddela mig om 8 fungerar): Ladda ner zip och extrahera det,
och kör filen QtLingo.exe inuti mappen som distribuerar AppDir.

Apple testar inte eftersom jag inte har en.

# Documentaion

Jag försöker få Doxygen -filerna att ladda upp till den här webbplatsen, fungerar inte än så länge.
[Documentaion] (https://light-wizzard.github.io/QtLingo/)

# GitHub -projekt och andra projekt som används

Jag använder GitHub -applikationer för detta,
för översättningar använder jag crow-translate på https://github.com/crow-translate/crow-translate,
och QOnlineTranslator på https://github.com/crow-translate/QOnlineTranslator,
och för att analysera .ts -filerna använder jag ts_tool på https://github.com/nen777w/ts_tool,
och jag använde https://wiki.qt.io/Simple_encryption_with_SimpleCrypt#Versions.

# Bearbeta

Klicka först på Kompilera för att uppdatera dina projekt Översättningsfiler enligt de språk du har valt,
Jag kallar det kompilera eftersom det är alla filer som sammanställs i din app,
klicka sedan på acceptera alla eller använd Qt Lingustic för att accetera varje översättning,
klicka sedan på uppdatera Hjälp och ReadMe och Translations dessa filer,
skapa filer med en språkkod.

# Doxygen

Jag använder Doxygen, du kan köra den från kommandona nedan.

'' bash
doxygen Doxyfile

eller

doxywizard
''

Jag har Doxygen Documents under docs.

# Problem

Hanterar att Internet -anslutningen går ner.

''
Kritiskt: "Socket operation timeout" (../QtLingo/src/MainWindow.cpp:2280, MainWindow :: translateWithReturn (const QString &, QOnlineTranslator :: Engine, QOnlineTranslator :: Language, QOnlineTranslator :: Language, QOnlineTranslator :: :: <lambda ()>)
Kritiskt: "Host www.bing.com inte hittat" (../QtLingo/src/MainWindow.cpp:2280, MainWindow :: translateWithReturn (const QString &, QOnlineTranslator :: Engine, QOnlineTranslator :: Språk, QOnlineTranslator :: Språk, QOnlineTranslator :: Språk) :: <lambda ()>)
Kritiskt: "Host translate.yandex.com hittades inte" (../QtLingo/src/MainWindow.cpp:2280, MainWindow :: translateWithReturn (const QString &, QOnlineTranslator :: Engine, QOnlineTranslator :: Language, QOnlineTranslator :: Language, QOnlineT :: Språk) :: <lambda ()>)
Kritiskt: "Host translate.googleapis.com hittades inte" (../QtLingo/src/MainWindow.cpp:2280, MainWindow :: translateWithReturn (const QString &, QOnlineTranslator :: Engine, QOnlineTranslator :: Språk, QOnlineTranslator :: Språk, QOnl :: Språk) :: <lambda ()>)

''

# Poäng

Jag använde några GitHub -projekt som jag listade ovan, allt annat är
skriven av Jeffrey Scott Flesher the Light Wizzard in the Flesh

### Slut på fil