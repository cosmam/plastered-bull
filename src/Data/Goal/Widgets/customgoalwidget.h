#ifndef CUSTOMGOALWIDGET_H
#define CUSTOMGOALWIDGET_H

#include "goalwidgetbase.h"

namespace Test {
    class CustomGoalWidgetTest;
}

namespace UI {

    class CustomGoalWidgetPrivate;

    class CustomGoalWidget : public UI::GoalWidgetBase
    {
        Q_OBJECT
        Q_DECLARE_PRIVATE(UI::CustomGoalWidget)
        Q_DISABLE_COPY(CustomGoalWidget)

        public:

            /// Default constructor
            explicit CustomGoalWidget(QWidget * parent = NULL);

            /// Destructor
            ~CustomGoalWidget();

            /// Sets this widget up based on the goal data
            void SetupWidget( const Data::Goal * inGoal );

            /// Gets the goal name
            QString Name() const;

            /// Gets the goal color
            QColor Color() const;

            /// Gets the goal start date
            QDate StartDate() const;

            /// Gets the goal duration
            int Duration() const;

        private:

            friend class Test::CustomGoalWidgetTest;
            CustomGoalWidgetPrivate * const d_ptr;
    };

}

#endif // CUSTOMGOALWIDGET_H
