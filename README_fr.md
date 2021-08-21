# Calculatrice Galaxie 2

Galaxy Calculator 2 intègre 4 calculatrices :

1. :milky_way : Calculatrice Galatique
2. :confused: Calculatrice de folie
3. :earth_americas: Calculatrice de planètes
4. :ordinateur: Calculatrice

J'ai utilisé les fichiers de projet de ma première calculatrice Galaxy qui est écrite en utilisant Qt QML et JavaScript,
celui-ci utilise Qt C++, et Widgets,
donc la documentation peut être farfelue jusqu'à ce que j'aie une chance de réparer tous les liens et de les convertir en ce nouveau projet,
Je vais devoir faire des projets Travis et AppYeyer, c'est donc un travail en cours.

Les calculateurs Galaxy, Madness et Planet sont basés sur les calculs de Sir Isaac Newtons,
et a été mis à jour pour inclure le Math Nikola Tesla,
inventant ainsi un nouveau type de mathématiques que j'appelle les mathématiques trinaires, qui sont utilisées pour calculer la galaxie.

Ce projet est Open Source, sans licence requise, il s'agit d'une application Qt C++,
qui s'exécutera sur le bureau et d'autres appareils, le script bash que j'ai utilisé pour le portage vers cette application est inclus.

Cette application peut être compilée pour n'importe quel système d'exploitation pris en charge par Qt : Linux, Windows, MAC, Android et iOS,
ainsi que tous les systèmes d'exploitation pris en charge par Qt, cela devrait donc fonctionner sur la plupart, sinon tous les systèmes d'exploitation populaires.

Je vais essayer de créer des programmes d'installation et des exécutables pour tous les systèmes d'exploitation Qt pris en charge, actuellement j'ai :

Si les badges sont verts, vous devriez pouvoir télécharger les applications, si ce n'est pas le cas,
il se peut que je travaille dessus, mais la mise à jour ne prend que quelques minutes.

Ce projet est en cours, donc les fichiers peuvent se casser, mais le code source devrait s'exécuter s'il est compilé sur n'importe quelle machine.

Le Qt Installer Framework fonctionne pour Linux et peut-être Windows mais le programme d'installation ne se téléchargera pas,
au travail, j'ai un installateur pour Windows 10 ci-dessous, pas sûr de 8, mais pas 7.

## Table des matières

1. [Statut](https://github.com/Light-Wizzard/Galaxy-Calculator-2#Status)
2. [Développement-Progrès](https://github.com/Light-Wizzard/Galaxy-Calculator-2#Development-Progress)
3. [Contexte] (https://github.com/Light-Wizzard/Galaxy-Calculator-2#Background)
4. [Captures d'écran] (https://github.com/Light-Wizzard/Galaxy-Calculator-2#Screen-Shots)
5. [Captures d'écran] (https://github.com/Light-Wizzard/Galaxy-Calculator-2#3rd-Party-Code)
6. [Wiki](https://github.com/Light-Wizzard/Galaxy-Calculator-2/wiki)
7. [Documentation Doxygen](https://light-wizzard.github.io/Galaxy-Calculator-2)

# Statut

[![Appveyor Build Status](https://ci.appveyor.com/api/projects/status/j7htumuwfx31elf6?svg=true)](https://ci.appveyor.com/project/Light-Wizzard/Galaxy- Calculatrice-2)

## :package : **Téléchargements :**

 - :pingouin: [Linux](https://github.com/Light-Wizzard/Galaxy-Calculator-2/releases/download/continuous/Galaxy-Calculator-2-x86_64.AppImage)
 - :penguin: :inbox_tray: [Linux ZSync](https://github.com/Light-Wizzard/Galaxy-Calculator-2/releases/download/continuous/Galaxy-Calculator-2-x86_64.AppImage.zsync)
 - :penguin: :outbox_tray: [Linux Installer in work](https://github.com/Light-Wizzard/Galaxy-Calculator-2/releases/download/continuous/Galaxy-Calculator-2-Linux-Installer)
 - :office : [Windows zip](https://github.com/Light-Wizzard/Galaxy-Calculator-2/releases/download/continuous/GalaxyCalculator2-Windows.zip)
 - :office: :outbox_tray: [Windows Installer exe](https://github.com/Light-Wizzard/Galaxy-Calculator-2/releases/download/continuous/GalaxyCalculator2.exe)
 - :apple : [Apple](https://github.com/Light-Wizzard/Galaxy-Calculator-2/releases/download/continuous/Galaxy-Calculator-2.dmg)

Windows (Testé sur 7 et 10, dites-moi si 8 fonctionne) : Téléchargez zip et extrayez-le, puis exécutez le fichier Galaxy-Calculator-2.exe à l'intérieur du dossier de déploiement.

Tous mes livres sont gratuits en ligne sur http://LightWizzard.com, mais les imprimer ou envoyer des ePubs sur votre appareil coûte de l'argent.

Je ne publie pas mes livres ici, vous pouvez les lire gratuitement sur mon
[Compte Github Light-Wizzard/The-Principles-Of-The-Trinary-Universe](https://github.com/Light-Wizzard/The-Principles-Of-The-Trinary-Universe),
mais vous devez payer pour des livres imprimés, ou la facilité d'avoir un ePub livré via vos appareils ePub Reader, sans avoir à le télécharger.

Livre imprimé et ePub disponible sur :

Loulou
* :livre: :ordinateur: http://www.lulu.com/spotlight/LightWizzard

Amazone
* :book: Book https://www.amazon.com/Principles-Trinary-Universe-according-Johannes/dp/1795429186/
* :ordinateur : ePub https://www.amazon.com/Principles-Trinary-Universe-according-Johannes-ebook/dp/B086D24HX9

Vous pouvez également l'obtenir dans n'importe quelle grande librairie, mais je vous recommande de le lire, si vous voulez connaître tous les détails sur les mathématiques, vous ne les trouverez pas autant dans le code.

Si vous ne voyez pas votre système d'exploitation, téléchargez-le, extrayez-le dans un dossier et ouvrez-le avec Qt Creator, qui doit être installé, et compilez ou exécutez-le.

# Avancement du développement

Vous devez comprendre la science trinaire et l'univers trinaire pour comprendre le calculateur galactique,
mais fondamentalement Trinary a la même signification que Trinity a fait à Sir Isaac Newton, il décrit et courant alternatif ou AC,
le Père est le +1, le Fils est le -1, et le Saint-Esprit ou Esprit de Mère Nature est 0, donc c'est la Logique Trinaire avec : +1, -1 et 0 comme Niveaux Logiques,
J'utilise le nom Trinaire parce que Newton détestait l'Enseignement du Christ.

Il y a un écran de configuration où vous configurez le Galaxy, vous pouvez nommer le Galaxy, définir sa taille de soleil en miles de diamètre,
définir sa taille de planètes vivantes en miles de diamètre, définir le nombre de moteurs trinaires, voir l'aide pour plus de détails,
et le rayon de la galaxie en miles de diamètre et le nombre de pistes que vous souhaitez imprimer.

J'ai supprimé la fonctionnalité de stockage local en raison des autorisations sur certains appareils.

# Fond

Le calculateur Galaxy est un simple clic pour calculer, il enregistre le numéro de piste, combien de moteurs trinaires il faut pour être sur cette piste,
sa vitesse minimale et maximale du soleil en milles par heure, la fréquence des planètes habitables, la distance orbitale du soleil en milles et la fréquence des pistes,
que Sir Isaac Newton a utilisé pour déterminer quand la fin de la civilisation se produira, et selon son et mon calcul,
cela se produira en 2060 sous le calendrier julien encore utilisé par les militaires, ou en 2061 sous le calendrier grégorien en usage aujourd'hui,
c'était le même calcul donné au Public, mais peu savent comment il l'a calculé, j'ai écrit une nouvelle formule, car je n'ai pas pu trouver son équation d'origine.

Sir Isaac Newton a brûlé sa copie de son calcul de 2060, il a écrit que cela pèse lourd sur son ÂME, il a donc dû laisser tomber,
et a écrit que quiconque veut savoir, peut le comprendre, toutes les formules sont dans la Bible, 36 ans plus tard, je les ai toutes trouvées.

Cette calculatrice Galaxy a été écrite pour être utilisée, après avoir pensé au script bash qui a créé cette page :

http://LightWizzard.com/books/trinary.universe/appendix.a.html

Le script bash a non seulement créé la page, mais a également calculé les valeurs de la table.

J'espère que cela aidera tout le monde à visualiser ce que l'application doit faire, c'est-à-dire uniquement tracer et tracer le chemin des étoiles autour de la galaxie.

Ce n'est pas un simulateur Galaxy, seulement un graphique et un tracé, et c'est très important à comprendre,
Je voudrais écrire un Galaxy Simulator construit en utilisant uniquement les lois et règles ou l'électronique,
et ce projet s'appellera un simulateur Galaxy, et pourquoi ce projet ne s'appelle qu'un Calculatrice Galaxie,
mais je cherche à utiliser Qt 3D Studio pour simuler un simulateur.

Pour plus d'informations, consultez : [Wiki](https://github.com/Light-Wizzard/Galaxy-Calculator-2/wiki)

Il s'agit d'un travail en cours, veuillez signaler tout bug et faire des commentaires.

# Captures d'écran

![Configuration Galaxy](/doc/images/screenshot-config.png?raw=true "Configuration Galaxy")

![Galaxy Calculator](/doc/images/screenshot-galaxy.png?raw=true "Galaxy Calculator")

![Calculateur d'énergie](/doc/images/screenshot-energy.png?raw=true "Calculateur d'énergie")

![Calculateur de folie](/doc/images/screenshot-madness.png?raw=true "Calculateur de folie")

![Calculatrice mondiale](/doc/images/screenshot-world.png?raw=true "Calculatrice planétaire")

![Calculatrice](/doc/images/screenshot-calc.png?raw=true "Calculatrice")


# Code tiers

[QCalculator](https://github.com/xenotux/qcalc)
https://github.com/xenotux/qcalc

DLL GMP pour Windows
https://osdn.net/projects/mingw/releases/69295

MPFR Dll pour Windows
https://osdn.net/projects/mingw/releases/69297


Fin du fichier README.md