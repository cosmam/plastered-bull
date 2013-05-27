#ifndef GOALCALENDARITEM_P_H
#define GOALCALENDARITEM_P_H

#include "selectablewidget_p.h"
#include "goalcalendaritem.h"

namespace UI
{

class GoalCalendarItemPrivate : public SelectableWidgetPrivate
{
    Q_OBJECT
    Q_DECLARE_PUBLIC(UI::GoalCalendarItem);

public:
    explicit GoalCalendarItemPrivate();
    virtual ~GoalCalendarItemPrivate() {};

    virtual void init();

    Q_DISABLE_COPY(GoalCalendarItemPrivate);

public Q_SLOTS:

};

}

#endif // GOALCALENDARITEM_P_H
