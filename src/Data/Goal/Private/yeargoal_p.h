#ifndef YEARGOAL_P_H
#define YEARGOAL_P_H

#include "goal_p.h"
#include "yeargoal.h"

#include <QPointer>

namespace UI
{
    class YearGoalWidget;
}

namespace Data
{

class Goal;
class YearGoal;

class YearGoalPrivate : public GoalPrivate
{
    Q_OBJECT
    Q_DECLARE_PUBLIC(Data::YearGoal);
    Q_DISABLE_COPY(YearGoalPrivate);

public:
    YearGoalPrivate();
    ~YearGoalPrivate();

    void init();

    int year;
    QPointer<UI::YearGoalWidget> widget;

public Q_SLOTS:

    void WidgetChangesAccepted();
    void OnDataUpdated();
};

}

#endif // YEARGOAL_P_H
