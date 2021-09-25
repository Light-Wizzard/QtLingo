/************************************************
* @file MyLanguageModel.cpp
* @brief My Abstact Model for QML GUI Translation,
* My Abstact Model is used to help with QML GUI Translation,
* I check variables before setting them to prevent triggers.
* @author Jeffrey Scott Flesher <Jeffrey.Scott.Flesher@>
 ***********************************************/
#include "MyLanguageModel.h"
/************************************************
 * @brief Language Model Constructor.
 * MyLanguageModel
 ***********************************************/
#ifdef MY_QML
MyLanguageModel::MyLanguageModel(QQmlEngine &thisQmlEngine, QObject *parent) : QAbstractListModel(parent), myEngine(thisQmlEngine)
#else
MyLanguageModel::MyLanguageModel(QObject *parent) : QAbstractListModel(parent)
#endif
{
    // Orgization Settings for INI files and Local Storage
    mySetting = new MyOrgSettings(qApp);
}
/************************************************
 * @brief Language Model Deconstructor.
 * ~MyLanguageModel
 ***********************************************/
MyLanguageModel::~MyLanguageModel()
{
    myItems.clear();
    if (myTranslator != nullptr )
    {
        if (!myTranslator->isEmpty())
        {
            qApp->removeTranslator(myTranslator);
        }
    }
}
/************************************************
 * @brief add Item.
 * addItem
 ***********************************************/
void MyLanguageModel::addItem(const QString &thisName, const QString &thisNameTranslated)
{
    mySetting->setMessage("add Item", QString("addItem(%1, %2)").arg(thisName, thisNameTranslated), MyOrgSettings::MyMessageTypes::Debug);
    addItem(MyLanguageData(thisName, thisNameTranslated));
}
/************************************************
 * @brief add Item.
 * addItem
 ***********************************************/
void MyLanguageModel::addItem(const MyLanguageData &thisItem)
{
    mySetting->setMessage("add Item", QString("addItem(%1, %2)").arg(thisItem.name(), thisItem.nameTranslated()), MyOrgSettings::MyMessageTypes::Debug);
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    myItems << thisItem;
    endInsertRows();
}
/************************************************
 * @brief remove Item.
 * removeItem
 ***********************************************/
void MyLanguageModel::removeItem(int thisRow)
{
    mySetting->setMessage("remove Item", QString("removeItem(%1)").arg(thisRow), MyOrgSettings::MyMessageTypes::Debug);
    beginRemoveRows(QModelIndex(), thisRow, thisRow);
    myItems.removeAt(thisRow);
    removeRow(thisRow, QModelIndex());
    endRemoveRows();
}
/************************************************
 * @brief row Count.
 * rowCount
 ***********************************************/
int MyLanguageModel::rowCount(const QModelIndex &parent) const
{
    mySetting->setMessage("row Count", "rowCount", MyOrgSettings::MyMessageTypes::Debug);
    Q_UNUSED(parent);
    return myItems.count();
}
/************************************************
 * @brief data.
 * data
 ***********************************************/
QVariant MyLanguageModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= myItems.count()) { return QVariant(); }
    mySetting->setMessage("data", QString("data(%1, %2)").arg(index.row(), role), MyOrgSettings::MyMessageTypes::Debug);
    const MyLanguageData &Item = myItems[index.row()];
    switch (role)
    {
        case Qt::DisplayRole:    { return QString("%1, %2").arg(index.column()).arg(index.row()); } // Numbers
        case NameRole:           { return Item.name(); }
        case NameTranslatedRole: { return tr(Item.nameTranslated().toLocal8Bit()); } // Translate this value
        default: break;
    }
    return QVariant();
}
/************************************************
 * @brief role Names.
 * roleNames
 ***********************************************/
QHash<int, QByteArray> MyLanguageModel::roleNames() const
{
    mySetting->setMessage("role Names", "roleNames", MyOrgSettings::MyMessageTypes::Debug);
    QHash<int, QByteArray> myRoles;
    myRoles[NameRole] = "name";
    myRoles[NameTranslatedRole] = "translation";
    return myRoles;
}
/************************************************
 * @brief read Language returns myLanguageName.
 * readLanguage
 ***********************************************/
void MyLanguageModel::readLanguage()
{
    mySetting->setMessage("read Language", QString("readLanguage(%1)").arg(myLanguageCode), MyOrgSettings::MyMessageTypes::Debug);
    setLanguageCode(mySetting->readSettings(mySetting->MY_LOCALE_LANG_CODE, getDefaultLanguageCode()));
    setLanguageName(mySetting->readSettings(mySetting->MY_LOCALE_LANG_NAME, getDefaultLanguageName()));
}
/************************************************
 * @brief write Language.
 * writeLanguage
 ***********************************************/
void MyLanguageModel::writeLanguage()
{
    mySetting->setMessage("write Language", QString("writeLanguage(%1, %2)").arg(getLanguageCode(), getLanguageName()), MyOrgSettings::MyMessageTypes::Debug);
    mySetting->writeSettings(mySetting->MY_LOCALE_LANG_CODE, getLanguageCode());
    mySetting->writeSettings(mySetting->MY_LOCALE_LANG_NAME, getLanguageName());
}
/************************************************
 * @brief translate This here because of the Translation File is here.
 * translateThis
 ***********************************************/
QString MyLanguageModel::translateThis(const QString &thisPhrase)
{
    return tr(thisPhrase.toLocal8Bit());
}
/************************************************
 * @brief set MyOrgSettings::MyMessageTypes::Debug Message.
 * setDebugMessage
 ***********************************************/
void MyLanguageModel::setDebugMessage(bool thisState)
{
    isDebugMessage = thisState;
    mySetting->setMessage("set Debug Message", QString("setDebugMessage(%1)").arg(thisState), MyOrgSettings::MyMessageTypes::Debug);
    // Debugging
    mySetting->writeSettings(mySetting->MY_IS_DEBUG_MESSAGE, isDebugMessage ? "true" : "false");
    //isDebugMessage = mySetting->readSettingsBool(mySetting->MY_IS_DEBUG_MESSAGE, isDebugMessage);
}
/************************************************
 * @brief get MyOrgSettings::MyMessageTypes::Debug Message.
 * getDebugMessage
 ***********************************************/
bool MyLanguageModel::getDebugMessage()
{
    mySetting->setMessage("get Debug Message", QString("getDebugMessage(%1)").arg(isDebugMessage), MyOrgSettings::MyMessageTypes::Debug);
    return isDebugMessage;
}
/************************************************
 * @brief language.
 * language
 ***********************************************/
void MyLanguageModel::setMainLoaded(bool thisMainLoaded)
{
    mySetting->setMessage("set Main Loaded", "setMainLoaded", MyOrgSettings::MyMessageTypes::Debug);
    isMainLoaded = thisMainLoaded;
}
/************************************************
 * @brief get Main Loaded.
 * getMainLoaded
 ***********************************************/
bool MyLanguageModel::getMainLoaded()
{
    mySetting->setMessage("get Main Loaded", "getMainLoaded", MyOrgSettings::MyMessageTypes::Debug);
    return isMainLoaded;
}
/************************************************
 * @brief set Languages.
 * setLanguage
 ***********************************************/
void MyLanguageModel::setLanguageList(const QStringList &thisLanguageList)
{
    myLanguages = thisLanguageList;
}
/************************************************
 * @brief set Languages.
 * setLanguage
 ***********************************************/
QStringList &MyLanguageModel::getLanguageList()
{
    return myLanguages;
}
/************************************************
 * @brief set Languages.
 * setLanguages
 ***********************************************/
void MyLanguageModel::setLanguages()
{
    mySetting->setMessage("set Languages", "setLanguages", MyOrgSettings::MyMessageTypes::Debug);
    const QStringList theQmFiles =  getQmFiles(getTranslationSource());
    for (int i = 0; i < theQmFiles.size(); ++i)
    {
        QString theLanguageName = getLanguageFromFile(getTransFilePrefix(), theQmFiles.at(i));
        addItem(MyLanguageData(theLanguageName, tr(theLanguageName.toLocal8Bit())));
        myLanguages.append(theLanguageName);
    } // end for
}
/************************************************
 * @brief set Languages.
 * setLanguage
 ***********************************************/
void MyLanguageModel::setLanguage(const QString &thisLanguageName)
{
    mySetting->setMessage("set Language", QString("setLanguage(%1)").arg(thisLanguageName), MyOrgSettings::MyMessageTypes::Debug);
    if (thisLanguageName.isEmpty()) { return; }
    // Get Language File
    QString theQmLanguageFile = getLanguageFile(languageNameToCode(thisLanguageName), getTranslationSource(), getTransFilePrefix());
    // Load Language
    if (myTranslator != nullptr ) { qApp->removeTranslator(myTranslator); }
    myTranslator = new QTranslator(qApp);
    if (myTranslator->load(theQmLanguageFile))
    {
        qApp->installTranslator(myTranslator);
        /* FIXME in MainWindow.h make sure to add a function to relates in
         * protected slots: virtual void changeEvent(QEvent * event) override;
         * see MainWindow.h and MainWindow.cpp
         */
        #ifdef MY_QML
        myEngine.retranslate();
        #endif
        setLanguageName(thisLanguageName);
        setLanguageCode(languageNameToCode(thisLanguageName));
        writeLanguage();
        emit languageChanged();
    }
    else
    {
        mySetting->setMessage("set Language", QString("%1: %2").arg(tr("loadLanguage failed"), theQmLanguageFile), MyOrgSettings::MyMessageTypes::Critical);
    }
}
/************************************************
 * @brief get Language From File.
 * getLanguageFromFile
 * QString thisLangFile = getLanguageFromFile(getTransFilePrefix(), "?.qm");
 ***********************************************/
QString MyLanguageModel::getLanguageFromFile(const QString &thisPrefix, const QString &thisQmLanguageFile)
{
    mySetting->setMessage("get Language From File", QString("getLanguageFromFile(%1, %2)").arg(thisPrefix, thisQmLanguageFile), MyOrgSettings::MyMessageTypes::Debug);
    return getLocalizerCode(thisPrefix, thisQmLanguageFile);
}
/************************************************
 * @brief get Localizer Code.
 * getLocalizerCode
 ***********************************************/
QString MyLanguageModel::getLocalizerCode(const QString &thisPrefix, const QString &thisQmFile)
{
    mySetting->setMessage("get Localizer Code", QString("getLocalizerCode(%1, %2)").arg(thisPrefix, thisQmFile), MyOrgSettings::MyMessageTypes::Debug);
    QString theQmLang = getLocalizedCodeFromFile(thisPrefix, thisQmFile);
    if (theQmLang.contains("_"))
        { theQmLang = theQmLang.replace("_", "-"); }
    return languageCodeToName(theQmLang);
}
/************************************************
 * @brief get Localized Code From File.
 * getLocalizedCodeFromFile
 ***********************************************/
QString MyLanguageModel::getLocalizedCodeFromFile(const QString &thisPrefix, const QString &thisQmFile)
{
    mySetting->setMessage("get Localized Code From File", QString("getLocalizedCodeFromFile(%1, %2)").arg(thisPrefix, thisQmFile), MyOrgSettings::MyMessageTypes::Debug);
    QFileInfo theFileInfo(thisQmFile);

    QString theFileName = theFileInfo.baseName();
    theFileName = theFileName.remove(QString("%1_").arg(thisPrefix));
    if (theFileName.contains("_"))
    {
        if (!theFileName.contains("zh"))
            { theFileName = theFileName.section("_", 0, 0); }
    }
    return theFileName;
}
/************************************************
 * @brief Get QM Files.
 * getQmFiles
 ***********************************************/
QStringList MyLanguageModel::getQmFiles(const QString &thisFolder)
{
    mySetting->setMessage("getQmFiles", QString("getQmFiles(%1)").arg(thisFolder), MyOrgSettings::MyMessageTypes::Debug);
    // Read from resource file
    QDir dir(QString(":/%1").arg(thisFolder));
    QStringList fileNames = dir.entryList(QStringList("*.qm"), QDir::Files, QDir::Name);
    for (QString &fileName : fileNames)
    {
        fileName = dir.filePath(fileName);
        QFileInfo theFileInfo(fileName);
        QString theLanguage = theFileInfo.baseName();
        theLanguage = getLocalizerCode(myTransFilePrefix, theLanguage);
        myCurrentQmFiles.insert(theLanguage, fileName);
    }
    return fileNames;
}
/************************************************
 * @brief Get TS Files.
 * getTsFiles
 ***********************************************/
QStringList MyLanguageModel::getTsFiles(const QString &thisFolder)
{
    mySetting->setMessage("getTsFiles", QString("getTsFiles(%1)").arg(thisFolder), MyOrgSettings::MyMessageTypes::Debug);
    QDir dir(thisFolder);
    QStringList fileNames = dir.entryList(QStringList("*.ts"), QDir::Files, QDir::Name);
    for (QString &fileName : fileNames)
    { fileName = dir.filePath(fileName); }
    return fileNames;
}
/************************************************
 * @brief get Lang Code.
 * getLangCode
 ***********************************************/
QString MyLanguageModel::getLangCode(const QString &thisString)
{
    mySetting->setMessage("getLangCode", QString("getLangCode(%1)").arg(thisString), MyOrgSettings::MyMessageTypes::Debug);
    QString theLangCode = thisString;
    if (theLangCode.indexOf('_') < 0) { return ""; }
    if (theLangCode.indexOf('.') > 0)
    { theLangCode = theLangCode.mid(0, theLangCode.indexOf('.')); }
    return theLangCode.mid(theLangCode.indexOf('_') + 1);
}
/************************************************
 * @brief get Translation Source.
 * getTranslationSource
 ***********************************************/
QString MyLanguageModel::getTranslationSource()
{
    mySetting->setMessage("get Translation Source", QString("getTranslationSource(%1)").arg(myTranslationSource), MyOrgSettings::MyMessageTypes::Debug);
    return myTranslationSource;
}
/************************************************
 * @brief set Translation Source.
 * setTranslationSource
 ***********************************************/
void MyLanguageModel::setTranslationSource(const QString &thisTranslationSource)
{
    mySetting->setMessage("set Translation Source", QString("setTranslationSource(%1)").arg(thisTranslationSource), MyOrgSettings::MyMessageTypes::Debug);
    myTranslationSource = thisTranslationSource;
}
/************************************************
 * @brief get Help Source.
 * getHelpSource
 ***********************************************/
QString MyLanguageModel::getHelpSource()
{
    mySetting->setMessage("get Help Source", QString("getHelpSource(%1)").arg(myHelpSource), MyOrgSettings::MyMessageTypes::Debug);
    return myHelpSource;
}
/************************************************
 * @brief set Help Source.
 * setHelpSource
 ***********************************************/
void MyLanguageModel::setHelpSource(const QString &thisHelpSource)
{
    mySetting->setMessage("set Help Source", QString("setHelpSource(%1)").arg(thisHelpSource), MyOrgSettings::MyMessageTypes::Debug);
    myHelpSource = thisHelpSource;
}
/************************************************
 * @brief get Trans File Prefix.
 * getTransFilePrefix
 ***********************************************/
QString MyLanguageModel::getTransFilePrefix()
{
    mySetting->setMessage("get Trans File Prefix", QString("getTransFilePrefix(%1)").arg(myTransFilePrefix), MyOrgSettings::MyMessageTypes::Debug);
    return myTransFilePrefix;
}
/************************************************
 * @brief set Trans File Prefix setTransFilePrefix("ProjectName");.
 * setTransFilePrefix
 ***********************************************/
void MyLanguageModel::setTransFilePrefix(const QString &thisTransFilePrefix)
{
    mySetting->setMessage("set Trans File Prefix", QString("setTransFilePrefix(%1)").arg(thisTransFilePrefix), MyOrgSettings::MyMessageTypes::Debug);
    myTransFilePrefix = thisTransFilePrefix;
}
/************************************************
 * @brief get Language File.
 * getLanguageFile
 ***********************************************/
QString MyLanguageModel::getLanguageFile(const QString &thisLanguageCode, const QString &thisPath, const QString &thisPrefix)
{
    mySetting->setMessage("get Language File", QString("getLanguageFile(%1, %2, %3)").arg(thisLanguageCode, thisPath, thisPrefix), MyOrgSettings::MyMessageTypes::Debug);
    QString theLang = thisLanguageCode;
    if (theLang.contains("-"))
        { theLang = theLang.replace("-", "_"); }
    const QStringList theQmFiles = getQmFiles(thisPath);
    // FIXME setLanguages() read from internal db myCurrentQmFiles
    for (int i = 0; i < theQmFiles.size(); ++i)
    {
        if (languageMatch(thisPrefix, theLang, theQmFiles.at(i)))
            { return theQmFiles.at(i); }
    }
    return "";
}
/************************************************
 * @brief language Match qmFile naming.
 * languageMatch
 ***********************************************/
bool MyLanguageModel::languageMatch(const QString &thisPrefix, const QString &thisLang, const QString &thisQmFile)
{
    mySetting->setMessage("language Match", QString("languageMatch(%1, %2, %3)").arg(thisPrefix, thisLang, thisQmFile), MyOrgSettings::MyMessageTypes::Debug);
    // qmFile: ProjectName_xx.qm
    QString theLang = thisLang;
    QString theLocalizer = getLocalizedCodeFromFile(thisPrefix, thisQmFile);
    if (theLocalizer.contains("_"))
        { theLocalizer = theLocalizer.section("_", 0, 0); }
    if (thisLang.contains("_"))
        { theLang = thisLang.section("_", 0, 0); }
    return theLocalizer == theLang;
}
/************************************************
 * @brief get Default Language Code.
 * getDefaultLanguageCode
 ***********************************************/
QString MyLanguageModel::getDefaultLanguageCode()
{
    mySetting->setMessage("get Default LanguageCode", QString("getDefaultLanguageCode(%1)").arg(language(QLocale())), MyOrgSettings::MyMessageTypes::Debug);
    return language(QLocale());
}
/************************************************
 * @brief get Default Lanuage Name.
 * getDefaultLanuageName
 ***********************************************/
QString MyLanguageModel::getDefaultLanguageName()
{
    mySetting->setMessage("get Default Lanuage Name", QString("getDefaultLanuageName=%1").arg(getLanguageName()), MyOrgSettings::MyMessageTypes::Debug);
    return getLanguageName();
}
/************************************************
 * @brief set Language Code.
 * setLanguageCode
 ***********************************************/
void MyLanguageModel::setLanguageCode(const QString &thisLanguageCode)
{
    mySetting->setMessage("set Language Code", QString("setLanguageCode(%1)").arg(thisLanguageCode), MyOrgSettings::MyMessageTypes::Debug);
    myLanguageCode = thisLanguageCode;
}
/************************************************
 * @brief get Language Code gurantees myLanguageCode is set to Default if not set.
 * getLanguageCode
 ***********************************************/
QString MyLanguageModel::getLanguageCode()
{
    if (myLanguageCode.isEmpty())
        { setLanguageCode(getDefaultLanguageCode()); }
    mySetting->setMessage("get Language Code", QString("getLanguageCode(%1)").arg(myLanguageCode), MyOrgSettings::MyMessageTypes::Debug);
    return myLanguageCode;
}
/************************************************
 * @brief set Language Name.
 * setLanguageName
 ***********************************************/
void MyLanguageModel::setLanguageName(const QString &thisLanguageName)
{
    mySetting->setMessage("set Language Name", QString("setLanguageName(%1)").arg(thisLanguageName), MyOrgSettings::MyMessageTypes::Debug);
    myLanguageName = thisLanguageName;
}
/************************************************
 * @brief get Language Name gurantees myLanguageName is set to Default if not set.
 * getLanguageName
 ***********************************************/
QString MyLanguageModel::getLanguageName()
{
    if (myLanguageName.isEmpty())
        { setLanguageName(languageCodeToName(getDefaultLanguageCode())); }
    mySetting->setMessage("get Language Name", QString("getLanguageName(%1)").arg(myLanguageName), MyOrgSettings::MyMessageTypes::Debug);
    return myLanguageName;
}
/************************************************
 * @brief language Code To Name.
 * languageCodeToName
 ***********************************************/
QString MyLanguageModel::languageCodeToName(const QString &thisLangageCode)
{
    mySetting->setMessage("language Code To Name", QString("languageCodeToName(%1)").arg(s_genericLanguageCodeToName.value(thisLangageCode)), MyOrgSettings::MyMessageTypes::Debug);
    return s_genericLanguageCodeToName.value(thisLangageCode);
} // end languageCodeToName
/************************************************
 * @brief language Name to Code.
 * languageNameToCode
 ***********************************************/
QString MyLanguageModel::languageNameToCode(const QString &lang)
{
    mySetting->setMessage("language Name To Code", QString("languageNameToCode(%1)").arg(s_genericLanguageNameToCode.value(lang)), MyOrgSettings::MyMessageTypes::Debug);
    return s_genericLanguageNameToCode.value(lang);
} // end languageNameToCode
/************************************************
 * @brief s_genericLanguageCodesName
 * s_genericLanguageCodesName
 ***********************************************/
const QMap<QString, QString> MyLanguageModel::s_genericLanguageCodeToName =
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
 * @brief language.
 * language
 * @param thisLocale QLocale given QLocale() returns Country Code
 ***********************************************/
QString MyLanguageModel::language(const QLocale &thisLocale)
{
    mySetting->setMessage("language", QString("language(%1)").arg(thisLocale.language()), MyOrgSettings::MyMessageTypes::Debug);
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
        //case QLocale::Kyrgyzstan:     return QStringLiteral("ky");
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
        default:
            if (thisLocale.name() == "HaitianCreole")
                { return QStringLiteral("ht"); }
            else if (thisLocale.name() == "HillMari")
                { return QStringLiteral("mrj"); }
            else if (thisLocale.name() == "Hmong")
                { return QStringLiteral("hmn"); }
            else if (thisLocale.name() == "Klingon")
                { return QStringLiteral("tlh"); }
            else if (thisLocale.name() == "KlingonPlqaD")
                { return QStringLiteral("tlh-Qaak"); }
            else if (thisLocale.name() == "Kyrgyz")
                { return QStringLiteral("ky"); }
            else if (thisLocale.name() == "LevantineArabic")
                { return QStringLiteral("apc"); }
            else if (thisLocale.name() == "Mari")
                { return QStringLiteral("mhr"); }
            else if (thisLocale.name() == "Myanmar")
                { return QStringLiteral("my"); }
            else if (thisLocale.name() == "ny")
                { return QStringLiteral("Chichewa"); }
            else if (thisLocale.name() == "QueretaroOtomi")
                { return QStringLiteral("otq"); }
            else if (thisLocale.name() == "ScotsGaelic")
                { return QStringLiteral("gd"); }
            else if (thisLocale.name() == "SerbianCyrillic")
                { return QStringLiteral("sr"); }
            else if (thisLocale.name() == "SerbianLatin")
                { return QStringLiteral("sr-Latin"); }
            else if (thisLocale.name() == "Sesotho")
                { return QStringLiteral("st"); }
            else if (thisLocale.name() == "Tagalog")
                { return QStringLiteral("tl"); }
            else if (thisLocale.name() == "Udmurt")
                { return QStringLiteral("udm"); }
            else if (thisLocale.name() == "YucatecMaya")
                { return QStringLiteral("yua"); }
            return QStringLiteral("en");
    }
} // end language(const QLocale
/************************************************
 * @brief Added by Light-Wizzard s_genericLanguageCodesName
 * s_genericLanguageCodesName
 ***********************************************/
const QMap<QString, QString> MyLanguageModel::s_genericLanguageNameToCode =
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
 * @brief language Name.
 * languageName
 ***********************************************/
QString MyLanguageModel::languageName(const QLocale &thisLocale)
{
    mySetting->setMessage("languageName", QString("languageName(%1)").arg(thisLocale.language()), MyOrgSettings::MyMessageTypes::Debug);
    switch (thisLocale.language())
    {
        case QLocale::Afrikaans:             return tr("Afrikaans");
        case QLocale::Albanian:              return tr("Albanian");
        case QLocale::Amharic:               return tr("Amharic");
        case QLocale::Arabic:                return tr("Arabic");
        case QLocale::Armenian:              return tr("Armenian");
        case QLocale::Azerbaijani:           return tr("Azeerbaijani");
        case QLocale::Basque:                return tr("Basque");
        case QLocale::Bashkir:               return tr("Bashkir");
        case QLocale::Belarusian:            return tr("Belarusian");
        case QLocale::Bengali:               return tr("Bengali");
        case QLocale::Bosnian:               return tr("Bosnian");
        case QLocale::Bulgarian:             return tr("Bulgarian");
        case QLocale::Catalan:               return tr("Catalan");
        case QLocale::Cantonese:             return tr("Cantonese");
        case QLocale::Cebuano:               return tr("Cebuano");
        case QLocale::Chinese:               return tr("SimplifiedChinese");
        case QLocale::LiteraryChinese:       return tr("TraditionalChinese");
        case QLocale::Corsican:              return tr("Corsican");
        case QLocale::Croatian:              return tr("Croatian");
        case QLocale::Czech:                 return tr("Czech");
        case QLocale::Danish:                return tr("Danish");
        case QLocale::Dutch:                 return tr("Dutch");
        case QLocale::English:               return tr("English");
        case QLocale::Esperanto:             return tr("Esperanto");
        case QLocale::Estonian:              return tr("Estonian");
        case QLocale::Fijian:                return tr("Fijian");
        case QLocale::Filipino:              return tr("Filipino");
        case QLocale::Finnish:               return tr("Finnish");
        case QLocale::French:                return tr("French");
        case QLocale::Frisian:               return tr("Frisian");
        case QLocale::Galician:              return tr("Galician");
        case QLocale::Georgian:              return tr("Georgian");
        case QLocale::German:                return tr("German");
        case QLocale::Greek:                 return tr("Greek");
        case QLocale::Gujarati:              return tr("Gujarati");
        //case QLocale::HaitianCreole:       return tr("Haitian Creole");
        case QLocale::Hausa:                 return tr("Hausa");
        case QLocale::Hawaiian:              return tr("Hawaiian");
        case QLocale::Hebrew:                return tr("Hebrew");
        //case QLocale::HillMari:            return tr("Hill Mari");
        case QLocale::Hindi:                 return tr("Hindi");
        //case QLocale::Hmong:               return tr("Hmong");
        case QLocale::Hungarian:             return tr("Hungarian");
        case QLocale::Icelandic:             return tr("Icelandic");
        case QLocale::Igbo:                  return tr("Igbo");
        case QLocale::Indonesian:            return tr("Indonesian");
        case QLocale::Irish:                 return tr("Irish");
        case QLocale::Italian:               return tr("Italian");
        case QLocale::Japanese:              return tr("Japanese");
        case QLocale::Javanese:              return tr("Javanese");
        case QLocale::Kannada:               return tr("Kannada");
        case QLocale::Kazakh:                return tr("Kazakh");
        case QLocale::Khmer:                 return tr("Khmer");
        case QLocale::Kinyarwanda:           return tr("Kinyarwanda");
        //case QLocale::Klingon:             return tr("Klingon");
        //case QLocale::KlingonPlqaD:        return tr("Klingon (PlqaD)");
        case QLocale::Korean:                return tr("Korean");
        case QLocale::Kurdish:               return tr("Kurdish");
        //case QLocale::Kyrgyz:              return tr("Kyrgyz");
        case QLocale::Lao:                   return tr("Lao");
        case QLocale::Latin:                 return tr("Latin");
        case QLocale::Latvian:               return tr("Latvian");
        //case QLocale::LevantineArabic:     return tr("Levantine Arabic");
        case QLocale::Lithuanian:            return tr("Lithuanian");
        case QLocale::Luxembourgish:         return tr("Luxembourgish");
        case QLocale::Macedonian:            return tr("Macedonian");
        case QLocale::Malagasy:              return tr("Malagasy");
        case QLocale::Malay:                 return tr("Malay");
        case QLocale::Malayalam:             return tr("Malayalam");
        case QLocale::Maltese:               return tr("Maltese");
        case QLocale::Maori:                 return tr("Maori");
        case QLocale::Marathi:               return tr("Marathi");
        //case QLocale::Mari:                return tr("Mari");
        case QLocale::Mongolian:             return tr("Mongolian");
        //case QLocale::Myanmar:             return tr("Myanmar");
        case QLocale::Nepali:                return tr("Nepali");
        case QLocale::NorwegianBokmal:       return tr("Norwegian");
        case QLocale::Oriya:                 return tr("Oriya");
        //case QLocale::Chichewa:            return tr("Chichewa");
        case QLocale::Papiamento:            return tr("Papiamento");
        case QLocale::Pashto:                return tr("Pashto");
        case QLocale::Persian:               return tr("Persian");
        case QLocale::Polish:                return tr("Polish");
        case QLocale::Portuguese:            return tr("Portuguese");
        case QLocale::Punjabi:               return tr("Punjabi");
        //case QLocale::QueretaroOtomi:      return tr("Queretaro Otomi");
        case QLocale::Romanian:              return tr("Romanian");
        case QLocale::Russian:               return tr("Russian");
        case QLocale::Samoan:                return tr("Samoan");
        //case QLocale::ScotsGaelic:         return tr("Scots Gaelic");
        //case QLocale::SerbianCyrillic:     return tr("Serbian (Cyrillic)");
        //case QLocale::SerbianLatin:        return tr("Serbian (Latin)");
        //case QLocale::Sesotho:             return tr("Sesotho");
        case QLocale::Shona:                 return tr("Shona");
        case QLocale::Sindhi:                return tr("Sindhi");
        case QLocale::Sinhala:               return tr("Sinhala");
        case QLocale::Slovak:                return tr("Slovak");
        case QLocale::Slovenian:             return tr("Slovenian");
        case QLocale::Somali:                return tr("Somali");
        case QLocale::Spanish:               return tr("Spanish");
        case QLocale::Sundanese:             return tr("Sundanese");
        case QLocale::Swahili:               return tr("Swahili");
        case QLocale::Swedish:               return tr("Swedish");
        //case QLocale::Tagalog:             return tr("Tagalog");
        case QLocale::Tahitian:              return tr("Tahitian");
        case QLocale::Tajik:                 return tr("Tajik");
        case QLocale::Tamil:                 return tr("Tamil");
        case QLocale::Tatar:                 return tr("Tatar");
        case QLocale::Telugu:                return tr("Telugu");
        case QLocale::Thai:                  return tr("Thai");
        case QLocale::Tongan:                return tr("Tongan");
        case QLocale::Turkish:               return tr("Turkish");
        case QLocale::Turkmen:               return tr("Turkmen");
        //case QLocale::Udmurt:              return tr("Udmurt");
        case QLocale::Uighur:                return tr("Uighur");
        case QLocale::Ukrainian:             return tr("Ukrainian");
        case QLocale::Urdu:                  return tr("Urdu");
        case QLocale::Uzbek:                 return tr("Uzbek");
        case QLocale::Vietnamese:            return tr("Vietnamese");
        case QLocale::Welsh:                 return tr("Welsh");
        case QLocale::Xhosa:                 return tr("Xhosa");
        case QLocale::Yiddish:               return tr("Yiddish");
        case QLocale::Yoruba:                return tr("Yoruba");
        //case QLocale::YucatecMaya:         return tr("Yucatec Maya");
        case QLocale::Zulu:                  return tr("Zulu");
        default:
            if (thisLocale.name() == "HaitianCreole")
                { return tr("Haitian Creole"); }
            else if (thisLocale.name() == "HillMari")
                { return tr("Hill Mari"); }
            else if (thisLocale.name() == "Hmong")
                { return tr("Hmong"); }
            else if (thisLocale.name() == "Klingon")
                { return tr("Klingon"); }
            else if (thisLocale.name() == "KlingonPlqaD")
                { return tr("Klingon (PlqaD)"); }
            else if (thisLocale.name() == "Kyrgyz")
                { return tr("Kyrgyz"); }
            else if (thisLocale.name() == "LevantineArabic")
                { return tr("Levantine Arabic"); }
            else if (thisLocale.name() == "Mari")
                { return tr("Mari"); }
            else if (thisLocale.name() == "Myanmar")
                { return tr("Myanmar"); }
            else if (thisLocale.name() == "Chichewa")
                { return tr("Chichewa"); }
            else if (thisLocale.name() == "QueretaroOtomi")
                { return tr("Queretaro Otomi"); }
            else if (thisLocale.name() == "ScotsGaelic")
                { return tr("Scots Gaelic"); }
            else if (thisLocale.name() == "SerbianCyrillic")
                { return tr("Serbian (Cyrillic)"); }
            else if (thisLocale.name() == "SerbianLatin")
                { return tr("Serbian (Latin)"); }
            else if (thisLocale.name() == "Sesotho")
                { return tr("Sesotho"); }
            else if (thisLocale.name() == "Tagalog")
                { return tr("Tagalog"); }
            else if (thisLocale.name() == "Udmurt")
                { return tr("Udmurt"); }
            else if (thisLocale.name() == "YucatecMaya")
                { return tr("Yucatec Maya"); }
            return QString();
        } // end switch (lang)
} // end languageName(Language lang)
/******************************* End of File *********************************/
