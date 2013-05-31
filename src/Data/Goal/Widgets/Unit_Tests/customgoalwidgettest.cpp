#include "customgoalwidgettest.h"

#include "customgoalwidget.h"
#include "timefunctions.h"

CustomGoalWidgetTest::CustomGoalWidgetTest(QObject *parent) :
    QObject(parent)
{
}

void CustomGoalWidgetTest::initTestCase()
{

}

void CustomGoalWidgetTest::cleanupTestCase()
{

}

void CustomGoalWidgetTest::init()
{
    m_widget = new UI::CustomGoalWidget();
}

void CustomGoalWidgetTest::cleanup()
{
    delete m_widget;
}
