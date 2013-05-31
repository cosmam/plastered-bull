#include "goalmock.h"

#include "goalwidgetbase.h"

using namespace Data;

GoalMock::GoalMock(QObject *parent) :
    Goal(parent)
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
