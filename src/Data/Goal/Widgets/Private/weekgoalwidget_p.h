#ifndef WEEKGOALWIDGET_P_H
#define WEEKGOALWIDGET_P_H

#include <QColor>
#include <QObject>
#include <QPointer>

class QColorDialog;

namespace Ui {
    class WeekGoalWidget;
}

namespace Data {
    class WeekGoal;
}

namespace UI {

    class WeekGoalWidget;

    class WeekGoalWidgetPrivate : public QObject
    {
        Q_OBJECT
        Q_DECLARE_PUBLIC(UI::WeekGoalWidget)
        Q_DISABLE_COPY(WeekGoalWidgetPrivate)

    public:

        /// Default constructor
        explicit WeekGoalWidgetPrivate(WeekGoalWidget *parent);

        /// Destructor
        ~WeekGoalWidgetPrivate();

        /// Sets up this widget based on the goal data
        void SetupWidget( const Data::WeekGoal * goal );

        /// Gets the goal name
        QString Name() const;

        /// Gets the goal start date
        QDate StartDate() const;

        /// Sets the widget data to defaults
        void SetToDefaults();

        QColor color;
        QPointer<QColorDialog> colorDialog;

        Ui::WeekGoalWidget * const ui;
        UI::WeekGoalWidget * const q_ptr;

    public Q_SLOTS:

        /// Slot called on color selected
        void OnColorSelected( const QColor & inColor );

        /// Slot called on color button clicked
        void OnColorButtonClicked();

        /// Slot called on cancel clicked
        void OnCancelClicked();

        /// Slot called on accept clicked
        void OnAcceptClicked();
    };

}

#endif // WEEKGOALWIDGET_P_H
