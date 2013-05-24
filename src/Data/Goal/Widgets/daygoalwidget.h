#ifndef DAYGOALWIDGET_H
#define DAYGOALWIDGET_H

#include "goalwidgetbase.h"

namespace UI
{

class DayGoalWidgetPrivate;

class DayGoalWidget : public UI::GoalWidgetBase
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(UI::DayGoalWidget);
    
public:
    explicit DayGoalWidget(QWidget * parent = NULL);
    ~DayGoalWidget();

    void SetupWidget( const Data::Goal * inGoal );

    QString Name() const;
	QColor Color() const;
	QDate Date() const;
    
private:

    Q_DISABLE_COPY(DayGoalWidget);
    DayGoalWidgetPrivate * const d_ptr;
};

}

#endif // DAYGOALWIDGET_H
