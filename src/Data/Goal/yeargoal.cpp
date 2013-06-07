#include "yeargoal.h"

#include "timefunctions.h"
#include "yeargoal_p.h"
#include "yeargoalwidget.h"

using namespace Data;

/**
 * @author Cosmam
 * @name YearGoal
 * @namespace Data
 * @brief Default constructor
 * @param parent: The parent object
 **/
YearGoal::YearGoal(QObject *parent) :
    Goal(*new Data::YearGoalPrivate, parent)
{
}

/**
 * @author Cosmam
 * @name ~YearGoal
 * @namespace Data
 * @brief Destructor
 **/
YearGoal::~YearGoal()
{
}

/**
 * @author Cosmam
 * @name start
 * @namespace Data
 * @brief The goal start datetime
 * @return The start datetime
 **/
QDateTime YearGoal::start() const
{
    Q_D(const Data::YearGoal);
    QDate date( d->year, 1, 1 );
	return QDateTime( date, Time::startTime );
}

/**
 * @author Cosmam
 * @name end
 * @namespace Data
 * @brief The goal end datetime
 * @return The end datetime
 **/
QDateTime YearGoal::end() const
{
    Q_D(const Data::YearGoal);
    QDate date( d->year, 12, 31 );
	return QDateTime( date, Time::endTime );
}
	
/**
 * @author Cosmam
 * @name setYear
 * @namespace Data
 * @brief Sets the goal year
 * @param year: The goal year
 **/
void YearGoal::setYear( int year )
{
    if( QDate(year,1,1).isValid() ) {
        Q_D(Data::YearGoal);
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
int YearGoal::year() const
{
    Q_D(const Data::YearGoal);
    return d->year;
}

/**
 * @author Cosmam
 * @name CreateWidget
 * @namespace Data
 * @brief Creates the goal widget based on this goal
 * @return The goal widget
 */
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

/**
 * @author Cosmam
 * @name YearGoalPrivate
 * @namespace Data
 * @brief Default constructor
 **/
YearGoalPrivate::YearGoalPrivate() :
    GoalPrivate(),
    year(QDate::currentDate().year())
{
}

/**
 * @author Cosmam
 * @name ~YearGoalPrivate
 * @namespace Data
 * @brief Destructor
 **/
YearGoalPrivate::~YearGoalPrivate()
{
}

/**
 * @author Cosmam
 * @name init
 * @namespace Data
 * @brief Initializes this object
 **/
void YearGoalPrivate::init()
{
    Q_Q(Data::YearGoal);
    connect( q, SIGNAL( nameChanged( QString ) ),
             this, SLOT( OnDataUpdated() ) );
    connect( q, SIGNAL( colorChanged( QColor ) ),
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

/**
 * @author Cosmam
 * @name OnDataUpdated
 * @namespace Data
 * @brief Slot called when data is updated, to emit the goal goalChanged signal
 **/
void YearGoalPrivate::OnDataUpdated()
{
    Q_Q(Data::YearGoal);
    emit q->goalChanged( q );
}

/************* External Functions *************/

/**
 * @author Cosmam
 * @name operator<<
 * @brief Outputs a yeargoal to QDataStream
 * @param out: The QDataStream output stream
 * @param goal: The goal to output data for
 * @return A reference to the output stream
 **/
QDataStream & operator<<(QDataStream & out, const YearGoal & goal)
{
    out << goal.name();
    out << goal.color();
    out << qint32( goal.year() );

    return out;
}

/**
 * @author Cosmam
 * @name operator>>
 * @brief Inputs a yeargoal from QDataStream
 * @param in: The QDataStream input stream
 * @param goal: The goal to populate
 * @return A reference to the input stream
 **/
QDataStream & operator>>(QDataStream & in, YearGoal & goal)
{
    QString name;
    QColor color;
    qint32 year;

    in >> name;
    in >> color;
    in >> year;

    goal.setName( name );
    goal.setColor( color );
    goal.setYear( int(year) );

    return in;
}
