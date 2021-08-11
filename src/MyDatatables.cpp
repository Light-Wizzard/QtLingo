#include "MyDatatables.h"

/*! ***************************************************************************
   \class MyDatatables
   \brief My Datatables Constructor
 *************************************************************************** */
MyDatatables::MyDatatables(QObject *parent) : QObject(parent)
{
    mySqlModel = new MySqlDbtModel();
    // Create Variable Trackers and Set to Empty
    myProject = new MyProjectClass("", "", "", "", "", "", "", "");
}
/*! ***************************************************************************
   \class MyDatatables
   \brief My Datatables Deconstructor
 *************************************************************************** */
MyDatatables::~MyDatatables()
{

}
/*! ***************************************************************************
   \fn setDebugMessage
   \brief set Debug Message
 *************************************************************************** */
void MyDatatables::setDebugMessage(bool thisState)
{
    isDebugMessage = thisState;
    if (isDebugMessage) { qDebug() << "setDebugMessage"; }
}
/*! ***************************************************************************
   \fn getDebugMessage
   \brief get Debug Message
 *************************************************************************** */
bool MyDatatables::getDebugMessage()
{
    if (isDebugMessage) { qDebug() << "getDebugMessage"; }
    return isDebugMessage;
}
/*! ***************************************************************************
   \fn setProjectFolder
   \brief set Project Folder
 *************************************************************************** */
void MyDatatables::setProjectFolder(const QString &thisProjectFolder)
{
    if (isDebugMessage) { qDebug() << "setProjectFolder"; }
    myProjectFolder = thisProjectFolder;
}
/*! ***************************************************************************
   \fn getProjectFolder
   \brief get Project Folder
 *************************************************************************** */
QString MyDatatables::getProjectFolder()
{
    if (isDebugMessage) { qDebug() << "getProjectFolder"; }
    return myProjectFolder;
}
/*! ***************************************************************************
   \fn setProjectName
   \brief set Project Name
 *************************************************************************** */
void MyDatatables::setProjectName(const QString &thisProjectName)
{
    if (isDebugMessage) { qDebug() << "setProjectName"; }
    myProjectName = thisProjectName;
}
/*! ***************************************************************************
   \fn getProjectName
   \brief get Project Name
 *************************************************************************** */
QString MyDatatables::getProjectName()
{
    if (isDebugMessage) { qDebug() << "getProjectName"; }
    return myProjectName;
}
/*! ***************************************************************************
   \fn setProjectID
   \brief set Project ID
 *************************************************************************** */
void MyDatatables::setProjectID(const QString &thisProjectID)
{
    if (isDebugMessage) { qDebug() << "setProjectID"; }
    myProjectID = thisProjectID;
}
/*! ***************************************************************************
   \fn getProjectID
   \brief get Project ID
 *************************************************************************** */
QString MyDatatables::getProjectID()
{
    if (isDebugMessage) { qDebug() << "getProjectID"; }
    return myProjectID;
}
/*! ***************************************************************************
   \fn setComboBoxSqlValue
   \brief set ComboBox Sql Value
 *************************************************************************** */
void MyDatatables::setComboBoxSqlValue(const QString &thisComboBoxSqlValue)
{
    if (isDebugMessage) { qDebug() << "setComboBoxSqlValue"; }
    myComboBoxSqlValue = thisComboBoxSqlValue;
}
/*! ***************************************************************************
   \fn getComboBoxSqlValue
   \brief get ComboBox Sql Value
 *************************************************************************** */
QString MyDatatables::getComboBoxSqlValue()
{
    if (isDebugMessage) { qDebug() << "getComboBoxSqlValue"; }
    return myComboBoxSqlValue;
}
/*! ***************************************************************************
   \fn checkDatabase
   \brief check Database
 *************************************************************************** */
bool MyDatatables::checkDatabase()
{
    if (isDebugMessage) { qDebug() << "checkDatabase"; }
    // Database
    mySqlModel->setSqlDriver(myComboBoxSqlValue);
    if (! mySqlModel->createDataBaseConnection()) { return false; }
    //
    // Configuration
    //
    if (!mySqlModel->isDbTable("Projects"))
    {
        /*
         * Table Projects holds the name of the Qt Project
         * id integer PRIMARY KEY autoincrement,
         * id, QtProjectName, QtProjectFolder, SourceFolder, DestinationFolder, SourceLanguage, LanguageIDs, Make
        */
        if (mySqlModel->runQuery(QLatin1String(R"(CREATE TABLE Projects(id integer PRIMARY KEY autoincrement, QtProjectName, QtProjectFolder, SourceFolder, DestinationFolder, SourceLanguage, LanguageIDs, Make))")))
        {
            QString theQtProjectName    = mySqlModel->mySetting->myConstants->MY_QT_PROJECT_NAME;
            QString theQtProjectFolder  = mySqlModel->mySetting->myConstants->MY_QT_PROJECT_FOLDER;
            QString theSource           = mySqlModel->mySetting->myConstants->MY_SOURCE_FOLDER;
            QString theDestination      = mySqlModel->mySetting->myConstants->MY_DESTINATION_FOLDER;
            QString theSourceLanguage   = mySqlModel->mySetting->myConstants->MY_SOURCE_LANGUAGE;
            QString theMake             = mySqlModel->mySetting->myConstants->MY_MAKE;
            QString theLanguageIDs      = mySqlModel->mySetting->myConstants->MY_LANGUAGE_IDs;
            setProject(theQtProjectName, theQtProjectFolder, theSource, theDestination, theSourceLanguage, theLanguageIDs, theMake);
            if (insertQtProjects())
            {
                myProjectFolder = mySqlModel->getRecordID();
                mySqlModel->mySetting->writeSettings(mySqlModel->mySetting->myConstants->MY_SQL_PROJECT_ID, myProjectFolder);
            }
            else
            {
                qCritical() << mySqlModel->getSqlDriver() <<  "  INSERT TABLE Projects error:";
            }
        }
        //
    } // end if (!isDbTable("Projects"))
    //
    return true;
}
/*! ***************************************************************************
   \fn insertProjects
   \brief insert Projects into SQL Database
 *************************************************************************** */
bool MyDatatables::insertQtProjects()
{
    if (isDebugMessage) { qDebug() << "insertProjects"; }
    // QtProjectName, QtProjectFolder, SourceFolder, DestinationFolder, LanguageIDs, Make
    QString theQuery = QLatin1String(R"(INSERT INTO Projects (QtProjectName, QtProjectFolder, SourceFolder, DestinationFolder, SourceLanguage, LanguageIDs, Make) values('%1', '%2', '%3', '%4', '%5', '%6', '%7'))").arg(myProject->getQtProjectName(), myProject->getQtProjectFolder(), myProject->getSourceFolder(), myProject->getDestinationFolder(), myProject->getSourceLanguage(), myProject->getLanguageIDs(), myProject->getMake());
    if (isDebugMessage) { qDebug() << "insertProjects: " << theQuery; }
    //
    if (!mySqlModel->runQuery(theQuery))
    {
        qCritical() << "INSERT Projects error: " << theQuery;
        return false;
    }
    myProjectFolder = mySqlModel->getRecordID();
    return true;
}
/*! ***************************************************************************
   \fn addProject
   \brief addProject Assumes you have ran setProject: QtProjectName, QtProjectFolder, SourceFolder, DestinationFolder, LanguageIDs
 *************************************************************************** */
bool MyDatatables::addQtProject()
{
    if (isDebugMessage) { qDebug() << "addQtProject"; }
    // SELECT id, QtProjectName FROM Projects WHERE QtProject =
    if (isQtProjectNameQuery(myProject->getQtProjectFolder()))
    {
        mySqlModel->mySetting->showMessageBox(QObject::tr("Record found!").toLocal8Bit(), QString("%1: %2").arg(tr("Not adding: Record found in database"), myProject->getQtProjectFolder()).toLocal8Bit(), mySqlModel->mySetting->Warning);
        return false;
    }
    return insertQtProjects();
}
/*! ***************************************************************************
   \fn deleteProject
   \brief delete Project
 *************************************************************************** */
void MyDatatables::deleteQtProject(const QString &thisID)
{
    if (isDebugMessage) { qDebug() << "deleteQtProject"; }
    QSqlQuery query; //!< SQL Query
    QString theQuery = QString("DELETE FROM Projects WHERE id = ").append(thisID);
    if (isDebugMessage) { qDebug() << "thisQuery: " << theQuery; }
    if (!query.exec(theQuery))
    {
        qCritical() << "SqLite error:" << query.lastError().text() << ", SqLite error code:" << query.lastError();
    }
}
/*! ***************************************************************************
   \fn getQtProjectNameSelectQuery
   \brief get Qt Project Name Select Query SELECT id, QtProjectName FROM Projects
 *************************************************************************** */
QString MyDatatables::getQtProjectNameSelectQuery()
{
    if (isDebugMessage) { qDebug() << "getQtProjectNameSelectQuery"; }
    return QString("SELECT id, QtProjectName FROM Projects");
}
/*! ***************************************************************************
   \fn getQtProjectNameByNameQuery
   \brief get Qt Project Name By Name Query SELECT id, QtProjectName FROM Projects WHERE QtProjectFolder =
 *************************************************************************** */
QString MyDatatables::getQtProjectNameByNameQuery(const QString &thisProject)
{
    if (isDebugMessage) { qDebug() << "getQtProjectNameByNameQuery"; }
    return QString("SELECT id, QtProjectName FROM Projects WHERE QtProjectName = '%1'").arg(thisProject);
}
/*! ***************************************************************************
   \fn isProjectFolderQuery
   \brief is Project Folder Query myAccessSqlDbtModel->isProjectQuery(ui->lineEditSettingsProjectBin->text());
 *************************************************************************** */
bool MyDatatables::isQtProjectNameQuery(const QString &thisProjectName)
{
    if (isDebugMessage) { qDebug() << "isQtProjectNameQuery"; }
    QSqlQuery theQuery; //!< SQL Query
    QString theQueryCommand = getQtProjectNameByNameQuery(thisProjectName);
    if (theQuery.exec(theQueryCommand))
    {
        if (theQuery.first()) { return true;  }
        else                  { return false; }
    }
    else
    {
        qCritical() << "SqLite error isProjectQuery:" << theQuery.lastError().text() << ", SqLite error code:" << theQuery.lastError();
    }
    return false;
}
/*! ***************************************************************************
   \fn getQtProjectFullSelectQueryID
   \brief get Qt Project Full Select Query ID SELECT * FROM Projects WHERE id =
 *************************************************************************** */
QString MyDatatables::getQtProjectFullSelectQueryID(const QString &thisWhereID)
{
    if (isDebugMessage) { qDebug() << "getProjectFolderFullSelectQueryID"; }
    return QString("SELECT * FROM Projects WHERE id = ").append(thisWhereID);
}
/*! ***************************************************************************
   \fn getQtProjectNameSelectQueryID
   \brief get Qt Project Name Select Query ID  SELECT id, QtProjectName FROM Projects WHERE id
 *************************************************************************** */
QString MyDatatables::getQtProjectNameSelectQueryID(const QString &thisWhereID)
{
    if (isDebugMessage) { qDebug() << "getQtProjectNameSelectQueryID"; }
    return QString("SELECT id, QtProjectName FROM Projects WHERE id = ").append(thisWhereID);
}
/*! ***************************************************************************
   \fn saveProject
   \brief save Project Projects: id, QtProjectName QtProjectFolder, SourceFolder, DestinationFolder, SourceLanguage, LanguageIDs, Make
 *************************************************************************** */
void MyDatatables::saveQtProject()
{
    if (isDebugMessage) { qDebug() << "saveProject"; }
    QSqlQuery theQuery; //!< SQL Query
    QString theQueryString = QString("UPDATE Projects set QtProjectName = '%1', QtProjectFolder = '%2', SourceFolder = '%3', DestinationFolder = '%4', SourceLanguage = '%5', LanguageIDs = '%6', Make = '%7' WHERE id = %8").arg(myProject->getQtProjectName(), myProject->getQtProjectFolder(), myProject->getSourceFolder(), myProject->getDestinationFolder(), myProject->getSourceLanguage(), myProject->getLanguageIDs(), myProject->getMake(), myProject->getID());
    if (isDebugMessage) { qDebug() << "thisQuery: |" << theQueryString << "|  getQtProjectName = " << myProject->getQtProjectName() << "|  getQtProjectFolder = " << myProject->getQtProjectFolder() << "| getSourceFolder=" << myProject->getSourceFolder() << "| getDestinationFolder=" << myProject->getDestinationFolder() << "| getSourceLanguage=" << myProject->getSourceLanguage() << "| getLanguageIDs=" << myProject->getLanguageIDs() << "| getMake=" << myProject->getMake() << "| ID=" << myProject->getID() << "|"; }
    if (!theQuery.exec(theQueryString))
    {
        qCritical() << "SqLite error saveProject:" << theQuery.lastError().text() << ", SqLite error code:" << theQuery.lastError();
    }
    isSaveSettings = false;
}
/*! ***************************************************************************
   \fn setProject
   \brief set Project Sets all Variables used in the Configuarion Database in one Place:
          QtProjectFolder, SourceFolder, DestinationFolder, SourceLanguage, LanguageIDs, Make
 *************************************************************************** */
void MyDatatables::setProject(const QString &thisQtProjectName, const QString &thisQtProjectFolder, const QString &thisSourceFolder, const QString &thisDestinationFolder, const QString &thisSourceLanguage, const QString &thisLanguageIDs, const QString &thisMake)
{
    if (isDebugMessage) { qDebug() << "setProject"; }
    myProject->setQtProjectName(thisQtProjectName);
    myProject->setQtProjectFolder(thisQtProjectFolder);
    myProject->setSourceFolder(thisSourceFolder);
    myProject->setDestinationFolder(thisDestinationFolder);
    myProject->setSourceLanguage(thisSourceLanguage);
    myProject->setLanguageIDs(thisLanguageIDs);
    myProject->setMake(thisMake);
}
/*** ************************* End of File ***********************************/
