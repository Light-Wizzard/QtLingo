#include <QDateTime>
#include <QStandardPaths>
#include <QFileInfo>
#include <QIcon>
#include <QStyleHints>
#include <QUrl>
#include <QScreen>
#ifdef MY_QML
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#else
#include "MainWindow.h"
#endif
//
#include "MyLanguageModel.h"
// STD
#include <iostream>
#include <assert.h>
#include <algorithm>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
//
#if Q_OS_MSDOS || defined(Q_OS_WIN32) || defined(Q_OS_WINCE)
#define VERSION "1.0.0"
#else
#define VERSION "1.0"
#endif
//
QString myLogFile = "";
/************************************************
* @brief get Message Log File.
* \fn getMessageLogFile
 ***********************************************/
QString getMessageLogFile(const QString &thisAppDataLocation)
{
    return QString("%1%2%3").arg(thisAppDataLocation, QDir::separator(), "messageLog.txt");
}
/************************************************
* @brief get File Error Message.
* \fn getFileErrorMessage
 ***********************************************/
QString getFileErrorMessage(const QString &thisAppDataLocation)
{
    return QString("%1: %2").arg(QObject::tr("Failed to open log file"), thisAppDataLocation);
}
/************************************************
* @brief set Message Log File.
* \fn setMessageLogFile
 ***********************************************/
bool setMessageLogFile(const QString &thisAppName, const QString &thisAppDataLocation)
{
    QString theFullFilePath = getMessageLogFile(thisAppDataLocation);
    if (QFileInfo::exists(theFullFilePath) && QFileInfo(theFullFilePath).isFile())
    { QFile::remove(theFullFilePath); }
    QFile theFile(theFullFilePath);
    if(!theFile.open(QFile::WriteOnly | QFile::Text | QIODevice::Truncate))
    {
        QString theErrorMessage = QString("%1: %2").arg(QObject::tr("Could not open log file"), theFullFilePath);
        std::cout << theErrorMessage.toStdString() << std::endl;
        return false;
    }
    // Write to log file
    QTextStream theFileStream(&theFile);
    const QDateTime theDateTimeStamp = QDateTime::currentDateTime();
    QString theDateStamp = QString("%1: %2 - %3 %4").arg(QObject::tr("Log File"), thisAppName, theDateTimeStamp.toString("dd MMM yyyy hh:mm:ss"), theDateTimeStamp.timeZoneAbbreviation());
    theFileStream << theDateStamp  << '\n';
    theFile.flush();
    theFile.close();
    if (QFileInfo::exists(theFullFilePath) && QFileInfo(theFullFilePath).isFile())
    {
        myLogFile = theFullFilePath;
        return true;
    }
    else
    { return false; }
}
/************************************************
* @brief log Events.
* \fn logEvents
 ***********************************************/
void logEvents(const QString &thisMessage)
{
    QFile theFileHandle(myLogFile);
    if(!theFileHandle.open( QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text ))
    {
        // Do not use qDebug() since that is a loop
        std::cout << QObject::tr("Log File failed to open").toStdString() << ": " << myLogFile.toStdString() << std::endl;
        return;
    }
    QTextStream theFileStream(&theFileHandle);
    theFileStream << thisMessage;
    theFileStream.flush();
    theFileHandle.close();
}
/************************************************
 * @brief I use a special Message Handler to format the output of Error.
 * \fn myMessageHandler
 ***********************************************/
void myMessageHandler(QtMsgType thisType, const QMessageLogContext &thisContext, const QString &thisMsg)
{
    QByteArray theLocalMsg  = thisMsg.toLocal8Bit();
    const char *theFile     = thisContext.file ? thisContext.file : "";
    const char *theFunction = thisContext.function ? thisContext.function : "";
    //
    switch (thisType)
    {
    case QtDebugMsg:
        logEvents(QString("Debug: %1 (%2:%3, %4)\n").arg(theLocalMsg.constData(), theFile, QString::number(thisContext.line), theFunction));
        fprintf(stderr, "Debug: %s (%s:%u, %s)\n", theLocalMsg.constData(), theFile, thisContext.line, theFunction);
        break;
    case QtInfoMsg:
        logEvents(QString("Info: %1 (%2:%3, %4)\n").arg(theLocalMsg.constData(), theFile, QString::number(thisContext.line), theFunction));
        fprintf(stderr, "Info: %s (%s:%u, %s)\n", theLocalMsg.constData(), theFile, thisContext.line, theFunction);
        break;
    case QtWarningMsg:
        logEvents(QString("Warning: %1 (%2:%3, %4)\n").arg(theLocalMsg.constData(), theFile, QString::number(thisContext.line), theFunction));
        fprintf(stderr, "Warning: %s (%s:%u, %s)\n", theLocalMsg.constData(), theFile, thisContext.line, theFunction);
        break;
    case QtCriticalMsg:
        logEvents(QString("Critical: %1 (%2:%3, %4)\n").arg(theLocalMsg.constData(), theFile, QString::number(thisContext.line), theFunction));
        fprintf(stderr, "Critical: %s (%s:%u, %s)\n", theLocalMsg.constData(), theFile, thisContext.line, theFunction);
        break;
    case QtFatalMsg:
        logEvents(QString("Fatal: %1 (%2:%3, %4)\n").arg(theLocalMsg.constData(), theFile, QString::number(thisContext.line), theFunction));
        fprintf(stderr, "Fatal: %s (%s:%u, %s)\n", theLocalMsg.constData(), theFile, thisContext.line, theFunction);
        break;
    }
}
/************************************************
 * @brief Utils.
 * Utils
 * Workaround: As of Qt 5.4 QtQuick does not expose QUrl::fromUserInput.
 ***********************************************/
class Utils : public QObject
{
    Q_OBJECT
        public:
                 Utils(QObject* parent = nullptr) : QObject(parent) { }
    Q_INVOKABLE static QUrl fromUserInput(const QString& userInput);
};
/************************************************
 * @brief fromUserInput.
 * fromUserInput
 ***********************************************/
QUrl Utils::fromUserInput(const QString& userInput)
{
    if (userInput.isEmpty()) return QUrl::fromUserInput("about:blank");
    const QUrl result = QUrl::fromUserInput(userInput);
    return result.isValid() ? result : QUrl::fromUserInput("about:blank");
}
/************************************************
 * @brief main.moc.
 * main.moc must be included below to define above
 ***********************************************/
#include "main.moc"
/************************************************
 * @brief main.
 * main
 ***********************************************/
int main(int argc, char *argv[])
{
    QString theAppName = "QtLingo";
    QString theAppDisplayName = "Qt Lingo";
    bool isDebugMessage = true;
    //
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    //
    #ifdef MY_QML
    QGuiApplication theApplication(argc, argv);
    QGuiApplication::setWindowIcon(QIcon(":/images/logo32.png"));
    QQmlApplicationEngine theEngine;
    QQmlContext *theContext = theEngine.rootContext();
    //
    QGuiApplication::setApplicationDisplayName(QCoreApplication::translate("main", theAppDisplayName.toLocal8Bit()));
    #else
    // Load Resource File QtLingo.qrc before creating Application
    Q_INIT_RESOURCE(QtLingo);
    QApplication theApplication(argc, argv);
    QApplication::setWindowIcon(QIcon(":/images/logo32.png"));
    #endif

    // Setup the Application for MyOrgSettings
    theApplication.setOrganizationName(theAppName);
    theApplication.setApplicationName(theAppName);
    theApplication.setApplicationDisplayName(theAppDisplayName);
    theApplication.setApplicationVersion(VERSION);
    //
    #ifdef MY_QML
    MyLanguageModel *theLanguageModel = new MyLanguageModel(theEngine, qApp);
    #else
    MyLanguageModel *theLanguageModel = new MyLanguageModel(qApp);
    #endif
    theLanguageModel->setTransFilePrefix(theAppName); //!< Prefix of Translation files
    theLanguageModel->setTranslationSource("translations");   //!< Relative Folder for Translation files
    theLanguageModel->setHelpSource("help");                  //!< Relative Folder for Help files
    theLanguageModel->setLanguages();
    //
    theLanguageModel->mySetting->setVersion(VERSION);
    theLanguageModel->mySetting->setIniFileName(theAppName);
    //
    //
    // Run after the Application is created and given a name and before creating MainWindow
    qInstallMessageHandler(myMessageHandler);
    // FIXME what if error
    setMessageLogFile(theApplication.applicationName(), theLanguageModel->mySetting->getAppDataLocation());
//
    #ifdef MY_QML
    //
    theContext->setContextProperty("thisLanguageList", theLanguageModel->getLanguageList());
    // thisDefaultLanguageName
    // FIXME function
    QString theLanguageName =theLanguageModel->mySetting->readSettings(theLanguageModel->mySetting->MY_LOCALE_LANG_NAME, theLanguageModel->getDefaultLanguageCode());
    theContext->setContextProperty("thisDefaultLanguageName", theLanguageName);
    // ComboBox Model
    theContext->setContextProperty("thisLanguageModel", theLanguageModel);
    // isDebugMessage
    theContext->setContextProperty("isDebugMessage", isDebugMessage);
    //
    const QUrl theQmlUrl(QStringLiteral("qrc:/qml/main.qml"));
    QObject::connect(&theEngine, &QQmlApplicationEngine::objectCreated, &theApplication, [theQmlUrl](QObject *obj, const QUrl &objUrl)
        {
            if (!obj && theQmlUrl == objUrl)
            { QCoreApplication::exit(-1); }
        }, Qt::QueuedConnection);
    theEngine.load(theQmlUrl);
    if (theEngine.rootObjects().isEmpty()) return -1;
    #endif

    #ifndef MY_QML
    #ifdef MYLANG
    MainWindow *theMainWindow = new MainWindow(theLanguageModel);
    #else
    MainWindow *theMainWindow = new MainWindow();
    theMainWindow->setLanguageModel(theLanguageModel);
    #endif
    theMainWindow->show();
    #endif
    return theApplication.exec();
}
/******************************* End of File *********************************/
