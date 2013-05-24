#ifndef YEARGOALWIDGET_P_H
#define YEARGOALWIDGET_P_H

#include <QColor>
#include <QObject>
#include <QPointer>

class QColorDialog;

namespace Ui {
class YearGoalWidget;
}

namespace Data
{
    class YearGoal;
}

namespace UI
{

class YearGoalWidget;

class YearGoalWidgetPrivate : public QObject
{
    Q_OBJECT
    Q_DECLARE_PUBLIC(UI::YearGoalWidget);

public:
    explicit YearGoalWidgetPrivate(YearGoalWidget *parent);
    ~YearGoalWidgetPrivate();

    QColor color;
    QPointer<QColorDialog> colorDialog;

    void SetupWidget( const Data::YearGoal * goal );

    QString Name() const;
    int Year() const;

    Ui::YearGoalWidget * const ui;
    UI::YearGoalWidget * const q_ptr;

    Q_DISABLE_COPY(YearGoalWidgetPrivate);

public Q_SLOTS:

    void OnColorSelected( const QColor & inColor );

    void OnColorButtonClicked();
    void OnCancelClicked();
    void OnAcceptClicked();
};

}

#endif // YEARGOALWIDGET_P_H
