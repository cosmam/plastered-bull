#include "monthgoal.h"

#include "monthgoal_p.h"
#include "monthgoalwidget.h"

using namespace Data;

MonthGoal::MonthGoal(QObject *parent) :
    Goal(parent),
    d_ptr( new MonthGoalPrivate( this ) )
{
}

MonthGoal::~MonthGoal()
{
    delete d_ptr;
}
	
void MonthGoal::setColor( const QColor & color )
{
    if( color.isValid() ) {
        Q_D(Data::MonthGoal);
        d->color = color;
        emit colorChanged( d->color );
    }
}

QColor MonthGoal::color() const
{
    Q_D(const Data::MonthGoal);
    return d->color;
}

void MonthGoal::setName( const QString & name )
{
    if( !name.isNull() ) {
        Q_D(Data::MonthGoal);
        d->name = name;
        emit nameChanged( d->name );
    }
}

QString MonthGoal::name() const
{
    Q_D(const Data::MonthGoal);
    return d->name;
}

void MonthGoal::setCriteria( const Data::Criteria & criteria )
{
    Q_D(Data::MonthGoal);
    d->criteria = criteria;
	criteriaChanged( criteria );
}

Data::Criteria MonthGoal::criteria() const
{
    Q_D(const Data::MonthGoal);
    return d->criteria;
}

QDateTime MonthGoal::start() const
{
    Q_D(const Data::MonthGoal);
    QDate date( d->year, Time::ToInt( d->month ), 1 );
	
	return QDateTime( date, Time::startTime );
}

QDateTime MonthGoal::end() const
{
    Q_D(const Data::MonthGoal);
    QDate date( d->year, Time::ToInt( d->month ), 1 );
    date.setDate( date.year(), date.month(), date.daysInMonth() );
	
	return QDateTime( date, Time::endTime );
}

void MonthGoal::setMonth( Time::Month month )
{
    Q_D(Data::MonthGoal);
    if( month != Time::INVALID_MONTH ) {
        d->month = month;
        emit monthChanged( d->month );
    }
}

Time::Month MonthGoal::month() const
{
    Q_D(const Data::MonthGoal);
    return d->month;
}
	
void MonthGoal::setYear( int year )
{
    if( year > 0 ) {
        Q_D(Data::MonthGoal);
        d->year = year;
        emit yearChanged( d->year );
    }
}

int MonthGoal::year() const
{
    Q_D(const Data::MonthGoal);
    return d->year;
}

UI::GoalWidgetBase *MonthGoal::CreateWidget()
{
    Q_D(Data::MonthGoal);

    d->widget = new UI::MonthGoalWidget();

    d->widget->SetupWidget( this );
	
    connect( d->widget, SIGNAL( ChangesAccepted() ),
             d, SLOT( WidgetChangesAccepted() ) );

    return d->widget;
}

/**************** Private Class ***************/

MonthGoalPrivate::MonthGoalPrivate(MonthGoal *parent) :
    QObject(parent),
    name(""),
    color(QColor(0,0,0)),
    month(Time::ToMonth(QDate::currentDate().month())),
    year(QDate::currentDate().year()),
    q_ptr(parent)
{
    Q_Q(Data::MonthGoal);
    connect( q, SIGNAL( nameChanged( QString ) ),
             this, SLOT( OnDataUpdated() ) );
    connect( q, SIGNAL( colorChanged( QColor ) ),
             this, SLOT( OnDataUpdated() ) );
    connect( q, SIGNAL( monthChanged( Time::Month ) ),
             this, SLOT( OnDataUpdated() ) );
    connect( q, SIGNAL( yearChanged( int ) ),
             this, SLOT( OnDataUpdated() ) );
}

void MonthGoalPrivate::WidgetChangesAccepted()
{
    if( widget == NULL )
        return;

    Q_Q(Data::MonthGoal);

    if( name != widget->Name() ) {
        q->setName( widget->Name() );
    }

    if( color != widget->Color() ) {
        q->setColor( widget->Color() );
    }

    if( month != widget->Month() ) {
        q->setMonth( widget->Month() );
    }

    if( year != widget->Year() ) {
        q->setYear( widget->Year() );
    }
}

void MonthGoalPrivate::OnDataUpdated()
{
    Q_Q(Data::MonthGoal);
    emit q->goalChanged( q );
}

/************* External Functions *************/

QDataStream & operator<<(QDataStream & out, const MonthGoal & goal)
{
    out << goal.name();
    out << goal.color();
    out << goal.criteria();
    out << qint32( goal.month() );
    out << qint32( goal.year() );

    return out;
}

QDataStream & operator>>(QDataStream & in, MonthGoal & goal)
{
    QString name;
    QColor color;
    Data::Criteria criteria;
    Time::Month month;
    qint32 year;

    in >> name;
    in >> color;
    in >> criteria;
    in >> month;
    in >> year;

    goal.setName( name );
    goal.setColor( color );
    goal.setCriteria( criteria );
    goal.setMonth( month );
    goal.setYear( int(year) );

    return in;
}