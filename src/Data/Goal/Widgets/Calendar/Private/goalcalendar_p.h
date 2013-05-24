#ifndef GOALCALENDAR_P_H
#define GOALCALENDAR_P_H

#include <QList>
#include <QObject>
#include <QPointer>

class QDialog;

namespace Ui {
class GoalCalendar;
}

namespace Data
{
    class Goal;
}

namespace UI
{

class GoalCalendar;

class GoalWidgetBase;

class GoalCalendarPrivate : public QObject
{
    Q_OBJECT
    Q_DECLARE_PUBLIC(UI::GoalCalendar);

public:
    explicit GoalCalendarPrivate( GoalCalendar * parent );
	~GoalCalendarPrivate();

    void MakeGoalConnections( Data::Goal * goal );
    void MakeConnections();
    void CreateDialog( Data::Goal * goal );

    QList<Data::Goal *> goals;
    QPointer<QDialog> goalDialog;
    QPointer<Data::Goal> newGoal;

    Ui::GoalCalendar * const ui;
    GoalCalendar * const q_ptr;

    Q_DISABLE_COPY(GoalCalendarPrivate);

public Q_SLOTS:

    void OnDestroyed( QObject * object );

    void OnMonthChanged( int month );
    void OnYearChanged( QString year );

    void OnCustomGoalClicked();
    void OnDayGoalClicked();
    void OnMonthGoalClicked();
    void OnWeekGoalClicked();
    void OnYearGoalClicked();

    void OnDialogCanceled();
};

}

#endif // GOALCALENDAR_P_H
