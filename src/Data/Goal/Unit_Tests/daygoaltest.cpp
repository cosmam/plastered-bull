#include "daygoaltest.h"

#include "daygoal.h"
#include "timefunctions.h"

DayGoalTest::DayGoalTest(QObject *parent) :
    QObject(parent)
{
}

void DayGoalTest::initTestCase()
{

}

void DayGoalTest::cleanupTestCase()
{

}

void DayGoalTest::init()
{
    m_goal = new Data::DayGoal();
}

void DayGoalTest::cleanup()
{
    delete m_goal;
}

void DayGoalTest::TestDate_data()
{
    QTest::addColumn<QDate>("start");

    QTest::newRow("current") << QDate::currentDate();
    QTest::newRow("invalid") << QDate();
    QTest::newRow("non leap year") << QDate(2013,2,29);
    QTest::newRow("valid") << QDate(2013,5,13);
    QTest::newRow("negative valid") << QDate(-10,2,13);
    QTest::newRow("negative invalid") << QDate(-10000,1,1);
}

void DayGoalTest::TestDate()
{
    QFETCH(QDate, start);
    QDateTime startDateTime(start, Time::startTime);
    m_goal->setDate(start);

    if( start.isValid() ) {
        QCOMPARE(m_goal->date(), start);
        QCOMPARE(m_goal->start(), startDateTime);
        QCOMPARE(m_goal->end(), QDateTime(start,Time::endTime));
    }
    else {
        QCOMPARE(m_goal->date(),QDate::currentDate());
        QCOMPARE(m_goal->start(),QDateTime(QDate::currentDate(),Time::startTime));
        QCOMPARE(m_goal->end(),QDateTime(QDate::currentDate(),Time::endTime));
    }

}
