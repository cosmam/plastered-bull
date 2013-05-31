#ifndef MONTHGOAL_H
#define MONTHGOAL_H

#include "goal.h"
#include "timefunctions.h"

namespace Data
{

class MonthGoalPrivate;

class MonthGoal : public Goal
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(Data::MonthGoal);
    Q_DISABLE_COPY(MonthGoal);

public:
    explicit MonthGoal(QObject *parent = 0);
    ~MonthGoal();
	
	QDateTime start() const;
	QDateTime end() const;
	
	void setMonth( Time::Month month );
	Time::Month month() const;
	
	void setYear( int year );
	int year() const;

    UI::GoalWidgetBase * CreateWidget();

public Q_SLOTS:
    
Q_SIGNALS:
    
	void monthChanged( Time::Month );
	void yearChanged( int );
};

}

QDataStream & operator<<(QDataStream & out, const Data::MonthGoal & goal);

QDataStream & operator>>(QDataStream & in, Data::MonthGoal & goal);

#endif // MONTHGOAL_H
