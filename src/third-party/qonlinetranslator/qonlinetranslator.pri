QT += network multimedia

HEADERS += $$PWD/src/qonlinetranslator.h $$PWD/src/qonlinetts.h $$PWD/src/qoption.h $$PWD/src/qexample.h
SOURCES += $$PWD/src/qonlinetranslator.cpp $$PWD/src/qonlinetts.cpp $$PWD/src/qoption.cpp  $$PWD/src/qexample.cpp

INCLUDEPATH += $$PWD/src

#CONFIG         *= strict_c++
#CONFIG         *= "c++11"
#CONFIG         *= "c++14"
#CONFIG         *= "c++1z"
#CONFIG         *= "c++17"
#CONFIG         *= "c++2a"
#CONFIG         *= "c++latest"
