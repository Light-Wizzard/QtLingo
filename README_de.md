# QtLingo

QtLingo ist eine Anwendung, um Qt-Übersetzungen zu vereinfachen,
im normalen Ablauf würden Sie Dateien bearbeiten und Wörter durch ihre Übersetzungen ersetzen.
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

##Status

[![Appveyor-Build-Status](https://ci.appveyor.com/api/projects/status/j7htumuwfx31elf6?svg=true)](https://ci.appveyor.com/project/Light-Wizzard/qtlingo)

### :Paket: **Downloads:**

 - :pinguin: [Linux zip](https://github.com/Light-Wizzard/QtLingo/releases/download/continuous/QtLingo-Ubuntu-Release-x86.zip)
 - :office: [Windows 64 zip](https://github.com/Light-Wizzard/QtLingo/releases/download/Windows64/QtLingo-Windows-x64.zip)
 - :apple: Derzeit nicht verfügbar [Apple zip](https://github.com/Light-Wizzard/QtLingo/releases/download/continuous/QtLingo.zip)

# Dokumentation

Ich versuche, die Doxygen-Dateien auf diese Site hochzuladen, funktioniert bisher nicht.
[Dokumentation](https://light-wizzard.github.io/QtLingo/)

# GitHub-Projekte und andere verwendete Projekte

Ich verwende dafür GitHub-Anwendungen,
für Übersetzungen verwende ich crow-translate unter https://github.com/crow-translate/crow-translate,
und QOnlineTranslator unter https://github.com/crow-translate/QOnlineTranslator,
und zum Parsen der .ts-Dateien verwende ich ts_tool unter https://github.com/nen777w/ts_tool,
und ich habe https://wiki.qt.io/Simple_encryption_with_SimpleCrypt#Versions verwendet.

# Verfahren

Klicken Sie zuerst auf Kompilieren, um die Übersetzungsdateien Ihrer Projekte entsprechend den von Ihnen ausgewählten Sprachen zu aktualisieren.
Ich nenne es kompilieren, weil dies alle Dateien sind, die in Ihre App kompiliert werden.
Klicken Sie dann auf Alle akzeptieren oder verwenden Sie Qt Lingustic, um jede Übersetzung zu akzeptieren.
Klicken Sie dann auf Hilfe und ReadMe und Übersetzungen dieser Dateien aktualisieren,
Erstellen von Dateien mit einem Sprachcode.

# Sauerstoff

Ich habe versucht, die Verwendung von Doxygen zu dokumentieren. Sie können es mit den folgenden Befehlen ausführen.

```bash
Doxygen Doxyfile

oder

Doxymagier
```

# Probleme

Umgang mit Internetverbindung, die ausfällt.

```
Kritisch: "Zeitüberschreitung bei Socket-Operation" (../QtLingo/src/MainWindow.cpp:2280, MainWindow::translateWithReturn(const QString&, QOnlineTranslator::Engine, QOnlineTranslator::Language, QOnlineTranslator::Language, QOnlineTransgator)::Lan ::<lambda()>)
Kritisch: "Host www.bing.com nicht gefunden" (../QtLingo/src/MainWindow.cpp:2280, MainWindow::translateWithReturn(const QString&, QOnlineTranslator::Engine, QOnlineTranslator::Language, QOnlineTranslator::Language, QOnlineTranslator ::Sprache::<lambda()>)
Kritisch: "Host translate.yandex.com nicht gefunden" (../QtLingo/src/MainWindow.cpp:2280, MainWindow::translateWithReturn(const QString&, QOnlineTranslator::Engine, QOnlineTranslator::Language, QOnlineTranslator::Language, QOnlineTranslator ::Sprache::<lambda()>)
Kritisch: "Host translate.googleapis.com nicht gefunden" (../QtLingo/src/MainWindow.cpp:2280, MainWindow::translateWithReturn(const QString&, QOnlineTranslator::Engine, QOnlineTranslator::Language, QOnlineTranslator::Language, QOnlineTranslator ::Sprache::<lambda()>)

```

# Credits

Ich habe ein paar GitHub-Projekte verwendet, die ich oben aufgelistet habe, alles andere ist
geschrieben von Jeffrey Scott Flesher the Light Wizzard in the Flesh

### Ende der Datei