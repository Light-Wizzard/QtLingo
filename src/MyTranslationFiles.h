#ifndef MYTRANSLATIONFILES_H
#define MYTRANSLATIONFILES_H

#include <QObject>
#include <QWidget>
#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <assert.h>
#include <algorithm>
#include <sstream>

//model
#include "third-party/ts_tool/ts_model.h"

//Qt
#include <QString>
#include <QCoreApplication>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QTextStream>
#include <QRegularExpression>
#include <QFileInfo>
#include <QDir>
#include <QtDebug>
#include "MyDatatables.h"

/*! ***************************************************************************
   \class TranslationFiles
   \brief Translation Files
 *************************************************************************** */
class MyTranslationFiles : public QObject
{
        Q_OBJECT
    public:
        explicit MyTranslationFiles(QObject *parent = nullptr, MyDatatables *thisSqlDb = nullptr);  //!< TranslationFiles Constructor
        enum MyMessageTypes
        {
            Information = 100, //!< \c Information  \brief Information
            Question    = 101, //!< \c Question     \brief Question
            Warning     = 102, //!< \c Warning      \brief Warning
            Critical    = 103, //!< \c Critical     \brief Critical
        }; // end enum MyFileinfo
        // Makes getting file Info easier
        Q_ENUM(MyMessageTypes)
//
        base_node::base_node_ptr parse_ts_file(const QString &inputFile);                         //!< parse_ts_file
        bool parse_txt_file(const QString &inputFile, visitors::map_QStringQString &strings);     //!< parse_txt_file
        void toTXT(const QString &inputFile, const QString &outputDir, bool with_unfinished, bool with_vanished, bool unfinished_only);  //!< toTXT
        void toTS(const QString &inputDir, const QString &outputFile, const QString &langid);     //!< toTS
        // Is Debug Message
        void setDebugMessage(bool thisState);       //!< set Debug Message
        bool getDebugMessage();                     //!< get Debug Message
        // Localization
        QStringList findQmFiles(const QString &thisFolder);                             //!< findQmFiles
        bool        languageMatch(const QString &thisPrefix, const QString &thisLang, const QString &thisQmFile); //!< language Match
        QString     languageNameFromFile(const QString &thisTranslationFile);               //!< language Name From File
        QString     getLocalizerCode(const QString &thisPrefix, const QString &thisQmFile); //!< get Localizer Code
        void removeArgs(const QString &thisString, const QString &thisTransFile);       //!< remove Args file creation
        void fileRemoveArgs();                                                          //!< file Remove Args
        void fixTranslationFile(const QString &thisFile);                               //!< fix Translation File
        QString getLocalizedCodeFromFile(const QString &thisPrefix, const QString &thisQmFile); //!< get Localized Code From File
        bool writeFile(const QString &thisFileName, const QString &thisContent); //!< write File
        QString getAppDataLocation(); //!< getAppDataLocation
        bool isFileExists(const QString &thisFile); //!< is File Exists
        int showMessageBox(const QString &thisTitle, const QString &thisMessage, MyMessageTypes thisMessageType); //!< show Message Box
        bool questionYesNo(const char *thisTitle, const char *thisQuestion); //!< question Yes No

    private:
        MyDatatables       *mySqlDb;               //!< \c mySqlDb              \brief Sql Datatables
        bool                isDebugMessage = true; //!< \c isDebugMessage       \brief is Debug Message
        QString             myRemoveTransArgs;     //!< \c myRemoveTransArgs    \brief List of Remove Trans Args
        QOnlineTranslator   myQOnlineTranslator;   //!< \c myQOnlineTranslator  \brief QOnlineTranslator

};
#endif // MYTRANSLATIONFILES_H
/******************************* End of File *********************************/
