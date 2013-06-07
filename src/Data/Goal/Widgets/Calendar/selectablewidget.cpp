#include "selectablewidget.h"
#include "selectablewidget_p.h"

#include <QMouseEvent>

using namespace UI;

/**
 * @author Cosmam
 * @name SelectableWidget
 * @namespace UI
 * @brief The parent widget
 * @param parent: The parent widget
 **/
SelectableWidget::SelectableWidget(QWidget *parent) :
    QWidget(parent),
    d_ptr( new SelectableWidgetPrivate )
{
}

/**
 * @author Cosmam
 * @name SelectableWidget
 * @namespace UI
 * @brief Overloaded constructor for d-pointer initialization
 * @param d: The d-pointer
 * @param parent: The parent widget
 **/
SelectableWidget::SelectableWidget(SelectableWidgetPrivate & d, QWidget *parent) :
	QWidget(parent),
	d_ptr(&d)
{
}

/**
 * @author Cosmam
 * @name setSelected
 * @namespace UI
 * @brief Sets whtether or not this is selected
 * @param selected: Whether or not this is selected
 **/
void SelectableWidget::setSelected(bool selected)
{
    Q_D(UI::SelectableWidget);

    d->m_selected = selected;
}

/**
 * @author Cosmam
 * @name isSelected
 * @namespace UI
 * @brief Gets whether or not this is selected
 * @return Whether or not this is selected
 **/
bool SelectableWidget::isSelected() const
{
    Q_D(const UI::SelectableWidget);

    return d->m_selected;
}

/**
 * @author Cosmam
 * @name setSelectable
 * @namespace UI
 * @brief Sets whether or not this is selectable
 * @param Whether or not this is selectable
 **/
void SelectableWidget::setSelectable(bool selectable)
{
    Q_D(UI::SelectableWidget);

    d->m_selectable = selectable;
}

/**
 * @author Cosmam
 * @name isSelectable
 * @namespace UI
 * @brief Gets whether or not this is selectable
 * @return Whether or not this is selectable
 **/
bool SelectableWidget::isSelectable() const
{
    Q_D(const UI::SelectableWidget);

    return d->m_selectable;
}

/**
 * @author Cosmam
 * @name mouseMoveEvenet
 * @namespace UI
 * @brief Reimplemented mouse move event
 * @param event:  The mouse move event
 */
void SelectableWidget::mouseMoveEvent( QMouseEvent * event )
{
    Q_UNUSED(event);
}

/**
 * @author Cosmam
 * @name mousePressEvent
 * @namespace UI
 * @brief Reimplemented mouse press event
 * @param event: The mouse press event
 **/
void SelectableWidget::mousePressEvent( QMouseEvent * event )
{
    if( event->button() == Qt::LeftButton )
    {
        Q_D(UI::SelectableWidget);

        d->m_pressPoint = event->pos();
        emit widgetPressed();
    }
}

/**
 * @author Cosmam
 * @name mouseReleaseEvent
 * @namespace UI
 * @brief Reimplemented mouse release event
 * @param event: The mouse release event
 **/
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

/**
 * @author Cosmam
 * @name SelectableWidgetPrivate
 * @namespace UI
 * @brief Default constructor
 **/
SelectableWidgetPrivate::SelectableWidgetPrivate() :
    QObject(),
    m_selected(false),
    m_selectable(false),
    q_ptr(NULL)
{
}

/**
 * @author Cosmam
 * @name ~SelectableWidgetPrivate
 * @namespace UI
 * @brief Destructor
 **/
void SelectableWidgetPrivate::init()
{

}
