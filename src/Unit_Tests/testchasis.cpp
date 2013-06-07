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
            m_errors.append( QString( object->metaObject()->className() ) );
        }

        m_status |= testStatus;
    }

    if( !m_errors.isEmpty() ) {
        qWarning() << "********** Testing Results!**********\n\nErrors in the following classes:" << m_errors
                   << "\n\n*************************************";
    } else {
        qWarning() << "********** Testing Results!**********\n\nAll tests passed!"
                   << "\n\n*************************************";
    }

    return m_status;
}

int TestChasis::RandInt(int lower, int upper)
{
    if( m_randInit == 0 ) {
        InitRand();
    }

    return (qrand() % ((upper + 1) - lower) + lower);
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
