#ifndef MYDATATABLES_H
#define MYDATATABLES_H

#include <QObject>
#include <QtDebug>
#include "MyConstants.h"
#include "MySqlDbtModel.h"
#include "MyLanguageModel.h"
/************************************************
 * @brief Project Class.
 * \class MyProjectClass
 * @author Jeffrey Scott Flesher
 ***********************************************/
class MyProjectClass
{
    public:
        MyProjectClass(const QString &thisID, const QString &thisQtProjectName, const QString &thisQtProjectFolder, const QString &thisSourceFolder, const QString &thisDestinationFolder,  const QString &thisHelpFolder, const QString &thisSourceLanguage, const QString &thisLanguageIDs, const QString &thisMake)
            : myID{thisID}, myQtProjectName{thisQtProjectName}, myQtProjectFolder{thisQtProjectFolder}, mySourceFolder{thisSourceFolder}, myDoxyfileFolder{thisDestinationFolder}, myHelpFolder{thisHelpFolder}, mySourceLanguage{thisSourceLanguage}, myLanguageIDs{thisLanguageIDs}, myMake{thisMake} {}
        // Getters
        QString getID()                const { return myID;                } //!< ID
        QString getQtProjectName()     const { return myQtProjectName;     } //!< Project Name of .pro file
        QString getQtProjectFolder()   const { return myQtProjectFolder;   } //!< Base Project Folder
        QString getSourceFolder()      const { return mySourceFolder;      } //!< Source Folder
        QString getDoxyfileFolder()    const { return myDoxyfileFolder;    } //!< Doxyfile Folder
        QString getHelpFolder()        const { return myHelpFolder;        } //!< Help Folder
        QString getSourceLanguage()    const { return mySourceLanguage;    } //!< ComboBox of Languages
        QString getLanguageIDs()       const { return myLanguageIDs;       } //!< Sum of Checkboxes
        QString getMake()              const { return myMake;              } //!< qmake or cmake
        // Setters
        void setID(const QString &s)                { myID                = s; }
        void setQtProjectName(const QString &s)     { myQtProjectName     = s; }
        void setQtProjectFolder(const QString &s)   { myQtProjectFolder   = s; }
        void setSourceFolder(const QString &s)      { mySourceFolder      = s; }
        void setDoxyfileFolder(const QString &s)    { myDoxyfileFolder    = s; }
        void setHelpFolder(const QString &s)        { myHelpFolder        = s; }
        void setSourceLanguage(const QString &s)    { mySourceLanguage    = s; }
        void setLanguageIDs(const QString &s)       { myLanguageIDs       = s; }
        void setMake(const QString &s)              { myMake              = s; }

    private:
        QString myID, myQtProjectName, myQtProjectFolder, mySourceFolder, myDoxyfileFolder, myHelpFolder;
        QString mySourceLanguage, myLanguageIDs, myMake;
};
/************************************************
 * @brief My Datatables.
 * \class MyDatatables
 * @author Jeffrey Scott Flesher
 ***********************************************/
class MyDatatables : public QObject
{
        Q_OBJECT
    public:
        explicit MyDatatables(MyLanguageModel *thisLanguageModel = nullptr, MyConstants *thisConstant = nullptr, QObject *parent = nullptr);
        ~MyDatatables();
        //
        MyProjectClass  *myProject;                  //!< \c myProject       @brief My Project Variables
        MySqlDbtModel   *mySqlModel;                 //!< \c mySqlModel      @brief Pointer to DataTable
        MyLanguageModel *myLanguageModel;            //!< \c myLanguageModel @brief Localization Model.
        MyConstants     *myConstants;                //!< \c myConstants     @brief All Constants in one class
        //
        bool checkDatabase();                        //!< check Database
        bool insertQtProjects();                     //!< insert Qt Project
        bool addQtProject();                         //!< add Qt Project
        void deleteQtProject(const QString &thisID); //!< delete Qt Project
        void saveQtProject();                        //!< save Qt Project
        //
        void setProject(const QString &thisQtProjectName, const QString &thisQtProject, const QString &thisSecret, const QString &thisEnvironment, const QString &thisHelpFolder, const QString &thisSourceLanguage, const QString &thisLanguageIDs, const QString &thisMake);
        // Query
        QString getQtProjectNameSelectQueryID(const QString &thisWhereID);  //!< get Qt Projects Name Select Query ID
        QString getQtProjectNameSelectQuery();                              //!< get Qt Projects Name Select Query
        QString getQtProjectFullSelectQueryID(const QString &thisWhereID);  //!< get Qt Projects Full Select Query ID
        QString getQtProjectNameByNameQuery(const QString &thisProject);    //!< get Qt Projects Name By Name Query
        bool isQtProjectNameQuery(const QString &thisProjectName);          //!< is Qt Project Name Query
        // Project Name
        void setProjectName(const QString &thisProjectName);                //!< set Project Name
        QString getProjectName();                                           //!< get Project Name
        // Project ID
        void setProjectID(const QString &thisProjectID);                    //!< set Project ID
        QString getProjectID();                                             //!< get Project ID
        // Project Folder
        void setProjectFolder(const QString &thisProjectFolder);            //!< set Project Folder
        QString getProjectFolder();                                         //!< get Project Folder
        // ComboBox SQL Value
        void setComboBoxSqlValue(const QString &thisComboBoxSqlValue);      //!< set ComboBox SqlValue
        QString getComboBoxSqlValue();                                      //!< get ComboBox SqlValue
        // Is Debug Message
        void setDebugMessage(bool thisState);                               //!< set Debug Message
        bool getDebugMessage();                                             //!< get Debug Message
        void setMessage(const QString &thisMessage);                        //!< set Message

    private:
        QString          myProjectID        = "-1";          //!< \c myProjectID         @brief Project ID
        QString          myComboBoxSqlValue = "-1";          //!< \c myComboBoxSqlValue  @brief ComboBox SQL Value
        QString          myProjectFolder    = "QtLingo";     //!< \c myProjectFolder     @brief Project Folder
        QString          myProjectName      = "QtLingo";     //!< \c myProjectName       @brief Project Name
        bool             isDebugMessage     = true;          //!< \c isDebugMessage      @brief Debug Message
        bool             isSaveSettings     = false;         //!< \c isSaveSettings      @brief is Save Settings for Auto Save

};
#endif // MYDATATABLES_H
/*** ************************* End of File ***********************************/
