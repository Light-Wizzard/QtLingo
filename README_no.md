# Galaxy Calculator 2

Galaxy Calculator 2 har 4 kalkulatorer innebygd i den:

1.: milky_way: Galatic Calculator
2.: forvirret: Madness Calculator
3.: earth_americas: Planet Calculator
4.: datamaskin: Kalkulator

Jeg brukte prosjektfilene fra min første Galaxy Calculator som er skrevet med Qt QML og JavaScript,
denne bruker Qt C ++ og widgets,
så dokumentasjonen kan være gal til jeg får sjansen til å fikse alle koblingene og konvertere dem til dette nye prosjektet,
Jeg må lage Travis og AppYeyer -prosjekter, så dette er et pågående arbeid.

Galaxy, Madness og Planet kalkulatorer er basert på Sir Isaac Newtons beregninger,
og ble oppdatert for å inkludere Math Nikola Tesla,
og dermed oppfinne en ny type matematikk jeg kaller Trinary Mathematics, som brukes til å beregne galaksen.

Dette prosjektet er åpen kildekode, uten lisens nødvendig, dette er en Qt C ++ - app,
som vil kjøre på stasjonære datamaskiner og andre enheter, er bash -skriptet jeg brukte til å overføre til denne appen inkludert.

Denne appen kan kompileres for alle operativsystemer som Qt støtter: Linux, Windows, MAC, Android og iOS,
så vel som alle operativsystemer som Qt støtter, så dette bør kjøre på de fleste om ikke alle populære operativsystemene.

Jeg skal prøve å gjøre installatører og kjørbare for alle støttede Qt OS -er, for tiden har jeg:

Hvis merkene er grønne, bør du kunne laste ned appene, hvis de ikke er det,
Det kan være at jeg jobber med det, men det tar bare noen få minutter å oppdatere.

Dette prosjektet er i arbeid, så filer kan gå i stykker, men kildekoden bør kjøres hvis den kompileres på en hvilken som helst maskin.

Qt Installer Framework fungerer for Linux og kanskje Windows, men installatøren vil ikke laste ned,
i arbeid, har jeg et installasjonsprogram for Windows 10 nedenfor, ikke sikker på om 8, men ikke 7.

## Innholdsfortegnelse

1. [Status] (https://github.com/Light-Wizzard/Galaxy-Calculator-2#Status)
2. [Development-Progress] (https://github.com/Light-Wizzard/Galaxy-Calculator-2#Development-Progress)
3. [Bakgrunn] (https://github.com/Light-Wizzard/Galaxy-Calculator-2#Background)
4. [Skjermbilder] (https://github.com/Light-Wizzard/Galaxy-Calculator-2#Screen-Shots)
5. [Skjermbilder] (https://github.com/Light-Wizzard/Galaxy-Calculator-2#3rd-Party-Code)
6. [Wiki] (https://github.com/Light-Wizzard/Galaxy-Calculator-2/wiki)
7. [Doxygen Documention] (https://light-wizzard.github.io/Galaxy-Calculator-2)

# Status

[! [Status for transportørbygger] (https://ci.appveyor.com/api/projects/status/j7htumuwfx31elf6?svg=true)] (https://ci.appveyor.com/project/Light-Wizzard/Galaxy- Kalkulator-2)

##: pakke: ** Nedlastinger: **

 -: penguin: [Linux] (https://github.com/Light-Wizzard/Galaxy-Calculator-2/releases/download/continuous/Galaxy-Calculator-2-x86_64.AppImage)
 -: penguin:: inbox_tray: [Linux ZSync] (https://github.com/Light-Wizzard/Galaxy-Calculator-2/releases/download/continuous/Galaxy-Calculator-2-x86_64.AppImage.zsync)
 -: penguin:: outbox_tray: [Linux Installer in work] (https://github.com/Light-Wizzard/Galaxy-Calculator-2/releases/download/continuous/Galaxy-Calculator-2-Linux-Installer)
 -: office: [Windows zip] (https://github.com/Light-Wizzard/Galaxy-Calculator-2/releases/download/continuous/GalaxyCalculator2-Windows.zip)
 -: office:: outbox_tray: [Windows Installer exe] (https://github.com/Light-Wizzard/Galaxy-Calculator-2/releases/download/continuous/GalaxyCalculator2.exe)
 -: apple: [Apple] (https://github.com/Light-Wizzard/Galaxy-Calculator-2/releases/download/continuous/Galaxy-Calculator-2.dmg)

Windows (Testet på 7 og 10, gi meg beskjed om 8 fungerer): Last ned zip og pakk det ut, og kjør filen Galaxy-Calculator-2.exe inne i distribusjonsmappen.

Alle bøkene mine er gratis online på http://LightWizzard.com, men det koster penger å skrive dem ut eller skyve ePubs til enheten din.

Jeg offentliggjør ikke bøkene mine her, du kan lese dem gratis på min
[Github-konto Light-Wizzard/The-Principles-Of-The-Trinary-Universe] (https://github.com/Light-Wizzard/The-Principles-Of-The-Trinary-Universe),
men du må betale for trykte bøker, eller enkelt for å få en ePub levert via ePub Reader på enhetene dine, uten å måtte laste den ned.

Trykt bok og ePub Tilgjengelig på:

Lulu
*: bok:: datamaskin: http://www.lulu.com/spotlight/LightWizzard

Amazon
*: bok: Bestill https://www.amazon.com/Principles-Trinary-Universe-according-Johannes/dp/1795429186/
*: datamaskin: ePub https://www.amazon.com/Principles-Trinary-Universe-according-Johannes-ebook/dp/B086D24HX9

Du kan også få den i hvilken som helst større bokhandel, men jeg vil anbefale å lese den. Hvis du vil vite alle detaljene om matematikken, finner du dem ikke så mye i koden.

Hvis du ikke ser operativsystemet, kan du bare laste ned, pakke ut til en mappe og åpne med Qt Creator, som må installeres, og kompilere eller kjøre den.

# Utviklingsfremgang

Du må forstå Trinary Science og Trinary Universe for å forstå Galaxy Calculator,
men i utgangspunktet har Trinary samme betydning som Trinity gjorde for Sir Isaac Newton, den beskriver og vekselstrøm eller vekselstrøm,
Faderen er +1, Sønnen er -1, og Den hellige ånd eller mors naturånd er 0, så det er Trinary Logic med: +1, -1 og 0 som logiske nivåer,
Jeg bruker navnet Trinary fordi Newton hatet Kristi lære.

Det er en konfigurasjonsskjerm der du konfigurerer galaksen, du kan navngi galaksen, angi solstørrelsen i mil i diameter,
angi størrelsen på Living Planets in Miles in Diameter, angi antall trinemotorer, se Hjelp for flere detaljer,
og Radius of of the Galaxy in Miles in Diameter, og hvor mange spor du vil skrive ut.

Jeg fjernet funksjonen for lokal lagring på grunn av tillatelser på noen enheter.

# Bakgrunn

Galaxy Calculator er et klikk med ett knapp for å beregne, det registrerer spornummeret, hvor mange trinemotorer det tar å være på det sporet,
solens minimums- og maksimalhastighet i miles i timen, frekvensen av levbare planeter, solens orbitalavstand i miles og sporfrekvensen,
som Sir Isaac Newton brukte for å bestemme når slutten av sivilisasjonen vil skje, og i henhold til hans og min beregning,
det vil skje i år 2060 under den julianske kalenderen som fortsatt brukes av militæret, eller 2061 under den gregorianske kalenderen som er i bruk i dag,
dette var den samme beregningen som ble gitt til offentligheten, men få vet hvordan han regnet det ut, jeg skrev en ny formel, fordi jeg ikke fant hans opprinnelige ligning.

Sir Isaac Newton brente sin kopi av beregningen fra 2060, han skrev at den veier tungt på SJELEN hans, så han måtte la den gå.
og skrev at alle som vil vite, kan finne ut av det, alle formlene er i Bibelen, 36 år senere fant jeg dem alle.

Denne Galaxy Calculator ble skrevet for bruk, etter at jeg tenkte på bash -skriptet som opprettet denne siden:

http://LightWizzard.com/books/trinary.universe/appendix.a.html

Bash -skriptet lagde ikke bare siden, men beregnet tabellverdiene.

Jeg håper dette hjelper alle med å visualisere hva programmet trenger å gjøre, som bare er å tegne og plotte banen til stjernene rundt galaksen.

Dette er ikke en Galaxy Simulator, bare en graf og et diagram, og det er veldig viktig å forstå,
Jeg vil skrive en Galaxy Simulator bygget bare med lover og regler eller elektronikk,
og det prosjektet vil bli kalt en Galaxy Simulator, og hvorfor dette prosjektet bare kalles a Galaxy Calculator,
men jeg ser etter å bruke Qt 3D Studio for å simulere en simulator.

For mer informasjon, se: [Wiki] (https://github.com/Light-Wizzard/Galaxy-Calculator-2/wiki)

Dette pågår, vennligst rapporter eventuelle feil og kommentarer.

# Skjermbilder

! [Galaxy Configuration] (/doc/images/screenshot-config.png? Raw = true "Galaxy Configuration")

! [Galaxy Calculator] (/doc/images/screenshot-galaxy.png? Raw = true "Galaxy Calculator")

! [Energikalkulator] (/doc/images/screenshot-energy.png? Raw = true "Energy Calculator")

! [Madness Calculator] (/doc/images/screenshot-madness.png? Raw = true "Madness Calculator")

! [World Calculator] (/doc/images/screenshot-world.png? Raw = true "Planet Calculator")

! [Kalkulator] (/doc/images/screenshot-calc.png? Raw = true "Calculator")


# Tredjeparts kode

[QCalculator] (https://github.com/xenotux/qcalc)
https://github.com/xenotux/qcalc

GMP Dll for Windows
https://osdn.net/projects/mingw/releases/69295

MPFR Dll for Windows
https://osdn.net/projects/mingw/releases/69297


Slutt på README.md