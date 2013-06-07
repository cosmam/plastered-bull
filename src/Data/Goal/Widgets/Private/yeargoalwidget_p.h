#ifndef YEARGOALWIDGET_P_H
#define YEARGOALWIDGET_P_H

#include <QColor>
#include <QObject>
#include <QPointer>

class QColorDialog;

namespace Ui {
    class YearGoalWidget;
}

namespace Data {
    class YearGoal;
}

namespace UI {

    class YearGoalWidget;

    class YearGoalWidgetPrivate : public QObject
    {
        Q_OBJECT
        Q_DECLARE_PUBLIC(UI::YearGoalWidget)
        Q_DISABLE_COPY(YearGoalWidgetPrivate)

    public:

        /// Default constructor
        explicit YearGoalWidgetPrivate(YearGoalWidget *parent);

        /// Destructor
        ~YearGoalWidgetPrivate();

        /// Sets up this widget based on the goal data
        void SetupWidget( const Data::YearGoal * goal );

        /// Gets the goal name
        QString Name() const;

        /// Gets the goal year
        int Year() const;

        /// Sets the widget data to defaults
        void SetToDefaults();

        QColor color;
        QPointer<QColorDialog> colorDialog;

        Ui::YearGoalWidget * const ui;
        UI::YearGoalWidget * const q_ptr;

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

#endif // YEARGOALWIDGET_P_H
