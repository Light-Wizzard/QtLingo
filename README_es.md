# QtLingo

QtLingo es una aplicación para facilitar las traducciones de Qt,
el flujo normal le haría editar archivos y reemplazar palabras con sus Traducciones,
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

## Estado

[! [Estado de compilación de Appveyor] (https://ci.appveyor.com/api/projects/status/j7htumuwfx31elf6?svg=true)] (https://ci.appveyor.com/project/Light-Wizzard/qtlingo)

###: paquete: ** Descargas: **

 -: pingüino: [zip de Linux] (https://github.com/Light-Wizzard/QtLingo/releases/download/continuous/QtLingo-Ubuntu-Release-x86.zip)
 -: oficina: [zip de Windows 64] (https://github.com/Light-Wizzard/QtLingo/releases/download/Windows64/QtLingo-Windows-x64.zip)
 -: apple: Actualmente no disponible [Apple zip] (https://github.com/Light-Wizzard/QtLingo/releases/download/continuous/QtLingo.zip)

# Documentación

Estoy tratando de que los archivos de Doxygen se carguen en este sitio, pero no estoy funcionando hasta ahora.
[Documentación] (https://light-wizzard.github.io/QtLingo/)

# Proyectos de GitHub y otros proyectos utilizados

Utilizo las aplicaciones de GitHub para esto,
para traducciones utilizo crow-translate en https://github.com/crow-translate/crow-translate,
y QOnlineTranslator en https://github.com/crow-translate/QOnlineTranslator,
y para analizar los archivos .ts utilizo ts_tool en https://github.com/nen777w/ts_tool,
y usé https://wiki.qt.io/Simple_encryption_with_SimpleCrypt#Versions.

# Proceso

Primero haga clic en Compilar para actualizar los archivos de traducción de sus proyectos de acuerdo con los idiomas que haya elegido,
Lo llamo compilar porque estos son todos los archivos que se compilan en su aplicación,
luego haga clic en aceptar todo o use Qt Lingustic para aceptar cada traducción,
luego haga clic en actualizar la Ayuda y Léame y Traducciones esos archivos,
creando archivos con un código de idioma.

# Doxygen

Traté de documentar usando Doxygen, puede ejecutarlo desde los siguientes comandos.

`` bash
doxygen Doxyfile

o

doxywizard
''

# Problemas

Lidiando con la conexión a Internet cayendo.

''
Crítico: "Operación de socket agotado" (../QtLingo/src/MainWindow.cpp:2280, MainWindow :: translateWithReturn (const QString &, QOnlineTranslator :: Engine, QOnlineTranslator :: Language, QOnlineTranslator :: Language, QOnlineTranslator :: Language) :: <lambda ()>)
Crítico: "Host www.bing.com no encontrado" (../QtLingo/src/MainWindow.cpp:2280, MainWindow :: translateWithReturn (const QString &, QOnlineTranslator :: Engine, QOnlineTranslator :: Language, QOnlineTranslator :: Language, QOnlineTranslator :: Idioma) :: <lambda ()>)
Crítico: "Host translate.yandex.com no encontrado" (../QtLingo/src/MainWindow.cpp:2280, MainWindow :: translateWithReturn (const QString &, QOnlineTranslator :: Engine, QOnlineTranslator :: Language, QOnlineTranslator :: Language, QOnlineTranslator :: Idioma) :: <lambda ()>)
Crítico: "Host translate.googleapis.com no encontrado" (../QtLingo/src/MainWindow.cpp:2280, MainWindow :: translateWithReturn (const QString &, QOnlineTranslator :: Engine, QOnlineTranslator :: Language, QOnlineTranslator :: Language, QOnlineTranslator :: Idioma) :: <lambda ()>)

''

# Créditos

Usé algunos proyectos de GitHub que enumeré anteriormente, todo lo demás es
escrito por Jeffrey Scott Flesher the Light Wizzard in the Flesh

### Fin del documento