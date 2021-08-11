#ifndef MY_ORG_SETTINGS_H
#define MY_ORG_SETTINGS_H

#include <QCoreApplication>
#include <QtCore>
#include <QObject>
#include <QtDebug>
#include <QMessageBox>
#include <QFileInfo>
#include <QtGlobal>
#include <QTime>
//
#include "MyConstants.h"
// Crypto
#include "MySimpleCrypt.h"

//#include "third-party/qonlinetranslator/src/qonlinetranslator.h"
#include "qonlinetranslator.h"

#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*! ***************************************************************************
   \class MyOrgSettings
   \brief My Org Settings
 *************************************************************************** */
class MyOrgSettings : public QObject
{
        Q_OBJECT
    public:
         explicit MyOrgSettings(QObject *parent = nullptr);  //!< MySettings Constructor
        ~MyOrgSettings();                                    //!< MySettings Destructor
        /*!
            \enum MyFileinfo
            \brief File Information
         */
        enum MyFileinfo
        {
            AbsolutePath      = 100, //!< \c AbsolutePath      \brief The absolute path name consists of the full path and the file name.
            AbsoluteFilePath  = 101, //!< \c CanonicalPath     \brief Returns a file's path absolute path, does not include the file name.
            BaseName          = 102, //!< \c BaseName          \brief Returns the base name of the file without the path.
            BirthTime         = 103, //!< \c BirthTime         \brief Returns the date and time when the file was created / born.
            CanonicalPath     = 104, //!< \c CanonicalPath     \brief Returns the canonical path including the file name, i.e. an absolute path without symbolic links or redundant "." or ".." elements.
            CanonicalFilePath = 105, //!< \c CanonicalFilePath \brief Returns the file's path canonical path (excluding the file name), i.e. an absolute path without symbolic links or redundant "." or ".." elements.
            CompleteBaseName  = 106, //!< \c CompleteBaseName  \brief Returns the complete base name of the file without the path.
            CompleteSuffix    = 107, //!< \c CompleteSuffix    \brief Returns the complete suffix (extension) of the file.
            Directory         = 108, //!< \c Directory         \brief Returns the path of the object's parent directory as a QDir object.
            FileName          = 109, //!< \c FileName          \brief Returns the name of the file, excluding the path.
            FilePath          = 110, //!< \c FilePath          \brief Returns the file name, including the path (which may be absolute or relative).
            IsWritable        = 111, //!< \c IsWritable        \brief Returns true if the user can write to the file; otherwise returns false.
            IsFile            = 112, //!< \c IsFile            \brief Returns true if this object points to a file or to a symbolic link to a file. Returns false if the object points to something which isn't a file, such as a directory.
            IsFolder          = 113, //!< \c IsFolder          \brief Returns true if this object points to a directory or to a symbolic link to a directory; otherwise returns false.
            FileSize          = 114, //!< \c FileSize          \brief File Size
            IsSymLink         = 115, //!< \c IsSymLink         \brief Returns true if this object points to a symbolic link; otherwise returns false.
            SymLinkTarget     = 116, //!< \c SymLinkTarget     \brief Returns the absolute path to the file or directory a symbolic link points to, or an empty string if the object isn't a symbolic link.
        }; // end enum MyFileinfo
        // Makes getting file Info easier
        Q_ENUM(MyFileinfo)
        /*!
            \enum MyMessageTypes
            \brief Message Types
         */
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
        MyConstants   *myConstants; //!< \c myConstants \brief All Constants in one class
        MySimpleCrypt *myCrypto;    //!< \c myCrypto    \brief myCrypto
        // Not added to above Constants, these need to FIXME
        const QPoint  ConstDefaultGeometryPos  = QPoint(10, 10);   //!< \c ConstDefaultGeometryPos     \brief Top, Left.
        const QSize   ConstDefaultGeometrySize = QSize(1134, 817); //!< \c ConstDefaultGeometrySize    \brief Width x Height.
        //
        void onRunOnStartup();                                                          //!< Run On Startup
        // Read
        QString readSettings(const QString &thisSetting, const QString &thisDefault);   //!< readSettings
        bool    readSettingsBool(const QString &thisSetting, bool thisDefault);         //!< readSettingsBool
        int     readSettingsInt(const QString &thisSetting, int thisDefault);           //!< readSettingsInt
        // Write
        void writeSettings(const QString &thisSetting, const QString &thisValue);       //!< writeSettings
        // Getter/Setter
        QSettings *getSettings();                                                       //!< getSettings
        QString getDataPath(const QString &thisFileName);                               //!< GetDataPath
        // Org Name
        QString getOrgName();                                                           //!< getOrgName
        void    setOrgName(const QString &thisOrgName);                                 //!< setOrgName
        // Org Domain
        QString getOrgDomain();                                                         //!<  myOrganizationDomain
        void    setOrgDomain(const QString &thisOrgDomain);
        // Application Name
        QString getAppName();                                                           //!< myApplicationName
        void    setAppName(const QString &thisAppName);                                 //!< setAppName
        // File Utilities
        QString readFile(const QString &thisFileName);                                  //!< readFile
        QString combinePathFileName(const QString &thisPath, const QString &thisFileName); //!< combinePathFileName
        bool isFileExists(const QString &thisFile);                                     //!< File Functions
        bool isFileMake(const QString &thisPath, const QString &thisFileName);          //!< isFileMake
        bool isPathExists(const QString &thisPath);                                     //!< isPathExists
        bool isMakeDir(const QString &thisPath);                                        //!< isMakeDir
        bool removeFile(const QString &thisFile);                                       //!< remove File
        bool writeFile(const QString &thisFileName, const QString &thisContent);        //!< write File
        QString getFileInfo(MyOrgSettings::MyFileinfo thisInfo, const QString &thisFileFolder); //!< getFileInfo
        int fileNumberLines(const QString &thisFile);                                   //!< file Number Lines
        void removeAllFiles(const QString &thisFolder);                                 //!< remove All Files
        QString getLastApplicationPath();                                               //!< get Last Application Path
        void    setLastApplicationPath(const QString &thisPath);                        //!< set Last Application Path
        QString getAppDataLocation();                                                   //!< getAppDataLocation
        bool    isAppDataLocationGood(const QString &thisFolder);                       //!< isAppDataLocationGood
        //
        bool   isSetting(const QString &thisFieldName);                                 //!< isSetting
        // Screen Geometry
        void   setGeometry(QPoint thisPos, QSize thisSize, bool isMax, bool isMin);     //!< Screen Geometry
        void   getGeometry();                                                           //!< getGeometry
        QPoint getGeometryPos();                                                        //!< getGeometryPos
        QSize  getGeometrySize();                                                       //!< getGeometrySize
        bool   getGeometryMax();                                                        //!< getGeometryMax
        bool   getGeometryMin();                                                        //!< getGeometryMin
        // Crypto for Password
        QString encryptThis(const QString &thisSecret);                                 //!< encryptThis
        QString decryptThis(const QString &thisSecret);                                 //!< decryptThis
        bool    questionYesNo(const char *thisTitle, const char *thisQuestion);         //!< questionYesNo
        int     showMessageBox(const QString &thisTitle, const QString &thisMessage, MyOrgSettings::MyMessageTypes thisMessageType); //!< show Message Box information, question, warning, critica
        //
        QString getEnvironmentVar(const QString &thisVar, const QString &thisDefault);  //!< get Windows Environment Var
        bool isWord(const QString &thisString) const;                                   //!< is Word
        void delay(int thisSeconds);                                                    //!< delay
        // Is Debug Message
        void setDebugMessage(bool thisState);                       //!< set Debug Message
        bool getDebugMessage();                                     //!< get Debug Message

    private:
        QSettings          *mySettings             = nullptr;       //!< \c mySettings              \brief QSettings is used for this class.
        QOnlineTranslator   myQOnlineTranslator;                    //!< \c myQOnlineTranslator     \brief QOnlineTranslator
        QString             myOrganizationName      = "QtLingo";    //!< \c myOrganizationName      \brief Organization Name.
        QString             myOrganizationDomain    = "QtLingo";    //!< \c myOrganizationDomain    \brief Organization Domain.
        QString             myApplicationName       = "QtLingo";    //!< \c myApplicationName       \brief Application Name.
        QString             myLastApplicationFolder = "";           //!< \c myLastApplicationFolder \brief Last Application Folder
        QPoint              myGeometryPos;                          //!< \c myGeometryPos           \brief Windows Geometry Pos
        QSize               myGeometrySize;                         //!< \c myGeometrySize          \brief Windows Geometry Size
        bool                myGeometryMax           = false;        //!< \c myGeometryMax           \brief Windows Geometry Max
        bool                myGeometryMin           = false;        //!< \c myGeometryMin           \brief Windows Geometry Min
        bool                isDebugMessage          = false;        //!< \c isDebugMessage          \brief true of false
        bool                isCreated               = false;        //!< \c isCreated               \brief true of false if file is created
};
#endif // MY_ORG_SETTINGS_H
/*** ************************* End of File ***********************************/
