#ifndef DAYGOAL_P_H
#define DAYGOAL_P_H

#include "goal_p.h"
#include "daygoal.h"

#include <QDate>
#include <QPointer>

namespace UI
{
    class DayGoalWidget;
}

namespace Data
{

class DayGoal;
class Goal;

class DayGoalPrivate : public GoalPrivate
{
    Q_OBJECT
    Q_DECLARE_PUBLIC(Data::DayGoal);
    Q_DISABLE_COPY(DayGoalPrivate);

public:
    explicit DayGoalPrivate();
    ~DayGoalPrivate();
    
    void init();

    QDate date;
    QPointer<UI::DayGoalWidget> widget;   

public Q_SLOTS:

    void WidgetChangesAccepted();
    void OnDataUpdated();
};

}

#endif // DAYGOAL_P_H
