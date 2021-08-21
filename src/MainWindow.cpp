/************************************************
* @file MainWindow.cpp
* @brief MainWindow.
* @author Jeffrey Scott Flesher <Jeffrey.Scott.Flesher@>
* @version 1.0
* @section LICENSE
* Unlicenced, Free, CopyLeft.
* @section DESCRIPTION
* Main Window of GUI
* @mainpage
* QtLingo is designed to parse TS files and Translate them using Computer Translations.
 ***********************************************/
#include "MainWindow.h"
/************************************************
 * @brief MainWindow Constructor.
 * MainWindow
 ***********************************************/
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    // App Icon
    QApplication::setWindowIcon(QIcon(":/images/logo32.png"));
    // Set up UI
    ui->setupUi(this);
    // Create table model:
    mySqlDb           = new MyDatatables(this);
    myLocalization    = new MyLocalization(this, mySqlDb->mySqlModel->mySetting);
    myTranlatorParser = new MyTranlatorParser(this, mySqlDb->mySqlModel->mySetting);
    // Read in Settings First
    readSettingsFirst();
    // Set to defaults
    myLocalization->setTransFilePrefix("QtLingo");          //!< Prefix of Translation files
    myLocalization->setTranslationSource("translations");   //!< Relative Folder for Translation files
    myLocalization->setHelpSource("help");                  //!< Relative Folder for Help files
    // SQL Database Types Do not Translate these
    ui->comboBoxSqlDatabaseType->addItem(":memory:");
    ui->comboBoxSqlDatabaseType->addItem("QSQLITE");
    ui->comboBoxSqlDatabaseType->addItem("QMYSQL");
    ui->comboBoxSqlDatabaseType->addItem("QPSQL");
    ui->comboBoxSqlDatabaseType->addItem("QDB2");
    ui->comboBoxSqlDatabaseType->addItem("QIBASE");
    ui->comboBoxSqlDatabaseType->addItem("QOCI");
    ui->comboBoxSqlDatabaseType->addItem("QTDS");
    // Hide Progress
    ui->progressBarProjectsTranslations->hide();
    ui->progressBarProjectsFiles->hide();
    // Connect actions
    connect(ui->actionExit,                 &QAction::triggered, this, &MainWindow::close);
    connect(ui->actionAbout,                &QAction::triggered, this, &MainWindow::onAbout);
    connect(ui->actionHelp,                 &QAction::triggered, this, &MainWindow::onHelp);
    connect(ui->actionAuthor,               &QAction::triggered, this, &MainWindow::onAuthor);
    connect(ui->actionClipboard,            &QAction::triggered, this, &MainWindow::onClipboard);
    connect(ui->actionCompile,              &QAction::triggered, this, &MainWindow::onCompile);
    connect(ui->actionSave,                 &QAction::triggered, this, &MainWindow::onSave);
    connect(ui->actionTranslate_Help,       &QAction::triggered, this, &MainWindow::onTranslateHelp);
    connect(ui->actionTranslate_ReadMe,     &QAction::triggered, this, &MainWindow::onTranslateReadMe);
    connect(ui->actionAccept_Translations,  &QAction::triggered, this, &MainWindow::acceptTranslations);
    // Progress bar
    connect(mySqlDb->mySqlModel->mySetting, &MyOrgSettings::sendInternetProgress, this, &MainWindow::onInternetProgress);
    // Set UI Language Code
    ui->labelSettingsLanguageUI->setText(myQOnlineTranslator.languageCode(myQOnlineTranslator.language(QLocale())));
    // Set Window Title to Application Name
    setWindowTitle(QApplication::applicationName());
    //
    setPrograms();
    // Do a one time Single Shot call to onRunFirstOnStartup to allow the GUI to load before calling what is in that call
    QTimer::singleShot(200, this, &MainWindow::onRunFirstOnStartup);
}
/************************************************
 * @brief MainWindow Deconstructor.
 * ~MainWindow
 ***********************************************/
MainWindow::~MainWindow()
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "~MainWindow"; }
    Q_CLEANUP_RESOURCE(QtLingo);
    delete ui;
}
/************************************************
 * @brief close Event.
 * closeEvent
 ***********************************************/
void MainWindow::closeEvent(QCloseEvent *event)
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "closeEvent"; }
    if (isSaveSettings) onSave();
    mySqlDb->mySqlModel->mySetting->setGeometry(pos(), size(), isMaximized(), isMinimized());
    writeAllSettings();
    QMainWindow::closeEvent(event);
    close();
} // end closeEvent
/************************************************
 * @brief change Event.
 * changeEvent
 ***********************************************/
void MainWindow::changeEvent(QEvent *event)
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "changeEvent"; }
    if (event ->type() == QEvent::LanguageChange && isMainLoaded)
    {
        // retranslate designer form (single inheritance approach)
        ui->retranslateUi(this);
        // retranslate other widgets which weren't added in designer
        retranslate();
    }
    // remember to call base class implementation
    QMainWindow::changeEvent(event);
}
/************************************************
 * @brief retranslate.
 * retranslate
 ***********************************************/
void MainWindow::onInternetProgress()
{
    ui->statusbar->showMessage(tr("Internet is down, trying to reconnect"));
}
/************************************************
 * @brief retranslate.
 * retranslate
 ***********************************************/
void MainWindow::retranslate()
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "retranslate"; }
    // FIXME
    loadLanguageComboBox();
    loadLanguageComboBoxSource();
}
/************************************************
 * @brief load Language ComboBox Source.
 * loadLanguageComboBoxSource
 ***********************************************/
void MainWindow::loadLanguageComboBoxSource()
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "loadLanguageComboBoxSource"; }
    //
    QMetaEnum e = QMetaEnum::fromType<QOnlineTranslator::Language>();
    bool lastIsMainLoaded = isMainLoaded;
    isMainLoaded = false;
    myLocalization->setMainLoaded(false);
    int theCurrentIndex = ui->comboBoxTranslationSourceLanguage->currentIndex();
    if (theCurrentIndex < 0)
    {
        theCurrentIndex = -1; // FIXME
    }
    ui->comboBoxTranslationSourceLanguage->clear();
    //
    QStandardItemModel *theLangModel = new QStandardItemModel(this);
    theLangModel->setColumnCount(2);
    for (int k = 0; k < e.keyCount(); k++)
    {
        QString theLanguageName = e.key(k);
        //QString theLanguageName = myQOnlineTranslator.languageNameToCode(e.key(k));
        QStandardItem* theCol0 = new QStandardItem(theLanguageName);
        QStandardItem* theCol1 = new QStandardItem(tr(theLanguageName.toLocal8Bit()));
        theLangModel->setItem(k, 0, theCol0);
        theLangModel->setItem(k, 1, theCol1);
    } // end for
    QTableView* tableView = new QTableView(this);
    tableView->setModel(theLangModel);
    tableView->verticalHeader()->setVisible(false);
    tableView->horizontalHeader()->setVisible(false);
    tableView->setColumnWidth (0, 196);
    tableView->setColumnWidth (1, 196);
    tableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableView->setAutoScroll(false);
    // Set comboBox
    ui->comboBoxTranslationSourceLanguage->setMinimumWidth(400);
    ui->comboBoxTranslationSourceLanguage->setModel(theLangModel);
    ui->comboBoxTranslationSourceLanguage->setView(tableView);
    if (theCurrentIndex == -1)
    { ui->comboBoxTranslationSourceLanguage->setCurrentIndex(ui->comboBoxTranslationSourceLanguage->findText(mySourceLanguage)); }
    else
    { ui->comboBoxTranslationSourceLanguage->setCurrentIndex(theCurrentIndex); }
    setLanguageCode();
    isMainLoaded = lastIsMainLoaded;
    myLocalization->setMainLoaded(lastIsMainLoaded);
}
/************************************************
 * @brief set Language Code.
 * setLanguageCode
 ***********************************************/
void MainWindow::setLanguageCode()
{
    ui->labelTranslationsSourceLanguageCode->setText(myLocalization->languageNameToCode(ui->comboBoxTranslationSourceLanguage->currentText()));
}
/************************************************
 * @brief load Language ComboBox.
 * loadLanguageComboBox
 ***********************************************/
void MainWindow::loadLanguageComboBox()
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "loadLanguageComboBox"; }
    bool lastIsMainLoaded = isMainLoaded;
    myLocalization->setMainLoaded(false);
    isMainLoaded = false;
    int theCurrentIndex = ui->comboBoxSettingsLanguage->currentIndex();
    if (theCurrentIndex < 0) { theCurrentIndex = myLanguageCombBoxIndex; } // FIXME never set
    ui->comboBoxSettingsLanguage->clear();
    const QStringList theQmFiles =  myLocalization->findQmFiles(myLocalization->getTranslationSource());
    QStandardItemModel *theLangModel = new QStandardItemModel(this);
    theLangModel->setColumnCount(2);
    for (int i = 0; i < theQmFiles.size(); ++i)
    {
        QString theLanguageName = myLocalization->getLanguageFromFile(myLocalization->getTransFilePrefix(), theQmFiles.at(i));
        QStandardItem* theCol0 = new QStandardItem(theLanguageName);
        QStandardItem* theCol1 = new QStandardItem(tr(theLanguageName.toLocal8Bit()));
        theLangModel->setItem(i, 0, theCol0);
        theLangModel->setItem(i, 1, theCol1);
    } // end for
    QTableView* theTableView = new QTableView(this);
    theTableView->setModel(theLangModel);
    theTableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    theTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    theTableView->setAutoScroll(false);
    theTableView->verticalHeader()->setVisible(false);
    theTableView->horizontalHeader()->setVisible(false);
    theTableView->setColumnWidth (0, 196);
    theTableView->setColumnWidth (1, 196);
    // Set comboBox
    ui->comboBoxSettingsLanguage->setMinimumWidth(400);
    ui->comboBoxSettingsLanguage->setModel(theLangModel);
    ui->comboBoxSettingsLanguage->setView(theTableView);
    ui->comboBoxSettingsLanguage->setCurrentIndex(theCurrentIndex);
    isMainLoaded = lastIsMainLoaded;
    myLocalization->setMainLoaded(lastIsMainLoaded);
}
/************************************************
 * @brief set Project Combo.
 * setProjectCombo
 ***********************************************/
void MainWindow::setQtProjectCombo()
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "setQtProjectCombo"; }
    bool lastIsMainLoaded = isMainLoaded;
    isMainLoaded = false;
    myLocalization->setMainLoaded(false);
    ui->comboBoxSettingsProjects->clear();
    QSqlQueryModel *theModalQtLingo = new QSqlQueryModel(this); //!< SQL Query Model
    //  SELECT id, QtProjectName FROM Projects
    const auto SELECTED_PROJECTS_SQL = QLatin1String(R"(%1)").arg(mySqlDb->getQtProjectNameSelectQuery());
    theModalQtLingo->setQuery(SELECTED_PROJECTS_SQL);
    if (theModalQtLingo->lastError().isValid()) { qWarning() << theModalQtLingo->lastError(); }
    theModalQtLingo->setHeaderData(0,Qt::Horizontal, tr("ID"));
    theModalQtLingo->setHeaderData(1, Qt::Horizontal, tr("Project"));
    QTableView *theTableView = new QTableView;
    theTableView->setModel(theModalQtLingo);
    theTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    theTableView->setSelectionMode(QAbstractItemView::SingleSelection);
    theTableView->verticalHeader()->setVisible(false);
    theTableView->horizontalHeader()->setVisible(false);
    theTableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    theTableView->setAutoScroll(false);
    //theTableView->setColumnHidden(0, true);
    theTableView->setColumnWidth (1, 296);
    //ui->comboBoxSettingsProjects->setModel(nullptr);
    ui->comboBoxSettingsProjects->setModel(theModalQtLingo);
    ui->comboBoxSettingsProjects->setView(theTableView);
    ui->comboBoxSettingsProjects->setMinimumWidth(300);
    ui->comboBoxSettingsProjects->setModelColumn(1);
    ui->comboBoxSettingsProjects->setCurrentIndex(0);
    // Set by Project name or Index
    QString theProjectName = mySqlDb->getProjectName();
    ui->comboBoxSettingsProjects->setCurrentIndex(ui->comboBoxSettingsProjects->findText(theProjectName));
    // int theProjectIndex = mySqlDb->getProjectID().toInt();
    //  ui->comboBoxSettingsProjects->setCurrentIndex(theProjectIndex);
    isMainLoaded = lastIsMainLoaded;
    myLocalization->setMainLoaded(lastIsMainLoaded);
}
/************************************************
 * @brief on Run First On Startup.
 * onRunFirstOnStartup
 ***********************************************/
void MainWindow::onRunFirstOnStartup()
{
    isMainLoaded = false;
    myLocalization->setMainLoaded(false);
    clearForms(TabAll);
    // Go to Tab
    ui->tabWidget->setCurrentIndex(ui->tabWidget->indexOf(ui->tabWidget->findChild<QWidget*>("tabSettings")));
    // Read Settings
    readAllSettings();
    // Read Saved Language
    myLocalization->readLanguage();
    // Get Language File
    QString theQmLanguageFile = myLocalization->getLanguageFile(myLocalization->getLanguageCode(), myLocalization->getTranslationSource(), myLocalization->getTransFilePrefix());
    // Load Language
    myLocalization->loadLanguage(theQmLanguageFile);
    QString theLastLanguage = myLocalization->getLanguageFromFile(myLocalization->getTransFilePrefix(), theQmLanguageFile);
    loadLanguageComboBox();
    ui->comboBoxSettingsLanguage->setCurrentIndex(ui->comboBoxSettingsLanguage->findText(theLastLanguage));
    //
    if (isDebugMessage && isMainLoaded) { qDebug() << "onRunFirstOnStartup"; }
    //
    if (!mySqlDb->checkDatabase()) close();
    setQtProjectCombo();
    //
    fillForms(mySqlDb->getProjectID());
    loadLanguageComboBoxSource();
    //
    setSqlBrowseButton();
    //
    isMainLoaded = true;
    myLocalization->setMainLoaded(true);
}
/************************************************
 * @brief read Settings First.
 * readSettingsFirst
 ***********************************************/
void MainWindow::readSettingsFirst()
{
    isDebugMessage = mySqlDb->mySqlModel->mySetting->readSettingsBool(mySqlDb->mySqlModel->mySetting->myConstants->MY_IS_DEBUG_MESSAGE, isDebugMessage);
    if (isDebugMessage)
        { ui->checkBoxSettignsMessaging->setCheckState(Qt::CheckState::Checked); }
    else
        { ui->checkBoxSettignsMessaging->setCheckState(Qt::CheckState::Unchecked); }
    setMessagingStates(isDebugMessage);
}
/************************************************
 * @brief read Settings.
 * readAllSettings
 ***********************************************/
void MainWindow::readAllSettings()
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "readAllSettings"; }
    //resize(myMySettings->getGeometrySize());
    //move(myMySettings->getGeometryPos());
    //
    //if(myMySettings->getGeometryMax()) setWindowState(windowState() | Qt::WindowMaximized);
    //if(myMySettings->getGeometryMin()) setWindowState(windowState() | Qt::WindowMinimized);
    //
    //
    readStatesChanges();
    readSqlDatabaseInfo();
}
/************************************************
 * @brief Write All Settings.
 * writeAllSettings
 ***********************************************/
void MainWindow::writeAllSettings()
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "writeAllSettings"; }
    mySqlDb->mySqlModel->mySetting->writeSettings(mySqlDb->mySqlModel->mySetting->myConstants->MY_IS_DEBUG_MESSAGE, isDebugMessage ? "true" : "false");
    //
    writeStateChanges();
    writeSqlDatabaseInfo();
}
/************************************************
 * @brief read SQL Database States.
 * readSqlDatabaseStates
 ***********************************************/
void MainWindow::readStatesChanges()
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "readStatesChanges"; }
    // SQL Memory option Chech
    // default set to myProjectID="-1"
    QString theProjectID = mySqlDb->mySqlModel->mySetting->readSettings(mySqlDb->mySqlModel->mySetting->myConstants->MY_SQL_PROJECT_ID, mySqlDb->getProjectID());
    // We cannot read from the database yet, we are only getting the last states we know of
    if (theProjectID != "-1") { mySqlDb->setProjectID(theProjectID); } else { mySqlDb->setProjectID("1"); }
    mySqlDb->setProjectName(mySqlDb->mySqlModel->mySetting->readSettings(mySqlDb->mySqlModel->mySetting->myConstants->MY_SQL_PROJECT_NAME, mySqlDb->getProjectName()));
    // Project ID
    ui->labelRecordIdSettings->setText(mySqlDb->getProjectID());
    // Trans Engine
    // Google
    ui->checkBoxSettingsGoogle->setCheckState((mySqlDb->mySqlModel->mySetting->readSettings(mySqlDb->mySqlModel->mySetting->myConstants->MY_TRANS_ENGINE_GOOGLE_VALUE, "true")) == "true" ? Qt::CheckState::Checked : Qt::CheckState::Unchecked);
    // Bing
    ui->checkBoxSettingsBing->setCheckState((mySqlDb->mySqlModel->mySetting->readSettings(mySqlDb->mySqlModel->mySetting->myConstants->MY_TRANS_ENGINE_BING_VALUE, "true")) == "true" ? Qt::CheckState::Checked : Qt::CheckState::Unchecked);
    // Yandex
    ui->checkBoxSettingsYandex->setCheckState((mySqlDb->mySqlModel->mySetting->readSettings(mySqlDb->mySqlModel->mySetting->myConstants->MY_TRANS_ENGINE_YANDEX_VALUE, "true")) == "true" ? Qt::CheckState::Checked : Qt::CheckState::Unchecked);
    // Delay
    ui->spinBoxSettingsDelay->setValue(mySqlDb->mySqlModel->mySetting->readSettingsInt(mySqlDb->mySqlModel->mySetting->myConstants->MY_TRANS_DELAY_VALUE, mySqlDb->mySqlModel->mySetting->myConstants->MY_TRANS_DELAY));
}
/************************************************
 * @brief write States Changes.
 * writeStateChanges
 ***********************************************/
void MainWindow::writeStateChanges()
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "writeStateChanges"; }
    // Project ID
    mySqlDb->mySqlModel->mySetting->writeSettings(mySqlDb->mySqlModel->mySetting->myConstants->MY_SQL_PROJECT_ID, ui->labelRecordIdSettings->text());
    mySqlDb->mySqlModel->mySetting->writeSettings(mySqlDb->mySqlModel->mySetting->myConstants->MY_SQL_PROJECT_NAME, ui->comboBoxSettingsProjects->currentText());
    // Trans Engines
    // Google
    mySqlDb->mySqlModel->mySetting->writeSettings(mySqlDb->mySqlModel->mySetting->myConstants->MY_TRANS_ENGINE_GOOGLE_VALUE, (ui->checkBoxSettingsGoogle->isChecked()) ? "true" : "false" );
    // Bing
    mySqlDb->mySqlModel->mySetting->writeSettings(mySqlDb->mySqlModel->mySetting->myConstants->MY_TRANS_ENGINE_BING_VALUE, (ui->checkBoxSettingsBing->isChecked()) ? "true" : "false" );
    // Yandex
    mySqlDb->mySqlModel->mySetting->writeSettings(mySqlDb->mySqlModel->mySetting->myConstants->MY_TRANS_ENGINE_YANDEX_VALUE, (ui->checkBoxSettingsYandex->isChecked()) ? "true" : "false" );
    // Language
    mySqlDb->mySqlModel->mySetting->writeSettings(mySqlDb->mySqlModel->mySetting->myConstants->MY_LANGUAGE_COMBO_STATE, QString::number(ui->comboBoxSettingsLanguage->currentIndex()));
    // Delay
    mySqlDb->mySqlModel->mySetting->writeSettings(mySqlDb->mySqlModel->mySetting->myConstants->MY_TRANS_DELAY_VALUE, ui->spinBoxSettingsDelay->text());
    // Language ComboBox
    myLocalization->setLanguageCode(myLocalization->languageNameToCode(ui->comboBoxSettingsLanguage->currentText()));
    myLocalization->writeLanguage(myLocalization->getLanguageCode());
}
/************************************************
 * @brief write SQL Database Info Uses SimpleCrypt to encrypt and decrypt Password.
 * writeSqlDatabaseInfo
 ***********************************************/
void MainWindow::writeSqlDatabaseInfo()
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "writeSqlDatabaseInfo"; }
    // SQL Database Type Index
    mySqlDb->mySqlModel->mySetting->writeSettings(mySqlDb->mySqlModel->mySetting->myConstants->MY_SQL_COMBO_STATE, QString::number(ui->comboBoxSqlDatabaseType->currentIndex()));
    // SQL Database Type Value
    mySqlDb->mySqlModel->mySetting->writeSettings(mySqlDb->mySqlModel->mySetting->myConstants->MY_SQL_DB_TYPE, ui->comboBoxSqlDatabaseType->currentText());
    // SQL Database Name
    mySqlDb->mySqlModel->mySetting->writeSettings(mySqlDb->mySqlModel->mySetting->myConstants->MY_SQL_DB_NAME,  ui->lineEditSqlDatabaseName->text());
    // SQL Database Type Host
    mySqlDb->mySqlModel->mySetting->writeSettings(mySqlDb->mySqlModel->mySetting->myConstants->MY_SQL_DB_HOST,  ui->lineEditSqlHostName->text());
    // SQL Database Type User
    mySqlDb->mySqlModel->mySetting->writeSettings(mySqlDb->mySqlModel->mySetting->myConstants->MY_SQL_DB_USER,  ui->lineEditSqlUserName->text());
    // SQL Encrypted Password, it is saved in Ini file
    if (!ui->lineEditSqlPassword->text().isEmpty())
        { mySqlDb->mySqlModel->mySetting->writeSettings(mySqlDb->mySqlModel->mySetting->myConstants->MY_SQL_DB_PASS, mySqlDb->mySqlModel->mySetting->encryptThis(ui->lineEditSqlPassword->text())); }
}
/************************************************
 * @brief read SQL Database Info Uses SimpleCrypt to encrypt and decrypt Password.
 * readSqlDatabaseInfo
 ***********************************************/
void MainWindow::readSqlDatabaseInfo()
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "readSqlDatabaseInfo"; }
    QString theDb = QString("%1%2%3.db").arg(mySqlDb->mySqlModel->mySetting->getAppDataLocation(), QDir::separator(), mySqlDb->mySqlModel->getSqlDatabaseName());
    // SQL Database Name
    ui->lineEditSqlDatabaseName->setText(mySqlDb->mySqlModel->mySetting->readSettings(mySqlDb->mySqlModel->mySetting->myConstants->MY_SQL_DB_NAME, theDb));
    // Set ComboBox for SQL
    ui->comboBoxSqlDatabaseType->setCurrentIndex(mySqlDb->mySqlModel->mySetting->readSettingsInt(mySqlDb->mySqlModel->mySetting->myConstants->MY_SQL_COMBO_STATE, 1));
    // SQL Type Value
    mySqlDb->setComboBoxSqlValue(mySqlDb->mySqlModel->mySetting->readSettings(mySqlDb->mySqlModel->mySetting->myConstants->MY_SQL_DB_TYPE, mySqlDb->mySqlModel->mySetting->myConstants->MY_SQL_DEFAULT));
    // SQL Host
    ui->lineEditSqlHostName->setText(mySqlDb->mySqlModel->mySetting->readSettings(mySqlDb->mySqlModel->mySetting->myConstants->MY_SQL_DB_HOST, "")); // No Default
    // SQL User
    ui->lineEditSqlUserName->setText(mySqlDb->mySqlModel->mySetting->readSettings(mySqlDb->mySqlModel->mySetting->myConstants->MY_SQL_DB_USER, "")); // No Default
    // SQL Decrypt Password, it is saved in Ini file
    QString thePassword = mySqlDb->mySqlModel->mySetting->decryptThis(mySqlDb->mySqlModel->mySetting->readSettings(mySqlDb->mySqlModel->mySetting->myConstants->MY_SQL_DB_PASS, ""));
    if (!thePassword.isEmpty())
        { ui->lineEditSqlPassword->setText(thePassword); }
    else
        { ui->lineEditSqlPassword->setText(""); }
}
/************************************************
 * @brief on Author.
 * onAuthor
 ***********************************************/
void MainWindow::onAuthor()
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "onAuthor"; }
    // Go to Tab
    ui->tabWidget->setCurrentIndex(ui->tabWidget->indexOf(ui->tabWidget->findChild<QWidget*>("tabHelp")));
    //
    QString theFileName = QString(":help/About-Author_%1.md").arg(myLocalization->getLanguageCode());
    if (!mySqlDb->mySqlModel->mySetting->isFileExists(theFileName))
        { theFileName = QString(":help/About-Author_%1.md").arg(mySqlDb->mySqlModel->mySetting->myConstants->MY_DEFAULT_LANGUAGE_CODE); }
    ui->textEditHelp->setMarkdown(mySqlDb->mySqlModel->mySetting->readFile(theFileName));
}
/************************************************
 * @brief Main Window Destructor.
 * onAbout
 ***********************************************/
void MainWindow::onAbout()
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "onAbout"; }
    // Go to Tab
    ui->tabWidget->setCurrentIndex(ui->tabWidget->indexOf(ui->tabWidget->findChild<QWidget*>("tabHelp")));
    //
    QString theFileName = QString(":help/About_%1.md").arg(myLocalization->getLanguageCode());
    if (!mySqlDb->mySqlModel->mySetting->isFileExists(theFileName))
        { theFileName = QString(":help/About_%1.md").arg(mySqlDb->mySqlModel->mySetting->myConstants->MY_DEFAULT_LANGUAGE_CODE); }
    ui->textEditHelp->setMarkdown(mySqlDb->mySqlModel->mySetting->readFile(theFileName));
}
/************************************************
 * @brief Help.
 * onHelp
 ***********************************************/
void MainWindow::onHelp()
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "onHelp"; }
    // Go to Tab
    ui->tabWidget->setCurrentIndex(ui->tabWidget->indexOf(ui->tabWidget->findChild<QWidget*>("tabHelp")));
    //
    QString theFileName = QString(":help/Help_%1.md").arg(myLocalization->getLanguageCode());
    if (!mySqlDb->mySqlModel->mySetting->isFileExists(theFileName))
        { theFileName = QString(":help/Help_%1.md").arg(mySqlDb->mySqlModel->mySetting->myConstants->MY_DEFAULT_LANGUAGE_CODE); }
    QString theFileContent = mySqlDb->mySqlModel->mySetting->readFile(theFileName);
    // Do not translate this file
    QString theLanguageFileName = QString(":help/Language.txt").arg(myLocalization->getLanguageCode());
    if (mySqlDb->mySqlModel->mySetting->isFileExists(theLanguageFileName))
    {
        theFileContent.append(mySqlDb->mySqlModel->mySetting->readFile(theLanguageFileName));
    }
    ui->textEditHelp->setMarkdown(theFileContent);
}
/************************************************
 * @brief on pushButton Translations Source Browse clicked.
 * on_pushButtonTranslationsSourceBrowse_clicked
 ***********************************************/
void MainWindow::on_pushButtonTranslationsSourceBrowse_clicked()
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "on_pushButtonTranslationsSourceBrowse_clicked"; }
    QFileDialog dialogTranslationFolder;
    dialogTranslationFolder.setFileMode(QFileDialog::Directory);
    dialogTranslationFolder.setOption(QFileDialog::ShowDirsOnly);
    dialogTranslationFolder.setOption(QFileDialog::DontResolveSymlinks);
    //
    QString theTranslationFolder = dialogTranslationFolder.getExistingDirectory(this, tr("Translation Source Folder Location"), mySqlDb->mySqlModel->mySetting->myConstants->MY_TRANSLATION_FOLDER);
    //QString theTranslationFolder = dialogTranslationFolder.getExistingDirectory(this, tr("Translation Source Folder Location"), mySqlDb->mySqlModel->mySetting->getQtProjectPath());
    if (!theTranslationFolder.isEmpty())
        { ui->lineEditTranslationsSource->setText(theTranslationFolder); }
}
/************************************************
 * @brief on pushButton Translations Destination Browse clicked.
 * on_pushButtonTranslationsDestinationBrowse_clicked
 ***********************************************/
void MainWindow::on_pushButtonTranslationsDestinationBrowse_clicked()
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "on_pushButtonTranslationsDestinationBrowse_clicked"; }
    QFileDialog dialogTranslationFolder;
    dialogTranslationFolder.setFileMode(QFileDialog::Directory);
    dialogTranslationFolder.setOption(QFileDialog::ShowDirsOnly);
    dialogTranslationFolder.setOption(QFileDialog::DontResolveSymlinks);
    //
    QString theTranslationFolder = dialogTranslationFolder.getExistingDirectory(this, tr("Translation Destination Folder Location"), mySqlDb->mySqlModel->mySetting->getLastApplicationPath());
    if (!theTranslationFolder.isEmpty())
        { ui->lineEditTranslationsDestination->setText(theTranslationFolder); }
}
/************************************************
 * @brief on pushButton Settings Projects Browser clicked.
 * on_pushButtonSettingsProjectsBrowser_clicked
 ***********************************************/
void MainWindow::on_pushButtonSettingsProjectsBrowser_clicked()
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "on_pushButtonSettingsProjectsBrowser_clicked"; }
    QFileDialog dialogTranslationFolder;
    dialogTranslationFolder.setFileMode(QFileDialog::Directory);
    dialogTranslationFolder.setOption(QFileDialog::ShowDirsOnly);
    dialogTranslationFolder.setOption(QFileDialog::DontResolveSymlinks);
    //
    QString theTranslationFolder = dialogTranslationFolder.getExistingDirectory(this, tr("Projects Folder Location"), mySqlDb->mySqlModel->mySetting->getLastApplicationPath());
    if (!theTranslationFolder.isEmpty())
        { ui->lineEditSettingsQtProjectName->setText(theTranslationFolder); }
}
/************************************************
 * @brief on pushButton Translations Project Folder Browse clicked.
 * on_pushButtonTranslationsProjectFolderBrowse_clicked
 ***********************************************/
void MainWindow::on_pushButtonTranslationsProjectFolderBrowse_clicked()
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "on_pushButtonTranslationsProjectFolderBrowse_clicked"; }
    QFileDialog dialogTranslationFolder;
    dialogTranslationFolder.setFileMode(QFileDialog::Directory);
    dialogTranslationFolder.setOption(QFileDialog::ShowDirsOnly);
    dialogTranslationFolder.setOption(QFileDialog::DontResolveSymlinks);
    //
    QString theTranslationFolder = dialogTranslationFolder.getExistingDirectory(this, tr("Projects Folder Location"), mySqlDb->mySqlModel->mySetting->getLastApplicationPath());
    if (!theTranslationFolder.isEmpty())
        { ui->lineEditTranslationsProjectFolder->setText(theTranslationFolder); }
}
/************************************************
 * @brief on comboBox Settings Language current Index Changed.
 * on_comboBoxSettingsLanguage_currentIndexChanged
 ***********************************************/
void MainWindow::on_comboBoxSettingsLanguage_currentIndexChanged(const QString &thisLanguage)
{
    if (!isMainLoaded) { return; }
    if (isDebugMessage && isMainLoaded) { qDebug() << "on_comboBoxSettingsLanguage_currentIndexChanged"; }
    myLocalization->writeLanguage(myLocalization->languageNameToCode(thisLanguage));
    myLocalization->loadLanguage(myLocalization->getLanguageFile(myLocalization->languageNameToCode(thisLanguage), myLocalization->getTranslationSource(), myLocalization->getTransFilePrefix()));
}
/************************************************
 * @brief on checkBox Settings Google state Changed.
 * on_checkBoxSettingsGoogle_stateChanged
 ***********************************************/
void MainWindow::on_checkBoxSettingsGoogle_stateChanged(int thisArg)
{
    Q_UNUSED(thisArg)
    if (!isMainLoaded) { return; }
    if (isDebugMessage && isMainLoaded) { qDebug() << "on_checkBoxSettingsGoogle_stateChanged"; }
    writeStateChanges();
}
/************************************************
 * @brief on checkBox Settings Bing state Changed.
 * on_checkBoxSettingsBing_stateChanged
 ***********************************************/
void MainWindow::on_checkBoxSettingsBing_stateChanged(int thisArg)
{
    Q_UNUSED(thisArg)
    if (!isMainLoaded) { return; }
    if (isDebugMessage && isMainLoaded) { qDebug() << "on_checkBoxSettingsBing_stateChanged"; }
    writeStateChanges();
}
/************************************************
 * on_checkBoxSettingsYandex_stateChanged
 * @brief on checkBox Settings Yandex state Changed.
 ***********************************************/
void MainWindow::on_checkBoxSettingsYandex_stateChanged(int thisArg)
{
    Q_UNUSED(thisArg)
    if (!isMainLoaded) { return; }
    if (isDebugMessage && isMainLoaded) { qDebug() << "on_checkBoxSettingsYandex_stateChanged"; }
    writeStateChanges();
}
/************************************************
 * @brief SQL Database Name Browse clicked.
 * on_pushButtonSqlDatabaseNameBrowse_clicked
 ***********************************************/
void MainWindow::on_pushButtonSqlDatabaseNameBrowse_clicked()
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "on_pushButtonSqlDatabaseNameBrowse_clicked"; }
    QFileDialog dialogSqlDbFolder;
    dialogSqlDbFolder.setFileMode(QFileDialog::Directory);
    dialogSqlDbFolder.setOption(QFileDialog::ShowDirsOnly);
    dialogSqlDbFolder.setOption(QFileDialog::DontResolveSymlinks);
    //
    QString theSqlFolder = dialogSqlDbFolder.getExistingDirectory(this, tr("Sqlite Folder Location"), mySqlDb->mySqlModel->mySetting->getAppDataLocation());
    if (!theSqlFolder.isEmpty())
    {
        QString theDbLocation = ui->lineEditSqlDatabaseName->text();
        QString theDbNewLocation = QString("%1/%2.db").arg(theSqlFolder, mySqlDb->mySqlModel->getSqlDatabaseName());
        if (theDbLocation != theDbNewLocation)
        {
            //
            if (mySqlDb->mySqlModel->mySetting->getFileInfo(MyOrgSettings::IsFile, ui->lineEditSqlDatabaseName->text()) == "true")
            {
                QString thePath = mySqlDb->mySqlModel->mySetting->getFileInfo(MyOrgSettings::CanonicalFilePath, ui->lineEditSqlDatabaseName->text());
                // moveDb
                if (mySqlDb->mySqlModel->moveDb(theDbNewLocation, thePath, theDbNewLocation))
                { ui->lineEditSqlDatabaseName->setText(theDbNewLocation); }
                else
                { mySqlDb->mySqlModel->mySetting->showMessageBox(QObject::tr("Database Move Failed").toLocal8Bit(), QString("%1: %2").arg(tr("Failed to move Database"), ui->lineEditSqlDatabaseName->text()).toLocal8Bit(), mySqlDb->mySqlModel->mySetting->Critical); }
            }
        }
    }
}
/************************************************
 * @brief on comboBox Settings Projects current Index Changed.
 * on_comboBoxSettingsProjects_currentIndexChanged
 ***********************************************/
void MainWindow::on_comboBoxSettingsProjects_currentIndexChanged(int thisIndex)
{
    Q_UNUSED(thisIndex) // not the same as theIndex
    if (!isMainLoaded) { return; }
    QString theIndex = ui->comboBoxSettingsProjects->model()->data(ui->comboBoxSettingsProjects->model()->index(ui->comboBoxSettingsProjects->currentIndex(), 0)).toString();
    if (isDebugMessage) { qDebug() << "on_comboBoxSettingsProjects_currentIndexChanged = " << thisIndex << " and thisIndex = " << theIndex; }
    fillForms(theIndex);
}
/************************************************
 * @brief on pushButton SQL Password Show clicked.
 * on_pushButtonSqlPasswordShow_clicked
 ***********************************************/
void MainWindow::on_pushButtonSqlPasswordShow_clicked()
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "on_pushButtonSqlPasswordShow_clicked"; }
    mySqlDb->mySqlModel->mySetting->showMessageBox(QObject::tr("Password Revieled").toLocal8Bit(), ui->lineEditSqlPassword->text().toLocal8Bit(), mySqlDb->mySqlModel->mySetting->Information);
}
/************************************************
 * on_pushButtonSqlSave_clicked
 * @brief on pushButton SQL Save clicked.
 ***********************************************/
void MainWindow::on_pushButtonSqlSave_clicked()
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "on_pushButtonSqlSave_clicked"; }
    writeStateChanges();
}
/************************************************
 * @brief on pushButton Settings Save clicked.
 * onSave
 ***********************************************/
void MainWindow::onSave()
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "onSave"; }
    setProjectClass(TabAll);
    mySqlDb->saveQtProject();
}
/************************************************
 * on_pushButtonSettingsSave_clicked
 * @brief on pushButton Settings Save clicked.
 ***********************************************/
void MainWindow::on_pushButtonSettingsSave_clicked()
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "on_pushButtonSettingsSave_clicked"; }
    onSave();
}
/************************************************
 * @brief on pushButton Settings Add clicked.
 * on_pushButtonSettingsAdd_clicked
 ***********************************************/
void MainWindow::on_pushButtonSettingsAdd_clicked()
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "on_pushButtonSettingsAdd_clicked"; }
    setProjectClass(TabAll);
    mySqlDb->addQtProject();
    setQtProjectCombo();
}
/************************************************
 * on_pushButtonSettingsDelete_clicked
 * @brief on pushButton Settings Delete clicked.
 ***********************************************/
void MainWindow::on_pushButtonSettingsDelete_clicked()
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "on_pushButtonSettingsDelete_clicked"; }
    setProjectClass(TabAll);
    mySqlDb->deleteQtProject(ui->labelRecordIdSettings->text());
}
/************************************************
 * @brief set Programs.
 * setPrograms
 ***********************************************/
void MainWindow::setPrograms()
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "setPrograms"; }
    QString theLupdatePath  = "/usr/bin/lupdate";
    QString theLreleasePath = "/usr/bin/lrelease";

//    #if Q_OS_MSDOS || defined(Q_OS_WIN32) || defined(Q_OS_WINCE)
//    // FIXME Qt Folder have not tested this code
//    QString theQtEnv;
//    theLupdatePath = mySqlDb->mySqlModel->runProcces("where", "lupdate.exe", true, 60);
//    if (theLupdatePath.isEmpty())
//    {
//        theQtEnv = mySqlDb->mySqlModel->mySetting->getEnvironmentVar("Qt");
//        if (theQtEnv.isEmpty())
//        {
//            theLupdatePath = QString("%1/lupdate.exe").arg(theQtEnv);
//        }
//        else
//        {
//            theLupdatePath = "c:/Qt/lupdate.exe";
//        }
//    }
//    theLreleasePath = mySqlDb->mySqlModel->runProcces("where", "lrelease.exe", true, 60);
//    if (theLreleasePath.isEmpty())
//    {
//        theQtEnv = mySqlDb->mySqlModel->mySetting->getEnvironmentVar("Qt");
//        if (theQtEnv.isEmpty())
//        {
//            theLreleasePath = QString("%1/lrelease.exe").arg(theQtEnv);
//        }
//        else
//        {
//            theLreleasePath = "c:/Qt/lrelease.exe";
//        }
//    }
//    ui->lineEditSettingsLupdate->setText(theLupdatePath);
//    ui->lineEditSettingsLrelease->setText(theLreleasePath);
//    #else
    if (!mySqlDb->mySqlModel->mySetting->isFileExists(theLupdatePath))
    {
        theLupdatePath = mySqlDb->mySqlModel->runProcces("which", "lupdate", true, 60);
        if (theLupdatePath.isEmpty())
        { theLupdatePath = mySqlDb->mySqlModel->runProcces("type -P", "lupdate", true, 60); }
    }
    if (!mySqlDb->mySqlModel->mySetting->isFileExists(theLreleasePath))
    {
        theLreleasePath = mySqlDb->mySqlModel->runProcces("which", "lrelease", true, 60);
        if (theLreleasePath.isEmpty())
        { theLreleasePath = mySqlDb->mySqlModel->runProcces("type -P", "lrelease", true, 60); }
    }
//    #endif
    ui->lineEditSettingsLupdate->setText(theLupdatePath);
    ui->lineEditSettingsLrelease->setText(theLreleasePath);
}
/************************************************
 * @brief set SQL Browse Button.
 * setSqlBrowseButton
 ***********************************************/
void MainWindow::setSqlBrowseButton()
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "settingsButtons"; }
    ui->pushButtonSqlDatabaseNameBrowse->setEnabled(ui->comboBoxSqlDatabaseType->currentText() == mySqlDb->mySqlModel->mySetting->myConstants->MY_SQL_DEFAULT || ui->comboBoxSqlDatabaseType->currentText() == ":memory:");
}
/************************************************
 * @brief on comboBox SQL Database Type current Index Changed.
 * on_comboBoxSqlDatabaseType_currentIndexChanged
 ***********************************************/
void MainWindow::on_comboBoxSqlDatabaseType_currentIndexChanged(const QString &thisSqlType)
{
    if (!isMainLoaded) { return; }
    if (isDebugMessage) { qDebug() << "on_comboBoxSqlDatabaseType_currentIndexChanged=" << thisSqlType; }
    mySqlDb->mySqlModel->setSqlDriver(thisSqlType);
    writeStateChanges();
    setSqlBrowseButton();
}
/************************************************
 * @brief language Checked.
 * languageChecked
 ***********************************************/
QString MainWindow::languageChecked()
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "languageChecked"; }
    myLanguages = "";
    checkLanguage("Amharic",        "am" , ui->checkBoxTranslationsAM->isChecked());
    checkLanguage("Afrikaans",      "af" , ui->checkBoxTranslationsAF->isChecked());
    checkLanguage("Albanian",       "sq" , ui->checkBoxTranslationsSQ->isChecked());
    checkLanguage("Arabic",         "ar" , ui->checkBoxTranslationsAR->isChecked());
    checkLanguage("Armenian",       "hy" , ui->checkBoxTranslationsHY->isChecked());
    checkLanguage("Azerbaijani",    "az" , ui->checkBoxTranslationsAZ->isChecked());
    checkLanguage("Basque",         "eu" , ui->checkBoxTranslationsEU->isChecked());
    checkLanguage("Bashkir",        "ba" , ui->checkBoxTranslationsBA->isChecked());
    checkLanguage("Belarusian",     "be" , ui->checkBoxTranslationsBE->isChecked());
    checkLanguage("Bengali",        "bn" , ui->checkBoxTranslationsBN->isChecked());
    checkLanguage("Bosnian",        "bs" , ui->checkBoxTranslationsBS->isChecked());
    checkLanguage("Bulgarian",      "bg" , ui->checkBoxTranslationsBG->isChecked());
    checkLanguage("Catalan",        "ca" , ui->checkBoxTranslationsCA->isChecked());
    checkLanguage("Chichewa",       "ny" , ui->checkBoxTranslationsNY->isChecked());
    checkLanguage("Corsican",       "co" , ui->checkBoxTranslationsCO->isChecked());
    checkLanguage("Croatian",       "hr" , ui->checkBoxTranslationsHR->isChecked());
    checkLanguage("Czech",          "cs" , ui->checkBoxTranslationsCS->isChecked());
    checkLanguage("Danish",         "da" , ui->checkBoxTranslationsDA->isChecked());
    checkLanguage("Dutch",          "nl" , ui->checkBoxTranslationsNL->isChecked());
    checkLanguage("English",        "en" , ui->checkBoxTranslationsEN->isChecked());
    checkLanguage("Esperanto",      "eo" , ui->checkBoxTranslationsEO->isChecked());
    checkLanguage("Estonian",       "et" , ui->checkBoxTranslationsET->isChecked());
    checkLanguage("Faeroese",       "fo" , ui->checkBoxTranslationsFO->isChecked());
    checkLanguage("Farsi",          "fa" , ui->checkBoxTranslationsFA->isChecked());
    checkLanguage("Finnish",        "fi" , ui->checkBoxTranslationsFI->isChecked());
    checkLanguage("Fijian",         "fj" , ui->checkBoxTranslationsFJ->isChecked());
    checkLanguage("French",         "fr" , ui->checkBoxTranslationsFR->isChecked());
    checkLanguage("Frisian",        "fy" , ui->checkBoxTranslationsFY->isChecked());
    checkLanguage("Gaelic",         "gd" , ui->checkBoxTranslationsGD->isChecked());
    checkLanguage("Galician",       "gl" , ui->checkBoxTranslationsGL->isChecked());
    checkLanguage("German",         "de" , ui->checkBoxTranslationsDE->isChecked());
    checkLanguage("Georgian",       "ka" , ui->checkBoxTranslationsKA->isChecked());
    checkLanguage("Greek",          "el" , ui->checkBoxTranslationsEL->isChecked());
    checkLanguage("Gujarati",       "gu" , ui->checkBoxTranslationsGU->isChecked());
    checkLanguage("Haitian",        "ht" , ui->checkBoxTranslationsHT->isChecked());
    checkLanguage("Hausa",          "ha" , ui->checkBoxTranslationsHA->isChecked());
    checkLanguage("Hebrew",         "he" , ui->checkBoxTranslationsHE->isChecked());
    checkLanguage("Hindi",          "hi" , ui->checkBoxTranslationsHI->isChecked());
    checkLanguage("Hungarian",      "hu" , ui->checkBoxTranslationsHU->isChecked());
    checkLanguage("Icelandic",      "is" , ui->checkBoxTranslationsIS->isChecked());
    checkLanguage("Igbo",           "ig" , ui->checkBoxTranslationsIG->isChecked());
    checkLanguage("Indonesian",     "id" , ui->checkBoxTranslationsID->isChecked());
    checkLanguage("Irish",          "ga" , ui->checkBoxTranslationsGA->isChecked());
    checkLanguage("Italian",        "it" , ui->checkBoxTranslationsIT->isChecked());
    checkLanguage("Japanese",       "ja" , ui->checkBoxTranslationsJA->isChecked());
    checkLanguage("Javanese",       "jw" , ui->checkBoxTranslationsJW->isChecked());
    checkLanguage("Kannada",        "kn" , ui->checkBoxTranslationsKN->isChecked());
    checkLanguage("Kazakh",         "kk" , ui->checkBoxTranslationsKK->isChecked());
    checkLanguage("Khmer",          "km" , ui->checkBoxTranslationsKM->isChecked());
    checkLanguage("Kinyarwanda",    "rw" , ui->checkBoxTranslationsRW->isChecked());
    checkLanguage("Korean",         "ko" , ui->checkBoxTranslationsKO->isChecked());
    checkLanguage("Kurdish",        "ku" , ui->checkBoxTranslationsKU->isChecked());
    checkLanguage("Kyrgyz",         "ky" , ui->checkBoxTranslationsKY->isChecked());
    checkLanguage("Lao",            "lo" , ui->checkBoxTranslationsLO->isChecked());
    checkLanguage("Latin",          "la" , ui->checkBoxTranslationsLA->isChecked());
    checkLanguage("Latvian",        "lv" , ui->checkBoxTranslationsLV->isChecked());
    checkLanguage("Lithuanian",     "lt" , ui->checkBoxTranslationsLT->isChecked());
    checkLanguage("Luxembourgish",  "lb" , ui->checkBoxTranslationsLB->isChecked());
    checkLanguage("Macedonian",     "mk" , ui->checkBoxTranslationsMK->isChecked());
    checkLanguage("Malagasy",       "mg" , ui->checkBoxTranslationsMG->isChecked());
    checkLanguage("Malayalam",      "ml" , ui->checkBoxTranslationsML->isChecked());
    checkLanguage("Malaysian",      "ms" , ui->checkBoxTranslationsMS->isChecked());
    checkLanguage("Maltese",        "mt" , ui->checkBoxTranslationsMT->isChecked());
    checkLanguage("Maori",          "mi" , ui->checkBoxTranslationsMI->isChecked());
    checkLanguage("Marathi",        "mr" , ui->checkBoxTranslationsMR->isChecked());
    checkLanguage("Mongolian",      "mn" , ui->checkBoxTranslationsMN->isChecked());
    checkLanguage("Myanmar",        "my" , ui->checkBoxTranslationsMY->isChecked());
    checkLanguage("Norwegian",      "no" , ui->checkBoxTranslationsNO->isChecked());
    checkLanguage("Bokmal",         "nb" , ui->checkBoxTranslationsNB->isChecked());
    checkLanguage("Nynorsk",        "nn" , ui->checkBoxTranslationsNN->isChecked());
    checkLanguage("Nepali",         "ne" , ui->checkBoxTranslationsNE->isChecked());
    checkLanguage("Oriya",          "or" , ui->checkBoxTranslationsOR->isChecked());
    checkLanguage("Pashto",         "ps" , ui->checkBoxTranslationsPS->isChecked());
    checkLanguage("Polish",         "pl" , ui->checkBoxTranslationsPL->isChecked());
    checkLanguage("Portuguese",     "pt" , ui->checkBoxTranslationsPT->isChecked());
    checkLanguage("Punjabi",        "pa" , ui->checkBoxTranslationsPA->isChecked());
    checkLanguage("Rhaeto-Romanic", "rm" , ui->checkBoxTranslationsRM->isChecked());
    checkLanguage("Romanian",       "ro" , ui->checkBoxTranslationsRO->isChecked());
    checkLanguage("Russian",        "ru" , ui->checkBoxTranslationsRU->isChecked());
    checkLanguage("Samoan",         "sm" , ui->checkBoxTranslationsSM->isChecked());
    checkLanguage("Sesotho",        "st" , ui->checkBoxTranslationsST->isChecked());
    checkLanguage("Serbian",        "sr" , ui->checkBoxTranslationsSR->isChecked());
    checkLanguage("Shona",          "sn" , ui->checkBoxTranslationsSN->isChecked());
    checkLanguage("Sindhi",         "sd" , ui->checkBoxTranslationsSD->isChecked());
    checkLanguage("Sinhala",        "si" , ui->checkBoxTranslationsSI->isChecked());
    checkLanguage("Slovak",         "sk" , ui->checkBoxTranslationsSK->isChecked());
    checkLanguage("Slovenian",      "sl" , ui->checkBoxTranslationsSL->isChecked());
    checkLanguage("Spanish",        "es" , ui->checkBoxTranslationsES->isChecked());
    checkLanguage("Somali",         "so" , ui->checkBoxTranslationsSO->isChecked());
    checkLanguage("Sorbian",        "sb" , ui->checkBoxTranslationsSB->isChecked());
    checkLanguage("Sundanese",      "su" , ui->checkBoxTranslationsSU->isChecked());
    checkLanguage("Swahili",        "sw" , ui->checkBoxTranslationsSW->isChecked());
    checkLanguage("Swedish",        "sv" , ui->checkBoxTranslationsSV->isChecked());
    checkLanguage("Tagalog",        "tl" , ui->checkBoxTranslationsTL->isChecked());
    checkLanguage("Tahitian",       "ty" , ui->checkBoxTranslationsTY->isChecked());
    checkLanguage("Tajik",          "tg" , ui->checkBoxTranslationsTG->isChecked());
    checkLanguage("Tamil",          "ta" , ui->checkBoxTranslationsTA->isChecked());
    checkLanguage("Tatar",          "tt" , ui->checkBoxTranslationsTT->isChecked());
    checkLanguage("Telugu",         "te" , ui->checkBoxTranslationsTE->isChecked());
    checkLanguage("Tongan",         "to" , ui->checkBoxTranslationsTO->isChecked());
    checkLanguage("Turkmen",        "tk" , ui->checkBoxTranslationsTK->isChecked());
    checkLanguage("Thai",           "th" , ui->checkBoxTranslationsTH->isChecked());
    checkLanguage("Tsonga",         "ts" , ui->checkBoxTranslationsTS->isChecked());
    checkLanguage("Tswana",         "tn" , ui->checkBoxTranslationsTN->isChecked());
    checkLanguage("Turkish",        "tr" , ui->checkBoxTranslationsTR->isChecked());
    checkLanguage("Ukrainian",      "uk" , ui->checkBoxTranslationsUK->isChecked());
    checkLanguage("Uighur",         "ug" , ui->checkBoxTranslationsUG->isChecked());
    checkLanguage("Uzbek",          "uz" , ui->checkBoxTranslationsUZ->isChecked());
    checkLanguage("Urdu",           "ur" , ui->checkBoxTranslationsUR->isChecked());
    checkLanguage("Venda",          "ve" , ui->checkBoxTranslationsVE->isChecked());
    checkLanguage("Vietnamese",     "vi" , ui->checkBoxTranslationsVI->isChecked());
    checkLanguage("Welsh",          "cy" , ui->checkBoxTranslationsCY->isChecked());
    checkLanguage("Xhosa",          "xh" , ui->checkBoxTranslationsXH->isChecked());
    checkLanguage("Yiddish",        "yi" , ui->checkBoxTranslationsYI->isChecked());
    checkLanguage("Yoruba",         "yo" , ui->checkBoxTranslationsYO->isChecked());
    checkLanguage("Zulu",           "zu" , ui->checkBoxTranslationsZU->isChecked());
    checkLanguage("SimplifiedChinese",  "zh-CN" , ui->checkBoxTranslationsZH_CN->isChecked());
    checkLanguage("TraditionalChinese", "zh-TW" , ui->checkBoxTranslationsZH_TW->isChecked());
    // Added
    checkLanguage("Klingon", "tlh" ,            ui->checkBoxTranslationsTLH->isChecked());
    checkLanguage("KlingonPlqaD", "tlh-Qaak" ,  ui->checkBoxTranslationsTLH_QAAK->isChecked());
    checkLanguage("Cantonese", "yue" ,          ui->checkBoxTranslationsYUE->isChecked());
    checkLanguage("Cebuano", "ceb" ,            ui->checkBoxTranslationsCEB->isChecked());
    checkLanguage("Filipino", "fil" ,           ui->checkBoxTranslationsFIL->isChecked());
    checkLanguage("Hawaiian", "haw" ,           ui->checkBoxTranslationsHAW->isChecked());
    checkLanguage("HillMari", "mrj" ,           ui->checkBoxTranslationsMRJ->isChecked());
    checkLanguage("Hmong", "hmn" ,              ui->checkBoxTranslationsHMN->isChecked());
    checkLanguage("LevantineArabic", "apc" ,    ui->checkBoxTranslationsAPC->isChecked());
    checkLanguage("Mari", "mhr" ,               ui->checkBoxTranslationsMHR->isChecked());
    checkLanguage("Papiamento", "pap" ,         ui->checkBoxTranslationsPAP->isChecked());
    checkLanguage("QueretaroOtomi", "otq" ,     ui->checkBoxTranslationsOTQ->isChecked());
    checkLanguage("SerbianLatin", "sr-Latin" ,  ui->checkBoxTranslationsSR_LATIN->isChecked());
    checkLanguage("Udmurt", "udm" ,             ui->checkBoxTranslationsUDM->isChecked());
    checkLanguage("YucatecMaya", "yua" ,        ui->checkBoxTranslationsYUA->isChecked());
    return myLanguages;
}
/************************************************
 * @brief check Language.
 * checkLanguage
 ***********************************************/
void MainWindow::checkLanguage(const QString &thisName, const QString &thisLanguage, bool thisChecked)
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "checkLanguage"; }
    QString theLangagesIDs = myLanguages;
    myLanguageName = thisName;
    if (thisChecked)
    {
        if (theLangagesIDs.contains(thisLanguage, Qt::CaseInsensitive)) { return; }
        else
        {
            if (theLangagesIDs.isEmpty())
            {
                theLangagesIDs.append(QString("%1").arg(thisLanguage.toLower()));
            }
            else
            {
                theLangagesIDs.append(QString(", %1").arg(thisLanguage.toLower()));
            }
        }
    }
    else
    {
        if (theLangagesIDs.contains(thisLanguage, Qt::CaseInsensitive))
        {
            if (theLangagesIDs.indexOf(thisLanguage, Qt::CaseInsensitive) - 1 > -1)
            {
                theLangagesIDs.remove(thisLanguage, Qt::CaseInsensitive);
            }
            else
            {
                theLangagesIDs.remove(QString(", %1").arg(thisLanguage), Qt::CaseInsensitive);
            }
        }
    }
    myLanguages = theLangagesIDs;
}
/************************************************
 * @brief fill Forms.
 * fillForms
 ***********************************************/
void MainWindow::fillForms(const QString &thisProjectID)
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "fillForms=" << thisProjectID; }
    clearForms(TabAll);
    ui->labelRecordIdSettings->setText(thisProjectID); // Project id and Configuration ProjectID
    // Declare all variable in function scope
    QString theDbValve;
    QSqlQuery query; //!< SQL Query
    QString myConfigurationSelectQuery = mySqlDb->getQtProjectFullSelectQueryID(thisProjectID);
    if (isDebugMessage && isMainLoaded) { qDebug() << " myConfigurationSelectQuery=|" << myConfigurationSelectQuery << "|"; }
    /*
     * id, QtProjectName, QtProjectFolder, SourceFolder, DestinationFolder, HelpFolder, LanguageIDs
    */
    if (query.exec(myConfigurationSelectQuery))
    {
        if (query.first())
        {
            if (isDebugMessage && isMainLoaded) { qDebug() << " QtProjectName=|" << query.value("QtProjectName").toString() << "| SourceFolder=|" << query.value("SourceFolder").toString() << "| QtProjectFolder=|" << query.value("QtProjectFolder").toString() << "| DestinationFolder=|" << query.value("DestinationFolder").toString() << "| HelpFolder=|" << query.value("HelpFolder").toString() << "| LanguageIDs=|" << query.value("LanguageIDs").toString() << "|"; }
            // Set Record ID
            myRecordID = query.value("id").toInt();
            ui->labelRecordIdSettings->setText(query.value("id").toString());
            ui->lineEditSettingsQtProjectName->setText(query.value("QtProjectName").toString());
            ui->lineEditTranslationsProjectFolder->setText(query.value("QtProjectFolder").toString());
            ui->lineEditTranslationsSource->setText(query.value("SourceFolder").toString());
            ui->lineEditTranslationsDestination->setText(query.value("DestinationFolder").toString());
            ui->lineEditTranslationsHelp->setText(query.value("HelpFolder").toString());
            //
            ui->radioButtonTranslationsQmake->setChecked(query.value("Make").toString() == "qmake" ? true : false);
            ui->radioButtonTranslationsCmake->setChecked(query.value("Make").toString() == "cmake" ? true : false);
            //
            mySourceLanguage = query.value("SourceLanguage").toString();
            ui->comboBoxTranslationSourceLanguage->setCurrentIndex(ui->comboBoxTranslationSourceLanguage->findText(query.value("SourceLanguage").toString()));
            setLanguageCode();
            // en,de,fr,it,ja,zh,no,ru,sv,ar
            theDbValve = query.value("LanguageIDs").toString();
            // set check boxes
            if (theDbValve.contains("af", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsAF->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsAF->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("sq", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsSQ->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsSQ->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("ar", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsAR->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsAR->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("eu", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsEU->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsEU->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("be", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsBE->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsBE->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("bg", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsBG->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsBG->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("ca", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsCA->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsCA->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("zh-CN", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsZH_CN->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsZH_CN->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("zh-TW", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsZH_TW->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsZH_TW->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("hr", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsHR->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsHR->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("cs", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsCS->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsCS->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("da", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsDA->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsDA->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("nl", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsNL->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsNL->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("en", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsEN->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsEN->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("et", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsET->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsET->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("fo", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsFO->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsFO->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("fa", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsFA->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsFA->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("fi", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsFI->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsFI->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("fr", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsFR->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsFR->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("gd", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsGD->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsGD->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("de", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsDE->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsDE->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("el", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsEL->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsEL->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("he", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsHE->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsHE->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("hi", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsHI->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsHI->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("hu", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsHU->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsHU->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("is", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsIS->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsIS->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("id", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsID->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsID->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("ga", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsGA->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsGA->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("it", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsIT->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsIT->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("ja", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsJA->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsJA->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("ko", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsKO->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsKO->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("ku", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsKU->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsKU->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("lv", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsLV->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsLV->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("lt", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsLT->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsLT->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("mk", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsMK->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsMK->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("ml", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsML->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsML->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("ms", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsMS->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsMS->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("mt", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsMT->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsMT->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("no", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsNO->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsNO->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("nb", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsNB->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsNB->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("nn", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsNN->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsNN->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("pl", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsPL->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsPL->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("pt", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsPT->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsPT->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("pa", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsPA->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsPA->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("rm", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsRM->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsRM->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("ro", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsRO->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsRO->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("ru", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsRU->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsRU->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("sr", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsSR->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsSR->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("sk", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsSK->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsSK->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("sl", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsSL->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsSL->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("sb", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsSB->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsSB->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("es", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsES->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsES->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("sv", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsSV->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsSV->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("th", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsTH->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsTH->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("ts", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsTS->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsTS->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("tn", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsTN->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsTN->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("tr", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsTR->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsTR->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("uk", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsUK->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsUK->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("ur", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsUR->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsUR->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("ve", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsVE->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsVE->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("vi", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsVI->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsVI->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("cy", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsCY->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsCY->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("xh", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsXH->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsXH->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("yi", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsYI->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsYI->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("zu", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsZU->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsZU->setCheckState(Qt::CheckState::Unchecked); }


            if (theDbValve.contains("am", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsAM->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsAM->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("hy", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsHY->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsHY->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("az", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsAZ->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsAZ->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("ba", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsBA->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsBA->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("bn", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsBN->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsBN->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("bs", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsBS->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsBS->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("ny", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsNY->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsNY->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("co", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsCO->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsCO->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("eo", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsEO->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsEO->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("fj", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsFJ->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsFJ->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("fy", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsFY->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsFY->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("gl", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsGL->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsGL->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("ka", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsKA->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsKA->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("GU", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsGU->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsGU->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("HT", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsHT->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsHT->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("ha", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsHA->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsHA->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("ig", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsIG->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsIG->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("jw", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsJW->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsJW->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("kn", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsKN->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsKN->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("kk", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsKK->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsKK->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("km", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsKM->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsKM->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("rw", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsRW->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsRW->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("ky", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsKY->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsKY->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("lo", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsLO->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsLO->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("la", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsLA->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsLA->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("lb", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsLB->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsLB->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("mg", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsMG->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsMG->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("mi", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsMI->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsMI->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("mr", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsMR->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsMR->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("mn", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsMN->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsMN->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("my", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsMY->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsMY->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("ne", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsNE->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsNE->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("or", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsOR->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsOR->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("ps", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsPS->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsPS->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("sm", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsSM->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsSM->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("st", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsST->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsST->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("sn", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsSN->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsSN->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("sd", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsSD->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsSD->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("si", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsSI->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsSI->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("so", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsSO->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsSO->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("su", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsSU->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsSU->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("sw", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsSW->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsSW->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("tl", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsTL->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsTL->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("ty", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsTY->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsTY->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("tg", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsTG->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsTG->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("ta", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsTA->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsTA->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("tt", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsTT->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsTT->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("te", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsTE->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsTE->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("to", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsTO->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsTO->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("tk", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsTK->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsTK->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("ug", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsUG->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsUG->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("uz", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsUZ->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsUZ->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("yo", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsYO->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsYO->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("tlh", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsTLH->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsTLH->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("tlh-Qaak", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsTLH_QAAK->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsTLH_QAAK->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("yue", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsYUE->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsYUE->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("ceb", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsCEB->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsCEB->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("fil", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsFIL->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsFIL->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("haw", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsHAW->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsHAW->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("mrj", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsMRJ->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsMRJ->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("hmn", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsHMN->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsHMN->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("apc", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsAPC->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsAPC->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("mhr", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsMHR->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsMHR->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("pap", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsPAP->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsPAP->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("otq", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsOTQ->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsOTQ->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("sr-Latin", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsSR_LATIN->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsSR_LATIN->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("udm", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsUDM->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsUDM->setCheckState(Qt::CheckState::Unchecked); }
            if (theDbValve.contains("yua", Qt::CaseInsensitive))
            { ui->checkBoxTranslationsYUA->setCheckState(Qt::CheckState::Checked); }
            else
            { ui->checkBoxTranslationsYUA->setCheckState(Qt::CheckState::Unchecked); }
        }
        else
        {
            mySqlDb->mySqlModel->mySetting->showMessageBox(QObject::tr("Could not read from the Database").toLocal8Bit(), QString("%1 %2").arg(tr("Unable to find record in database"), myConfigurationSelectQuery).toLocal8Bit(), mySqlDb->mySqlModel->mySetting->Critical);
        }
    }
    else
    {
        mySqlDb->mySqlModel->mySetting->showMessageBox(tr("Could not read from the Database").toLocal8Bit(), QString("%1 %2").arg(tr("Unable to find record in database"), myConfigurationSelectQuery).toLocal8Bit(), mySqlDb->mySqlModel->mySetting->Critical);
        return;
    }
    isSaveSettings = false;
}
/************************************************
 * @brief clear Tab Settings.
 * clearTabSettings
 ***********************************************/
void MainWindow::clearTabSettings()
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "clearTabSettings"; }
    // Defaults
    ui->labelRecordIdSettings->setText("0");
}
/************************************************
 * @brief clear Tab Translations.
 * clearTabTranslations
 ***********************************************/
void MainWindow::clearTabTranslations()
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "clearTabTranslations"; }
    // Defaults
    //#define TEST_FORM
    #ifdef TEST_FORM
    ui->lineEditTranslationsDestination->setText("Destination");
    ui->lineEditTranslationsSource->setText("Source");
    ui->lineEditTranslationsProjectFolder->setText("ProjectFolder");
    ui->checkBoxTranslationsAF->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsSQ->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsAR->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsEU->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsBE->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsBG->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsCA->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsHR->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsCS->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsAR->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsNL->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsEN->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsET->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsFO->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsFA->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsFI->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsFR->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsGD->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsDE->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsEL->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsHE->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsHI->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsHU->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsIS->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsID->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsGA->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsIT->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsJA->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsKO->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsKU->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsLV->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsLT->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsMK->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsML->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsMS->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsMT->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsNO->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsNB->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsNN->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsPL->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsPT->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsPA->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsRM->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsRO->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsRU->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsSR->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsSK->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsSL->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsSB->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsES->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsSV->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsTH->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsTS->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsTN->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsTR->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsUK->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsUR->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsVE->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsVI->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsCY->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsXH->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsYI->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsZU->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsAM->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsHY->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsAZ->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsBA->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsBN->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsBS->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsNY->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsCO->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsEO->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsFJ->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsFY->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsGL->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsKA->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsGU->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsHT->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsHA->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsIG->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsJW->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsKN->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsKK->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsKM->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsRW->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsKY->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsLO->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsLA->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsLB->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsMG->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsMI->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsMR->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsMN->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsMY->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsNE->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsOR->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsPS->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsSM->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsST->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsSN->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsSD->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsSI->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsSO->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsSU->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsSW->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsTL->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsTY->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsTG->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsTA->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsTT->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsTE->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsTO->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsTK->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsUG->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsUZ->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsYO->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsZH_CN->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsZH_TW->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsTLH->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsTLH_QAAK->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsYUE->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsCEB->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsFIL->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsHAW->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsMRJ->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsHMN->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsAPC->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsMHR->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsPAP->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsOTQ->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsSR_LATIN->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsUDM->setCheckState(Qt::CheckState::Checked);
    ui->checkBoxTranslationsYUA->setCheckState(Qt::CheckState::Checked);
    #else
    ui->lineEditTranslationsDestination->setText("");
    ui->lineEditTranslationsSource->setText("");
    ui->lineEditTranslationsProjectFolder->setText("");
    ui->checkBoxTranslationsAF->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsSQ->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsAR->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsEU->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsBE->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsBG->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsCA->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsHR->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsCS->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsAR->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsNL->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsEN->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsET->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsFO->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsFA->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsFI->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsFR->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsGD->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsDE->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsEL->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsHE->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsHI->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsHU->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsIS->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsID->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsGA->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsIT->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsJA->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsKO->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsKU->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsLV->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsLT->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsMK->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsML->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsMS->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsMT->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsNO->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsNB->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsNN->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsPL->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsPT->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsPA->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsRM->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsRO->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsRU->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsSR->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsSK->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsSL->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsSB->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsES->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsSV->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsTH->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsTS->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsTN->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsTR->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsUK->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsUR->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsVE->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsVI->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsCY->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsXH->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsYI->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsZU->setCheckState(Qt::CheckState::Unchecked);

    ui->checkBoxTranslationsAM->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsHY->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsAZ->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsBA->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsBN->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsBS->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsNY->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsCO->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsEO->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsFJ->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsFY->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsGL->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsKA->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsGU->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsHT->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsHA->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsIG->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsJW->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsKN->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsKK->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsKM->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsRW->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsKY->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsLO->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsLA->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsLB->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsMG->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsMI->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsMR->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsMN->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsMY->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsNE->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsOR->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsPS->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsSM->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsST->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsSN->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsSD->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsSI->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsSO->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsSU->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsSW->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsTL->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsTY->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsTG->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsTA->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsTT->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsTE->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsTO->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsTK->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsUG->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsUZ->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsYO->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsZH_CN->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsZH_TW->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsTLH->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsTLH_QAAK->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsYUE->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsCEB->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsFIL->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsHAW->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsMRJ->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsHMN->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsAPC->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsMHR->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsPAP->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsOTQ->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsSR_LATIN->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsUDM->setCheckState(Qt::CheckState::Unchecked);
    ui->checkBoxTranslationsYUA->setCheckState(Qt::CheckState::Unchecked);
    #endif
}
/************************************************
 * @brief clear Tab Project.
 * clearTabProject
 ***********************************************/
void MainWindow::clearTabProject()
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "clearTabProject"; }
    ui->textEditProjects->setText("");
}
/************************************************
 * @brief clear Tab Help.
 * clearTabHelp
 ***********************************************/
void MainWindow::clearTabHelp()
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "clearTabHelp"; }
    ui->textEditHelp->setText("");
}
/************************************************
 * @brief clear Forms.
 * clearForms
 ***********************************************/
void MainWindow::clearForms(int tabNumber)
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "clearForms"; }
    switch (tabNumber)
    {
        case TabSettings:     clearTabSettings();     break;
        case TabTranslations: clearTabTranslations(); break;
        case TabProject:      clearTabProject();      break;
        case TabTabHelp:      clearTabHelp();      break;
        case TabAll:
            ui->labelRecordIdSettings->setText("");
            clearTabSettings();
            clearTabTranslations();
            clearTabProject();
            clearTabHelp();
            break;
    }
}
/************************************************
 * @brief set Tab Settings.
 * setTabSettings
 ***********************************************/
void MainWindow::setTabSettings()
{
    mySqlDb->myProject->setID(ui->labelRecordIdSettings->text());
    mySqlDb->myProject->setQtProjectName(ui->lineEditSettingsQtProjectName->text());
    mySqlDb->myProject->setQtProjectFolder(ui->lineEditTranslationsProjectFolder->text());
    mySqlDb->myProject->setSourceFolder(ui->lineEditTranslationsSource->text());
    mySqlDb->myProject->setDestinationFolder(ui->lineEditTranslationsDestination->text());
    mySqlDb->myProject->setHelpFolder(ui->lineEditTranslationsHelp->text());
    mySqlDb->myProject->setSourceLanguage(ui->comboBoxTranslationSourceLanguage->currentText());
    mySqlDb->myProject->setLanguageIDs(languageChecked());
    mySqlDb->myProject->setMake(ui->radioButtonTranslationsQmake->isChecked() ? "qmake" : "cmake");
}
/************************************************
 * @brief set Tab Translations.
 * setTabTranslations
 ***********************************************/
void MainWindow::setTabTranslations()
{
    mySqlDb->myProject->setID(ui->labelRecordIdSettings->text());
    mySqlDb->myProject->setQtProjectName(ui->lineEditSettingsQtProjectName->text());
    mySqlDb->myProject->setQtProjectFolder(ui->lineEditTranslationsProjectFolder->text());
    mySqlDb->myProject->setSourceFolder(ui->lineEditTranslationsSource->text());
    mySqlDb->myProject->setDestinationFolder(ui->lineEditTranslationsDestination->text());
    mySqlDb->myProject->setHelpFolder(ui->lineEditTranslationsHelp->text());
    mySqlDb->myProject->setSourceLanguage(ui->comboBoxTranslationSourceLanguage->currentText());
    mySqlDb->myProject->setLanguageIDs(languageChecked());
    mySqlDb->myProject->setMake(ui->radioButtonTranslationsQmake->isChecked() ? "qmake" : "cmake");
}
/************************************************
 * @brief set Tab All.
 * setTabAll
 ***********************************************/
void MainWindow::setTabAll()
{
    mySqlDb->myProject->setID(ui->labelRecordIdSettings->text());
    mySqlDb->myProject->setQtProjectName(ui->lineEditSettingsQtProjectName->text());
    mySqlDb->myProject->setQtProjectFolder(ui->lineEditTranslationsProjectFolder->text());
    mySqlDb->myProject->setSourceFolder(ui->lineEditTranslationsSource->text());
    mySqlDb->myProject->setDestinationFolder(ui->lineEditTranslationsDestination->text());
    mySqlDb->myProject->setHelpFolder(ui->lineEditTranslationsHelp->text());
    mySqlDb->myProject->setSourceLanguage(ui->comboBoxTranslationSourceLanguage->currentText());
    mySqlDb->myProject->setLanguageIDs(languageChecked());
    mySqlDb->myProject->setMake(ui->radioButtonTranslationsQmake->isChecked() ? "qmake" : "cmake");
}
/************************************************
 * @brief set Project Class.
 * setProjectClass
 ***********************************************/
void MainWindow::setProjectClass(int tabNumber)
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "setProjectClass"; }
    switch (tabNumber)
    {
        case TabSettings:
            setTabSettings();
            break;
        case TabTranslations:
            setTabTranslations();
            break;
        case TabProject:
            break;
        case TabTabHelp:
            break;
        case TabSql:
            writeAllSettings();
            break;
        case TabAll:
            setTabAll();
            break;
    }
}
/************************************************
 * @brief on Compile.
 * onCompile
 ***********************************************/
void MainWindow::onCompile()
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "onCompile"; }
    if (ui->lineEditTranslationsDestination->text() == ui->lineEditTranslationsSource->text())
    {
        mySqlDb->mySqlModel->mySetting->showMessageBox(QObject::tr("Error Source and Destination cannot be the same").toLocal8Bit(), QString("%1: %2 %3: %4 %5").arg(tr("Source"), ui->lineEditTranslationsSource->text(), tr("and Destination"), ui->lineEditTranslationsDestination->text(), tr("cannot be the same")).toLocal8Bit(), mySqlDb->mySqlModel->mySetting->Critical);
        return;
    }
    QString theProject = mySqlDb->mySqlModel->mySetting->combinePathFileName(ui->lineEditTranslationsProjectFolder->text(), QString("%1%2").arg(ui->lineEditSettingsQtProjectName->text(), ui->radioButtonTranslationsQmake->isChecked() ? ".pro" : ".cmake"));
    if (!mySqlDb->mySqlModel->mySetting->isFileExists(theProject))
    {
        mySqlDb->mySqlModel->mySetting->showMessageBox(QObject::tr("Project file not found").toLocal8Bit(), QString("%1: %2").arg(tr("Project file not found"), theProject).toLocal8Bit(), mySqlDb->mySqlModel->mySetting->Critical);
        return;
    }
    QString theLupdateResult  = mySqlDb->mySqlModel->runProcces(ui->lineEditSettingsLupdate->text(), theProject, true, 60);
    if (mySqlDb->mySqlModel->getRunReturnCode() != 0)
    {
        mySqlDb->mySqlModel->mySetting->showMessageBox(QObject::tr("Error running lupdate").toLocal8Bit(), QString("%1: %2").arg(tr("Error running lupdate"), theLupdateResult).toLocal8Bit(), mySqlDb->mySqlModel->mySetting->Critical);
        return;
    }
    if (!mySqlDb->mySqlModel->mySetting->isMakeDir(ui->lineEditTranslationsDestination->text()))
    {
        mySqlDb->mySqlModel->mySetting->showMessageBox(QObject::tr("Error Translations Destination Folder").toLocal8Bit(), QString("%1: %2").arg(tr("Error could not make Translations Destination"), ui->lineEditTranslationsDestination->text()).toLocal8Bit(), mySqlDb->mySqlModel->mySetting->Critical);
        return;
    }
    setProjectClass(TabAll);
    if (ui->radioButtonTranslationsQmake->isChecked())
    {
        // qmake
        myTranslationConf = "TRANSLATIONS += ";
    }
    else
    {
        // cmake
        myTranslationConf = "set(TS_FILES ";
    }
    myTranslationQrc.clear();

    createTranslationJob("Afrikaans",           "af" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsAF->isChecked());
    createTranslationJob("Albanian",            "sq" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsSQ->isChecked());
    createTranslationJob("Amharic",             "am" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsAM->isChecked());
    createTranslationJob("Arabic",              "ar" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsAR->isChecked());
    createTranslationJob("Armenian",            "hy" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsHY->isChecked());
    createTranslationJob("Azerbaijani",         "az" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsAZ->isChecked());
    createTranslationJob("Bashkir",             "ba" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsBA->isChecked());
    createTranslationJob("Basque",              "eu" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsEU->isChecked());
    createTranslationJob("Belarusian",          "be" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsBE->isChecked());
    createTranslationJob("Bengali",             "bn" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsBN->isChecked());
    createTranslationJob("Bosnian",             "bs" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsBS->isChecked());
    createTranslationJob("Bulgarian",           "bg" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsBG->isChecked());
    createTranslationJob("Cantonese",           "yue",      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsYO->isChecked());
    createTranslationJob("Catalan",             "ca" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsCA->isChecked());
    createTranslationJob("Cebuano",             "ceb",      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsYO->isChecked());
    createTranslationJob("Chichewa",            "ny" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsNY->isChecked());
    createTranslationJob("Corsican",            "co" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsCO->isChecked());
    createTranslationJob("Croatian",            "hr" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsHR->isChecked());
    createTranslationJob("Czech",               "cs" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsCS->isChecked());
    createTranslationJob("SimplifiedChinese",   "zh-CN" ,   ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsZH_CN->isChecked());
    createTranslationJob("TraditionalChinese",  "zh-TW" ,   ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsZH_TW->isChecked());
    createTranslationJob("Danish",              "da" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsDA->isChecked());
    createTranslationJob("Dutch",               "nl" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsNL->isChecked());
    createTranslationJob("English",             "en" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsEN->isChecked());
    createTranslationJob("Estonian",            "et" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsET->isChecked());
    createTranslationJob("Esperanto",           "eo" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsEO->isChecked());
    createTranslationJob("Faeroese",            "fo" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsFO->isChecked());
    createTranslationJob("Farsi",               "fa" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsFA->isChecked());
    createTranslationJob("Fijian",              "fj" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsFJ->isChecked());
    createTranslationJob("Filipino",            "fil",      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsYO->isChecked());
    createTranslationJob("Finnish",             "fi" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsFI->isChecked());
    createTranslationJob("French",              "fr" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsFR->isChecked());
    createTranslationJob("Frisian",             "fy" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsFY->isChecked());
    createTranslationJob("Gaelic",              "gd" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsGD->isChecked());
    createTranslationJob("Galician",            "gl" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsGL->isChecked());
    createTranslationJob("Georgian",            "ka" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsKA->isChecked());
    createTranslationJob("German",              "de" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsDE->isChecked());
    createTranslationJob("Greek",               "el" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsEL->isChecked());
    createTranslationJob("Gujarati",            "gu" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsGU->isChecked());
    createTranslationJob("Haitian",             "ht" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsHT->isChecked());
    createTranslationJob("Hausa",               "ha" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsHA->isChecked());
    createTranslationJob("Hawaiian",            "haw",      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsYO->isChecked());
    createTranslationJob("Hebrew",              "he" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsHE->isChecked());
    createTranslationJob("HillMari",            "mrj",      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsYO->isChecked());
    createTranslationJob("Hindi",               "hi" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsHI->isChecked());
    createTranslationJob("Hmong",               "hmn",      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsYO->isChecked());
    createTranslationJob("Hungarian",           "hu" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsHU->isChecked());
    createTranslationJob("Icelandic",           "is" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsIS->isChecked());
    createTranslationJob("Igbo",                "ig" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsIG->isChecked());
    createTranslationJob("Indonesian",          "id" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsID->isChecked());
    createTranslationJob("Irish",               "ga" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsGA->isChecked());
    createTranslationJob("Italian",             "it" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsIT->isChecked());
    createTranslationJob("Japanese",            "ja" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsJA->isChecked());
    createTranslationJob("Javanese",            "jw" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsJW->isChecked());
    createTranslationJob("Kannada",             "kn" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsKN->isChecked());
    createTranslationJob("Kazakh",              "kk" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsKK->isChecked());
    createTranslationJob("Khmer",               "km" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsKM->isChecked());
    createTranslationJob("Kinyarwanda",         "rw" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsRW->isChecked());
    createTranslationJob("Klingon",             "tlh",      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsYO->isChecked());
    createTranslationJob("KlingonPlqaD",        "tlh-Qaak", ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsYO->isChecked());
    createTranslationJob("Korean",              "ko" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsKO->isChecked());
    createTranslationJob("Kurdish",             "ku" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsKU->isChecked());
    createTranslationJob("Kyrgyz",              "ky" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsKY->isChecked());
    createTranslationJob("Latvian",             "lv" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsLV->isChecked());
    createTranslationJob("Lao",                 "lo" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsLO->isChecked());
    createTranslationJob("Latin",               "la" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsLA->isChecked());
    createTranslationJob("LevantineArabic",     "apc",      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsYO->isChecked());
    createTranslationJob("Lithuanian",          "lt" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsLT->isChecked());
    createTranslationJob("Luxembourgish",       "lb" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsLB->isChecked());
    createTranslationJob("Macedonian",          "mk" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsMK->isChecked());
    createTranslationJob("Mari",                "mhr",      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsYO->isChecked());
    createTranslationJob("Maori",               "mi" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsMI->isChecked());
    createTranslationJob("Marathi",             "mr" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsMR->isChecked());
    createTranslationJob("Malagasy",            "mg" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsMG->isChecked());
    createTranslationJob("Malayalam",           "ml" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsML->isChecked());
    createTranslationJob("Malaysian",           "ms" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsMS->isChecked());
    createTranslationJob("Maltese",             "mt" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsMT->isChecked());
    createTranslationJob("Mongolian",           "mn" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsMN->isChecked());
    createTranslationJob("Myanmar",             "my" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsMY->isChecked());
    createTranslationJob("Norwegian",           "no" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsNO->isChecked());
    createTranslationJob("Bokmal",              "nb" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsNB->isChecked());
    createTranslationJob("Nepali",              "ne" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsNE->isChecked());
    createTranslationJob("Nynorsk",             "nn" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsNN->isChecked());
    createTranslationJob("Oriya",               "or" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsOR->isChecked());
    createTranslationJob("Pashto",              "ps" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsPS->isChecked());
    createTranslationJob("Papiamento",          "pap",      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsYO->isChecked());
    createTranslationJob("Polish",              "pl" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsPL->isChecked());
    createTranslationJob("Portuguese",          "pt" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsPT->isChecked());
    createTranslationJob("Punjabi",             "pa" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsPA->isChecked());
    createTranslationJob("QueretaroOtomi",      "otq",      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsYO->isChecked());
    createTranslationJob("Rhaeto-Romanic",      "rm" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsRM->isChecked());
    createTranslationJob("Romanian",            "ro" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsRO->isChecked());
    createTranslationJob("Russian",             "ru" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsRU->isChecked());
    createTranslationJob("Samoan",              "sm" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsSM->isChecked());
    createTranslationJob("Serbian",             "sr" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsSR->isChecked());
    createTranslationJob("SerbianLatin",        "sr-Latin", ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsYO->isChecked());
    createTranslationJob("Slovak",              "sk" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsSK->isChecked());
    createTranslationJob("Slovenian",           "sl" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsSL->isChecked());
    createTranslationJob("Sesotho",             "st" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsST->isChecked());
    createTranslationJob("Shona",               "sn" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsSN->isChecked());
    createTranslationJob("Sindhi",              "sd" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsSD->isChecked());
    createTranslationJob("Sinhala",             "si" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsSI->isChecked());
    createTranslationJob("Somali",              "so" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsSO->isChecked());
    createTranslationJob("Sorbian",             "sb" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsSB->isChecked());
    createTranslationJob("Spanish",             "es" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsES->isChecked());
    createTranslationJob("Sundanese",           "su" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsSU->isChecked());
    createTranslationJob("Swahili",             "sw" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsSW->isChecked());
    createTranslationJob("Swedish",             "sv" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsSV->isChecked());
    createTranslationJob("Tagalog",             "tl" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsTL->isChecked());
    createTranslationJob("Tahitian",            "ty" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsTY->isChecked());
    createTranslationJob("Tajik",               "tg" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsTG->isChecked());
    createTranslationJob("Tamil",               "ta" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsTA->isChecked());
    createTranslationJob("Tatar",               "tt" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsTT->isChecked());
    createTranslationJob("Telugu",              "te" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsTE->isChecked());
    createTranslationJob("Thai",                "th" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsTH->isChecked());
    createTranslationJob("Tongan",              "to" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsTO->isChecked());
    createTranslationJob("Tsonga",              "ts" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsTS->isChecked());
    createTranslationJob("Tswana",              "tn" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsTN->isChecked());
    createTranslationJob("Turkish",             "tr" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsTR->isChecked());
    createTranslationJob("Turkmen",             "tk" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsTK->isChecked());
    createTranslationJob("Uighur",              "ub" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsUG->isChecked());
    createTranslationJob("Ukrainian",           "uk" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsUK->isChecked());
    createTranslationJob("Urdu",                "ur" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsUR->isChecked());
    createTranslationJob("Udmurt",              "udm",      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsYO->isChecked());
    createTranslationJob("Uzbek",               "uz" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsUZ->isChecked());
    createTranslationJob("Venda",               "ve" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsVE->isChecked());
    createTranslationJob("Vietnamese",          "vi" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsVI->isChecked());
    createTranslationJob("Welsh",               "cy" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsCY->isChecked());
    createTranslationJob("Xhosa",               "xh" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsXH->isChecked());
    createTranslationJob("Yiddish",             "yi" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsYI->isChecked());
    createTranslationJob("Yoruba",              "yo" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsYO->isChecked());
    createTranslationJob("YucatecMaya",         "yua",      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsYO->isChecked());
    createTranslationJob("Zulu",                "zu" ,      ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsZU->isChecked());

    if (ui->radioButtonTranslationsCmake->isChecked()) { myTranslationConf.append(")"); }
    //
    ui->textEditProjects->setText(QString("%1\n\n\n%2").arg(myTranslationConf, myTranslationQrc));
    ui->progressBarProjectsTranslations->show();
    ui->progressBarProjectsFiles->setMaximum(myLingoJob.count());
    ui->progressBarProjectsFiles->show();
    // Go to Tab
    ui->tabWidget->setCurrentIndex(ui->tabWidget->indexOf(ui->tabWidget->findChild<QWidget*>("tabProject")));
    //
    // Now I can run the job with myLingoJob
    for( int i = 0; i < myLingoJob.count(); ++i )
    {
        ui->progressBarProjectsFiles->setValue(i);
        // Made sure they know this gets deleted in status bar and tool tip
        mySqlDb->mySqlModel->mySetting->removeAllFiles(ui->lineEditTranslationsDestination->text());
        if (isDebugMessage && isMainLoaded) { qDebug() << "Translating..." << myLingoJob.at(i).getLanguageName(); }
        // check for files existance make sure source and destination are not the same is done at the beginning
        QString theDestTxtFile = QString("%1%2%3_%4.txt").arg(ui->lineEditTranslationsDestination->text(), QDir::separator(), ui->lineEditSettingsQtProjectName->text(), myLingoJob.at(i).getLangName());
        // Make sure to delete txt file before trying to create it, it will bomb
        if (mySqlDb->mySqlModel->mySetting->isFileExists(theDestTxtFile))
        {
            if (!mySqlDb->mySqlModel->mySetting->removeFile(theDestTxtFile))
            {
                if (mySqlDb->mySqlModel->mySetting->isFileExists(theDestTxtFile))
                {
                    // ts_tool --src translations/QtAppVeyor_en.ts  --dst translations_new/ --mode TXT --unfinished-only
                    mySqlDb->mySqlModel->mySetting->showMessageBox(QObject::tr("Error trying to remove file").toLocal8Bit(), QString("%1: %2").arg(tr("Can not remove file"), theDestTxtFile).toLocal8Bit(), mySqlDb->mySqlModel->mySetting->Critical);
                }
            }
        }
        // Create Txt file
        myTranlatorParser->toTXT(myLingoJob.at(i).getTsFile(), ui->lineEditTranslationsDestination->text(), true, false, true);
        // make sure txt file exist
        if (!mySqlDb->mySqlModel->mySetting->isFileExists(theDestTxtFile))
        {
            mySqlDb->mySqlModel->mySetting->showMessageBox(QObject::tr("Could not find the Txt file").toLocal8Bit(), QString("%1: %2").arg(tr("Can not find Txt file"), theDestTxtFile).toLocal8Bit(), mySqlDb->mySqlModel->mySetting->Critical);
            return;
        }
        bool isSameLanguage = false;
        if (myLingoJob.at(i).getLanguageName() == ui->comboBoxTranslationSourceLanguage->currentText()) { isSameLanguage = true; }
        //
        QString theTxtFileContent;
        //
        QFile theInputTxtFile(theDestTxtFile);
        if (theInputTxtFile.open(QIODevice::ReadOnly))
        {
            int theTranslastionsCounter = 1;
            ui->progressBarProjectsTranslations->setMaximum(mySqlDb->mySqlModel->mySetting->fileNumberLines(theDestTxtFile));
            QTextStream theTxtFileStream(&theInputTxtFile);
            while (!theTxtFileStream.atEnd())
            {
                ui->progressBarProjectsTranslations->setValue(theTranslastionsCounter++);
                // [[[00000281]]] "%1"
                QString theLine = theTxtFileStream.readLine();
                // Append ID
                theTxtFileContent.append(theLine.leftRef(theLine.indexOf("\"") -1));
                // Find what is in between "?"
                QString theMatch = theLine.section('"', 1, 1);
                // Check to see if it has any Letters in it
                if (mySqlDb->mySqlModel->mySetting->isWord(theMatch))
                {
                    if (theMatch.contains("%")) { myLocalization->removeArgs(theMatch, myLingoJob.at(i).getTsFile()); }
                    if (isSameLanguage)
                    { myTranslation = theMatch; }
                    else
                    {
                        // QString &text, Engine engine, Language translationLang, Language sourceLang, Language uiLang
                        myTranslation = translateWithReturn(theMatch, QOnlineTranslator::Engine::Google, myLingoJob.at(i).getLang(), myLingoJob.at(i).getSourceLang(), myQOnlineTranslator.language(QLocale()));
                        myTranslation = checkTranslationErrors(myTranslation, theMatch, QOnlineTranslator::Engine::Google, myLingoJob.at(i).getLang(), myLingoJob.at(i).getSourceLang(), myQOnlineTranslator.language(QLocale()));
                        // if empty use another service
                        if (myTranslation.isEmpty())
                        {
                            myTranslation = translateWithReturn(theMatch, QOnlineTranslator::Engine::Bing, myLingoJob.at(i).getLang(), myLingoJob.at(i).getSourceLang(), myQOnlineTranslator.language(QLocale()));
                            myTranslation = checkTranslationErrors(myTranslation, theMatch, QOnlineTranslator::Engine::Google, myLingoJob.at(i).getLang(), myLingoJob.at(i).getSourceLang(), myQOnlineTranslator.language(QLocale()));
                            if (myTranslation.isEmpty())
                            {
                                myTranslation = translateWithReturn(theMatch, QOnlineTranslator::Engine::Yandex, myLingoJob.at(i).getLang(), myLingoJob.at(i).getSourceLang(), myQOnlineTranslator.language(QLocale()));
                                myTranslation = checkTranslationErrors(myTranslation, theMatch, QOnlineTranslator::Engine::Google, myLingoJob.at(i).getLang(), myLingoJob.at(i).getSourceLang(), myQOnlineTranslator.language(QLocale()));
                            }
                        }
                    }
                }
                if (myTranslation.isEmpty()) { myTranslation = theMatch; }
                theTxtFileContent.append(QString(" \"%1\"\n").arg(myTranslation));
                ui->statusbar->showMessage(QString("%1: %2 = %3").arg(myLingoJob.at(i).getLanguageName(), theMatch, myTranslation));
                // Set a delay or you will be ban from Engine
                if (!isSameLanguage) { mySqlDb->mySqlModel->mySetting->delay(ui->spinBoxSettingsDelay->value()); }
            }
            theInputTxtFile.close();
            mySqlDb->mySqlModel->mySetting->writeFile(theDestTxtFile, theTxtFileContent);
            if (mySqlDb->mySqlModel->mySetting->isFileExists(theDestTxtFile))
            {
                myLocalization->fixTranslationFile(theDestTxtFile);
                // Create Txt file
                myTranlatorParser->toTS(ui->lineEditTranslationsDestination->text(), myLingoJob.at(i).getTsFile(), myLingoJob.at(i).getLangName());
            }
        } // end if (theInputTxtFile.open(QIODevice::ReadOnly))
    } // end for( int i = 0; i < myLingoJob.count(); ++i )
    QString theLreleaseResult = mySqlDb->mySqlModel->runProcces(ui->lineEditSettingsLrelease->text(), theProject, true, 60);
    if (mySqlDb->mySqlModel->getRunReturnCode() != 0)
    {
        mySqlDb->mySqlModel->mySetting->showMessageBox(QObject::tr("Error running lrelease").toLocal8Bit(), QString("%1: %2").arg(tr("Error running lrelease"), theLreleaseResult).toLocal8Bit(), mySqlDb->mySqlModel->mySetting->Critical);
    }
    ui->progressBarProjectsTranslations->hide();
    ui->progressBarProjectsFiles->hide();
    myLocalization->fileRemoveArgs();
    ui->statusbar->showMessage("");
} // end onCompile
/************************************************
 * @brief check Translation Errors.
 * checkTranslationErrors
 ***********************************************/
void MainWindow::setTranslationErrorType(const QString &thisTranslations)
{
    if (!myTranslationError.isEmpty())
    {
        if (thisTranslations.contains("Error transferring"))
        {
            // server replied: Too Many Requests, seems to happen with Arabic FIXME
            myTranslationErrorType = ErrorTransferring;
        }
        else if (thisTranslations.contains("Socket operation timed out"))
        {
            // Internet Down
            myTranslationErrorType = HostNotFound;
        }
        else if (thisTranslations.contains("Host www.bing.com not found"))
        {
            // Internet Down
            myTranslationErrorType = HostNotFound;
        }
        else if (thisTranslations.contains("Host translate.yandex.com not found"))
        {
            // Internet Down
            myTranslationErrorType = HostNotFound;
        }
        else if (thisTranslations.contains("Host translate.googleapis.com not found"))
        {
            // Internet Down
            myTranslationErrorType = HostNotFound;
        }
        else
        {
            myTranslationErrorType = NoError; // No Error Type detected, Log Critical
        }
    }
}
/************************************************
 * @brief check Translation Errors.
 * checkTranslationErrors
 ***********************************************/
QString MainWindow::checkTranslationErrors(const QString &thisTranslations, const QString &thisText, QOnlineTranslator::Engine thisEngine, QOnlineTranslator::Language thisTranslationLang, QOnlineTranslator::Language thisSourceLang, QOnlineTranslator::Language thisUiLang)
{
    if (isTranslationError) { setTranslationErrorType(thisTranslations); }
    switch (myTranslationErrorType)
    {
        case HostNotFound:
            mySqlDb->mySqlModel->mySetting->getInternetWait();
            myTranslation = translateWithReturn(thisText, thisEngine, thisTranslationLang, thisSourceLang, thisUiLang);
            break;
        case ErrorTransferring:
            // Increase delay, wait, and retry
            ui->spinBoxSettingsDelay->setValue(ui->spinBoxSettingsDelay->value() + myIncreameantValue);
            mySqlDb->mySqlModel->mySetting->delay(myDelayValue + myIncreameantValue);
            myTranslation = translateWithReturn(thisText, thisEngine, thisTranslationLang, thisSourceLang, thisUiLang);
            break;
        case NoError:
            qCritical() << "Translation Error not found: " << thisTranslations;
            myTranslation = thisTranslations;
            break;
    }
    return myTranslation;
}
/************************************************
 * @brief accept Translations.
 * acceptTranslations
 ***********************************************/
void MainWindow::acceptTranslations()
{
    const QStringList theTsFiles =  myLocalization->findTsFiles(ui->lineEditTranslationsSource->text());
    for (int i = 0; i < theTsFiles.size(); ++i)
    {
        if (!mySqlDb->mySqlModel->mySetting->isFileExists(theTsFiles.at(i)))
            { mySqlDb->mySqlModel->mySetting->showMessageBox(tr("Translation TS File not found"), QString("%1: %2").arg(tr("Translation TS File not found"), theTsFiles.at(i)), mySqlDb->mySqlModel->mySetting->Critical); }
        QString theFileContent = mySqlDb->mySqlModel->mySetting->readFile(theTsFiles.at(i));
        theFileContent.replace(QString(" type=\"unfinished\""), QString("")); // replace text in string
        mySqlDb->mySqlModel->mySetting->writeFile(theTsFiles.at(i), theFileContent);
    }
    ui->statusbar->showMessage(tr("Accepted all Translations"));
}
/************************************************
 * @brief translate Help files.
 * translateHelp
 ***********************************************/
void MainWindow::onTranslateHelp()
{
    myLingoJob.clear();
    myHelpTranslationsFiles.clear();
    myHelpFileNames.clear();
    myTranslationQrc.clear();
    QString theHelpPath = ui->lineEditTranslationsHelp->text();
    QDir dir(theHelpPath);
    QStringList theFileNames = dir.entryList(QStringList("*.md"), QDir::Files, QDir::Name);
    for (QString &theFileName : theFileNames)
    {
        QString theLangCode = myLocalization->getLangCode(theFileName);
        if (ui->labelTranslationsSourceLanguageCode->text() == theLangCode)
            { myHelpTranslationsFiles.append(dir.filePath(theFileName)); }
    }
    for (QString &fileName : myHelpTranslationsFiles)
    {
        QString theFileName = mySqlDb->mySqlModel->mySetting->getFileInfo(mySqlDb->mySqlModel->mySetting->BaseName, fileName);
        int theIndex = theFileName.indexOf("_");
        theFileName = theFileName.mid(0, theIndex);
        myHelpFileNames.append(theFileName);
    }
    //
    setProjectClass(TabAll);
    //
    createHelpTranslationJob("Afrikaans",           "af" ,      ui->checkBoxTranslationsAF->isChecked());
    createHelpTranslationJob("Albanian",            "sq" ,      ui->checkBoxTranslationsSQ->isChecked());
    createHelpTranslationJob("Amharic",             "am" ,      ui->checkBoxTranslationsAM->isChecked());
    createHelpTranslationJob("Arabic",              "ar" ,      ui->checkBoxTranslationsAR->isChecked());
    createHelpTranslationJob("Armenian",            "hy" ,      ui->checkBoxTranslationsHY->isChecked());
    createHelpTranslationJob("Azerbaijani",         "az" ,      ui->checkBoxTranslationsAZ->isChecked());
    createHelpTranslationJob("Bashkir",             "ba" ,      ui->checkBoxTranslationsBA->isChecked());
    createHelpTranslationJob("Basque",              "eu" ,      ui->checkBoxTranslationsEU->isChecked());
    createHelpTranslationJob("Belarusian",          "be" ,      ui->checkBoxTranslationsBE->isChecked());
    createHelpTranslationJob("Bengali",             "bn" ,      ui->checkBoxTranslationsBN->isChecked());
    createHelpTranslationJob("Bosnian",             "bs" ,      ui->checkBoxTranslationsBS->isChecked());
    createHelpTranslationJob("Bulgarian",           "bg" ,      ui->checkBoxTranslationsBG->isChecked());
    createHelpTranslationJob("Cantonese",           "yue",      ui->checkBoxTranslationsYO->isChecked());
    createHelpTranslationJob("Catalan",             "ca" ,      ui->checkBoxTranslationsCA->isChecked());
    createHelpTranslationJob("Cebuano",             "ceb",      ui->checkBoxTranslationsYO->isChecked());
    createHelpTranslationJob("Chichewa",            "ny" ,      ui->checkBoxTranslationsNY->isChecked());
    createHelpTranslationJob("Corsican",            "co" ,      ui->checkBoxTranslationsCO->isChecked());
    createHelpTranslationJob("Croatian",            "hr" ,      ui->checkBoxTranslationsHR->isChecked());
    createHelpTranslationJob("Czech",               "cs" ,      ui->checkBoxTranslationsCS->isChecked());
    createHelpTranslationJob("SimplifiedChinese",   "zh-CN" ,   ui->checkBoxTranslationsZH_CN->isChecked());
    createHelpTranslationJob("TraditionalChinese",  "zh-TW" ,   ui->checkBoxTranslationsZH_TW->isChecked());
    createHelpTranslationJob("Danish",              "da" ,      ui->checkBoxTranslationsDA->isChecked());
    createHelpTranslationJob("Dutch",               "nl" ,      ui->checkBoxTranslationsNL->isChecked());
    createHelpTranslationJob("English",             "en" ,      ui->checkBoxTranslationsEN->isChecked());
    createHelpTranslationJob("Estonian",            "et" ,      ui->checkBoxTranslationsET->isChecked());
    createHelpTranslationJob("Esperanto",           "eo" ,      ui->checkBoxTranslationsEO->isChecked());
    createHelpTranslationJob("Faeroese",            "fo" ,      ui->checkBoxTranslationsFO->isChecked());
    createHelpTranslationJob("Farsi",               "fa" ,      ui->checkBoxTranslationsFA->isChecked());
    createHelpTranslationJob("Fijian",              "fj" ,      ui->checkBoxTranslationsFJ->isChecked());
    createHelpTranslationJob("Filipino",            "fil",      ui->checkBoxTranslationsYO->isChecked());
    createHelpTranslationJob("Finnish",             "fi" ,      ui->checkBoxTranslationsFI->isChecked());
    createHelpTranslationJob("French",              "fr" ,      ui->checkBoxTranslationsFR->isChecked());
    createHelpTranslationJob("Frisian",             "fy" ,      ui->checkBoxTranslationsFY->isChecked());
    createHelpTranslationJob("Gaelic",              "gd" ,      ui->checkBoxTranslationsGD->isChecked());
    createHelpTranslationJob("Galician",            "gl" ,      ui->checkBoxTranslationsGL->isChecked());
    createHelpTranslationJob("Georgian",            "ka" ,      ui->checkBoxTranslationsKA->isChecked());
    createHelpTranslationJob("German",              "de" ,      ui->checkBoxTranslationsDE->isChecked());
    createHelpTranslationJob("Greek",               "el" ,      ui->checkBoxTranslationsEL->isChecked());
    createHelpTranslationJob("Gujarati",            "gu" ,      ui->checkBoxTranslationsGU->isChecked());
    createHelpTranslationJob("Haitian",             "ht" ,      ui->checkBoxTranslationsHT->isChecked());
    createHelpTranslationJob("Hausa",               "ha" ,      ui->checkBoxTranslationsHA->isChecked());
    createHelpTranslationJob("Hawaiian",            "haw",      ui->checkBoxTranslationsYO->isChecked());
    createHelpTranslationJob("Hebrew",              "he" ,      ui->checkBoxTranslationsHE->isChecked());
    createHelpTranslationJob("HillMari",            "mrj",      ui->checkBoxTranslationsYO->isChecked());
    createHelpTranslationJob("Hindi",               "hi" ,      ui->checkBoxTranslationsHI->isChecked());
    createHelpTranslationJob("Hmong",               "hmn",      ui->checkBoxTranslationsYO->isChecked());
    createHelpTranslationJob("Hungarian",           "hu" ,      ui->checkBoxTranslationsHU->isChecked());
    createHelpTranslationJob("Icelandic",           "is" ,      ui->checkBoxTranslationsIS->isChecked());
    createHelpTranslationJob("Igbo",                "ig" ,      ui->checkBoxTranslationsIG->isChecked());
    createHelpTranslationJob("Indonesian",          "id" ,      ui->checkBoxTranslationsID->isChecked());
    createHelpTranslationJob("Irish",               "ga" ,      ui->checkBoxTranslationsGA->isChecked());
    createHelpTranslationJob("Italian",             "it" ,      ui->checkBoxTranslationsIT->isChecked());
    createHelpTranslationJob("Japanese",            "ja" ,      ui->checkBoxTranslationsJA->isChecked());
    createHelpTranslationJob("Javanese",            "jw" ,      ui->checkBoxTranslationsJW->isChecked());
    createHelpTranslationJob("Kannada",             "kn" ,      ui->checkBoxTranslationsKN->isChecked());
    createHelpTranslationJob("Kazakh",              "kk" ,      ui->checkBoxTranslationsKK->isChecked());
    createHelpTranslationJob("Khmer",               "km" ,      ui->checkBoxTranslationsKM->isChecked());
    createHelpTranslationJob("Kinyarwanda",         "rw" ,      ui->checkBoxTranslationsRW->isChecked());
    createHelpTranslationJob("Klingon",             "tlh",      ui->checkBoxTranslationsYO->isChecked());
    createHelpTranslationJob("KlingonPlqaD",        "tlh-Qaak", ui->checkBoxTranslationsYO->isChecked());
    createHelpTranslationJob("Korean",              "ko" ,      ui->checkBoxTranslationsKO->isChecked());
    createHelpTranslationJob("Kurdish",             "ku" ,      ui->checkBoxTranslationsKU->isChecked());
    createHelpTranslationJob("Kyrgyz",              "ky" ,      ui->checkBoxTranslationsKY->isChecked());
    createHelpTranslationJob("Latvian",             "lv" ,      ui->checkBoxTranslationsLV->isChecked());
    createHelpTranslationJob("Lao",                 "lo" ,      ui->checkBoxTranslationsLO->isChecked());
    createHelpTranslationJob("Latin",               "la" ,      ui->checkBoxTranslationsLA->isChecked());
    createHelpTranslationJob("LevantineArabic",     "apc",      ui->checkBoxTranslationsYO->isChecked());
    createHelpTranslationJob("Lithuanian",          "lt" ,      ui->checkBoxTranslationsLT->isChecked());
    createHelpTranslationJob("Luxembourgish",       "lb" ,      ui->checkBoxTranslationsLB->isChecked());
    createHelpTranslationJob("Macedonian",          "mk" ,      ui->checkBoxTranslationsMK->isChecked());
    createHelpTranslationJob("Mari",                "mhr",      ui->checkBoxTranslationsYO->isChecked());
    createHelpTranslationJob("Maori",               "mi" ,      ui->checkBoxTranslationsMI->isChecked());
    createHelpTranslationJob("Marathi",             "mr" ,      ui->checkBoxTranslationsMR->isChecked());
    createHelpTranslationJob("Malagasy",            "mg" ,      ui->checkBoxTranslationsMG->isChecked());
    createHelpTranslationJob("Malayalam",           "ml" ,      ui->checkBoxTranslationsML->isChecked());
    createHelpTranslationJob("Malaysian",           "ms" ,      ui->checkBoxTranslationsMS->isChecked());
    createHelpTranslationJob("Maltese",             "mt" ,      ui->checkBoxTranslationsMT->isChecked());
    createHelpTranslationJob("Mongolian",           "mn" ,      ui->checkBoxTranslationsMN->isChecked());
    createHelpTranslationJob("Myanmar",             "my" ,      ui->checkBoxTranslationsMY->isChecked());
    createHelpTranslationJob("Norwegian",           "no" ,      ui->checkBoxTranslationsNO->isChecked());
    createHelpTranslationJob("Bokmal",              "nb" ,      ui->checkBoxTranslationsNB->isChecked());
    createHelpTranslationJob("Nepali",              "ne" ,      ui->checkBoxTranslationsNE->isChecked());
    createHelpTranslationJob("Nynorsk",             "nn" ,      ui->checkBoxTranslationsNN->isChecked());
    createHelpTranslationJob("Oriya",               "or" ,      ui->checkBoxTranslationsOR->isChecked());
    createHelpTranslationJob("Pashto",              "ps" ,      ui->checkBoxTranslationsPS->isChecked());
    createHelpTranslationJob("Papiamento",          "pap",      ui->checkBoxTranslationsYO->isChecked());
    createHelpTranslationJob("Polish",              "pl" ,      ui->checkBoxTranslationsPL->isChecked());
    createHelpTranslationJob("Portuguese",          "pt" ,      ui->checkBoxTranslationsPT->isChecked());
    createHelpTranslationJob("Punjabi",             "pa" ,      ui->checkBoxTranslationsPA->isChecked());
    createHelpTranslationJob("QueretaroOtomi",      "otq",      ui->checkBoxTranslationsYO->isChecked());
    createHelpTranslationJob("Rhaeto-Romanic",      "rm" ,      ui->checkBoxTranslationsRM->isChecked());
    createHelpTranslationJob("Romanian",            "ro" ,      ui->checkBoxTranslationsRO->isChecked());
    createHelpTranslationJob("Russian",             "ru" ,      ui->checkBoxTranslationsRU->isChecked());
    createHelpTranslationJob("Samoan",              "sm" ,      ui->checkBoxTranslationsSM->isChecked());
    createHelpTranslationJob("Serbian",             "sr" ,      ui->checkBoxTranslationsSR->isChecked());
    createHelpTranslationJob("SerbianLatin",        "sr-Latin", ui->checkBoxTranslationsYO->isChecked());
    createHelpTranslationJob("Slovak",              "sk" ,      ui->checkBoxTranslationsSK->isChecked());
    createHelpTranslationJob("Slovenian",           "sl" ,      ui->checkBoxTranslationsSL->isChecked());
    createHelpTranslationJob("Sesotho",             "st" ,      ui->checkBoxTranslationsST->isChecked());
    createHelpTranslationJob("Shona",               "sn" ,      ui->checkBoxTranslationsSN->isChecked());
    createHelpTranslationJob("Sindhi",              "sd" ,      ui->checkBoxTranslationsSD->isChecked());
    createHelpTranslationJob("Sinhala",             "si" ,      ui->checkBoxTranslationsSI->isChecked());
    createHelpTranslationJob("Somali",              "so" ,      ui->checkBoxTranslationsSO->isChecked());
    createHelpTranslationJob("Sorbian",             "sb" ,      ui->checkBoxTranslationsSB->isChecked());
    createHelpTranslationJob("Spanish",             "es" ,      ui->checkBoxTranslationsES->isChecked());
    createHelpTranslationJob("Sundanese",           "su" ,      ui->checkBoxTranslationsSU->isChecked());
    createHelpTranslationJob("Swahili",             "sw" ,      ui->checkBoxTranslationsSW->isChecked());
    createHelpTranslationJob("Swedish",             "sv" ,      ui->checkBoxTranslationsSV->isChecked());
    createHelpTranslationJob("Tagalog",             "tl" ,      ui->checkBoxTranslationsTL->isChecked());
    createHelpTranslationJob("Tahitian",            "ty" ,      ui->checkBoxTranslationsTY->isChecked());
    createHelpTranslationJob("Tajik",               "tg" ,      ui->checkBoxTranslationsTG->isChecked());
    createHelpTranslationJob("Tamil",               "ta" ,      ui->checkBoxTranslationsTA->isChecked());
    createHelpTranslationJob("Tatar",               "tt" ,      ui->checkBoxTranslationsTT->isChecked());
    createHelpTranslationJob("Telugu",              "te" ,      ui->checkBoxTranslationsTE->isChecked());
    createHelpTranslationJob("Thai",                "th" ,      ui->checkBoxTranslationsTH->isChecked());
    createHelpTranslationJob("Tongan",              "to" ,      ui->checkBoxTranslationsTO->isChecked());
    createHelpTranslationJob("Tsonga",              "ts" ,      ui->checkBoxTranslationsTS->isChecked());
    createHelpTranslationJob("Tswana",              "tn" ,      ui->checkBoxTranslationsTN->isChecked());
    createHelpTranslationJob("Turkish",             "tr" ,      ui->checkBoxTranslationsTR->isChecked());
    createHelpTranslationJob("Turkmen",             "tk" ,      ui->checkBoxTranslationsTK->isChecked());
    createHelpTranslationJob("Uighur",              "ub" ,      ui->checkBoxTranslationsUG->isChecked());
    createHelpTranslationJob("Ukrainian",           "uk" ,      ui->checkBoxTranslationsUK->isChecked());
    createHelpTranslationJob("Urdu",                "ur" ,      ui->checkBoxTranslationsUR->isChecked());
    createHelpTranslationJob("Udmurt",              "udm",      ui->checkBoxTranslationsYO->isChecked());
    createHelpTranslationJob("Uzbek",               "uz" ,      ui->checkBoxTranslationsUZ->isChecked());
    createHelpTranslationJob("Venda",               "ve" ,      ui->checkBoxTranslationsVE->isChecked());
    createHelpTranslationJob("Vietnamese",          "vi" ,      ui->checkBoxTranslationsVI->isChecked());
    createHelpTranslationJob("Welsh",               "cy" ,      ui->checkBoxTranslationsCY->isChecked());
    createHelpTranslationJob("Xhosa",               "xh" ,      ui->checkBoxTranslationsXH->isChecked());
    createHelpTranslationJob("Yiddish",             "yi" ,      ui->checkBoxTranslationsYI->isChecked());
    createHelpTranslationJob("Yoruba",              "yo" ,      ui->checkBoxTranslationsYO->isChecked());
    createHelpTranslationJob("YucatecMaya",         "yua",      ui->checkBoxTranslationsYO->isChecked());
    createHelpTranslationJob("Zulu",                "zu" ,      ui->checkBoxTranslationsZU->isChecked());
    //
    ui->textEditProjects->setText(QString("%1\n").arg(myTranslationQrc));
    // Go to Tab
    ui->tabWidget->setCurrentIndex(ui->tabWidget->indexOf(ui->tabWidget->findChild<QWidget*>("tabProject")));
    //
    ui->progressBarProjectsTranslations->setMaximum(myLingoJob.count());
    ui->progressBarProjectsTranslations->setValue(0);
    ui->progressBarProjectsTranslations->show();
    ui->progressBarProjectsFiles->setMaximum(myLingoJob.count());
    ui->progressBarProjectsFiles->show();
    /*
     * Now I can run the job with myLingoJob
     * Every Language has a Help_xx.md
    */
    for( int i = 0; i < myLingoJob.count(); ++i )
    {
        ui->progressBarProjectsFiles->setValue(i);
        if (isDebugMessage && isMainLoaded) { qDebug() << "Translating..." << myLingoJob.at(i).getLanguageName(); }
        // Skip if current language is the same as source
        if (myLingoJob.at(i).getLanguageName() == ui->comboBoxTranslationSourceLanguage->currentText()) { continue; }
        QString theHelpFile = myLingoJob.at(i).getTsFile();
        // Make sure Source file exists
        if (!mySqlDb->mySqlModel->mySetting->isFileExists(theHelpFile))
        {
            mySqlDb->mySqlModel->mySetting->showMessageBox(tr("Help File not found"), QString("%1: %2").arg(tr("Help File not found"), myLingoJob.at(i).getTsFile()), mySqlDb->mySqlModel->mySetting->Critical);
            return;
        }
        QString theHelpFileContents = mySqlDb->mySqlModel->mySetting->readFile(theHelpFile);
        if (theHelpFileContents.isEmpty())
        {
            mySqlDb->mySqlModel->mySetting->showMessageBox(tr("Help File is Empty"), QString("%1: %2").arg(tr("Help File is Empty"), myLingoJob.at(i).getTsFile()), mySqlDb->mySqlModel->mySetting->Critical);
            return;
        }
        // QString &text, Engine engine, Language translationLang, Language sourceLang, Language uiLang
        myTranslation = translateWithReturn(theHelpFileContents, QOnlineTranslator::Engine::Google, myLingoJob.at(i).getLang(), myLingoJob.at(i).getSourceLang(), myQOnlineTranslator.language(QLocale()));
        myTranslation = checkTranslationErrors(myTranslation, theHelpFileContents, QOnlineTranslator::Engine::Google, myLingoJob.at(i).getLang(), myLingoJob.at(i).getSourceLang(), myQOnlineTranslator.language(QLocale()));
        // if empty use another service
        if (myTranslation.isEmpty())
        {
            myTranslation = translateWithReturn(theHelpFileContents, QOnlineTranslator::Engine::Bing, myLingoJob.at(i).getLang(), myLingoJob.at(i).getSourceLang(), myQOnlineTranslator.language(QLocale()));
            myTranslation = checkTranslationErrors(myTranslation, theHelpFileContents, QOnlineTranslator::Engine::Google, myLingoJob.at(i).getLang(), myLingoJob.at(i).getSourceLang(), myQOnlineTranslator.language(QLocale()));
            if (myTranslation.isEmpty())
            {
                myTranslation = translateWithReturn(theHelpFileContents, QOnlineTranslator::Engine::Yandex, myLingoJob.at(i).getLang(), myLingoJob.at(i).getSourceLang(), myQOnlineTranslator.language(QLocale()));
                myTranslation = checkTranslationErrors(myTranslation, theHelpFileContents, QOnlineTranslator::Engine::Google, myLingoJob.at(i).getLang(), myLingoJob.at(i).getSourceLang(), myQOnlineTranslator.language(QLocale()));
            }
        }
        // Make sure Translation string has content
        if (myTranslation.isEmpty()) { myTranslation = theHelpFileContents; }
        mySqlDb->mySqlModel->mySetting->writeFile(myLingoJob.at(i).getDestinationFile(), myTranslation);
        if (!mySqlDb->mySqlModel->mySetting->isFileExists(myLingoJob.at(i).getDestinationFile()))
        {
            mySqlDb->mySqlModel->mySetting->showMessageBox(tr("Help File could not be created"), QString("%1: %2").arg(tr("Help File could not be created"), myLingoJob.at(i).getTsFile()), mySqlDb->mySqlModel->mySetting->Critical);
            return;
        }
        ui->statusbar->showMessage(QString("%1: %2 = %3").arg(myLingoJob.at(i).getLanguageName(), theHelpFileContents.mid(0, 16), myTranslation));
        // Set a delay or you will be ban from Engine
        mySqlDb->mySqlModel->mySetting->delay(ui->spinBoxSettingsDelay->value());
        // Set a delay or you will be ban from Engine
        mySqlDb->mySqlModel->mySetting->delay(ui->spinBoxSettingsDelay->value());
        ui->progressBarProjectsTranslations->setValue(i);
    } // end for( int i = 0; i < myLingoJob.count(); ++i )
    ui->progressBarProjectsTranslations->hide();
    ui->progressBarProjectsFiles->hide();
    ui->statusbar->showMessage("");
} // end translateHelp
/************************************************
 * @brief translate ReadMe.
 * onTranslateReadMe
 ***********************************************/
void MainWindow::onTranslateReadMe()
{
    myLingoJob.clear();
    myHelpTranslationsFiles.clear();
    myHelpFileNames.clear();
    myTranslationQrc.clear();
    //
    setProjectClass(TabAll);
    //
    createReadMeTranslationJob("Afrikaans",           "af" ,      ui->checkBoxTranslationsAF->isChecked());
    createReadMeTranslationJob("Albanian",            "sq" ,      ui->checkBoxTranslationsSQ->isChecked());
    createReadMeTranslationJob("Amharic",             "am" ,      ui->checkBoxTranslationsAM->isChecked());
    createReadMeTranslationJob("Arabic",              "ar" ,      ui->checkBoxTranslationsAR->isChecked());
    createReadMeTranslationJob("Armenian",            "hy" ,      ui->checkBoxTranslationsHY->isChecked());
    createReadMeTranslationJob("Azerbaijani",         "az" ,      ui->checkBoxTranslationsAZ->isChecked());
    createReadMeTranslationJob("Bashkir",             "ba" ,      ui->checkBoxTranslationsBA->isChecked());
    createReadMeTranslationJob("Basque",              "eu" ,      ui->checkBoxTranslationsEU->isChecked());
    createReadMeTranslationJob("Belarusian",          "be" ,      ui->checkBoxTranslationsBE->isChecked());
    createReadMeTranslationJob("Bengali",             "bn" ,      ui->checkBoxTranslationsBN->isChecked());
    createReadMeTranslationJob("Bosnian",             "bs" ,      ui->checkBoxTranslationsBS->isChecked());
    createReadMeTranslationJob("Bulgarian",           "bg" ,      ui->checkBoxTranslationsBG->isChecked());
    createReadMeTranslationJob("Cantonese",           "yue",      ui->checkBoxTranslationsYO->isChecked());
    createReadMeTranslationJob("Catalan",             "ca" ,      ui->checkBoxTranslationsCA->isChecked());
    createReadMeTranslationJob("Cebuano",             "ceb",      ui->checkBoxTranslationsYO->isChecked());
    createReadMeTranslationJob("Chichewa",            "ny" ,      ui->checkBoxTranslationsNY->isChecked());
    createReadMeTranslationJob("Corsican",            "co" ,      ui->checkBoxTranslationsCO->isChecked());
    createReadMeTranslationJob("Croatian",            "hr" ,      ui->checkBoxTranslationsHR->isChecked());
    createReadMeTranslationJob("Czech",               "cs" ,      ui->checkBoxTranslationsCS->isChecked());
    createReadMeTranslationJob("SimplifiedChinese",   "zh-CN" ,   ui->checkBoxTranslationsZH_CN->isChecked());
    createReadMeTranslationJob("TraditionalChinese",  "zh-TW" ,   ui->checkBoxTranslationsZH_TW->isChecked());
    createReadMeTranslationJob("Danish",              "da" ,      ui->checkBoxTranslationsDA->isChecked());
    createReadMeTranslationJob("Dutch",               "nl" ,      ui->checkBoxTranslationsNL->isChecked());
    createReadMeTranslationJob("English",             "en" ,      ui->checkBoxTranslationsEN->isChecked());
    createReadMeTranslationJob("Estonian",            "et" ,      ui->checkBoxTranslationsET->isChecked());
    createReadMeTranslationJob("Esperanto",           "eo" ,      ui->checkBoxTranslationsEO->isChecked());
    createReadMeTranslationJob("Faeroese",            "fo" ,      ui->checkBoxTranslationsFO->isChecked());
    createReadMeTranslationJob("Farsi",               "fa" ,      ui->checkBoxTranslationsFA->isChecked());
    createReadMeTranslationJob("Fijian",              "fj" ,      ui->checkBoxTranslationsFJ->isChecked());
    createReadMeTranslationJob("Filipino",            "fil",      ui->checkBoxTranslationsYO->isChecked());
    createReadMeTranslationJob("Finnish",             "fi" ,      ui->checkBoxTranslationsFI->isChecked());
    createReadMeTranslationJob("French",              "fr" ,      ui->checkBoxTranslationsFR->isChecked());
    createReadMeTranslationJob("Frisian",             "fy" ,      ui->checkBoxTranslationsFY->isChecked());
    createReadMeTranslationJob("Gaelic",              "gd" ,      ui->checkBoxTranslationsGD->isChecked());
    createReadMeTranslationJob("Galician",            "gl" ,      ui->checkBoxTranslationsGL->isChecked());
    createReadMeTranslationJob("Georgian",            "ka" ,      ui->checkBoxTranslationsKA->isChecked());
    createReadMeTranslationJob("German",              "de" ,      ui->checkBoxTranslationsDE->isChecked());
    createReadMeTranslationJob("Greek",               "el" ,      ui->checkBoxTranslationsEL->isChecked());
    createReadMeTranslationJob("Gujarati",            "gu" ,      ui->checkBoxTranslationsGU->isChecked());
    createReadMeTranslationJob("Haitian",             "ht" ,      ui->checkBoxTranslationsHT->isChecked());
    createReadMeTranslationJob("Hausa",               "ha" ,      ui->checkBoxTranslationsHA->isChecked());
    createReadMeTranslationJob("Hawaiian",            "haw",      ui->checkBoxTranslationsYO->isChecked());
    createReadMeTranslationJob("Hebrew",              "he" ,      ui->checkBoxTranslationsHE->isChecked());
    createReadMeTranslationJob("HillMari",            "mrj",      ui->checkBoxTranslationsYO->isChecked());
    createReadMeTranslationJob("Hindi",               "hi" ,      ui->checkBoxTranslationsHI->isChecked());
    createReadMeTranslationJob("Hmong",               "hmn",      ui->checkBoxTranslationsYO->isChecked());
    createReadMeTranslationJob("Hungarian",           "hu" ,      ui->checkBoxTranslationsHU->isChecked());
    createReadMeTranslationJob("Icelandic",           "is" ,      ui->checkBoxTranslationsIS->isChecked());
    createReadMeTranslationJob("Igbo",                "ig" ,      ui->checkBoxTranslationsIG->isChecked());
    createReadMeTranslationJob("Indonesian",          "id" ,      ui->checkBoxTranslationsID->isChecked());
    createReadMeTranslationJob("Irish",               "ga" ,      ui->checkBoxTranslationsGA->isChecked());
    createReadMeTranslationJob("Italian",             "it" ,      ui->checkBoxTranslationsIT->isChecked());
    createReadMeTranslationJob("Japanese",            "ja" ,      ui->checkBoxTranslationsJA->isChecked());
    createReadMeTranslationJob("Javanese",            "jw" ,      ui->checkBoxTranslationsJW->isChecked());
    createReadMeTranslationJob("Kannada",             "kn" ,      ui->checkBoxTranslationsKN->isChecked());
    createReadMeTranslationJob("Kazakh",              "kk" ,      ui->checkBoxTranslationsKK->isChecked());
    createReadMeTranslationJob("Khmer",               "km" ,      ui->checkBoxTranslationsKM->isChecked());
    createReadMeTranslationJob("Kinyarwanda",         "rw" ,      ui->checkBoxTranslationsRW->isChecked());
    createReadMeTranslationJob("Klingon",             "tlh",      ui->checkBoxTranslationsYO->isChecked());
    createReadMeTranslationJob("KlingonPlqaD",        "tlh-Qaak", ui->checkBoxTranslationsYO->isChecked());
    createReadMeTranslationJob("Korean",              "ko" ,      ui->checkBoxTranslationsKO->isChecked());
    createReadMeTranslationJob("Kurdish",             "ku" ,      ui->checkBoxTranslationsKU->isChecked());
    createReadMeTranslationJob("Kyrgyz",              "ky" ,      ui->checkBoxTranslationsKY->isChecked());
    createReadMeTranslationJob("Latvian",             "lv" ,      ui->checkBoxTranslationsLV->isChecked());
    createReadMeTranslationJob("Lao",                 "lo" ,      ui->checkBoxTranslationsLO->isChecked());
    createReadMeTranslationJob("Latin",               "la" ,      ui->checkBoxTranslationsLA->isChecked());
    createReadMeTranslationJob("LevantineArabic",     "apc",      ui->checkBoxTranslationsYO->isChecked());
    createReadMeTranslationJob("Lithuanian",          "lt" ,      ui->checkBoxTranslationsLT->isChecked());
    createReadMeTranslationJob("Luxembourgish",       "lb" ,      ui->checkBoxTranslationsLB->isChecked());
    createReadMeTranslationJob("Macedonian",          "mk" ,      ui->checkBoxTranslationsMK->isChecked());
    createReadMeTranslationJob("Mari",                "mhr",      ui->checkBoxTranslationsYO->isChecked());
    createReadMeTranslationJob("Maori",               "mi" ,      ui->checkBoxTranslationsMI->isChecked());
    createReadMeTranslationJob("Marathi",             "mr" ,      ui->checkBoxTranslationsMR->isChecked());
    createReadMeTranslationJob("Malagasy",            "mg" ,      ui->checkBoxTranslationsMG->isChecked());
    createReadMeTranslationJob("Malayalam",           "ml" ,      ui->checkBoxTranslationsML->isChecked());
    createReadMeTranslationJob("Malaysian",           "ms" ,      ui->checkBoxTranslationsMS->isChecked());
    createReadMeTranslationJob("Maltese",             "mt" ,      ui->checkBoxTranslationsMT->isChecked());
    createReadMeTranslationJob("Mongolian",           "mn" ,      ui->checkBoxTranslationsMN->isChecked());
    createReadMeTranslationJob("Myanmar",             "my" ,      ui->checkBoxTranslationsMY->isChecked());
    createReadMeTranslationJob("Norwegian",           "no" ,      ui->checkBoxTranslationsNO->isChecked());
    createReadMeTranslationJob("Bokmal",              "nb" ,      ui->checkBoxTranslationsNB->isChecked());
    createReadMeTranslationJob("Nepali",              "ne" ,      ui->checkBoxTranslationsNE->isChecked());
    createReadMeTranslationJob("Nynorsk",             "nn" ,      ui->checkBoxTranslationsNN->isChecked());
    createReadMeTranslationJob("Oriya",               "or" ,      ui->checkBoxTranslationsOR->isChecked());
    createReadMeTranslationJob("Pashto",              "ps" ,      ui->checkBoxTranslationsPS->isChecked());
    createReadMeTranslationJob("Papiamento",          "pap",      ui->checkBoxTranslationsYO->isChecked());
    createReadMeTranslationJob("Polish",              "pl" ,      ui->checkBoxTranslationsPL->isChecked());
    createReadMeTranslationJob("Portuguese",          "pt" ,      ui->checkBoxTranslationsPT->isChecked());
    createReadMeTranslationJob("Punjabi",             "pa" ,      ui->checkBoxTranslationsPA->isChecked());
    createReadMeTranslationJob("QueretaroOtomi",      "otq",      ui->checkBoxTranslationsYO->isChecked());
    createReadMeTranslationJob("Rhaeto-Romanic",      "rm" ,      ui->checkBoxTranslationsRM->isChecked());
    createReadMeTranslationJob("Romanian",            "ro" ,      ui->checkBoxTranslationsRO->isChecked());
    createReadMeTranslationJob("Russian",             "ru" ,      ui->checkBoxTranslationsRU->isChecked());
    createReadMeTranslationJob("Samoan",              "sm" ,      ui->checkBoxTranslationsSM->isChecked());
    createReadMeTranslationJob("Serbian",             "sr" ,      ui->checkBoxTranslationsSR->isChecked());
    createReadMeTranslationJob("SerbianLatin",        "sr-Latin", ui->checkBoxTranslationsYO->isChecked());
    createReadMeTranslationJob("Slovak",              "sk" ,      ui->checkBoxTranslationsSK->isChecked());
    createReadMeTranslationJob("Slovenian",           "sl" ,      ui->checkBoxTranslationsSL->isChecked());
    createReadMeTranslationJob("Sesotho",             "st" ,      ui->checkBoxTranslationsST->isChecked());
    createReadMeTranslationJob("Shona",               "sn" ,      ui->checkBoxTranslationsSN->isChecked());
    createReadMeTranslationJob("Sindhi",              "sd" ,      ui->checkBoxTranslationsSD->isChecked());
    createReadMeTranslationJob("Sinhala",             "si" ,      ui->checkBoxTranslationsSI->isChecked());
    createReadMeTranslationJob("Somali",              "so" ,      ui->checkBoxTranslationsSO->isChecked());
    createReadMeTranslationJob("Sorbian",             "sb" ,      ui->checkBoxTranslationsSB->isChecked());
    createReadMeTranslationJob("Spanish",             "es" ,      ui->checkBoxTranslationsES->isChecked());
    createReadMeTranslationJob("Sundanese",           "su" ,      ui->checkBoxTranslationsSU->isChecked());
    createReadMeTranslationJob("Swahili",             "sw" ,      ui->checkBoxTranslationsSW->isChecked());
    createReadMeTranslationJob("Swedish",             "sv" ,      ui->checkBoxTranslationsSV->isChecked());
    createReadMeTranslationJob("Tagalog",             "tl" ,      ui->checkBoxTranslationsTL->isChecked());
    createReadMeTranslationJob("Tahitian",            "ty" ,      ui->checkBoxTranslationsTY->isChecked());
    createReadMeTranslationJob("Tajik",               "tg" ,      ui->checkBoxTranslationsTG->isChecked());
    createReadMeTranslationJob("Tamil",               "ta" ,      ui->checkBoxTranslationsTA->isChecked());
    createReadMeTranslationJob("Tatar",               "tt" ,      ui->checkBoxTranslationsTT->isChecked());
    createReadMeTranslationJob("Telugu",              "te" ,      ui->checkBoxTranslationsTE->isChecked());
    createReadMeTranslationJob("Thai",                "th" ,      ui->checkBoxTranslationsTH->isChecked());
    createReadMeTranslationJob("Tongan",              "to" ,      ui->checkBoxTranslationsTO->isChecked());
    createReadMeTranslationJob("Tsonga",              "ts" ,      ui->checkBoxTranslationsTS->isChecked());
    createReadMeTranslationJob("Tswana",              "tn" ,      ui->checkBoxTranslationsTN->isChecked());
    createReadMeTranslationJob("Turkish",             "tr" ,      ui->checkBoxTranslationsTR->isChecked());
    createReadMeTranslationJob("Turkmen",             "tk" ,      ui->checkBoxTranslationsTK->isChecked());
    createReadMeTranslationJob("Uighur",              "ub" ,      ui->checkBoxTranslationsUG->isChecked());
    createReadMeTranslationJob("Ukrainian",           "uk" ,      ui->checkBoxTranslationsUK->isChecked());
    createReadMeTranslationJob("Urdu",                "ur" ,      ui->checkBoxTranslationsUR->isChecked());
    createReadMeTranslationJob("Udmurt",              "udm",      ui->checkBoxTranslationsYO->isChecked());
    createReadMeTranslationJob("Uzbek",               "uz" ,      ui->checkBoxTranslationsUZ->isChecked());
    createReadMeTranslationJob("Venda",               "ve" ,      ui->checkBoxTranslationsVE->isChecked());
    createReadMeTranslationJob("Vietnamese",          "vi" ,      ui->checkBoxTranslationsVI->isChecked());
    createReadMeTranslationJob("Welsh",               "cy" ,      ui->checkBoxTranslationsCY->isChecked());
    createReadMeTranslationJob("Xhosa",               "xh" ,      ui->checkBoxTranslationsXH->isChecked());
    createReadMeTranslationJob("Yiddish",             "yi" ,      ui->checkBoxTranslationsYI->isChecked());
    createReadMeTranslationJob("Yoruba",              "yo" ,      ui->checkBoxTranslationsYO->isChecked());
    createReadMeTranslationJob("YucatecMaya",         "yua",      ui->checkBoxTranslationsYO->isChecked());
    createReadMeTranslationJob("Zulu",                "zu" ,      ui->checkBoxTranslationsZU->isChecked());
    // Read Me
    QString theReadMeFile = QString("%1%2%3").arg(ui->lineEditTranslationsProjectFolder->text(), QDir::separator(), "README.md");
    //
    ui->textEditProjects->setText(QString("%1\n").arg(myTranslationQrc));
    // Go to Tab
    ui->tabWidget->setCurrentIndex(ui->tabWidget->indexOf(ui->tabWidget->findChild<QWidget*>("tabProject")));
    //
    ui->progressBarProjectsTranslations->setMaximum(myLingoJob.count());
    ui->progressBarProjectsTranslations->setValue(0);
    ui->progressBarProjectsTranslations->show();
    ui->progressBarProjectsFiles->setMaximum(myLingoJob.count());
    ui->progressBarProjectsFiles->show();
    /*
     * Now I can run the job with myLingoJob
     * Every Language has a Help_xx.md and README_xx.md
     * I mixed them in one Job and alternate between them.
    */
    for( int i = 0; i < myLingoJob.count(); ++i )
    {
        ui->progressBarProjectsFiles->setValue(i);
        if (isDebugMessage && isMainLoaded) { qDebug() << "Translating..." << myLingoJob.at(i).getLanguageName(); }
        // Skip if current language is the same as source
        if (myLingoJob.at(i).getLanguageName() == ui->comboBoxTranslationSourceLanguage->currentText()) { continue; }
        // The Default Languge will not have an under-score Language Code, i.e. README.md
        if (!myLingoJob.at(i).getReadMe().contains("_")) { continue; }
        // Make sure Source file exists
        if (!mySqlDb->mySqlModel->mySetting->isFileExists(theReadMeFile))
        {
            mySqlDb->mySqlModel->mySetting->showMessageBox(tr("README File not found"), QString("%1: %2").arg(tr("README File not found"), myLingoJob.at(i).getReadMe()), mySqlDb->mySqlModel->mySetting->Critical);
            return;
        }
        QString theReadMeFileContents = mySqlDb->mySqlModel->mySetting->readFile(theReadMeFile);
        if (theReadMeFileContents.isEmpty())
        {
            mySqlDb->mySqlModel->mySetting->showMessageBox(tr("README File is Empty"), QString("%1: %2").arg(tr("README File is Empty"), myLingoJob.at(i).getReadMe()), mySqlDb->mySqlModel->mySetting->Critical);
            return;
        }
        // QString &text, Engine engine, Language translationLang, Language sourceLang, Language uiLang
        myTranslation = translateWithReturn(theReadMeFileContents, QOnlineTranslator::Engine::Google, myLingoJob.at(i).getLang(), myLingoJob.at(i).getSourceLang(), myQOnlineTranslator.language(QLocale()));
        myTranslation = checkTranslationErrors(myTranslation, theReadMeFileContents, QOnlineTranslator::Engine::Google, myLingoJob.at(i).getLang(), myLingoJob.at(i).getSourceLang(), myQOnlineTranslator.language(QLocale()));
        // if empty use another service
        if (myTranslation.isEmpty())
        {
            myTranslation = translateWithReturn(theReadMeFileContents, QOnlineTranslator::Engine::Bing, myLingoJob.at(i).getLang(), myLingoJob.at(i).getSourceLang(), myQOnlineTranslator.language(QLocale()));
            myTranslation = checkTranslationErrors(myTranslation, theReadMeFileContents, QOnlineTranslator::Engine::Google, myLingoJob.at(i).getLang(), myLingoJob.at(i).getSourceLang(), myQOnlineTranslator.language(QLocale()));
            if (myTranslation.isEmpty())
            {
                myTranslation = translateWithReturn(theReadMeFileContents, QOnlineTranslator::Engine::Yandex, myLingoJob.at(i).getLang(), myLingoJob.at(i).getSourceLang(), myQOnlineTranslator.language(QLocale()));
                myTranslation = checkTranslationErrors(myTranslation, theReadMeFileContents, QOnlineTranslator::Engine::Google, myLingoJob.at(i).getLang(), myLingoJob.at(i).getSourceLang(), myQOnlineTranslator.language(QLocale()));
            }
        }
        // Make sure Translation string has content
        if (myTranslation.isEmpty()) { myTranslation = theReadMeFileContents; }
        mySqlDb->mySqlModel->mySetting->writeFile(myLingoJob.at(i).getReadMe(), myTranslation);
        if (!mySqlDb->mySqlModel->mySetting->isFileExists(myLingoJob.at(i).getReadMe()))
        {
            mySqlDb->mySqlModel->mySetting->showMessageBox(tr("README File could not be created"), QString("%1: %2").arg(tr("README File could not be created"), myLingoJob.at(i).getReadMe()), mySqlDb->mySqlModel->mySetting->Critical);
            return;
        }
        ui->statusbar->showMessage(QString("%1: %2 = %3").arg(myLingoJob.at(i).getLanguageName(), theReadMeFileContents.mid(0, 16), myTranslation));
        // Set a delay or you will be ban from Engine
        mySqlDb->mySqlModel->mySetting->delay(ui->spinBoxSettingsDelay->value());
        ui->progressBarProjectsTranslations->setValue(i);
    } // end for( int i = 0; i < myLingoJob.count(); ++i )
    ui->progressBarProjectsTranslations->hide();
    ui->progressBarProjectsFiles->hide();
    ui->statusbar->showMessage("");
} // end translateReadMe
/************************************************
 * @brief create Translation Job, I pass in the Name of the Language,
 *        and the language ID, I do not use the Name, but find it nice to have the info with it.
 * createTranslationJob
 ***********************************************/
void MainWindow::createTranslationJob(const QString &thisLanguageName, const QString &thisLanguage, const QString &thisSourceLanguage, bool thisChecked)
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "createTranslationJob(" << thisLanguageName << ", " << thisLanguage << ", " << thisSourceLanguage << ", " << thisChecked << ")"; }
    //
    if (!thisChecked) { return; }
    QString theLang = thisLanguage;
    theLang = theLang.replace("-", "_");
    // Create Translation file names for configuration
    QString theTsFile = QString("%1%2%3%4%5%6").arg(ui->lineEditTranslationsSource->text(), QDir::separator(), ui->lineEditSettingsQtProjectName->text(), "_", theLang, ".ts");
    QString theQmFile = QString("%1%2%3%4%5%6").arg(ui->lineEditTranslationsSource->text(), QDir::separator(), ui->lineEditSettingsQtProjectName->text(), "_", theLang, ".qm");
    //
    QString theTransFile = theTsFile;
    QString theTransQmFile = theQmFile;
    theTransFile.remove(ui->lineEditTranslationsProjectFolder->text());
    theTransQmFile.remove(ui->lineEditTranslationsProjectFolder->text());
    if (theTransFile.mid(0, 1)   == "/" || theTransFile.mid(0, 1)   == "\\") { theTransFile = theTransFile.mid(1); }
    if (theTransQmFile.mid(0, 1) == "/" || theTransQmFile.mid(0, 1) == "\\") { theTransQmFile = theTransQmFile.mid(1); }
    myTranslationConf.append(QString(" %1").arg(theTransFile));
    myTranslationQrc.append(QString("<file>%1</file>\n").arg(theTransQmFile));
    // Create Job
    // to store a job I need the theSourcePath and Language
    MyLingoJobs theTranslationJobs(thisLanguageName, thisLanguage, theTsFile, theTransQmFile, "", QOnlineTranslator::language(thisLanguage), QOnlineTranslator::language(myLocalization->languageNameToCode(thisSourceLanguage)));
    myLingoJob.append(theTranslationJobs);
}
/************************************************
 * @brief translate With Return Added by Light-Wizzard.
 * translateWithReturn
 ***********************************************/
void MainWindow::createHelpTranslationJob(const QString &thisLanguageName, const QString &theLangCode, bool thisChecked)
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "createHelpTranslationJob(" << thisLanguageName << ", " << theLangCode << ", " << thisChecked << ")"; }
    //
    if (!thisChecked) { return; }
    if (ui->labelTranslationsSourceLanguageCode->text() == theLangCode) { return; }
    //
    for (QString &theFileName : myHelpFileNames)
    {
        // Create Translation file names for configuration
        QString theMdFile     = QString("%1%2%3%4%5%6").arg(ui->lineEditTranslationsHelp->text(), QDir::separator(), theFileName, "_", theLangCode, ".md");
        QString theQmFile     = QString("%1%2%3%4%5%6").arg(ui->lineEditTranslationsHelp->text(), QDir::separator(), theFileName, "_", theLangCode, ".qm");
        // ReadMe
        QString theHelpSource = QString("%1%2%3%4%5%6").arg(ui->lineEditTranslationsHelp->text(), QDir::separator(), theFileName, "_", ui->labelTranslationsSourceLanguageCode->text(), ".md");
        QString theReadMeFile = QString("%1%2%3%4%5%6").arg(ui->lineEditTranslationsProjectFolder->text(), QDir::separator(), "README", "_", theLangCode, ".md");
        //
        QString theTransQmFile = theQmFile;
        theTransQmFile.remove(ui->lineEditTranslationsProjectFolder->text());
        if (theTransQmFile.mid(0, 1) == "/" || theTransQmFile.mid(0, 1) == "\\") { theTransQmFile = theTransQmFile.mid(1); }
        // for display
        if (!myTranslationQrc.contains(theTransQmFile))
        {
            myTranslationQrc.append(QString("<file>%1</file>\n").arg(theTransQmFile));
        }
        // Create Job
        // to store a job I need the theSourcePath and Language
        MyLingoJobs theTranslationJobs(thisLanguageName, theLangCode, theHelpSource, theMdFile, theReadMeFile, QOnlineTranslator::language(theLangCode), QOnlineTranslator::language(ui->labelTranslationsSourceLanguageCode->text()));
        myLingoJob.append(theTranslationJobs);
    }
}
/************************************************
 * @brief translate With Return Added by Light-Wizzard.
 * translateWithReturn
 ***********************************************/
void MainWindow::createReadMeTranslationJob(const QString &thisLanguageName, const QString &theLangCode, bool thisChecked)
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "createHelpTranslationJob(" << thisLanguageName << ", " << theLangCode << ", " << thisChecked << ")"; }
    //
    if (!thisChecked) { return; }
    if (ui->labelTranslationsSourceLanguageCode->text() == theLangCode) { return; }
    //
    // Create Translation file names for configuration
    QString theFileName = "README";
    QString theMdFile     = QString("%1%2%3%4%5%6").arg(ui->lineEditTranslationsHelp->text(), QDir::separator(), theFileName, "_", theLangCode, ".md");
    QString theQmFile     = QString("%1%2%3%4%5%6").arg(ui->lineEditTranslationsHelp->text(), QDir::separator(), theFileName, "_", theLangCode, ".qm");
    // ReadMe
    QString theHelpSource = QString("%1%2%3%4%5%6").arg(ui->lineEditTranslationsHelp->text(), QDir::separator(), theFileName, "_", ui->labelTranslationsSourceLanguageCode->text(), ".md");
    QString theReadMeFile = QString("%1%2%3%4%5%6").arg(ui->lineEditTranslationsProjectFolder->text(), QDir::separator(), "README", "_", theLangCode, ".md");
    //
    QString theTransQmFile = theQmFile;
    theTransQmFile.remove(ui->lineEditTranslationsProjectFolder->text());
    if (theTransQmFile.mid(0, 1) == "/" || theTransQmFile.mid(0, 1) == "\\") { theTransQmFile = theTransQmFile.mid(1); }
    // for display
    myTranslationQrc.append(QString("<file>%1</file>\n").arg(theTransQmFile));
    // Create Job
    // to store a job I need the theSourcePath and Language
    MyLingoJobs theTranslationJobs(thisLanguageName, theLangCode, theHelpSource, theMdFile, theReadMeFile, QOnlineTranslator::language(theLangCode), QOnlineTranslator::language(ui->labelTranslationsSourceLanguageCode->text()));
    myLingoJob.append(theTranslationJobs);
}
/************************************************
 * @brief translate With Return Added by Light-Wizzard.
 * translateWithReturn
 ***********************************************/
QString MainWindow::translateWithReturn(const QString &text, QOnlineTranslator::Engine engine, QOnlineTranslator::Language translationLang, QOnlineTranslator::Language sourceLang, QOnlineTranslator::Language uiLang)
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "translateWithReturn(" << text << ", " << engine << ", " << translationLang << ", " << sourceLang << ", " << uiLang << ")"; }
    // Clear Translation
    myTranslation.clear();
    // Event Loop
    QEventLoop theEventLoop;
    // Create Translator
    QOnlineTranslator theTranslator;
    // Call Translate on a thread
    theTranslator.translate(text, engine, translationLang, sourceLang, uiLang);
    // Connect to thread finished
    QObject::connect(&theTranslator, &QOnlineTranslator::finished, &theEventLoop, [&]
    {
        if (theTranslator.error() == QOnlineTranslator::NoError)
        {
            if (isTranslationLog) { qInfo() << theTranslator.translation(); }
            myTranslation = theTranslator.translation();
            isTranslationError = false; // No Error
            myTranslationError.clear(); // No Error Message
        }
        else
        {
            qCritical() << theTranslator.errorString();
            myTranslationError = QString("%1 %2 %3").arg(tr("Error in Translation phrase"), text, theTranslator.errorString());
            isTranslationError = true;
            myTranslation.clear();
        }
        theEventLoop.quit();
    });
    theEventLoop.exec();
    return myTranslation;
} // end translateWithReturn
/************************************************
 * @brief set Debug Message.
 * setDebugMessage
 ***********************************************/
void MainWindow::setDebugMessage(bool thisState)
{
    isDebugMessage = thisState;
    if (isDebugMessage && isMainLoaded) { qDebug() << "setDebugMessage"; }
}
/************************************************
 * @brief get Debug Message.
 * getDebugMessage
 ***********************************************/
bool MainWindow::getDebugMessage()
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "getDebugMessage"; }
    return isDebugMessage;
}
/************************************************
 * @brief Clipboard.
 * onClipboard
 ***********************************************/
void MainWindow::onClipboard()
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "onClipboard"; }
    //if (!isQtSettingsLoaded) { onCreate();}
    clipboard->setText(ui->textEditProjects->toPlainText());
}
/************************************************
 * @brief on checkBox Settigns Messaging state Changed.
 * on_checkBoxSettignsMessaging_stateChanged
 ***********************************************/
void MainWindow::on_checkBoxSettignsMessaging_stateChanged(int thisCheckState)
{
    if (!isMainLoaded) { return; }
    if (isDebugMessage) { qDebug() << "on_checkBoxSettignsMessaging_stateChanged"; }
    if (thisCheckState == Qt::Checked)
        { setMessagingStates(true); }
    else
        { setMessagingStates(false); }
}
/************************************************
 * @brief set Messaging States.
 * setMessagingStates
 ***********************************************/
void MainWindow::setMessagingStates(bool thisMessageState)
{
    if (thisMessageState)
    {
        mySqlDb->mySqlModel->mySetting->writeSettings(mySqlDb->mySqlModel->mySetting->myConstants->MY_IS_DEBUG_MESSAGE, "true");
        isDebugMessage = true;
        mySqlDb->setDebugMessage(true);
        mySqlDb->mySqlModel->setDebugMessage(true);
        mySqlDb->mySqlModel->mySetting->setDebugMessage(true);
        myLocalization->setDebugMessage(true);
        mySqlDb->mySqlModel->mySetting->myCrypto->setDebugMessage(true);
    }
    else
    {
        mySqlDb->mySqlModel->mySetting->writeSettings(mySqlDb->mySqlModel->mySetting->myConstants->MY_IS_DEBUG_MESSAGE, "false");
        isDebugMessage = false;
        mySqlDb->setDebugMessage(false);
        mySqlDb->mySqlModel->setDebugMessage(false);
        mySqlDb->mySqlModel->mySetting->setDebugMessage(false);
        myLocalization->setDebugMessage(false);
        mySqlDb->mySqlModel->mySetting->myCrypto->setDebugMessage(false);
    }
}
/************************************************
 * @brief on pushButton Translations Help clicked.
 * on_pushButtonTranslationsHelp_clicked
 ***********************************************/
void MainWindow::on_pushButtonTranslationsHelp_clicked()
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "on_pushButtonTranslationsHelp_clicked"; }
    QFileDialog dialogTranslationFolder;
    dialogTranslationFolder.setFileMode(QFileDialog::Directory);
    dialogTranslationFolder.setOption(QFileDialog::ShowDirsOnly);
    dialogTranslationFolder.setOption(QFileDialog::DontResolveSymlinks);
    //
    QString theTranslationFolder = dialogTranslationFolder.getExistingDirectory(this, tr("Help Folder Location"), mySqlDb->mySqlModel->mySetting->getLastApplicationPath());
    if (!theTranslationFolder.isEmpty())
        { ui->lineEditTranslationsHelp->setText(theTranslationFolder); }
    else
        { ui->lineEditTranslationsHelp->setText(""); }
}
/************************************************
 * @brief on comboBox Translation Source Language current Index Changed.
 * on_comboBoxTranslationSourceLanguage_currentIndexChanged
 ***********************************************/
void MainWindow::on_comboBoxTranslationSourceLanguage_currentIndexChanged(const QString &arg1)
{
    Q_UNUSED(arg1)
    setLanguageCode();
}
/* ******************************* End of File ***************************** */

