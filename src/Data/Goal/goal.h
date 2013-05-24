#ifndef GOAL_H
#define GOAL_H

#include "commontypes.h"
#include "criteria.h"

#include<QColor>
#include<QDateTime>
#include<QObject>
#include<QString>

namespace UI
{
    class GoalWidgetBase;
}

namespace Data
{

class GoalData;
class Goal : public QObject
{
	Q_OBJECT

public:

    Goal( QObject * parent = NULL );

    virtual ~Goal() {};
	
	virtual void setColor( const QColor & color ) = 0;
	virtual QColor color() const = 0;
	
	virtual void setName( const QString & name ) = 0;
	virtual QString name() const = 0;

	virtual void setCriteria( const Data::Criteria & criteria ) = 0;
	virtual Data::Criteria criteria() const = 0;
	
	virtual QDateTime start() const = 0;
	virtual QDateTime end() const = 0;
	
    virtual UI::GoalWidgetBase * CreateWidget() = 0;

    ID_t id() const;
	
Q_SIGNALS:

	void colorChanged( QColor );
    void nameChanged( QString );
	void criteriaChanged( Data::Criteria );
	void goalChanged( Data::Goal * );
};

}

#endif // GOAL_H
