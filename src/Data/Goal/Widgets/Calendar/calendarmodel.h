#ifndef CALENDARMODEL_H
#define CALENDARMODEL_H

#include <QObject>

namespace UI
{

class CalendarDay;
class CalendarModelPrivate;
class CalendarMonth;

class CalendarModel : public QObject
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(UI::CalendarModel);

public:
    explicit CalendarModel(QObject *parent = 0);
    ~CalendarModel();

    void SetCalendarReference(UI::CalendarMonth * month);

    UI::CalendarDay * Day(int row, int col) const;
    QList<UI::CalendarDay *> Range(UI::CalendarDay * start, UI::CalendarDay * end) const;

    int Rows() const;

public Q_SLOTS:

Q_SIGNALS:

private:

    Q_DISABLE_COPY(CalendarModel);
    CalendarModelPrivate * const d_ptr;
};

}

#endif // CALENDARMODEL_H
