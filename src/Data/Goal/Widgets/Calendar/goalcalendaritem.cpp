#include "goalcalendaritem.h"
#include "goalcalendaritem_p.h"

using namespace UI;

GoalCalendarItem::GoalCalendarItem(QWidget *parent) :
    SelectableWidget(*new GoalCalendarItemPrivate, parent)
{
}

GoalCalendarItem::GoalCalendarItem(GoalCalendarItemPrivate & d, QWidget *parent) :
    SelectableWidget(d,parent)
{

}

/**************** Private Class ***************/

GoalCalendarItemPrivate::GoalCalendarItemPrivate() :
    SelectableWidgetPrivate()
{
}

void GoalCalendarItemPrivate::init()
{

}
