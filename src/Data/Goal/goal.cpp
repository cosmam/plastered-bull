#include "goal.h"
#include "goal_p.h"

#include <QHash>

using namespace Data;

/**
 * @author Cosmam
 * @name Goal
 * @namespace Data
 * @brief Default constructor
 * @param parent: The parent object
 **/
Goal::Goal(QObject *parent) :
    Challenge(*new GoalPrivate, parent)
{
}

/**
 * @author Cosmam
 * @name Goal
 * @namespace Data
 * @brief Overloaded constructor for d-ptr initialization
 * @param d: A reference to the private class
 * @param parent: The parent object
 **/
Goal::Goal(GoalPrivate &d, QObject *parent) :
    Challenge(d,parent)
{
}

/**
 * @author Cosmam
 * @name setColor
 * @namespace Data
 * @brief Sets the goal color
 * @param color: A reference to the goal color
 **/
void Goal::setColor( const QColor & color )
{
    if( color.isValid() ) {
        Q_D(Data::Goal);
        d->color = color;
        emit colorChanged( d->color );
    }
}

/**
 * @author Cosmam
 * @name color
 * @namespace Data
 * @brief Gets the goal color
 * @return The goal color
 **/
QColor Goal::color() const
{
    Q_D(const Data::Goal);
    return d->color;
}

/**
 * @author Cosmam
 * @name setName
 * @namespace Data
 * @brief Sets the goal name
 * @param color: A reference to the goal name
 **/
void Goal::setName( const QString & name )
{
    if( !name.isNull() ) {
        Q_D(Data::Goal);
        d->name = name;
        emit nameChanged( d->name );
    }
}

/**
 * @author Cosmam
 * @name name
 * @namespace Data
 * @brief Gets the goal name
 * @return The goal name
 **/
QString Goal::name() const
{
    Q_D(const Data::Goal);
    return d->name;
}


/**
 * @author Cosmam
 * @name id
 * @namespace Data
 * @brief Generates a unique ID for this goal
 * @return A unique numerical value denoting this goal
 **/
ID_t Goal::id() const
{
    return qHash(this);
}

/**************** Private Class ***************/

/**
 * @author Cosmam
 * @name GoalPrivate
 * @namespace Data
 * @brief Default constructor
 **/
GoalPrivate::GoalPrivate() :
    ChallengePrivate(),
    color(QColor(0,0,0)),
    name("")
{
}

/**
 * @author Cosmam
 * @name init
 * @namespace Data
 * @brief Initializes this object
 **/
void GoalPrivate::init()
{

}
