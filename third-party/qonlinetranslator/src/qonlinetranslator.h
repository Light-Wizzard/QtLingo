/*
 *  Copyright © 2018-2021 Hennadii Chernyshchyk <genaloner@gmail.com>
 *
 *  This file is part of QOnlineTranslator.
 *
 *  QOnlineTranslator is free library; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a get of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef QONLINETRANSLATOR_H
#define QONLINETRANSLATOR_H

#include <QMap>
#include <QPointer>
#include <QVector>
#include <QtGlobal>
#include <QCoreApplication>
#include <QFinalState>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMediaPlayer>
#include <QNetworkReply>
#include <QStateMachine>
#include <QMediaContent>

#include "qexample.h"
#include "qoption.h"

class QStateMachine;
class QState;
class QNetworkAccessManager;
class QNetworkReply;
/*! ***************************************************************************
   \class QOnlineTranslator
   \brief QOnlineTranslator
 *************************************************************************** */
class QOnlineTranslator : public QObject
{
        Q_OBJECT
        Q_DISABLE_COPY(QOnlineTranslator)

        friend class QOnlineTts; //!< QOnlineTts

    public:
        /* QOnlineTranslator::Language */
        enum Language
        {
            NoLanguage = -1,        //!< \c NoLanguage          \brief NoLanguage
            Auto,                   //!< \c Auto                \brief Auto
            Afrikaans,              //!< \c Afrikaans           \brief Afrikaans
            Albanian,               //!< \c Albanian            \brief Albanian
            Amharic,                //!< \c Amharic             \brief Amharic
            Arabic,                 //!< \c Arabic              \brief Arabic
            Armenian,               //!< \c Armenian            \brief Armenian
            Azerbaijani,            //!< \c Azerbaijani         \brief Azerbaijani
            Bashkir,                //!< \c Bashkir             \brief Bashkir
            Basque,                 //!< \c Basque              \brief Basque
            Belarusian,             //!< \c Belarusian          \brief Belarusian
            Bengali,                //!< \c Bengali             \brief Bengali
            Bosnian,                //!< \c Bosnian             \brief Bosnian
            Bulgarian,              //!< \c Bulgarian           \brief Bulgarian
            Cantonese,              //!< \c Cantonese           \brief Cantonese
            Catalan,                //!< \c Catalan             \brief Catalan
            Cebuano,                //!< \c Cebuano             \brief Cebuano
            Chichewa,               //!< \c Chichewa            \brief Chichewa
            Corsican,               //!< \c Corsican            \brief Corsican
            Croatian,               //!< \c Croatian            \brief Croatian
            Czech,                  //!< \c Czech               \brief Czech
            Danish,                 //!< \c Danish              \brief Danish
            Dutch,                  //!< \c Dutch               \brief Dutch
            English,                //!< \c English             \brief English
            Esperanto,              //!< \c Esperanto           \brief Esperanto
            Estonian,               //!< \c Estonian            \brief Estonian
            Fijian,                 //!< \c Fijian              \brief Fijian
            Filipino,               //!< \c Filipino            \brief Filipino
            Finnish,                //!< \c Finnish             \brief Finnish
            French,                 //!< \c French              \brief French
            Frisian,                //!< \c Frisian             \brief Frisian
            Galician,               //!< \c Galician            \brief Galician
            Georgian,               //!< \c Georgian            \brief Georgian
            German,                 //!< \c German              \brief German
            Greek,                  //!< \c Greek               \brief Greek
            Gujarati,               //!< \c Gujarati            \brief Gujarati
            HaitianCreole,          //!< \c HaitianCreole       \brief HaitianCreole
            Hausa,                  //!< \c Hausa               \brief Hausa
            Hawaiian,               //!< \c Hawaiian            \brief Hawaiian
            Hebrew,                 //!< \c Hebrew              \brief Hebrew
            HillMari,               //!< \c HillMari            \brief HillMari
            Hindi,                  //!< \c Hindi               \brief Hindi
            Hmong,                  //!< \c Hmong               \brief Hmong
            Hungarian,              //!< \c Hungarian           \brief Hungarian
            Icelandic,              //!< \c Icelandic           \brief Icelandic
            Igbo,                   //!< \c Igbo                \brief Igbo
            Indonesian,             //!< \c Indonesian          \brief Indonesian
            Irish,                  //!< \c Irish               \brief Irish
            Italian,                //!< \c Italian             \brief Italian
            Japanese,               //!< \c Japanese            \brief Japanese
            Javanese,               //!< \c Javanese            \brief Javanese
            Kannada,                //!< \c Kannada             \brief Kannada
            Kazakh,                 //!< \c Kazakh              \brief Kazakh
            Khmer,                  //!< \c Khmer               \brief Khmer
            Kinyarwanda,            //!< \c Kinyarwanda         \brief Kinyarwanda
            Klingon,                //!< \c Klingon             \brief Klingon
            KlingonPlqaD,           //!< \c KlingonPlqaD        \brief KlingonPlqaD
            Korean,                 //!< \c Korean              \brief Korean
            Kurdish,                //!< \c Kurdish             \brief Kurdish
            Kyrgyz,                 //!< \c Kyrgyz              \brief Kyrgyz
            Lao,                    //!< \c Lao                 \brief Lao
            Latin,                  //!< \c Latin               \brief Latin
            Latvian,                //!< \c Latvian             \brief Latvian
            LevantineArabic,        //!< \c LevantineArabic     \brief LevantineArabic
            Lithuanian,             //!< \c Lithuanian          \brief Lithuanian
            Luxembourgish,          //!< \c Luxembourgish       \brief Luxembourgish
            Macedonian,             //!< \c Macedonian          \brief Macedonian
            Malagasy,               //!< \c Malagasy            \brief Malagasy
            Malay,                  //!< \c Malay               \brief Malay
            Malayalam,              //!< \c Malayalam           \brief Malayalam
            Maltese,                //!< \c Maltese             \brief Maltese
            Maori,                  //!< \c Maori               \brief Maori
            Marathi,                //!< \c Marathi             \brief Marathi
            Mari,                   //!< \c Mari                \brief Mari
            Mongolian,              //!< \c Mongolian           \brief Mongolian
            Myanmar,                //!< \c Myanmar             \brief Myanmar
            Nepali,                 //!< \c Nepali              \brief Nepali
            Norwegian,              //!< \c Norwegian           \brief Norwegian
            Oriya,                  //!< \c Oriya               \brief Oriya
            Papiamento,             //!< \c Papiamento          \brief Papiamento
            Pashto,                 //!< \c Pashto              \brief Pashto
            Persian,                //!< \c Persian             \brief Persian
            Polish,                 //!< \c Polish              \brief Polish
            Portuguese,             //!< \c Portuguese          \brief Portuguese
            Punjabi,                //!< \c Punjabi             \brief Punjabi
            QueretaroOtomi,         //!< \c QueretaroOtomi      \brief QueretaroOtomi
            Romanian,               //!< \c Romanian            \brief Romanian
            Russian,                //!< \c Russian             \brief Russian
            Samoan,                 //!< \c Samoan              \brief Samoan
            ScotsGaelic,            //!< \c ScotsGaelic         \brief ScotsGaelic
            SerbianCyrillic,        //!< \c SerbianCyrillic     \brief SerbianCyrillic
            SerbianLatin,           //!< \c SerbianLatin        \brief SerbianLatin
            Sesotho,                //!< \c Sesotho             \brief Sesotho
            Shona,                  //!< \c Shona               \brief Shona
            SimplifiedChinese,      //!< \c SimplifiedChinese   \brief SimplifiedChinese
            Sindhi,                 //!< \c Sindhi              \brief Sindhi
            Sinhala,                //!< \c Sinhala             \brief Sinhala
            Slovak,                 //!< \c Slovak              \brief Slovak
            Slovenian,              //!< \c Slovenian           \brief Slovenian
            Somali,                 //!< \c Somali              \brief Somali
            Spanish,                //!< \c Spanish             \brief Spanish
            Sundanese,              //!< \c Sundanese           \brief Sundanese
            Swahili,                //!< \c Swahili             \brief Swahili
            Swedish,                //!< \c Swedish             \brief Swedish
            Tagalog,                //!< \c Tagalog             \brief Tagalog
            Tahitian,               //!< \c Tahitian            \brief Tahitian
            Tajik,                  //!< \c Tajik               \brief Tajik
            Tamil,                  //!< \c Tamil               \brief Tamil
            Tatar,                  //!< \c Tatar               \brief Tatar
            Telugu,                 //!< \c Telugu              \brief Telugu
            Thai,                   //!< \c Thai                \brief Thai
            Tongan,                 //!< \c Tongan              \brief Tongan
            TraditionalChinese,     //!< \c TraditionalChinese  \brief TraditionalChinese
            Turkish,                //!< \c Turkish             \brief Turkish
            Turkmen,                //!< \c Turkmen             \brief Turkmen
            Udmurt,                 //!< \c Udmurt              \brief Udmurt
            Uighur,                 //!< \c Uighur              \brief Uighur
            Ukrainian,              //!< \c Ukrainian           \brief Ukrainian
            Urdu,                   //!< \c Urdu                \brief Urdu
            Uzbek,                  //!< \c Uzbek               \brief Uzbek
            Vietnamese,             //!< \c Vietnamese          \brief Vietnamese
            Welsh,                  //!< \c Welsh               \brief Welsh
            Xhosa,                  //!< \c Xhosa               \brief Xhosa
            Yiddish,                //!< \c Yiddish             \brief Yiddish
            Yoruba,                 //!< \c Yoruba              \brief Yoruba
            YucatecMaya,            //!< \c YucatecMaya         \brief YucatecMaya
            Zulu                    //!< \c Zulu                \brief Zulu
        };
        Q_ENUM(Language)

        enum Engine
        {
            Google, //!< \c Google  \brief Google
            Yandex, //!< \c Yandex  \brief Yandex
            Bing    //!< \c Bing    \brief Bing
        };
        Q_ENUM(Engine)

        enum TranslationError
        {
            NoError,         //!< \c NoError            \brief No Error
            ParametersError, //!< \c ParametersError    \brief Parameters Error
            NetworkError,    //!< \c NetworkError       \brief Network Error
            ServiceError,    //!< \c ServiceError       \brief Service Error
            ParsingError     //!< \c ParsingError       \brief Parsing Error
        };

        explicit QOnlineTranslator(QObject *parent = nullptr); //!< QOnlineTranslator

        void translate(const QString &text, Engine engine = Google, Language translationLang = Auto, Language sourceLang = Auto, Language uiLang = Auto); //!< translate
        //
        void detectLanguage(const QString &text, Engine engine = Google); //!< detect Language

        void abort();                                                   //!< abort
        bool isRunning() const;                                         //!< is Running

        QJsonDocument toJson() const;                                   //!< to Json
        QString source() const;                                         //!< source
        QString sourceTranslit() const;                                 //!< source Translit
        QString sourceTranscription() const;                            //!< source Transcription
        QString sourceLanguageName() const;                             //!< source Language Name
        Language sourceLanguage() const;                                //!< source Language

        QString translation() const;                                    //!< translation
        QString translationTranslit() const;                            //!< translation Translit
        QString translationLanguageName() const;                        //!< translation Language Name
        Language translationLanguage() const;                           //!< translation Language

        QMap<QString, QVector<QOption>> translationOptions() const;     //!< translation Options
        QMap<QString, QVector<QExample>> examples() const;              //!< examples

        TranslationError error() const;                                 //!< error
        QString errorString() const;                                    //!< error String

        bool isSourceTranslitEnabled() const;                           //!< is Source Translit Enabled
        void setSourceTranslitEnabled(bool enable);                     //!< set Source Translit Enabled

        bool isTranslationTranslitEnabled() const;                      //!< is Translation Translit Enabled
        void setTranslationTranslitEnabled(bool enable);                //!< set Translation Translit Enabled

        bool isSourceTranscriptionEnabled() const;                      //!< is Source Transcription Enabled
        void setSourceTranscriptionEnabled(bool enable);                //!< set Source Transcription Enabled

        bool isTranslationOptionsEnabled() const;                       //!< is Translation Options Enabled
        void setTranslationOptionsEnabled(bool enable);                 //!< set Translation Options Enabled

        bool isExamplesEnabled() const;                                 //!< is Examples Enabled
        void setExamplesEnabled(bool enable);                           //!< set Examples Enabled

        static QString languageName(Language lang);                     //!< language Name
        QString languageName(const QString &lang);                      //!< language Name
        static QString languageCode(Language lang);                     //!< language Code
        static Language language(const QLocale &locale);                //!< language
        static Language language(const QString &langCode);              //!< language
        static bool isSupportTranslation(Engine engine, Language lang); //!< is Support Translation
        // Added by Light-Wizzard
        QString languageNameToCode(const QString &lang);                //!< language Name to Code Added by Light-Wizzard
        QString languageCodeToName(const QString &lang);                //!< language Code to Name Added by Light-Wizzard

    signals:
        void finished();                            //!< finished

    private slots:
        void skipGarbageText();                     //!< skip Garbage Text

        // Google
        void requestGoogleTranslate();              //!< request Google Translate
        void parseGoogleTranslate();                //!< parse Google Translate

        // Yandex
        void requestYandexKey();                    //!< request Yandex Key
        void parseYandexKey();                      //!< parse Yandex Key

        void requestYandexTranslate();              //!< request Yandex Translate
        void parseYandexTranslate();                //!< parse Yandex Translate

        void requestYandexSourceTranslit();         //!< request Yandex Source Translit
        void parseYandexSourceTranslit();           //!< parse Yandex Source Translit

        void requestYandexTranslationTranslit();    //!< request Yandex Translation Translit
        void parseYandexTranslationTranslit();      //!< parse Yandex Translation Translit

        void requestYandexDictionary();             //!< request Yandex Dictionary
        void parseYandexDictionary();               //!< parse Yandex Dictionary

        // Bing
        void requestBingCredentials();              //!< request Bing Credentials
        void parseBingCredentials();                //!< parse Bing Credentials

        void requestBingTranslate();                //!< request Bing Translate
        void parseBingTranslate();                  //!< parse Bing Translate

        void requestBingDictionary();               //!< request Bing Dictionary
        void parseBingDictionary();                 //!< parse Bing Dictionary

    private:
    /*
     * Engines have translation limit, so need to split all text into parts and make request sequentially.
     * Also Yandex and Bing requires several requests to get dictionary, transliteration etc.
     * We use state machine to rely async computation with signals and slots.
     */
        void buildGoogleStateMachine();         //!< build Google State Machine
        void buildGoogleDetectStateMachine();   //!< build Google Detect State Machine

        void buildYandexStateMachine();         //!< build Yandex State Machine
        void buildYandexDetectStateMachine();   //!< build Yandex Detect State Machine

        void buildBingStateMachine();           //!< build Bing State Machine
        void buildBingDetectStateMachine();     //!< build Bing Detect State Machine

        // Helper functions to build nested states
        void buildSplitNetworkRequest(QState *parent, void (QOnlineTranslator::*requestMethod)(), void (QOnlineTranslator::*parseMethod)(), const QString &text, int textLimit); //!< build Split Network Request
        void buildNetworkRequestState(QState *parent, void (QOnlineTranslator::*requestMethod)(), void (QOnlineTranslator::*parseMethod)(), const QString &text = {});           //!< build Network Request State

        // Helper functions for transliteration
        void requestYandexTranslit(Language language);  //!< request Yandex Translit
        void parseYandexTranslit(QString &text);        //!< parse Yandex Translit

        void resetData(TranslationError error = NoError, const QString &errorString = {}); //!< reset Data

        // Check for service support
        static bool isSupportTranslit(Engine engine, Language lang); //!< isSupportTranslit
        static bool isSupportDictionary(Engine engine, Language sourceLang, Language translationLang); //!< is Support Dictionary

        // Other
        static QString languageApiCode(Engine engine, Language lang);           //!< language Api Code
        static Language language(Engine engine, const QString &langCode);       //!< language
        static int getSplitIndex(const QString &untranslatedText, int limit);   //!< get Split Index
        static bool isContainsSpace(const QString &text);                       //!< is Contains Space
        static void addSpaceBetweenParts(QString &text);                        //!< add Space Between Parts

        static const QMap<Language, QString> s_genericLanguageCodes;      //!< \c s_genericLanguageCodes \brief generic Language Codes
        static const QMap<QString, QString> s_genericLanguageNameToCode;  //!< \c s_genericLanguageNameToCode \brief generic Language Name to Code
        static const QMap<QString, QString> s_genericLanguageCodeToName;  //!< \c s_genericLanguageCodeToName \brief generic Language Code to Name

        // Engines have some language codes exceptions
        static const QMap<Language, QString> s_googleLanguageCodes; //!< \c s_googleLanguageCodes   \brief google Language Codes
        static const QMap<Language, QString> s_yandexLanguageCodes; //!< \c s_yandexLanguageCodes   \brief yandex Language Codes
        static const QMap<Language, QString> s_bingLanguageCodes;   //!< \c s_bingLanguageCodes     \brief bing Language Codes

        // Credentials that is parsed from the web version to receive the translation using the API
        static inline QString    s_yandexKey;   //!< \c s_yandexKey \brief yandex Key
        static inline QByteArray s_bingKey;     //!< \c s_bingKey   \brief bing Key
        static inline QByteArray s_bingToken;   //!< \c s_bingToken \brief bing Token

        // This properties used to store unseful information in states
        static constexpr char s_textProperty[] = "Text"; //!< \c s_textProperty  \brief text Property

        // Engines have a limit of characters per translation request.
        // If the query is larger, then it should be splited into several with getSplitIndex() helper function
        static constexpr int s_googleTranslateLimit = 5000; //!< \c s_googleTranslateLimit  \brief google Translate Limit
        static constexpr int s_yandexTranslateLimit = 150;  //!< \c s_yandexTranslateLimit  \brief yandex Translate Limit
        static constexpr int s_yandexTranslitLimit  = 180;  //!< \c s_yandexTranslitLimit   \brief yandex Translit Limit
        static constexpr int s_bingTranslateLimit   = 5001; //!< \c s_bingTranslateLimit    \brief bing Translate Limit

        QStateMachine          *m_stateMachine;     //!< \c m_stateMachine      \brief state Machine
        QNetworkAccessManager  *m_networkManager;   //!< \c m_networkManager    \brief network Manager
        QPointer<QNetworkReply> m_currentReply;     //!< \c m_currentReply      \brief current Reply

        Language m_sourceLang      = NoLanguage;    //!< \c m_sourceLang        \brief Source Text to Translates Source Language
        Language m_translationLang = NoLanguage;    //!< \c m_translationLang   \brief Translation Language
        Language m_uiLang          = NoLanguage;    //!< \c m_uiLang            \brief ui Lang
        TranslationError m_error   = NoError;       //!< \c m_error             \brief error

        QString m_source;               //!< \c m_source                \brief Source Text to Translate
        QString m_sourceTranslit;       //!< \c m_sourceTranslit        \brief source Translit
        QString m_sourceTranscription;  //!< \c m_sourceTranscription   \brief source Transcription
        QString m_translation;          //!< \c m_translation           \brief translation
        QString m_translationTranslit;  //!< \c m_translationTranslit   \brief translation Translit
        QString m_errorString;          //!< \c m_errorString           \brief error String

        QMap<QString, QVector<QOption>>  m_translationOptions;   //!< \c m_translationOptions \brief translation Options
        QMap<QString, QVector<QExample>> m_examples;             //!< \c m_examples           \brief examples

        bool m_sourceTranslitEnabled      = true; //!< \c m_sourceTranslitEnabled       \brief source Translit Enabled
        bool m_translationTranslitEnabled = true; //!< \c m_translationTranslitEnabled  \brief translation Translit Enabled
        bool m_sourceTranscriptionEnabled = true; //!< \c m_sourceTranscriptionEnabled  \brief source Transcription Enabled
        bool m_translationOptionsEnabled  = true; //!< \c m_translationOptionsEnabled   \brief translation Options Enabled
        bool m_examplesEnabled            = true; //!< \c m_examplesEnabled             \brief examples Enabled
        bool m_onlyDetectLanguage         = false; //!< \c m_onlyDetectLanguage         \brief only Detect Language

}; // end class QOnlineTranslator
#endif // QONLINETRANSLATOR_H
/******************************* End of File *********************************/
