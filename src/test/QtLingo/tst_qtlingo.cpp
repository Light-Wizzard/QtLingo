#include <QtTest>
#include <QCoreApplication>

/*! ***************************************************************************
   \class QtLingo QTest
   \brief QtLingo QTest Constructor
 *************************************************************************** */
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
/*! ***************************************************************************
   \fn QtLingo QTest
   \brief QtLingo QTest Constructor
 *************************************************************************** */
QtLingo::QtLingo()
{

}
/*! ***************************************************************************
   \fn QtLingo QTest
   \brief QtLingo QTest Deconstructor
 *************************************************************************** */
QtLingo::~QtLingo()
{

}
/*! ***************************************************************************
   \fn initTestCase
   \brief QtLingo QTest initTestCase
 *************************************************************************** */
void QtLingo::initTestCase()
{

}
/*! ***************************************************************************
   \fn cleanupTestCase
   \brief QtLingo QTest cleanupTestCase
 *************************************************************************** */
void QtLingo::cleanupTestCase()
{

}
/*! ***************************************************************************
   \fn test_case1
   \brief QtLingo QTest test_case1
 *************************************************************************** */
void QtLingo::test_case1()
{

}
// This creates main and runs it
QTEST_MAIN(QtLingo)
// Must compile before this exists, so it might fail the first time
#include "tst_qtlingo.moc"
/******************************* End of File *********************************/
