#include "MainWindow.h"
/*! ***************************************************************************
   \fn MainWindow
   \brief MainWindow Constructor
 *************************************************************************** */
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    // Create table model:
    mySqlDb             = new MyDatatables(this);
    myTranslationFiles  = new MyTranslationFiles(this, mySqlDb);
    myTranslator        = new QTranslator(qApp);
    // Set up UI
    ui->setupUi(this);
    // Read in Settings First
    readSettingsFirst();
    // Set to defaults
    setTransFilePrefix("QtLingo");          //!< Prefix of Translation files
    setTranslationSource("translations");   //!< Relative Folder for Translation files
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
    connect(ui->actionExit,      &QAction::triggered, this, &MainWindow::close);
    connect(ui->actionAbout,     &QAction::triggered, this, &MainWindow::onAbout);
    connect(ui->actionHelp,      &QAction::triggered, this, &MainWindow::onHelp);
    connect(ui->actionAuthor,    &QAction::triggered, this, &MainWindow::onAuthor);
    connect(ui->actionClipboard, &QAction::triggered, this, &MainWindow::onClipboard);
    connect(ui->actionCompile,   &QAction::triggered, this, &MainWindow::onCompile);
    connect(ui->actionSave,      &QAction::triggered, this, &MainWindow::onSave);
    //
    ui->labelSettingsLanguageUI->setText(myQOnlineTranslator.languageCode(myQOnlineTranslator.language(QLocale())));
    // Set Window Title to Application Name
    setWindowTitle(QApplication::applicationName());
    //
    setPrograms();
    // Do a one time Single Shot call to onRunOnStartup to allow the GUI to load before calling what is in that call
    QTimer::singleShot(200, this, &MainWindow::onRunOnStartup);
}
/*! ***************************************************************************
   \fn ~MainWindow
   \brief MainWindow Deconstructor
 *************************************************************************** */
MainWindow::~MainWindow()
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "~MainWindow"; }
    Q_CLEANUP_RESOURCE(QtLingo);
    delete ui;
}
/*! ***************************************************************************
   \fn closeEvent
   \brief close Event
 *************************************************************************** */
void MainWindow::closeEvent(QCloseEvent *event)
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "closeEvent"; }
    if (isSaveSettings) onSave();
    mySqlDb->mySqlModel->mySetting->setGeometry(pos(), size(), isMaximized(), isMinimized());
    writeSettings();
    QMainWindow::closeEvent(event);
    close();
} // end closeEvent
/*! ***************************************************************************
   \fn changeEvent
   \brief change Event
 *************************************************************************** */
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
/*! ***************************************************************************
   \fn loadLanguage
   \brief load Language.
 *************************************************************************** */
void MainWindow::retranslate()
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "retranslate"; }
    // FIXME
    loadLanguageComboBox();
    loadLanguageComboBoxSource();
}
/*! ***************************************************************************
   \fn loadLanguage
   \brief load Language.
 *************************************************************************** */
void MainWindow::loadLanguageComboBoxSource()
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "loadLanguageComboBoxSource"; }
    //
    QMetaEnum e = QMetaEnum::fromType<QOnlineTranslator::Language>();

    isMainLoaded = false;
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
    isMainLoaded = true;
}
/*! ***************************************************************************
   \fn loadLanguage
   \brief load Language.
 *************************************************************************** */
void MainWindow::loadLanguageComboBox()
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "loadLanguageComboBox"; }
    isMainLoaded = false;
    int theCurrentIndex = ui->comboBoxSettingsLanguage->currentIndex();
    if (theCurrentIndex < 0)
    {
        theCurrentIndex = myLanguageCombBoxIndex;
    }
    ui->comboBoxSettingsLanguage->clear();
    const QStringList theQmFiles =  myTranslationFiles->findQmFiles(getTranslationSource());
    QStandardItemModel *theLangModel = new QStandardItemModel(this);
    theLangModel->setColumnCount(2);
    for (int i = 0; i < theQmFiles.size(); ++i)
    {
        QString theLanguageName = getLanguageFromFile(getTransFilePrefix(), theQmFiles.at(i));
        QStandardItem* theCol0 = new QStandardItem(theLanguageName);
        QStandardItem* theCol1 = new QStandardItem(tr(theLanguageName.toLocal8Bit()));
        theLangModel->setItem(i, 0, theCol0);
        theLangModel->setItem(i, 1, theCol1);
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
    ui->comboBoxSettingsLanguage->setMinimumWidth(400);
    ui->comboBoxSettingsLanguage->setModel( theLangModel );
    ui->comboBoxSettingsLanguage->setView( tableView );
    ui->comboBoxSettingsLanguage->setCurrentIndex(theCurrentIndex);
    isMainLoaded = true;
}
/*! ***************************************************************************
   \fn loadLanguage
   \brief load Language.
 *************************************************************************** */
void MainWindow::loadLanguage(const QString &thisQmLanguageFile)
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "loadLanguage"; }

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
/*! ***************************************************************************
   \fn getLanguageFile
   \brief get Language File
   QString thisLangFile = getLanguageFile("en", getTranslationSource(), getTransFilePrefix());
 *************************************************************************** */
QString MainWindow::getLanguageFile(const QString &thisLanguage, const QString &thisPath, const QString &thisPrefix)
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "getLanguageFile"; }
    const QStringList theQmFiles = myTranslationFiles->findQmFiles(thisPath);
    for (int i = 0; i < theQmFiles.size(); ++i)
    {
        if (myTranslationFiles->languageMatch(thisPrefix, thisLanguage, theQmFiles.at(i)))
            { return theQmFiles.at(i); }
    }
    return "";
} // getLanguageFile
/*! ***************************************************************************
   \fn onRunOnStartup
   \brief on Run On Startup.
 *************************************************************************** */
void MainWindow::onRunOnStartup()
{
    isMainLoaded = false;
    clearForms(TabAll);
    // Go to Tab
    ui->tabWidget->setCurrentIndex(ui->tabWidget->indexOf(ui->tabWidget->findChild<QWidget*>("tabSettings")));
    // Read Settings
    readSettings();

    // Read Saved Language
    readLanguage();
    // Get Language File
    QString theQmLanguageFile = getLanguageFile(myCurrentLanguageCode, getTranslationSource(), getTransFilePrefix());
    // Load Language
    loadLanguage(theQmLanguageFile);
    QString theLastLanguage = getLanguageFromFile(getTransFilePrefix(), theQmLanguageFile);
    loadLanguageComboBox();
    ui->comboBoxSettingsLanguage->setCurrentIndex(ui->comboBoxSettingsLanguage->findText(theLastLanguage));
    //
    if (isDebugMessage && isMainLoaded) { qDebug() << "onRunOnStartup"; }
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
}
/*! ***************************************************************************
   \fn readLanguage
   \brief read Language
 *************************************************************************** */
QString MainWindow::readLanguage()
{
    myCurrentLanguageCode = mySqlDb->mySqlModel->mySetting->readSettings(mySqlDb->mySqlModel->mySetting->myConstants->MY_CURRENT_LANG_CODE, myQOnlineTranslator.languageCode(myQOnlineTranslator.language(QLocale())));
    return myCurrentLanguageCode;
}
/*! ***************************************************************************
   \fn writeLanguage
   \brief write Language
 *************************************************************************** */
void MainWindow::writeLanguage(const QString &thisCurrentLanguageCode)
{
    myCurrentLanguageCode = thisCurrentLanguageCode;
    mySqlDb->mySqlModel->mySetting->writeSettings(mySqlDb->mySqlModel->mySetting->myConstants->MY_CURRENT_LANG_CODE, thisCurrentLanguageCode);
}
/*! ***************************************************************************
   \fn readSettingsFirst
   \brief read Settings First
 *************************************************************************** */
void MainWindow::readSettingsFirst()
{
    isDebugMessage = mySqlDb->mySqlModel->mySetting->readSettingsBool(mySqlDb->mySqlModel->mySetting->myConstants->MY_IS_DEBUG_MESSAGE, isDebugMessage);
    if (isDebugMessage)
    { ui->checkBoxSettignsMessaging->setCheckState(Qt::CheckState::Checked); }
    else
    { ui->checkBoxSettignsMessaging->setCheckState(Qt::CheckState::Unchecked); }
    setMessagingStates(isDebugMessage);
}
/*! ***************************************************************************
   \fn readSettings
   \brief read Settings
 *************************************************************************** */
void MainWindow::readSettings()
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "readSettings"; }
    // SQL Memory option Chech
    // default set to myProjectID="-1"
    QString theProjectID = mySqlDb->mySqlModel->mySetting->readSettings(mySqlDb->mySqlModel->mySetting->myConstants->MY_SQL_PROJECT_ID, mySqlDb->getProjectID());
    // We cannot read from the database yet, we are only getting the last states we know of
    if (theProjectID != "-1") { mySqlDb->setProjectID(theProjectID); } else { mySqlDb->setProjectID("1"); }
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
/*! ***************************************************************************
   \fn writeSettings
   \brief write Settings
 *************************************************************************** */
bool MainWindow::writeSettings()
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "writeSettings"; }
    mySqlDb->mySqlModel->mySetting->writeSettings(mySqlDb->mySqlModel->mySetting->myConstants->MY_IS_DEBUG_MESSAGE, isDebugMessage ? "true" : "false");
    //
    writeStateChanges();
    writeSqlDatabaseInfo();
    return true;
}
/*! ***************************************************************************
   \fn writeStateChanges
   \brief write States Changes
 *************************************************************************** */
void MainWindow::writeStateChanges()
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "writeStateChanges"; }
    // Sql Database Type Index
    mySqlDb->mySqlModel->mySetting->writeSettings(mySqlDb->mySqlModel->mySetting->myConstants->MY_SQL_COMBO_STATE, QString::number(ui->comboBoxSqlDatabaseType->currentIndex()));
    // Sql Database Type Value
    mySqlDb->mySqlModel->mySetting->writeSettings(mySqlDb->mySqlModel->mySetting->myConstants->MY_SQL_COMBO_VALUE, ui->comboBoxSqlDatabaseType->currentText());
    // Project ID
    mySqlDb->mySqlModel->mySetting->writeSettings(mySqlDb->mySqlModel->mySetting->myConstants->MY_SQL_PROJECT_ID, ui->labelRecordIdSettings->text());
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
    myCurrentLanguageCode = myQOnlineTranslator.languageNameToCode(ui->comboBoxSettingsLanguage->currentText());
    writeLanguage(myCurrentLanguageCode);
}
/*! ***************************************************************************
   \fn readSqlDatabaseStates
   \brief read Sql Database States
 *************************************************************************** */
void MainWindow::readStatesChanges()
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "readStatesChanges"; }
    // Set ComboBox for SQL
    ui->comboBoxSqlDatabaseType->setCurrentIndex(mySqlDb->mySqlModel->mySetting->readSettingsInt(mySqlDb->mySqlModel->mySetting->myConstants->MY_SQL_COMBO_STATE, 1));
    // SQL Type Value
    mySqlDb->setComboBoxSqlValue(mySqlDb->mySqlModel->mySetting->readSettings(mySqlDb->mySqlModel->mySetting->myConstants->MY_SQL_COMBO_VALUE, mySqlDb->mySqlModel->mySetting->myConstants->MY_SQL_DEFAULT));
    // Project ID
    ui->labelRecordIdSettings->setText(mySqlDb->mySqlModel->mySetting->readSettings(mySqlDb->mySqlModel->mySetting->myConstants->MY_SQL_PROJECT_ID, "-1"));
    // Trans Engine
    // Google
    ui->checkBoxSettingsGoogle->setCheckState((mySqlDb->mySqlModel->mySetting->readSettings(mySqlDb->mySqlModel->mySetting->myConstants->MY_TRANS_ENGINE_GOOGLE_VALUE, "true")) == "true" ? Qt::CheckState::Checked : Qt::CheckState::Unchecked);
    // Bing
    ui->checkBoxSettingsBing->setCheckState((mySqlDb->mySqlModel->mySetting->readSettings(mySqlDb->mySqlModel->mySetting->myConstants->MY_TRANS_ENGINE_BING_VALUE, "true")) == "true" ? Qt::CheckState::Checked : Qt::CheckState::Unchecked);
    // Yandex
    ui->checkBoxSettingsYandex->setCheckState((mySqlDb->mySqlModel->mySetting->readSettings(mySqlDb->mySqlModel->mySetting->myConstants->MY_TRANS_ENGINE_YANDEX_VALUE, "true")) == "true" ? Qt::CheckState::Checked : Qt::CheckState::Unchecked);
    // Language
    int theDefaultIndex = ui->comboBoxSettingsLanguage->findText(myQOnlineTranslator.languageName(myQOnlineTranslator.language(QLocale())));
    myLanguageCombBoxIndex = mySqlDb->mySqlModel->mySetting->readSettingsInt(mySqlDb->mySqlModel->mySetting->myConstants->MY_LANGUAGE_COMBO_STATE, theDefaultIndex);
    ui->comboBoxSettingsLanguage->setCurrentIndex(myLanguageCombBoxIndex);
    // Delay
    ui->spinBoxSettingsDelay->setValue(mySqlDb->mySqlModel->mySetting->readSettingsInt(mySqlDb->mySqlModel->mySetting->myConstants->MY_TRANS_DELAY_VALUE, mySqlDb->mySqlModel->mySetting->myConstants->MY_TRANS_DELAY));
}
/*! ***************************************************************************
   \fn writeSqlDatabaseInfo
   \brief write Sql Database Info Uses SimpleCrypt to encrypt and decrypt Password
 *************************************************************************** */
void MainWindow::writeSqlDatabaseInfo()
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "writeSqlDatabaseInfo"; }
    mySqlDb->mySqlModel->mySetting->writeSettings(mySqlDb->mySqlModel->mySetting->myConstants->MY_SQL_DB_NAME,  ui->lineEditSqlDatabaseName->text());
    mySqlDb->mySqlModel->mySetting->writeSettings(mySqlDb->mySqlModel->mySetting->myConstants->MY_SQL_DB_TYPE,  ui->comboBoxSqlDatabaseType->currentText());
    mySqlDb->mySqlModel->mySetting->writeSettings(mySqlDb->mySqlModel->mySetting->myConstants->MY_SQL_DB_HOST,  ui->lineEditSqlHostName->text());
    mySqlDb->mySqlModel->mySetting->writeSettings(mySqlDb->mySqlModel->mySetting->myConstants->MY_SQL_DB_USER,  ui->lineEditSqlUserName->text());
    // Encrypt Password, it is saved in Ini file
    if (!ui->lineEditSqlPassword->text().isEmpty())
        { mySqlDb->mySqlModel->mySetting->writeSettings(mySqlDb->mySqlModel->mySetting->myConstants->MY_SQL_DB_PASS, mySqlDb->mySqlModel->mySetting->encryptThis(ui->lineEditSqlPassword->text())); }
}
/*! ***************************************************************************
   \fn readSqlDatabaseInfo
   \brief read Sql Database Info Uses SimpleCrypt to encrypt and decrypt Password
 *************************************************************************** */
void MainWindow::readSqlDatabaseInfo()
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "readSqlDatabaseInfo"; }
    QString theDb = QString("%1%2%3.db").arg(mySqlDb->mySqlModel->mySetting->getAppDataLocation(), QDir::separator(), mySqlDb->mySqlModel->getSqlDatabaseName());
    ui->lineEditSqlDatabaseName->setText(mySqlDb->mySqlModel->mySetting->readSettings(mySqlDb->mySqlModel->mySetting->myConstants->MY_SQL_DB_NAME, theDb));
    //myOrgDomainSetting->readSettings(myOrgDomainSetting->myConstants->MY_SQL_DB_TYPE, ""); // No Default
    ui->lineEditSqlHostName->setText(mySqlDb->mySqlModel->mySetting->readSettings(mySqlDb->mySqlModel->mySetting->myConstants->MY_SQL_DB_HOST, "")); // No Default
    ui->lineEditSqlUserName->setText(mySqlDb->mySqlModel->mySetting->readSettings(mySqlDb->mySqlModel->mySetting->myConstants->MY_SQL_DB_USER, "")); // No Default
    // Decrypt Password, it is saved in Ini file
    QString thePassword = mySqlDb->mySqlModel->mySetting->decryptThis(mySqlDb->mySqlModel->mySetting->readSettings(mySqlDb->mySqlModel->mySetting->myConstants->MY_SQL_DB_PASS, ""));
    if (!thePassword.isEmpty())
        { ui->lineEditSqlPassword->setText(thePassword); }
    else
        { ui->lineEditSqlPassword->setText(""); }
}
/*! ***************************************************************************
   \fn setProjectCombo
   \brief set Project Combo
 *************************************************************************** */
bool MainWindow::setQtProjectCombo()
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "setQtProjectCombo"; }
    QSqlQueryModel *modalQtLingo = new QSqlQueryModel; //!< SQL Query Model
    //  SELECT id, QtProjectName FROM Projects
    const auto SELECTED_PROJECTS_SQL = QLatin1String(R"(%1)").arg(mySqlDb->getQtProjectNameSelectQuery());
    modalQtLingo->setQuery(SELECTED_PROJECTS_SQL);
    if (modalQtLingo->lastError().isValid())
    {
        qWarning() << modalQtLingo->lastError();
    }
    modalQtLingo->setHeaderData(0,Qt::Horizontal, tr("ID"));
    modalQtLingo->setHeaderData(1, Qt::Horizontal, tr("Project"));
    QTableView *view = new QTableView;
    view->setSelectionBehavior(QAbstractItemView::SelectRows);
    view->setSelectionMode(QAbstractItemView::SingleSelection);
    //ui->comboBoxSettingsProjects->setModel(nullptr);
    ui->comboBoxSettingsProjects->setModel(modalQtLingo);
    ui->comboBoxSettingsProjects->setView(view);
    view->setColumnHidden(0, true);
    ui->comboBoxSettingsProjects->setModelColumn(1);
    ui->comboBoxSettingsProjects->setCurrentIndex(0);
    view->setColumnWidth(1, 166);
    return true;
}
/*! ***************************************************************************
   \fn onAuthor
   \brief on Author
 *************************************************************************** */
void MainWindow::onAuthor()
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "onAuthor"; }
    // Go to Tab
    ui->tabWidget->setCurrentIndex(ui->tabWidget->indexOf(ui->tabWidget->findChild<QWidget*>("tabHelp")));
    //
    QString thisHelp = mySqlDb->mySqlModel->mySetting->readFile(":help/About-Author-en.html");
    ui->textEditHelp->setHtml(thisHelp);
}
/*! ***************************************************************************
   \fn onAbout
   \brief Main Window Destructor.
 *************************************************************************** */
void MainWindow::onAbout()
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "onAbout"; }
    // Go to Tab
    ui->tabWidget->setCurrentIndex(ui->tabWidget->indexOf(ui->tabWidget->findChild<QWidget*>("tabHelp")));
    //
    QString thisHelp = mySqlDb->mySqlModel->mySetting->readFile(":help/About-en.html");
    ui->textEditHelp->setHtml(thisHelp);
}
/*! ***************************************************************************
   \fn onHelp
   \brief Help
 *************************************************************************** */
void MainWindow::onHelp()
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "onHelp"; }
    // Go to Tab
    ui->tabWidget->setCurrentIndex(ui->tabWidget->indexOf(ui->tabWidget->findChild<QWidget*>("tabHelp")));
    //
    QString thisHelp = mySqlDb->mySqlModel->mySetting->readFile(":help/Help-en.html");
    ui->textEditHelp->setHtml(thisHelp);
}
/*! ***************************************************************************
   \fn on_pushButtonTranslationsSourceBrowse_clicked
   \brief
 *************************************************************************** */
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
    {
        ui->lineEditTranslationsSource->setText(theTranslationFolder);
    }
}
/*! ***************************************************************************
   \fn on_pushButtonTranslationsDestinationBrowse_clicked
   \brief
 *************************************************************************** */
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
    {
        ui->lineEditTranslationsDestination->setText(theTranslationFolder);
    }
}
/*! ***************************************************************************
   \fn on_pushButtonSettingsProjectsBrowser_clicked
   \brief
 *************************************************************************** */
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
    {
        ui->lineEditSettingsQtProjectName->setText(theTranslationFolder);
    }
}
/*! ***************************************************************************
   \fn on_pushButtonTranslationsProjectFolderBrowse_clicked
   \brief
 *************************************************************************** */
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
    {
        ui->lineEditTranslationsProjectFolder->setText(theTranslationFolder);
    }
}
/*! ***************************************************************************
   \fn on_comboBoxSettingsLanguage_currentIndexChanged
   \brief
 *************************************************************************** */
void MainWindow::on_comboBoxSettingsLanguage_currentIndexChanged(const QString &thisLanguage)
{
    if (!isMainLoaded) { return; }
    if (isDebugMessage && isMainLoaded) { qDebug() << "on_comboBoxSettingsLanguage_currentIndexChanged"; }
    writeLanguage(myQOnlineTranslator.languageNameToCode(thisLanguage));
    loadLanguage(getLanguageFile(myQOnlineTranslator.languageNameToCode(thisLanguage), getTranslationSource(), getTransFilePrefix()));
}
/*! ***************************************************************************
   \fn on_checkBoxSettingsGoogle_stateChanged
   \brief on checkBox Settings Google state Changed
 *************************************************************************** */
void MainWindow::on_checkBoxSettingsGoogle_stateChanged(int thisArg)
{
    Q_UNUSED(thisArg)
    if (!isMainLoaded) { return; }
    if (isDebugMessage && isMainLoaded) { qDebug() << "on_checkBoxSettingsGoogle_stateChanged"; }
    writeStateChanges();
}
/*! ***************************************************************************
   \fn on_checkBoxSettingsBing_stateChanged
   \brief on checkBox Settings Bing state Changed
 *************************************************************************** */
void MainWindow::on_checkBoxSettingsBing_stateChanged(int thisArg)
{
    Q_UNUSED(thisArg)
    if (!isMainLoaded) { return; }
    if (isDebugMessage && isMainLoaded) { qDebug() << "on_checkBoxSettingsBing_stateChanged"; }
    writeStateChanges();
}
/*! ***************************************************************************
   \fn on_checkBoxSettingsYandex_stateChanged
   \brief on checkBox Settings Yandex state Changed
 *************************************************************************** */
void MainWindow::on_checkBoxSettingsYandex_stateChanged(int thisArg)
{
    Q_UNUSED(thisArg)
    if (!isMainLoaded) { return; }
    if (isDebugMessage && isMainLoaded) { qDebug() << "on_checkBoxSettingsYandex_stateChanged"; }
    writeStateChanges();
}
/*! ***************************************************************************
   \fn on_pushButtonSqlDatabaseNameBrowse_clicked
   \brief Sql Database Name Browse clicked
 *************************************************************************** */
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
/*! ***************************************************************************
   \fn on_comboBoxSettingsProjects_currentIndexChanged
   \brief on comboBox Settings Projects current Index Changed
 *************************************************************************** */
void MainWindow::on_comboBoxSettingsProjects_currentIndexChanged(int thisIndex)
{
    Q_UNUSED(thisIndex) // not the same as theIndex
    if (!isMainLoaded) { return; }
    QString theIndex = ui->comboBoxSettingsProjects->model()->data(ui->comboBoxSettingsProjects->model()->index(ui->comboBoxSettingsProjects->currentIndex(), 0)).toString();
    if (isDebugMessage) { qDebug() << "on_comboBoxSettingsProjects_currentIndexChanged = " << thisIndex << " and thisIndex = " << theIndex; }
    fillForms(theIndex);
}
/*! ***************************************************************************
   \fn on_pushButtonSqlPasswordShow_clicked
   \brief on pushButton Sql Password Show clicked
 *************************************************************************** */
void MainWindow::on_pushButtonSqlPasswordShow_clicked()
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "on_pushButtonSqlPasswordShow_clicked"; }
    mySqlDb->mySqlModel->mySetting->showMessageBox(QObject::tr("Password Revieled").toLocal8Bit(), ui->lineEditSqlPassword->text().toLocal8Bit(), mySqlDb->mySqlModel->mySetting->Information);
}
/*! ***************************************************************************
   \fn on_pushButtonSqlSave_clicked
   \brief on pushButton Sql Save clicked
 *************************************************************************** */
void MainWindow::on_pushButtonSqlSave_clicked()
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "on_pushButtonSqlSave_clicked"; }
    writeStateChanges();
}
/*! ***************************************************************************
   \fn onSave
   \brief on pushButton Settings Save clicked
 *************************************************************************** */
void MainWindow::onSave()
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "onSave"; }
    setProjectClass(TabAll);
    mySqlDb->saveQtProject();
}
/*! ***************************************************************************
   \fn on_pushButtonSettingsSave_clicked
   \brief on pushButton Settings Save clicked
 *************************************************************************** */
void MainWindow::on_pushButtonSettingsSave_clicked()
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "on_pushButtonSettingsSave_clicked"; }
    onSave();
}
/*! ***************************************************************************
   \fn on_pushButtonSettingsAdd_clicked
   \brief on pushButton Settings Add clicked
 *************************************************************************** */
void MainWindow::on_pushButtonSettingsAdd_clicked()
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "on_pushButtonSettingsAdd_clicked"; }
    setProjectClass(TabAll);
    mySqlDb->addQtProject();
}
/*! ***************************************************************************
   \fn on_pushButtonSettingsDelete_clicked
   \brief on pushButton Settings Delete clicked
 *************************************************************************** */
void MainWindow::on_pushButtonSettingsDelete_clicked()
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "on_pushButtonSettingsDelete_clicked"; }
    setProjectClass(TabAll);
    mySqlDb->deleteQtProject(ui->labelRecordIdSettings->text());
}
/*! ***************************************************************************
   \fn setPrograms
   \brief set Programs
 *************************************************************************** */
void MainWindow::setPrograms()
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "setPrograms"; }
    QString theLupdatePath  = "/usr/bin/lupdate";
    QString theLreleasePath = "/usr/bin/lrelease";

    #if Q_OS_MSDOS || defined(Q_OS_WIN32) || defined(Q_OS_WINCE)
    // FIXME Qt Folder have not tested this code
    QString theQtEnv;
    theLupdatePath = mySqlDb->mySqlModel->runProcces("where", "lupdate.exe", true, 60);
    if (theLupdatePath.isEmpty())
    {
        theQtEnv = mySqlDb->mySqlModel->mySetting->getEnvironmentVar("Qt");
        if (theQtEnv.isEmpty())
        {
            theLupdatePath = QString("%1/lupdate.exe").arg(theQtEnv);
        }
        else
        {
            theLupdatePath = "c:/Qt/lupdate.exe";
        }
    }
    theLreleasePath = mySqlDb->mySqlModel->runProcces("where", "lrelease.exe", true, 60);
    if (theLreleasePath.isEmpty())
    {
        theQtEnv = mySqlDb->mySqlModel->mySetting->getEnvironmentVar("Qt");
        if (theQtEnv.isEmpty())
        {
            theLreleasePath = QString("%1/lrelease.exe").arg(theQtEnv);
        }
        else
        {
            theLreleasePath = "c:/Qt/lrelease.exe";
        }
    }
    ui->lineEditSettingsLupdate->setText(theLupdatePath);
    ui->lineEditSettingsLrelease->setText(theLreleasePath);
    #else
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
    #endif
    ui->lineEditSettingsLupdate->setText(theLupdatePath);
    ui->lineEditSettingsLrelease->setText(theLreleasePath);
}
/*! ***************************************************************************
   \fn on_comboBoxSqlDatabaseType_currentIndexChanged
   \brief on comboBox Sql Database Type current Index Changed
 *************************************************************************** */
void MainWindow::on_comboBoxSqlDatabaseType_currentIndexChanged(const QString &thisSqlType)
{
    if (!isMainLoaded) { return; }
    if (isDebugMessage) { qDebug() << "on_comboBoxSqlDatabaseType_currentIndexChanged=" << thisSqlType; }
    mySqlDb->mySqlModel->setSqlDriver(thisSqlType);
    writeStateChanges();
    setSqlBrowseButton();
}
/*! ***************************************************************************
   \fn languageChecked
   \brief language Checked
 *************************************************************************** */
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
    return myLanguages;
}
/*! ***************************************************************************
   \fn checkLanguage
   \brief check Language
 *************************************************************************** */
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
/*! ***************************************************************************
   \fn fillForms
   \brief fill Forms
 *************************************************************************** */
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
     * id, QtProjectName, QtProjectFolder, SourceFolder, DestinationFolder, LanguageIDs
    */
    if (query.exec(myConfigurationSelectQuery))
    {
        if (query.first())
        {
            if (isDebugMessage && isMainLoaded) { qDebug() << " QtProjectName=|" << query.value("QtProjectName").toString() << "|" << " SourceFolder=|" << query.value("SourceFolder").toString() << "|" << " QtProjectFolder=|" << query.value("QtProjectFolder").toString() << "|" << " DestinationFolder=|" << query.value("DestinationFolder").toString() << "|" << " LanguageIDs=|" << query.value("LanguageIDs").toString() << "|"; }
            // Set Record ID
            myRecordID = query.value("id").toInt();
            ui->labelRecordIdSettings->setText(query.value("id").toString());
            ui->lineEditSettingsQtProjectName->setText(query.value("QtProjectName").toString());
            ui->lineEditTranslationsProjectFolder->setText(query.value("QtProjectFolder").toString());
            ui->lineEditTranslationsSource->setText(query.value("SourceFolder").toString());
            ui->lineEditTranslationsDestination->setText(query.value("DestinationFolder").toString());
            //
            ui->radioButtonTranslationsQmake->setChecked(query.value("Make").toString() == "qmake" ? true : false);
            ui->radioButtonTranslationsCmake->setChecked(query.value("Make").toString() == "cmake" ? true : false);
            //
            mySourceLanguage = query.value("SourceLanguage").toString();
            ui->comboBoxTranslationSourceLanguage->setCurrentIndex(ui->comboBoxTranslationSourceLanguage->findText(query.value("SourceLanguage").toString()));
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
/*! ***************************************************************************
   \fn clearTabSettings
   \brief clear Tab Settings
 *************************************************************************** */
void MainWindow::clearTabSettings()
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "clearTabSettings"; }
    // Defaults
    ui->labelRecordIdSettings->setText("0");
}
/*! ***************************************************************************
   \fn clearTabTranslations
   \brief clear Tab Translations
 *************************************************************************** */
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
    #endif
}
/*! ***************************************************************************
   \fn clearTabProject
   \brief clear Tab Project
 *************************************************************************** */
void MainWindow::clearTabProject()
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "clearTabProject"; }
    ui->textEditProjects->setText("");
}
/*! ***************************************************************************
   \fn clearTabHelp
   \brief clear Tab Help
 *************************************************************************** */
void MainWindow::clearTabHelp()
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "clearTabHelp"; }
    ui->textEditHelp->setText("");
}
/*! ***************************************************************************
   \fn clearForms
   \brief  clear Forms
 *************************************************************************** */
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
/*! ***************************************************************************
   \fn setProjectClass
   \brief set Project Class
 *************************************************************************** */
void MainWindow::setProjectClass(int tabNumber)
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "setProjectClass"; }
    switch (tabNumber)
    {
        case TabSettings:
            mySqlDb->myProject->setID(ui->labelRecordIdSettings->text());
            mySqlDb->myProject->setQtProjectName(ui->lineEditSettingsQtProjectName->text());
            mySqlDb->myProject->setQtProjectFolder(ui->lineEditTranslationsProjectFolder->text());
            mySqlDb->myProject->setSourceFolder(ui->lineEditTranslationsSource->text());
            mySqlDb->myProject->setDestinationFolder(ui->lineEditTranslationsDestination->text());
            mySqlDb->myProject->setSourceLanguage(ui->comboBoxTranslationSourceLanguage->currentText());
            mySqlDb->myProject->setLanguageIDs(languageChecked());
            mySqlDb->myProject->setMake(ui->radioButtonTranslationsQmake->isChecked() ? "qmake" : "cmake");
            break;
        case TabTranslations:
            mySqlDb->myProject->setID(ui->labelRecordIdSettings->text());
            mySqlDb->myProject->setQtProjectName(ui->lineEditSettingsQtProjectName->text());
            mySqlDb->myProject->setQtProjectFolder(ui->lineEditTranslationsProjectFolder->text());
            mySqlDb->myProject->setSourceFolder(ui->lineEditTranslationsSource->text());
            mySqlDb->myProject->setDestinationFolder(ui->lineEditTranslationsDestination->text());
            mySqlDb->myProject->setSourceLanguage(ui->comboBoxTranslationSourceLanguage->currentText());
            mySqlDb->myProject->setLanguageIDs(languageChecked());
            mySqlDb->myProject->setMake(ui->radioButtonTranslationsQmake->isChecked() ? "qmake" : "cmake");
            break;
        case TabProject:
            break;
        case TabTabHelp:
            break;
        case TabAll:
            mySqlDb->myProject->setID(ui->labelRecordIdSettings->text());
            mySqlDb->myProject->setQtProjectName(ui->lineEditSettingsQtProjectName->text());
            mySqlDb->myProject->setQtProjectFolder(ui->lineEditTranslationsProjectFolder->text());
            mySqlDb->myProject->setSourceFolder(ui->lineEditTranslationsSource->text());
            mySqlDb->myProject->setDestinationFolder(ui->lineEditTranslationsDestination->text());
            mySqlDb->myProject->setSourceLanguage(ui->comboBoxTranslationSourceLanguage->currentText());
            mySqlDb->myProject->setLanguageIDs(languageChecked());
            mySqlDb->myProject->setMake(ui->radioButtonTranslationsQmake->isChecked() ? "qmake" : "cmake");
            break;
    }
}
/*! ***************************************************************************
   \fn onCompile
   \brief on Compile
 *************************************************************************** */
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

    createTranslationJob("Afrikaans",      "af" , ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsAF->isChecked());
    createTranslationJob("Albanian",       "sq" , ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsSQ->isChecked());
    createTranslationJob("Arabic",         "ar" , ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsAR->isChecked());
    createTranslationJob("Basque",         "eu" , ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsEU->isChecked());
    createTranslationJob("Belarusian",     "be" , ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsBE->isChecked());
    createTranslationJob("Bulgarian",      "bg" , ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsBG->isChecked());
    createTranslationJob("Catalan",        "ca" , ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsCA->isChecked());
    createTranslationJob("Croatian",       "hr" , ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsHR->isChecked());
    createTranslationJob("Czech",          "cs" , ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsCS->isChecked());
    createTranslationJob("Danish",         "da" , ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsDA->isChecked());
    createTranslationJob("Dutch",          "nl" , ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsNL->isChecked());
    createTranslationJob("English",        "en" , ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsEN->isChecked());
    createTranslationJob("Estonian",       "et" , ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsET->isChecked());
    createTranslationJob("Faeroese",       "fo" , ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsFO->isChecked());
    createTranslationJob("Farsi",          "fa" , ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsFA->isChecked());
    createTranslationJob("Finnish",        "fi" , ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsFI->isChecked());
    createTranslationJob("French",         "fr" , ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsFR->isChecked());
    createTranslationJob("Gaelic",         "gd" , ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsGD->isChecked());
    createTranslationJob("German",         "de" , ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsDE->isChecked());
    createTranslationJob("Greek",          "el" , ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsEL->isChecked());
    createTranslationJob("Hebrew",         "he" , ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsHE->isChecked());
    createTranslationJob("Hindi",          "hi" , ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsHI->isChecked());
    createTranslationJob("Hungarian",      "hu" , ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsHU->isChecked());
    createTranslationJob("Icelandic",      "is" , ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsIS->isChecked());
    createTranslationJob("Indonesian",     "id" , ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsID->isChecked());
    createTranslationJob("Irish",          "ga" , ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsGA->isChecked());
    createTranslationJob("Italian",        "it" , ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsIT->isChecked());
    createTranslationJob("Japanese",       "ja" , ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsJA->isChecked());
    createTranslationJob("Korean",         "ko" , ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsKO->isChecked());
    createTranslationJob("Kurdish",        "ku" , ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsKU->isChecked());
    createTranslationJob("Latvian",        "lv" , ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsLV->isChecked());
    createTranslationJob("Lithuanian",     "lt" , ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsLT->isChecked());
    createTranslationJob("Macedonian",     "mk" , ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsMK->isChecked());
    createTranslationJob("Malayalam",      "ml" , ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsML->isChecked());
    createTranslationJob("Malaysian",      "ms" , ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsMS->isChecked());
    createTranslationJob("Maltese",        "mt" , ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsMT->isChecked());
    createTranslationJob("Norwegian",      "no" , ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsNO->isChecked());
    createTranslationJob("Bokmal",         "nb" , ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsNB->isChecked());
    createTranslationJob("Nynorsk",        "nn" , ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsNN->isChecked());
    createTranslationJob("Polish",         "pl" , ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsPL->isChecked());
    createTranslationJob("Portuguese",     "pt" , ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsPT->isChecked());
    createTranslationJob("Punjabi",        "pa" , ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsPA->isChecked());
    createTranslationJob("Rhaeto-Romanic", "rm" , ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsRM->isChecked());
    createTranslationJob("Romanian",       "ro" , ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsRO->isChecked());
    createTranslationJob("Russian",        "ru" , ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsRU->isChecked());
    createTranslationJob("Serbian",        "sr" , ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsSR->isChecked());
    createTranslationJob("Slovak",         "sk" , ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsSK->isChecked());
    createTranslationJob("Slovenian",      "sl" , ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsSL->isChecked());
    createTranslationJob("Sorbian",        "sb" , ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsSB->isChecked());
    createTranslationJob("Spanish",        "es" , ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsES->isChecked());
    createTranslationJob("Swedish",        "sv" , ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsSV->isChecked());
    createTranslationJob("Thai",           "th" , ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsTH->isChecked());
    createTranslationJob("Tsonga",         "ts" , ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsTS->isChecked());
    createTranslationJob("Tswana",         "tn" , ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsTN->isChecked());
    createTranslationJob("Turkish",        "tr" , ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsTR->isChecked());
    createTranslationJob("Ukrainian",      "uk" , ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsUK->isChecked());
    createTranslationJob("Urdu",           "ur" , ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsUR->isChecked());
    createTranslationJob("Venda",          "ve" , ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsVE->isChecked());
    createTranslationJob("Vietnamese",     "vi" , ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsVI->isChecked());
    createTranslationJob("Welsh",          "cy" , ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsCY->isChecked());
    createTranslationJob("Xhosa",          "xh" , ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsXH->isChecked());
    createTranslationJob("Yiddish",        "yi" , ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsYI->isChecked());
    createTranslationJob("Zulu",           "zu" , ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsZU->isChecked());

    createTranslationJob("Amharic",        "am",  ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsAM->isChecked());
    createTranslationJob("Armenian",       "hy",  ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsHY->isChecked());
    createTranslationJob("Azerbaijani",    "az",  ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsAZ->isChecked());
    createTranslationJob("Bashkir",        "ba",  ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsBA->isChecked());
    createTranslationJob("Bengali",        "bn",  ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsBN->isChecked());
    createTranslationJob("Bosnian",        "bs",  ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsBS->isChecked());
    createTranslationJob("Chichewa",       "ny",  ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsNY->isChecked());
    createTranslationJob("Corsican",       "co",  ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsCO->isChecked());
    createTranslationJob("Esperanto",      "eo",  ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsEO->isChecked());
    createTranslationJob("Fijian",         "fj",  ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsFJ->isChecked());
    createTranslationJob("Frisian",        "fy",  ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsFY->isChecked());
    createTranslationJob("Galician",       "gl",  ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsGL->isChecked());
    createTranslationJob("Georgian",       "ka",  ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsKA->isChecked());
    createTranslationJob("Gujarati",       "gu",  ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsGU->isChecked());
    createTranslationJob("Haitian",        "ht",  ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsHT->isChecked());
    createTranslationJob("Hausa",          "ha",  ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsHA->isChecked());
    createTranslationJob("Igbo",           "ig",  ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsIG->isChecked());
    createTranslationJob("Javanese",       "jw",  ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsJW->isChecked());
    createTranslationJob("Kannada",        "kn",  ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsKN->isChecked());
    createTranslationJob("Kazakh",         "kk",  ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsKK->isChecked());
    createTranslationJob("Khmer",          "km",  ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsKM->isChecked());
    createTranslationJob("Kinyarwanda",    "rw",  ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsRW->isChecked());
    createTranslationJob("Kyrgyz",         "ky",  ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsKY->isChecked());
    createTranslationJob("Lao",            "lo",  ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsLO->isChecked());
    createTranslationJob("Latin",          "la",  ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsLA->isChecked());
    createTranslationJob("Luxembourgish",  "lb",  ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsLB->isChecked());
    createTranslationJob("Malagasy",       "mg",  ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsMG->isChecked());
    createTranslationJob("Maori",          "mi",  ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsMI->isChecked());
    createTranslationJob("Marathi",        "mr",  ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsMR->isChecked());
    createTranslationJob("Mongolian",      "mn",  ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsMN->isChecked());
    createTranslationJob("Myanmar",        "my",  ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsMY->isChecked());
    createTranslationJob("Nepali",         "ne",  ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsNE->isChecked());
    createTranslationJob("Oriya",          "or",  ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsOR->isChecked());
    createTranslationJob("Pashto",         "ps",  ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsPS->isChecked());
    createTranslationJob("Samoan",         "sm",  ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsSM->isChecked());
    createTranslationJob("Sesotho",        "st",  ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsST->isChecked());
    createTranslationJob("Shona",          "sn",  ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsSN->isChecked());
    createTranslationJob("Sindhi",         "sd",  ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsSD->isChecked());
    createTranslationJob("Sinhala",        "si",  ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsSI->isChecked());
    createTranslationJob("Somali",         "so",  ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsSO->isChecked());
    createTranslationJob("Sundanese",      "su",  ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsSU->isChecked());
    createTranslationJob("Swahili",        "sw",  ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsSW->isChecked());
    createTranslationJob("Tagalog",        "tl",  ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsTL->isChecked());
    createTranslationJob("Tahitian",       "ty",  ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsTY->isChecked());
    createTranslationJob("Tajik",          "tg",  ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsTG->isChecked());
    createTranslationJob("Tamil",          "ta",  ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsTA->isChecked());
    createTranslationJob("Tatar",          "tt",  ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsTT->isChecked());
    createTranslationJob("Telugu",         "te",  ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsTE->isChecked());
    createTranslationJob("Tongan",         "to",  ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsTO->isChecked());
    createTranslationJob("Turkmen",        "tk",  ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsTK->isChecked());
    createTranslationJob("Uighur",         "ub",  ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsUG->isChecked());
    createTranslationJob("Uzbek",          "uz",  ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsUZ->isChecked());
    createTranslationJob("Yoruba",         "yo",  ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsYO->isChecked());
    createTranslationJob("SimplifiedChinese",  "zh-CN" , ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsZH_CN->isChecked());
    createTranslationJob("TraditionalChinese", "zh-TW" , ui->comboBoxTranslationSourceLanguage->currentText(), ui->checkBoxTranslationsZH_TW->isChecked());
    //
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
        myTranslationFiles->toTXT(myLingoJob.at(i).getTsFile(), ui->lineEditTranslationsDestination->text(), true, false, true);
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
                    if (theMatch.contains("%")) { myTranslationFiles->removeArgs(theMatch, myLingoJob.at(i).getTsFile()); }
                    if (isSameLanguage)
                    { myTranslation = theMatch; }
                    else
                    {
                        // QString &text, Engine engine, Language translationLang, Language sourceLang, Language uiLang
                        myTranslation = translateWithReturn(theMatch, QOnlineTranslator::Engine::Google, myLingoJob.at(i).getLang(), myLingoJob.at(i).getSourceLang(), myQOnlineTranslator.language(QLocale()));
                        // if empty use another service
                        if (myTranslation.isEmpty())
                        {
                            if (isTranslationError)
                            {
                                if (myTranslationError.contains("Error transferring"))
                                {
                                    // server replied: Too Many Requests, seems to happen with Arabic FIXME
                                }
                            }
                            myTranslation = translateWithReturn(theMatch, QOnlineTranslator::Engine::Bing, myLingoJob.at(i).getLang(), myLingoJob.at(i).getSourceLang(), myQOnlineTranslator.language(QLocale()));
                            if (myTranslation.isEmpty())
                            {
                                myTranslation = translateWithReturn(theMatch, QOnlineTranslator::Engine::Yandex, myLingoJob.at(i).getLang(), myLingoJob.at(i).getSourceLang(), myQOnlineTranslator.language(QLocale()));
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
                myTranslationFiles->fixTranslationFile(theDestTxtFile);
                // Create Txt file
                myTranslationFiles->toTS(ui->lineEditTranslationsDestination->text(), myLingoJob.at(i).getTsFile(), myLingoJob.at(i).getLangName());
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
    myTranslationFiles->fileRemoveArgs();
} // end onCompile
/*! ***************************************************************************
   \fn createTranslationJob
   \brief create Translation Job, I pass in the Name of the Language,
          and the language ID, I do not use the Name, but find it nice to have the info with it.
 *************************************************************************** */
void MainWindow::createTranslationJob(const QString &thisLanguageName, const QString &thisLanguage, const QString &thisSourceLanguage, bool thisChecked)
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "createTranslationJob(" << thisLanguageName << ", " << thisLanguage << ", " << thisSourceLanguage << ", " << thisChecked << ")"; }
    //
    if (!thisChecked) { return; }
    // Create Translation file names for configuration
    QString theTsFile =QString("%1%2%3%4%5%6").arg(ui->lineEditTranslationsSource->text(), QDir::separator(), ui->lineEditSettingsQtProjectName->text(), "_", thisLanguage, ".ts");
    QString theQmFile =QString("%1%2%3%4%5%6").arg(ui->lineEditTranslationsSource->text(), QDir::separator(), ui->lineEditSettingsQtProjectName->text(), "_", thisLanguage, ".qm");
    //
    QString theTransFile = theTsFile;
    QString theTransQmFile = theQmFile;
    theTransFile.remove(ui->lineEditTranslationsProjectFolder->text());
    theTransQmFile.remove(ui->lineEditTranslationsProjectFolder->text());
    if (theTransFile.mid(0, 1) == "/" || theTransFile.mid(0, 1) == "\\") { theTransFile = theTransFile.mid(1); }
    if (theTransQmFile.mid(0, 1) == "/" || theTransQmFile.mid(0, 1) == "\\") { theTransQmFile = theTransQmFile.mid(1); }
    myTranslationConf.append(QString(" %1").arg(theTransFile));
    myTranslationQrc.append(QString("<file>%1</file>\n").arg(theTransQmFile));
    // Create Job
    // to store a job I need the theSourcePath and Language
    MyLingoJobs theTranslationJobs(thisLanguageName, thisLanguage, theTsFile, QOnlineTranslator::language(thisLanguage), QOnlineTranslator::language(myQOnlineTranslator.languageNameToCode(thisSourceLanguage)));
    myLingoJob.append(theTranslationJobs);
}
/*! ***************************************************************************
   \fn translateWithReturn
   \brief translate With Return Added by Light-Wizzard
 *************************************************************************** */
QString MainWindow::translateWithReturn(const QString &text, QOnlineTranslator::Engine engine, QOnlineTranslator::Language translationLang, QOnlineTranslator::Language sourceLang, QOnlineTranslator::Language uiLang)
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "translateWithReturn(" << text << ", " << engine << ", " << translationLang << ", " << sourceLang << ", " << uiLang << ")"; }
    //
    myTranslation = "";
    //
    QEventLoop eventLoop;
    //
    QOnlineTranslator translator;
    //
    translator.translate(text, engine, translationLang, sourceLang, uiLang);
    //
    QObject::connect(&translator, &QOnlineTranslator::finished, &eventLoop, [&]
    {
        if (translator.error() == QOnlineTranslator::NoError)
        {
            qInfo() << translator.translation();
            myTranslation = translator.translation();
            isTranslationError = false;
        }
        else
        {
            qCritical() << translator.errorString();
            myTranslationError = QString("%1 %2 %3").arg(tr("Error in Translation phrase"), text, translator.errorString());
            isTranslationError = true;
            myTranslation = "";
        }
        eventLoop.quit();
    });
    eventLoop.exec();
    return myTranslation;
} // end translateWithReturn
/*! ***************************************************************************
   \fn getLanguageFromFile
   \brief get Language File
   QString thisLangFile = getLanguageFromFile(getTransFilePrefix(), "?.qm");
 *************************************************************************** */
QString MainWindow::getLanguageFromFile(const QString &thisPrefix, const QString &thisQmLanguageFile)
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "getLanguageFromFile"; }
    return myTranslationFiles->getLocalizerCode(thisPrefix, thisQmLanguageFile);
}
/*! ***************************************************************************
   \fn getTranslationSource
   \brief get Translation Source
 *************************************************************************** */
QString MainWindow::getTranslationSource()
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "getTranslationSource"; }
    return myTranslationSource;
}
/*! ***************************************************************************
   \fn setTranslationSource
   \brief set Translation Source
 *************************************************************************** */
void MainWindow::setTranslationSource(const QString &thisTranslationSource)
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "setTranslationSource"; }
    myTranslationSource = thisTranslationSource;
}
/*! ***************************************************************************
   \fn getTransFilePrefix
   \brief get Trans File Prefix
 *************************************************************************** */
QString MainWindow::getTransFilePrefix()
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "getTransFilePrefix"; }
    if (myTransFilePrefix.isEmpty()) { myTransFilePrefix = mySqlDb->mySqlModel->mySetting->myConstants->MY_TRANSLATION_PREFIX; }
    return myTransFilePrefix;
}
/*! ***************************************************************************
   \fn setTransFilePrefix
   \brief set Trans File Prefix setTransFilePrefix("QtLingo");
 *************************************************************************** */
void MainWindow::setTransFilePrefix(const QString &thisTransFilePrefix)
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "setTransFilePrefix"; }
    myTransFilePrefix = thisTransFilePrefix;
}
/*! ***************************************************************************
   \fn setDebugMessage
   \brief set Debug Message
 *************************************************************************** */
void MainWindow::setDebugMessage(bool thisState)
{
    isDebugMessage = thisState;
    if (isDebugMessage && isMainLoaded) { qDebug() << "setDebugMessage"; }
}
/*! ***************************************************************************
   \fn getDebugMessage
   \brief get Debug Message
 *************************************************************************** */
bool MainWindow::getDebugMessage()
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "getDebugMessage"; }
    return isDebugMessage;
}
/*! ***************************************************************************
   \fn setSqlBrowseButton
   \brief set Sql Browse Button
 *************************************************************************** */
void MainWindow::setSqlBrowseButton()
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "settingsButtons"; }
    ui->pushButtonSqlDatabaseNameBrowse->setEnabled(ui->comboBoxSqlDatabaseType->currentText() == mySqlDb->mySqlModel->mySetting->myConstants->MY_SQL_DEFAULT || ui->comboBoxSqlDatabaseType->currentText() == ":memory:");
}
/*! ***************************************************************************
   \fn onClipboard
   \brief Clipboard
 *************************************************************************** */
void MainWindow::onClipboard()
{
    if (isDebugMessage && isMainLoaded) { qDebug() << "onClipboard"; }
    //if (!isQtSettingsLoaded) { onCreate();}
    clipboard->setText(ui->textEditProjects->toPlainText());
}
/*! ***************************************************************************
   \fn on_checkBoxSettignsMessaging_stateChanged
   \brief on checkBox Settigns Messaging state Changed
 *************************************************************************** */
void MainWindow::on_checkBoxSettignsMessaging_stateChanged(int thisCheckState)
{
    if (isMainLoaded) { return; }
    if (isDebugMessage) { qDebug() << "on_checkBoxSettignsMessaging_stateChanged"; }
    if (thisCheckState == Qt::Checked)
    {
        setMessagingStates(true);
    }
    else
    {
        setMessagingStates(false);
    }
}
/*! ***************************************************************************
   \fn setMessagingStates
   \brief set Messaging States
 *************************************************************************** */
void MainWindow::setMessagingStates(bool thisMessageState)
{
    if (thisMessageState)
    {
        mySqlDb->mySqlModel->mySetting->writeSettings(mySqlDb->mySqlModel->mySetting->myConstants->MY_IS_DEBUG_MESSAGE, "true");
        isDebugMessage = true;
        mySqlDb->setDebugMessage(true);
        mySqlDb->mySqlModel->setDebugMessage(true);
        mySqlDb->mySqlModel->mySetting->setDebugMessage(true);
        myTranslationFiles->setDebugMessage(true);
        mySqlDb->mySqlModel->mySetting->myCrypto->setDebugMessage(true);
    }
    else
    {
        mySqlDb->mySqlModel->mySetting->writeSettings(mySqlDb->mySqlModel->mySetting->myConstants->MY_IS_DEBUG_MESSAGE, "false");
        isDebugMessage = false;
        mySqlDb->setDebugMessage(false);
        mySqlDb->mySqlModel->setDebugMessage(false);
        mySqlDb->mySqlModel->mySetting->setDebugMessage(false);
        myTranslationFiles->setDebugMessage(false);
        mySqlDb->mySqlModel->mySetting->myCrypto->setDebugMessage(false);
    }
}
/* ******************************* End of File ***************************** */
/*
 * Not Supported
{Klingon, QStringLiteral("tlh")},               // Klingon tlh
{KlingonPlqaD, QStringLiteral("tlh-Qaak")},     // KlingonPlqaD tlh-Qaak
{Cantonese, QStringLiteral("yue")},             // Cantonese yue
{Cebuano, QStringLiteral("ceb")},               // Cebuano ceb
{Filipino, QStringLiteral("fil")},              // Filipino fil
{Hawaiian, QStringLiteral("haw")},              // Hawaiian haw
{HillMari, QStringLiteral("mrj")},              // HillMari mrj
{Hmong, QStringLiteral("hmn")},                 // Hmong hmn
{LevantineArabic, QStringLiteral("apc")},       // Levantine Arabic apc
{Mari, QStringLiteral("mhr")},                  // Mari mhr
{Papiamento, QStringLiteral("pap")},            // Papiamento pap
{QueretaroOtomi, QStringLiteral("otq")},        // QueretaroOtomi otq
{SerbianLatin, QStringLiteral("sr-Latin")},     // SerbianLatin sr-Latin
{Udmurt, QStringLiteral("udm")},                // Udmurt udm
{YucatecMaya, QStringLiteral("yua")},           // YucatecMaya yua
 */


