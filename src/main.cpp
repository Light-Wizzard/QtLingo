#include "MainWindow.h"
/*! ***************************************************************************
   \fn getAppDataLocation
   \brief get App Data Location
 *************************************************************************** */
QString getAppDataLocation()
{
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
}
/*! ***************************************************************************
   \fn getMessageLogFile
   \brief get Message Log File
 *************************************************************************** */
QString getMessageLogFile()
{
    return QString("%1%2%3").arg(getAppDataLocation(), QDir::separator(), "messageLog.txt");
}
/*! ***************************************************************************
   \fn setMessageLogFile
   \brief set Message Log File
 *************************************************************************** */
QString getFileErrorMessage()
{
    return QString("%1: %2").arg(QObject::tr("Failed to open log file"), getMessageLogFile());
}
/*! ***************************************************************************
   \fn setMessageLogFile
   \brief set Message Log File
 *************************************************************************** */
bool setMessageLogFile()
{
    QString theLogFile = getMessageLogFile();
    if (QFileInfo::exists(theLogFile) && QFileInfo(theLogFile).isFile())
        { QFile::remove(theLogFile); }
    QFile theFile(theLogFile);
    if(!theFile.open(QFile::WriteOnly | QFile::Text))
    {
        QString theErrorMessage = getFileErrorMessage();
        std::cout << theErrorMessage.toStdString() << std::endl;
        return false;
    }
    // Write to log file
    QTextStream theFileStream(&theFile);
    const QDateTime theDateTimeStamp = QDateTime::currentDateTime();
    theFileStream << theDateTimeStamp.toString("MM-yyyy-dd hh:mm:ss") << theDateTimeStamp.timeZoneAbbreviation() << '\n';
    theFile.flush();
    theFile.close();
    if (QFileInfo::exists(theLogFile) && QFileInfo(theLogFile).isFile())
        { return true; }
    else
        { return false; }
}
/*! ***************************************************************************
   \fn logEvents
   \brief log Events
 *************************************************************************** */
void logEvents(const QString &thisMessage)
{
    QFile theFileHandle(getMessageLogFile());
    if(!theFileHandle.open( QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text ))
    {
        // Do not use qDebug() since that is a loop
        QString theErrorMessage = getFileErrorMessage();
        std::cout << theErrorMessage.toStdString() << std::endl;
        return;
    }
    QTextStream theFileStream(&theFileHandle);
    theFileStream << thisMessage;
    theFileStream.flush();
    theFileHandle.close();
}
/*! ***************************************************************************
   \fn myMessageHandler
   \brief I use a special Message Handler to format the output of Error
 *************************************************************************** */
void myMessageHandler(QtMsgType thisType, const QMessageLogContext &thisContext, const QString &thisMsg)
{
    QByteArray localMsg = thisMsg.toLocal8Bit();
    const char *file = thisContext.file ? thisContext.file : "";
    const char *function = thisContext.function ? thisContext.function : "";
    switch (thisType)
    {
        case QtDebugMsg:
            logEvents(QString("Debug: %1 (%2:%3, %4)\n").arg(thisMsg, thisContext.file ? thisContext.file : "", QString::number(thisContext.line), thisContext.function ? thisContext.function : ""));
            fprintf(stderr, "Debug: %s (%s:%u, %s)\n", localMsg.constData(), file, thisContext.line, function);
            break;
        case QtInfoMsg:
            logEvents(QString("Info: %1 (%2:%3, %4)\n").arg(thisMsg, thisContext.file ? thisContext.file : "", QString::number(thisContext.line), thisContext.function ? thisContext.function : ""));
            fprintf(stderr, "Info: %s (%s:%u, %s)\n", localMsg.constData(), file, thisContext.line, function);
            break;
        case QtWarningMsg:
            logEvents(QString("Warning: %1 (%2:%3, %4)\n").arg(thisMsg, thisContext.file ? thisContext.file : "", QString::number(thisContext.line), thisContext.function ? thisContext.function : ""));
            fprintf(stderr, "Warning: %s (%s:%u, %s)\n", localMsg.constData(), file, thisContext.line, function);
            break;
        case QtCriticalMsg:
            logEvents(QString("Critical: %1 (%2:%3, %4)\n").arg(thisMsg, thisContext.file ? thisContext.file : "", QString::number(thisContext.line), thisContext.function ? thisContext.function : ""));
            fprintf(stderr, "Critical: %s (%s:%u, %s)\n", localMsg.constData(), file, thisContext.line, function);
            break;
        case QtFatalMsg:
            logEvents(QString("Fatal: %1 (%2:%3, %4)\n").arg(thisMsg, thisContext.file ? thisContext.file : "", QString::number(thisContext.line), thisContext.function ? thisContext.function : ""));
            fprintf(stderr, "Fatal: %s (%s:%u, %s)\n", localMsg.constData(), file, thisContext.line, function);
            break;
    }
}
/*! ***************************************************************************
   \fn main
   \brief main
 *************************************************************************** */
int main(int argc, char *argv[])
{
    setMessageLogFile(); // FIXME what if error
    qInstallMessageHandler(myMessageHandler);
    // Load Resource File QtLingo.qrc
    Q_INIT_RESOURCE(QtLingo);
    QApplication thisApplication(argc, argv);
    thisApplication.setOrganizationName("QtLingo");
    thisApplication.setApplicationName("QtLingo");
    thisApplication.setApplicationDisplayName("QtLingo");
    thisApplication.setApplicationVersion(VERSION);
    //
    MainWindow thisMainWindow;
    thisMainWindow.show();
    return thisApplication.exec();
}
/******************************* End of File *********************************/
