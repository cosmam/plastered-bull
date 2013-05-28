#include "selectionmanager.h"
#include "selectionmanager_p.h"

#include "calendarday.h"
#include "calendarmodel.h"
#include "calendarmonth.h"

#include "widgetfunctions.h"

#include <QApplication>

using namespace UI;

namespace
{
    const QString SelectedStyle = "QWidget#frame { border: 2px solid blue; }";
    const QString UnselectedStyle = "QWidget#frame { border: 1px solid black; }";
}

SelectionManager::SelectionManager(QObject *parent) :
    QObject(parent),
    d_ptr( new SelectionManagerPrivate( this ) )
{
}

SelectionManager::~SelectionManager()
{
    delete d_ptr;
}

void SelectionManager::ClearData()
{
    Q_D(UI::SelectionManager);
    d->BreakModelConnections();
    d->lastSelected = NULL;
}

void SelectionManager::SetModel(CalendarModel *model)
{
    ClearData();

    Q_D(UI::SelectionManager);
    d->model = model;
    d->StyleItems();
    d->MakeModelConnections();
}

/**************** Private Class ***************/

SelectionManagerPrivate::SelectionManagerPrivate(SelectionManager *parent) :
    QObject(parent),
    model(NULL),
    lastSelected(NULL),
    q_ptr(parent)
{
}

SelectionManagerPrivate::~SelectionManagerPrivate()
{
}

void SelectionManagerPrivate::BreakModelConnections() const
{
    if( model == NULL )
        return;

    UI::CalendarDay * day(NULL);

    for( int i=0 ; i < model->Rows() ; ++i ) {
        for( int j=0 ; j < 7 ; ++j ) {
            day = model->Day(i,j);
            if( day != NULL )
            {
                disconnect( day, SIGNAL( widgetClicked() ),
                            this, SLOT( OnWidgetClicked() ) );
            }
        }
    }
}

void SelectionManagerPrivate::MakeModelConnections() const
{
    if( model == NULL )
        return;

    UI::CalendarDay * day(NULL);

    for( int i=0 ; i < model->Rows() ; ++i ) {
        for( int j=0 ; j < 7 ; ++j ) {
            day = model->Day(i,j);
            if( day != NULL )
            {
                connect( day, SIGNAL( widgetClicked() ),
                         this, SLOT( OnWidgetClicked() ) );
            }
        }
    }
}

void SelectionManagerPrivate::StyleItems()
{
    if( model == NULL )
        return;

    UI::CalendarDay * day(NULL);
    QString styleSheet;

    for( int i=0 ; i < model->Rows() ; ++i ) {
        for( int j=0 ; j < 7 ; ++j ) {
            day = model->Day(i,j);
            if( day != NULL )
            {
                styleSheet = (day->isSelected() ? SelectedStyle : UnselectedStyle );
                day->setStyleSheet(styleSheet);
            }
        }
    }
}

void SelectionManagerPrivate::OnWidgetClicked()
{
    UI::CalendarDay * day = qobject_cast<UI::CalendarDay *>(sender());

    if( !day || !day->isSelectable() )
        return;

    Qt::KeyboardModifiers modifiers = QApplication::keyboardModifiers();

    Q_Q(UI::SelectionManager);

    q->enableUpdates(false);

    if( modifiers == Qt::NoModifier ) {
        bool select = !day->isSelected();

        UnselectAll();

        if( select ) {
            SetItemSelected(day, true);
        }
    }
    else if( modifiers == Qt::ControlModifier ) {
        SetItemSelected(day, !day->isSelected() );
    }
    else if( modifiers == Qt::ShiftModifier ) {
        if( lastSelected == NULL) {
            UnselectAll();
        }
        else {
            QList<UI::CalendarDay *> items = model->Range(lastSelected, day);

            UnselectAll();

            foreach(UI::CalendarDay * day, items) {
                SetItemSelected(day, true);
            }
        }
    }
    else if( modifiers == (Qt::ShiftModifier | Qt::ControlModifier) ) {
        if( lastSelected != NULL ) {
            QList<UI::CalendarDay *> items = model->Range(lastSelected, day);

            foreach(UI::CalendarDay * day, items) {
                SetItemSelected(day, true);
            }
        }
    }

    q->enableUpdates(true);
}

void SelectionManagerPrivate::UnselectAll()
{
    foreach( GoalCalendarItem * item, selectedItems )
    {
        item->setSelected(false);
        item->setStyleSheet( UnselectedStyle );
    }

    selectedItems.clear();
    lastSelected = NULL;
}

void SelectionManagerPrivate::SetItemSelected(UI::CalendarDay * item, bool selected)
{
    item->setSelected( selected );
    item->setStyleSheet( ( item->isSelected() ? SelectedStyle : UnselectedStyle ) );

    if( item->isSelected() ) {
        lastSelected = item;

        if( !selectedItems.contains(item) ) {
            selectedItems.append(item);
        }
    }
    else if ( !selected ){
        selectedItems.removeAll(item);
        lastSelected = NULL;
    }
}
