#ifndef YEARGOAL_H
#define YEARGOAL_H

#include "goal.h"

namespace Data
{

class YearGoalPrivate;

class YearGoal : public Goal
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(Data::YearGoal);
    Q_DISABLE_COPY(YearGoal);

public:
    explicit YearGoal(QObject *parent = 0);
    ~YearGoal();
	
	QDateTime start() const;
	QDateTime end() const;

	void setYear( int year );
	int year() const;

    UI::GoalWidgetBase * CreateWidget();

public Q_SLOTS:
    
Q_SIGNALS:

   	void yearChanged( int ); 
};

}

QDataStream & operator<<(QDataStream & out, const Data::YearGoal & goal);

QDataStream & operator>>(QDataStream & in, Data::YearGoal & goal);

#endif // YEARGOAL_H
