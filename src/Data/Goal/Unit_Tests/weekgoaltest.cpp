#include "weekgoaltest.h"

#include "weekgoal.h"
#include "timefunctions.h"

WeekGoalTest::WeekGoalTest(QObject *parent) :
    QObject(parent)
{
}

void WeekGoalTest::initTestCase()
{

}

void WeekGoalTest::cleanupTestCase()
{

}

void WeekGoalTest::init()
{
    m_goal = new Data::WeekGoal();
}

void WeekGoalTest::cleanup()
{
    delete m_goal;
}

void WeekGoalTest::TestStart_data()
{
    QTest::addColumn<QDate>("start");

    QTest::newRow("current") << QDate::currentDate();
    QTest::newRow("invalid") << QDate();
    QTest::newRow("non leap year") << QDate(2013,2,29);
    QTest::newRow("valid") << QDate(2013,5,13);
    QTest::newRow("negative valid") << QDate(-10,2,13);
    QTest::newRow("negative invalid") << QDate(-10000,1,1);
}

void WeekGoalTest::TestStart()
{
    QFETCH(QDate, start);
    QDateTime startDateTime(start, Time::startTime);
    m_goal->setStartDate(start);

    if( start.isValid() ) {
        QCOMPARE(m_goal->startDate(), start);
        QCOMPARE(m_goal->start(), startDateTime);
        QCOMPARE(m_goal->end(), QDateTime(start.addDays(7),Time::endTime));
    }
    else {
        QCOMPARE(m_goal->startDate(),QDate::currentDate());
        QCOMPARE(m_goal->start(),QDateTime(QDate::currentDate(),Time::startTime));
        QCOMPARE(m_goal->end(), QDateTime(QDate::currentDate().addDays(7),Time::endTime));
    }

}
