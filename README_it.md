# Calcolatrice Galassia 2

Galaxy Calculator 2 ha 4 Calcolatrici integrate:

1. : milky_way: calcolatrice galattica
2. :confuso: Calcolatrice di follia
3. :earth_americas: Calcolatrice del pianeta
4. :computer: Calcolatrice

Ho usato i file di progetto del mio primo Galaxy Calculator scritto usando Qt QML e JavaScript,
questo usa Qt C++ e Widget,
quindi la documentazione potrebbe essere stravagante finché non avrò la possibilità di sistemare tutti i collegamenti e convertirli in questo nuovo progetto,
Dovrò realizzare progetti per Travis e AppYeyer, quindi questo è un lavoro in corso.

I calcolatori Galaxy, Madness e Planet si basano sui calcoli di Sir Isaac Newton,
ed è stato aggiornato per includere il Math Nikola Tesla,
inventando così un nuovo tipo di Matematica che chiamo Matematica Trinaria, che viene utilizzata per Calcolare la Galassia.

Questo progetto è Open Source, senza licenza richiesta, questa è un'app Qt C++,
che verrà eseguito su desktop e altri dispositivi, è incluso lo script bash che ho usato per il porting su questa app.

Questa App può essere compilata per qualsiasi sistema operativo supportato da Qt: Linux, Windows, MAC, Android e iOS,
così come tutti i sistemi operativi supportati da Qt, quindi dovrebbe funzionare sulla maggior parte se non su tutti i sistemi operativi più diffusi.

Cercherò di creare programmi di installazione ed eseguibili per tutti i sistemi operativi Qt supportati, attualmente ho:

Se i badge sono verdi, dovresti essere in grado di scaricare le app, in caso contrario,
potrebbe essere che ci sto lavorando, ma l'aggiornamento richiede solo pochi minuti.

Questo progetto è funzionante, quindi i file potrebbero rompersi, ma il codice sorgente dovrebbe essere eseguito se compilato su qualsiasi macchina.

Il Qt Installer Framework funziona per Linux e forse Windows ma il programma di installazione non verrà scaricato,
al lavoro, ho un programma di installazione per Windows 10 di seguito, non sono sicuro di 8, ma non di 7.

## Tabella dei contenuti

1. [Stato](https://github.com/Light-Wizzard/Galaxy-Calculator-2#Status)
2. [Progresso-sviluppo](https://github.com/Light-Wizzard/Galaxy-Calculator-2#Progresso-sviluppo)
3. [Sfondo](https://github.com/Light-Wizzard/Galaxy-Calculator-2#Sfondo)
4. [Screen-Shots](https://github.com/Light-Wizzard/Galaxy-Calculator-2#Screen-Shots)
5. [Screen-Shots](https://github.com/Light-Wizzard/Galaxy-Calculator-2#3rd-Party-Code)
6. [Wiki](https://github.com/Light-Wizzard/Galaxy-Calculator-2/wiki)
7. [Documentazione Doxygen](https://light-wizzard.github.io/Galaxy-Calculator-2)

# Stato

[![Stato build Appveyor](https://ci.appveyor.com/api/projects/status/j7htumuwfx31elf6?svg=true)](https://ci.appveyor.com/project/Light-Wizzard/Galaxy- Calcolatrice-2)

## :pacchetto: **Download:**

 - :penguin: [Linux](https://github.com/Light-Wizzard/Galaxy-Calculator-2/releases/download/continuous/Galaxy-Calculator-2-x86_64.AppImage)
 - :penguin: :inbox_tray: [Linux ZSync](https://github.com/Light-Wizzard/Galaxy-Calculator-2/releases/download/continuous/Galaxy-Calculator-2-x86_64.AppImage.zsync)
 - :penguin: :outbox_tray: [Linux Installer in lavoro](https://github.com/Light-Wizzard/Galaxy-Calculator-2/releases/download/continuous/Galaxy-Calculator-2-Linux-Installer)
 - :office: [Windows zip](https://github.com/Light-Wizzard/Galaxy-Calculator-2/releases/download/continuous/GalaxyCalculator2-Windows.zip)
 - :office: :outbox_tray: [Windows Installer exe](https://github.com/Light-Wizzard/Galaxy-Calculator-2/releases/download/continuous/GalaxyCalculator2.exe)
 - :apple: [Apple](https://github.com/Light-Wizzard/Galaxy-Calculator-2/releases/download/continuous/Galaxy-Calculator-2.dmg)

Windows (testato su 7 e 10 fammi sapere se 8 funziona): scarica zip ed estrailo ed esegui il file Galaxy-Calculator-2.exe all'interno della cartella di distribuzione.

Tutti i miei libri sono gratuiti online su http://LightWizzard.com, ma è costoso stamparli o inviare ePub al tuo dispositivo.

Non pubblico i miei libri qui, puoi leggerli gratuitamente sul mio
[Account Github Light-Wizzard/The-Principles-Of-The-Trinary-Universe](https://github.com/Light-Wizzard/The-Principles-Of-The-Trinary-Universe),
ma devi pagare per i libri stampati, o la facilità di avere un ePub consegnato tramite i tuoi dispositivi ePub Reader, senza doverlo scaricare.

Libro cartaceo ed ePub Disponibile su:

Lulu
* :book: :computer: http://www.lulu.com/spotlight/LightWizzard

Amazon
* :book: Prenota https://www.amazon.com/Principles-Trinary-Universe-according-Johannes/dp/1795429186/
* :computer: ePub https://www.amazon.com/Principles-Trinary-Universe-according-Johannes-ebook/dp/B086D24HX9

Puoi anche prenderlo in qualsiasi grande libreria, ma ti consiglio di leggerlo, se vuoi conoscere tutti i dettagli sulla matematica, non li troverai tanto nel codice.

Se non vedi il tuo sistema operativo, scarica, estrai in una cartella e apri con Qt Creator, che deve essere installato, e compilalo o eseguilo.

# Progressi dello sviluppo

Dovresti capire la scienza trinaria e l'universo trinario per capire il calcolatore della galassia,
ma fondamentalmente Trinary ha lo stesso significato che Trinity diede a Sir Isaac Newton, descrive e Alternating Current o AC,
il Padre è il +1, il Figlio è il -1 e lo Spirito Santo o Spirito di Madre Natura è 0, quindi è Logica Trinaria con: +1, -1 e 0 come Livelli logici,
Uso il nome Trinary perché Newton odiava l'Insegnamento di Cristo.

C'è una schermata di configurazione in cui si configura il Galaxy, è possibile nominare il Galaxy, impostare la sua dimensione del sole in miglia di diametro,
impostare la dimensione dei pianeti viventi in miglia di diametro, impostare il numero di motori trinari, vedere la Guida per maggiori dettagli,
e il raggio della galassia in miglia di diametro e quante tracce si desidera stampare.

Ho rimosso la funzione di archiviazione locale a causa delle autorizzazioni su alcuni dispositivi.

# Sfondo

Il Galaxy Calculator è un clic con un solo pulsante per calcolare, registra il numero di traccia, quanti motori trinari ci vogliono per essere su quella traccia,
la sua velocità minima e massima del sole in miglia all'ora, la frequenza dei pianeti vivibili, la distanza orbitale del sole in miglia e la frequenza delle tracce,
che Sir Isaac Newton usava per determinare quando sarebbe avvenuta la Fine della Civiltà, e secondo il suo e il mio calcolo,
che accadrà nell'anno 2060 sotto il calendario giuliano ancora usato dai militari, o nel 2061 sotto il calendario gregoriano in uso oggi,
questo era lo stesso calcolo dato al Pubblico, ma pochi sanno come lo ha calcolato, ho scritto una nuova formula, perché non riuscivo a trovare la sua equazione originale.

Sir Isaac Newton ha bruciato la sua copia del suo Calcolo del 2060, ha scritto che pesa molto sulla sua ANIMA, quindi ha dovuto lasciarlo andare,
e ha scritto che chiunque voglia sapere, può capirlo, tutte le formule sono nella Bibbia, 36 anni dopo le ho trovate tutte.

Questo Galaxy Calculator è stato scritto per l'uso, dopo aver pensato allo script bash che ha creato questa pagina:

http://LightWizzard.com/books/trinary.universe/apppendix.a.html

Lo script bash non solo ha creato la pagina, ma ha calcolato i valori della tabella.

Spero che questo aiuti tutti a visualizzare ciò che l'Applicazione deve fare, che è solo tracciare e tracciare il percorso delle Stelle intorno alla Galassia.

Questo non è un Galaxy Simulator, solo un grafico e un diagramma, e questo è molto importante da capire,
Vorrei scrivere un simulatore Galaxy costruito utilizzando solo le leggi e le regole o l'elettronica,
e quel progetto si chiamerà Galaxy Simulator, e perché questo progetto si chiama solo a Calcolatrice Galassia,
ma sto cercando di usare Qt 3D Studio per simulare un simulatore.

Per ulteriori informazioni, vedere: [Wiki](https://github.com/Light-Wizzard/Galaxy-Calculator-2/wiki)

Questo è un lavoro in corso, si prega di segnalare eventuali bug e commenti.

# Schermate

![Configurazione Galaxy](/doc/images/screenshot-config.png?raw=true "Configurazione Galaxy")

![Calcolatrice Galassia](/doc/images/screenshot-galaxy.png?raw=true "Calcolatrice Galassia")

![Calcolatore di energia](/doc/images/screenshot-energy.png?raw=true "Calcolatore di energia")

![Calcolatore di follia](/doc/images/screenshot-madness.png?raw=true "Calcolatore di follia")

![Calcolatore del mondo](/doc/images/screenshot-world.png?raw=true "Calcolatore del pianeta")

![Calcolatrice](/doc/images/screenshot-calc.png?raw=true "Calcolatrice")


# Codice di terze parti

[QCalculator](https://github.com/xenotux/qcalc)
https://github.com/xenotux/qcalc

DLL GMP per Windows
https://osdn.net/projects/mingw/releases/69295

DLL MPFR per Windows
https://osdn.net/projects/mingw/releases/69297


Fine di README.md