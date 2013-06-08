#ifndef GOAL_P_H
#define GOAL_P_H

#include "challenge_p.h"
#include "goal.h"

#include <QColor>
#include <QString>

namespace UI {
    class GoalWidgetBase;
}

namespace Data {

    class Criteria;
    class Goal;

    class GoalPrivate : public ChallengePrivate
    {
        Q_OBJECT
        Q_DECLARE_PUBLIC(Data::Goal)
        //TODO - declare properties

    public:

        /// Default constructor
        GoalPrivate();

        /// Virtual destructor
        virtual ~GoalPrivate() {}       // LCOV_EXCL_LINE

        /// Virtual function to initialize this widget
        virtual void init();

        QColor color;
        QString name;

        Q_DISABLE_COPY(GoalPrivate)

    public Q_SLOTS:

    };

}

#endif // GOAL_P_H
