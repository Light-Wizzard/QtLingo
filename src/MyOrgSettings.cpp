#include "MyOrgSettings.h"

/*! ***************************************************************************
   \fn MyOrgSettings
   \brief Creates QSettings for organizationName, organizationDomain, applicationName
 *************************************************************************** */
MyOrgSettings::MyOrgSettings(QObject *parent) : QObject(parent)
{
    // Fixed random number, change it before using it, then leave it,
    // all data stored with this key will only work with this key.
    // Defined in MyConstants.h
    myCrypto = new MySimpleCrypt(MY_CRYPTO_SEED);
    // Constants
    myConstants = new MyConstants();
    // Run after GUI loads
    QTimer::singleShot(200, this, &MyOrgSettings::onRunOnStartup);
}
/*! ***************************************************************************
   \fn ~MyOrgSettings
   \brief Deconstructor
 *************************************************************************** */
MyOrgSettings::~MyOrgSettings()
{

}
/*! ***************************************************************************
   \fn setDebugMessage
   \brief set Debug Message
 *************************************************************************** */
void MyOrgSettings::setDebugMessage(bool thisState)
{
    isDebugMessage = thisState;
    if (isDebugMessage) { qDebug() << "setDebugMessage"; }
}
/*! ***************************************************************************
   \fn getDebugMessage
   \brief get Debug Message
 *************************************************************************** */
bool MyOrgSettings::getDebugMessage()
{
    if (isDebugMessage) { qDebug() << "getDebugMessage"; }
    return isDebugMessage;
}
/*! ***************************************************************************
   \fn onRunOnStartup
   \brief Run On Start up
 *************************************************************************** */
void MyOrgSettings::onRunOnStartup()
{
    if (isDebugMessage)
    {
        qDebug() << "onRunOnStartup";
        QString theTest = "This is my Secret";
        if (theTest != decryptThis(encryptThis(theTest)))
        { showMessageBox(QObject::tr("Crypto Fail").toLocal8Bit(), tr("Crypto Fail: MyOrgSettings::onRunOnStartup()").toLocal8Bit(), Critical); }
    }
}
/*! ***************************************************************************
   \fn getSettings
   \brief get Settings
 *************************************************************************** */
QSettings *MyOrgSettings::getSettings()
{
    if (isDebugMessage) { qDebug() << "getSettings"; }
    // organizationName, organizationDomain, applicationName and applicationName
    // are set in main.cpp, and passed into Constuctor, so they are set
    QCoreApplication::setOrganizationName(getOrgName());
    QCoreApplication::setOrganizationDomain(getOrgDomain());
    QCoreApplication::setApplicationName(getAppName());
    //QCoreApplication::setApplicationDisplayName(getAppName());
    // see *.pro file where it is: DEFINES *= APP_VERSION=$${VERSION}
    // cmake does not have this yet, this is a hack till I FIXME
    QCoreApplication::setApplicationVersion(QObject::tr(VERSION));
    QString myIni = QString("%1%2%3").arg(getAppDataLocation(), QDir::separator(), myConstants->MY_INI_FILE);
    if (!isFileMake(getAppDataLocation(), myConstants->MY_INI_FILE))
    {
        qCritical() << "Failed to make File in getSettings " << getAppDataLocation() << QDir::separator() << myConstants->MY_INI_FILE;
    }
    return new QSettings(myIni, QSettings::IniFormat);
} // end qSettingsInstance
/*! ***************************************************************************
   \fn isSetting
   \brief is Setting
 *************************************************************************** */
bool MyOrgSettings::isSetting(const QString &thisFieldName)
{
    if (isDebugMessage) { qDebug() << "isSetting"; }
    QSettings *mySettings = getSettings();
    return mySettings->contains(thisFieldName);
} // end isSetting
/*! ***************************************************************************
   \fn readSettings
   \brief read Settings
 *************************************************************************** */
QString MyOrgSettings::readSettings(const QString &thisSetting, const QString &thisDefault)
{
    if (isDebugMessage) { qDebug() << "readSettings"; }
    QSettings *mySettings = getSettings();
    mySettings->beginGroup("General");
    QString theSetting = mySettings->value(thisSetting, thisDefault).toString();
    mySettings->endGroup();
    return theSetting;
}
/*! ***************************************************************************
   \fn readSettingsBool
   \brief read Settings Bool
 *************************************************************************** */
bool MyOrgSettings::readSettingsBool(const QString &thisSetting, bool thisDefault)
{
    if (isDebugMessage) { qDebug() << "readSettingsBool"; }
    QSettings *mySettings = getSettings();
    mySettings->beginGroup("General");
    bool theSetting = mySettings->value(thisSetting, thisDefault).toBool();
    mySettings->endGroup();
    return theSetting;
}
/*! ***************************************************************************
   \fn readSettingsInt
   \brief read Settings Int
 *************************************************************************** */
int MyOrgSettings::readSettingsInt(const QString &thisSetting, int thisDefault)
{
    if (isDebugMessage) { qDebug() << "readSettingsInt"; }
    QSettings *mySettings = getSettings();
    mySettings->beginGroup("General");
    int theSetting = mySettings->value(thisSetting, thisDefault).toInt();
    mySettings->endGroup();
    return theSetting;
}
/*! ***************************************************************************
   \fn writeSettings
   \brief write Settings
 *************************************************************************** */
void MyOrgSettings::writeSettings(const QString &thisSetting, const QString &thisValue)
{
    if (isDebugMessage) { qDebug() << "writeSettings"; }
    QSettings *mySettings = getSettings();
    mySettings->beginGroup("General");
    mySettings->setValue(thisSetting, thisValue);
    mySettings->endGroup();
}
/*! ***************************************************************************
   \fn getDataPath
   \brief get Data Path
 *************************************************************************** */
QString MyOrgSettings::getDataPath(const QString &thisFileName)
{
    if (isDebugMessage) { qDebug() << "getDataPath"; }
    //
    QDir settingsPath;
    // FIXME this is where the exe is
    QString myDataPath = QString("%1%2%3").arg(settingsPath.currentPath(), QDir::separator(), thisFileName);
    if (isDebugMessage) { qDebug() << "getDataPath = " << myDataPath; }
    return myDataPath;
}
/*! ***************************************************************************
   \fn getLastApplicationPath
   \brief get Last Application Path
 *************************************************************************** */
QString MyOrgSettings::getLastApplicationPath()
{
    if (isDebugMessage) { qDebug() << "getLastApplicationPath"; }
    if (myLastApplicationFolder.isEmpty())
    {
        //
        QString theProjectPath = QCoreApplication::applicationFilePath();
        if (!isPathExists(theProjectPath))
        {
            qWarning() << "getLastApplicationPath not found = " << theProjectPath;
            theProjectPath = QDir::currentPath();
        }
        myLastApplicationFolder = readSettings(myConstants->MY_LAST_PROJECT_FOLDER, theProjectPath);
    }
    return myLastApplicationFolder;
}
/*! ***************************************************************************
   \fn setLastApplicationPath
   \brief set Last Application Path
 *************************************************************************** */
void MyOrgSettings::setLastApplicationPath(const QString &thisPath)
{
    if (isDebugMessage) { qDebug() << "setLastApplicationPath"; }
    myLastApplicationFolder = thisPath;
    writeSettings(myConstants->MY_LAST_PROJECT_FOLDER, thisPath);
}
/*! ***************************************************************************
   \fn combinePathFileName
   \brief combine Path File Name
 *************************************************************************** */
QString MyOrgSettings::combinePathFileName(const QString &thisPath,const  QString &thisFileName)
{
    if (isDebugMessage) { qDebug() << "combinePathFileName"; }
    return QString("%1%2%3").arg(thisPath, QDir::separator(), thisFileName);
} // end combinePathFileName
/*! ***************************************************************************
   \fn isPathExists
   \brief is Path Exists
 *************************************************************************** */
bool MyOrgSettings::isPathExists(const QString &thisPath)
{
    if (isDebugMessage) { qDebug() << "isPathExists"; }
    return QDir(thisPath).exists() && QFileInfo(thisPath).isDir();
} // end isPathExists
/*! ***************************************************************************
   \fn isFileExists
   \brief is File Exists
 *************************************************************************** */
bool MyOrgSettings::isFileExists(const QString &thisFile)
{
    if (isDebugMessage) { qDebug() << "isFileExists"; }
    // check if file exists and if yes: Is it really a file and not directory?
    return QFileInfo::exists(thisFile) && QFileInfo(thisFile).isFile();
} // end isFileExists
/*! ***************************************************************************
   \fn removeFile
   \brief remove File
 *************************************************************************** */
bool MyOrgSettings::removeFile(const QString &thisFile)
{
    if (isDebugMessage) { qDebug() << "removeFile"; }
    if (isFileExists(thisFile))
    { return QFile::remove(thisFile); }
    return true;
}
/*! ***************************************************************************
   \fn isFileMake
   \brief is File Make
 *************************************************************************** */
bool MyOrgSettings::isFileMake(const QString &thisPath, const QString &thisFileName)
{
    if (isDebugMessage) { qDebug() << "isFileMake"; }
    isCreated = false;
    QString thePath = combinePathFileName(thisPath, thisFileName);
    if (!isMakeDir(thisPath)) return false;
    if (!isFileExists(thePath))
    {
        QFile theFile(thePath);
        if (theFile.open(QIODevice::WriteOnly))
        {
            /* Point a QTextStream object at the file */
            QTextStream outStream(&theFile);
            /* Write the line to the file */
            outStream << QString("%1 %2").arg(tr("This file was created to test if this folder is writeable by"), QCoreApplication::applicationName()).toLocal8Bit();
            /* Close the file */
            theFile.close();
            if (isFileExists(thePath)) { isCreated = true; }
            return isCreated;
        }
        else return false;
    }
    return true;
} // end isFileMake
/*! ***************************************************************************
   \fn isMakeDir
   \brief is Make Dir
 *************************************************************************** */
bool MyOrgSettings::isMakeDir(const QString &thisPath)
{
    if (isDebugMessage) { qDebug() << "isMakeDir"; }
    QDir dir(thisPath);
    if (!dir.exists())
    {
        if (!dir.mkpath("."))
        { showMessageBox(QObject::tr("File System Error").toLocal8Bit(), QString("%1 %2").arg(tr("Error: cannot create file"), thisPath).toLocal8Bit(), Critical); }
        else return true;
    }
    return isPathExists(thisPath);
} // end isMakeDir
/*! ***************************************************************************
   \fn getOrgName
   \brief This value is used for Qt Settings: GitHub Account Name is one example
 *************************************************************************** */
QString MyOrgSettings::getOrgName()
{
    if (isDebugMessage) { qDebug() << "getOrgName"; }
    return myOrganizationName;
} // end getOrgName
/*! ***************************************************************************
   \fn setOrgName
   \brief set Org Name
 *************************************************************************** */
void MyOrgSettings::setOrgName(const QString &thisOrgName)
{
    if (isDebugMessage) { qDebug() << "setOrgName"; }
    if (QString::compare(myOrganizationName, thisOrgName, Qt::CaseInsensitive))
    {
        myOrganizationName = thisOrgName;
    }
} // end setOrgName
/*! ***************************************************************************
   \fn getOrgDomain
   \brief get Org Domain
 *************************************************************************** */
QString MyOrgSettings::getOrgDomain()
{
    if (isDebugMessage) { qDebug() << "getOrgDomain"; }
    return myOrganizationDomain;
} // end getOrgDomain
/*! ***************************************************************************
   \fn setOrgDomain
   \brief set Org Domain
 *************************************************************************** */
void MyOrgSettings::setOrgDomain(const QString &thisOrgDomain)
{
    if (isDebugMessage) { qDebug() << "setOrgDomain"; }
    if (QString::compare(myOrganizationDomain, thisOrgDomain, Qt::CaseInsensitive))
    {
        myOrganizationDomain = thisOrgDomain;
    }
} // end setOrgDomain
/*! ***************************************************************************
   \fn getAppName
   \brief get App Name
 *************************************************************************** */
QString MyOrgSettings::getAppName()
{
    if (isDebugMessage) { qDebug() << "getAppName"; }
    return myApplicationName;
} // end getAppName
/*! ***************************************************************************
   \fn setAppName
   \brief set App Name
 *************************************************************************** */
void MyOrgSettings::setAppName(const QString &thisAppName)
{
    if (isDebugMessage) { qDebug() << "setAppName"; }
    if (QString::compare(myApplicationName, thisAppName, Qt::CaseInsensitive))
    {
        myApplicationName = thisAppName;
    }
} // end setAppName
/*! ***************************************************************************
   \fn setGeometry
   \brief set Geometry
 *************************************************************************** */
void MyOrgSettings::setGeometry(QPoint thisPos, QSize thisSize, bool isMax, bool isMin)
{
    if (isDebugMessage) { qDebug() << "setGeometry"; }
    QSettings *mySettings = getSettings();
    mySettings->beginGroup("General");
    mySettings->setValue(myConstants->MY_GEOMETRY_POS, thisPos);
    mySettings->setValue(myConstants->MY_GEOMETRY_MAX, isMax);
    mySettings->setValue(myConstants->MY_GEOMETRY_MIN, isMin);
    if(!isMax && !isMin) mySettings->setValue(myConstants->MY_GEOMETRY_SIZE, thisSize);
    mySettings->endGroup();
} // end setGeometry
/*! ***************************************************************************
   \fn getGeometry
   \brief get Geometry
 *************************************************************************** */
void MyOrgSettings::getGeometry()
{
    if (isDebugMessage) { qDebug() << "getGeometry"; }
    // Geometry
    QSettings *mySettings = getSettings();
    mySettings->beginGroup("General");
    myGeometryPos  = mySettings->value(myConstants->MY_GEOMETRY_POS, ConstDefaultGeometryPos).toPoint();
    myGeometrySize = mySettings->value(myConstants->MY_GEOMETRY_SIZE, ConstDefaultGeometrySize).toSize();
    myGeometryMax  = mySettings->value(myConstants->MY_GEOMETRY_MAX, true).toBool();
    myGeometryMin  = mySettings->value(myConstants->MY_GEOMETRY_MIN, false).toBool();
    mySettings->endGroup();
} // end getGeometry
/*! ***************************************************************************
   \fn getGeometryPos
   \brief get Geometry Pos
 *************************************************************************** */
QPoint MyOrgSettings::getGeometryPos()
{
    if (isDebugMessage) { qDebug() << "getGeometryPos"; }
    return myGeometryPos;
} // end getGeometryPos
/*! ***************************************************************************
   \fn getGeometrySize
   \brief get Geometry Size
 *************************************************************************** */
QSize MyOrgSettings::getGeometrySize()
{
    if (isDebugMessage) { qDebug() << "getGeometrySize"; }
    return myGeometrySize;
} // end getGeometrySize
/*! ***************************************************************************
   \fn getGeometryMax
   \brief get Geometry Max
 *************************************************************************** */
bool MyOrgSettings::getGeometryMax()
{
    if (isDebugMessage) { qDebug() << "getGeometryMax"; }
    return myGeometryMax;
} // end getGeometryMax
/*! ***************************************************************************
   \fn getGeometryMin
   \brief get Geometry Min
 *************************************************************************** */
bool MyOrgSettings::getGeometryMin()
{
    if (isDebugMessage) { qDebug() << "getGeometryMin"; }
    return myGeometryMin;
} // end getGeometryMin
/*! ***************************************************************************
   \fn readFile
   \brief read File
 *************************************************************************** */
QString MyOrgSettings::readFile(const QString &thisFileName)
{
    if (isDebugMessage) { qDebug() << "readFile"; }
    QFile file(thisFileName);
    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        showMessageBox(tr("Error opening file for reading").toLocal8Bit(), QString("%1: %2").arg(tr("Could not open file for reading"), thisFileName).toLocal8Bit(), Critical);
        return "";
    }
    QTextStream in(&file);
    QString thisText = in.readAll();
    file.close();
    return thisText;
}
/*! ***************************************************************************
   \fn writeFile
   \brief write File
 *************************************************************************** */
bool MyOrgSettings::writeFile(const QString &thisFileName, const QString &thisContent)
{
    if (isDebugMessage) { qDebug() << "writeFile"; }
    QFile theFile(thisFileName);
    // Trying to open in WriteOnly and Text mode
    if(!theFile.open(QFile::WriteOnly | QFile::Text))
    {
        showMessageBox(tr("Error opening file for writing").toLocal8Bit(), QString("%1: %2").arg(tr("Could not open file for writing"), thisFileName).toLocal8Bit(), Critical);
        return false;
    }
    // Write to file
    QTextStream theFileStream(&theFile);
    theFileStream << thisContent;
    theFile.flush();
    theFile.close();
    return true;
} // end writeFile
/*! ***************************************************************************
   \fn encryptThis
   \brief Crypto using SimpleCrypt
 *************************************************************************** */
QString MyOrgSettings::encryptThis(const QString &thisSecret)
{
    if (isDebugMessage) { qDebug() << "encryptThis"; }
    return myCrypto->encryptToString(thisSecret);
}
/*! ***************************************************************************
   \fn decryptThis
   \brief Crypto using SimpleCrypt
 *************************************************************************** */
QString MyOrgSettings::decryptThis(const QString &thisSecret)
{
    if (isDebugMessage) { qDebug() << "decryptThis"; }
    return myCrypto->decryptToString(thisSecret);
}
/*! ***************************************************************************
   \fn questionYesNo
   \brief Titel and Question Yes No
 *************************************************************************** */
bool MyOrgSettings::questionYesNo(const char *thisTitle, const char *thisQuestion)
{
    if (isDebugMessage) { qDebug() << "questionYesNo"; }
    QMessageBox theMsgBox;
    theMsgBox.setWindowTitle(QObject::tr(thisTitle));
    theMsgBox.setText(QObject::tr(thisQuestion));
    theMsgBox.setStandardButtons(QMessageBox::Yes);
    theMsgBox.addButton(QMessageBox::No);
    theMsgBox.setDefaultButton(QMessageBox::No);
    if(theMsgBox.exec() == QMessageBox::Yes)
    {
        if (isDebugMessage) { qDebug() << "Yes was clicked"; }
        return true;
    }
    else
    {
        if (isDebugMessage) { qDebug() << "Yes was *not* clicked"; }
        return false;
    }
} // end questionYesNo
/*! ***************************************************************************
   \fn showMessageBox
   \brief information, question: 1 = true, 0 = false, warning, critical: theMessage.toLocal8Bit()
 *************************************************************************** */
int MyOrgSettings::showMessageBox(const QString &thisTitle, const QString &thisMessage, MyMessageTypes thisMessageType)
{
    if (isDebugMessage) { qDebug() << "showMessageBox(" << thisTitle << ", " << thisMessage << ", " << thisMessageType << ")"; }
    switch (thisMessageType)
    {
        case Information:   { return QMessageBox::information(nullptr, thisTitle, thisMessage, QMessageBox::Ok); }
        case Question:      { if (questionYesNo(thisTitle.toLocal8Bit(), thisMessage.toLocal8Bit())) return 1; else return 0; }
        case Warning:       { return QMessageBox::warning(nullptr, thisTitle, thisMessage, QMessageBox::Ok); }
        case Critical:      { return QMessageBox::critical(nullptr, thisTitle, thisMessage, QMessageBox::Ok); }
    }
    return 0;
} // end showMessageBox
/*! ***************************************************************************
   \fn getFileInfo
   \brief get File Info
 *************************************************************************** */
QString MyOrgSettings::getFileInfo(MyOrgSettings::MyFileinfo thisInfo, const QString &thisFileFolder)
{
    if (isDebugMessage) { qDebug() << "getFileInfo"; }
    if (thisFileFolder.isEmpty()) { return ""; }
    //
    QFileInfo theFileInfo(thisFileFolder);
    //
    switch (thisInfo)
    {
        case AbsoluteFilePath:
            // The absolute path name consists of the full path and the file name.
            return theFileInfo.absoluteFilePath();
        case AbsolutePath:
            // Returns a file's path absolute path. This doesn't include the file name..
            return theFileInfo.absolutePath();
        case BaseName:
            // Returns the base name of the file without the path.
            return theFileInfo.baseName();
        case BirthTime:
            // Returns the date and time when the file was created / born.
            return theFileInfo.birthTime().toString();
        case CanonicalPath:
            // Returns the file's path canonical path (excluding the file name), i.e. an absolute path without symbolic links or redundant "." or ".." elements.
            return theFileInfo.canonicalPath();
        case CanonicalFilePath:
            // Returns the canonical path including the file name, i.e. an absolute path without symbolic links or redundant "." or ".." elements.
            return theFileInfo.canonicalFilePath();
        case CompleteBaseName:
            // Returns the complete base name of the file without the path.
            // "/tmp/archive.tar.gz" == "archive.tar"
            return theFileInfo.completeBaseName();
        case CompleteSuffix:
            // Returns the complete suffix (extension) of the file.
            // "/tmp/archive.tar.gz" == "tar.gz"
            return theFileInfo.completeSuffix();
        case Directory:
            // Returns the path of the object's parent directory as a QDir object.
            return theFileInfo.dir().currentPath();
        case FileName:
            // Returns the name of the file, excluding the path. getFileInfo(FileName, "")
            return theFileInfo.fileName();
        case FilePath:
            // Returns the file name, including the path (which may be absolute or relative).
            return theFileInfo.filePath();
        case IsWritable:
            // Returns true if the user can write to the file; otherwise returns false.
            if (theFileInfo.isWritable()) return "true"; else return "false";
        case FileSize:
            return QString::number(theFileInfo.size());
        case IsFile:
            if (isFileExists(thisFileFolder)) return "true"; else return "false";
        case IsFolder:
            if (isPathExists(thisFileFolder)) return "true"; else return "false";
        case IsSymLink:
            if (theFileInfo.isSymLink()) return "true"; else return "false";
        case SymLinkTarget:
            if (theFileInfo.isSymLink()) return theFileInfo.symLinkTarget(); else return "";
    }
    return "";
}
/*! ***************************************************************************
   \fn isAppDataLocationGood
   \brief is App Data Location Good
 *************************************************************************** */
bool MyOrgSettings::isAppDataLocationGood(const QString &thisFolder)
{
    if (isDebugMessage) { qDebug() << "isAppDataLocationGood"; }
    bool isGood = true;
    if (isFileMake(thisFolder, "ReadMe.txt"))
    {
        if (getFileInfo(IsWritable, combinePathFileName(thisFolder, "ReadMe.txt")) == "false")
        {
            isGood = false;
        }
    }
    else
    {
        isGood = false;
    }
    if (getFileInfo(IsFolder, thisFolder) == "false")
    {
        isGood = false;
    }
    return isGood;
} // end isAppDataLocationGood
/*! ***************************************************************************
   \fn getAppDataLocation
   \brief get App Data Location
 *************************************************************************** */
QString MyOrgSettings::getAppDataLocation()
{
    if (isDebugMessage) { qDebug() << "getAppDataLocation"; }
    QString theAppDataLocation = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    if (theAppDataLocation.isEmpty())
    {
        theAppDataLocation = QStandardPaths::writableLocation(QStandardPaths::GenericDataLocation);
        if (theAppDataLocation.isEmpty())
        { theAppDataLocation = QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation); }
        if (theAppDataLocation.isEmpty())
        { theAppDataLocation = QDir::currentPath(); }
    }
    if (!isAppDataLocationGood(theAppDataLocation))
    {
        return QDir::currentPath(); // FIXME
    }
    return theAppDataLocation;
} // end getAppDataLocation
/*! ***************************************************************************
   \fn getEnvironmentVar
   \brief get Environment Var
inline auto get_environement_variable(const char* key )
{
    char * val = getenv(key);
    return (val == NULL) ? "" : std::string(val);
}
auto programFiles = get_environement_variable("%ProgramW6432%");
auto programFilesX86 = get_environement_variable("%ProgramFiles(x86)%");
auto userProfile = get_environement_variable("%USERPROFILE%");
auto userProfile = get_environement_variable("%USERPROFILE%\Documents");
 *************************************************************************** */
QString MyOrgSettings::getEnvironmentVar(const QString &thisVar, const QString &thisDefault)
{
    QString theEnvValue = qEnvironmentVariable(thisVar.toLocal8Bit());
    if (!theEnvValue.isNull())
    { return theEnvValue; }
    else
    { return thisDefault; }
}
/*! ***************************************************************************
   \fn isWord
   \brief is Word
 *************************************************************************** */
bool MyOrgSettings::isWord(const QString &thisString) const
{
    for(int i = 0; i< thisString.length(); i++)
    {
        if (thisString.at(i).isLetter())
            return true;
    }
    return false;
}
/*! ***************************************************************************
   \fn delay
   \brief delay
 *************************************************************************** */
void MyOrgSettings::delay(int thisSeconds)
{
    QEventLoop theDelayLoop;
    QTimer::singleShot(thisSeconds * 1000, &theDelayLoop, &QEventLoop::quit);
    theDelayLoop.exec();
} // end delay
/*! ***************************************************************************
   \fn fileNumberLines
   \brief Number of Lines in a file
 *************************************************************************** */
int MyOrgSettings::fileNumberLines(const QString &thisFile)
{
    if (!isFileExists(thisFile)) { showMessageBox(tr("File not found").toLocal8Bit(), QString("%1: %2").arg(tr("File not found"), thisFile).toLocal8Bit(), Critical); return 0; }
    std::ifstream inFile(thisFile.toLocal8Bit());
    return std::count(std::istreambuf_iterator<char>(inFile), std::istreambuf_iterator<char>(), '\n');
} // end fileNumberLines
/*! ***************************************************************************
   \fn removeAllFiles
   \brief removeAllFiles
 *************************************************************************** */
void MyOrgSettings::removeAllFiles(const QString &thisFolder)
{
    if (!isPathExists(thisFolder)) { showMessageBox(tr("Folder not found").toLocal8Bit(), QString("%1: %2").arg(tr("Folder not found"), thisFolder).toLocal8Bit(), Critical); return;  }
    QDir theDirFiles(thisFolder);
    theDirFiles.setNameFilters(QStringList() << "*.*");
    theDirFiles.setFilter(QDir::Files);
    foreach(QString theDirFile, theDirFiles.entryList())
    {
        theDirFiles.remove(theDirFile);
    }
} // end removeAllFiles
/*** ************************* End of File ***********************************/
