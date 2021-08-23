#ifndef MYTRANLATORPARSER_H
#define MYTRANLATORPARSER_H

#include <QObject>
#include <QFile>
#include <QFileInfo>

#include <QtDebug>
#include <QRegularExpression>
#include <QTextStream>

//model
#include "third-party/ts_tool/ts_model.h"
// Local
#include "MyOrgSettings.h"
/************************************************
 * @brief Tranlator Parser.
 * \class MyTranlatorParser
 ***********************************************/
class MyTranlatorParser : public QObject
{
        Q_OBJECT
    public:
        explicit MyTranlatorParser(QObject *parent = nullptr, MyOrgSettings *thisSetting = nullptr);
        //
        base_node::base_node_ptr parse_ts_file(const QString &inputFile);                         //!< parse_ts_file
        bool parse_txt_file(const QString &inputFile, visitors::map_QStringQString &strings);     //!< parse_txt_file
        void toTXT(const QString &inputFile, const QString &outputDir, bool with_unfinished, bool with_vanished, bool unfinished_only);  //!< toTXT
        void toTS(const QString &inputDir, const QString &outputFile, const QString &langid);     //!< toTS
        // Is Debug Message
        void setDebugMessage(bool thisState);        //!< set Debug Message
        bool getDebugMessage();                      //!< get Debug Message
        void setMessage(const QString &thisMessage);     //!< set Message

    private:
        MyOrgSettings  *mySetting;             //!< \c mySetting      @brief Domain Settings
        bool            isDebugMessage = true; //!< \c isDebugMessage @brief is Debug Message

};
#endif // MYTRANLATORPARSER_H
/******************************* End of File *********************************/
