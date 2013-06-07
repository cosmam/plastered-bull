#include "monthgoaltest.h"

#include "monthgoal.h"

using namespace Test;

MonthGoalTest::MonthGoalTest(QObject *parent) :
    QObject(parent)
{
}

void MonthGoalTest::initTestCase()
{

}

void MonthGoalTest::cleanupTestCase()
{

}

void MonthGoalTest::init()
{
    m_goal = new Data::MonthGoal();
}

void MonthGoalTest::cleanup()
{
    delete m_goal;
}

void MonthGoalTest::TestMonth_data()
{
    QTest::addColumn<Time::Month>("month");

    QTest::newRow("invalid") << Time::INVALID_MONTH;
    QTest::newRow("jan") << Time::JAN;
    QTest::newRow("feb") << Time::FEB;
    QTest::newRow("mar") << Time::MAR;
    QTest::newRow("apr") << Time::APR;
    QTest::newRow("may") << Time::MAY;
    QTest::newRow("jun") << Time::JUN;
    QTest::newRow("jul") << Time::JUL;
    QTest::newRow("aug") << Time::AUG;
    QTest::newRow("sep") << Time::SEP;
    QTest::newRow("oct") << Time::OCT;
    QTest::newRow("nov") << Time::NOV;
    QTest::newRow("dec") << Time::DEC;
}

void MonthGoalTest::TestMonth()
{
    QFETCH(Time::Month, month);
    QDate startDate(QDate::currentDate().year(),Time::ToInt(month),1);
    QDate endDate(QDate::currentDate().year(),Time::ToInt(month),startDate.daysInMonth());
    m_goal->setMonth(month);

    if( month != Time::INVALID_MONTH ) {
        QCOMPARE(m_goal->month(), month);
        QCOMPARE(m_goal->start(),QDateTime(startDate,Time::startTime));
        QCOMPARE(m_goal->end(),QDateTime(endDate,Time::endTime));
    }
    else {
        QCOMPARE(m_goal->month(),Time::ToMonth(QDate::currentDate().month()));
        QCOMPARE(m_goal->start(),QDateTime(QDate(QDate::currentDate().year(),QDate::currentDate().month(),1),Time::startTime));
        QCOMPARE(m_goal->end(),QDateTime(QDate(QDate::currentDate().year(),QDate::currentDate().month(),QDate::currentDate().daysInMonth()),Time::endTime));
    }
}

void MonthGoalTest::TestYear_data()
{
    QTest::addColumn<int>("year");

    QTest::newRow("current") << QDate::currentDate().year();
    QTest::newRow("zero") << 0;
    QTest::newRow("one") << 1;
    QTest::newRow("negative") << -1;
    QTest::newRow("large") << 10000;
    QTest::newRow("large negative") << -10000;
}

void MonthGoalTest::TestYear()
{
    QFETCH(int,year);
    QDate startDate(year,QDate::currentDate().month(),1);
    QDate endDate(year,QDate::currentDate().month(),startDate.daysInMonth());
    m_goal->setYear(year);

    if( startDate.isValid() ) {
        QCOMPARE(m_goal->year(), year);
        QCOMPARE(m_goal->start(), QDateTime(startDate,Time::startTime));
        QCOMPARE(m_goal->end(),QDateTime(endDate,Time::endTime));
    }
    else {
        QCOMPARE(m_goal->year(), QDate::currentDate().year());
        QCOMPARE(m_goal->start(),QDateTime(QDate(QDate::currentDate().year(),QDate::currentDate().month(),1),Time::startTime));
        QCOMPARE(m_goal->end(),QDateTime(QDate(QDate::currentDate().year(),QDate::currentDate().month(),QDate::currentDate().daysInMonth()),Time::endTime));
    }
}
