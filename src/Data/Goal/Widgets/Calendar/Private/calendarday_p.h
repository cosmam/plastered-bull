#ifndef CALENDARDAY_P_H
#define CALENDARDAY_P_H

#include "goalcalendaritem_p.h"
#include "calendarday.h"

namespace Ui {
    class CalendarDay;
}

namespace UI {

    class CalendarDay;

    class CalendarDayPrivate : public GoalCalendarItemPrivate
    {
        Q_OBJECT
        Q_DECLARE_PUBLIC(UI::CalendarDay)
        Q_DISABLE_COPY(CalendarDayPrivate)

    public:

        /// Default constructor
        explicit CalendarDayPrivate();

        /// Destructor
        ~CalendarDayPrivate();

        /// Sets the day label
        void SetDayLabel( const QString & label );

        /// Initializes this widget
        void init();

        Ui::CalendarDay * const m_ui;

    public Q_SLOTS:

        /// Slot to position this widget's widgets
        void PositionWidgets();
    };

}

#endif // CALENDARDAY_P_H
