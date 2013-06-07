#ifndef CUSTOMGOAL_P_H
#define CUSTOMGOAL_P_H

#include "goal_p.h"
#include "customgoal.h"

#include <QDate>
#include <QPointer>

namespace UI {
    class CustomGoalWidget;
}

namespace Data {

    class CustomGoal;
    class Goal;

    class CustomGoalPrivate : public GoalPrivate
    {
        Q_OBJECT
        Q_DECLARE_PUBLIC(Data::CustomGoal)

    public:

        /// Default constructor
        explicit CustomGoalPrivate();

        /// Destructor
        ~CustomGoalPrivate();

        /// Initializes this widget
        void init();

        QDate startDate;
        int duration;
        QPointer<UI::CustomGoalWidget> widget;

        Q_DISABLE_COPY(CustomGoalPrivate)

    public Q_SLOTS:

        /// Slot called when the widget changes are accepted
        void WidgetChangesAccepted();

        /// Slot called when the data is updated
        void OnDataUpdated();
    };

}

#endif // CUSTOMGOAL_P_H
