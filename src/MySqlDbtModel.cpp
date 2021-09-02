#include "MySqlDbtModel.h"

/************************************************
 * @brief Constructor.
 * MySqlDbtModel
 ***********************************************/
MySqlDbtModel::MySqlDbtModel(QObject *parent, MyOrgSettings *thisSetting) : QObject(parent), mySetting(thisSetting)
{
}
/************************************************
 * @brief Deconstructor.
 * ~MySqlDbtModel
 ***********************************************/
MySqlDbtModel::~MySqlDbtModel()
{
    #ifdef USE_SQL_FLAG
    if (myDb.isOpen()) { myDb.close(); }
    #endif
}
/************************************************
 * @brief is Db Table.
 * isDbTable
 ***********************************************/
bool MySqlDbtModel::isDbTable(const QString &thisTable)
{
    setMessage("isDatabase");
    #ifdef USE_SQL_FLAG
    QStringList theTables = myDb.tables();
    if (theTables.contains(thisTable, Qt::CaseInsensitive))  { return true; }
    else                                                     { return false; }
    #else
    return true;
    #endif
}
#ifdef USE_SQL_FLAG
/************************************************
 * @brief set Sql Database.
 * setSqlDatabase
 ***********************************************/
void MySqlDbtModel::setSqlDatabase(QSqlDatabase thisDatabase)
{
    setMessage("setSqlDatabase");
    myDb = thisDatabase;
}
/************************************************
 * @brief get Sql Database.
 * getSqlDatabase
 ***********************************************/
QSqlDatabase MySqlDbtModel::getSqlDatabase()
{
    setMessage("getSqlDatabase");
    return myDb;
}
#endif
/************************************************
 * @brief get Sql Driver.
 * getSqlDriver
 ***********************************************/
QString MySqlDbtModel::getSqlDriver()
{
    setMessage("getSqlDriver");
    return mySqlDriver;
}
/************************************************
 * @brief set Sql Table Name.
 * setSqlTableName
 ***********************************************/
void MySqlDbtModel::setSqlTableName(const QString &thisTableName)
{
    setMessage("setSqlTableName");
    myTableName = thisTableName;
}
/************************************************
 * @brief get Sql Table Name.
 * getSqlTableName
 ***********************************************/
QString MySqlDbtModel::getSqlTableName()
{
    setMessage("getSqlTableName");
    return myTableName;
}
/************************************************
 * @brief set Sql Host Name.
 * setSqlHostName
 ***********************************************/
void MySqlDbtModel::setSqlHostName(const QString &thisHostName)
{
    setMessage("setSqlHostName");
    myHostName = thisHostName;
}
/************************************************
 * @brief get Sql Host Name.
 * getSqlHostName
 ***********************************************/
QString MySqlDbtModel::getSqlHostName()
{
    setMessage("getSqlHostName");
    return myHostName;
}
/************************************************
 * @brief set Sql User Name.
 * setSqlUserName
 ***********************************************/
void MySqlDbtModel::setSqlUserName(const QString &thisUserName)
{
    setMessage("setSqlUserName");
    myUserName = thisUserName;
}
/************************************************
 * @brief get Sql User Name.
 * getSqlUserName
 ***********************************************/
QString MySqlDbtModel::getSqlUserName()
{
    setMessage("getSqlUserName");
    return myUserName;
}
/************************************************
 * @brief set Sql Database Name.
 * setSqlDatabaseName
 ***********************************************/
void MySqlDbtModel::setSqlDatabaseName(const QString &thisPassword)
{
    setMessage("setSqlDatabaseName");
    myDatabaseName = thisPassword;
}
/************************************************
 * @brief get Sql Database Name.
 * getSqlDatabaseName
 ***********************************************/
QString MySqlDbtModel::getSqlDatabaseName()
{
    setMessage("getSqlDatabaseName");
    return myDatabaseName;
}
/************************************************
 * @brief set Sql Password.
 * setSqlPassword
 ***********************************************/
void MySqlDbtModel::setSqlPassword(const QString &thisPassword)
{
    setMessage("setSqlPassword");
    myPassword = thisPassword;
}
/************************************************
 * @brief get Sql Password.
 * getSqlPassword
 ***********************************************/
QString MySqlDbtModel::getSqlPassword()
{
    setMessage("getSqlPassword");
    return myPassword;
}
/************************************************
 * @brief set Connection Name.
 * setConnectionName
 ***********************************************/
void MySqlDbtModel::setConnectionName(const QString &thisConnectionName)
{
    setMessage("setConnectionName");
    myConnectionName = thisConnectionName;
}
/************************************************
 * @brief get Record ID.
 * getRecordID
 ***********************************************/
QString MySqlDbtModel::getRecordID()
{
    return myInsertID;
}
/************************************************
 * @brief set Record ID.
 * setRecordID
 ***********************************************/
void MySqlDbtModel::setRecordID(const QString &thisRecordID)
{
    myInsertID = thisRecordID;
}
/************************************************
 * @brief get Connection Name.
 * getConnectionName
 ***********************************************/
QString MySqlDbtModel::getConnectionName()
{
    setMessage("getConnectionName");
    return myConnectionName;
}
/************************************************
 * @brief set Sql Driver setSqlDriver(":memory:");.
 * setSqlDriver
 ***********************************************/
void MySqlDbtModel::setSqlDriver(const QString &thisDriver)
{
    setMessage("setSqlDriver");
#ifdef USE_SQL_FLAG
    QString theDriver = thisDriver;
    if (theDriver.length() == 0)  { theDriver = mySetting->myConstants->MY_SQL_DEFAULT; }
    // Check for Database memory setting
    // ui->checkBoxSettingsMemory->isChecked() || combobox
    // Database Driver
    if (theDriver == ":memory:")
    {
        // SQLite version 3 SQLite version 2 Note: obsolete since Qt 5.14
        mySqlDriver = theDriver;
    }
    else if (theDriver == "QSQLITE" || theDriver == "QSQLITE2")
    {
        // SQLite version 3 SQLite version 2 Note: obsolete since Qt 5.14
        mySqlDriver = theDriver;
    }
    else if (theDriver == "QMYSQL" || theDriver == "MARIADB")
    {
        // MySQL or MariaDB (version 5.0 and above)
        mySqlDriver = theDriver;
    }
    else if (theDriver == "QPSQL")
    {
        // PostgreSQL (versions 7.3 and above)
        mySqlDriver = theDriver;
    }
    else if (theDriver == "QDB2")
    {
        // IBM DB2 (version 7.1 and above)
        mySqlDriver = theDriver;
    }
    else if (theDriver == "QIBASE")
    {
        // Borland InterBase
        mySqlDriver = theDriver;
    }
    else if (theDriver == "QOCI")
    {
        // Oracle Call Interface Driver
        mySqlDriver = theDriver;
    }
    else if (theDriver == "QTDS")
    {
        // Sybase Adaptive Server - Note: obsolete since Qt 4.7
        mySqlDriver = theDriver;
    }
    else
    {
        mySqlDriver = theDriver;
    }
#endif
} // end setSqlDriver
/************************************************
 * @brief create DataBase Connection.
 * createDataBaseConnection
 ***********************************************/
bool MySqlDbtModel::createDataBaseConnection()
{
    setMessage("createDataBaseConnection");
#ifdef USE_SQL_FLAG
    // Make sure Drive is set
    if (mySqlDriver == "NOTSET") { setSqlDriver(mySetting->myConstants->MY_SQL_DEFAULT); }
    QString theDb = getSqlDatabaseName();
    // Database Driver
    if (mySqlDriver == ":memory:")
    {
        myDb = QSqlDatabase::addDatabase("QSQLITE"); //!< set myDb SQLite
        myDb.setDatabaseName(":memory:");
    }
    else
    {
        if (mySqlDriver == "QSQLITE" || mySqlDriver == "QSQLITE2")
        {   //!< set myDb QSQLITE or QSQLITE2
            // SQLite version 3 and SQLite version 2 Note: obsolete since Qt 5.14
            if (theDb.contains(".db"))
            {
                if (!mySetting->isFileExists(theDb))
                {
                    qCritical() << "createDataBaseConnection new DB: " << theDb;
                }
            }
            else
            {
                theDb = QString("%1%2%3.db").arg(mySetting->getAppDataLocation(), QDir::separator(), getSqlDatabaseName());
            }
            //
            myDb = QSqlDatabase::addDatabase(mySqlDriver); //!< set myDb SQLite
            myDb.setDatabaseName(theDb);
            //    myDb.setHostName(getSqlHostName());
            //    myDb.setUserName(getSqlUserName());
            //    myDb.setPassword(getSqlPassword());
            //
        }
        else if (mySqlDriver == "QDB2")
        {   //!< set myDb QDB2
            // IBM DB2 (version 7.1 and above)
            myDb = QSqlDatabase::addDatabase(mySqlDriver, myConnectionName);
            myDb.setHostName(getSqlHostName());
            myDb.setDatabaseName(getSqlDatabaseName());
            myDb.setUserName(getSqlUserName());
            myDb.setPassword(getSqlPassword());
        }
        else if (mySqlDriver == "QIBASE")
        {   //!< set myDb QIBASE
            // Borland InterBase
            myDb = QSqlDatabase::addDatabase(mySqlDriver, myConnectionName);
            myDb.setHostName(getSqlHostName());
            myDb.setDatabaseName(getSqlDatabaseName());
            myDb.setUserName(getSqlUserName());
            myDb.setPassword(getSqlPassword());
        }
        else if (mySqlDriver == "QMYSQL" || mySqlDriver == "MARIADB")
        {   //!< set myDb QMYSQL or MARIADB
            // MySQL or MariaDB (version 5.0 and above)
            myDb = QSqlDatabase::addDatabase(mySqlDriver, myConnectionName);
            myDb.setHostName(getSqlHostName());
            myDb.setDatabaseName(getSqlDatabaseName());
            myDb.setUserName(getSqlUserName());
            myDb.setPassword(getSqlPassword());
        }
        else if (mySqlDriver == "QOCI")
        {   //!< set myDb QOCI
            // Oracle Call Interface Driver
            myDb = QSqlDatabase::addDatabase(mySqlDriver, myConnectionName);
            myDb.setHostName(getSqlHostName());
            myDb.setDatabaseName(getSqlDatabaseName());
            myDb.setUserName(getSqlUserName());
            myDb.setPassword(getSqlPassword());
        }
        else if (mySqlDriver == "QPSQL")
        {   //!< set myDb QPSQL
            // PostgreSQL (versions 7.3 and above)
            myDb = QSqlDatabase::addDatabase(mySqlDriver, myConnectionName);
            myDb.setHostName(getSqlHostName());
            myDb.setDatabaseName(getSqlDatabaseName());
            myDb.setUserName(getSqlUserName());
            myDb.setPassword(getSqlPassword());
        }
        else if (mySqlDriver == "QTDS")
        {   //!< set myDb QTDS
            // Sybase Adaptive Server - Note: obsolete since Qt 4.7
            myDb = QSqlDatabase::addDatabase(mySqlDriver, myConnectionName);
            myDb.setHostName(getSqlHostName());
            myDb.setDatabaseName(getSqlDatabaseName());
            myDb.setUserName(getSqlUserName());
            myDb.setPassword(getSqlPassword());
        }
    } // end ! if (:memory:)
    if (!myDb.open())
    {
        if(!QSqlDatabase::isDriverAvailable(mySqlDriver))
        {
            mySetting->showMessageBox(tr("Database SQL Driver is missing").toLocal8Bit(), tr("Install SQL").toLocal8Bit(), mySetting->Critical);
            return false;
        }
        else
        {
            mySetting->showMessageBox(QString("%1: %2").arg(tr("Cannot open database"), myDb.lastError().text()).toLocal8Bit(), tr("Unable to establish a database connection").toLocal8Bit(), mySetting->Critical);
            return false;
        }
    }
    // Set Settings
    mySetting->writeSettings(mySetting->myConstants->MY_SQL_DB_NAME, theDb);
    mySetting->writeSettings(mySetting->myConstants->MY_SQL_DB_TYPE, "QSQLITE");
#endif
    return true;
} // end createDataBaseConnection
/************************************************
 * @brief Set myInsertID, returns true or false.
 * runQuery
 ***********************************************/
bool MySqlDbtModel::runQuery(const QString &thisQuery)
{
    setMessage("runQuery=" + thisQuery);
    #ifdef USE_SQL_FLAG
    QSqlQuery theQuery; //!< SQL Query
    if (theQuery.exec(thisQuery))
    {
        setRecordID(theQuery.lastInsertId().toString());
        return true;
    }
    else
    {
        qCritical() << "Error running Query: " << thisQuery << theQuery.lastError().text() << ", SqLite error code:" << theQuery.lastError();
        setRecordID("-1");
        return false;
    }
    #else
    return true;
    #endif
}
/************************************************
 * moveDb
 * @brief move Db.
 ***********************************************/
bool MySqlDbtModel::moveDb(const QString &thisSourceFile,const QString &thisSourcePath, const QString &thisDestinationFolder)
{
    setMessage("moveDb");
#ifdef USE_SQL_FLAG
    QFile file(QString("%1%2%3").arg(thisSourcePath, QDir::separator(), thisSourceFile));
    //
    QString theNewDatabaseName = QString("%1%2%3").arg(thisDestinationFolder, QDir::separator(), thisSourceFile);
    //
    if (mySetting->isFileExists(theNewDatabaseName))
    {
        if (!mySetting->questionYesNo("Overwrite Database", "Are you sure you want to overwrite existing Database?"))
        {
            return true;
        }
    }
    //
    if (myDb.isOpen()) { myDb.close(); }
    if (file.rename(theNewDatabaseName))
    {
        myDatabaseName = theNewDatabaseName;
        return createDataBaseConnection();
    }
    else { return true; }
#else
    return true;
#endif
}
/************************************************
 * @brief run Procces given exe path, argument, and if you want to wait and how long,
 *        in both cases this is a blocking call and will wait till finished and return value.
 * runProcces
 ***********************************************/
QString MySqlDbtModel::runProcces(const QString &thisExePath, const QString &thisArgument, bool isWait, int thisWaitTimeSec)
{
    QProcess *thisProcess = new QProcess(this);
    if (isWait)
    {
        thisProcess->start(thisExePath, QStringList() << thisArgument);
        // default wait time 30 sec
        if(!thisProcess->waitForStarted()) { qWarning() << tr("runProcces cannot start process"); }
        // wait time
        int waitTime = thisWaitTimeSec * 1000; // 60000 = 60 sec divide by 1000
        // now wait
        if (!thisProcess->waitForFinished(waitTime)) { qWarning() << tr("runProcces timeout .."); }
    }
    else
    {
        thisProcess->start(thisExePath, QStringList() << thisArgument);
        thisProcess->waitForFinished();
    }
    //
    thisProcess->setProcessChannelMode(QProcess::MergedChannels);
    myRunReturnCode = thisProcess->exitCode();
    return QString(thisProcess->readAllStandardOutput().simplified());
}
/************************************************
 * @brief get Run eturn Code.
 * getRunReturnCode
 ***********************************************/
int MySqlDbtModel::getRunReturnCode()
{
    return myRunReturnCode;
}
/************************************************
 * @brief set Debug Message.
 * setDebugMessage
 ***********************************************/
void MySqlDbtModel::setDebugMessage(bool thisState)
{
    isDebugMessage = thisState;
}
/************************************************
 * @brief get Debug Message.
 * getDebugMessage
 ***********************************************/
bool MySqlDbtModel::getDebugMessage()
{
    return isDebugMessage;
}
/************************************************
 * @brief set Message.
 * setMessage
 ***********************************************/
void MySqlDbtModel::setMessage(const QString &thisMessage)
{
    if (isDebugMessage)
    {
        qDebug() << thisMessage;
        //std::cout << thisMessage.toStdString() << std::endl;
    }
}
/*** ************************* End of File ***********************************/
