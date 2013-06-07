#ifndef CALENDARDAY_H
#define CALENDARDAY_H

#include "goalcalendaritem.h"

namespace Data {
    class Goal;
}

namespace UI {

    class CalendarDayPrivate;

    class CalendarDay : public GoalCalendarItem
    {
        Q_OBJECT
        Q_DECLARE_PRIVATE(UI::CalendarDay)
        Q_DISABLE_COPY(CalendarDay)

    public:

        /// Defaults constructor
        explicit CalendarDay(QWidget *parent = 0);

        /// Destructor
        ~CalendarDay();

    public Q_SLOTS:

        /// Sets the day
        void SetDay( int day );

        /// Adds a goal to the day
        void AddGoal( Data::Goal * goal, int index = -1 );

    protected:

        /// Reimplemented resize event
        void resizeEvent(QResizeEvent *);
    };

}

#endif // CALENDARDAY_H
