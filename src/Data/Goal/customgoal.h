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

public:
    explicit CustomGoal(QObject *parent = 0);
    ~CustomGoal();
	
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

	void setDuration( int duration );
	int duration() const;
	
    UI::GoalWidgetBase * CreateWidget();
    
public Q_SLOTS:

Q_SIGNALS:
    
	void startDateChanged( QDate );
	void durationChanged( int );
	
private:

    Q_DISABLE_COPY(CustomGoal);
    CustomGoalPrivate * const d_ptr;
};

}

QDataStream & operator<<(QDataStream & out, const Data::CustomGoal & goal);

QDataStream & operator>>(QDataStream & in, Data::CustomGoal & goal);

#endif // CUSTOMGOAL_H
