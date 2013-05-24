#ifndef CUSTOMGOAL_P_H
#define CUSTOMGOAL_P_H

#include "criteria.h"

#include <QColor>
#include <QDate>
#include <QObject>
#include <QPointer>

namespace UI
{
    class CustomGoalWidget;
}

namespace Data
{

class CustomGoal;
class Goal;

class CustomGoalPrivate : public QObject
{
    Q_OBJECT
    Q_DECLARE_PUBLIC(Data::CustomGoal);

public:
    explicit CustomGoalPrivate(CustomGoal *parent);
    
    QString name;
    QColor color;
    Data::Criteria criteria;
    QDate startDate;
    int duration;
    QPointer<UI::CustomGoalWidget> widget;
    CustomGoal * const q_ptr;

    Q_DISABLE_COPY(CustomGoalPrivate);

public Q_SLOTS:

    void WidgetChangesAccepted();
    void OnDataUpdated();
};

}

#endif // CUSTOMGOAL_P_H
