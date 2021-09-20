# QtLingo

QtLingo è un'applicazione per rendere più facili le traduzioni di Qt,
il flusso normale ti farebbe modificare i file e sostituire le parole con le loro traduzioni,
questo è troppo lavoro da fare per me,
così ho deciso di renderlo più facile,
esegui questa applicazione e imposta un progetto assegnandogli la posizione della cartella e il nome del tuo progetto,
assegnagli la posizione in cui desideri i file .ts,
e una destinazione per i file .qm,
e compilalo,
e ti darà la configurazione per qmake o cmake,
e aggiorna i tuoi file con quel codice,
e distribuisci il tuo progetto,
è tutto fatto, niente più da fare.

## Stato

[![Stato build Appveyor](https://ci.appveyor.com/api/projects/status/j7htumuwfx31elf6?svg=true)](https://ci.appveyor.com/project/Light-Wizzard/qtlingo)

### :pacchetto: **Download:**

- :penguin: [Zip Linux x64](https://github.com/Light-Wizzard/QtLingo/releases/download/continuous/QtLingo-Ubuntu-Release-x64.zip)
- :office: [Windows x64 zip](https://github.com/Light-Wizzard/QtLingo/releases/download/continuous/QtLingo-Windows-Release-x64.zip)
- :apple: [Apple x64 zip](https://github.com/Light-Wizzard/QtLingo/releases/download/continuous/QtLingo-MacOs-Release-x64.zip)

Windows (testato su 7 e 10 fammi sapere se 8 funziona): scarica zip ed estrailo,
ed esegui il file QtLingo.exe all'interno della cartella deploy AppDir.

Apple non prova perché non ne ho uno.

# Documentazione

Sto cercando di caricare i file Doxygen su questo sito, ma finora non funziona.
[Documentazione](https://light-wizzard.github.io/QtLingo/)

# Progetti GitHub e altri progetti utilizzati

Uso le applicazioni GitHub per questo,
per le traduzioni utilizzo crow-translate su https://github.com/crow-translate/crow-translate,
e QOnlineTranslator su https://github.com/crow-translate/QOnlineTranslator,
e per analizzare i file .ts uso ts_tool su https://github.com/nen777w/ts_tool,
e ho usato https://wiki.qt.io/Simple_encryption_with_SimpleCrypt#Versions.

# Processi

Per prima cosa fai clic su Compila per aggiornare i file di traduzione dei tuoi progetti in base alle lingue che hai scelto,
Lo chiamo compilazione perché questi sono tutti i file che vengono compilati nella tua app,
quindi fai clic su accetta tutto o usa Qt Lingustic per accettare ogni traduzione,
quindi fai clic su aggiorna i file di Aiuto e Leggimi e Traduzioni,
creazione di file con un codice lingua.

# Doxygen

Uso Doxygen, puoi eseguirlo dai comandi seguenti.

```bash
doxygen Doxyfile

o

doxywizard
```

Ho documenti Doxygen sotto docs.

# I problemi

Affrontare la connessione a Internet in calo.

```
Critico: "Operazione socket scaduta" (../QtLingo/src/MainWindow.cpp:2280, MainWindow::translateWithReturn(const QString&, QOnlineTranslator::Engine, QOnlineTranslator::Language, QOnlineTranslator::Language, QOnlineTranslator) ::<lambda()>)
Critico: "Host www.bing.com non trovato" (../QtLingo/src/MainWindow.cpp:2280, MainWindow::translateWithReturn(const QString&, QOnlineTranslator::Engine, QOnlineTranslator::Language, QOnlineTranslator::Language, QOnline ::Lingua)::<lambda()>)
Critico: "Host translate.yandex.com non trovato" (../QtLingo/src/MainWindow.cpp:2280, MainWindow::translateWithReturn(const QString&, QOnlineTranslator::Engine, QOnlineTranslator::Language, QOnlineTranslator::Language, QOnline ::Lingua)::<lambda()>)
Critico: "Host translate.googleapis.com non trovato" (../QtLingo/src/MainWindow.cpp:2280, MainWindow::translateWithReturn(const QString&, QOnlineTranslator::Engine, QOnlineTranslator::Language, QOnlineTranslator::Language, QOnline ::Lingua)::<lambda()>)

```

# Titoli di coda

Ho usato alcuni progetti GitHub che ho elencato sopra, tutto il resto lo è
scritto da Jeffrey Scott Flesher il mago della luce nella carne

### Fine del file