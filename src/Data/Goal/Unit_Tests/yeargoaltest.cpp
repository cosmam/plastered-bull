#include "yeargoaltest.h"

#include "yeargoal.h"
#include "timefunctions.h"

YearGoalTest::YearGoalTest(QObject *parent) :
    QObject(parent)
{
}

void YearGoalTest::initTestCase()
{

}

void YearGoalTest::cleanupTestCase()
{

}

void YearGoalTest::init()
{
    m_goal = new Data::YearGoal();
}

void YearGoalTest::cleanup()
{
    delete m_goal;
}

void YearGoalTest::TestYear_data()
{
    QTest::addColumn<int>("year");

    QTest::newRow("current") << QDate::currentDate().year();
    QTest::newRow("zero") << 0;
    QTest::newRow("one") << 1;
    QTest::newRow("negative") << -1;
    QTest::newRow("large") << 10000;
    QTest::newRow("large negative") << -10000;
}

void YearGoalTest::TestYear()
{
    QFETCH(int,year);
    QDate date(year, 1, 1);
    m_goal->setYear(year);

    if( date.isValid() ) {
        QCOMPARE(m_goal->year(), year);
        QCOMPARE(m_goal->start(), QDateTime(date,Time::startTime));
        QCOMPARE(m_goal->end(),QDateTime(QDate(date.year(),12,31),Time::endTime));
    }
    else {
        QCOMPARE(m_goal->year(), QDate::currentDate().year());
        QCOMPARE(m_goal->start(),QDateTime(QDate(QDate::currentDate().year(),1,1),Time::startTime));
        QCOMPARE(m_goal->end(),QDateTime(QDate(QDate::currentDate().year(),12,31),Time::endTime));
    }
}
