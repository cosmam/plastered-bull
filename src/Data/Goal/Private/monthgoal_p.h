#ifndef MONTHGOAL_P_H
#define MONTHGOAL_P_H

#include "goal_p.h"
#include "monthgoal.h"

#include "timefunctions.h"

#include <QPointer>

namespace UI {
    class MonthGoalWidget;
}

namespace Data {

    class Goal;
    class MonthGoal;

    class MonthGoalPrivate : public GoalPrivate
    {
        Q_OBJECT
        Q_DECLARE_PUBLIC(Data::MonthGoal)
        Q_DISABLE_COPY(MonthGoalPrivate)

    public:

        /// Default constructor
        explicit MonthGoalPrivate();

        /// Destructor
        ~MonthGoalPrivate();

        /// Initializes this widget
        void init();

        Time::Month month;
        int year;
        QPointer<UI::MonthGoalWidget> widget;

    public Q_SLOTS:

        /// Slot called when the widget changes are accepted
        void WidgetChangesAccepted();

        /// Slot called when the data is updated
        void OnDataUpdated();
    };

}
#endif // MONTHGOAL_P_H
