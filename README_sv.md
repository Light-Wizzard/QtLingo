# Galaxy Calculator 2

Galaxy Calculator 2 har 4 räknare inbyggda i den:

1.: milky_way: Galatic Calculator
2.: confounded: Madness Calculator
3.: earth_americas: Planet Calculator
4.: dator: Miniräknare

Jag använde projektfilerna från min första Galaxy Calculator som är skriven med Qt QML och JavaScript,
den här använder Qt C ++ och widgets,
så dokumentationen kan vara galen tills jag har en chans att fixa alla länkar och konvertera dem till detta nya projekt,
Jag måste göra Travis och AppYeyer -projekt, så detta är ett pågående arbete.

Galax-, galenskaps- och planetkalkylatorerna är baserade på Sir Isaac Newtons beräkningar,
och uppdaterades för att inkludera Math Nikola Tesla,
därmed uppfinna en ny typ av matematik som jag kallar Trinary Mathematics, som används för att beräkna galaxen.

Detta projekt är öppen källkod, utan licens krävs, detta är en Qt C ++ - app,
som körs på skrivbordet och andra enheter, bash -skriptet som jag använde för att överföra till den här appen ingår.

Denna app kan kompileras för alla operativsystem som Qt stöder: Linux, Windows, MAC, Android och iOS,
liksom alla operativsystem som Qt stöder, så detta bör köras på de flesta om inte alla populära operativsystemen.

Jag kommer att försöka göra installatörer och körbara för alla Qt -operativsystem som stöds, för närvarande har jag:

Om märkena är gröna bör du kunna ladda ner apparna, om de inte är det,
det kan vara så att jag arbetar med det, men det tar bara några minuter att uppdatera.

Detta projekt pågår, så filer kan gå sönder, men källkoden bör köras om den kompileras på någon maskin.

Qt Installer Framework fungerar för Linux och kanske Windows men installationsprogrammet laddas inte ner,
i arbete har jag ett installationsprogram för Windows 10 nedan, inte säker på 8, men inte 7.

## Innehållsförteckning

1. [Status] (https://github.com/Light-Wizzard/Galaxy-Calculator-2#Status)
2. [Development-Progress] (https://github.com/Light-Wizzard/Galaxy-Calculator-2#Development-Progress)
3. [Bakgrund] (https://github.com/Light-Wizzard/Galaxy-Calculator-2#Background)
4. [Screen-Shots] (https://github.com/Light-Wizzard/Galaxy-Calculator-2#Screen-Shots)
5. [Screen-Shots] (https://github.com/Light-Wizzard/Galaxy-Calculator-2#3rd-Party-Code)
6. [Wiki] (https://github.com/Light-Wizzard/Galaxy-Calculator-2/wiki)
7. [Doxygen Documention] (https://light-wizzard.github.io/Galaxy-Calculator-2)

# Status

[! [Status för Appveyor Build] [https://ci.appveyor.com/api/projects/status/j7htumuwfx31elf6?svg=true]] (https://ci.appveyor.com/project/Light-Wizzard/Galaxy- Kalkylator-2)

##: paket: ** Nedladdningar: **

 -: penguin: [Linux] (https://github.com/Light-Wizzard/Galaxy-Calculator-2/releases/download/continuous/Galaxy-Calculator-2-x86_64.AppImage)
 -: penguin:: inbox_tray: [Linux ZSync] (https://github.com/Light-Wizzard/Galaxy-Calculator-2/releases/download/continuous/Galaxy-Calculator-2-x86_64.AppImage.zsync)
 -: penguin:: outbox_tray: [Linux Installer in work] (https://github.com/Light-Wizzard/Galaxy-Calculator-2/releases/download/continuous/Galaxy-Calculator-2-Linux-Installer)
 -: office: [Windows zip] (https://github.com/Light-Wizzard/Galaxy-Calculator-2/releases/download/continuous/GalaxyCalculator2-Windows.zip)
 -: office:: outbox_tray: [Windows Installer exe] (https://github.com/Light-Wizzard/Galaxy-Calculator-2/releases/download/continuous/GalaxyCalculator2.exe)
 -: apple: [Apple] (https://github.com/Light-Wizzard/Galaxy-Calculator-2/releases/download/continuous/Galaxy-Calculator-2.dmg)

Windows (Testat på 7 och 10 meddela mig om 8 fungerar): Ladda ner zip och extrahera det och kör filen Galaxy-Calculator-2.exe inuti distributionsmappen.

Alla mina böcker är gratis online på http://LightWizzard.com, men det kostar pengar att skriva ut dem eller skjuta ePubs till din enhet.

Jag publicerar inte mina böcker här, du kan läsa dem gratis på min
[Github-konto Light-Wizzard/The-Principles-Of-The-Trinary-Universe] (https://github.com/Light-Wizzard/The-Principles-Of-The-Trinary-Universe),
men du måste betala för tryckta böcker, eller enkelt för att få en ePub levererad via dina ePub -läsare utan att behöva ladda ner den.

Tryckt bok och ePub Finns på:

Lulu
*: bok:: dator: http://www.lulu.com/spotlight/LightWizzard

Amazon
*: bok: Boka https://www.amazon.com/Principles-Trinary-Universe-according-Johannes/dp/1795429186/
*: dator: ePub https://www.amazon.com/Principles-Trinary-Universe-according-Johannes-ebook/dp/B086D24HX9

Du kan också få den i vilken större bokhandel som helst, men jag skulle rekommendera att läsa den, om du vill veta alla detaljer om matematiken hittar du dem inte så mycket i koden.

Om du inte ser ditt operativsystem, bara ladda ner, extrahera till en mapp och öppna med Qt Creator, som måste installeras, och kompilera eller köra den.

# Utvecklingsframsteg

Du måste förstå Trinary Science och Trinary Universe för att förstå Galaxy Calculator,
men i grunden har Trinary samma innebörd som Trinity gjorde för Sir Isaac Newton, den beskriver och växelström eller växelström,
Fadern är +1, Sonen är -1, och den Helige Anden eller Ande av Moder Natur är 0, så det är Trinary Logic med: +1, -1 och 0 som logiska nivåer,
Jag använder namnet Trinary eftersom Newton hatade Kristi undervisning.

Det finns en konfigurationsskärm där du konfigurerar galaxen, du kan namnge galaxen, ställa in dess solstorlek i mil i diameter,
ställ in dess Living Planets Size i Miles i Diameter, ställ in antalet Trinary Motorer, se Hjälp för mer information,
och Radius of of the Galaxy in Miles in Diameter, och hur många spår du vill skriva ut.

Jag tog bort funktionen för lokal lagring på grund av behörigheter på vissa enheter.

# Bakgrund

Galaxy Calculator är ett klick med ett knapptryck för att beräkna, det registrerar spårnumret, hur många trinmotorer som krävs för att vara på det spåret,
dess solars lägsta och högsta hastighet i mil i timmen, frekvensen för livliga planeter, solens orbitalavstånd i mil och spårfrekvensen,
som Sir Isaac Newton använde för att avgöra när civilisationens slut kommer att hända, och enligt hans och min beräkning,
det kommer att hända år 2060 enligt den julianska kalendern som fortfarande används av militären, eller 2061 under den gregorianska kalendern som används idag,
detta var samma beräkning som gavs till allmänheten, men få vet hur han beräknade det, jag skrev en ny formel, eftersom jag inte kunde hitta hans ursprungliga ekvation.

Sir Isaac Newton brände sitt exemplar av hans 2060 -beräkning, han skrev att det tynger tungt på hans SJÄL, så han var tvungen att släppa det,
och skrev att alla som vill veta kan förstå det, alla formler finns i Bibeln, 36 år senare hittade jag dem alla.

Denna Galaxy Calculator skrevs för användning, efter att jag tänkte på bash -skriptet som skapade den här sidan:

http://LightWizzard.com/books/trinary.universe/appendix.a.html

Bash -skriptet skapade inte bara sidan utan beräknade tabellvärdena.

Jag hoppas att detta hjälper alla att visualisera vad applikationen behöver göra, vilket bara är att rita och plotta stjärnornas väg runt galaxen.

Detta är inte en Galaxy Simulator, bara en graf och ett diagram, och det är mycket viktigt att förstå,
Jag skulle vilja skriva en Galaxy Simulator byggd med endast lagar och regler eller elektronik,
och det projektet kommer att kallas en Galaxy Simulator, och varför detta projekt bara kallas a Galaxy Calculator,
men jag funderar på att använda Qt 3D Studio för att simulera en simulator.

För mer information se: [Wiki] (https://github.com/Light-Wizzard/Galaxy-Calculator-2/wiki)

Detta pågår, rapportera eventuella buggar och kommentarer.

# Skärmbilder

! [Galaxy Configuration] (/doc/images/screenshot-config.png? Raw = true "Galaxy Configuration")

! [Galaxy Calculator] (/doc/images/screenshot-galaxy.png? Raw = true "Galaxy Calculator")

! [Energikalkylator] (/doc/images/screenshot-energy.png? Raw = true "Energy Calculator")

! [Madness Calculator] (/doc/images/screenshot-madness.png? Raw = true "Madness Calculator")

! [World Calculator] (/doc/images/screenshot-world.png? Raw = true "Planet Calculator")

! [Kalkylator] (/doc/images/screenshot-calc.png? Raw = true "Calculator")


# Tredjepartskod

[QCalculator] (https://github.com/xenotux/qcalc)
https://github.com/xenotux/qcalc

GMP Dll för Windows
https://osdn.net/projects/mingw/releases/69295

MPFR Dll för Windows
https://osdn.net/projects/mingw/releases/69297


Slut på README.md