#ifndef CUSTOMGOAL_H
#define CUSTOMGOAL_H

#include "goal.h"

namespace Data
{

class CustomGoalPrivate;

class CustomGoal : public Goal
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(Data::CustomGoal);
    Q_DISABLE_COPY(CustomGoal);

public:
    explicit CustomGoal(QObject *parent = 0);
    ~CustomGoal();
	
	QDateTime start() const;
	QDateTime end() const;

	void setStartDate( const QDate & date );
	QDate startDate() const;

	void setDuration( int duration );
	int duration() const;
	
    UI::GoalWidgetBase * CreateWidget();
    
public Q_SLOTS:

Q_SIGNALS:
    
	void startDateChanged( QDate );
	void durationChanged( int );
};

}

QDataStream & operator<<(QDataStream & out, const Data::CustomGoal & goal);

QDataStream & operator>>(QDataStream & in, Data::CustomGoal & goal);

#endif // CUSTOMGOAL_H
