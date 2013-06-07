#ifndef WEEKGOALWIDGET_H
#define WEEKGOALWIDGET_H

#include "goalwidgetbase.h"

namespace Test {
    class WeekGoalWidgetTest;
}

namespace UI {

    class WeekGoalWidgetPrivate;

    class WeekGoalWidget : public UI::GoalWidgetBase
    {
        Q_OBJECT
        Q_DECLARE_PRIVATE(UI::WeekGoalWidget)
        Q_DISABLE_COPY(WeekGoalWidget)

    public:

        /// Default constructor
        explicit WeekGoalWidget(QWidget * parent = NULL);

        /// Destructor
        ~WeekGoalWidget();

        /// Sets this widget up based on the goal data
        void SetupWidget( const Data::Goal * inGoal );

        /// Gets the goal name
        QString Name() const;

        /// Gets the goal color
        QColor Color() const;

        /// Gets the goal start date
        QDate StartDate() const;

    private:

        friend class Test::WeekGoalWidgetTest;
        WeekGoalWidgetPrivate * const d_ptr;
    };

}

#endif // WEEKGOALWIDGET_H
