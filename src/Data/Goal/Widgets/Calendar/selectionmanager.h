#ifndef SELECTIONMANAGER_H
#define SELECTIONMANAGER_H

#include <QObject>

namespace UI
{

class CalendarModel;
class SelectionManagerPrivate;

class SelectionManager : public QObject
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(UI::SelectionManager);

public:
    explicit SelectionManager(QObject *parent = 0);
    ~SelectionManager();
    
    void ClearData();

    void SetModel(UI::CalendarModel * model);

public Q_SLOTS:

Q_SIGNALS:

    void enableUpdates(bool);

private:

    Q_DISABLE_COPY(SelectionManager);
    SelectionManagerPrivate * const d_ptr;
};

}

#endif // SELECTIONMANAGER_H
