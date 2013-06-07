#include "customgoal.h"

#include "customgoal_p.h"
#include "customgoalwidget.h"

#include "timefunctions.h"

using namespace Data;

/**
 * @author Cosmam
 * @name CustomGoal
 * @namespace Data
 * @brief Default constructor
 * @param parent: The parent object
 **/
CustomGoal::CustomGoal(QObject *parent) :
    Goal(*new Data::CustomGoalPrivate, parent)
{
    Q_D(Data::CustomGoal);
    d->setParent(this);
    d->q_ptr = this;
    d->init();
}

/**
 * @author Cosmam
 * @name ~CustomGoal
 * @namespace Data
 * @brief Destructor
 **/
CustomGoal::~CustomGoal()
{
}

/**
 * @author Cosmam
 * @name start
 * @namespace Data
 * @brief The goal start datetime
 * @return The start datetime
 **/
QDateTime CustomGoal::start() const
{
    Q_D(const Data::CustomGoal);
    return QDateTime( d->startDate, Time::startTime );
}

/**
 * @author Cosmam
 * @name end
 * @namespace Data
 * @brief The goal end datetime
 * @return The end datetime
 **/
QDateTime CustomGoal::end() const
{
    Q_D(const Data::CustomGoal);
    QDate date( d->startDate );
    return QDateTime( date.addDays( d->duration ), Time::endTime );
}

/**
 * @author Cosmam
 * @name setStartDate
 * @namespace Data
 * @brief Sets the goal start date
 * @param date: The goal start date
 **/
void CustomGoal::setStartDate( const QDate & date )
{
    if( date.isValid() )
     {
        Q_D(Data::CustomGoal);
        d->startDate = date;
        emit startDateChanged( d->startDate );
    }
}

/**
 * @author Cosmam
 * @name startDate
 * @namespace Data
 * @brief Gets the goal start date
 * @return The goal start date
 **/
QDate CustomGoal::startDate() const
{
    Q_D(const Data::CustomGoal);
    return d->startDate;
}

/**
 * @author Cosmam
 * @name setDuration
 * @namespace Data
 * @brief Sets the goal duration
 * @param duration: The goal duration
 **/
void CustomGoal::setDuration( int duration )
{
    if( duration > 0 ) {
        Q_D(Data::CustomGoal);
        d->duration = duration;
        emit durationChanged( d->duration );
    }
}

/**
 * @author Cosmam
 * @name duration
 * @namespace Data
 * @brief Gets the goal duration
 * @return The goal duration
 */
int CustomGoal::duration() const
{
    Q_D(const Data::CustomGoal);
    return d->duration;
}

/**
 * @author Cosmam
 * @name CreateWidget
 * @namespace Data
 * @brief Creates the goal widget based on this goal
 * @return The goal widget
 */
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

/**
 * @author Cosmam
 * @name CustomGoalPrivate
 * @namespace Data
 * @brief Default constructor
 **/
CustomGoalPrivate::CustomGoalPrivate() :
    GoalPrivate(),
    startDate(QDate::currentDate()),
    duration(0)
{
}

/**
 * @author Cosmam
 * @name ~CustomGoalPrivate
 * @namespace Data
 * @brief Destructor
 **/
CustomGoalPrivate::~CustomGoalPrivate()
{
}

/**
 * @author Cosmam
 * @name init
 * @namespace Data
 * @brief Initializes this object
 **/
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

/**
 * @author Cosmam
 * @name WidgetChangesAccepted
 * @namespace Data
 * @brief Slot called when the widget changes are accepted to process the new data
 **/
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

/**
 * @author Cosmam
 * @name OnDataUpdated
 * @namespace Data
 * @brief Slot called when data is updated, to emit the goal goalChanged signal
 **/
void CustomGoalPrivate::OnDataUpdated()
{
    Q_Q(Data::CustomGoal);
    emit q->goalChanged( q );
}

/************* External Functions *************/

/**
 * @author Cosmam
 * @name operator<<
 * @brief Outputs a customgoal to QDataStream
 * @param out: The QDataStream output stream
 * @param goal: The goal to output data for
 * @return A reference to the output stream
 **/
QDataStream & operator<<(QDataStream & out, const CustomGoal & goal)
{
    out << goal.name();
    out << goal.color();
    out << goal.startDate();
    out << quint32( goal.duration() );

    return out;
}

/**
 * @author Cosmam
 * @name operator>>
 * @brief Inputs a customgoal from QDataStream
 * @param in: The QDataStream input stream
 * @param goal: The goal to populate
 * @return A reference to the input stream
 **/
QDataStream & operator>>(QDataStream & in, CustomGoal & goal)
{
    QString name;
    QColor color;
    QDate date;
    quint32 duration;

    in >> name;
    in >> color;
    in >> date;
    in >> duration;

    goal.setName( name );
    goal.setColor( color );
    goal.setStartDate( date );
    goal.setDuration( int(duration) );

    return in;
}
