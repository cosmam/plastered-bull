#include "daygoal.h"

#include "daygoal_p.h"
#include "daygoalwidget.h"
#include "timefunctions.h"

using namespace Data;

/**
 * @author Cosmam
 * @name DayGoal
 * @namespace Data
 * @brief Default constructor
 * @param parent: The parent object
 **/
DayGoal::DayGoal(QObject *parent) :
    Goal(*new Data::DayGoalPrivate, parent)
{
    Q_D(Data::DayGoal);
    d->setParent(this);
    d->q_ptr = this;
    d->init();
}

/**
 * @author Cosmam
 * @name ~DayGoal
 * @namespace Data
 * @brief Destructor
 **/
DayGoal::~DayGoal()
{
}

/**
 * @author Cosmam
 * @name start
 * @namespace Data
 * @brief Gets the start datetime of the goal
 * @return The start datetime of this custom goal
 **/
QDateTime DayGoal::start() const
{
    Q_D(const Data::DayGoal);
    return QDateTime( d->date, Time::startTime );
}

/**
 * @author Cosmam
 * @name end
 * @namespace Data
 * @brief Gets the end datetime of the goal
 * @return The end datetime of this custom goal
 **/
QDateTime DayGoal::end() const
{
    Q_D(const Data::DayGoal);
    return QDateTime( d->date, Time::endTime );
}

/**
 * @author Cosmam
 * @name setDate
 * @namespace Data
 * @brief Sets the date for this goal
 * @param date: A reference to the QDate representing this goal's date
 **/
void DayGoal::setDate( const QDate & date )
{
    if( date.isValid() ) {
        Q_D(Data::DayGoal);
        d->date = date;
        emit dateChanged( d->date );
    }
}

/**
 * @author Cosmam
 * @name date
 * @namespace Data
 * @brief Gets the date for this goal
 * @return A QDate object representing this goal's date
 **/
QDate DayGoal::date() const
{
    Q_D(const Data::DayGoal);
    return d->date;
}

/**
 * @author Cosmam
 * @name CreateWidget
 * @namespace Data
 * @brief Creates a goal widget from this goal
 * @return A pointer to the goal widget form
 **/
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

/**
 * @author Cosmam
 * @name DayGoalPrivate
 * @namespace Data
 * @brief Default constructor
 **/
DayGoalPrivate::DayGoalPrivate() :
    GoalPrivate(),
    date(QDate::currentDate())
{
}

/**
 * @author Cosmam
 * @name ~DayGoalPrivate
 * @namespace Data
 * @brief Destructor
 **/
DayGoalPrivate::~DayGoalPrivate()
{
}

/**
 * @author Cosmam
 * @name init
 * @namespace Data
 * @brief Initializes this object
 **/
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

/**
 * @author Cosmam
 * @name WidgetChangesAccepted
 * @namespace Data
 * @brief Slot called when widget changes are accepted
 **/
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

/**
 * @author Cosmam
 * @name OnDataUpdated
 * @namespace Data
 * @brief Slot called when the data is updated to emit public class's signal
 **/
void DayGoalPrivate::OnDataUpdated()
{
    Q_Q(Data::DayGoal);
    emit q->goalChanged( q );
}

/************* External Functions *************/

/**
 * @author Cosmam
 * @name operator<<
 * @brief Outputs a daygoal to QDataStream
 * @param out: The QDataStream output stream
 * @param goal: The goal to output data for
 * @return A reference to the output stream
 **/
QDataStream & operator<<(QDataStream & out, const DayGoal & goal)
{
    out << goal.name();
    out << goal.color();
    out << goal.date();

    return out;
}

/**
 * @author Cosmam
 * @name operator>>
 * @brief Inputs a daygoal from QDataStream
 * @param in: The QDataStream input stream
 * @param goal: The goal to populate
 * @return A reference to the input stream
 **/
QDataStream & operator>>(QDataStream & in, DayGoal & goal)
{
    QString name;
    QColor color;
    QDate date;

    in >> name;
    in >> color;
    in >> date;

    goal.setName( name );
    goal.setColor( color );
    goal.setDate( date );

    return in;
}
