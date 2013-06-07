#ifndef CALENDARMODEL_H
#define CALENDARMODEL_H

#include <QObject>

namespace UI {

    class CalendarDay;
    class CalendarModelPrivate;
    class CalendarMonth;

    class CalendarModel : public QObject
    {
        Q_OBJECT
        Q_DECLARE_PRIVATE(UI::CalendarModel)
        Q_DISABLE_COPY(CalendarModel)

    public:

        /// Default constructor
        explicit CalendarModel(QObject *parent = 0);

        /// Destructor
        ~CalendarModel();

        /// Sets the calendar reference
        void SetCalendarReference(UI::CalendarMonth * month);

        /// Gets the calendar day at the given location
        UI::CalendarDay * Day(int row, int col) const;

        /// Gets the range of calendar days between the start and end days
        QList<UI::CalendarDay *> Range(UI::CalendarDay * start, UI::CalendarDay * end) const;

        /// Gets the number of rows
        int Rows() const;

    public Q_SLOTS:

    Q_SIGNALS:

    private:

        CalendarModelPrivate * const d_ptr;
    };

}

#endif // CALENDARMODEL_H
