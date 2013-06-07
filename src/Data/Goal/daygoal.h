#ifndef DAYGOAL_H
#define DAYGOAL_H

#include "goal.h"

#include <QDate>

namespace Data {

    class DayGoalPrivate;

    class DayGoal : public Goal
    {
        Q_OBJECT
        Q_DECLARE_PRIVATE(Data::DayGoal)
        Q_DISABLE_COPY(DayGoal)

    public:

        /// Default constructor
        explicit DayGoal(QObject *parent = 0);

        /// Destructor
        ~DayGoal();

        /// Gets the goal start datetime
        QDateTime start() const;

        /// Gets the goal end datetime
        QDateTime end() const;

        /// Sets the goal date
        void setDate( const QDate & date );

        /// Gets the goal date
        QDate date() const;

        /// Creates a goal widget from this goal
        UI::GoalWidgetBase * CreateWidget();

    public Q_SLOTS:

    Q_SIGNALS:

        /// Signal emitted on date changed
        void dateChanged( QDate );
    };

}

/// QDataStream output operator
QDataStream & operator<<(QDataStream & out, const Data::DayGoal & goal);

/// QDataStream input operator
QDataStream & operator>>(QDataStream & in, Data::DayGoal & goal);

#endif // DAYGOAL_H
