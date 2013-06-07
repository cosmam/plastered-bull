#ifndef SELECTABLEWIDGET_H
#define SELECTABLEWIDGET_H

#include <QWidget>

namespace UI {

    class SelectableWidgetPrivate;

    class SelectableWidget : public QWidget
    {
        Q_OBJECT
        Q_DECLARE_PRIVATE(UI::SelectableWidget)
        Q_DISABLE_COPY(SelectableWidget)

    public:

        /// Default constructor
        explicit SelectableWidget(QWidget *parent = 0);

        /// Virtual destructor
        virtual ~SelectableWidget() {}

        /// Sets whether or not this is selected
        void setSelected(bool selected);

        /// Gets whether or not this is selected
        bool isSelected() const;

        /// Sets whether or not this is selectable
        void setSelectable(bool selectable);

        /// Gets whether or not this is selectable
        bool isSelectable() const;

    public Q_SLOTS:

    Q_SIGNALS:

        /// Signal emitted when the widget is pressed
        void widgetPressed();

        /// Signal emitted when the widget is released
        void widgetReleased();

        /// Signal emitted when the widget is clicked
        void widgetClicked();

    protected:

        /// Overloaded constructor for d-pointer initialization
        explicit SelectableWidget(SelectableWidgetPrivate & d, QWidget *parent = 0);
        SelectableWidgetPrivate * const d_ptr;

        /// Reimplemented mouse move event
        void mouseMoveEvent( QMouseEvent * event );

        /// Reimplemented mouse press event
        void mousePressEvent( QMouseEvent * event );

        /// Reimplemented mouse release event
        void mouseReleaseEvent( QMouseEvent * event );
    };

}

#endif // SELECTABLEWIDGET_H
