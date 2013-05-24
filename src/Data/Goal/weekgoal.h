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

public:
    explicit WeekGoal(QObject *parent = 0);
    ~WeekGoal();

	void setColor( const QColor & color );
	QColor color() const;
	
	void setName( const QString & name );
	QString name() const;

	void setCriteria( const Data::Criteria & criteria );
	Data::Criteria criteria() const;
	
	QDateTime start() const;
	QDateTime end() const;

	void setStartDate( const QDate & date );
	QDate startDate() const;

    UI::GoalWidgetBase * CreateWidget();

public Q_SLOTS:
    
Q_SIGNALS:
   
 	void startDateChanged( QDate );

private:

    Q_DISABLE_COPY(WeekGoal);
    WeekGoalPrivate * const d_ptr;
};

}

QDataStream & operator<<(QDataStream & out, const Data::WeekGoal & goal);

QDataStream & operator>>(QDataStream & in, Data::WeekGoal & goal);

#endif // WEEKGOAL_H
