#ifndef CALENDARMODEL_P_H
#define CALENDARMODEL_P_H

#include <QObject>

namespace UI
{

class CalendarModel;

class CalendarModelPrivate : public QObject
{
    Q_OBJECT
    Q_DECLARE_PUBLIC(UI::CalendarModel);

public:
    explicit CalendarModelPrivate(CalendarModel *parent);
	~CalendarModelPrivate();
    
    CalendarModel * const q_ptr;

    Q_DISABLE_COPY(CalendarModelPrivate);

public Q_SLOTS:

};

}

#endif // CALENDARMODEL_P_H