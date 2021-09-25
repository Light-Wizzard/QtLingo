/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QAction *actionAbout;
    QAction *actionHelp;
    QAction *actionCompile;
    QAction *actionClipboard;
    QAction *actionAuthor;
    QAction *actionSave;
    QAction *actionTranslate_Help;
    QAction *actionAccept_Translations;
    QAction *actionTranslate_ReadMe;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tabSettings;
    QVBoxLayout *verticalLayout_3;
    QFormLayout *formLayoutSettings;
    QLabel *labelSettingsLanguage;
    QHBoxLayout *horizontalLayoutSettingsLanguage;
    QComboBox *comboBoxLanguage;
    QSpacerItem *horizontalSpacerSettingsLanguage;
    QLabel *labelSettingLupdate;
    QHBoxLayout *horizontalLayoutSettingsLupdate;
    QLineEdit *lineEditSettingsLupdate;
    QPushButton *pushButtonSettingsLupdate;
    QLabel *labelSettingsLrelease;
    QHBoxLayout *horizontalLayoutSettingsLrelease;
    QLineEdit *lineEditSettingsLrelease;
    QPushButton *pushButtonSettingsLrelease;
    QLabel *labelSettingsUiLanguage;
    QHBoxLayout *horizontalLayoutSettingsUI;
    QLabel *labelSettingsLanguageUI;
    QLabel *labelSettingsTranslationEngine;
    QGridLayout *gridLayoutSettingsTransEngine;
    QCheckBox *checkBoxSettingsGoogle;
    QCheckBox *checkBoxSettingsYandex;
    QCheckBox *checkBoxSettingsBing;
    QSpacerItem *horizontalSpacerSettingsTransEng;
    QLabel *labelSettingsDelay;
    QHBoxLayout *horizontalLayoutSettingsDelay;
    QSpinBox *spinBoxSettingsDelay;
    QSpacerItem *horizontalSpacerSettingsDelay;
    QLabel *labelSettignsMessaging;
    QHBoxLayout *horizontalLayoutSettignsMessaging;
    QCheckBox *checkBoxSettignsMessaging;
    QSpacerItem *horizontalSpacerSettignsMessaging;
    QWidget *tabSQL;
    QVBoxLayout *verticalLayout_2;
    QFormLayout *formLayoutSql;
    QLabel *labelSqlDatabaseName;
    QHBoxLayout *horizontalLayoutSqlDatabaseName;
    QComboBox *comboBoxSqlDatabaseType;
    QLineEdit *lineEditSqlDatabaseName;
    QPushButton *pushButtonSqlDatabaseNameBrowse;
    QLabel *labelSqlHostName;
    QLineEdit *lineEditSqlHostName;
    QLabel *labelSqlUserName;
    QLineEdit *lineEditSqlUserName;
    QLabel *labelSqlPassword;
    QHBoxLayout *horizontalLayoutSqlPassword;
    QLineEdit *lineEditSqlPassword;
    QPushButton *pushButtonSqlPasswordShow;
    QLabel *labelSqlOptions;
    QHBoxLayout *horizontalLayoutSqlOptions;
    QPushButton *pushButtonSqlSave;
    QSpacerItem *horizontalSpacer;
    QWidget *tabTranslations;
    QVBoxLayout *verticalLayout_4;
    QFormLayout *formLayoutTranslations;
    QLabel *labelTranslationsProjectFolder;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEditTranslationsProjectFolder;
    QPushButton *pushButtonTranslationsProjectFolderBrowse;
    QLabel *labelTranslationMake;
    QHBoxLayout *horizontalLayoutTranslationsMake;
    QRadioButton *radioButtonTranslationsQmake;
    QRadioButton *radioButtonTranslationsCmake;
    QSpacerItem *horizontalSpacerTranslationMake;
    QLabel *labelTranslationsSource;
    QHBoxLayout *horizontalLayoutTranslationsSource;
    QLineEdit *lineEditTranslationsSource;
    QPushButton *pushButtonTranslationsSourceBrowse;
    QLabel *labelTranslationsDoxyfile;
    QHBoxLayout *horizontalLayoutTranslationsDestination;
    QLineEdit *lineEditTranslationsDoxyfile;
    QPushButton *pushButtonTranslationsDoxyfileBrowse;
    QLabel *labelTranslationSourceLanguage;
    QHBoxLayout *horizontalLayoutTranslationSourceLang;
    QComboBox *comboBoxTranslationSourceLanguage;
    QLabel *labelTranslationsSourceLanguageCode;
    QSpacerItem *horizontalSpacerTranslationsSourceLang;
    QLabel *labelTranslationsHelp;
    QHBoxLayout *horizontalLayoutTranslationsHelp;
    QLineEdit *lineEditTranslationsHelp;
    QPushButton *pushButtonTranslationsHelp;
    QLabel *labelTranslationsCountryCode;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayoutCountryCodes;
    QCheckBox *checkBoxTranslationsTO;
    QCheckBox *checkBoxTranslationsFY;
    QCheckBox *checkBoxTranslationsTE;
    QCheckBox *checkBoxTranslationsTT;
    QCheckBox *checkBoxTranslationsLV;
    QCheckBox *checkBoxTranslationsCS;
    QCheckBox *checkBoxTranslationsKY;
    QCheckBox *checkBoxTranslationsZU;
    QCheckBox *checkBoxTranslationsRW;
    QCheckBox *checkBoxTranslationsHI;
    QCheckBox *checkBoxTranslationsTLH_QAAK;
    QCheckBox *checkBoxTranslationsLB;
    QCheckBox *checkBoxTranslationsHT;
    QCheckBox *checkBoxTranslationsEN;
    QCheckBox *checkBoxTranslationsKN;
    QCheckBox *checkBoxTranslationsPL;
    QCheckBox *checkBoxTranslationsNL;
    QCheckBox *checkBoxTranslationsSM;
    QCheckBox *checkBoxTranslationsAPC;
    QCheckBox *checkBoxTranslationsTH;
    QCheckBox *checkBoxTranslationsNY;
    QCheckBox *checkBoxTranslationsMS;
    QCheckBox *checkBoxTranslationsIG;
    QCheckBox *checkBoxTranslationsVI;
    QCheckBox *checkBoxTranslationsFO;
    QCheckBox *checkBoxTranslationsAM;
    QCheckBox *checkBoxTranslationsGA;
    QCheckBox *checkBoxTranslationsSQ;
    QCheckBox *checkBoxTranslationsOR;
    QCheckBox *checkBoxTranslationsFR;
    QCheckBox *checkBoxTranslationsHU;
    QCheckBox *checkBoxTranslationsFIL;
    QCheckBox *checkBoxTranslationsGD;
    QCheckBox *checkBoxTranslationsID;
    QCheckBox *checkBoxTranslationsKM;
    QCheckBox *checkBoxTranslationsRU;
    QCheckBox *checkBoxTranslationsRO;
    QCheckBox *checkBoxTranslationsMG;
    QCheckBox *checkBoxTranslationsTL;
    QCheckBox *checkBoxTranslationsMN;
    QCheckBox *checkBoxTranslationsPT;
    QCheckBox *checkBoxTranslationsNB;
    QCheckBox *checkBoxTranslationsGU;
    QCheckBox *checkBoxTranslationsNE;
    QCheckBox *checkBoxTranslationsFI;
    QCheckBox *checkBoxTranslationsZH_CN;
    QCheckBox *checkBoxTranslationsVE;
    QCheckBox *checkBoxTranslationsAR;
    QCheckBox *checkBoxTranslationsKA;
    QCheckBox *checkBoxTranslationsZH_TW;
    QCheckBox *checkBoxTranslationsLA;
    QCheckBox *checkBoxTranslationsFJ;
    QCheckBox *checkBoxTranslationsEL;
    QCheckBox *checkBoxTranslationsLO;
    QCheckBox *checkBoxTranslationsCO;
    QCheckBox *checkBoxTranslationsTLH;
    QCheckBox *checkBoxTranslationsBN;
    QCheckBox *checkBoxTranslationsTY;
    QCheckBox *checkBoxTranslationsET;
    QCheckBox *checkBoxTranslationsPAP;
    QCheckBox *checkBoxTranslationsFA;
    QCheckBox *checkBoxTranslationsDA;
    QCheckBox *checkBoxTranslationsNO;
    QCheckBox *checkBoxTranslationsDE;
    QCheckBox *checkBoxTranslationsCEB;
    QCheckBox *checkBoxTranslationsTS;
    QSpacerItem *horizontalSpacerTranslations;
    QCheckBox *checkBoxTranslationsMR;
    QCheckBox *checkBoxTranslationsCY;
    QCheckBox *checkBoxTranslationsNN;
    QCheckBox *checkBoxTranslationsKO;
    QCheckBox *checkBoxTranslationsML;
    QCheckBox *checkBoxTranslationsXH;
    QCheckBox *checkBoxTranslationsYO;
    QCheckBox *checkBoxTranslationsPA;
    QCheckBox *checkBoxTranslationsBS;
    QCheckBox *checkBoxTranslationsHMN;
    QCheckBox *checkBoxTranslationsGL;
    QCheckBox *checkBoxTranslationsHAW;
    QCheckBox *checkBoxTranslationsMY;
    QCheckBox *checkBoxTranslationsAF;
    QCheckBox *checkBoxTranslationsMHR;
    QCheckBox *checkBoxTranslationsBA;
    QCheckBox *checkBoxTranslationsCA;
    QCheckBox *checkBoxTranslationsYI;
    QCheckBox *checkBoxTranslationsJA;
    QCheckBox *checkBoxTranslationsJW;
    QCheckBox *checkBoxTranslationsBG;
    QCheckBox *checkBoxTranslationsSR;
    QCheckBox *checkBoxTranslationsTR;
    QCheckBox *checkBoxTranslationsTA;
    QCheckBox *checkBoxTranslationsMI;
    QCheckBox *checkBoxTranslationsHR;
    QCheckBox *checkBoxTranslationsPS;
    QCheckBox *checkBoxTranslationsHY;
    QCheckBox *checkBoxTranslationsTN;
    QCheckBox *checkBoxTranslationsKU;
    QCheckBox *checkBoxTranslationsHE;
    QCheckBox *checkBoxTranslationsMT;
    QCheckBox *checkBoxTranslationsIT;
    QCheckBox *checkBoxTranslationsEU;
    QCheckBox *checkBoxTranslationsTG;
    QCheckBox *checkBoxTranslationsAZ;
    QCheckBox *checkBoxTranslationsTK;
    QCheckBox *checkBoxTranslationsHA;
    QCheckBox *checkBoxTranslationsIS;
    QCheckBox *checkBoxTranslationsYUE;
    QCheckBox *checkBoxTranslationsBE;
    QCheckBox *checkBoxTranslationsMRJ;
    QCheckBox *checkBoxTranslationsKK;
    QCheckBox *checkBoxTranslationsRM;
    QCheckBox *checkBoxTranslationsMK;
    QCheckBox *checkBoxTranslationsEO;
    QCheckBox *checkBoxTranslationsLT;
    QCheckBox *checkBoxTranslationsOTQ;
    QCheckBox *checkBoxTranslationsSW;
    QCheckBox *checkBoxTranslationsSU;
    QCheckBox *checkBoxTranslationsSO;
    QCheckBox *checkBoxTranslationsSI;
    QCheckBox *checkBoxTranslationsSD;
    QCheckBox *checkBoxTranslationsES;
    QCheckBox *checkBoxTranslationsSB;
    QCheckBox *checkBoxTranslationsSV;
    QCheckBox *checkBoxTranslationsSN;
    QCheckBox *checkBoxTranslationsSL;
    QCheckBox *checkBoxTranslationsSK;
    QCheckBox *checkBoxTranslationsST;
    QCheckBox *checkBoxTranslationsSR_LATIN;
    QCheckBox *checkBoxTranslationsUZ;
    QCheckBox *checkBoxTranslationsUR;
    QCheckBox *checkBoxTranslationsUG;
    QCheckBox *checkBoxTranslationsUK;
    QCheckBox *checkBoxTranslationsUDM;
    QCheckBox *checkBoxTranslationsYUA;
    QLabel *labelProjectName;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *comboBoxTranslationsProjectNames;
    QLineEdit *lineEditProjectName;
    QLabel *labelRecordIdProject;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButtonTranslationsProjectBrowser;
    QLabel *labelTranslationsOptions;
    QHBoxLayout *horizontalLayoutTranslationsOptions;
    QPushButton *pushButtonTranslationsSave;
    QPushButton *pushButtonTranslationsClear;
    QPushButton *pushButtonTranslationsAdd;
    QPushButton *pushButtonTranslationsDelete;
    QSpacerItem *horizontalSpacer_3;
    QWidget *tabProject;
    QVBoxLayout *verticalLayout_5;
    QTextEdit *textEditProjects;
    QProgressBar *progressBarProjectsFiles;
    QProgressBar *progressBarProjectsTranslations;
    QWidget *tabHelp;
    QVBoxLayout *verticalLayout_6;
    QTextEdit *textEditHelp;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1415, 686);
        QFont font;
        font.setPointSize(13);
        MainWindow->setFont(font);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/gear.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout->setIcon(icon1);
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName(QString::fromUtf8("actionHelp"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionHelp->setIcon(icon2);
        actionCompile = new QAction(MainWindow);
        actionCompile->setObjectName(QString::fromUtf8("actionCompile"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/thumbsup.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCompile->setIcon(icon3);
        actionClipboard = new QAction(MainWindow);
        actionClipboard->setObjectName(QString::fromUtf8("actionClipboard"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/clipboard.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClipboard->setIcon(icon4);
        actionAuthor = new QAction(MainWindow);
        actionAuthor->setObjectName(QString::fromUtf8("actionAuthor"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/handshake.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAuthor->setIcon(icon5);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/filesave.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon6);
        actionTranslate_Help = new QAction(MainWindow);
        actionTranslate_Help->setObjectName(QString::fromUtf8("actionTranslate_Help"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/wizardwand.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionTranslate_Help->setIcon(icon7);
        actionAccept_Translations = new QAction(MainWindow);
        actionAccept_Translations->setObjectName(QString::fromUtf8("actionAccept_Translations"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/lock.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAccept_Translations->setIcon(icon8);
        actionTranslate_ReadMe = new QAction(MainWindow);
        actionTranslate_ReadMe->setObjectName(QString::fromUtf8("actionTranslate_ReadMe"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/images/lists.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionTranslate_ReadMe->setIcon(icon9);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabSettings = new QWidget();
        tabSettings->setObjectName(QString::fromUtf8("tabSettings"));
        verticalLayout_3 = new QVBoxLayout(tabSettings);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        formLayoutSettings = new QFormLayout();
        formLayoutSettings->setObjectName(QString::fromUtf8("formLayoutSettings"));
        labelSettingsLanguage = new QLabel(tabSettings);
        labelSettingsLanguage->setObjectName(QString::fromUtf8("labelSettingsLanguage"));

        formLayoutSettings->setWidget(0, QFormLayout::LabelRole, labelSettingsLanguage);

        horizontalLayoutSettingsLanguage = new QHBoxLayout();
        horizontalLayoutSettingsLanguage->setObjectName(QString::fromUtf8("horizontalLayoutSettingsLanguage"));
        comboBoxLanguage = new QComboBox(tabSettings);
        comboBoxLanguage->setObjectName(QString::fromUtf8("comboBoxLanguage"));
        comboBoxLanguage->setCurrentText(QString::fromUtf8(""));

        horizontalLayoutSettingsLanguage->addWidget(comboBoxLanguage);

        horizontalSpacerSettingsLanguage = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayoutSettingsLanguage->addItem(horizontalSpacerSettingsLanguage);


        formLayoutSettings->setLayout(0, QFormLayout::FieldRole, horizontalLayoutSettingsLanguage);

        labelSettingLupdate = new QLabel(tabSettings);
        labelSettingLupdate->setObjectName(QString::fromUtf8("labelSettingLupdate"));
#if QT_CONFIG(tooltip)
        labelSettingLupdate->setToolTip(QString::fromUtf8(""));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        labelSettingLupdate->setStatusTip(QString::fromUtf8(""));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(whatsthis)
        labelSettingLupdate->setWhatsThis(QString::fromUtf8(""));
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(accessibility)
        labelSettingLupdate->setAccessibleName(QString::fromUtf8(""));
#endif // QT_CONFIG(accessibility)
#if QT_CONFIG(accessibility)
        labelSettingLupdate->setAccessibleDescription(QString::fromUtf8(""));
#endif // QT_CONFIG(accessibility)
        labelSettingLupdate->setText(QString::fromUtf8("lupdate"));

        formLayoutSettings->setWidget(1, QFormLayout::LabelRole, labelSettingLupdate);

        horizontalLayoutSettingsLupdate = new QHBoxLayout();
        horizontalLayoutSettingsLupdate->setObjectName(QString::fromUtf8("horizontalLayoutSettingsLupdate"));
        lineEditSettingsLupdate = new QLineEdit(tabSettings);
        lineEditSettingsLupdate->setObjectName(QString::fromUtf8("lineEditSettingsLupdate"));
#if QT_CONFIG(tooltip)
        lineEditSettingsLupdate->setToolTip(QString::fromUtf8(""));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        lineEditSettingsLupdate->setStatusTip(QString::fromUtf8(""));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(accessibility)
        lineEditSettingsLupdate->setAccessibleName(QString::fromUtf8(""));
#endif // QT_CONFIG(accessibility)
#if QT_CONFIG(accessibility)
        lineEditSettingsLupdate->setAccessibleDescription(QString::fromUtf8(""));
#endif // QT_CONFIG(accessibility)
        lineEditSettingsLupdate->setInputMask(QString::fromUtf8(""));
        lineEditSettingsLupdate->setText(QString::fromUtf8(""));
        lineEditSettingsLupdate->setPlaceholderText(QString::fromUtf8(""));

        horizontalLayoutSettingsLupdate->addWidget(lineEditSettingsLupdate);

        pushButtonSettingsLupdate = new QPushButton(tabSettings);
        pushButtonSettingsLupdate->setObjectName(QString::fromUtf8("pushButtonSettingsLupdate"));

        horizontalLayoutSettingsLupdate->addWidget(pushButtonSettingsLupdate);


        formLayoutSettings->setLayout(1, QFormLayout::FieldRole, horizontalLayoutSettingsLupdate);

        labelSettingsLrelease = new QLabel(tabSettings);
        labelSettingsLrelease->setObjectName(QString::fromUtf8("labelSettingsLrelease"));

        formLayoutSettings->setWidget(2, QFormLayout::LabelRole, labelSettingsLrelease);

        horizontalLayoutSettingsLrelease = new QHBoxLayout();
        horizontalLayoutSettingsLrelease->setObjectName(QString::fromUtf8("horizontalLayoutSettingsLrelease"));
        lineEditSettingsLrelease = new QLineEdit(tabSettings);
        lineEditSettingsLrelease->setObjectName(QString::fromUtf8("lineEditSettingsLrelease"));
#if QT_CONFIG(accessibility)
        lineEditSettingsLrelease->setAccessibleName(QString::fromUtf8(""));
#endif // QT_CONFIG(accessibility)
#if QT_CONFIG(accessibility)
        lineEditSettingsLrelease->setAccessibleDescription(QString::fromUtf8(""));
#endif // QT_CONFIG(accessibility)
        lineEditSettingsLrelease->setInputMask(QString::fromUtf8(""));
        lineEditSettingsLrelease->setText(QString::fromUtf8(""));
        lineEditSettingsLrelease->setPlaceholderText(QString::fromUtf8(""));

        horizontalLayoutSettingsLrelease->addWidget(lineEditSettingsLrelease);

        pushButtonSettingsLrelease = new QPushButton(tabSettings);
        pushButtonSettingsLrelease->setObjectName(QString::fromUtf8("pushButtonSettingsLrelease"));

        horizontalLayoutSettingsLrelease->addWidget(pushButtonSettingsLrelease);


        formLayoutSettings->setLayout(2, QFormLayout::FieldRole, horizontalLayoutSettingsLrelease);

        labelSettingsUiLanguage = new QLabel(tabSettings);
        labelSettingsUiLanguage->setObjectName(QString::fromUtf8("labelSettingsUiLanguage"));

        formLayoutSettings->setWidget(3, QFormLayout::LabelRole, labelSettingsUiLanguage);

        horizontalLayoutSettingsUI = new QHBoxLayout();
        horizontalLayoutSettingsUI->setObjectName(QString::fromUtf8("horizontalLayoutSettingsUI"));
        labelSettingsLanguageUI = new QLabel(tabSettings);
        labelSettingsLanguageUI->setObjectName(QString::fromUtf8("labelSettingsLanguageUI"));
        labelSettingsLanguageUI->setText(QString::fromUtf8("English"));

        horizontalLayoutSettingsUI->addWidget(labelSettingsLanguageUI);


        formLayoutSettings->setLayout(3, QFormLayout::FieldRole, horizontalLayoutSettingsUI);

        labelSettingsTranslationEngine = new QLabel(tabSettings);
        labelSettingsTranslationEngine->setObjectName(QString::fromUtf8("labelSettingsTranslationEngine"));

        formLayoutSettings->setWidget(4, QFormLayout::LabelRole, labelSettingsTranslationEngine);

        gridLayoutSettingsTransEngine = new QGridLayout();
        gridLayoutSettingsTransEngine->setObjectName(QString::fromUtf8("gridLayoutSettingsTransEngine"));
        checkBoxSettingsGoogle = new QCheckBox(tabSettings);
        checkBoxSettingsGoogle->setObjectName(QString::fromUtf8("checkBoxSettingsGoogle"));
        checkBoxSettingsGoogle->setText(QString::fromUtf8("Google"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/images/google_translate.png"), QSize(), QIcon::Normal, QIcon::On);
        checkBoxSettingsGoogle->setIcon(icon10);

        gridLayoutSettingsTransEngine->addWidget(checkBoxSettingsGoogle, 0, 0, 1, 1);

        checkBoxSettingsYandex = new QCheckBox(tabSettings);
        checkBoxSettingsYandex->setObjectName(QString::fromUtf8("checkBoxSettingsYandex"));
        checkBoxSettingsYandex->setText(QString::fromUtf8("Yandex"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/images/yandex_translate.png"), QSize(), QIcon::Normal, QIcon::On);
        checkBoxSettingsYandex->setIcon(icon11);

        gridLayoutSettingsTransEngine->addWidget(checkBoxSettingsYandex, 0, 2, 1, 1);

        checkBoxSettingsBing = new QCheckBox(tabSettings);
        checkBoxSettingsBing->setObjectName(QString::fromUtf8("checkBoxSettingsBing"));
        checkBoxSettingsBing->setText(QString::fromUtf8("Bing"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/images/microsoft_translator.png"), QSize(), QIcon::Normal, QIcon::On);
        checkBoxSettingsBing->setIcon(icon12);

        gridLayoutSettingsTransEngine->addWidget(checkBoxSettingsBing, 0, 1, 1, 1);

        horizontalSpacerSettingsTransEng = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayoutSettingsTransEngine->addItem(horizontalSpacerSettingsTransEng, 0, 3, 1, 1);


        formLayoutSettings->setLayout(4, QFormLayout::FieldRole, gridLayoutSettingsTransEngine);

        labelSettingsDelay = new QLabel(tabSettings);
        labelSettingsDelay->setObjectName(QString::fromUtf8("labelSettingsDelay"));

        formLayoutSettings->setWidget(5, QFormLayout::LabelRole, labelSettingsDelay);

        horizontalLayoutSettingsDelay = new QHBoxLayout();
        horizontalLayoutSettingsDelay->setObjectName(QString::fromUtf8("horizontalLayoutSettingsDelay"));
        spinBoxSettingsDelay = new QSpinBox(tabSettings);
        spinBoxSettingsDelay->setObjectName(QString::fromUtf8("spinBoxSettingsDelay"));
        spinBoxSettingsDelay->setMaximum(66666);

        horizontalLayoutSettingsDelay->addWidget(spinBoxSettingsDelay);

        horizontalSpacerSettingsDelay = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayoutSettingsDelay->addItem(horizontalSpacerSettingsDelay);


        formLayoutSettings->setLayout(5, QFormLayout::FieldRole, horizontalLayoutSettingsDelay);

        labelSettignsMessaging = new QLabel(tabSettings);
        labelSettignsMessaging->setObjectName(QString::fromUtf8("labelSettignsMessaging"));

        formLayoutSettings->setWidget(6, QFormLayout::LabelRole, labelSettignsMessaging);

        horizontalLayoutSettignsMessaging = new QHBoxLayout();
        horizontalLayoutSettignsMessaging->setObjectName(QString::fromUtf8("horizontalLayoutSettignsMessaging"));
        checkBoxSettignsMessaging = new QCheckBox(tabSettings);
        checkBoxSettignsMessaging->setObjectName(QString::fromUtf8("checkBoxSettignsMessaging"));

        horizontalLayoutSettignsMessaging->addWidget(checkBoxSettignsMessaging);

        horizontalSpacerSettignsMessaging = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayoutSettignsMessaging->addItem(horizontalSpacerSettignsMessaging);


        formLayoutSettings->setLayout(6, QFormLayout::FieldRole, horizontalLayoutSettignsMessaging);


        verticalLayout_3->addLayout(formLayoutSettings);

        tabWidget->addTab(tabSettings, QString());
        tabSQL = new QWidget();
        tabSQL->setObjectName(QString::fromUtf8("tabSQL"));
        verticalLayout_2 = new QVBoxLayout(tabSQL);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        formLayoutSql = new QFormLayout();
        formLayoutSql->setObjectName(QString::fromUtf8("formLayoutSql"));
        labelSqlDatabaseName = new QLabel(tabSQL);
        labelSqlDatabaseName->setObjectName(QString::fromUtf8("labelSqlDatabaseName"));

        formLayoutSql->setWidget(0, QFormLayout::LabelRole, labelSqlDatabaseName);

        horizontalLayoutSqlDatabaseName = new QHBoxLayout();
        horizontalLayoutSqlDatabaseName->setObjectName(QString::fromUtf8("horizontalLayoutSqlDatabaseName"));
        comboBoxSqlDatabaseType = new QComboBox(tabSQL);
        comboBoxSqlDatabaseType->setObjectName(QString::fromUtf8("comboBoxSqlDatabaseType"));
        comboBoxSqlDatabaseType->setCurrentText(QString::fromUtf8(""));

        horizontalLayoutSqlDatabaseName->addWidget(comboBoxSqlDatabaseType);

        lineEditSqlDatabaseName = new QLineEdit(tabSQL);
        lineEditSqlDatabaseName->setObjectName(QString::fromUtf8("lineEditSqlDatabaseName"));
        lineEditSqlDatabaseName->setInputMask(QString::fromUtf8(""));
        lineEditSqlDatabaseName->setText(QString::fromUtf8(""));
        lineEditSqlDatabaseName->setPlaceholderText(QString::fromUtf8(""));

        horizontalLayoutSqlDatabaseName->addWidget(lineEditSqlDatabaseName);

        pushButtonSqlDatabaseNameBrowse = new QPushButton(tabSQL);
        pushButtonSqlDatabaseNameBrowse->setObjectName(QString::fromUtf8("pushButtonSqlDatabaseNameBrowse"));

        horizontalLayoutSqlDatabaseName->addWidget(pushButtonSqlDatabaseNameBrowse);


        formLayoutSql->setLayout(0, QFormLayout::FieldRole, horizontalLayoutSqlDatabaseName);

        labelSqlHostName = new QLabel(tabSQL);
        labelSqlHostName->setObjectName(QString::fromUtf8("labelSqlHostName"));

        formLayoutSql->setWidget(1, QFormLayout::LabelRole, labelSqlHostName);

        lineEditSqlHostName = new QLineEdit(tabSQL);
        lineEditSqlHostName->setObjectName(QString::fromUtf8("lineEditSqlHostName"));
        lineEditSqlHostName->setInputMask(QString::fromUtf8(""));
        lineEditSqlHostName->setText(QString::fromUtf8(""));
        lineEditSqlHostName->setPlaceholderText(QString::fromUtf8(""));

        formLayoutSql->setWidget(1, QFormLayout::FieldRole, lineEditSqlHostName);

        labelSqlUserName = new QLabel(tabSQL);
        labelSqlUserName->setObjectName(QString::fromUtf8("labelSqlUserName"));

        formLayoutSql->setWidget(2, QFormLayout::LabelRole, labelSqlUserName);

        lineEditSqlUserName = new QLineEdit(tabSQL);
        lineEditSqlUserName->setObjectName(QString::fromUtf8("lineEditSqlUserName"));
        lineEditSqlUserName->setInputMask(QString::fromUtf8(""));
        lineEditSqlUserName->setText(QString::fromUtf8(""));
        lineEditSqlUserName->setPlaceholderText(QString::fromUtf8(""));

        formLayoutSql->setWidget(2, QFormLayout::FieldRole, lineEditSqlUserName);

        labelSqlPassword = new QLabel(tabSQL);
        labelSqlPassword->setObjectName(QString::fromUtf8("labelSqlPassword"));

        formLayoutSql->setWidget(3, QFormLayout::LabelRole, labelSqlPassword);

        horizontalLayoutSqlPassword = new QHBoxLayout();
        horizontalLayoutSqlPassword->setObjectName(QString::fromUtf8("horizontalLayoutSqlPassword"));
        lineEditSqlPassword = new QLineEdit(tabSQL);
        lineEditSqlPassword->setObjectName(QString::fromUtf8("lineEditSqlPassword"));
        lineEditSqlPassword->setInputMask(QString::fromUtf8(""));
        lineEditSqlPassword->setText(QString::fromUtf8(""));
        lineEditSqlPassword->setPlaceholderText(QString::fromUtf8(""));

        horizontalLayoutSqlPassword->addWidget(lineEditSqlPassword);

        pushButtonSqlPasswordShow = new QPushButton(tabSQL);
        pushButtonSqlPasswordShow->setObjectName(QString::fromUtf8("pushButtonSqlPasswordShow"));

        horizontalLayoutSqlPassword->addWidget(pushButtonSqlPasswordShow);


        formLayoutSql->setLayout(3, QFormLayout::FieldRole, horizontalLayoutSqlPassword);

        labelSqlOptions = new QLabel(tabSQL);
        labelSqlOptions->setObjectName(QString::fromUtf8("labelSqlOptions"));

        formLayoutSql->setWidget(4, QFormLayout::LabelRole, labelSqlOptions);

        horizontalLayoutSqlOptions = new QHBoxLayout();
        horizontalLayoutSqlOptions->setObjectName(QString::fromUtf8("horizontalLayoutSqlOptions"));
        pushButtonSqlSave = new QPushButton(tabSQL);
        pushButtonSqlSave->setObjectName(QString::fromUtf8("pushButtonSqlSave"));

        horizontalLayoutSqlOptions->addWidget(pushButtonSqlSave);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayoutSqlOptions->addItem(horizontalSpacer);


        formLayoutSql->setLayout(4, QFormLayout::FieldRole, horizontalLayoutSqlOptions);


        verticalLayout_2->addLayout(formLayoutSql);

        tabWidget->addTab(tabSQL, QString());
        tabTranslations = new QWidget();
        tabTranslations->setObjectName(QString::fromUtf8("tabTranslations"));
        verticalLayout_4 = new QVBoxLayout(tabTranslations);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        formLayoutTranslations = new QFormLayout();
        formLayoutTranslations->setObjectName(QString::fromUtf8("formLayoutTranslations"));
        labelTranslationsProjectFolder = new QLabel(tabTranslations);
        labelTranslationsProjectFolder->setObjectName(QString::fromUtf8("labelTranslationsProjectFolder"));

        formLayoutTranslations->setWidget(1, QFormLayout::LabelRole, labelTranslationsProjectFolder);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lineEditTranslationsProjectFolder = new QLineEdit(tabTranslations);
        lineEditTranslationsProjectFolder->setObjectName(QString::fromUtf8("lineEditTranslationsProjectFolder"));
        lineEditTranslationsProjectFolder->setInputMask(QString::fromUtf8(""));
        lineEditTranslationsProjectFolder->setText(QString::fromUtf8(""));
        lineEditTranslationsProjectFolder->setPlaceholderText(QString::fromUtf8(""));

        horizontalLayout->addWidget(lineEditTranslationsProjectFolder);

        pushButtonTranslationsProjectFolderBrowse = new QPushButton(tabTranslations);
        pushButtonTranslationsProjectFolderBrowse->setObjectName(QString::fromUtf8("pushButtonTranslationsProjectFolderBrowse"));

        horizontalLayout->addWidget(pushButtonTranslationsProjectFolderBrowse);


        formLayoutTranslations->setLayout(1, QFormLayout::FieldRole, horizontalLayout);

        labelTranslationMake = new QLabel(tabTranslations);
        labelTranslationMake->setObjectName(QString::fromUtf8("labelTranslationMake"));

        formLayoutTranslations->setWidget(2, QFormLayout::LabelRole, labelTranslationMake);

        horizontalLayoutTranslationsMake = new QHBoxLayout();
        horizontalLayoutTranslationsMake->setObjectName(QString::fromUtf8("horizontalLayoutTranslationsMake"));
        radioButtonTranslationsQmake = new QRadioButton(tabTranslations);
        radioButtonTranslationsQmake->setObjectName(QString::fromUtf8("radioButtonTranslationsQmake"));
        radioButtonTranslationsQmake->setText(QString::fromUtf8("qmake"));

        horizontalLayoutTranslationsMake->addWidget(radioButtonTranslationsQmake);

        radioButtonTranslationsCmake = new QRadioButton(tabTranslations);
        radioButtonTranslationsCmake->setObjectName(QString::fromUtf8("radioButtonTranslationsCmake"));
        radioButtonTranslationsCmake->setText(QString::fromUtf8("cmake"));

        horizontalLayoutTranslationsMake->addWidget(radioButtonTranslationsCmake);

        horizontalSpacerTranslationMake = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayoutTranslationsMake->addItem(horizontalSpacerTranslationMake);


        formLayoutTranslations->setLayout(2, QFormLayout::FieldRole, horizontalLayoutTranslationsMake);

        labelTranslationsSource = new QLabel(tabTranslations);
        labelTranslationsSource->setObjectName(QString::fromUtf8("labelTranslationsSource"));

        formLayoutTranslations->setWidget(3, QFormLayout::LabelRole, labelTranslationsSource);

        horizontalLayoutTranslationsSource = new QHBoxLayout();
        horizontalLayoutTranslationsSource->setObjectName(QString::fromUtf8("horizontalLayoutTranslationsSource"));
        lineEditTranslationsSource = new QLineEdit(tabTranslations);
        lineEditTranslationsSource->setObjectName(QString::fromUtf8("lineEditTranslationsSource"));
        lineEditTranslationsSource->setInputMask(QString::fromUtf8(""));
        lineEditTranslationsSource->setText(QString::fromUtf8(""));
        lineEditTranslationsSource->setPlaceholderText(QString::fromUtf8(""));

        horizontalLayoutTranslationsSource->addWidget(lineEditTranslationsSource);

        pushButtonTranslationsSourceBrowse = new QPushButton(tabTranslations);
        pushButtonTranslationsSourceBrowse->setObjectName(QString::fromUtf8("pushButtonTranslationsSourceBrowse"));

        horizontalLayoutTranslationsSource->addWidget(pushButtonTranslationsSourceBrowse);


        formLayoutTranslations->setLayout(3, QFormLayout::FieldRole, horizontalLayoutTranslationsSource);

        labelTranslationsDoxyfile = new QLabel(tabTranslations);
        labelTranslationsDoxyfile->setObjectName(QString::fromUtf8("labelTranslationsDoxyfile"));

        formLayoutTranslations->setWidget(4, QFormLayout::LabelRole, labelTranslationsDoxyfile);

        horizontalLayoutTranslationsDestination = new QHBoxLayout();
        horizontalLayoutTranslationsDestination->setObjectName(QString::fromUtf8("horizontalLayoutTranslationsDestination"));
        lineEditTranslationsDoxyfile = new QLineEdit(tabTranslations);
        lineEditTranslationsDoxyfile->setObjectName(QString::fromUtf8("lineEditTranslationsDoxyfile"));
        lineEditTranslationsDoxyfile->setInputMask(QString::fromUtf8(""));
        lineEditTranslationsDoxyfile->setText(QString::fromUtf8(""));
        lineEditTranslationsDoxyfile->setPlaceholderText(QString::fromUtf8(""));

        horizontalLayoutTranslationsDestination->addWidget(lineEditTranslationsDoxyfile);

        pushButtonTranslationsDoxyfileBrowse = new QPushButton(tabTranslations);
        pushButtonTranslationsDoxyfileBrowse->setObjectName(QString::fromUtf8("pushButtonTranslationsDoxyfileBrowse"));

        horizontalLayoutTranslationsDestination->addWidget(pushButtonTranslationsDoxyfileBrowse);


        formLayoutTranslations->setLayout(4, QFormLayout::FieldRole, horizontalLayoutTranslationsDestination);

        labelTranslationSourceLanguage = new QLabel(tabTranslations);
        labelTranslationSourceLanguage->setObjectName(QString::fromUtf8("labelTranslationSourceLanguage"));

        formLayoutTranslations->setWidget(5, QFormLayout::LabelRole, labelTranslationSourceLanguage);

        horizontalLayoutTranslationSourceLang = new QHBoxLayout();
        horizontalLayoutTranslationSourceLang->setObjectName(QString::fromUtf8("horizontalLayoutTranslationSourceLang"));
        comboBoxTranslationSourceLanguage = new QComboBox(tabTranslations);
        comboBoxTranslationSourceLanguage->setObjectName(QString::fromUtf8("comboBoxTranslationSourceLanguage"));
        comboBoxTranslationSourceLanguage->setCurrentText(QString::fromUtf8(""));

        horizontalLayoutTranslationSourceLang->addWidget(comboBoxTranslationSourceLanguage);

        labelTranslationsSourceLanguageCode = new QLabel(tabTranslations);
        labelTranslationsSourceLanguageCode->setObjectName(QString::fromUtf8("labelTranslationsSourceLanguageCode"));
        labelTranslationsSourceLanguageCode->setText(QString::fromUtf8("en"));

        horizontalLayoutTranslationSourceLang->addWidget(labelTranslationsSourceLanguageCode);

        horizontalSpacerTranslationsSourceLang = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayoutTranslationSourceLang->addItem(horizontalSpacerTranslationsSourceLang);


        formLayoutTranslations->setLayout(5, QFormLayout::FieldRole, horizontalLayoutTranslationSourceLang);

        labelTranslationsHelp = new QLabel(tabTranslations);
        labelTranslationsHelp->setObjectName(QString::fromUtf8("labelTranslationsHelp"));

        formLayoutTranslations->setWidget(6, QFormLayout::LabelRole, labelTranslationsHelp);

        horizontalLayoutTranslationsHelp = new QHBoxLayout();
        horizontalLayoutTranslationsHelp->setObjectName(QString::fromUtf8("horizontalLayoutTranslationsHelp"));
        lineEditTranslationsHelp = new QLineEdit(tabTranslations);
        lineEditTranslationsHelp->setObjectName(QString::fromUtf8("lineEditTranslationsHelp"));
        lineEditTranslationsHelp->setInputMask(QString::fromUtf8(""));
        lineEditTranslationsHelp->setText(QString::fromUtf8(""));
        lineEditTranslationsHelp->setPlaceholderText(QString::fromUtf8(""));

        horizontalLayoutTranslationsHelp->addWidget(lineEditTranslationsHelp);

        pushButtonTranslationsHelp = new QPushButton(tabTranslations);
        pushButtonTranslationsHelp->setObjectName(QString::fromUtf8("pushButtonTranslationsHelp"));

        horizontalLayoutTranslationsHelp->addWidget(pushButtonTranslationsHelp);


        formLayoutTranslations->setLayout(6, QFormLayout::FieldRole, horizontalLayoutTranslationsHelp);

        labelTranslationsCountryCode = new QLabel(tabTranslations);
        labelTranslationsCountryCode->setObjectName(QString::fromUtf8("labelTranslationsCountryCode"));

        formLayoutTranslations->setWidget(8, QFormLayout::LabelRole, labelTranslationsCountryCode);

        scrollArea = new QScrollArea(tabTranslations);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1212, 1310));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayoutCountryCodes = new QGridLayout();
        gridLayoutCountryCodes->setObjectName(QString::fromUtf8("gridLayoutCountryCodes"));
        checkBoxTranslationsTO = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsTO->setObjectName(QString::fromUtf8("checkBoxTranslationsTO"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsTO, 28, 1, 1, 1);

        checkBoxTranslationsFY = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsFY->setObjectName(QString::fromUtf8("checkBoxTranslationsFY"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsFY, 7, 4, 1, 1);

        checkBoxTranslationsTE = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsTE->setObjectName(QString::fromUtf8("checkBoxTranslationsTE"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsTE, 28, 2, 1, 1);

        checkBoxTranslationsTT = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsTT->setObjectName(QString::fromUtf8("checkBoxTranslationsTT"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsTT, 27, 4, 1, 1);

        checkBoxTranslationsLV = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsLV->setObjectName(QString::fromUtf8("checkBoxTranslationsLV"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsLV, 16, 2, 1, 1);

        checkBoxTranslationsCS = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsCS->setObjectName(QString::fromUtf8("checkBoxTranslationsCS"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsCS, 4, 3, 1, 1);

        checkBoxTranslationsKY = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsKY->setObjectName(QString::fromUtf8("checkBoxTranslationsKY"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsKY, 15, 1, 1, 1);

        checkBoxTranslationsZU = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsZU->setObjectName(QString::fromUtf8("checkBoxTranslationsZU"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsZU, 35, 0, 1, 1);

        checkBoxTranslationsRW = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsRW->setObjectName(QString::fromUtf8("checkBoxTranslationsRW"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsRW, 14, 3, 1, 1);

        checkBoxTranslationsHI = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsHI->setObjectName(QString::fromUtf8("checkBoxTranslationsHI"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsHI, 10, 4, 1, 1);

        checkBoxTranslationsTLH_QAAK = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsTLH_QAAK->setObjectName(QString::fromUtf8("checkBoxTranslationsTLH_QAAK"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsTLH_QAAK, 15, 3, 1, 1);

        checkBoxTranslationsLB = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsLB->setObjectName(QString::fromUtf8("checkBoxTranslationsLB"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsLB, 16, 4, 1, 1);

        checkBoxTranslationsHT = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsHT->setObjectName(QString::fromUtf8("checkBoxTranslationsHT"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsHT, 10, 0, 1, 1);

        checkBoxTranslationsEN = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsEN->setObjectName(QString::fromUtf8("checkBoxTranslationsEN"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsEN, 6, 0, 1, 1);

        checkBoxTranslationsKN = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsKN->setObjectName(QString::fromUtf8("checkBoxTranslationsKN"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsKN, 14, 0, 1, 1);

        checkBoxTranslationsPL = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsPL->setObjectName(QString::fromUtf8("checkBoxTranslationsPL"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsPL, 21, 1, 1, 1);

        checkBoxTranslationsNL = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsNL->setObjectName(QString::fromUtf8("checkBoxTranslationsNL"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsNL, 5, 1, 1, 1);

        checkBoxTranslationsSM = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsSM->setObjectName(QString::fromUtf8("checkBoxTranslationsSM"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsSM, 24, 0, 1, 1);

        checkBoxTranslationsAPC = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsAPC->setObjectName(QString::fromUtf8("checkBoxTranslationsAPC"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsAPC, 1, 1, 1, 1);

        checkBoxTranslationsTH = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsTH->setObjectName(QString::fromUtf8("checkBoxTranslationsTH"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsTH, 27, 5, 1, 1);

        checkBoxTranslationsNY = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsNY->setObjectName(QString::fromUtf8("checkBoxTranslationsNY"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsNY, 3, 3, 1, 1);

        checkBoxTranslationsMS = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsMS->setObjectName(QString::fromUtf8("checkBoxTranslationsMS"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsMS, 17, 3, 1, 1);

        checkBoxTranslationsIG = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsIG->setObjectName(QString::fromUtf8("checkBoxTranslationsIG"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsIG, 12, 1, 1, 1);

        checkBoxTranslationsVI = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsVI->setObjectName(QString::fromUtf8("checkBoxTranslationsVI"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsVI, 31, 1, 1, 1);

        checkBoxTranslationsFO = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsFO->setObjectName(QString::fromUtf8("checkBoxTranslationsFO"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsFO, 7, 0, 1, 1);

        checkBoxTranslationsAM = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsAM->setObjectName(QString::fromUtf8("checkBoxTranslationsAM"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsAM, 0, 2, 1, 1);

        checkBoxTranslationsGA = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsGA->setObjectName(QString::fromUtf8("checkBoxTranslationsGA"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsGA, 12, 3, 1, 1);

        checkBoxTranslationsSQ = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsSQ->setObjectName(QString::fromUtf8("checkBoxTranslationsSQ"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsSQ, 0, 1, 1, 1);

        checkBoxTranslationsOR = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsOR->setObjectName(QString::fromUtf8("checkBoxTranslationsOR"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsOR, 20, 0, 1, 1);

        checkBoxTranslationsFR = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsFR->setObjectName(QString::fromUtf8("checkBoxTranslationsFR"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsFR, 7, 5, 1, 1);

        checkBoxTranslationsHU = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsHU->setObjectName(QString::fromUtf8("checkBoxTranslationsHU"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsHU, 10, 5, 1, 1);

        checkBoxTranslationsFIL = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsFIL->setObjectName(QString::fromUtf8("checkBoxTranslationsFIL"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsFIL, 8, 1, 1, 1);

        checkBoxTranslationsGD = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsGD->setObjectName(QString::fromUtf8("checkBoxTranslationsGD"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsGD, 9, 0, 1, 1);

        checkBoxTranslationsID = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsID->setObjectName(QString::fromUtf8("checkBoxTranslationsID"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsID, 12, 2, 1, 1);

        checkBoxTranslationsKM = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsKM->setObjectName(QString::fromUtf8("checkBoxTranslationsKM"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsKM, 14, 2, 1, 1);

        checkBoxTranslationsRU = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsRU->setObjectName(QString::fromUtf8("checkBoxTranslationsRU"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsRU, 23, 2, 1, 1);

        checkBoxTranslationsRO = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsRO->setObjectName(QString::fromUtf8("checkBoxTranslationsRO"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsRO, 23, 1, 1, 1);

        checkBoxTranslationsMG = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsMG->setObjectName(QString::fromUtf8("checkBoxTranslationsMG"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsMG, 17, 1, 1, 1);

        checkBoxTranslationsTL = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsTL->setObjectName(QString::fromUtf8("checkBoxTranslationsTL"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsTL, 27, 0, 1, 1);

        checkBoxTranslationsMN = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsMN->setObjectName(QString::fromUtf8("checkBoxTranslationsMN"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsMN, 18, 3, 1, 1);

        checkBoxTranslationsPT = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsPT->setObjectName(QString::fromUtf8("checkBoxTranslationsPT"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsPT, 21, 2, 1, 1);

        checkBoxTranslationsNB = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsNB->setObjectName(QString::fromUtf8("checkBoxTranslationsNB"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsNB, 19, 2, 1, 1);

        checkBoxTranslationsGU = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsGU->setObjectName(QString::fromUtf8("checkBoxTranslationsGU"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsGU, 9, 4, 1, 1);

        checkBoxTranslationsNE = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsNE->setObjectName(QString::fromUtf8("checkBoxTranslationsNE"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsNE, 19, 0, 1, 1);

        checkBoxTranslationsFI = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsFI->setObjectName(QString::fromUtf8("checkBoxTranslationsFI"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsFI, 7, 2, 1, 1);

        checkBoxTranslationsZH_CN = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsZH_CN->setObjectName(QString::fromUtf8("checkBoxTranslationsZH_CN"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsZH_CN, 4, 2, 1, 1);

        checkBoxTranslationsVE = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsVE->setObjectName(QString::fromUtf8("checkBoxTranslationsVE"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsVE, 31, 0, 1, 1);

        checkBoxTranslationsAR = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsAR->setObjectName(QString::fromUtf8("checkBoxTranslationsAR"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsAR, 0, 3, 1, 1);

        checkBoxTranslationsKA = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsKA->setObjectName(QString::fromUtf8("checkBoxTranslationsKA"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsKA, 9, 2, 1, 1);

        checkBoxTranslationsZH_TW = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsZH_TW->setObjectName(QString::fromUtf8("checkBoxTranslationsZH_TW"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsZH_TW, 4, 1, 1, 1);

        checkBoxTranslationsLA = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsLA->setObjectName(QString::fromUtf8("checkBoxTranslationsLA"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsLA, 16, 1, 1, 1);

        checkBoxTranslationsFJ = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsFJ->setObjectName(QString::fromUtf8("checkBoxTranslationsFJ"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsFJ, 7, 3, 1, 1);

        checkBoxTranslationsEL = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsEL->setObjectName(QString::fromUtf8("checkBoxTranslationsEL"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsEL, 9, 5, 1, 1);

        checkBoxTranslationsLO = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsLO->setObjectName(QString::fromUtf8("checkBoxTranslationsLO"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsLO, 16, 0, 1, 1);

        checkBoxTranslationsCO = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsCO->setObjectName(QString::fromUtf8("checkBoxTranslationsCO"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsCO, 3, 4, 1, 1);

        checkBoxTranslationsTLH = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsTLH->setObjectName(QString::fromUtf8("checkBoxTranslationsTLH"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsTLH, 15, 2, 1, 1);

        checkBoxTranslationsBN = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsBN->setObjectName(QString::fromUtf8("checkBoxTranslationsBN"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsBN, 2, 3, 1, 1);

        checkBoxTranslationsTY = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsTY->setObjectName(QString::fromUtf8("checkBoxTranslationsTY"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsTY, 27, 1, 1, 1);

        checkBoxTranslationsET = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsET->setObjectName(QString::fromUtf8("checkBoxTranslationsET"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsET, 6, 1, 1, 1);

        checkBoxTranslationsPAP = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsPAP->setObjectName(QString::fromUtf8("checkBoxTranslationsPAP"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsPAP, 21, 0, 1, 1);

        checkBoxTranslationsFA = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsFA->setObjectName(QString::fromUtf8("checkBoxTranslationsFA"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsFA, 7, 1, 1, 1);

        checkBoxTranslationsDA = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsDA->setObjectName(QString::fromUtf8("checkBoxTranslationsDA"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsDA, 5, 0, 1, 1);

        checkBoxTranslationsNO = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsNO->setObjectName(QString::fromUtf8("checkBoxTranslationsNO"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsNO, 19, 1, 1, 1);

        checkBoxTranslationsDE = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsDE->setObjectName(QString::fromUtf8("checkBoxTranslationsDE"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsDE, 9, 3, 1, 1);

        checkBoxTranslationsCEB = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsCEB->setObjectName(QString::fromUtf8("checkBoxTranslationsCEB"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsCEB, 3, 2, 1, 1);

        checkBoxTranslationsTS = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsTS->setObjectName(QString::fromUtf8("checkBoxTranslationsTS"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsTS, 28, 3, 1, 1);

        horizontalSpacerTranslations = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayoutCountryCodes->addItem(horizontalSpacerTranslations, 0, 6, 1, 1);

        checkBoxTranslationsMR = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsMR->setObjectName(QString::fromUtf8("checkBoxTranslationsMR"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsMR, 18, 1, 1, 1);

        checkBoxTranslationsCY = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsCY->setObjectName(QString::fromUtf8("checkBoxTranslationsCY"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsCY, 32, 0, 1, 1);

        checkBoxTranslationsNN = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsNN->setObjectName(QString::fromUtf8("checkBoxTranslationsNN"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsNN, 19, 3, 1, 1);

        checkBoxTranslationsKO = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsKO->setObjectName(QString::fromUtf8("checkBoxTranslationsKO"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsKO, 14, 4, 1, 1);

        checkBoxTranslationsML = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsML->setObjectName(QString::fromUtf8("checkBoxTranslationsML"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsML, 17, 2, 1, 1);

        checkBoxTranslationsXH = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsXH->setObjectName(QString::fromUtf8("checkBoxTranslationsXH"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsXH, 33, 0, 1, 1);

        checkBoxTranslationsYO = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsYO->setObjectName(QString::fromUtf8("checkBoxTranslationsYO"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsYO, 34, 1, 1, 1);

        checkBoxTranslationsPA = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsPA->setObjectName(QString::fromUtf8("checkBoxTranslationsPA"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsPA, 21, 4, 1, 1);

        checkBoxTranslationsBS = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsBS->setObjectName(QString::fromUtf8("checkBoxTranslationsBS"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsBS, 2, 4, 1, 1);

        checkBoxTranslationsHMN = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsHMN->setObjectName(QString::fromUtf8("checkBoxTranslationsHMN"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsHMN, 11, 2, 1, 1);

        checkBoxTranslationsGL = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsGL->setObjectName(QString::fromUtf8("checkBoxTranslationsGL"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsGL, 9, 1, 1, 1);

        checkBoxTranslationsHAW = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsHAW->setObjectName(QString::fromUtf8("checkBoxTranslationsHAW"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsHAW, 10, 2, 1, 1);

        checkBoxTranslationsMY = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsMY->setObjectName(QString::fromUtf8("checkBoxTranslationsMY"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsMY, 18, 4, 1, 1);

        checkBoxTranslationsAF = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsAF->setObjectName(QString::fromUtf8("checkBoxTranslationsAF"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsAF, 0, 0, 1, 1);

        checkBoxTranslationsMHR = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsMHR->setObjectName(QString::fromUtf8("checkBoxTranslationsMHR"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsMHR, 18, 2, 1, 1);

        checkBoxTranslationsBA = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsBA->setObjectName(QString::fromUtf8("checkBoxTranslationsBA"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsBA, 2, 1, 1, 1);

        checkBoxTranslationsCA = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsCA->setObjectName(QString::fromUtf8("checkBoxTranslationsCA"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsCA, 3, 1, 1, 1);

        checkBoxTranslationsYI = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsYI->setObjectName(QString::fromUtf8("checkBoxTranslationsYI"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsYI, 34, 0, 1, 1);

        checkBoxTranslationsJA = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsJA->setObjectName(QString::fromUtf8("checkBoxTranslationsJA"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsJA, 13, 0, 1, 1);

        checkBoxTranslationsJW = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsJW->setObjectName(QString::fromUtf8("checkBoxTranslationsJW"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsJW, 13, 1, 1, 1);

        checkBoxTranslationsBG = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsBG->setObjectName(QString::fromUtf8("checkBoxTranslationsBG"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsBG, 2, 5, 1, 1);

        checkBoxTranslationsSR = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsSR->setObjectName(QString::fromUtf8("checkBoxTranslationsSR"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsSR, 24, 1, 1, 1);

        checkBoxTranslationsTR = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsTR->setObjectName(QString::fromUtf8("checkBoxTranslationsTR"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsTR, 28, 5, 1, 1);

        checkBoxTranslationsTA = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsTA->setObjectName(QString::fromUtf8("checkBoxTranslationsTA"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsTA, 27, 3, 1, 1);

        checkBoxTranslationsMI = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsMI->setObjectName(QString::fromUtf8("checkBoxTranslationsMI"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsMI, 17, 5, 1, 1);

        checkBoxTranslationsHR = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsHR->setObjectName(QString::fromUtf8("checkBoxTranslationsHR"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsHR, 3, 5, 1, 1);

        checkBoxTranslationsPS = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsPS->setObjectName(QString::fromUtf8("checkBoxTranslationsPS"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsPS, 21, 3, 1, 1);

        checkBoxTranslationsHY = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsHY->setObjectName(QString::fromUtf8("checkBoxTranslationsHY"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsHY, 0, 4, 1, 1);

        checkBoxTranslationsTN = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsTN->setObjectName(QString::fromUtf8("checkBoxTranslationsTN"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsTN, 28, 4, 1, 1);

        checkBoxTranslationsKU = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsKU->setObjectName(QString::fromUtf8("checkBoxTranslationsKU"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsKU, 14, 5, 1, 1);

        checkBoxTranslationsHE = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsHE->setObjectName(QString::fromUtf8("checkBoxTranslationsHE"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsHE, 10, 3, 1, 1);

        checkBoxTranslationsMT = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsMT->setObjectName(QString::fromUtf8("checkBoxTranslationsMT"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsMT, 17, 4, 1, 1);

        checkBoxTranslationsIT = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsIT->setObjectName(QString::fromUtf8("checkBoxTranslationsIT"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsIT, 12, 4, 1, 1);

        checkBoxTranslationsEU = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsEU->setObjectName(QString::fromUtf8("checkBoxTranslationsEU"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsEU, 2, 0, 1, 1);

        checkBoxTranslationsTG = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsTG->setObjectName(QString::fromUtf8("checkBoxTranslationsTG"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsTG, 27, 2, 1, 1);

        checkBoxTranslationsAZ = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsAZ->setObjectName(QString::fromUtf8("checkBoxTranslationsAZ"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsAZ, 0, 5, 1, 1);

        checkBoxTranslationsTK = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsTK->setObjectName(QString::fromUtf8("checkBoxTranslationsTK"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsTK, 29, 1, 1, 1);

        checkBoxTranslationsHA = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsHA->setObjectName(QString::fromUtf8("checkBoxTranslationsHA"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsHA, 10, 1, 1, 1);

        checkBoxTranslationsIS = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsIS->setObjectName(QString::fromUtf8("checkBoxTranslationsIS"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsIS, 12, 0, 1, 1);

        checkBoxTranslationsYUE = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsYUE->setObjectName(QString::fromUtf8("checkBoxTranslationsYUE"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsYUE, 3, 0, 1, 1);

        checkBoxTranslationsBE = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsBE->setObjectName(QString::fromUtf8("checkBoxTranslationsBE"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsBE, 2, 2, 1, 1);

        checkBoxTranslationsMRJ = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsMRJ->setObjectName(QString::fromUtf8("checkBoxTranslationsMRJ"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsMRJ, 11, 1, 1, 1);

        checkBoxTranslationsKK = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsKK->setObjectName(QString::fromUtf8("checkBoxTranslationsKK"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsKK, 14, 1, 1, 1);

        checkBoxTranslationsRM = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsRM->setObjectName(QString::fromUtf8("checkBoxTranslationsRM"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsRM, 23, 0, 1, 1);

        checkBoxTranslationsMK = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsMK->setObjectName(QString::fromUtf8("checkBoxTranslationsMK"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsMK, 17, 0, 1, 1);

        checkBoxTranslationsEO = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsEO->setObjectName(QString::fromUtf8("checkBoxTranslationsEO"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsEO, 6, 2, 1, 1);

        checkBoxTranslationsLT = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsLT->setObjectName(QString::fromUtf8("checkBoxTranslationsLT"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsLT, 16, 3, 1, 1);

        checkBoxTranslationsOTQ = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsOTQ->setObjectName(QString::fromUtf8("checkBoxTranslationsOTQ"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsOTQ, 22, 0, 1, 1);

        checkBoxTranslationsSW = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsSW->setObjectName(QString::fromUtf8("checkBoxTranslationsSW"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsSW, 26, 4, 1, 1);

        checkBoxTranslationsSU = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsSU->setObjectName(QString::fromUtf8("checkBoxTranslationsSU"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsSU, 26, 3, 1, 1);

        checkBoxTranslationsSO = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsSO->setObjectName(QString::fromUtf8("checkBoxTranslationsSO"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsSO, 26, 2, 1, 1);

        checkBoxTranslationsSI = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsSI->setObjectName(QString::fromUtf8("checkBoxTranslationsSI"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsSI, 26, 1, 1, 1);

        checkBoxTranslationsSD = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsSD->setObjectName(QString::fromUtf8("checkBoxTranslationsSD"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsSD, 25, 5, 1, 1);

        checkBoxTranslationsES = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsES->setObjectName(QString::fromUtf8("checkBoxTranslationsES"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsES, 25, 4, 1, 1);

        checkBoxTranslationsSB = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsSB->setObjectName(QString::fromUtf8("checkBoxTranslationsSB"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsSB, 25, 3, 1, 1);

        checkBoxTranslationsSV = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsSV->setObjectName(QString::fromUtf8("checkBoxTranslationsSV"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsSV, 25, 2, 1, 1);

        checkBoxTranslationsSN = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsSN->setObjectName(QString::fromUtf8("checkBoxTranslationsSN"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsSN, 25, 1, 1, 1);

        checkBoxTranslationsSL = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsSL->setObjectName(QString::fromUtf8("checkBoxTranslationsSL"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsSL, 24, 5, 1, 1);

        checkBoxTranslationsSK = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsSK->setObjectName(QString::fromUtf8("checkBoxTranslationsSK"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsSK, 24, 4, 1, 1);

        checkBoxTranslationsST = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsST->setObjectName(QString::fromUtf8("checkBoxTranslationsST"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsST, 24, 3, 1, 1);

        checkBoxTranslationsSR_LATIN = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsSR_LATIN->setObjectName(QString::fromUtf8("checkBoxTranslationsSR_LATIN"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsSR_LATIN, 24, 2, 1, 1);

        checkBoxTranslationsUZ = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsUZ->setObjectName(QString::fromUtf8("checkBoxTranslationsUZ"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsUZ, 30, 4, 1, 1);

        checkBoxTranslationsUR = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsUR->setObjectName(QString::fromUtf8("checkBoxTranslationsUR"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsUR, 30, 3, 1, 1);

        checkBoxTranslationsUG = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsUG->setObjectName(QString::fromUtf8("checkBoxTranslationsUG"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsUG, 30, 2, 1, 1);

        checkBoxTranslationsUK = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsUK->setObjectName(QString::fromUtf8("checkBoxTranslationsUK"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsUK, 30, 1, 1, 1);

        checkBoxTranslationsUDM = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsUDM->setObjectName(QString::fromUtf8("checkBoxTranslationsUDM"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsUDM, 30, 0, 1, 1);

        checkBoxTranslationsYUA = new QCheckBox(scrollAreaWidgetContents);
        checkBoxTranslationsYUA->setObjectName(QString::fromUtf8("checkBoxTranslationsYUA"));

        gridLayoutCountryCodes->addWidget(checkBoxTranslationsYUA, 34, 2, 1, 1);


        gridLayout_2->addLayout(gridLayoutCountryCodes, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        formLayoutTranslations->setWidget(8, QFormLayout::FieldRole, scrollArea);

        labelProjectName = new QLabel(tabTranslations);
        labelProjectName->setObjectName(QString::fromUtf8("labelProjectName"));

        formLayoutTranslations->setWidget(0, QFormLayout::LabelRole, labelProjectName);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        comboBoxTranslationsProjectNames = new QComboBox(tabTranslations);
        comboBoxTranslationsProjectNames->setObjectName(QString::fromUtf8("comboBoxTranslationsProjectNames"));

        horizontalLayout_2->addWidget(comboBoxTranslationsProjectNames);

        lineEditProjectName = new QLineEdit(tabTranslations);
        lineEditProjectName->setObjectName(QString::fromUtf8("lineEditProjectName"));

        horizontalLayout_2->addWidget(lineEditProjectName);

        labelRecordIdProject = new QLabel(tabTranslations);
        labelRecordIdProject->setObjectName(QString::fromUtf8("labelRecordIdProject"));
        labelRecordIdProject->setText(QString::fromUtf8("#"));

        horizontalLayout_2->addWidget(labelRecordIdProject);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        pushButtonTranslationsProjectBrowser = new QPushButton(tabTranslations);
        pushButtonTranslationsProjectBrowser->setObjectName(QString::fromUtf8("pushButtonTranslationsProjectBrowser"));

        horizontalLayout_2->addWidget(pushButtonTranslationsProjectBrowser);


        formLayoutTranslations->setLayout(0, QFormLayout::FieldRole, horizontalLayout_2);

        labelTranslationsOptions = new QLabel(tabTranslations);
        labelTranslationsOptions->setObjectName(QString::fromUtf8("labelTranslationsOptions"));

        formLayoutTranslations->setWidget(7, QFormLayout::LabelRole, labelTranslationsOptions);

        horizontalLayoutTranslationsOptions = new QHBoxLayout();
        horizontalLayoutTranslationsOptions->setObjectName(QString::fromUtf8("horizontalLayoutTranslationsOptions"));
        pushButtonTranslationsSave = new QPushButton(tabTranslations);
        pushButtonTranslationsSave->setObjectName(QString::fromUtf8("pushButtonTranslationsSave"));

        horizontalLayoutTranslationsOptions->addWidget(pushButtonTranslationsSave);

        pushButtonTranslationsClear = new QPushButton(tabTranslations);
        pushButtonTranslationsClear->setObjectName(QString::fromUtf8("pushButtonTranslationsClear"));

        horizontalLayoutTranslationsOptions->addWidget(pushButtonTranslationsClear);

        pushButtonTranslationsAdd = new QPushButton(tabTranslations);
        pushButtonTranslationsAdd->setObjectName(QString::fromUtf8("pushButtonTranslationsAdd"));

        horizontalLayoutTranslationsOptions->addWidget(pushButtonTranslationsAdd);

        pushButtonTranslationsDelete = new QPushButton(tabTranslations);
        pushButtonTranslationsDelete->setObjectName(QString::fromUtf8("pushButtonTranslationsDelete"));

        horizontalLayoutTranslationsOptions->addWidget(pushButtonTranslationsDelete);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayoutTranslationsOptions->addItem(horizontalSpacer_3);


        formLayoutTranslations->setLayout(7, QFormLayout::FieldRole, horizontalLayoutTranslationsOptions);


        verticalLayout_4->addLayout(formLayoutTranslations);

        tabWidget->addTab(tabTranslations, QString());
        tabProject = new QWidget();
        tabProject->setObjectName(QString::fromUtf8("tabProject"));
        verticalLayout_5 = new QVBoxLayout(tabProject);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        textEditProjects = new QTextEdit(tabProject);
        textEditProjects->setObjectName(QString::fromUtf8("textEditProjects"));

        verticalLayout_5->addWidget(textEditProjects);

        progressBarProjectsFiles = new QProgressBar(tabProject);
        progressBarProjectsFiles->setObjectName(QString::fromUtf8("progressBarProjectsFiles"));
        progressBarProjectsFiles->setValue(24);

        verticalLayout_5->addWidget(progressBarProjectsFiles);

        progressBarProjectsTranslations = new QProgressBar(tabProject);
        progressBarProjectsTranslations->setObjectName(QString::fromUtf8("progressBarProjectsTranslations"));
        progressBarProjectsTranslations->setValue(24);

        verticalLayout_5->addWidget(progressBarProjectsTranslations);

        tabWidget->addTab(tabProject, QString());
        tabHelp = new QWidget();
        tabHelp->setObjectName(QString::fromUtf8("tabHelp"));
        verticalLayout_6 = new QVBoxLayout(tabHelp);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        textEditHelp = new QTextEdit(tabHelp);
        textEditHelp->setObjectName(QString::fromUtf8("textEditHelp"));

        verticalLayout_6->addWidget(textEditHelp);

        tabWidget->addTab(tabHelp, QString());

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1415, 29));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionCompile);
        menuFile->addAction(actionAccept_Translations);
        menuFile->addAction(actionTranslate_ReadMe);
        menuFile->addAction(actionTranslate_Help);
        menuFile->addSeparator();
        menuFile->addAction(actionClipboard);
        menuFile->addSeparator();
        menuFile->addAction(actionSave);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuHelp->addSeparator();
        menuHelp->addAction(actionAbout);
        menuHelp->addSeparator();
        menuHelp->addAction(actionAuthor);
        menuHelp->addSeparator();
        menuHelp->addAction(actionHelp);
        toolBar->addAction(actionSave);
        toolBar->addSeparator();
        toolBar->addAction(actionCompile);
        toolBar->addAction(actionTranslate_Help);
        toolBar->addAction(actionTranslate_ReadMe);
        toolBar->addAction(actionAccept_Translations);
        toolBar->addSeparator();
        toolBar->addAction(actionClipboard);
        toolBar->addSeparator();
        toolBar->addAction(actionAbout);
        toolBar->addAction(actionAuthor);
        toolBar->addAction(actionHelp);
        toolBar->addSeparator();
        toolBar->addAction(actionExit);
        toolBar->addSeparator();

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        actionAbout->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
        actionHelp->setText(QCoreApplication::translate("MainWindow", "Help", nullptr));
        actionCompile->setText(QCoreApplication::translate("MainWindow", "Translate", nullptr));
        actionClipboard->setText(QCoreApplication::translate("MainWindow", "Clipboard", nullptr));
        actionAuthor->setText(QCoreApplication::translate("MainWindow", "Author", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        actionTranslate_Help->setText(QCoreApplication::translate("MainWindow", "Translate Help", nullptr));
        actionAccept_Translations->setText(QCoreApplication::translate("MainWindow", "Accept Translations", nullptr));
        actionTranslate_ReadMe->setText(QCoreApplication::translate("MainWindow", "Translate ReadMe", nullptr));
        labelSettingsLanguage->setText(QCoreApplication::translate("MainWindow", "Change Language", nullptr));
#if QT_CONFIG(accessibility)
        comboBoxLanguage->setAccessibleName(QString());
#endif // QT_CONFIG(accessibility)
#if QT_CONFIG(accessibility)
        comboBoxLanguage->setAccessibleDescription(QString());
#endif // QT_CONFIG(accessibility)
        pushButtonSettingsLupdate->setText(QCoreApplication::translate("MainWindow", "Browse", nullptr));
        labelSettingsLrelease->setText(QCoreApplication::translate("MainWindow", "lrelease", nullptr));
        pushButtonSettingsLrelease->setText(QCoreApplication::translate("MainWindow", "Browse", nullptr));
        labelSettingsUiLanguage->setText(QCoreApplication::translate("MainWindow", "UI Language", nullptr));
        labelSettingsTranslationEngine->setText(QCoreApplication::translate("MainWindow", "Translation Engines", nullptr));
        labelSettingsDelay->setText(QCoreApplication::translate("MainWindow", "Delay in Seconds", nullptr));
        labelSettignsMessaging->setText(QCoreApplication::translate("MainWindow", "Logging", nullptr));
        checkBoxSettignsMessaging->setText(QCoreApplication::translate("MainWindow", "Debug Messages", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabSettings), QCoreApplication::translate("MainWindow", "Settings", nullptr));
        labelSqlDatabaseName->setText(QCoreApplication::translate("MainWindow", "Database Name", nullptr));
        pushButtonSqlDatabaseNameBrowse->setText(QCoreApplication::translate("MainWindow", "Browse", nullptr));
        labelSqlHostName->setText(QCoreApplication::translate("MainWindow", "Host Name", nullptr));
        labelSqlUserName->setText(QCoreApplication::translate("MainWindow", "User Name", nullptr));
        labelSqlPassword->setText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        pushButtonSqlPasswordShow->setText(QCoreApplication::translate("MainWindow", "Show", nullptr));
        labelSqlOptions->setText(QCoreApplication::translate("MainWindow", "Options", nullptr));
        pushButtonSqlSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabSQL), QCoreApplication::translate("MainWindow", "SQL", nullptr));
        labelTranslationsProjectFolder->setText(QCoreApplication::translate("MainWindow", "Project Folder", nullptr));
        pushButtonTranslationsProjectFolderBrowse->setText(QCoreApplication::translate("MainWindow", "Browes", nullptr));
        labelTranslationMake->setText(QCoreApplication::translate("MainWindow", "Type make", nullptr));
        labelTranslationsSource->setText(QCoreApplication::translate("MainWindow", "Source", nullptr));
        pushButtonTranslationsSourceBrowse->setText(QCoreApplication::translate("MainWindow", "Browse", nullptr));
#if QT_CONFIG(tooltip)
        labelTranslationsDoxyfile->setToolTip(QCoreApplication::translate("MainWindow", "Tempoary Folder contents gets deleted", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        labelTranslationsDoxyfile->setStatusTip(QCoreApplication::translate("MainWindow", "Tempoary Folder contents gets deleted", nullptr));
#endif // QT_CONFIG(statustip)
        labelTranslationsDoxyfile->setText(QCoreApplication::translate("MainWindow", "Doxyfile", nullptr));
#if QT_CONFIG(statustip)
        lineEditTranslationsDoxyfile->setStatusTip(QCoreApplication::translate("MainWindow", "Tempoary Folder contents gets deleted", nullptr));
#endif // QT_CONFIG(statustip)
        pushButtonTranslationsDoxyfileBrowse->setText(QCoreApplication::translate("MainWindow", "Browse", nullptr));
        labelTranslationSourceLanguage->setText(QCoreApplication::translate("MainWindow", "Source Language", nullptr));
        labelTranslationsHelp->setText(QCoreApplication::translate("MainWindow", "Help Folder", nullptr));
        pushButtonTranslationsHelp->setText(QCoreApplication::translate("MainWindow", "Browse", nullptr));
        labelTranslationsCountryCode->setText(QCoreApplication::translate("MainWindow", "Country Codes", nullptr));
        checkBoxTranslationsTO->setText(QCoreApplication::translate("MainWindow", "Tongan - to", nullptr));
        checkBoxTranslationsFY->setText(QCoreApplication::translate("MainWindow", "Frisian - fy", nullptr));
        checkBoxTranslationsTE->setText(QCoreApplication::translate("MainWindow", "Telugu - te", nullptr));
        checkBoxTranslationsTT->setText(QCoreApplication::translate("MainWindow", "Tatar - tt", nullptr));
        checkBoxTranslationsLV->setText(QCoreApplication::translate("MainWindow", "Latvian - lv", nullptr));
        checkBoxTranslationsCS->setText(QCoreApplication::translate("MainWindow", "Czech - cs", nullptr));
        checkBoxTranslationsKY->setText(QCoreApplication::translate("MainWindow", "Kyrgyz - ky", nullptr));
        checkBoxTranslationsZU->setText(QCoreApplication::translate("MainWindow", "Zulu - zu", nullptr));
        checkBoxTranslationsRW->setText(QCoreApplication::translate("MainWindow", "Kinyarwanda - rw", nullptr));
        checkBoxTranslationsHI->setText(QCoreApplication::translate("MainWindow", "Hindi - hi", nullptr));
        checkBoxTranslationsTLH_QAAK->setText(QCoreApplication::translate("MainWindow", "KlingonPlqaD - tlh-Qaak", nullptr));
        checkBoxTranslationsLB->setText(QCoreApplication::translate("MainWindow", "Luxembourgish - lb", nullptr));
        checkBoxTranslationsHT->setText(QCoreApplication::translate("MainWindow", "Haitian - ht", nullptr));
        checkBoxTranslationsEN->setText(QCoreApplication::translate("MainWindow", "English - en", nullptr));
        checkBoxTranslationsKN->setText(QCoreApplication::translate("MainWindow", "Kannada - kn", nullptr));
        checkBoxTranslationsPL->setText(QCoreApplication::translate("MainWindow", "Polish - pl", nullptr));
        checkBoxTranslationsNL->setText(QCoreApplication::translate("MainWindow", "Dutch - nl", nullptr));
        checkBoxTranslationsSM->setText(QCoreApplication::translate("MainWindow", "Samoan - sm", nullptr));
        checkBoxTranslationsAPC->setText(QCoreApplication::translate("MainWindow", "Levantine Arabic - apc", nullptr));
        checkBoxTranslationsTH->setText(QCoreApplication::translate("MainWindow", "Thai - th", nullptr));
        checkBoxTranslationsNY->setText(QCoreApplication::translate("MainWindow", "Chichewa - ny", nullptr));
        checkBoxTranslationsMS->setText(QCoreApplication::translate("MainWindow", "Malaysian - ms", nullptr));
        checkBoxTranslationsIG->setText(QCoreApplication::translate("MainWindow", "Igbo - ig", nullptr));
        checkBoxTranslationsVI->setText(QCoreApplication::translate("MainWindow", "Vietnamese - vi", nullptr));
        checkBoxTranslationsFO->setText(QCoreApplication::translate("MainWindow", "Faeroese - fo", nullptr));
        checkBoxTranslationsAM->setText(QCoreApplication::translate("MainWindow", "Amharic - am", nullptr));
        checkBoxTranslationsGA->setText(QCoreApplication::translate("MainWindow", "Irish - ga", nullptr));
        checkBoxTranslationsSQ->setText(QCoreApplication::translate("MainWindow", "Albanian - sq", nullptr));
        checkBoxTranslationsOR->setText(QCoreApplication::translate("MainWindow", "Oriya - or", nullptr));
        checkBoxTranslationsFR->setText(QCoreApplication::translate("MainWindow", "French - fr", nullptr));
        checkBoxTranslationsHU->setText(QCoreApplication::translate("MainWindow", "Hungarian - hu", nullptr));
        checkBoxTranslationsFIL->setText(QCoreApplication::translate("MainWindow", "Filipino - fil", nullptr));
        checkBoxTranslationsGD->setText(QCoreApplication::translate("MainWindow", "Gaelic - gd", nullptr));
        checkBoxTranslationsID->setText(QCoreApplication::translate("MainWindow", "Indonesian - id", nullptr));
        checkBoxTranslationsKM->setText(QCoreApplication::translate("MainWindow", "Khmer - km", nullptr));
        checkBoxTranslationsRU->setText(QCoreApplication::translate("MainWindow", "Russian - ru", nullptr));
        checkBoxTranslationsRO->setText(QCoreApplication::translate("MainWindow", "Romanian - ro", nullptr));
        checkBoxTranslationsMG->setText(QCoreApplication::translate("MainWindow", "Malagasy - mg", nullptr));
        checkBoxTranslationsTL->setText(QCoreApplication::translate("MainWindow", "Tagalog - tl", nullptr));
        checkBoxTranslationsMN->setText(QCoreApplication::translate("MainWindow", "Mongolian - mn", nullptr));
        checkBoxTranslationsPT->setText(QCoreApplication::translate("MainWindow", "Portuguese - pt", nullptr));
        checkBoxTranslationsNB->setText(QCoreApplication::translate("MainWindow", "Bokmal - nb", nullptr));
        checkBoxTranslationsGU->setText(QCoreApplication::translate("MainWindow", "Gujarati - gu", nullptr));
        checkBoxTranslationsNE->setText(QCoreApplication::translate("MainWindow", "Nepali - ne", nullptr));
        checkBoxTranslationsFI->setText(QCoreApplication::translate("MainWindow", "Finnish - fi", nullptr));
        checkBoxTranslationsZH_CN->setText(QCoreApplication::translate("MainWindow", "S. China - zh-CN", nullptr));
        checkBoxTranslationsVE->setText(QCoreApplication::translate("MainWindow", "Venda - ve", nullptr));
        checkBoxTranslationsAR->setText(QCoreApplication::translate("MainWindow", "Arabic - ar", nullptr));
        checkBoxTranslationsKA->setText(QCoreApplication::translate("MainWindow", "Georgian - ka", nullptr));
        checkBoxTranslationsZH_TW->setText(QCoreApplication::translate("MainWindow", "T. China - zh-TW", nullptr));
        checkBoxTranslationsLA->setText(QCoreApplication::translate("MainWindow", "Latin - la", nullptr));
        checkBoxTranslationsFJ->setText(QCoreApplication::translate("MainWindow", "Fijian - fj", nullptr));
        checkBoxTranslationsEL->setText(QCoreApplication::translate("MainWindow", "Greek - el", nullptr));
        checkBoxTranslationsLO->setText(QCoreApplication::translate("MainWindow", "Lao - lo", nullptr));
        checkBoxTranslationsCO->setText(QCoreApplication::translate("MainWindow", "Corsican - co", nullptr));
        checkBoxTranslationsTLH->setText(QCoreApplication::translate("MainWindow", "Klingon - tlh", nullptr));
        checkBoxTranslationsBN->setText(QCoreApplication::translate("MainWindow", "Bengali - bn", nullptr));
        checkBoxTranslationsTY->setText(QCoreApplication::translate("MainWindow", "Tahitian - ty", nullptr));
        checkBoxTranslationsET->setText(QCoreApplication::translate("MainWindow", "Estonian - et", nullptr));
        checkBoxTranslationsPAP->setText(QCoreApplication::translate("MainWindow", "Papiamento - pap", nullptr));
        checkBoxTranslationsFA->setText(QCoreApplication::translate("MainWindow", "Farsi - fa", nullptr));
        checkBoxTranslationsDA->setText(QCoreApplication::translate("MainWindow", "Danish - da", nullptr));
        checkBoxTranslationsNO->setText(QCoreApplication::translate("MainWindow", "Norwegian - no", nullptr));
        checkBoxTranslationsDE->setText(QCoreApplication::translate("MainWindow", "German - de", nullptr));
        checkBoxTranslationsCEB->setText(QCoreApplication::translate("MainWindow", "Cebuano - ceb", nullptr));
        checkBoxTranslationsTS->setText(QCoreApplication::translate("MainWindow", "Tsonga - ts", nullptr));
        checkBoxTranslationsMR->setText(QCoreApplication::translate("MainWindow", "Marathi - mr", nullptr));
        checkBoxTranslationsCY->setText(QCoreApplication::translate("MainWindow", "Welsh - cy", nullptr));
        checkBoxTranslationsNN->setText(QCoreApplication::translate("MainWindow", "Nynorsk - nn", nullptr));
        checkBoxTranslationsKO->setText(QCoreApplication::translate("MainWindow", "Korean - ko", nullptr));
        checkBoxTranslationsML->setText(QCoreApplication::translate("MainWindow", "Malayalam - ml", nullptr));
        checkBoxTranslationsXH->setText(QCoreApplication::translate("MainWindow", "Xhosa - xh", nullptr));
        checkBoxTranslationsYO->setText(QCoreApplication::translate("MainWindow", "Yoruba - yo", nullptr));
        checkBoxTranslationsPA->setText(QCoreApplication::translate("MainWindow", "Punjabi - pa", nullptr));
        checkBoxTranslationsBS->setText(QCoreApplication::translate("MainWindow", "Bosnian - bs", nullptr));
        checkBoxTranslationsHMN->setText(QCoreApplication::translate("MainWindow", "Hmong - hmn", nullptr));
        checkBoxTranslationsGL->setText(QCoreApplication::translate("MainWindow", "Galician - gl", nullptr));
        checkBoxTranslationsHAW->setText(QCoreApplication::translate("MainWindow", "Hawaiian - haw", nullptr));
        checkBoxTranslationsMY->setText(QCoreApplication::translate("MainWindow", "Myanmar - my", nullptr));
        checkBoxTranslationsAF->setText(QCoreApplication::translate("MainWindow", "Afrikaans - af", nullptr));
        checkBoxTranslationsMHR->setText(QCoreApplication::translate("MainWindow", "Mari - mhr", nullptr));
        checkBoxTranslationsBA->setText(QCoreApplication::translate("MainWindow", "Bashkir - ba", nullptr));
        checkBoxTranslationsCA->setText(QCoreApplication::translate("MainWindow", "Catalan - ca", nullptr));
        checkBoxTranslationsYI->setText(QCoreApplication::translate("MainWindow", "Yiddish - yi", nullptr));
        checkBoxTranslationsJA->setText(QCoreApplication::translate("MainWindow", "Japanese - ja", nullptr));
        checkBoxTranslationsJW->setText(QCoreApplication::translate("MainWindow", "Javanese - jw", nullptr));
        checkBoxTranslationsBG->setText(QCoreApplication::translate("MainWindow", "Bulgarian - bg", nullptr));
        checkBoxTranslationsSR->setText(QCoreApplication::translate("MainWindow", "Serbian - sr", nullptr));
        checkBoxTranslationsTR->setText(QCoreApplication::translate("MainWindow", "Turkish - tr", nullptr));
        checkBoxTranslationsTA->setText(QCoreApplication::translate("MainWindow", "Tamil - ta", nullptr));
        checkBoxTranslationsMI->setText(QCoreApplication::translate("MainWindow", "Maori - mi", nullptr));
        checkBoxTranslationsHR->setText(QCoreApplication::translate("MainWindow", "Croatian - hr", nullptr));
        checkBoxTranslationsPS->setText(QCoreApplication::translate("MainWindow", "Pashto - ps", nullptr));
        checkBoxTranslationsHY->setText(QCoreApplication::translate("MainWindow", "Armenian - hy", nullptr));
        checkBoxTranslationsTN->setText(QCoreApplication::translate("MainWindow", "Tswana - tn", nullptr));
        checkBoxTranslationsKU->setText(QCoreApplication::translate("MainWindow", "Kurdish - ku", nullptr));
        checkBoxTranslationsHE->setText(QCoreApplication::translate("MainWindow", "Hebrew - he", nullptr));
        checkBoxTranslationsMT->setText(QCoreApplication::translate("MainWindow", "Maltese - mt", nullptr));
        checkBoxTranslationsIT->setText(QCoreApplication::translate("MainWindow", "Italian - it", nullptr));
        checkBoxTranslationsEU->setText(QCoreApplication::translate("MainWindow", "Basque - eu", nullptr));
        checkBoxTranslationsTG->setText(QCoreApplication::translate("MainWindow", "Tajik - tg", nullptr));
        checkBoxTranslationsAZ->setText(QCoreApplication::translate("MainWindow", "Azerbaijani - az", nullptr));
        checkBoxTranslationsTK->setText(QCoreApplication::translate("MainWindow", "Turkmen - tk", nullptr));
        checkBoxTranslationsHA->setText(QCoreApplication::translate("MainWindow", "Hausa - ha", nullptr));
        checkBoxTranslationsIS->setText(QCoreApplication::translate("MainWindow", "Icelandic - is", nullptr));
        checkBoxTranslationsYUE->setText(QCoreApplication::translate("MainWindow", "Cantonese - yue", nullptr));
        checkBoxTranslationsBE->setText(QCoreApplication::translate("MainWindow", "Belarusian - be", nullptr));
        checkBoxTranslationsMRJ->setText(QCoreApplication::translate("MainWindow", "HillMari - mrj", nullptr));
        checkBoxTranslationsKK->setText(QCoreApplication::translate("MainWindow", "Kazakh - kk", nullptr));
        checkBoxTranslationsRM->setText(QCoreApplication::translate("MainWindow", "Rhaeto-Romanic - rm ", nullptr));
        checkBoxTranslationsMK->setText(QCoreApplication::translate("MainWindow", "Macedonian - mk", nullptr));
        checkBoxTranslationsEO->setText(QCoreApplication::translate("MainWindow", "Esperanto - eo", nullptr));
        checkBoxTranslationsLT->setText(QCoreApplication::translate("MainWindow", "Lithuanian - lt", nullptr));
        checkBoxTranslationsOTQ->setText(QCoreApplication::translate("MainWindow", "Queretaro Otomi - otq", nullptr));
        checkBoxTranslationsSW->setText(QCoreApplication::translate("MainWindow", "Swahili - sw", nullptr));
        checkBoxTranslationsSU->setText(QCoreApplication::translate("MainWindow", "Sundanese - su", nullptr));
        checkBoxTranslationsSO->setText(QCoreApplication::translate("MainWindow", "Somali - so", nullptr));
        checkBoxTranslationsSI->setText(QCoreApplication::translate("MainWindow", "Sinhala - si", nullptr));
        checkBoxTranslationsSD->setText(QCoreApplication::translate("MainWindow", "Sindhi - sd", nullptr));
        checkBoxTranslationsES->setText(QCoreApplication::translate("MainWindow", "Spanish - es", nullptr));
        checkBoxTranslationsSB->setText(QCoreApplication::translate("MainWindow", "Sorbian - sb", nullptr));
        checkBoxTranslationsSV->setText(QCoreApplication::translate("MainWindow", "Swedish - sv", nullptr));
        checkBoxTranslationsSN->setText(QCoreApplication::translate("MainWindow", "Shona - sn", nullptr));
        checkBoxTranslationsSL->setText(QCoreApplication::translate("MainWindow", "Slovenian - sl", nullptr));
        checkBoxTranslationsSK->setText(QCoreApplication::translate("MainWindow", "Slovak - sk", nullptr));
        checkBoxTranslationsST->setText(QCoreApplication::translate("MainWindow", "Sesotho - st", nullptr));
        checkBoxTranslationsSR_LATIN->setText(QCoreApplication::translate("MainWindow", "Serbian Latin -sr-Latin", nullptr));
        checkBoxTranslationsUZ->setText(QCoreApplication::translate("MainWindow", "Uzbek - uz", nullptr));
        checkBoxTranslationsUR->setText(QCoreApplication::translate("MainWindow", "Urdu - ur", nullptr));
        checkBoxTranslationsUG->setText(QCoreApplication::translate("MainWindow", "Uighur - ug", nullptr));
        checkBoxTranslationsUK->setText(QCoreApplication::translate("MainWindow", "Ukrainian - uk", nullptr));
        checkBoxTranslationsUDM->setText(QCoreApplication::translate("MainWindow", "Udmurt - udm", nullptr));
        checkBoxTranslationsYUA->setText(QCoreApplication::translate("MainWindow", "Yucatec Maya - yua", nullptr));
        labelProjectName->setText(QCoreApplication::translate("MainWindow", "Project Name", nullptr));
        pushButtonTranslationsProjectBrowser->setText(QCoreApplication::translate("MainWindow", "Browse", nullptr));
        labelTranslationsOptions->setText(QCoreApplication::translate("MainWindow", "Options", nullptr));
        pushButtonTranslationsSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        pushButtonTranslationsClear->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        pushButtonTranslationsAdd->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        pushButtonTranslationsDelete->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabTranslations), QCoreApplication::translate("MainWindow", "Translations", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabProject), QCoreApplication::translate("MainWindow", "Project", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabHelp), QCoreApplication::translate("MainWindow", "Help", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
