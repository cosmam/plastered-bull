#include "goalmock.h"

#include "goalwidgetbase.h"

using namespace Test;

GoalMock::GoalMock(QObject *parent) :
    Data::Goal(parent)
{
}

QDateTime GoalMock::start() const
{
    return QDateTime::currentDateTime();
}

QDateTime GoalMock::end() const
{
    return QDateTime::currentDateTime();
}

UI::GoalWidgetBase * GoalMock::CreateWidget()
{
    return NULL;
}
