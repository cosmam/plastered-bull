#include "calendarday.h"
#include "calendarday_p.h"
#include "ui_calendarday.h"

#include "goal.h"

using namespace UI;

/**
 * @author Cosmam
 * @name CalendarDay
 * @namespace UI
 * @brief Default controller
 * @param parent: The parent widget
 **/
CalendarDay::CalendarDay(QWidget *parent) :
    GoalCalendarItem(*new UI::CalendarDayPrivate, parent)
{
    Q_D(UI::CalendarDay);
    d->setParent(this);
    d->q_ptr = this;
    d->init();
    d->PositionWidgets();
}

/**
 * @author Cosmam
 * @name ~CalendarDay
 * @namespace UI
 * @brief Destructor
 **/
CalendarDay::~CalendarDay()
{
}

/**
 * @author Cosmam
 * @name SetDay
 * @namespace UI
 * @brief Sets the day
 * @param day
 **/
void CalendarDay::SetDay(int day)
{
    Q_D(UI::CalendarDay);

    if( day > 0 && day < 32 ) {
        d->SetDayLabel( QString::number(day) );
    }
    else {
        d->SetDayLabel( "" );
	}
}

/**
 * @author Cosmam
 * @name AddGoal
 * @namespace UI
 * @brief Adds a goal to the day
 * @param goal: The goal to add
 * @param index: The index to add it at
 **/
void CalendarDay::AddGoal(Data::Goal *goal, int index)
{
    Q_UNUSED(goal);
    Q_UNUSED(index);
}

/**
 * @author Cosmam
 * @name resizeEvent
 * @namespace UI
 * @brief Reimplemented resize event
 * @param e: The resize event
 **/
void CalendarDay::resizeEvent(QResizeEvent * e)
{
    Q_UNUSED(e);
    Q_D(UI::CalendarDay);
    d->PositionWidgets();
}

/**************** Private Class ***************/

/**
 * @author Cosmam
 * @name CalendarDayPrivate
 * @namespace UI
 * @brief Default constructor
 **/
CalendarDayPrivate::CalendarDayPrivate() :
    GoalCalendarItemPrivate(),
    m_ui(new Ui::CalendarDay)
{
}

/**
 * @author Cosmam
 * @name ~CalendarDayPrivate
 * @namespace UI
 * @brief Destructor
 **/
CalendarDayPrivate::~CalendarDayPrivate()
{
    delete m_ui;
}

/**
 * @author Cosmam
 * @name SetDayLabel
 * @namespace UI
 * @brief Sets the day label
 * @param label: The day label
 **/
void CalendarDayPrivate::SetDayLabel( const QString & label )
{
    m_ui->day_Label->setText( label );
}

/**
 * @author Cosmam
 * @name init
 * @namespace UI
 * @brief Initializes this class
 **/
void CalendarDayPrivate::init()
{
    Q_Q(UI::CalendarDay);
    m_ui->setupUi(q);
}

/**
 * @author Cosmam
 * @name PositionWidget
 * @namespace UI
 * @brief Position this widget's widgets
 **/
void CalendarDayPrivate::PositionWidgets()
{
    Q_Q(UI::CalendarDay);

    m_ui->frame->move(0,0);
    m_ui->frame->resize(q->size());

    m_ui->widget->move(0,0);
    m_ui->widget->resize(q->size());
}
