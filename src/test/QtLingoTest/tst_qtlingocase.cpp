#include <QtTest>
#include <QCoreApplication>

#include "MyOrgSettings.h"

/************************************************
 * @brief QtLingoCase Class.
 * /class QtLingoCase
 ***********************************************/
class QtLingoCase : public QObject
{
        Q_OBJECT

    public:
        QtLingoCase();
        ~QtLingoCase();

    private slots:
        void initTestCase();
        void cleanupTestCase();
        void test_case1();

};
/************************************************
 * @brief QtLingoCase Constructor.
 * QtLingoCase
 ***********************************************/
QtLingoCase::QtLingoCase()
{

}
/************************************************
 * @brief QtLingoCase Deconstructor.
 * QtLingoCase
 ***********************************************/
QtLingoCase::~QtLingoCase()
{

}
/************************************************
 * @brief initTestCase.
 * initTestCase
 ***********************************************/
void QtLingoCase::initTestCase()
{
    MyOrgSettings *myOrgSettings = new MyOrgSettings(this);
    QCOMPARE(myOrgSettings->getAppName(), qApp->applicationName());
}
/************************************************
 * @brief initTestCase.
 * initTestCase
 ***********************************************/
void QtLingoCase::cleanupTestCase()
{

}
/************************************************
 * @brief initTestCase.
 * initTestCase
 ***********************************************/
void QtLingoCase::test_case1()
{
    QString theTest = "This is my Secret";
    MyOrgSettings *myOrgSettings = new MyOrgSettings(this);
    QCOMPARE(theTest, myOrgSettings->decryptThis(myOrgSettings->encryptThis(theTest)));
}
/************************************************
 * @brief QTEST_MAIN.
 * QTEST_MAIN
 ***********************************************/
QTEST_MAIN(QtLingoCase)

#include "tst_qtlingocase.moc"
/******************************* End of File *********************************/
