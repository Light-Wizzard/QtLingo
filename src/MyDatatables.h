#ifndef MYDATATABLES_H
#define MYDATATABLES_H

#include <QObject>
#include <QtDebug>
#include "MySqlDbtModel.h"
/*! ***************************************************************************
   \class MyProjectClass
   \brief
        QString         mySource;                   //!< \c mySource            \brief Source
        QString         myDestination;              //!< \c myDestination       \brief Destination
        QString         myMode;                     //!< \c myMode              \brief Mode
        QString         myLanguageID;               //!< \c myLanguageID        \brief Language ID
        bool            myWithUnfinished = false;   //!< \c myWithUnfinished    \brief With Unfinished
        bool            myWithVanished = false;     //!< \c myWithVanished      \brief With Vanished
        bool            myUnfinishedOnly = false;   //!< \c myUnfinishedOnly    \brief Unfinished Only

QtProjectFolder, SourceFolder, DestinationFolder, LanguageIDs
 *************************************************************************** */
class MyProjectClass
{
        QString myID, myQtProjectName, myQtProjectFolder, mySourceFolder, myDestinationFolder, mySourceLanguage, myLanguageIDs, myMake;
    public:
        MyProjectClass(const QString &thisID, const QString &thisQtProjectName, const QString &thisQtProjectFolder, const QString &thisSourceFolder, const QString &thisDestinationFolder, const QString &thisSourceLanguage, const QString &thisLanguageIDs, const QString &thisMake)
            : myID{thisID}, myQtProjectName{thisQtProjectName}, myQtProjectFolder{thisQtProjectFolder}, mySourceFolder{thisSourceFolder}, myDestinationFolder{thisDestinationFolder}, mySourceLanguage{thisSourceLanguage}, myLanguageIDs{thisLanguageIDs}, myMake{thisMake} {}
        // Getters
        QString getID()                const { return myID;                }
        QString getQtProjectName()     const { return myQtProjectName;     }
        QString getQtProjectFolder()   const { return myQtProjectFolder;   }
        QString getSourceFolder()      const { return mySourceFolder;      }
        QString getDestinationFolder() const { return myDestinationFolder; }
        QString getSourceLanguage()    const { return mySourceLanguage;    }
        QString getLanguageIDs()       const { return myLanguageIDs;       }
        QString getMake()              const { return myMake;              }
        // Setters
        void setID(const QString &s)                { myID = s;                }
        void setQtProjectName(const QString &s)     { myQtProjectName = s;     }
        void setQtProjectFolder(const QString &s)   { myQtProjectFolder = s;   }
        void setSourceFolder(const QString &s)      { mySourceFolder = s;      }
        void setDestinationFolder(const QString &s) { myDestinationFolder = s; }
        void setSourceLanguage(const QString &s)    { mySourceLanguage = s;    }
        void setLanguageIDs(const QString &s)       { myLanguageIDs = s;       }
        void setMake(const QString &s)              { myMake = s;              }
};
/*! ***************************************************************************
   \class MyDatatables
   \brief My Datatables
 *************************************************************************** */
class MyDatatables : public QObject
{
        Q_OBJECT
    public:
        explicit MyDatatables(QObject *parent = nullptr);
        ~MyDatatables();
        //
        MyProjectClass *myProject;                                  //!< \c myProject \brief My Project Variables
        MySqlDbtModel  *mySqlModel;                                 //!< \c mySqlModel \brief Pointer to DataTable
        //
        bool checkDatabase();                                       //!< check Database
        bool insertQtProjects();                                    //!< insert Qt Project
        //
        void setProject(const QString &thisQtProjectName, const QString &thisQtProject, const QString &thisSecret, const QString &thisEnvironment, const QString &thisSourceLanguage, const QString &thisLanguageIDs, const QString &thisMake);
        //
        QString getQtProjectNameSelectQueryID(const QString &thisWhereID);  //!< get Qt Projects Name Select Query ID
        QString getQtProjectNameSelectQuery();                              //!< get Qt Projects Name Select Query
        QString getQtProjectFullSelectQueryID(const QString &thisWhereID);  //!< get Qt Projects Full Select Query ID
        QString getQtProjectNameByNameQuery(const QString &thisProject);    //!< get Qt Projects Name By Name Query
        bool isQtProjectNameQuery(const QString &thisProjectName);          //!< is Qt Project Name Query
        bool addQtProject();                                                //!< add Qt Project
        void deleteQtProject(const QString &thisID);                        //!< delete Qt Project
        void saveQtProject();                                               //!< save Qt Project

        void setProjectName(const QString &thisProjectName);                //!< set Project Name
        QString getProjectName();                                           //!< get Project Name

        void setProjectID(const QString &thisProjectID);                    //!< set Project ID
        QString getProjectID();                                             //!< get Project ID
        //
        void setProjectFolder(const QString &thisProjectFolder);            //!< set Project Folder
        QString getProjectFolder();                                         //!< get Project Folder
        //
        void setComboBoxSqlValue(const QString &thisComboBoxSqlValue);      //!< set ComboBox SqlValue
        QString getComboBoxSqlValue();                                      //!< get ComboBox SqlValue
        // Is Debug Message
        void setDebugMessage(bool thisState);                               //!< set Debug Message
        bool getDebugMessage();                                             //!< get Debug Message

    private:
        QString          myProjectID        = "-1";          //!< \c myProjectID         \brief Project ID
        QString          myComboBoxSqlValue = "-1";          //!< \c myComboBoxSqlValue  \brief ComboBox Sql Value
        QString          myProjectFolder    = "QtLingo";     //!< \c myProjectFolder     \brief Project Folder
        QString          myProjectName      = "QtLingo";     //!< \c myProjectName       \brief Project Name
        bool             isDebugMessage     = true;          //!< \c isDebugMessage      \brief Debug Message
        bool             isSaveSettings     = false;         //!< \c isSaveSettings      \brief is Save Settings for Auto Save

};
#endif // MYDATATABLES_H
/*** ************************* End of File ***********************************/
