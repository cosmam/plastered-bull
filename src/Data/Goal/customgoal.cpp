#include "customgoal.h"

#include "customgoal_p.h"
#include "customgoalwidget.h"

#include "timefunctions.h"

using namespace Data;

CustomGoal::CustomGoal(QObject *parent) :
    Goal(*new Data::CustomGoalPrivate, parent)
{
    Q_D(Data::CustomGoal);
    d->setParent(this);
    d->q_ptr = this;
    d->init();
}

CustomGoal::~CustomGoal()
{
}

QDateTime CustomGoal::start() const
{
    Q_D(const Data::CustomGoal);
    return QDateTime( d->startDate, Time::startTime );
}

QDateTime CustomGoal::end() const
{
    Q_D(const Data::CustomGoal);
    QDate date( d->startDate );
    return QDateTime( date.addDays( d->duration ), Time::endTime );
}

void CustomGoal::setStartDate( const QDate & date )
{
    if( date.isValid() )
     {
        Q_D(Data::CustomGoal);
        d->startDate = date;
        emit startDateChanged( d->startDate );
    }
}

QDate CustomGoal::startDate() const
{
    Q_D(const Data::CustomGoal);
    return d->startDate;
}

void CustomGoal::setDuration( int duration )
{
    if( duration > 0 ) {
        Q_D(Data::CustomGoal);
        d->duration = duration;
        emit durationChanged( d->duration );
    }
}

int CustomGoal::duration() const
{
    Q_D(const Data::CustomGoal);
    return d->duration;
}

UI::GoalWidgetBase * CustomGoal::CreateWidget()
{
    Q_D(Data::CustomGoal);
    d->widget = new UI::CustomGoalWidget();

    d->widget->SetupWidget( this );

    connect( d->widget, SIGNAL( ChangesAccepted() ),
             d, SLOT( WidgetChangesAccepted() ) );

    return d->widget;
}

/**************** Private Class ***************/

CustomGoalPrivate::CustomGoalPrivate() :
    GoalPrivate(),
    startDate(QDate::currentDate()),
    duration(0)
{
}

CustomGoalPrivate::~CustomGoalPrivate()
{
}

void CustomGoalPrivate::init()
{
    Q_Q(Data::CustomGoal);
    connect( q, SIGNAL( nameChanged( QString ) ),
             this, SLOT( OnDataUpdated() ) );
    connect( q, SIGNAL( colorChanged( QColor ) ),
             this, SLOT( OnDataUpdated() ) );
    connect( q, SIGNAL( startDateChanged( QDate ) ),
             this, SLOT( OnDataUpdated() ) );
    connect( q, SIGNAL( durationChanged( int ) ),
             this, SLOT( OnDataUpdated() ) );
}

void CustomGoalPrivate::WidgetChangesAccepted()
{
    if( widget == NULL )
        return;

    Q_Q(Data::CustomGoal);

    if( name != widget->Name() ) {
        q->setName( widget->Name() );
    }

    if( color != widget->Color() ) {
        q->setColor( widget->Color() );
    }

    if( startDate != widget->StartDate() ) {
        q->setStartDate( widget->StartDate() );
    }

    if( duration != widget->Duration() ) {
        q->setDuration( widget->Duration() );
    }
}

void CustomGoalPrivate::OnDataUpdated()
{
    Q_Q(Data::CustomGoal);
    emit q->goalChanged( q );
}

/************* External Functions *************/

QDataStream & operator<<(QDataStream & out, const CustomGoal & goal)
{
    out << goal.name();
    out << goal.color();
//    out << goal.criteria();
    out << goal.startDate();
    out << quint32( goal.duration() );

    return out;
}

QDataStream & operator>>(QDataStream & in, CustomGoal & goal)
{
    QString name;
    QColor color;
//    Data::Criteria criteria;
    QDate date;
    quint32 duration;

    in >> name;
    in >> color;
//    in >> criteria;
    in >> date;
    in >> duration;

    goal.setName( name );
    goal.setColor( color );
//    goal.setCriteria( criteria );
    goal.setStartDate( date );
    goal.setDuration( int(duration) );

    return in;
}
