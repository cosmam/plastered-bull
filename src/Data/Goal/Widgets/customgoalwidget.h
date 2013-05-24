#ifndef CUSTOMGOALWIDGET_H
#define CUSTOMGOALWIDGET_H

#include "goalwidgetbase.h"

namespace UI
{

class CustomGoalWidgetPrivate;

class CustomGoalWidget : public UI::GoalWidgetBase
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(UI::CustomGoalWidget);
    
public:
    explicit CustomGoalWidget(QWidget * parent = NULL);
    ~CustomGoalWidget();

    void SetupWidget( const Data::Goal * inGoal );

    QString Name() const;
	QColor Color() const;
	QDate StartDate() const;
	int Duration() const;

private:

    Q_DISABLE_COPY(CustomGoalWidget);
    CustomGoalWidgetPrivate * const d_ptr;
};

}

#endif // CUSTOMGOALWIDGET_H
