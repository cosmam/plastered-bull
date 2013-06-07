#ifndef GOALMOCK_H
#define GOALMOCK_H

#include "goal.h"

namespace UI
{
    class GoalWidgetBase;
}

namespace Test
{

class GoalMock : public Data::Goal
{
        Q_OBJECT
    public:
        explicit GoalMock(QObject *parent = 0);
        
        QDateTime start() const;
        QDateTime end() const;

        UI::GoalWidgetBase * CreateWidget();

    signals:
        
    public slots:
        
};

}

#endif // GOALMOCK_H
