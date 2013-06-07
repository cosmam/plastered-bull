#ifndef YEARGOAL_H
#define YEARGOAL_H

#include "goal.h"

namespace Data {

    class YearGoalPrivate;

    class YearGoal : public Goal
    {
        Q_OBJECT
        Q_DECLARE_PRIVATE(Data::YearGoal)
        Q_DISABLE_COPY(YearGoal)

    public:

        /// Default constructor
        explicit YearGoal(QObject *parent = 0);

        /// Destrucotr
        ~YearGoal();

        /// Gets the start datetime
        QDateTime start() const;

        /// Gets the end datetime
        QDateTime end() const;

        /// Sets the goal year
        void setYear( int year );

        /// Gets the goal year
        int year() const;

        /// Signal emitted on start date changed
        UI::GoalWidgetBase * CreateWidget();

    public Q_SLOTS:

    Q_SIGNALS:

        /// Signal emitted on year changed
        void yearChanged( int );
    };

}

/// QDataStream output operator
QDataStream & operator<<(QDataStream & out, const Data::YearGoal & goal);

/// QDataStream input operator
QDataStream & operator>>(QDataStream & in, Data::YearGoal & goal);

#endif // YEARGOAL_H
