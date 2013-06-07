#ifndef GOALCALENDAR_H
#define GOALCALENDAR_H

#include <QWidget>

namespace Data {
    class Goal;
}

namespace UI {

    class GoalCalendarPrivate;

    class GoalCalendar : public QWidget
    {
        Q_OBJECT
        Q_DECLARE_PRIVATE(UI::GoalCalendar)
        Q_DISABLE_COPY(GoalCalendar)

    public:

        enum ViewMode
        {
            DAY_VIEW_MODE = 0,
            WEEK_VIEW_MODE,
            MONTH_VIEW_MODE,
            YEAR_VIEW_MODE
        };

        /// Default constructor
        explicit GoalCalendar(QWidget *parent = 0);

        /// Destructor
        ~GoalCalendar();

        /// Sets the list of goals
        void SetGoals( const QList<Data::Goal *> goals );

    public Q_SLOTS:

        /// Slot to remove a goal
        void RemoveGoal( Data::Goal * goal );

        /// Slot to update a goal
        void UpdateGoal( Data::Goal * goal );

        /// Slot to add a goal
        void AddGoal( Data::Goal * goal );

    private:

        GoalCalendarPrivate * const d_ptr;
    };

}

#endif // GOALCALENDAR_H
