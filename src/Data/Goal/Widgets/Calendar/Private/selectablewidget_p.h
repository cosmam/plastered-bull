#ifndef SELECTABLEWIDGET_P_H
#define SELECTABLEWIDGET_P_H

#include <QObject>

namespace UI
{

class SelectableWidget;

class SelectableWidgetPrivate : public QObject
{
    Q_OBJECT
    Q_DECLARE_PUBLIC(UI::SelectableWidget);
    Q_DISABLE_COPY(SelectableWidgetPrivate);

public:
    explicit SelectableWidgetPrivate();
    virtual ~SelectableWidgetPrivate() {};

    virtual void init();

    SelectableWidget * q_ptr;

public Q_SLOTS:

};

}

#endif // SELECTABLEWIDGET_P_H
