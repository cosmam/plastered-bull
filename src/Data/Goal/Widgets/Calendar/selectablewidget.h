#ifndef SELECTABLEWIDGET_H
#define SELECTABLEWIDGET_H

#include <QWidget>

namespace UI
{

class SelectableWidgetPrivate;

class SelectableWidget : public QWidget
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(UI::SelectableWidget);
    Q_DISABLE_COPY(SelectableWidget);

public:
    explicit SelectableWidget(QWidget *parent = 0);
    virtual ~SelectableWidget() {};
    
public Q_SLOTS:

Q_SIGNALS:

protected:
    explicit SelectableWidget(SelectableWidgetPrivate & d, QWidget *parent = 0);
    SelectableWidgetPrivate * const d_ptr;
};

}

#endif // SELECTABLEWIDGET_H
