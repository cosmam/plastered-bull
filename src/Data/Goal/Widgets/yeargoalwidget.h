#ifndef YEARGOALWIDGET_H
#define YEARGOALWIDGET_H

#include "goalwidgetbase.h"

namespace UI
{

class YearGoalWidgetPrivate;

class YearGoalWidget : public UI::GoalWidgetBase
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(UI::YearGoalWidget);
    
public:
    explicit YearGoalWidget(QWidget * parent = NULL);
    ~YearGoalWidget();

    void SetupWidget( const Data::Goal * inGoal );

    QString Name() const;
	QColor Color() const;
	int Year() const;

private:

    Q_DISABLE_COPY(YearGoalWidget);
    YearGoalWidgetPrivate * const d_ptr;
};

}

#endif // YEARGOALWIDGET_H
