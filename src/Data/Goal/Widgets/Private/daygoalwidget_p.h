#ifndef DAYGOALWIDGET_P_H
#define DAYGOALWIDGET_P_H

#include <QColor>
#include <QObject>
#include <QPointer>

class QColorDialog;

namespace Ui {
    class DayGoalWidget;
}

namespace Data {
    class DayGoal;
}

namespace UI {

    class DayGoalWidget;

    class DayGoalWidgetPrivate : public QObject
    {
        Q_OBJECT
        Q_DECLARE_PUBLIC(UI::DayGoalWidget)
        Q_DISABLE_COPY(DayGoalWidgetPrivate)

    public:

        /// Default constructor
        explicit DayGoalWidgetPrivate(DayGoalWidget *parent);

        /// Destructor
        ~DayGoalWidgetPrivate();

        /// Sets up this widget based on the goal data
        void SetupWidget( const Data::DayGoal * goal );

        /// Gets the goal name
        QString Name() const;

        /// Gets the goal date
        QDate Date() const;

        /// Sets the widget data to defaults
        void SetToDefaults();

        QColor color;
        QPointer<QColorDialog> colorDialog;

        Ui::DayGoalWidget * const ui;
        UI::DayGoalWidget * const q_ptr;

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

#endif // DAYGOALWIDGET_P_H
