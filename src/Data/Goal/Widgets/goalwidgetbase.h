#ifndef GOALWIDGETBASE_H
#define GOALWIDGETBASE_H

#include "goal.h"

#include <QWidget>

namespace UI {

class GoalWidgetBase : public QWidget
{
    Q_OBJECT

    public:

        /// Default constructor
        explicit GoalWidgetBase(QWidget *parent = 0);

        /// Virtual destructor
        virtual ~GoalWidgetBase() {}        // LCOV_EXCL_LINE

        /// Virtual function to set this widget up based on goal data
        virtual void SetupWidget( const Data::Goal * inGoal ) = 0;

    Q_SIGNALS:

        /// Signal emitted on changes accepted
        void ChangesAccepted();

        /// Signal emitted on changes canceled
        void ChangesCanceled();

    public Q_SLOTS:

    };

}

Q_DECLARE_METATYPE(UI::GoalWidgetBase *)

#endif // GOALWIDGETBASE_H
