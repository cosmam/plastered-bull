#ifndef WEEKGOALWIDGET_P_H
#define WEEKGOALWIDGET_P_H

#include <QColor>
#include <QObject>
#include <QPointer>

class QColorDialog;

namespace Ui {
class WeekGoalWidget;
}

namespace Data
{
    class WeekGoal;
}

namespace UI
{

class WeekGoalWidget;

class WeekGoalWidgetPrivate : public QObject
{
    Q_OBJECT
    Q_DECLARE_PUBLIC(UI::WeekGoalWidget);

public:
    explicit WeekGoalWidgetPrivate(WeekGoalWidget *parent);
    ~WeekGoalWidgetPrivate();

    QColor color;
    QPointer<QColorDialog> colorDialog;

    void SetupWidget( const Data::WeekGoal * goal );

    QString Name() const;
    QDate StartDate() const;

    Ui::WeekGoalWidget * const ui;
    UI::WeekGoalWidget * const q_ptr;

    Q_DISABLE_COPY(WeekGoalWidgetPrivate);

public Q_SLOTS:

    void OnColorSelected( const QColor & inColor );

    void OnColorButtonClicked();
    void OnCancelClicked();
    void OnAcceptClicked();
};

}

#endif // WEEKGOALWIDGET_P_H
