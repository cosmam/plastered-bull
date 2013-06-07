#ifndef WEEKGOAL_P_H
#define WEEKGOAL_P_H

#include "goal_p.h"
#include "weekgoal.h"

#include <QPointer>

namespace UI {
    class WeekGoalWidget;
}

namespace Data {

    class CustomGoal;
    class WeekGoal;

    class WeekGoalPrivate : public GoalPrivate
    {
        Q_OBJECT
        Q_DECLARE_PUBLIC(Data::WeekGoal)
        Q_DISABLE_COPY(WeekGoalPrivate)

    public:

        /// Default constructor
        explicit WeekGoalPrivate();

        /// Destructor
        ~WeekGoalPrivate();

        /// Initializes this widget
        void init();

        QPointer<CustomGoal> goal;
        QPointer<UI::WeekGoalWidget> widget;

    public Q_SLOTS:

        /// Slot called when the widget changes are accepted
        void WidgetChangesAccepted();
    };

}

#endif // WEEKGOAL_P_H
