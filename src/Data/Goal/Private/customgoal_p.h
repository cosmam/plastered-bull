#ifndef CUSTOMGOAL_P_H
#define CUSTOMGOAL_P_H

#include "goal_p.h"
#include "customgoal.h"

#include <QDate>
#include <QPointer>

namespace UI
{
    class CustomGoalWidget;
}

namespace Data
{

class CustomGoal;
class Goal;

class CustomGoalPrivate : public GoalPrivate
{
    Q_OBJECT
    Q_DECLARE_PUBLIC(Data::CustomGoal);

public:
    explicit CustomGoalPrivate();
    ~CustomGoalPrivate();

    void init();

    QDate startDate;
    int duration;
    QPointer<UI::CustomGoalWidget> widget;

    Q_DISABLE_COPY(CustomGoalPrivate);

public Q_SLOTS:

    void WidgetChangesAccepted();
    void OnDataUpdated();
};

}

#endif // CUSTOMGOAL_P_H
