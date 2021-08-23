/*
 * https://wiki.qt.io/Simple_encryption_with_SimpleCrypt#Versions
 * Copyright (c) 2011, Andre Somers
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the Rathenau Instituut, Andre Somers nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL ANDRE SOMERS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR #######; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
#include "SimpleCrypt.h"

/************************************************
 * @brief Constructor.
 * SimpleCrypt
 ***********************************************/
SimpleCrypt::SimpleCrypt(): myKey(0), myCompressionMode(CompressionAuto), myProtectionMode(ProtectionChecksum), myLastError(ErrorNoError)
{
    QRandomGenerator generator(uint(QDateTime::currentMSecsSinceEpoch() & 0xFFFF));
    generator.generate();
    // qsrand(uint(QDateTime::currentMSecsSinceEpoch() & 0xFFFF));
}
/************************************************
 * @brief Constructor.
 * SimpleCrypt
 ***********************************************/
SimpleCrypt::SimpleCrypt(quint64 key): myKey(key), myCompressionMode(CompressionAuto), myProtectionMode(ProtectionChecksum), myLastError(ErrorNoError)
{
    QRandomGenerator generator(uint(QDateTime::currentMSecsSinceEpoch() & 0xFFFF));
    generator.generate();
    // qsrand(uint(QDateTime::currentMSecsSinceEpoch() & 0xFFFF));
    splitKey();
}
/************************************************
 * @brief set Debug Message.
 * setDebugMessage
 ***********************************************/
void SimpleCrypt::setDebugMessage(bool thisState)
{
    isDebugMessage = thisState;
}
/************************************************
 * @brief get Debug Message.
 * getDebugMessage
 ***********************************************/
bool SimpleCrypt::getDebugMessage()
{
    return isDebugMessage;
}
/************************************************
 * @brief set Key.
 * setKey
 ***********************************************/
void SimpleCrypt::setKey(quint64 key)
{
    myKey = key;
    splitKey();
}
/************************************************
 * @brief split Key.
 * splitKey
 ***********************************************/
void SimpleCrypt::splitKey()
{
    myKeyParts.clear();
    myKeyParts.resize(8);
    for (int i = 0;i < 8; i++)
    {
        quint64 part = myKey;
        for (int j = i; j > 0; j--) { part = part >> 8; }
        part = part & 0xff;
        myKeyParts[i] = static_cast<char>(part);
    }
}
/************************************************
 * @brief encrypt To Byte Array QString.
 * encryptToByteArray
 ***********************************************/
QByteArray SimpleCrypt::encryptToByteArray(const QString &plaintext)
{
    QByteArray plaintextArray = plaintext.toUtf8();
    return encryptToByteArray(plaintextArray);
}
/************************************************
 * @brief encrypt To Byte Array QByteArray.
 * encryptToByteArray
 ***********************************************/
QByteArray SimpleCrypt::encryptToByteArray(const QByteArray &plaintext)
{
    if (myKeyParts.isEmpty())
    {
        qWarning() << "No key set.";
        myLastError = ErrorNoKeySet;
        return QByteArray();
    }

    QByteArray ba = plaintext;

    CryptoFlags flags = CryptoFlagNone;
    if (myCompressionMode == CompressionAlways)
    {
        ba = qCompress(ba, 9); // maximum compression
        flags |= CryptoFlagCompression;
    }
    else if (myCompressionMode == CompressionAuto)
    {
        QByteArray compressed = qCompress(ba, 9);
        if (compressed.count() < ba.count())
        {
            ba = compressed;
            flags |= CryptoFlagCompression;
        }
    }

    QByteArray integrityProtection;
    if (myProtectionMode == ProtectionChecksum)
    {
        flags |= CryptoFlagChecksum;
        QDataStream s(&integrityProtection, QIODevice::WriteOnly);
        s << qChecksum(ba.constData(), ba.length());
    }
    else if (myProtectionMode == ProtectionHash)
    {
        flags |= CryptoFlagHash;
        QCryptographicHash hash(QCryptographicHash::Sha1);
        hash.addData(ba);

        integrityProtection += hash.result();
    }
    // prepend a random char to the string
    QRandomGenerator generator(uint(QDateTime::currentMSecsSinceEpoch() & 0xFFFF));
    char randomChar = char(generator.generate() & 0xFF);
    // char randomChar = char(qrand() & 0xFF);

    ba = randomChar + integrityProtection + ba;

    int pos(0);
    char lastChar(0);

    int cnt = ba.count();

    while (pos < cnt)
    {
        ba[pos] = ba.at(pos) ^ myKeyParts.at(pos % 8) ^ lastChar;
        lastChar = ba.at(pos);
        ++pos;
    }

    QByteArray resultArray;
    resultArray.append(char(0x03));  // version for future updates to algorithm
    resultArray.append(char(flags)); // encryption flags
    resultArray.append(ba);

    myLastError = ErrorNoError;
    return resultArray;
}
/************************************************
 * @brief encrypt To String QString.
 * encryptToString
 ***********************************************/
QString SimpleCrypt::encryptToString(const QString &plaintext)
{
    QByteArray plaintextArray = plaintext.toUtf8();
    QByteArray cypher = encryptToByteArray(plaintextArray);
    QString cypherString = QString::fromLatin1(cypher.toBase64());
    return cypherString;
}
/************************************************
 * @brief encrypt To String QByteArray.
 * encryptToString
 ***********************************************/
QString SimpleCrypt::encryptToString(const QByteArray &plaintext)
{
    QByteArray cypher = encryptToByteArray(plaintext);
    QString cypherString = QString::fromLatin1(cypher.toBase64());
    return cypherString;
}
/************************************************
 * @brief decrypt To String QString.
 * decryptToString
 ***********************************************/
QString SimpleCrypt::decryptToString(const QString &cyphertext)
{
    QByteArray cyphertextArray = QByteArray::fromBase64(cyphertext.toLatin1());
    QByteArray plaintextArray = decryptToByteArray(cyphertextArray);
    QString plaintext = QString::fromUtf8(plaintextArray, plaintextArray.size());

    return plaintext;
}
/************************************************
 * @brief decrypt To String QByteArray.
 * decryptToString
 ***********************************************/
QString SimpleCrypt::decryptToString(const QByteArray &cypher)
{
    QByteArray ba = decryptToByteArray(cypher);
    QString plaintext = QString::fromUtf8(ba, ba.size());

    return plaintext;
}
/************************************************
 * @brief decrypt To Byte Array QString.
 * decryptToByteArray
 ***********************************************/
QByteArray SimpleCrypt::decryptToByteArray(const QString &cyphertext)
{
    QByteArray cyphertextArray = QByteArray::fromBase64(cyphertext.toLatin1());
    QByteArray ba = decryptToByteArray(cyphertextArray);

    return ba;
}
/************************************************
 * @brief decrypt To Byte Array QByteArray.
 * decryptToByteArray
 ***********************************************/
QByteArray SimpleCrypt::decryptToByteArray(QByteArray cypher)
{
    if (myKeyParts.isEmpty())
    {
        qWarning() << "No key set.";
        myLastError = ErrorNoKeySet;
        return QByteArray();
    }

    QByteArray ba = cypher;

    if( cypher.count() < 3 )
        { return QByteArray(); }

    char version = ba.at(0);

    if (version != 3)
    {  // we only work with version 3
        myLastError = ErrorUnknownVersion;
        qWarning() << "Invalid version or not a cyphertext.";
        return QByteArray();
    }

    CryptoFlags flags = CryptoFlags(ba.at(1));

    ba = ba.mid(2);
    int pos(0);
    int cnt(ba.count());
    char lastChar = 0;

    while (pos < cnt)
    {
        char currentChar = ba[pos];
        ba[pos] = ba.at(pos) ^ lastChar ^ myKeyParts.at(pos % 8);
        lastChar = currentChar;
        ++pos;
    }

    ba = ba.mid(1); // chop off the random number at the start

    bool integrityOk(true);
    if (flags.testFlag(CryptoFlagChecksum))
    {
        if (ba.length() < 2)
        {
            myLastError = ErrorIntegrityFailed;
            return QByteArray();
        }
        quint16 storedChecksum;
        {
            QDataStream s(&ba, QIODevice::ReadOnly);
            s >> storedChecksum;
        }
        ba = ba.mid(2);
        quint16 checksum = qChecksum(ba.constData(), ba.length());
        integrityOk = (checksum == storedChecksum);
    }
    else if (flags.testFlag(CryptoFlagHash))
    {
        if (ba.length() < 20)
        {
            myLastError = ErrorIntegrityFailed;
            return QByteArray();
        }
        QByteArray storedHash = ba.left(20);
        ba = ba.mid(20);
        QCryptographicHash hash(QCryptographicHash::Sha1);
        hash.addData(ba);
        integrityOk = (hash.result() == storedHash);
    }

    if (!integrityOk)
    {
        myLastError = ErrorIntegrityFailed;
        return QByteArray();
    }

    if (flags.testFlag(CryptoFlagCompression))
       { ba = qUncompress(ba); }

    myLastError = ErrorNoError;
    return ba;
}
/************************************************
 * @brief set Message.
 * setMessage
 ***********************************************/
void SimpleCrypt::setMessage(const QString &thisMessage)
{
    if (isDebugMessage)
    {
        qDebug() << thisMessage;
        std::cout << thisMessage.toStdString() << std::endl;
    }
}
/******************************* End of File *********************************/
