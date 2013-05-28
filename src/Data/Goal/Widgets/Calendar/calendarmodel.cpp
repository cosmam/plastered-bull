#include "calendarmodel.h"
#include "calendarmodel_p.h"

#include "calendarday.h"
#include "calendarmonth.h"

using namespace UI;

namespace
{
    const int daysInWeek = 7;
}

CalendarModel::CalendarModel(QObject *parent) :
    QObject(parent),
    d_ptr( new CalendarModelPrivate( this ) )
{
}

CalendarModel::~CalendarModel()
{
    delete d_ptr;
}

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

int CalendarModel::Rows() const
{
    Q_D(const UI::CalendarModel);

    return d->m_rows;
}

/**************** Private Class ***************/

CalendarModelPrivate::CalendarModelPrivate(CalendarModel *parent) :
    QObject(parent),
    m_rows(0),
    q_ptr(parent)
{
}

CalendarModelPrivate::~CalendarModelPrivate()
{
}

void CalendarModelPrivate::ClearData()
{
    m_rows = 0;
    m_days.clear();
}

bool CalendarModelPrivate::IsValid(int row, int col) const
{
    return ((row < m_rows) && (col < daysInWeek));
}
