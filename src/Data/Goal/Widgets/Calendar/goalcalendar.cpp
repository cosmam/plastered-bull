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

GoalCalendar::GoalCalendar(QWidget *parent) :
    QWidget(parent),
    d_ptr( new GoalCalendarPrivate( this ) )
{
}

GoalCalendar::~GoalCalendar()
{
    delete d_ptr;
}

void GoalCalendar::SetGoals( const QList<Data::Goal *> goals )
{
    Q_D(UI::GoalCalendar);

    d->goals = goals;
	
    foreach( Data::Goal * goal, d->goals ) {
        d->MakeGoalConnections( goal );
	}
}

void GoalCalendar::RemoveGoal( Data::Goal * goal )
{
    Q_D(UI::GoalCalendar);

    d->goals.removeAll( goal );

	// processing to remove widgets
}
	
void GoalCalendar::UpdateGoal( Data::Goal * goal )
{
    Q_UNUSED(goal);
	// processing to update widgets
}
	
void GoalCalendar::AddGoal( Data::Goal * goal )
{
    Q_D(UI::GoalCalendar);

    d->goals.append( goal );
    d->MakeGoalConnections( goal );
	
	// processing to add widgets
}

/**************** Private Class ***************/

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

GoalCalendarPrivate::~GoalCalendarPrivate()
{
    delete ui;
}

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

void GoalCalendarPrivate::OnDestroyed( QObject * object )
{
    Data::Goal * goal = qobject_cast<Data::Goal *>(object);

    if( goal != NULL ) {
        Q_Q(UI::GoalCalendar);

        q->RemoveGoal( goal );
    }
}

void GoalCalendarPrivate::OnMonthChanged( int month )
{
    manager->ClearData();
    ui->calendarMonth->SetMonth( Time::ToMonth( month + 1 ) );
    PopulateModel();
    manager->SetModel(model);
}

void GoalCalendarPrivate::OnYearChanged( QString year )
{
    manager->ClearData();
    ui->calendarMonth->SetYear( year.toInt() );
    PopulateModel();
    manager->SetModel(model);
}

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

void GoalCalendarPrivate::OnDialogCanceled()
{
    delete newGoal;
}

void GoalCalendarPrivate::PopulateModel()
{
    model->SetCalendarReference(ui->calendarMonth);
}

void GoalCalendarPrivate::SetUpdatesEnabled(bool enabled)
{
    Q_Q(UI::GoalCalendar);

    q->setUpdatesEnabled(enabled);
}
