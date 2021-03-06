#ifndef CALENDARGOAL_P_H
#define CALENDARGOAL_P_H

#include "goalcalendaritem_p.h"
#include "calendargoal.h"

namespace Ui {
    class CalendarGoal;
}

namespace UI {

    class CalendarGoal;

    class CalendarGoalPrivate : public GoalCalendarItemPrivate
    {
        Q_OBJECT
        Q_DECLARE_PUBLIC(UI::CalendarGoal)
        Q_DISABLE_COPY(CalendarGoalPrivate)

    public:

        /// Default constructor
        explicit CalendarGoalPrivate();

        /// Destructor
        ~CalendarGoalPrivate();

        /// Initializes this widget
        void init();

        Ui::CalendarGoal * const m_ui;

    public Q_SLOTS:

    };

}

#endif // CALENDARGOAL_P_H
