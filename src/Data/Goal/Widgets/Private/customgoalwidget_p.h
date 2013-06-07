#ifndef CUSTOMGOALWIDGET_P_H
#define CUSTOMGOALWIDGET_P_H

#include <QColor>
#include <QObject>
#include <QPointer>

class QColorDialog;

namespace Ui {
    class CustomGoalWidget;
}

namespace Data {
    class CustomGoal;
}

namespace UI {

    class CustomGoalWidget;

    class CustomGoalWidgetPrivate : public QObject
    {
        Q_OBJECT
        Q_DECLARE_PUBLIC(UI::CustomGoalWidget)
        Q_DISABLE_COPY(CustomGoalWidgetPrivate)

    public:

        /// Default constructor
        explicit CustomGoalWidgetPrivate(CustomGoalWidget *parent);

        /// Destructor
        ~CustomGoalWidgetPrivate();

        /// Sets up this widget based on the goal data
        void SetupWidget( const Data::CustomGoal * goal );

        /// Gets the goal name
        QString Name() const;

        /// Gets the goal start date
        QDate StartDate() const;

        /// Gets the goal duration
        int Duration() const;

        /// Sets the widget data to defaults
        void SetToDefaults();

        QColor color;
        QPointer<QColorDialog> colorDialog;

        Ui::CustomGoalWidget * const ui;
        UI::CustomGoalWidget * const q_ptr;


    public Q_SLOTS:

        /// Slot called on color selected
        void OnColorSelected( const QColor & inColor );

        /// Slot called on start date changed
        void OnStartDateChanged( const QDate & date );

        /// Slot called on color button clicked
        void OnColorButtonClicked();

        /// Slot called on cancel clicked
        void OnCancelClicked();

        /// Slot called on accept clicked
        void OnAcceptClicked();
    };

}

#endif // CUSTOMGOALWIDGET_P_H
