#ifndef CALENDARMONTH_H
#define CALENDARMONTH_H

#include "timefunctions.h"

#include <QWidget>

namespace UI
{

class CalendarDay;
class CalendarModel;
class CalendarMonthPrivate;

class CalendarMonth : public QWidget
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(UI::CalendarMonth);
    
public:
    explicit CalendarMonth(QWidget *parent = 0);
    ~CalendarMonth();
    
    Time::Month Month() const;
    int Year() const;
    int NumWeeks() const;

    UI::CalendarDay * Day(int day) const;

public Q_SLOTS:

    void SetMonth( Time::Month month );
    void SetYear( int year );

private:

    Q_DISABLE_COPY(CalendarMonth);
    CalendarMonthPrivate * const d_ptr;
};

}

#endif // CALENDARMONTH_H
