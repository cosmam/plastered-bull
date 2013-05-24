#ifndef MONTHGOAL_P_H
#define MONTHGOAL_P_H

#include "criteria.h"
#include "timefunctions.h"

#include <QColor>
#include <QObject>
#include <QPointer>

namespace UI
{
    class MonthGoalWidget;
}

namespace Data
{

class Goal;
class MonthGoal;

class MonthGoalPrivate : public QObject
{
    Q_OBJECT
    Q_DECLARE_PUBLIC(Data::MonthGoal);

public:
    explicit MonthGoalPrivate(MonthGoal *parent);

    QString name;
    QColor color;
    Data::Criteria criteria;
    Time::Month month;
    int year;
    QPointer<UI::MonthGoalWidget> widget;   
    MonthGoal * const q_ptr;

    Q_DISABLE_COPY(MonthGoalPrivate);

public Q_SLOTS:

    void WidgetChangesAccepted();
    void OnDataUpdated();
};

}
#endif // MONTHGOAL_P_H
