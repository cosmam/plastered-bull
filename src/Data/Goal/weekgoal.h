#ifndef WEEKGOAL_H
#define WEEKGOAL_H

#include "goal.h"

namespace Data
{

class WeekGoalPrivate;

class WeekGoal : public Goal
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(Data::WeekGoal);
    Q_DISABLE_COPY(WeekGoal);

public:
    explicit WeekGoal(QObject *parent = 0);
    ~WeekGoal();

	QDateTime start() const;
	QDateTime end() const;

	void setStartDate( const QDate & date );
	QDate startDate() const;

    UI::GoalWidgetBase * CreateWidget();

public Q_SLOTS:
    
Q_SIGNALS:
   
 	void startDateChanged( QDate );
};

}

QDataStream & operator<<(QDataStream & out, const Data::WeekGoal & goal);

QDataStream & operator>>(QDataStream & in, Data::WeekGoal & goal);

#endif // WEEKGOAL_H
