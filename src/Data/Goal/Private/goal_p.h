#ifndef GOAL_P_H
#define GOAL_P_H

#include "challenge_p.h"
#include "goal.h"

#include "commontypes.h"
#include "criteria.h"

#include <QColor>
#include <QPointer>
#include <QString>

namespace UI
{
    class GoalWidgetBase;
}

namespace Data
{

class Goal;

class GoalPrivate : public ChallengePrivate
{
	Q_OBJECT
    Q_DECLARE_PUBLIC(Data::Goal);
    //TODO - declare properties

public:

    GoalPrivate();
    virtual ~GoalPrivate() {};
	
    virtual void init();

    QColor color;
    QString name;
    QPointer<Data::Criteria> criteria;

    Q_DISABLE_COPY(GoalPrivate);

public Q_SLOTS:

};

}

#endif // GOAL_P_H
