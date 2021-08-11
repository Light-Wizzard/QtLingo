#ifndef QT_LINGO_CONSTANTS_H
#define QT_LINGO_CONSTANTS_H
// Includes
#include <QObject>
#include <QtGlobal>
//
#define MY_CRYPTO_SEED (Q_UINT64_C(0x0c6add66acdcf066)) //!< \c MY_CRYPTO_SEED      \brief Ini File Name
#define VERSION "1.0"
/*! ***************************************************************************
   \fn class MyConstants
   \brief Constants are defined as const QString, starting with MY_ all capps
 *************************************************************************** */
class MyConstants
{
    public:
        // Constants
        const QString MY_INI_FILE          = "QtLingo.ini";         //!< \c MY_INI_FILE             \brief Ini File Name
        const QString MY_SQL_DEFAULT       = "QSQLITE";             //!< \c SQL_DEFAULT             \brief Default Sql Driver QSQLITE
        const QString MY_SQL_COMBO_INDEX   = "SqlComboBoxIndex";    //!< \c SQL_COMBO_INDEX         \brief Field Name for Sql ComboBox Index
        const QString MY_SQL_COMBO_VALUE   = "SqlComboBoxValue";    //!< \c SQL_COMBO_VALUE         \brief Field Name for Sql ComboBox Value
        const QString MY_SQL_COMBO_STATE   = "SqlComboBoxState";    //!< \c SQL_COMBO_STATE         \brief Field Name for Sql ComboBox State
        const QString MY_SQL_PROJECT_ID    = "ProjectID";           //!< \c SQL_PROJECT_ID          \brief Field Name for Project ID
        const QString MY_IS_DEBUG_MESSAGE  = "IsDebugMessage";      //!< \c MY_IS_DEBUG_MESSAGE     \brief Field Name for IsDebugMessage
        const QString MY_CURRENT_LANG_CODE = "CurrentLanguageCode"; //!< \c MY_CURRENT_LANG_CODE    \brief Field Name for Current Language Code
        //
        const QString MY_TRANSLATION_FOLDER         = "translations";      //!< \c MY_TRANSLATION_FOLDER        \brief Translation Folder
        const QString MY_TRANSLATION_PREFIX         = "QtLingo";           //!< \c MY_TRANSLATION_PREFIX        \brief Translation Prefix
        const QString MY_LANGUAGE_COMBO_STATE       = "CurrentLang";       //!< \c MY_LANGUAGE_COMBO_STATE      \brief Field Name for Language ComboBox State
        const QString MY_TRANS_ENGINE_GOOGLE_VALUE  = "TransEngineGooble"; //!< \c MY_TRANS_ENGINE_GOOGLE_VALUE \brief Field Name for Sql Translation Engine Value
        const QString MY_TRANS_ENGINE_BING_VALUE    = "TransEngineBing";   //!< \c MY_TRANS_ENGINE_BING_VALUE   \brief Field Name for Sql Translation Engine Value
        const QString MY_TRANS_ENGINE_YANDEX_VALUE  = "TransEngineYandex"; //!< \c MY_TRANS_ENGINE_COMBO_VALUE  \brief Field Name for Sql Translation Engine Value
        const QString MY_TRANS_DELAY_VALUE          = "TransEngineDelay";  //!< \c MY_TRANS_DELAY_VALUE         \brief Field Name for Sql Translation Engine Delay Value
        int MY_TRANS_DELAY                          = 3;                   //!< \c MY_TRANS_DELAY               \brief TRANS DELAY
        //
        const QString MY_QT_PROJECT_NAME     = "QtLingo";           //!< \c MY_QT_PROJECT_NAME    \brief Qt Project Name
        const QString MY_QT_PROJECT_FOLDER   = "QtLingo";           //!< \c MY_QT_PROJECT_FOLDER  \brief Qt Project Folder
        const QString MY_SOURCE_FOLDER       = "translations";      //!< \c MY_SOURCE_FOLDER      \brief Source Folder
        const QString MY_DESTINATION_FOLDER  = "translations";      //!< \c MY_DESTINATION_FOLDER \brief Destination folder
        const QString MY_SOURCE_LANGUAGE     = "English";           //!< \c MY_SOURCE_LANGUAGE    \brief Source Language
        const QString MY_MAKE                = "qmake";             //!< \c MY_MAKE               \brief Default Make Type: qmake or cmake
        const QString MY_LANGUAGE_IDs        = "en,de,fr,it,ja,zh,no,ru,sv,ar"; //!< \c MY_LANGUAGES_ID \brief Langages IDs
        const QString MY_LAST_PROJECT_FOLDER = "LastProjectFolder"; //!< \c MY_QT_PROJECT_NAME  \brief Field Name for Last Project folder
        // Sql Ini Variable Names Field Names
        const QString MY_SQL_DB_NAME   = "SqlDatabaseName";  //!< \c MY_SQL_DB_NAME   \brief SQL Ini Storage Field Name
        const QString MY_SQL_DB_TYPE   = "SqlDatabaseType";  //!< \c MY_SQL_DB_TYPE   \brief SQL Ini Storage Field Name
        const QString MY_SQL_DB_HOST   = "SqlDatabaseHost";  //!< \c MY_SQL_DB_HOST   \brief SQL Ini Storage Field Name
        const QString MY_SQL_DB_USER   = "SqlDatabaseUser";  //!< \c MY_SQL_DB_USER   \brief SQL Ini Storage Field Name
        const QString MY_SQL_DB_PASS   = "SqlDatabasePass";  //!< \c MY_SQL_DB_PASS   \brief SQL Ini Storage Field Name
        // Used in tr
        const char *MY_ERROR_MESSAGE_DB_RECORD_NOT_FOUND_1 = "Record not found in Database";
        const char *MY_ERROR_MESSAGE_DB_RECORD_NOT_FOUND_2 = "Record not found in Database for %1. Click Cancel to exit.";
        // My Org Settings Field Names
        const QString MY_APPLICATION_NAME   = "SettingsApplicationName"; //!< \c ConstSettingsApplicationName \brief QSettings Field Settings Application Name.
        const QString MY_ORG_NAME           = "SettingsOrgName";         //!< \c ConstSettingsOrgName         \brief QSettings Field Settings Org Name.
        const QString MY_ORG_DOMAIN         = "SettingsOrgDomain";       //!< \c ConstSettingsOrgDomain       \brief QSettings Field Settings Org Domain.
        const QString MY_GEOMETRY_POS       = "SettingsGeometryPos";     //!< \c ConstSettingsGeometryPos     \brief QSettings Field Settings Geometry Pos.
        const QString MY_GEOMETRY_SIZE      = "SettingsGeometrySize";    //!< \c ConstSettingsGeometrySize    \brief QSettings Field Settings Geometry Size.
        const QString MY_GEOMETRY_MAX       = "SettingsGeometryMax";     //!< \c ConstSettingsGeometryMax     \brief QSettings Field Settings Geometry Max.
        const QString MY_GEOMETRY_MIN       = "SettingsGeometryMin";     //!< \c ConstSettingsGeometryMin     \brief QSettings Field Settings Geometry Min.
        //
        const QString MY_APP_NAME_VALUE     = "QtLingo";              //!< \c ConstDefaultAppName          \brief Default App Name.
        // Change this value if you fork this Project, just make sure it points to a valid Repository
        const QString MY_ORG_NAME_VALUE     = "Light-Wizzard";           //!< \c ConstDefaultOrgName          \brief Default Org Name.
        // This is the User Name and Project or GitHub URL, but does not have to be
        const QString MY_DEFAULT_DOMAIN     = "https://github.com";      //!< \c ConstDefaultDomain      \brief Default Domain, This can be any URL.
        // "https://github.com/Light-Wizzard/QtLingo";
        const QString MY_DEFAULT_ORG_DOMAIN = MY_DEFAULT_DOMAIN + "/" + MY_ORG_NAME_VALUE + "/" + MY_APP_NAME_VALUE; //!< \c ConstDefaultOrgDomain \brief Default Org Domain.
};
#endif // QT_LINGO_CONSTANTS_H
/*** ************************* End of File ***********************************/
