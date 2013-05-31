#ifndef GOALWIDGETBASE_H
#define GOALWIDGETBASE_H

#include "goal.h"

#include <QWidget>

namespace UI
{

class GoalWidgetBase : public QWidget
{
    Q_OBJECT
public:
    explicit GoalWidgetBase(QWidget *parent = 0);
    
    virtual ~GoalWidgetBase() {};

    virtual void SetupWidget( const Data::Goal * inGoal ) = 0;

Q_SIGNALS:

    void ChangesAccepted();
    void ChangesCanceled();

public Q_SLOTS:
    
};

}

Q_DECLARE_METATYPE(UI::GoalWidgetBase *)

#endif // GOALWIDGETBASE_H
