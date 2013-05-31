#ifndef DAYGOALWIDGET_P_H
#define DAYGOALWIDGET_P_H

#include <QColor>
#include <QObject>
#include <QPointer>

class QColorDialog;

namespace Ui {
class DayGoalWidget;
}

namespace Data
{
    class DayGoal;
}

namespace UI
{

class DayGoalWidget;

class DayGoalWidgetPrivate : public QObject
{
    Q_OBJECT
    Q_DECLARE_PUBLIC(UI::DayGoalWidget);

public:
    explicit DayGoalWidgetPrivate(DayGoalWidget *parent);
    ~DayGoalWidgetPrivate();

    QColor color;
    QPointer<QColorDialog> colorDialog;

    void SetupWidget( const Data::DayGoal * goal );

    QString Name() const;
    QDate Date() const;

    Ui::DayGoalWidget * const ui;
    UI::DayGoalWidget * const q_ptr;

    Q_DISABLE_COPY(DayGoalWidgetPrivate);

public Q_SLOTS:

    void OnColorSelected( const QColor & inColor );

    void OnColorButtonClicked();
    void OnCancelClicked();
    void OnAcceptClicked();
};

}

#endif // DAYGOALWIDGET_P_H
