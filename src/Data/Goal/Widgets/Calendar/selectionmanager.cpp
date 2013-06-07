#include "selectionmanager.h"
#include "selectionmanager_p.h"

#include "calendarday.h"
#include "calendarmodel.h"
#include "calendarmonth.h"

#include "widgetfunctions.h"

#include <QApplication>

using namespace UI;

namespace {
    const QString SelectedStyle = "QWidget#frame { border: 2px solid blue; }";
    const QString UnselectedStyle = "QWidget#frame { border: 1px solid black; }";
}

/**
 * @author Cosmam
 * @name SelectionManager
 * @namespace UI
 * @brief Default constructor
 * @param parent: The parent object
 */
SelectionManager::SelectionManager(QObject *parent) :
    QObject(parent),
    d_ptr( new SelectionManagerPrivate( this ) )
{
}

/**
 * @author Cosmam
 * @name ~SelectionManager
 * @namespace UI
 * @brief Destructor
 */
SelectionManager::~SelectionManager()
{
    delete d_ptr;
}

/**
 * @author Cosmam
 * @name ClearData
 * @namespace UI
 * @brief Clears the data
 **/
void SelectionManager::ClearData()
{
    Q_D(UI::SelectionManager);
    d->BreakModelConnections();
    d->lastSelected = NULL;
}

/**
 * @author Cosmam
 * @name SetModel
 * @namespace UI
 * @brief Sets the model
 * @param model: The calendar model
 */
void SelectionManager::SetModel(CalendarModel *model)
{
    ClearData();

    Q_D(UI::SelectionManager);
    d->model = model;
    d->StyleItems();
    d->MakeModelConnections();
}

/**************** Private Class ***************/

/**
 * @author Cosmam
 * @name SelectionManagerPrivate
 * @namespace UI
 * @brief Default constructor
 * @param parent: The parent SelectionManager
 **/
SelectionManagerPrivate::SelectionManagerPrivate(SelectionManager *parent) :
    QObject(parent),
    model(NULL),
    lastSelected(NULL),
    q_ptr(parent)
{
}

/**
 * @author Cosmam
 * @name ~SelectionManagerPrivate
 * @namespace UI
 * @brief Destructor
 **/
SelectionManagerPrivate::~SelectionManagerPrivate()
{
}

/**
 * @author Cosmam
 * @name BreakModelConnections
 * @namespace UI
 * @brief Breaks the connections for the model
 **/
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

/**
 * @author Cosmam
 * @name MakeModelConnections
 * @namespace UI
 * @brief Makes the connections for the model
 **/
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

/**
 * @author Cosmam
 * @name StyleItems
 * @namespace UI
 * @brief Styles the items
 **/
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

/**
 * @author Cosmam
 * @name OnWidgetClicked
 * @namespace UI
 * @brief Slot called when a widget is clicked
 */
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

/**
 * @author Cosmam
 * @name UnselectAll
 * @namespace UI
 * @brief Unselects all items
 **/
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

/**
 * @author Cosmam
 * @name SetItemSelected
 * @namespace UI
 * @brief Sets the item selected state
 * @param item: the item to set the selected state of
 * @param selected: Whether or not the item is selected
 **/
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
