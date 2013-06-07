#ifndef SELECTIONMANAGER_P_H
#define SELECTIONMANAGER_P_H

#include <QObject>

namespace UI
{

    class CalendarDay;
    class CalendarModel;
    class GoalCalendarItem;
    class SelectionManager;

    class SelectionManagerPrivate : public QObject
    {
        Q_OBJECT
        Q_DECLARE_PUBLIC(UI::SelectionManager)
        Q_DISABLE_COPY(SelectionManagerPrivate)

    public:

        /// Default constructor
        explicit SelectionManagerPrivate(SelectionManager *parent);

        /// Destructor
        ~SelectionManagerPrivate();

        /// Breaks the connections for the model
        void BreakModelConnections() const;

        /// Makes the connections for the model
        void MakeModelConnections() const;

        /// Unselects all items
        void UnselectAll();

        /// Sets the item selected state
        void SetItemSelected(UI::CalendarDay * item, bool selected);

        /// Styles the items
        void StyleItems();

        UI::CalendarModel * model;
        QList<UI::CalendarDay *> selectedItems;
        UI::CalendarDay * lastSelected;

        SelectionManager * const q_ptr;

    public Q_SLOTS:

        /// Slot called when a widget is clicked
        void OnWidgetClicked();

    };

}

#endif // SELECTIONMANAGER_P_H
