# Galaxy Calculadora 2

Galaxy Calculator 2 tiene 4 calculadoras integradas:

1.: milky_way: Calculadora galáctica
2.: confundido: Calculadora de locura
3.: earth_americas: Planet Calculator
4.: computadora: calculadora

Usé los archivos del proyecto de mi primera calculadora Galaxy que está escrita usando Qt QML y JavaScript,
este usa Qt C ++ y Widgets,
por lo que la documentación puede ser loca hasta que tenga la oportunidad de arreglar todos los enlaces y convertirlos a este nuevo proyecto,
Tendré que hacer proyectos de Travis y AppYeyer, así que este es un trabajo en progreso.

Las calculadoras Galaxy, Madness y Planet se basan en los cálculos de Sir Isaac Newton,
y se actualizó para incluir Math Nikola Tesla,
inventando así un nuevo tipo de Matemáticas que llamo Matemáticas Trinarias, que se utiliza para Calcular la Galaxia.

Este proyecto es de código abierto, no se requiere licencia, esta es una aplicación Qt C ++,
que se ejecutará en el escritorio y otros dispositivos, se incluye el script bash que solía portar a esta aplicación.

Esta aplicación se puede compilar para cualquier sistema operativo compatible con Qt: Linux, Windows, MAC, Android e iOS,
así como todos los sistemas operativos compatibles con Qt, por lo que debería ejecutarse en la mayoría, si no en todos, los sistemas operativos más populares.

Intentaré hacer instaladores y ejecutables para todos los sistemas operativos Qt compatibles, actualmente tengo:

Si las insignias son verdes, debería poder descargar las aplicaciones, si no lo son,
puede ser que esté trabajando en ello, pero solo me llevará unos minutos actualizarlo.

Este proyecto está en funcionamiento, por lo que los archivos pueden romperse, pero el código fuente debe ejecutarse si se compila en cualquier máquina.

El marco de instalación de Qt funciona para Linux y tal vez para Windows, pero el instalador no se descarga,
en el trabajo, tengo un instalador para Windows 10 a continuación, no estoy seguro de 8, pero no 7.

## Tabla de contenidos

1. [Estado] (https://github.com/Light-Wizzard/Galaxy-Calculator-2#Status)
2. [Desarrollo-Progreso] (https://github.com/Light-Wizzard/Galaxy-Calculator-2#Development-Progress)
3. [Fondo] (https://github.com/Light-Wizzard/Galaxy-Calculator-2#Background)
4. [Capturas de pantalla] (https://github.com/Light-Wizzard/Galaxy-Calculator-2#Screen-Shots)
5. [Capturas de pantalla] (https://github.com/Light-Wizzard/Galaxy-Calculator-2#3rd-Party-Code)
6. [Wiki] (https://github.com/Light-Wizzard/Galaxy-Calculator-2/wiki)
7. [Documentación de Doxygen] (https://light-wizzard.github.io/Galaxy-Calculator-2)

# Estado

[! [Estado de compilación de Appveyor] (https://ci.appveyor.com/api/projects/status/j7htumuwfx31elf6?svg=true)] (https://ci.appveyor.com/project/Light-Wizzard/Galaxy- Calculadora-2)

##: paquete: ** Descargas: **

 -: pingüino: [Linux] (https://github.com/Light-Wizzard/Galaxy-Calculator-2/releases/download/continuous/Galaxy-Calculator-2-x86_64.AppImage)
 -: pingüino:: bandeja de entrada: [Linux ZSync] (https://github.com/Light-Wizzard/Galaxy-Calculator-2/releases/download/continuous/Galaxy-Calculator-2-x86_64.AppImage.zsync)
 -: penguin:: outbox_tray: [Instalador de Linux en funcionamiento] (https://github.com/Light-Wizzard/Galaxy-Calculator-2/releases/download/continuous/Galaxy-Calculator-2-Linux-Installer)
 -: oficina: [zip de Windows] (https://github.com/Light-Wizzard/Galaxy-Calculator-2/releases/download/continuous/GalaxyCalculator2-Windows.zip)
 -: office:: outbox_tray: [Windows Installer exe] (https://github.com/Light-Wizzard/Galaxy-Calculator-2/releases/download/continuous/GalaxyCalculator2.exe)
 -: manzana: [Apple] (https://github.com/Light-Wizzard/Galaxy-Calculator-2/releases/download/continuous/Galaxy-Calculator-2.dmg)

Windows (probado en 7 y 10, avíseme si 8 funciona): descargue zip y extráigalo, y ejecute el archivo Galaxy-Calculator-2.exe dentro de la carpeta de implementación.

Todos mis libros son gratuitos en línea en http://LightWizzard.com, pero cuesta dinero imprimirlos o enviar ePubs a su dispositivo.

No estoy publicando mis libros aquí, puede leerlos gratis en mi
[Cuenta de Github Light-Wizzard / The-Principles-Of-The-Trinary-Universe] (https://github.com/Light-Wizzard/The-Principles-Of-The-Trinary-Universe),
pero tienes que pagar por los libros impresos, o la facilidad de recibir un ePub a través de tu dispositivo ePub Reader, sin tener que descargarlo.

Libro impreso y ePub disponibles en:

Lulú
*: libro:: computadora: http://www.lulu.com/spotlight/LightWizzard

Amazonas
*: libro: Libro https://www.amazon.com/Principles-Trinary-Universe-according-Johannes/dp/1795429186/
*: computadora: ePub https://www.amazon.com/Principles-Trinary-Universe-according-Johannes-ebook/dp/B086D24HX9

También puedes conseguirlo en cualquier librería importante, pero te recomiendo que lo leas, si quieres conocer todos los detalles sobre las matemáticas, no los encontrarás tanto en el código.

Si no ve su sistema operativo, simplemente descárguelo, extráigalo a una carpeta y ábralo con Qt Creator, que debe estar instalado y compílelo o ejecútelo.

# El progreso del desarrollo

Tendrías que entender la ciencia trinaria y el universo trinario para entender la calculadora de galaxias,
pero básicamente Trinary tiene el mismo significado que Trinity le dio a Sir Isaac Newton, describe una Corriente Alterna o CA,
el Padre es el +1, el Hijo es el -1, y el Espíritu Santo o Espíritu de la Madre Naturaleza es 0, por lo que es Lógica Trinaria con: +1, -1 y 0 como Niveles de Lógica,
Utilizo el nombre Trinary porque Newton odiaba la Enseñanza de Cristo.

Hay una pantalla de configuración en la que configura el Galaxy, puede nombrar el Galaxy, establecer su tamaño del sol en millas de diámetro,
establezca el tamaño de los planetas vivientes en millas de diámetro, establezca el número de motores trinarios, consulte la Ayuda para obtener más detalles,
y el radio de la galaxia en millas de diámetro, y cuántas pistas desea imprimir.

Eliminé la función de almacenamiento local debido a los permisos en algunos dispositivos.

# Fondo

La Calculadora Galaxy es un clic de un botón para calcular, registra el número de pista, cuántos motores trinarios se necesitan para estar en esa pista,
su velocidad mínima y máxima del Sol en millas por hora, la frecuencia de los planetas habitables, la distancia orbital del sol en millas y la frecuencia de las pistas,
que sir Isaac Newton usó para determinar cuándo sucederá el fin de la civilización, y de acuerdo con sus cálculos y los míos,
que sucederá en el año 2060 bajo el Calendario Juliano todavía usado por las Fuerzas Armadas, o 2061 bajo el Calendario Gregoriano en uso hoy,
Este fue el mismo cálculo que se le dio al Público, pero pocos saben cómo lo calculó, escribí una nueva fórmula, porque no pude encontrar su ecuación original.

Sir Isaac Newton quemó su copia de su Cálculo de 2060, escribió que pesa mucho en su ALMA, por lo que tuvo que dejarlo ir,
y escribí que cualquiera que quiera saber, puede resolverlo, todas las fórmulas están en la Biblia, 36 años después las encontré todas.

Esta calculadora Galaxy fue escrita para su uso, después de pensar en el script bash que creó esta página:

http://LightWizzard.com/books/trinary.universe/appendix.a.html

El script bash no solo creó la página, sino que también calculó los valores de la tabla.

Espero que esto ayude a todos a visualizar lo que la Aplicación necesita hacer, que es solo graficar y trazar el camino de las estrellas alrededor de la galaxia.

Esto no es un Galaxy Simulator, solo un gráfico y un diagrama, y ​​es muy importante entenderlo,
Me gustaría escribir un Galaxy Simulator construido usando solo las Leyes y Reglas o Electrónica,
y ese proyecto se llamará Galaxy Simulator, y por qué este proyecto solo se llama Calculadora de galaxias,
pero estoy buscando usar Qt 3D Studio para simular un simulador.

Para obtener más información, consulte: [Wiki] (https://github.com/Light-Wizzard/Galaxy-Calculator-2/wiki)

Este es un trabajo en progreso, informe cualquier error y comentario.

# Capturas de pantalla

! [Configuración de Galaxy] (/ doc / images / screenshot-config.png? Raw = true "Configuración de Galaxy")

! [Calculadora de galaxias] (/ doc / images / screenshot-galaxy.png? Raw = true "Calculadora de galaxias")

! [Calculadora de energía] (/ doc / images / screenshot-energy.png? Raw = true "Calculadora de energía")

! [Calculadora de locura] (/ doc / images / screenshot-madness.png? Raw = true "Calculadora de locura")

! [Calculadora mundial] (/ doc / images / screenshot-world.png? Raw = true "Calculadora planetaria")

! [Calculadora] (/ doc / images / screenshot-calc.png? Raw = true "Calculadora")


# Código de terceros

[QCalculator] (https://github.com/xenotux/qcalc)
https://github.com/xenotux/qcalc

GMP Dll para Windows
https://osdn.net/projects/mingw/releases/69295

MPFR Dll para Windows
https://osdn.net/projects/mingw/releases/69297


Fin de README.md