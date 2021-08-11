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

#ifndef QONLINETTS_H
#define QONLINETTS_H

#include "qonlinetranslator.h"

#include <QMetaEnum>
#include <QUrl>

/*! ***************************************************************************
   \class QOnlineTts
   \brief QOnlineTts
 *************************************************************************** */
class QOnlineTts : public QObject
{
        Q_OBJECT
        Q_DISABLE_COPY(QOnlineTts)

    public:
        enum Voice
        {
            // All
            NoVoice = -1,   //!< \c NoVoice \brief NoVoice
            // Yandex
            Zahar,          //!< \c Zahar   \brief Zahar
            Ermil,          //!< \c Ermil   \brief Ermil
            Jane,           //!< \c Jane    \brief Jane
            Oksana,         //!< \c Oksana  \brief Oksana
            Alyss,          //!< \c Alyss   \brief Alyss
            Omazh           //!< \c Omazh   \brief Omazh
        };
        Q_ENUM(Voice)

        enum Emotion
        {
            // All
            NoEmotion = -1, //!< \c NoEmotion   \brief NoEmotion
            // Yandex
            Neutral,        //!< \c Neutral     \brief Neutral
            Good,           //!< \c Good        \brief Good
            Evil            //!< \c Evil        \brief Evil
        };
        Q_ENUM(Emotion)

        enum TtsError
        {
            NoError,                //!< \c NoError             \brief NoError
            UnsupportedEngine,      //!< \c UnsupportedEngine   \brief Unsupported Engine
            UnsupportedLanguage,    //!< \c UnsupportedLanguage \brief Unsupported Language
            UnsupportedVoice,       //!< \c UnsupportedVoice    \brief Unsupported Voice
            UnsupportedEmotion,     //!< \c UnsupportedEmotion  \brief Unsupported Emotion
        };

        explicit QOnlineTts(QObject *parent = nullptr); //!< QOnlineTts

        void generateUrls(const QString &text, QOnlineTranslator::Engine engine, QOnlineTranslator::Language lang, Voice voice = NoVoice, Emotion emotion = NoEmotion);  //!< generateUrls
        QList<QMediaContent> media() const; //!< media

        TtsError error() const;      //!< error
        QString errorString() const; //!< errorString

        static QString voiceCode(Voice voice);              //!< voiceCode
        static QString emotionCode(Emotion emotion);        //!< emotionCode
        static Emotion emotion(const QString &emotionCode); //!< emotion
        static Voice voice(const QString &voiceCode);       //!< voice

    private:
        void setError(TtsError error, const QString &errorString); //!< setError

        QString languageApiCode(QOnlineTranslator::Engine engine, QOnlineTranslator::Language lang); //!< languageApiCode
        QString voiceApiCode(QOnlineTranslator::Engine engine, Voice voice);                         //!< voiceApiCode
        QString emotionApiCode(QOnlineTranslator::Engine engine, Emotion emotion);                   //!< emotionApiCode

        static const QMap<Emotion, QString> s_emotionCodes; //!< s_emotionCodes
        static const QMap<Voice, QString>   s_voiceCodes;   //!< s_voiceCodes

        static constexpr int s_googleTtsLimit = 200;    //!< \c s_googleTtsLimit    \brief google Tts Limit
        static constexpr int s_yandexTtsLimit = 1400;   //!< \c s_yandexTtsLimit    \brief yandex Tts Limit

        QList<QMediaContent>    m_media;            //!< \c m_media         \brief m_media
        QString                 m_errorString;      //!< \c m_errorString   \brief m_errorString
        TtsError                m_error = NoError;  //!< \c m_error         \brief m_error
};

#endif // QONLINETTS_H
/******************************* End of File *********************************/
