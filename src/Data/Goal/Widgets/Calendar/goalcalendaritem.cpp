#include "goalcalendaritem.h"
#include "goalcalendaritem_p.h"

using namespace UI;

/**
 * @author Cosmam
 * @name GoalCalendarItem
 * @namespace UI
 * @brief Default Constructor
 * @param parent: The parent widget
 **/
GoalCalendarItem::GoalCalendarItem(QWidget *parent) :
    SelectableWidget(*new GoalCalendarItemPrivate, parent)
{
}

/**
 * @author Cosmam
 * @name GoalCalendarItem
 * @namespace UI
 * @brief Overloaded constructor for d-pointer initialization
 * @param d: The d-pointer
 * @param parent: The parent widget
 **/
GoalCalendarItem::GoalCalendarItem(GoalCalendarItemPrivate & d, QWidget *parent) :
    SelectableWidget(d,parent)
{

}

/**************** Private Class ***************/

/**
 * @author Cosmam
 * @name GoalCalendarItemPrivate
 * @namespace UI
 * @brief Default constructor
 **/
GoalCalendarItemPrivate::GoalCalendarItemPrivate() :
    SelectableWidgetPrivate()
{
}

/**
 * @author Cosmam
 * @name init
 * @namespace UI
 * @brief Initializes the class
 **/
void GoalCalendarItemPrivate::init()
{
}
