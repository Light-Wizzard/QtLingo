# QtLingo Über

QtLingo ist eine Anwendung, um Qt-Computerübersetzungen zu vereinfachen,
und etwas, das ich noch nie gesehen habe,
es ist also ein neues Konzept für Qt Translations.

Im normalen Ablauf würden Sie Dateien bearbeiten und Wörter durch ihre Übersetzungen ersetzen.
Das ist zu viel Arbeit für mich,
Also beschloss ich, es einfacher zu machen,
Führen Sie diese Anwendung aus und richten Sie ein Projekt ein, indem Sie ihm den Ordnerspeicherort und den Namen Ihres Projekts angeben.
Geben Sie den Speicherort für die .ts-Dateien an,
und ein Ziel für die .qm-Dateien,
und kompiliere es,
und es gibt Ihnen die Konfiguration für qmake oder cmake,
und aktualisieren Sie einfach Ihre Dateien mit diesem Code,
und stellen Sie Ihr Projekt bereit,
es ist alles fertig, nichts mehr zu tun.

Ich verwende dafür GitHub-Anwendungen,
für Übersetzungen verwende ich crow-translate unter https://github.com/crow-translate/crow-translate,
und QOnlineTranslator unter https://github.com/crow-translate/QOnlineTranslator,
und zum Parsen der .ts-Dateien verwende ich ts_tool unter https://github.com/nen777w/ts_tool.

Zuerst werde ich Ihre Projekt-Übersetzungsdateien entsprechend den von Ihnen ausgewählten Sprachen aktualisieren,
dann übersetze ich alle Sprachen,
Aktualisieren Sie dann die Übersetzungsdateien und kompilieren Sie sie für die Bereitstellung in .qm-Dateien.

Geschrieben von Jeffrey Scott Flesher