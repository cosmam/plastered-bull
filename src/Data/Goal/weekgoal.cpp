#include "weekgoal.h"

#include "weekgoal_p.h"
#include "weekgoalwidget.h"

#include "customgoal.h"

#include <QDateTime>

using namespace Data;

WeekGoal::WeekGoal(QObject *parent) :
    Goal(*new Data::WeekGoalPrivate, parent)
{
    Q_D(Data::WeekGoal);

    d->setParent(this);
    d->q_ptr = this;
    d->init();

    connect( d->goal, SIGNAL( colorChanged( QColor ) ),
	         this, SIGNAL( colorChanged( QColor ) ) );
    connect( d->goal, SIGNAL( nameChanged( QString ) ),
	         this, SIGNAL( nameChanged( QString ) ) );
    connect( d->goal, SIGNAL( criteriaChanged( Data::Criteria ) ),
	         this, SIGNAL( criteriaChanged( Data::Criteria ) ) );
    connect( d->goal, SIGNAL( startDateChanged( QDate ) ),
             this, SIGNAL( startDateChanged( QDate ) ) );
}

WeekGoal::~WeekGoal()
{
}

QDateTime WeekGoal::start() const
{
    Q_D(const Data::WeekGoal);
    return d->goal->start();
}

QDateTime WeekGoal::end() const
{
    Q_D(const Data::WeekGoal);
    return d->goal->end();
}

void WeekGoal::setStartDate( const QDate & date )
{
    Q_D(Data::WeekGoal);
    d->goal->setStartDate( date );
}

QDate WeekGoal::startDate() const
{
    Q_D(const Data::WeekGoal);
    return d->goal->startDate();
}

UI::GoalWidgetBase * WeekGoal::CreateWidget()
{
    Q_D(Data::WeekGoal);

    d->widget = new UI::WeekGoalWidget();

    d->widget->SetupWidget( this );
	
    connect( d->widget, SIGNAL( ChangesAccepted() ),
             d, SLOT( WidgetChangesAccepted() ) );

    return d->widget;
}

/**************** Private Class ***************/

WeekGoalPrivate::WeekGoalPrivate() :
    GoalPrivate()
{
}

WeekGoalPrivate::~WeekGoalPrivate()
{
    delete goal;
}

void WeekGoalPrivate::init()
{
    goal = new CustomGoal();
    goal->setDuration(7);

    Q_Q(Data::WeekGoal);

    connect( goal, SIGNAL( goalChanged( Data::Goal * ) ),
             q, SIGNAL( goalChanged( Data::Goal * ) ) );
}

void WeekGoalPrivate::WidgetChangesAccepted()
{
    if( widget == NULL )
        return;

    Q_Q(Data::WeekGoal);

    if( goal->name() != widget->Name() ) {
        q->setName( widget->Name() );
    }

    if( goal->color() != widget->Color() ) {
        q->setColor( widget->Color() );
    }

    if( goal->startDate() != widget->StartDate() ) {
        q->setStartDate( widget->StartDate() );
    }
}

/************* External Functions *************/

QDataStream & operator<<(QDataStream & out, const WeekGoal & goal)
{
    out << goal.name();
    out << goal.color();
//    out << goal.criteria();
    out << goal.startDate();

    return out;
}

QDataStream & operator>>(QDataStream & in, WeekGoal & goal)
{
    QString name;
    QColor color;
//    Data::Criteria criteria;
    QDate date;

    in >> name;
    in >> color;
//    in >> criteria;
    in >> date;

    goal.setName( name );
    goal.setColor( color );
//    goal.setCriteria( criteria );
    goal.setStartDate( date );

    return in;
}
