#ifndef MY_SQL_DBT_MODEL_H
#define MY_SQL_DBT_MODEL_H

#include <QObject>
#include <QtWidgets>
#ifdef USE_SQL_FLAG
    #include <QtSql>
#endif
#include <QtDebug>
#include <QDir>
//
#include "MyConstants.h"
//#include "MyOrgSettings.h"
#include "MyLanguageModel.h"
/************************************************
 * @brief SQL Database Table Model.
 * \class MySqlDbtModel
 * @author Jeffrey Scott Flesher
 ***********************************************/
class MySqlDbtModel : public QObject
{
        Q_OBJECT
    public:
        MySqlDbtModel(MyLanguageModel *thisLanguageModel = nullptr, MyConstants *thisConstant = nullptr, QObject *parent = 0); //!< MySqlDbtModel
        ~MySqlDbtModel();                                           //!< ~MySqlDbtModel
        // Public
        MyLanguageModel *myLanguageModel;                           //!< \c myLanguageModel @brief Localization Model.
        MyConstants     *myConstants;                               //!< \c myConstants     @brief All Constants in one class
        // DataBase Connection
        bool createDataBaseConnection();                            //!< create DataBase Connection
        bool isDbTable(const QString &thisTable);                   //!< isDbTable
        // Sql Driver
        void setSqlDriver(const QString &thisDriver);               //!< setSqlDriver
        QString getSqlDriver();                                     //!< getSqlDriver
        // Sql Table Name
        void setSqlTableName(const QString &thisTableName);         //!< setSqlTableName
        QString getSqlTableName();                                  //!< getSqlTableName
        // Sql Host Name
        void setSqlHostName(const QString &thisHostName);           //!< setSqlHostName
        QString getSqlHostName();                                   //!< getSqlHostName
        // Sql User Name
        void setSqlUserName(const QString &thisUserName);           //!< setSqlUserName
        QString getSqlUserName();                                   //!< getSqlUserName
        // Sql Password
        void setSqlPassword(const QString &thisPassword);           //!< setSqlPassword
        QString getSqlPassword();                                   //!< getSqlPassword
        // Sql Database Name
        void setSqlDatabaseName(const QString &thisPassword);       //!< setSqlDatabaseName
        QString getSqlDatabaseName();                               //!< getSqlDatabaseName
        #ifdef USE_SQL_FLAG
        // Sql Database
        void setSqlDatabase(QSqlDatabase thisDatabase);             //!< set Sql Database
        QSqlDatabase getSqlDatabase();                              //!< get Sql Database
        #endif
        // Connection Name
        QString getConnectionName();                                //!< get Connection Name
        void setConnectionName(const QString &thisConnectionName);  //!< set Connection Name
        // RecordID
        QString getRecordID();                                      //!< get RecordID
        void setRecordID(const QString &thisRecordID);              //!< set RecordID
        // run Query
        bool runQuery(const QString &thisQuery);                    //!< runQuery
        // move Db
        bool moveDb(const QString &thisSourceFile, const QString &thisSourcePath, const QString &thisDestinationFolder); //!<  Move Db
        QString runProcces(const QString &thisExePath, const QString &thisArgument, bool isWait, int thisWaitTimeSec);   //!< run Procces
        // Run Return Code
        int getRunReturnCode();                      //!< get Run Return Code
        // Is Debug Message
        void setDebugMessage(bool thisState);        //!< set Debug Message
        bool getDebugMessage();                      //!< get Debug Message
        void setMessage(const QString &thisMessage); //!< setMessage

    private:
        #ifdef USE_SQL_FLAG
        QSqlDatabase myDb;                              //!< \c myDb               @brief Database
        #endif
        QString      myDatabaseName   = "QtLingo";      //!< \c myDatabaseName     @brief Sql Driver DatabaseName with extention for Sqlite
        QString      myTableName      = "QtLingo" ;     //!< \c myTableName        @brief Table Name
        QString      mySqlDriver      = "NOTSET";       //!< \c mySqlDriver        @brief Sql Driver NOTSET
        QString      myHostName       = "localhost";    //!< \c myHostName         @brief Sql HostName location of your MySQL server and database, localhost
        QString      myUserName       = "";             //!< \c myUserName         @brief Sql User Name
        QString      myPassword       = "";             //!< \c myPassword         @brief Sql Password
        QString      myConnectionName = "QtLingo";      //!< \c myConnectionName   @brief Connection Name
        QString      myInsertID       = "-1";           //!< \c myInsertID         @brief InsertID for last SQL insert
        bool         isDebugMessage   = true;           //!< \c isDebugMessage     @brief Debug Message
        int          myRunReturnCode  = 1;              //!< \c myRunReturnCode    @brief Run Return Code
};
#endif // MY_SQL_DBT_MODEL_H
/*** ************************* End of File ***********************************/
