#include "goal.h"
#include "goal_p.h"

#include <QHash>

using namespace Data;

Goal::Goal(QObject *parent) :
    Challenge(*new GoalPrivate, parent)
{
}

Goal::Goal(GoalPrivate &d, QObject *parent) :
    Challenge(d,parent)
{
}

void Goal::setColor( const QColor & color )
{
    if( color.isValid() ) {
        Q_D(Data::Goal);
        d->color = color;
        emit colorChanged( d->color );
    }
}

QColor Goal::color() const
{
    Q_D(const Data::Goal);
    return d->color;
}

void Goal::setName( const QString & name )
{
    if( !name.isNull() ) {
        Q_D(Data::Goal);
        d->name = name;
        emit nameChanged( d->name );
    }
}

QString Goal::name() const
{
    Q_D(const Data::Goal);
    return d->name;
}

void Goal::setCriteria( Data::Criteria * criteria )
{
    Q_D(Data::Goal);
    if( d->criteria != criteria ) {
        if( d->criteria != NULL ) {
            delete d->criteria;
        }
        d->criteria = criteria;
        criteriaChanged( criteria );
    }
}

const Data::Criteria * Goal::criteria() const
{
    Q_D(const Data::Goal);
    return d->criteria;
}

ID_t Goal::id() const
{
    return qHash(this);
}

/**************** Private Class ***************/

GoalPrivate::GoalPrivate() :
    ChallengePrivate(),
    color(QColor(0,0,0)),
    name("")
{
}

void GoalPrivate::init()
{

}
