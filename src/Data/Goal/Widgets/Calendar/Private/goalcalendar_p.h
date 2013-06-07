#ifndef GOALCALENDAR_P_H
#define GOALCALENDAR_P_H

#include <QList>
#include <QObject>
#include <QPointer>

class QDialog;

namespace Ui {
class GoalCalendar;
}

namespace Data  {
    class Goal;
}

namespace UI    {

    class CalendarModel;
    class GoalCalendar;
    class GoalWidgetBase;
    class SelectionManager;

    class GoalCalendarPrivate : public QObject
    {
        Q_OBJECT
        Q_DECLARE_PUBLIC(UI::GoalCalendar)
        Q_DISABLE_COPY(GoalCalendarPrivate)

    public:

        /// Default constructor
        explicit GoalCalendarPrivate( GoalCalendar * parent );

        /// Destructor
        ~GoalCalendarPrivate();

        /// Makes the connections for the given goal
        void MakeGoalConnections( Data::Goal * goal );

        /// Makes the connections for this widget
        void MakeConnections();

        /// Creates the dialog for a goal
        void CreateDialog( Data::Goal * goal );

        /// Populates the calendar model
        void PopulateModel();

        QList<Data::Goal *> goals;
        QPointer<QDialog> goalDialog;
        QPointer<Data::Goal> newGoal;
        UI::CalendarModel * model;
        UI::SelectionManager * manager;

        Ui::GoalCalendar * const ui;
        GoalCalendar * const q_ptr;

    public Q_SLOTS:

        /// Slot called when a goal is destroyed
        void OnDestroyed( QObject * object );

        /// Slot called when the month is changed
        void OnMonthChanged( int month );

        /// Slot called when the year is changed
        void OnYearChanged( QString year );

        /// Slot called when the custom goal button is clicked
        void OnCustomGoalClicked();

        /// Slot called when the day goal button is clicked
        void OnDayGoalClicked();

        /// Slot called when the month goal button is clicked
        void OnMonthGoalClicked();

        /// Slot called when the week goal button is clicked
        void OnWeekGoalClicked();

        /// Slot called when the year goal button is clicked
        void OnYearGoalClicked();

        /// Slot called when the dialog is canceled
        void OnDialogCanceled();

        /// Slot called to enable/disable updates
        void SetUpdatesEnabled(bool enabled);
    };

}

#endif // GOALCALENDAR_P_H
