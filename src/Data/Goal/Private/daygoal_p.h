#ifndef DAYGOAL_P_H
#define DAYGOAL_P_H

#include "goal_p.h"
#include "daygoal.h"

#include <QDate>
#include <QPointer>

namespace UI {
    class DayGoalWidget;
}

namespace Data {

    class DayGoal;
    class Goal;

    class DayGoalPrivate : public GoalPrivate
    {
        Q_OBJECT
        Q_DECLARE_PUBLIC(Data::DayGoal)
        Q_DISABLE_COPY(DayGoalPrivate)

    public:

        /// Default constructor
        explicit DayGoalPrivate();

        /// Destructor
        ~DayGoalPrivate();

        /// Initializes this widget
        void init();

        QDate date;
        QPointer<UI::DayGoalWidget> widget;

    public Q_SLOTS:

        /// Slot called when the widget changes are accepted
        void WidgetChangesAccepted();

        /// Slot called when the data is updated
        void OnDataUpdated();
    };

}

#endif // DAYGOAL_P_H
