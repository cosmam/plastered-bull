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

public:
    explicit DayGoal(QObject *parent = NULL);
    ~DayGoal();
	
	void setColor( const QColor & color );
	QColor color() const;
	
	void setName( const QString & name );
	QString name() const;

	void setCriteria( const Data::Criteria & criteria );
	Data::Criteria criteria() const;
	
	QDateTime start() const;
	QDateTime end() const;

	void setDate( const QDate & date );
	QDate date() const;
	
    UI::GoalWidgetBase * CreateWidget();
	
public Q_SLOTS:
    
Q_SIGNALS:

    void dateChanged( QDate );
	
private:

    Q_DISABLE_COPY(DayGoal);
    DayGoalPrivate * const d_ptr;
};

}

QDataStream & operator<<(QDataStream & out, const Data::DayGoal & goal);

QDataStream & operator>>(QDataStream & in, Data::DayGoal & goal);

#endif // DAYGOAL_H
