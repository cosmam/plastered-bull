#include "calendarday.h"
#include "calendarday_p.h"
#include "ui_calendarday.h"

#include "goal.h"

using namespace UI;

CalendarDay::CalendarDay(QWidget *parent) :
    QWidget(parent),
    d_ptr( new UI::CalendarDayPrivate( this ) )
{
    Q_D(UI::CalendarDay);
    d->PositionWidgets();
}

CalendarDay::~CalendarDay()
{
    delete d_ptr;
}

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

void CalendarDay::AddGoal(Data::Goal *goal, int index)
{
    Q_UNUSED(goal);
    Q_UNUSED(index);
}

void CalendarDay::resizeEvent(QResizeEvent * e)
{
    Q_UNUSED(e);
    Q_D(UI::CalendarDay);
    d->PositionWidgets();
}

/**************** Private Class ***************/

CalendarDayPrivate::CalendarDayPrivate(CalendarDay *parent) :
    QObject(parent),
    m_ui(new Ui::CalendarDay),
    q_ptr(parent)
{
    m_ui->setupUi(q_ptr);
}

CalendarDayPrivate::~CalendarDayPrivate()
{
    delete m_ui;
}


void CalendarDayPrivate::SetDayLabel( const QString & label )
{
    m_ui->day_Label->setText( label );
}

void CalendarDayPrivate::PositionWidgets()
{
    Q_Q(UI::CalendarDay);

    m_ui->frame->move(0,0);
    m_ui->frame->resize(q->size());

    m_ui->widget->move(0,0);
    m_ui->widget->resize(q->size());
}
