# QtLingo

QtLingo est une application pour rendre les traductions Qt plus faciles,
le flux normal vous obligerait à modifier les fichiers et à remplacer les mots par leurs traductions,
c'est trop de travail pour moi,
alors j'ai décidé de faire plus facile,
lancez cette Application et configurez un projet en lui donnant l'emplacement du dossier et le nom de votre projet,
donnez-lui l'emplacement où vous voulez les fichiers .ts,
et une destination pour les fichiers .qm,
et compilez-le,
et il vous donnera la configuration pour qmake ou cmake,
et mettez simplement à jour vos fichiers avec ce code,
et déployez votre projet,
tout est fait, plus rien à faire.

## Statut

[![État de la version Appveyor](https://ci.appveyor.com/api/projects/status/j7htumuwfx31elf6?svg=true)](https://ci.appveyor.com/project/Light-Wizzard/qtlingo)

### :package : **Téléchargements :**

 - :pingouin : [Linux zip](https://github.com/Light-Wizzard/QtLingo/releases/download/continuous/QtLingo-Ubuntu-Release-x86.zip)
 - :office : [Windows 64 zip](https://github.com/Light-Wizzard/QtLingo/releases/download/Windows64/QtLingo-Windows-x64.zip)
 - :apple : actuellement indisponible [Apple zip](https://github.com/Light-Wizzard/QtLingo/releases/download/continuous/QtLingo.zip)

# Documentation

J'essaie de télécharger les fichiers Doxygen sur ce site, cela ne fonctionne pas jusqu'à présent.
[Documentation](https://light-wizzard.github.io/QtLingo/)

# Projets GitHub et autres projets utilisés

J'utilise les applications GitHub pour cela,
pour les traductions, j'utilise crow-translate sur https://github.com/crow-translate/crow-translate,
et QOnlineTranslator sur https://github.com/crow-translate/QOnlineTranslator,
et pour analyser les fichiers .ts, j'utilise ts_tool sur https://github.com/nen777w/ts_tool,
et j'ai utilisé https://wiki.qt.io/Simple_encryption_with_SimpleCrypt#Versions.

# Traiter

Cliquez d'abord sur Compiler pour mettre à jour les fichiers de traductions de vos projets en fonction des Langues que vous avez choisies,
Je l'appelle compiler car ce sont tous les fichiers qui sont compilés dans votre application,
puis cliquez sur accepter tout ou utilisez Qt Lingustic pour accepter chaque traduction,
puis cliquez sur mettre à jour l'aide et le fichier Lisez-moi et les traductions de ces fichiers,
créer des fichiers avec un code de langue.

# Doxygène

J'ai essayé de documenter l'utilisation de Doxygen, vous pouvez l'exécuter à partir des commandes ci-dessous.

```bash
doxygen Doxyfile

ou

magicien doxy
```

# Problèmes

Faire face à la connexion Internet en panne.

```
Critique : "L'opération de socket a expiré" (../QtLingo/src/MainWindow.cpp:2280, MainWindow::translateWithReturn(const QString&, QOnlineTranslator::Engine, QOnlineTranslator::Language, QOnlineTranslator::Language, QLanguageTranslator):: ::<lambda()>)
Critique : "Host www.bing.com introuvable" (../QtLingo/src/MainWindow.cpp:2280, MainWindow::translateWithReturn(const QString&, QOnlineTranslator::Engine, QOnlineTranslator::Language, QOnlineTranslator::Language, QOnlineTranslator ::Langue)::<lambda()>)
Critique : "Host translate.yandex.com not found" (../QtLingo/src/MainWindow.cpp:2280, MainWindow::translateWithReturn(const QString&, QOnlineTranslator::Engine, QOnlineTranslator::Language, QOnlineTranslator::Language, QOnlineTranslator ::Langue)::<lambda()>)
Critique : "Host translate.googleapis.com introuvable" (../QtLingo/src/MainWindow.cpp:2280, MainWindow::translateWithReturn(const QString&, QOnlineTranslator::Engine, QOnlineTranslator::Language, QOnlineTranslator::Language, QOnlineTranslator ::Langue)::<lambda()>)

```

# Crédits

J'ai utilisé quelques projets GitHub que j'ai énumérés ci-dessus, tout le reste est
écrit par Jeffrey Scott Flesher le magicien de la lumière dans la chair

### Fin de fichier