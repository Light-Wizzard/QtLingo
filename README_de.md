# Galaxie-Rechner 2

In Galaxy Calculator 2 sind 4 Rechner integriert:

1. :milky_way: Galatischer Rechner
2. :verwirrt: Wahnsinnsrechner
3. :earth_americas: Planetenrechner
4. :Computer: Rechner

Ich habe die Projektdateien meines ersten Galaxy-Rechners verwendet, der mit Qt QML und JavaScript geschrieben wurde.
dieser verwendet Qt C++ und Widgets,
Daher kann die Dokumentation verrückt sein, bis ich eine Chance habe, alle Links zu reparieren und sie in dieses neue Projekt zu konvertieren,
Ich werde Travis- und AppYeyer-Projekte machen müssen, also ist dies noch in Arbeit.

Die Galaxy-, Madness- und Planet-Rechner basieren auf den Berechnungen von Sir Isaac Newton.
und wurde aktualisiert, um den Math Nikola Tesla aufzunehmen,
Damit erfinde ich eine neue Art von Mathematik, die ich Trinary Mathematics nenne, die verwendet wird, um die Galaxie zu berechnen.

Dieses Projekt ist Open Source, keine Lizenz erforderlich, dies ist eine Qt C++ App.
das auf Desktop und anderen Geräten ausgeführt wird, das Bash-Skript, das ich zum Portieren auf diese App verwendet habe, ist enthalten.

Diese App kann für jedes von Qt unterstützte Betriebssystem kompiliert werden: Linux, Windows, MAC, Android und iOS,
sowie jedes Betriebssystem, das Qt unterstützt, daher sollte dies auf den meisten, wenn nicht allen gängigen Betriebssystemen laufen.

Ich werde versuchen, Installer für alle unterstützten Qt-Betriebssysteme ausführbar und ausführbar zu machen, derzeit habe ich:

Wenn die Abzeichen grün sind, sollten Sie die Apps herunterladen können, wenn nicht,
Es kann sein, dass ich daran arbeite, aber das Update dauert nur ein paar Minuten.

Dieses Projekt ist in Arbeit, daher können Dateien beschädigt werden, aber der Quellcode sollte ausgeführt werden, wenn er auf einem beliebigen Computer kompiliert wird.

Das Qt Installer Framework funktioniert für Linux und möglicherweise Windows, aber das Installationsprogramm wird nicht heruntergeladen.
In der Arbeit habe ich unten ein Installationsprogramm für Windows 10, bin mir bei 8 nicht sicher, aber nicht bei 7.

## Inhaltsverzeichnis

1. [Status](https://github.com/Light-Wizzard/Galaxy-Calculator-2#Status)
2. [Entwicklungsfortschritt](https://github.com/Light-Wizzard/Galaxy-Calculator-2#Entwicklungsfortschritt)
3. [Hintergrund](https://github.com/Light-Wizzard/Galaxy-Calculator-2#Hintergrund)
4. [Screenshots](https://github.com/Light-Wizzard/Galaxy-Calculator-2#Screen-Shots)
5. [Screenshots](https://github.com/Light-Wizzard/Galaxy-Calculator-2#3rd-Party-Code)
6. [Wiki](https://github.com/Light-Wizzard/Galaxy-Calculator-2/wiki)
7. [Doxygen-Dokumentation](https://light-wizzard.github.io/Galaxy-Calculator-2)

# Status

[![Appveyor-Build-Status](https://ci.appveyor.com/api/projects/status/j7htumuwfx31elf6?svg=true)](https://ci.appveyor.com/project/Light-Wizzard/Galaxy- Rechner-2)

## :Paket: **Downloads:**

 - :Pinguin: [Linux](https://github.com/Light-Wizzard/Galaxy-Calculator-2/releases/download/continuous/Galaxy-Calculator-2-x86_64.AppImage)
 - :pinguin: :inbox_tray: [Linux ZSync](https://github.com/Light-Wizzard/Galaxy-Calculator-2/releases/download/continuous/Galaxy-Calculator-2-x86_64.AppImage.zsync)
 - :pinguin: :outbox_tray: [Linux Installer in Arbeit](https://github.com/Light-Wizzard/Galaxy-Calculator-2/releases/download/continuous/Galaxy-Calculator-2-Linux-Installer)
 - :office: [Windows zip](https://github.com/Light-Wizzard/Galaxy-Calculator-2/releases/download/continuous/GalaxyCalculator2-Windows.zip)
 - :office: :outbox_tray: [Windows Installer exe](https://github.com/Light-Wizzard/Galaxy-Calculator-2/releases/download/continuous/GalaxyCalculator2.exe)
 - :apple: [Apple](https://github.com/Light-Wizzard/Galaxy-Calculator-2/releases/download/continuous/Galaxy-Calculator-2.dmg)

Windows (auf 7 und 10 getestet, lassen Sie mich wissen, ob 8 funktioniert): Laden Sie die ZIP-Datei herunter, entpacken Sie sie und führen Sie die Datei Galaxy-Calculator-2.exe im Bereitstellungsordner aus.

Alle meine Bücher sind kostenlos online unter http://LightWizzard.com erhältlich, aber es kostet Geld, sie auszudrucken oder ePubs auf Ihr Gerät zu übertragen.

Ich veröffentliche meine Bücher hier nicht, Sie können sie kostenlos auf meinem lesen
[Github-Account Light-Wizzard/The-Principles-Of-The-Trinary-Universe](https://github.com/Light-Wizzard/The-Principles-Of-The-Trinary-Universe),
Sie müssen jedoch für gedruckte Bücher bezahlen oder für die einfache Lieferung eines ePub über den ePub-Reader Ihres Geräts, ohne es herunterladen zu müssen.

Gedrucktes Buch und ePub Erhältlich bei:

Lulu
* :Buch: :Computer: http://www.lulu.com/spotlight/LightWizzard

Amazonas
* :Buch: Buch https://www.amazon.com/Principles-Trinary-Universe-according-Johannes/dp/1795429186/
* :Computer: ePub https://www.amazon.com/Principles-Trinary-Universe-according-Johannes-ebook/dp/B086D24HX9

Sie können es auch in jedem größeren Buchladen bekommen, aber ich würde empfehlen, es zu lesen, wenn Sie alle Details über die Mathematik wissen möchten, werden Sie sie nicht so oft im Code finden.

Wenn Sie Ihr Betriebssystem nicht sehen, laden Sie es einfach herunter, extrahieren Sie es in einen Ordner und öffnen Sie es mit Qt Creator, das installiert sein muss, und kompilieren Sie es oder führen Sie es aus.

# Entwicklungsfortschritt

Sie müssten die Trinäre Wissenschaft und das Trinäre Universum verstehen, um den Galaxienrechner zu verstehen.
aber im Grunde hat Trinary die gleiche Bedeutung wie Trinity für Sir Isaac Newton, es beschreibt und Alternating Current oder AC,
der Vater ist die +1, der Sohn ist die -1 und der Heilige Geist oder der Geist von Mutter Natur ist 0, also ist es Trinäre Logik mit: +1, -1 und 0 als Logikebenen,
Ich verwende den Namen Trinär, weil Newton die Lehre Christi hasste.

Es gibt einen Konfigurationsbildschirm, in dem Sie die Galaxie konfigurieren, Sie können die Galaxie benennen, ihre Sonnengröße in Meilen in Durchmesser einstellen,
Legen Sie die Größe des Living Planets in Meilen im Durchmesser fest, legen Sie die Anzahl der Trinary Engines fest, siehe Hilfe für weitere Details,
und den Radius der Galaxie in Meilen im Durchmesser und wie viele Tracks Sie drucken möchten.

Ich habe die lokale Speicherfunktion aufgrund von Berechtigungen auf einigen Geräten entfernt.

# Hintergrund

Der Galaxy-Rechner ist mit einem Klick zu berechnen, er zeichnet die Track-Nummer auf, wie viele Trinary Engines es braucht, um auf diesem Track zu sein,
seine minimale und maximale Sonnengeschwindigkeit in Meilen pro Stunde, die Frequenz der bewohnbaren Planeten, die Umlaufentfernung der Sonnen in Meilen und die Frequenz der Spuren,
die Sir Isaac Newton verwendet hat, um zu bestimmen, wann das Ende der Zivilisation eintreten wird, und nach seiner und meiner Berechnung,
das wird im Jahr 2060 nach dem Julianischen Kalender passieren, der noch vom Militär verwendet wird, oder 2061 nach dem Gregorianischen Kalender, der heute verwendet wird,
Dies war dieselbe Berechnung, die der Öffentlichkeit vorgelegt wurde, aber nur wenige wissen, wie er sie berechnet hat. Ich schrieb eine neue Formel, weil ich seine ursprüngliche Gleichung nicht finden konnte.

Sir Isaac Newton verbrannte seine Kopie seiner 2060-Kalkulation, er schrieb, dass sie schwer auf seiner SEELE lastet, also musste er sie gehen lassen.
und schrieb, dass jeder, der es wissen will, es herausfinden kann, alle Formeln stehen in der Bibel, 36 Jahre später habe ich sie alle gefunden.

Dieser Galaxy-Rechner wurde für den Gebrauch geschrieben, nachdem ich über das Bash-Skript nachgedacht habe, das diese Seite erstellt hat:

http://LightWizzard.com/books/trinary.universe/appendix.a.html

Das Bash-Skript hat nicht nur die Seite erstellt, sondern auch die Tabellenwerte berechnet.

Ich hoffe, dies hilft jedem, sich vorzustellen, was die Anwendung tun muss, nämlich nur den Weg der Sterne um die Galaxie grafisch darzustellen und zu zeichnen.

Dies ist kein Galaxy Simulator, sondern nur ein Graph und ein Plot, und das ist sehr wichtig zu verstehen.
Ich möchte einen Galaxy Simulator schreiben, der nur mit den Gesetzen und Regeln oder der Elektronik gebaut wurde.
und dieses Projekt wird Galaxy Simulator genannt, und warum dieses Projekt nur als a . bezeichnet wird Galaxie-Rechner,
aber ich überlege, mit Qt 3D Studio einen Simulator zu simulieren.

Weitere Informationen finden Sie unter: [Wiki](https://github.com/Light-Wizzard/Galaxy-Calculator-2/wiki)

Dies ist in Arbeit, bitte melden Sie alle Fehler und Kommentare.

# Screenshots

![Galaxy-Konfiguration](/doc/images/screenshot-config.png?raw=true "Galaxy-Konfiguration")

![Galaxie-Rechner](/doc/images/screenshot-galaxy.png?raw=true "Galaxie-Rechner")

![Energierechner](/doc/images/screenshot-energy.png?raw=true "Energierechner")

![Wahnsinnsrechner](/doc/images/screenshot-madness.png?raw=true "Wahnsinnsrechner")

![Weltenrechner](/doc/images/screenshot-world.png?raw=true "Planetenrechner")

![Rechner](/doc/images/screenshot-calc.png?raw=true "Rechner")


# Drittanbietercode

[QCalculator](https://github.com/xenotux/qcalc)
https://github.com/xenotux/qcalc

GMP-Dll für Windows
https://osdn.net/projects/mingw/releases/69295

MPFR-Dll für Windows
https://osdn.net/projects/mingw/releases/69297


Ende von README.md