#include "calendarmonth.h"
#include "calendarmonth_p.h"
#include "ui_calendarmonth.h"

#include "calendarday.h"

using namespace UI;

CalendarMonth::CalendarMonth(QWidget *parent) :
    QWidget(parent),
    d_ptr(new CalendarMonthPrivate( this ) )
{
}

CalendarMonth::~CalendarMonth()
{
    delete d_ptr;
}

Time::Month CalendarMonth::Month() const
{
    Q_D(const UI::CalendarMonth);
    return d->month;
}

int CalendarMonth::Year() const
{
    Q_D(const UI::CalendarMonth);
    return d->year;
}

int CalendarMonth::NumWeeks() const
{
    Q_D(const UI::CalendarMonth);

    return d->weeks;
}

UI::CalendarDay * CalendarMonth::Day(int day) const
{
    Q_D(const UI::CalendarMonth);

    return (d->m_days.size() > (day + d->dayOffset - 1) ? d->m_days.at(d->dayOffset + day - 1) : NULL);
}

void CalendarMonth::SetMonth( Time::Month month )
{
    Q_D(UI::CalendarMonth);

    if( d->month != month ) {
		d->month = month;
		d->DrawCalendar();
	}
}

void CalendarMonth::SetYear( int year )
{
    Q_D(UI::CalendarMonth);

    if( d->year != year ) {
		d->year = year;
		d->DrawCalendar();
	}
}

/**************** Private Class ***************/

CalendarMonthPrivate::CalendarMonthPrivate(CalendarMonth *parent, const QDate & date) :
    QObject(parent),
    month(Time::ToMonth( date.month() )),
    year(date.year()),
    weeks(0),
    dayOffset(0),
    m_ui(new Ui::CalendarMonth),
    q_ptr(parent)
{
    m_ui->setupUi(q_ptr);

    InitCreateObjects();

    DrawCalendar();
}

CalendarMonthPrivate::~CalendarMonthPrivate()
{
    delete m_ui;
}

void CalendarMonthPrivate::DrawCalendar()
{
    Q_Q(UI::CalendarMonth);

    q->setUpdatesEnabled(false);
    QDate date( this->date() );
    CalendarDay * day( NULL );

    dayOffset = ( date.dayOfWeek() == 7 ? 0 : date.dayOfWeek() );
    const int end = date.daysInMonth() + dayOffset - 1;

    for( int i=0; i < m_days.size() ; i++ ) {
        day = m_days.value(i);

        if( i < dayOffset || i > end ) {
            day->SetDay(0);
            day->setSelectable(false);
        }
        else {
            day->SetDay( i - dayOffset + 1 );
            day->setSelectable(true);
        }

        if( ( end < 35 && i >= 35 ) || ( end < 28 && i >= 28 ) ) {
            day->hide();
        }
        else {
            day->show();
        }
    }

    if( end < 28 ) {
        weeks = 4;
    }
    else if( end < 35 ) {
        weeks = 5;
    }
    else {
        weeks = 6;
    }

    q->setUpdatesEnabled(true);
}

void CalendarMonthPrivate::InitCreateObjects()
{
    UI::CalendarDay * day( NULL );

    for( int i=0 ; i < 6 ; i++ ) {
        for( int j=0 ; j < 7 ; j++ ) {
            day = new CalendarDay();
            m_ui->gridLayout->addWidget(day,i,j);
            m_days.append(day);
        }
    }
}

const QDate CalendarMonthPrivate::date() const
{
    return QDate( year, Time::ToInt( month ), 1 );
}
