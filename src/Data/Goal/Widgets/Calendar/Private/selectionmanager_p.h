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
    Q_DECLARE_PUBLIC(UI::SelectionManager);

public:
    explicit SelectionManagerPrivate(SelectionManager *parent);
	~SelectionManagerPrivate();

    void BreakModelConnections() const;
    void MakeModelConnections() const;
    void UnselectAll();

    void SetItemSelected(UI::CalendarDay * item, bool selected);
    void StyleItems();

    UI::CalendarModel * model;
    QList<UI::CalendarDay *> selectedItems;
    UI::CalendarDay * lastSelected;
    
    SelectionManager * const q_ptr;

    Q_DISABLE_COPY(SelectionManagerPrivate);

public Q_SLOTS:

    void OnWidgetClicked();

};

}

#endif // SELECTIONMANAGER_P_H
