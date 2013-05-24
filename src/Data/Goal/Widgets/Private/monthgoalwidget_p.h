#ifndef MONTHGOALWIDGET_P_H
#define MONTHGOALWIDGET_P_H

#include "timefunctions.h"

#include <QColor>
#include <QObject>
#include <QPointer>

class QColorDialog;

namespace Ui {
class MonthGoalWidget;
}

namespace Data
{
    class MonthGoal;
}

namespace UI
{

class MonthGoalWidget;

class MonthGoalWidgetPrivate : public QObject
{
    Q_OBJECT
    Q_DECLARE_PUBLIC(UI::MonthGoalWidget);

public:
    explicit MonthGoalWidgetPrivate(MonthGoalWidget *parent);
    ~MonthGoalWidgetPrivate();

    QColor color;
    QPointer<QColorDialog> colorDialog;

    void SetupWidget( const Data::MonthGoal * goal );

    QString Name() const;
    Time::Month Month() const;
    int Year() const;

    Ui::MonthGoalWidget * const ui;
    UI::MonthGoalWidget * const q_ptr;

    Q_DISABLE_COPY(MonthGoalWidgetPrivate);

public Q_SLOTS:

    void OnColorSelected( const QColor & inColor );

    void OnColorButtonClicked();
    void OnCancelClicked();
    void OnAcceptClicked();
};

}

#endif // MONTHGOALWIDGET_P_H
