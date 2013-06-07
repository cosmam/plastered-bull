#ifndef DAYGOALWIDGET_H
#define DAYGOALWIDGET_H

#include "goalwidgetbase.h"

namespace Test {
    class DayGoalWidgetTest;
}

namespace UI {

    class DayGoalWidgetPrivate;

    class DayGoalWidget : public UI::GoalWidgetBase
    {
        Q_OBJECT
        Q_DECLARE_PRIVATE(UI::DayGoalWidget)
        Q_DISABLE_COPY(DayGoalWidget)

    public:

        /// Default constructor
        explicit DayGoalWidget(QWidget * parent = NULL);

        /// Destructor
        ~DayGoalWidget();

        /// Sets this widget up based on the goal data
        void SetupWidget( const Data::Goal * inGoal );

        /// Gets the goal name
        QString Name() const;

        /// Gets the goal color
        QColor Color() const;

        /// Gets the goal date
        QDate Date() const;

    private:

        friend class Test::DayGoalWidgetTest;
        DayGoalWidgetPrivate * const d_ptr;
    };

}

#endif // DAYGOALWIDGET_H
