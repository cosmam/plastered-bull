#ifndef CALENDARDAY_H
#define CALENDARDAY_H

#include <QWidget>

namespace Data
{
    class Goal;
}

namespace UI
{

class CalendarDayPrivate;

class CalendarDay : public QWidget
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(UI::CalendarDay);
    
public:
    explicit CalendarDay(QWidget *parent = 0);
    ~CalendarDay();

public Q_SLOTS:

    void SetDay( int day );

    void AddGoal( Data::Goal * goal, int index = -1 );

protected:

    void resizeEvent(QResizeEvent *);

private:

    Q_DISABLE_COPY(CalendarDay);
    CalendarDayPrivate * const d_ptr;
};

}

#endif // CALENDARDAY_H
