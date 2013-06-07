#ifndef CALENDARMODEL_P_H
#define CALENDARMODEL_P_H

#include <QList>
#include <QObject>

namespace UI {

    class CalendarDay;
    class CalendarModel;

    class CalendarModelPrivate : public QObject
    {
        Q_OBJECT
        Q_DECLARE_PUBLIC(UI::CalendarModel)
        Q_DISABLE_COPY(CalendarModelPrivate)

    public:

        /// Default constructor
        explicit CalendarModelPrivate(CalendarModel *parent);

        /// Destructor
        ~CalendarModelPrivate();

        /// Clears the data for this widget
        void ClearData();

        /// Determines if the data at the given position is valid
        bool IsValid(int row, int col) const;

        QList<UI::CalendarDay *> m_days;
        int m_rows;
        CalendarModel * const q_ptr;

    public Q_SLOTS:

    };

}

#endif // CALENDARMODEL_P_H
