#include "MyLocalization.h"

/************************************************
 * @brief Translation Files Constructor.
 * MyLocalization
 ***********************************************/
MyLocalization::MyLocalization(QObject *parent, MyOrgSettings *thisSetting ) : QObject(parent), mySetting(thisSetting)
{
    myTranslator = new QTranslator(qApp);
}
/************************************************
 * @brief get Language File.
 * getLanguageFromFile
 * QString thisLangFile = getLanguageFromFile(getTransFilePrefix(), "?.qm");
 ***********************************************/
QString MyLocalization::getLanguageFromFile(const QString &thisPrefix, const QString &thisQmLanguageFile)
{
    setMessage("getLanguageFromFile", Debug);
    return getLocalizerCode(thisPrefix, thisQmLanguageFile);
}
/************************************************
 * @brief get Translation Source.
 * getTranslationSource
 ***********************************************/
QString MyLocalization::getTranslationSource()
{
    setMessage("getTranslationSource", Debug);
    return myTranslationSource;
}
/************************************************
 * @brief set Translation Source.
 * setTranslationSource
 ***********************************************/
void MyLocalization::setTranslationSource(const QString &thisTranslationSource)
{
    setMessage("setTranslationSource", Debug);
    myTranslationSource = thisTranslationSource;
}
/************************************************
 * @brief get Help Source.
 * getHelpSource
 ***********************************************/
QString MyLocalization::getHelpSource()
{
    setMessage("getHelpSource", Debug);
    return myHelpSource;
}
/************************************************
 * @brief set Help Source.
 * setHelpSource
 ***********************************************/
void MyLocalization::setHelpSource(const QString &thisHelpSource)
{
    setMessage("setHelpSource", Debug);
    myHelpSource = thisHelpSource;
}
/************************************************
 * @brief get Trans File Prefix.
 * getTransFilePrefix
 ***********************************************/
QString MyLocalization::getTransFilePrefix()
{
    setMessage("getTransFilePrefix", Debug);
    if (myTransFilePrefix.isEmpty()) { myTransFilePrefix = mySetting->myConstants->MY_TRANSLATION_PREFIX; }
    return myTransFilePrefix;
}
/************************************************
 * @brief set Trans File Prefix setTransFilePrefix("ProjectName");.
 * setTransFilePrefix
 ***********************************************/
void MyLocalization::setTransFilePrefix(const QString &thisTransFilePrefix)
{
    setMessage("setTransFilePrefix", Debug);
    myTransFilePrefix = thisTransFilePrefix;
}
/************************************************
 * @brief load Language.
 * loadLanguage
 ***********************************************/
void MyLocalization::loadLanguage(const QString &thisQmLanguageFile)
{
    setMessage("loadLanguage", Debug);

    if (myTranslator->load(thisQmLanguageFile))
    {
        if (myLastTranslator == nullptr ) { qApp->removeTranslator(myLastTranslator); }
        qApp->installTranslator(myTranslator);
        myLastTranslator = myTranslator;
    }
    else
    {
        qCritical() << "loadLanguage failed";
    }
}
/************************************************
 * @brief get Language File.
 * getLanguageFile
 ***********************************************/
QString MyLocalization::getLanguageFile(const QString &thisLanguage, const QString &thisPath, const QString &thisPrefix)
{
    setMessage("getLanguageFile", Debug);
    const QStringList theQmFiles = findQmFiles(thisPath);
    for (int i = 0; i < theQmFiles.size(); ++i)
    {
        if (languageMatch(thisPrefix, thisLanguage, theQmFiles.at(i)))
            { return theQmFiles.at(i); }
    }
    return "";
}
/************************************************
 * @brief set Debug Message.
 * setDebugMessage
 ***********************************************/
void MyLocalization::setDebugMessage(bool thisState)
{
    isDebugMessage = thisState;
    setMessage("setDebugMessage", Debug);
}
/************************************************
 * @brief get Debug Message.
 * getDebugMessage
 ***********************************************/
bool MyLocalization::getDebugMessage()
{
    setMessage("getDebugMessage", Debug);
    return isDebugMessage;
}
/************************************************
 * @brief language Name From File.
 * languageNameFromFile
 ***********************************************/
QString MyLocalization::languageNameFromFile(const QString &thisTranslationFile)
{
    setMessage("languageNameFromFile", Debug);
    QTranslator translator;
    translator.load(thisTranslationFile);
    // FIXME
    return translator.translate("MainWindow", "English");
}
/************************************************
 * @brief language Match qmFile naming.
 * languageMatch
 ***********************************************/
QString MyLocalization::getLocalizedCodeFromFile(const QString &thisPrefix, const QString &thisQmFile)
{
    setMessage("getLocalizedCodeFromFile", Debug);
    QFileInfo theFileInfo(thisQmFile);

    QString theFileName = theFileInfo.baseName();
    return theFileName.remove(QString("%1_").arg(thisPrefix));
}
/************************************************
 * @brief remove Args like "String %1" list.
 * removeArgs
 ***********************************************/
void MyLocalization::removeArgs(const QString &thisString, const QString &thisTransFile)
{
    setMessage("removeArgs", Debug);
    myRemoveTransArgs.append(QString("%1 |%2| in file %3").arg(tr("Remove Arguments that use Percent Sign x"), thisString, thisTransFile));
} // end removeArgs
/************************************************
 * @brief file Remove Args "String %1".
 * fileRemoveArgs
 ***********************************************/
void MyLocalization::fileRemoveArgs()
{
    setMessage("fileRemoveArgs", Debug);
    if (!myRemoveTransArgs.isEmpty())
    {
        QString theRemoveFileName = QString("%1").arg(mySetting->getAppDataLocation(), QDir::separator(), "RemoveArgFile.txt");
        mySetting->writeFile(theRemoveFileName, myRemoveTransArgs);
        mySetting->showMessageBox(QObject::tr("Remove Args file is created").toLocal8Bit(), QString("%1: %2 %3 %4").arg(tr("Remove Args"), myRemoveTransArgs, tr("File: "), theRemoveFileName).toLocal8Bit(), mySetting->Warning);
    }
} // end fileRemoveArgs
/************************************************
 * @brief fix Translation File; mostly Arabic gets the value before the ID on some fields.
 * fixTranslationFile
 ***********************************************/
void MyLocalization::fixTranslationFile(const QString &thisFile)
{
    setMessage("fixTranslationFile", Debug);
    if (!mySetting->isFileExists(thisFile)) { mySetting->showMessageBox(tr("File not found").toLocal8Bit(), QString("%1: %2").arg(tr("File not found"), thisFile).toLocal8Bit(), mySetting->Critical); return; }
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
/************************************************
 * @brief language Match qmFile naming.
 * languageMatch
 ***********************************************/
bool MyLocalization::languageMatch(const QString &thisPrefix, const QString &thisLang, const QString &thisQmFile)
{
    setMessage("languageMatch", Debug);
    // qmFile: ProjectName_xx.qm
    QString thisLocalizer = getLocalizedCodeFromFile(thisPrefix, thisQmFile);
    return thisLocalizer == thisLang;
}
/************************************************
 * @brief find Qm Files.
 * findQmFiles
 ***********************************************/
QStringList MyLocalization::findQmFiles(const QString &thisFolder)
{
    setMessage("findQmFiles", Debug);
    QDir dir(QString(":/%1").arg(thisFolder));
    QStringList fileNames = dir.entryList(QStringList("*.qm"), QDir::Files, QDir::Name);
    for (QString &fileName : fileNames)
        { fileName = dir.filePath(fileName); }
    return fileNames;
}
/************************************************
 * @brief find Ts Files.
 * findTsFiles
 ***********************************************/
QStringList MyLocalization::findTsFiles(const QString &thisFolder)
{
    setMessage("findTsFiles", Debug);
    QDir dir(thisFolder);
    QStringList fileNames = dir.entryList(QStringList("*.ts"), QDir::Files, QDir::Name);
    for (QString &fileName : fileNames)
        { fileName = dir.filePath(fileName); }
    return fileNames;
}/************************************************
 * @brief get Localizer Code.
 * getLocalizerCode
 ***********************************************/
QString MyLocalization::getLocalizerCode(const QString &thisPrefix, const QString &thisQmFile)
{
    setMessage("getLocalizerCode", Debug);
    return languageCodeToName(getLocalizedCodeFromFile(thisPrefix, thisQmFile));
}
/************************************************
 * @brief get Lang Code.
 * getLangCode
 ***********************************************/
QString MyLocalization::getLangCode(const QString &thisString)
{
    setMessage("getLangCode", Debug);
    QString theLangCode = thisString;
    if (theLangCode.indexOf('_') < 0) { return ""; }
    if (theLangCode.indexOf('.') > 0)
        { theLangCode = theLangCode.mid(0, theLangCode.indexOf('.')); }
    return theLangCode.mid(theLangCode.indexOf('_') + 1);
}
/************************************************
 * @brief Added by Light-Wizzard language Name to Code.
 * languageNameToCode
 ***********************************************/
QString MyLocalization::languageNameToCode(const QString &lang)
{
    setMessage("languageNameToCode", Debug);
    return s_genericLanguageNameToCode.value(lang);
} // end languageNameToCode
/************************************************
 * languageCodeToName
 * @brief Added by Light-Wizzard language Code to Name.
 ***********************************************/
QString MyLocalization::languageCodeToName(const QString &lang)
{
    setMessage("languageCodeToName", Debug);
    return s_genericLanguageCodeToName.value(lang);
} // end languageCodeToName
/************************************************
 * @brief read Language.
 * readLanguage
 ***********************************************/
QString MyLocalization::readLanguage()
{
    setMessage("readLanguage", Debug);
    QString theCode = language(QLocale());
    setLanguageCode(mySetting->readSettings(mySetting->myConstants->MY_LOCALE_LANG_CODE, theCode));
    return myLanguageCode;
}
/************************************************
 * @brief write Language.
 * writeLanguage
 ***********************************************/
void MyLocalization::writeLanguage(const QString &thisCurrentLanguageCode)
{
    setMessage("writeLanguage", Debug);
    setLanguageCode(thisCurrentLanguageCode);
    mySetting->writeSettings(mySetting->myConstants->MY_LOCALE_LANG_CODE, thisCurrentLanguageCode);
}
/************************************************
 * @brief set Debug Message.
 * setDebugMessage
 ***********************************************/
void MyLocalization::setLanguageCode(const QString &thisLanguageCode)
{
    setMessage("setLanguageCode", Debug);
    myLanguageCode = thisLanguageCode;
}
/************************************************
 * @brief get Debug Message.
 * getDebugMessage
 ***********************************************/
QString MyLocalization::getLanguageCode()
{
    setMessage("getLanguageCode", Debug);
    if (myLanguageCode.isEmpty())
    {
        QString theLangCode = language(QLocale());
        myLanguageCode = mySetting->readSettings(MY_LANG_CODE, theLangCode);
    }
    return myLanguageCode;
}
/************************************************
 * @brief language.
 * language
 ***********************************************/
void MyLocalization::setMainLoaded(bool thisMainLoaded)
{
    setMessage("setMainLoaded", Debug);
    isMainLoaded = thisMainLoaded;
}
/************************************************
 * @brief get Main Loaded.
 * getMainLoaded
 ***********************************************/
bool MyLocalization::getMainLoaded()
{
    setMessage("getMainLoaded", Debug);
    return isMainLoaded;
}
/************************************************
 * @brief language.
 * language
 * @param thisLocale QLocale given QLocale() returns Country Code
 ***********************************************/
QString MyLocalization::language(const QLocale &thisLocale)
{
    setMessage("language", Debug);
    switch (thisLocale.language())
    {
        case QLocale::Afrikaans:        return QStringLiteral("af");
        case QLocale::Albanian:         return QStringLiteral("sq");
        case QLocale::Amharic:          return QStringLiteral("am");
        case QLocale::Arabic:           return QStringLiteral("ar");
        case QLocale::Armenian:         return QStringLiteral("hy");
        case QLocale::Azerbaijani:      return QStringLiteral("az");
        case QLocale::Bashkir:          return QStringLiteral("ba");
        case QLocale::Basque:           return QStringLiteral("eu");
        case QLocale::Belarusian:       return QStringLiteral("be");
        case QLocale::Bengali:          return QStringLiteral("bn");
        case QLocale::Bosnian:          return QStringLiteral("bs");
        case QLocale::Bulgarian:        return QStringLiteral("bg");
        case QLocale::Catalan:          return QStringLiteral("ca");
        case QLocale::Chinese:          return QStringLiteral("zh-CN");
        case QLocale::LiteraryChinese:  return QStringLiteral("zh-TW");
        case QLocale::Corsican:         return QStringLiteral("co");
        case QLocale::Croatian:         return QStringLiteral("hr");
        case QLocale::Czech:            return QStringLiteral("cs");
        case QLocale::Cantonese:        return QStringLiteral("yue");
        case QLocale::Cebuano:          return QStringLiteral("ceb");
        case QLocale::Chickasaw:        return QStringLiteral("ny");
        case QLocale::Danish:           return QStringLiteral("da");
        case QLocale::Dutch:            return QStringLiteral("nl");
        case QLocale::Esperanto:        return QStringLiteral("eo");
        case QLocale::Estonian:         return QStringLiteral("et");
        case QLocale::Finnish:          return QStringLiteral("fi");
        case QLocale::French:           return QStringLiteral("fr");
        case QLocale::Frisian:          return QStringLiteral("fy");
        case QLocale::Fijian:           return QStringLiteral("fj");
        case QLocale::Galician:         return QStringLiteral("gl");
        case QLocale::Georgian:         return QStringLiteral("ka");
        case QLocale::German:           return QStringLiteral("de");
        case QLocale::Greek:            return QStringLiteral("el");
        case QLocale::Gujarati:         return QStringLiteral("gu");
        case QLocale::Haitian:          return QStringLiteral("ht");
        case QLocale::Hausa:            return QStringLiteral("ha");
        case QLocale::Hawaiian:         return QStringLiteral("haw");
        case QLocale::Hebrew:           return QStringLiteral("he");
        case QLocale::Hindi:            return QStringLiteral("hi");
        case QLocale::Hungarian:        return QStringLiteral("hu");
        //case QLocale::HillMari:       return QStringLiteral("mrj");
        //case QLocale::HmongNjua Hmong:return QStringLiteral("hmn");
        case QLocale::Icelandic:        return QStringLiteral("is");
        case QLocale::Igbo:             return QStringLiteral("ig");
        case QLocale::Indonesian:       return QStringLiteral("id");
        case QLocale::Irish:            return QStringLiteral("ga");
        case QLocale::Italian:          return QStringLiteral("it");
        case QLocale::Japanese:         return QStringLiteral("ja");
        case QLocale::Javanese:         return QStringLiteral("jw");
        case QLocale::Kannada:          return QStringLiteral("kn");
        case QLocale::Kazakh:           return QStringLiteral("kk");
        case QLocale::Khmer:            return QStringLiteral("km");
        case QLocale::Kinyarwanda:      return QStringLiteral("rw");
        case QLocale::Korean:           return QStringLiteral("ko");
        case QLocale::Kurdish:          return QStringLiteral("ku");
        //case QLocale::Klingon:        return QStringLiteral("tlh");
        //case QLocale::KlingonPlqaD:   return QStringLiteral("tlh-Qaak");
        //case QLocale::Kyrgyzstan:     return QStringLiteral("ky"); // Kyrgyz
        case QLocale::Lao:              return QStringLiteral("lo");
        case QLocale::Latin:            return QStringLiteral("la");
        case QLocale::Latvian:          return QStringLiteral("lv");
        case QLocale::Lithuanian:       return QStringLiteral("lt");
        case QLocale::Luxembourgish:    return QStringLiteral("lb");
        //case QLocale::LevantineArabic:return QStringLiteral("apc");
        //case QLocale::Mari:           return QStringLiteral("mhr");
        //case QLocale::Myanmar:        return QStringLiteral("my");
        case QLocale::Papiamento:       return QStringLiteral("pap");
        case QLocale::Macedonian:       return QStringLiteral("mk");
        case QLocale::Malagasy:         return QStringLiteral("mg");
        case QLocale::Malay:            return QStringLiteral("ms");
        case QLocale::Malayalam:        return QStringLiteral("ml");
        case QLocale::Maltese:          return QStringLiteral("mt");
        case QLocale::Maori:            return QStringLiteral("mi");
        case QLocale::Marathi:          return QStringLiteral("mr");
        case QLocale::Mongolian:        return QStringLiteral("mn");
        case QLocale::Nepali:           return QStringLiteral("ne");
        case QLocale::NorwegianBokmal:  return QStringLiteral("no");
        case QLocale::Oriya:            return QStringLiteral("or");
        //case QLocale::QueretaroOtomi: return QStringLiteral("otq");
        case QLocale::Pashto:           return QStringLiteral("ps");
        case QLocale::Persian:          return QStringLiteral("fa");
        case QLocale::Polish:           return QStringLiteral("pl");
        case QLocale::Portuguese:       return QStringLiteral("pt");
        case QLocale::Punjabi:          return QStringLiteral("pa");
        case QLocale::Romanian:         return QStringLiteral("ro");
        case QLocale::Russian:          return QStringLiteral("ru");
        case QLocale::Samoan:           return QStringLiteral("sm");
        case QLocale::Gaelic:           return QStringLiteral("gd");
        case QLocale::Serbian:          return QStringLiteral("sr");
        case QLocale::Shona:            return QStringLiteral("sn");
        case QLocale::Sindhi:           return QStringLiteral("sd");
        case QLocale::Sinhala:          return QStringLiteral("si");
        case QLocale::Slovak:           return QStringLiteral("sk");
        case QLocale::Slovenian:        return QStringLiteral("sl");
        case QLocale::Somali:           return QStringLiteral("so");
        case QLocale::Spanish:          return QStringLiteral("es");
        case QLocale::Sundanese:        return QStringLiteral("su");
        case QLocale::Swahili:          return QStringLiteral("sw");
        case QLocale::Swedish:          return QStringLiteral("sv");
        //case QLocale::SerbianLatin:   return QStringLiteral("sr-Latin");
        //case QLocale::Sesotho:        return QStringLiteral("st");
        case QLocale::Filipino:         return QStringLiteral("fil");
        case QLocale::Tajik:            return QStringLiteral("tg");
        case QLocale::Tamil:            return QStringLiteral("ta");
        case QLocale::Tatar:            return QStringLiteral("tt");
        case QLocale::Telugu:           return QStringLiteral("te");
        case QLocale::Thai:             return QStringLiteral("th");
        case QLocale::Turkish:          return QStringLiteral("tr");
        case QLocale::Turkmen:          return QStringLiteral("tk");
        //case QLocale::Tagalog:        return QStringLiteral("tl");
        case QLocale::Tahitian:         return QStringLiteral("ty");
        case QLocale::Tongan:           return QStringLiteral("to");
        case QLocale::Uighur:           return QStringLiteral("ug");
        case QLocale::Ukrainian:        return QStringLiteral("uk");
        case QLocale::Urdu:             return QStringLiteral("ur");
        case QLocale::Uzbek:            return QStringLiteral("uz");
        //case QLocale::Udmurt:         return QStringLiteral("udm");
        case QLocale::Vietnamese:       return QStringLiteral("vi");
        case QLocale::Welsh:            return QStringLiteral("cy");
        case QLocale::Xhosa:            return QStringLiteral("xh");
        case QLocale::Yiddish:          return QStringLiteral("yi");
        case QLocale::Yoruba:           return QStringLiteral("yo");
        //case QLocale::YucatecMaya:    return QStringLiteral("yua");
        case QLocale::Zulu:             return QStringLiteral("zu");
        default:                        return QStringLiteral("en");
    }
} // end language(const QLocale
/************************************************
 * @brief Added by Light-Wizzard s_genericLanguageCodesName
 * s_genericLanguageCodesName
 ***********************************************/
const QMap<QString, QString> MyLocalization::s_genericLanguageNameToCode =
{
    { QStringLiteral("Auto"),                  QStringLiteral("auto")     },
    { QStringLiteral("Afrikaans"),             QStringLiteral("af")       },
    { QStringLiteral("Albanian"),              QStringLiteral("sq")       },
    { QStringLiteral("Amharic"),               QStringLiteral("am")       },
    { QStringLiteral("Arabic"),                QStringLiteral("ar")       },
    { QStringLiteral("Armenian"),              QStringLiteral("hy")       },
    { QStringLiteral("Azerbaijani"),           QStringLiteral("az")       },
    { QStringLiteral("Bashkir"),               QStringLiteral("ba")       },
    { QStringLiteral("Basque"),                QStringLiteral("eu")       },
    { QStringLiteral("Belarusian"),            QStringLiteral("be")       },
    { QStringLiteral("Bengali"),               QStringLiteral("bn")       },
    { QStringLiteral("Bosnian"),               QStringLiteral("bs")       },
    { QStringLiteral("Bulgarian"),             QStringLiteral("bg")       },
    { QStringLiteral("Cantonese"),             QStringLiteral("yue")      },
    { QStringLiteral("Catalan"),               QStringLiteral("ca")       },
    { QStringLiteral("Cebuano"),               QStringLiteral("ceb")      },
    { QStringLiteral("Chichewa"),              QStringLiteral("ny")       },
    { QStringLiteral("Corsican"),              QStringLiteral("co")       },
    { QStringLiteral("Croatian"),              QStringLiteral("hr")       },
    { QStringLiteral("Czech"),                 QStringLiteral("cs")       },
    { QStringLiteral("Danish"),                QStringLiteral("da")       },
    { QStringLiteral("Dutch"),                 QStringLiteral("nl")       },
    { QStringLiteral("English"),               QStringLiteral("en")       },
    { QStringLiteral("Esperanto"),             QStringLiteral("eo")       },
    { QStringLiteral("Estonian"),              QStringLiteral("et")       },
    { QStringLiteral("Fijian"),                QStringLiteral("fj")       },
    { QStringLiteral("Filipino"),              QStringLiteral("fil")      },
    { QStringLiteral("Finnish"),               QStringLiteral("fi")       },
    { QStringLiteral("French"),                QStringLiteral("fr")       },
    { QStringLiteral("Frisian"),               QStringLiteral("fy")       },
    { QStringLiteral("Galician"),              QStringLiteral("gl")       },
    { QStringLiteral("Georgian"),              QStringLiteral("ka")       },
    { QStringLiteral("German"),                QStringLiteral("de")       },
    { QStringLiteral("Greek"),                 QStringLiteral("el")       },
    { QStringLiteral("Gujarati"),              QStringLiteral("gu")       },
    { QStringLiteral("HaitianCreole"),         QStringLiteral("ht")       },
    { QStringLiteral("Hausa"),                 QStringLiteral("ha")       },
    { QStringLiteral("Hawaiian"),              QStringLiteral("haw")      },
    { QStringLiteral("Hebrew"),                QStringLiteral("he")       },
    { QStringLiteral("HillMari"),              QStringLiteral("mrj")      },
    { QStringLiteral("Hindi"),                 QStringLiteral("hi")       },
    { QStringLiteral("Hmong"),                 QStringLiteral("hmn")      },
    { QStringLiteral("Hungarian"),             QStringLiteral("hu")       },
    { QStringLiteral("Icelandic"),             QStringLiteral("is")       },
    { QStringLiteral("Igbo"),                  QStringLiteral("ig")       },
    { QStringLiteral("Indonesian"),            QStringLiteral("id")       },
    { QStringLiteral("Irish"),                 QStringLiteral("ga")       },
    { QStringLiteral("Italian"),               QStringLiteral("it")       },
    { QStringLiteral("Japanese"),              QStringLiteral("ja")       },
    { QStringLiteral("Javanese"),              QStringLiteral("jw")       },
    { QStringLiteral("Kannada"),               QStringLiteral("kn")       },
    { QStringLiteral("Kazakh"),                QStringLiteral("kk")       },
    { QStringLiteral("Khmer"),                 QStringLiteral("km")       },
    { QStringLiteral("Kinyarwanda"),           QStringLiteral("rw")       },
    { QStringLiteral("Klingon"),               QStringLiteral("tlh")      },
    { QStringLiteral("KlingonPlqaD"),          QStringLiteral("tlh-Qaak") },
    { QStringLiteral("Korean"),                QStringLiteral("ko")       },
    { QStringLiteral("Kurdish"),               QStringLiteral("ku")       },
    { QStringLiteral("Kyrgyz"),                QStringLiteral("ky")       },
    { QStringLiteral("Lao"),                   QStringLiteral("lo")       },
    { QStringLiteral("Latin"),                 QStringLiteral("la")       },
    { QStringLiteral("Latvian"),               QStringLiteral("lv")       },
    { QStringLiteral("LevantineArabic"),       QStringLiteral("apc")      },
    { QStringLiteral("Lithuanian"),            QStringLiteral("lt")       },
    { QStringLiteral("Luxembourgish"),         QStringLiteral("lb")       },
    { QStringLiteral("Macedonian"),            QStringLiteral("mk")       },
    { QStringLiteral("Malagasy"),              QStringLiteral("mg")       },
    { QStringLiteral("Malay"),                 QStringLiteral("ms")       },
    { QStringLiteral("Malayalam"),             QStringLiteral("ml")       },
    { QStringLiteral("Maltese"),               QStringLiteral("mt")       },
    { QStringLiteral("Maori"),                 QStringLiteral("mi")       },
    { QStringLiteral("Marathi"),               QStringLiteral("mr")       },
    { QStringLiteral("Mari"),                  QStringLiteral("mhr")      },
    { QStringLiteral("Mongolian"),             QStringLiteral("mn")       },
    { QStringLiteral("Myanmar"),               QStringLiteral("my")       },
    { QStringLiteral("Nepali"),                QStringLiteral("ne")       },
    { QStringLiteral("Norwegian"),             QStringLiteral("no")       },
    { QStringLiteral("Oriya"),                 QStringLiteral("or")       },
    { QStringLiteral("Papiamento"),            QStringLiteral("pap")      },
    { QStringLiteral("Pashto"),                QStringLiteral("ps")       },
    { QStringLiteral("Persian"),               QStringLiteral("fa")       },
    { QStringLiteral("Polish"),                QStringLiteral("pl")       },
    { QStringLiteral("Portuguese"),            QStringLiteral("pt")       },
    { QStringLiteral("Punjabi"),               QStringLiteral("pa")       },
    { QStringLiteral("QueretaroOtomi"),        QStringLiteral("otq")      },
    { QStringLiteral("Romanian"),              QStringLiteral("ro")       },
    { QStringLiteral("Russian"),               QStringLiteral("ru")       },
    { QStringLiteral("Samoan"),                QStringLiteral("sm")       },
    { QStringLiteral("ScotsGaelic"),           QStringLiteral("gd")       },
    { QStringLiteral("SerbianCyrillic"),       QStringLiteral("sr")       },
    { QStringLiteral("SerbianLatin"),          QStringLiteral("sr-Latin") },
    { QStringLiteral("Sesotho"),               QStringLiteral("st")       },
    { QStringLiteral("Shona"),                 QStringLiteral("sn")       },
    { QStringLiteral("SimplifiedChinese"),     QStringLiteral("zh-CN")    },
    { QStringLiteral("Sindhi"),                QStringLiteral("sd")       },
    { QStringLiteral("Sinhala"),               QStringLiteral("si")       },
    { QStringLiteral("Slovak"),                QStringLiteral("sk")       },
    { QStringLiteral("Slovenian"),             QStringLiteral("sl")       },
    { QStringLiteral("Somali"),                QStringLiteral("so")       },
    { QStringLiteral("Spanish"),               QStringLiteral("es")       },
    { QStringLiteral("Sundanese"),             QStringLiteral("su")       },
    { QStringLiteral("Swahili"),               QStringLiteral("sw")       },
    { QStringLiteral("Swedish"),               QStringLiteral("sv")       },
    { QStringLiteral("SerbianLatin"),          QStringLiteral("sr-Latin") },
    { QStringLiteral("Tagalog"),               QStringLiteral("tl")       },
    { QStringLiteral("Tahitian"),              QStringLiteral("ty")       },
    { QStringLiteral("Tajik"),                 QStringLiteral("tg")       },
    { QStringLiteral("Tamil"),                 QStringLiteral("ta")       },
    { QStringLiteral("Tatar"),                 QStringLiteral("tt")       },
    { QStringLiteral("Telugu"),                QStringLiteral("te")       },
    { QStringLiteral("Thai"),                  QStringLiteral("th")       },
    { QStringLiteral("Tongan"),                QStringLiteral("to")       },
    { QStringLiteral("TraditionalChinese"),    QStringLiteral("zh-TW")    },
    { QStringLiteral("Turkish"),               QStringLiteral("tr")       },
    { QStringLiteral("Turkmen"),               QStringLiteral("tk")       },
    { QStringLiteral("Udmurt"),                QStringLiteral("udm")      },
    { QStringLiteral("Uighur"),                QStringLiteral("ug")       },
    { QStringLiteral("Ukrainian"),             QStringLiteral("uk")       },
    { QStringLiteral("Urdu"),                  QStringLiteral("ur")       },
    { QStringLiteral("Uzbek"),                 QStringLiteral("uz")       },
    { QStringLiteral("Udmurt"),                QStringLiteral("udm")      },
    { QStringLiteral("Vietnamese"),            QStringLiteral("vi")       },
    { QStringLiteral("Welsh"),                 QStringLiteral("cy")       },
    { QStringLiteral("Xhosa"),                 QStringLiteral("xh")       },
    { QStringLiteral("Yiddish"),               QStringLiteral("yi")       },
    { QStringLiteral("Yoruba"),                QStringLiteral("yo")       },
    { QStringLiteral("YucatecMaya"),           QStringLiteral("yua")      },
    { QStringLiteral("YucatecMaya"),           QStringLiteral("yua")      },
    { QStringLiteral("Zulu"),                  QStringLiteral("zu")       }
}; // end s_genericLanguageNameToCode
/************************************************
 * @brief Added by Light-Wizzard s_genericLanguageCodesName
 * s_genericLanguageCodesName
 ***********************************************/
const QMap<QString, QString> MyLocalization::s_genericLanguageCodeToName =
{
    { QStringLiteral("auto"),       QStringLiteral("Auto")                  },
    { QStringLiteral("af"),         QStringLiteral("Afrikaans")             },
    { QStringLiteral("sq"),         QStringLiteral("Albanian")              },
    { QStringLiteral("am"),         QStringLiteral("Amharic")               },
    { QStringLiteral("ar"),         QStringLiteral("Arabic")                },
    { QStringLiteral("hy"),         QStringLiteral("Armenian")              },
    { QStringLiteral("az"),         QStringLiteral("Azerbaijani")           },
    { QStringLiteral("ba"),         QStringLiteral("Bashkir")               },
    { QStringLiteral("eu"),         QStringLiteral("Basque")                },
    { QStringLiteral("be"),         QStringLiteral("Belarusian")            },
    { QStringLiteral("bn"),         QStringLiteral("Bengali")               },
    { QStringLiteral("bs"),         QStringLiteral("Bosnian")               },
    { QStringLiteral("bg"),         QStringLiteral("Bulgarian")             },
    { QStringLiteral("yue"),        QStringLiteral("Cantonese")             },
    { QStringLiteral("ca"),         QStringLiteral("Catalan")               },
    { QStringLiteral("ceb"),        QStringLiteral("Cebuano")               },
    { QStringLiteral("ny"),         QStringLiteral("Chichewa")              },
    { QStringLiteral("co"),         QStringLiteral("Corsican")              },
    { QStringLiteral("hr"),         QStringLiteral("Croatian")              },
    { QStringLiteral("cs"),         QStringLiteral("Czech")                 },
    { QStringLiteral("da"),         QStringLiteral("Danish")                },
    { QStringLiteral("nl"),         QStringLiteral("Dutch")                 },
    { QStringLiteral("en"),         QStringLiteral("English")               },
    { QStringLiteral("eo"),         QStringLiteral("Esperanto")             },
    { QStringLiteral("et"),         QStringLiteral("Estonian")              },
    { QStringLiteral("fj"),         QStringLiteral("Fijian")                },
    { QStringLiteral("fil"),        QStringLiteral("Filipino")              },
    { QStringLiteral("fi"),         QStringLiteral("Finnish")               },
    { QStringLiteral("fr"),         QStringLiteral("French")                },
    { QStringLiteral("fy"),         QStringLiteral("Frisian")               },
    { QStringLiteral("gl"),         QStringLiteral("Galician")              },
    { QStringLiteral("ka"),         QStringLiteral("Georgian")              },
    { QStringLiteral("de"),         QStringLiteral("German")                },
    { QStringLiteral("el"),         QStringLiteral("Greek")                 },
    { QStringLiteral("gu"),         QStringLiteral("Gujarati")              },
    { QStringLiteral("ht"),         QStringLiteral("HaitianCreole")         },
    { QStringLiteral("ha"),         QStringLiteral("Hausa")                 },
    { QStringLiteral("haw"),        QStringLiteral("Hawaiian")              },
    { QStringLiteral("he"),         QStringLiteral("Hebrew")                },
    { QStringLiteral("mrj"),        QStringLiteral("HillMari")              },
    { QStringLiteral("hi"),         QStringLiteral("Hindi")                 },
    { QStringLiteral("hmn"),        QStringLiteral("Hmong")                 },
    { QStringLiteral("hu"),         QStringLiteral("Hungarian")             },
    { QStringLiteral("is"),         QStringLiteral("Icelandic")             },
    { QStringLiteral("ig"),         QStringLiteral("Igbo")                  },
    { QStringLiteral("id"),         QStringLiteral("Indonesian")            },
    { QStringLiteral("ga"),         QStringLiteral("Irish")                 },
    { QStringLiteral("it"),         QStringLiteral("Italian")               },
    { QStringLiteral("ja"),         QStringLiteral("Japanese")              },
    { QStringLiteral("jw"),         QStringLiteral("Javanese")              },
    { QStringLiteral("kn"),         QStringLiteral("Kannada")               },
    { QStringLiteral("kk"),         QStringLiteral("Kazakh")                },
    { QStringLiteral("km"),         QStringLiteral("Khmer")                 },
    { QStringLiteral("rw"),         QStringLiteral("Kinyarwanda")           },
    { QStringLiteral("tlh"),        QStringLiteral("Klingon")               },
    { QStringLiteral("tlh-Qaak"),   QStringLiteral("KlingonPlqaD")          },
    { QStringLiteral("ko"),         QStringLiteral("Korean")                },
    { QStringLiteral("ku"),         QStringLiteral("Kurdish")               },
    { QStringLiteral("ky"),         QStringLiteral("Kyrgyz")                },
    { QStringLiteral("lo"),         QStringLiteral("Lao")                   },
    { QStringLiteral("la"),         QStringLiteral("Latin")                 },
    { QStringLiteral("lv"),         QStringLiteral("Latvian")               },
    { QStringLiteral("apc"),        QStringLiteral("LevantineArabic")       },
    { QStringLiteral("lt"),         QStringLiteral("Lithuanian")            },
    { QStringLiteral("lb"),         QStringLiteral("Luxembourgish")         },
    { QStringLiteral("mk"),         QStringLiteral("Macedonian")            },
    { QStringLiteral("mg"),         QStringLiteral("Malagasy")              },
    { QStringLiteral("ms"),         QStringLiteral("Malay")                 },
    { QStringLiteral("ml"),         QStringLiteral("Malayalam")             },
    { QStringLiteral("mt"),         QStringLiteral("Maltese")               },
    { QStringLiteral("mi"),         QStringLiteral("Maori")                 },
    { QStringLiteral("mr"),         QStringLiteral("Marathi")               },
    { QStringLiteral("mhr"),        QStringLiteral("Mari")                  },
    { QStringLiteral("mn"),         QStringLiteral("Mongolian")             },
    { QStringLiteral("my"),         QStringLiteral("Myanmar")               },
    { QStringLiteral("ne"),         QStringLiteral("Nepali")                },
    { QStringLiteral("no"),         QStringLiteral("Norwegian")             },
    { QStringLiteral("or"),         QStringLiteral("Oriya")                 },
    { QStringLiteral("pap"),        QStringLiteral("Papiamento")            },
    { QStringLiteral("ps"),         QStringLiteral("Pashto")                },
    { QStringLiteral("fa"),         QStringLiteral("Persian")               },
    { QStringLiteral("pl"),         QStringLiteral("Polish")                },
    { QStringLiteral("pt"),         QStringLiteral("Portuguese")            },
    { QStringLiteral("pa"),         QStringLiteral("Punjabi")               },
    { QStringLiteral("otq"),        QStringLiteral("QueretaroOtomi")        },
    { QStringLiteral("ro"),         QStringLiteral("Romanian")              },
    { QStringLiteral("ru"),         QStringLiteral("Russian")               },
    { QStringLiteral("sm"),         QStringLiteral("Samoan")                },
    { QStringLiteral("gd"),         QStringLiteral("ScotsGaelic")           },
    { QStringLiteral("sr"),         QStringLiteral("SerbianCyrillic")       },
    { QStringLiteral("sr-Latin"),   QStringLiteral("SerbianLatin")          },
    { QStringLiteral("st"),         QStringLiteral("Sesotho")               },
    { QStringLiteral("sn"),         QStringLiteral("Shona")                 },
    { QStringLiteral("zh-CN"),      QStringLiteral("SimplifiedChinese")     },
    { QStringLiteral("sd"),         QStringLiteral("Sindhi")                },
    { QStringLiteral("si"),         QStringLiteral("Sinhala")               },
    { QStringLiteral("sk"),         QStringLiteral("Slovak")                },
    { QStringLiteral("sl"),         QStringLiteral("Slovenian")             },
    { QStringLiteral("so"),         QStringLiteral("Somali")                },
    { QStringLiteral("es"),         QStringLiteral("Spanish")               },
    { QStringLiteral("su"),         QStringLiteral("Sundanese")             },
    { QStringLiteral("sw"),         QStringLiteral("Swahili")               },
    { QStringLiteral("sv"),         QStringLiteral("Swedish")               },
    { QStringLiteral("tl"),         QStringLiteral("Tagalog")               },
    { QStringLiteral("ty"),         QStringLiteral("Tahitian")              },
    { QStringLiteral("tg"),         QStringLiteral("Tajik")                 },
    { QStringLiteral("ta"),         QStringLiteral("Tamil")                 },
    { QStringLiteral("tt"),         QStringLiteral("Tatar")                 },
    { QStringLiteral("te"),         QStringLiteral("Telugu")                },
    { QStringLiteral("th"),         QStringLiteral("Thai")                  },
    { QStringLiteral("to"),         QStringLiteral("Tongan")                },
    { QStringLiteral("zh-TW"),      QStringLiteral("TraditionalChinese")    },
    { QStringLiteral("tr"),         QStringLiteral("Turkish")               },
    { QStringLiteral("tk"),         QStringLiteral("Turkmen")               },
    { QStringLiteral("udm"),        QStringLiteral("Udmurt")                },
    { QStringLiteral("ug"),         QStringLiteral("Uighur")                },
    { QStringLiteral("uk"),         QStringLiteral("Ukrainian")             },
    { QStringLiteral("ur"),         QStringLiteral("Urdu")                  },
    { QStringLiteral("uz"),         QStringLiteral("Uzbek")                 },
    { QStringLiteral("vi"),         QStringLiteral("Vietnamese")            },
    { QStringLiteral("cy"),         QStringLiteral("Welsh")                 },
    { QStringLiteral("xh"),         QStringLiteral("Xhosa")                 },
    { QStringLiteral("yi"),         QStringLiteral("Yiddish")               },
    { QStringLiteral("yo"),         QStringLiteral("Yoruba")                },
    { QStringLiteral("yua"),        QStringLiteral("YucatecMaya")           },
    { QStringLiteral("zu"),         QStringLiteral("Zulu")                  }
}; // end s_genericLanguageCodeToName
/************************************************
 * @brief set Message.
 * setMessage
 ***********************************************/
void MyLocalization::setMessage(const QString &thisMessage, MyMessageTypes thisMessageType)
{
    if (isDebugMessage && isMainLoaded) { return; }
    switch (thisMessageType)
    {
        case Information:
            mySetting->showMessageBox(thisMessage, thisMessage, mySetting->Information);
            break;
        case Warning:
            mySetting->showMessageBox(thisMessage, thisMessage, mySetting->Warning);
            break;
        case Critical:
            mySetting->showMessageBox(thisMessage, thisMessage, mySetting->Critical);
            break;
        case Question:
        case Debug:
            qDebug() << thisMessage;
            //std::cout << thisMessage.toStdString() << std::endl;
            break;
    }
}
/******************************* End of File *********************************/
