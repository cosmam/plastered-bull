#include "calendargoal.h"
#include "calendargoal_p.h"
#include "ui_calendargoal.h"

#include "goal.h"

using namespace UI;

CalendarGoal::CalendarGoal(QWidget *parent) :
    GoalCalendarItem(*new UI::CalendarGoalPrivate, parent)
{
    Q_D(UI::CalendarGoal);
    d->setParent(this);
    d->q_ptr = this;
    d->init();
}

CalendarGoal::~CalendarGoal()
{
}

/**************** Private Class ***************/

CalendarGoalPrivate::CalendarGoalPrivate() :
    GoalCalendarItemPrivate(),
    m_ui(new Ui::CalendarGoal)
{
}

CalendarGoalPrivate::~CalendarGoalPrivate()
{
    delete m_ui;
}

void CalendarGoalPrivate::init()
{
    Q_Q(UI::CalendarGoal);
    m_ui->setupUi(q);
}
