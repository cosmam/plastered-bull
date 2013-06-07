#include "goalcalendar.h"
#include "goalcalendar_p.h"
#include "ui_goalcalendar.h"

#include "calendarmodel.h"
#include "goal.h"
#include "goalfactory.h"
#include "goaltypes.h"
#include "goalwidgetbase.h"
#include "selectionmanager.h"

#include <QDialog>
#include <QVBoxLayout>

using namespace UI;

/**
 * @author Cosmam
 * @name GoalCalendar
 * @namespace UI
 * @brief Default constructor
 * @param parent: The parent widget
 **/
GoalCalendar::GoalCalendar(QWidget *parent) :
    QWidget(parent),
    d_ptr( new GoalCalendarPrivate( this ) )
{
}

/**
 * @author Cosmam
 * @name ~GoalCalendar
 * @namespace UI
 * @brief Destructor
 **/
GoalCalendar::~GoalCalendar()
{
    delete d_ptr;
}

/**
 * @author Cosmam
 * @name SetGoals
 * @namespace UI
 * @brief Sets the list of goals
 * @param goals: The list of goals
 **/
void GoalCalendar::SetGoals( const QList<Data::Goal *> goals )
{
    Q_D(UI::GoalCalendar);

    d->goals = goals;
	
    foreach( Data::Goal * goal, d->goals ) {
        d->MakeGoalConnections( goal );
	}
}

/**
 * @author Cosmam
 * @name RemoveGoal
 * @namespace UI
 * @brief Slot to remove a goal
 * @param goal: The remove a goal
 **/
void GoalCalendar::RemoveGoal( Data::Goal * goal )
{
    Q_D(UI::GoalCalendar);

    d->goals.removeAll( goal );

	// processing to remove widgets
}

/**
 * @author Cosmam
 * @name UpdateGoal
 * @namespace UI
 * @brief Slot to update a goal
 * @param goal: The goal to update
 **/
void GoalCalendar::UpdateGoal( Data::Goal * goal )
{
    Q_UNUSED(goal);
	// processing to update widgets
}

/**
 * @author Cosmam
 * @name AddGoal
 * @namespace UI
 * @brief Slot to add a goal
 * @param goal: The goal to add
 **/
void GoalCalendar::AddGoal( Data::Goal * goal )
{
    Q_D(UI::GoalCalendar);

    d->goals.append( goal );
    d->MakeGoalConnections( goal );
	
	// processing to add widgets
}

/**************** Private Class ***************/

/**
 * @author Cosmam
 * @name GoalCalendarPrivate
 * @namespace UI
 * @brief Default constructor
 * @param parent: The parent Goal Calendar
 **/
GoalCalendarPrivate::GoalCalendarPrivate(GoalCalendar *parent) :
    QObject(parent),
    model(new UI::CalendarModel(parent)),
    manager(new UI::SelectionManager(parent)),
    ui(new Ui::GoalCalendar),
    q_ptr(parent)
{
    ui->setupUi(q_ptr);

    ui->month_ComboBox->setCurrentIndex( QDate::currentDate().month() - 1 );
    ui->year_ComboBox->setCurrentIndex( QDate::currentDate().year() -
                                        ui->year_ComboBox->itemText(0).toInt() );

    PopulateModel();
    manager->SetModel(model);

    MakeConnections();
}

/**
 * @author Cosmam
 * @name ~GoalCalendarPrivate
 * @namespace UI
 * @brief Destructor
 **/
GoalCalendarPrivate::~GoalCalendarPrivate()
{
    delete ui;
}

/**
 * @author Cosmam
 * @name MakeConnections
 * @namespace UI
 * @brief Makes the goal connections for this widget
 **/
void GoalCalendarPrivate::MakeConnections()
{
    connect( ui->month_ComboBox, SIGNAL( currentIndexChanged(int) ),
             this, SLOT( OnMonthChanged(int) ) );
    connect( ui->year_ComboBox, SIGNAL( currentIndexChanged(QString) ),
             this, SLOT( OnYearChanged(QString) ) );

    connect( ui->btn_CustomGoal, SIGNAL(clicked()),
             this, SLOT(OnCustomGoalClicked()));
    connect( ui->btn_DayGoal, SIGNAL(clicked()),
             this, SLOT(OnDayGoalClicked()));
    connect( ui->btn_MonthGoal, SIGNAL(clicked()),
             this, SLOT(OnMonthGoalClicked()));
    connect( ui->btn_WeekGoal, SIGNAL(clicked()),
             this, SLOT(OnWeekGoalClicked()));
    connect( ui->btn_YearGoal, SIGNAL(clicked()),
             this, SLOT(OnYearGoalClicked()));

    connect( manager, SIGNAL(enableUpdates(bool)),
             this, SLOT(SetUpdatesEnabled(bool)));
}

/**
 * @author Cosmam
 * @name MakeGoalConnections
 * @namespace UI
 * @brief Makes the connections for a given goal
 * @param goal: The goal to make connections for
 **/
void GoalCalendarPrivate::MakeGoalConnections( Data::Goal * goal )
{
    Q_Q(UI::GoalCalendar);

    connect( goal, SIGNAL( destroyed( QObject * ) ),
             this, SLOT( OnDestroyed( QObject * ) ),
             Qt::UniqueConnection );
    connect( goal, SIGNAL( goalChanged( Data::Goal * ) ),
             q, SLOT( UpdateGoal( Data::Goal * ) ),
             Qt::UniqueConnection );
}

/**
 * @author Cosmam
 * @name OnDestroyed
 * @namespace UI
 * @brief Slot called when a goal is destroyed
 * @param object: The destroyed goal
 **/
void GoalCalendarPrivate::OnDestroyed( QObject * object )
{
    Data::Goal * goal = qobject_cast<Data::Goal *>(object);

    if( goal != NULL ) {
        Q_Q(UI::GoalCalendar);

        q->RemoveGoal( goal );
    }
}

/**
 * @author Cosmam
 * @name OnMonthChanged
 * @namespace UI
 * @brief Slot called when the month is changed
 * @param month: The new month value
 **/
void GoalCalendarPrivate::OnMonthChanged( int month )
{
    manager->ClearData();
    ui->calendarMonth->SetMonth( Time::ToMonth( month + 1 ) );
    PopulateModel();
    manager->SetModel(model);
}

/**
 * @author Cosmam
 * @name OnYearChanged
 * @namespace UI
 * @brief Slot called when the year is changed
 * @param year: the new year
 **/
void GoalCalendarPrivate::OnYearChanged( QString year )
{
    manager->ClearData();
    ui->calendarMonth->SetYear( year.toInt() );
    PopulateModel();
    manager->SetModel(model);
}

/**
 * @author Cosmam
 * @name OnCustomGoalClicked
 * @namespace UI
 * @brief Slot called when the custom goal button is clicked
 **/
void GoalCalendarPrivate::OnCustomGoalClicked()
{
    if( goalDialog ) {
        goalDialog->reject();
    }

    Data::Goal * goal = Data::GoalFactory::CreateGoal( Data::CUSTOM_GOAL_TYPE );

    goals.append( goal );
    MakeGoalConnections(goal);

    CreateDialog(goal);
}

/**
 * @author Cosmam
 * @name OnDayGoalClicked
 * @namespace UI
 * @brief Slot called when the day goal button is clicked
 **/
void GoalCalendarPrivate::OnDayGoalClicked()
{
    if( goalDialog ) {
        goalDialog->reject();
    }

    Data::Goal * goal = Data::GoalFactory::CreateGoal( Data::DAY_GOAL_TYPE );

    goals.append( goal );
    MakeGoalConnections(goal);

    CreateDialog(goal);
}

/**
 * @author Cosmam
 * @name OnMonthGoalClicked
 * @namespace UI
 * @brief Slot called when the month goal button is clicked
 **/
void GoalCalendarPrivate::OnMonthGoalClicked()
{
    if( goalDialog ) {
        goalDialog->reject();
    }

    Data::Goal * goal = Data::GoalFactory::CreateGoal( Data::MONTH_GOAL_TYPE );

    goals.append( goal );
    MakeGoalConnections(goal);

    CreateDialog(goal);
}

/**
 * @author Cosmam
 * @name OnWeekGoalClicked
 * @namespace UI
 * @brief Slot called when the week goal button is clicked
 **/
void GoalCalendarPrivate::OnWeekGoalClicked()
{
    if( goalDialog ) {
        goalDialog->reject();
    }

    Data::Goal * goal = Data::GoalFactory::CreateGoal( Data::WEEK_GOAL_TYPE );

    goals.append( goal );
    MakeGoalConnections(goal);

    CreateDialog(goal);
}

/**
 * @author Cosmam
 * @name OnYearGoalClicked
 * @namespace UI
 * @brief Slot called when the year goal button is clicked
 **/
void GoalCalendarPrivate::OnYearGoalClicked()
{
    if( goalDialog ) {
        goalDialog->reject();
    }

    Data::Goal * goal = Data::GoalFactory::CreateGoal( Data::YEAR_GOAL_TYPE );

    goals.append( goal );
    MakeGoalConnections(goal);

    CreateDialog(goal);
}

/**
 * @author Cosmam
 * @name CreateDialog
 * @namespace UI
 * @brief Creates a dialog from the given goal
 * @param goal
 **/
void GoalCalendarPrivate::CreateDialog( Data::Goal * goal )
{
    Q_Q(UI::GoalCalendar);

    goalDialog = new QDialog(q);

    QVBoxLayout * layout = new QVBoxLayout(goalDialog);
    layout->setContentsMargins(0,0,0,0);

    UI::GoalWidgetBase * widget = goal->CreateWidget();
    layout->addWidget(widget);

    newGoal = goal;

    connect( widget, SIGNAL(ChangesCanceled()),
             goalDialog, SLOT(reject()));
    connect( goalDialog, SIGNAL(rejected()),
             widget, SLOT(close()));
    connect( widget, SIGNAL(ChangesAccepted()),
             goalDialog, SLOT(accept()));

    connect( goalDialog, SIGNAL(rejected()),
             this, SLOT(OnDialogCanceled()));

    goalDialog->show();
}

/**
 * @author Cosmam
 * @name OnDialogCanceled
 * @namespace UI
 * @brief SlotCalled when the dialog is canceled
 **/
void GoalCalendarPrivate::OnDialogCanceled()
{
    delete newGoal;
}

/**
 * @author Cosmam
 * @name PopulateModel
 * @namespace UI
 * @brief Populates the calendar model
 **/
void GoalCalendarPrivate::PopulateModel()
{
    model->SetCalendarReference(ui->calendarMonth);
}
/**
 * @author Cosmam
 * @name StUpdatesEnabled
 * @namespace UI
 * @brief Sets whether updates are enabled/disbled
 * @param enabled: Whether or not updates are enabled
 **/
void GoalCalendarPrivate::SetUpdatesEnabled(bool enabled)
{
    Q_Q(UI::GoalCalendar);

    q->setUpdatesEnabled(enabled);
}
