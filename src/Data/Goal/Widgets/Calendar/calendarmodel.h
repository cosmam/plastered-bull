#ifndef CALENDARMODEL_H
#define CALENDARMODEL_H

#include <QObject>

namespace UI
{

class CalendarModelPrivate;

class CalendarModel : public QObject
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(UI::CalendarModel);

public:
    explicit CalendarModel(QObject *parent = 0);
    ~CalendarModel();
    
public Q_SLOTS:

Q_SIGNALS:

private:

    Q_DISABLE_COPY(CalendarModel);
    CalendarModelPrivate * const d_ptr;
};

}

#endif // CALENDARMODEL_H