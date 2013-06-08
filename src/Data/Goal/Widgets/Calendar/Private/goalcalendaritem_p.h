#ifndef GOALCALENDARITEM_P_H
#define GOALCALENDARITEM_P_H

#include "selectablewidget_p.h"
#include "goalcalendaritem.h"

namespace UI {

    class GoalCalendarItemPrivate : public SelectableWidgetPrivate
    {
        Q_OBJECT
        Q_DECLARE_PUBLIC(UI::GoalCalendarItem)
        Q_DISABLE_COPY(GoalCalendarItemPrivate)

    public:

        /// Default constructor
        explicit GoalCalendarItemPrivate();

        /// Virtual destructor
        virtual ~GoalCalendarItemPrivate() {}       // LCOV_EXCL_LINE

        /// Virtual function to initialize this widget
        virtual void init();

    public Q_SLOTS:

    };

}

#endif // GOALCALENDARITEM_P_H
