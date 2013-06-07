#ifndef CALENDARMONTH_H
#define CALENDARMONTH_H

#include "timefunctions.h"

#include <QWidget>

namespace UI {

    class CalendarDay;
    class CalendarModel;
    class CalendarMonthPrivate;

    class CalendarMonth : public QWidget
    {
        Q_OBJECT
        Q_DECLARE_PRIVATE(UI::CalendarMonth)
        Q_DISABLE_COPY(CalendarMonth)

    public:

        /// Default constructor
        explicit CalendarMonth(QWidget *parent = 0);

        /// Destructor
        ~CalendarMonth();

        /// Gets the month
        Time::Month Month() const;

        /// Gets the year
        int Year() const;

        /// Gets the number of weeks in the month
        int NumWeeks() const;

        /// Gets the calendar day object for the given day
        UI::CalendarDay * Day(int day) const;

    public Q_SLOTS:

        /// Sets the month
        void SetMonth( Time::Month month );

        /// Sets the year
        void SetYear( int year );

    private:

        CalendarMonthPrivate * const d_ptr;
    };

}

#endif // CALENDARMONTH_H
