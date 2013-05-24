#include "yeargoal.h"

#include "timefunctions.h"
#include "yeargoal_p.h"
#include "yeargoalwidget.h"

using namespace Data;

YearGoal::YearGoal(QObject *parent) :
    Goal(parent),
    d_ptr( new YearGoalPrivate( this ) )
{
}

YearGoal::~YearGoal()
{
    delete d_ptr;
}

void YearGoal::setColor( const QColor & color )
{
    if( color.isValid() ) {
        Q_D(Data::YearGoal);
        d->color = color;
        emit colorChanged( d->color );
    }
}

QColor YearGoal::color() const
{
    Q_D(const Data::YearGoal);
    return d->color;
}

void YearGoal::setName( const QString & name )
{
    if( !name.isNull() ) {
        Q_D(Data::YearGoal);
        d->name = name;
        emit nameChanged( d->name );
    }
}

QString YearGoal::name() const
{
    Q_D(const Data::YearGoal);
    return d->name;
}

void YearGoal::setCriteria( const Data::Criteria & criteria )
{
    Q_D(Data::YearGoal);
    d->criteria = criteria;
	criteriaChanged( criteria );
}

Data::Criteria YearGoal::criteria() const
{
    Q_D(const Data::YearGoal);
    return d->criteria;
}

QDateTime YearGoal::start() const
{
    Q_D(const Data::YearGoal);
    QDate date( d->year, 1, 1 );
	return QDateTime( date, Time::startTime );
}

QDateTime YearGoal::end() const
{
    Q_D(const Data::YearGoal);
    QDate date( d->year, 12, 31 );
	return QDateTime( date, Time::endTime );
}
	
void YearGoal::setYear( int year )
{
    if( year > 0 ) {
        Q_D(Data::YearGoal);
        d->year = year;
        emit yearChanged( d->year );
    }
}

int YearGoal::year() const
{
    Q_D(const Data::YearGoal);
    return d->year;
}

UI::GoalWidgetBase *YearGoal::CreateWidget()
{
    Q_D(Data::YearGoal);

    d->widget = new UI::YearGoalWidget();

    d->widget->SetupWidget( this );
	
    connect( d->widget, SIGNAL( ChangesAccepted() ),
             d, SLOT( WidgetChangesAccepted() ) );

    return d->widget;
}

/**************** Private Class ***************/

YearGoalPrivate::YearGoalPrivate( YearGoal * parent ) :
    QObject(parent),
    name(""),
    color(QColor(0,0,0)),
    year(QDate::currentDate().year()),
    q_ptr(parent)
{
    Q_Q(Data::YearGoal);
    connect( q, SIGNAL( nameChanged( QString ) ),
             this, SLOT( OnDataUpdated() ) );
    connect( q, SIGNAL( colorChanged( QColor ) ),
             this, SLOT( OnDataUpdated() ) );
    connect( q, SIGNAL( yearChanged( int ) ),
             this, SLOT( OnDataUpdated() ) );
}

void YearGoalPrivate::WidgetChangesAccepted()
{
    if( widget == NULL )
        return;

    Q_Q(Data::YearGoal);

    if( name != widget->Name() ) {
        q->setName( widget->Name() );
    }

    if( color != widget->Color() ) {
        q->setColor( widget->Color() );
    }

    if( year != widget->Year() ) {
        q->setYear( widget->Year() );
    }
}

void YearGoalPrivate::OnDataUpdated()
{
    Q_Q(Data::YearGoal);
    emit q->goalChanged( q );
}

/************* External Functions *************/

QDataStream & operator<<(QDataStream & out, const YearGoal & goal)
{
    out << goal.name();
    out << goal.color();
    out << goal.criteria();
    out << qint32( goal.year() );

    return out;
}

QDataStream & operator>>(QDataStream & in, YearGoal & goal)
{
    QString name;
    QColor color;
    Data::Criteria criteria;
    qint32 year;

    in >> name;
    in >> color;
    in >> criteria;
    in >> year;

    goal.setName( name );
    goal.setColor( color );
    goal.setCriteria( criteria );
    goal.setYear( int(year) );

    return in;
}
