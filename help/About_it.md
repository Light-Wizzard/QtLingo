# QtLingo Informazioni

QtLingo è un'applicazione per rendere più facili le traduzioni di Qt Computer,
e qualcosa che non ho mai visto prima,
quindi è un nuovo concetto per Qt Translations.

Il flusso normale ti farebbe modificare i file e sostituire le parole con le loro traduzioni,
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

Uso le applicazioni GitHub per questo,
per le traduzioni utilizzo crow-translate su https://github.com/crow-translate/crow-translate,
e QOnlineTranslator su https://github.com/crow-translate/QOnlineTranslator,
e per analizzare i file .ts utilizzo ts_tool su https://github.com/nen777w/ts_tool.

Per prima cosa aggiornerò i file delle traduzioni dei tuoi progetti in base alle lingue che hai scelto,
poi tradurrò tutte le lingue,
quindi aggiorna i file Translations e compilali in file .qm per la distribuzione.

Scritto da Jeffrey Scott Flesher