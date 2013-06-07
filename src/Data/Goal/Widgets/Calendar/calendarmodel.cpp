#include "calendarmodel.h"
#include "calendarmodel_p.h"

#include "calendarday.h"
#include "calendarmonth.h"

using namespace UI;

namespace {
    const int daysInWeek = 7;
}

/**
 * @author Cosmam
 * @name CalendarModel
 * @namespace UI
 * @brief Default constructor
 * @param parent: The parent object
 **/
CalendarModel::CalendarModel(QObject *parent) :
    QObject(parent),
    d_ptr( new CalendarModelPrivate( this ) )
{
}

/**
 * @author Cosmam
 * @name ~CalendarModel
 * @namespace UI
 * @brief Destructor
 **/
CalendarModel::~CalendarModel()
{
    delete d_ptr;
}

/**
 * @author Cosmam
 * @name SetCalendarReference
 * @namespace UI
 * @brief Sets the calendar reference
 * @param month: The month to set the reference with
 **/
void CalendarModel::SetCalendarReference(UI::CalendarMonth * month)
{
    if( month == NULL ) {
        return;
    }

    Q_D(UI::CalendarModel);
    d->ClearData();

    d->m_rows = month->NumWeeks();
    d->m_days.reserve(daysInWeek * d->m_rows);

    for( int i=0; i < (daysInWeek * d->m_rows) ; ++i ) {
        d->m_days.append(NULL);
    }

    QDate date( month->Year(), Time::ToInt(month->Month()), 1);

    int start = date.dayOfWeek() == 7 ? 0 : date.dayOfWeek();

    for( int i=0 ; i < date.daysInMonth() ; ++i ) {
        d->m_days.replace(start + i, month->Day(i+1));
    }
}

/**
 * @author Cosmam
 * @name Day
 * @namespace UI
 * @brief Gets the calendar day at the given location
 * @param row: The row position
 * @param col: The column position
 * @return The calendar day (possibly NULL)
 **/
UI::CalendarDay * CalendarModel::Day(int row, int col) const
{
    UI::CalendarDay * day(NULL);

    Q_D(const UI::CalendarModel);

    if( d->IsValid(row, col) )
    {
        day = d->m_days.at(daysInWeek * row + col);
    }

    return day;
}

/**
 * @author Cosmam
 * @name Range
 * @namespace UI
 * @brief CGets the range of calendar days between the start and end days
 * @param start: The start day
 * @param end: The end day
 * @return The list of days in the range
 **/
QList<UI::CalendarDay *> CalendarModel::Range(CalendarDay *start, CalendarDay *end) const
{
    QList<UI::CalendarDay *> days;

    if( ( start == NULL ) || ( end == NULL ) )
        return days;

    Q_D(const UI::CalendarModel);

    int startIndex = d->m_days.indexOf(start);
    int endIndex = d->m_days.indexOf(end);

    if( startIndex > endIndex )
        qSwap( startIndex, endIndex );

    for( int i = startIndex ; i <= endIndex ; ++i ) {
        days.append( d->m_days.at(i) );
    }

    return days;
}

/**
 * @author Cosmam
 * @name Rows
 * @namespace UI
 * @brief Gets the number of rows
 * @return The number of rows
 **/
int CalendarModel::Rows() const
{
    Q_D(const UI::CalendarModel);

    return d->m_rows;
}

/**************** Private Class ***************/

/**
 * @author Cosmam
 * @name CalendarModelPrivate
 * @namespace UI
 * @brief Default Constructor
 * @param parent:  The parent CalendarModel
 **/
CalendarModelPrivate::CalendarModelPrivate(CalendarModel *parent) :
    QObject(parent),
    m_rows(0),
    q_ptr(parent)
{
}

/**
 * @author Cosmam
 * @name ~CalendarModelPrivate
 * @namespace UI
 * @brief Destructor
 **/
CalendarModelPrivate::~CalendarModelPrivate()
{
}

/**
 * @author Cosmam
 * @name ClearData
 * @namespace UI
 * @brief Clears the private data
 **/
void CalendarModelPrivate::ClearData()
{
    m_rows = 0;
    m_days.clear();
}

/**
 * @author Cosmam
 * @name IsValid
 * @namespace UI
 * @brief Gets whether or not the item is valid
 * @param row: the item row
 * @param col: the item column
 * @return Whether or no the item at (row, col) is valid
 **/
bool CalendarModelPrivate::IsValid(int row, int col) const
{
    return ((row < m_rows) && (col < daysInWeek));
}
