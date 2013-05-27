#include "calendarmodel.h"
#include "calendarmodel_p.h"

using namespace UI;

CalendarModel::CalendarModel(QObject *parent) :
    QObject(parent),
    d_ptr( new CalendarModelPrivate( this ) )
{
}

CalendarModel::~CalendarModel()
{
    delete d_ptr;
}

/**************** Private Class ***************/

CalendarModelPrivate::CalendarModelPrivate(CalendarModel *parent) :
    QObject(parent),
    q_ptr(parent)
{
}

CalendarModelPrivate::~CalendarModelPrivate()
{
}
