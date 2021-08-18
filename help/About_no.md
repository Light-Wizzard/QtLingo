# QtLingo Om

QtLingo er et program for å gjøre Qt Computer Translations enklere,
og noe jeg aldri har sett før,
så det er et nytt konsept for Qt Translations.

Den normale flyten vil at du skal redigere filer og erstatte ord med oversettelsene,
Dette er for mye arbeid for meg å gjøre,
så jeg bestemte meg for å gjøre det enklere,
kjør denne applikasjonen og sett opp et prosjekt ved å gi den mappens plassering og navnet på prosjektet ditt,
gi den plasseringen der du vil ha .ts -filene,
og en destinasjon for .qm -filene,
og kompilere det,
og det vil gi deg konfigurasjonen for qmake eller cmake,
og bare oppdater filene dine med den koden,
og distribuer prosjektet ditt,
alt er gjort, ingenting mer å gjøre.

Jeg bruker GitHub -applikasjoner for dette,
for oversettelser bruker jeg crow-translate på https://github.com/crow-translate/crow-translate,
og QOnlineTranslator på https://github.com/crow-translate/QOnlineTranslator,
og for å analysere .ts -filene bruker jeg ts_tool på https://github.com/nen777w/ts_tool.

Først vil jeg oppdatere prosjektene dine Oversettelsesfiler i henhold til språkene du har valgt,
så vil jeg oversette alle språkene,
oppdater deretter Translations -filene og kompiler dem til .qm -filer for distribusjon.

Skrevet av Jeffrey Scott Flesher