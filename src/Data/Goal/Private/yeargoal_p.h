#ifndef YEARGOALPRIVATE_H
#define YEARGOALPRIVATE_H

#include <QColor>
#include <QObject>
#include <QPointer>

#include "criteria.h"

namespace UI
{
    class YearGoalWidget;
}

namespace Data
{

class Goal;
class YearGoal;

class YearGoalPrivate : public QObject
{
    Q_OBJECT
    Q_DECLARE_PUBLIC(Data::YearGoal);

public:
    YearGoalPrivate( YearGoal * parent );

    QString name;
    QColor color;
    Data::Criteria criteria;
    int year;
    QPointer<UI::YearGoalWidget> widget;
    YearGoal * const q_ptr;

    Q_DISABLE_COPY(YearGoalPrivate);

public Q_SLOTS:

    void WidgetChangesAccepted();
    void OnDataUpdated();
};

}

#endif // YEARGOALPRIVATE_H
