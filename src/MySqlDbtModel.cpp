#include "MySqlDbtModel.h"

/************************************************
 * MySqlDbtModel
 * @brief Constructor.
 ***********************************************/
MySqlDbtModel::MySqlDbtModel(QObject *parent)
{
    // MySettings Settings
    mySetting = new MyOrgSettings(parent);
}
/************************************************
 * ~MySqlDbtModel
 * @brief Deconstructor.
 ***********************************************/
MySqlDbtModel::~MySqlDbtModel()
{
    if (myDb.isOpen()) { myDb.close(); }
}
/************************************************
 * setDebugMessage
 * @brief set Debug Message.
 ***********************************************/
void MySqlDbtModel::setDebugMessage(bool thisState)
{
    isDebugMessage = thisState;
}
/************************************************
 * getDebugMessage
 * @brief get Debug Message.
 ***********************************************/
bool MySqlDbtModel::getDebugMessage()
{
    return isDebugMessage;
}
/************************************************
 * isDbTable
 * @brief is Db Table.
 ***********************************************/
bool MySqlDbtModel::isDbTable(const QString &thisTable)
{
    if (isDebugMessage) { qDebug() << "isDatabase"; }
    QStringList theTables = myDb.tables();
    if (theTables.contains(thisTable, Qt::CaseInsensitive))  { return true; }
    else                                                     { return false; }
}
/************************************************
 * setSqlDatabase
 * @brief set Sql Database.
 ***********************************************/
void MySqlDbtModel::setSqlDatabase(QSqlDatabase thisDatabase)
{
    if (isDebugMessage) { qDebug() << "setSqlDatabase"; }
    myDb = thisDatabase;
}
/************************************************
 * getSqlDatabase
 * @brief get Sql Database.
 ***********************************************/
QSqlDatabase MySqlDbtModel::getSqlDatabase()
{
    if (isDebugMessage) { qDebug() << "getSqlDatabase"; }
    return myDb;
}
/************************************************
 * getSqlDriver
 * @brief get Sql Driver.
 ***********************************************/
QString MySqlDbtModel::getSqlDriver()
{
    if (isDebugMessage) { qDebug() << "getSqlDriver"; }
    return mySqlDriver;
}
/************************************************
 * setSqlTableName
 * @brief set Sql Table Name.
 ***********************************************/
void MySqlDbtModel::setSqlTableName(const QString &thisTableName)
{
    if (isDebugMessage) { qDebug() << "setSqlTableName"; }
    myTableName = thisTableName;
}
/************************************************
 * getSqlTableName
 * @brief get Sql Table Name.
 ***********************************************/
QString MySqlDbtModel::getSqlTableName()
{
    if (isDebugMessage) { qDebug() << "getSqlTableName"; }
    return myTableName;
}
/************************************************
 * setSqlHostName
 * @brief set Sql Host Name.
 ***********************************************/
void MySqlDbtModel::setSqlHostName(const QString &thisHostName)
{
    if (isDebugMessage) { qDebug() << "setSqlHostName"; }
    myHostName = thisHostName;
}
/************************************************
 * getSqlHostName
 * @brief get Sql Host Name.
 ***********************************************/
QString MySqlDbtModel::getSqlHostName()
{
    if (isDebugMessage) { qDebug() << "getSqlHostName"; }
    return myHostName;
}
/************************************************
 * setSqlUserName
 * @brief set Sql User Name.
 ***********************************************/
void MySqlDbtModel::setSqlUserName(const QString &thisUserName)
{
    if (isDebugMessage) { qDebug() << "setSqlUserName"; }
    myUserName = thisUserName;
}
/************************************************
 * getSqlUserName
 * @brief get Sql User Name.
 ***********************************************/
QString MySqlDbtModel::getSqlUserName()
{
    if (isDebugMessage) { qDebug() << "getSqlUserName"; }
    return myUserName;
}
/************************************************
 * setSqlDatabaseName
 * @brief set Sql Database Name.
 ***********************************************/
void MySqlDbtModel::setSqlDatabaseName(const QString &thisPassword)
{
    if (isDebugMessage) { qDebug() << "setSqlDatabaseName"; }
    myDatabaseName = thisPassword;
}
/************************************************
 * getSqlDatabaseName
 * @brief get Sql Database Name.
 ***********************************************/
QString MySqlDbtModel::getSqlDatabaseName()
{
    if (isDebugMessage) { qDebug() << "getSqlDatabaseName"; }
    return myDatabaseName;
}
/************************************************
 * setSqlPassword
 * @brief set Sql Password.
 ***********************************************/
void MySqlDbtModel::setSqlPassword(const QString &thisPassword)
{
    if (isDebugMessage) { qDebug() << "setSqlPassword"; }
    myPassword = thisPassword;
}
/************************************************
 * getSqlPassword
 * @brief get Sql Password.
 ***********************************************/
QString MySqlDbtModel::getSqlPassword()
{
    if (isDebugMessage) { qDebug() << "getSqlPassword"; }
    return myPassword;
}
/************************************************
 * setConnectionName
 * @brief set Connection Name.
 ***********************************************/
void MySqlDbtModel::setConnectionName(const QString &thisConnectionName)
{
    if (isDebugMessage) { qDebug() << "setConnectionName"; }
    myConnectionName = thisConnectionName;
}
/************************************************
 * getRecordID
 * @brief get Record ID.
 ***********************************************/
QString MySqlDbtModel::getRecordID()
{
    return myInsertID;
}
/************************************************
 * setRecordID
 * @brief set Record ID.
 ***********************************************/
void MySqlDbtModel::setRecordID(const QString &thisRecordID)
{
    myInsertID = thisRecordID;
}
/************************************************
 * getConnectionName
 * @brief get Connection Name.
 ***********************************************/
QString MySqlDbtModel::getConnectionName()
{
    if (isDebugMessage) { qDebug() << "getConnectionName"; }
    return myConnectionName;
}
/************************************************
 * setSqlDriver
 * @brief set Sql Driver setSqlDriver(":memory:");.
 ***********************************************/
void MySqlDbtModel::setSqlDriver(const QString &thisDriver)
{
    if (isDebugMessage) { qDebug() << "setSqlDriver"; }
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
}
/************************************************
 * createDataBaseConnection
 * @brief create DataBase Connection.
 ***********************************************/
bool MySqlDbtModel::createDataBaseConnection()
{
    if (isDebugMessage) { qDebug() << "createDataBaseConnection"; }
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
    return true;
} // end createDataBaseConnection
/************************************************
 * runQuery
 * @brief Set myInsertID, returns true or false.
 ***********************************************/
bool MySqlDbtModel::runQuery(const QString &thisQuery)
{
    if (isDebugMessage) { qDebug() << "runQuery=" << thisQuery; }
    QSqlQuery theQuery; //!< SQL Query
    if (theQuery.exec(thisQuery))
    {
        myInsertID = theQuery.lastInsertId().toString();
        return true;
    }
    else
    {
        qCritical() << "Error running Query: " << thisQuery << theQuery.lastError().text() << ", SqLite error code:" << theQuery.lastError();
        myInsertID = "-1";
        return false;
    }
}
/************************************************
 * moveDb
 * @brief move Db.
 ***********************************************/
bool MySqlDbtModel::moveDb(const QString &thisSourceFile,const QString &thisSourcePath, const QString &thisDestinationFolder)
{
    if (isDebugMessage) { qDebug() << "moveDb"; }

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
}
/************************************************
 * runProcces
 * @brief run Procces given exe path, argument, and if you want to wait and how long,
 *        in both cases this is a blocking call and will wait till finished and return value.
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
 * getRunReturnCode
 * @brief get Run eturn Code.
 ***********************************************/
int MySqlDbtModel::getRunReturnCode()
{
    return myRunReturnCode;
}
/*** ************************* End of File ***********************************/
