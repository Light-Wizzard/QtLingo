#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QCloseEvent>
#include <QDir>
#include <QFile>
#include <QMainWindow>
#include <QMap>
#include <QObject>
#include <QPointer>
#include <QTimer>
#include <QTranslator>
#include <QVector>
#include <QtGlobal>
//
#include "MyConstants.h"
#include "MyDatatables.h"
#include "MyLanguageModel.h"
// QOnlineTranslator
#include "third-party/qonlinetranslator/src/qexample.h"
#include "third-party/qonlinetranslator/src/qoption.h"
#include "third-party/qonlinetranslator/src/qonlinetranslator.h"
//
#include "MyTranlatorParser.h"
//
namespace Ui { class MainWindow; }
//
#if Q_OS_MSDOS || defined(Q_OS_WIN32) || defined(Q_OS_WINCE)
    #define VERSION "1.0.0"
#else
    #define VERSION "1.0"
#endif
/************************************************
 * @brief My Lingo Jobs.
 * @param thisLanguageName    QString Full Name: English
 * @param thisLangName        QString Language code of file: en
 * @param thisTsFile          QString Full path to Translation File
 * @param thisDoxyFile QString Doxy File
 * @param thisReadMe          QString README_xx.md file
 * @param thisLang            QOnlineTranslator::Language Translate to
 * @param thisSourceLang      QOnlineTranslator::Language Translate from
 * @author Jeffrey Scott Flesher
 * MyLingoJobs
 ***********************************************/
class MyLingoJobs
{
    public:
        MyLingoJobs(const QString &thisLanguageName, const QString &thisLangName, const QString &thisTsFile, const QString &thisDoxyFile, const QString &thisReadMe, QOnlineTranslator::Language thisLang, QOnlineTranslator::Language thisSourceLang)
            : myLanguageName{thisLanguageName}, myLangName{thisLangName}, myTsFile{thisTsFile}, myDoxyFile{thisDoxyFile}, myReadMe{thisReadMe}, myLang{thisLang}, mySourceLang{thisSourceLang} {}
        // Getters
        QString getLanguageName()                   const { return myLanguageName;    }
        QString getLangName()                       const { return myLangName;        }
        QString getTsFile()                         const { return myTsFile;          }
        QString getDoxyFile()                       const { return myDoxyFile;        }
        QString getReadMe()                         const { return myReadMe;          }
        QOnlineTranslator::Language getLang()       const { return myLang;            }
        QOnlineTranslator::Language getSourceLang() const { return mySourceLang;      }
        // Setters
        void setLanguageName(const QString &s)            { myLanguageName    = s; }
        void setLangName(const QString &s)                { myLangName        = s; }
        void setTsFile(const QString &s)                  { myTsFile          = s; }
        void setDoxyFile(const QString &s)                { myDoxyFile        = s; }
        void setReadMe(const QString &s)                  { myReadMe          = s; }
        void setSourceLang(QOnlineTranslator::Language s) { mySourceLang      = s; }
        void setLang(QOnlineTranslator::Language s)       { myLang            = s; }

    private:
        QString myLanguageName, myLangName, myTsFile, myDoxyFile, myReadMe;
        QOnlineTranslator::Language myLang, mySourceLang;
};
/************************************************
 * @brief Main Window Constructor.
 * /class MainWindow
 * @author Jeffrey Scott Flesher
 ***********************************************/
class MainWindow : public QMainWindow
{
        Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = nullptr);
        ~MainWindow();
        /*!
            @brief Tabs must be forced to be int 0 based indexes that match the actual ui for widgetTab, this enforces compile-time checks.
            \enum MainTabs
         */
        enum MainTabs
        {
            TabSettings     = 0,  //!< \c TabSettings     @brief Tab Settings.
            TabSql          = 1,  //!< \c TabSql          @brief Tab SQL
            TabTranslations = 2,  //!< \c TabTranslations @brief Tab Ubuntu.
            TabProject      = 3,  //!< \c TabProject      @brief Tab Project.
            TabTabHelp      = 4,  //!< \c TabHelp         @brief Tab Help.
            TabAll          = 9   //!< \c TabAll          @brief Tab All used for Actions on all Tabs.
        }; // end enum MainTabs
        Q_ENUM(MainTabs)
        /*!
            @brief Translations Errors.
            \enum TranslationsErrors
         */
        enum TranslationsErrors
        {
            NoError           = 100,  //!< \c NoError           @brief No Error.
            HostNotFound      = 101,  //!< \c HostNotFound      @brief Host Not Found: Internet Down, wait till it comes back up.
            ErrorTransferring = 102   //!< \c ErrorTransferring @brief Error Transferring: server replied: Too Many Requests, increase Delay time.
        }; // end enum TranslationsErrors
        Q_ENUM(TranslationsErrors)
        /*!
            \enum MyMessageTypes
            @brief Message Types
         */
        enum MyMessageTypes
        {
            Information = 100, //!< \c Information  @brief Information
            Warning     = 101, //!< \c Warning      @brief Warning
            Critical    = 102, //!< \c Critical     @brief Critical
            Debug       = 103  //!< \c Debug        @brief Debug
        }; // end enum MyMessageTypes
        // Makes Messaging easier
        Q_ENUM(MyMessageTypes)
        /*!
            @brief Action States Manager.
            \enum ActionStatesManager
         */
        enum ActionStatesManager
        {
            Translations      = 100,  //!< \c Translations      @brief Translations On Compile.
            TranslationHelp   = 101,  //!< \c TranslationHelp   @brief Translation Help
            TranslationReadMe = 102   //!< \c TranslationReadMe @brief Translation ReadMe.
        }; // end enum ActionStatesManager
        Q_ENUM(ActionStatesManager)
        //
        MyConstants *myConstants;                       //!< \c myConstants @brief All Constants in one class
        //
        void onRunFirstOnStartup();                     //!< on Run First On Startup
        //
        void loadQtProjectCombo();                       //!< set Qt Project Combo
        // Read
        void readAllSettings();                         //!< read Settings
        void readStatesChanges();                       //!< read States Changes
        void readSqlDatabaseInfo();                     //!< read SQL Database Info
        // Write
        void writeAllSettings();                        //!< write Settings
        void writeStateChanges();                       //!< write State Changes
        void writeSqlDatabaseInfo();                    //!< write SQL Database Info
        //
        void setSqlBrowseButton();                      //!< set SQL Browse Button
        //
        bool fillForms(const QString &thisProjectID);   //!< fill Forms
        //
        void clearForms(int tabNumber);                 //!< clear Forms
        void clearTabSettings();                        //!< clear Tab Settings
        void clearTabHelp();                            //!< clear Tab Help
        void clearTabTranslations();                    //!< clear Tab Translations
        void clearTabProject();                         //!< clear Tab Project
        void checkLanguage(const QString &thisName, const QString &thisLanguage, bool thisChecked); //!< check Language
        QString languageChecked();                      //!< language Checked
        void setProjectClass(int tabNumber);            //!< set Project Class
        void createTranslationJob(const QString &thisTranslate, const QString &thisLangCode, const QString &thisSourceLanguage, bool thisChecked); //!< get Translation String
        void setPrograms();                             //!< set Programs
        // Is Debug Message
        void setDebugMessage(bool thisState);           //!< set Debug Message
        bool getDebugMessage();                         //!< get Debug Message
        void retranslate();                             //!< retranslate none designer components
        void loadLanguageComboBox();                    //!< load Language ComboBox
        void loadLanguageComboBoxSource();              //!< load Language ComboBox Source
        void readSettingsFirst();                       //!< read Settings First
        void setMessagingStates(bool thisMessageState); //!< set Messaging States
        // Set Tabs
        void setTabSettings();                          //!< set Tab Settings
        void setTabTranslations();                      //!< set Tab Translations
        void setTabAll();                               //!< set Tab All
        //
        QString translateWithReturn(const QString &text, QOnlineTranslator::Engine engine, QOnlineTranslator::Language translationLang, QOnlineTranslator::Language sourceLang, QOnlineTranslator::Language uiLang); //!< translate With Return, note this is blocking
        QString checkTranslationErrors(const QString &thisTranslations, const QString &thisText, QOnlineTranslator::Engine thisEngine, QOnlineTranslator::Language thisTranslationLang, QOnlineTranslator::Language thisSourceLang, QOnlineTranslator::Language thisUiLang); //!< check Translation Errors
        void setTranslationErrorType(const QString &thisTranslations); //!< set Translation Error Type
        void createHelpTranslationJob(const QString &thisLanguageName, const QString &thisLangCode, bool thisChecked); //!< create Help Translation Job
        void setLanguageCode();                         //!< set Language Code Lable in UI
        void acceptTranslations();                      //!< accept Translations
        void createReadMeTranslationJob(const QString &thisLanguageName, const QString &thisLangCode, bool thisChecked); //!< create ReadMe Translation Job
        void closeTransHelp();                          //!< close Trans Help
        void setMessage(const QString &thisMessage, MainWindow::MyMessageTypes thisMessageType); //!< set Message
        void setActionsDisabled(ActionStatesManager thisAction, bool thisState); //!< set Actions Disabled
        void setMainLoaded(bool thisState);                             //!< set Main Loaded
        void setCheckMarksTranslation(const QString &thisDbValve);      //!< set Check Marks Translation

        QString getComboBoxProjectsID(int thisIndex);                   //!< get ComboBox Projects ID

        void loadLanguage(const QString &thisLanguage);                 //!< loadLanguage

        void setLastLanguageName(const QString &thisLastLanguageName);  //!< setLastLanguageName
        QString getLastLanguageName();                                  //!< getLastLanguageName
        void setDatabaseModel();                                        //!< setDatabaseModel

        void setLanguageModel(MyLanguageModel *thisLanguageModel);      //!< set Language Model

        bool getMainLoaded(); //!<
        void removeArgs(const QString &thisString, const QString &thisTransFile); //!<
        void fileRemoveArgs(); //!<
        void fixTranslationFile(const QString &thisFile); //!<

    public slots:
        void onHelp();                                  //!< on Help
        void onAbout();                                 //!< on About
        void onClipboard();                             //!< on Clipboard
        void onCompile();                               //!< on Compile
        void onAuthor();                                //!< on Author
        void onSave();                                  //!< on Save
        void onInternetProgress();                      //!< on Internet Progress
        // Translate Help
        void onTranslateHelp();                         //!< translate Help Files
        void onTranslateReadMe();                       //!< Translate ReadMe

    private slots:
        // ComboBoxes
        void on_comboBoxTranslationsProjectNames_currentIndexChanged(int thisIndex);                    //!< on comboBox Settings Projects current Index Changed
        void on_comboBoxLanguage_currentIndexChanged(const QString &thisLanguage);          //!< on comboBox Language current Index Changed
        void on_comboBoxSqlDatabaseType_currentIndexChanged(const QString &thisSqlType);    //!< on comboBox SQL Database Type current Index Changed
        void on_comboBoxTranslationSourceLanguage_currentIndexChanged(const QString &arg1); //!< on comboBox Translation Source Language current Index Changed
        // Push Buttons Settings
        void on_pushButtonSettingsLupdate_clicked();
        void on_pushButtonSettingsLrelease_clicked();
        // Push Buttons SQL
        void on_pushButtonSqlDatabaseNameBrowse_clicked();                                  //!< on pushButton SQL Database Name Browse clicked
        void on_pushButtonSqlPasswordShow_clicked();                                        //!< on pushButton SQL Password Show clicked
        void on_pushButtonSqlSave_clicked();                                                //!< on pushButton SQL Save clicked
        // Push Buttons Translations
        void on_pushButtonTranslationsAdd_clicked();                                        //!< on pushButton Translations Add clicked
        void on_pushButtonTranslationsSave_clicked();                                       //!< on pushButton Translations Save clicked
        void on_pushButtonTranslationsDelete_clicked();                                     //!< on pushButton Translations Delete clicked
        void on_pushButtonTranslationsProjectsBrowser_clicked();                            //!< on pushButton Translations Projects Browser clicked
        void on_pushButtonTranslationsSourceBrowse_clicked();                               //!< on pushButton Translations Source Browse clicked
        void on_pushButtonTranslationsDoxyfileBrowse_clicked();                             //!< on pushButton Translations Doxyfile Browse clicked
        void on_pushButtonTranslationsProjectFolderBrowse_clicked();                        //!< on pushButton Translations ProjectFolder Browse clicked
        void on_pushButtonTranslationsHelp_clicked();                                       //!< on pushButton Translations Help clicked
        void on_pushButtonTranslationsClear_clicked();                                      //!< on pushButton Translations Clear clicked
        // Checkboxes Settings
        void on_checkBoxSettingsGoogle_stateChanged(int thisArg);                           //!< on checkBox Settings Google state Changed
        void on_checkBoxSettingsBing_stateChanged(int thisArg);                             //!< on checkBox Settings Bing state Changed
        void on_checkBoxSettingsYandex_stateChanged(int thisArg);                           //!< on checkBox Settings Yandex state Changed
        void on_checkBoxSettignsMessaging_stateChanged(int thisCheckState);                 //!< on checkBox Settigns Messaging state Changed
        // Tab
        void on_tabWidget_currentChanged(int index);                                        //!< on tabWidget current Changed


    protected:
        void closeEvent(QCloseEvent *event) override;           //!< close Event

    protected slots:
        virtual void changeEvent(QEvent * event) override;      //!< change Event

    private:
        Ui::MainWindow     *ui;                                 //!< \c ui                      @brief ui.
        MyDatatables       *myDbModel;                          //!< \c myDbModel               @brief SQL Datatables Model.
        MyLanguageModel    *myLanguageModel;                    //!< \c myLanguageModel         @brief Localization Model.
        MyTranlatorParser  *myTranlatorParser;                  //!< \c myDelayValue            @brief Delay Value.
        QOnlineTranslator   myQOnlineTranslator;                //!< \c myQOnlineTranslator     @brief QOnlineTranslator.
        QClipboard         *clipboard;                          //!< \c clipboard               @brief clipboard.
        QString             myLanguages           = "";         //!< \c myLanguages             @brief Languages for checkboxes.
        QString             myTranslationConf     = "";         //!< \c myTranslationConf       @brief Languages for Config.
        QString             myTranslationQrc      = "";         //!< \c myTranslationQrc        @brief Translation qrc.
        QString             myLanguageName        = "";         //!< \c myLanguageName          @brief Language Name.
        QString             myCurrentLanguage     = "";         //!< \c myCurrentLanguage       @brief Current Language.
        QString             myTranslation         = "";         //!< \c myTranslation           @brief Translation.
        QString             myTranslationError    = "";         //!< \c myTranslationError      @brief Translation Error.
        QString             mySourceLanguage      = "";         //!< \c mySourceLanguage        @brief Source Language.
        QString             myLastLanguageName    = "";         //!< \c myLastLanguageName      @brief Last Language Name
        QString             myUiLanguageName      = "";         //!< \c myUiLanguageName        @brief UI Language Name.
        QString             myRemoveTransArgs;                  //!< \c myRemoveTransArgs       @brief List of Remove Trans Args
        QList<MyLingoJobs>  myLingoJob;                         //!< \c myLingoJob              @brief Lingo Job.
        QStringList         myHelpTranslationsFiles;            //!< \c myHelpTranslationsFiles @brief Help Translations Files
        QStringList         myHelpFileNames;                    //!< \c myHelpFileNames         @brief Help File Names
        bool                isDebugMessage        = true;       //!< \c isDebugMessage          @brief true of false for Debugging.
        bool                isTranslationLog      = false;      //!< \c isTranslationLog        @brief true of false for Info during Translation.
        bool                isMainLoaded          = false;      //!< \c isMainLoaded            @brief Set true after one shot time loads.
        bool                isQtSettingsLoaded    = false;      //!< \c isQtSettingsLoaded      @brief is Qt Settings Loaded.
        bool                isSaveSettings        = false;      //!< \c isSaveSettings          @brief Auto Save.
        bool                isTranslationError    = false;      //!< \c isTranslationError      @brief is Translation Error.
        int                 myLanguageCombBoxIndex = -1;        //!< \c myLanguageCombBoxIndex  @brief Language CombBox Index.
        int                 myRecordID             = -1;        //!< \c myRecordID              @brief Record ID.
        int                 myTranslationErrorType = -1;        //!< \c myTranslationErrorType  @brief Translation Error Type.
        int                 myIncreameantValue     = 60;        //!< \c myIncreameantValue      @brief Increameant Value in Seconds.
        int                 myDelayValue           = 60*6;      //!< \c myIncreameantValue      @brief Increameant Value in Seconds.
};
#endif // MAINWINDOW_H
/******************************* End of File *********************************/
