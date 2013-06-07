#include "customgoaltest.h"

#include "customgoal.h"
#include "timefunctions.h"

using namespace Test;

CustomGoalTest::CustomGoalTest(QObject *parent) :
    QObject(parent)
{
}

void CustomGoalTest::initTestCase()
{

}

void CustomGoalTest::cleanupTestCase()
{

}

void CustomGoalTest::init()
{
    m_goal = new Data::CustomGoal();
}

void CustomGoalTest::cleanup()
{
    delete m_goal;
}

void CustomGoalTest::TestStart_data()
{
    QTest::addColumn<QDate>("start");

    QTest::newRow("current") << QDate::currentDate();
    QTest::newRow("invalid") << QDate();
    QTest::newRow("non leap year") << QDate(2013,2,29);
    QTest::newRow("valid") << QDate(2013,5,13);
    QTest::newRow("negative valid") << QDate(-10,2,13);
    QTest::newRow("negative invalid") << QDate(-10000,1,1);
}

void CustomGoalTest::TestStart()
{
    QFETCH(QDate, start);
    QDateTime startDateTime(start, Time::startTime);
    m_goal->setStartDate(start);

    if( start.isValid() ) {
        QCOMPARE(m_goal->startDate(), start);
        QCOMPARE(m_goal->start(), startDateTime);
    }
    else {
        QCOMPARE(m_goal->startDate(),QDate::currentDate());
        QCOMPARE(m_goal->start(),QDateTime(QDate::currentDate(),Time::startTime));
    }

}

void CustomGoalTest::TestDuration_data()
{
    QTest::addColumn<int>("duration");

    QTest::newRow("zero") << 0;
    QTest::newRow("one") << 1;
    QTest::newRow("negative") << -1;
    QTest::newRow("large") << 1000;
}

void CustomGoalTest::TestDuration()
{
    QFETCH(int,duration);
    QDateTime endTime(QDate::currentDate().addDays(duration), Time::endTime);
    m_goal->setDuration(duration);

    if( duration >= 0 ) {
        QCOMPARE(m_goal->duration(), duration);
        QCOMPARE(m_goal->end(), endTime);
    }
    else {
        QCOMPARE(m_goal->duration(), 0);
        QCOMPARE(m_goal->end(),QDateTime(QDate::currentDate(),Time::endTime));
    }
}
