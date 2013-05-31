#ifndef DAYGOAL_H
#define DAYGOAL_H

#include "goal.h"

#include <QDate>

namespace Data
{

class DayGoalPrivate;

class DayGoal : public Goal
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(Data::DayGoal);
    Q_DISABLE_COPY(DayGoal);

public:
    explicit DayGoal(QObject *parent = 0);
    ~DayGoal();
	
    QDateTime start() const;
	QDateTime end() const;

	void setDate( const QDate & date );
	QDate date() const;
	
    UI::GoalWidgetBase * CreateWidget();
	
public Q_SLOTS:
    
Q_SIGNALS:

    void dateChanged( QDate );
};

}

QDataStream & operator<<(QDataStream & out, const Data::DayGoal & goal);

QDataStream & operator>>(QDataStream & in, Data::DayGoal & goal);

#endif // DAYGOAL_H
