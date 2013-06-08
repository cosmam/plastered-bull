#ifndef GOALCALENDARITEM_H
#define GOALCALENDARITEM_H

#include "selectablewidget.h"

namespace UI {

    class GoalCalendarItemPrivate;

    class GoalCalendarItem : public SelectableWidget
    {
        Q_OBJECT
        Q_DECLARE_PRIVATE(UI::GoalCalendarItem)
        Q_DISABLE_COPY(GoalCalendarItem)

    public:

        /// Default constructor
        explicit GoalCalendarItem(QWidget *parent = 0);

        /// Virtual destructor
        virtual ~GoalCalendarItem() {}      // LCOV_EXCL_LINE

    public Q_SLOTS:

    Q_SIGNALS:

    protected:

        /// Overloaded constructor for d-pointer initialization
        explicit GoalCalendarItem(GoalCalendarItemPrivate & d, QWidget *parent = 0);
    };

}

#endif // GOALCALENDARITEM_H
