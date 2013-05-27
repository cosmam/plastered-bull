#ifndef SELECTIONMANAGER_P_H
#define SELECTIONMANAGER_P_H

#include <QObject>

namespace UI
{

class SelectionManager;

class SelectionManagerPrivate : public QObject
{
    Q_OBJECT
    Q_DECLARE_PUBLIC(UI::SelectionManager);

public:
    explicit SelectionManagerPrivate(SelectionManager *parent);
	~SelectionManagerPrivate();
    
    SelectionManager * const q_ptr;

    Q_DISABLE_COPY(SelectionManagerPrivate);

public Q_SLOTS:

};

}

#endif // SELECTIONMANAGER_P_H