# QtLingo

QtLingo er et program for å gjøre Qt -oversettelser enklere,
den normale flyten vil få deg til å redigere filer og erstatte ord med oversettelsene deres,
Dette er for mye arbeid for meg å gjøre,
så jeg bestemte meg for å gjøre det enklere,
kjør denne applikasjonen og sett opp et prosjekt ved å gi den mappens plassering og navnet på prosjektet ditt,
gi den stedet der du vil ha .ts -filene,
og en destinasjon for .qm -filene,
og kompiler det,
og det vil gi deg konfigurasjonen for qmake eller cmake,
og bare oppdater filene dine med den koden,
og distribuer prosjektet ditt,
alt er gjort, ingenting mer å gjøre.

## Status

[! [Status for transportørbygger] (https://ci.appveyor.com/api/projects/status/j7htumuwfx31elf6?svg=true)] (https://ci.appveyor.com/project/Light-Wizzard/qtlingo)

###: pakke: ** Nedlastinger: **

-: penguin: [Linux x64 zip] (https://github.com/Light-Wizzard/QtLingo/releases/download/continuous/QtLingo-Ubuntu-Release-x64.zip)
-: office: [Windows x64 zip] (https://github.com/Light-Wizzard/QtLingo/releases/download/continuous/QtLingo-Windows-Release-x64.zip)
-: apple: [Apple x64 zip] (https://github.com/Light-Wizzard/QtLingo/releases/download/continuous/QtLingo-MacOs-Release-x64.zip)

Windows (Testet på 7 og 10, gi meg beskjed om 8 fungerer): Last ned zip og pakk det ut,
og kjør filen QtLingo.exe inne i implementeringsmappen AppDir.

Apple tester ikke fordi jeg ikke har en.

# Documentaion

Jeg prøver å få Doxygen -filene til å laste opp til dette nettstedet, men fungerer ikke så langt.
[Documentaion] (https://light-wizzard.github.io/QtLingo/)

# GitHub -prosjekter og andre prosjekter som brukes

Jeg bruker GitHub -applikasjoner for dette,
for oversettelser bruker jeg crow-translate på https://github.com/crow-translate/crow-translate,
og QOnlineTranslator på https://github.com/crow-translate/QOnlineTranslator,
og for å analysere .ts -filene bruker jeg ts_tool på https://github.com/nen777w/ts_tool,
og jeg brukte https://wiki.qt.io/Simple_encryption_with_SimpleCrypt#Versions.

# Prosess

Klikk først på Kompiler for å oppdatere prosjektene dine Oversettelsesfiler i henhold til språkene du har valgt,
Jeg kaller det kompilering fordi dette er alle filene som blir samlet inn i appen din,
klikk deretter på godta alle eller bruk Qt Lingustic for å fremheve hver oversettelse,
klikk deretter på oppdater Hjelp og ReadMe og Translations disse filene,
lage filer med en språkkode.

# Doxygen

Jeg bruker Doxygen, du kan kjøre den fra kommandoene nedenfor.

`` bash
doxygen Doxyfile

eller

doxywizard
``

Jeg har Doxygen Documents under docs.

# Problemer

Håndterer Internett -tilkoblingen.

``
Kritisk: "Socket -drift ble tidsavbrutt" (../QtLingo/src/MainWindow.cpp:2280, MainWindow :: translateWithReturn (const QString &, QOnlineTranslator :: Engine, QOnlineTranslator :: Language, QOnlineTranslator :: Language, QOnlineTranslator :: :: <lambda ()>)
Kritisk: "Host www.bing.com ikke funnet" (../QtLingo/src/MainWindow.cpp:2280, MainWindow :: translateWithReturn (const QString &, QOnlineTranslator :: Engine, QOnlineTranslator :: Language, QOnlineTranslator :: Language, QOnlineTranslator :: Språk) :: <lambda ()>)
Kritisk: "Host translate.yandex.com ikke funnet" (../QtLingo/src/MainWindow.cpp:2280, MainWindow :: translateWithReturn (const QString &, QOnlineTranslator :: Engine, QOnlineTranslator :: Language, QOnlineTranslator :: Language, QOnlineT :: Språk) :: <lambda ()>)
Kritisk: "Host translate.googleapis.com ikke funnet" (../QtLingo/src/MainWindow.cpp:2280, MainWindow :: translateWithReturn (const QString &, QOnlineTranslator :: Engine, QOnlineTranslator :: Language, QOnlineTranslator :: Language, QOnl :: Språk) :: <lambda ()>)

``

# Studiepoeng

Jeg brukte noen GitHub -prosjekter som jeg nevnte ovenfor, alt annet er
skrevet av Jeffrey Scott Flesher the Light Wizzard in the Flesh

### Slutt på filen