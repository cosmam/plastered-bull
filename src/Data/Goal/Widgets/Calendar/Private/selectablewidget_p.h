#ifndef SELECTABLEWIDGET_P_H
#define SELECTABLEWIDGET_P_H

#include <QObject>
#include <QPoint>

namespace UI {

    class SelectableWidget;

    class SelectableWidgetPrivate : public QObject
    {
        Q_OBJECT
        Q_DECLARE_PUBLIC(UI::SelectableWidget)
        Q_DISABLE_COPY(SelectableWidgetPrivate)

    public:

        /// Default constructor
        explicit SelectableWidgetPrivate();

        /// Virtual Destructor
        virtual ~SelectableWidgetPrivate() {}

        /// Virtual function to initialize the widget
        virtual void init();

        QPoint m_pressPoint;
        bool m_selected;
        bool m_selectable;

        SelectableWidget * q_ptr;

    public Q_SLOTS:

    };

}

#endif // SELECTABLEWIDGET_P_H
