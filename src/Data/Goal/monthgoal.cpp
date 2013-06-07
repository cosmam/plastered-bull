#include "monthgoal.h"

#include "monthgoal_p.h"
#include "monthgoalwidget.h"

using namespace Data;

/**
 * @author Cosmam
 * @name MonthGoal
 * @namespace Data
 * @brief Default constructor
 * @param parent: The parent object
 **/
MonthGoal::MonthGoal(QObject *parent) :
    Goal(*new Data::MonthGoalPrivate, parent)
{
    Q_D(Data::MonthGoal);
    d->setParent(this);
    d->q_ptr = this;
    d->init();
}

/**
 * @author Cosmam
 * @name ~MonthGoal
 * @namespace Data
 * @brief Destructor
 **/
MonthGoal::~MonthGoal()
{
}

/**
 * @author Cosmam
 * @name start
 * @namespace Data
 * @brief The goal start datetime
 * @return The start datetime
 **/
QDateTime MonthGoal::start() const
{
    Q_D(const Data::MonthGoal);
    QDate date( d->year, Time::ToInt( d->month ), 1 );
	
	return QDateTime( date, Time::startTime );
}

/**
 * @author Cosmam
 * @name end
 * @namespace Data
 * @brief The goal end datetime
 * @return The end datetime
 **/
QDateTime MonthGoal::end() const
{
    Q_D(const Data::MonthGoal);
    QDate date( d->year, Time::ToInt( d->month ), 1 );
    date.setDate( date.year(), date.month(), date.daysInMonth() );
	
	return QDateTime( date, Time::endTime );
}

/**
 * @author Cosmam
 * @name setMonth
 * @namespace Data
 * @brief Sets the goal month
 * @param month: An enum representing the goal month
 **/
void MonthGoal::setMonth( Time::Month month )
{
    Q_D(Data::MonthGoal);
    if( month != Time::INVALID_MONTH ) {
        d->month = month;
        emit monthChanged( d->month );
    }
}

/**
 * @author Cosmam
 * @name month
 * @namespace Data
 * @brief Gets the goal month
 * @return The goal month enum
 */
Time::Month MonthGoal::month() const
{
    Q_D(const Data::MonthGoal);
    return d->month;
}
	
/**
 * @author Cosmam
 * @name setYear
 * @namespace Data
 * @brief Sets the goal year
 * @param year: The goal year
 **/
void MonthGoal::setYear( int year )
{
    Q_D(Data::MonthGoal);
    if( QDate(year,Time::ToInt(d->month),1).isValid() ) {
        d->year = year;
        emit yearChanged( d->year );
    }
}

/**
 * @author Cosmam
 * @name month
 * @namespace Data
 * @brief Gets the goal year
 * @return The goal year
 */
int MonthGoal::year() const
{
    Q_D(const Data::MonthGoal);
    return d->year;
}

/**
 * @author Cosmam
 * @name CreateWidget
 * @namespace Data
 * @brief Creates the goal widget based on this goal
 * @return The goal widget
 */
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

/**
 * @author Cosmam
 * @name MonthGoalPrivate
 * @namespace Data
 * @brief Default constructor
 **/
MonthGoalPrivate::MonthGoalPrivate() :
    GoalPrivate(),
    month(Time::ToMonth(QDate::currentDate().month())),
    year(QDate::currentDate().year())
{
}

/**
 * @author Cosmam
 * @name ~MonthGoalPrivate
 * @namespace Data
 * @brief Destructor
 **/
MonthGoalPrivate::~MonthGoalPrivate()
{
}

/**
 * @author Cosmam
 * @name init
 * @namespace Data
 * @brief Initializes this object
 **/
void MonthGoalPrivate::init()
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

/**
 * @author Cosmam
 * @name WidgetChangesAccepted
 * @namespace Data
 * @brief Slot called when the widget changes are accepted to process the new data
 **/
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

/**
 * @author Cosmam
 * @name OnDataUpdated
 * @namespace Data
 * @brief Slot called when data is updated, to emit the goal goalChanged signal
 **/
void MonthGoalPrivate::OnDataUpdated()
{
    Q_Q(Data::MonthGoal);
    emit q->goalChanged( q );
}

/************* External Functions *************/

/**
 * @author Cosmam
 * @name operator<<
 * @brief Outputs a monthgoal to QDataStream
 * @param out: The QDataStream output stream
 * @param goal: The goal to output data for
 * @return A reference to the output stream
 **/
QDataStream & operator<<(QDataStream & out, const MonthGoal & goal)
{
    out << goal.name();
    out << goal.color();
    out << qint32( goal.month() );
    out << qint32( goal.year() );

    return out;
}

/**
 * @author Cosmam
 * @name operator>>
 * @brief Inputs a monthgoal from QDataStream
 * @param in: The QDataStream input stream
 * @param goal: The goal to populate
 * @return A reference to the input stream
 **/
QDataStream & operator>>(QDataStream & in, MonthGoal & goal)
{
    QString name;
    QColor color;
    Time::Month month;
    qint32 year;

    in >> name;
    in >> color;
    in >> month;
    in >> year;

    goal.setName( name );
    goal.setColor( color );
    goal.setMonth( month );
    goal.setYear( int(year) );

    return in;
}
