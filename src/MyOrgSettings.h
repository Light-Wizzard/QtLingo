#ifndef MY_ORG_SETTINGS_H
#define MY_ORG_SETTINGS_H

#include <QCoreApplication>
#include <QFileInfo>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QObject>
#include <QTime>
// GUI Widget stuff goes here
#ifndef MY_QML
#include <QMessageBox>
#endif
//
#include <QtCore>
#include <QtDebug>
#include <QtGlobal>
// Crypto
#include "SimpleCrypt.h"
//
//
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//
#define MY_CRYPTO_SEED (Q_UINT64_C(0x0c6add66acdcf066)) //!< \c MY_CRYPTO_SEED      @brief Ini File Name
/************************************************
 * @brief My Org Settings.
 * \class MyOrgSettings
 * @author Jeffrey Scott Flesher
 ***********************************************/
class MyOrgSettings : public QObject
{
    Q_OBJECT
        public:
                 explicit MyOrgSettings(QObject *parent = nullptr);  //!< MyOrgSettings Constructor
    ~MyOrgSettings();                                    //!< MyOrgSettings Destructor
    /*!
            \enum MyFileinfo
            @brief File Information
         */
    enum MyFileinfo
    {
        AbsolutePath      = 100, //!< \c AbsolutePath      @brief The absolute path name consists of the full path and the file name.
        AbsoluteFilePath  = 101, //!< \c CanonicalPath     @brief Returns a file's path absolute path, does not include the file name.
        BaseName          = 102, //!< \c BaseName          @brief Returns the base name of the file without the path.
        BirthTime         = 103, //!< \c BirthTime         @brief Returns the date and time when the file was created / born.
        CanonicalPath     = 104, //!< \c CanonicalPath     @brief Returns the canonical path including the file name, i.e. an absolute path without symbolic links or redundant "." or ".." elements.
        CanonicalFilePath = 105, //!< \c CanonicalFilePath @brief Returns the file's path canonical path (excluding the file name), i.e. an absolute path without symbolic links or redundant "." or ".." elements.
        CompleteBaseName  = 106, //!< \c CompleteBaseName  @brief Returns the complete base name of the file without the path.
        CompleteSuffix    = 107, //!< \c CompleteSuffix    @brief Returns the complete suffix (extension) of the file.
        Directory         = 108, //!< \c Directory         @brief Returns the path of the object's parent directory as a QDir object.
        FileName          = 109, //!< \c FileName          @brief Returns the name of the file, excluding the path.
        FilePath          = 110, //!< \c FilePath          @brief Returns the file name, including the path (which may be absolute or relative).
        IsWritable        = 111, //!< \c IsWritable        @brief Returns true if the user can write to the file; otherwise returns false.
        IsFile            = 112, //!< \c IsFile            @brief Returns true if this object points to a file or to a symbolic link to a file. Returns false if the object points to something which isn't a file, such as a directory.
        IsFolder          = 113, //!< \c IsFolder          @brief Returns true if this object points to a directory or to a symbolic link to a directory; otherwise returns false.
        FileSize          = 114, //!< \c FileSize          @brief File Size
        IsSymLink         = 115, //!< \c IsSymLink         @brief Returns true if this object points to a symbolic link; otherwise returns false.
        SymLinkTarget     = 116, //!< \c SymLinkTarget     @brief Returns the absolute path to the file or directory a symbolic link points to, or an empty string if the object isn't a symbolic link.
    }; // end enum MyFileinfo
    // Makes getting file Info easier
    Q_ENUM(MyFileinfo)
    /*!
            \enum MyMessageTypes
            @brief Message Types
         */
    enum MyMessageTypes
    {
        Information = 100, //!< \c Information  @brief Information
        Question    = 101, //!< \c Question     @brief Question
        Warning     = 102, //!< \c Warning      @brief Warning
        Critical    = 103, //!< \c Critical     @brief Critical
        Debug       = 104, //!< \c Debug        @brief Debug
    }; // end enum MyFileinfo
    // Makes Messaging easier
    Q_ENUM(MyMessageTypes)
    //
    SimpleCrypt *myCrypto;    //!< \c myCrypto    @brief my Crypto
    // Constants
    // Project Specific Constants you might want to change
    const QString MY_PROJECT_NAME           = "QmlWidgetTranslator";   //!< \c MY_QT_PROJECT_NAME  @brief Qt Project Name.
    const QString MY_INI_EXTENSION          = "ini";                   //!< \c MY_INI_EXTENSION    @brief Ini File Extension.
    const QString MY_HELP_FOLDER            = "help";                  //!< \c MY_HELP_FOLDER      @brief Help folder.
    const QString MY_INTERNET_URL           = "http://www.google.com"; //!< \c MY_INTERNET_URL     @brief Default Internet URL for testing if Internet is up.
    //
    const QPoint  ConstDefaultGeometryPos  = QPoint(10, 10);       //!< \c ConstDefaultGeometryPos  @brief Top, Left.
    const QSize   ConstDefaultGeometrySize = QSize(666, 333);      //!< \c ConstDefaultGeometrySize @brief Width x Height.
    const QString MY_LAST_PROJECT_FOLDER   = "LastProjectFolder";  //!< \c MY_QT_PROJECT_NAME       @brief Field Name for Last Project folder.
    const QString MY_IS_DEBUG_MESSAGE      = "IsDebugMessage";     //!< \c MY_IS_DEBUG_MESSAGE      @brief Field Name for IsDebugMessage.
    const QString MY_LOCALE_LANG_CODE      = "LocaleLanguageCode"; //!< \c MY_CURRENT_LANG_CODE     @brief Field Name for Current Language Code.
    const QString MY_LOCALE_LANG_NAME      = "LocaleLanguageName"; //!< \c MY_LOCALE_LANG_NAME      @brief Field Name for Current Language Name.
    // Sql Ini Variable Names Field Names
    const QString MY_SQL_DEFAULT      = "QSQLITE";          //!< \c SQL_DEFAULT         @brief Default Sql Driver QSQLITE.
    const QString MY_DEFAULT_SQL      = ":memory:";         //!< \c MY_DEFAULT_SQL      @brief Default Sql Driver is in memory.
    const QString MY_SQL_PROJECT_ID   = "ProjectID";        //!< \c SQL_PROJECT_ID      @brief Field Name for Project ID.
    const QString MY_SQL_PROJECT_NAME = "ProjectName";      //!< \c MY_SQL_PROJECT_NAME @brief Field Name for Project ID.
    const QString MY_SQL_DB_NAME      = "SqlDatabaseName";  //!< \c MY_SQL_DB_NAME      @brief SQL Ini Storage Field Name.
    const QString MY_SQL_DB_TYPE      = "SqlDatabaseType";  //!< \c MY_SQL_DB_TYPE      @brief SQL Ini Storage Field Name.
    const QString MY_SQL_DB_HOST      = "SqlDatabaseHost";  //!< \c MY_SQL_DB_HOST      @brief SQL Ini Storage Field Name.
    const QString MY_SQL_DB_USER      = "SqlDatabaseUser";  //!< \c MY_SQL_DB_USER      @brief SQL Ini Storage Field Name.
    const QString MY_SQL_DB_PASS      = "SqlDatabasePass";  //!< \c MY_SQL_DB_PASS      @brief SQL Ini Storage Field Name.
    const QString MY_DATETIME_FORMAT_STARTED = "DateTimeFormatStarted";  //!< \c MY_DATETIME_FORMAT_STARTED @brief DateTime Format Storage Field Name.
    const QString MY_DATETIME_FORMAT_DUE     = "DateTimeFormatDue";      //!< \c MY_DATETIME_FORMAT_STARTED @brief DateTime Format Storage Field Name.
    const QString MY_PROJECT_STATUS          = "ProjectStatus";          //!< \c MY_PROJECT_STATUS @brief Project Status Storage Field Name.

    //
    const QString MY_DEFAULT_LANGUAGE_CODE = "en"; //!< \c MY_DEFAULT_LANGUAGE_CODE @brief Used to find default Translation Files
    // My Org Settings Field Names
    const QString MY_APPLICATION_NAME   = "SettingsApplicationName"; //!< \c ConstSettingsApplicationName @brief QSettings Field Settings Application Name.
    const QString MY_ORG_NAME           = "SettingsOrgName";         //!< \c ConstSettingsOrgName         @brief QSettings Field Settings Org Name.
    const QString MY_ORG_DOMAIN         = "SettingsOrgDomain";       //!< \c ConstSettingsOrgDomain       @brief QSettings Field Settings Org Domain.
    const QString MY_GEOMETRY           = "Geometry";                //!< \c ConstSettingsGeometry        @brief QSettings Field Settings Geometry.
    const QString MY_WINDOW_STATES      = "WidowState";              //!< \c MY_WINDOW_STATES             @brief QSettings Field Window State.
    const QString MY_LAST_TAB_INDEX     = "LastTabInex";             //!< \c MY_LAST_TAB                  @brief Field Name for Current Last Tab Index.
    const QString MY_DEFAULT_TAB_INDEX  = "0";                       //!< \c MY_DEFAULT_TAB_INDEX         @brief Default Tab Index.
    //
    void onRunOnStartup();                                                          //!< Run On Startup
    // Read
    QString readSettings(const QString &thisSetting, const QString &thisDefault);   //!< read Settings
    QString readSettings(const QString &thisSetting);                               //!< read Settings
    bool    readSettingsBool(const QString &thisSetting, bool thisDefault);         //!< read Settings Bool
    int     readSettingsInt(const QString &thisSetting, int thisDefault);           //!< read Settings Int
    // Write
    void writeSettings(const QString &thisSetting, const QString &thisValue);       //!< write Settings
    // Getter/Setter
    QSettings *getSettings();                                                       //!< get Settings
    // Data Path
    QString getDataPath(const QString &thisFileName);                               //!< Get Data Path
    // Org Name
    QString getOrgName();                                                           //!< get Org Name
    void    setOrgName(const QString &thisOrgName);                                 //!< set Org Name
    // Org Domain
    QString getOrgDomain();                                                         //!<  my Organization Domain
    void    setOrgDomain(const QString &thisOrgDomain);
    // Application Name
    QString getAppName();                                                           //!< my Application Name
    void    setAppName(const QString &thisAppName);                                 //!< set AppName
    // Application Version
    QString getVersion();                                                           //!< my Application Version
    void    setVersion(const QString &thisVersion);                                 //!< set Version
    // Application Ini File Name
    QString getIniFileName();                                                       //!< my Application IniFile
    void    setIniFileName(const QString &thisIniFileName);                         //!< set IniFile
    // Ini File Extension
    void setIniFileExtension(const QString &thisIniFileNameExtension); //!< set Ini File Extension
    QString getIniFileExtension();                                     //!< getIniFileExtension
    // Application Ini Full Path
    QString getIniFullPath();                                                       //!< my Application IniFile
    void    setIniFullPath(const QString &thisIniFileName);                         //!< set IniFile
    // File Utilities
    QString readFile(const QString &thisFileName);                                  //!< read File
    QString combinePathFileName(const QString &thisPath, const QString &thisFileName); //!< combine Path File Name
    bool isFileExists(const QString &thisFile);                                     //!< File Functions
    bool isFileMake(const QString &thisPath, const QString &thisFileName);          //!< is File Make
    bool isPathExists(const QString &thisPath);                                     //!< is Path Exists
    bool isMakeDir(const QString &thisPath);                                        //!< is Make Dir
    bool removeFile(const QString &thisFile);                                       //!< remove File
    bool writeFile(const QString &thisFileName, const QString &thisContent);        //!< write File
    QString getFileInfo(MyOrgSettings::MyFileinfo thisInfo, const QString &thisFileFolder); //!< get File Info
    int fileNumberLines(const QString &thisFile);                                   //!< file Number Lines
    bool removeAllFiles(const QString &thisFolder);                                 //!< remove All Files
    QString getLastApplicationPath();                                               //!< get Last Application Path
    void    setLastApplicationPath(const QString &thisPath);                        //!< set Last Application Path
    QString getAppDataLocation();                                                   //!< get AppData Location
    void    setAppDataLocation(const QString &thisAppDataLocation);                 //!< set AppData Location
    bool    isAppDataLocationGood(const QString &thisFolder);                       //!< is AppData Location Good
    //
    bool   isSetting(const QString &thisFieldName);                                 //!< is Setting
    // Screen Geometry
    void   setGeometry(QByteArray thisGeometry);     //!< Screen Geometry
    QByteArray getGeometry();                                                           //!< get Geometry
    //
    QByteArray   getWindowState();                                                        //!< get Geometry Min
    void   setWindowState(QByteArray thisWindowState);                                                        //!< get Geometry Min
    // Crypto for Password
    QString encryptThis(const QString &thisSecret);                                 //!< encrypt This
    QString decryptThis(const QString &thisSecret);                                 //!< decrypt This
    //
    QString getEnvironmentVar(const QString &thisVar, const QString &thisDefault);  //!< get Windows Environment Var
    bool isWord(const QString &thisString) const;                                   //!< is Word
    void delay(int thisSeconds);                                                    //!< delay
    // Is Debug Message
    void setDebugMessage(bool thisState);                       //!< set Debug Message
    bool getDebugMessage();                                     //!< get Debug Message
    // Messaging
    bool    questionYesNo(const char *thisTitle, const char *thisQuestion) const;   //!< question Yes No
    QVariant showMessageBox(const QString &thisTitle, const QString &thisMessage, MyMessageTypes thisMessageType) const; //!< show Message Box information, question, warning, critica
    QVariant setMessage(const QString &thisTitle, const QString &thisMessage, MyMessageTypes thisMessageType) const; //!< set Message
    // Internet with Wait
    bool getInternetWait();                                     //!< get Internet Wait
    bool pingInternet();                                        //!< ping Internet
    bool connectInternet();                                     //!< connect Internet
    QString getCheckInternetUrl();                                 //!< get Check Internet Url
    void setCheckInternetUrl(const QString &thisCheckInternetUrl); //!< set Check Internet Url

    QSettings *getSetteings();

    private slots:
    void onUpdateSettings();

    signals:
    void sendInternetProgress();                                //!< send Internet Progress
    void sendUpdateSettings();                                  //!< send Update Settings

    private:
    QSettings          *mySettings              = nullptr;      //!< \c mySettings              @brief QSettings is used for this class.
    QString             myOrganizationName      = "";           //!< \c myOrganizationName      @brief Organization Name.
    QString             myOrganizationDomain    = "";           //!< \c myOrganizationDomain    @brief Organization Domain.
    QString             myApplicationName       = "";           //!< \c myApplicationName       @brief Application Name.
    QString             myLastApplicationFolder = "";           //!< \c myLastApplicationFolder @brief Last Application Folder
    QByteArray          myGeometry;                             //!< \c myGeometryPos           @brief Windows Geometry Pos
    QByteArray          myWindowState;                          //!< \c myGeometrySize          @brief Windows Geometry Size
    bool                myGeometryMax           = false;        //!< \c myGeometryMax           @brief Windows Geometry Max
    bool                myGeometryMin           = false;        //!< \c myGeometryMin           @brief Windows Geometry Min
    bool                isDebugMessage          = false;        //!< \c isDebugMessage          @brief Debug Message
    bool                isCreated               = false;        //!< \c isCreated               @brief if file is created
    bool                isLocalStorage          = true;         //!< \c isLocalStorage          @brief If Local Storage is enabled save to Settings
    QString             myVersion               = "1.0.0";      //!< \c myVersion               @brief Version
    QString             myIniFullPath           = "";           //!< \c myIniFullPath           @brief my Ini Full File Path and Name.ext
    QString             myIniFileName           = "";           //!< \c myIniFile               @brief my Ini File
    QString             myIniFileExtension      = "";           //!< \c myIniFileExtension      @brief my Ini File Extension
    QString             myCheckInternetUrl      = "";           //!< \c myCheckInternetUrl      @brief my Check Internet Url
    QString             myAppDataLocation       = "";           //!< \c myAppDataLocation       @brief my App Data Location

};
#endif // MY_ORG_SETTINGS_H
/*** ************************* End of File ***********************************/
