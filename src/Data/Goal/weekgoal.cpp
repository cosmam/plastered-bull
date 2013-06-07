#include "weekgoal.h"

#include "weekgoal_p.h"
#include "weekgoalwidget.h"

#include "customgoal.h"

#include <QDateTime>

using namespace Data;

/**
 * @author Cosmam
 * @name WeekGoal
 * @namespace Data
 * @brief Default constructor
 * @param parent: The parent object
 **/
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
    connect( d->goal, SIGNAL( criteriaChanged( Data::Criteria * ) ),
             this, SIGNAL( criteriaChanged( Data::Criteria * ) ) );
    connect( d->goal, SIGNAL( startDateChanged( QDate ) ),
             this, SIGNAL( startDateChanged( QDate ) ) );
}

/**
 * @author Cosmam
 * @name ~WeekGoal
 * @namespace Data
 * @brief Destructor
 **/
WeekGoal::~WeekGoal()
{
}

/**
 * @author Cosmam
 * @name start
 * @namespace Data
 * @brief The goal start datetime
 * @return The start datetime
 **/
QDateTime WeekGoal::start() const
{
    Q_D(const Data::WeekGoal);
    return d->goal->start();
}

/**
 * @author Cosmam
 * @name end
 * @namespace Data
 * @brief The goal end datetime
 * @return The end datetime
 **/
QDateTime WeekGoal::end() const
{
    Q_D(const Data::WeekGoal);
    return d->goal->end();
}

/**
 * @author Cosmam
 * @name setStartDate
 * @namespace Data
 * @brief Sets the goal start date
 * @param date: The goal start date
 **/
void WeekGoal::setStartDate( const QDate & date )
{
    Q_D(Data::WeekGoal);
    d->goal->setStartDate( date );
}

/**
 * @author Cosmam
 * @name startDate
 * @namespace Data
 * @brief Gets the goal start date
 * @return The goal start date
 **/
QDate WeekGoal::startDate() const
{
    Q_D(const Data::WeekGoal);
    return d->goal->startDate();
}

/**
 * @author Cosmam
 * @name CreateWidget
 * @namespace Data
 * @brief Creates the goal widget based on this goal
 * @return The goal widget
 */
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

/**
 * @author Cosmam
 * @name WeekGoalPrivate
 * @namespace Data
 * @brief Default constructor
 **/
WeekGoalPrivate::WeekGoalPrivate() :
    GoalPrivate()
{
}

/**
 * @author Cosmam
 * @name ~WeekGoalPrivate
 * @namespace Data
 * @brief Destructor
 **/
WeekGoalPrivate::~WeekGoalPrivate()
{
    delete goal;
}

/**
 * @author Cosmam
 * @name init
 * @namespace Data
 * @brief Initializes this object
 **/
void WeekGoalPrivate::init()
{
    goal = new CustomGoal();
    goal->setDuration(7);

    Q_Q(Data::WeekGoal);

    connect( goal, SIGNAL( goalChanged( Data::Goal * ) ),
             q, SIGNAL( goalChanged( Data::Goal * ) ) );
}

/**
 * @author Cosmam
 * @name WidgetChangesAccepted
 * @namespace Data
 * @brief Slot called when the widget changes are accepted to process the new data
 **/
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

/**
 * @author Cosmam
 * @name operator<<
 * @brief Outputs a weekgoal to QDataStream
 * @param out: The QDataStream output stream
 * @param goal: The goal to output data for
 * @return A reference to the output stream
 **/
QDataStream & operator<<(QDataStream & out, const WeekGoal & goal)
{
    out << goal.name();
    out << goal.color();
    out << goal.startDate();

    return out;
}

/**
 * @author Cosmam
 * @name operator>>
 * @brief Inputs a weekgoal from QDataStream
 * @param in: The QDataStream input stream
 * @param goal: The goal to populate
 * @return A reference to the input stream
 **/
QDataStream & operator>>(QDataStream & in, WeekGoal & goal)
{
    QString name;
    QColor color;
    QDate date;

    in >> name;
    in >> color;
    in >> date;

    goal.setName( name );
    goal.setColor( color );
    goal.setStartDate( date );

    return in;
}
