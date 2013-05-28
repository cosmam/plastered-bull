#ifndef CALENDARMODEL_P_H
#define CALENDARMODEL_P_H

#include <QList>
#include <QObject>

namespace UI
{

class CalendarDay;
class CalendarModel;

class CalendarModelPrivate : public QObject
{
    Q_OBJECT
    Q_DECLARE_PUBLIC(UI::CalendarModel);

public:
    explicit CalendarModelPrivate(CalendarModel *parent);
	~CalendarModelPrivate();

    void ClearData();

    bool IsValid(int row, int col) const;

    QList<UI::CalendarDay *> m_days;
    int m_rows;
    CalendarModel * const q_ptr;

    Q_DISABLE_COPY(CalendarModelPrivate);

public Q_SLOTS:

};

}

#endif // CALENDARMODEL_P_H
