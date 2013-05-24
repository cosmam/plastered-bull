#ifndef WEEKGOAL_P_H
#define WEEKGOAL_P_H

#include <QObject>
#include <QPointer>

namespace UI
{
    class WeekGoalWidget;
}

namespace Data
{

class CustomGoal;
class WeekGoal;

class WeekGoalPrivate : public QObject
{
    Q_OBJECT
    Q_DECLARE_PUBLIC(Data::WeekGoal);

public:
    explicit WeekGoalPrivate(WeekGoal *parent);
    
    QPointer<CustomGoal> goal;
    QPointer<UI::WeekGoalWidget> widget;
    WeekGoal * const q_ptr;

    Q_DISABLE_COPY(WeekGoalPrivate);

public Q_SLOTS:

    void WidgetChangesAccepted();
};

}

#endif // WEEKGOAL_P_H
