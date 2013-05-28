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
    
    void setSelected(bool selected);
    bool isSelected() const;

    void setSelectable(bool selectable);
    bool isSelectable() const;

public Q_SLOTS:

Q_SIGNALS:

    void widgetPressed();
    void widgetReleased();
    void widgetClicked();

protected:
    explicit SelectableWidget(SelectableWidgetPrivate & d, QWidget *parent = 0);
    SelectableWidgetPrivate * const d_ptr;

    void mouseMoveEvent( QMouseEvent * event );
    void mousePressEvent( QMouseEvent * event );
    void mouseReleaseEvent( QMouseEvent * event );
};

}

#endif // SELECTABLEWIDGET_H
