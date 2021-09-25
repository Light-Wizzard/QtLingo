#ifndef MyLangageDATA_H
#define MyLangageDATA_H

#include <QString>

/************************************************
 * @brief Language Data.
 * /class MyLanguageData
 ***********************************************/
class MyLanguageData
{
    public:
        MyLanguageData(const QString &thisName, const QString &thisNameTranslated); //!< MyLanguageData

        QString name() const;           //!< name
        QString nameTranslated() const; //!< name Translated

    private:
        QString myName;           //!< \c myName           @brief my Name in base Lanuage
        QString myNameTranslated; //!< \c myNameTranslated @brief my Name Translated
};
#endif // MyLangageDATA_H
/******************************* End of File *********************************/
