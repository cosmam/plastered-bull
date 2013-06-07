#ifndef MONTHGOALWIDGET_H
#define MONTHGOALWIDGET_H

#include "goalwidgetbase.h"
#include "timefunctions.h"

namespace Test {
    class MonthGoalWidgetTest;
}

namespace UI {

    class MonthGoalWidgetPrivate;

    class MonthGoalWidget : public UI::GoalWidgetBase
    {
        Q_OBJECT
        Q_DECLARE_PRIVATE(UI::MonthGoalWidget)
        Q_DISABLE_COPY(MonthGoalWidget)

    public:

        /// Default constructor
        explicit MonthGoalWidget(QWidget * parent = NULL);

        /// Destructor
        ~MonthGoalWidget();

        /// Sets up the widget based on the goal data
        void SetupWidget( const Data::Goal * inGoal );

        /// Gets the goal name
        QString Name() const;

        /// Gets the goal color
        QColor Color() const;

        /// Gets the goal month
        Time::Month Month() const;

        /// Gets the goal year
        int Year() const;

    private:

        friend class Test::MonthGoalWidgetTest;
        MonthGoalWidgetPrivate * const d_ptr;
    };

}

#endif // MONTHGOALWIDGET_H
