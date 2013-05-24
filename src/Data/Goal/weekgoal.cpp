#include "weekgoal.h"

#include "weekgoal_p.h"
#include "weekgoalwidget.h"

#include "customgoal.h"

using namespace Data;

WeekGoal::WeekGoal(QObject *parent) :
    Goal(parent),
    d_ptr( new WeekGoalPrivate( this ) )
{
    Q_D(Data::WeekGoal);
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
    delete d_ptr->goal;
    delete d_ptr;
}

void WeekGoal::setColor( const QColor & color )
{
    Q_D(Data::WeekGoal);
    d->goal->setColor( color );
}

QColor WeekGoal::color() const
{
    Q_D(const Data::WeekGoal);
    return d->goal->color();
}

void WeekGoal::setName( const QString & name )
{
    Q_D(Data::WeekGoal);
    d->goal->setName( name );
}

QString WeekGoal::name() const
{
    Q_D(const Data::WeekGoal);
    return d->goal->name();
}

void WeekGoal::setCriteria( const Data::Criteria & criteria )
{
    Q_D(Data::WeekGoal);
    d->goal->setCriteria( criteria );
}

Data::Criteria WeekGoal::criteria() const
{
    Q_D(const Data::WeekGoal);
    return d->goal->criteria();
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

WeekGoalPrivate::WeekGoalPrivate( WeekGoal * parent ) :
    QObject(parent),
    q_ptr(parent)
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
    out << goal.criteria();
    out << goal.startDate();

    return out;
}

QDataStream & operator>>(QDataStream & in, WeekGoal & goal)
{
    QString name;
    QColor color;
    Data::Criteria criteria;
    QDate date;

    in >> name;
    in >> color;
    in >> criteria;
    in >> date;

    goal.setName( name );
    goal.setColor( color );
    goal.setCriteria( criteria );
    goal.setStartDate( date );

    return in;
}
