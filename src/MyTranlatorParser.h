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
#include "MyDatatables.h"

class MyTranlatorParser : public QObject
{
        Q_OBJECT
    public:
        explicit MyTranlatorParser(QObject *parent = nullptr, MyDatatables *thisSqlDb = nullptr);
        //
        base_node::base_node_ptr parse_ts_file(const QString &inputFile);                         //!< parse_ts_file
        bool parse_txt_file(const QString &inputFile, visitors::map_QStringQString &strings);     //!< parse_txt_file
        void toTXT(const QString &inputFile, const QString &outputDir, bool with_unfinished, bool with_vanished, bool unfinished_only);  //!< toTXT
        void toTS(const QString &inputDir, const QString &outputFile, const QString &langid);     //!< toTS

    private:
        MyDatatables       *mySqlDb;               //!< \c mySqlDb              @brief Sql Datatables
        bool                isDebugMessage = true; //!< \c isDebugMessage       @brief is Debug Message

};
#endif // MYTRANLATORPARSER_H
/******************************* End of File *********************************/
