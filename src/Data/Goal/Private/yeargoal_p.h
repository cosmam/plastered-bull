#ifndef YEARGOAL_P_H
#define YEARGOAL_P_H

#include "goal_p.h"
#include "yeargoal.h"

#include <QPointer>

namespace UI {
    class YearGoalWidget;
}

namespace Data {

    class Goal;
    class YearGoal;

    class YearGoalPrivate : public GoalPrivate
    {
        Q_OBJECT
        Q_DECLARE_PUBLIC(Data::YearGoal)
        Q_DISABLE_COPY(YearGoalPrivate)

    public:

        /// Default constructor
        YearGoalPrivate();

        /// Destructor
        ~YearGoalPrivate();

        /// Initializes this widget
        void init();

        int year;
        QPointer<UI::YearGoalWidget> widget;

    public Q_SLOTS:

        /// Slot called when the widget changes are accepted
        void WidgetChangesAccepted();

        /// Slot called when the data is updated
        void OnDataUpdated();
    };

}

#endif // YEARGOAL_P_H
