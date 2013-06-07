#include "calendarmonth.h"
#include "calendarmonth_p.h"
#include "ui_calendarmonth.h"

#include "calendarday.h"

using namespace UI;

/**
 * @author Cosmam
 * @name CalenderMonth
 * @namespace UI
 * @brief Default constructor
 * @param parent: The parent widget
 **/
CalendarMonth::CalendarMonth(QWidget *parent) :
    QWidget(parent),
    d_ptr(new CalendarMonthPrivate( this ) )
{
}

/**
 * @author Cosmam
 * @name ~CalendarMonth
 * @namespace UI
 * @brief Destructor
 **/
CalendarMonth::~CalendarMonth()
{
    delete d_ptr;
}

/**
 * @author Cosmam
 * @name Month
 * @namespace UI
 * @brief Gets the month
 * @return The goal month
 **/
Time::Month CalendarMonth::Month() const
{
    Q_D(const UI::CalendarMonth);
    return d->month;
}

/**
 * @author Cosmam
 * @name Year
 * @namespace UI
 * @brief gets the year
 * @return Gets the goal year
 **/
int CalendarMonth::Year() const
{
    Q_D(const UI::CalendarMonth);
    return d->year;
}

/**
 * @author Cosmam
 * @name NumWeeks
 * @namespace UI
 * @brief Gets the number of weeks in the month
 * @return The number of weeks in the month
 **/
int CalendarMonth::NumWeeks() const
{
    Q_D(const UI::CalendarMonth);

    return d->weeks;
}

/**
 * @author Cosmam
 * @name Day
 * @namespace UI
 * @brief Gets the calendar day object for the given day
 * @param day: The calendar date
 * @return The calendar day widget (possibly NULL)
 **/
UI::CalendarDay * CalendarMonth::Day(int day) const
{
    Q_D(const UI::CalendarMonth);

    return (d->m_days.size() > (day + d->dayOffset - 1) ? d->m_days.at(d->dayOffset + day - 1) : NULL);
}

/**
 * @author Cosmam
 * @name SetMonth
 * @namespace UI
 * @brief Sets the month
 * @param month: The calendar month
 **/
void CalendarMonth::SetMonth( Time::Month month )
{
    Q_D(UI::CalendarMonth);

    if( d->month != month ) {
		d->month = month;
		d->DrawCalendar();
	}
}

/**
 * @author Cosmam
 * @name SetYear
 * @namespace UI
 * @brief Sets the year
 * @param year: The calendar year
 **/
void CalendarMonth::SetYear( int year )
{
    Q_D(UI::CalendarMonth);

    if( d->year != year ) {
		d->year = year;
		d->DrawCalendar();
	}
}

/**************** Private Class ***************/

/**
 * @author Cosmam
 * @name CalendarMonthPrivate
 * @namespace UI
 * @brief Default constructor
 * @param parent: The parent CalendarMonth
 * @param date: The date
 **/
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

/**
 * @author Cosmam
 * @name ~CalendarMonthPrivate
 * @namespace UI
 * @brief Destructor
 */
CalendarMonthPrivate::~CalendarMonthPrivate()
{
    delete m_ui;
}

/**
 * @author Cosmam
 * @name DrawCalendar
 * @namespace UI
 * @brief Draws the calendar
 **/
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

/**
 * @author Cosmam
 * @name InitCreateObjects
 * @namespace UI
 * @brief Creates the initial calendar day objects
 **/
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

/**
 * @author Cosmam
 * @name date
 * @namespace UI
 * @brief Gets the calendar date
 * @return The calendar date representing the month
 **/
const QDate CalendarMonthPrivate::date() const
{
    return QDate( year, Time::ToInt( month ), 1 );
}
