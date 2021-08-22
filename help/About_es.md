# QtLingo Acerca de

QtLingo es una aplicación para facilitar las traducciones de Qt Computer,
y algo que nunca había visto antes,
por lo que es un nuevo concepto para Qt Translations.

El flujo normal le haría editar archivos y reemplazar palabras con sus Traducciones,
esto es demasiado trabajo para mí,
así que decidí hacérselo más fácil
ejecute esta aplicación y configure un proyecto dándole la ubicación de la carpeta y el nombre de su proyecto,
dale la ubicación donde quieres los archivos .ts,
y un destino para los archivos .qm,
y compilarlo,
y te dará la configuración para qmake o cmake,
y simplemente actualice sus archivos con ese código,
y despliegue su proyecto,
todo está hecho, nada más que hacer.

Utilizo las aplicaciones de GitHub para esto,
para traducciones utilizo crow-translate en https://github.com/crow-translate/crow-translate,
y QOnlineTranslator en https://github.com/crow-translate/QOnlineTranslator,
y para analizar los archivos .ts utilizo ts_tool en https://github.com/nen777w/ts_tool.

Primero actualizaré los archivos de traducción de sus proyectos de acuerdo con los idiomas que haya elegido,
luego traduciré todos los idiomas,
luego actualice los archivos de traducción y compílelos en archivos .qm para su implementación.

Escrito por Jeffrey Scott Flesher