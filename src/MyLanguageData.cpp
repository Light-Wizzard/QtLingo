/************************************************
* @file MyLanguageData.cpp
* @brief My Language Data,
* I check variables before setting them to prevent triggers.
* @author Jeffrey Scott Flesher <Jeffrey.Scott.Flesher@>
 ***********************************************/
#include "MyLanguageData.h"
/************************************************
 * @brief Language Data.
 * MyLanguageData
 ***********************************************/
MyLanguageData::MyLanguageData(const QString &thisName, const QString &thisNameTranslated) : myName(thisName), myNameTranslated(thisNameTranslated)
{
}
/************************************************
 * @brief name.
 * name
 ***********************************************/
QString MyLanguageData::name() const
{
    return myName;
}
/************************************************
 * @brief name Translated.
 * nameTranslated
 ***********************************************/
QString MyLanguageData::nameTranslated() const
{
    return myNameTranslated;
}
/******************************* End of File *********************************/
