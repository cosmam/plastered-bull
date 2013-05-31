#include "selectablewidget.h"
#include "selectablewidget_p.h"

#include <QMouseEvent>

using namespace UI;

SelectableWidget::SelectableWidget(QWidget *parent) :
    QWidget(parent),
    d_ptr( new SelectableWidgetPrivate )
{
}

SelectableWidget::SelectableWidget(SelectableWidgetPrivate & d, QWidget *parent) :
	QWidget(parent),
	d_ptr(&d)
{
}

void SelectableWidget::setSelected(bool selected)
{
    Q_D(UI::SelectableWidget);

    d->m_selected = selected;
}

bool SelectableWidget::isSelected() const
{
    Q_D(const UI::SelectableWidget);

    return d->m_selected;
}

void SelectableWidget::setSelectable(bool selectable)
{
    Q_D(UI::SelectableWidget);

    d->m_selectable = selectable;
}

bool SelectableWidget::isSelectable() const
{
    Q_D(const UI::SelectableWidget);

    return d->m_selectable;
}

void SelectableWidget::mouseMoveEvent( QMouseEvent * event )
{
    Q_UNUSED(event);
}

void SelectableWidget::mousePressEvent( QMouseEvent * event )
{
    if( event->button() == Qt::LeftButton )
    {
        Q_D(UI::SelectableWidget);

        d->m_pressPoint = event->pos();
        emit widgetPressed();
    }
}

void SelectableWidget::mouseReleaseEvent( QMouseEvent * event )
{
    if( event->button() == Qt::LeftButton )
    {
        Q_D(UI::SelectableWidget);

        emit widgetReleased();

        if( event->pos() == d->m_pressPoint )
        {
            emit widgetClicked();
        }
    }

}

/**************** Private Class ***************/

SelectableWidgetPrivate::SelectableWidgetPrivate() :
    QObject(),
    m_selected(false),
    m_selectable(false),
    q_ptr(NULL)
{
}

void SelectableWidgetPrivate::init()
{

}
