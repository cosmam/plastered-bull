#include "widgetfunctions.h"

#include <QStyle>
#include <QWidget>

void Widgets::Repolish(QWidget *widget)
{
    if( !widget )
        return;

    widget->style()->unpolish(widget);
    widget->style()->polish(widget);
}
