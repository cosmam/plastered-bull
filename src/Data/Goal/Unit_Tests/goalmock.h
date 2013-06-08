#ifndef GOALMOCK_H
#define GOALMOCK_H

#include "goal.h"

namespace UI {
    class GoalWidgetBase;
}

namespace Test {

    class GoalMock : public Data::Goal
    {
            Q_OBJECT
        public:
            explicit GoalMock(QObject *parent = 0);

            QDateTime start() const;                // LCOV_EXCL_LINE
            QDateTime end() const;                  // LCOV_EXCL_LINE

            UI::GoalWidgetBase * CreateWidget();    // LCOV_EXCL_LINE

        signals:

        public slots:

    };

}

#endif // GOALMOCK_H
