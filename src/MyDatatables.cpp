#include "MyDatatables.h"

/************************************************
 * @brief My Datatables Constructor.
 * MyDatatables
 ***********************************************/
MyDatatables::MyDatatables(QObject *parent) : QObject(parent)
{
    mySqlModel = new MySqlDbtModel(this);
    // Create Variable Trackers and Set to Empty
    myProject = new MyProjectClass("", "", "", "", "", "", "", "", "");
}
/************************************************
 * @brief My Datatables Deconstructor.
 * MyDatatables
 ***********************************************/
MyDatatables::~MyDatatables()
{

}
/************************************************
 * @brief set Debug Message.
 * setDebugMessage
 ***********************************************/
void MyDatatables::setDebugMessage(bool thisState)
{
    isDebugMessage = thisState;
    setMessage("setDebugMessage");
}
/************************************************
 * @brief get Debug Message.
 * getDebugMessage
 ***********************************************/
bool MyDatatables::getDebugMessage()
{
    setMessage("getDebugMessage");
    return isDebugMessage;
}
/************************************************
 * @brief set Project Folder.
 * setProjectFolder
 ***********************************************/
void MyDatatables::setProjectFolder(const QString &thisProjectFolder)
{
    setMessage("setProjectFolder");
    myProjectFolder = thisProjectFolder;
}
/************************************************
 * @brief get Project Folder.
 * getProjectFolder
 ***********************************************/
QString MyDatatables::getProjectFolder()
{
    setMessage("getProjectFolder");
    return myProjectFolder;
}
/************************************************
 * @brief set Project Name.
 * setProjectName
 ***********************************************/
void MyDatatables::setProjectName(const QString &thisProjectName)
{
    setMessage("setProjectName");
    myProjectName = thisProjectName;
}
/************************************************
 * @brief get Project Name.
 * getProjectName
 ***********************************************/
QString MyDatatables::getProjectName()
{
    setMessage("getProjectName");
    return myProjectName;
}
/************************************************
 * @brief set Project ID.
 * setProjectID
 ***********************************************/
void MyDatatables::setProjectID(const QString &thisProjectID)
{
    setMessage("setProjectID");
    myProjectID = thisProjectID;
}
/************************************************
 * @brief get Project ID.
 * getProjectID
 ***********************************************/
QString MyDatatables::getProjectID()
{
    setMessage("getProjectID");
    return myProjectID;
}
/************************************************
 * @brief set ComboBox Sql Value.
 * setComboBoxSqlValue
 ***********************************************/
void MyDatatables::setComboBoxSqlValue(const QString &thisComboBoxSqlValue)
{
    setMessage("setComboBoxSqlValue");
    myComboBoxSqlValue = thisComboBoxSqlValue;
}
/************************************************
 * @brief get ComboBox Sql Value.
 * getComboBoxSqlValue
 ***********************************************/
QString MyDatatables::getComboBoxSqlValue()
{
    setMessage("getComboBoxSqlValue");
    return myComboBoxSqlValue;
}
/************************************************
 * @brief check Database.
 * checkDatabase
 ***********************************************/
bool MyDatatables::checkDatabase()
{
    setMessage("checkDatabase");
    // Database
    mySqlModel->setSqlDriver(myComboBoxSqlValue);
    if (!mySqlModel->createDataBaseConnection()) { return false; }
    //
    // Configuration
    //
    if (!mySqlModel->isDbTable("Projects"))
    {
        /*
         * Table Projects holds the name of the Qt Project
         * id integer PRIMARY KEY autoincrement,
         * id, QtProjectName, QtProjectFolder, SourceFolder, DestinationFolder, HelpFolder, SourceLanguage, LanguageIDs, Make
        */
        if (mySqlModel->runQuery(QLatin1String(R"(CREATE TABLE Projects(id integer PRIMARY KEY autoincrement, QtProjectName, QtProjectFolder, SourceFolder, DestinationFolder, HelpFolder, SourceLanguage, LanguageIDs, Make))")))
        {
            QString theQtProjectName    = mySqlModel->mySetting->myConstants->MY_QT_PROJECT_NAME;
            QString theQtProjectFolder  = mySqlModel->mySetting->myConstants->MY_QT_PROJECT_FOLDER;
            QString theSource           = mySqlModel->mySetting->myConstants->MY_SOURCE_FOLDER;
            QString theDestination      = mySqlModel->mySetting->myConstants->MY_DESTINATION_FOLDER;
            QString theHelpFolder       = mySqlModel->mySetting->myConstants->MY_HELP_FOLDER;
            QString theSourceLanguage   = mySqlModel->mySetting->myConstants->MY_SOURCE_LANGUAGE;
            QString theMake             = mySqlModel->mySetting->myConstants->MY_MAKE;
            QString theLanguageIDs      = mySqlModel->mySetting->myConstants->MY_LANGUAGE_IDs;
            setProject(theQtProjectName, theQtProjectFolder, theSource, theDestination, theHelpFolder, theSourceLanguage, theLanguageIDs, theMake);
            if (insertQtProjects())
            {
                myProjectID = mySqlModel->getRecordID();
                mySqlModel->mySetting->writeSettings(mySqlModel->mySetting->myConstants->MY_SQL_PROJECT_ID, myProjectID);
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
/************************************************
 * @brief insert Qt Projects into SQL Database.
 * insertQtProjects
 ***********************************************/
bool MyDatatables::insertQtProjects()
{
    setMessage("insertProjects");
    // QtProjectName, QtProjectFolder, SourceFolder, DestinationFolder, HelpFolder, LanguageIDs, Make
    QString theQuery = QLatin1String(R"(INSERT INTO Projects (QtProjectName, QtProjectFolder, SourceFolder, DestinationFolder, HelpFolder, SourceLanguage, LanguageIDs, Make) values('%1', '%2', '%3', '%4', '%5', '%6', '%7', '%8'))").arg(myProject->getQtProjectName(), myProject->getQtProjectFolder(), myProject->getSourceFolder(), myProject->getDestinationFolder(), myProject->getHelpFolder(), myProject->getSourceLanguage(), myProject->getLanguageIDs(), myProject->getMake());
    setMessage("insertProjects: " + theQuery);
    //
    if (!mySqlModel->runQuery(theQuery))
    {
        qCritical() << "INSERT Projects error: " << theQuery;
        return false;
    }
    myProjectID = mySqlModel->getRecordID();
    return true;
}
/************************************************
 * @brief addQtProject Assumes you have ran setProject: QtProjectName, QtProjectFolder, SourceFolder, DestinationFolder, HelpFolder, LanguageIDs.
 * addQtProject
 ***********************************************/
bool MyDatatables::addQtProject()
{
    setMessage("addQtProject");
    // SELECT id, QtProjectName FROM Projects WHERE QtProject =
    if (isQtProjectNameQuery(myProject->getQtProjectName()))
    {
        mySqlModel->mySetting->showMessageBox(QObject::tr("Record found!").toLocal8Bit(), QString("%1: %2").arg(tr("Not adding: Record found in database"), myProject->getQtProjectName()).toLocal8Bit(), mySqlModel->mySetting->Warning);
        return false;
    }
    return insertQtProjects();
}
/************************************************
 * @brief delete Project.
 * deleteProject
 ***********************************************/
void MyDatatables::deleteQtProject(const QString &thisID)
{
    setMessage("deleteQtProject");
    QSqlQuery query; //!< SQL Query
    QString theQuery = QString("DELETE FROM Projects WHERE id = ").append(thisID);
    setMessage("thisQuery: " + theQuery);
    if (!query.exec(theQuery))
    {
        qCritical() << "SqLite error:" << query.lastError().text() << ", SqLite error code:" << query.lastError();
    }
}
/************************************************
 * @brief get Qt Project Name Select Query SELECT id, QtProjectName FROM Projects.
 * getQtProjectNameSelectQuery
 ***********************************************/
QString MyDatatables::getQtProjectNameSelectQuery()
{
    setMessage("getQtProjectNameSelectQuery");
    return QString("SELECT id, QtProjectName FROM Projects");
}
/************************************************
 * @brief get Qt Project Name By Name Query SELECT id, QtProjectName FROM Projects WHERE QtProjectFolder =.
 * getQtProjectNameByNameQuery
 ***********************************************/
QString MyDatatables::getQtProjectNameByNameQuery(const QString &thisProject)
{
    setMessage("getQtProjectNameByNameQuery");
    return QString("SELECT id, QtProjectName FROM Projects WHERE QtProjectName = '%1'").arg(thisProject);
}
/************************************************
 * @brief is Project Folder Query myAccessSqlDbtModel->isProjectQuery(ui->lineEditSettingsProjectBin->text());.
 * isProjectFolderQuery
 ***********************************************/
bool MyDatatables::isQtProjectNameQuery(const QString &thisProjectName)
{
    setMessage("isQtProjectNameQuery");
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
/************************************************
 * @brief get Qt Project Full Select Query ID SELECT * FROM Projects WHERE id =.
 * getQtProjectFullSelectQueryID
 ***********************************************/
QString MyDatatables::getQtProjectFullSelectQueryID(const QString &thisWhereID)
{
    setMessage("getProjectFolderFullSelectQueryID");
    return QString("SELECT * FROM Projects WHERE id = ").append(thisWhereID);
}
/************************************************
 * @brief get Qt Project Name Select Query ID  SELECT id, QtProjectName FROM Projects WHERE id.
 * getQtProjectNameSelectQueryID
 ***********************************************/
QString MyDatatables::getQtProjectNameSelectQueryID(const QString &thisWhereID)
{
    setMessage("getQtProjectNameSelectQueryID");
    return QString("SELECT id, QtProjectName FROM Projects WHERE id = ").append(thisWhereID);
}
/************************************************
 * @brief save Project Projects: id, QtProjectName QtProjectFolder, SourceFolder, DestinationFolder, HelpFolder, SourceLanguage, LanguageIDs, Make
 * saveProject
 ***********************************************/
void MyDatatables::saveQtProject()
{
    setMessage("saveProject");
    QSqlQuery theQuery; //!< SQL Query
    QString theQueryString = QString("UPDATE Projects set QtProjectName = '%1', QtProjectFolder = '%2', SourceFolder = '%3', DestinationFolder = '%4', HelpFolder = '%5', SourceLanguage = '%6', LanguageIDs = '%7', Make = '%8' WHERE id = %9").arg(myProject->getQtProjectName(), myProject->getQtProjectFolder(), myProject->getSourceFolder(), myProject->getDestinationFolder(), myProject->getHelpFolder(), myProject->getSourceLanguage(), myProject->getLanguageIDs(), myProject->getMake(), myProject->getID());
    setMessage("thisQuery: |" + theQueryString + "|  getQtProjectName = " + myProject->getQtProjectName() + "|  getQtProjectFolder = " + myProject->getQtProjectFolder() + "| getSourceFolder=" + myProject->getSourceFolder() + "| getDestinationFolder=" + myProject->getDestinationFolder() + "| getHelpFolder=" + myProject->getHelpFolder() + "| getSourceLanguage=" + myProject->getSourceLanguage() + "| getLanguageIDs=" + myProject->getLanguageIDs() + "| getMake=" + myProject->getMake() + "| ID=" + myProject->getID() + "|");
    if (!theQuery.exec(theQueryString))
    {
        qCritical() << "SqLite error saveProject:" << theQuery.lastError().text() << ", SqLite error code:" << theQuery.lastError();
    }
    isSaveSettings = false;
}
/************************************************
 * @brief set Project Sets all Variables used in the Configuarion Database in one Place:
 *        QtProjectFolder, SourceFolder, DestinationFolder, HelpFolder, SourceLanguage, LanguageIDs, Make.
 * setProject
 ***********************************************/
void MyDatatables::setProject(const QString &thisQtProjectName, const QString &thisQtProjectFolder, const QString &thisSourceFolder, const QString &thisDestinationFolder,  const QString &thisHelpFolder, const QString &thisSourceLanguage, const QString &thisLanguageIDs, const QString &thisMake)
{
    setMessage("setProject");
    myProject->setQtProjectName(thisQtProjectName);
    myProject->setQtProjectFolder(thisQtProjectFolder);
    myProject->setSourceFolder(thisSourceFolder);
    myProject->setDestinationFolder(thisDestinationFolder);
    myProject->setHelpFolder(thisHelpFolder);
    myProject->setSourceLanguage(thisSourceLanguage);
    myProject->setLanguageIDs(thisLanguageIDs);
    myProject->setMake(thisMake);
}
/************************************************
 * @brief set Message.
 * setMessage
 ***********************************************/
void MyDatatables::setMessage(const QString &thisMessage)
{
    if (isDebugMessage)
    {
        qDebug() << thisMessage;
        std::cout << thisMessage.toStdString() << std::endl;
    }
}
/*** ************************* End of File ***********************************/
