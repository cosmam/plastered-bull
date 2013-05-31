#ifndef GOALCALENDARITEM_H
#define GOALCALENDARITEM_H

#include "selectablewidget.h"

namespace UI
{

class GoalCalendarItemPrivate;

class GoalCalendarItem : public SelectableWidget
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(UI::GoalCalendarItem);

public:
    explicit GoalCalendarItem(QWidget *parent = 0);
    virtual ~GoalCalendarItem() {};
    
public Q_SLOTS:

Q_SIGNALS:

protected:
	explicit GoalCalendarItem(GoalCalendarItemPrivate & d, QWidget *parent = 0);

    Q_DISABLE_COPY(GoalCalendarItem);
};

}

#endif // GOALCALENDARITEM_H
