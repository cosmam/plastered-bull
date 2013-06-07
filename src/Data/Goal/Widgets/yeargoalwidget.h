#ifndef YEARGOALWIDGET_H
#define YEARGOALWIDGET_H

#include "goalwidgetbase.h"

namespace Test {
    class YearGoalWidgetTest;
}

namespace UI {

    class YearGoalWidgetPrivate;

    class YearGoalWidget : public UI::GoalWidgetBase
    {
        Q_OBJECT
        Q_DECLARE_PRIVATE(UI::YearGoalWidget)
        Q_DISABLE_COPY(YearGoalWidget)

    public:

        /// Default constructor
        explicit YearGoalWidget(QWidget * parent = NULL);

        /// Destructor
        ~YearGoalWidget();

        /// Sets this widget up based on the goal data
        void SetupWidget( const Data::Goal * inGoal );

        /// Gets the goal name
        QString Name() const;

        /// Gets the goal color
        QColor Color() const;

        /// Gets the goal year
        int Year() const;

    private:

        friend class Test::YearGoalWidgetTest;
        YearGoalWidgetPrivate * const d_ptr;
    };

}

#endif // YEARGOALWIDGET_H
