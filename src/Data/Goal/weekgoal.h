#ifndef WEEKGOAL_H
#define WEEKGOAL_H

#include "goal.h"

namespace Data {

    class WeekGoalPrivate;

    class WeekGoal : public Goal
    {
        Q_OBJECT
        Q_DECLARE_PRIVATE(Data::WeekGoal)
        Q_DISABLE_COPY(WeekGoal)

    public:

        /// Default constructor
        explicit WeekGoal(QObject *parent = 0);

        /// Destructor
        ~WeekGoal();

        /// Gets the goal start datetime
        QDateTime start() const;

        /// Gets the goal end datetime
        QDateTime end() const;

        /// Sets the goal start date
        void setStartDate( const QDate & date );

        /// Gets the goal start date
        QDate startDate() const;

        /// Creates a goal widget from this goal
        UI::GoalWidgetBase * CreateWidget();

    public Q_SLOTS:

    Q_SIGNALS:

        /// Signal emitted on start date changed
        void startDateChanged( QDate );
    };

}

/// QDataStream output operator
QDataStream & operator<<(QDataStream & out, const Data::WeekGoal & goal);


/// QDataStream input operator
QDataStream & operator>>(QDataStream & in, Data::WeekGoal & goal);

#endif // WEEKGOAL_H
