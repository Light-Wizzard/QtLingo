#ifndef MY_ORG_SETTINGS_H
#define MY_ORG_SETTINGS_H

#include <QCoreApplication>
#include <QFileInfo>
#include <QMessageBox>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QObject>
#include <QTime>
//
#include <QtCore>
#include <QtDebug>
#include <QtGlobal>
//
#include "MyConstants.h"
// Crypto
#include "SimpleCrypt.h"
//
//
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
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
        // Makes getting file Info easier
        Q_ENUM(MyMessageTypes)
        //
        MyConstants *myConstants; //!< \c myConstants @brief All Constants in one class
        SimpleCrypt *myCrypto;    //!< \c myCrypto    @brief my Crypto
        // Not added to above Constants, these need to FIXME
        const QPoint  ConstDefaultGeometryPos  = QPoint(10, 10);   //!< \c ConstDefaultGeometryPos     @brief Top, Left.
        const QSize   ConstDefaultGeometrySize = QSize(1134, 817); //!< \c ConstDefaultGeometrySize    @brief Width x Height.
        //
        void onRunOnStartup();                                                          //!< Run On Startup
        // Read
        QString readSettings(const QString &thisSetting, const QString &thisDefault);   //!< read Settings
        bool    readSettingsBool(const QString &thisSetting, bool thisDefault);         //!< read Settings Bool
        int     readSettingsInt(const QString &thisSetting, int thisDefault);           //!< read Settings Int
        // Write
        void writeSettings(const QString &thisSetting, const QString &thisValue);       //!< write Settings
        // Getter/Setter
        QSettings *getSettings();                                                       //!< get Settings
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
        void removeAllFiles(const QString &thisFolder);                                 //!< remove All Files
        QString getLastApplicationPath();                                               //!< get Last Application Path
        void    setLastApplicationPath(const QString &thisPath);                        //!< set Last Application Path
        QString getAppDataLocation();                                                   //!< get AppData Location
        bool    isAppDataLocationGood(const QString &thisFolder);                       //!< is AppData Location Good
        //
        bool   isSetting(const QString &thisFieldName);                                 //!< is Setting
        // Screen Geometry
        void   setGeometry(QPoint thisPos, QSize thisSize, bool isMax, bool isMin);     //!< Screen Geometry
        void   getGeometry();                                                           //!< get Geometry
        QPoint getGeometryPos();                                                        //!< get Geometry Pos
        QSize  getGeometrySize();                                                       //!< get Geometry Size
        bool   getGeometryMax();                                                        //!< get Geometry Max
        bool   getGeometryMin();                                                        //!< get Geometry Min
        // Crypto for Password
        QString encryptThis(const QString &thisSecret);                                 //!< encrypt This
        QString decryptThis(const QString &thisSecret);                                 //!< decrypt This
        bool    questionYesNo(const char *thisTitle, const char *thisQuestion) const;   //!< question Yes No
        int     showMessageBox(const QString &thisTitle, const QString &thisMessage, MyOrgSettings::MyMessageTypes thisMessageType) const; //!< show Message Box information, question, warning, critica
        //
        QString getEnvironmentVar(const QString &thisVar, const QString &thisDefault);  //!< get Windows Environment Var
        bool isWord(const QString &thisString) const;                                   //!< is Word
        void delay(int thisSeconds);                                                    //!< delay
        // Is Debug Message
        void setDebugMessage(bool thisState);                       //!< set Debug Message
        bool getDebugMessage();                                     //!< get Debug Message
        void setMessage(const QString &thisMessage, MyOrgSettings::MyMessageTypes thisMessageType) const; //!< set Message
        // Internet with Wait
        bool getInternetWait();                                     //!< get Internet Wait
        bool pingInternet();                                        //!< ping Internet
        bool connectInternet();                                     //!< connect Internet

    signals:
        void sendInternetProgress();                                //!< send Internet Progress

    private:
        QSettings          *mySettings              = nullptr;      //!< \c mySettings              @brief QSettings is used for this class.
        QString             myOrganizationName      = "";           //!< \c myOrganizationName      @brief Organization Name.
        QString             myOrganizationDomain    = "";           //!< \c myOrganizationDomain    @brief Organization Domain.
        QString             myApplicationName       = "";           //!< \c myApplicationName       @brief Application Name.
        QString             myLastApplicationFolder = "";           //!< \c myLastApplicationFolder @brief Last Application Folder
        QPoint              myGeometryPos;                          //!< \c myGeometryPos           @brief Windows Geometry Pos
        QSize               myGeometrySize;                         //!< \c myGeometrySize          @brief Windows Geometry Size
        bool                myGeometryMax           = false;        //!< \c myGeometryMax           @brief Windows Geometry Max
        bool                myGeometryMin           = false;        //!< \c myGeometryMin           @brief Windows Geometry Min
        bool                isDebugMessage          = false;        //!< \c isDebugMessage          @brief Debug Message
        bool                isCreated               = false;        //!< \c isCreated               @brief if file is created
};
#endif // MY_ORG_SETTINGS_H
/*** ************************* End of File ***********************************/
