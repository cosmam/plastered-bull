#ifndef CUSTOMGOALWIDGET_P_H
#define CUSTOMGOALWIDGET_P_H

#include <QColor>
#include <QObject>
#include <QPointer>

class QColorDialog;

namespace Ui {
class CustomGoalWidget;
}

namespace Data
{
    class CustomGoal;
}

namespace UI
{

class CustomGoalWidget;

class CustomGoalWidgetPrivate : public QObject
{
    Q_OBJECT
    Q_DECLARE_PUBLIC(UI::CustomGoalWidget);

public:
    explicit CustomGoalWidgetPrivate(CustomGoalWidget *parent);
    ~CustomGoalWidgetPrivate();

    QColor color;
    QPointer<QColorDialog> colorDialog;

    void SetupWidget( const Data::CustomGoal * goal );

    QString Name() const;
    QDate StartDate() const;
    int Duration() const;

    Ui::CustomGoalWidget * const ui;
    UI::CustomGoalWidget * const q_ptr;

    Q_DISABLE_COPY(CustomGoalWidgetPrivate);

public Q_SLOTS:

    void OnColorSelected( const QColor & inColor );
    void OnStartDateChanged( const QDate & date );

    void OnColorButtonClicked();
    void OnCancelClicked();
    void OnAcceptClicked();
};

}

#endif // CUSTOMGOALWIDGET_P_H
