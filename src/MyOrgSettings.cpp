/************************************************
* @file MyOrgSettings.cpp
* @brief My Orginization Settings for INI files,
* My Org Settings has many functions to help track variables,
* I check variables before setting them to prevent triggers.
* @author Jeffrey Scott Flesher <Jeffrey.Scott.Flesher@>
 ***********************************************/
#include "MyOrgSettings.h"
/************************************************
 * @brief Creates QSettings for organizationName, organizationDomain, applicationName.
 * MyOrgSettings
 ***********************************************/
MyOrgSettings::MyOrgSettings(QObject *parent) : QObject(parent)
{
    // Fixed random number, change it before using it, then leave it,
    // all data stored with this key will only work with this key.
    // Defined in MyOrgSettings.h
    myCrypto = new SimpleCrypt(MY_CRYPTO_SEED);
    // Trigger for Update
    connect(this, &MyOrgSettings::sendUpdateSettings, this, &MyOrgSettings::onUpdateSettings);

    // Run after GUI loads
    QTimer::singleShot(200, this, &MyOrgSettings::onRunOnStartup);
}
/************************************************
 * @brief Deconstructor.
 * ~MyOrgSettings
 ***********************************************/
MyOrgSettings::~MyOrgSettings()
{

}
/************************************************
 * @brief Run On Start up.
 * onRunOnStartup
 ***********************************************/
void MyOrgSettings::onRunOnStartup()
{
    if (isDebugMessage)
    {
        setMessage("on Run On Start up", "onRunOnStartup", Debug);
        // FIXME move to test project
        QString theTest = "This is my Secret";
        if (theTest != decryptThis(encryptThis(theTest)))
        { setMessage(QObject::tr("Crypto Fail").toLocal8Bit(), tr("Crypto Fail: MyOrgSettings::onRunOnStartup()").toLocal8Bit(), Critical); }
    }
}
/************************************************
 * @brief on Update Settings.
 * onUpdateSettings
 ***********************************************/
void MyOrgSettings::onUpdateSettings()
{
    mySettings = getSettings();
}
/************************************************
 * @brief on Update Settings.
 * onUpdateSettings
 ***********************************************/
QSettings *MyOrgSettings::getSetteings()
{
    return mySettings;
}
/************************************************
 * @brief get Settings.
 * getSettings
 ***********************************************/
QSettings *MyOrgSettings::getSettings()
{
    setMessage("get Settings", "getSettings", Debug);
    if (!isFileExists(getIniFullPath()))
    {
        if (!isFileMake(getAppDataLocation(), QString("%1.%2").arg(getIniFileName(), getIniFileExtension())))
        {
            setMessage("get Settings", QString("%1: %2").arg(QObject::tr("Failed to make File in getSettings"), getIniFullPath()), Critical);
        }
    }
    return new QSettings(getIniFullPath(), QSettings::IniFormat);
} // end qSettingsInstance
/************************************************
 * @brief is Setting.
 * isSetting
 ***********************************************/
bool MyOrgSettings::isSetting(const QString &thisFieldName)
{
    setMessage("is Setting", QString("isSetting(%1)").arg(thisFieldName), Debug);
    return mySettings->contains(thisFieldName);
} // end isSetting
/************************************************
 * @brief read Settings.
 * readSettings
 ***********************************************/
QString MyOrgSettings::readSettings(const QString &thisSetting, const QString &thisDefault)
{
    setMessage("read Settings", QString("readSettings(%1, %2)").arg(thisSetting, thisDefault), Debug);
    mySettings->beginGroup("General");
    QString theSetting = mySettings->value(thisSetting, thisDefault).toString();
    mySettings->endGroup();
    return theSetting;
}
/************************************************
 * @brief read Settings.
 * readSettings
 ***********************************************/
QString MyOrgSettings::readSettings(const QString &thisSetting)
{
    setMessage("read Settings", QString("readSettings(%1)").arg(thisSetting), Debug);
    mySettings->beginGroup("General");
    QString theSetting = mySettings->value(thisSetting).toString();
    mySettings->endGroup();
    return theSetting;
}
/************************************************
 * @brief read Settings Bool.
 * readSettingsBool
 ***********************************************/
bool MyOrgSettings::readSettingsBool(const QString &thisSetting, bool thisDefault)
{
    setMessage("read Settings Bool", QString("readSettingsBool(%1, %2)").arg(thisSetting, thisDefault), Debug);
    mySettings->beginGroup("General");
    bool theSetting = mySettings->value(thisSetting, thisDefault).toBool();
    mySettings->endGroup();
    return theSetting;
}
/************************************************
 * @brief read Settings Int.
 * readSettingsInt
 ***********************************************/
int MyOrgSettings::readSettingsInt(const QString &thisSetting, int thisDefault)
{
    setMessage("read Settings Int", QString("readSettingsInt(%1, %2)").arg(thisSetting, thisDefault), Debug);
    mySettings->beginGroup("General");
    int theSetting = mySettings->value(thisSetting, thisDefault).toInt();
    mySettings->endGroup();
    return theSetting;
}
/************************************************
 * @brief write Settings.
 * writeSettings
 ***********************************************/
void MyOrgSettings::writeSettings(const QString &thisSetting, const QString &thisValue)
{
    setMessage("write Settings", QString("writeSettings(%1, %2)").arg(thisSetting, thisValue), Debug);
    mySettings->beginGroup("General");
    mySettings->setValue(thisSetting, thisValue);
    mySettings->endGroup();
}
/************************************************
 * @brief get Data Path.
 * getDataPath
 * FIXME
 ***********************************************/
QString MyOrgSettings::getDataPath(const QString &thisFileName)
{
    setMessage("get Data Path", QString("getDataPath(%1)").arg(thisFileName), Debug);
    //
    QDir settingsPath;
    // FIXME this is where the exe is
    QString myDataPath = QString("%1%2%3").arg(settingsPath.currentPath(), QDir::separator(), thisFileName);
    setMessage("", "getDataPath = " + myDataPath, Debug);
    return myDataPath;
}
/************************************************
 * @brief get Last Application Path.
 * getLastApplicationPath
 ***********************************************/
QString MyOrgSettings::getLastApplicationPath()
{
    if (myLastApplicationFolder.isEmpty())
    {
        //
        QString theProjectPath = QCoreApplication::applicationFilePath();
        if (!isPathExists(theProjectPath))
        {
            setMessage("get Last Application Path", QString("%1 getLastApplicationPath(%2) - %3").arg(tr("getLastApplicationPath not found"), myLastApplicationFolder, theProjectPath), Warning);
            theProjectPath = QDir::currentPath();
        }
        setLastApplicationPath(readSettings(MY_LAST_PROJECT_FOLDER, theProjectPath));
    }
    setMessage("get Last Application Path", QString("getLastApplicationPath(%1)").arg(myLastApplicationFolder), Debug);
    return myLastApplicationFolder;
}
/************************************************
 * @brief set Last Application Path.
 * setLastApplicationPath
 ***********************************************/
void MyOrgSettings::setLastApplicationPath(const QString &thisPath)
{
    setMessage("set Last Application Path", QString("setLastApplicationPath(%1)").arg(thisPath), Debug);
    myLastApplicationFolder = thisPath;
    writeSettings(MY_LAST_PROJECT_FOLDER, thisPath);
}
/************************************************
 * @brief This value is used for Qt Settings: GitHub Account Name is one example.
 * getOrgName
 ***********************************************/
QString MyOrgSettings::getOrgName()
{
    if (myOrganizationName.isEmpty()) { setOrgName(qApp->organizationName()); }
    setMessage("get Org Name", QString("getOrgName(%1)").arg(myOrganizationName), Debug);
    return myOrganizationName;
} // end getOrgName
/************************************************
 * @brief set Org Name.
 * setOrgName
 ***********************************************/
void MyOrgSettings::setOrgName(const QString &thisOrgName)
{
    setMessage("set Org Name", QString("setOrgName(%1)").arg(thisOrgName), Debug);
    if (QString::compare(myOrganizationName, thisOrgName, Qt::CaseInsensitive))
    {
        myOrganizationName = thisOrgName;
        emit sendUpdateSettings();
    }
} // end setOrgName
/************************************************
 * @brief get Org Domain.
 * getOrgDomain
 ***********************************************/
QString MyOrgSettings::getOrgDomain()
{
    if (myOrganizationDomain.isEmpty()) { setOrgDomain(qApp->organizationDomain()); }
    setMessage("get Org Domain", QString("getOrgDomain(%1)").arg(myOrganizationDomain), Debug);
    return myOrganizationDomain;
} // end getOrgDomain
/************************************************
 * @brief set Org Domain.
 * setOrgDomain
 ***********************************************/
void MyOrgSettings::setOrgDomain(const QString &thisOrgDomain)
{
    setMessage("set Org Domain", QString("setOrgDomain(%1)").arg(thisOrgDomain), Debug);
    if (QString::compare(myOrganizationDomain, thisOrgDomain, Qt::CaseInsensitive))
    {
        myOrganizationDomain = thisOrgDomain;
        emit sendUpdateSettings();
    }
} // end setOrgDomain
/************************************************
 * @brief get App Name.
 * getAppName
 ***********************************************/
QString MyOrgSettings::getAppName()
{
    if (myApplicationName.isEmpty()) { setAppName(qApp->applicationName()); }
    setMessage("get App Name", QString("getAppName(%1)").arg(myApplicationName), Debug);
    return myApplicationName;
} // end getAppName
/************************************************
 * @brief set App Name.
 * setAppName
 ***********************************************/
void MyOrgSettings::setAppName(const QString &thisAppName)
{
    setMessage("set App Name", QString("setAppName(%1)").arg(thisAppName), Debug);
    if (QString::compare(myApplicationName, thisAppName, Qt::CaseInsensitive))
    {
        myApplicationName = thisAppName;
        emit sendUpdateSettings();
    }
} // end setAppName
/************************************************
 * @brief get Version is set in header as a default.
 * getVersion
 ***********************************************/
QString MyOrgSettings::getVersion()
{
    setMessage("get Version", QString("getVersion(%1)").arg(myVersion), Debug);
    return myVersion;
}
/************************************************
 * @brief set Version.
 * setVersion
 * theLanguageModel->mySetting->setVersion(VERSION);
 ***********************************************/
void MyOrgSettings::setVersion(const QString &thisVersion)
{
    setMessage("set Version", QString("setVersion(%1)").arg(thisVersion), Debug);
    if (QString::compare(myVersion, thisVersion, Qt::CaseInsensitive))
    {
        myVersion = thisVersion;
        emit sendUpdateSettings();
    }
}
/************************************************
 * @brief get CheckInternetUrl.
 * getCheckInternetUrl
 ***********************************************/
QString MyOrgSettings::getCheckInternetUrl()
{
    setMessage("get CheckInternetUrl", QString("getCheckInternetUrl(%1)").arg(myCheckInternetUrl), Debug);
    if (myCheckInternetUrl.isEmpty())
    { setCheckInternetUrl(MY_INTERNET_URL); }
    return myCheckInternetUrl;
}
/************************************************
 * @brief set CheckInternetUrl.
 * setCheckInternetUrl
 * theLanguageModel->mySetting->setVersion(VERSION);
 ***********************************************/
void MyOrgSettings::setCheckInternetUrl(const QString &thisCheckInternetUrl)
{
    setMessage("set CheckInternetUrl", QString("setCheckInternetUrl(%1)").arg(thisCheckInternetUrl), Debug);
    if (QString::compare(myCheckInternetUrl, thisCheckInternetUrl, Qt::CaseInsensitive))
    {
        myCheckInternetUrl = thisCheckInternetUrl;
        emit sendUpdateSettings();
    }
}
/************************************************
 * @brief get Ini File Name.
 * getIniFileName
 ***********************************************/
QString MyOrgSettings::getIniFileName()
{
    if (myIniFileName.isEmpty())
    { setIniFileName(getAppName()); }
    setMessage("get Ini File", QString("getIniFile(%1)").arg(myIniFileName), Debug);
    return myIniFileName;
}
/************************************************
 * @brief set Ini File Name.
 * setIniFileName
 ***********************************************/
void MyOrgSettings::setIniFileName(const QString &thisIniFileName)
{
    setMessage("set Ini File", QString("setIniFile(%1)").arg(thisIniFileName), Debug);
    if (QString::compare(myIniFileName, thisIniFileName, Qt::CaseInsensitive))
    {
        myIniFileName = thisIniFileName;
        emit sendUpdateSettings();
    }
}
/************************************************
 * @brief get Ini File Extension.
 * getIniFileExtension
 ***********************************************/
QString MyOrgSettings::getIniFileExtension()
{
    setMessage("get Ini File", QString("getIniFile(%1)").arg(myIniFileName), Debug);
    if (myIniFileExtension.isEmpty())
    { setIniFileExtension(MY_INI_EXTENSION); }
    return myIniFileExtension;
}
/************************************************
 * @brief set Ini File Extension.
 * setIniFileExtension
 ***********************************************/
void MyOrgSettings::setIniFileExtension(const QString &thisIniFileNameExtension)
{
    setMessage("set Ini File", QString("setIniFile(%1)").arg(thisIniFileNameExtension), Debug);
    if (QString::compare(myIniFileExtension, thisIniFileNameExtension, Qt::CaseInsensitive))
    {
        myIniFileExtension = thisIniFileNameExtension;
        emit sendUpdateSettings();
    }
}
/************************************************
 * @brief set Ini Full Path.
 * getIniFullPath
 ***********************************************/
QString MyOrgSettings::getIniFullPath()
{
    setMessage("get Ini Full Path", "getIniFullPath", Debug);
    if (myIniFullPath.isEmpty())
    {
        // organizationName, organizationDomain, applicationName and applicationName
        // are set in main.cpp, and passed into Constuctor, so they are set
        QCoreApplication::setOrganizationName(getOrgName());
        QCoreApplication::setOrganizationDomain(getOrgDomain());
        QCoreApplication::setApplicationName(getAppName());
        //QCoreApplication::setApplicationDisplayName(getAppName());
        // see *.pro file where it is: DEFINES *= APP_VERSION=$${VERSION}
        // cmake does not have this yet, this is a hack till I FIXME
        QCoreApplication::setApplicationVersion(getVersion());
        setIniFullPath(QString("%1%2%3.%4").arg(getAppDataLocation(), QDir::separator(), getIniFileName(), getIniFileExtension()));
    }
    return myIniFullPath;
}
/************************************************
 * @brief set Ini Full Path.
 * setIniFullPath
 ***********************************************/
void MyOrgSettings::setIniFullPath(const QString &thisIniFileName)
{
    setMessage("set Ini Full Path", QString("%1(%2)").arg("setIniFullPath", thisIniFileName), Debug);
    if (QString::compare(myIniFullPath, thisIniFileName, Qt::CaseInsensitive))
    {
        myIniFullPath = thisIniFileName;
        emit sendUpdateSettings();
    }
}
/************************************************
 * @brief set Geometry.
 * setGeometry
 ***********************************************/
void MyOrgSettings::setGeometry(QByteArray thisGeometry)
{
    setMessage("set Geometry", "setGeometry", Debug);
    mySettings->beginGroup("Geometry");
    mySettings->setValue(MY_GEOMETRY, thisGeometry);
    mySettings->endGroup();
} // end setGeometry
/************************************************
 * @brief get Geometry.
 * getGeometry
 ***********************************************/
QByteArray MyOrgSettings::getGeometry()
{
    setMessage("get Geometry", "getGeometry", Debug);
    // Geometry
    mySettings->beginGroup("Geometry");
    myGeometry = mySettings->value(MY_GEOMETRY).toByteArray();
    mySettings->endGroup();
    return myGeometry;
} // end getGeometry
/************************************************
 * @brief set Window State.
 * setWindowState
 ***********************************************/
void MyOrgSettings::setWindowState(QByteArray thisWindowState)
{
    setMessage("set Window State", "setWindowState", Debug);
    mySettings->beginGroup("Geometry");
    mySettings->setValue(MY_WINDOW_STATES, thisWindowState);
    mySettings->endGroup();
}
/************************************************
 * @brief get Window State.
 * getWindowState
 ***********************************************/
QByteArray MyOrgSettings::getWindowState()
{
    setMessage("get Window State", "getWindowState", Debug);
    // Window State
    mySettings->beginGroup("Geometry");
    myWindowState = mySettings->value(MY_WINDOW_STATES).toByteArray();
    mySettings->endGroup();
    return myWindowState;
}
/************************************************
 * @brief read File.
 * readFile
 ***********************************************/
QString MyOrgSettings::readFile(const QString &thisFileName)
{
    setMessage("read File", QString("readFile(%1)").arg(thisFileName), Debug);
    QFile file(thisFileName);
    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        setMessage(QObject::tr("Error opening file for reading").toLocal8Bit(), QString("%1: %2").arg(QObject::tr("Could not open file for reading"), thisFileName).toLocal8Bit(), Critical);
        return "";
    }
    QTextStream in(&file);
    QString thisText = in.readAll();
    file.close();
    return thisText;
}
/************************************************
 * @brief write File.
 * @param thisFileName QString File Name
 * @param thisContent  QString Content
 * writeFile
 ***********************************************/
bool MyOrgSettings::writeFile(const QString &thisFileName, const QString &thisContent)
{
    setMessage("write File", QString("writeFile(%1)").arg(thisFileName), Debug);
    QFile theFile(thisFileName);
    // Trying to open in WriteOnly and Text mode and Truncate file if contents exists
    if(!theFile.open(QFile::WriteOnly | QFile::Text | QIODevice::Truncate))
    {
        setMessage(QObject::tr("Error opening file for writing").toLocal8Bit(), QString("%1: %2").arg(QObject::tr("Could not open file for writing"), thisFileName).toLocal8Bit(), Critical);
        return false;
    }
    // Write to file
    QTextStream theFileStream(&theFile);
    theFileStream << thisContent;
    theFile.flush();
    theFile.close();
    return true;
} // end writeFile
/************************************************
 * @brief Crypto using SimpleCrypt.
 * encryptThis
 ***********************************************/
QString MyOrgSettings::encryptThis(const QString &thisSecret)
{
    setMessage("encrypt This", "encryptThis", Debug);
    return myCrypto->encryptToString(thisSecret);
}
/************************************************
 * @brief Crypto using SimpleCrypt.
 * decryptThis
 ***********************************************/
QString MyOrgSettings::decryptThis(const QString &thisSecret)
{
    setMessage("decryp tThis", "decryptThis", Debug);
    return myCrypto->decryptToString(thisSecret);
}
/************************************************
 * @brief get File Info.
 * getFileInfo
 ***********************************************/
QString MyOrgSettings::getFileInfo(MyOrgSettings::MyFileinfo thisInfo, const QString &thisFileFolder)
{
    setMessage("get File Info", QString("getFileInfo(%1)").arg(thisFileFolder), Debug);
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
/************************************************
 * @brief is App Data Location Good.
 * isAppDataLocationGood
 ***********************************************/
bool MyOrgSettings::isAppDataLocationGood(const QString &thisFolder)
{
    setMessage("is App Data Location Good", QString("isAppDataLocationGood(%1)").arg(thisFolder), Debug);
    bool isGood = true;
    if (isFileMake(thisFolder, "ReadMe.txt"))
    {
        if (getFileInfo(IsWritable, combinePathFileName(thisFolder, "ReadMe.txt")) == "false")
        { isGood = false; }
    }
    else
    { isGood = false; }
    if (getFileInfo(IsFolder, thisFolder) == "false")
    { isGood = false; }
    return isGood;
} // end isAppDataLocationGood
/************************************************
 * @brief get App Data Location.
 * getAppDataLocation
 ***********************************************/
QString MyOrgSettings::getAppDataLocation()
{
    if (myAppDataLocation.isEmpty())
    {
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
            theAppDataLocation = QDir::currentPath(); // FIXME
        }
        setAppDataLocation(theAppDataLocation);
    }
    setMessage("get App Data Location", QString("getAppDataLocation(%1)").arg(myAppDataLocation), Debug);
    return myAppDataLocation;
} // end getAppDataLocation
/************************************************
 * @brief set App Data Location.
 * setAppDataLocation
 ***********************************************/
void MyOrgSettings::setAppDataLocation(const QString &thisAppDataLocation)
{
    if (QString::compare(myAppDataLocation, thisAppDataLocation, Qt::CaseInsensitive))
    {
        myAppDataLocation = thisAppDataLocation;
        emit sendUpdateSettings();
    }
} // end setAppDataLocation
/************************************************
 * @brief get Environment Var.
 * getEnvironmentVar
 * inline auto get_environement_variable(const char* key )
 * {
 *     char * val = getenv(key);
 *     return (val == NULL) ? "" : std::string(val);
 * }
 * auto programFiles = get_environement_variable("%ProgramW6432%");
 * auto programFilesX86 = get_environement_variable("%ProgramFiles(x86)%");
 * auto userProfile = get_environement_variable("%USERPROFILE%");
 * auto userProfile = get_environement_variable("%USERPROFILE%\Documents");
 ***********************************************/
QString MyOrgSettings::getEnvironmentVar(const QString &thisVar, const QString &thisDefault)
{
    setMessage("get Environment Var", QString("getEnvironmentVar(%1)").arg(thisVar), Debug);
    QString theEnvValue = qEnvironmentVariable(thisVar.toLocal8Bit());
    if (!theEnvValue.isNull())
    { return theEnvValue; }
    else
    { return thisDefault; }
}
/************************************************
 * @brief is Word only checks to see if any letters are in it.
 * isWord
 ***********************************************/
bool MyOrgSettings::isWord(const QString &thisString) const
{
    setMessage("is Word", QString("isWord(%1)").arg(thisString), Debug);
    for(int i = 0; i < thisString.length(); i++)
    {
        if (thisString.at(i).isLetter())
        { return true; }
    }
    return false;
}
/************************************************
 * @brief delay.
 * delay
 ***********************************************/
void MyOrgSettings::delay(int thisSeconds)
{
    setMessage("idelay", QString("delay(%1)").arg(thisSeconds), Debug);
    QEventLoop theDelayLoop;
    QTimer::singleShot(thisSeconds * 1000, &theDelayLoop, &QEventLoop::quit);
    theDelayLoop.exec();
} // end delay
/************************************************
 * @brief ping Internet.
 * pingInternet
 * set in cmake
 ***********************************************/
//#define MY_INTERNET_CHECK_PING
#ifdef MY_INTERNET_CHECK_PING
bool MyOrgSettings::pingInternet()
{
    setMessage("ping Internet", "pingInternet", Debug);
    QStringList parameters;
#if defined(WIN32)
    parameters << "-n" << "1";
#else
    parameters << "-c 1";
#endif
    parameters << getCheckInternetUrl();
    int exitCode = QProcess::execute("ping", parameters);
    if (exitCode==0)
    { return true; }
    else
    { return false; }
} // end delay
#else
/************************************************
 * @brief connect Internet.
 * connectInternet
 ***********************************************/
bool MyOrgSettings::connectInternet()
{
    setMessage("connect Internet", "connectInternet", Debug);
    bool isInternetAvailable = false;
    QNetworkAccessManager *theNetworkManager = new QNetworkAccessManager;
    QEventLoop theEventLoop;
    QObject::connect(theNetworkManager, &QNetworkAccessManager::finished, &theEventLoop, &QEventLoop::quit);
    QNetworkReply *reply = theNetworkManager->get(QNetworkRequest(QUrl(getCheckInternetUrl())));
    theEventLoop.exec();
    if (reply->bytesAvailable())
    { isInternetAvailable = true; }
    else
    { isInternetAvailable = false; }
    delete reply;
    delete theNetworkManager;
    return isInternetAvailable;
} // end delay
#endif
/************************************************
 * @brief get Internet Wait.
 * getInternetWait
 ***********************************************/
bool MyOrgSettings::getInternetWait()
{
    setMessage("get Internet Wait", "getInternetWait", Debug);
#ifdef MY_INTERNET_CHECK_PING
    if (pingInternet()) { return true; }
#else
    if (connectInternet()) { return true; }
#endif

    bool isNotConnected = true;
    while (isNotConnected)
    {
        delay(30);
#ifdef MY_INTERNET_CHECK_PING
        isNotConnected = pingInternet();
#else
        isNotConnected = connectInternet();
#endif
        emit sendInternetProgress();
    }
    return true;
} // end delay
/************************************************
 * @brief Number of Lines in a file.
 * fileNumberLines
 ***********************************************/
int MyOrgSettings::fileNumberLines(const QString &thisFile)
{
    setMessage("file Number Lines", QString("fileNumberLines(%1)").arg(thisFile), Debug);
    if (!isFileExists(thisFile)) { setMessage(QObject::tr("File not found").toLocal8Bit(), QString("%1: %2").arg(QObject::tr("File not found"), thisFile).toLocal8Bit(), Critical); return 0; }
    std::ifstream inFile(thisFile.toLocal8Bit());
    return std::count(std::istreambuf_iterator<char>(inFile), std::istreambuf_iterator<char>(), '\n');
} // end fileNumberLines
/************************************************
 * @brief removeAllFiles.
 * removeAllFiles
 ***********************************************/
bool MyOrgSettings::removeAllFiles(const QString &thisFolder)
{
    setMessage("remove All Files", QString("removeAllFiles(%1)").arg(thisFolder), Debug);
    if (!isPathExists(thisFolder)) { setMessage(QObject::tr("Folder not found").toLocal8Bit(), QString("%1: %2").arg(QObject::tr("Folder not found"), thisFolder).toLocal8Bit(), Critical); return false;  }
    QDir theDirFiles(thisFolder);
    theDirFiles.setNameFilters(QStringList() << "*.*");
    theDirFiles.setFilter(QDir::Files);
    foreach(QString theDirFile, theDirFiles.entryList())
    {
        if (!theDirFiles.remove(theDirFile))
        {
            setMessage(QObject::tr("Files could not be removed").toLocal8Bit(), QString("%1: %2").arg(QObject::tr("Files could not be removed"), thisFolder).toLocal8Bit(), Critical);
            return false;
        }
    }
    return true;
} // end removeAllFiles
/************************************************
 * @brief combine Path File Name.
 * combinePathFileName
 ***********************************************/
QString MyOrgSettings::combinePathFileName(const QString &thisPath,const  QString &thisFileName)
{
    setMessage("combine Path File Name", QString("combinePathFileName(%1, %2)").arg(thisPath, thisFileName), Debug);
    return QString("%1%2%3").arg(thisPath, QDir::separator(), thisFileName);
} // end combinePathFileName
/************************************************
 * @brief is Path Exists.
 * isPathExists
 ***********************************************/
bool MyOrgSettings::isPathExists(const QString &thisPath)
{
    setMessage("is Path Exists", QString("isPathExists(%1)").arg(thisPath), Debug);
    return QDir(thisPath).exists() && QFileInfo(thisPath).isDir();
} // end isPathExists
/************************************************
 * @brief is File Exists.
 * isFileExists
 ***********************************************/
bool MyOrgSettings::isFileExists(const QString &thisFile)
{
    setMessage("is File Exists", QString("isFileExists(%1)").arg(thisFile), Debug);
    // check if file exists and if yes: Is it really a file and not directory?
    return QFileInfo::exists(thisFile) && QFileInfo(thisFile).isFile();
} // end isFileExists
/************************************************
 * @brief remove File.
 * removeFile
 ***********************************************/
bool MyOrgSettings::removeFile(const QString &thisFile)
{
    setMessage("remove File", QString("removeFile(%1)").arg(thisFile), Debug);
    if (isFileExists(thisFile))
    { return QFile::remove(thisFile); }
    return true;
}
/************************************************
 * @brief is File Make.
 * isFileMake
 ***********************************************/
bool MyOrgSettings::isFileMake(const QString &thisPath, const QString &thisFileName)
{
    setMessage("is File Make", QString("isFileMake(%1, %2)").arg(thisPath, thisFileName), Debug);
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
            outStream << QString("%1 %2").arg(QObject::tr("This file was created to test if this folder is writeable by"), QCoreApplication::applicationName()).toLocal8Bit();
            /* Close the file */
            theFile.close();
            if (isFileExists(thePath)) { isCreated = true; }
            return isCreated;
        }
        else return false;
    }
    return true;
} // end isFileMake
/************************************************
 * @brief is Make Dir.
 * isMakeDir
 ***********************************************/
bool MyOrgSettings::isMakeDir(const QString &thisPath)
{
    setMessage("is Make Dir", QString("isMakeDir(%1)").arg(thisPath), Debug);
    QDir dir(thisPath);
    if (!dir.exists())
    {
        if (!dir.mkpath("."))
        { setMessage(QObject::tr("File System Error").toLocal8Bit(), QString("%1 %2").arg(tr("Error: cannot create file"), thisPath).toLocal8Bit(), Critical); }
        else return true;
    }
    return isPathExists(thisPath);
} // end isMakeDir
/************************************************
 * @brief set Debug Message.
 * setDebugMessage
 ***********************************************/
void MyOrgSettings::setDebugMessage(bool thisState)
{
    isDebugMessage = thisState;
    setMessage("set Debug Message", QString("setDebugMessage(%1)").arg(thisState), Debug);
}
/************************************************
 * @brief get Debug Message.
 * getDebugMessage
 ***********************************************/
bool MyOrgSettings::getDebugMessage()
{
    setMessage("get Debug Message", QString("getDebugMessage(%1)").arg(isDebugMessage), Debug);
    return isDebugMessage;
}
/************************************************
 * @brief Titel and Question Yes No.
 * questionYesNo
 ***********************************************/
bool MyOrgSettings::questionYesNo(const char *thisTitle, const char *thisQuestion) const
{
    if (setMessage(thisTitle, thisQuestion, MyMessageTypes::Question) == "true")
    { return true; }
    else
    { return false; }
} // end questionYesNo
/************************************************
 * @brief information, question: 1 = true, 0 = false, warning, critical: theMessage.toLocal8Bit().
 * @param thisTitle       QString Title
 * @param thisMessage     QString Message
 * @param thisMessageType QString Message Type
 * showMessageBox
 ***********************************************/
QVariant MyOrgSettings::showMessageBox(const QString &thisTitle, const QString &thisMessage, MyMessageTypes thisMessageType) const
{
    return setMessage(thisTitle, thisMessage, thisMessageType);
} // end showMessageBox
/************************************************
 * @brief set Message.
 * setMessage
 ***********************************************/
QVariant MyOrgSettings::setMessage(const QString &thisTitle, const QString &thisMessage, MyMessageTypes thisMessageType) const
{
    switch (thisMessageType)
    {
    case Debug:
    {
#ifdef MY_QML
#ifdef DEBUG
        // FIXME
        if (isDebugMessage)
        {
#ifdef QT_DEBUG
            qDebug() << thisMessage;
#else
            std::cout << thisMessage.toStdString() << std::endl;
#endif
        }
#else
        if (isDebugMessage)
        { std::cout << thisMessage.toStdString() << std::endl; }
#endif
        return "";
#else
        if (isDebugMessage)
        {
#ifdef QT_DEBUG
            qDebug() << thisMessage;
#else
            std::cout << thisMessage.toStdString() << std::endl;
#endif
        }
        return "";
#endif
    }
    case Information:
    {
#ifdef MY_QML
#ifdef QT_DEBUG
        // FIXME
        qInfo() << thisMessage;
#else
        std::cout << thisMessage.toStdString() << std::endl;
#endif
        return "";
#else
        return QMessageBox::information(nullptr, thisTitle, thisMessage, QMessageBox::Ok);
#endif
    }
    case Question:
    {
#ifdef MY_QML
        // FIXME
#ifdef QT_DEBUG
        qDebug() << thisMessage;
#else
        std::cout << thisMessage.toStdString() << std::endl;
#endif
        return "";
#else
        QMessageBox theMsgBox;
        theMsgBox.setWindowTitle(QObject::tr(thisTitle.toLocal8Bit()));
        theMsgBox.setText(QObject::tr(thisMessage.toLocal8Bit()));
        theMsgBox.setStandardButtons(QMessageBox::Yes);
        theMsgBox.addButton(QMessageBox::No);
        theMsgBox.setDefaultButton(QMessageBox::No);
        if(theMsgBox.exec() == QMessageBox::Yes)
        {
            setMessage("", QObject::tr("Yes was clicked"), Debug);
            return true;
        }
        else
        {
            setMessage("", QObject::tr("Yes was not clicked"), Debug);
            return false;
        }

#endif
    }
    case Warning:
    {
#ifdef MY_QML
#ifdef QT_DEBUG
        // FIXME
        qWarning() << thisMessage;
#else
        std::cout << thisMessage.toStdString() << std::endl;
#endif
        return "";
#else
        return QMessageBox::warning(nullptr, thisTitle, thisMessage, QMessageBox::Ok);
#endif
    }
    case Critical:
    {
#ifdef MY_QML
#ifdef QT_DEBUG
        // FIXME
        qCritical() << thisMessage;
#else
        std::cout << thisMessage.toStdString() << std::endl;
#endif
        return "";
#else
        return QMessageBox::critical(nullptr, thisTitle, thisMessage, QMessageBox::Ok);
#endif
    }
    } // end switch (thisMessageType)
    return QVariant();
} // end setMessage
/*** ************************* End of File ***********************************/
