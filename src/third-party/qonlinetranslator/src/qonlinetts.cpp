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

#include "qonlinetts.h"

/************************************************
 * @brief  emotion Codes.
 * s_emotionCodes
 ***********************************************/
const QMap<QOnlineTts::Emotion, QString> QOnlineTts::s_emotionCodes =
{
    {Neutral, QStringLiteral("neutral")},
    {Good,    QStringLiteral("good")},
    {Evil,    QStringLiteral("evil")}
};
/************************************************
 * @brief  voice Codes.
 * s_voiceCodes
 ***********************************************/
const QMap<QOnlineTts::Voice, QString> QOnlineTts::s_voiceCodes =
{
    {Zahar,  QStringLiteral("zahar")},
    {Ermil,  QStringLiteral("ermil")},
    {Jane,   QStringLiteral("jane")},
    {Oksana, QStringLiteral("oksana")},
    {Alyss,  QStringLiteral("alyss")},
    {Omazh,  QStringLiteral("omazh")}
};
/************************************************
 * @brief QOnline Tts.
 * QOnlineTts
 ***********************************************/
QOnlineTts::QOnlineTts(QObject *parent) : QObject(parent)
{
}
/************************************************
 * @brief generate Urls.
 * generateUrls
 ***********************************************/
void QOnlineTts::generateUrls(const QString &text, QOnlineTranslator::Engine engine, QOnlineTranslator::Language lang, Voice voice, Emotion emotion)
{
    // Get speech
    QString unparsedText = text;
    switch (engine)
    {
        case QOnlineTranslator::Google:
        {
            if (voice != NoVoice)
            {
                setError(UnsupportedVoice, QString("%1 %2 %3").arg(tr("Selected engine"), QMetaEnum::fromType<QOnlineTranslator::Engine>().valueToKey(engine), tr("does not support voice settings")));
                return;
            }

            if (emotion != NoEmotion)
            {
                setError(UnsupportedEmotion, QString("%1 %2 %3").arg(tr("Selected engine"), QMetaEnum::fromType<QOnlineTranslator::Engine>().valueToKey(engine), tr("does not support emotion settings")));
                return;
            }

            const QString langString = languageApiCode(engine, lang);
            if (langString.isNull())
                return;

            // Google has a limit of characters per tts request. If the query is larger, then it should be splited into several
            while (!unparsedText.isEmpty())
            {
                const int splitIndex = QOnlineTranslator::getSplitIndex(unparsedText, s_googleTtsLimit); // Split the part by special symbol

                // Generate URL API for add it to the playlist
                QUrl apiUrl(QStringLiteral("http://translate.googleapis.com/translate_tts"));
                const QString query = QStringLiteral("ie=UTF-8&client=gtx&tl=%1&q=%2").arg(langString, QString(QUrl::toPercentEncoding(unparsedText.left(splitIndex))));
                #if defined(Q_OS_LINUX)
                apiUrl.setQuery(query);
                #elif defined(Q_OS_WIN)
                apiUrl.setQuery(query, QUrl::DecodedMode);
                #endif
                m_media.append(apiUrl);

                // Remove the said part from the next saying
                unparsedText = unparsedText.mid(splitIndex);
            }
            break;
        }
        case QOnlineTranslator::Yandex:
        {
            const QString langString = languageApiCode(engine, lang);
            if (langString.isNull())
                return;

            const QString voiceString = voiceApiCode(engine, voice);
            if (voiceString.isNull())
                return;

            const QString emotionString = emotionApiCode(engine, emotion);
            if (emotionString.isNull())
                return;

            // Yandex has a limit of characters per tts request. If the query is larger, then it should be splited into several
            while (!unparsedText.isEmpty())
            {
                const int splitIndex = QOnlineTranslator::getSplitIndex(unparsedText, s_yandexTtsLimit); // Split the part by special symbol

                // Generate URL API for add it to the playlist
                QUrl apiUrl(QStringLiteral("https://tts.voicetech.yandex.net/tts"));
                const QString query = QStringLiteral("text=%1&lang=%2&speaker=%3&emotion=%4&format=mp3")
                        .arg(QUrl::toPercentEncoding(unparsedText.left(splitIndex)), langString, voiceString, emotionString);
                #if defined(Q_OS_LINUX)
                apiUrl.setQuery(query);
                #elif defined(Q_OS_WIN)
                apiUrl.setQuery(query, QUrl::DecodedMode);
                #endif
                m_media.append(apiUrl);

                // Remove the said part from the next saying
                unparsedText = unparsedText.mid(splitIndex);
            }
            break;
        }
        case QOnlineTranslator::Bing:
            setError(UnsupportedEngine, QString("%1 %2").arg(QMetaEnum::fromType<QOnlineTranslator::Engine>().valueToKey(QOnlineTranslator::Bing), tr("engine does not support TTS")));
    }
}
/************************************************
 * @brief media.
 * media
 ***********************************************/
QList<QMediaContent> QOnlineTts::media() const
{
    return m_media;
}
/************************************************
 * @brief error String.
 * errorString
 ***********************************************/
QString QOnlineTts::errorString() const
{
    return m_errorString;
}
/************************************************
 * @brief error.
 * error
 ***********************************************/
QOnlineTts::TtsError QOnlineTts::error() const
{
    return m_error;
}
/************************************************
 * @brief voice Code
 * voiceCode
 ***********************************************/
QString QOnlineTts::voiceCode(Voice voice)
{
    return s_voiceCodes.value(voice);
}
/************************************************
 * @brief emotion Code.
 * emotionCode
 ***********************************************/
QString QOnlineTts::emotionCode(Emotion emotion)
{
    return s_emotionCodes.value(emotion);
}
/************************************************
 * @brief emotion.
 * emotion
 ***********************************************/
QOnlineTts::Emotion QOnlineTts::emotion(const QString &emotionCode)
{
    return s_emotionCodes.key(emotionCode, NoEmotion);
}
/************************************************
 * @brief voice.
 * voice
 ***********************************************/
QOnlineTts::Voice QOnlineTts::voice(const QString &voiceCode)
{
    return s_voiceCodes.key(voiceCode, NoVoice);
}
/************************************************
 * @brief set Error.
 * setError
 ***********************************************/
void QOnlineTts::setError(TtsError error, const QString &errorString)
{
    m_error = error;
    m_errorString = errorString;
}
/************************************************
 * @brief Returns engine-specific language code for tts.
 * languageApiCode
 ***********************************************/
QString QOnlineTts::languageApiCode(QOnlineTranslator::Engine engine, QOnlineTranslator::Language lang)
{
    switch (engine)
    {
        case QOnlineTranslator::Google:
            if (lang != QOnlineTranslator::Auto)
            { return QOnlineTranslator::languageApiCode(engine, lang); } // Google use the same codes for tts (except 'auto')
            break;
        case QOnlineTranslator::Yandex:
            switch (lang)
            {
                case QOnlineTranslator::Russian:
                    return QStringLiteral("ru_RU");
                case QOnlineTranslator::Tatar:
                    return QStringLiteral("tr_TR");
                case QOnlineTranslator::English:
                    return QStringLiteral("en_GB");
                default:
                    break;
            }
            break;
        default:
            break;
    }

    setError(UnsupportedLanguage, QString("%1 %2 %3").arg(tr("Selected language"), QMetaEnum::fromType<QOnlineTranslator::Language>().valueToKey(lang), QMetaEnum::fromType<QOnlineTranslator::Engine>().valueToKey(engine), tr("is not supported for")));
    return QString();
}
/************************************************
 * @brief voice Api Code.
 * voiceApiCode
 ***********************************************/
QString QOnlineTts::voiceApiCode(QOnlineTranslator::Engine engine, Voice voice)
{
    if (engine == QOnlineTranslator::Yandex)
    {
        if (voice == NoVoice)
            return voiceCode(Zahar);
        return voiceCode(voice);
    }

    setError(UnsupportedVoice, QString(" %1 %2 %2").arg(tr("Selected voice"), QMetaEnum::fromType<Voice>().valueToKey(voice), QMetaEnum::fromType<QOnlineTranslator::Engine>().valueToKey(engine), tr("is not supported for")));
    return QString();
}
/************************************************
 * @brief emotion Api Code.
 * emotionApiCode
 ***********************************************/
QString QOnlineTts::emotionApiCode(QOnlineTranslator::Engine engine, Emotion emotion)
{
    if (engine == QOnlineTranslator::Yandex)
    {
        if (emotion == NoEmotion)
            return emotionCode(Neutral);
        return emotionCode(emotion);
    }

    setError(UnsupportedEmotion, QString("%1 %2 %3").arg(tr("Selected emotion"), QMetaEnum::fromType<Emotion>().valueToKey(emotion), QMetaEnum::fromType<QOnlineTranslator::Engine>().valueToKey(engine), tr("is not supported for")));
    return QString();
}
/******************************* End of File *********************************/
