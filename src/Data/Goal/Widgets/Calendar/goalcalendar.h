#ifndef GOALCALENDAR_H
#define GOALCALENDAR_H

#include <QWidget>

namespace Data
{
    class Goal;
}

namespace UI
{

class GoalCalendarPrivate;

class GoalCalendar : public QWidget
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(UI::GoalCalendar);
    
public:

	enum ViewMode
	{
		DAY_VIEW_MODE = 0,
		WEEK_VIEW_MODE,
		MONTH_VIEW_MODE,
		YEAR_VIEW_MODE
	};

    explicit GoalCalendar(QWidget *parent = 0);
    ~GoalCalendar();
    
    void SetGoals( const QList<Data::Goal *> goals );
	
public Q_SLOTS:

	void RemoveGoal( Data::Goal * goal );	
	void UpdateGoal( Data::Goal * goal );
	void AddGoal( Data::Goal * goal );
	
private:

    Q_DISABLE_COPY(GoalCalendar);
    GoalCalendarPrivate * const d_ptr;
};

}

#endif // GOALCALENDAR_H
