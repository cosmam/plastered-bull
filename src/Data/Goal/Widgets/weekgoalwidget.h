#ifndef WEEKGOALWIDGET_H
#define WEEKGOALWIDGET_H

#include "goalwidgetbase.h"

namespace UI
{

class WeekGoalWidgetPrivate;

class WeekGoalWidget : public UI::GoalWidgetBase
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(UI::WeekGoalWidget);
    
public:
    explicit WeekGoalWidget(QWidget * parent = NULL);
    ~WeekGoalWidget();

    void SetupWidget( const Data::Goal * inGoal );

    QString Name() const;
	QColor Color() const;
	QDate StartDate() const;

private:

    Q_DISABLE_COPY(WeekGoalWidget);
    WeekGoalWidgetPrivate * const d_ptr;
};

}

#endif // WEEKGOALWIDGET_H
