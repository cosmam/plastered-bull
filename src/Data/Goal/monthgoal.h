#ifndef MONTHGOAL_H
#define MONTHGOAL_H

#include "goal.h"
#include "timefunctions.h"

namespace Data {

    class MonthGoalPrivate;

    class MonthGoal : public Goal
    {
        Q_OBJECT
        Q_DECLARE_PRIVATE(Data::MonthGoal)
        Q_DISABLE_COPY(MonthGoal)

    public:

        /// Default constructor
        explicit MonthGoal(QObject *parent = 0);

        /// Destructor
        ~MonthGoal();

        /// Gets the goal start datetime
        QDateTime start() const;

        /// Gets the goal end datetime
        QDateTime end() const;

        /// Sets the goal month
        void setMonth( Time::Month month );

        /// Gets the goal month
        Time::Month month() const;

        /// Sets the goal year
        void setYear( int year );

        /// Gets the goal year
        int year() const;

        /// Creates a goal widget from this goal
        UI::GoalWidgetBase * CreateWidget();

    public Q_SLOTS:

    Q_SIGNALS:

        /// Signal emitted on month changed
        void monthChanged( Time::Month );

        /// Signal emitted on year changed
        void yearChanged( int );
    };

}

/// QDataStream ouput operator
QDataStream & operator<<(QDataStream & out, const Data::MonthGoal & goal);

/// QDataStream input operator
QDataStream & operator>>(QDataStream & in, Data::MonthGoal & goal);

#endif // MONTHGOAL_H
