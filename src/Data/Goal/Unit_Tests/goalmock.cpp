#include "goalmock.h"

#include "goalwidgetbase.h"

using namespace Test;

GoalMock::GoalMock(QObject *parent) :
    Data::Goal(parent)
{
}

// LCOV_EXCL_START
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
//LCOV_EXCL_END
