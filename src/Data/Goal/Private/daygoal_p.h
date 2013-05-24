#ifndef DAYGOAL_P_H
#define DAYGOAL_P_H

#include "criteria.h"

#include <QColor>
#include <QDate>
#include <QObject>
#include <QPointer>

namespace UI
{
    class DayGoalWidget;
}

namespace Data
{

class DayGoal;
class Goal;

class DayGoalPrivate : public QObject
{
    Q_OBJECT
    Q_DECLARE_PUBLIC(Data::DayGoal);

public:
    explicit DayGoalPrivate(DayGoal *parent);
    
    QString name;
    QColor color;
    Data::Criteria criteria;
    QDate date;
    QPointer<UI::DayGoalWidget> widget;   
    DayGoal * const q_ptr;

    Q_DISABLE_COPY(DayGoalPrivate);

public Q_SLOTS:

    void WidgetChangesAccepted();
    void OnDataUpdated();
};

}

#endif // DAYGOAL_P_H
