#ifndef CALENDARMONTH_P_H
#define CALENDARMONTH_P_H

#include "timefunctions.h"

#include <QDate>
#include <QObject>

namespace Ui {
    class CalendarMonth;
}

namespace UI {

    class CalendarDay;
    class CalendarMonth;

    class CalendarMonthPrivate : public QObject
    {
        Q_OBJECT
        Q_DECLARE_PUBLIC(UI::CalendarMonth)
        Q_DISABLE_COPY(CalendarMonthPrivate)

    public:

        /// Default constructor
        explicit CalendarMonthPrivate(CalendarMonth *parent, const QDate & date = QDate::currentDate() );

        /// Destructor
        ~CalendarMonthPrivate();

        /// Draws the calendar
        void DrawCalendar();

        /// Initializes the calendar objects
        void InitCreateObjects();

        /// Gets the date that represents this month
        const QDate date() const;

        Time::Month month;
        int year;
        int weeks;
        int dayOffset;

        QList<UI::CalendarDay *> m_days;
        Ui::CalendarMonth * const m_ui;
        CalendarMonth * const q_ptr;
    };

}

#endif // CALENDARMONTH_P_H
