#include "MyTranslationFiles.h"

/*! ***************************************************************************
   \class MyTranslationFiles
   \brief Translation Files Constructor
 *************************************************************************** */
MyTranslationFiles::MyTranslationFiles(QObject *parent, MyDatatables *thisSqlDb) : QObject(parent), mySqlDb(thisSqlDb)
{

}
/*! ***************************************************************************
   \fn setDebugMessage
   \brief set Debug Message
 *************************************************************************** */
void MyTranslationFiles::setDebugMessage(bool thisState)
{
    isDebugMessage = thisState;
}
/*! ***************************************************************************
   \fn getDebugMessage
   \brief get Debug Message
 *************************************************************************** */
bool MyTranslationFiles::getDebugMessage()
{
    return isDebugMessage;
}
/*! ***************************************************************************
   \fn languageNameFromFile
   \brief language Name From File
 *************************************************************************** */
QString MyTranslationFiles::languageNameFromFile(const QString &thisTranslationFile)
{
    if (isDebugMessage) { qDebug() << "languageNameFromFile"; }
    QTranslator translator;
    translator.load(thisTranslationFile);
    // FIXME
    return translator.translate("MainWindow", "English");
}
/*! ***************************************************************************
   \fn languageMatch
   \brief language Match qmFile naming
 *************************************************************************** */
QString MyTranslationFiles::getLocalizedCodeFromFile(const QString &thisPrefix, const QString &thisQmFile)
{
    if (isDebugMessage) { qDebug() << "getLocalizedCodeFromFile"; }
    QFileInfo theFileInfo(thisQmFile);

    QString theFileName = theFileInfo.baseName();
    return theFileName.remove(QString("%1_").arg(thisPrefix));
}
/*! ***************************************************************************
   \fn removeArgs
   \brief "String %1"
 *************************************************************************** */
void MyTranslationFiles::removeArgs(const QString &thisString, const QString &thisTransFile)
{
    myRemoveTransArgs.append(QString("%1 |%2| in file %3").arg(tr("Remove Arguments that use Percent Sign x"), thisString, thisTransFile));
} // end removeArgs
/*! ***************************************************************************
   \fn fileRemoveArgs
   \brief file Remove Args "String %1"
 *************************************************************************** */
void MyTranslationFiles::fileRemoveArgs()
{
    if (!myRemoveTransArgs.isEmpty())
    {
        QString theRemoveFileName = QString("%1").arg(getAppDataLocation(), QDir::separator(), "RemoveArgFile.txt");
        writeFile(theRemoveFileName, myRemoveTransArgs);
        showMessageBox(QObject::tr("Remove Args file is created").toLocal8Bit(), QString("%1: %2 %3 %4").arg(tr("Remove Args"), myRemoveTransArgs, tr("File: "), theRemoveFileName).toLocal8Bit(), Warning);
    }
} // end fileRemoveArgs
/*! ***************************************************************************
   \fn fixTranslationFile
   \brief fix Translation File; mostly Arabic gets the value before the ID on some fields
 *************************************************************************** */
void MyTranslationFiles::fixTranslationFile(const QString &thisFile)
{
    if (!isFileExists(thisFile)) { showMessageBox(tr("File not found").toLocal8Bit(), QString("%1: %2").arg(tr("File not found"), thisFile).toLocal8Bit(), Critical); return; }
    //
    QString theNewFileContent;
    QFile theInputTxtFile(thisFile);
    if (theInputTxtFile.open(QIODevice::ReadOnly))
    {
        QTextStream theFileStream(&theInputTxtFile);
        while (!theFileStream.atEnd())
        {
            QString theLine = theFileStream.readLine();
            if (theLine.mid(0, 1) != "[")
            {
                QString theTransValue = theLine;
                theTransValue.remove(QRegExp("\[([^)]+)\\]"));
                //
                QRegExp rx("\[([^)]+)\\]");
                QString theOnlyID = theLine;
                if (rx.indexIn(theLine) == 0) { theOnlyID = rx.cap(1); }
                theNewFileContent.append(QString("%1 %2\n").arg(theOnlyID, theTransValue));
            }
        }
    }
} // end fixTranslationFile
/*! ***************************************************************************
   \fn languageMatch
   \brief language Match qmFile naming
 *************************************************************************** */
bool MyTranslationFiles::languageMatch(const QString &thisPrefix, const QString &thisLang, const QString &thisQmFile)
{
    if (isDebugMessage) { qDebug() << "languageMatch"; }
    //qmFile: ProjectName_xx.qm
    QString thisLocalizer = getLocalizedCodeFromFile(thisPrefix, thisQmFile);
    return thisLocalizer == thisLang;
}
/*! ***************************************************************************
   \fn findQmFiles
   \brief find Qm Files
 *************************************************************************** */
QStringList MyTranslationFiles::findQmFiles(const QString &thisFolder)
{
    QDir dir(QString(":/%1").arg(thisFolder));
    QStringList fileNames = dir.entryList(QStringList("*.qm"), QDir::Files, QDir::Name);
    for (QString &fileName : fileNames)
        { fileName = dir.filePath(fileName); }
    return fileNames;
}
/*! ***************************************************************************
   \fn get Localizer Code
   \brief get Localizer Code
 *************************************************************************** */
QString MyTranslationFiles::getLocalizerCode(const QString &thisPrefix, const QString &thisQmFile)
{
    QString thisLocalizer = getLocalizedCodeFromFile(thisPrefix, thisQmFile);
    return myQOnlineTranslator.languageCodeToName(thisLocalizer);
}
/*! ***************************************************************************
   \fn parse_ts_file
   \brief
 *************************************************************************** */
base_node::base_node_ptr MyTranslationFiles::parse_ts_file(const QString &inputFile)
{
    QFile iFile(inputFile);
    iFile.open(QIODevice::ReadOnly);

    QXmlStreamReader xmlReader(&iFile);

    base_node::base_node_ptr root, current;
    QString text;

    enum EStates
    {
        st_Unstate             = 0,
        st_WaitForStartElement = 0x01,
        st_WaitForText         = 0x02,
        st_WaitForEndElement   = 0x04
    };

    int states = st_WaitForStartElement;

    while(!xmlReader.atEnd())
    {
        QXmlStreamReader::TokenType tt = xmlReader.readNext();
        switch(tt)
        {
            case QXmlStreamReader::StartDocument:
            {
                root = std::make_shared<document_node>();
                current = root;
            } break;
            case QXmlStreamReader::DTD:
            {
                current->add_child(std::make_shared<DTD_node>("<!DOCTYPE TS>"));
            } break;
            case QXmlStreamReader::StartElement:
            {
                assert(states & st_WaitForStartElement);

                QString name = xmlReader.name().toString();
                QXmlStreamAttributes attrs = xmlReader.attributes();

                if("message" == name)
                {
                    current = current->add_child(std::make_shared<element_node>(element_node::ent_message, name, attrs));
                }
                else if("source" == name)
                {
                    current = current->add_child(std::make_shared<element_node>(element_node::ent_source, name, attrs));
                }
                else if("translation" == name)
                {
                    current = current->add_child(std::make_shared<element_node>(element_node::ent_translation, name, attrs));
                }
                else if("TS" == name)
                {
                    current = current->add_child(std::make_shared<TS_node>(name, attrs));
                }
                else
                {
                    current = current->add_child(std::make_shared<element_node>(element_node::ent_element, name, attrs));
                }

                states = st_WaitForText|st_WaitForStartElement|st_WaitForEndElement;
            } break;
            case QXmlStreamReader::Characters:
            {
                if(states & st_WaitForText)
                {
                    text = xmlReader.text().toString();
                    states = st_WaitForEndElement|st_WaitForStartElement;
                }
            } break;
            case QXmlStreamReader::EndElement:
            {
                assert(states & st_WaitForEndElement);
                assert(current->kind() & base_node::nt_Element);
                //((element_node*)current.get())->set_text(text);

                reinterpret_cast<element_node*>(current.get())->set_text(text);

                text.clear();
                states = st_WaitForStartElement|st_WaitForEndElement;
                current = current->parent();
            } break;
            case QXmlStreamReader::Invalid:               { break; }
            case QXmlStreamReader::EndDocument:           { break; }
            case QXmlStreamReader::Comment:               { break; }
            case QXmlStreamReader::EntityReference:       { break; }
            case QXmlStreamReader::ProcessingInstruction: { break; }
            case QXmlStreamReader::NoToken:               { break; }
        }
    }

    return root;
}
/*! ***************************************************************************
   \fn parse_txt_file
   \brief
 *************************************************************************** */
bool MyTranslationFiles::parse_txt_file(const QString &inputFile, visitors::map_QStringQString &strings)
{
    QFile iFile(inputFile);
    iFile.open(QFile::ReadOnly|QFile::Text);
    QTextStream txts(&iFile);
    txts.setCodec("UTF-8");

    const QString rgxp("^(?<id>\\[\\[\\[[A-F0-9]{8}\\]\\]\\])\\s*[\\\",“,”](?<text>.*)[\\\",“,”]$");
    QRegularExpression rxp(rgxp);

    unsigned int line_counter = 0;

    while(!txts.atEnd())
    {
        QString str = txts.readLine();
        QRegularExpressionMatch rm = rxp.match(str);

        QString id		= rm.captured("id");
        QString text	= rm.captured("text");

        if(id.isEmpty() || text.isEmpty())
        {
            std::cout << "Error in line: " << line_counter << " , file: " << inputFile.toUtf8().constData() << " , source line: " << str.toUtf8().constData() << std::endl;
            return false;
        }

        strings.insert(visitors::map_QStringQString::value_type(id, text));
        line_counter++;
    }

    return true;
}
/*! ***************************************************************************
   \fn toTXT
   \brief ts_tool --src \ProjectFolder\translations\ColorMagic_EN.ts --dst \ProjectFolder\translations_new --mode TXT
 *************************************************************************** */
void MyTranslationFiles::toTXT(const QString &inputFile, const QString &outputDir, bool with_unfinished, bool with_vanished, bool unfinished_only)
{
    using namespace visitors;

    QFileInfo fiI(inputFile);
    if(!fiI.exists())
    {
        mySqlDb->mySqlModel->mySetting->showMessageBox(QObject::tr("Input does file not exist!").toLocal8Bit(), QString("%1: %2").arg(tr("Unable to find Input file"), inputFile).toLocal8Bit(), mySqlDb->mySqlModel->mySetting->Critical);
        return;
    }

    QFileInfo fiO(outputDir);
    if(!fiO.exists())
    {
        QDir().mkdir(outputDir);
    }

    QString outputXmlFileName = QDir(outputDir).path() + QDir::separator() + fiI.fileName();
    QString outputTextFile    = QDir(outputDir).path() + QDir::separator() + fiI.baseName() + ".txt";

    unsigned int files_in_out_dir = QDir(outputDir).entryInfoList(QDir::NoDotAndDotDot|QDir::AllEntries).count();

    if( !fiO.exists() || 2 < files_in_out_dir || (2 == files_in_out_dir && !QFileInfo::exists(outputXmlFileName) && !QFileInfo::exists(outputTextFile)) )
    {
        // FIXME question delete
        mySqlDb->mySqlModel->mySetting->showMessageBox(QObject::tr("Check output Folder").toLocal8Bit(), QString("%1!: %2").arg(tr("Can not create output directory OR directory is not empty"), inputFile).toLocal8Bit(), mySqlDb->mySqlModel->mySetting->Critical);
        return;
    }

    QFile oFile(outputXmlFileName);
    oFile.open(QIODevice::WriteOnly);

    //pares ts file
    base_node::base_node_ptr root = parse_ts_file(inputFile);

    //replace strings
    map_hashQString strings;
    string_extractor_replacer ser(strings, with_unfinished, with_vanished, unfinished_only);
    root->visit(ser);

    //write text file
    QFile sFile(outputTextFile);
    sFile.open(QIODevice::WriteOnly|QIODevice::Text);
    QTextStream txts(&sFile);
    txts.setCodec("UTF-8");

    std::for_each(strings.begin(), strings.end(), [&txts](const map_hashQString::value_type &vt){ txts << vt.second << "\n"; });

    //write modified ts file
    QXmlStreamWriter xmlWriter(&oFile);
    xmlWriter.setAutoFormatting(true);

    document_dump ddv(xmlWriter);
    root->visit(ddv);
}
/*! ***************************************************************************
   \fn toTS
   \brief ts_tool --src \inputFolder\ --dst \destination\translations\ProjectName_LangID.ts --mode TS
 *************************************************************************** */
void MyTranslationFiles::toTS(const QString &inputDir, const QString &outputFile, const QString &langid)
{
    using namespace visitors;

    QFileInfo fiI(inputDir);
    if(!fiI.exists())
    {
        mySqlDb->mySqlModel->mySetting->showMessageBox(QObject::tr("Input directory not exist!").toLocal8Bit(), QString("%1: %2").arg(tr("Unable to find Input folder"), inputDir).toLocal8Bit(), mySqlDb->mySqlModel->mySetting->Critical);
        return;
        // FIXME Error
    }

    const QFileInfoList &fil = QDir(inputDir).entryInfoList(QDir::NoDotAndDotDot|QDir::AllEntries);
    unsigned int files_in_input_dir = fil.count();

    QString tsFile, txtFile;

    if(2 == files_in_input_dir)
    {
        QFileInfo if0(QDir(inputDir).path() + QDir::separator() + fil[0].baseName() + ".ts");
        QFileInfo if1(QDir(inputDir).path() + QDir::separator() + fil[0].baseName() + ".txt");

        if(if0.isFile() && if1.isFile())
        {
            tsFile = if0.filePath();
            txtFile = if1.filePath();
        }
    }

    if(2 < files_in_input_dir || 0 == files_in_input_dir || tsFile.isEmpty() || txtFile.isEmpty())
    {
        mySqlDb->mySqlModel->mySetting->showMessageBox(QObject::tr("Check Input Folder").toLocal8Bit(), QString("%1!: %2").arg(tr("Input directory should contain only txt and ts file with same name"), tsFile).toLocal8Bit(), mySqlDb->mySqlModel->mySetting->Critical);
        return;
        // FIXME Error
    }

    // pares ts file
    base_node::base_node_ptr root = parse_ts_file(tsFile);

    // parse txt file
    map_QStringQString strings;
    if(!parse_txt_file(txtFile, strings))
    {
        std::cout << "Parsing error: " << txtFile.toUtf8().constData() << " !" << std::endl;
        mySqlDb->mySqlModel->mySetting->showMessageBox(QObject::tr("Parsing errorr").toLocal8Bit(), QString("%1: %2").arg(tr("Parsing errorr"), txtFile.toUtf8().constData()).toLocal8Bit(), mySqlDb->mySqlModel->mySetting->Critical);
        return;
        // FIXME Error
    }

    // replace strings
    back_string_replacer bsr(strings, langid);
    root->visit(bsr);

    // dump to file
    QFile oFile(outputFile);
    oFile.open(QIODevice::WriteOnly);

    QXmlStreamWriter xmlWriter(&oFile);
    xmlWriter.setAutoFormatting(true);
    xmlWriter.setCodec("UTF-8");

    document_dump ddv(xmlWriter);
    root->visit(ddv);
}
/*! ***************************************************************************
   \fn writeFile
   \brief write File
 *************************************************************************** */
bool MyTranslationFiles::writeFile(const QString &thisFileName, const QString &thisContent)
{
    if (isDebugMessage) { qDebug() << "writeFile"; }
    QFile theFile(thisFileName);
    // Trying to open in WriteOnly and Text mode
    if(!theFile.open(QFile::WriteOnly | QFile::Text))
    {
        showMessageBox(tr("Error opening file for writing").toLocal8Bit(), QString("%1: %2").arg(tr("Could not open file for writing"), thisFileName).toLocal8Bit(), Critical);
        return false;
    }
    // Write to file
    QTextStream theFileStream(&theFile);
    theFileStream << thisContent;
    theFile.flush();
    theFile.close();
    return true;
} // end writeFile
/*! ***************************************************************************
   \fn getAppDataLocation
   \brief get App Data Location
 *************************************************************************** */
QString MyTranslationFiles::getAppDataLocation()
{
   if (isDebugMessage) { qDebug() << "getAppDataLocation"; }
   QString theAppDataLocation = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
   if (theAppDataLocation.isEmpty())
   {
       theAppDataLocation = QStandardPaths::writableLocation(QStandardPaths::GenericDataLocation);
       if (theAppDataLocation.isEmpty())
       { theAppDataLocation = QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation); }
       if (theAppDataLocation.isEmpty())
       { theAppDataLocation = QDir::currentPath(); }
   }
   return theAppDataLocation;
} // end getAppDataLocation
/*! ***************************************************************************
   \fn isFileExists
   \brief is File Exists
 *************************************************************************** */
bool MyTranslationFiles::isFileExists(const QString &thisFile)
{
    if (isDebugMessage) { qDebug() << "isFileExists"; }
    // check if file exists and if yes: Is it really a file and not directory?
    return QFileInfo::exists(thisFile) && QFileInfo(thisFile).isFile();
} // end isFileExists
/*! ***************************************************************************
   \fn showMessageBox
   \brief information, question: 1 = true, 0 = false, warning, critical: theMessage.toLocal8Bit()
 *************************************************************************** */
int MyTranslationFiles::showMessageBox(const QString &thisTitle, const QString &thisMessage, MyMessageTypes thisMessageType)
{
    if (isDebugMessage) { qDebug() << "showMessageBox(" << thisTitle << ", " << thisMessage << ", " << thisMessageType << ")"; }
    switch (thisMessageType)
    {
        case Information:   { return QMessageBox::information(nullptr, thisTitle, thisMessage, QMessageBox::Ok); }
        case Question:      { if (questionYesNo(thisTitle.toLocal8Bit(), thisMessage.toLocal8Bit())) return 1; else return 0; }
        case Warning:       { return QMessageBox::warning(nullptr, thisTitle, thisMessage, QMessageBox::Ok); }
        case Critical:      { return QMessageBox::critical(nullptr, thisTitle, thisMessage, QMessageBox::Ok); }
    }
    return 0;
} // end showMessageBox
/*! ***************************************************************************
   \fn questionYesNo
   \brief Titel and Question Yes No
 *************************************************************************** */
bool MyTranslationFiles::questionYesNo(const char *thisTitle, const char *thisQuestion)
{
    if (isDebugMessage) { qDebug() << "questionYesNo"; }
    QMessageBox theMsgBox;
    theMsgBox.setWindowTitle(QObject::tr(thisTitle));
    theMsgBox.setText(QObject::tr(thisQuestion));
    theMsgBox.setStandardButtons(QMessageBox::Yes);
    theMsgBox.addButton(QMessageBox::No);
    theMsgBox.setDefaultButton(QMessageBox::No);
    if(theMsgBox.exec() == QMessageBox::Yes)
    {
        if (isDebugMessage) { qDebug() << "Yes was clicked"; }
        return true;
    }
    else
    {
        if (isDebugMessage) { qDebug() << "Yes was *not* clicked"; }
        return false;
    }
} // end questionYesNo
/******************************* End of File *********************************/
