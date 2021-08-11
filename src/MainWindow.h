#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QTranslator>
#include <QtGlobal>
#include <QMap>
#include <QPointer>
#include <QVector>
#include <QCloseEvent>
#include <QFile>
//
#include "qexample.h"
#include "qoption.h"
// UI
#include "ui_MainWindow.h"
// MyDatatables
#include "MyDatatables.h"
#include "MyTranslationFiles.h"
//
//#include "third-party/qonlinetranslator/src/qonlinetranslator.h"
#include "qonlinetranslator.h"
//
namespace Ui { class MainWindow; }
/*! ***************************************************************************
   \class MyTranslationJobs
   \brief My Translation Jobs
 *************************************************************************** */
class MyLingoJobs
{
        QString myLanguageName, myLangName, myTsFile;
        QOnlineTranslator::Language myLang, mySourceLang;
    public:
        MyLingoJobs(const QString &thisLanguageName, const QString &thisLangName, const QString &thisTsFile, QOnlineTranslator::Language thisLang, QOnlineTranslator::Language thisSourceLang)
            : myLanguageName{thisLanguageName}, myLangName{thisLangName}, myTsFile{thisTsFile}, myLang{thisLang}, mySourceLang{thisSourceLang} {}
        // Getters
        QString getLanguageName()                   const { return myLanguageName; }
        QString getLangName()                       const { return myLangName;     }
        QString getTsFile()                         const { return myTsFile;       }
        QOnlineTranslator::Language getLang()       const { return myLang;         }
        QOnlineTranslator::Language getSourceLang() const { return mySourceLang;   }
        // Setters
        void setLanguageName(const QString &s)            { myLanguageName = s; }
        void setLangName(const QString &s)                { myLangName = s;     }
        void setTsFile(const QString &s)                  { myTsFile = s;       }
        void setSourceLang(QOnlineTranslator::Language s) { mySourceLang = s;   }
        void setLang(QOnlineTranslator::Language s)       { myLang = s;         }
};
/*! ***************************************************************************
   \class MainWindow
   \fn MainWindow::MainWindow(QWidget *parent) : QDialog(parent), ui(new Ui::MainWindow)
   \brief Main Window Constructor.
 *************************************************************************** */
class MainWindow : public QMainWindow
{
        Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = nullptr);
        ~MainWindow();
        /*!
            \enum MainTabs
            \brief Tabs must be forced to be int 0 based indexes that match the actual ui for widgetTab, this enforces compile-time checks.
         */
        enum MainTabs
        {
            TabSettings     = 100,  //!< \c TabSettings     \brief Tab Settings.
            TabSql          = 101,  //!< \c TabSql          \brief Tab SQL
            TabTranslations = 102,  //!< \c TabTranslations \brief Tab Ubuntu.
            TabProject      = 103,  //!< \c TabProject      \brief Tab Project.
            TabTabHelp      = 104,  //!< \c TabHelp         \brief Tab Help.
            TabAll          = 200   //!< \c TabAll          \brief Tab All used for Actions on all Tabs.
        }; // end enum MainTabs

        Q_ENUM(MainTabs) // I enumerate the Tabs to make it easier to travers
        //
        void onRunOnStartup();                          //!< on Run On Startup
        //
        bool setQtProjectCombo();                       //!< set Qt Project Combo
        // Read
        void readSettings();                            //!< read Settings
        void readStatesChanges();                       //!< read States Changes
        void readSqlDatabaseInfo();                     //!< read Sql Database Info
        // Write
        bool writeSettings();                           //!< write Settings
        void writeStateChanges();                       //!< write State Changes
        void writeSqlDatabaseInfo();                    //!< write Sql Database Info
        //
        void setSqlBrowseButton();                      //!< set Sql Browse Button
        //
        void fillForms(const QString &thisProjectID);   //!< fill Forms
        //
        void clearForms(int tabNumber);                 //!< clear Forms
        void clearTabSettings();                        //!< clear Tab Settings
        void clearTabHelp();                            //!< clear Tab Help
        void clearTabTranslations();                    //!< clear Tab Translations
        void clearTabProject();                         //!< clear Tab Project
        void checkLanguage(const QString &thisName, const QString &thisLanguage, bool thisChecked); //!< check Language
        QString languageChecked();                      //!< language Checked
        void setProjectClass(int tabNumber);            //!< set Project Class
        void createTranslationJob(const QString &thisTranslate, const QString &thisLanguage, const QString &thisSourceLanguage, bool thisChecked); //!< get Translation String
        void setPrograms();                             //!< set Programs
        // Added by Light-Wizzard
        QString translateWithReturn(const QString &text, QOnlineTranslator::Engine engine, QOnlineTranslator::Language translationLang, QOnlineTranslator::Language sourceLang, QOnlineTranslator::Language uiLang); //!< translate With Return, note this is blocking
        void loadLanguage(const QString &thisQmLanguageFile); //!< load Language
        QString getLanguageFile(const QString &thisLanguage, const QString &thisPath, const QString &thisPrefix); //!< get Language File
        QString getLanguageFromFile(const QString &thisPrefix, const QString &thisQmLanguageFile); //!< getLanguageFromFile
        QString getTranslationSource();                                     //!< get Translation Source
        void setTranslationSource(const QString &thisTranslationSource);    //!< set Translation Source
        QString getTransFilePrefix();                                       //!< get TransFile Prefix
        void setTransFilePrefix(const QString &thisTransFilePrefix);        //!< set TransFile Prefix
        // Is Debug Message
        void setDebugMessage(bool thisState);           //!< set Debug Message
        bool getDebugMessage();                         //!< get Debug Message
        QString readLanguage();                         //!< read Language
        void writeLanguage(const QString &thisCurrentLanguageCode); //!< write Language
        void retranslate();                             //!< retranslate none designer components
        void loadLanguageComboBox();                    //!< load Language ComboBox
        void loadLanguageComboBoxSource();              //!< load Language ComboBox Source
        void readSettingsFirst();                       //!< read Settings First
        void setMessagingStates(bool thisMessageState); //!< set Messaging States

    public slots:
        void onHelp();                                  //!< on Help
        void onAbout();                                 //!< on About
        void onClipboard();                             //!< on Clipboard
        void onCompile();                               //!< on Compile
        void onAuthor();                                //!< on Author
        void onSave();                                  //!< on Save

    private slots:
        // ComboBoxes
        void on_comboBoxSettingsProjects_currentIndexChanged(int thisIndex);                               //!< on comboBox Settings Projects current Index Changed
        void on_comboBoxSettingsLanguage_currentIndexChanged(const QString &thisLanguage);             //!< on comboBox Settings Language current Index Changed
        void on_comboBoxSqlDatabaseType_currentIndexChanged(const QString &thisSqlType);               //!< on comboBox Sql Database Type current Index Changed
        // Push Buttons
        void on_pushButtonSettingsAdd_clicked();                                            //!< on pushButton Settings Add clicked
        void on_pushButtonSettingsSave_clicked();                                           //!< on pushButton Settings Save clicked
        void on_pushButtonSettingsDelete_clicked();                                         //!< on pushButton Settings Delete clicked
        void on_pushButtonSettingsProjectsBrowser_clicked();                                //!< on pushButton Settings Projects Browser clicked
        void on_pushButtonSqlDatabaseNameBrowse_clicked();                                  //!< on pushButton Sql Database Name Browse clicked
        void on_pushButtonSqlPasswordShow_clicked();                                        //!< on pushButton Sql Password Show clicked
        void on_pushButtonSqlSave_clicked();                                                //!< on pushButton Sql Save clicked
        void on_pushButtonTranslationsSourceBrowse_clicked();                               //!< on pushButton Translations Source Browse clicked
        void on_pushButtonTranslationsDestinationBrowse_clicked();                          //!< on pushButton Translations Destination Browse clicked
        void on_pushButtonTranslationsProjectFolderBrowse_clicked();                        //!< on pushButton Translations ProjectFolder Browse clicked
        void on_checkBoxSettingsGoogle_stateChanged(int thisArg);                           //!< on checkBox Settings Google state Changed
        void on_checkBoxSettingsBing_stateChanged(int thisArg);                             //!< on checkBox Settings Bing state Changed
        void on_checkBoxSettingsYandex_stateChanged(int thisArg);                           //!< on checkBox Settings Yandex state Changed
        void on_checkBoxSettignsMessaging_stateChanged(int thisCheckState);                 //!< on checkBox Settigns Messaging state Changed

    protected:
        void closeEvent(QCloseEvent *event) override;                //!< close Event

    protected slots:
        virtual void changeEvent(QEvent * event) override;           //!< change Event

    private:
        Ui::MainWindow     *ui;                                 //!< \c ui                      \brief ui
        MyDatatables       *mySqlDb;                            //!< \c mySqlDb                 \brief Sql Datatables
        MyTranslationFiles *myTranslationFiles;                 //!< \c myTranslationFiles      \brief Translation Files
        QOnlineTranslator   myQOnlineTranslator;                //!< \c myQOnlineTranslator     \brief QOnlineTranslator
        QClipboard         *clipboard;                          //!< \c clipboard               \brief clipboard
        bool                isDebugMessage        = true;       //!< \c isDebugMessage          \brief true of false for Debugging
        bool                isMainLoaded          = false;      //!< \c isMainLoaded            \brief Set true after one shot time loads
        bool                isQtSettingsLoaded    = false;      //!< \c isQtSettingsLoaded      \brief is Qt Settings Loaded
        bool                isSaveSettings        = false;      //!< \c isSaveSettings          \brief Auto Save
        bool                isTranslationError    = false;      //!< \c isTranslationError      \brief is Translation Error
        QString             myLanguages           = "";         //!< \c myLanguages             \brief Languages for checkboxes
        QString             myTranslationConf     = "";         //!< \c myTranslationConf       \brief Languages for Config
        QString             myTranslationQrc      = "";         //!< \c myTranslationQrc        \brief Translation qrc
        QString             myLanguageName        = "";         //!< \c myLanguageName          \brief Language Name
        QString             myCurrentLanguage     = "";         //!< \c myCurrentLanguage       \brief Current Language
        QString             myCurrentLanguageCode = "";         //!< \c myCurrentLanguage       \brief Current Language
        QString             myTranslation         = "";         //!< \c myTranslation           \brief Translation
        QString             myTranslationError    = "";         //!< \c myTranslationError      \brief Translation Error
        QString             myTranslationSource   = "";         //!< \c myTranslationSource     \brief Translation Source
        QString             myTransFilePrefix     = "";         //!< \c myTransFilePrefix       \brief Translation File Prefix
        QString             mySourceLanguage      = "";         //!< \c mySourceLanguage        \brief Source Language
        QList<MyLingoJobs>  myLingoJob;                         //!< \c myLingoJob              \brief Lingo Job
        QTranslator        *myTranslator;                       //!< \c myTranslator            \brief Translator
        QTranslator        *myLastTranslator = nullptr;         //!< \c myLastTranslator        \brief Last Translator
        int                 myLanguageCombBoxIndex = -1;        //!< \c myLanguageCombBoxIndex  \brief Language CombBox Index
        int                 myRecordID             = -1;        //!< \c myRecordID              \brief Record ID
};
#endif // MAINWINDOW_H
/******************************* End of File *********************************/
