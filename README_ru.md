# QtLingo

QtLingo - это приложение, упрощающее перевод Qt,
в обычном потоке вы редактируете файлы и заменяете слова их переводами,
это слишком много для меня,
поэтому я решил упростить,
запустите это приложение и настройте проект, указав ему расположение папки и имя вашего проекта,
укажите место, где вы хотите файлы .ts,
и место назначения для файлов .qm,
и скомпилируйте его,
и он предоставит вам конфигурацию для qmake или cmake,
и просто обновите свои файлы этим кодом,
и разверните свой проект,
все сделано, больше нечего делать.

## Положение дел

[! [Статус сборки Appveyor] (https://ci.appveyor.com/api/projects/status/j7htumuwfx31elf6?svg=true)] (https://ci.appveyor.com/project/Light-Wizzard/qtlingo)

###: package: ** Загрузки: **

-: penguin: [Linux x64 zip] (https://github.com/Light-Wizzard/QtLingo/releases/download/continuous/QtLingo-Ubuntu-Release-x64.zip)
-: office: [Windows x64 zip] (https://github.com/Light-Wizzard/QtLingo/releases/download/continuous/QtLingo-Windows-Release-x64.zip)
-: apple: [Apple x64 zip] (https://github.com/Light-Wizzard/QtLingo/releases/download/continuous/QtLingo-MacOs-Release-x64.zip)

Windows (проверено на 7 и 10, дайте мне знать, работает ли 8): загрузите zip и распакуйте его,
и запустите файл QtLingo.exe внутри папки развертывания AppDir.

Apple не тестирует, потому что у меня его нет.

# Documentaion

Я пытаюсь загрузить файлы Doxygen на этот сайт, но пока не работает.
[Documentaion] (https://light-wizzard.github.io/QtLingo/)

# Проекты GitHub и другие используемые проекты

Я использую для этого приложения GitHub,
для переводов я использую crow-translate на https://github.com/crow-translate/crow-translate,
и QOnlineTranslator на https://github.com/crow-translate/QOnlineTranslator,
и для анализа файлов .ts я использую ts_tool по адресу https://github.com/nen777w/ts_tool,
и я использовал https://wiki.qt.io/Simple_encryption_with_SimpleCrypt#Versions.

# Процесс

Сначала нажмите «Скомпилировать», чтобы обновить файлы переводов проектов в соответствии с выбранными вами языками,
Я называю это компиляцией, потому что это все файлы, которые компилируются в ваше приложение,
затем нажмите «Принять все» или используйте Qt Lingustic для подтверждения каждого перевода,
затем нажмите на обновление справки, ReadMe и переводов этих файлов,
создание файлов с языковым кодом.

# Doxygen

Я использую Doxygen, вы можете запустить его с помощью команд ниже.

Баш
doxygen Doxyfile

или

doxywizard
`` ''

У меня есть документы Doxygen в разделе docs.

# Проблемы

Решение проблемы с подключением к Интернету.

`` ''
Критическое: «Истекло время ожидания операции сокета» (../QtLingo/src/MainWindow.cpp:2280, MainWindow :: translateWithReturn (const QString &, QOnlineTranslator :: Engine, QOnlineTranslator :: Language, QOnlineTranslator :: Language, QOnlineTranslator) :: <лямбда ()>)
Критично: «Хост www.bing.com не найден» (../QtLingo/src/MainWindow.cpp:2280, MainWindow :: translateWithReturn (const QString &, QOnlineTranslator :: Engine, QOnlineTranslator :: Language, QOnlineTranslator :: Language, QOnlineTranslator :: Язык) :: <лямбда ()>)
Критично: «Хост translate.yandex.com не найден» (../QtLingo/src/MainWindow.cpp:2280, MainWindow :: translateWithReturn (const QString &, QOnlineTranslator :: Engine, QOnlineTranslator :: Language, QOnlineTranslator :: Language, QOnlineTranslator :: Language, QOnlineTranslator :: Language, QOnlineTranslator :: Language, QOnlineTranslator :: Language :: Язык) :: <лямбда ()>)
Критично: «Хост translate.googleapis.com не найден» (../QtLingo/src/MainWindow.cpp:2280, MainWindow :: translateWithReturn (const QString &, QOnlineTranslator :: Engine, QOnlineTranslator :: Language, QOnlineTranslator :: Language, QOnlineTranslator :: Language, QOnlineTranslator :: Language, QOnlineTranslator :: Language, QOnlineTranslator :: Language, QOnlineTranslator :: Language :: Язык) :: <лямбда ()>)

`` ''

# Кредитов

Я использовал несколько проектов GitHub, которые я перечислил выше, все остальное
по сценарию Джеффри Скотта Флешера, волшебника света во плоти

### Конец файла