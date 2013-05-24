#ifndef CALENDARDAY_P_H
#define CALENDARDAY_P_H

#include <QObject>

namespace Ui {
class CalendarDay;
}

namespace UI
{

class CalendarDay;

class CalendarDayPrivate : public QObject
{
    Q_OBJECT
    Q_DECLARE_PUBLIC(UI::CalendarDay);

public:
    explicit CalendarDayPrivate(CalendarDay *parent);
    ~CalendarDayPrivate();

	void SetDayLabel( const QString & label );

    Ui::CalendarDay * const m_ui;
    CalendarDay * const q_ptr;
    
    Q_DISABLE_COPY(CalendarDayPrivate);

public Q_SLOTS:

    void PositionWidgets();
};

}

#endif // CALENDARDAY_P_H
