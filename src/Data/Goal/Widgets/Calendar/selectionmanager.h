#ifndef SELECTIONMANAGER_H
#define SELECTIONMANAGER_H

#include <QObject>

namespace UI {

    class CalendarModel;
    class SelectionManagerPrivate;

    class SelectionManager : public QObject
    {
        Q_OBJECT
        Q_DECLARE_PRIVATE(UI::SelectionManager)
        Q_DISABLE_COPY(SelectionManager)

    public:

        /// Default constructor
        explicit SelectionManager(QObject *parent = 0);

        /// Destructor
        ~SelectionManager();

        /// Clears the data
        void ClearData();

        /// Sets the model
        void SetModel(UI::CalendarModel * model);

    public Q_SLOTS:

    Q_SIGNALS:

        /// Signal to enable/disable updates
        void enableUpdates(bool);

    private:

        SelectionManagerPrivate * const d_ptr;
    };

}

#endif // SELECTIONMANAGER_H
