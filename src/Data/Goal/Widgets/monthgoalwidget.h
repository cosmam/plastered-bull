#ifndef MONTHGOALWIDGET_H
#define MONTHGOALWIDGET_H

#include "goalwidgetbase.h"
#include "timefunctions.h"

namespace UI
{

class MonthGoalWidgetPrivate;

class MonthGoalWidget : public UI::GoalWidgetBase
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(UI::MonthGoalWidget);
    
public:
    explicit MonthGoalWidget(QWidget * parent = NULL);
    ~MonthGoalWidget();

    void SetupWidget( const Data::Goal * inGoal );

    QString Name() const;
	QColor Color() const;
	Time::Month Month() const;
	int Year() const;

private:

    Q_DISABLE_COPY(MonthGoalWidget);
    MonthGoalWidgetPrivate * const d_ptr;
};

}

#endif // MONTHGOALWIDGET_H
