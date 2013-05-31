#include "goaltest.h"

#include "goalmock.h"
#include "timefunctions.h"

GoalTest::GoalTest(QObject *parent) :
    QObject(parent)
{
}

void GoalTest::initTestCase()
{

}

void GoalTest::cleanupTestCase()
{

}

void GoalTest::init()
{
    m_goal = new Data::GoalMock();
}

void GoalTest::cleanup()
{
    delete m_goal;
}

void GoalTest::TestName_data()
{
    QTest::addColumn<QString>("name");

    QTest::newRow("empty") << QString("");
    QTest::newRow("invalid") << QString();
    QTest::newRow("short") << QString("kajdlasd");
    QTest::newRow("long") << QString('a', 10000);
    QTest::newRow("special chars") << QString("!@#$%^&*()~`_+{}|[]\\-=;':,./<>?");
}

void GoalTest::TestName()
{
    QFETCH(QString, name);
    m_goal->setName(name);

    if( !name.isNull() ) {
        QCOMPARE(m_goal->name(), name);
    }
    else {
        QCOMPARE(m_goal->name(),QString(""));
    }

}

void GoalTest::TestColor_data()
{
    QTest::addColumn<QColor>("color");

    QTest::newRow("default") << QColor(0,0,0);
    QTest::newRow("invalid") << QColor();
    QTest::newRow("bad values") << QColor(1000,0,0);
    QTest::newRow("rgb") << QColor(10,20,100);
    QTest::newRow("name") << QColor("blue");
}

void GoalTest::TestColor()
{
    QFETCH(QColor,color);
    m_goal->setColor(color);

    if( color.isValid() ) {
        QCOMPARE(m_goal->color(), color);
    }
    else {
        QCOMPARE(m_goal->color(), QColor(0,0,0));
    }
}
