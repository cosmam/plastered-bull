#include "testchasis.h"

#include "customgoaltest.h"
#include "daygoaltest.h"
#include "goaltest.h"
#include "monthgoaltest.h"
#include "weekgoaltest.h"
#include "yeargoaltest.h"
#include "customgoalwidgettest.h"
#include "daygoalwidgettest.h"
#include "monthgoalwidgettest.h"
#include "weekgoalwidgettest.h"
#include "yeargoalwidgettest.h"
#include "criteriatest.h"
#include "pagescriteriatest.h"
#include "wordscriteriatest.h"

#include <QtGlobal>
#include <QDebug>
#include <QTime>

using namespace Test;

uint TestChasis::m_randInit = 0;

TestChasis::TestChasis(QObject *parent) :
    QObject(parent)
{
}

TestChasis::~TestChasis()
{
    qDeleteAll(m_objects);
}

void TestChasis::CreateObjects()
{
    RegisterTest(new CustomGoalTest());
    RegisterTest(new DayGoalTest());
    RegisterTest(new GoalTest());
    RegisterTest(new MonthGoalTest());
    RegisterTest(new WeekGoalTest());
    RegisterTest(new YearGoalTest());
    RegisterTest(new CustomGoalWidgetTest());
    RegisterTest(new DayGoalWidgetTest());
    RegisterTest(new MonthGoalWidgetTest());
    RegisterTest(new WeekGoalWidgetTest());
    RegisterTest(new YearGoalWidgetTest());
    RegisterTest(new CriteriaTest());
    RegisterTest(new PagesCriteriaTest());
    RegisterTest(new WordsCriteriaTest());
}

int TestChasis::RunTests()
{
    int testStatus;

    m_status = 0;
    m_errors.clear();

    foreach(QObject * object, m_objects ) {
        testStatus = QTest::qExec(object);

        if( testStatus != 0 ) {
            m_errors.append( QString( object->metaObject()->className() ) );        // LCOV_EXCL_LINE
        }

        m_status |= testStatus;
    }

    if( !m_errors.isEmpty() ) {
        qWarning() << "********** Testing Results!**********\n\nErrors in the following classes:" << m_errors       // LCOV_EXCL_LINE
                   << "\n\n*************************************";                                                  // LCOV_EXCL_LINE
    } else {
        qWarning() << "********** Testing Results!**********\n\nAll tests passed!"
                   << "\n\n*************************************";
    }

    return m_status;
}

int TestChasis::RandInt(int lower, int upper)
{
    if( m_randInit == 0 ) {
        InitRand();                                         // LCOV_EXCL_LINE
    }

    return (qrand() % ((upper + 1) - lower) + lower);
}

QString TestChasis::RandString()
{
    if( m_randInit == 0 ) {
        InitRand();                                         // LCOV_EXCL_LINE
    }

    QString retString("");
    int length = RandInt(1,1000);

    for( int i=0 ; i < length ; ++i ) {
        retString += QChar((ushort)RandInt(10,255));
    }

    return retString;
}

QDate TestChasis::RandDate(QDate start, QDate end)
{
    if( m_randInit == 0 ) {
        InitRand();                                         // LCOV_EXCL_LINE
    }

    QDate date(1,1,1);

    while( !( (start <= date) && (date <= end) ) ) {

        int year = RandInt(start.year(),end.year());
        int month = RandInt(1,12);
        int day = RandInt(1, QDate(year, month, 1).daysInMonth());
        date.setDate(year, month, day);
    }

    return date;
}

QColor TestChasis::RandColor()
{
    if( m_randInit == 0 ) {
        InitRand();                                         // LCOV_EXCL_LINE
    }

    int red = RandInt(0,255);
    int blue = RandInt(0,255);
    int green = RandInt(0,255);

    return QColor(red, blue, green);
}

void TestChasis::RegisterTest(QObject *object)
{
    if( !m_objects.contains(object) ) {
        m_objects.append(object);
    }
}

void TestChasis::InitRand()
{
    m_randInit = (uint)QTime::currentTime().msec();
    qsrand( m_randInit );
}
