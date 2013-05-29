#include "daygoal.h"

#include "daygoal_p.h"
#include "daygoalwidget.h"
#include "timefunctions.h"

using namespace Data;

DayGoal::DayGoal(QObject *parent) :
    Goal(*new Data::DayGoalPrivate, parent)
{
    Q_D(Data::DayGoal);
    d->setParent(this);
    d->q_ptr = this;
    d->init();
}

DayGoal::~DayGoal()
{
}

QDateTime DayGoal::start() const
{
    Q_D(const Data::DayGoal);
    return QDateTime( d->date, Time::startTime );
}

QDateTime DayGoal::end() const
{
    Q_D(const Data::DayGoal);
    return QDateTime( d->date, Time::endTime );
}

void DayGoal::setDate( const QDate & date )
{
    if( date.isValid() ) {
        Q_D(Data::DayGoal);
        d->date = date;
        emit dateChanged( d->date );
    }
}

QDate DayGoal::date() const
{
    Q_D(const Data::DayGoal);
    return d->date;
}

UI::GoalWidgetBase *DayGoal::CreateWidget()
{
    Q_D(Data::DayGoal);

    d->widget = new UI::DayGoalWidget();

    d->widget->SetupWidget( this );
	
    connect( d->widget, SIGNAL( ChangesAccepted() ),
             d, SLOT( WidgetChangesAccepted() ) );

    return d->widget;
}

/**************** Private Class ***************/

DayGoalPrivate::DayGoalPrivate() :
    GoalPrivate(),
    date(QDate::currentDate())
{
}

DayGoalPrivate::~DayGoalPrivate()
{
}

void DayGoalPrivate::init()
{
    Q_Q(Data::DayGoal);
    connect( q, SIGNAL( nameChanged( QString ) ),
             this, SLOT( OnDataUpdated() ) );
    connect( q, SIGNAL( colorChanged( QColor ) ),
             this, SLOT( OnDataUpdated() ) );
    connect( q, SIGNAL( dateChanged( QDate ) ),
             this, SLOT( OnDataUpdated() ) );
}

void DayGoalPrivate::WidgetChangesAccepted()
{
    if( widget == NULL )
        return;

    Q_Q(Data::DayGoal);

    if( name != widget->Name() ) {
        q->setName( widget->Name() );
    }

    if( color != widget->Color() ) {
        q->setColor( widget->Color() );
    }

    if( date != widget->Date() ) {
        q->setDate( widget->Date() );
    }
}

void DayGoalPrivate::OnDataUpdated()
{
    Q_Q(Data::DayGoal);
    emit q->goalChanged( q );
}

/************* External Functions *************/

QDataStream & operator<<(QDataStream & out, const DayGoal & goal)
{
    out << goal.name();
    out << goal.color();
//    out << goal.criteria();
    out << goal.date();

    return out;
}

QDataStream & operator>>(QDataStream & in, DayGoal & goal)
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
    goal.setDate( date );

    return in;
}
