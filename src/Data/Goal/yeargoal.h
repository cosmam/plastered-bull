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

public:
    explicit YearGoal(QObject *parent = 0);
    ~YearGoal();
	
	void setColor( const QColor & color );
	QColor color() const;
	
	void setName( const QString & name );
	QString name() const;

	void setCriteria( const Data::Criteria & criteria );
	Data::Criteria criteria() const;
	
	QDateTime start() const;
	QDateTime end() const;

	void setYear( int year );
	int year() const;

    UI::GoalWidgetBase * CreateWidget();

public Q_SLOTS:
    
Q_SIGNALS:

   	void yearChanged( int );
 
private:

    Q_DISABLE_COPY(YearGoal);
    YearGoalPrivate * const d_ptr;
};

}

QDataStream & operator<<(QDataStream & out, const Data::YearGoal & goal);

QDataStream & operator>>(QDataStream & in, Data::YearGoal & goal);

#endif // YEARGOAL_H
