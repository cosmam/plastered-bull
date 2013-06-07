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

namespace Data {
    class MonthGoal;
}

namespace UI {

    class MonthGoalWidget;

    class MonthGoalWidgetPrivate : public QObject
    {
        Q_OBJECT
        Q_DECLARE_PUBLIC(UI::MonthGoalWidget)
        Q_DISABLE_COPY(MonthGoalWidgetPrivate)

    public:

        /// Default constructor
        explicit MonthGoalWidgetPrivate(MonthGoalWidget *parent);

        /// Destructor
        ~MonthGoalWidgetPrivate();

        /// Sets up this widget based on the goal data
        void SetupWidget( const Data::MonthGoal * goal );

        /// Gets the goal name
        QString Name() const;

        /// Gets the goal month
        Time::Month Month() const;

        /// Gets the goal year
        int Year() const;

        /// Sets the widget data to defaults
        void SetToDefaults();

        QColor color;
        QPointer<QColorDialog> colorDialog;

        Ui::MonthGoalWidget * const ui;
        UI::MonthGoalWidget * const q_ptr;

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

#endif // MONTHGOALWIDGET_P_H
