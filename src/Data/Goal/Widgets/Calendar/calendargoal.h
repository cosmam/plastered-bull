#ifndef CALENDARGOAL_H
#define CALENDARGOAL_H

#include "goalcalendaritem.h"

namespace Data {
    class Goal;
}

namespace UI {

    class CalendarGoalPrivate;

    class CalendarGoal : public GoalCalendarItem
    {
        Q_OBJECT
        Q_DECLARE_PRIVATE(UI::CalendarGoal)
        Q_DISABLE_COPY(CalendarGoal)

    public:

        /// Default constructor
        explicit CalendarGoal(QWidget *parent = 0);

        /// Destructor
        ~CalendarGoal();

    public Q_SLOTS:

    };

}

#endif // CALENDARGOAL_H
