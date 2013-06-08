#include "weekgoaltest.h"

#include "goalwidgetbase.h"
#include "testchasis.h"
#include "timefunctions.h"
#include "weekgoal.h"
#include "weekgoalwidget.h"

using namespace Test;

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

void WeekGoalTest::WidgetTest_data()
{
    QTest::addColumn<QString>("name");
    QTest::addColumn<QColor>("color");
    QTest::addColumn<QDate>("startDate");

    for( int i=0 ; i < 10 ; ++i ) {
        QTest::newRow(qPrintable(QString::number(i))) << TestChasis::RandString()
                                                      << TestChasis::RandColor()
                                                      << TestChasis::RandDate();
    }
}

void WeekGoalTest::WidgetTest()
{
    QFETCH(QString, name);
    QFETCH(QColor, color);
    QFETCH(QDate, startDate);

    m_goal->setName(name);
    m_goal->setColor(color);
    m_goal->setStartDate(startDate);

    UI::GoalWidgetBase * baseWidget = m_goal->CreateWidget();
    UI::WeekGoalWidget * widget = qobject_cast<UI::WeekGoalWidget*>(baseWidget);

    QVERIFY( baseWidget != NULL );
    QVERIFY( widget != NULL );

    if( (baseWidget == NULL) || (widget == NULL)) {
        return;
    }

    QCOMPARE(widget->Name(), name);
    QCOMPARE(widget->Color(), color);
    QCOMPARE(widget->StartDate(), startDate);

    delete baseWidget;
}
