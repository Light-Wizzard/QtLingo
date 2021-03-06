# QtLingo.pro
# Specifies the name of the template to use when generating the project.
# The allowed values are: app, lib, subdirs, aux, vcapp or vclib
TEMPLATE = "app"
# This pro(ject) file is based on a pattern
# Do not use Spaces in Target Name
TARGET = "QtLingo"
#
QT += core gui sql widgets network multimedia concurrent printsupport
#
#CONFIG *= strict_c++
#CONFIG *= "c++11"
#CONFIG *= "c++14"
#CONFIG *= "c++1z"
 CONFIG *= "c++17"
#CONFIG *= "c++2a"
#CONFIG *= "c++latest"
#
win32:CONFIG       += static
win32:DEFINES      += STATIC
win32:QMAKE_LFLAGS += -static
#
win32:CONFIG    *= windeployqt windows
win32:QMAKE_CC  += "C:\Qt\Tools\$env:MY_QT_TOOLS_MINGW64\bin\gcc.exe"
win32:QMAKE_CXX += "C:\Qt\Tools\$env:MY_QT_TOOLS_MINGW64\bin\g++.exe"
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
# Specifies the name of the target file. Contains the base name of the project file by default.
##-------------------------------------------------------------------------------------
INCLUDEPATH     += .
INCLUDEPATH     += src
INCLUDEPATH     += "${QT_INSTALL_LIBS}/qt"
##-------------------------------------------------------------------------------------
#
HEADERS +=  \
    src/MainWindow.h \
    src/MyConstants.h \
    src/MyDatatables.h \
    src/MyLanguageData.h \
    src/MyLanguageModel.h \
    src/MyOrgSettings.h \
    src/MySqlDbtModel.h \
    src/MyTranlatorParser.h \
    src/SimpleCrypt.h \
    src/third-party/ts_tool/efl_hash.h \
    src/third-party/ts_tool/ts_model.h
#
#
SOURCES += \
    src/main.cpp \
    src/MainWindow.cpp \
    src/MyDatatables.cpp \
    src/MyLanguageData.cpp \
    src/MyLanguageModel.cpp \
    src/MyOrgSettings.cpp \
    src/MySqlDbtModel.cpp \
    src/MyTranlatorParser.cpp \
    src/SimpleCrypt.cpp \
    src/third-party/ts_tool/ts_model.cpp \
    src/third-party/qonlinetranslator/src/qonlinetranslator.cpp \
    src/third-party/qonlinetranslator/src/qonlinetts.cpp \
    src/third-party/qonlinetranslator/src/qexample.cpp \
    src/third-party/qonlinetranslator/src/qoption.cpp
#
FORMS += src/MainWindow.ui
#
INCLUDEPATH += $$PWD/src $$PWD/src/third-party/qonlinetranslator/src
#
include(src/third-party/qonlinetranslator/qonlinetranslator.pri)
# Resources
RESOURCES   += QtLingo.qrc
#
# Translations
#
CONFIG += localize_deployment
SYMBIAN_SUPPORTED_LANGUAGES += zh_CN
SYMBIAN_LANG.zh_CN = 31
CONFIG += lrelease
CONFIG += embed_translations
LRELEASE_DIR=./translations
QM_FILES_RESOURCE_PREFIX=./translations
# ar,de,en,es,fr,it,ja,no,ru,sv,zh_CN
TRANSLATIONS += translations/QtLingo_ar.ts \
                translations/QtLingo_de.ts \
                translations/QtLingo_en.ts \
                translations/QtLingo_es.ts \
                translations/QtLingo_fr.ts \
                translations/QtLingo_it.ts \
                translations/QtLingo_ja.ts \
                translations/QtLingo_no.ts \
                translations/QtLingo_ru.ts \
                translations/QtLingo_sv.ts \
                translations/QtLingo_zh_CN.ts
#
DISTFILES += README.md CMakeLists.txt \
    .appveyor.yml \
    .github/workflows/main.yml \
    Doxyfile \
    desktop/CMakeLists.txt \
    desktop/QtLingo.desktop \
    desktop/QtLingo.ico \
    desktop/QtLingo.png \
    desktop/QtLingo.svg \
    help/About-Author_en.md \
    help/About_en.md \
    help/Help_en.md \
    help/Language.txt \
    help/Languages.txt \
    help/images/settings.png \
    help/images/sql.png \
    scripts/build_script.cmd \
    scripts/build_script.ps1 \
    scripts/build_script.sh \
    scripts/install.cmd \
    scripts/install.ps1 \
    scripts/install.sh \
    scripts/upload.sh \
    src/third-party/docs/QExample.md \
    src/third-party/docs/QOnlineTranslator.md \
    src/third-party/docs/QOnlineTts.md \
    src/third-party/docs/QOption.md \
    src/third-party/qonlinetranslator/CMakeLists.txt

###############################################################################
#
# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
#DEFINES += QT_DEPRECATED_WARNINGS
#
# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
#
#
macos:QMAKE_INFO_PLIST = macos/Info.plist
ios:QMAKE_INFO_PLIST   = ios/Info.plist
#-------------------------------------------------------------------------------------
#contains(QMAKE_HOST.arch, x86_64) { #x64
#    BUILD_ARCH = x64
#} else { #x32
#    BUILD_ARCH += x32
#}
#CONFIG(release, debug|release) {
#    BUILD_TYPE = release
#} else {
#    BUILD_TYPE = debug
#}
#GENF_ROOT   = $${BUILD_ARCH}/_output
#BIN_OUTPUT  = $${GENF_ROOT}/_bin
#DESTDIR     = $${BIN_OUTPUT}/$${BUILD_TYPE}
#OBJECTS_DIR = $${GENF_ROOT}/$${TARGET}/$${BUILD_TYPE}/_build
#MOC_DIR     = $${GENF_ROOT}/$${TARGET}/$${BUILD_TYPE}/_moc
#UI_DIR      = $${GENF_ROOT}/$${TARGET}/$${BUILD_TYPE}/_ui
#RCC_DIR     = $${GENF_ROOT}/$${TARGET}/$${BUILD_TYPE}/_rc
#-------------------------------------------------------------------------------------
#
#Release:DESTDIR     = release
#Release:OBJECTS_DIR = release/.obj
#Release:MOC_DIR     = release/.moc
#Release:RCC_DIR     = release/.rcc
#Release:UI_DIR      = release/.ui

#Debug:DESTDIR     = debug
#Debug:OBJECTS_DIR = debug/.obj
#Debug:MOC_DIR     = debug/.moc
#Debug:RCC_DIR     = debug/.rcc
#Debug:UI_DIR      = debug/.ui


win32-g++{
    contains(QMAKE_HOST.arch, x86_64) { #x64
        DEFINES += MINGW_X64
    } else { #x32
        DEFINES += MINGW_X32
    }

    CONFIG(release, debug|release) {
        #release
        QMAKE_CXXFLAGS += -std=c++0x -O2 -Os -msse2 -ffp-contract=fast -fpic
    }
    else {
        #debug
        DEFINES += _DEBUG
        QMAKE_CXXFLAGS += -std=c++0x -O0 -g3 -msse2 -fpic
    }
}

#
unix {
    isEmpty(PREFIX) {
        PREFIX = /usr
    }
    target.path         = "$${PREFIX}/bin"
    shortcutfiles.files = "usr/share/applications/$${TARGET}.desktop"
    shortcutfiles.path  = usr/share/applications
    data.files         += "usr/share/icons/hicolor/48x48/apps/$${TARGET}.png"
    data.path           = usr/share/pixmaps
    INSTALLS           += shortcutfiles
    INSTALLS           += data
    INSTALLS           += target
    macx {
        RC_FILE = macos/Icon.icns
    }
} else {
    isEmpty(PREFIX) {
        PREFIX = /usr
    }
    target.path         = "$${PREFIX}/bin"
    shortcutfiles.files = "usr/share/applications/$${TARGET}.desktop"
    shortcutfiles.path  = usr/share/applications
    data.files         += "usr/share/icons/hicolor/48x48/apps/$${TARGET}.png"
    data.path           = usr/share/pixmaps
    INSTALLS           += shortcutfiles
    INSTALLS           += data
    INSTALLS           += target
}
################################ End of File ##################################
