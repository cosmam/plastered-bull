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

    const int start = ( date.dayOfWeek() == 7 ? 0 : date.dayOfWeek() );
    const int end = date.daysInMonth() + start - 1;

    for( int i=0; i < m_days.size() ; i++ ) {
        day = m_days.value(i);

        if( i < start || i > end ) {
            day->SetDay(0);
        }
        else {
            day->SetDay( i - start + 1 );
        }

        if( ( end < 35 && i >= 35 ) || ( end < 28 && i >= 28 ) ) {
            day->hide();
        }
        else {
            day->show();
        }
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
