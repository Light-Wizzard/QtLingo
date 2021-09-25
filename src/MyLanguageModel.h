#ifndef MyLanguageMODEL_H
#define MyLanguageMODEL_H

#include <QCoreApplication>
#include <QtDebug>
//#include <QDebug>
#include <QStringList>
#include <QListIterator>
#include <QStandardItemModel>
#include <QAbstractListModel>
#include <QDir>
#include <QFile>
#include <QMap>
#include <QObject>
#include <QPointer>
#include <QTimer>
#include <QTranslator>
#include <QVector>
// Qml
#ifdef MY_QML
    #include <QQmlEngine>
#else
    #include <QAbstractItemView>
    #include <QAbstractItemView>
    #include <QHeaderView>
    #include <QTableView>
#endif
//
//#include "MainWindow.h"
#include "ui_MainWindow.h"
//
#include "MyLanguageData.h"
#include "MyOrgSettings.h"
/************************************************
 * @brief Abstact Model used for ComboBox.
 * /class MyLanguageModel
 ***********************************************/
class MyLanguageModel : public QAbstractListModel
{
        Q_OBJECT
    public:
        enum ItemRoles
        {
            NameRole = Qt::UserRole + 1, //!< Name Role
            NameTranslatedRole           //!< Name Translated Role
        };
        //
        #ifdef MY_QML
        MyLanguageModel(QQmlEngine &thisQmlEngine, QObject *parent = nullptr); //!< My Abstact Model Constructor
        #else
        MyLanguageModel(QObject *parent = nullptr); //!< My Abstact Model Constructor
        #endif
        ~MyLanguageModel();  //!< Deconstructor
        //
        MyOrgSettings *mySetting;                       //!< \c mySetting            @brief my Setting
        // add Item
        Q_INVOKABLE void addItem(const QString &thisName, const QString &thisNameTranslated); //!< add Item
        void addItem(const MyLanguageData &thisItem);   //!< add Item
        // remove Item
        Q_INVOKABLE void removeItem(int thisRow);       //!< remove Item
        // row Count
        int rowCount(const QModelIndex & parent = QModelIndex()) const;             //!< row Count
        // data
        QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const; //!< data
        // Languages
        Q_INVOKABLE void setLanguages();                                //!< set Languages
        Q_INVOKABLE void setLanguage(const QString &thisLanguageName);  //!< load Language
        // Get TS and QM Files
        QStringList getTsFiles(const QString &thisFolder);               //!< get Ts Files
        QStringList getQmFiles(const QString &thisFolder);               //!< get Qm Files
        // Translation Source
        void setTranslationSource(const QString &thisTranslationSource); //!< set Translation Source
        QString getTranslationSource();                                  //!< get Translation Source
        // Translation File Prefix
        void setTransFilePrefix(const QString &thisTransFilePrefix);     //!< set TransFile Prefix
        QString getTransFilePrefix();                                    //!< get TransFile Prefix
        // Help Source
        void setHelpSource(const QString &thisHelpSource);               //!< set Help Source
        QString getHelpSource();                                         //!< get Help Source
        // Language Code
        void setLanguageCode(const QString &thisLanguageCode);           //!< set Language Code
        QString getLanguageCode();                                       //!< get Language Code
        // Language Name
        QString getLanguageName();                                       //!< get Language Name
        void setLanguageName(const QString &thisLanguageName);           //!< set Language Name
        // Default Language Name and Code
        QString getDefaultLanguageName();                                //!< get Default Lanuage Name
        QString getDefaultLanguageCode();                                //!< get Default Language Code
        // language Code To Name and Name to Code
        QString languageCodeToName(const QString &thisLangageCode);      //!< language Code To Name
        QString languageNameToCode(const QString &lang);                 //!< language Name to Code Added by Light-Wizzard
        // Localize File Utilities
        QString getLanguageFromFile(const QString &thisPrefix, const QString &thisQmLanguageFile); //!< get Language From File
        QString getLocalizerCode(const QString &thisPrefix, const QString &thisQmFile);            //!< get Localizer Code
        QString getLocalizedCodeFromFile(const QString &thisPrefix, const QString &thisQmFile);    //!< get Localized Code From File
        QString getLanguageFile(const QString &thisLanguageCode, const QString &thisPath, const QString &thisPrefix); //!< get Language File
        // languageMatch
        bool languageMatch(const QString &thisPrefix, const QString &thisLang, const QString &thisQmFile); //!< language Match
        // language
        QString language(const QLocale &thisLocale);     //!< language
        QString languageName(const QLocale &thisLocale); //!< language Name used for tr to translate all names
        // Language List
        Q_INVOKABLE void setLanguageList(const QStringList &thisLanguageList); //!< set Language List
        Q_INVOKABLE QStringList &getLanguageList();                            //!< get Language List
        // Is Debug Message
        void setDebugMessage(bool thisState);                       //!< set Debug Message
        bool getDebugMessage();                                     //!< get Debug Message
        // Main Loaded
        bool getMainLoaded();                                       //!< get Main Loaded
        void setMainLoaded(bool thisMainLoaded);                    //!< set Main Loaded
        // Language
        void readLanguage();                                        //!< read Language
        void writeLanguage();                                       //!< write Language
        // translate This
        QString translateThis(const QString &thisPhrase);           //!< translate This is required for Translation Files
        QString getLangCode(const QString &thisString);             //!< get Lang Code

    signals:
        void languageChanged();                   //!< language Changed Event

    protected:
        QHash<int, QByteArray> roleNames() const; //!< roleNames

    private:
        #ifdef MY_QML
        QQmlEngine   &myEngine;                         //!< \c myEngine             @brief Qml Engine
        #endif
        QList<MyLanguageData> myItems;                  //!< \c myItems              @brief my Items
        static const QMap<QString, QString>  s_genericLanguageCodeToName; //!< \c s_genericLanguageCodeToName @brief generic Language Code to Name
        static const QMap<QString, QString>  s_genericLanguageNameToCode; //!< \c s_genericLanguageNameToCode @brief generic Language Name to Code
        QTranslator  *myTranslator = nullptr;           //!< \c myTranslator         @brief Translator
        QString       myTranslationSource  = "";        //!< \c myTranslationSource  @brief Translation Source
        QString       myHelpSource         = "";        //!< \c myHelpSource         @brief Help Source
        QString       myTransFilePrefix    = "";        //!< \c myTransFilePrefix    @brief Translation File Prefix
        QString       myLanguageCode       = "";        //!< \c myLanguageCode       @brief Two Digit Language Code
        QString       myLanguageName       = "";        //!< \c myLanguageName       @brief Language Name
        QMap<QString, QString> myCurrentQmFiles;        //!< \c myCurrentQmFiles     @brief my Current Qm Files
        QStringList   myLanguages;                      //!< \c myLanguages          @brief my Languages
        bool          isDebugMessage       = false;     //!< \c isDebugMessage       @brief true of false for Debugging.
        bool          isMainLoaded         = false;     //!< \c isMainLoaded         @brief Set true after one shot time loads.
};
#endif // MyLanguageMODEL_H
/******************************* End of File *********************************/
