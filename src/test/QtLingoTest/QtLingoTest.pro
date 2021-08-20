# QtLingoTest.pro
QT += testlib
#
QT += core gui sql network multimedia concurrent widgets printsupport
#
CONFIG += qt warn_on depend_includepath testcase
#
TEMPLATE = app
#
SOURCES +=  tst_qtlingocase.cpp \
    ../../MainWindow.cpp \
    ../../MyDatatables.cpp \
    ../../MyLocalization.cpp \
    ../../MyOrgSettings.cpp \
    ../../MySqlDbtModel.cpp \
    ../../MyTranlatorParser.cpp \
    ../../SimpleCrypt.cpp \
    ../../third-party/ts_tool/ts_model.cpp

HEADERS += ../../MainWindow.h \
        ../../MyConstants.h \
        ../../MyDatatables.h \
        ../../MyLocalization.h \
        ../../MyOrgSettings.h \
        ../../MySqlDbtModel.h \
        ../../MyTranlatorParser.h \
        ../../SimpleCrypt.h \
        ../../third-party/ts_tool/efl_hash.h \
        ../../third-party/ts_tool/ts_model.h
#
FORMS += ../../MainWindow.ui

INCLUDEPATH += ../../../
INCLUDEPATH += ../../../src
INCLUDEPATH += ../../third-party/ts_tool
INCLUDEPATH += ../../third-party/qonlinetranslator/src
INCLUDEPATH += "${QT_INSTALL_LIBS}/qt"
#
include(../../third-party/qonlinetranslator/qonlinetranslator.pri)
# Resources
RESOURCES   += ../../../QtLingo.qrc
###############################################################################
message("*******************************************************************************")
message(Qt version: $$[QT_VERSION])
message(Qt is installed in $$[QT_INSTALL_PREFIX])
message(Qt resources can be found in the following locations:)
message(Documentation: $$[QT_INSTALL_DOCS])
message(Header files: $$[QT_INSTALL_HEADERS])
message(Libraries: $$[QT_INSTALL_LIBS])
message(Binary files (executables): $$[QT_INSTALL_BINS])
message(Plugins: $$[QT_INSTALL_PLUGINS])
message(Data files: $$[QT_INSTALL_DATA])
message(Translation files: $$[QT_INSTALL_TRANSLATIONS])
message(Settings: $$[QT_INSTALL_SETTINGS])
message(Examples: $$[QT_INSTALL_EXAMPLES])
message(Demonstrations: $$[QT_INSTALL_DEMOS])
message(Demonstrations: $$[QT_INSTALL_DEMOS])
message(OUT_PWD: $${OUT_PWD})
message(DESTDIR: $${DESTDIR})
message(OBJECTS_DIR: $${OBJECTS_DIR})
message(MOC_DIR: $${MOC_DIR})
message(UI_DIR: $${UI_DIR})
message(RCC_DIR: $${RCC_DIR})
message(INSTALLS: $${INSTALLS})
message(RC_FILE: $${RC_FILE})
message(DEFINES: $${DEFINES})
message(QMAKE_CXXFLAGS: $${QMAKE_CXXFLAGS})
message("*******************************************************************************")
################################ End of File ##################################

