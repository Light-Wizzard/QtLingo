#ifndef MY_LOCALIZATION_H
#define MY_LOCALIZATION_H

// Qx
#include <QApplication>
#include <QCoreApplication>
#include <QDir>
#include <QFileInfo>
#include <QLocale>
#include <QObject>
#include <QRegularExpression>
#include <QString>
#include <QTranslator>
#include <QWidget>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
// Qt
#include <QtDebug>
#include <QTextStream>
// STD
#include <iostream>
#include <assert.h>
#include <algorithm>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
//
#include "MyOrgSettings.h"
// Local
/************************************************
 * @brief Translation Files.
 * \class TranslationFiles
 ***********************************************/
class MyLocalization : public QObject
{
        Q_OBJECT
    public:
        explicit MyLocalization(QObject *parent = nullptr, MyOrgSettings *thisSetting = nullptr);  //!< TranslationFiles Constructor
        enum MyMessageTypes
        {
            Information = 100, //!< \c Information  @brief Information
            Question    = 101, //!< \c Question     @brief Question
            Warning     = 102, //!< \c Warning      @brief Warning
            Critical    = 103, //!< \c Critical     @brief Critical
        }; // end enum MyFileinfo
        // Makes getting file Info easier
        Q_ENUM(MyMessageTypes)
//
        // Public
        MyOrgSettings  *mySetting;                       //!< \c mySetting @brief Domain Settings
        // Constants
        const QString MY_LANG_CODE = "LanguageCode"; //!< \c MY_LANG_CODE @brief Field Name for Language Code
        const QString MY_LANG_NAME = "LanguageName"; //!< \c MY_LANG_NAME @brief Field Name for Language Name
        // Is Debug Message
        void setDebugMessage(bool thisState);       //!< set Debug Message
        bool getDebugMessage();                     //!< get Debug Message
        // Localization
        QStringList findQmFiles(const QString &thisFolder);                             //!< find Qm Files
        QStringList findTsFiles(const QString &thisFolder);                             //!< find Ts Files
        bool        languageMatch(const QString &thisPrefix, const QString &thisLang, const QString &thisQmFile); //!< language Match
        QString     languageNameFromFile(const QString &thisTranslationFile);               //!< language Name From File
        QString     getLocalizerCode(const QString &thisPrefix, const QString &thisQmFile); //!< get Localizer Code
        void removeArgs(const QString &thisString, const QString &thisTransFile);       //!< remove Args file creation
        void fileRemoveArgs();                                                          //!< file Remove Args
        void fixTranslationFile(const QString &thisFile);                               //!< fix Translation File
        QString getLocalizedCodeFromFile(const QString &thisPrefix, const QString &thisQmFile); //!< get Localized Code From File
        // Added by Light-Wizzard
        QString languageNameToCode(const QString &lang);                //!< language Name to Code Added by Light-Wizzard
        QString languageCodeToName(const QString &lang);                //!< language Code to Name Added by Light-Wizzard

        void loadLanguage(const QString &thisQmLanguageFile); //!< load Language
        QString getLanguageFile(const QString &thisLanguage, const QString &thisPath, const QString &thisPrefix); //!< get Language File
        QString getLanguageFromFile(const QString &thisPrefix, const QString &thisQmLanguageFile); //!< getLanguageFromFile
        // Translation Source
        QString getTranslationSource();                                     //!< get Translation Source
        void setTranslationSource(const QString &thisTranslationSource);    //!< set Translation Source
        // Help Source
        QString getHelpSource();                                            //!< get Help Source
        void setHelpSource(const QString &thisHelpSource);                  //!< set Help Source
        //
        QString getTransFilePrefix();                                       //!< get TransFile Prefix
        void setTransFilePrefix(const QString &thisTransFilePrefix);        //!< set TransFile Prefix
        //
        QString readLanguage();                                             //!< read Language
        void writeLanguage(const QString &thisCurrentLanguageCode);         //!< write Language
        QString language(const QLocale &thisLocale);                        //!< language
        // Language Code
        void setLanguageCode(const QString &thisLanguageCode);              //!< set Language Code
        QString getLanguageCode();                                          //!< get Language Code
        // Main Loaded
        void setMainLoaded(bool thisMainLoaded);                            //!< set Main Loaded
        bool getMainLoaded();                                               //!< get Main Loaded

    private:
        static const QMap<QString, QString>  s_genericLanguageNameToCode; //!< \c s_genericLanguageNameToCode @brief generic Language Name to Code
        static const QMap<QString, QString>  s_genericLanguageCodeToName; //!< \c s_genericLanguageCodeToName @brief generic Language Code to Name
        bool            isDebugMessage       = true;    //!< \c isDebugMessage       @brief is Debug Message
        QString         myRemoveTransArgs;              //!< \c myRemoveTransArgs    @brief List of Remove Trans Args
        QString         myTranslationSource  = "";      //!< \c myTranslationSource  @brief Translation Source
        QString         myHelpSource         = "";      //!< \c myHelpSource         @brief Help Source
        QString         myTransFilePrefix    = "";      //!< \c myTransFilePrefix    @brief Translation File Prefix
        bool            isMainLoaded         = false;   //!< \c isMainLoaded         @brief Set true after one shot time loads
        QTranslator    *myTranslator;                   //!< \c myTranslator         @brief Translator
        QTranslator    *myLastTranslator     = nullptr; //!< \c myLastTranslator     @brief Last Translator
        QString         myLanguageCode       = "en";    //!< \c myLanguageCode       @brief Two Digit Language Code

};
#endif // MY_LOCALIZATION_H
/******************************* End of File *********************************/
