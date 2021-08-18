# QtLingo À propos

QtLingo est une application pour faciliter les traductions informatiques de Qt,
et quelque chose que je n'ai jamais vu auparavant,
c'est donc un nouveau concept pour Qt Translations.

Le flux normal vous obligerait à modifier les fichiers et à remplacer les mots par leurs traductions,
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

J'utilise les applications GitHub pour cela,
pour les traductions, j'utilise crow-translate sur https://github.com/crow-translate/crow-translate,
et QOnlineTranslator sur https://github.com/crow-translate/QOnlineTranslator,
et pour analyser les fichiers .ts, j'utilise ts_tool sur https://github.com/nen777w/ts_tool.

Dans un premier temps, je mettrai à jour les fichiers de traductions de vos projets en fonction des langues que vous avez choisies,
alors je traduirai toutes les langues,
puis mettez à jour les fichiers de traduction et compilez-les dans des fichiers .qm pour le déploiement.

Écrit par Jeffrey Scott Flesher