#include "calendargoal.h"
#include "calendargoal_p.h"
#include "ui_calendargoal.h"

#include "goal.h"

using namespace UI;

/**
 * @author Cosmam
 * @name CalendarGoal
 * @namespace UI
 * @brief Default constructor
 * @param parent: The parent widget
 **/
CalendarGoal::CalendarGoal(QWidget *parent) :
    GoalCalendarItem(*new UI::CalendarGoalPrivate, parent)
{
    Q_D(UI::CalendarGoal);
    d->setParent(this);
    d->q_ptr = this;
    d->init();
}

/**
 * @author Cosmam
 * @name ~CalendarGoal
 * @namespace UI
 * @brief Destructor
 **/
CalendarGoal::~CalendarGoal()
{
}

/**************** Private Class ***************/

/**
 * @author Cosmam
 * @name CalendarGoalPrivate
 * @namespace UI
 * @brief Default constructor
 */
CalendarGoalPrivate::CalendarGoalPrivate() :
    GoalCalendarItemPrivate(),
    m_ui(new Ui::CalendarGoal)
{
}

/**
 * @author Cosmam
 * @name ~CalendarGoalPrivate
 * @namespace UI
 * @brief Destructor
 **/
CalendarGoalPrivate::~CalendarGoalPrivate()
{
    delete m_ui;
}

/**
 * @author Cosmam
 * @name init
 * @namespace UI
 * @brief Initializes this class
 **/
void CalendarGoalPrivate::init()
{
    Q_Q(UI::CalendarGoal);
    m_ui->setupUi(q);
}
