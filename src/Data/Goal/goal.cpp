#include "goal.h"

using namespace Data;

Goal::Goal(QObject *parent) :
    QObject(parent)
{
}

ID_t Goal::id() const
{
    return qHash(this);
}
