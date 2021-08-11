cmake_minimum_required(VERSION 3.1.0)

project(QtLingo)
set(APP_VERSION "0.1.0")
# [Using CMake with Qt 5](http://www.kdab.com/using-cmake-with-qt-5/)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
#
if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()
#
find_package(Qt5 COMPONENTS Core Widgets LinguistTools PrintSupport Sql LinguistTools Concurrent REQUIRED)
# Libraries
set(QT5_LIBRARIES Qt5::Widgets Qt5::PrintSupport Qt5::Sql)
#
set(TARGET ${CMAKE_PROJECT_NAME})
# Source
set(SOURCES
    src/main.cpp
    src/MainWindow.cpp
)
# UI
set(UI_SOURCES
    src/MainWindow.ui
)
#
qt5_add_resources(SOURCES QtLingo.qrc)
add_subdirectory(src/third-party/qonlinetranslator)
# https://github.com/pedrolcl/qt5-i18n
# not sure if I need to add en since it is the default
set(TS_FILES
    QtLingo_es.ts
    QtLingo_de.ts
    QtLingo_fr.ts
    QtLingo_it.ts
    QtLingo_ja.ts
    QtLingo_zh.ts
    QtLingo_no.ts
    QtLingo_ru.ts
    QtLingo_ar.ts
)

if (QT_VERSION VERSION_LESS 5.15.0)
    qt5_add_translation(QM_FILES ${TS_FILES})
else()
    qt_add_translation(QM_FILES ${TS_FILES})
endif()

include(TranslationUtils)
add_app_translations_resource(APP_RES ${QM_FILES})
add_qt_translations_resource(QT_RES de fr it ja zh no ru sv ar)
# The qm files are generated in the build tree, but the qrc file is inside the
# source directory and the path to resources are relative to the location of
# the qrc file itself. We use configure_file() to copy the qrc file in the build
# directory such that it can find the qm translations files. The qrc file is
# copied if it doesn't exist in the destination or if it is modified.
#configure_file(QtAppVeyor.qrc ${CMAKE_BINARY_DIR} COPYONLY)
# The Qt5Widgets_INCLUDES also includes the include directories for dependencies QtCore and QtGui
include_directories(${Qt5Widgets_INCLUDES})
#
include_directories(${CMAKE_CURRENT_BINARY_DIR})
# We need add -DQT_WIDGETS_LIB when using QtWidgets in Qt 5.
add_definitions(${Qt5Widgets_DEFINITIONS})
# Executables fail to build with Qt 5 in the default configuration without -fPIE, added here.
set(CMAKE_CXX_FLAGS "${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")
#
# Generate necessary headers from .ui files. (qmake lets `uic` do this job.)
# hint from [Cross-platform Qt5 project using cmake](http://stackoverflow.com/questions/21174586/cross-platform-qt5-project-using-cmake)
#
qt5_wrap_ui(UI_GENERATED_HEADERS ${UI_SOURCES})
#
# IMPORTANT: Adding generated headers to target as dependencies
# hint from [unable to include a ui_form header of QT5 in cmake](http://stackoverflow.com/questions/16245147/unable-to-include-a-ui-form-header-of-qt5-in-cmake)
#
add_executable(${TARGET} ${SOURCES} ${UI_GENERATED_HEADERS} ${APP_RES} ${QT_RES})
#
# `target_link_libraries()` rather than `qt5_use_modules()` for CMake 2.8.11 or later
# hint from [CMake & QT5 - QT5_WRAP_UI not generating ui header files](http://stackoverflow.com/questions/25875255/cmake-qt5-qt5-wrap-ui-not-generating-ui-header-files)
#
target_link_libraries(${TARGET} ${QT5_LIBRARIES})
