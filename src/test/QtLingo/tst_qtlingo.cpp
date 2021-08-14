#include <QtTest>
#include <QCoreApplication>

/************************************************
 * \class QtLingo
 * @brief QtLingo QTest Class.
 ***********************************************/
class QtLingo : public QObject
{
        Q_OBJECT

    public:
        QtLingo();
        ~QtLingo();

    private slots:
        void initTestCase();
        void cleanupTestCase();
        void test_case1();

};
/************************************************
 * @brief QtLingo QTest Constructor.
 * QtLingo
 ***********************************************/
QtLingo::QtLingo()
{

}
/************************************************
 * @brief QtLingo QTest Deconstructor.
 * ~QtLingo
 ***********************************************/
QtLingo::~QtLingo()
{

}
/************************************************
 * @brief QtLingo QTest initTestCase.
 * initTestCase
 ***********************************************/
void QtLingo::initTestCase()
{

}
/************************************************
 * @brief QtLingo QTest cleanupTestCase.
 * cleanupTestCase
 ***********************************************/
void QtLingo::cleanupTestCase()
{

}
/************************************************
 * @brief QtLingo QTest test_case1.
 * test_case1
 ***********************************************/
void QtLingo::test_case1()
{

}
// This creates main and runs it
QTEST_MAIN(QtLingo)
// Must compile before this exists, so it might fail the first time
#include "tst_qtlingo.moc"
/******************************* End of File *********************************/
