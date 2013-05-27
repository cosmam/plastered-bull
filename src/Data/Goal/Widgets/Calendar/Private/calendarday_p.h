#ifndef CALENDARDAY_P_H
#define CALENDARDAY_P_H

#include "goalcalendaritem_p.h"
#include "calendarday.h"

namespace Ui {
class CalendarDay;
}

namespace UI
{

class CalendarDay;

class CalendarDayPrivate : public GoalCalendarItemPrivate
{
    Q_OBJECT
    Q_DECLARE_PUBLIC(UI::CalendarDay);

public:
    explicit CalendarDayPrivate();
    ~CalendarDayPrivate();

	void SetDayLabel( const QString & label );

    void init();

    Ui::CalendarDay * const m_ui;
    
    Q_DISABLE_COPY(CalendarDayPrivate);

public Q_SLOTS:

    void PositionWidgets();
};

}

#endif // CALENDARDAY_P_H
