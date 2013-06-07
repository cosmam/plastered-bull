#ifndef CUSTOMGOAL_H
#define CUSTOMGOAL_H

#include "goal.h"

namespace Data {

    class CustomGoalPrivate;

    class CustomGoal : public Goal
    {
        Q_OBJECT
        Q_DECLARE_PRIVATE(Data::CustomGoal)
        Q_DISABLE_COPY(CustomGoal)

    public:

        /// Default constructor
        explicit CustomGoal(QObject *parent = 0);

        /// Destructor
        ~CustomGoal();

        /// Gets the start datetime of the goal
        QDateTime start() const;

        /// Gets the end datetime of the goal
        QDateTime end() const;

        /// Sets the goal start date
        void setStartDate( const QDate & date );

        /// Gets the goal start date
        QDate startDate() const;

        /// Sets the goal duration
        void setDuration( int duration );

        /// Gets the goal duration
        int duration() const;

        /// Creates a goal widget from this goal
        UI::GoalWidgetBase * CreateWidget();

    public Q_SLOTS:

    Q_SIGNALS:

        /// Signal emitted when the start date is changed
        void startDateChanged( QDate );

        /// Signal emitted when the duration is changed
        void durationChanged( int );
    };

}

/// QDataStream output operator
QDataStream & operator<<(QDataStream & out, const Data::CustomGoal & goal);

/// QDataStream input operator
QDataStream & operator>>(QDataStream & in, Data::CustomGoal & goal);

#endif // CUSTOMGOAL_H
