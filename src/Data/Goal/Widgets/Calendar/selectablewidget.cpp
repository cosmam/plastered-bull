#include "selectablewidget.h"
#include "selectablewidget_p.h"

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

/**************** Private Class ***************/

SelectableWidgetPrivate::SelectableWidgetPrivate() :
    QObject(),
    q_ptr(NULL)
{
}

void SelectableWidgetPrivate::init()
{

}
