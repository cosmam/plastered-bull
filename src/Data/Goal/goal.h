#ifndef GOAL_H
#define GOAL_H

#include "challenge.h"
#include "commontypes.h"
#include "criteria.h"

#include<QColor>
#include<QString>

namespace UI
{
    class GoalWidgetBase;
}

namespace Data
{

class GoalPrivate;

class Goal : public Challenge
{
	Q_OBJECT
    Q_DECLARE_PRIVATE(Data::Goal);

public:

    Goal( QObject * parent = 0 );
    virtual ~Goal() {};
	
    void setColor( const QColor & color );
    QColor color() const;
	
    void setName( const QString & name );
    QString name() const;

    void setCriteria( Data::Criteria * criteria );
    const Data::Criteria * criteria() const;
		
    virtual UI::GoalWidgetBase * CreateWidget() = 0;

    ID_t id() const;
	
public Q_SLOTS:

Q_SIGNALS:

	void colorChanged( QColor );
    void nameChanged( QString );
    void criteriaChanged( Data::Criteria * );
	void goalChanged( Data::Goal * );

protected:
    explicit Goal(GoalPrivate & d, QObject * parent = 0);

    Q_DISABLE_COPY(Goal);
};

}

#endif // GOAL_H
